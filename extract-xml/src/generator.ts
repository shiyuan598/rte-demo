// @ts-ignore
import swcJson from "../out/mock/swcs.json";
import cddJson from "../out/mock/cdds.json";
import taskJson from "../out/mock/task.json";
import dataTypeJson from "../out/mock/datatype.json";
import { writeFile } from "./utils";

const findCoreId = (taskName: string) => {
    // @ts-ignore
    return taskJson["Task"][taskName]["data"]["cpuId"];
};
const findTask = (runnable: string, runnables: { name: string; task: string }[]) => {
    return runnables.find((item) => item.name === runnable)?.task;
};

const findCoreIdByRunnable = (runnable: string, runnables: { name: string; task: string }[]) => {
    const task = findTask(runnable, runnables)
    if (task) {
        return findCoreId(task)
    }
    return undefined;
}

const addCoreId = (swc: any, targetComps: any[]) => {
    const { name, appPorts, runnableMapping, IRVs } = swc;

    const newAppPorts = appPorts.map((item:any) => {
        item["coreId"] = findCoreIdByRunnable(item.runnable, runnableMapping);
        item["connections"] = item["connections"].map((conn:any) => {
            const target = targetComps.find(item => item.name === conn.target);
            conn["coreId"] = findCoreIdByRunnable(item.runnable, target.runnableMapping)
            return {...conn};
        });
        return {...item};
    });

    const newIRVs = IRVs?.map((item:any) => {
        item["coreId"] = findCoreIdByRunnable(item.runnable, runnableMapping);
        return {...item};
    });

    // 按照coreId分组


    return {
        name,
        appPorts: newAppPorts,
        IRVs: newIRVs,
        runnableMapping
    }
}

const prepare = (swcs:any, cdds:any, task:any, dataType:any) => {
    const swcsCoreId = swcs.map((item:any) => addCoreId(item, cdds));
    const cddsCoreId = cdds.map((item:any) => addCoreId(item, swcs));


    console.info("swcsCoreId:", JSON.stringify(swcsCoreId, null, 2));

    // 按照coreId分组


    writeFile("../out/swcsCoreId.json", JSON.stringify(swcsCoreId, null, 2));
    writeFile("../out/cddsCoreId.json", JSON.stringify(cddsCoreId, null, 2));
}

prepare(swcJson, cddJson, taskJson, dataTypeJson);

const separateSwcByCore = (swc: any) => {
    const { name, appPorts, runnableMapping, IRVs } = swc;

    const portCoreMap: {[prop:string]: any[]} = {}

    appPorts.forEach((port: any) => {

    });
};
