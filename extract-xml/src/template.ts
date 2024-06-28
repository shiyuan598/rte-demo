import dayjs from "dayjs";

const getDateTime = () => {
    return dayjs().format("YYYY-MM-DD HH:mm:ss");
};

// 一、Ports、runnableMapping
// 【1.1定义Rte变量】:
// 来源于Ports: swc, runnable(portName, portType, dataElement, dataType, initValue, runnable, connection: [{cdd01, TASK_COREID}, {cdd02, TASK_COREID}]), task-coreId
// VAR(${dataType}, RTE_VAR_INIT_NOCACHE) Rte_${swc}_${portName}_o${dataElement} = ${initValue};

// 数据：Ports数组.connected
// source: {swc, portType, dataElement, dataType, task-coreId }, target: {cdd, portType, dataElement, dataType, TASK_COREID }
// 或者： [{cdd, portType, dataElement, dataType, TASK_COREID }]
// 【1.2定义访问的Rte变量】:
// 来源于Ports: P-Port时查看connection，定义在和coreId相同的文件中, 如何确定接收、发送同核以确定是否需要在Rte_type.h声明？

// -- Task来源于Runnable的配置runnableMapping

// 二、IRVs数组
// 【1.3定义Irv变量】
// swc, irvs(dataElement, dataType, initValue), runnable, task-coreId

// 【1.4定义SWC中读写Rte变量的函数】

// 三、CDD连接数据 - 参考SWC Ports
// 【1.5定义CDD中读写Rte变量的函数】
// 连接：swc - cdd
// cdd - swc 以及cdd - cdd


// 生成Rte_OsApplication_Core[Id].c时将Ports按照task-coreId分组 ！！

// 四、datatype数据
// 【2.1所有datatype定义】
// 【2.2声明访问的Rte变量】-- 根据【1.2定义访问的Rte变量】数据：Ports数组.connected

// 【3.1声明Rte变量】-- 根据【1.1定义Rte变量】Rtes数据
// 【3.2声明Irv变量】-- 根据【1.3定义Irv变量】Irvs数据
// 【3.3】定义Rte变量读写接口 -- 根据【1.1定义Rte变量】Rtes数据
// 【3.4】定义Irv变量读写接口 -- 根据【1.3定义Irv变量】Irvs数据

// 【4.1声明CDD访问Rte实体函数】-- 根据【1.5定义CDD中读写Rte变量的函数】

/**
 * 生成Rte_OsApplication_Core[Id].c
 * desc: 1.定义Rte变量，2.定义访问的Rte变量，3.定义Irv变量，4.定义SWC中读写Rte变量的函数，5.定义CDD中读写Rte变量的函数
 */
