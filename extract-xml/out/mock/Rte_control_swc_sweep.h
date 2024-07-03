

/**
 * ********************************************************************************************************************
 * @file Rte_control_swc_sweep.h
 * @brief Rte Interface for control_swc_sweep.
 * @author zhito 
 * @version 1.0.0
 * @date 2024-07-03 11:40:21
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
extern VAR(ADMInfoSOC2MCU, RTE_VAR_INIT_NOCACHE) Rte_control_swc_sweep_ADMInfoSOC2MCU_oADMInfoSOC2MCU;
extern VAR(ChassisInfo, RTE_VAR_INIT_NOCACHE) Rte_control_swc_sweep_ChassisInp_oChassisInp;
extern VAR(J6L_RxBus, RTE_VAR_INIT_NOCACHE) Rte_control_swc_sweep_J6LCANRxInp_oJ6LCANRxInp;
extern VAR(PlanningInfo, RTE_VAR_INIT_NOCACHE) Rte_control_swc_sweep_PlanningInfo_oPlanningInfo;
extern VAR(ChassisInfo, RTE_VAR_INIT_NOCACHE) Rte_control_swc_sweep_ChassisInp_oChassisInp;
extern VAR(LocalizationInfo, RTE_VAR_INIT_NOCACHE) Rte_control_swc_sweep_LocalizationInfo_oLocalizationInfo;
extern VAR(PlanningInfo, RTE_VAR_INIT_NOCACHE) Rte_control_swc_sweep_PlanningInfo_oPlanningInfo;
extern VAR(ChassisInfo, RTE_VAR_INIT_NOCACHE) Rte_control_swc_sweep_ChassisInp_oChassisInp;
extern VAR(PlanningInfo, RTE_VAR_INIT_NOCACHE) Rte_control_swc_sweep_PlanningInfo_oPlanningInfo;
extern VAR(PlanningInfo, RTE_VAR_INIT_NOCACHE) Rte_control_swc_sweep_PlanningInfo_oPlanningInfo;
extern VAR(PlanningInfo, RTE_VAR_INIT_NOCACHE) Rte_control_swc_sweep_PlanningInfo_oPlanningInfo;
extern VAR(J6L_TxBus, RTE_VAR_INIT_NOCACHE) Rte_control_swc_sweep_J6LCANTxOutp_oJ6LCANTxOutp;
extern VAR(ADMInfoMCU2SOC, RTE_VAR_INIT_NOCACHE) Rte_control_swc_sweep_ADMInfoMCU2SOC_oADMInfoMCU2SOC;
extern VAR(CtrlInfoMCU2SOC, RTE_VAR_INIT_NOCACHE) Rte_control_swc_sweep_CtrlDebugInfoMCU2SOC_oCtrlDebugInfoMCU2SOC;



extern VAR(BusEM, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_EMOutp_oEMOutp;
extern VAR(BusEM, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_EMOutp_oEMOutp;
extern VAR(BusADM, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_ADMOutp_oADMOutp;
extern VAR(BusVSE, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_VSEOutp_oVSEOutp;
extern VAR(BusVSE, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_VSEOutp_oVSEOutp;
extern VAR(BusCRM, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_CRMOutp_oCRMOutp;
extern VAR(BusADM, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_ADMOutp_oADMOutp;
extern VAR(BusCRM, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_CRMOutp_oCRMOutp;
extern VAR(BusVSE, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_VSEOutp_oVSEOutp;
extern VAR(BusLongCtrl, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_LongCtrlOutp_oLongCtrlOutp;
extern VAR(BusADM, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_ADMOutp_oADMOutp;
extern VAR(BusCRM, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_CRMOutp_oCRMOutp;
extern VAR(BusVSE, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_VSEOutp_oVSEOutp;
extern VAR(BusLatCtrl, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_LatCtrlOutp_oLatCtrlOutp;
extern VAR(BusADM, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_ADMOutp_oADMOutp;
extern VAR(BusLatCtrl, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_LatCtrlOutp_oLatCtrlOutp;
extern VAR(BusLongCtrl, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_LongCtrlOutp_oLongCtrlOutp;



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

#define Rte_IRead_CRM_20ms_PlanningInfo_oPlanningInfo()  \
  (&Rte_Irv_control_swc_sweep_PlanningInfo_oPlanningInfo)

#define Rte_IRead_LongCtrl_20ms_ChassisInp_oChassisInp()  \
  (&Rte_Irv_control_swc_sweep_ChassisInp_oChassisInp)

#define Rte_IRead_LongCtrl_20ms_PlanningInfo_oPlanningInfo()  \
  (&Rte_Irv_control_swc_sweep_PlanningInfo_oPlanningInfo)

#define Rte_IRead_LatCtrl_20ms_PlanningInfo_oPlanningInfo()  \
  (&Rte_Irv_control_swc_sweep_PlanningInfo_oPlanningInfo)

#define Rte_IRead_Tx_20ms_PlanningInfo_oPlanningInfo()  \
  (&Rte_Irv_control_swc_sweep_PlanningInfo_oPlanningInfo)

#define Rte_IWrite_Tx_20ms_J6LCANTxOutp_oJ6LCANTxOutp(data)  \
( \
  Rte_Irv_control_swc_sweep_J6LCANTxOutp_oJ6LCANTxOutp = *(data) \
)

#define Rte_IWrite_Tx_20ms_ADMInfoMCU2SOC_oADMInfoMCU2SOC(data)  \
( \
  Rte_Irv_control_swc_sweep_ADMInfoMCU2SOC_oADMInfoMCU2SOC = *(data) \
)

#define Rte_IWrite_Tx_20ms_CtrlDebugInfoMCU2SOC_oCtrlDebugInfoMCU2SOC(data)  \
( \
  Rte_Irv_control_swc_sweep_CtrlDebugInfoMCU2SOC_oCtrlDebugInfoMCU2SOC = *(data) \
)



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

#define Rte_IrvIRead_CRM_20ms_VSEOutp()  \
  (&Rte_Irv_control_swc_sweep_VSEOutp_oVSEOutp)

#define Rte_IrvIWrite_CRM_20ms_CRMOutp(data)  \
(  \
  Rte_Irv_control_swc_sweep_CRMOutp_oCRMOutp = *(data) \
)

#define Rte_IrvIRead_LongCtrl_20ms_ADMOutp()  \
  (&Rte_Irv_control_swc_sweep_ADMOutp_oADMOutp)

#define Rte_IrvIRead_LongCtrl_20ms_CRMOutp()  \
  (&Rte_Irv_control_swc_sweep_CRMOutp_oCRMOutp)

#define Rte_IrvIRead_LongCtrl_20ms_VSEOutp()  \
  (&Rte_Irv_control_swc_sweep_VSEOutp_oVSEOutp)

#define Rte_IrvIWrite_LongCtrl_20ms_LongCtrlOutp(data)  \
(  \
  Rte_Irv_control_swc_sweep_LongCtrlOutp_oLongCtrlOutp = *(data) \
)

#define Rte_IrvIRead_LatCtrl_20ms_ADMOutp()  \
  (&Rte_Irv_control_swc_sweep_ADMOutp_oADMOutp)

#define Rte_IrvIRead_LatCtrl_20ms_CRMOutp()  \
  (&Rte_Irv_control_swc_sweep_CRMOutp_oCRMOutp)

#define Rte_IrvIRead_LatCtrl_20ms_VSEOutp()  \
  (&Rte_Irv_control_swc_sweep_VSEOutp_oVSEOutp)

#define Rte_IrvIWrite_LatCtrl_20ms_LatCtrlOutp(data)  \
(  \
  Rte_Irv_control_swc_sweep_LatCtrlOutp_oLatCtrlOutp = *(data) \
)

#define Rte_IrvIRead_Tx_20ms_ADMOutp()  \
  (&Rte_Irv_control_swc_sweep_ADMOutp_oADMOutp)

#define Rte_IrvIRead_Tx_20ms_LatCtrlOutp()  \
  (&Rte_Irv_control_swc_sweep_LatCtrlOutp_oLatCtrlOutp)

#define Rte_IrvIRead_Tx_20ms_LongCtrlOutp()  \
  (&Rte_Irv_control_swc_sweep_LongCtrlOutp_oLongCtrlOutp)


#endif
