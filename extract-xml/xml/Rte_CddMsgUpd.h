/**
 * ********************************************************************************************************************
 * @file Rte_CddMsgUpd.h
 * @brief Rte Interface for CddMsgUpd.
 * @author zhito 
 * @version 1.0.0
 * @date 2023-12-19 13:21:55
 * @copyright Copyright (c) Zhito Co., Ltd. 2020-2035. All rights reserved.
 * ********************************************************************************************************************
 */
#ifndef RTE_CDDMSGUPD_H
#define RTE_CDDMSGUPD_H

#include "Rte_Type.h"

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_CCVS1_sg(SG_CCVS1_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_ETC2_sg(SG_ETC2_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_DM1_EPB_sg(SG_DM1_EPB_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_EPB1_sg(SG_EPB1_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_DM1_ABS_sg(SG_DM1_ABS_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_EBC1_sg(SG_EBC1_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_EBC2_sg(SG_EBC2_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_EBC5_sg(SG_EBC5_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_ESC1_sg(SG_ESC1_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_CVW_sg(SG_CVW_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_VDC2_sg(SG_VDC2_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_LC_ADU_sg(SG_LC_ADU_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_LC_sg(SG_LC_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_DC2_sg(SG_DC2_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_MCU1_sg(SG_MCU1_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_DM1_EPS_sg(SG_DM1_EPS_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_EPS1_ZF_sg(SG_EPS1_ZF_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_EPS2_ZF_sg(SG_EPS2_ZF_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TIRE1_sg(SG_TIRE1_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TIRE2_sg(SG_TIRE2_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TIRE3_sg(SG_TIRE3_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_DM1_TPMS_sg(SG_DM1_TPMS_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_EEC2_sg(SG_EEC2_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_TSC1_ACCE_sg(SG_TSC1_ACCE_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_XBR2_sg(SG_XBR2_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_TC1_ADU_sg(SG_TC1_ADU_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_EPB2_sg(SG_EPB2_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_ADU1_sg(SG_ADU1_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_ADU_Cmd_sg(SG_ADU_Cmd_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_VCU_Status_sg(SG_VCU_Status_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_OWW_sg(SG_OWW_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_SC_sg(SG_SC_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_BCU_sg(SG_BCU_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_HCU_BMS_sg(SG_HCU_BMS_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_BMS1_sg(SG_BMS1_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_BMS5_sg(SG_BMS5_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_VD_sg(SG_VD_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_DM1_BCM_sg(SG_DM1_BCM_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_TSC1_ACCDR_sg(SG_TSC1_ACCDR_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_EC_EM1_sg(SG_EC_EM1_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_LD_sg(SG_LD_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_BCM_Status_sg(SG_BCM_Status_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_DM1_BMS_sg(SG_DM1_BMS_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_DM1_PTU_sg(SG_DM1_PTU_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_DM1_DCDC2_sg(SG_DM1_DCDC2_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_DM1_APCU_sg(SG_DM1_APCU_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_EPSO1_sg(SG_EPSO1_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_EPSO2_sg(SG_EPSO2_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_XBR1_sg(SG_XBR1_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_EPSI1_sg(SG_EPSI1_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_EPSI2_sg(SG_EPSI2_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_FBCM_sg(SG_FBCM_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_PS1_sg(SG_PS1_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_ENGSC_FM_sg(SG_ENGSC_FM_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_ATR_FM_sg(SG_ATR_FM_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_ATS_PS_sg(SG_ATS_PS_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_Lcks_Cmd1_sg(SG_Lcks_Cmd1_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPCM_EPB_sg(SG_TPCM_EPB_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPDT_EPB_sg(SG_TPDT_EPB_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPCM_EBS_sg(SG_TPCM_EBS_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPDT_EBS_sg(SG_TPDT_EBS_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPCM_EPS_sg(SG_TPCM_EPS_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPDT_EPS_sg(SG_TPDT_EPS_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPCM_BCM_sg(SG_TPCM_BCM_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPDT_BCM_sg(SG_TPDT_BCM_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPCM_TPMS_sg(SG_TPCM_TPMS_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPDT_TPMS_sg(SG_TPDT_TPMS_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPCM_BMS_sg(SG_TPCM_BMS_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPDT_BMS_sg(SG_TPDT_BMS_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPCM_VCU_sg(SG_TPCM_VCU_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPDT_VCU_sg(SG_TPDT_VCU_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPCM_PTU_sg(SG_TPCM_PTU_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPDT_PTU_sg(SG_TPDT_PTU_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPCM_DCDC2_sg(SG_TPCM_DCDC2_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPDT_DCDC2_sg(SG_TPDT_DCDC2_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPCM_APCU_sg(SG_TPCM_APCU_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPDT_APCU_sg(SG_TPDT_APCU_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_HRW_sg(SG_HRW_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_ADUSt_sg(SG_ADUSt_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_RDUSt_sg(SG_RDUSt_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_IGWSt_sg(SG_IGWSt_sg* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Flag_Arr_CCVS1_oRx_Flag_Arr_CCVS1(Rx_Flag_Type* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Flag_Arr_EBC1_oRx_Flag_Arr_EBC1(Rx_Flag_Type* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Flag_Arr_EBC2_oRx_Flag_Arr_EBC2(Rx_Flag_Type* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Flag_Arr_EEC2_oRx_Flag_Arr_EEC2(Rx_Flag_Type* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Flag_Arr_EPB1_oRx_Flag_Arr_EPB1(Rx_Flag_Type* data);
FUNC(Std_Retu