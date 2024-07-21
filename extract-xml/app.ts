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
    writeFile,
    deepMerge,
    extractMember
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

swcs.then((v) => {
    // console.info(v[0].dataType);
    writeFile("./out/swcs.json", JSON.stringify(v, null, 2));
});

const newObj = {
    d: [
        {
            name: "rt_Array_Float_3",
            category: "ARRAY",
            length: "4",
            a: "32",
            subElements: [
                {
                    name: "rt_Array_Float_3",
                    category: "TYPE_REFERENCE",
                    typeRef: "Float"
                }
            ],
            subElements2: [
                {
                    name: "rt_Array_Float_3",
                    category: "TYPE_REFERENCE",
                    typeRef: "Float"
                }
            ]
        }
    ]
};

const oldObj = {
    d: [
        {
            name: "rt_Array_Float_3",
            category: "ARRAY",
            length: "5",
            b: "433",
            subElements: [
                {
                    name: "rt_Array_Float_3",
                    category: "TYPE_REFERENCE",
                    typeRef: "Float"
                }
            ]
        }
    ]
};

// 1.同样的属性取新值
// 2.新增加的属性要保留
// 3.相比旧对象，没有的属性，也就是用户添加的属性要保留 -- 

const res = deepMerge(newObj, oldObj);
console.info(JSON.stringify(res, null, 4));

// const values = "{0U, 0U, 0U, 0U, 0U, 0.0, 0.0F, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, 0.0F, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, 0.0, 0U, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, 0.0, 0.0, 0.0}"
const values = "{0.0, 0.0F, {0.0F, 0.0F, 0.0F}, 0U, {0.0, 0.0, 0U, {0.0, 0U}}, 0.0}"
const members = extractMember(values)
console.info("members:", members);

// "{0.0, 0.0F, {0.0F, 0.0F, 0.0F}, 0U}" 转换为
// ['0.0', "0.0F", "{0.0F, 0.0F, 0.0F}", "0U"]

// "{0.0, 0.0F, {0.0F, 0.0F, 0.0F}, 0U, {0.0, 0.0, 0U, {0.0, 0U}}, 0.0}"转换为
// ['0.0', "0.0F", "{0.0F, 0.0F, 0.0F}", "0U", "{0.0, 0.0, 0U, {0.0, 0U}}", "0.0"]