export const Rte_OsApplication_CoreX_c = ({
    coreId = 3,
    rteVariables = [],
    vRteVariables = [],
    irvVariables = [],
    readFuncs = [],
    writeFuncs = []
}) => {
    return `
${`
/**
 * ********************************************************************************************************************
 * @file Rte_OsApplication_Core${coreId}.c
 * @brief Rte Interface for OsApplication_Core${coreId}
 * @author zhito 
 * @version 1.0.0
 * @date ${getDateTime()}
 * @copyright Copyright (c) Zhito Co., Ltd. 2020-2035. All rights reserved.
 * ********************************************************************************************************************
 */
`}
#include "shared.h"
#include "IDC.h"
#include "Rte_${"control_swc_sweep"}.h"
#include "Rte_${"CddMsgUpd"}.h"
#include "ee_oo_api_osek.h"

${/*Rte变量*/ ""}
${rteVariables.map((item: any) => {
    const { dataType, swc, portName, dataElement, initValue } = item;
    return `VAR(${dataType}, RTE_VAR_INIT_NOCACHE) Rte_${swc}_${portName}_o${dataElement} = ${initValue};\n`;
}).join("\n")}

${/*访问的Rte变量*/ ""}
${vRteVariables.map((item: any) => {
    const { dataType, swc, portName, dataElement, initValue } = item;
    return `VAR(${dataType}, RTE_VAR_INIT_NOCACHE) Rte_${portName}_o${dataElement} = ${initValue};\n`;
}).join("\n")}

${/*IRV变量*/ ""}
${irvVariables.map((item: any) => {
    const { dataType, swc, dataElement, initValue } = item;
    return `VAR(${dataType}, RTE_VAR_INIT_NOCACHE) Rte_Irv_${swc}_${dataElement}_o${dataElement} = ${initValue};\n`;
}).join("\n")}

${/*SWC中读Rte变量*/ ""}
${readFuncs.map((item: any) => {
    const { dataType, swc, portName, dataElement, isLock } = item;
    return `
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_${swc}_${portName}_o${dataElement}(void)
{
    Std_ReturnType ret = RTE_E_OK;
${
    isLock
        ? `
    Rte_DisableOSInterrupts();
    (void)GetSpinlock(Rte_Spinlock_${portName}_o${dataElement});
    (void)memcpy(&Rte_${swc}_${portName}_o${dataElement}, &Rte_${portName}_o${dataElement}, sizeof(${dataType}));
    (void)ReleaseSpinlock(Rte_Spinlock_${portName}_o${dataElement});
    Rte_EnableOSInterrupts();
    `
        : `
    (void)memcpy(&Rte_${swc}_${portName}_o${dataElement}, &Rte_${portName}_o${dataElement}, sizeof(${dataType}));
    `
}
    return ret;
}\n`;
}).join("\n")}

${/*SWC中写Rte变量*/ ""}
${readFuncs.map((item: any) => {
    const { dataType, swc, portName, dataElement, isLock } = item;
    return `
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_${swc}_${portName}_o${dataElement}(void)
{
    Std_ReturnType ret = RTE_E_OK;
${
    isLock
        ? `
    Rte_DisableOSInterrupts();
    (void)GetSpinlock(Rte_Spinlock_${portName}_o${dataElement});
    (void)memcpy(&Rte_${portName}_o${dataElement}, &Rte_${swc}_${portName}_o${dataElement}, sizeof(${dataType}));
    (void)ReleaseSpinlock(Rte_Spinlock_${portName}_o${dataElement});
    Rte_EnableOSInterrupts();
    `
        : `
    (void)memcpy(&Rte_${portName}_o${dataElement}, &Rte_${swc}_${portName}_o${dataElement}, sizeof(${dataType}));
    `
}
    return ret;
}\n`;
}).join("\n")}

${/*CDD组件中读Rte变量*/ ""}
${readFuncs.map((item: any) => {
    const { dataType, swc, portName, dataElement, isLock } = item;
    return `
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_${swc}_${portName}_o${dataElement}(${dataType}* data)
{
    Std_ReturnType ret = RTE_E_OK;
${
    isLock
        ? `
    Rte_DisableOSInterrupts();
    (void)GetSpinlock(Rte_Spinlock_${portName}_o${dataElement});
    (void)memcpy(&Rte_${portName}_o${dataElement}, data, sizeof(${dataType}));
    *(data) = Rte_${portName}_o${dataElement};
    (void)ReleaseSpinlock(Rte_Spinlock_${portName}_o${dataElement});
    Rte_EnableOSInterrupts();
    `
        : `
    (void)memcpy(data, &Rte_${portName}_o${dataElement}, sizeof(${dataType}));
    `
}
    return ret;
}\n`;
}).join("\n")}

${/*CDD组件中写Rte变量*/ ""}
${writeFuncs.map((item: any) => {
    const { dataType, cdd, portName, dataElement, isLock } = item;
    return `
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_${cdd}_${portName}_o${dataElement}(${dataType}* data)
{
    Std_ReturnType ret = RTE_E_OK;
${
    isLock
        ? `
    Rte_DisableOSInterrupts();
    (void)GetSpinlock(Rte_Spinlock_${portName}_o${dataElement});
    Rte_${portName}_o${dataElement} = *(data);
    (void)ReleaseSpinlock(Rte_Spinlock_${portName}_o${dataElement});
    Rte_EnableOSInterrupts();
    `
        : `
    (void)memcpy(&Rte_${portName}_o${dataElement}, data, sizeof(${dataType}));
    `
}
    return ret;
}\n`;
}).join("\n")}

`;
};

