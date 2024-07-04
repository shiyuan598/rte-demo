import dayjs from "dayjs";
import { noRepeat } from "./utils";

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
 * 1.生成Rte_OsApplication_Core[Id].c
 * desc: 1.定义Rte变量，2.定义访问的Rte变量，3.定义Irv变量，4.定义SWC中读写Rte变量的函数，5.定义CDD中读写Rte变量的函数
 */
export const Rte_OsApplication_CoreX_c = ({coreId, appPorts=[], IRVs=[], cddPorts=[]}: {coreId:string;appPorts:any[];IRVs:any[];cddPorts:any[]}) => {
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

${/*Rte变量定义*/ ""}
${noRepeat(appPorts).map((item: any) => {
    const { dataType, swcName, portName, portType, dataElement, initValue } = item;
    return `VAR(${dataType}, RTE_VAR_INIT_NOCACHE) Rte_${swcName}_${portName}_o${dataElement} = ${initValue};\n`;
}).join("")}

${/*访问的Rte变量定义*/""}
${appPorts.map((item: any) => {
    const { dataType, portName, portType, dataElement, initValue, connected, connections } = item;
    if (connected && portType === "P-PORT") {
        return `VAR(${dataType}, RTE_VAR_INIT_NOCACHE) Rte_${portName}_o${dataElement} = ${initValue};\n`;
    }
}).join("")}

${/*IRV变量定义*/ ""}
${IRVs.map((item: any) => {
    const { swcName, type, dataElement, dataType, initValue } = item;
    if (type === "W") {
        return `VAR(${dataType}, RTE_VAR_INIT_NOCACHE) Rte_Irv_${swcName}_${dataElement}_o${dataElement} = ${initValue};\n`;
    }
}).join("")}

${/*SWC中读、写Rte变量*/ ""}
${appPorts.map((item: any) => {
    const { dataType, swcName, portName, portType, dataElement, connected, connections } = item;
    const isLock = connections.some((conn:any) => conn.coreId !== coreId);
    if (connected) {
        if (portType === "R-PORT") {
            return `
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_${swcName}_${portName}_o${dataElement}(void)
{
    Std_ReturnType ret = RTE_E_OK;
    ${
        isLock
            ? `
    Rte_DisableOSInterrupts();
    (void)GetSpinlock(Rte_Spinlock_${portName}_o${dataElement});
    (void)memcpy(&Rte_${swcName}_${portName}_o${dataElement}, &Rte_${portName}_o${dataElement}, sizeof(${dataType}));
    (void)ReleaseSpinlock(Rte_Spinlock_${portName}_o${dataElement});
    Rte_EnableOSInterrupts();`
            : `  (void)memcpy(&Rte_${swcName}_${portName}_o${dataElement}, &Rte_${portName}_o${dataElement}, sizeof(${dataType}));`
    }
    return ret;
}\n`;
        } else {
            return `
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_${swcName}_${portName}_o${dataElement}(void)
{
    Std_ReturnType ret = RTE_E_OK;
${
    isLock
        ? `
    Rte_DisableOSInterrupts();
    (void)GetSpinlock(Rte_Spinlock_${portName}_o${dataElement});
    (void)memcpy(&Rte_${portName}_o${dataElement}, &Rte_${swcName}_${portName}_o${dataElement}, sizeof(${dataType}));
    (void)ReleaseSpinlock(Rte_Spinlock_${portName}_o${dataElement});
    Rte_EnableOSInterrupts();`
        : `  (void)memcpy(&Rte_${portName}_o${dataElement}, &Rte_${swcName}_${portName}_o${dataElement}, sizeof(${dataType}));`
}
    return ret;
}\n`;
        }
    }
}).join("")}

${/*CDD中读、写Rte变量*/ ""}
${cddPorts.map((item: any) => {
    const { dataType, swcName, portName, portType, dataElement, connected, connections } = item;
    const isLock = connections.some((conn:any) => conn.coreId !== coreId);
    if (connected) {
        if (portType === "R-PORT") {
            return `
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_${swcName}_${portName}_o${dataElement}(${dataType}* data)
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
    Rte_EnableOSInterrupts();`
        : `  (void)memcpy(data, &Rte_${portName}_o${dataElement}, sizeof(${dataType}));`
}
    return ret;
}\n`;    
        } else {
            return `
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_${swcName}_${portName}_o${dataElement}(${dataType}* data)
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
        : `  (void)memcpy(&Rte_${portName}_o${dataElement}, data, sizeof(${dataType}));`
}
    return ret;
}\n`;
        }
    }
}).join("")}
`;
};

/**
 * 2.生成Rte_Type.h
 * desc: 1.定义所有类型，2.声明访问的Rte变量 -- 根据发送、接收方coreX确定是否需要声明
 */
export const Rte_Type_h = ({ dataTypes = [], appPorts=[] }:{dataTypes?: any[];appPorts?:any[]}) => {
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
${/*固定的内容*/ ""}
${`
#ifndef RTE_TYPE_H
# define RTE_TYPE_H

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

# define Rte_TypeDef_ComM_InhibitionStatusType
typedef uint8 ComM_InhibitionStatusType;

# define Rte_TypeDef_ComM_UserHandleType
typedef uint8 ComM_UserHandleType;

# define Rte_TypeDef_Csm_ConfigIdType
typedef uint16 Csm_ConfigIdType;

# define Rte_TypeDef_Dlt_ApplicationIDType
typedef uint32 Dlt_ApplicationIDType;

# define Rte_TypeDef_Dlt_ContextIDType
typedef uint32 Dlt_ContextIDType;

# define Rte_TypeDef_Dlt_MessageOptionsType
typedef uint8 Dlt_MessageOptionsType;

# define Rte_TypeDef_Dlt_SessionIDType
typedef uint32 Dlt_SessionIDType;

# define Rte_TypeDef_EcuM_TimeType
typedef uint32 EcuM_TimeType;

# define Rte_TypeDef_EcuM_UserType
typedef uint8 EcuM_UserType;

# define Rte_TypeDef_FiM_FunctionIdType
typedef uint8 FiM_FunctionIdType;

# define Rte_TypeDef_Serial_Num
typedef uint32 Serial_Num;

# define Rte_TypeDef_TimeInMicrosecondsType
typedef uint32 TimeInMicrosecondsType;

# define Rte_TypeDef_WdgM_CheckpointIdType
typedef uint16 WdgM_CheckpointIdType;

# define Rte_TypeDef_WdgM_ModeType
typedef uint8 WdgM_ModeType;

# define Rte_TypeDef_WdgM_SupervisedEntityIdType
typedef uint16 WdgM_SupervisedEntityIdType;

# define Rte_TypeDef_BswM_ESH_Mode
typedef uint8 BswM_ESH_Mode;

# define Rte_TypeDef_BswM_ESH_RunRequest
typedef uint8 BswM_ESH_RunRequest;

# define Rte_TypeDef_ComM_ModeType
typedef uint8 ComM_ModeType;

# define Rte_TypeDef_Crypto_KeyElementType
typedef uint32 Crypto_KeyElementType;

# define Rte_TypeDef_Crypto_OperationModeType
typedef uint8 Crypto_OperationModeType;

# define Rte_TypeDef_Crypto_VerifyResultType
typedef uint8 Crypto_VerifyResultType;

# define Rte_TypeDef_Csm_ResultType
typedef uint8 Csm_ResultType;

# define Rte_TypeDef_Csm_VerifyResultType
typedef uint8 Csm_VerifyResultType;

# define Rte_TypeDef_Dcm_CommunicationModeType
typedef uint8 Dcm_CommunicationModeType;

# define Rte_TypeDef_Dcm_ConfirmationStatusType
typedef uint8 Dcm_ConfirmationStatusType;

# define Rte_TypeDef_Dcm_ControlDtcSettingType
typedef uint8 Dcm_ControlDtcSettingType;

# define Rte_TypeDef_Dcm_DiagnosticSessionControlType
typedef uint8 Dcm_DiagnosticSessionControlType;

# define Rte_TypeDef_Dcm_EcuResetType
typedef uint8 Dcm_EcuResetType;

# define Rte_TypeDef_Dcm_NegativeResponseCodeType
typedef uint8 Dcm_NegativeResponseCodeType;

# define Rte_TypeDef_Dcm_OpStatusType
typedef uint8 Dcm_OpStatusType;

# define Rte_TypeDef_Dcm_ProtocolType
typedef uint8 Dcm_ProtocolType;

# define Rte_TypeDef_Dcm_RequestKindType
typedef uint8 Dcm_RequestKindType;

# define Rte_TypeDef_Dcm_SecLevelType
typedef uint8 Dcm_SecLevelType;

# define Rte_TypeDef_Dcm_SesCtrlType
typedef uint8 Dcm_SesCtrlType;

# define Rte_TypeDef_Dlt_GlobalStateType
typedef uint8 Dlt_GlobalStateType;

# define Rte_TypeDef_Dlt_MessageLogLevelType
typedef uint8 Dlt_MessageLogLevelType;

# define Rte_TypeDef_EcuM_BootTargetType
typedef uint8 EcuM_BootTargetType;
# define Rte_TypeDef_EcuM_ModeType
typedef uint8 EcuM_ModeType;
# define Rte_TypeDef_EcuM_ShutdownCauseType
typedef uint8 EcuM_ShutdownCauseType;
# define Rte_TypeDef_EcuM_StateType
typedef uint8 EcuM_StateType;

# define Rte_TypeDef_Double
typedef float64 Double;
# define Rte_TypeDef_Float
typedef float32 Float;
# define Rte_TypeDef_SInt16
typedef sint16 SInt16;
# define Rte_TypeDef_SInt32
typedef sint32 SInt32;
# define Rte_TypeDef_SInt8
typedef sint8 SInt8;
# define Rte_TypeDef_UInt16
typedef uint16 UInt16;
# define Rte_TypeDef_UInt32
typedef uint32 UInt32;
# define Rte_TypeDef_UInt8
typedef uint8 UInt8;
# define Rte_TypeDef_ByteDataBuffer
typedef struct
{
  uint16 DataBufferSize;
  uint32 DataBufferPtr;
} ByteDataBuffer;

typedef unsigned int Rte_BitType;
typedef struct
{
  Rte_BitType Rte_ModeSwitchAck_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode_Ack : 1;
  Rte_BitType Rte_ModeSwitchAck_Dcm_DcmControlDtcSetting_DcmControlDtcSetting_Ack : 1;
  Rte_BitType Rte_ModeSwitchAck_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Ack : 1;
  Rte_BitType Rte_ModeSwitchAck_Dcm_DcmEcuReset_DcmEcuReset_Ack : 1;
} Rte_OsApplication_NonTrusted_Core0_AckFlagsType;

`}

${dataTypes.map((item: any) => {
    const {name, category, typeRef, length, subElements} = item;
    const typeMapping: any = {
        Boolean: "boolean",
        UInt8: "uint8",
        SInt8: "sint8",
        UInt16: "uint16", 
        SInt16: "sint16", 
        UInt32: "uint32",
        SInt32: "sint32",
        Float: "float32",
        Double: "float64"
    };
    
    switch (category) {
        case "VALUE":
            const types = ["boolean", "uint8", "sint8", "uint16", "sint16", "uint32", "sint32", "float32", "float64"];
            if (types.includes(typeRef)) {
                return;
            } else {
                return `
# define Rte_TypeDef_${name}
typedef ${typeMapping[typeRef]} ${name};
`;
            }
        case "ARRAY":
            return `
# define Rte_TypeDef_${name}
typedef ${typeMapping[subElements[0].typeRef]} ${name}[${length}];
`;
        case "STRUCTURE":
            return `
# define Rte_TypeDef_${name}
typedef struct
{
${
    subElements.map((ele:any) => {
        const {name, typeRef} = ele;
        if (typeMapping[typeRef]) {
            return `  ${typeMapping[typeRef]} ${name};`;
        } else {
            const match = dataTypes.filter(item => item.name === typeRef)[0];
            const {category, length, subElements} = match;
            if (category === "STRUCTURE") {
                return `  ${typeRef} ${name};`;
            } else {
                return `  ${typeMapping[subElements[0].typeRef]} ${name}[${length}];`;
            }
        }
    }).join("\n")
}            
} ${name};
`;
        default:
            break;
    }
}).join("")}

${/*声明访问的Rte变量*/''}
${
    appPorts.map((item: any) => {
        const { dataType, swcName, portName, portType, coreId, dataElement, connected, connections } = item;
        const isLock = connections.some((conn: any) => conn.coreId !== coreId);
        if (connected && isLock && portType === "P-PORT") {
            return `extern VAR(${dataType}, RTE_VAR_INIT_NOCACHE) Rte_${portName}_o${dataElement};\n`;
        }
    }).join("")
}

#endif
`;
};

/**
 * 3.生成Rte_[SWC].h
 * desc: 1.声明Rte变量，2.声明Irv变量，3.定义Rte变量读写接口，4.定义Irv变量读写接口
 */
export const Rte_SWC_h = ({ 
    name = "control_swc_sweep", appPorts = [], IRVs = [], cddPorts=[] }) => {
    return `
${`
/**
 * ********************************************************************************************************************
 * @file Rte_${name}.h
 * @brief Rte Interface for ${name}.
 * @author zhito 
 * @version 1.0.0
 * @date ${getDateTime()}
 * @copyright Copyright (c) Zhito Co., Ltd. 2020-2035. All rights reserved.
 * ********************************************************************************************************************
 */
`}
#ifndef RTE_${name.toUpperCase()}_H
#define RTE_${name.toUpperCase()}_H

#include "Rte_Type.h"

${/*Rte变量声明*/ ""}
${noRepeat(appPorts).map((item: any) => {
    const { dataType, swcName, portName, portType, dataElement } = item;
    return `extern VAR(${dataType}, RTE_VAR_INIT_NOCACHE) Rte_${swcName}_${portName}_o${dataElement};\n`;
}).join("")}

${/*IRV变量声明*/ ""}
${IRVs.map((item: any) => {
    const { swcName, type, dataElement, dataType } = item;
    if (type === "W") {
        return `extern VAR(${dataType}, RTE_VAR_INIT_NOCACHE) Rte_Irv_${swcName}_${dataElement}_o${dataElement};\n`;
    }
}).join("")}

${/*定义Rte变量读写接口*/ ""}
${appPorts.map((item: any) => {
    const { swcName, runnable, portName, portType, dataElement } = item;
    if (portType === "R-PORT") {
        return `#define Rte_IRead_${runnable}_${dataElement}_o${dataElement}()  \\
  (&Rte_Irv_${swcName}_${portName}_o${dataElement})\n`;
    } else {
        return `#define Rte_IWrite_${runnable}_${dataElement}_o${dataElement}(data)  \\
( \\
  Rte_Irv_${swcName}_${portName}_o${dataElement} = *(data) \\
)\n`;
    }
}).join("\n")}

${/*定义IRV变量读写接口*/ ""}
${IRVs.map((item: any) => {
    const { swcName, runnable, type, dataElement } = item;
    if (type === "R") {
        return `#define Rte_IrvIRead_${runnable}_${dataElement}()  \\
  (&Rte_Irv_${swcName}_${dataElement}_o${dataElement})\n`;
    } else {
        return `#define Rte_IrvIWrite_${runnable}_${dataElement}(data)  \\
(  \\
  Rte_Irv_${swcName}_${dataElement}_o${dataElement} = *(data) \\
)\n`;
    }
}).join("\n")}

#endif
`;
};

/**
 * 4.生成Rte_[CDD].h
 * desc: 声明CDD访问Rte实体函数
 */
export const Rte_CDD_h = ({name ="", appPorts=[] }:{name:string;appPorts:any[] }) => {
    return `
${`
/**
 * ********************************************************************************************************************
 * @file Rte_${name}.h
 * @brief Rte Interface for ${name}.
 * @author zhito 
 * @version 1.0.0
 * @date ${getDateTime()}
 * @copyright Copyright (c) Zhito Co., Ltd. 2020-2035. All rights reserved.
 * ********************************************************************************************************************
 */
`}
#ifndef RTE_${name.toUpperCase()}_H
#define RTE_${name.toUpperCase()}_H

#include "Rte_Type.h"

${/*CDD组件使用的Rte函数实体*/ ""}
${
    appPorts.map((item: any) => {
        const { dataType, swcName, portName, portType, coreId, dataElement, connected, connections } = item;
        const isLock = connections.some((conn: any) => conn.coreId !== coreId);
        if (connected && isLock) {
            if (portType === "R-PORT") {
                return `FUNC(Std_ReturnType, RTE_CODE) Rte_Read_${swcName}_${portName}_o${dataElement}(${dataType}* data);\n`;
            } else {
                return `FUNC(Std_ReturnType, RTE_CODE) Rte_Write_${swcName}_${portName}_o${dataElement}(${dataType}* data);\n`;
            }
        }
    }).join("")
}
#endif
`;
};
