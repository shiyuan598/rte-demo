/**
 * ********************************************************************************************************************
 * @file Rte_OsApplication_Core0.c
 * @brief Rte Interface for OsApplication_Core0
 * @author zhito 
 * @version 1.0.0
 * @date 2023-12-11 13:21:55
 * @copyright Copyright (c) Zhito Co., Ltd. 2020-2035. All rights reserved.
 * ********************************************************************************************************************
 */
#include "shared.h"
#include "Mcu.h"
#include "Spi.h"
#include "Spi_PBcfg.h"
#include "CanIf.h"
#include "Port.h"
#include "Port_PBcfg.h"
#include "I2c.h"
#include "CanSM_Cfg.h"
#include "I2c_PBcfg.h"
#include "IfxCpu_reg.h"
#include "ComStack_Types.h"
#include "Eth_17_GEthMac.h"
#include "Eth_17_GEthMac_PBcfg.h"
#include "Ifx_Lwip.h"
#include "SoAd.h"
#include "IfxStm_reg.h"
#include "Com_Cfg.h"
#include "MSDC_Callout.h"
#include "SchM_Xcp.h"
#include "NvProxy.h"
#include "Rte_control_swc_sweep.h"
#include "Rte_CddMsgUpd.h"
#include "Rte_MSDC.h"
#include "Rte_ComProxy.h"
#include "ee_oo_api_osek.h"
#include "Rte_Compiler_Cfg.h"
#include "Rte_NV_SWC_DiagHandler.h"
uint8_t Core[6][10];

VAR(SG_CCVS1_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_CCVS1_sg_oCCVS1_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U
};

