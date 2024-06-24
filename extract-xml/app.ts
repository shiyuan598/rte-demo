// @ts-ignore
import arxml2json from "./out/control_swc_sweep_component.json";
import { extractSWC, parseXML, readFile, writeFile } from "./src/utils";

let inPath = "./xml/control_swc_sweep_component.arxml";
let outPath = "./out/control_swc_sweep_component.json";

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

const swc = extractSWC(arxml2json);

writeFile("./out/swc.json", JSON.stringify(swc, null, 2));