/**
 * 生成Rte_Type.h
 * desc: 1.定义所有类型，2.声明访问的Rte变量 -- 根据coreX确定是否需要声明
 */
export const Rte_Type_h = ({ dataTypesByPorts = [], dataTypesByIRVs = [], vRteVariables = [] }) => {
    return `
${`
/**
 * ********************************************************************************************************************
 * @file Rte_Type.h
 * @brief Rte Type define
 * @author zhito 
 * @version 1.0.0
 * @date ${getDateTime()}
 * @copyright Copyright (c) Zhito Co., Ltd. 2020-2035. All rights reserved.
 * ********************************************************************************************************************
 */
`}
#ifndef RTE_TYPE_H
# define RTE_TYPE_H
${/*固定的内容*/ ""}
${`
#include "Platform_Types.h"
#include "Std_Types.h"
#include "ee_spinlock_Lcfg.h"
#include "Mcal_Compiler.h"

# define RTE_VAR_ZERO_INIT
# define RTE_CODE
# define RTE_VAR_NOINIT_NOCACHE
# define RTE_VAR_ZERO_INIT_NOCACHE
# define RTE_VAR_INIT_NOCACHE

# define RTE_CDDMSGUPD_APPL_VAR
# define RTE_CDDMSGUPD_APPL_DATA
# define RTE_CDDMSGUPD_APPL_CODE
# define RTE_CDDMSGUPD_APPL_CONST

# define RTE_E_OK               (0U)
# define RTE_E_INVALID          (1U)

# define RTE_STATE_UNINIT    (0U)
# define RTE_STATE_SCHM_INIT (1U)
# define RTE_STATE_INIT      (2U)

# define RTE_START_SEC_VAR_ZERO_INIT_8BIT
# include "MemMap.h"

extern volatile VAR(uint8, RTE_VAR_ZERO_INIT) Rte_InitState;
extern volatile VAR(uint8, RTE_VAR_ZERO_INIT) Rte_StartTiming_InitState;

# define RTE_STOP_SEC_VAR_ZERO_INIT_8BIT
# include "MemMap.h"

# define RTE_START_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# include "MemMap.h"

extern volatile VAR(uint8, RTE_VAR_ZERO_INIT_NOCACHE) Rte_InitState_1;

# define RTE_STOP_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# include "MemMap.h"

# define RTE_START_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# include "MemMap.h"

extern volatile VAR(uint8, RTE_VAR_ZERO_INIT_NOCACHE) Rte_InitState_2;

# define RTE_STOP_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# include "MemMap.h"

# define RTE_START_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# include "MemMap.h"

extern volatile VAR(uint8, RTE_VAR_ZERO_INIT_NOCACHE) Rte_InitState_3;

# define RTE_STOP_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# include "MemMap.h"

# define RTE_START_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# include "MemMap.h"

extern volatile VAR(uint8, RTE_VAR_ZERO_INIT_NOCACHE) Rte_InitState_4;

# define RTE_STOP_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# include "MemMap.h"

# define RTE_START_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# include "MemMap.h"

extern volatile VAR(uint8, RTE_VAR_ZERO_INIT_NOCACHE) Rte_InitState_5;

# define RTE_STOP_SEC_VAR_GLOBALSHARED_NOCACHE_ZERO_INIT_8BIT
# include "MemMap.h"
`}

${dataTypesByPorts.map((item: any) => {
    return `${item}\n`;
}).join("\n")}

${dataTypesByIRVs.map((item: any) => {
    return `${item}\n`;
}).join("\n")}

${/*声明访问的Rte变量*/''}
${vRteVariables.map((item: any) => {
    const { dataType, portName, dataElement } = item;
    return `extern VAR(${dataType}, RTE_VAR_INIT_NOCACHE) Rte_${portName}_o${dataElement};\n`;
}).join("\n")}


#endif
`;
};

/**
 * 生成Rte_[SWC].h
 * desc: 1.声明Rte变量，2.声明Irv变量，3.定义Rte变量读写接口，4.定义Irv变量读写接口
 */
