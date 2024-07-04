

/**
 * ********************************************************************************************************************
 * @file Rte_control_swc_sweep.h
 * @brief Rte Interface for control_swc_sweep.
 * @author zhito 
 * @version 1.0.0
 * @date 2024-07-04 17:31:50
 * @copyright Copyright (c) Zhito Co., Ltd. 2020-2035. All rights reserved.
 * ********************************************************************************************************************
 */

#ifndef RTE_CONTROL_SWC_SWEEP_H
#define RTE_CONTROL_SWC_SWEEP_H

#include "Rte_Type.h"


extern VAR(ADMInfoSOC2MCU, RTE_VAR_INIT_NOCACHE) Rte_control_swc_sweep_ADMInfoSOC2MCU_oADMInfoSOC2MCU;
extern VAR(J6L_RxBus, RTE_VAR_INIT_NOCACHE) Rte_control_swc_sweep_J6LCANRxInp_oJ6LCANRxInp;
extern VAR(LocalizationInfo, RTE_VAR_INIT_NOCACHE) Rte_control_swc_sweep_LocalizationInfo_oLocalizationInfo;
extern VAR(PlanningInfo, RTE_VAR_INIT_NOCACHE) Rte_control_swc_sweep_PlanningInfo_oPlanningInfo;
extern VAR(ChassisInfo, RTE_VAR_INIT_NOCACHE) Rte_control_swc_sweep_ChassisInp_oChassisInp;



extern VAR(BusEM, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_EMOutp_oEMOutp;
extern VAR(BusADM, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_ADMOutp_oADMOutp;
extern VAR(BusVSE, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_VSEOutp_oVSEOutp;



#define Rte_IRead_EM_20ms_ADMInfoSOC2MCU_oADMInfoSOC2MCU()  \
  (&Rte_Irv_control_swc_sweep_ADMInfoSOC2MCU_oADMInfoSOC2MCU)

#define Rte_IRead_EM_20ms_J6LCANRxInp_oJ6LCANRxInp()  \
  (&Rte_Irv_control_swc_sweep_J6LCANRxInp_oJ6LCANRxInp)

#define Rte_IRead_EM_20ms_LocalizationInfo_oLocalizationInfo()  \
  (&Rte_Irv_control_swc_sweep_LocalizationInfo_oLocalizationInfo)

#define Rte_IRead_EM_20ms_PlanningInfo_oPlanningInfo()  \
  (&Rte_Irv_control_swc_sweep_PlanningInfo_oPlanningInfo)

#define Rte_IRead_ADM_20ms_ADMInfoSOC2MCU_oADMInfoSOC2MCU()  \
  (&Rte_Irv_control_swc_sweep_ADMInfoSOC2MCU_oADMInfoSOC2MCU)

#define Rte_IRead_ADM_20ms_ChassisInp_oChassisInp()  \
  (&Rte_Irv_control_swc_sweep_ChassisInp_oChassisInp)

#define Rte_IRead_ADM_20ms_J6LCANRxInp_oJ6LCANRxInp()  \
  (&Rte_Irv_control_swc_sweep_J6LCANRxInp_oJ6LCANRxInp)

#define Rte_IRead_ADM_20ms_PlanningInfo_oPlanningInfo()  \
  (&Rte_Irv_control_swc_sweep_PlanningInfo_oPlanningInfo)

#define Rte_IRead_VSE_20ms_ChassisInp_oChassisInp()  \
  (&Rte_Irv_control_swc_sweep_ChassisInp_oChassisInp)

#define Rte_IRead_VSE_20ms_LocalizationInfo_oLocalizationInfo()  \
  (&Rte_Irv_control_swc_sweep_LocalizationInfo_oLocalizationInfo)



#define Rte_IrvIWrite_EM_20ms_EMOutp(data)  \
(  \
  Rte_Irv_control_swc_sweep_EMOutp_oEMOutp = *(data) \
)

#define Rte_IrvIRead_ADM_20ms_EMOutp()  \
  (&Rte_Irv_control_swc_sweep_EMOutp_oEMOutp)

#define Rte_IrvIWrite_ADM_20ms_ADMOutp(data)  \
(  \
  Rte_Irv_control_swc_sweep_ADMOutp_oADMOutp = *(data) \
)

#define Rte_IrvIWrite_VSE_20ms_VSEOutp(data)  \
(  \
  Rte_Irv_control_swc_sweep_VSEOutp_oVSEOutp = *(data) \
)


#endif
