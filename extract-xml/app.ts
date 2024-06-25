// @ts-ignore
import componentJson from "./out/control_swc_sweep_component.json";
import datatypeJson from "./out/control_swc_sweep_datatype.json";
import interfaceJson from "./out/control_swc_sweep_interface.json";
import { extractDatatype, extractDatatypeInterface, extractSWC, parseXML, readFile, writeFile } from "./src/utils";

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
writeFile("./out/swc.json", JSON.stringify(swc, null, 2));

const datatype = extractDatatype(datatypeJson);
// console.info(datatype.map((item: any) => item.name));
writeFile("./out/datatype.json", JSON.stringify(datatype, null, 2));

const interfaces = extractDatatypeInterface(interfaceJson);
// console.info(interfaces.map((item: any) => `${item.dataElement} - ${item.dataType}`));
writeFile("./out/datatypeInterfaces.json", JSON.stringify(interfaces, null, 2));

const DATAELEMENT_INITVALUE = [
    'J6LCANRxInp',
    'LocalizationInfo',
    'PlanningInfo',
    'ADMInfoSOC2MCU',
    'ChassisInp',
    'ADMInfoMCU2SOC',
    'CtrlDebugInfoMCU2SOC',
    'J6LCANTxOutp'
  ]

const DATAELEMENT_DATATYPE = [
    "J6LCANRxInp - J6L_RxBus",
    "LocalizationInfo - LocalizationInfo",
    "PlanningInfo - PlanningInfo",
    "ADMInfoSOC2MCU - ADMInfoSOC2MCU",
    "ChassisInp - ChassisInfo",
    "ADMInfoMCU2SOC - ADMInfoMCU2SOC",
    "CtrlDebugInfoMCU2SOC - CtrlInfoMCU2SOC",
    "J6LCANTxOutp - J6L_TxBus"
];

const DATATYPE = [
    "J6L_RxBus",
    "Float",
    "LocalizationInfo",
    "UInt32",
    "Double",
    "rt_Array_Float_3",
    "rt_Array_Float_4",
    "rt_Array_Double_3",
    "PlanningInfo",
    "TrajectoryPoint",
    "rt_Array_Float_100",
    "PathPoint",
    "VehicleSignal",
    "ADMInfoSOC2MCU",
    "ChassisInfo",
    "SInt32",
    "ADMInfoMCU2SOC",
    "CtrlInfoMCU2SOC",
    "J6L_TxBus",
    "BusLatCtrl",
    "Boolean",
    "BusEM",
    "BusCRM",
    "BusADM",
    "UInt8",
    "BusLongCtrl",
    "BusVSE",
    "SInt8",
    "Double_const",
    "Float_const",
    "rt_Array_Float_22",
    "rt_Array_Float_22_const",
    "rt_Array_Float_292",
    "rt_Array_Float_292_const",
    "rt_Array_Float_25",
    "rt_Array_Float_25_const",
    "rt_Array_Float_7",
    "rt_Array_Float_7_const",
    "rt_Array_Float_5",
    "rt_Array_Float_5_const",
    "rt_Array_Float_2",
    "rt_Array_Float_2_const",
    "rt_Array_Float_9",
    "rt_Array_Float_9_const",
    "rt_Array_Float_8",
    "rt_Array_Float_8_const",
    "UInt16",
    "UInt16_const",
    "Boolean_const",
    "UInt8_const"
];
