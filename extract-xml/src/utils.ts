// @ts-ignore
import * as xml2js from "xml2js";
// @ts-ignore
import * as fs from "fs";

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

export const readFile = (path: string): Promise<string> => {
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

const getValueType = (str: string) => {
    const types = ["Boolean", "UInt8", "SInt8", "UInt16", "SInt16", "UInt32", "SInt32", "Float", "Double"];
    for (const type of types) {
        if (str.includes(type)) {
            return type;
        }
    }
    return "";
};

const signValue = (value: string | number, type: string): string => {
    switch (type.toLowerCase()) {
        case "uint8":
        case "uint16":
        case "uint32":
            if (/^\d+$/.test(value.toString())) {
                return value.toString() + "U";
            }
            break;
        case "sint8":
        case "sint16":
        case "sint32":
            if (/^-?\d+$/.test(value.toString())) {
                return value.toString();
            }
            break;
        case "float":
            const floatString = value.toString();
            if (/^-?\d+(\.\d+)?f?$/i.test(floatString)) {
                const floatVal = parseFloat(floatString.replace(/f$/i, ""));
                if (Number.isInteger(floatVal)) {
                    return floatVal + ".0F";
                } else {
                    return floatVal + "F";
                }
            }
            break;
        case "double":
            const doubleString = value.toString();
            if (/^-?\d+(\.\d+)?$/.test(doubleString)) {
                const doubleVal = parseFloat(doubleString);
                if (Number.isInteger(doubleVal)) {
                    return doubleVal + ".0";
                } else {
                    return doubleVal.toString();
                }
            }
            break;
        case "boolean":
            if (/^(0|1)$/i.test(value.toString())) {
                return value.toString() === "1" ? "TRUE" : "FALSE";
            }
            break;
        default:
            // 不支持的类型，直接返回原值的字符串形式
            return value.toString();
    }

    // 默认情况下返回原值的字符串形式
    return value.toString();
};

const stringLineBreak = (str: string, num = 120) => {
    if (str.length < num) {
        return str;
    } else {
        // 如果第一个字符是 '{'，替换为 '{\n  '
        if (str.startsWith("{")) {
            str = "{\n  " + str.slice(1);
        }

        // 如果最后一个字符是 '}'，替换为 '\n}'
        if (str.endsWith("}")) {
            str = str.slice(0, -1) + "\n}";
        }
    }

    let result = "";
    let currentLineLength = 0;

    // 遍历输入字符串的每个字符
    for (let i = 0; i < str.length; i++) {
        const char = str[i];
        result += char;
        currentLineLength++;

        // 检查当前字符是否为逗号，并且当前行长度是否已经达到指定的长度
        if (char === "," && currentLineLength >= num) {
            result += "\n ";
            currentLineLength = 0;
        }
    }
    return result;
};

const convertArrayToString = (arr: any[]): string => {
    const stringify = (item: any): string => {
        if (Array.isArray(item)) {
            return "{" + item.map(stringify).join(", ") + "}";
        }
        return item.toString();
    };
    return stringify(arr);
};

const removeWhitespace = (str: string) => {
    return str
        .replace(/\s+/g, " ") // 将多个空格和换行替换为单个空格
        .replace(/,\s*/g, ", ") // 确保逗号后只有一个空格
        .replace(/\{\s*/g, "{") // 移除 { 后的空格
        .replace(/\s*\}/g, "}") // 移除 } 前的空格
        .trim(); // 去掉字符串首尾的空格;
};

export const extractComponent = (data: any) => {
    // 1.SWCName, 通过APPLICATION-SW-COMPONENT-TYP标签下SHORT-NAME标签
    const swcObj = findChildrenByKey("APPLICATION-SW-COMPONENT-TYPE", data);
    const nameObj = findChildrenByKey("SHORT-NAME", swcObj);
    const swcName = nameObj?.attributes?.innerText;

    // 2.Events periods
    // 通过EVENTS标签
    const eventsObj = findChildrenByKey("EVENTS", swcObj);
    const periods = eventsObj?.children?.reduce((pre: any, item: any) => {
        let runnable = findChildrenByKey("START-ON-EVENT-REF", item)?.attributes?.innerText?.split("/")?.at(-1);
        let period = findChildrenByKey("PERIOD", item)?.attributes?.innerText;
        pre[runnable] = period;
        return pre;
    }, {});

    // 3.Ports initValue
    // 通过PORTS下FIELDS标签，注意分三类，有嵌套结构
    const getInitValues = (fields: any) => {
        return fields?.children?.map((item: any) => {
            const tag = item["tag"];
            switch (tag) {
                case "NUMERICAL-VALUE-SPECIFICATION":
                    const dataType = findChildrenByKey("SHORT-LABEL", item)?.attributes?.innerText;
                    return signValue(findChildrenByKey("VALUE", item)?.attributes?.innerText, getValueType(dataType));
                case "ARRAY-VALUE-SPECIFICATION":
                    return getInitValues(findChildrenByKey("ELEMENTS", item));
                case "RECORD-VALUE-SPECIFICATION":
                    return getInitValues(findChildrenByKey("FIELDS", item));
                default:
                    break;
            }
        });
    };

    const portsObj = findChildrenByKey("PORTS", swcObj);
    const initValues = portsObj?.children?.reduce((pre: any, item: any) => {
        const dataElement = findChildrenByKey("DATA-ELEMENT-REF", item)?.attributes?.innerText?.split("/")?.at(-1);
        const initValueObj = findChildrenByKey("FIELDS", item);
        let initValue = getInitValues(initValueObj);

        // 转为字符串
        initValue = convertArrayToString(initValue);
        // // 添加换行
        initValue = stringLineBreak(initValue);
        pre[dataElement] = initValue;
        return pre;
    }, {});

    // 3.1 IRV initValues
    const innerVarObj = findChildrenByKey("IMPLICIT-INTER-RUNNABLE-VARIABLES", swcObj);
    const IRVMeta = innerVarObj?.children?.reduce(
        (pre: any, item: any) => {
            const dataElement = findChildrenByKey("SHORT-NAME", item)?.attributes?.innerText;
            const dataType = findChildrenByKey("TYPE-TREF", item)?.attributes?.innerText?.split("/")?.at(-1);
            const initValueObj = findChildrenByKey("FIELDS", item);
            let initValue = getInitValues(initValueObj);
            // 转为字符串
            initValue = convertArrayToString(initValue);
            pre.dataTypeMeta[dataElement] = dataType;
            pre.initValues[dataElement] = initValue;
            return pre;
        },
        { dataTypeMeta: {}, initValues: {} }
    );

    // 4.Runnables
    // 通过RUNNABLES标签
    // Interface需要解析dataElement、port
    // IRV需要解析dataElement和读写方向
    const runnablesObj = findChildrenByKey("RUNNABLES", swcObj);
    const runnables = runnablesObj?.children?.map((runnable: any) => {
        const name = findChildrenByKey("SHORT-NAME", runnable)?.attributes?.innerText;
        const interfaces: any = [];
        const irvs: any = [];
        runnable?.children.forEach((dataAccess: any) => {
            const tag = dataAccess["tag"];
            switch (tag) {
                case "DATA-READ-ACCESSS":
                case "DATA-WRITE-ACCESSS":
                    dataAccess?.children.forEach((item: any) => {
                        const textArr = findChildrenByKey(
                            "TARGET-DATA-PROTOTYPE-REF",
                            item
                        )?.attributes?.innerText?.split("/");
                        const dataElement = textArr?.at(-1);
                        const interfaceName = textArr?.at(-2);

                        const portObj = findChildrenByKey("PORT-PROTOTYPE-REF", item);
                        const portName = portObj?.attributes?.innerText?.split("/")?.at(-1);
                        const portType = portObj?.attributes?.DEST?.startsWith("R-PORT") ? "R-PORT" : "P-PORT";
                        interfaceName &&
                            interfaces.push({
                                name: interfaceName,
                                dataElement,
                                port: {
                                    name: portName,
                                    type: portType
                                }
                            });
                    });

                case "READ-LOCAL-VARIABLES":
                case "WRITTEN-LOCAL-VARIABLES":
                    dataAccess?.children?.forEach((item: any) => {
                        const dataElement = findChildrenByKey("LOCAL-VARIABLE-REF", item)
                            ?.attributes?.innerText?.split("/")
                            ?.at(-1);
                        const type = findChildrenByKey("SHORT-NAME", item)?.attributes?.innerText?.startsWith("WV")
                            ? "W"
                            : "R";
                        dataElement &&
                            irvs.push({
                                dataElement,
                                type
                            });
                    });
                default:
                    break;
            }
        });

        return {
            name,
            interfaces,
            irvs
        };
    });

    return {
        runnables,
        swcName,
        periods,
        initValues,
        IRVMeta
    };
};

export const orderDataType = (dataTypeInfo: any[]) => {
    const result: any[] = [];
    const types = ["boolean", "uint8", "sint8", "uint16", "sint16", "uint32", "sint32", "float", "double"];

    const findDataTypeDeps = (dataType: any): any => {
        const deps: any = [];
        const { typeRef, subElements } = dataType;
        // 1.查看typeRef
        if (typeRef) {
            if (types.includes(typeRef)) {
                return deps;
            } else {
                deps.push(dataTypeInfo.filter((item) => item.name === typeRef)[0]);
            }
        } else {
            if (subElements) {
                subElements.map((item: any) => {
                    deps.push(...findDataTypeDeps(item));
                });
            }
        }
        return deps;
    };
    dataTypeInfo.forEach((item) => {
        const deps = findDataTypeDeps(item);
        if (!deps) {
            if (!result.find((i) => i.name === item.name)) {
                result.push(item);
            }
        } else {
            deps.push(item);
            deps.forEach((dataType: any) => {
                if (dataType && !result.find((i) => i.name === dataType.name)) {
                    result.push(dataType);
                }
            });
        }
    });
    return result;
};

export const extractDataType = (data: any) => {
    const getDatatypeInfo = (dataTypeObjs: any) => {
        return dataTypeObjs?.children.map((datatype: any) => {
            const name = findChildrenByKey("SHORT-NAME", datatype)?.attributes?.innerText;
            const category = findChildrenByKey("CATEGORY", datatype)?.attributes?.innerText;
            let typeRef = "";
            switch (category) {
                case "STRUCTURE":
                    return {
                        name,
                        category,
                        subElements: getDatatypeInfo(findChildrenByKey("SUB-ELEMENTS", datatype))
                    };
                case "ARRAY":
                    return {
                        name,
                        category,
                        length: findChildrenByKey("ARRAY-SIZE", datatype)?.attributes?.innerText,
                        subElements: getDatatypeInfo(findChildrenByKey("SUB-ELEMENTS", datatype))
                    };
                case "TYPE_REFERENCE":
                    typeRef = findChildrenByKey("IMPLEMENTATION-DATA-TYPE-REF", datatype)
                        ?.attributes?.innerText?.split("/")
                        ?.at(-1);
                    return {
                        name,
                        category,
                        typeRef
                    };
                case "VALUE":
                    typeRef = findChildrenByKey("BASE-TYPE-REF", datatype)?.attributes?.innerText?.split("/")?.at(-1);
                    return {
                        name,
                        category,
                        typeRef
                    };
                default:
                    console.info("Category: ", category);
                    break;
            }
        });
    };

    const dataTypeObjs = findChildrenByKey("ELEMENTS", data);
    const dataTypeInfo = getDatatypeInfo(dataTypeObjs);
    return orderDataType(dataTypeInfo);
};

export const extractDataTypeMeta = (data: any) => {
    const interfaceObjs = findChildrenByKey("ELEMENTS", data);
    return interfaceObjs?.children?.reduce((pre: any, item: any) => {
        const interfaceName = findChildrenByKey("SHORT-NAME", item)?.attributes?.innerText;
        const dataTypeObj = findChildrenByKey("DATA-ELEMENTS", item);
        const dataElement = findChildrenByKey("SHORT-NAME", dataTypeObj)?.attributes?.innerText;
        const dataType = findChildrenByKey("TYPE-TREF", dataTypeObj)?.attributes?.innerText?.split("/")?.at(-1);
        const category = findChildrenByKey("CATEGORY", dataTypeObj)?.attributes?.innerText;
        pre[dataElement] = dataType;
        return pre;
    }, {});
};

const transformComponent = (data: any, dataTypeMeta: any) => {
    const { swcName, runnables, periods, initValues, IRVMeta } = data;
    const appPorts: any[] = [];
    const runnableMapping: any[] = [];
    const IRVs: any[] = [];
    runnables.forEach((runnable: any) => {
        const { name, interfaces, irvs } = runnable;
        runnableMapping.push({
            name,
            trigger: periods[name] ? "Period" : "Init",
            periodValue: periods[name],
            task: ""
        });
        interfaces.forEach((item: any) => {
            const { dataElement, port } = item;
            appPorts.push({
                swcName,
                runnable: name,
                portName: port.name,
                portType: port.type,
                dataElement,
                dataType: dataTypeMeta[dataElement],
                // initValue: initValues[dataElement],
                connections: [
                    {
                        target: "",
                        connected: false
                    }
                ]
            });
        });

        irvs.forEach((item: any) => {
            const { dataElement, type } = item;
            IRVs.push({
                swcName,
                runnable: name,
                type,
                dataElement,
                dataType: IRVMeta.dataTypeMeta[dataElement],
                initValue: IRVMeta.initValues[dataElement]
            });
        });
    });
    return {
        appPorts,
        runnableMapping,
        IRVs
    };
};

export const extractSwcs = async (
    paths: [
        {
            interfaceFile: string;
            dataTypeFile: string;
            componentFile: string;
        }
    ]
) => {
    const swcs = await Promise.all(paths.map(async (pathGroup) => {
        const { interfaceFile, dataTypeFile: datatypeFile, componentFile } = pathGroup;
        const jsonDatas = await Promise.all([
            readFile(interfaceFile).then(parseXML),
            readFile(datatypeFile).then(parseXML),
            readFile(componentFile).then(parseXML)
        ]);
        const [interfaceJson, dataTypeJson, componentJson] = jsonDatas;
        const dataTypeMeta = extractDataTypeMeta(interfaceJson);
        const dataType = extractDataType(dataTypeJson);
        const component = extractComponent(componentJson);
        const swc = transformComponent(component, dataTypeMeta);
        return {
            dataType,
            swc
        };
    }));
    return swcs;
};
