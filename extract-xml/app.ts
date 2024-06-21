let inPath = "./xml/control_swc_sweep_component.arxml";
let outPath = "./out/control_swc_sweep_component.json";

import { extractSWC, parseXML, parseXML2, readFile, writeFile } from "./src/utils";

// 示例 XML 字符串
const extractXml = async (inPath: string, outPath: string) => {
    const xmlString = await readFile(inPath);
    // 转换 XML 为 JS 对象
    parseXML(xmlString as string)
        .then((result) => {
            // console.log(JSON.stringify(result, null, 2));
            writeFile(outPath, JSON.stringify(result, null, 2));

        })
        .catch((err) => console.error(err));


        parseXML2(xmlString as string)
};

extractXml(inPath, outPath);

