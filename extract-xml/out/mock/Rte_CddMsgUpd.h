

/**
 * ********************************************************************************************************************
 * @file Rte_CddMsgUpd.h
 * @brief Rte Interface for CddMsgUpd.
 * @author zhito 
 * @version 1.0.0
 * @date 2024-07-03 11:40:21
 * @copyright Copyright (c) Zhito Co., Ltd. 2020-2035. All rights reserved.
 * ********************************************************************************************************************
 */

#ifndef RTE_CDDMSGUPD_H
#define RTE_CDDMSGUPD_H

#include "Rte_Type.h"


FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_ADMInfoSOC2MCU_oADMInfoSOC2MCU(ADMInfoSOC2MCU* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6LCANRxInp_oJ6LCANRxInp(J6L_RxBus* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_LocalizationInfo_oLocalizationInfo(LocalizationInfo* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_PlanningInfo_oPlanningInfo(PlanningInfo* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_ADMInfoSOC2MCU_oADMInfoSOC2MCU(ADMInfoSOC2MCU* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_ChassisInp_oChassisInp(ChassisInfo* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6LCANRxInp_oJ6LCANRxInp(J6L_RxBus* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_PlanningInfo_oPlanningInfo(PlanningInfo* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_ChassisInp_oChassisInp(ChassisInfo* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_LocalizationInfo_oLocalizationInfo(LocalizationInfo* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_PlanningInfo_oPlanningInfo(PlanningInfo* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_ChassisInp_oChassisInp(ChassisInfo* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_PlanningInfo_oPlanningInfo(PlanningInfo* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_PlanningInfo_oPlanningInfo(PlanningInfo* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_PlanningInfo_oPlanningInfo(PlanningInfo* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6LCANTxOutp_oJ6LCANTxOutp(J6L_TxBus* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_ADMInfoMCU2SOC_oADMInfoMCU2SOC(ADMInfoMCU2SOC* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_CtrlDebugInfoMCU2SOC_oCtrlDebugInfoMCU2SOC(CtrlInfoMCU2SOC* data);

#endif        