VAR(SG_ETC2_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_ETC2_sg_oETC2_oJ6L_ADUCAN_Rx = {
  0U,0U,0U
};

VAR(SG_DM1_EPB_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_DM1_EPB_sg_oDM1_EPB_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,FALSE
};

VAR(SG_EPB1_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_EPB1_sg_oEPB1_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U
};

VAR(SG_DM1_ABS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_DM1_ABS_sg_oDM1_ABS_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,0U,0U,0U,0U,FALSE
};

VAR(SG_EBC1_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_EBC1_sg_oEBC1_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U
};

VAR(SG_EBC2_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_EBC2_sg_oEBC2_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,0U,0U
};

VAR(SG_EBC5_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_EBC5_sg_oEBC5_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,0U,0U,0U
};

VAR(SG_ESC1_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_ESC1_sg_oESC1_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,0U,0U
};

VAR(SG_CVW_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_CVW_sg_oCVW_oJ6L_ADUCAN_Rx = {
  0U,0U
};

VAR(SG_VDC2_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_VDC2_sg_oVDC2_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,0U
};

VAR(SG_LC_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_LC_sg_oLC_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U
};

VAR(SG_DC2_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_DC2_sg_oDC2_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U
};

VAR(SG_MCU1_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_MCU1_sg_oMCU1_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U
};

VAR(SG_DM1_EPS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_DM1_EPS_sg_oDM1_EPS_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,FALSE
};

VAR(SG_EPS1_ZF_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_EPS1_ZF_sg_oEPS1_ZF_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,FALSE,FALSE,FALSE,FALSE,FALSE,0U,0U
};

VAR(SG_EPS2_ZF_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_EPS2_ZF_sg_oEPS2_ZF_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,FALSE,0U,0U
};

VAR(SG_TIRE1_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TIRE1_sg_oTIRE1_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,0U,0U
};

VAR(SG_TIRE2_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TIRE2_sg_oTIRE2_oJ6L_ADUCAN_Rx = {
  0U,0U,0U
};

VAR(SG_TIRE3_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TIRE3_sg_oTIRE3_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U
};

VAR(SG_DM1_TPMS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_DM1_TPMS_sg_oDM1_TPMS_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,FALSE
};

VAR(SG_EEC2_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_EEC2_sg_oEEC2_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U
};

VAR(SG_VCU_Status_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_VCU_Status_sg_oVCU_Status_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U
};

VAR(SG_OWW_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_OWW_sg_oOWW_oJ6L_ADUCAN_Rx = {
  0U,0U
};

VAR(SG_SC_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_SC_sg_oSC_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U
};

VAR(SG_BCU_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_BCU_sg_oBCU_oJ6L_ADUCAN_Rx = {
  0U,0U,0U
};

VAR(SG_HCU_BMS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_HCU_BMS_sg_oHCU_BMS_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,0U
};

VAR(SG_BMS1_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_BMS1_sg_oBMS1_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,0U,0U,0U,0U
};

VAR(SG_BMS5_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_BMS5_sg_oBMS5_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,0U,0U,0U,0U,0U
};

VAR(SG_VD_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_VD_sg_oVD_oJ6L_ADUCAN_Rx = {
  0U,0U
};

VAR(SG_DM1_BCM_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_DM1_BCM_sg_oDM1_BCM_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,0U,0U,0U,FALSE
};

VAR(SG_EC_EM1_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_EC_EM1_sg_oEC_EM1_oJ6L_ADUCAN_Rx = {
  0U,0U,0U
};

VAR(SG_LD_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_LD_sg_oLD_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,0U,0U,0U,0U,0U
};

VAR(SG_BCM_Status_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_BCM_Status_sg_oBCM_Status_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U
};

VAR(SG_DM1_BMS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_DM1_BMS_sg_oDM1_BMS_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,0U,0U,0U,FALSE
};

VAR(SG_DM1_PTU_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_DM1_PTU_sg_oDM1_PTU_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,0U,0U,0U,FALSE
};

VAR(SG_DM1_DCDC2_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_DM1_DCDC2_sg_oDM1_DCDC2_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,0U,0U,0U,FALSE
};

VAR(SG_DM1_APCU_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_DM1_APCU_sg_oDM1_APCU_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,0U,0U,0U,FALSE
};

VAR(SG_EPSO1_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_EPSO1_sg_oEPSO1_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,0U,0U,0U,0U
};

VAR(SG_EPSO2_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_EPSO2_sg_oEPSO2_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,0U,0U
};

VAR(SG_FBCM_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_FBCM_sg_oFBCM_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U
};

VAR(SG_PS1_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_PS1_sg_oPS1_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U,0U
};

VAR(SG_ATS_PS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_ATS_PS_sg_oATS_PS_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U,{0U,0U,0U,0U,0U,0U,0U}
};

VAR(SG_TPCM_EPB_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPCM_EPB_sg_oTPCM_EPB_oJ6L_ADUCAN_Rx = {
  {0U,0U,0U,0U,0U,0U,0U,0U}
};

VAR(SG_TPDT_EPB_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPDT_EPB_sg_oTPDT_EPB_oJ6L_ADUCAN_Rx = {
  {0U,0U,0U,0U,0U,0U,0U,0U}
};

VAR(SG_TPCM_EBS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPCM_EBS_sg_oTPCM_EBS_oJ6L_ADUCAN_Rx = {
  {0U,0U,0U,0U,0U,0U,0U,0U}
};

VAR(SG_TPDT_EBS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPDT_EBS_sg_oTPDT_EBS_oJ6L_ADUCAN_Rx = {
  {0U,0U,0U,0U,0U,0U,0U,0U}
};

VAR(SG_TPCM_EPS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPCM_EPS_sg_oTPCM_EPS_oJ6L_ADUCAN_Rx = {
  {0U,0U,0U,0U,0U,0U,0U,0U}
};

VAR(SG_TPDT_EPS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPDT_EPS_sg_oTPDT_EPS_oJ6L_ADUCAN_Rx = {
  {0U,0U,0U,0U,0U,0U,0U,0U}
};

VAR(SG_TPCM_BCM_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPCM_BCM_sg_oTPCM_BCM_oJ6L_ADUCAN_Rx = {
  {0U,0U,0U,0U,0U,0U,0U,0U}
};

VAR(SG_TPDT_BCM_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPDT_BCM_sg_oTPDT_BCM_oJ6L_ADUCAN_Rx = {
  {0U,0U,0U,0U,0U,0U,0U,0U}
};

VAR(SG_TPCM_TPMS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPCM_TPMS_sg_oTPCM_TPMS_oJ6L_ADUCAN_Rx = {
  {0U,0U,0U,0U,0U,0U,0U,0U}
};

VAR(SG_TPDT_TPMS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPDT_TPMS_sg_oTPDT_TPMS_oJ6L_ADUCAN_Rx = {
  {0U,0U,0U,0U,0U,0U,0U,0U}
};

VAR(SG_TPCM_BMS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPCM_BMS_sg_oTPCM_BMS_oJ6L_ADUCAN_Rx = {
  {0U,0U,0U,0U,0U,0U,0U,0U}
};

VAR(SG_TPDT_BMS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPDT_BMS_sg_oTPDT_BMS_oJ6L_ADUCAN_Rx = {
  {0U,0U,0U,0U,0U,0U,0U,0U}
};

VAR(SG_TPCM_VCU_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPCM_VCU_sg_oTPCM_VCU_oJ6L_ADUCAN_Rx = {
  0U
};

VAR(SG_TPDT_VCU_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPDT_VCU_sg_oTPDT_VCU_oJ6L_ADUCAN_Rx = {
  0U
};

VAR(SG_TPCM_PTU_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPCM_PTU_sg_oTPCM_PTU_oJ6L_ADUCAN_Rx = {
  0U
};

VAR(SG_TPDT_PTU_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPDT_PTU_sg_oTPDT_PTU_oJ6L_ADUCAN_Rx = {
  0U
};

VAR(SG_TPCM_DCDC2_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPCM_DCDC2_sg_oTPCM_DCDC2_oJ6L_ADUCAN_Rx = {
  0U
};

VAR(SG_TPDT_DCDC2_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPDT_DCDC2_sg_oTPDT_DCDC2_oJ6L_ADUCAN_Rx = {
  0U
};

VAR(SG_TPCM_APCU_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPCM_APCU_sg_oTPCM_APCU_oJ6L_ADUCAN_Rx = {
  0U
};

VAR(SG_TPDT_APCU_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPDT_APCU_sg_oTPDT_APCU_oJ6L_ADUCAN_Rx = {
  0U
};

VAR(SG_HRW_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_HRW_sg_oHRW_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U
};

VAR(SG_RDUSt_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_RDUSt_sg_oRDUSt_oJ6L_ADUCAN_Rx = {
  0U,FALSE,FALSE,0U,0U,0U,0U,0U,FALSE,0U,0U,0U,0U,0U
};

VAR(SG_IGWSt_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_IGWSt_sg_oIGWSt_oJ6L_ADUCAN_Rx = {
  0U,0U,0U,0U
};

VAR(SG_Time_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_Time_sg_oTime_oGNSSCooling_CANMatrix_Rx = {
  0U,0U
};

VAR(SG_Ang_Rate_Raw_IMU_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_Ang_Rate_Raw_IMU_sg_oAng_Rate_Raw_IMU_oGNSSCooling_CANMatrix_Rx = {
  0U,0U,0U
};

VAR(SG_Accel_IMU_Raw_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_Accel_IMU_Raw_sg_oAccel_IMU_Raw_oGNSSCooling_CANMatrix_Rx = {
  0U,0U,0U
};

VAR(SG_InsStatus_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_InsStatus_sg_oInsStatus_oGNSSCooling_CANMatrix_Rx = {
  0U,0U,0U,0U,0U,0U,0U
};

VAR(SG_LatitudeLongitude_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_LatitudeLongitude_sg_oLatitudeLongitude_oGNSSCooling_CANMatrix_Rx = {
  0U,0U
};

VAR(SG_Altitude_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_Altitude_sg_oAltitude_oGNSSCooling_CANMatrix_Rx = {
  0U
};

VAR(SG_PosSigma_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_PosSigma_sg_oPosSigma_oGNSSCooling_CANMatrix_Rx = {
  0U,0U,0U
};

VAR(SG_VelocityLevel_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_VelocityLevel_sg_oVelocityLevel_oGNSSCooling_CANMatrix_Rx = {
  0U,0U,0U,0U
};

VAR(SG_VelocityLevelSigma_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_VelocityLevelSigma_sg_oVelocityLevelSigma_oGNSSCooling_CANMatrix_Rx = {
  0U,0U,0U,0U
};

VAR(SG_Accel_Vehicle_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_Accel_Vehicle_sg_oAccel_Vehicle_oGNSSCooling_CANMatrix_Rx = {
  0U,0U,0U
};

VAR(SG_HeadingPitchRoll_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_HeadingPitchRoll_sg_oHeadingPitchRoll_oGNSSCooling_CANMatrix_Rx = {
  0U,0U,0U
};

VAR(SG_HeadingPitchRollSigma_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_HeadingPitchRollSigma_sg_oHeadingPitchRollSigma_oGNSSCooling_CANMatrix_Rx = {
  0U,0U,0U
};

VAR(SG_AngRateVehicle_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_AngRateVehicle_sg_oAngRateVehicle_oGNSSCooling_CANMatrix_Rx = {
  0U,0U,0U
};

VAR(SG_Longitude_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_Longitude_sg_oLongitude_oGNSSCooling_CANMatrix_Rx = {
  {0U,0U,0U,0U,0U,0U,0U,0U}
};

VAR(SG_Latitude_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_Latitude_sg_oLatitude_oGNSSCooling_CANMatrix_Rx = {
  {0U,0U,0U,0U,0U,0U,0U,0U}
};

VAR(SG_RDF_State_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_RDF_State_sg_oRDF_State_oRDF2_CANMatrix_F_Rx = {
  0U,0U,0U,0U,0U
};

VAR(SG_CI_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_CI_sg_oCI_oRDF2_CANMatrix_F_Rx = {
  0U,0U,0U,0U
};

VAR(SG_RadarState_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_RadarState_sg_oRadarState_oARS408_CANMatrix_Rx = {
  FALSE,FALSE,0U,FALSE,FALSE,FALSE,FALSE,FALSE,0U,0U,0U,0U,FALSE,FALSE,0U,FALSE,0U
};

VAR(SG_VersionID_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_VersionID_sg_oVersionID_oARS408_CANMatrix_Rx = {
  0U,0U,0U,FALSE,FALSE
};

VAR(SG_Obj_0_Status_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_Obj_0_Status_sg_oObj_0_Status_oARS408_CANMatrix_Rx = {
  0U,0U,0U
};

VAR(Rx_Flag_Type, RTE_VAR_INIT_NOCACHE) Rte_Rx_Flag_Arr_CCVS1_oRx_Flag_Arr_CCVS1 = RX_FLAG_DEF;

VAR(Rx_Flag_Type, RTE_VAR_INIT_NOCACHE) Rte_Rx_Flag_Arr_EBC1_oRx_Flag_Arr_EBC1 = RX_FLAG_DEF;

VAR(Rx_Flag_Type, RTE_VAR_INIT_NOCACHE) Rte_Rx_Flag_Arr_EBC2_oRx_Flag_Arr_EBC2 = RX_FLAG_DEF;

VAR(Rx_Flag_Type, RTE_VAR_INIT_NOCACHE) Rte_Rx_Flag_Arr_EEC2_oRx_Flag_Arr_EEC2 = RX_FLAG_DEF;

VAR(Rx_Flag_Type, RTE_VAR_INIT_NOCACHE) Rte_Rx_Flag_Arr_EPB1_oRx_Flag_Arr_EPB1 = RX_FLAG_DEF;

VAR(Rx_Flag_Type, RTE_VAR_INIT_NOCACHE) Rte_Rx_Flag_Arr_EPS2_oRx_Flag_Arr_EPS2 = RX_FLAG_DEF;

VAR(Rx_Flag_Type, RTE_VAR_INIT_NOCACHE) Rte_Rx_Flag_Arr_ETC2_oRx_Flag_Arr_ETC2 = RX_FLAG_DEF;

VAR(Rx_Flag_Type, RTE_VAR_INIT_NOCACHE) Rte_Rx_Flag_Arr_LC_oRx_Flag_Arr_LC = RX_FLAG_DEF;

VAR(Rx_Flag_Type, RTE_VAR_INIT_NOCACHE) Rte_Rx_Flag_Arr_MCU1_oRx_Flag_Arr_MCU1 = RX_FLAG_DEF;

VAR(Rx_Flag_Type, RTE_VAR_INIT_NOCACHE) Rte_Rx_Flag_Arr_PS1_oRx_Flag_Arr_PS1 = RX_FLAG_DEF;

VAR(Rx_Flag_Type, RTE_VAR_INIT_NOCACHE) Rte_Rx_Flag_Arr_VCU_Status_oRx_Flag_Arr_VCU_Status = RX_FLAG_DEF;

VAR(Rx_Flag_Type, RTE_VAR_INIT_NOCACHE) Rte_Rx_Flag_Arr_VDC2_oRx_Flag_Arr_VDC2 = RX_FLAG_DEF;

VAR(CCVS1_SigStatusType, RTE_VAR_INIT_NOCACHE) Rte_Rx_SigStat_Arr_CCVS1_oRx_SigStat_Arr_CCVS1 = {0u};

VAR(EBC1_SigStatusType, RTE_VAR_INIT_NOCACHE) Rte_Rx_SigStat_Arr_EBC1_oRx_SigStat_Arr_EBC1 = {0u};

VAR(EBC2_SigStatusType, RTE_VAR_INIT_NOCACHE) Rte_Rx_SigStat_Arr_EBC2_oRx_SigStat_Arr_EBC2 = {0u};

VAR(EEC2_SigStatusType, RTE_VAR_INIT_NOCACHE) Rte_Rx_SigStat_Arr_EEC2_oRx_SigStat_Arr_EEC2 = {0u};

VAR(EPB1_SigStatusType, RTE_VAR_INIT_NOCACHE) Rte_Rx_SigStat_Arr_EPB1_oRx_SigStat_Arr_EPB1 = {0u};

VAR(EPS2_SigStatusType, RTE_VAR_INIT_NOCACHE) Rte_Rx_SigStat_Arr_EPS2_oRx_SigStat_Arr_EPS2 = {0u};

VAR(ETC2_SigStatusType, RTE_VAR_INIT_NOCACHE) Rte_Rx_SigStat_Arr_ETC2_oRx_SigStat_Arr_ETC2 = {0u};

VAR(LC_SigStatusType, RTE_VAR_INIT_NOCACHE) Rte_Rx_SigStat_Arr_LC_oRx_SigStat_Arr_LC = {0u};

VAR(MCU1_SigStatusType, RTE_VAR_INIT_NOCACHE) Rte_Rx_SigStat_Arr_MCU1_oRx_SigStat_Arr_MCU1 = {0u};

VAR(PS1_SigStatusType, RTE_VAR_INIT_NOCACHE) Rte_Rx_SigStat_Arr_PS1_oRx_SigStat_Arr_PS1 = {0u};

VAR(VCU_Status_SigStatusType, RTE_VAR_INIT_NOCACHE) Rte_Rx_SigStat_Arr_VCU_Status_oRx_SigStat_Arr_VCU_Status = {0u};

VAR(VDC2_SigStatusType, RTE_VAR_INIT_NOCACHE) Rte_Rx_SigStat_Arr_VDC2_oRx_SigStat_Arr_VDC2 = {0u};

VAR(uint64, RTE_VAR_INIT_NOCACHE) Rte_Rx_Time_Arr_CCVS1_oRx_Time_Arr_CCVS1 = 0u;

VAR(uint64, RTE_VAR_INIT_NOCACHE) Rte_Rx_Time_Arr_EBC1_oRx_Time_Arr_EBC1 = 0u;

VAR(uint64, RTE_VAR_INIT_NOCACHE) Rte_Rx_Time_Arr_EBC2_oRx_Time_Arr_EBC2 = 0u;

VAR(uint64, RTE_VAR_INIT_NOCACHE) Rte_Rx_Time_Arr_EEC2_oRx_Time_Arr_EEC2 = 0u;

VAR(uint64, RTE_VAR_INIT_NOCACHE) Rte_Rx_Time_Arr_EPB1_oRx_Time_Arr_EPB1 = 0u;

VAR(uint64, RTE_VAR_INIT_NOCACHE) Rte_Rx_Time_Arr_EPS2_oRx_Time_Arr_EPS2 = 0u;

VAR(uint64, RTE_VAR_INIT_NOCACHE) Rte_Rx_Time_Arr_ETC2_oRx_Time_Arr_ETC2 = 0u;

VAR(uint64, RTE_VAR_INIT_NOCACHE) Rte_Rx_Time_Arr_LC_oRx_Time_Arr_LC = 0u;

VAR(uint64, RTE_VAR_INIT_NOCACHE) Rte_Rx_Time_Arr_MCU1_oRx_Time_Arr_MCU1 = 0u;

VAR(uint64, RTE_VAR_INIT_NOCACHE) Rte_Rx_Time_Arr_PS1_oRx_Time_Arr_PS1 = 0u;

VAR(uint64, RTE_VAR_INIT_NOCACHE) Rte_Rx_Time_Arr_VCU_Status_oRx_Time_Arr_VCU_Status = 0u;

VAR(uint64, RTE_VAR_INIT_NOCACHE) Rte_Rx_Time_Arr_VDC2_oRx_Time_Arr_VDC2 = 0u;

VAR(uint8, RTE_VAR_INIT_NOCACHE) Rte_Rx_Pro_Cnt_LC_oRx_Pro_Cnt_LC = 0u;

VAR(uint8, RTE_VAR_INIT_NOCACHE) Rte_SecurityAttemptCounter_MirrorBlock_oSecurityAttemptCounter_MirrorBlock = 0u;

VAR(rt_Array_uint8_16, RTE_VAR_INIT_NOCACHE) Rte_ConfigurationInformation_MirrorBlock_oConfigurationInformation_MirrorBlock = {0u};

VAR(rt_Array_uint8_4, RTE_VAR_INIT_NOCACHE) Rte_ECUInstallationDate_MirrorBlock_oECUInstallationDate_MirrorBlock = {0u};

VAR(rt_Array_uint8_4, RTE_VAR_INIT_NOCACHE) Rte_ProgrammingDate_MirrorBlock_oProgrammingDate_MirrorBlock = {0u};

VAR(rt_Array_uint8_16, RTE_VAR_INIT_NOCACHE) Rte_Reserved_1_MirrorBlock_oReserved_1_MirrorBlock = {0u};

VAR(rt_Array_uint8_10, RTE_VAR_INIT_NOCACHE) Rte_TesterSeriesNumber_MirrorBlock_oTesterSeriesNumber_MirrorBlock = {0u};

VAR(rt_Array_uint8_17, RTE_VAR_INIT_NOCACHE) Rte_VIN_MirrorBlock_oVIN_MirrorBlock = {0u};

VAR(rt_Array_uint8_100, RTE_VAR_INIT_NOCACHE) Rte_AdminData_MirrorBlock_oAdminData_MirrorBlock = {0u};



#if (defined(__TASKING__))
#define OS_CORE0_START_SEC_CODE
#include "Os_MemMap.h"
#endif

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_CCVS1_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_CCVS1_sg_oCCVS1_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_CCVS1_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_CCVS1_oCCVS1_PBSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_CCVS1_sg_oCCVS1_oJ6L_ADUCAN_Rx)).CCVS1_PBSwitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_CCVS1_oCCVS1_CruiseCtrlPauseSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_CCVS1_sg_oCCVS1_oJ6L_ADUCAN_Rx)).CCVS1_CruiseCtrlPauseSwitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_CCVS1_oCCVS1_WheelBasedVehSpd_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_CCVS1_sg_oCCVS1_oJ6L_ADUCAN_Rx)).CCVS1_WheelBasedVehSpd);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_CCVS1_oCruiseCtrlActive_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_CCVS1_sg_oCCVS1_oJ6L_ADUCAN_Rx)).CruiseCtrlActive);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_CCVS1_oCCVS1_CruiseCtrlEnbSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_CCVS1_sg_oCCVS1_oJ6L_ADUCAN_Rx)).CCVS1_CruiseCtrlEnbSwitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_CCVS1_oCCVS1_BrakeSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_CCVS1_sg_oCCVS1_oJ6L_ADUCAN_Rx)).CCVS1_BrakeSwitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_CCVS1_oCCVS1_ClutchSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_CCVS1_sg_oCCVS1_oJ6L_ADUCAN_Rx)).CCVS1_ClutchSwitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_CCVS1_oCCVS1_CruiseCtrlSetSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_CCVS1_sg_oCCVS1_oJ6L_ADUCAN_Rx)).CCVS1_CruiseCtrlSetSwitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_CCVS1_oCCVS1_CruiseCtrlResumeSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_CCVS1_sg_oCCVS1_oJ6L_ADUCAN_Rx)).CCVS1_CruiseCtrlResumeSwitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_CCVS1_oCCVS1_CruiseCtrlSetSpd_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_CCVS1_sg_oCCVS1_oJ6L_ADUCAN_Rx)).CCVS1_CruiseCtrlSetSpd);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_CCVS1_oCCVS1_PTOManagmentState_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_CCVS1_sg_oCCVS1_oJ6L_ADUCAN_Rx)).CCVS1_PTOManagmentState);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_CCVS1_oCCVS1_CruiseCtrlState_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_CCVS1_sg_oCCVS1_oJ6L_ADUCAN_Rx)).CCVS1_CruiseCtrlState);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_CCVS1_sg_oCCVS1_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_ETC2_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_ETC2_sg_oETC2_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_ETC2_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_ETC2_oETC2_TransSelectedGear_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_ETC2_sg_oETC2_oJ6L_ADUCAN_Rx)).ETC2_TransSelectedGear);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_ETC2_oETC2_TransActualGearRatio_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_ETC2_sg_oETC2_oJ6L_ADUCAN_Rx)).ETC2_TransActualGearRatio);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_ETC2_oETC2_TransCurrentGear_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_ETC2_sg_oETC2_oJ6L_ADUCAN_Rx)).ETC2_TransCurrentGear);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_ETC2_sg_oETC2_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_DM1_EPB_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_DM1_EPB_sg_oDM1_EPB_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_DM1_EPB_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_EPB_oDM1_EPB_ProtectLamp_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_EPB_sg_oDM1_EPB_oJ6L_ADUCAN_Rx)).DM1_EPB_ProtectLamp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_EPB_oDM1_EPB_AmberWarningLamp_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_EPB_sg_oDM1_EPB_oJ6L_ADUCAN_Rx)).DM1_EPB_AmberWarningLamp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_EPB_oDM1_EPB_RedStopLamp_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_EPB_sg_oDM1_EPB_oJ6L_ADUCAN_Rx)).DM1_EPB_RedStopLamp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_EPB_oDM1_EPB_MalfunctionIndicatorLamp_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_EPB_sg_oDM1_EPB_oJ6L_ADUCAN_Rx)).DM1_EPB_MalfunctionIndicatorLamp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_EPB_oDM1_EPB_SAELamp_Reserved_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_EPB_sg_oDM1_EPB_oJ6L_ADUCAN_Rx)).DM1_EPB_SAELamp_Reserved);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_EPB_oDM1_EPB_SPN8_LeastSignificantBit_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_EPB_sg_oDM1_EPB_oJ6L_ADUCAN_Rx)).DM1_EPB_SPN8_LeastSignificantBit);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_EPB_oDM1_EPB_SPN_secondByteOfSPN_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_EPB_sg_oDM1_EPB_oJ6L_ADUCAN_Rx)).DM1_EPB_SPN_secondByteOfSPN);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_EPB_oDM1_EPB_FMI_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_EPB_sg_oDM1_EPB_oJ6L_ADUCAN_Rx)).DM1_EPB_FMI);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_EPB_oDM1_EPB_SPN3MmostSignificantBit_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_EPB_sg_oDM1_EPB_oJ6L_ADUCAN_Rx)).DM1_EPB_SPN3MmostSignificantBit);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_EPB_oDM1_EPB_OccurrenceCount_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_EPB_sg_oDM1_EPB_oJ6L_ADUCAN_Rx)).DM1_EPB_OccurrenceCount);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_EPB_oDM1_EPB_SPNConversionMethod_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_EPB_sg_oDM1_EPB_oJ6L_ADUCAN_Rx)).DM1_EPB_SPNConversionMethod);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_DM1_EPB_sg_oDM1_EPB_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_EPB1_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_EPB1_sg_oEPB1_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_EPB1_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPB1_oEPB1_PressOfSpringBrakeChamber_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPB1_sg_oEPB1_oJ6L_ADUCAN_Rx)).EPB1_PressOfSpringBrakeChamber);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPB1_oEPB1_ReasonForInhibitOfRelease_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPB1_sg_oEPB1_oJ6L_ADUCAN_Rx)).EPB1_ReasonForInhibitOfRelease);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPB1_oEPB1_ReasonForInhibitOfApply_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPB1_sg_oEPB1_oJ6L_ADUCAN_Rx)).EPB1_ReasonForInhibitOfApply);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPB1_oEPB1_AmberWarnLampStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPB1_sg_oEPB1_oJ6L_ADUCAN_Rx)).EPB1_AmberWarnLampStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPB1_oEPB1_RedStopLampStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPB1_sg_oEPB1_oJ6L_ADUCAN_Rx)).EPB1_RedStopLampStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPB1_oEPB1_StateOfInhibitOfEPBRelease_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPB1_sg_oEPB1_oJ6L_ADUCAN_Rx)).EPB1_StateOfInhibitOfEPBRelease);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPB1_oEPB1_StateOfEPB_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPB1_sg_oEPB1_oJ6L_ADUCAN_Rx)).EPB1_StateOfEPB);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPB1_oEPB1_WorkModeOfEPB_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPB1_sg_oEPB1_oJ6L_ADUCAN_Rx)).EPB1_WorkModeOfEPB);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPB1_oEPB1_TrailerTestActivationState_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPB1_sg_oEPB1_oJ6L_ADUCAN_Rx)).EPB1_TrailerTestActivationState);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPB1_oEPB1_StateOfInhibitOfEPBApply_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPB1_sg_oEPB1_oJ6L_ADUCAN_Rx)).EPB1_StateOfInhibitOfEPBApply);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPB1_oEPB1_EPBHCUInParkState_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPB1_sg_oEPB1_oJ6L_ADUCAN_Rx)).EPB1_EPBHCUInParkState);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPB1_oEPB1_EPBHCUInReleaseState_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPB1_sg_oEPB1_oJ6L_ADUCAN_Rx)).EPB1_EPBHCUInReleaseState);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPB1_oEPB1_PstnOfEPBHCU_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPB1_sg_oEPB1_oJ6L_ADUCAN_Rx)).EPB1_PstnOfEPBHCU);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_EPB1_sg_oEPB1_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_DM1_ABS_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_DM1_ABS_sg_oDM1_ABS_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_DM1_ABS_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_ABS_oDM1_ABS_ProtectLamp_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_ABS_sg_oDM1_ABS_oJ6L_ADUCAN_Rx)).DM1_ABS_ProtectLamp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_ABS_oDM1_ABS_AmberWarningLamp_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_ABS_sg_oDM1_ABS_oJ6L_ADUCAN_Rx)).DM1_ABS_AmberWarningLamp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_ABS_oDM1_ABS_RedStopLamp_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_ABS_sg_oDM1_ABS_oJ6L_ADUCAN_Rx)).DM1_ABS_RedStopLamp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_ABS_oDM1_ABS_MalfunctionIndicatorLamp_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_ABS_sg_oDM1_ABS_oJ6L_ADUCAN_Rx)).DM1_ABS_MalfunctionIndicatorLamp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_ABS_oDM1_ABS_SPN8_LeastSignificantBit_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_ABS_sg_oDM1_ABS_oJ6L_ADUCAN_Rx)).DM1_ABS_SPN8_LeastSignificantBit);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_ABS_oDM1_ABS_SPN_secondByteOfSPN_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_ABS_sg_oDM1_ABS_oJ6L_ADUCAN_Rx)).DM1_ABS_SPN_secondByteOfSPN);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_ABS_oDM1_ABS_FMI_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_ABS_sg_oDM1_ABS_oJ6L_ADUCAN_Rx)).DM1_ABS_FMI);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_ABS_oDM1_ABS_SPN3MmostSignificantBit_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_ABS_sg_oDM1_ABS_oJ6L_ADUCAN_Rx)).DM1_ABS_SPN3MmostSignificantBit);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_ABS_oDM1_ABS_OccurrenceCount_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_ABS_sg_oDM1_ABS_oJ6L_ADUCAN_Rx)).DM1_ABS_OccurrenceCount);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_ABS_oDM1_ABS_SPNConversionMethod_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_ABS_sg_oDM1_ABS_oJ6L_ADUCAN_Rx)).DM1_ABS_SPNConversionMethod);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_DM1_ABS_sg_oDM1_ABS_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_EBC1_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_EBC1_sg_oEBC1_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_EBC1_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC1_oEBC1_ASREngCtrlActive_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC1_sg_oEBC1_oJ6L_ADUCAN_Rx)).EBC1_ASREngCtrlActive);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC1_oEBC1_ASRBrakeCtrlActive_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC1_sg_oEBC1_oJ6L_ADUCAN_Rx)).EBC1_ASRBrakeCtrlActive);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC1_oEBC1_ABSActive_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC1_sg_oEBC1_oJ6L_ADUCAN_Rx)).EBC1_ABSActive);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC1_oEBC1_EBSBrakeSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC1_sg_oEBC1_oJ6L_ADUCAN_Rx)).EBC1_EBSBrakeSwitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC1_oEBC1_BrakePedalPstn_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC1_sg_oEBC1_oJ6L_ADUCAN_Rx)).EBC1_BrakePedalPstn);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC1_oEBC1_ABSOffroadSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC1_sg_oEBC1_oJ6L_ADUCAN_Rx)).EBC1_ABSOffroadSwitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC1_oEBC1_ASROffroadSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC1_sg_oEBC1_oJ6L_ADUCAN_Rx)).EBC1_ASROffroadSwitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC1_oEBC1_ASRHillHolderSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC1_sg_oEBC1_oJ6L_ADUCAN_Rx)).EBC1_ASRHillHolderSwitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC1_oEBC1_ABSFullyOperational_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC1_sg_oEBC1_oJ6L_ADUCAN_Rx)).EBC1_ABSFullyOperational);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC1_oEBC1_EBSRedWarnSignal_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC1_sg_oEBC1_oJ6L_ADUCAN_Rx)).EBC1_EBSRedWarnSignal);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC1_oEBC1_ABSOrEBSAmberWarnSignal_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC1_sg_oEBC1_oJ6L_ADUCAN_Rx)).EBC1_ABSOrEBSAmberWarnSignal);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC1_oEBC1_ATCOrASRInfoSignal_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC1_sg_oEBC1_oJ6L_ADUCAN_Rx)).EBC1_ATCOrASRInfoSignal);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC1_oEBC1_SourceAddressOfCtrlDevice_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC1_sg_oEBC1_oJ6L_ADUCAN_Rx)).EBC1_SourceAddressOfCtrlDevice);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC1_oEBC1_TractorMountTrailerABSWarn_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC1_sg_oEBC1_oJ6L_ADUCAN_Rx)).EBC1_TractorMountTrailerABSWarn);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_EBC1_sg_oEBC1_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_EBC2_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_EBC2_sg_oEBC2_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_EBC2_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC2_oEBC2_FrontAxleSpeed_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC2_sg_oEBC2_oJ6L_ADUCAN_Rx)).EBC2_FrontAxleSpeed);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC2_oEBC2_RelativeSpdFrontAxleLWhl_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC2_sg_oEBC2_oJ6L_ADUCAN_Rx)).EBC2_RelativeSpdFrontAxleLWhl);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC2_oEBC2_RelativeSpdFrontAxleRWhl_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC2_sg_oEBC2_oJ6L_ADUCAN_Rx)).EBC2_RelativeSpdFrontAxleRWhl);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC2_oEBC2_RelativeSpdRearAxle1LWhl_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC2_sg_oEBC2_oJ6L_ADUCAN_Rx)).EBC2_RelativeSpdRearAxle1LWhl);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC2_oEBC2_RelativeSpdRearAxle1RWhl_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC2_sg_oEBC2_oJ6L_ADUCAN_Rx)).EBC2_RelativeSpdRearAxle1RWhl);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC2_oEBC2_RelativeSpdRearAxle2LWhl_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC2_sg_oEBC2_oJ6L_ADUCAN_Rx)).EBC2_RelativeSpdRearAxle2LWhl);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC2_oEBC2_RelativeSpdRearAxle2RWhl_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC2_sg_oEBC2_oJ6L_ADUCAN_Rx)).EBC2_RelativeSpdRearAxle2RWhl);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_EBC2_sg_oEBC2_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_EBC5_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_EBC5_sg_oEBC5_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_EBC5_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC5_oEBC5_BrakeTempWarning_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC5_sg_oEBC5_oJ6L_ADUCAN_Rx)).EBC5_BrakeTempWarning);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC5_oEBC5_HaltBrakeMode_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC5_sg_oEBC5_oJ6L_ADUCAN_Rx)).EBC5_HaltBrakeMode);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC5_oEBC5_HillHolderMode_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC5_sg_oEBC5_oJ6L_ADUCAN_Rx)).EBC5_HillHolderMode);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC5_oEBC5_FoundationBrakeUse_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC5_sg_oEBC5_oJ6L_ADUCAN_Rx)).EBC5_FoundationBrakeUse);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC5_oEBC5_XBRSysState_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC5_sg_oEBC5_oJ6L_ADUCAN_Rx)).EBC5_XBRSysState);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC5_oEBC5_XBRActiveCtrlMode_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC5_sg_oEBC5_oJ6L_ADUCAN_Rx)).EBC5_XBRActiveCtrlMode);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC5_oEBC5_XBRAccelLim_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC5_sg_oEBC5_oJ6L_ADUCAN_Rx)).EBC5_XBRAccelLim);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EBC5_oEBC5_EmergencyBrakeActive_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EBC5_sg_oEBC5_oJ6L_ADUCAN_Rx)).EBC5_EmergencyBrakeActive);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_EBC5_sg_oEBC5_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_ESC1_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_ESC1_sg_oESC1_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_ESC1_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_ESC1_oESC1_ActualInnerWheelSteerAng_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_ESC1_sg_oESC1_oJ6L_ADUCAN_Rx)).ESC1_ActualInnerWheelSteerAng);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_ESC1_oESC1_AxleLocation_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_ESC1_sg_oESC1_oJ6L_ADUCAN_Rx)).ESC1_AxleLocation);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_ESC1_oESC1_StatOfSteerAxle_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_ESC1_sg_oESC1_oJ6L_ADUCAN_Rx)).ESC1_StatOfSteerAxle);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_ESC1_oESC1_AxleLoweringInhibit_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_ESC1_sg_oESC1_oJ6L_ADUCAN_Rx)).ESC1_AxleLoweringInhibit);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_ESC1_oESC1_SteerType_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_ESC1_sg_oESC1_oJ6L_ADUCAN_Rx)).ESC1_SteerType);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_ESC1_oESC1_TypeOfSteerForces_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_ESC1_sg_oESC1_oJ6L_ADUCAN_Rx)).ESC1_TypeOfSteerForces);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_ESC1_oESC1_TypeOfSteerTrans_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_ESC1_sg_oESC1_oJ6L_ADUCAN_Rx)).ESC1_TypeOfSteerTrans);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_ESC1_sg_oESC1_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_CVW_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_CVW_sg_oCVW_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_CVW_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_CVW_oCVW_PoweredVehWeight_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_CVW_sg_oCVW_oJ6L_ADUCAN_Rx)).CVW_PoweredVehWeight);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_CVW_oCVW_GrossCombineVehWeight_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_CVW_sg_oCVW_oJ6L_ADUCAN_Rx)).CVW_GrossCombineVehWeight);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_CVW_sg_oCVW_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_VDC2_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_VDC2_sg_oVDC2_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_VDC2_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_VDC2_oVDC2_SteerWheelAng_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_VDC2_sg_oVDC2_oJ6L_ADUCAN_Rx)).VDC2_SteerWheelAng);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_VDC2_oVDC2_SteerWheelTurnCounter_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_VDC2_sg_oVDC2_oJ6L_ADUCAN_Rx)).VDC2_SteerWheelTurnCounter);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_VDC2_oVDC2_SteerWheelAngSensorType_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_VDC2_sg_oVDC2_oJ6L_ADUCAN_Rx)).VDC2_SteerWheelAngSensorType);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_VDC2_oVDC2_YawRate_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_VDC2_sg_oVDC2_oJ6L_ADUCAN_Rx)).VDC2_YawRate);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_VDC2_oVDC2_LateralAccel_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_VDC2_sg_oVDC2_oJ6L_ADUCAN_Rx)).VDC2_LateralAccel);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_VDC2_oVDC2_LongitudinalAccel_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_VDC2_sg_oVDC2_oJ6L_ADUCAN_Rx)).VDC2_LongitudinalAccel);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_VDC2_sg_oVDC2_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_ComProxy_J6L_ADUCAN_TxSignal_SG_LC_ADU_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_LC_ADU_sg_oLC_ADU_oJ6L_ADUCAN_Tx);
  ret |= Com_SendSignal(ComConf_ComSignal_LC_ADU_oLC_ADU_RunLightCmd_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_LC_ADU_sg_oLC_ADU_oJ6L_ADUCAN_Tx)).LC_ADU_RunLightCmd);
  ret |= Com_SendSignal(ComConf_ComSignal_LC_ADU_oLC_ADU_LowBeamHeadLightCmd_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_LC_ADU_sg_oLC_ADU_oJ6L_ADUCAN_Tx)).LC_ADU_LowBeamHeadLightCmd);
  ret |= Com_SendSignal(ComConf_ComSignal_LC_ADU_oLC_ADU_HighBeamHeadLightCmd_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_LC_ADU_sg_oLC_ADU_oJ6L_ADUCAN_Tx)).LC_ADU_HighBeamHeadLightCmd);
  ret |= Com_SendSignal(ComConf_ComSignal_LC_ADU_oLC_ADU_TractorFrontFogLightsCmd_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_LC_ADU_sg_oLC_ADU_oJ6L_ADUCAN_Tx)).LC_ADU_TractorFrontFogLightsCmd);
  ret |= Com_SendSignal(ComConf_ComSignal_LC_ADU_oLC_ADU_RightTurnSignalLightsCmd_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_LC_ADU_sg_oLC_ADU_oJ6L_ADUCAN_Tx)).LC_ADU_RightTurnSignalLightsCmd);
  ret |= Com_SendSignal(ComConf_ComSignal_LC_ADU_oLC_ADU_LeftTurnSignalLightsCmd_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_LC_ADU_sg_oLC_ADU_oJ6L_ADUCAN_Tx)).LC_ADU_LeftTurnSignalLightsCmd);
  ret |= Com_SendSignal(ComConf_ComSignal_LC_ADU_oLC_ADU_BackUpLightAndHornCmd_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_LC_ADU_sg_oLC_ADU_oJ6L_ADUCAN_Tx)).LC_ADU_BackUpLightAndHornCmd);
  ret |= Com_SendSignal(ComConf_ComSignal_LC_ADU_oLC_ADU_ImplementMarkerLightCmd_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_LC_ADU_sg_oLC_ADU_oJ6L_ADUCAN_Tx)).LC_ADU_ImplementMarkerLightCmd);
  ret |= Com_SendSignal(ComConf_ComSignal_LC_ADU_oLC_ADU_RearFogLightCmd_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_LC_ADU_sg_oLC_ADU_oJ6L_ADUCAN_Tx)).LC_ADU_RearFogLightCmd);
  (void)Com_SendSignalGroup(ComConf_ComGroupSignal_LC_ADU_oJ6L_ADUCAN_TX);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_LC_ADU_sg_oLC_ADU_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_LC_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_LC_sg_oLC_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_LC_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_LC_oLC_RunLightCmd_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_LC_sg_oLC_oJ6L_ADUCAN_Rx)).LC_RunLightCmd);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_LC_oLC_LowBeamHeadLightCmd_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_LC_sg_oLC_oJ6L_ADUCAN_Rx)).LC_LowBeamHeadLightCmd);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_LC_oLC_HighBeamHeadLightCmd_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_LC_sg_oLC_oJ6L_ADUCAN_Rx)).LC_HighBeamHeadLightCmd);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_LC_oLC_TractorFrontFogLightsCmd_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_LC_sg_oLC_oJ6L_ADUCAN_Rx)).LC_TractorFrontFogLightsCmd);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_LC_oLC_RightTurnSignalLightsCmd_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_LC_sg_oLC_oJ6L_ADUCAN_Rx)).LC_RightTurnSignalLightsCmd);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_LC_oLC_LeftTurnSignalLightsCmd_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_LC_sg_oLC_oJ6L_ADUCAN_Rx)).LC_LeftTurnSignalLightsCmd);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_LC_oLC_BackUpLightAndAlarmHornCmd_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_LC_sg_oLC_oJ6L_ADUCAN_Rx)).LC_BackUpLightAndAlarmHornCmd);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_LC_oLC_CenterStopLightCmd_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_LC_sg_oLC_oJ6L_ADUCAN_Rx)).LC_CenterStopLightCmd);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_LC_oLC_ImplementMarkerLightCmd_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_LC_sg_oLC_oJ6L_ADUCAN_Rx)).LC_ImplementMarkerLightCmd);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_LC_oLC_RearFogLightCmd_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_LC_sg_oLC_oJ6L_ADUCAN_Rx)).LC_RearFogLightCmd);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_LC_oLC_DriverSideDomeLight_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_LC_sg_oLC_oJ6L_ADUCAN_Rx)).LC_DriverSideDomeLight);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_LC_oLC_PassengerSideDomeLight_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_LC_sg_oLC_oJ6L_ADUCAN_Rx)).LC_PassengerSideDomeLight);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_LC_sg_oLC_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_DC2_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_DC2_sg_oDC2_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_DC2_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DC2_oDC2_LockStatOfDoor1_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DC2_sg_oDC2_oJ6L_ADUCAN_Rx)).DC2_LockStatOfDoor1);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DC2_oDC2_OpenStatOfDoor1_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DC2_sg_oDC2_oJ6L_ADUCAN_Rx)).DC2_OpenStatOfDoor1);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DC2_oDC2_LockStatOfDoor2_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DC2_sg_oDC2_oJ6L_ADUCAN_Rx)).DC2_LockStatOfDoor2);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DC2_oDC2_OpenStatOfDoor2_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DC2_sg_oDC2_oJ6L_ADUCAN_Rx)).DC2_OpenStatOfDoor2);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_DC2_sg_oDC2_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_MCU1_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_MCU1_sg_oMCU1_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_MCU1_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_MCU1_oMCU1_MotorWorkMode_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_MCU1_sg_oMCU1_oJ6L_ADUCAN_Rx)).MCU1_MotorWorkMode);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_MCU1_oMCU1_MotorRotateDirection_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_MCU1_sg_oMCU1_oJ6L_ADUCAN_Rx)).MCU1_MotorRotateDirection);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_MCU1_oMCU1_MotorSysStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_MCU1_sg_oMCU1_oJ6L_ADUCAN_Rx)).MCU1_MotorSysStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_MCU1_oMCU1_ActualMotorTrqHR_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_MCU1_sg_oMCU1_oJ6L_ADUCAN_Rx)).MCU1_ActualMotorTrqHR);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_MCU1_oMCU1_MaxOutputMotorTrqHR_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_MCU1_sg_oMCU1_oJ6L_ADUCAN_Rx)).MCU1_MaxOutputMotorTrqHR);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_MCU1_oMCU1_MotorTrq_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_MCU1_sg_oMCU1_oJ6L_ADUCAN_Rx)).MCU1_MotorTrq);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_MCU1_oMCU1_MaxOutputMotorTrq_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_MCU1_sg_oMCU1_oJ6L_ADUCAN_Rx)).MCU1_MaxOutputMotorTrq);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_MCU1_oMCU1_MotorSpd_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_MCU1_sg_oMCU1_oJ6L_ADUCAN_Rx)).MCU1_MotorSpd);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_MCU1_oMCU1_HighVoltOffPermit_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_MCU1_sg_oMCU1_oJ6L_ADUCAN_Rx)).MCU1_HighVoltOffPermit);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_MCU1_oMCU1_MotorDischargeStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_MCU1_sg_oMCU1_oJ6L_ADUCAN_Rx)).MCU1_MotorDischargeStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_MCU1_oMCU1_MotorFaliureStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_MCU1_sg_oMCU1_oJ6L_ADUCAN_Rx)).MCU1_MotorFaliureStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_MCU1_oMCU1_MsgCounter_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_MCU1_sg_oMCU1_oJ6L_ADUCAN_Rx)).MCU1_MsgCounter);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_MCU1_oMCU1_MsgChecksum_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_MCU1_sg_oMCU1_oJ6L_ADUCAN_Rx)).MCU1_MsgChecksum);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_MCU1_sg_oMCU1_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_DM1_EPS_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_DM1_EPS_sg_oDM1_EPS_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_DM1_EPS_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_EPS_oDM1_EPS_ProtectLamp_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_EPS_sg_oDM1_EPS_oJ6L_ADUCAN_Rx)).DM1_EPS_ProtectLamp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_EPS_oDM1_EPS_AmberWarningLamp_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_EPS_sg_oDM1_EPS_oJ6L_ADUCAN_Rx)).DM1_EPS_AmberWarningLamp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_EPS_oDM1_EPS_RedStopLamp_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_EPS_sg_oDM1_EPS_oJ6L_ADUCAN_Rx)).DM1_EPS_RedStopLamp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_EPS_oDM1_EPS_MalfunctionIndicatorLamp_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_EPS_sg_oDM1_EPS_oJ6L_ADUCAN_Rx)).DM1_EPS_MalfunctionIndicatorLamp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_EPS_oDM1_EPS_SAELamp_Reserved_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_EPS_sg_oDM1_EPS_oJ6L_ADUCAN_Rx)).DM1_EPS_SAELamp_Reserved);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_EPS_oDM1_EPS_SPN8_LeastSignificantBit_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_EPS_sg_oDM1_EPS_oJ6L_ADUCAN_Rx)).DM1_EPS_SPN8_LeastSignificantBit);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_EPS_oDM1_EPS_SPN_secondByteOfSPN_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_EPS_sg_oDM1_EPS_oJ6L_ADUCAN_Rx)).DM1_EPS_SPN_secondByteOfSPN);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_EPS_oDM1_EPS_FMI_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_EPS_sg_oDM1_EPS_oJ6L_ADUCAN_Rx)).DM1_EPS_FMI);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_EPS_oDM1_EPS_SPN3MmostSignificantBit_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_EPS_sg_oDM1_EPS_oJ6L_ADUCAN_Rx)).DM1_EPS_SPN3MmostSignificantBit);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_EPS_oDM1_EPS_OccurrenceCount_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_EPS_sg_oDM1_EPS_oJ6L_ADUCAN_Rx)).DM1_EPS_OccurrenceCount);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_EPS_oDM1_EPS_SPNConversionMethod_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_EPS_sg_oDM1_EPS_oJ6L_ADUCAN_Rx)).DM1_EPS_SPNConversionMethod);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_DM1_EPS_sg_oDM1_EPS_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_EPS1_ZF_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_EPS1_ZF_sg_oEPS1_ZF_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_EPS1_ZF_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPS1_ZF_oEPS1_ColumnTrq_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPS1_ZF_sg_oEPS1_ZF_oJ6L_ADUCAN_Rx)).EPS1_ColumnTrq);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPS1_ZF_oEPS1_ColumnVelocity_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPS1_ZF_sg_oEPS1_ZF_oJ6L_ADUCAN_Rx)).EPS1_ColumnVelocity);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPS1_ZF_oEPS1_PullCompensation_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPS1_ZF_sg_oEPS1_ZF_oJ6L_ADUCAN_Rx)).EPS1_PullCompensation);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPS1_ZF_oEPS1_ColumnTrqQF_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPS1_ZF_sg_oEPS1_ZF_oJ6L_ADUCAN_Rx)).EPS1_ColumnTrqQF);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPS1_ZF_oEPS1_ColumnVelocityQF_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPS1_ZF_sg_oEPS1_ZF_oJ6L_ADUCAN_Rx)).EPS1_ColumnVelocityQF);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPS1_ZF_oEPS1_IgnitionState_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPS1_ZF_sg_oEPS1_ZF_oJ6L_ADUCAN_Rx)).EPS1_IgnitionState);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPS1_ZF_oEPS1_HandsOffDetected_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPS1_ZF_sg_oEPS1_ZF_oJ6L_ADUCAN_Rx)).EPS1_HandsOffDetected);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPS1_ZF_oEPS1_HandsOnDetected_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPS1_ZF_sg_oEPS1_ZF_oJ6L_ADUCAN_Rx)).EPS1_HandsOnDetected);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPS1_ZF_oEPS1_MessageChecksum_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPS1_ZF_sg_oEPS1_ZF_oJ6L_ADUCAN_Rx)).EPS1_MessageChecksum);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPS1_ZF_oEPS1_MessageCounter_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPS1_ZF_sg_oEPS1_ZF_oJ6L_ADUCAN_Rx)).EPS1_MessageCounter);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_EPS1_ZF_sg_oEPS1_ZF_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_EPS2_ZF_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_EPS2_ZF_sg_oEPS2_ZF_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_EPS2_ZF_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPS2_ZF_oEPS2_AbsSteerPstn_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPS2_ZF_sg_oEPS2_ZF_oJ6L_ADUCAN_Rx)).EPS2_AbsSteerPstn);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPS2_ZF_oEPS2_ExtInputCmdEcho_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPS2_ZF_sg_oEPS2_ZF_oJ6L_ADUCAN_Rx)).EPS2_ExtInputCmdEcho);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPS2_ZF_oEPS2_StatusOrError_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPS2_ZF_sg_oEPS2_ZF_oJ6L_ADUCAN_Rx)).EPS2_StatusOrError);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPS2_ZF_oEPS2_ActualMode_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPS2_ZF_sg_oEPS2_ZF_oJ6L_ADUCAN_Rx)).EPS2_ActualMode);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPS2_ZF_oEPS2_ReqMode_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPS2_ZF_sg_oEPS2_ZF_oJ6L_ADUCAN_Rx)).EPS2_ReqMode);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPS2_ZF_oEPS2_AbsSteerPstnQF_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPS2_ZF_sg_oEPS2_ZF_oJ6L_ADUCAN_Rx)).EPS2_AbsSteerPstnQF);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPS2_ZF_oEPS2_MessageChecksum_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPS2_ZF_sg_oEPS2_ZF_oJ6L_ADUCAN_Rx)).EPS2_MessageChecksum);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPS2_ZF_oEPS2_MessageCounter_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPS2_ZF_sg_oEPS2_ZF_oJ6L_ADUCAN_Rx)).EPS2_MessageCounter);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_EPS2_ZF_sg_oEPS2_ZF_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_TIRE1_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TIRE1_sg_oTIRE1_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_TIRE1_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TIRE1_oTIRE1_Location_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TIRE1_sg_oTIRE1_oJ6L_ADUCAN_Rx)).TIRE1_Location);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TIRE1_oTIRE1_Press_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TIRE1_sg_oTIRE1_oJ6L_ADUCAN_Rx)).TIRE1_Press);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TIRE1_oTIRE1_Temp_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TIRE1_sg_oTIRE1_oJ6L_ADUCAN_Rx)).TIRE1_Temp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TIRE1_oTIRE1_Stat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TIRE1_sg_oTIRE1_oJ6L_ADUCAN_Rx)).TIRE1_Stat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TIRE1_oTIRE1_ExtendTirePressSupport_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TIRE1_sg_oTIRE1_oJ6L_ADUCAN_Rx)).TIRE1_ExtendTirePressSupport);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TIRE1_oTIRE1_AirLeakageRate_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TIRE1_sg_oTIRE1_oJ6L_ADUCAN_Rx)).TIRE1_AirLeakageRate);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TIRE1_oTIRE1_PressThresholdDetect_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TIRE1_sg_oTIRE1_oJ6L_ADUCAN_Rx)).TIRE1_PressThresholdDetect);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TIRE1_sg_oTIRE1_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_TIRE2_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TIRE2_sg_oTIRE2_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_TIRE2_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TIRE2_oTIRE2_Location_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TIRE2_sg_oTIRE2_oJ6L_ADUCAN_Rx)).TIRE2_Location);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TIRE2_oTIRE2_PressExtendRange_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TIRE2_sg_oTIRE2_oJ6L_ADUCAN_Rx)).TIRE2_PressExtendRange);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TIRE2_oTIRE2_ReqTirePress_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TIRE2_sg_oTIRE2_oJ6L_ADUCAN_Rx)).TIRE2_ReqTirePress);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TIRE2_sg_oTIRE2_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_TIRE3_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TIRE3_sg_oTIRE3_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_TIRE3_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TIRE3_oTIRE3_TireLocation_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TIRE3_sg_oTIRE3_oJ6L_ADUCAN_Rx)).TIRE3_TireLocation);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TIRE3_oTIRE3_TireSensorMatchStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TIRE3_sg_oTIRE3_oJ6L_ADUCAN_Rx)).TIRE3_TireSensorMatchStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TIRE3_oTIRE3_TireSensorSelfLearningStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TIRE3_sg_oTIRE3_oJ6L_ADUCAN_Rx)).TIRE3_TireSensorSelfLearningStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TIRE3_oTIRE3_TireSensorElectricalFault_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TIRE3_sg_oTIRE3_oJ6L_ADUCAN_Rx)).TIRE3_TireSensorElectricalFault);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TIRE3_oTIRE3_TireTemThresholdDetection_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TIRE3_sg_oTIRE3_oJ6L_ADUCAN_Rx)).TIRE3_TireTemThresholdDetection);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TIRE3_sg_oTIRE3_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_DM1_TPMS_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_DM1_TPMS_sg_oDM1_TPMS_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_DM1_TPMS_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_TPMS_oDM1_TPMS_ProtectLamp_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_TPMS_sg_oDM1_TPMS_oJ6L_ADUCAN_Rx)).DM1_TPMS_ProtectLamp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_TPMS_oDM1_TPMS_AmberWarningLamp_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_TPMS_sg_oDM1_TPMS_oJ6L_ADUCAN_Rx)).DM1_TPMS_AmberWarningLamp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_TPMS_oDM1_TPMS_RedStopLamp_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_TPMS_sg_oDM1_TPMS_oJ6L_ADUCAN_Rx)).DM1_TPMS_RedStopLamp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_TPMS_oDM1_TPMS_MalfunctionLamp_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_TPMS_sg_oDM1_TPMS_oJ6L_ADUCAN_Rx)).DM1_TPMS_MalfunctionLamp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_TPMS_oDM1_TPMS_SAELamp_Reserved_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_TPMS_sg_oDM1_TPMS_oJ6L_ADUCAN_Rx)).DM1_TPMS_SAELamp_Reserved);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_TPMS_oDM1_TPMS_SPN_LeastSignificantBit_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_TPMS_sg_oDM1_TPMS_oJ6L_ADUCAN_Rx)).DM1_TPMS_SPN_LeastSignificantBit);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_TPMS_oDM1_TPMS_SPN_secondByteOfSPN_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_TPMS_sg_oDM1_TPMS_oJ6L_ADUCAN_Rx)).DM1_TPMS_SPN_secondByteOfSPN);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_TPMS_oDM1_TPMS_FMI_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_TPMS_sg_oDM1_TPMS_oJ6L_ADUCAN_Rx)).DM1_TPMS_FMI);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_TPMS_oDM1_TPMS_SPN3MmostSignificantBit_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_TPMS_sg_oDM1_TPMS_oJ6L_ADUCAN_Rx)).DM1_TPMS_SPN3MmostSignificantBit);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_TPMS_oDM1_TPMS_OccurrenceCount_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_TPMS_sg_oDM1_TPMS_oJ6L_ADUCAN_Rx)).DM1_TPMS_OccurrenceCount);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_TPMS_oDM1_TPMS_SPNConversionMethod_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_TPMS_sg_oDM1_TPMS_oJ6L_ADUCAN_Rx)).DM1_TPMS_SPNConversionMethod);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_DM1_TPMS_sg_oDM1_TPMS_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_EEC2_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_EEC2_sg_oEEC2_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_EEC2_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EEC2_oEEC2_AccelPedal1LowIdleSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EEC2_sg_oEEC2_oJ6L_ADUCAN_Rx)).EEC2_AccelPedal1LowIdleSwitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EEC2_oEEC2_AccelPedalKickdownSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EEC2_sg_oEEC2_oJ6L_ADUCAN_Rx)).EEC2_AccelPedalKickdownSwitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EEC2_oEEC2_AccelPedalPstn_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EEC2_sg_oEEC2_oJ6L_ADUCAN_Rx)).EEC2_AccelPedalPstn);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EEC2_oEEC2_PercentLoadAtCurrentSpd_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EEC2_sg_oEEC2_oJ6L_ADUCAN_Rx)).EEC2_PercentLoadAtCurrentSpd);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_EEC2_sg_oEEC2_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_ComProxy_J6L_ADUCAN_TxSignal_SG_TSC1_ACCE_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TSC1_ACCE_sg_oTSC1_ACCE_oJ6L_ADUCAN_Tx);
  ret |= Com_SendSignal(ComConf_ComSignal_TSC1_ACCE_oTSC1_ACCE_EngOvrrdCtrlMode_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_TSC1_ACCE_sg_oTSC1_ACCE_oJ6L_ADUCAN_Tx)).TSC1_ACCE_EngOvrrdCtrlMode);
  ret |= Com_SendSignal(ComConf_ComSignal_TSC1_ACCE_oTSC1_ACCE_ReqSpdCtrlConditions_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_TSC1_ACCE_sg_oTSC1_ACCE_oJ6L_ADUCAN_Tx)).TSC1_ACCE_ReqSpdCtrlConditions);
  ret |= Com_SendSignal(ComConf_ComSignal_TSC1_ACCE_oTSC1_ACCE_OvrrdCtrlModePriority_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_TSC1_ACCE_sg_oTSC1_ACCE_oJ6L_ADUCAN_Tx)).TSC1_ACCE_OvrrdCtrlModePriority);
  ret |= Com_SendSignal(ComConf_ComSignal_TSC1_ACCE_oTSC1_ACCE_EngReqTrqOrTrqLim_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_TSC1_ACCE_sg_oTSC1_ACCE_oJ6L_ADUCAN_Tx)).TSC1_ACCE_EngReqTrqOrTrqLim);
  ret |= Com_SendSignal(ComConf_ComSignal_TSC1_ACCE_oTSC1_ACCE_TransRate_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_TSC1_ACCE_sg_oTSC1_ACCE_oJ6L_ADUCAN_Tx)).TSC1_ACCE_TransRate);
  ret |= Com_SendSignal(ComConf_ComSignal_TSC1_ACCE_oTSC1_ACCE_CtrlPurpose_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_TSC1_ACCE_sg_oTSC1_ACCE_oJ6L_ADUCAN_Tx)).TSC1_ACCE_CtrlPurpose);
  ret |= Com_SendSignal(ComConf_ComSignal_TSC1_ACCE_oTSC1_ACCE_EngReqTrqHR_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_TSC1_ACCE_sg_oTSC1_ACCE_oJ6L_ADUCAN_Tx)).TSC1_ACCE_EngReqTrqHR);
  ret |= Com_SendSignal(ComConf_ComSignal_TSC1_ACCE_oTSC1_ACCE_MessageCounter_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_TSC1_ACCE_sg_oTSC1_ACCE_oJ6L_ADUCAN_Tx)).TSC1_ACCE_MessageCounter);
  ret |= Com_SendSignal(ComConf_ComSignal_TSC1_ACCE_oTSC1_ACCE_MessageChecksum_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_TSC1_ACCE_sg_oTSC1_ACCE_oJ6L_ADUCAN_Tx)).TSC1_ACCE_MessageChecksum);
  (void)Com_SendSignalGroup(ComConf_ComGroupSignal_TSC1_ACCE_oJ6L_ADUCAN_TX);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TSC1_ACCE_sg_oTSC1_ACCE_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_ComProxy_J6L_ADUCAN_TxSignal_SG_XBR2_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_XBR2_sg_oXBR2_oJ6L_ADUCAN_Tx);
  ret |= Com_SendSignal(ComConf_ComSignal_XBR2_oXBR2_ExtAccelDemand_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_XBR2_sg_oXBR2_oJ6L_ADUCAN_Tx)).XBR2_ExtAccelDemand);
  ret |= Com_SendSignal(ComConf_ComSignal_XBR2_oXBR2_EBIMode_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_XBR2_sg_oXBR2_oJ6L_ADUCAN_Tx)).XBR2_EBIMode);
  ret |= Com_SendSignal(ComConf_ComSignal_XBR2_oXBR2_Priority_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_XBR2_sg_oXBR2_oJ6L_ADUCAN_Tx)).XBR2_Priority);
  ret |= Com_SendSignal(ComConf_ComSignal_XBR2_oXBR2_CtrlMode_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_XBR2_sg_oXBR2_oJ6L_ADUCAN_Tx)).XBR2_CtrlMode);
  ret |= Com_SendSignal(ComConf_ComSignal_XBR2_oXBR2_MessageCounter_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_XBR2_sg_oXBR2_oJ6L_ADUCAN_Tx)).XBR2_MessageCounter);
  ret |= Com_SendSignal(ComConf_ComSignal_XBR2_oXBR2_MessageChecksum_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_XBR2_sg_oXBR2_oJ6L_ADUCAN_Tx)).XBR2_MessageChecksum);
  (void)Com_SendSignalGroup(ComConf_ComGroupSignal_XBR2_oJ6L_ADUCAN_TX);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_XBR2_sg_oXBR2_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_ComProxy_J6L_ADUCAN_TxSignal_SG_TC1_ADU_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TC1_ADU_sg_oTC1_ADU_oJ6L_ADUCAN_Tx);
  ret |= Com_SendSignal(ComConf_ComSignal_TC1_ADU_oTC1_ADU_TransReqGear_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_TC1_ADU_sg_oTC1_ADU_oJ6L_ADUCAN_Tx)).TC1_ADU_TransReqGear);
  (void)Com_SendSignalGroup(ComConf_ComGroupSignal_TC1_ADU_oJ6L_ADUCAN_TX);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TC1_ADU_sg_oTC1_ADU_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_ComProxy_J6L_ADUCAN_TxSignal_SG_EPB2_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_EPB2_sg_oEPB2_oJ6L_ADUCAN_Tx);
  ret |= Com_SendSignal(ComConf_ComSignal_EPB2_oEPB2_ExtPressDemandForEPB_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_EPB2_sg_oEPB2_oJ6L_ADUCAN_Tx)).EPB2_ExtPressDemandForEPB);
  ret |= Com_SendSignal(ComConf_ComSignal_EPB2_oEPB2_ExtInhibitReqForPBRelease_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_EPB2_sg_oEPB2_oJ6L_ADUCAN_Tx)).EPB2_ExtInhibitReqForPBRelease);
  ret |= Com_SendSignal(ComConf_ComSignal_EPB2_oEPB2_ExtInhibitReqForPBApply_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_EPB2_sg_oEPB2_oJ6L_ADUCAN_Tx)).EPB2_ExtInhibitReqForPBApply);
  ret |= Com_SendSignal(ComConf_ComSignal_EPB2_oEPB2_ExtApplyReqForEPB_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_EPB2_sg_oEPB2_oJ6L_ADUCAN_Tx)).EPB2_ExtApplyReqForEPB);
  ret |= Com_SendSignal(ComConf_ComSignal_EPB2_oEPB2_ExtReleaseReqForEPB_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_EPB2_sg_oEPB2_oJ6L_ADUCAN_Tx)).EPB2_ExtReleaseReqForEPB);
  ret |= Com_SendSignal(ComConf_ComSignal_EPB2_oEPB2_AutoDrvState_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_EPB2_sg_oEPB2_oJ6L_ADUCAN_Tx)).EPB2_AutoDrvState);
  ret |= Com_SendSignal(ComConf_ComSignal_EPB2_oEPB2_MessageCounter_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_EPB2_sg_oEPB2_oJ6L_ADUCAN_Tx)).EPB2_MessageCounter);
  ret |= Com_SendSignal(ComConf_ComSignal_EPB2_oEPB2_MessageChecksum_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_EPB2_sg_oEPB2_oJ6L_ADUCAN_Tx)).EPB2_MessageChecksum);
  (void)Com_SendSignalGroup(ComConf_ComGroupSignal_EPB2_oJ6L_ADUCAN_TX);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_EPB2_sg_oEPB2_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_ComProxy_J6L_ADUCAN_TxSignal_SG_ADU1_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_ADU1_sg_oADU1_oJ6L_ADUCAN_Tx);
  ret |= Com_SendSignal(ComConf_ComSignal_ADU1_oADU1_ADUStat_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_ADU1_sg_oADU1_oJ6L_ADUCAN_Tx)).ADU1_ADUStat);
  ret |= Com_SendSignal(ComConf_ComSignal_ADU1_oADU1_ADUTargetSpd_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_ADU1_sg_oADU1_oJ6L_ADUCAN_Tx)).ADU1_ADUTargetSpd);
  ret |= Com_SendSignal(ComConf_ComSignal_ADU1_oADU1_ADUBrakeSwitch_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_ADU1_sg_oADU1_oJ6L_ADUCAN_Tx)).ADU1_ADUBrakeSwitch);
  ret |= Com_SendSignal(ComConf_ComSignal_ADU1_oADU1_ADUTargetAccel_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_ADU1_sg_oADU1_oJ6L_ADUCAN_Tx)).ADU1_ADUTargetAccel);
  (void)Com_SendSignalGroup(ComConf_ComGroupSignal_ADU1_oJ6L_ADUCAN_TX);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_ADU1_sg_oADU1_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_ComProxy_J6L_ADUCAN_TxSignal_SG_ADU_Cmd_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_ADU_Cmd_sg_oADU_Cmd_oJ6L_ADUCAN_Tx);
  ret |= Com_SendSignal(ComConf_ComSignal_ADU_Cmd_oADU_Cmd_FrontWiperSwitchCmd_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_ADU_Cmd_sg_oADU_Cmd_oJ6L_ADUCAN_Tx)).ADU_Cmd_FrontWiperSwitchCmd);
  ret |= Com_SendSignal(ComConf_ComSignal_ADU_Cmd_oADU_Cmd_FrontWasherSwitchCmd_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_ADU_Cmd_sg_oADU_Cmd_oJ6L_ADUCAN_Tx)).ADU_Cmd_FrontWasherSwitchCmd);
  ret |= Com_SendSignal(ComConf_ComSignal_ADU_Cmd_oADU_Cmd_ADUToBCM_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_ADU_Cmd_sg_oADU_Cmd_oJ6L_ADUCAN_Tx)).ADU_Cmd_ADUToBCM);
  ret |= Com_SendSignal(ComConf_ComSignal_ADU_Cmd_oADU_Cmd_DrvDoor1UnlockReq_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_ADU_Cmd_sg_oADU_Cmd_oJ6L_ADUCAN_Tx)).ADU_Cmd_DrvDoor1UnlockReq);
  ret |= Com_SendSignal(ComConf_ComSignal_ADU_Cmd_oADU_Cmd_PassengerDoor2UnlockReq_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_ADU_Cmd_sg_oADU_Cmd_oJ6L_ADUCAN_Tx)).ADU_Cmd_PassengerDoor2UnlockReq);
  ret |= Com_SendSignal(ComConf_ComSignal_ADU_Cmd_oADU_Cmd_BackBrakeLightCmd_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_ADU_Cmd_sg_oADU_Cmd_oJ6L_ADUCAN_Tx)).ADU_Cmd_BackBrakeLightCmd);
  ret |= Com_SendSignal(ComConf_ComSignal_ADU_Cmd_oADU_Cmd_HornCmd_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_ADU_Cmd_sg_oADU_Cmd_oJ6L_ADUCAN_Tx)).ADU_Cmd_HornCmd);
  (void)Com_SendSignalGroup(ComConf_ComGroupSignal_ADU_Cmd_oJ6L_ADUCAN_TX);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_ADU_Cmd_sg_oADU_Cmd_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_VCU_Status_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_VCU_Status_sg_oVCU_Status_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_VCU_Status_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_VCU_Status_oVCU_Status_VCUMode_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_VCU_Status_sg_oVCU_Status_oJ6L_ADUCAN_Rx)).VCU_Status_VCUMode);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_VCU_Status_oVCU_Status_ManualBrakeSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_VCU_Status_sg_oVCU_Status_oJ6L_ADUCAN_Rx)).VCU_Status_ManualBrakeSwitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_VCU_Status_oVCU_Status_ManualAccelPedalPstn_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_VCU_Status_sg_oVCU_Status_oJ6L_ADUCAN_Rx)).VCU_Status_ManualAccelPedalPstn);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_VCU_Status_oVCU_Status_VCUAutoToManualTips_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_VCU_Status_sg_oVCU_Status_oJ6L_ADUCAN_Rx)).VCU_Status_VCUAutoToManualTips);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_VCU_Status_oVCU_Status_ActualMaxDrivePctTrq_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_VCU_Status_sg_oVCU_Status_oJ6L_ADUCAN_Rx)).VCU_Status_ActualMaxDrivePctTrq);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_VCU_Status_sg_oVCU_Status_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_OWW_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_OWW_sg_oOWW_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_OWW_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_OWW_oOWW_FrontOperatorWiperSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_OWW_sg_oOWW_oJ6L_ADUCAN_Rx)).OWW_FrontOperatorWiperSwitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_OWW_oOWW_FrontOperatorWasherSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_OWW_sg_oOWW_oJ6L_ADUCAN_Rx)).OWW_FrontOperatorWasherSwitch);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_OWW_sg_oOWW_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_SC_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_SC_sg_oSC_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_SC_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_SC_oSC_IGOffPostnLightAlert_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_SC_sg_oSC_oJ6L_ADUCAN_Rx)).SC_IGOffPostnLightAlert);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_SC_oSC_LDWSwitchStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_SC_sg_oSC_oJ6L_ADUCAN_Rx)).SC_LDWSwitchStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_SC_oSC_FCWSwitchStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_SC_sg_oSC_oJ6L_ADUCAN_Rx)).SC_FCWSwitchStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_SC_oSC_ReverseGearSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_SC_sg_oSC_oJ6L_ADUCAN_Rx)).SC_ReverseGearSwitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_SC_oSC_RearWorkLampSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_SC_sg_oSC_oJ6L_ADUCAN_Rx)).SC_RearWorkLampSwitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_SC_oSC_SleepAreaLightSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_SC_sg_oSC_oJ6L_ADUCAN_Rx)).SC_SleepAreaLightSwitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_SC_oSC_IndoorLightSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_SC_sg_oSC_oJ6L_ADUCAN_Rx)).SC_IndoorLightSwitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_SC_oSC_HornSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_SC_sg_oSC_oJ6L_ADUCAN_Rx)).SC_HornSwitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_SC_oSC_HornSelectionSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_SC_sg_oSC_oJ6L_ADUCAN_Rx)).SC_HornSelectionSwitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_SC_oSC_CabDoorWarnOFFSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_SC_sg_oSC_oJ6L_ADUCAN_Rx)).SC_CabDoorWarnOFFSwitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_SC_oSC_AutoLightCtrlSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_SC_sg_oSC_oJ6L_ADUCAN_Rx)).SC_AutoLightCtrlSwitch);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_SC_sg_oSC_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_BCU_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_BCU_sg_oBCU_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_BCU_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_BCU_oBCU_IgnitionPstn_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_BCU_sg_oBCU_oJ6L_ADUCAN_Rx)).BCU_IgnitionPstn);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_BCU_oBCU_DriverSeatBeltAlert_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_BCU_sg_oBCU_oJ6L_ADUCAN_Rx)).BCU_DriverSeatBeltAlert);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_BCU_oBCU_PassengerSeatBeltAlert_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_BCU_sg_oBCU_oJ6L_ADUCAN_Rx)).BCU_PassengerSeatBeltAlert);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_BCU_sg_oBCU_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_HCU_BMS_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_HCU_BMS_sg_oHCU_BMS_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_HCU_BMS_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_HCU_BMS_oHCU_BMS_HCUSysStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_HCU_BMS_sg_oHCU_BMS_oJ6L_ADUCAN_Rx)).HCU_BMS_HCUSysStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_HCU_BMS_oHCU_BMS_ReadyToDriveStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_HCU_BMS_sg_oHCU_BMS_oJ6L_ADUCAN_Rx)).HCU_BMS_ReadyToDriveStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_HCU_BMS_oHCU_BMS_PermitCharge_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_HCU_BMS_sg_oHCU_BMS_oJ6L_ADUCAN_Rx)).HCU_BMS_PermitCharge);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_HCU_BMS_oHCU_BMS_EnduranceMileage_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_HCU_BMS_sg_oHCU_BMS_oJ6L_ADUCAN_Rx)).HCU_BMS_EnduranceMileage);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_HCU_BMS_oHCU_BMS_SleepCmd_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_HCU_BMS_sg_oHCU_BMS_oJ6L_ADUCAN_Rx)).HCU_BMS_SleepCmd);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_HCU_BMS_oHCU_BMS_HighVoltSysFailStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_HCU_BMS_sg_oHCU_BMS_oJ6L_ADUCAN_Rx)).HCU_BMS_HighVoltSysFailStat);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_HCU_BMS_sg_oHCU_BMS_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_BMS1_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_BMS1_sg_oBMS1_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_BMS1_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_BMS1_oBMS1_PowerBattVolt_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_BMS1_sg_oBMS1_oJ6L_ADUCAN_Rx)).BMS1_PowerBattVolt);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_BMS1_oBMS1_PowerBattCurrent_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_BMS1_sg_oBMS1_oJ6L_ADUCAN_Rx)).BMS1_PowerBattCurrent);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_BMS1_oBMS1_PowerBattSOC_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_BMS1_sg_oBMS1_oJ6L_ADUCAN_Rx)).BMS1_PowerBattSOC);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_BMS1_oBMS1_PowerBattSysStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_BMS1_sg_oBMS1_oJ6L_ADUCAN_Rx)).BMS1_PowerBattSysStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_BMS1_oBMS1_PowerBattChargeReq_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_BMS1_sg_oBMS1_oJ6L_ADUCAN_Rx)).BMS1_PowerBattChargeReq);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_BMS1_oBMS1_PowerBattChargeStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_BMS1_sg_oBMS1_oJ6L_ADUCAN_Rx)).BMS1_PowerBattChargeStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_BMS1_oBMS1_PowerBattHeatStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_BMS1_sg_oBMS1_oJ6L_ADUCAN_Rx)).BMS1_PowerBattHeatStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_BMS1_oBMS1_MsgCounter_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_BMS1_sg_oBMS1_oJ6L_ADUCAN_Rx)).BMS1_MsgCounter);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_BMS1_oBMS1_MsgChecksum_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_BMS1_sg_oBMS1_oJ6L_ADUCAN_Rx)).BMS1_MsgChecksum);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_BMS1_sg_oBMS1_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_BMS5_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_BMS5_sg_oBMS5_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_BMS5_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_BMS5_oBMS5_BMSMainNgtvCoilDrvStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_BMS5_sg_oBMS5_oJ6L_ADUCAN_Rx)).BMS5_BMSMainNgtvCoilDrvStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_BMS5_oBMS5_PowerBattSOH_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_BMS5_sg_oBMS5_oJ6L_ADUCAN_Rx)).BMS5_PowerBattSOH);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_BMS5_oBMS5_MainNgtvRelayDisconnectReq_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_BMS5_sg_oBMS5_oJ6L_ADUCAN_Rx)).BMS5_MainNgtvRelayDisconnectReq);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_BMS5_oBMS5_MainNgtvRelayStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_BMS5_sg_oBMS5_oJ6L_ADUCAN_Rx)).BMS5_MainNgtvRelayStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_BMS5_oBMS5_BattPackHeatCtrlCmdPstv_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_BMS5_sg_oBMS5_oJ6L_ADUCAN_Rx)).BMS5_BattPackHeatCtrlCmdPstv);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_BMS5_oBMS5_BattPackHeatCtrlCmdNgtv_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_BMS5_sg_oBMS5_oJ6L_ADUCAN_Rx)).BMS5_BattPackHeatCtrlCmdNgtv);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_BMS5_oBMS5_ChargePlugConnectionStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_BMS5_sg_oBMS5_oJ6L_ADUCAN_Rx)).BMS5_ChargePlugConnectionStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_BMS5_oBMS5_ChargePlug2ConnectionStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_BMS5_sg_oBMS5_oJ6L_ADUCAN_Rx)).BMS5_ChargePlug2ConnectionStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_BMS5_oBMS5_ChargeRelayStatPstv_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_BMS5_sg_oBMS5_oJ6L_ADUCAN_Rx)).BMS5_ChargeRelayStatPstv);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_BMS5_oBMS5_ChargeRelayStatNgtv_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_BMS5_sg_oBMS5_oJ6L_ADUCAN_Rx)).BMS5_ChargeRelayStatNgtv);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_BMS5_sg_oBMS5_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_VD_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_VD_sg_oVD_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_VD_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_VD_oVD_TripDistance_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_VD_sg_oVD_oJ6L_ADUCAN_Rx)).VD_TripDistance);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_VD_oVD_TotalVehDistance_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_VD_sg_oVD_oJ6L_ADUCAN_Rx)).VD_TotalVehDistance);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_VD_sg_oVD_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_DM1_BCM_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_DM1_BCM_sg_oDM1_BCM_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_DM1_BCM_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_BCM_oDM1_BCM_AmberWarningLamp_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_BCM_sg_oDM1_BCM_oJ6L_ADUCAN_Rx)).DM1_BCM_AmberWarningLamp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_BCM_oDM1_BCM_RedStopLamp_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_BCM_sg_oDM1_BCM_oJ6L_ADUCAN_Rx)).DM1_BCM_RedStopLamp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_BCM_oDM1_BCM_SAELamp_Reserved_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_BCM_sg_oDM1_BCM_oJ6L_ADUCAN_Rx)).DM1_BCM_SAELamp_Reserved);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_BCM_oDM1_BCM_SPN8_LeastSignificantBit_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_BCM_sg_oDM1_BCM_oJ6L_ADUCAN_Rx)).DM1_BCM_SPN8_LeastSignificantBit);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_BCM_oDM1_BCM_SPN_secondByteOfSPN_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_BCM_sg_oDM1_BCM_oJ6L_ADUCAN_Rx)).DM1_BCM_SPN_secondByteOfSPN);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_BCM_oDM1_BCM_FMI_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_BCM_sg_oDM1_BCM_oJ6L_ADUCAN_Rx)).DM1_BCM_FMI);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_BCM_oDM1_BCM_SPN3MmostSignificantBit_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_BCM_sg_oDM1_BCM_oJ6L_ADUCAN_Rx)).DM1_BCM_SPN3MmostSignificantBit);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_BCM_oDM1_BCM_OccurrenceCount_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_BCM_sg_oDM1_BCM_oJ6L_ADUCAN_Rx)).DM1_BCM_OccurrenceCount);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_BCM_oDM1_BCM_SPNConversionMethod_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_BCM_sg_oDM1_BCM_oJ6L_ADUCAN_Rx)).DM1_BCM_SPNConversionMethod);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_DM1_BCM_sg_oDM1_BCM_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_ComProxy_J6L_ADUCAN_TxSignal_SG_TSC1_ACCDR_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TSC1_ACCDR_sg_oTSC1_ACCDR_oJ6L_ADUCAN_Tx);
  ret |= Com_SendSignal(ComConf_ComSignal_TSC1_ACCDR_oTSC1_ACCDR_EngOvrrdCtrlMode_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_TSC1_ACCDR_sg_oTSC1_ACCDR_oJ6L_ADUCAN_Tx)).TSC1_ACCDR_EngOvrrdCtrlMode);
  ret |= Com_SendSignal(ComConf_ComSignal_TSC1_ACCDR_oTSC1_ACCDR_ReqSpdCtrlConditions_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_TSC1_ACCDR_sg_oTSC1_ACCDR_oJ6L_ADUCAN_Tx)).TSC1_ACCDR_ReqSpdCtrlConditions);
  ret |= Com_SendSignal(ComConf_ComSignal_TSC1_ACCDR_oTSC1_ACCDR_OvrrdCtrlModePriority_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_TSC1_ACCDR_sg_oTSC1_ACCDR_oJ6L_ADUCAN_Tx)).TSC1_ACCDR_OvrrdCtrlModePriority);
  ret |= Com_SendSignal(ComConf_ComSignal_TSC1_ACCDR_oTSC1_ACCDR_EngReqTrqOrTrqLim_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_TSC1_ACCDR_sg_oTSC1_ACCDR_oJ6L_ADUCAN_Tx)).TSC1_ACCDR_EngReqTrqOrTrqLim);
  ret |= Com_SendSignal(ComConf_ComSignal_TSC1_ACCDR_oTSC1_ACCDR_TransRate_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_TSC1_ACCDR_sg_oTSC1_ACCDR_oJ6L_ADUCAN_Tx)).TSC1_ACCDR_TransRate);
  ret |= Com_SendSignal(ComConf_ComSignal_TSC1_ACCDR_oTSC1_ACCDR_CtrlPurpose_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_TSC1_ACCDR_sg_oTSC1_ACCDR_oJ6L_ADUCAN_Tx)).TSC1_ACCDR_CtrlPurpose);
  ret |= Com_SendSignal(ComConf_ComSignal_TSC1_ACCDR_oTSC1_ACCDR_EngReqTrqHR_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_TSC1_ACCDR_sg_oTSC1_ACCDR_oJ6L_ADUCAN_Tx)).TSC1_ACCDR_EngReqTrqHR);
  ret |= Com_SendSignal(ComConf_ComSignal_TSC1_ACCDR_oTSC1_ACCDR_MessageCounter_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_TSC1_ACCDR_sg_oTSC1_ACCDR_oJ6L_ADUCAN_Tx)).TSC1_ACCDR_MessageCounter);
  ret |= Com_SendSignal(ComConf_ComSignal_TSC1_ACCDR_oTSC1_ACCDR_MessageChecksum_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_TSC1_ACCDR_sg_oTSC1_ACCDR_oJ6L_ADUCAN_Tx)).TSC1_ACCDR_MessageChecksum);
  (void)Com_SendSignalGroup(ComConf_ComGroupSignal_TSC1_ACCDR_oJ6L_ADUCAN_TX);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TSC1_ACCDR_sg_oTSC1_ACCDR_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_EC_EM1_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_EC_EM1_sg_oEC_EM1_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_EC_EM1_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EC_EM1_oEC_EM1_EngSpdAtPoint1_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EC_EM1_sg_oEC_EM1_oJ6L_ADUCAN_Rx)).EC_EM1_EngSpdAtPoint1);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EC_EM1_oEC_EM1_EngReferenceTrq_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EC_EM1_sg_oEC_EM1_oJ6L_ADUCAN_Rx)).EC_EM1_EngReferenceTrq);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EC_EM1_oEC_EM1_SupportVariableRateTSC1_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EC_EM1_sg_oEC_EM1_oJ6L_ADUCAN_Rx)).EC_EM1_SupportVariableRateTSC1);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_EC_EM1_sg_oEC_EM1_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_LD_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_LD_sg_oLD_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_LD_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_LD_oLD_RunLight_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_LD_sg_oLD_oJ6L_ADUCAN_Rx)).LD_RunLight);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_LD_oLD_LowBeamHeadLightData_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_LD_sg_oLD_oJ6L_ADUCAN_Rx)).LD_LowBeamHeadLightData);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_LD_oLD_HighBeamHeadLightData_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_LD_sg_oLD_oJ6L_ADUCAN_Rx)).LD_HighBeamHeadLightData);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_LD_oLD_RightTurnSignalLights_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_LD_sg_oLD_oJ6L_ADUCAN_Rx)).LD_RightTurnSignalLights);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_LD_oLD_LeftTurnSignalLights_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_LD_sg_oLD_oJ6L_ADUCAN_Rx)).LD_LeftTurnSignalLights);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_LD_oLD_FrontFogLights_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_LD_sg_oLD_oJ6L_ADUCAN_Rx)).LD_FrontFogLights);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_LD_oLD_RearFogLights_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_LD_sg_oLD_oJ6L_ADUCAN_Rx)).LD_RearFogLights);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_LD_oLD_BackUpLightAndAlarmHorn_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_LD_sg_oLD_oJ6L_ADUCAN_Rx)).LD_BackUpLightAndAlarmHorn);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_LD_oLD_CenterStopLight_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_LD_sg_oLD_oJ6L_ADUCAN_Rx)).LD_CenterStopLight);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_LD_oLD_ImplementMarkerLightData_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_LD_sg_oLD_oJ6L_ADUCAN_Rx)).LD_ImplementMarkerLightData);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_LD_sg_oLD_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_BCM_Status_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_BCM_Status_sg_oBCM_Status_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_BCM_Status_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_BCM_Status_oBCM_Status_BCMRespStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_BCM_Status_sg_oBCM_Status_oJ6L_ADUCAN_Rx)).BCM_Status_BCMRespStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_BCM_Status_oBCM_Status_BackBrakeLightStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_BCM_Status_sg_oBCM_Status_oJ6L_ADUCAN_Rx)).BCM_Status_BackBrakeLightStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_BCM_Status_oBCM_Status_HornStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_BCM_Status_sg_oBCM_Status_oJ6L_ADUCAN_Rx)).BCM_Status_HornStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_BCM_Status_oBCM_Status_WiperStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_BCM_Status_sg_oBCM_Status_oJ6L_ADUCAN_Rx)).BCM_Status_WiperStat);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_BCM_Status_sg_oBCM_Status_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_DM1_BMS_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_DM1_BMS_sg_oDM1_BMS_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_DM1_BMS_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_BMS_oDM1_BMS_AmberWarningLamp_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_BMS_sg_oDM1_BMS_oJ6L_ADUCAN_Rx)).DM1_BMS_AmberWarningLamp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_BMS_oDM1_BMS_RedStopLamp_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_BMS_sg_oDM1_BMS_oJ6L_ADUCAN_Rx)).DM1_BMS_RedStopLamp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_BMS_oDM1_BMS_SAELamp_Reserved_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_BMS_sg_oDM1_BMS_oJ6L_ADUCAN_Rx)).DM1_BMS_SAELamp_Reserved);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_BMS_oDM1_BMS_SPN8_LeastSignificantBit_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_BMS_sg_oDM1_BMS_oJ6L_ADUCAN_Rx)).DM1_BMS_SPN8_LeastSignificantBit);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_BMS_oDM1_BMS_SPN_secondByteOfSPN_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_BMS_sg_oDM1_BMS_oJ6L_ADUCAN_Rx)).DM1_BMS_SPN_secondByteOfSPN);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_BMS_oDM1_BMS_FMI_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_BMS_sg_oDM1_BMS_oJ6L_ADUCAN_Rx)).DM1_BMS_FMI);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_BMS_oDM1_BMS_SPN3MmostSignificantBit_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_BMS_sg_oDM1_BMS_oJ6L_ADUCAN_Rx)).DM1_BMS_SPN3MmostSignificantBit);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_BMS_oDM1_BMS_OccurrenceCount_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_BMS_sg_oDM1_BMS_oJ6L_ADUCAN_Rx)).DM1_BMS_OccurrenceCount);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_BMS_oDM1_BMS_SPNConversionMethod_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_BMS_sg_oDM1_BMS_oJ6L_ADUCAN_Rx)).DM1_BMS_SPNConversionMethod);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_DM1_BMS_sg_oDM1_BMS_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_DM1_PTU_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_DM1_PTU_sg_oDM1_PTU_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_DM1_PTU_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_PTU_oDM1_PTU_AmberWarningLamp_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_PTU_sg_oDM1_PTU_oJ6L_ADUCAN_Rx)).DM1_PTU_AmberWarningLamp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_PTU_oDM1_PTU_RedStopLamp_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_PTU_sg_oDM1_PTU_oJ6L_ADUCAN_Rx)).DM1_PTU_RedStopLamp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_PTU_oDM1_PTU_SAELamp_Reserved_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_PTU_sg_oDM1_PTU_oJ6L_ADUCAN_Rx)).DM1_PTU_SAELamp_Reserved);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_PTU_oDM1_PTU_SPN8_LeastSignificantBit_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_PTU_sg_oDM1_PTU_oJ6L_ADUCAN_Rx)).DM1_PTU_SPN8_LeastSignificantBit);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_PTU_oDM1_PTU_SPN_secondByteOfSPN_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_PTU_sg_oDM1_PTU_oJ6L_ADUCAN_Rx)).DM1_PTU_SPN_secondByteOfSPN);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_PTU_oDM1_PTU_FMI_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_PTU_sg_oDM1_PTU_oJ6L_ADUCAN_Rx)).DM1_PTU_FMI);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_PTU_oDM1_PTU_SPN3MmostSignificantBit_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_PTU_sg_oDM1_PTU_oJ6L_ADUCAN_Rx)).DM1_PTU_SPN3MmostSignificantBit);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_PTU_oDM1_PTU_OccurrenceCount_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_PTU_sg_oDM1_PTU_oJ6L_ADUCAN_Rx)).DM1_PTU_OccurrenceCount);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_PTU_oDM1_PTU_SPNConversionMethod_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_PTU_sg_oDM1_PTU_oJ6L_ADUCAN_Rx)).DM1_PTU_SPNConversionMethod);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_DM1_PTU_sg_oDM1_PTU_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_DM1_DCDC2_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_DM1_DCDC2_sg_oDM1_DCDC2_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_DM1_DCDC2_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_DCDC2_oDM1_DCDC2_AmberWarningLamp_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_DCDC2_sg_oDM1_DCDC2_oJ6L_ADUCAN_Rx)).DM1_DCDC2_AmberWarningLamp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_DCDC2_oDM1_DCDC2_RedStopLamp_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_DCDC2_sg_oDM1_DCDC2_oJ6L_ADUCAN_Rx)).DM1_DCDC2_RedStopLamp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_DCDC2_oDM1_DCDC2_SAELamp_Reserved_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_DCDC2_sg_oDM1_DCDC2_oJ6L_ADUCAN_Rx)).DM1_DCDC2_SAELamp_Reserved);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_DCDC2_oDM1_DCDC2_SPN_LeastSgnificantBit_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_DCDC2_sg_oDM1_DCDC2_oJ6L_ADUCAN_Rx)).DM1_DCDC2_SPN_LeastSgnificantBit);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_DCDC2_oDM1_DCDC2_SPN_secondByteOfSPN_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_DCDC2_sg_oDM1_DCDC2_oJ6L_ADUCAN_Rx)).DM1_DCDC2_SPN_secondByteOfSPN);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_DCDC2_oDM1_DCDC2_FMI_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_DCDC2_sg_oDM1_DCDC2_oJ6L_ADUCAN_Rx)).DM1_DCDC2_FMI);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_DCDC2_oDM1_DCDC2_SPNMmostSignificantBit_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_DCDC2_sg_oDM1_DCDC2_oJ6L_ADUCAN_Rx)).DM1_DCDC2_SPNMmostSignificantBit);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_DCDC2_oDM1_DCDC2_OccurrenceCount_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_DCDC2_sg_oDM1_DCDC2_oJ6L_ADUCAN_Rx)).DM1_DCDC2_OccurrenceCount);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_DCDC2_oDM1_DCDC2_SPNConversionMethod_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_DCDC2_sg_oDM1_DCDC2_oJ6L_ADUCAN_Rx)).DM1_DCDC2_SPNConversionMethod);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_DM1_DCDC2_sg_oDM1_DCDC2_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_DM1_APCU_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_DM1_APCU_sg_oDM1_APCU_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_DM1_APCU_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_APCU_oDM1_APCU_AmberWarningLamp_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_APCU_sg_oDM1_APCU_oJ6L_ADUCAN_Rx)).DM1_APCU_AmberWarningLamp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_APCU_oDM1_APCU_RedStopLamp_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_APCU_sg_oDM1_APCU_oJ6L_ADUCAN_Rx)).DM1_APCU_RedStopLamp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_APCU_oDM1_APCU_SAELamp_Reserved_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_APCU_sg_oDM1_APCU_oJ6L_ADUCAN_Rx)).DM1_APCU_SAELamp_Reserved);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_APCU_oDM1_APCU_SPN_LeastSignificantBit_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_APCU_sg_oDM1_APCU_oJ6L_ADUCAN_Rx)).DM1_APCU_SPN_LeastSignificantBit);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_APCU_oDM1_APCU_SPN_secondByteOfSPN_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_APCU_sg_oDM1_APCU_oJ6L_ADUCAN_Rx)).DM1_APCU_SPN_secondByteOfSPN);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_APCU_oDM1_APCU_FMI_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_APCU_sg_oDM1_APCU_oJ6L_ADUCAN_Rx)).DM1_APCU_FMI);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_APCU_oDM1_APCU_SPN3MmostSignificantBit_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_APCU_sg_oDM1_APCU_oJ6L_ADUCAN_Rx)).DM1_APCU_SPN3MmostSignificantBit);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_APCU_oDM1_APCU_OccurrenceCount_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_APCU_sg_oDM1_APCU_oJ6L_ADUCAN_Rx)).DM1_APCU_OccurrenceCount);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_DM1_APCU_oDM1_APCU_SPNConversionMethod_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_DM1_APCU_sg_oDM1_APCU_oJ6L_ADUCAN_Rx)).DM1_APCU_SPNConversionMethod);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_DM1_APCU_sg_oDM1_APCU_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_EPSO1_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_EPSO1_sg_oEPSO1_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_EPSO1_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPSO1_oEPSO1_SteerAng_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPSO1_sg_oEPSO1_oJ6L_ADUCAN_Rx)).EPSO1_SteerAng);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPSO1_oEPSO1_SteerAngSpd_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPSO1_sg_oEPSO1_oJ6L_ADUCAN_Rx)).EPSO1_SteerAngSpd);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPSO1_oEPSO1_ElectricalSteerSupRedLv_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPSO1_sg_oEPSO1_oJ6L_ADUCAN_Rx)).EPSO1_ElectricalSteerSupRedLv);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPSO1_oEPSO1_EmergencySteerStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPSO1_sg_oEPSO1_oJ6L_ADUCAN_Rx)).EPSO1_EmergencySteerStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPSO1_oEPSO1_AmberWarnLampStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPSO1_sg_oEPSO1_oJ6L_ADUCAN_Rx)).EPSO1_AmberWarnLampStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPSO1_oEPSO1_RedStopLampState_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPSO1_sg_oEPSO1_oJ6L_ADUCAN_Rx)).EPSO1_RedStopLampState);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPSO1_oEPSO1_SysState_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPSO1_sg_oEPSO1_oJ6L_ADUCAN_Rx)).EPSO1_SysState);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPSO1_oEPSO1_MessageCounter_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPSO1_sg_oEPSO1_oJ6L_ADUCAN_Rx)).EPSO1_MessageCounter);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPSO1_oEPSO1_MessageChecksum_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPSO1_sg_oEPSO1_oJ6L_ADUCAN_Rx)).EPSO1_MessageChecksum);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_EPSO1_sg_oEPSO1_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_EPSO2_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_EPSO2_sg_oEPSO2_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_EPSO2_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPSO2_oEPSO2_DriverTrq_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPSO2_sg_oEPSO2_oJ6L_ADUCAN_Rx)).EPSO2_DriverTrq);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPSO2_oEPSO2_MotorTrq_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPSO2_sg_oEPSO2_oJ6L_ADUCAN_Rx)).EPSO2_MotorTrq);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPSO2_oEPSO2_HandsOffProbability_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPSO2_sg_oEPSO2_oJ6L_ADUCAN_Rx)).EPSO2_HandsOffProbability);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPSO2_oEPSO2_ExtCtrlMode_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPSO2_sg_oEPSO2_oJ6L_ADUCAN_Rx)).EPSO2_ExtCtrlMode);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPSO2_oEPSO2_SteerWheelVibrationMode_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPSO2_sg_oEPSO2_oJ6L_ADUCAN_Rx)).EPSO2_SteerWheelVibrationMode);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPSO2_oEPSO2_MessageCounter_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPSO2_sg_oEPSO2_oJ6L_ADUCAN_Rx)).EPSO2_MessageCounter);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_EPSO2_oEPSO2_MessageChecksum_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_EPSO2_sg_oEPSO2_oJ6L_ADUCAN_Rx)).EPSO2_MessageChecksum);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_EPSO2_sg_oEPSO2_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_ComProxy_J6L_ADUCAN_TxSignal_SG_XBR1_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_XBR1_sg_oXBR1_oJ6L_ADUCAN_Tx);
  ret |= Com_SendSignal(ComConf_ComSignal_XBR1_oXBR1_ExtAccelDemand_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_XBR1_sg_oXBR1_oJ6L_ADUCAN_Tx)).XBR1_ExtAccelDemand);
  ret |= Com_SendSignal(ComConf_ComSignal_XBR1_oXBR1_EBIMode_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_XBR1_sg_oXBR1_oJ6L_ADUCAN_Tx)).XBR1_EBIMode);
  ret |= Com_SendSignal(ComConf_ComSignal_XBR1_oXBR1_Priority_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_XBR1_sg_oXBR1_oJ6L_ADUCAN_Tx)).XBR1_Priority);
  ret |= Com_SendSignal(ComConf_ComSignal_XBR1_oXBR1_CtrlMode_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_XBR1_sg_oXBR1_oJ6L_ADUCAN_Tx)).XBR1_CtrlMode);
  ret |= Com_SendSignal(ComConf_ComSignal_XBR1_oXBR1_MessageCounter_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_XBR1_sg_oXBR1_oJ6L_ADUCAN_Tx)).XBR1_MessageCounter);
  ret |= Com_SendSignal(ComConf_ComSignal_XBR1_oXBR1_MessageChecksum_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_XBR1_sg_oXBR1_oJ6L_ADUCAN_Tx)).XBR1_MessageChecksum);
  (void)Com_SendSignalGroup(ComConf_ComGroupSignal_XBR1_oJ6L_ADUCAN_TX);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_XBR1_sg_oXBR1_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_ComProxy_J6L_ADUCAN_TxSignal_SG_EPSI1_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_EPSI1_sg_oEPSI1_oJ6L_ADUCAN_Tx);
  ret |= Com_SendSignal(ComConf_ComSignal_EPSI1_oEPSI1_MotorTrqReq_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_EPSI1_sg_oEPSI1_oJ6L_ADUCAN_Tx)).EPSI1_MotorTrqReq);
  ret |= Com_SendSignal(ComConf_ComSignal_EPSI1_oEPSI1_SteerAngReq_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_EPSI1_sg_oEPSI1_oJ6L_ADUCAN_Tx)).EPSI1_SteerAngReq);
  ret |= Com_SendSignal(ComConf_ComSignal_EPSI1_oEPSI1_FBFTrqReq_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_EPSI1_sg_oEPSI1_oJ6L_ADUCAN_Tx)).EPSI1_FBFTrqReq);
  ret |= Com_SendSignal(ComConf_ComSignal_EPSI1_oEPSI1_ExtCtrlModeReq_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_EPSI1_sg_oEPSI1_oJ6L_ADUCAN_Tx)).EPSI1_ExtCtrlModeReq);
  ret |= Com_SendSignal(ComConf_ComSignal_EPSI1_oEPSI1_MessageCounter_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_EPSI1_sg_oEPSI1_oJ6L_ADUCAN_Tx)).EPSI1_MessageCounter);
  ret |= Com_SendSignal(ComConf_ComSignal_EPSI1_oEPSI1_MessageChecksum_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_EPSI1_sg_oEPSI1_oJ6L_ADUCAN_Tx)).EPSI1_MessageChecksum);
  (void)Com_SendSignalGroup(ComConf_ComGroupSignal_EPSI1_oJ6L_ADUCAN_TX);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_EPSI1_sg_oEPSI1_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_ComProxy_J6L_ADUCAN_TxSignal_SG_EPSI2_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_EPSI2_sg_oEPSI2_oJ6L_ADUCAN_Tx);
  ret |= Com_SendSignal(ComConf_ComSignal_EPSI2_oEPSI2_ActiveReturnWeightReq_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_EPSI2_sg_oEPSI2_oJ6L_ADUCAN_Tx)).EPSI2_ActiveReturnWeightReq);
  ret |= Com_SendSignal(ComConf_ComSignal_EPSI2_oEPSI2_AngCtrlWeightReq_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_EPSI2_sg_oEPSI2_oJ6L_ADUCAN_Tx)).EPSI2_AngCtrlWeightReq);
  ret |= Com_SendSignal(ComConf_ComSignal_EPSI2_oEPSI2_AngCtrTrqLimReq_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_EPSI2_sg_oEPSI2_oJ6L_ADUCAN_Tx)).EPSI2_AngCtrTrqLimReq);
  ret |= Com_SendSignal(ComConf_ComSignal_EPSI2_oEPSI2_MessageCounter_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_EPSI2_sg_oEPSI2_oJ6L_ADUCAN_Tx)).EPSI2_MessageCounter);
  ret |= Com_SendSignal(ComConf_ComSignal_EPSI2_oEPSI2_MessageChecksum_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_EPSI2_sg_oEPSI2_oJ6L_ADUCAN_Tx)).EPSI2_MessageChecksum);
  (void)Com_SendSignalGroup(ComConf_ComGroupSignal_EPSI2_oJ6L_ADUCAN_TX);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_EPSI2_sg_oEPSI2_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_FBCM_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_FBCM_sg_oFBCM_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_FBCM_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_FBCM_oFBCM_DriverWindowSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_FBCM_sg_oFBCM_oJ6L_ADUCAN_Rx)).FBCM_DriverWindowSwitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_FBCM_oFBCM_DriverCtrlPasgrWindowSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_FBCM_sg_oFBCM_oJ6L_ADUCAN_Rx)).FBCM_DriverCtrlPasgrWindowSwitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_FBCM_oFBCM_PassengerWindowSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_FBCM_sg_oFBCM_oJ6L_ADUCAN_Rx)).FBCM_PassengerWindowSwitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_FBCM_oFBCM_CabDoorsLockSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_FBCM_sg_oFBCM_oJ6L_ADUCAN_Rx)).FBCM_CabDoorsLockSwitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_FBCM_oFBCM_BackMirrorHeatSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_FBCM_sg_oFBCM_oJ6L_ADUCAN_Rx)).FBCM_BackMirrorHeatSwitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_FBCM_oFBCM_BackMirrorSelectSwitch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_FBCM_sg_oFBCM_oJ6L_ADUCAN_Rx)).FBCM_BackMirrorSelectSwitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_FBCM_oFBCM_BackMirrorAdjustSwch_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_FBCM_sg_oFBCM_oJ6L_ADUCAN_Rx)).FBCM_BackMirrorAdjustSwch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_FBCM_oFBCM_VehAntiTheftStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_FBCM_sg_oFBCM_oJ6L_ADUCAN_Rx)).FBCM_VehAntiTheftStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_FBCM_oFBCM_RmtLightInspectCmd_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_FBCM_sg_oFBCM_oJ6L_ADUCAN_Rx)).FBCM_RmtLightInspectCmd);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_FBCM_oFBCM_RmtSearchVehCmd_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_FBCM_sg_oFBCM_oJ6L_ADUCAN_Rx)).FBCM_RmtSearchVehCmd);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_FBCM_oFBCM_LockOrUnlockSuccessAlert_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_FBCM_sg_oFBCM_oJ6L_ADUCAN_Rx)).FBCM_LockOrUnlockSuccessAlert);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_FBCM_oFBCM_RMKeyBattStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_FBCM_sg_oFBCM_oJ6L_ADUCAN_Rx)).FBCM_RMKeyBattStat);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_FBCM_sg_oFBCM_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_PS1_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_PS1_sg_oPS1_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_PS1_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_PS1_oPS1_PowerOffBeforeLeaveVehWarn_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_PS1_sg_oPS1_oJ6L_ADUCAN_Rx)).PS1_PowerOffBeforeLeaveVehWarn);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_PS1_oPS1_NoLegalSmartKeyInsideVehWarn_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_PS1_sg_oPS1_oJ6L_ADUCAN_Rx)).PS1_NoLegalSmartKeyInsideVehWarn);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_PS1_oPS1_NoLegalSmartKeyIDWarn_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_PS1_sg_oPS1_oJ6L_ADUCAN_Rx)).PS1_NoLegalSmartKeyIDWarn);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_PS1_oPS1_SmartStartConditionWarn_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_PS1_sg_oPS1_oJ6L_ADUCAN_Rx)).PS1_SmartStartConditionWarn);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_PS1_oPS1_ESCLNotUnlockWarn_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_PS1_sg_oPS1_oJ6L_ADUCAN_Rx)).PS1_ESCLNotUnlockWarn);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_PS1_oPS1_ESCLNotLockWarn_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_PS1_sg_oPS1_oJ6L_ADUCAN_Rx)).PS1_ESCLNotLockWarn);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_PS1_oPS1_SmartKeyBattStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_PS1_sg_oPS1_oJ6L_ADUCAN_Rx)).PS1_SmartKeyBattStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_PS1_oPS1_PowerMainSwchNotClosed_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_PS1_sg_oPS1_oJ6L_ADUCAN_Rx)).PS1_PowerMainSwchNotClosed);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_PS1_oPS1_RmtLightInspectionCmd_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_PS1_sg_oPS1_oJ6L_ADUCAN_Rx)).PS1_RmtLightInspectionCmd);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_PS1_oPS1_RmtSearchVehCmd_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_PS1_sg_oPS1_oJ6L_ADUCAN_Rx)).PS1_RmtSearchVehCmd);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_PS1_oPS1_IgnitionPstn_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_PS1_sg_oPS1_oJ6L_ADUCAN_Rx)).PS1_IgnitionPstn);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_PS1_oPS1_EngRmtStartAndStopStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_PS1_sg_oPS1_oJ6L_ADUCAN_Rx)).PS1_EngRmtStartAndStopStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_PS1_oPS1_IgnitionRmtCtrlStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_PS1_sg_oPS1_oJ6L_ADUCAN_Rx)).PS1_IgnitionRmtCtrlStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_PS1_oPS1_RmtLockOrUnlockStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_PS1_sg_oPS1_oJ6L_ADUCAN_Rx)).PS1_RmtLockOrUnlockStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_PS1_oPS1_RmtSearchVehStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_PS1_sg_oPS1_oJ6L_ADUCAN_Rx)).PS1_RmtSearchVehStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_PS1_oPS1_VehRmtCtrlMode_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_PS1_sg_oPS1_oJ6L_ADUCAN_Rx)).PS1_VehRmtCtrlMode);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_PS1_oPS1_TurnLightCtrlCmd_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_PS1_sg_oPS1_oJ6L_ADUCAN_Rx)).PS1_TurnLightCtrlCmd);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_PS1_sg_oPS1_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_ComProxy_J6L_ADUCAN_TxSignal_SG_ENGSC_FM_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_ENGSC_FM_sg_oENGSC_FM_oJ6L_ADUCAN_Tx);
  ret |= Com_SendSignal(ComConf_ComSignal_ENGSC_FM_oENGSC_FM_EngStartReq_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_ENGSC_FM_sg_oENGSC_FM_oJ6L_ADUCAN_Tx)).ENGSC_FM_EngStartReq);
  ret |= Com_SendSignal(ComConf_ComSignal_ENGSC_FM_oENGSC_FM_EngStartAbortReq_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_ENGSC_FM_sg_oENGSC_FM_oJ6L_ADUCAN_Tx)).ENGSC_FM_EngStartAbortReq);
  ret |= Com_SendSignal(ComConf_ComSignal_ENGSC_FM_oENGSC_FM_MsgCounter_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_ENGSC_FM_sg_oENGSC_FM_oJ6L_ADUCAN_Tx)).ENGSC_FM_MsgCounter);
  ret |= Com_SendSignal(ComConf_ComSignal_ENGSC_FM_oENGSC_FM_MsgChecksum_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_ENGSC_FM_sg_oENGSC_FM_oJ6L_ADUCAN_Tx)).ENGSC_FM_MsgChecksum);
  (void)Com_SendSignalGroup(ComConf_ComGroupSignal_ENGSC_FM_oJ6L_ADUCAN_TX);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_ENGSC_FM_sg_oENGSC_FM_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_ComProxy_J6L_ADUCAN_TxSignal_SG_ATR_FM_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_ATR_FM_sg_oATR_FM_oJ6L_ADUCAN_Tx);
  ret |= Com_SendSignal(ComConf_ComSignal_ATR_FM_oATR_FM_AntiTheftEncryIndicatStat_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_ATR_FM_sg_oATR_FM_oJ6L_ADUCAN_Tx)).ATR_FM_AntiTheftEncryIndicatStat);
  ret |= Com_SendSignal(ComConf_ComSignal_ATR_FM_oATR_FM_AntiTheftDesireExitMode_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_ATR_FM_sg_oATR_FM_oJ6L_ADUCAN_Tx)).ATR_FM_AntiTheftDesireExitMode);
  ret |= Com_SendSignal(ComConf_ComSignal_ATR_FM_oATR_FM_AntiTheftCmdStat_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_ATR_FM_sg_oATR_FM_oJ6L_ADUCAN_Tx)).ATR_FM_AntiTheftCmdStat);
  ret |= Com_SendSignal(ComConf_ComSignal_ATR_FM_oATR_FM_AntiTheftPassword_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_ATR_FM_sg_oATR_FM_oJ6L_ADUCAN_Tx)).ATR_FM_AntiTheftPassword);
  (void)Com_SendSignalGroup(ComConf_ComGroupSignal_ATR_FM_oJ6L_ADUCAN_TX);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_ATR_FM_sg_oATR_FM_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_ATS_PS_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_ATS_PS_sg_oATS_PS_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_ATS_PS_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_ATS_PS_oATS_PS_AntiTheftEncrySeedIndicat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_ATS_PS_sg_oATS_PS_oJ6L_ADUCAN_Rx)).ATS_PS_AntiTheftEncrySeedIndicat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_ATS_PS_oATS_PS_AntiTheftPasswordValid_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_ATS_PS_sg_oATS_PS_oJ6L_ADUCAN_Rx)).ATS_PS_AntiTheftPasswordValid);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_ATS_PS_oATS_PS_AntiTheftComponentStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_ATS_PS_sg_oATS_PS_oJ6L_ADUCAN_Rx)).ATS_PS_AntiTheftComponentStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_ATS_PS_oATS_PS_AntiTheftModifyPassword_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_ATS_PS_sg_oATS_PS_oJ6L_ADUCAN_Rx)).ATS_PS_AntiTheftModifyPassword);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_ATS_PS_oATS_PS_AntiTheftRandomNumber_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_ATS_PS_sg_oATS_PS_oJ6L_ADUCAN_Rx)).ATS_PS_AntiTheftRandomNumber);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_ATS_PS_sg_oATS_PS_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_ComProxy_J6L_ADUCAN_TxSignal_SG_Lcks_Cmd1_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_Lcks_Cmd1_sg_oLcks_Cmd1_oJ6L_ADUCAN_Tx);
  ret |= Com_SendSignal(ComConf_ComSignal_Lcks_Cmd1_oLcks_Cmd1_DesiredOperateMode_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_Lcks_Cmd1_sg_oLcks_Cmd1_oJ6L_ADUCAN_Tx)).Lcks_Cmd1_DesiredOperateMode);
  ret |= Com_SendSignal(ComConf_ComSignal_Lcks_Cmd1_oLcks_Cmd1_CmdFromExtController_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_Lcks_Cmd1_sg_oLcks_Cmd1_oJ6L_ADUCAN_Tx)).Lcks_Cmd1_CmdFromExtController);
  ret |= Com_SendSignal(ComConf_ComSignal_Lcks_Cmd1_oLcks_Cmd1_MessageCounter_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_Lcks_Cmd1_sg_oLcks_Cmd1_oJ6L_ADUCAN_Tx)).Lcks_Cmd1_MessageCounter);
  ret |= Com_SendSignal(ComConf_ComSignal_Lcks_Cmd1_oLcks_Cmd1_MessageChecksum_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_Lcks_Cmd1_sg_oLcks_Cmd1_oJ6L_ADUCAN_Tx)).Lcks_Cmd1_MessageChecksum);
  (void)Com_SendSignalGroup(ComConf_ComGroupSignal_Lcks_Cmd1_oJ6L_ADUCAN_TX);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_Lcks_Cmd1_sg_oLcks_Cmd1_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_TPCM_EPB_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPCM_EPB_sg_oTPCM_EPB_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_TPCM_EPB_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TPCM_EPB_oTPCM_EPB_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TPCM_EPB_sg_oTPCM_EPB_oJ6L_ADUCAN_Rx)).TPCM_EPB);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPCM_EPB_sg_oTPCM_EPB_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_TPDT_EPB_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPDT_EPB_sg_oTPDT_EPB_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_TPDT_EPB_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TPDT_EPB_oTPDT_EPB_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TPDT_EPB_sg_oTPDT_EPB_oJ6L_ADUCAN_Rx)).TPDT_EPB);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPDT_EPB_sg_oTPDT_EPB_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_TPCM_EBS_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPCM_EBS_sg_oTPCM_EBS_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_TPCM_EBS_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TPCM_EBS_oTPCM_EBS_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TPCM_EBS_sg_oTPCM_EBS_oJ6L_ADUCAN_Rx)).TPCM_EBS);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPCM_EBS_sg_oTPCM_EBS_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_TPDT_EBS_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPDT_EBS_sg_oTPDT_EBS_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_TPDT_EBS_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TPDT_EBS_oTPDT_EBS_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TPDT_EBS_sg_oTPDT_EBS_oJ6L_ADUCAN_Rx)).TPDT_EBS);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPDT_EBS_sg_oTPDT_EBS_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_TPCM_EPS_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPCM_EPS_sg_oTPCM_EPS_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_TPCM_EPS_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TPCM_EPS_oTPCM_EPS_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TPCM_EPS_sg_oTPCM_EPS_oJ6L_ADUCAN_Rx)).TPCM_EPS);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPCM_EPS_sg_oTPCM_EPS_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_TPDT_EPS_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPDT_EPS_sg_oTPDT_EPS_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_TPDT_EPS_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TPDT_EPS_oTPDT_EPS_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TPDT_EPS_sg_oTPDT_EPS_oJ6L_ADUCAN_Rx)).TPDT_EPS);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPDT_EPS_sg_oTPDT_EPS_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_TPCM_BCM_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPCM_BCM_sg_oTPCM_BCM_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_TPCM_BCM_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TPCM_BCM_oTPCM_BCM_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TPCM_BCM_sg_oTPCM_BCM_oJ6L_ADUCAN_Rx)).TPCM_BCM);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPCM_BCM_sg_oTPCM_BCM_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_TPDT_BCM_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPDT_BCM_sg_oTPDT_BCM_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_TPDT_BCM_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TPDT_BCM_oTPDT_BCM_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TPDT_BCM_sg_oTPDT_BCM_oJ6L_ADUCAN_Rx)).TPDT_BCM);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPDT_BCM_sg_oTPDT_BCM_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_TPCM_TPMS_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPCM_TPMS_sg_oTPCM_TPMS_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_TPCM_TPMS_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TPCM_TPMS_oTPCM_TPMS_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TPCM_TPMS_sg_oTPCM_TPMS_oJ6L_ADUCAN_Rx)).TPCM_TPMS);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPCM_TPMS_sg_oTPCM_TPMS_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_TPDT_TPMS_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPDT_TPMS_sg_oTPDT_TPMS_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_TPDT_TPMS_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TPDT_TPMS_oTPDT_TPMS_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TPDT_TPMS_sg_oTPDT_TPMS_oJ6L_ADUCAN_Rx)).TPDT_TPMS);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPDT_TPMS_sg_oTPDT_TPMS_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_TPCM_BMS_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPCM_BMS_sg_oTPCM_BMS_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_TPCM_BMS_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TPCM_BMS_oTPCM_BMS_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TPCM_BMS_sg_oTPCM_BMS_oJ6L_ADUCAN_Rx)).TPCM_BMS);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPCM_BMS_sg_oTPCM_BMS_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_TPDT_BMS_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPDT_BMS_sg_oTPDT_BMS_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_TPDT_BMS_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TPDT_BMS_oTPDT_BMS_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TPDT_BMS_sg_oTPDT_BMS_oJ6L_ADUCAN_Rx)).TPDT_BMS);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPDT_BMS_sg_oTPDT_BMS_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_TPCM_VCU_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPCM_VCU_sg_oTPCM_VCU_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_TPCM_VCU_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TPCM_VCU_oTPCM_VCU_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TPCM_VCU_sg_oTPCM_VCU_oJ6L_ADUCAN_Rx)).TPCM_VCU);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPCM_VCU_sg_oTPCM_VCU_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_TPDT_VCU_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPDT_VCU_sg_oTPDT_VCU_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_TPDT_VCU_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TPDT_VCU_oTPDT_VCU_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TPDT_VCU_sg_oTPDT_VCU_oJ6L_ADUCAN_Rx)).TPDT_VCU);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPDT_VCU_sg_oTPDT_VCU_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_TPCM_PTU_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPCM_PTU_sg_oTPCM_PTU_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_TPCM_PTU_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TPCM_PTU_oTPCM_PTU_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TPCM_PTU_sg_oTPCM_PTU_oJ6L_ADUCAN_Rx)).TPCM_PTU);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPCM_PTU_sg_oTPCM_PTU_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_TPDT_PTU_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPDT_PTU_sg_oTPDT_PTU_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_TPDT_PTU_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TPDT_PTU_oTPDT_PTU_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TPDT_PTU_sg_oTPDT_PTU_oJ6L_ADUCAN_Rx)).TPDT_PTU);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPDT_PTU_sg_oTPDT_PTU_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_TPCM_DCDC2_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPCM_DCDC2_sg_oTPCM_DCDC2_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_TPCM_DCDC2_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TPCM_DCDC2_oTPCM_DCDC2_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TPCM_DCDC2_sg_oTPCM_DCDC2_oJ6L_ADUCAN_Rx)).TPCM_DCDC2);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPCM_DCDC2_sg_oTPCM_DCDC2_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_TPDT_DCDC2_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPDT_DCDC2_sg_oTPDT_DCDC2_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_TPDT_DCDC2_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TPDT_DCDC2_oTPDT_DCDC2_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TPDT_DCDC2_sg_oTPDT_DCDC2_oJ6L_ADUCAN_Rx)).TPDT_DCDC2);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPDT_DCDC2_sg_oTPDT_DCDC2_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_TPCM_APCU_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPCM_APCU_sg_oTPCM_APCU_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_TPCM_APCU_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TPCM_APCU_oTPCM_APCU_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TPCM_APCU_sg_oTPCM_APCU_oJ6L_ADUCAN_Rx)).TPCM_APCU);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPCM_APCU_sg_oTPCM_APCU_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_TPDT_APCU_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_TPDT_APCU_sg_oTPDT_APCU_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_TPDT_APCU_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_TPDT_APCU_oTPDT_APCU_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_TPDT_APCU_sg_oTPDT_APCU_oJ6L_ADUCAN_Rx)).TPDT_APCU);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_TPDT_APCU_sg_oTPDT_APCU_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_HRW_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_HRW_sg_oHRW_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_HRW_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_HRW_oHRW_FrontAxleLeftWheelSpd_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_HRW_sg_oHRW_oJ6L_ADUCAN_Rx)).HRW_FrontAxleLeftWheelSpd);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_HRW_oHRW_FrontAxleRightWheelSpd_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_HRW_sg_oHRW_oJ6L_ADUCAN_Rx)).HRW_FrontAxleRightWheelSpd);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_HRW_oHRW_RearAxleLeftWheelSpd_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_HRW_sg_oHRW_oJ6L_ADUCAN_Rx)).HRW_RearAxleLeftWheelSpd);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_HRW_oHRW_RearAxleRightWheelSpd_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_HRW_sg_oHRW_oJ6L_ADUCAN_Rx)).HRW_RearAxleRightWheelSpd);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_HRW_sg_oHRW_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_ComProxy_J6L_ADUCAN_TxSignal_SG_ADUSt_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_ADUSt_sg_oADUSt_oJ6L_ADUCAN_Tx);
  ret |= Com_SendSignal(ComConf_ComSignal_ADUSt_oADUSt_ADCtrlStat_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_ADUSt_sg_oADUSt_oJ6L_ADUCAN_Tx)).ADUSt_ADCtrlStat);
  ret |= Com_SendSignal(ComConf_ComSignal_ADUSt_oADUSt_EBStat_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_ADUSt_sg_oADUSt_oJ6L_ADUCAN_Tx)).ADUSt_EBStat);
  ret |= Com_SendSignal(ComConf_ComSignal_ADUSt_oADUSt_EBSrc_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_ADUSt_sg_oADUSt_oJ6L_ADUCAN_Tx)).ADUSt_EBSrc);
  ret |= Com_SendSignal(ComConf_ComSignal_ADUSt_oADUSt_ADCtrlReq_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_ADUSt_sg_oADUSt_oJ6L_ADUCAN_Tx)).ADUSt_ADCtrlReq);
  ret |= Com_SendSignal(ComConf_ComSignal_ADUSt_oADUSt_LiveCounter_o_J6L_ADUCAN_Tx,&(*(&Rte_SG_ADUSt_sg_oADUSt_oJ6L_ADUCAN_Tx)).ADUSt_LiveCounter);
  (void)Com_SendSignalGroup(ComConf_ComGroupSignal_ADUSt_oJ6L_ADUCAN_TX);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_ADUSt_sg_oADUSt_oJ6L_ADUCAN_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_RDUSt_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_RDUSt_sg_oRDUSt_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_RDUSt_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDUSt_oRDUSt_RmtCtrlStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_RDUSt_sg_oRDUSt_oJ6L_ADUCAN_Rx)).RDUSt_RmtCtrlStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDUSt_oRDUSt_SafetyMode_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_RDUSt_sg_oRDUSt_oJ6L_ADUCAN_Rx)).RDUSt_SafetyMode);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDUSt_oRDUSt_EBStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_RDUSt_sg_oRDUSt_oJ6L_ADUCAN_Rx)).RDUSt_EBStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDUSt_oRDUSt_EBSrc_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_RDUSt_sg_oRDUSt_oJ6L_ADUCAN_Rx)).RDUSt_EBSrc);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDUSt_oRDUSt_ADCtrlEnable_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_RDUSt_sg_oRDUSt_oJ6L_ADUCAN_Rx)).RDUSt_ADCtrlEnable);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDUSt_oRDUSt_RmtCtrlEnable_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_RDUSt_sg_oRDUSt_oJ6L_ADUCAN_Rx)).RDUSt_RmtCtrlEnable);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDUSt_oRDUSt_RmtCtrlEnableResp_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_RDUSt_sg_oRDUSt_oJ6L_ADUCAN_Rx)).RDUSt_RmtCtrlEnableResp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDUSt_oRDUSt_RmtPowerOnOff_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_RDUSt_sg_oRDUSt_oJ6L_ADUCAN_Rx)).RDUSt_RmtPowerOnOff);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDUSt_oRDUSt_RDUSleepCmd_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_RDUSt_sg_oRDUSt_oJ6L_ADUCAN_Rx)).RDUSt_RDUSleepCmd);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDUSt_oRDUSt_DriveTorqueLimit_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_RDUSt_sg_oRDUSt_oJ6L_ADUCAN_Rx)).RDUSt_DriveTorqueLimit);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDUSt_oRDUSt_BrakeDeccelLimit_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_RDUSt_sg_oRDUSt_oJ6L_ADUCAN_Rx)).RDUSt_BrakeDeccelLimit);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDUSt_oRDUSt_VehicleSpdLimit_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_RDUSt_sg_oRDUSt_oJ6L_ADUCAN_Rx)).RDUSt_VehicleSpdLimit);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDUSt_oRDUSt_ErrorStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_RDUSt_sg_oRDUSt_oJ6L_ADUCAN_Rx)).RDUSt_ErrorStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDUSt_oRDUSt_LiveCounter_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_RDUSt_sg_oRDUSt_oJ6L_ADUCAN_Rx)).RDUSt_LiveCounter);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_RDUSt_sg_oRDUSt_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_J6L_ADUCAN_RxSignal_SG_IGWSt_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_IGWSt_sg_oIGWSt_oJ6L_ADUCAN_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_IGWSt_oJ6L_ADUCAN_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_IGWSt_oIGWSt_IGWStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_IGWSt_sg_oIGWSt_oJ6L_ADUCAN_Rx)).IGWSt_IGWStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_IGWSt_oIGWSt_RouteStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_IGWSt_sg_oIGWSt_oJ6L_ADUCAN_Rx)).IGWSt_RouteStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_IGWSt_oIGWSt_ErrorStat_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_IGWSt_sg_oIGWSt_oJ6L_ADUCAN_Rx)).IGWSt_ErrorStat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_IGWSt_oIGWSt_LiveCounter_o_J6L_ADUCAN_Rx,&(*(&Rte_SG_IGWSt_sg_oIGWSt_oJ6L_ADUCAN_Rx)).IGWSt_LiveCounter);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_IGWSt_sg_oIGWSt_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_ComProxy_GNSS_TxSignal_SG_ADU_Cmd_AECS_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_ADU_Cmd_AECS_sg_oADU_Cmd_AECS_oGNSSCooling_CANMatrix_Tx);
  ret |= Com_SendSignal(ComConf_ComSignal_ADU_Cmd_AECS_oACS_Enable_Status_o_GNSSCooling_CANMatrix_Tx,&(*(&Rte_SG_ADU_Cmd_AECS_sg_oADU_Cmd_AECS_oGNSSCooling_CANMatrix_Tx)).ACS_Enable_Status);
  ret |= Com_SendSignal(ComConf_ComSignal_ADU_Cmd_AECS_oACS_Enable_Status_Counter_o_GNSSCooling_CANMatrix_Tx,&(*(&Rte_SG_ADU_Cmd_AECS_sg_oADU_Cmd_AECS_oGNSSCooling_CANMatrix_Tx)).ACS_Enable_Status_Counter);
  ret |= Com_SendSignal(ComConf_ComSignal_ADU_Cmd_AECS_oV_ADU_Temp_M_o_GNSSCooling_CANMatrix_Tx,&(*(&Rte_SG_ADU_Cmd_AECS_sg_oADU_Cmd_AECS_oGNSSCooling_CANMatrix_Tx)).V_ADU_Temp_M);
  ret |= Com_SendSignal(ComConf_ComSignal_ADU_Cmd_AECS_oV_ADU_Inter_W_o_GNSSCooling_CANMatrix_Tx,&(*(&Rte_SG_ADU_Cmd_AECS_sg_oADU_Cmd_AECS_oGNSSCooling_CANMatrix_Tx)).V_ADU_Inter_W);
  ret |= Com_SendSignal(ComConf_ComSignal_ADU_Cmd_AECS_oV_ADU_Temp_Valid_o_GNSSCooling_CANMatrix_Tx,&(*(&Rte_SG_ADU_Cmd_AECS_sg_oADU_Cmd_AECS_oGNSSCooling_CANMatrix_Tx)).V_ADU_Temp_Valid);
  ret |= Com_SendSignal(ComConf_ComSignal_ADU_Cmd_AECS_oACS_Fan_Pwm_Req_o_GNSSCooling_CANMatrix_Tx,&(*(&Rte_SG_ADU_Cmd_AECS_sg_oADU_Cmd_AECS_oGNSSCooling_CANMatrix_Tx)).ACS_Fan_Pwm_Req);
  ret |= Com_SendSignal(ComConf_ComSignal_ADU_Cmd_AECS_oACS_Pump_Pwm_Req_o_GNSSCooling_CANMatrix_Tx,&(*(&Rte_SG_ADU_Cmd_AECS_sg_oADU_Cmd_AECS_oGNSSCooling_CANMatrix_Tx)).ACS_Pump_Pwm_Req);
  (void)Com_SendSignalGroup(ComConf_ComGroupSignal_ADU_Cmd_AECS_oGNSSCooling_CANMatrix_TX);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_ADU_Cmd_AECS_sg_oADU_Cmd_AECS_oGNSSCooling_CANMatrix_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_GnssDC_Callout_GNSS_RxSignal_SG_AECS_Feedback1_sg(SG_AECS_Feedback1_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_AECS_Feedback1_oGNSSCooling_CANMatrix_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_AECS_Feedback1_oInlet_RadiatorTemp_o_GNSSCooling_CANMatrix_Rx,&(*(data)).Inlet_RadiatorTemp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_AECS_Feedback1_oOutlet_RadiatorTemp_o_GNSSCooling_CANMatrix_Rx,&(*(data)).Outlet_RadiatorTemp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_AECS_Feedback1_oFan_AmbientTemp_o_GNSSCooling_CANMatrix_Rx,&(*(data)).Fan_AmbientTemp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_AECS_Feedback1_oECU_AmbientTemp_o_GNSSCooling_CANMatrix_Rx,&(*(data)).ECU_AmbientTemp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_AECS_Feedback1_oAECS_Voltage_o_GNSSCooling_CANMatrix_Rx,&(*(data)).AECS_Voltage);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_AECS_Feedback1_oFan_SpeedPercent_o_GNSSCooling_CANMatrix_Rx,&(*(data)).Fan_SpeedPercent);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_AECS_Feedback1_oPump_SpeedPercent_o_GNSSCooling_CANMatrix_Rx,&(*(data)).Pump_SpeedPercent);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_AECS_Feedback1_oAECS_Status_o_GNSSCooling_CANMatrix_Rx,&(*(data)).AECS_Status);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_AECS_Feedback1_oOver_Temp_level_o_GNSSCooling_CANMatrix_Rx,&(*(data)).Over_Temp_level);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_AECS_Feedback1_oAECS_Alive_Counter1_o_GNSSCooling_CANMatrix_Rx,&(*(data)).AECS_Alive_Counter1);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_GnssDC_Callout_GNSS_RxSignal_SG_AECS_Feedback2_sg(SG_AECS_Feedback2_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_AECS_Feedback2_oGNSSCooling_CANMatrix_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_AECS_Feedback2_oCoolant_Alarm_o_GNSSCooling_CANMatrix_Rx,&(*(data)).Coolant_Alarm);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_AECS_Feedback2_oFan_AmbientTemp_Alarm_o_GNSSCooling_CANMatrix_Rx,&(*(data)).Fan_AmbientTemp_Alarm);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_AECS_Feedback2_oECU_AmbientTemp_Alarm_o_GNSSCooling_CANMatrix_Rx,&(*(data)).ECU_AmbientTemp_Alarm);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_AECS_Feedback2_oVoltage_Alarm_o_GNSSCooling_CANMatrix_Rx,&(*(data)).Voltage_Alarm);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_AECS_Feedback2_oFan_hardware_Fault_o_GNSSCooling_CANMatrix_Rx,&(*(data)).Fan_hardware_Fault);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_AECS_Feedback2_oECU_hardware_Fault_o_GNSSCooling_CANMatrix_Rx,&(*(data)).ECU_hardware_Fault);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_AECS_Feedback2_oPump_hardware_Fault_o_GNSSCooling_CANMatrix_Rx,&(*(data)).Pump_hardware_Fault);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_AECS_Feedback2_oWater_Thermometer_Alarm_o_GNSSCooling_CANMatrix_Rx,&(*(data)).Water_Thermometer_Alarm);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_AECS_Feedback2_oAECS_Alive_Counter2_o_GNSSCooling_CANMatrix_Rx,&(*(data)).AECS_Alive_Counter2);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_ComProxy_GNSS_TxSignal_SG_ACS_Calibration_ADU_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_ACS_Calibration_ADU_sg_oACS_Calibration_ADU_oGNSSCooling_CANMatrix_Tx);
  ret |= Com_SendSignal(ComConf_ComSignal_ACS_Calibration_ADU_oK_ACS_Temp_RFS_o_GNSSCooling_CANMatrix_Tx,&(*(&Rte_SG_ACS_Calibration_ADU_sg_oACS_Calibration_ADU_oGNSSCooling_CANMatrix_Tx)).K_ACS_Temp_RFS);
  ret |= Com_SendSignal(ComConf_ComSignal_ACS_Calibration_ADU_oK_ACS_Temp_W_o_GNSSCooling_CANMatrix_Tx,&(*(&Rte_SG_ACS_Calibration_ADU_sg_oACS_Calibration_ADU_oGNSSCooling_CANMatrix_Tx)).K_ACS_Temp_W);
  ret |= Com_SendSignal(ComConf_ComSignal_ACS_Calibration_ADU_oK_ACS_Temp_C_o_GNSSCooling_CANMatrix_Tx,&(*(&Rte_SG_ACS_Calibration_ADU_sg_oACS_Calibration_ADU_oGNSSCooling_CANMatrix_Tx)).K_ACS_Temp_C);
  ret |= Com_SendSignal(ComConf_ComSignal_ACS_Calibration_ADU_oK_TimeLast_Over_Temp_o_GNSSCooling_CANMatrix_Tx,&(*(&Rte_SG_ACS_Calibration_ADU_sg_oACS_Calibration_ADU_oGNSSCooling_CANMatrix_Tx)).K_TimeLast_Over_Temp);
  ret |= Com_SendSignal(ComConf_ComSignal_ACS_Calibration_ADU_oK_ADU_Temp_RPS_o_GNSSCooling_CANMatrix_Tx,&(*(&Rte_SG_ACS_Calibration_ADU_sg_oACS_Calibration_ADU_oGNSSCooling_CANMatrix_Tx)).K_ADU_Temp_RPS);
  ret |= Com_SendSignal(ComConf_ComSignal_ACS_Calibration_ADU_oK_ADU_Temp_RFS_o_GNSSCooling_CANMatrix_Tx,&(*(&Rte_SG_ACS_Calibration_ADU_sg_oACS_Calibration_ADU_oGNSSCooling_CANMatrix_Tx)).K_ADU_Temp_RFS);
  ret |= Com_SendSignal(ComConf_ComSignal_ACS_Calibration_ADU_oK_ADU_Temp_W_o_GNSSCooling_CANMatrix_Tx,&(*(&Rte_SG_ACS_Calibration_ADU_sg_oACS_Calibration_ADU_oGNSSCooling_CANMatrix_Tx)).K_ADU_Temp_W);
  ret |= Com_SendSignal(ComConf_ComSignal_ACS_Calibration_ADU_oK_ADU_Temp_C_o_GNSSCooling_CANMatrix_Tx,&(*(&Rte_SG_ACS_Calibration_ADU_sg_oACS_Calibration_ADU_oGNSSCooling_CANMatrix_Tx)).K_ADU_Temp_C);
  (void)Com_SendSignalGroup(ComConf_ComGroupSignal_ACS_Calibration_ADU_oGNSSCooling_CANMatrix_TX);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_ACS_Calibration_ADU_sg_oACS_Calibration_ADU_oGNSSCooling_CANMatrix_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_GNSS_RxSignal_SG_Time_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_Time_sg_oTime_oGNSSCooling_CANMatrix_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_Time_oGNSSCooling_CANMatrix_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Time_oGpsWeek_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_Time_sg_oTime_oGNSSCooling_CANMatrix_Rx)).GpsWeek);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Time_oGpsTime_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_Time_sg_oTime_oGNSSCooling_CANMatrix_Rx)).GpsTime);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_Time_sg_oTime_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_GNSS_RxSignal_SG_Ang_Rate_Raw_IMU_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_Ang_Rate_Raw_IMU_sg_oAng_Rate_Raw_IMU_oGNSSCooling_CANMatrix_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_Ang_Rate_Raw_IMU_oGNSSCooling_CANMatrix_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Ang_Rate_Raw_IMU_oAngRateRawX_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_Ang_Rate_Raw_IMU_sg_oAng_Rate_Raw_IMU_oGNSSCooling_CANMatrix_Rx)).AngRateRawX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Ang_Rate_Raw_IMU_oAngRateRawY_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_Ang_Rate_Raw_IMU_sg_oAng_Rate_Raw_IMU_oGNSSCooling_CANMatrix_Rx)).AngRateRawY);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Ang_Rate_Raw_IMU_oAngRateRawZ_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_Ang_Rate_Raw_IMU_sg_oAng_Rate_Raw_IMU_oGNSSCooling_CANMatrix_Rx)).AngRateRawZ);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_Ang_Rate_Raw_IMU_sg_oAng_Rate_Raw_IMU_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_GNSS_RxSignal_SG_Accel_IMU_Raw_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_Accel_IMU_Raw_sg_oAccel_IMU_Raw_oGNSSCooling_CANMatrix_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_Accel_IMU_Raw_oGNSSCooling_CANMatrix_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Accel_IMU_Raw_oAccelRawX_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_Accel_IMU_Raw_sg_oAccel_IMU_Raw_oGNSSCooling_CANMatrix_Rx)).AccelRawX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Accel_IMU_Raw_oAccelRawY_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_Accel_IMU_Raw_sg_oAccel_IMU_Raw_oGNSSCooling_CANMatrix_Rx)).AccelRawY);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Accel_IMU_Raw_oAccelRawZ_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_Accel_IMU_Raw_sg_oAccel_IMU_Raw_oGNSSCooling_CANMatrix_Rx)).AccelRawZ);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_Accel_IMU_Raw_sg_oAccel_IMU_Raw_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_GNSS_RxSignal_SG_InsStatus_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_InsStatus_sg_oInsStatus_oGNSSCooling_CANMatrix_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_InsStatus_oGNSSCooling_CANMatrix_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_InsStatus_osystem_state_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_InsStatus_sg_oInsStatus_oGNSSCooling_CANMatrix_Rx)).system_state);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_InsStatus_oGpsNumSatsUsed_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_InsStatus_sg_oInsStatus_oGNSSCooling_CANMatrix_Rx)).GpsNumSatsUsed);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_InsStatus_osatellite_status_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_InsStatus_sg_oInsStatus_oGNSSCooling_CANMatrix_Rx)).satellite_status);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_InsStatus_oGpsNumSats2Used_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_InsStatus_sg_oInsStatus_oGNSSCooling_CANMatrix_Rx)).GpsNumSats2Used);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_InsStatus_oGpsAge_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_InsStatus_sg_oInsStatus_oGNSSCooling_CANMatrix_Rx)).GpsAge);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_InsStatus_oGpsNumSats_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_InsStatus_sg_oInsStatus_oGNSSCooling_CANMatrix_Rx)).GpsNumSats);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_InsStatus_oGpsNumSats2_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_InsStatus_sg_oInsStatus_oGNSSCooling_CANMatrix_Rx)).GpsNumSats2);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_InsStatus_sg_oInsStatus_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_GNSS_RxSignal_SG_LatitudeLongitude_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_LatitudeLongitude_sg_oLatitudeLongitude_oGNSSCooling_CANMatrix_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_LatitudeLongitude_oGNSSCooling_CANMatrix_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_LatitudeLongitude_oPosLat_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_LatitudeLongitude_sg_oLatitudeLongitude_oGNSSCooling_CANMatrix_Rx)).PosLat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_LatitudeLongitude_oPosLon_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_LatitudeLongitude_sg_oLatitudeLongitude_oGNSSCooling_CANMatrix_Rx)).PosLon);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_LatitudeLongitude_sg_oLatitudeLongitude_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_GNSS_RxSignal_SG_Altitude_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_Altitude_sg_oAltitude_oGNSSCooling_CANMatrix_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_Altitude_oGNSSCooling_CANMatrix_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Altitude_oPosAlt_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_Altitude_sg_oAltitude_oGNSSCooling_CANMatrix_Rx)).PosAlt);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_Altitude_sg_oAltitude_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_GNSS_RxSignal_SG_PosSigma_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_PosSigma_sg_oPosSigma_oGNSSCooling_CANMatrix_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_PosSigma_oGNSSCooling_CANMatrix_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_PosSigma_oPosESigma_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_PosSigma_sg_oPosSigma_oGNSSCooling_CANMatrix_Rx)).PosESigma);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_PosSigma_oPosNsigma_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_PosSigma_sg_oPosSigma_oGNSSCooling_CANMatrix_Rx)).PosNsigma);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_PosSigma_oPosUsigma_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_PosSigma_sg_oPosSigma_oGNSSCooling_CANMatrix_Rx)).PosUsigma);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_PosSigma_sg_oPosSigma_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_GNSS_RxSignal_SG_VelocityLevel_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_VelocityLevel_sg_oVelocityLevel_oGNSSCooling_CANMatrix_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_VelocityLevel_oGNSSCooling_CANMatrix_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_VelocityLevel_oVelE_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_VelocityLevel_sg_oVelocityLevel_oGNSSCooling_CANMatrix_Rx)).VelE);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_VelocityLevel_oVelN_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_VelocityLevel_sg_oVelocityLevel_oGNSSCooling_CANMatrix_Rx)).VelN);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_VelocityLevel_oVelU_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_VelocityLevel_sg_oVelocityLevel_oGNSSCooling_CANMatrix_Rx)).VelU);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_VelocityLevel_oVel_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_VelocityLevel_sg_oVelocityLevel_oGNSSCooling_CANMatrix_Rx)).Vel);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_VelocityLevel_sg_oVelocityLevel_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_GNSS_RxSignal_SG_VelocityLevelSigma_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_VelocityLevelSigma_sg_oVelocityLevelSigma_oGNSSCooling_CANMatrix_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_VelocityLevelSigma_oGNSSCooling_CANMatrix_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_VelocityLevelSigma_oVelESigma_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_VelocityLevelSigma_sg_oVelocityLevelSigma_oGNSSCooling_CANMatrix_Rx)).VelESigma);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_VelocityLevelSigma_oVelNSigma_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_VelocityLevelSigma_sg_oVelocityLevelSigma_oGNSSCooling_CANMatrix_Rx)).VelNSigma);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_VelocityLevelSigma_oVelUSigma_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_VelocityLevelSigma_sg_oVelocityLevelSigma_oGNSSCooling_CANMatrix_Rx)).VelUSigma);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_VelocityLevelSigma_oVelSigma_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_VelocityLevelSigma_sg_oVelocityLevelSigma_oGNSSCooling_CANMatrix_Rx)).VelSigma);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_VelocityLevelSigma_sg_oVelocityLevelSigma_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_GNSS_RxSignal_SG_Accel_Vehicle_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_Accel_Vehicle_sg_oAccel_Vehicle_oGNSSCooling_CANMatrix_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_Accel_Vehicle_oGNSSCooling_CANMatrix_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Accel_Vehicle_oAccelX_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_Accel_Vehicle_sg_oAccel_Vehicle_oGNSSCooling_CANMatrix_Rx)).AccelX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Accel_Vehicle_oAccelY_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_Accel_Vehicle_sg_oAccel_Vehicle_oGNSSCooling_CANMatrix_Rx)).AccelY);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Accel_Vehicle_oAccelZ_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_Accel_Vehicle_sg_oAccel_Vehicle_oGNSSCooling_CANMatrix_Rx)).AccelZ);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_Accel_Vehicle_sg_oAccel_Vehicle_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_GNSS_RxSignal_SG_HeadingPitchRoll_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_HeadingPitchRoll_sg_oHeadingPitchRoll_oGNSSCooling_CANMatrix_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_HeadingPitchRoll_oGNSSCooling_CANMatrix_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_HeadingPitchRoll_oAngleHeading_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_HeadingPitchRoll_sg_oHeadingPitchRoll_oGNSSCooling_CANMatrix_Rx)).AngleHeading);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_HeadingPitchRoll_oAnglePitch_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_HeadingPitchRoll_sg_oHeadingPitchRoll_oGNSSCooling_CANMatrix_Rx)).AnglePitch);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_HeadingPitchRoll_oAngleRoll_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_HeadingPitchRoll_sg_oHeadingPitchRoll_oGNSSCooling_CANMatrix_Rx)).AngleRoll);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_HeadingPitchRoll_sg_oHeadingPitchRoll_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_GNSS_RxSignal_SG_HeadingPitchRollSigma_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_HeadingPitchRollSigma_sg_oHeadingPitchRollSigma_oGNSSCooling_CANMatrix_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_HeadingPitchRollSigma_oGNSSCooling_CANMatrix_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_HeadingPitchRollSigma_oAngleHeadingSigma_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_HeadingPitchRollSigma_sg_oHeadingPitchRollSigma_oGNSSCooling_CANMatrix_Rx)).AngleHeadingSigma);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_HeadingPitchRollSigma_oAnglePitchSigma_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_HeadingPitchRollSigma_sg_oHeadingPitchRollSigma_oGNSSCooling_CANMatrix_Rx)).AnglePitchSigma);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_HeadingPitchRollSigma_oAngleRollSigma_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_HeadingPitchRollSigma_sg_oHeadingPitchRollSigma_oGNSSCooling_CANMatrix_Rx)).AngleRollSigma);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_HeadingPitchRollSigma_sg_oHeadingPitchRollSigma_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_GNSS_RxSignal_SG_AngRateVehicle_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_AngRateVehicle_sg_oAngRateVehicle_oGNSSCooling_CANMatrix_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_AngRateVehicle_oGNSSCooling_CANMatrix_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_AngRateVehicle_oAngRateX_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_AngRateVehicle_sg_oAngRateVehicle_oGNSSCooling_CANMatrix_Rx)).AngRateX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_AngRateVehicle_oAngRateY_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_AngRateVehicle_sg_oAngRateVehicle_oGNSSCooling_CANMatrix_Rx)).AngRateY);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_AngRateVehicle_oAngRateZ_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_AngRateVehicle_sg_oAngRateVehicle_oGNSSCooling_CANMatrix_Rx)).AngRateZ);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_AngRateVehicle_sg_oAngRateVehicle_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_GNSS_RxSignal_SG_Longitude_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_Longitude_sg_oLongitude_oGNSSCooling_CANMatrix_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_Longitude_oGNSSCooling_CANMatrix_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Longitude_oPosLon2_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_Longitude_sg_oLongitude_oGNSSCooling_CANMatrix_Rx)).PosLon2);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_Longitude_sg_oLongitude_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_GNSS_RxSignal_SG_Latitude_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_Latitude_sg_oLatitude_oGNSSCooling_CANMatrix_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_Latitude_oGNSSCooling_CANMatrix_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Latitude_oPosLat2_o_GNSSCooling_CANMatrix_Rx,&(*(&Rte_SG_Latitude_sg_oLatitude_oGNSSCooling_CANMatrix_Rx)).PosLat2);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_Latitude_sg_oLatitude_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_Callout_ARS430_RxSignal_SG_RDF_State_sg(SG_RDF_State_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_RDF_State_oRDF2_CANMatrix_F_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_State_oCRC_SG_RS_Pkt_o_RDF2_CANMatrix_F_Rx,&(*(data)).CRC_SG_RS_Pkt);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_State_oSQC_SG_RS_Pkt_o_RDF2_CANMatrix_F_Rx,&(*(data)).SQC_SG_RS_Pkt);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_State_oWakeupRsn_RS_RDF_o_RDF2_CANMatrix_F_Rx,&(*(data)).WakeupRsn_RS_RDF);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_State_oSystem_RS_Availability_o_RDF2_CANMatrix_F_Rx,&(*(data)).System_RS_Availability);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_State_oBlockage_RS_State_o_RDF2_CANMatrix_F_Rx,&(*(data)).Blockage_RS_State);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_ARS430_RxSignal_SG_RDF_State_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_RDF_State_sg_oRDF_State_oRDF2_CANMatrix_F_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_RDF_State_oRDF2_CANMatrix_F_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_State_oCRC_SG_RS_Pkt_o_RDF2_CANMatrix_F_Rx,&(*(&Rte_SG_RDF_State_sg_oRDF_State_oRDF2_CANMatrix_F_Rx)).CRC_SG_RS_Pkt);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_State_oSQC_SG_RS_Pkt_o_RDF2_CANMatrix_F_Rx,&(*(&Rte_SG_RDF_State_sg_oRDF_State_oRDF2_CANMatrix_F_Rx)).SQC_SG_RS_Pkt);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_State_oWakeupRsn_RS_RDF_o_RDF2_CANMatrix_F_Rx,&(*(&Rte_SG_RDF_State_sg_oRDF_State_oRDF2_CANMatrix_F_Rx)).WakeupRsn_RS_RDF);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_State_oSystem_RS_Availability_o_RDF2_CANMatrix_F_Rx,&(*(&Rte_SG_RDF_State_sg_oRDF_State_oRDF2_CANMatrix_F_Rx)).System_RS_Availability);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_State_oBlockage_RS_State_o_RDF2_CANMatrix_F_Rx,&(*(&Rte_SG_RDF_State_sg_oRDF_State_oRDF2_CANMatrix_F_Rx)).Blockage_RS_State);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_RDF_State_sg_oRDF_State_oRDF2_CANMatrix_F_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_Callout_ARS430_RxSignal_SG_RDF_C01_sg(SG_RDF_C01_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_RDF_C01_oRDF2_CANMatrix_F_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C01_oCRC_SG_RDF_C01_Pkt_o_RDF2_CANMatrix_F_Rx,&(*(data)).CRC_SG_RDF_C01_Pkt);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C01_oSQC_SG_RDF_C01_Pkt_o_RDF2_CANMatrix_F_Rx,&(*(data)).SQC_SG_RDF_C01_Pkt);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C01_oObj_ID1_o_RDF2_CANMatrix_F_Rx,&(*(data)).Obj_ID1);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C01_oRCS_Obj_Cval_o_RDF2_CANMatrix_F_Rx,&(*(data)).RCS_Obj_Cval);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C01_oTypeObj_Stat_RDF_o_RDF2_CANMatrix_F_Rx,&(*(data)).TypeObj_Stat_RDF);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C01_oObj_eClassification_o_RDF2_CANMatrix_F_Rx,&(*(data)).Obj_eClassification);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C01_oTnlObsrv_Stat_RDF_o_RDF2_CANMatrix_F_Rx,&(*(data)).TnlObsrv_Stat_RDF);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C01_ouiDynConfidence_o_RDF2_CANMatrix_F_Rx,&(*(data)).uiDynConfidence);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C01_ouiProbabilityOfExistence_o_RDF2_CANMatrix_F_Rx,&(*(data)).uiProbabilityOfExistence);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C01_oLossObj_Stat_RDF_o_RDF2_CANMatrix_F_Rx,&(*(data)).LossObj_Stat_RDF);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C01_oeMaintenanceState_o_RDF2_CANMatrix_F_Rx,&(*(data)).eMaintenanceState);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_Callout_ARS430_RxSignal_SG_RDF_C02_sg(SG_RDF_C02_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_RDF_C02_oRDF2_CANMatrix_F_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C02_oCRC_SG_RDF_C02_Pkt_o_RDF2_CANMatrix_F_Rx,&(*(data)).CRC_SG_RDF_C02_Pkt);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C02_oSQC_SG_RDF_C02_Pkt_o_RDF2_CANMatrix_F_Rx,&(*(data)).SQC_SG_RDF_C02_Pkt);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C02_oDist_Y_Obj_Cval_RDF_o_RDF2_CANMatrix_F_Rx,&(*(data)).Dist_Y_Obj_Cval_RDF);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C02_oDist_X_Obj_Cval_RDF_o_RDF2_CANMatrix_F_Rx,&(*(data)).Dist_X_Obj_Cval_RDF);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C02_oWidthObj_Cval_RDF_o_RDF2_CANMatrix_F_Rx,&(*(data)).WidthObj_Cval_RDF);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C02_oObj_ID2_o_RDF2_CANMatrix_F_Rx,&(*(data)).Obj_ID2);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C02_oAccel_X_Obj_Cval_RDF_o_RDF2_CANMatrix_F_Rx,&(*(data)).Accel_X_Obj_Cval_RDF);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_Callout_ARS430_RxSignal_SG_RDF_C03_sg(SG_RDF_C03_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_RDF_C03_oRDF2_CANMatrix_F_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C03_oCRC_SG_RDF_C03_Pkt_o_RDF2_CANMatrix_F_Rx,&(*(data)).CRC_SG_RDF_C03_Pkt);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C03_oSQC_SG_RDF_C03_Pkt_o_RDF2_CANMatrix_F_Rx,&(*(data)).SQC_SG_RDF_C03_Pkt);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C03_oSpd_X_Obj_Cval_RDF_o_RDF2_CANMatrix_F_Rx,&(*(data)).Spd_X_Obj_Cval_RDF);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C03_oObj_ID3_o_RDF2_CANMatrix_F_Rx,&(*(data)).Obj_ID3);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C03_oObj_ucObstacleProbability_o_RDF2_CANMatrix_F_Rx,&(*(data)).Obj_ucObstacleProbability);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C03_oObj_uiLifeCycles_o_RDF2_CANMatrix_F_Rx,&(*(data)).Obj_uiLifeCycles);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_Callout_ARS430_RxSignal_SG_RDF_C04_sg(SG_RDF_C04_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_RDF_C04_oRDF2_CANMatrix_F_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C04_oCRC_SG_RDF_C04_Pkt_o_RDF2_CANMatrix_F_Rx,&(*(data)).CRC_SG_RDF_C04_Pkt);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C04_oSQC_SG_RDF_C04_Pkt_o_RDF2_CANMatrix_F_Rx,&(*(data)).SQC_SG_RDF_C04_Pkt);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C04_oStdRng_Y_Obj_Cval_RDF_o_RDF2_CANMatrix_F_Rx,&(*(data)).StdRng_Y_Obj_Cval_RDF);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C04_oStdRng_X_Obj_Cval_RDF_o_RDF2_CANMatrix_F_Rx,&(*(data)).StdRng_X_Obj_Cval_RDF);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C04_oStdRngSpd_Y_ObjStati_Cval_RDF_o_RDF2_CANMatrix_F_Rx,&(*(data)).StdRngSpd_Y_ObjStati_Cval_RDF);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C04_oStdRngSpd_X_Obj_Cval_RDF_o_RDF2_CANMatrix_F_Rx,&(*(data)).StdRngSpd_X_Obj_Cval_RDF);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C04_oSpd_Y_Obj_Cval_RDF_o_RDF2_CANMatrix_F_Rx,&(*(data)).Spd_Y_Obj_Cval_RDF);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RDF_C04_oObj_ID4_o_RDF2_CANMatrix_F_Rx,&(*(data)).Obj_ID4);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_ComProxy_ARS430_TxSignal_SG_SCA_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_SCA_sg_oSCA_oRDF2_CANMatrix_F_Tx);
  ret |= Com_SendSignal(ComConf_ComSignal_SCA_oCRC_SG_SCA_Pkt_o_RDF2_CANMatrix_F_Tx,&(*(&Rte_SG_SCA_sg_oSCA_oRDF2_CANMatrix_F_Tx)).CRC_SG_SCA_Pkt);
  ret |= Com_SendSignal(ComConf_ComSignal_SCA_oSQC_SG_SCA_Pkt_o_RDF2_CANMatrix_F_Tx,&(*(&Rte_SG_SCA_sg_oSCA_oRDF2_CANMatrix_F_Tx)).SQC_SG_SCA_Pkt);
  ret |= Com_SendSignal(ComConf_ComSignal_SCA_oVehLongMotStateExt_SCA_o_RDF2_CANMatrix_F_Tx,&(*(&Rte_SG_SCA_sg_oSCA_oRDF2_CANMatrix_F_Tx)).VehLongMotStateExt_SCA);
  ret |= Com_SendSignal(ComConf_ComSignal_SCA_oDrvDirec_Stat_SCA_o_RDF2_CANMatrix_F_Tx,&(*(&Rte_SG_SCA_sg_oSCA_oRDF2_CANMatrix_F_Tx)).DrvDirec_Stat_SCA);
  ret |= Com_SendSignal(ComConf_ComSignal_SCA_oIgnSw_Stat_SCA_o_RDF2_CANMatrix_F_Tx,&(*(&Rte_SG_SCA_sg_oSCA_oRDF2_CANMatrix_F_Tx)).IgnSw_Stat_SCA);
  (void)Com_SendSignalGroup(ComConf_ComGroupSignal_SCA_oRDF2_CANMatrix_F_TX);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_SCA_sg_oSCA_oRDF2_CANMatrix_F_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_ComProxy_ARS430_TxSignal_SG_HRW_FR_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_HRW_FR_sg_oHRW_FR_oRDF2_CANMatrix_F_Tx);
  ret |= Com_SendSignal(ComConf_ComSignal_HRW_FR_oCRC_SG_HRW_FR_Pkt_o_RDF2_CANMatrix_F_Tx,&(*(&Rte_SG_HRW_FR_sg_oHRW_FR_oRDF2_CANMatrix_F_Tx)).CRC_SG_HRW_FR_Pkt);
  ret |= Com_SendSignal(ComConf_ComSignal_HRW_FR_oSQC_SG_HRW_FR_Pkt_o_RDF2_CANMatrix_F_Tx,&(*(&Rte_SG_HRW_FR_sg_oHRW_FR_oRDF2_CANMatrix_F_Tx)).SQC_SG_HRW_FR_Pkt);
  ret |= Com_SendSignal(ComConf_ComSignal_HRW_FR_oSpdFtAxleLtWhl_Cval_o_RDF2_CANMatrix_F_Tx,&(*(&Rte_SG_HRW_FR_sg_oHRW_FR_oRDF2_CANMatrix_F_Tx)).SpdFtAxleLtWhl_Cval);
  ret |= Com_SendSignal(ComConf_ComSignal_HRW_FR_oSpdFtAxleRtWhl_Cval_o_RDF2_CANMatrix_F_Tx,&(*(&Rte_SG_HRW_FR_sg_oHRW_FR_oRDF2_CANMatrix_F_Tx)).SpdFtAxleRtWhl_Cval);
  (void)Com_SendSignalGroup(ComConf_ComGroupSignal_HRW_FR_oRDF2_CANMatrix_F_TX);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_HRW_FR_sg_oHRW_FR_oRDF2_CANMatrix_F_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_ComProxy_ARS430_TxSignal_SG_HRW_RE_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_HRW_RE_sg_oHRW_RE_oRDF2_CANMatrix_F_Tx);
  ret |= Com_SendSignal(ComConf_ComSignal_HRW_RE_oCRC_SG_HRW_RE_Pkt_o_RDF2_CANMatrix_F_Tx,&(*(&Rte_SG_HRW_RE_sg_oHRW_RE_oRDF2_CANMatrix_F_Tx)).CRC_SG_HRW_RE_Pkt);
  ret |= Com_SendSignal(ComConf_ComSignal_HRW_RE_oSQC_SG_HRW_RE_Pkt_o_RDF2_CANMatrix_F_Tx,&(*(&Rte_SG_HRW_RE_sg_oHRW_RE_oRDF2_CANMatrix_F_Tx)).SQC_SG_HRW_RE_Pkt);
  ret |= Com_SendSignal(ComConf_ComSignal_HRW_RE_oSpdR_AxleLtWhl_Cval_o_RDF2_CANMatrix_F_Tx,&(*(&Rte_SG_HRW_RE_sg_oHRW_RE_oRDF2_CANMatrix_F_Tx)).SpdR_AxleLtWhl_Cval);
  ret |= Com_SendSignal(ComConf_ComSignal_HRW_RE_oSpdR_AxleRtWhl_Cval_o_RDF2_CANMatrix_F_Tx,&(*(&Rte_SG_HRW_RE_sg_oHRW_RE_oRDF2_CANMatrix_F_Tx)).SpdR_AxleRtWhl_Cval);
  (void)Com_SendSignalGroup(ComConf_ComGroupSignal_HRW_RE_oRDF2_CANMatrix_F_TX);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_HRW_RE_sg_oHRW_RE_oRDF2_CANMatrix_F_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_ComProxy_ARS430_TxSignal_SG_BS_E7_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_BS_E7_sg_oBS_E7_oRDF2_CANMatrix_F_Tx);
  ret |= Com_SendSignal(ComConf_ComSignal_BS_E7_oCRC_SG_BS_E7_Pkt_o_RDF2_CANMatrix_F_Tx,&(*(&Rte_SG_BS_E7_sg_oBS_E7_oRDF2_CANMatrix_F_Tx)).CRC_SG_BS_E7_Pkt);
  ret |= Com_SendSignal(ComConf_ComSignal_BS_E7_oSQC_SG_BS_E7_Pkt_o_RDF2_CANMatrix_F_Tx,&(*(&Rte_SG_BS_E7_sg_oBS_E7_oRDF2_CANMatrix_F_Tx)).SQC_SG_BS_E7_Pkt);
  ret |= Com_SendSignal(ComConf_ComSignal_BS_E7_oYawRateCorr_Cval_BS_o_RDF2_CANMatrix_F_Tx,&(*(&Rte_SG_BS_E7_sg_oBS_E7_oRDF2_CANMatrix_F_Tx)).YawRateCorr_Cval_BS);
  ret |= Com_SendSignal(ComConf_ComSignal_BS_E7_oLongitudinalAcceleration_Cval_BS_o_RDF2_CANMatrix_F_Tx,&(*(&Rte_SG_BS_E7_sg_oBS_E7_oRDF2_CANMatrix_F_Tx)).LongitudinalAcceleration_Cval_BS);
  (void)Com_SendSignalGroup(ComConf_ComGroupSignal_BS_E7_oRDF2_CANMatrix_F_TX);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_BS_E7_sg_oBS_E7_oRDF2_CANMatrix_F_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Send_ComProxy_ARS430_TxSignal_SG_Brak_Sta_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_Brak_Sta_sg_oBrak_Sta_oRDF2_CANMatrix_F_Tx);
  ret |= Com_SendSignal(ComConf_ComSignal_Brak_Sta_oCRC_SG_Brak_Sta_Pkt_o_RDF2_CANMatrix_F_Tx,&(*(&Rte_SG_Brak_Sta_sg_oBrak_Sta_oRDF2_CANMatrix_F_Tx)).CRC_SG_Brak_Sta_Pkt);
  ret |= Com_SendSignal(ComConf_ComSignal_Brak_Sta_oSQC_SG_Brak_Sta_Pkt_o_RDF2_CANMatrix_F_Tx,&(*(&Rte_SG_Brak_Sta_sg_oBrak_Sta_oRDF2_CANMatrix_F_Tx)).SQC_SG_Brak_Sta_Pkt);
  ret |= Com_SendSignal(ComConf_ComSignal_Brak_Sta_oATC_EngCtrl_Stat_o_RDF2_CANMatrix_F_Tx,&(*(&Rte_SG_Brak_Sta_sg_oBrak_Sta_oRDF2_CANMatrix_F_Tx)).ATC_EngCtrl_Stat);
  ret |= Com_SendSignal(ComConf_ComSignal_Brak_Sta_oATC_BrkCtrl_Stat_o_RDF2_CANMatrix_F_Tx,&(*(&Rte_SG_Brak_Sta_sg_oBrak_Sta_oRDF2_CANMatrix_F_Tx)).ATC_BrkCtrl_Stat);
  ret |= Com_SendSignal(ComConf_ComSignal_Brak_Sta_oABS_Actv_Stat_o_RDF2_CANMatrix_F_Tx,&(*(&Rte_SG_Brak_Sta_sg_oBrak_Sta_oRDF2_CANMatrix_F_Tx)).ABS_Actv_Stat);
  ret |= Com_SendSignal(ComConf_ComSignal_Brak_Sta_oEBS_BrkSw_Rq_o_RDF2_CANMatrix_F_Tx,&(*(&Rte_SG_Brak_Sta_sg_oBrak_Sta_oRDF2_CANMatrix_F_Tx)).EBS_BrkSw_Rq);
  (void)Com_SendSignalGroup(ComConf_ComGroupSignal_Brak_Sta_oRDF2_CANMatrix_F_TX);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_Brak_Sta_sg_oBrak_Sta_oRDF2_CANMatrix_F_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_ARS430_RxSignal_SG_CI_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_CI_sg_oCI_oRDF2_CANMatrix_F_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_CI_oRDF2_CANMatrix_F_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_CI_oYear_o_RDF2_CANMatrix_F_Rx,&(*(&Rte_SG_CI_sg_oCI_oRDF2_CANMatrix_F_Rx)).Year);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_CI_oMonth_o_RDF2_CANMatrix_F_Rx,&(*(&Rte_SG_CI_sg_oCI_oRDF2_CANMatrix_F_Rx)).Month);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_CI_oDate_o_RDF2_CANMatrix_F_Rx,&(*(&Rte_SG_CI_sg_oCI_oRDF2_CANMatrix_F_Rx)).Date);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_CI_oSerial_Num_o_RDF2_CANMatrix_F_Rx,&(*(&Rte_SG_CI_sg_oCI_oRDF2_CANMatrix_F_Rx)).Serial_Num);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_CI_sg_oCI_oRDF2_CANMatrix_F_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_ARS408_RxSignal_SG_RadarState_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_RadarState_sg_oRadarState_oARS408_CANMatrix_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_RadarState_oARS408_CANMatrix_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RadarState_oRadarState_NVMwriteStatus_o_ARS408_CANMatrix_Rx,&(*(&Rte_SG_RadarState_sg_oRadarState_oARS408_CANMatrix_Rx)).RadarState_NVMwriteStatus);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RadarState_oRadarState_NVMReadStatus_o_ARS408_CANMatrix_Rx,&(*(&Rte_SG_RadarState_sg_oRadarState_oARS408_CANMatrix_Rx)).RadarState_NVMReadStatus);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RadarState_oRadarState_MaxDistanceCfg_o_ARS408_CANMatrix_Rx,&(*(&Rte_SG_RadarState_sg_oRadarState_oARS408_CANMatrix_Rx)).RadarState_MaxDistanceCfg);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RadarState_oRadarState_Persistent_Error_o_ARS408_CANMatrix_Rx,&(*(&Rte_SG_RadarState_sg_oRadarState_oARS408_CANMatrix_Rx)).RadarState_Persistent_Error);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RadarState_oRadarState_Interference_o_ARS408_CANMatrix_Rx,&(*(&Rte_SG_RadarState_sg_oRadarState_oARS408_CANMatrix_Rx)).RadarState_Interference);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RadarState_oRadarState_Temperature_Error_o_ARS408_CANMatrix_Rx,&(*(&Rte_SG_RadarState_sg_oRadarState_oARS408_CANMatrix_Rx)).RadarState_Temperature_Error);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RadarState_oRadarState_Temporary_Error_o_ARS408_CANMatrix_Rx,&(*(&Rte_SG_RadarState_sg_oRadarState_oARS408_CANMatrix_Rx)).RadarState_Temporary_Error);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RadarState_oRadarState_Voltage_Error_o_ARS408_CANMatrix_Rx,&(*(&Rte_SG_RadarState_sg_oRadarState_oARS408_CANMatrix_Rx)).RadarState_Voltage_Error);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RadarState_oRadarState_RadarPowerCfg_o_ARS408_CANMatrix_Rx,&(*(&Rte_SG_RadarState_sg_oRadarState_oARS408_CANMatrix_Rx)).RadarState_RadarPowerCfg);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RadarState_oRadarState_SortIndex_o_ARS408_CANMatrix_Rx,&(*(&Rte_SG_RadarState_sg_oRadarState_oARS408_CANMatrix_Rx)).RadarState_SortIndex);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RadarState_oRadarState_SensorID_o_ARS408_CANMatrix_Rx,&(*(&Rte_SG_RadarState_sg_oRadarState_oARS408_CANMatrix_Rx)).RadarState_SensorID);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RadarState_oRadarState_MotionRxState_o_ARS408_CANMatrix_Rx,&(*(&Rte_SG_RadarState_sg_oRadarState_oARS408_CANMatrix_Rx)).RadarState_MotionRxState);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RadarState_oRadarState_SendExtInfoCfg_o_ARS408_CANMatrix_Rx,&(*(&Rte_SG_RadarState_sg_oRadarState_oARS408_CANMatrix_Rx)).RadarState_SendExtInfoCfg);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RadarState_oRadarState_SendQualityCfg_o_ARS408_CANMatrix_Rx,&(*(&Rte_SG_RadarState_sg_oRadarState_oARS408_CANMatrix_Rx)).RadarState_SendQualityCfg);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RadarState_oRadarState_OutputTypeCfg_o_ARS408_CANMatrix_Rx,&(*(&Rte_SG_RadarState_sg_oRadarState_oARS408_CANMatrix_Rx)).RadarState_OutputTypeCfg);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RadarState_oRadarState_CtrlRelayCfg_o_ARS408_CANMatrix_Rx,&(*(&Rte_SG_RadarState_sg_oRadarState_oARS408_CANMatrix_Rx)).RadarState_CtrlRelayCfg);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_RadarState_oRadarState_RCS_Threshold_o_ARS408_CANMatrix_Rx,&(*(&Rte_SG_RadarState_sg_oRadarState_oARS408_CANMatrix_Rx)).RadarState_RCS_Threshold);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_RadarState_sg_oRadarState_oARS408_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_ARS408_RxSignal_SG_VersionID_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_VersionID_sg_oVersionID_oARS408_CANMatrix_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_VersionID_oARS408_CANMatrix_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_VersionID_oVersion_MajorRelease_o_ARS408_CANMatrix_Rx,&(*(&Rte_SG_VersionID_sg_oVersionID_oARS408_CANMatrix_Rx)).Version_MajorRelease);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_VersionID_oVersion_MinorRelease_o_ARS408_CANMatrix_Rx,&(*(&Rte_SG_VersionID_sg_oVersionID_oARS408_CANMatrix_Rx)).Version_MinorRelease);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_VersionID_oVersion_PatchLevel_o_ARS408_CANMatrix_Rx,&(*(&Rte_SG_VersionID_sg_oVersionID_oARS408_CANMatrix_Rx)).Version_PatchLevel);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_VersionID_oVersion_ExtendedRange_o_ARS408_CANMatrix_Rx,&(*(&Rte_SG_VersionID_sg_oVersionID_oARS408_CANMatrix_Rx)).Version_ExtendedRange);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_VersionID_oVersion_CountryCode_o_ARS408_CANMatrix_Rx,&(*(&Rte_SG_VersionID_sg_oVersionID_oARS408_CANMatrix_Rx)).Version_CountryCode);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_VersionID_sg_oVersionID_oARS408_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_Callout_ARS408_RxSignal_SG_Obj_0_Status_sg(SG_Obj_0_Status_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_Obj_0_Status_oARS408_CANMatrix_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_0_Status_oObj_NofObjects_o_ARS408_CANMatrix_Rx,&(*(data)).Obj_NofObjects);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_0_Status_oObj_MeasCounter_o_ARS408_CANMatrix_Rx,&(*(data)).Obj_MeasCounter);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_0_Status_oObj_InterfaceVersion_o_ARS408_CANMatrix_Rx,&(*(data)).Obj_InterfaceVersion);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Receive_ComProxy_ARS408_RxSignal_SG_Obj_0_Status_sg(void)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_Obj_0_Status_sg_oObj_0_Status_oARS408_CANMatrix_Rx);
  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_Obj_0_Status_oARS408_CANMatrix_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_0_Status_oObj_NofObjects_o_ARS408_CANMatrix_Rx,&(*(&Rte_SG_Obj_0_Status_sg_oObj_0_Status_oARS408_CANMatrix_Rx)).Obj_NofObjects);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_0_Status_oObj_MeasCounter_o_ARS408_CANMatrix_Rx,&(*(&Rte_SG_Obj_0_Status_sg_oObj_0_Status_oARS408_CANMatrix_Rx)).Obj_MeasCounter);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_0_Status_oObj_InterfaceVersion_o_ARS408_CANMatrix_Rx,&(*(&Rte_SG_Obj_0_Status_sg_oObj_0_Status_oARS408_CANMatrix_Rx)).Obj_InterfaceVersion);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_Obj_0_Status_sg_oObj_0_Status_oARS408_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_Callout_ARS408_RxSignal_SG_Obj_1_General_sg(SG_Obj_1_General_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_Obj_1_General_oARS408_CANMatrix_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_1_General_oObj_ID_o_ARS408_CANMatrix_Rx,&(*(data)).Obj_ID);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_1_General_oObj_DistLong_o_ARS408_CANMatrix_Rx,&(*(data)).Obj_DistLong);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_1_General_oObj_DistLat_o_ARS408_CANMatrix_Rx,&(*(data)).Obj_DistLat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_1_General_oObj_VrelLong_o_ARS408_CANMatrix_Rx,&(*(data)).Obj_VrelLong);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_1_General_oObj_VrelLat_o_ARS408_CANMatrix_Rx,&(*(data)).Obj_VrelLat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_1_General_oObj_DynProp_o_ARS408_CANMatrix_Rx,&(*(data)).Obj_DynProp);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_1_General_oObj_RCS_o_ARS408_CANMatrix_Rx,&(*(data)).Obj_RCS);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_Callout_ARS408_RxSignal_SG_Obj_2_Quality_sg(SG_Obj_2_Quality_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_Obj_2_Quality_oARS408_CANMatrix_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_2_Quality_oObj_ID_o_ARS408_CANMatrix_Rx,&(*(data)).Obj_ID);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_2_Quality_oObj_DistLong_rms_o_ARS408_CANMatrix_Rx,&(*(data)).Obj_DistLong_rms);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_2_Quality_oObj_DistLat_rms_o_ARS408_CANMatrix_Rx,&(*(data)).Obj_DistLat_rms);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_2_Quality_oObj_VrelLong_rms_o_ARS408_CANMatrix_Rx,&(*(data)).Obj_VrelLong_rms);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_2_Quality_oObj_VrelLat_rms_o_ARS408_CANMatrix_Rx,&(*(data)).Obj_VrelLat_rms);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_2_Quality_oObj_ArelLong_rms_o_ARS408_CANMatrix_Rx,&(*(data)).Obj_ArelLong_rms);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_2_Quality_oObj_ArelLat_rms_o_ARS408_CANMatrix_Rx,&(*(data)).Obj_ArelLat_rms);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_2_Quality_oObj_Orientation_rms_o_ARS408_CANMatrix_Rx,&(*(data)).Obj_Orientation_rms);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_2_Quality_oObj_ProbOfExist_o_ARS408_CANMatrix_Rx,&(*(data)).Obj_ProbOfExist);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_2_Quality_oObj_MeasState_o_ARS408_CANMatrix_Rx,&(*(data)).Obj_MeasState);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_Callout_ARS408_RxSignal_SG_Obj_3_Extended_sg(SG_Obj_3_Extended_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_Obj_3_Extended_oARS408_CANMatrix_RX);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_3_Extended_oObj_ID_o_ARS408_CANMatrix_Rx,&(*(data)).Obj_ID);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_3_Extended_oObj_ArelLong_o_ARS408_CANMatrix_Rx,&(*(data)).Obj_ArelLong);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_3_Extended_oObj_ArelLat_o_ARS408_CANMatrix_Rx,&(*(data)).Obj_ArelLat);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_3_Extended_oObj_Class_o_ARS408_CANMatrix_Rx,&(*(data)).Obj_Class);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_3_Extended_oObj_OrientationAngle_o_ARS408_CANMatrix_Rx,&(*(data)).Obj_OrientationAngle);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_3_Extended_oObj_Length_o_ARS408_CANMatrix_Rx,&(*(data)).Obj_Length);
  ret |= Com_ReceiveSignal(ComConf_ComSignal_Obj_3_Extended_oObj_Width_o_ARS408_CANMatrix_Rx,&(*(data)).Obj_Width);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DevCan_DEV_TxSignal_SG_TaskInfo_sg(SG_TaskInfo_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_TaskInfo_oAverExcnt_o_DEVCAN_CANMatrix_Tx,&(*(data)).AverExcnt);
  ret |= Com_SendSignal(ComConf_ComSignal_TaskInfo_oAverExtime_o_DEVCAN_CANMatrix_Tx,&(*(data)).AverExtime);
  ret |= Com_SendSignal(ComConf_ComSignal_TaskInfo_oAverPercnt_o_DEVCAN_CANMatrix_Tx,&(*(data)).AverPercnt);
  ret |= Com_SendSignal(ComConf_ComSignal_TaskInfo_oAverPertime_o_DEVCAN_CANMatrix_Tx,&(*(data)).AverPertime);
  ret |= Com_SendSignal(ComConf_ComSignal_TaskInfo_oCoreindex_o_DEVCAN_CANMatrix_Tx,&(*(data)).Coreindex);
  ret |= Com_SendSignal(ComConf_ComSignal_TaskInfo_oExcount_o_DEVCAN_CANMatrix_Tx,&(*(data)).Excount);
  ret |= Com_SendSignal(ComConf_ComSignal_TaskInfo_oExmax_o_DEVCAN_CANMatrix_Tx,&(*(data)).Exmax);
  ret |= Com_SendSignal(ComConf_ComSignal_TaskInfo_oExmin_o_DEVCAN_CANMatrix_Tx,&(*(data)).Exmin);
  ret |= Com_SendSignal(ComConf_ComSignal_TaskInfo_oExtime_o_DEVCAN_CANMatrix_Tx,&(*(data)).Extime);
  ret |= Com_SendSignal(ComConf_ComSignal_TaskInfo_oPercount_o_DEVCAN_CANMatrix_Tx,&(*(data)).Percount);
  ret |= Com_SendSignal(ComConf_ComSignal_TaskInfo_oPerFtEn_o_DEVCAN_CANMatrix_Tx,&(*(data)).PerFtEn);
  ret |= Com_SendSignal(ComConf_ComSignal_TaskInfo_oPermax_o_DEVCAN_CANMatrix_Tx,&(*(data)).Permax);
  ret |= Com_SendSignal(ComConf_ComSignal_TaskInfo_oPermin_o_DEVCAN_CANMatrix_Tx,&(*(data)).Permin);
  ret |= Com_SendSignal(ComConf_ComSignal_TaskInfo_oPertime_o_DEVCAN_CANMatrix_Tx,&(*(data)).Pertime);
  ret |= Com_SendSignal(ComConf_ComSignal_TaskInfo_oRunableindex_o_DEVCAN_CANMatrix_Tx,&(*(data)).Runableindex);
  ret |= Com_SendSignal(ComConf_ComSignal_TaskInfo_oSumExtime_o_DEVCAN_CANMatrix_Tx,&(*(data)).SumExtime);
  ret |= Com_SendSignal(ComConf_ComSignal_TaskInfo_oSumPertime_o_DEVCAN_CANMatrix_Tx,&(*(data)).SumPertime);
  ret |= Com_SendSignal(ComConf_ComSignal_TaskInfo_oTaskindex_o_DEVCAN_CANMatrix_Tx,&(*(data)).Taskindex);
  ret |= Com_SendSignal(ComConf_ComSignal_TaskInfo_oTmFlag_o_DEVCAN_CANMatrix_Tx,&(*(data)).TmFlag);
  (void)Com_SendSignalGroup(ComConf_ComGroupSignal_TaskInfo_oDEVCAN_CANMatrix_TX);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DevCan_DEV_TxSignal_SG_CpuInfo_sg(SG_CpuInfo_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_CpuInfo_oCpuLoad_Core0_o_DEVCAN_CANMatrix_Tx,&(*(data)).CpuLoad_Core0);
  ret |= Com_SendSignal(ComConf_ComSignal_CpuInfo_oCpuload_Core0_Max_o_DEVCAN_CANMatrix_Tx,&(*(data)).Cpuload_Core0_Max);
  ret |= Com_SendSignal(ComConf_ComSignal_CpuInfo_oCpuload_Core0_Min_o_DEVCAN_CANMatrix_Tx,&(*(data)).Cpuload_Core0_Min);
  ret |= Com_SendSignal(ComConf_ComSignal_CpuInfo_oCpuLoad_Core1_o_DEVCAN_CANMatrix_Tx,&(*(data)).CpuLoad_Core1);
  ret |= Com_SendSignal(ComConf_ComSignal_CpuInfo_oCpuload_Core1_Max_o_DEVCAN_CANMatrix_Tx,&(*(data)).Cpuload_Core1_Max);
  ret |= Com_SendSignal(ComConf_ComSignal_CpuInfo_oCpuload_Core1_Min_o_DEVCAN_CANMatrix_Tx,&(*(data)).Cpuload_Core1_Min);
  ret |= Com_SendSignal(ComConf_ComSignal_CpuInfo_oCpuLoad_Core2_o_DEVCAN_CANMatrix_Tx,&(*(data)).CpuLoad_Core2);
  ret |= Com_SendSignal(ComConf_ComSignal_CpuInfo_oCpuload_Core2_Max_o_DEVCAN_CANMatrix_Tx,&(*(data)).Cpuload_Core2_Max);
  ret |= Com_SendSignal(ComConf_ComSignal_CpuInfo_oCpuload_Core2_Min_o_DEVCAN_CANMatrix_Tx,&(*(data)).Cpuload_Core2_Min);
  ret |= Com_SendSignal(ComConf_ComSignal_CpuInfo_oCpuLoad_Core3_o_DEVCAN_CANMatrix_Tx,&(*(data)).CpuLoad_Core3);
  ret |= Com_SendSignal(ComConf_ComSignal_CpuInfo_oCpuload_Core3_Max_o_DEVCAN_CANMatrix_Tx,&(*(data)).Cpuload_Core3_Max);
  ret |= Com_SendSignal(ComConf_ComSignal_CpuInfo_oCpuload_Core3_Min_o_DEVCAN_CANMatrix_Tx,&(*(data)).Cpuload_Core3_Min);
  ret |= Com_SendSignal(ComConf_ComSignal_CpuInfo_oCpuLoad_Core4_o_DEVCAN_CANMatrix_Tx,&(*(data)).CpuLoad_Core4);
  ret |= Com_SendSignal(ComConf_ComSignal_CpuInfo_oCpuload_Core4_Max_o_DEVCAN_CANMatrix_Tx,&(*(data)).Cpuload_Core4_Max);
  ret |= Com_SendSignal(ComConf_ComSignal_CpuInfo_oCpuload_Core4_Min_o_DEVCAN_CANMatrix_Tx,&(*(data)).Cpuload_Core4_Min);
  ret |= Com_SendSignal(ComConf_ComSignal_CpuInfo_oCpuLoad_Core5_o_DEVCAN_CANMatrix_Tx,&(*(data)).CpuLoad_Core5);
  ret |= Com_SendSignal(ComConf_ComSignal_CpuInfo_oCpuload_Core5_Max_o_DEVCAN_CANMatrix_Tx,&(*(data)).Cpuload_Core5_Max);
  ret |= Com_SendSignal(ComConf_ComSignal_CpuInfo_oCpuload_Core5_Min_o_DEVCAN_CANMatrix_Tx,&(*(data)).Cpuload_Core5_Min);
  ret |= Com_SendSignal(ComConf_ComSignal_CpuInfo_oCurrent_Time_o_DEVCAN_CANMatrix_Tx,&(*(data)).Current_Time);
  ret |= Com_SendSignal(ComConf_ComSignal_CpuInfo_oError_Time_o_DEVCAN_CANMatrix_Tx,&(*(data)).Error_Time);
  ret |= Com_SendSignal(ComConf_ComSignal_CpuInfo_oError_Time_CNT_o_DEVCAN_CANMatrix_Tx,&(*(data)).Error_Time_CNT);
  ret |= Com_SendSignal(ComConf_ComSignal_CpuInfo_oVER_Head_o_DEVCAN_CANMatrix_Tx,&(*(data)).VER_Head);
  ret |= Com_SendSignal(ComConf_ComSignal_CpuInfo_oVER_Major_o_DEVCAN_CANMatrix_Tx,&(*(data)).VER_Major);
  ret |= Com_SendSignal(ComConf_ComSignal_CpuInfo_oVER_Revise_o_DEVCAN_CANMatrix_Tx,&(*(data)).VER_Revise);
  ret |= Com_SendSignal(ComConf_ComSignal_CpuInfo_oVER_Sub_o_DEVCAN_CANMatrix_Tx,&(*(data)).VER_Sub);
  (void)Com_SendSignalGroup(ComConf_ComGroupSignal_CpuInfo_oDEVCAN_CANMatrix_TX);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DevCan_DEV_TxSignal_SG_FrameDiagInfo_sg(SG_FrameDiagInfo_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_FrameDiagInfo_oARS430_LoseFrame_o_DEVCAN_CANMatrix_Tx,&(*(data)).ARS430_LoseFrame);
  ret |= Com_SendSignal(ComConf_ComSignal_FrameDiagInfo_oZIC_LoseFrame_o_DEVCAN_CANMatrix_Tx,&(*(data)).ZIC_LoseFrame);
  ret |= Com_SendSignal(ComConf_ComSignal_FrameDiagInfo_oGNSS_LoseFrame_o_DEVCAN_CANMatrix_Tx,&(*(data)).GNSS_LoseFrame);
  ret |= Com_SendSignal(ComConf_ComSignal_FrameDiagInfo_oCR5TP_RF_LoseFrame_o_DEVCAN_CANMatrix_Tx,&(*(data)).CR5TP_RF_LoseFrame);
  ret |= Com_SendSignal(ComConf_ComSignal_FrameDiagInfo_oCR5TP_LF_LoseFrame_o_DEVCAN_CANMatrix_Tx,&(*(data)).CR5TP_LF_LoseFrame);
  ret |= Com_SendSignal(ComConf_ComSignal_FrameDiagInfo_oARS408_LoseFrame_o_DEVCAN_CANMatrix_Tx,&(*(data)).ARS408_LoseFrame);
  ret |= Com_SendSignal(ComConf_ComSignal_FrameDiagInfo_oARS430_TimeFault_o_DEVCAN_CANMatrix_Tx,&(*(data)).ARS430_TimeFault);
  ret |= Com_SendSignal(ComConf_ComSignal_FrameDiagInfo_oZIC_TimeFault_o_DEVCAN_CANMatrix_Tx,&(*(data)).ZIC_TimeFault);
  ret |= Com_SendSignal(ComConf_ComSignal_FrameDiagInfo_oGNSS_TimeFault_o_DEVCAN_CANMatrix_Tx,&(*(data)).GNSS_TimeFault);
  ret |= Com_SendSignal(ComConf_ComSignal_FrameDiagInfo_oCR5TP_RF_TimeFault_o_DEVCAN_CANMatrix_Tx,&(*(data)).CR5TP_RF_TimeFault);
  ret |= Com_SendSignal(ComConf_ComSignal_FrameDiagInfo_oCR5TP_LF_TimeFault_o_DEVCAN_CANMatrix_Tx,&(*(data)).CR5TP_LF_TimeFault);
  ret |= Com_SendSignal(ComConf_ComSignal_FrameDiagInfo_oARS408_TimeFault_o_DEVCAN_CANMatrix_Tx,&(*(data)).ARS408_TimeFault);
  (void)Com_SendSignalGroup(ComConf_ComGroupSignal_FrameDiagInfo_oDEVCAN_CANMatrix_TX);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_Flag_Arr_CCVS1_oRx_Flag_Arr_CCVS1(Rx_Flag_Type* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Flag_Arr_CCVS1_oRx_Flag_Arr_CCVS1);
  Rte_Rx_Flag_Arr_CCVS1_oRx_Flag_Arr_CCVS1 = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Flag_Arr_CCVS1_oRx_Flag_Arr_CCVS1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_Flag_Arr_EBC1_oRx_Flag_Arr_EBC1(Rx_Flag_Type* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Flag_Arr_EBC1_oRx_Flag_Arr_EBC1);
  Rte_Rx_Flag_Arr_EBC1_oRx_Flag_Arr_EBC1 = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Flag_Arr_EBC1_oRx_Flag_Arr_EBC1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_Flag_Arr_EBC2_oRx_Flag_Arr_EBC2(Rx_Flag_Type* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Flag_Arr_EBC2_oRx_Flag_Arr_EBC2);
  Rte_Rx_Flag_Arr_EBC2_oRx_Flag_Arr_EBC2 = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Flag_Arr_EBC2_oRx_Flag_Arr_EBC2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_Flag_Arr_EEC2_oRx_Flag_Arr_EEC2(Rx_Flag_Type* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Flag_Arr_EEC2_oRx_Flag_Arr_EEC2);
  Rte_Rx_Flag_Arr_EEC2_oRx_Flag_Arr_EEC2 = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Flag_Arr_EEC2_oRx_Flag_Arr_EEC2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_Flag_Arr_EPB1_oRx_Flag_Arr_EPB1(Rx_Flag_Type* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Flag_Arr_EPB1_oRx_Flag_Arr_EPB1);
  Rte_Rx_Flag_Arr_EPB1_oRx_Flag_Arr_EPB1 = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Flag_Arr_EPB1_oRx_Flag_Arr_EPB1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_Flag_Arr_EPS2_oRx_Flag_Arr_EPS2(Rx_Flag_Type* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Flag_Arr_EPS2_oRx_Flag_Arr_EPS2);
  Rte_Rx_Flag_Arr_EPS2_oRx_Flag_Arr_EPS2 = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Flag_Arr_EPS2_oRx_Flag_Arr_EPS2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_Flag_Arr_ETC2_oRx_Flag_Arr_ETC2(Rx_Flag_Type* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Flag_Arr_ETC2_oRx_Flag_Arr_ETC2);
  Rte_Rx_Flag_Arr_ETC2_oRx_Flag_Arr_ETC2 = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Flag_Arr_ETC2_oRx_Flag_Arr_ETC2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_Flag_Arr_LC_oRx_Flag_Arr_LC(Rx_Flag_Type* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Flag_Arr_LC_oRx_Flag_Arr_LC);
  Rte_Rx_Flag_Arr_LC_oRx_Flag_Arr_LC = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Flag_Arr_LC_oRx_Flag_Arr_LC);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_Flag_Arr_MCU1_oRx_Flag_Arr_MCU1(Rx_Flag_Type* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Flag_Arr_MCU1_oRx_Flag_Arr_MCU1);
  Rte_Rx_Flag_Arr_MCU1_oRx_Flag_Arr_MCU1 = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Flag_Arr_MCU1_oRx_Flag_Arr_MCU1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_Flag_Arr_PS1_oRx_Flag_Arr_PS1(Rx_Flag_Type* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Flag_Arr_PS1_oRx_Flag_Arr_PS1);
  Rte_Rx_Flag_Arr_PS1_oRx_Flag_Arr_PS1 = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Flag_Arr_PS1_oRx_Flag_Arr_PS1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_Flag_Arr_VCU_Status_oRx_Flag_Arr_VCU_Status(Rx_Flag_Type* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Flag_Arr_VCU_Status_oRx_Flag_Arr_VCU_Status);
  Rte_Rx_Flag_Arr_VCU_Status_oRx_Flag_Arr_VCU_Status = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Flag_Arr_VCU_Status_oRx_Flag_Arr_VCU_Status);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_Flag_Arr_VDC2_oRx_Flag_Arr_VDC2(Rx_Flag_Type* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Flag_Arr_VDC2_oRx_Flag_Arr_VDC2);
  Rte_Rx_Flag_Arr_VDC2_oRx_Flag_Arr_VDC2 = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Flag_Arr_VDC2_oRx_Flag_Arr_VDC2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_SigStat_Arr_CCVS1_oRx_SigStat_Arr_CCVS1(CCVS1_SigStatusType* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_SigStat_Arr_CCVS1_oRx_SigStat_Arr_CCVS1);
  if(sizeof(CCVS1_SigStatusType) > 200u)
  {
    (void)memcpy(&Rte_Rx_SigStat_Arr_CCVS1_oRx_SigStat_Arr_CCVS1,data,sizeof(CCVS1_SigStatusType));
  }
  else
  {
    Rte_Rx_SigStat_Arr_CCVS1_oRx_SigStat_Arr_CCVS1 = *data;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_SigStat_Arr_CCVS1_oRx_SigStat_Arr_CCVS1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_SigStat_Arr_EBC1_oRx_SigStat_Arr_EBC1(EBC1_SigStatusType* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_SigStat_Arr_EBC1_oRx_SigStat_Arr_EBC1);
  if(sizeof(EBC1_SigStatusType) > 200u)
  {
    (void)memcpy(&Rte_Rx_SigStat_Arr_EBC1_oRx_SigStat_Arr_EBC1,data,sizeof(EBC1_SigStatusType));
  }
  else
  {
    Rte_Rx_SigStat_Arr_EBC1_oRx_SigStat_Arr_EBC1 = *data;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_SigStat_Arr_EBC1_oRx_SigStat_Arr_EBC1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_SigStat_Arr_EBC2_oRx_SigStat_Arr_EBC2(EBC2_SigStatusType* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_SigStat_Arr_EBC2_oRx_SigStat_Arr_EBC2);
  if(sizeof(EBC2_SigStatusType) > 200u)
  {
    (void)memcpy(&Rte_Rx_SigStat_Arr_EBC2_oRx_SigStat_Arr_EBC2,data,sizeof(EBC2_SigStatusType));
  }
  else
  {
    Rte_Rx_SigStat_Arr_EBC2_oRx_SigStat_Arr_EBC2 = *data;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_SigStat_Arr_EBC2_oRx_SigStat_Arr_EBC2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_SigStat_Arr_EEC2_oRx_SigStat_Arr_EEC2(EEC2_SigStatusType* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_SigStat_Arr_EEC2_oRx_SigStat_Arr_EEC2);
  if(sizeof(EEC2_SigStatusType) > 200u)
  {
    (void)memcpy(&Rte_Rx_SigStat_Arr_EEC2_oRx_SigStat_Arr_EEC2,data,sizeof(EEC2_SigStatusType));
  }
  else
  {
    Rte_Rx_SigStat_Arr_EEC2_oRx_SigStat_Arr_EEC2 = *data;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_SigStat_Arr_EEC2_oRx_SigStat_Arr_EEC2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_SigStat_Arr_EPB1_oRx_SigStat_Arr_EPB1(EPB1_SigStatusType* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_SigStat_Arr_EPB1_oRx_SigStat_Arr_EPB1);
  if(sizeof(EPB1_SigStatusType) > 200u)
  {
    (void)memcpy(&Rte_Rx_SigStat_Arr_EPB1_oRx_SigStat_Arr_EPB1,data,sizeof(EPB1_SigStatusType));
  }
  else
  {
    Rte_Rx_SigStat_Arr_EPB1_oRx_SigStat_Arr_EPB1 = *data;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_SigStat_Arr_EPB1_oRx_SigStat_Arr_EPB1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_SigStat_Arr_EPS2_oRx_SigStat_Arr_EPS2(EPS2_SigStatusType* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_SigStat_Arr_EPS2_oRx_SigStat_Arr_EPS2);
  if(sizeof(EPS2_SigStatusType) > 200u)
  {
    (void)memcpy(&Rte_Rx_SigStat_Arr_EPS2_oRx_SigStat_Arr_EPS2,data,sizeof(EPS2_SigStatusType));
  }
  else
  {
    Rte_Rx_SigStat_Arr_EPS2_oRx_SigStat_Arr_EPS2 = *data;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_SigStat_Arr_EPS2_oRx_SigStat_Arr_EPS2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_SigStat_Arr_ETC2_oRx_SigStat_Arr_ETC2(ETC2_SigStatusType* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_SigStat_Arr_ETC2_oRx_SigStat_Arr_ETC2);
  if(sizeof(ETC2_SigStatusType) > 200u)
  {
    (void)memcpy(&Rte_Rx_SigStat_Arr_ETC2_oRx_SigStat_Arr_ETC2,data,sizeof(ETC2_SigStatusType));
  }
  else
  {
    Rte_Rx_SigStat_Arr_ETC2_oRx_SigStat_Arr_ETC2 = *data;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_SigStat_Arr_ETC2_oRx_SigStat_Arr_ETC2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_SigStat_Arr_LC_oRx_SigStat_Arr_LC(LC_SigStatusType* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_SigStat_Arr_LC_oRx_SigStat_Arr_LC);
  if(sizeof(LC_SigStatusType) > 200u)
  {
    (void)memcpy(&Rte_Rx_SigStat_Arr_LC_oRx_SigStat_Arr_LC,data,sizeof(LC_SigStatusType));
  }
  else
  {
    Rte_Rx_SigStat_Arr_LC_oRx_SigStat_Arr_LC = *data;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_SigStat_Arr_LC_oRx_SigStat_Arr_LC);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_SigStat_Arr_MCU1_oRx_SigStat_Arr_MCU1(MCU1_SigStatusType* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_SigStat_Arr_MCU1_oRx_SigStat_Arr_MCU1);
  if(sizeof(MCU1_SigStatusType) > 200u)
  {
    (void)memcpy(&Rte_Rx_SigStat_Arr_MCU1_oRx_SigStat_Arr_MCU1,data,sizeof(MCU1_SigStatusType));
  }
  else
  {
    Rte_Rx_SigStat_Arr_MCU1_oRx_SigStat_Arr_MCU1 = *data;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_SigStat_Arr_MCU1_oRx_SigStat_Arr_MCU1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_SigStat_Arr_PS1_oRx_SigStat_Arr_PS1(PS1_SigStatusType* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_SigStat_Arr_PS1_oRx_SigStat_Arr_PS1);
  if(sizeof(PS1_SigStatusType) > 200u)
  {
    (void)memcpy(&Rte_Rx_SigStat_Arr_PS1_oRx_SigStat_Arr_PS1,data,sizeof(PS1_SigStatusType));
  }
  else
  {
    Rte_Rx_SigStat_Arr_PS1_oRx_SigStat_Arr_PS1 = *data;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_SigStat_Arr_PS1_oRx_SigStat_Arr_PS1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_SigStat_Arr_VCU_Status_oRx_SigStat_Arr_VCU_Status(VCU_Status_SigStatusType* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_SigStat_Arr_VCU_Status_oRx_SigStat_Arr_VCU_Status);
  if(sizeof(VCU_Status_SigStatusType) > 200u)
  {
    (void)memcpy(&Rte_Rx_SigStat_Arr_VCU_Status_oRx_SigStat_Arr_VCU_Status,data,sizeof(VCU_Status_SigStatusType));
  }
  else
  {
    Rte_Rx_SigStat_Arr_VCU_Status_oRx_SigStat_Arr_VCU_Status = *data;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_SigStat_Arr_VCU_Status_oRx_SigStat_Arr_VCU_Status);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_SigStat_Arr_VDC2_oRx_SigStat_Arr_VDC2(VDC2_SigStatusType* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_SigStat_Arr_VDC2_oRx_SigStat_Arr_VDC2);
  if(sizeof(VDC2_SigStatusType) > 200u)
  {
    (void)memcpy(&Rte_Rx_SigStat_Arr_VDC2_oRx_SigStat_Arr_VDC2,data,sizeof(VDC2_SigStatusType));
  }
  else
  {
    Rte_Rx_SigStat_Arr_VDC2_oRx_SigStat_Arr_VDC2 = *data;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_SigStat_Arr_VDC2_oRx_SigStat_Arr_VDC2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_Time_Arr_CCVS1_oRx_Time_Arr_CCVS1(uint64* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Time_Arr_CCVS1_oRx_Time_Arr_CCVS1);
  Rte_Rx_Time_Arr_CCVS1_oRx_Time_Arr_CCVS1 = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Time_Arr_CCVS1_oRx_Time_Arr_CCVS1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_Time_Arr_EBC1_oRx_Time_Arr_EBC1(uint64* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Time_Arr_EBC1_oRx_Time_Arr_EBC1);
  Rte_Rx_Time_Arr_EBC1_oRx_Time_Arr_EBC1 = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Time_Arr_EBC1_oRx_Time_Arr_EBC1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_Time_Arr_EBC2_oRx_Time_Arr_EBC2(uint64* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Time_Arr_EBC2_oRx_Time_Arr_EBC2);
  Rte_Rx_Time_Arr_EBC2_oRx_Time_Arr_EBC2 = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Time_Arr_EBC2_oRx_Time_Arr_EBC2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_Time_Arr_EEC2_oRx_Time_Arr_EEC2(uint64* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Time_Arr_EEC2_oRx_Time_Arr_EEC2);
  Rte_Rx_Time_Arr_EEC2_oRx_Time_Arr_EEC2 = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Time_Arr_EEC2_oRx_Time_Arr_EEC2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_Time_Arr_EPB1_oRx_Time_Arr_EPB1(uint64* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Time_Arr_EPB1_oRx_Time_Arr_EPB1);
  Rte_Rx_Time_Arr_EPB1_oRx_Time_Arr_EPB1 = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Time_Arr_EPB1_oRx_Time_Arr_EPB1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_Time_Arr_EPS2_oRx_Time_Arr_EPS2(uint64* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Time_Arr_EPS2_oRx_Time_Arr_EPS2);
  Rte_Rx_Time_Arr_EPS2_oRx_Time_Arr_EPS2 = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Time_Arr_EPS2_oRx_Time_Arr_EPS2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_Time_Arr_ETC2_oRx_Time_Arr_ETC2(uint64* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Time_Arr_ETC2_oRx_Time_Arr_ETC2);
  Rte_Rx_Time_Arr_ETC2_oRx_Time_Arr_ETC2 = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Time_Arr_ETC2_oRx_Time_Arr_ETC2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_Time_Arr_LC_oRx_Time_Arr_LC(uint64* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Time_Arr_LC_oRx_Time_Arr_LC);
  Rte_Rx_Time_Arr_LC_oRx_Time_Arr_LC = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Time_Arr_LC_oRx_Time_Arr_LC);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_Time_Arr_MCU1_oRx_Time_Arr_MCU1(uint64* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Time_Arr_MCU1_oRx_Time_Arr_MCU1);
  Rte_Rx_Time_Arr_MCU1_oRx_Time_Arr_MCU1 = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Time_Arr_MCU1_oRx_Time_Arr_MCU1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_Time_Arr_PS1_oRx_Time_Arr_PS1(uint64* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Time_Arr_PS1_oRx_Time_Arr_PS1);
  Rte_Rx_Time_Arr_PS1_oRx_Time_Arr_PS1 = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Time_Arr_PS1_oRx_Time_Arr_PS1);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_Time_Arr_VCU_Status_oRx_Time_Arr_VCU_Status(uint64* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Time_Arr_VCU_Status_oRx_Time_Arr_VCU_Status);
  Rte_Rx_Time_Arr_VCU_Status_oRx_Time_Arr_VCU_Status = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Time_Arr_VCU_Status_oRx_Time_Arr_VCU_Status);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_Time_Arr_VDC2_oRx_Time_Arr_VDC2(uint64* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Time_Arr_VDC2_oRx_Time_Arr_VDC2);
  Rte_Rx_Time_Arr_VDC2_oRx_Time_Arr_VDC2 = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Time_Arr_VDC2_oRx_Time_Arr_VDC2);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_Callout_Rx_Pro_Cnt_LC_oRx_Pro_Cnt_LC(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Pro_Cnt_LC_oRx_Pro_Cnt_LC);
  Rte_Rx_Pro_Cnt_LC_oRx_Pro_Cnt_LC = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Pro_Cnt_LC_oRx_Pro_Cnt_LC);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_Callout_Rx_Cur_Pro_Cnt_LC_oRx_Cur_Pro_Cnt_LC(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Rx_Cur_Pro_Cnt_LC_oRx_Cur_Pro_Cnt_LC);
  *data = Rte_Rx_Cur_Pro_Cnt_LC_oRx_Cur_Pro_Cnt_LC;
  (void)ReleaseSpinlock(Rte_Spinlock_Rx_Cur_Pro_Cnt_LC_oRx_Cur_Pro_Cnt_LC);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NV_SWC_DiagHandler_SecurityAttemptCounter_MirrorBlock_oSecurityAttemptCounter_MirrorBlock(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  *data = Rte_SecurityAttemptCounter_MirrorBlock_oSecurityAttemptCounter_MirrorBlock;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NV_SWC_DiagHandler_SecurityAttemptCounter_MirrorBlock_oSecurityAttemptCounter_MirrorBlock(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_SecurityAttemptCounter_MirrorBlock_oSecurityAttemptCounter_MirrorBlock = *data;

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NV_SWC_DiagHandler_ConfigurationInformation_MirrorBlock_oConfigurationInformation_MirrorBlock(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)memcpy(data,Rte_ConfigurationInformation_MirrorBlock_oConfigurationInformation_MirrorBlock,sizeof(rt_Array_uint8_16));

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NV_SWC_DiagHandler_ConfigurationInformation_MirrorBlock_oConfigurationInformation_MirrorBlock(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)memcpy(Rte_ConfigurationInformation_MirrorBlock_oConfigurationInformation_MirrorBlock,data,sizeof(rt_Array_uint8_16));

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NV_SWC_DiagHandler_ECUInstallationDate_MirrorBlock_oECUInstallationDate_MirrorBlock(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)memcpy(data,Rte_ECUInstallationDate_MirrorBlock_oECUInstallationDate_MirrorBlock,sizeof(rt_Array_uint8_4));

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NV_SWC_DiagHandler_ECUInstallationDate_MirrorBlock_oECUInstallationDate_MirrorBlock(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)memcpy(Rte_ECUInstallationDate_MirrorBlock_oECUInstallationDate_MirrorBlock,data,sizeof(rt_Array_uint8_4));

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NV_SWC_DiagHandler_ProgrammingDate_MirrorBlock_oProgrammingDate_MirrorBlock(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)memcpy(data,Rte_ProgrammingDate_MirrorBlock_oProgrammingDate_MirrorBlock,sizeof(rt_Array_uint8_4));

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NV_SWC_DiagHandler_ProgrammingDate_MirrorBlock_oProgrammingDate_MirrorBlock(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)memcpy(Rte_ProgrammingDate_MirrorBlock_oProgrammingDate_MirrorBlock,data,sizeof(rt_Array_uint8_4));

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NV_SWC_DiagHandler_Reserved_1_MirrorBlock_oReserved_1_MirrorBlock(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)memcpy(data,Rte_Reserved_1_MirrorBlock_oReserved_1_MirrorBlock,sizeof(rt_Array_uint8_16));

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NV_SWC_DiagHandler_Reserved_1_MirrorBlock_oReserved_1_MirrorBlock(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)memcpy(Rte_Reserved_1_MirrorBlock_oReserved_1_MirrorBlock,data,sizeof(rt_Array_uint8_16));

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NV_SWC_DiagHandler_TesterSeriesNumber_MirrorBlock_oTesterSeriesNumber_MirrorBlock(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)memcpy(data,Rte_TesterSeriesNumber_MirrorBlock_oTesterSeriesNumber_MirrorBlock,sizeof(rt_Array_uint8_10));

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NV_SWC_DiagHandler_TesterSeriesNumber_MirrorBlock_oTesterSeriesNumber_MirrorBlock(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)memcpy(Rte_TesterSeriesNumber_MirrorBlock_oTesterSeriesNumber_MirrorBlock,data,sizeof(rt_Array_uint8_10));

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NV_SWC_DiagHandler_VIN_MirrorBlock_oVIN_MirrorBlock(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)memcpy(data,Rte_VIN_MirrorBlock_oVIN_MirrorBlock,sizeof(rt_Array_uint8_17));

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NV_SWC_DiagHandler_VIN_MirrorBlock_oVIN_MirrorBlock(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)memcpy(Rte_VIN_MirrorBlock_oVIN_MirrorBlock,data,sizeof(rt_Array_uint8_17));

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_NV_SWC_DiagHandler_AdminData_MirrorBlock_oAdminData_MirrorBlock(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)memcpy(data,Rte_AdminData_MirrorBlock_oAdminData_MirrorBlock,sizeof(rt_Array_uint8_100));

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_NV_SWC_DiagHandler_AdminData_MirrorBlock_oAdminData_MirrorBlock(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)memcpy(Rte_AdminData_MirrorBlock_oAdminData_MirrorBlock,data,sizeof(rt_Array_uint8_100));

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_Callout_Core0TimeStamp_oCore0TimeStamp(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Core0TimeStamp_oCore0TimeStamp);
  (void)memcpy(data,Rte_Core0TimeStamp_oCore0TimeStamp,sizeof(rt_Array_uint8_12));
  (void)ReleaseSpinlock(Rte_Spinlock_Core0TimeStamp_oCore0TimeStamp);
  Rte_EnableOSInterrupts();

  return ret;
}
/**********************************************************************************************************************
 * Task:     Bsw_QM_Event_Task_Core0
 * Priority: 170
 * Schedule: FULL
 *********************************************************************************************************************/
 TASK(Bsw_Init_Task_Core0)
 {
    Core[0][0]++;
    Tm_Init();
    Tm_Start(0); 
    NvProxy_Init();
    EMR_Init();
    EcuM_StartupTwo();
    while ((((volatile uint8)Rte_InitState_1) != RTE_STATE_INIT)||
          (((volatile uint8)Rte_InitState_2) != RTE_STATE_INIT)||
          (((volatile uint8)Rte_InitState_3) != RTE_STATE_INIT)||
          (((volatile uint8)Rte_InitState_4) != RTE_STATE_INIT)||
          (((volatile uint8)Rte_InitState_5) != RTE_STATE_INIT))
    {

    }   
    Tm_Stop(0);    
    TerminateTask();
 }

/**********************************************************************************************************************
 * Task:     Bsw_QM_Event_Task_Core0
 * Priority: 170
 * Schedul