/**
 * ********************************************************************************************************************
 * @file Rte_control_swc_sweep.h
 * @brief Rte Interface for control_swc_sweep.
 * @author zhito 
 * @version 1.0.0
 * @date 2023-12-19 13:21:55
 * @copyright Copyright (c) Zhito Co., Ltd. 2020-2035. All rights reserved.
 * ********************************************************************************************************************
 */
#ifndef RTE_CONTROL_SWC_SWEEP_H
#define RTE_CONTROL_SWC_SWEEP_H

#include "Rte_Type.h"

extern VAR(ADMInfoSOC2MCU, RTE_VAR_NOINIT_NOCACHE) Rte_control_swc_sweep_ADMInfoSOC2MCU_oADMInfoSOC2MCU;

extern VAR(ChassisInfo, RTE_VAR_NOINIT_NOCACHE) Rte_control_swc_sweep_ChassisInp_oChassisInp;

extern VAR(J6L_RxBus, RTE_VAR_NOINIT_NOCACHE) Rte_control_swc_sweep_J6LCANRxInp_oJ6LCANRxInp;

extern VAR(PlanningInfo, RTE_VAR_NOINIT_NOCACHE) Rte_control_swc_sweep_PlanningInfo_oPlanningInfo;

extern VAR(LocalizationInfo, RTE_VAR_NOINIT_NOCACHE) Rte_control_swc_sweep_LocalizationInfo_oLocalizationInfo;

extern VAR(J6L_TxBus, RTE_VAR_NOINIT_NOCACHE) Rte_control_swc_sweep_J6LCANTxOutp_oJ6LCANTxOutp;

extern VAR(ADMInfoMCU2SOC, RTE_VAR_NOINIT_NOCACHE) Rte_control_swc_sweep_ADMInfoMCU2SOC_oADMInfoMCU2SOC;

extern VAR(CtrlInfoMCU2SOC, RTE_VAR_NOINIT_NOCACHE) Rte_control_swc_sweep_CtrlDebugInfoMCU2SOC_oCtrlDebugInfoMCU2SOC;

extern VAR(BusEM, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_EMOutp_oEMOutp;

extern VAR(BusADM, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_ADMOutp_oADMOutp;

extern VAR(BusVSE, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_VSEOutp_oVSEOutp;

extern VAR(BusCRM, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_CRMOutp_oCRMOutp;

extern VAR(BusLatCtrl, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_LatCtrlOutp_oLatCtrlOutp;

extern VAR(BusLongCtrl, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_LongCtrlOutp_oLongCtrlOutp;

#define Rte_IRead_EM_20ms_ADMInfoSOC2MCU_ADMInfoSOC2MCU()  \
  (&Rte_con