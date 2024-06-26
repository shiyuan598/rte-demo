/**
 * ********************************************************************************************************************
 * @file Rte_OsApplication_Core3.c
 * @brief Rte Interface for OsApplication_Core3
 * @author zhito 
 * @version 1.0.0
 * @date 2023-12-11 13:21:55
 * @copyright Copyright (c) Zhito Co., Ltd. 2020-2035. All rights reserved.
 * ********************************************************************************************************************
 */
#include "shared.h"
#include "IDC.h"
#include "Rte_control_swc_sweep.h"
#include "Rte_CddMsgUpd.h"
#include "ee_oo_api_osek.h"

VAR(SG_LC_ADU_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_LC_ADU_sg_oLC_ADU_oJ6L_ADUCAN_Tx = {
  0U,0U,0U,0U,0U,0U,0U,0U,0U
};

VAR(SG_TSC1_ACCE_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TSC1_ACCE_sg_oTSC1_ACCE_oJ6L_ADUCAN_Tx = {
  0U,0U,0U,0U,0U,0U,0U,0U,0U
};

VAR(SG_XBR2_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_XBR2_sg_oXBR2_oJ6L_ADUCAN_Tx = {
  0U,0U,0U,0U,0U,0U
};

VAR(SG_TC1_ADU_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TC1_ADU_sg_oTC1_ADU_oJ6L_ADUCAN_Tx = {
  0U
};

VAR(SG_EPB2_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_EPB2_sg_oEPB2_oJ6L_ADUCAN_Tx = {
  0U,0U,0U,0U,0U,0U,0U,0U
};

VAR(SG_ADU1_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_ADU1_sg_oADU1_oJ6L_ADUCAN_Tx = {
  0U,0U,0U,0U
};

VAR(SG_ADU_Cmd_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_ADU_Cmd_sg_oADU_Cmd_oJ6L_ADUCAN_Tx = {
  0U,0U,0U,0U,0U,0U,0U
};

VAR(SG_TSC1_ACCDR_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TSC1_ACCDR_sg_oTSC1_ACCDR_oJ6L_ADUCAN_Tx = {
  0U,0U,0U,0U,0U,0U,0U,0U,0U
};

VAR(SG_XBR1_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_XBR1_sg_oXBR1_oJ6L_ADUCAN_Tx = {
  0U,0U,0U,0U,0U,0U
};

VAR(SG_EPSI1_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_EPSI1_sg_oEPSI1_oJ6L_ADUCAN_Tx = {
  0U,0U,0U,0U,0U,0U
};

VAR(SG_EPSI2_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_EPSI2_sg_oEPSI2_oJ6L_ADUCAN_Tx = {
  0U,0U,0U,0U,0U
};

VAR(SG_ENGSC_FM_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_ENGSC_FM_sg_oENGSC_FM_oJ6L_ADUCAN_Tx = {
  0U,0U,0U,0U
};

VAR(SG_ATR_FM_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_ATR_FM_sg_oATR_FM_oJ6L_ADUCAN_Tx = {
  0U,0U,0U,{0U,0U,0U,0U,0U,0U,0U}
};

VAR(SG_Lcks_Cmd1_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_Lcks_Cmd1_sg_oLcks_Cmd1_oJ6L_ADUCAN_Tx = {
  0U,0U,0U,0U
};

VAR(SG_ADUSt_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_ADUSt_sg_oADUSt_oJ6L_ADUCAN_Tx = {
  0U,FALSE,0U,0U,0U
};

VAR(Chassis_Info_Type, RTE_VAR_INIT_NOCACHE) Rte_chassis_info_ochassis_info = {
  0U, 0U, 0U, 0U, 0U, 0.0F, SIG_ST_NOT_RCV, 0U, 0.0F, SIG_ST_NOT_RCV, 0U, 0.0F, SIG_ST_NOT_RCV, 0U, 0.0F, SIG_ST_NOT_RCV, 0U, 0.0F, SIG_ST_NOT_RCV, 0U, 0.0F, SIG_ST_NOT_RCV, 0U,
  0.0F, SIG_ST_NOT_RCV, 0U, 0.0F, SIG_ST_NOT_RCV, 0U, 0.0F, SIG_ST_NOT_RCV, 0U, 0, SIG_ST_NOT_RCV, 0U, 0U, SIG_ST_NOT_RCV, 0U, 0U, SIG_ST_NOT_RCV, 0U, 0.0F, SIG_ST_NOT_RCV, 0U,
  0.0F, SIG_ST_NOT_RCV, 0U, 0.0F, SIG_ST_NOT_RCV, 0U, 0.0F, SIG_ST_NOT_RCV, 0U, 0.0F, SIG_ST_NOT_RCV, 0U, 0.0F, SIG_ST_NOT_RCV, 0U, 0.0F, SIG_ST_NOT_RCV, 0U, 0.0F, SIG_ST_NOT_RCV, 0U,
  0.0F, SIG_ST_NOT_RCV, 0U, 0U, SIG_ST_NOT_RCV, 0U, 0U, SIG_ST_NOT_RCV, 0U, 0U, SIG_ST_NOT_RCV, 0U, 0U, SIG_ST_NOT_RCV, 0U, 0U, SIG_ST_NOT_RCV, 0U, 0U, SIG_ST_NOT_RCV, 0U, 0U, SIG_ST_NOT_RCV, 0U,
  0U, SIG_ST_NOT_RCV, 0U, 0U, SIG_ST_NOT_RCV, 0U, 0U, SIG_ST_NOT_RCV, 0U, 0.0F, SIG_ST_NOT_RCV, 0U, 0U, SIG_ST_NOT_RCV, 0U, 0.0F, SIG_ST_NOT_RCV, 0U, 0.0F, SIG_ST_NOT_RCV, 0U, 0.0F, SIG_ST_NOT_RCV, 0U,
  0.0F, SIG_ST_NOT_RCV, 0U, 0.0F, SIG_ST_NOT_RCV, 0U, 0.0F, SIG_ST_NOT_RCV, 0U, 0U, SIG_ST_NOT_RCV, 0U, 0U, SIG_ST_NOT_RCV, 0U, 0.0F, 0, 0.0F
};

VAR(TxSocAdminDataType, RTE_VAR_NOINIT_NOCACHE) Rte_TxSocAdminData_oTxSocAdminData;

VAR(uint8, RTE_VAR_INIT_NOCACHE) Rte_Rx_Cur_Pro_Cnt_LC_oRx_Cur_Pro_Cnt_LC = 0u;

VAR(ADMInfoSOC2MCU, RTE_VAR_INIT_NOCACHE) Rte_ADMInfoSOC2MCU_oADMInfoSOC2MCU = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};

VAR(ADMInfoSOC2MCU, RTE_VAR_NOINIT_NOCACHE) Rte_control_swc_sweep_ADMInfoSOC2MCU_oADMInfoSOC2MCU;

VAR(ChassisInfo, RTE_VAR_INIT_NOCACHE) Rte_ChassisInp_oChassisInp = {
  0U, 0U, 0U, 0U, 0U, 0.0F, 0U, 0U, 0.0F, 0U, 0U, 0.0F, 0U, 0U, 0.0F, 0U, 0U, 0.0F, 0U, 0U, 0.0F, 0U, 0U, 0.0F, 0U, 0U, 
  0.0F, 0U, 0U, 0.0F, 0U, 0U, 0, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0.0F, 0U, 0U, 0.0F, 0U, 0U, 0.0F, 0U, 0U, 0.0F, 0U, 
  0U, 0.0F, 0U, 0U, 0.0F, 0U, 0U, 0.0F, 0U, 0U, 0.0F, 0U, 0U, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0.0F, 0U, 0U, 0U, 0U, 0U, 0.0F, 0U, 0U, 
  0.0F, 0U, 0U, 0.0F, 0U, 0U, 0.0F, 0U, 0U, 0.0F, 0U, 0U, 0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0.0F, 0, 0.0F
};

VAR(ChassisInfo, RTE_VAR_NOINIT_NOCACHE) Rte_control_swc_sweep_ChassisInp_oChassisInp;

VAR(J6L_RxBus, RTE_VAR_INIT_NOCACHE) Rte_J6LCANRxInp_oJ6LCANRxInp = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
};

VAR(J6L_RxBus, RTE_VAR_NOINIT_NOCACHE) Rte_control_swc_sweep_J6LCANRxInp_oJ6LCANRxInp;

VAR(PlanningInfo, RTE_VAR_INIT_NOCACHE) Rte_PlanningInfo_oPlanningInfo = {
  0U, 0U, 0U, 0U, 0U, 0.0, 0U, 0.0F, 0.0F, 0U, {{0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
  }, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}}, 0U, {{0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F}}, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, {0U, 0U, 0U, 0U, 0U}, 0.0, 0.0
};

VAR(PlanningInfo, RTE_VAR_NOINIT_NOCACHE) Rte_control_swc_sweep_PlanningInfo_oPlanningInfo;

VAR(LocalizationInfo, RTE_VAR_INIT_NOCACHE) Rte_LocalizationInfo_oLocalizationInfo = {
  0U, 0U, 0U, 0U, 0U, 0.0, 0.0F, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {
  0.0F, 0.0F, 0.0F}, 0.0F, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, 0.0, 0U, {
  0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, 0.0, 0.0, 0.0
};

VAR(LocalizationInfo, RTE_VAR_NOINIT_NOCACHE) Rte_control_swc_sweep_LocalizationInfo_oLocalizationInfo;

VAR(J6L_TxBus, RTE_VAR_INIT_NOCACHE) Rte_J6LCANTxOutp_oJ6LCANTxOutp = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
};

VAR(J6L_TxBus, RTE_VAR_NOINIT_NOCACHE) Rte_control_swc_sweep_J6LCANTxOutp_oJ6LCANTxOutp;

VAR(ADMInfoMCU2SOC, RTE_VAR_INIT_NOCACHE) Rte_ADMInfoMCU2SOC_oADMInfoMCU2SOC = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};

VAR(ADMInfoMCU2SOC, RTE_VAR_NOINIT_NOCACHE) Rte_control_swc_sweep_ADMInfoMCU2SOC_oADMInfoMCU2SOC;

VAR(CtrlInfoMCU2SOC, RTE_VAR_INIT_NOCACHE) Rte_CtrlDebugInfoMCU2SOC_oCtrlDebugInfoMCU2SOC = {
  0U, 0U, 0U, 0U, 0U, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};

VAR(CtrlInfoMCU2SOC, RTE_VAR_NOINIT_NOCACHE) Rte_control_swc_sweep_CtrlDebugInfoMCU2SOC_oCtrlDebugInfoMCU2SOC;

VAR(BusEM, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_EMOutp_oEMOutp = {
  FALSE, 0U
};

VAR(BusADM, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_ADMOutp_oADMOutp = {
  0U, FALSE
};

VAR(BusVSE, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_VSEOutp_oVSEOutp = {
  0.0F, 0.0F, FALSE, 0.0F, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0U
};

VAR(BusCRM, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_CRMOutp_oCRMOutp = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
};

VAR(BusLatCtrl, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_LatCtrlOutp_oLatCtrlOutp = {
  0.0F, FALSE
};

VAR(BusLongCtrl, RTE_VAR_INIT_NOCACHE) Rte_Irv_control_swc_sweep_LongCtrlOutp_oLongCtrlOutp = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 
  0.0F, 0U
};

#if (defined(__TASKING__))
#define OS_CORE3_START_SEC_CODE
#include "Os_MemMap.h"
#endif

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_CCVS1_sg(SG_CCVS1_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_CCVS1_sg_oCCVS1_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_CCVS1_sg_oCCVS1_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_CCVS1_sg_oCCVS1_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_ETC2_sg(SG_ETC2_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_ETC2_sg_oETC2_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_ETC2_sg_oETC2_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_ETC2_sg_oETC2_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_DM1_EPB_sg(SG_DM1_EPB_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_DM1_EPB_sg_oDM1_EPB_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_DM1_EPB_sg_oDM1_EPB_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_DM1_EPB_sg_oDM1_EPB_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_EPB1_sg(SG_EPB1_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_EPB1_sg_oEPB1_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_EPB1_sg_oEPB1_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_EPB1_sg_oEPB1_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_DM1_ABS_sg(SG_DM1_ABS_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_DM1_ABS_sg_oDM1_ABS_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_DM1_ABS_sg_oDM1_ABS_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_DM1_ABS_sg_oDM1_ABS_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_EBC1_sg(SG_EBC1_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_EBC1_sg_oEBC1_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_EBC1_sg_oEBC1_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_EBC1_sg_oEBC1_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_EBC2_sg(SG_EBC2_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_EBC2_sg_oEBC2_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_EBC2_sg_oEBC2_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_EBC2_sg_oEBC2_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_EBC5_sg(SG_EBC5_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_EBC5_sg_oEBC5_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_EBC5_sg_oEBC5_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_EBC5_sg_oEBC5_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_ESC1_sg(SG_ESC1_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_ESC1_sg_oESC1_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_ESC1_sg_oESC1_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_ESC1_sg_oESC1_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_CVW_sg(SG_CVW_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_CVW_sg_oCVW_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_CVW_sg_oCVW_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_CVW_sg_oCVW_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_VDC2_sg(SG_VDC2_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_VDC2_sg_oVDC2_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_VDC2_sg_oVDC2_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_VDC2_sg_oVDC2_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_LC_ADU_sg(SG_LC_ADU_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_LC_ADU_sg_oLC_ADU_oJ6L_ADUCAN_Tx);
  Rte_SG_LC_ADU_sg_oLC_ADU_oJ6L_ADUCAN_Tx = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_LC_ADU_sg_oLC_ADU_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_LC_sg(SG_LC_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_LC_sg_oLC_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_LC_sg_oLC_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_LC_sg_oLC_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_DC2_sg(SG_DC2_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_DC2_sg_oDC2_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_DC2_sg_oDC2_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_DC2_sg_oDC2_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_MCU1_sg(SG_MCU1_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_MCU1_sg_oMCU1_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_MCU1_sg_oMCU1_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_MCU1_sg_oMCU1_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_DM1_EPS_sg(SG_DM1_EPS_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_DM1_EPS_sg_oDM1_EPS_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_DM1_EPS_sg_oDM1_EPS_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_DM1_EPS_sg_oDM1_EPS_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_EPS1_ZF_sg(SG_EPS1_ZF_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_EPS1_ZF_sg_oEPS1_ZF_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_EPS1_ZF_sg_oEPS1_ZF_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_EPS1_ZF_sg_oEPS1_ZF_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_EPS2_ZF_sg(SG_EPS2_ZF_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_EPS2_ZF_sg_oEPS2_ZF_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_EPS2_ZF_sg_oEPS2_ZF_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_EPS2_ZF_sg_oEPS2_ZF_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TIRE1_sg(SG_TIRE1_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TIRE1_sg_oTIRE1_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_TIRE1_sg_oTIRE1_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TIRE1_sg_oTIRE1_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TIRE2_sg(SG_TIRE2_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TIRE2_sg_oTIRE2_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_TIRE2_sg_oTIRE2_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TIRE2_sg_oTIRE2_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TIRE3_sg(SG_TIRE3_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TIRE3_sg_oTIRE3_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_TIRE3_sg_oTIRE3_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TIRE3_sg_oTIRE3_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_DM1_TPMS_sg(SG_DM1_TPMS_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_DM1_TPMS_sg_oDM1_TPMS_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_DM1_TPMS_sg_oDM1_TPMS_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_DM1_TPMS_sg_oDM1_TPMS_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_EEC2_sg(SG_EEC2_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_EEC2_sg_oEEC2_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_EEC2_sg_oEEC2_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_EEC2_sg_oEEC2_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_TSC1_ACCE_sg(SG_TSC1_ACCE_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TSC1_ACCE_sg_oTSC1_ACCE_oJ6L_ADUCAN_Tx);
  Rte_SG_TSC1_ACCE_sg_oTSC1_ACCE_oJ6L_ADUCAN_Tx = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TSC1_ACCE_sg_oTSC1_ACCE_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_XBR2_sg(SG_XBR2_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_XBR2_sg_oXBR2_oJ6L_ADUCAN_Tx);
  Rte_SG_XBR2_sg_oXBR2_oJ6L_ADUCAN_Tx = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_XBR2_sg_oXBR2_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_TC1_ADU_sg(SG_TC1_ADU_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TC1_ADU_sg_oTC1_ADU_oJ6L_ADUCAN_Tx);
  Rte_SG_TC1_ADU_sg_oTC1_ADU_oJ6L_ADUCAN_Tx = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TC1_ADU_sg_oTC1_ADU_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_EPB2_sg(SG_EPB2_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_EPB2_sg_oEPB2_oJ6L_ADUCAN_Tx);
  Rte_SG_EPB2_sg_oEPB2_oJ6L_ADUCAN_Tx = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_EPB2_sg_oEPB2_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_ADU1_sg(SG_ADU1_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_ADU1_sg_oADU1_oJ6L_ADUCAN_Tx);
  Rte_SG_ADU1_sg_oADU1_oJ6L_ADUCAN_Tx = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_ADU1_sg_oADU1_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_ADU_Cmd_sg(SG_ADU_Cmd_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_ADU_Cmd_sg_oADU_Cmd_oJ6L_ADUCAN_Tx);
  Rte_SG_ADU_Cmd_sg_oADU_Cmd_oJ6L_ADUCAN_Tx = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_ADU_Cmd_sg_oADU_Cmd_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_VCU_Status_sg(SG_VCU_Status_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_VCU_Status_sg_oVCU_Status_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_VCU_Status_sg_oVCU_Status_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_VCU_Status_sg_oVCU_Status_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_OWW_sg(SG_OWW_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_OWW_sg_oOWW_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_OWW_sg_oOWW_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_OWW_sg_oOWW_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_SC_sg(SG_SC_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_SC_sg_oSC_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_SC_sg_oSC_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_SC_sg_oSC_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_BCU_sg(SG_BCU_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_BCU_sg_oBCU_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_BCU_sg_oBCU_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_BCU_sg_oBCU_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_HCU_BMS_sg(SG_HCU_BMS_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_HCU_BMS_sg_oHCU_BMS_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_HCU_BMS_sg_oHCU_BMS_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_HCU_BMS_sg_oHCU_BMS_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_BMS1_sg(SG_BMS1_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_BMS1_sg_oBMS1_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_BMS1_sg_oBMS1_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_BMS1_sg_oBMS1_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_BMS5_sg(SG_BMS5_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_BMS5_sg_oBMS5_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_BMS5_sg_oBMS5_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_BMS5_sg_oBMS5_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_VD_sg(SG_VD_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_VD_sg_oVD_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_VD_sg_oVD_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_VD_sg_oVD_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_DM1_BCM_sg(SG_DM1_BCM_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_DM1_BCM_sg_oDM1_BCM_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_DM1_BCM_sg_oDM1_BCM_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_DM1_BCM_sg_oDM1_BCM_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_TSC1_ACCDR_sg(SG_TSC1_ACCDR_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TSC1_ACCDR_sg_oTSC1_ACCDR_oJ6L_ADUCAN_Tx);
  Rte_SG_TSC1_ACCDR_sg_oTSC1_ACCDR_oJ6L_ADUCAN_Tx = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TSC1_ACCDR_sg_oTSC1_ACCDR_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_EC_EM1_sg(SG_EC_EM1_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_EC_EM1_sg_oEC_EM1_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_EC_EM1_sg_oEC_EM1_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_EC_EM1_sg_oEC_EM1_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_LD_sg(SG_LD_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_LD_sg_oLD_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_LD_sg_oLD_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_LD_sg_oLD_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_BCM_Status_sg(SG_BCM_Status_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_BCM_Status_sg_oBCM_Status_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_BCM_Status_sg_oBCM_Status_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_BCM_Status_sg_oBCM_Status_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_DM1_BMS_sg(SG_DM1_BMS_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_DM1_BMS_sg_oDM1_BMS_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_DM1_BMS_sg_oDM1_BMS_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_DM1_BMS_sg_oDM1_BMS_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_DM1_PTU_sg(SG_DM1_PTU_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_DM1_PTU_sg_oDM1_PTU_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_DM1_PTU_sg_oDM1_PTU_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_DM1_PTU_sg_oDM1_PTU_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_DM1_DCDC2_sg(SG_DM1_DCDC2_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_DM1_DCDC2_sg_oDM1_DCDC2_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_DM1_DCDC2_sg_oDM1_DCDC2_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_DM1_DCDC2_sg_oDM1_DCDC2_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_DM1_APCU_sg(SG_DM1_APCU_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_DM1_APCU_sg_oDM1_APCU_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_DM1_APCU_sg_oDM1_APCU_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_DM1_APCU_sg_oDM1_APCU_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_EPSO1_sg(SG_EPSO1_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_EPSO1_sg_oEPSO1_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_EPSO1_sg_oEPSO1_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_EPSO1_sg_oEPSO1_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_EPSO2_sg(SG_EPSO2_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_EPSO2_sg_oEPSO2_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_EPSO2_sg_oEPSO2_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_EPSO2_sg_oEPSO2_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_XBR1_sg(SG_XBR1_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_XBR1_sg_oXBR1_oJ6L_ADUCAN_Tx);
  Rte_SG_XBR1_sg_oXBR1_oJ6L_ADUCAN_Tx = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_XBR1_sg_oXBR1_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_EPSI1_sg(SG_EPSI1_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_EPSI1_sg_oEPSI1_oJ6L_ADUCAN_Tx);
  Rte_SG_EPSI1_sg_oEPSI1_oJ6L_ADUCAN_Tx = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_EPSI1_sg_oEPSI1_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_EPSI2_sg(SG_EPSI2_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_EPSI2_sg_oEPSI2_oJ6L_ADUCAN_Tx);
  Rte_SG_EPSI2_sg_oEPSI2_oJ6L_ADUCAN_Tx = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_EPSI2_sg_oEPSI2_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_FBCM_sg(SG_FBCM_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_FBCM_sg_oFBCM_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_FBCM_sg_oFBCM_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_FBCM_sg_oFBCM_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_PS1_sg(SG_PS1_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_PS1_sg_oPS1_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_PS1_sg_oPS1_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_PS1_sg_oPS1_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_ENGSC_FM_sg(SG_ENGSC_FM_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_ENGSC_FM_sg_oENGSC_FM_oJ6L_ADUCAN_Tx);
  Rte_SG_ENGSC_FM_sg_oENGSC_FM_oJ6L_ADUCAN_Tx = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_ENGSC_FM_sg_oENGSC_FM_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_ATR_FM_sg(SG_ATR_FM_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_ATR_FM_sg_oATR_FM_oJ6L_ADUCAN_Tx);
  Rte_SG_ATR_FM_sg_oATR_FM_oJ6L_ADUCAN_Tx = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_ATR_FM_sg_oATR_FM_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_ATS_PS_sg(SG_ATS_PS_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_ATS_PS_sg_oATS_PS_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_ATS_PS_sg_oATS_PS_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_ATS_PS_sg_oATS_PS_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_Lcks_Cmd1_sg(SG_Lcks_Cmd1_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_Lcks_Cmd1_sg_oLcks_Cmd1_oJ6L_ADUCAN_Tx);
  Rte_SG_Lcks_Cmd1_sg_oLcks_Cmd1_oJ6L_ADUCAN_Tx = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_Lcks_Cmd1_sg_oLcks_Cmd1_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPCM_EPB_sg(SG_TPCM_EPB_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPCM_EPB_sg_oTPCM_EPB_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_TPCM_EPB_sg_oTPCM_EPB_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPCM_EPB_sg_oTPCM_EPB_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPDT_EPB_sg(SG_TPDT_EPB_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPDT_EPB_sg_oTPDT_EPB_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_TPDT_EPB_sg_oTPDT_EPB_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPDT_EPB_sg_oTPDT_EPB_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPCM_EBS_sg(SG_TPCM_EBS_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPCM_EBS_sg_oTPCM_EBS_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_TPCM_EBS_sg_oTPCM_EBS_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPCM_EBS_sg_oTPCM_EBS_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPDT_EBS_sg(SG_TPDT_EBS_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPDT_EBS_sg_oTPDT_EBS_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_TPDT_EBS_sg_oTPDT_EBS_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPDT_EBS_sg_oTPDT_EBS_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPCM_EPS_sg(SG_TPCM_EPS_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPCM_EPS_sg_oTPCM_EPS_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_TPCM_EPS_sg_oTPCM_EPS_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPCM_EPS_sg_oTPCM_EPS_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPDT_EPS_sg(SG_TPDT_EPS_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPDT_EPS_sg_oTPDT_EPS_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_TPDT_EPS_sg_oTPDT_EPS_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPDT_EPS_sg_oTPDT_EPS_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPCM_BCM_sg(SG_TPCM_BCM_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPCM_BCM_sg_oTPCM_BCM_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_TPCM_BCM_sg_oTPCM_BCM_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPCM_BCM_sg_oTPCM_BCM_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPDT_BCM_sg(SG_TPDT_BCM_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPDT_BCM_sg_oTPDT_BCM_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_TPDT_BCM_sg_oTPDT_BCM_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPDT_BCM_sg_oTPDT_BCM_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPCM_TPMS_sg(SG_TPCM_TPMS_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPCM_TPMS_sg_oTPCM_TPMS_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_TPCM_TPMS_sg_oTPCM_TPMS_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPCM_TPMS_sg_oTPCM_TPMS_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPDT_TPMS_sg(SG_TPDT_TPMS_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPDT_TPMS_sg_oTPDT_TPMS_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_TPDT_TPMS_sg_oTPDT_TPMS_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPDT_TPMS_sg_oTPDT_TPMS_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPCM_BMS_sg(SG_TPCM_BMS_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPCM_BMS_sg_oTPCM_BMS_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_TPCM_BMS_sg_oTPCM_BMS_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPCM_BMS_sg_oTPCM_BMS_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPDT_BMS_sg(SG_TPDT_BMS_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPDT_BMS_sg_oTPDT_BMS_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_TPDT_BMS_sg_oTPDT_BMS_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPDT_BMS_sg_oTPDT_BMS_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPCM_VCU_sg(SG_TPCM_VCU_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPCM_VCU_sg_oTPCM_VCU_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_TPCM_VCU_sg_oTPCM_VCU_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPCM_VCU_sg_oTPCM_VCU_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPDT_VCU_sg(SG_TPDT_VCU_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPDT_VCU_sg_oTPDT_VCU_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_TPDT_VCU_sg_oTPDT_VCU_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPDT_VCU_sg_oTPDT_VCU_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPCM_PTU_sg(SG_TPCM_PTU_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPCM_PTU_sg_oTPCM_PTU_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_TPCM_PTU_sg_oTPCM_PTU_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPCM_PTU_sg_oTPCM_PTU_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPDT_PTU_sg(SG_TPDT_PTU_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPDT_PTU_sg_oTPDT_PTU_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_TPDT_PTU_sg_oTPDT_PTU_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPDT_PTU_sg_oTPDT_PTU_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPCM_DCDC2_sg(SG_TPCM_DCDC2_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPCM_DCDC2_sg_oTPCM_DCDC2_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_TPCM_DCDC2_sg_oTPCM_DCDC2_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPCM_DCDC2_sg_oTPCM_DCDC2_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPDT_DCDC2_sg(SG_TPDT_DCDC2_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPDT_DCDC2_sg_oTPDT_DCDC2_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_TPDT_DCDC2_sg_oTPDT_DCDC2_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPDT_DCDC2_sg_oTPDT_DCDC2_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPCM_APCU_sg(SG_TPCM_APCU_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPCM_APCU_sg_oTPCM_APCU_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_TPCM_APCU_sg_oTPCM_APCU_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPCM_APCU_sg_oTPCM_APCU_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_TPDT_APCU_sg(SG_TPDT_APCU_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPDT_APCU_sg_oTPDT_APCU_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_TPDT_APCU_sg_oTPDT_APCU_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPDT_APCU_sg_oTPDT_APCU_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_HRW_sg(SG_HRW_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_HRW_sg_oHRW_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_HRW_sg_oHRW_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_HRW_sg_oHRW_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6L_ADUCAN_TxSignal_SG_ADUSt_sg(SG_ADUSt_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_ADUSt_sg_oADUSt_oJ6L_ADUCAN_Tx);
  Rte_SG_ADUSt_sg_oADUSt_oJ6L_ADUCAN_Tx = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_ADUSt_sg_oADUSt_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_RDUSt_sg(SG_RDUSt_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_RDUSt_sg_oRDUSt_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_RDUSt_sg_oRDUSt_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_RDUSt_sg_oRDUSt_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6L_ADUCAN_RxSignal_SG_IGWSt_sg(SG_IGWSt_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_IGWSt_sg_oIGWSt_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_IGWSt_sg_oIGWSt_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_IGWSt_sg_oIGWSt_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Flag_Arr_CCVS1_oRx_Flag_Arr_CCVS1(Rx_Flag_Type* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Flag_Arr_CCVS1_oRx_Flag_Arr_CCVS1);
  *data = Rte_Rx_Flag_Arr_CCVS1_oRx_Flag_Arr_CCVS1;
  if(RX_FLAG_RCV == Rte_Rx_Flag_Arr_CCVS1_oRx_Flag_Arr_CCVS1)
  {
    Rte_Rx_Flag_Arr_CCVS1_oRx_Flag_Arr_CCVS1 = RX_FLAG_CLR;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Flag_Arr_CCVS1_oRx_Flag_Arr_CCVS1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Flag_Arr_EBC1_oRx_Flag_Arr_EBC1(Rx_Flag_Type* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Flag_Arr_EBC1_oRx_Flag_Arr_EBC1);
  *data = Rte_Rx_Flag_Arr_EBC1_oRx_Flag_Arr_EBC1;
  if(RX_FLAG_RCV == Rte_Rx_Flag_Arr_EBC1_oRx_Flag_Arr_EBC1)
  {
    Rte_Rx_Flag_Arr_EBC1_oRx_Flag_Arr_EBC1 = RX_FLAG_CLR;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Flag_Arr_EBC1_oRx_Flag_Arr_EBC1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Flag_Arr_EBC2_oRx_Flag_Arr_EBC2(Rx_Flag_Type* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Flag_Arr_EBC2_oRx_Flag_Arr_EBC2);
  *data = Rte_Rx_Flag_Arr_EBC2_oRx_Flag_Arr_EBC2;
  if(RX_FLAG_RCV == Rte_Rx_Flag_Arr_EBC2_oRx_Flag_Arr_EBC2)
  {
    Rte_Rx_Flag_Arr_EBC2_oRx_Flag_Arr_EBC2 = RX_FLAG_CLR;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Flag_Arr_EBC2_oRx_Flag_Arr_EBC2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Flag_Arr_EEC2_oRx_Flag_Arr_EEC2(Rx_Flag_Type* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Flag_Arr_EEC2_oRx_Flag_Arr_EEC2);
  *data = Rte_Rx_Flag_Arr_EEC2_oRx_Flag_Arr_EEC2;
  if(RX_FLAG_RCV == Rte_Rx_Flag_Arr_EEC2_oRx_Flag_Arr_EEC2)
  {
    Rte_Rx_Flag_Arr_EEC2_oRx_Flag_Arr_EEC2 = RX_FLAG_CLR;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Flag_Arr_EEC2_oRx_Flag_Arr_EEC2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Flag_Arr_EPB1_oRx_Flag_Arr_EPB1(Rx_Flag_Type* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Flag_Arr_EPB1_oRx_Flag_Arr_EPB1);
  *data = Rte_Rx_Flag_Arr_EPB1_oRx_Flag_Arr_EPB1;
  if(RX_FLAG_RCV == Rte_Rx_Flag_Arr_EPB1_oRx_Flag_Arr_EPB1)
  {
    Rte_Rx_Flag_Arr_EPB1_oRx_Flag_Arr_EPB1 = RX_FLAG_CLR;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Flag_Arr_EPB1_oRx_Flag_Arr_EPB1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Flag_Arr_EPS2_oRx_Flag_Arr_EPS2(Rx_Flag_Type* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Flag_Arr_EPS2_oRx_Flag_Arr_EPS2);
  *data = Rte_Rx_Flag_Arr_EPS2_oRx_Flag_Arr_EPS2;
  if(RX_FLAG_RCV == Rte_Rx_Flag_Arr_EPS2_oRx_Flag_Arr_EPS2)
  {
    Rte_Rx_Flag_Arr_EPS2_oRx_Flag_Arr_EPS2 = RX_FLAG_CLR;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Flag_Arr_EPS2_oRx_Flag_Arr_EPS2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Flag_Arr_ETC2_oRx_Flag_Arr_ETC2(Rx_Flag_Type* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Flag_Arr_ETC2_oRx_Flag_Arr_ETC2);
  *data = Rte_Rx_Flag_Arr_ETC2_oRx_Flag_Arr_ETC2;
  if(RX_FLAG_RCV == Rte_Rx_Flag_Arr_ETC2_oRx_Flag_Arr_ETC2)
  {
    Rte_Rx_Flag_Arr_ETC2_oRx_Flag_Arr_ETC2 = RX_FLAG_CLR;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Flag_Arr_ETC2_oRx_Flag_Arr_ETC2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Flag_Arr_LC_oRx_Flag_Arr_LC(Rx_Flag_Type* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Flag_Arr_LC_oRx_Flag_Arr_LC);
  *data = Rte_Rx_Flag_Arr_LC_oRx_Flag_Arr_LC;
  if(RX_FLAG_RCV == Rte_Rx_Flag_Arr_LC_oRx_Flag_Arr_LC)
  {
    Rte_Rx_Flag_Arr_LC_oRx_Flag_Arr_LC = RX_FLAG_CLR;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Flag_Arr_LC_oRx_Flag_Arr_LC);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Flag_Arr_MCU1_oRx_Flag_Arr_MCU1(Rx_Flag_Type* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Flag_Arr_MCU1_oRx_Flag_Arr_MCU1);
  *data = Rte_Rx_Flag_Arr_MCU1_oRx_Flag_Arr_MCU1;
  if(RX_FLAG_RCV == Rte_Rx_Flag_Arr_MCU1_oRx_Flag_Arr_MCU1)
  {
    Rte_Rx_Flag_Arr_MCU1_oRx_Flag_Arr_MCU1 = RX_FLAG_CLR;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Flag_Arr_MCU1_oRx_Flag_Arr_MCU1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Flag_Arr_PS1_oRx_Flag_Arr_PS1(Rx_Flag_Type* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Flag_Arr_PS1_oRx_Flag_Arr_PS1);
  *data = Rte_Rx_Flag_Arr_PS1_oRx_Flag_Arr_PS1;
  if(RX_FLAG_RCV == Rte_Rx_Flag_Arr_PS1_oRx_Flag_Arr_PS1)
  {
    Rte_Rx_Flag_Arr_PS1_oRx_Flag_Arr_PS1 = RX_FLAG_CLR;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Flag_Arr_PS1_oRx_Flag_Arr_PS1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Flag_Arr_VCU_Status_oRx_Flag_Arr_VCU_Status(Rx_Flag_Type* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Flag_Arr_VCU_Status_oRx_Flag_Arr_VCU_Status);
  *data = Rte_Rx_Flag_Arr_VCU_Status_oRx_Flag_Arr_VCU_Status;
  if(RX_FLAG_RCV == Rte_Rx_Flag_Arr_VCU_Status_oRx_Flag_Arr_VCU_Status)
  {
    Rte_Rx_Flag_Arr_VCU_Status_oRx_Flag_Arr_VCU_Status = RX_FLAG_CLR;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Flag_Arr_VCU_Status_oRx_Flag_Arr_VCU_Status);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Flag_Arr_VDC2_oRx_Flag_Arr_VDC2(Rx_Flag_Type* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Flag_Arr_VDC2_oRx_Flag_Arr_VDC2);
  *data = Rte_Rx_Flag_Arr_VDC2_oRx_Flag_Arr_VDC2;
  if(RX_FLAG_RCV == Rte_Rx_Flag_Arr_VDC2_oRx_Flag_Arr_VDC2)
  {
    Rte_Rx_Flag_Arr_VDC2_oRx_Flag_Arr_VDC2 = RX_FLAG_CLR;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Flag_Arr_VDC2_oRx_Flag_Arr_VDC2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_SigStat_Arr_CCVS1_oRx_SigStat_Arr_CCVS1(CCVS1_SigStatusType* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_SigStat_Arr_CCVS1_oRx_SigStat_Arr_CCVS1);
  if(sizeof(CCVS1_SigStatusType) > 200u)
  {
    (void)memcpy(data,&Rte_Rx_SigStat_Arr_CCVS1_oRx_SigStat_Arr_CCVS1,sizeof(CCVS1_SigStatusType));
  }
  else
  {
    *data = Rte_Rx_SigStat_Arr_CCVS1_oRx_SigStat_Arr_CCVS1;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_SigStat_Arr_CCVS1_oRx_SigStat_Arr_CCVS1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_SigStat_Arr_EBC1_oRx_SigStat_Arr_EBC1(EBC1_SigStatusType* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_SigStat_Arr_EBC1_oRx_SigStat_Arr_EBC1);
  if(sizeof(EBC1_SigStatusType) > 200u)
  {
    (void)memcpy(data,&Rte_Rx_SigStat_Arr_EBC1_oRx_SigStat_Arr_EBC1,sizeof(EBC1_SigStatusType));
  }
  else
  {
    *data = Rte_Rx_SigStat_Arr_EBC1_oRx_SigStat_Arr_EBC1;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_SigStat_Arr_EBC1_oRx_SigStat_Arr_EBC1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_SigStat_Arr_EBC2_oRx_SigStat_Arr_EBC2(EBC2_SigStatusType* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_SigStat_Arr_EBC2_oRx_SigStat_Arr_EBC2);
  if(sizeof(EBC2_SigStatusType) > 200u)
  {
    (void)memcpy(data,&Rte_Rx_SigStat_Arr_EBC2_oRx_SigStat_Arr_EBC2,sizeof(EBC2_SigStatusType));
  }
  else
  {
    *data = Rte_Rx_SigStat_Arr_EBC2_oRx_SigStat_Arr_EBC2;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_SigStat_Arr_EBC2_oRx_SigStat_Arr_EBC2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_SigStat_Arr_EEC2_oRx_SigStat_Arr_EEC2(EEC2_SigStatusType* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_SigStat_Arr_EEC2_oRx_SigStat_Arr_EEC2);
  if(sizeof(EEC2_SigStatusType) > 200u)
  {
    (void)memcpy(data,&Rte_Rx_SigStat_Arr_EEC2_oRx_SigStat_Arr_EEC2,sizeof(EEC2_SigStatusType));
  }
  else
  {
    *data = Rte_Rx_SigStat_Arr_EEC2_oRx_SigStat_Arr_EEC2;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_SigStat_Arr_EEC2_oRx_SigStat_Arr_EEC2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_SigStat_Arr_EPB1_oRx_SigStat_Arr_EPB1(EPB1_SigStatusType* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_SigStat_Arr_EPB1_oRx_SigStat_Arr_EPB1);
  if(sizeof(EPB1_SigStatusType) > 200u)
  {
    (void)memcpy(data,&Rte_Rx_SigStat_Arr_EPB1_oRx_SigStat_Arr_EPB1,sizeof(EPB1_SigStatusType));
  }
  else
  {
    *data = Rte_Rx_SigStat_Arr_EPB1_oRx_SigStat_Arr_EPB1;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_SigStat_Arr_EPB1_oRx_SigStat_Arr_EPB1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_SigStat_Arr_EPS2_oRx_SigStat_Arr_EPS2(EPS2_SigStatusType* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_SigStat_Arr_EPS2_oRx_SigStat_Arr_EPS2);
  if(sizeof(EPS2_SigStatusType) > 200u)
  {
    (void)memcpy(data,&Rte_Rx_SigStat_Arr_EPS2_oRx_SigStat_Arr_EPS2,sizeof(EPS2_SigStatusType));
  }
  else
  {
    *data = Rte_Rx_SigStat_Arr_EPS2_oRx_SigStat_Arr_EPS2;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_SigStat_Arr_EPS2_oRx_SigStat_Arr_EPS2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_SigStat_Arr_ETC2_oRx_SigStat_Arr_ETC2(ETC2_SigStatusType* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_SigStat_Arr_ETC2_oRx_SigStat_Arr_ETC2);
  if(sizeof(ETC2_SigStatusType) > 200u)
  {
    (void)memcpy(data,&Rte_Rx_SigStat_Arr_ETC2_oRx_SigStat_Arr_ETC2,sizeof(ETC2_SigStatusType));
  }
  else
  {
    *data = Rte_Rx_SigStat_Arr_ETC2_oRx_SigStat_Arr_ETC2;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_SigStat_Arr_ETC2_oRx_SigStat_Arr_ETC2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_SigStat_Arr_LC_oRx_SigStat_Arr_LC(LC_SigStatusType* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_SigStat_Arr_LC_oRx_SigStat_Arr_LC);
  if(sizeof(LC_SigStatusType) > 200u)
  {
    (void)memcpy(data,&Rte_Rx_SigStat_Arr_LC_oRx_SigStat_Arr_LC,sizeof(LC_SigStatusType));
  }
  else
  {
    *data = Rte_Rx_SigStat_Arr_LC_oRx_SigStat_Arr_LC;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_SigStat_Arr_LC_oRx_SigStat_Arr_LC);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_SigStat_Arr_MCU1_oRx_SigStat_Arr_MCU1(MCU1_SigStatusType* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_SigStat_Arr_MCU1_oRx_SigStat_Arr_MCU1);
  if(sizeof(MCU1_SigStatusType) > 200u)
  {
    (void)memcpy(data,&Rte_Rx_SigStat_Arr_MCU1_oRx_SigStat_Arr_MCU1,sizeof(MCU1_SigStatusType));
  }
  else
  {
    *data = Rte_Rx_SigStat_Arr_MCU1_oRx_SigStat_Arr_MCU1;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_SigStat_Arr_MCU1_oRx_SigStat_Arr_MCU1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_SigStat_Arr_PS1_oRx_SigStat_Arr_PS1(PS1_SigStatusType* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_SigStat_Arr_PS1_oRx_SigStat_Arr_PS1);
  if(sizeof(PS1_SigStatusType) > 200u)
  {
    (void)memcpy(data,&Rte_Rx_SigStat_Arr_PS1_oRx_SigStat_Arr_PS1,sizeof(PS1_SigStatusType));
  }
  else
  {
    *data = Rte_Rx_SigStat_Arr_PS1_oRx_SigStat_Arr_PS1;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_SigStat_Arr_PS1_oRx_SigStat_Arr_PS1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_SigStat_Arr_VCU_Status_oRx_SigStat_Arr_VCU_Status(VCU_Status_SigStatusType* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_SigStat_Arr_VCU_Status_oRx_SigStat_Arr_VCU_Status);
  if(sizeof(VCU_Status_SigStatusType) > 200u)
  {
    (void)memcpy(data,&Rte_Rx_SigStat_Arr_VCU_Status_oRx_SigStat_Arr_VCU_Status,sizeof(VCU_Status_SigStatusType));
  }
  else
  {
    *data = Rte_Rx_SigStat_Arr_VCU_Status_oRx_SigStat_Arr_VCU_Status;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_SigStat_Arr_VCU_Status_oRx_SigStat_Arr_VCU_Status);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_SigStat_Arr_VDC2_oRx_SigStat_Arr_VDC2(VDC2_SigStatusType* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_SigStat_Arr_VDC2_oRx_SigStat_Arr_VDC2);
  if(sizeof(VDC2_SigStatusType) > 200u)
  {
    (void)memcpy(data,&Rte_Rx_SigStat_Arr_VDC2_oRx_SigStat_Arr_VDC2,sizeof(VDC2_SigStatusType));
  }
  else
  {
    *data = Rte_Rx_SigStat_Arr_VDC2_oRx_SigStat_Arr_VDC2;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_SigStat_Arr_VDC2_oRx_SigStat_Arr_VDC2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Time_Arr_CCVS1_oRx_Time_Arr_CCVS1(uint64* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Time_Arr_CCVS1_oRx_Time_Arr_CCVS1);
  *data = Rte_Rx_Time_Arr_CCVS1_oRx_Time_Arr_CCVS1;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Time_Arr_CCVS1_oRx_Time_Arr_CCVS1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Time_Arr_EBC1_oRx_Time_Arr_EBC1(uint64* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Time_Arr_EBC1_oRx_Time_Arr_EBC1);
  *data = Rte_Rx_Time_Arr_EBC1_oRx_Time_Arr_EBC1;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Time_Arr_EBC1_oRx_Time_Arr_EBC1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Time_Arr_EBC2_oRx_Time_Arr_EBC2(uint64* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Time_Arr_EBC2_oRx_Time_Arr_EBC2);
  *data = Rte_Rx_Time_Arr_EBC2_oRx_Time_Arr_EBC2;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Time_Arr_EBC2_oRx_Time_Arr_EBC2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Time_Arr_EEC2_oRx_Time_Arr_EEC2(uint64* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Time_Arr_EEC2_oRx_Time_Arr_EEC2);
  *data = Rte_Rx_Time_Arr_EEC2_oRx_Time_Arr_EEC2;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Time_Arr_EEC2_oRx_Time_Arr_EEC2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Time_Arr_EPB1_oRx_Time_Arr_EPB1(uint64* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Time_Arr_EPB1_oRx_Time_Arr_EPB1);
  *data = Rte_Rx_Time_Arr_EPB1_oRx_Time_Arr_EPB1;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Time_Arr_EPB1_oRx_Time_Arr_EPB1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Time_Arr_EPS2_oRx_Time_Arr_EPS2(uint64* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Time_Arr_EPS2_oRx_Time_Arr_EPS2);
  *data = Rte_Rx_Time_Arr_EPS2_oRx_Time_Arr_EPS2;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Time_Arr_EPS2_oRx_Time_Arr_EPS2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Time_Arr_ETC2_oRx_Time_Arr_ETC2(uint64* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Time_Arr_ETC2_oRx_Time_Arr_ETC2);
  *data = Rte_Rx_Time_Arr_ETC2_oRx_Time_Arr_ETC2;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Time_Arr_ETC2_oRx_Time_Arr_ETC2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Time_Arr_LC_oRx_Time_Arr_LC(uint64* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Time_Arr_LC_oRx_Time_Arr_LC);
  *data = Rte_Rx_Time_Arr_LC_oRx_Time_Arr_LC;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Time_Arr_LC_oRx_Time_Arr_LC);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Time_Arr_MCU1_oRx_Time_Arr_MCU1(uint64* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Time_Arr_MCU1_oRx_Time_Arr_MCU1);
  *data = Rte_Rx_Time_Arr_MCU1_oRx_Time_Arr_MCU1;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Time_Arr_MCU1_oRx_Time_Arr_MCU1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Time_Arr_PS1_oRx_Time_Arr_PS1(uint64* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Time_Arr_PS1_oRx_Time_Arr_PS1);
  *data = Rte_Rx_Time_Arr_PS1_oRx_Time_Arr_PS1;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Time_Arr_PS1_oRx_Time_Arr_PS1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Time_Arr_VCU_Status_oRx_Time_Arr_VCU_Status(uint64* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Time_Arr_VCU_Status_oRx_Time_Arr_VCU_Status);
  *data = Rte_Rx_Time_Arr_VCU_Status_oRx_Time_Arr_VCU_Status;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Time_Arr_VCU_Status_oRx_Time_Arr_VCU_Status);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Time_Arr_VDC2_oRx_Time_Arr_VDC2(uint64* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Time_Arr_VDC2_oRx_Time_Arr_VDC2);
  *data = Rte_Rx_Time_Arr_VDC2_oRx_Time_Arr_VDC2;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Time_Arr_VDC2_oRx_Time_Arr_VDC2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IDC_RxSocAdminData_oRxSocAdminData(RxSocAdminDataType* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_RxSocAdminData_oRxSocAdminData);
  if(sizeof(RxSocAdminDataType) > 200u)
  {
    (void)memcpy(data,&Rte_RxSocAdminData_oRxSocAdminData,sizeof(RxSocAdminDataType));
  }
  else
  {
    *data = Rte_RxSocAdminData_oRxSocAdminData;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_RxSocAdminData_oRxSocAdminData);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IDC_chassis_info_ochassis_info(Chassis_Info_Type* data)
{
  Std_ReturnType ret = RTE_E_OK;

  if(sizeof(Chassis_Info_Type) > 200u)
  {
    (void)memcpy(data,&Rte_chassis_info_ochassis_info,sizeof(Chassis_Info_Type));
  }
  else
  {
    *data = Rte_chassis_info_ochassis_info;
  }

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_chassis_info_ochassis_info(Chassis_Info_Type* data)
{
  Std_ReturnType ret = RTE_E_OK;

  if(sizeof(Chassis_Info_Type) > 200u)
  {
    (void)memcpy(&Rte_chassis_info_ochassis_info,data,sizeof(Chassis_Info_Type));
  }
  else
  {
    Rte_chassis_info_ochassis_info = *data;
  }

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IDC_TxSocAdminData_oTxSocAdminData(TxSocAdminDataType* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_TxSocAdminData_oTxSocAdminData);
  if(sizeof(TxSocAdminDataType) > 200u)
  {
    (void)memcpy(&Rte_TxSocAdminData_oTxSocAdminData,data,sizeof(TxSocAdminDataType));
  }
  else
  {
    Rte_TxSocAdminData_oTxSocAdminData = *data;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_TxSocAdminData_oTxSocAdminData);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Rx_Pro_Cnt_LC_oRx_Pro_Cnt_LC(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Pro_Cnt_LC_oRx_Pro_Cnt_LC);
  *data = Rte_Rx_Pro_Cnt_LC_oRx_Pro_Cnt_LC;
  if(0u != Rte_Rx_Pro_Cnt_LC_oRx_Pro_Cnt_LC)
  {
    Rte_Rx_Pro_Cnt_LC_oRx_Pro_Cnt_LC--;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Pro_Cnt_LC_oRx_Pro_Cnt_LC);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_Rx_Cur_Pro_Cnt_LC_oRx_Cur_Pro_Cnt_LC(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Cur_Pro_Cnt_LC_oRx_Cur_Pro_Cnt_LC);
  Rte_Rx_Cur_Pro_Cnt_LC_oRx_Cur_Pro_Cnt_LC = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Cur_Pro_Cnt_LC_oRx_Cur_Pro_Cnt_LC);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_Core3TimeStamp_oCore3TimeStamp(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Core3TimeStamp_oCore3TimeStamp);
  (void)memcpy(data,Rte_Core3TimeStamp_oCore3TimeStamp,sizeof(rt_Array_uint8_12));
  (void)ReleaseSpinlock(Rte_Spinlock_Core3TimeStamp_oCore3TimeStamp);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_control_swc_sweep_ADMInfoSOC2MCU_oADMInfoSOC2MCU(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_control_swc_sweep_ADMInfoSOC2MCU_oADMInfoSOC2MCU = Rte_ADMInfoSOC2MCU_oADMInfoSOC2MCU;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IDC_ADMInfoSOC2MCU_oADMInfoSOC2MCU(ADMInfoSOC2MCU* data)
{
  Std_ReturnType ret = RTE_E_OK;

  if(sizeof(ADMInfoSOC2MCU) > 200u)
  {
    (void)memcpy(&Rte_ADMInfoSOC2MCU_oADMInfoSOC2MCU,data,sizeof(ADMInfoSOC2MCU));
  }
  else
  {
    Rte_ADMInfoSOC2MCU_oADMInfoSOC2MCU = *data;
  }

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_control_swc_sweep_ChassisInp_oChassisInp(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_control_swc_sweep_ChassisInp_oChassisInp = Rte_ChassisInp_oChassisInp;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_ChassisInp_oChassisInp(ChassisInfo* data)
{
  Std_ReturnType ret = RTE_E_OK;

  if(sizeof(ChassisInfo) > 200u)
  {
    (void)memcpy(&Rte_ChassisInp_oChassisInp,data,sizeof(ChassisInfo));
  }
  else
  {
    Rte_ChassisInp_oChassisInp = *data;
  }

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_control_swc_sweep_J6LCANRxInp_oJ6LCANRxInp(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_control_swc_sweep_J6LCANRxInp_oJ6LCANRxInp = Rte_J6LCANRxInp_oJ6LCANRxInp;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6LCANRxInp_oJ6LCANRxInp(J6L_RxBus* data)
{
  Std_ReturnType ret = RTE_E_OK;

  if(sizeof(J6L_RxBus) > 200u)
  {
    (void)memcpy(&Rte_J6LCANRxInp_oJ6LCANRxInp,data,sizeof(J6L_RxBus));
  }
  else
  {
    Rte_J6LCANRxInp_oJ6LCANRxInp = *data;
  }

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_control_swc_sweep_PlanningInfo_oPlanningInfo(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_control_swc_sweep_PlanningInfo_oPlanningInfo = Rte_PlanningInfo_oPlanningInfo;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IDC_PlanningInfo_oPlanningInfo(PlanningInfo* data)
{
  Std_ReturnType ret = RTE_E_OK;

  if(sizeof(PlanningInfo) > 200u)
  {
    (void)memcpy(&Rte_PlanningInfo_oPlanningInfo,data,sizeof(PlanningInfo));
  }
  else
  {
    Rte_PlanningInfo_oPlanningInfo = *data;
  }

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_control_swc_sweep_LocalizationInfo_oLocalizationInfo(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_control_swc_sweep_LocalizationInfo_oLocalizationInfo = Rte_LocalizationInfo_oLocalizationInfo;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IDC_LocalizationInfo_oLocalizationInfo(LocalizationInfo* data)
{
  Std_ReturnType ret = RTE_E_OK;

  if(sizeof(LocalizationInfo) > 200u)
  {
    (void)memcpy(&Rte_LocalizationInfo_oLocalizationInfo,data,sizeof(LocalizationInfo));
  }
  else
  {
    Rte_LocalizationInfo_oLocalizationInfo = *data;
  }

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6LCANTxOutp_oJ6LCANTxOutp(J6L_TxBus* data)
{
  Std_ReturnType ret = RTE_E_OK;

  if(sizeof(J6L_TxBus) > 200u)
  {
    (void)memcpy(data,&Rte_J6LCANTxOutp_oJ6LCANTxOutp,sizeof(J6L_TxBus));
  }
  else
  {
    *data = Rte_J6LCANTxOutp_oJ6LCANTxOutp;
  }

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_control_swc_sweep_J6LCANTxOutp_oJ6LCANTxOutp(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_J6LCANTxOutp_oJ6LCANTxOutp = Rte_control_swc_sweep_J6LCANTxOutp_oJ6LCANTxOutp;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IDC_ADMInfoMCU2SOC_oADMInfoMCU2SOC(ADMInfoMCU2SOC* data)
{
  Std_ReturnType ret = RTE_E_OK;

  if(sizeof(ADMInfoMCU2SOC) > 200u)
  {
    (void)memcpy(data,&Rte_ADMInfoMCU2SOC_oADMInfoMCU2SOC,sizeof(ADMInfoMCU2SOC));
  }
  else
  {
    *data = Rte_ADMInfoMCU2SOC_oADMInfoMCU2SOC;
  }

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_control_swc_sweep_ADMInfoMCU2SOC_oADMInfoMCU2SOC(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_ADMInfoMCU2SOC_oADMInfoMCU2SOC = Rte_control_swc_sweep_ADMInfoMCU2SOC_oADMInfoMCU2SOC;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IDC_CtrlDebugInfoMCU2SOC_oCtrlDebugInfoMCU2SOC(CtrlInfoMCU2SOC* data)
{
  Std_ReturnType ret = RTE_E_OK;

  if(sizeof(CtrlInfoMCU2SOC) > 200u)
  {
    (void)memcpy(data,&Rte_CtrlDebugInfoMCU2SOC_oCtrlDebugInfoMCU2SOC,sizeof(CtrlInfoMCU2SOC));
  }
  else
  {
    *data = Rte_CtrlDebugInfoMCU2SOC_oCtrlDebugInfoMCU2SOC;
  }

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_control_swc_sweep_CtrlDebugInfoMCU2SOC_oCtrlDebugInfoMCU2SOC(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_CtrlDebugInfoMCU2SOC_oCtrlDebugInfoMCU2SOC = Rte_control_swc_sweep_CtrlDebugInfoMCU2SOC_oCtrlDebugInfoMCU2SOC;

  return ret;
}

void idle_hook_core3(void);
void idle_hook_core3(void)
{
  idle_hook_body();
}
extern uint8_t Core[6][10];
/**********************************************************************************************************************
 * Task:     Bsw_QM_Event_Task_Core0
 * Priority: 170
 * Schedule: FULL
 *********************************************************************************************************************/
 TASK(Bsw_Init_Task_Core3)
 {
   Core[3][0]++;
   Tm_Start(30);
   EcuM_StartupTwo(); 
   Rte_Start();    
   CddMsgUpd_Init();
   SwcAppC1_Init();
   IDC_Init();
   while (((volatile uint8)Rte_InitState) != RTE_STATE_INIT)
    {

    }
   Tm_Stop(30);
   TerminateTask();
 }
 /**********************************************************************************************************************
 * Task:     Bsw_QM_Event_Task_Core0
 * Priority: 170
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Bsw_P1ms_Task_Core3)
{
	Core[3][1]++;
  Tm_Start(31);
  Tm_Stop(31);
  TerminateTask();
}
/**********************************************************************************************************************
 * Task:     Bsw_QM_Event_Task_Core0
 * Priority: 170
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Bsw_P5ms_Task_Core3)
{
	Core[3][2]++;
  Tm_Start(32);
  Tm_Stop(32);
  TerminateTask();
}
/**********************************************************************************************************************
 * Task:     Bsw_QM_Event_Task_Core0
 * Priority: 170
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Bsw_P10ms_Task_Core3)
{
	Core[3][3]++;
  Tm_Start(33);
  EcuM_MainFunction();  
  IDC_MainFunctionRx();
  IDC_MainFunctionTx();
  Tm_Stop(33);
  TerminateTask();
}
/**********************************************************************************************************************
 * Task:     Bsw_QM_Event_Task_Core0
 * Priority: 170
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Bsw_P20ms_Task_Core3)
{
	Core[3][5]++;
  Tm_Start(35);
  CddMsgUpd_MainFunctionRx();
  CddMsgUpd_MainFunction_20ms();
  (void)Rte_Read_control_swc_sweep_ADMInfoSOC2MCU_oADMInfoSOC2MCU();
  (void)Rte_Read_control_swc_sweep_ChassisInp_oChassisInp();
  (void)Rte_Read_control_swc_sweep_J6LCANRxInp_oJ6LCANRxInp();
  (void)Rte_Read_control_swc_sweep_PlanningInfo_oPlanningInfo();
  (void)Rte_Read_control_swc_sweep_LocalizationInfo_oLocalizationInfo();
  SwcAppC1_MainFunction_20ms();
  (void)Rte_Write_control_swc_sweep_J6LCANTxOutp_oJ6LCANTxOutp();
  (void)Rte_Write_control_swc_sweep_ADMInfoMCU2SOC_oADMInfoMCU2SOC();
  (void)Rte_Write_control_swc_sweep_CtrlDebugInfoMCU2SOC_oCtrlDebugInfoMCU2SOC();
  CddMsgUpd_MainFunctionTx();
  Tm_Stop(35);
  TerminateTask();
}

/**********************************************************************************************************************
 * Task:     Bsw_QM_Event_Task_Core0
 * Priority: 170
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Bsw_P100ms_Task_Core3)
{
  Core[3][4]++;
  Tm_Start(34);
  Clm_runnable_100ms();
  Tm_Stop(34);
  TerminateTask();
}

#if (defined(__TASKING__))
#define OS_CORE3_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif

