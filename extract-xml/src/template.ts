import dayjs from "dayjs";

const getDateTime = () => {
   
    return  dayjs().format("YYYY-MM-DD HH:mm:ss");
}

export const Rte_OsApplication_Corex_c = () => {
    const coreId = 3;
    const rteVariables:any = []
    const visitedRteVariables:any = []
    const irvVariables:any = []
    const readFuncs:any = []
    const writeFuncs:any = []

    return `
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
#include "shared.h"
#include "IDC.h"
#include "Rte_${"control_swc_sweep"}.h"
#include "Rte_${"CddMsgUpd"}.h"
#include "ee_oo_api_osek.h"

${rteVariables.map((item:any) => {
    const {dataType, swcName, port, dataElement, initValue} = item;
    return `VAR(${dataType}, RTE_VAR_INIT_NOCACHE) Rte_${swcName}_${port}_o${dataElement} = ${initValue};\n`;
})}

${visitedRteVariables.map((item:any) => {
    const {dataType, swcName, port, dataElement, initValue} = item;
    return `VAR(${dataType}, RTE_VAR_INIT_NOCACHE) Rte_${port}_o${dataElement} = ${initValue};\n`;
})}

${irvVariables.map((item:any) => {
    const {dataType, swcName, port, dataElement, initValue} = item;
    return `VAR(${dataType}, RTE_VAR_INIT_NOCACHE) Rte_Irv_${swcName}_${port}_o${dataElement} = ${initValue};\n`;
})}

${readFuncs.map((item:any) => {
    const {dataType, swcName, port, dataElement, initValue} = item;
    return `FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_VDC2_sg(SG_VDC2_sg* data)
    {
      Std_ReturnType ret = RTE_E_OK;
    
      Rte_DisableOSInterrupts();
      (void)GetSpinlock(Rte_Spinlock_SG_VDC2_sg_oVDC2_oJ6L_ADUCAN_Rx);
      *(data) = Rte_SG_VDC2_sg_oVDC2_oJ6L_ADUCAN_Rx;
      (void)ReleaseSpinlock(Rte_Spinlock_SG_VDC2_sg_oVDC2_oJ6L_ADUCAN_Rx);
      Rte_EnableOSInterrupts();
    
      return ret;
    }\n`;
})}

${irvVariables.map((item:any) => {
    const {dataType, swcName, port, dataElement, initValue} = item;
    return `FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_LC_ADU_sg(SG_LC_ADU_sg* data)
    {
      Std_ReturnType ret = RTE_E_OK;
    
      Rte_DisableOSInterrupts();
      (void)GetSpinlock(Rte_Spinlock_SG_LC_ADU_sg_oLC_ADU_oJ6L_ADUCAN_Tx);
      Rte_SG_LC_ADU_sg_oLC_ADU_oJ6L_ADUCAN_Tx = *(data);
      (void)ReleaseSpinlock(Rte_Spinlock_SG_LC_ADU_sg_oLC_ADU_oJ6L_ADUCAN_Tx);
      Rte_EnableOSInterrupts();
    
      return ret;
    }\n`;
})}

`;
};


export const Rte_Type_h = () => {
    const dataTypesByPorts:any = []
    return `
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

${dataTypesByPorts.map((item:any) => {
    return `${item}\n`;
})}


#endif
`;
};

export const Rte_SWC_h = () => {
    const swc = "control_swc_sweep";
    return `
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
#ifndef RTE_${swc.toUpperCase()}_H
#define RTE_${swc.toUpperCase()}_H

#include "Rte_Type.h"

${
    "rte vars"
    // extern VAR(ADMInfoSOC2MCU, RTE_VAR_NOINIT_NOCACHE) Rte_control_swc_sweep_ADMInfoSOC2MCU_oADMInfoSOC2MCU;    
}

${
    "irvs"
    // extern VAR(BusEM, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_EMOutp_oEMOutp;
}

#define Rte_IRead_LatCtrl_20ms_PlanningInfo_PlanningInfo()  \
    (&Rte_control_swc_sweep_PlanningInfo_oPlanningInfo)

#define Rte_IWrite_Tx_20ms_ADMInfoMCU2SOC_ADMInfoMCU2SOC(data)  \
    (  \
        Rte_control_swc_sweep_ADMInfoMCU2SOC_oADMInfoMCU2SOC = *(data) \
    )

#define Rte_IrvIWrite_EM_20ms_EMOutp(data)  \
(  \
    Rte_Irv_control_swc_sweep_EMOutp_oEMOutp = *(data) \
)

#define Rte_IrvIRead_ADM_20ms_EMOutp()  \
    (&Rte_Irv_control_swc_sweep_EMOutp_oEMOutp)

#endif
    

`;
};


export const Rte_CDD_h = () => {
    const cdd = "CddMsgUpd";
    return `
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
#ifndef RTE_${cdd.toUpperCase()}_H
#define RTE_${cdd.toUpperCase()}_H

#include "Rte_Type.h"

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_ChassisInp_oChassisInp(ChassisInfo* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6LCANRxInp_oJ6LCANRxInp(J6L_RxBus* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6LCANTxOutp_oJ6LCANTxOutp(J6L_TxBus* data);

#endif        
`
}