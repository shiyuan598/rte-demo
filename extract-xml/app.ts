// @ts-ignore
import componentJson from "./out/control_swc_sweep_component.json";
import dataTypeJson from "./out/control_swc_sweep_datatype.json";
import interfaceJson from "./out/control_swc_sweep_interface.json";
import { Rte_CDD_h, Rte_OsApplication_CoreX_c, Rte_Type_h } from "./src/template";
import {
    extractDataType,
    extractDataTypeMeta,
    extractComponent,
    extractSwcs,
    orderDataType,
    parseXML,
    readFile,
    writeFile
} from "./src/utils";

const swcs = extractSwcs([
    {
        interfaceFile: "./xml/control_swc_sweep_interface.arxml",
        dataTypeFile: "./xml/control_swc_sweep_datatype.arxml",
        componentFile: "./xml/control_swc_sweep_component.arxml"
    }
]);
// swcs.then(console.info)

// const d = extractDataType(dataTypeJson);
// console.info(d);
// writeFile("./out/datatype2.json", JSON.stringify(d, null, 2));

swcs.then(v => {
    // console.info(v[0].dataType);
    const codes = Rte_Type_h({dataTypes: v[0].dataType});
    console.info(codes);
    writeFile("./out/Rte_Type.h", codes);
})

