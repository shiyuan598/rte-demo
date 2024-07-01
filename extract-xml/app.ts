// @ts-ignore
import componentJson from "./out/control_swc_sweep_component.json";
import dataTypeJson from "./out/control_swc_sweep_datatype.json";
import interfaceJson from "./out/control_swc_sweep_interface.json";
import { Rte_CDD_h, Rte_OsApplication_CoreX_c } from "./src/template";
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
swcs.then(console.info)
