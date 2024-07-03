import { Rte_CDD_h, Rte_SWC_h, Rte_OsApplication_CoreX_c } from './template';
// @ts-ignore
import swcJson from "../out/mock/swcs.json";
import cddJson from "../out/mock/cdds.json";
import taskJson from "../out/mock/task.json";
import dataTypeJson from "../out/mock/datatype.json";
import { writeFile } from "./utils";
import { Rte_Type_h } from "./template";

const findCoreId = (taskName: string) => {
    // @ts-ignore
    return taskJson["Task"][taskName]["data"]["cpuId"];
};
const findTask = (runnable: string, runnables: { name: string; task: string }[]) => {
    return runnables.find((item) => item.name === runnable)?.task;
};

const findCoreIdByRunnable = (runnable: string, runnables: { name: string; task: string }[]) => {
    const task = findTask(runnable, runnables);
    if (task) {
        return findCoreId(task);
    }
    return undefined;
};

// 加上coreId, 并按照coreId分组
const addCoreId = (swc: any, targetComps: any[]) => {
    const { name, appPorts, runnableMapping, IRVs } = swc;

    // const newAppPorts: { [prop: string]: any } = {};
    const newAppPorts = appPorts.map((item: any) => {
        const coreId = findCoreIdByRunnable(item.runnable, runnableMapping);
        item["coreId"] = coreId;
        item["connections"] = item["connections"].map((conn: any) => {
            const target = targetComps.find((item) => item.name === conn.target);
            conn["coreId"] = findCoreIdByRunnable(item.runnable, target.runnableMapping);
            return { ...conn };
        });
        return {...item}
        // if (newAppPorts[coreId]) {
        //     newAppPorts[coreId].push({ ...item });
        // } else {
        //     newAppPorts[coreId] = [{ ...item }];
        // }
    });

    // const newIRVs: { [prop: string]: any } = {};
    const newIRVs = IRVs?.map((item: any) => {
        const coreId = findCoreIdByRunnable(item.runnable, runnableMapping);
        item["coreId"] = coreId;
        return { ...item }
        // if (newIRVs[coreId]) {
        //     newIRVs[coreId].push({ ...item });
        // } else {
        //     newIRVs[coreId] = [{ ...item }];
        // }
    });

    return {
        name,
        appPorts: newAppPorts,
        IRVs: newIRVs,
        runnableMapping
    };
};

const prepare = (swcs: any, cdds: any, task: any, dataTypes: any) => {
    // 1.每个组件中的ports及IRVs增加coreId属性
    const swcsCoreId = swcs.map((item: any) => addCoreId(item, cdds));
    const cddsCoreId = cdds.map((item: any) => addCoreId(item, swcs));

    // console.info("swcsCoreId:", JSON.stringify(swcsCoreId, null, 2));

    // writeFile("../out/mock/swcsCoreId.json", JSON.stringify(swcsCoreId, null, 2));
    // writeFile("../out/mock/cddsCoreId.json", JSON.stringify(cddsCoreId, null, 2));

    // 2.把所有组件的ports及IRVs按照coreId分组，不用挂在组件下
    const coreMap: { [prop: string]: any } = {};
    swcsCoreId.forEach((item: {appPorts: any[]; IRVs: any[];}) => {
        const {appPorts, IRVs} = item;
        appPorts.forEach((item:any) => {
            const coreId = item.coreId;
            if (coreMap[coreId]) {
                if (coreMap[coreId].appPorts) {
                    coreMap[coreId].appPorts.push(item);
                } else {
                    coreMap[coreId].appPorts = [item];
                }
            } else {
                coreMap[coreId] = {
                    appPorts: [item]
                }
            }
        });
        IRVs.forEach((item:any) => {
            const coreId = item.coreId;
            if (coreMap[coreId]) {
                if (coreMap[coreId].IRVs) {
                    coreMap[coreId].IRVs.push(item);
                } else {
                    coreMap[coreId].IRVs = [item];
                }
            } else {
                coreMap[coreId] = {
                    IRVs: [item]
                }
            }
        });
    });

    cddsCoreId.forEach((item: {appPorts: any[];}) => {
        const {appPorts} = item;
        appPorts.forEach((item:any) => {
            const coreId = item.coreId;
            if (coreMap[coreId]) {
                if (coreMap[coreId].cddPorts) {
                    coreMap[coreId].cddPorts.push(item);
                } else {
                    coreMap[coreId].cddPorts = [item];
                }
            } else {
                coreMap[coreId] = {
                    cddPorts: [item]
                }
            }
        });
    });

    writeFile("../out/mock/CoreMap.json", JSON.stringify(coreMap, null, 2));

    // 生成代码
    // 1.生成OsApplicaton_CoreX.c -- 所有组件共用
    Object.keys(coreMap).forEach(key => {
        const value = coreMap[key];
        const codes = Rte_OsApplication_CoreX_c({
            coreId: key,
            ...value
        });
        writeFile(`../out/mock/Rte_OsApplication_Core${key}.h`, codes); 
    })

    // Done!
    // 2.生成Rte_Type.h -- 所有组件共用？
    const rteTypeCodes = Rte_Type_h({
        dataTypes,
        appPorts: swcsCoreId.reduce((pre:any[], cur: {appPorts:any}) => {
            pre.push(...cur.appPorts);
            return pre;
        }, [])
    });
    writeFile(`../out/mock/Rte_Type.h`, rteTypeCodes);

    // Done!
    // 3.生成Rte_SWC.h -- 根据组件名称会生成多个文件
    swcsCoreId.forEach((swc:any) => {
        const codes = Rte_SWC_h(swc);
        // console.info(codes);
        writeFile(`../out/mock/Rte_${swc.name}.h`, codes);
    });

    // Done!
    // 4.生成Rte_CDD.h -- 根据组件名称会生成多个文件
    cddsCoreId.forEach((cdd:any) => {
        const codes = Rte_CDD_h(cdd);
        // console.info(codes);
        writeFile(`../out/mock/Rte_${cdd.name}.h`, codes);
    });


    

};

prepare(swcJson, cddJson, taskJson, dataTypeJson);
