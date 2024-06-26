/**
 * ********************************************************************************************************************
 * @file Rte_IDC.h
 * @brief Rte Interface for IDC
 * @author zhito 
 * @version 1.0.0
 * @date 2023-12-11 13:21:55
 * @copyright Copyright (c) Zhito Co., Ltd. 2020-2035. All rights reserved.
 * ********************************************************************************************************************
 */
#ifndef RTE_IDC_H
#define RTE_IDC_H

#include "Rte_Type.h"

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IDC_RxSocAdminData_oRxSocAdminData(RxSocAdminDataType* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IDC_chassis_info_ochassis_info(Chassis_Info_Type* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IDC_TxSocAdminData_oTxSocAdminData(TxSocAdminDataType* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IDC_ADMInfoSOC2MCU_oADMInfoSOC2MCU(ADMInfoSOC2MCU* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IDC_PlanningInfo_oPlanningInfo(PlanningInfo* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IDC_LocalizationInfo_oLocalizationInfo(LocalizationInfo* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IDC_ADMInfoMCU2SOC_oADMInfoMCU2SOC(ADMInfoMCU2SOC* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IDC_CtrlDebugInfoMCU2SOC_oCtrlDebugInfoMCU2SOC(CtrlInfoMCU2SOC* data);

#endif