export const Rte_SWC_h = ({ swc = "control_swc_sweep", Rtes = [], IRVs = [] }) => {
    return `
${`
/**
 * ********************************************************************************************************************
 * @file Rte_${swc}.h
 * @brief Rte Interface for ${swc}.
 * @author zhito 
 * @version 1.0.0
 * @date ${getDateTime()}
 * @copyright Copyright (c) Zhito Co., Ltd. 2020-2035. All rights reserved.
 * ********************************************************************************************************************
 */
`}
#ifndef RTE_${swc.toUpperCase()}_H
#define RTE_${swc.toUpperCase()}_H

#include "Rte_Type.h"

${/*Rte变量声明*/ ""}
${Rtes.map((item: any) => {
    const { dataType, swc, portName, dataElement } = item;
    return `extern VAR(${dataType}, RTE_VAR_INIT_NOCACHE) Rte_${swc}_${portName}_o${dataElement};\n`;
}).join("\n")}

${/*IRV变量声明*/ ""}
${IRVs.map((item: any) => {
    const { swc, dataElement, dataType } = item;
    return `extern VAR(${dataType}, RTE_VAR_INIT_NOCACHE) Rte_Irv_${swc}_${dataElement}_o${dataElement};\n`;
}).join("\n")}

${/*定义Rte变量读写接口*/ ""}
${Rtes.map((item: any) => {
    const { swc, runnable, portName, portType, dataElement } = item;
    if (portType === "R-Port") {
        return `
#define Rte_IRead_${runnable}_${dataElement}_o${dataElement}()  \\
(&Rte_Irv_${swc}_${portName}_o${dataElement})\n
            `;
    } else {
        return `
#define Rte_IWrite_${runnable}_${dataElement}_o${dataElement}(data)  \\
( \\
    Rte_Irv_${swc}_${portName}_o${dataElement} = *(data) \\
)\n
            `;
    }
}).join("\n")}

${/*定义IRV变量读写接口*/ ""}
${IRVs.map((item: any) => {
    const { swc, runnable, type, dataElement } = item;
    if (type === "R") {
        return `
#define Rte_IrvIRead_${runnable}_${dataElement}()  \\
(&Rte_Irv_${swc}_${dataElement}_o${dataElement})\n
            `;
    } else {
        return `
#define Rte_IrvIWrite_${runnable}_${dataElement}(data)  \\
(  \\
    Rte_Irv_${swc}_${dataElement}_o${dataElement} = *(data) \\
)\n
            `;
    }
}).join("\n")}

#endif
`;
};

/**
 * 生成Rte_[CDD].h
 * desc: 声明CDD访问Rte实体函数
 */
export const Rte_CDD_h = () => {
    const cdd = "CddMsgUpd";
    const readFuncs: any = [{dataType: "SG_CCVS1_sg", swcName: "CddMsgUpd", port: "J6L_ADUCAN_RxSignal", dataElement: "SG_CCVS1_sg"}];
    const writeFuncs: any = [{dataType: "SG_CCVS1_sg", swcName: "CddMsgUpd", port: "J6L_ADUCAN_RxSignal", dataElement: "SG_CCVS1_sg"}];
    return `
${`
/**
 * ********************************************************************************************************************
 * @file Rte_${cdd}.h
 * @brief Rte Interface for ${cdd}.
 * @author zhito 
 * @version 1.0.0
 * @date ${getDateTime()}
 * @copyright Copyright (c) Zhito Co., Ltd. 2020-2035. All rights reserved.
 * ********************************************************************************************************************
 */
`}
#ifndef RTE_${cdd.toUpperCase()}_H
#define RTE_${cdd.toUpperCase()}_H

#include "Rte_Type.h"

${/*CDD组件使用的Rte函数实体*/ ""}
${readFuncs.map((item: any) => {
    const { dataType, swcName, port, dataElement } = item;
    return `
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_${swcName}_${port}_o${dataElement}(${dataType}* data);\n`;
})}

${writeFuncs.map((item: any) => {
    const { dataType, swcName, port, dataElement } = item;
    return `
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_${swcName}_${port}_o${dataElement}(${dataType}* data);\n`;
})}

#endif        
`;
};
