// @ts-ignore
import * as xml2js from "xml2js";
// @ts-ignore
import * as fs from "fs";
// @ts-ignore
import arxml2json from "../out/control_swc_sweep_component.json";

const parser = new xml2js.Parser({
    explicitArray: false,
    explicitChildren: true,
    preserveChildrenOrder: true,
    charsAsChildren: true
});

interface NodeAttributes {
    [key: string]: string;
}

interface Node {
    $?: NodeAttributes;
    $$?: Node[];
    _?: string;
    [key: string]: any;
}

interface TransformedNode {
    tag: string;
    attributes?: NodeAttributes;
    children: TransformedNode[];
}

function transformNode(node: Node, nodeName: string): TransformedNode {
    const result: TransformedNode = { tag: nodeName, children: [] };

    // 处理属性
    if (node.$) {
        result.attributes = { ...node.$ };
    }

    // 处理文本内容
    if (node._ && node._.trim()) {
        if (!result.attributes) {
            result.attributes = {};
        }
        result.attributes.innerText = node._.trim();
    }

    // 处理子节点
    if (node.$$) {
        node.$$.forEach((child) => {
            const childName = child["#name"];
            if (childName !== "__text__") {
                const transformedChild = transformNode(child, childName);
                result.children.push(transformedChild);
            }
        });
    }

    return result;
}

export const parseXML = (xmlString: string): Promise<TransformedNode> => {
    return new Promise((resolve, reject) => {
        parser.parseString(xmlString, (err: Error, result: any) => {
            if (err) {
                reject(err);
            } else {
                // 根节点
                const rootNodeName = Object.keys(result)[0];
                const transformedResult = transformNode(result[rootNodeName], rootNodeName);
                resolve(transformedResult);
            }
        });
    });
};

export const parseXML2 = (xmlString: string): Promise<TransformedNode> => {
    console.info("parseXML2");
    return new Promise((resolve, reject) => {
        parser.parseString(xmlString, (err: Error, result: any) => {
            if (err) {
                reject(err);
                console.info("err", err);
            } else {
                console.info(JSON.stringify(result, null, 4));
                resolve(result);
            }
        });
    });
};

export const readFile = (path: string) => {
    return new Promise((resolve, reject) => {
        fs.readFile(path, "utf8", (err: Error, data: string) => {
            if (err) {
                reject(err);
            }
            resolve(data);
        });
    });
};

export const writeFile = (path: string, data: string) => {
    return new Promise((resolve, reject) => {
        fs.writeFile(path, data, "utf8", (err: Error, data: string) => {
            if (err) {
                reject(err);
            }
            resolve(data);
        });
    });
};

const findChildrenByKey: any = (key: string, data: any) => {
    if (data["tag"] === key) {
        return data;
    } else if (data["children"]?.length) {
        let match = false;
        let cur = null;
        let index = 0;
        while (!match && index < data["children"].length) {
            cur = data["children"][index++];
            match = findChildrenByKey(key, cur);
        }
        return match;
    } else {
        return null;
    }
};

const getType = (str:string) => {
    const types = ["Boolean", "UInt8", "SInt8", "UInt16", "SInt16", "UInt32", "SInt32", "Float", "Double"]
    for (const type of types) {
        if (str.includes(type)) {
            return type;
        }
    }
    return ""; // 如果未找到匹配项，返回 null
}

const  formatValue = (value: string | number, type: string): string => {
    switch (type.toLowerCase()) {
        case 'uint8':
        case 'uint16':
        case 'uint32':
            if (/^\d+$/.test(value.toString())) {
                return value.toString() + 'U';
            }
            break;
        case 'sint8':
        case 'sint16':
        case 'sint32':
            if (/^-?\d+$/.test(value.toString())) {
                return value.toString();
            }
            break;
        case 'float':
            const floatString = value.toString();
            if (/^-?\d+(\.\d+)?f?$/i.test(floatString)) {
                const floatVal = parseFloat(floatString.replace(/f$/i, ''));
                if (Number.isInteger(floatVal)) {
                    return floatVal + '.0F';
                } else {
                    return floatVal + 'F';
                }
            }
            break;
        case 'double':
            const doubleString = value.toString();
            if (/^-?\d+(\.\d+)?$/.test(doubleString)) {
                const doubleVal = parseFloat(doubleString);
                if (Number.isInteger(doubleVal)) {
                    return doubleVal + '.0';
                } else {
                    return doubleVal.toString();
                }
            }
            break;
        case 'boolean':
            if (/^(0|1)$/i.test(value.toString())) {
                return value.toString() === '1' ? 'TRUE' : 'FALSE';
            }
            break;
        default:
            // 不支持的类型，直接返回原值的字符串形式
            return value.toString();
    }

    // 默认情况下返回原值的字符串形式
    return value.toString();
}

export const extractSWC = (data: any) => {
    // 1.SWCName
    // APPLICATION-SW-COMPONENT-TYPE - SHORT-NAME
    // findChildrenByKey("APPLICATION-SW-COMPONENT-TYPE", data);
    // let swcObj = findChildrenByKey("APPLICATION-SW-COMPONENT-TYPE", arxml2json);
    // let nameObj = findChildrenByKey("SHORT-NAME", swcObj);
    // let swcName = nameObj?.attributes?.innerText;
    // console.info("SWC Name:", swcName);
    // 2.Events periods
    // let eventsObj = findChildrenByKey("EVENTS", swcObj);
    // let periods = eventsObj?.children.map((item: any) => {
    //     let runnable = findChildrenByKey("START-ON-EVENT-REF", item)?.attributes?.innerText?.split("/")?.pop();
    //     let period = findChildrenByKey("PERIOD", item)?.attributes?.innerText;
    //     return {
    //         runnable,
    //         period
    //     };
    // });
    // console.info("periods:", JSON.stringify(periods, null, 4));
    // 3.Ports initValue
    let portsObj = findChildrenByKey("PORTS", data);

    let i = 0;
    const getInitValues = (fields: any) => {
        console.info("fields:", i++, fields);
        return fields?.children.map((item: any) => {
            let tag = item["tag"];
            console.info("tag:", i, tag, item);
            switch (tag) {
                case "NUMERICAL-VALUE-SPECIFICATION":
                    const dataType = findChildrenByKey("SHORT-LABEL", item)?.attributes?.innerText;
                    return formatValue(findChildrenByKey("VALUE", item)?.attributes?.innerText, getType(dataType))
                case "ARRAY-VALUE-SPECIFICATION":
                    return getInitValues(findChildrenByKey("ELEMENTS", item));
                case "RECORD-VALUE-SPECIFICATION":
                    console.info("item:", JSON.stringify(item, null, 4));
                    console.info("match:", JSON.stringify(findChildrenByKey("FIELDs", item), null, 4));
                    return getInitValues(findChildrenByKey("FIELDS", item));
                default:
                    break;
            }
        });
    };

    let initValues = portsObj?.children.map((item: any) => {
        let dataElement = findChildrenByKey("DATA-ELEMENT-REF", item)?.attributes?.innerText?.split("/")?.pop();
        let initValueObj = findChildrenByKey("FIELDS", item);
        let initValue = getInitValues(initValueObj);

        return {
            [dataElement]: initValue
        };
    });

    console.info(JSON.stringify(initValues, null, 4));
    writeFile("./out/initvalues.json", JSON.stringify(initValues, null, 2));
    // 4.Runnables
    // let runnables = findChildrenByKey("RUNNABLES", swcObj);
};

extractSWC(arxml2json);
