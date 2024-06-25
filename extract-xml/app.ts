// @ts-ignore
import componentJson from "./out/control_swc_sweep_component.json";
import datatypeJson from "./out/control_swc_sweep_datatype.json";
import interfaceJson from "./out/control_swc_sweep_interface.json";
import { extractDatatype, extractInterface, extractSWC, parseXML, readFile, writeFile } from "./src/utils";

let inPath = "./xml/control_swc_sweep_interface.arxml";
let outPath = "./out/control_swc_sweep_interface.json";

// 示例 XML 字符串
const extractXml = async (inPath: string, outPath: string) => {
    const xmlString = await readFile(inPath);
    // 转换 XML 为 JS 对象
    parseXML(xmlString as string)
        .then((result) => {
            writeFile(outPath, JSON.stringify(result, null, 2));

        })
        .catch((err) => console.error(err));
};

// extractXml(inPath, outPath);

const swc = extractSWC(componentJson);
// writeFile("./out/swc.json", JSON.stringify(swc, null, 2));


const datatype = extractDatatype(datatypeJson);
// writeFile("./out/datatype.json", JSON.stringify(datatype, null, 2));


const interfaces = extractInterface(interfaceJson);
writeFile("./out/interfaces.json", JSON.stringify(interfaces, null, 2));
