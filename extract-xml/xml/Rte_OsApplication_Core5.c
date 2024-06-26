/**
 * ********************************************************************************************************************
 * @file Rte_OsApplication_Core5.c
 * @brief Rte Interface for OsApplication_Core5
 * @author zhito 
 * @version 1.0.0
 * @date 2023-12-11 13:21:55
 * @copyright Copyright (c) Zhito Co., Ltd. 2020-2035. All rights reserved.
 * ********************************************************************************************************************
 */
#include "shared.h"
#include "McalLib.h"
#include "Rte_Type.h"


VAR(SG_ADU_Cmd_AECS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_ADU_Cmd_AECS_sg_oADU_Cmd_AECS_oGNSSCooling_CANMatrix_Tx = {
  0U,0U,0U,0U,0U,0U,0U
};

VAR(SG_ACS_Calibration_ADU_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_ACS_Calibration_ADU_sg_oACS_Calibration_ADU_oGNSSCooling_CANMatrix_Tx = {
  0U,0U,0U,0U,0U,0U,0U,0U
};

VAR(SG_SCA_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_SCA_sg_oSCA_oRDF2_CANMatrix_F_Tx = {
  0U,0U,0U,0U,0U
};

VAR(SG_HRW_FR_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_HRW_FR_sg_oHRW_FR_oRDF2_CANMatrix_F_Tx = {
  0U,0U,0U,0U
};

VAR(SG_HRW_RE_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_HRW_RE_sg_oHRW_RE_oRDF2_CANMatrix_F_Tx = {
  0U,0U,0U,0U
};

VAR(SG_BS_E7_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_BS_E7_sg_oBS_E7_oRDF2_CANMatrix_F_Tx = {
  0U,0U,0U,0U
};

VAR(SG_Brak_Sta_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_Brak_Sta_sg_oBrak_Sta_oRDF2_CANMatrix_F_Tx = {
  0U,0U,0U,0U,0U,0U
};

VAR(rt_Array_uint8_6876, RTE_VAR_INIT_NOCACHE) Rte_ARS408_Info_ETH_oARS408_Info_ETH = {0u};

VAR(boolean, RTE_VAR_INIT_NOCACHE) Rte_ARS408_ETH_Tx_Flag_oARS408_ETH_Tx_Flag = FALSE;

VAR(rt_Array_uint8_5192, RTE_VAR_INIT_NOCACHE) Rte_ARS430_Info_ETH_oARS430_Info_ETH = {0u};

VAR(boolean, RTE_VAR_INIT_NOCACHE) Rte_ARS430_ETH_Tx_Flag_oARS430_ETH_Tx_Flag = FALSE;
extern uint8_t Core[6][10];
VAR(rt_Array_uint8_224, RTE_VAR_INIT_NOCACHE) Rte_GNSS_Info_ETH_oGNSS_Info_ETH = {0u};

VAR(boolean, RTE_VAR_INIT_NOCACHE) Rte_GNSS_ETH_Tx_Flag_oGNSS_ETH_Tx_Flag = FALSE;

#if (defined(__TASKING__))
#define OS_CORE6_START_SEC_CODE
#include "Os_MemMap.h"
#endif

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_J6L_ADUCAN_RxSignal_SG_VDC2_sg(SG_VDC2_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_VDC2_sg_oVDC2_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_VDC2_sg_oVDC2_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_VDC2_sg_oVDC2_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_J6L_ADUCAN_RxSignal_SG_BCU_sg(SG_BCU_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_BCU_sg_oBCU_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_BCU_sg_oBCU_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_BCU_sg_oBCU_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_J6L_ADUCAN_RxSignal_SG_HRW_sg(SG_HRW_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_HRW_sg_oHRW_oJ6L_ADUCAN_Rx);
  *(data) = Rte_SG_HRW_sg_oHRW_oJ6L_ADUCAN_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_HRW_sg_oHRW_oJ6L_ADUCAN_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_GNSS_TxSignal_SG_ADU_Cmd_AECS_sg(SG_ADU_Cmd_AECS_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_ADU_Cmd_AECS_sg_oADU_Cmd_AECS_oGNSSCooling_CANMatrix_Tx);
  Rte_SG_ADU_Cmd_AECS_sg_oADU_Cmd_AECS_oGNSSCooling_CANMatrix_Tx = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_ADU_Cmd_AECS_sg_oADU_Cmd_AECS_oGNSSCooling_CANMatrix_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_GNSS_TxSignal_SG_ACS_Calibration_ADU_sg(SG_ACS_Calibration_ADU_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_ACS_Calibration_ADU_sg_oACS_Calibration_ADU_oGNSSCooling_CANMatrix_Tx);
  Rte_SG_ACS_Calibration_ADU_sg_oACS_Calibration_ADU_oGNSSCooling_CANMatrix_Tx = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_ACS_Calibration_ADU_sg_oACS_Calibration_ADU_oGNSSCooling_CANMatrix_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_GNSS_RxSignal_SG_Time_sg(SG_Time_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_Time_sg_oTime_oGNSSCooling_CANMatrix_Rx);
  *(data) = Rte_SG_Time_sg_oTime_oGNSSCooling_CANMatrix_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_Time_sg_oTime_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_GNSS_RxSignal_SG_Ang_Rate_Raw_IMU_sg(SG_Ang_Rate_Raw_IMU_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_Ang_Rate_Raw_IMU_sg_oAng_Rate_Raw_IMU_oGNSSCooling_CANMatrix_Rx);
  *(data) = Rte_SG_Ang_Rate_Raw_IMU_sg_oAng_Rate_Raw_IMU_oGNSSCooling_CANMatrix_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_Ang_Rate_Raw_IMU_sg_oAng_Rate_Raw_IMU_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_GNSS_RxSignal_SG_Accel_IMU_Raw_sg(SG_Accel_IMU_Raw_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_Accel_IMU_Raw_sg_oAccel_IMU_Raw_oGNSSCooling_CANMatrix_Rx);
  *(data) = Rte_SG_Accel_IMU_Raw_sg_oAccel_IMU_Raw_oGNSSCooling_CANMatrix_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_Accel_IMU_Raw_sg_oAccel_IMU_Raw_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_GNSS_RxSignal_SG_InsStatus_sg(SG_InsStatus_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_InsStatus_sg_oInsStatus_oGNSSCooling_CANMatrix_Rx);
  *(data) = Rte_SG_InsStatus_sg_oInsStatus_oGNSSCooling_CANMatrix_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_InsStatus_sg_oInsStatus_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_GNSS_RxSignal_SG_LatitudeLongitude_sg(SG_LatitudeLongitude_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_LatitudeLongitude_sg_oLatitudeLongitude_oGNSSCooling_CANMatrix_Rx);
  *(data) = Rte_SG_LatitudeLongitude_sg_oLatitudeLongitude_oGNSSCooling_CANMatrix_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_LatitudeLongitude_sg_oLatitudeLongitude_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_GNSS_RxSignal_SG_Altitude_sg(SG_Altitude_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_Altitude_sg_oAltitude_oGNSSCooling_CANMatrix_Rx);
  *(data) = Rte_SG_Altitude_sg_oAltitude_oGNSSCooling_CANMatrix_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_Altitude_sg_oAltitude_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_GNSS_RxSignal_SG_PosSigma_sg(SG_PosSigma_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_PosSigma_sg_oPosSigma_oGNSSCooling_CANMatrix_Rx);
  *(data) = Rte_SG_PosSigma_sg_oPosSigma_oGNSSCooling_CANMatrix_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_PosSigma_sg_oPosSigma_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_GNSS_RxSignal_SG_VelocityLevel_sg(SG_VelocityLevel_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_VelocityLevel_sg_oVelocityLevel_oGNSSCooling_CANMatrix_Rx);
  *(data) = Rte_SG_VelocityLevel_sg_oVelocityLevel_oGNSSCooling_CANMatrix_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_VelocityLevel_sg_oVelocityLevel_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_GNSS_RxSignal_SG_VelocityLevelSigma_sg(SG_VelocityLevelSigma_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_VelocityLevelSigma_sg_oVelocityLevelSigma_oGNSSCooling_CANMatrix_Rx);
  *(data) = Rte_SG_VelocityLevelSigma_sg_oVelocityLevelSigma_oGNSSCooling_CANMatrix_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_VelocityLevelSigma_sg_oVelocityLevelSigma_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_GNSS_RxSignal_SG_Accel_Vehicle_sg(SG_Accel_Vehicle_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_Accel_Vehicle_sg_oAccel_Vehicle_oGNSSCooling_CANMatrix_Rx);
  *(data) = Rte_SG_Accel_Vehicle_sg_oAccel_Vehicle_oGNSSCooling_CANMatrix_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_Accel_Vehicle_sg_oAccel_Vehicle_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_GNSS_RxSignal_SG_HeadingPitchRoll_sg(SG_HeadingPitchRoll_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_HeadingPitchRoll_sg_oHeadingPitchRoll_oGNSSCooling_CANMatrix_Rx);
  *(data) = Rte_SG_HeadingPitchRoll_sg_oHeadingPitchRoll_oGNSSCooling_CANMatrix_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_HeadingPitchRoll_sg_oHeadingPitchRoll_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_GNSS_RxSignal_SG_HeadingPitchRollSigma_sg(SG_HeadingPitchRollSigma_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_HeadingPitchRollSigma_sg_oHeadingPitchRollSigma_oGNSSCooling_CANMatrix_Rx);
  *(data) = Rte_SG_HeadingPitchRollSigma_sg_oHeadingPitchRollSigma_oGNSSCooling_CANMatrix_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_HeadingPitchRollSigma_sg_oHeadingPitchRollSigma_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_GNSS_RxSignal_SG_AngRateVehicle_sg(SG_AngRateVehicle_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_AngRateVehicle_sg_oAngRateVehicle_oGNSSCooling_CANMatrix_Rx);
  *(data) = Rte_SG_AngRateVehicle_sg_oAngRateVehicle_oGNSSCooling_CANMatrix_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_AngRateVehicle_sg_oAngRateVehicle_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_GNSS_RxSignal_SG_Longitude_sg(SG_Longitude_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_Longitude_sg_oLongitude_oGNSSCooling_CANMatrix_Rx);
  *(data) = Rte_SG_Longitude_sg_oLongitude_oGNSSCooling_CANMatrix_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_Longitude_sg_oLongitude_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_GNSS_RxSignal_SG_Latitude_sg(SG_Latitude_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_Latitude_sg_oLatitude_oGNSSCooling_CANMatrix_Rx);
  *(data) = Rte_SG_Latitude_sg_oLatitude_oGNSSCooling_CANMatrix_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_Latitude_sg_oLatitude_oGNSSCooling_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_ARS430_RxSignal_SG_RDF_State_sg(SG_RDF_State_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_RDF_State_sg_oRDF_State_oRDF2_CANMatrix_F_Rx);
  *(data) = Rte_SG_RDF_State_sg_oRDF_State_oRDF2_CANMatrix_F_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_RDF_State_sg_oRDF_State_oRDF2_CANMatrix_F_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_ARS430_TxSignal_SG_SCA_sg(SG_SCA_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_SCA_sg_oSCA_oRDF2_CANMatrix_F_Tx);
  Rte_SG_SCA_sg_oSCA_oRDF2_CANMatrix_F_Tx = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_SCA_sg_oSCA_oRDF2_CANMatrix_F_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_ARS430_TxSignal_SG_HRW_FR_sg(SG_HRW_FR_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_HRW_FR_sg_oHRW_FR_oRDF2_CANMatrix_F_Tx);
  Rte_SG_HRW_FR_sg_oHRW_FR_oRDF2_CANMatrix_F_Tx = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_HRW_FR_sg_oHRW_FR_oRDF2_CANMatrix_F_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_ARS430_TxSignal_SG_HRW_RE_sg(SG_HRW_RE_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_HRW_RE_sg_oHRW_RE_oRDF2_CANMatrix_F_Tx);
  Rte_SG_HRW_RE_sg_oHRW_RE_oRDF2_CANMatrix_F_Tx = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_HRW_RE_sg_oHRW_RE_oRDF2_CANMatrix_F_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_ARS430_TxSignal_SG_BS_E7_sg(SG_BS_E7_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_BS_E7_sg_oBS_E7_oRDF2_CANMatrix_F_Tx);
  Rte_SG_BS_E7_sg_oBS_E7_oRDF2_CANMatrix_F_Tx = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_BS_E7_sg_oBS_E7_oRDF2_CANMatrix_F_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_ARS430_TxSignal_SG_Brak_Sta_sg(SG_Brak_Sta_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_Brak_Sta_sg_oBrak_Sta_oRDF2_CANMatrix_F_Tx);
  Rte_SG_Brak_Sta_sg_oBrak_Sta_oRDF2_CANMatrix_F_Tx = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_SG_Brak_Sta_sg_oBrak_Sta_oRDF2_CANMatrix_F_Tx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_ARS430_RxSignal_SG_CI_sg(SG_CI_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_CI_sg_oCI_oRDF2_CANMatrix_F_Rx);
  *(data) = Rte_SG_CI_sg_oCI_oRDF2_CANMatrix_F_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_CI_sg_oCI_oRDF2_CANMatrix_F_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_ARS408_RxSignal_SG_RadarState_sg(SG_RadarState_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_RadarState_sg_oRadarState_oARS408_CANMatrix_Rx);
  *(data) = Rte_SG_RadarState_sg_oRadarState_oARS408_CANMatrix_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_RadarState_sg_oRadarState_oARS408_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_ARS408_RxSignal_SG_VersionID_sg(SG_VersionID_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_VersionID_sg_oVersionID_oARS408_CANMatrix_Rx);
  *(data) = Rte_SG_VersionID_sg_oVersionID_oARS408_CANMatrix_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_VersionID_sg_oVersionID_oARS408_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_ARS408_RxSignal_SG_Obj_0_Status_sg(SG_Obj_0_Status_sg* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_SG_Obj_0_Status_sg_oObj_0_Status_oARS408_CANMatrix_Rx);
  *(data) = Rte_SG_Obj_0_Status_sg_oObj_0_Status_oARS408_CANMatrix_Rx;
  (void)ReleaseSpinlock(Rte_Spinlock_SG_Obj_0_Status_sg_oObj_0_Status_oARS408_CANMatrix_Rx);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_ARS408_Info_ETH_oARS408_Info_ETH(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_ARS408_Info_ETH_oARS408_Info_ETH);
  (void)memcpy(Rte_ARS408_Info_ETH_oARS408_Info_ETH,data,sizeof(rt_Array_uint8_6876));
  (void)ReleaseSpinlock(Rte_Spinlock_ARS408_Info_ETH_oARS408_Info_ETH);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_ARS408_ETH_Tx_Flag_oARS408_ETH_Tx_Flag(boolean* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_ARS408_ETH_Tx_Flag_oARS408_ETH_Tx_Flag);
  Rte_ARS408_ETH_Tx_Flag_oARS408_ETH_Tx_Flag = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_ARS408_ETH_Tx_Flag_oARS408_ETH_Tx_Flag);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_ARS430_Info_ETH_oARS430_Info_ETH(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_ARS430_Info_ETH_oARS430_Info_ETH);
  (void)memcpy(Rte_ARS430_Info_ETH_oARS430_Info_ETH,data,sizeof(rt_Array_uint8_5192));
  (void)ReleaseSpinlock(Rte_Spinlock_ARS430_Info_ETH_oARS430_Info_ETH);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_ARS430_ETH_Tx_Flag_oARS430_ETH_Tx_Flag(boolean* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_ARS430_ETH_Tx_Flag_oARS430_ETH_Tx_Flag);
  Rte_ARS430_ETH_Tx_Flag_oARS430_ETH_Tx_Flag = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_ARS430_ETH_Tx_Flag_oARS430_ETH_Tx_Flag);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_GNSS_Info_ETH_oGNSS_Info_ETH(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_GNSS_Info_ETH_oGNSS_Info_ETH);
  (void)memcpy(Rte_GNSS_Info_ETH_oGNSS_Info_ETH,data,sizeof(rt_Array_uint8_224));
  (void)ReleaseSpinlock(Rte_Spinlock_GNSS_Info_ETH_oGNSS_Info_ETH);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MSDC_GNSS_ETH_Tx_Flag_oGNSS_ETH_Tx_Flag(boolean* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_GNSS_ETH_Tx_Flag_oGNSS_ETH_Tx_Flag);
  Rte_GNSS_ETH_Tx_Flag_oGNSS_ETH_Tx_Flag = *data;
  (void)ReleaseSpinlock(Rte_Spinlock_GNSS_ETH_Tx_Flag_oGNSS_ETH_Tx_Flag);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDC_Core5TimeStamp_oCore5TimeStamp(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Core5TimeStamp_oCore5TimeStamp);
  (void)memcpy(data,Rte_Core5TimeStamp_oCore5TimeStamp,sizeof(rt_Array_uint8_12));
  (void)ReleaseSpinlock(Rte_Spinlock_Core5TimeStamp_oCore5TimeStamp);
  Rte_EnableOSInterrupts();

  return ret;
}
/**********************************************************************************************************************
 * Task:     Bsw_QM_Event_Task_Core0
 * Priority: 170
 * Schedule: FULL
 *********************************************************************************************************************/
void idle_hook_core5(void);
void idle_hook_core5(void)
{
  idle_hook_body();
}
extern uint8_t Core[6][10];
/**********************************************************************************************************************
 * Task:     Bsw_QM_Event_Task_Core0
 * Priority: 170
 * Schedule: FULL
 *********************************************************************************************************************/
 TASK(Bsw_Init_Task_Core5)
 {
   Core[5][0]++;
   Tm_Start(50);
   MSDC_Init();  
   EcuM_StartupTwo();
   Rte_Start();     
   while (((volatile uint8)Rte_InitState) != RTE_STATE_INIT)
   {

    }
   Tm_Stop(50);
   TerminateTask();
 }
/**********************************************************************************************************************
 * Task:     Bsw_QM_Event_Task_Core0
 * Priority: 170
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Bsw_P1ms_Task_Core5)
{
	Core[5][1]++;
  Tm_Start(51);
  MSDC_MainFunction_1ms();
  Tm_Stop(51);    
  TerminateTask();
}
/**********************************************************************************************************************
 * Task:     Bsw_QM_Event_Task_Core0
 * Priority: 170
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Bsw_P5ms_Task_Core5)
{
	Core[5][2]++;
  Tm_Start(52);
  MSDC_MainFunction_5ms();
  Tm_Stop(52);
  TerminateTask();
}
/**********************************************************************************************************************
 * Task:     Bsw_QM_Event_Task_Core0
 * Priority: 170
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Bsw_P10ms_Task_Core5)
{  
	Core[5][3]++;
  Tm_Start(53);
  EcuM_MainFunction();  
  Tm_Stop(53);
  TerminateTask();
}
/**********************************************************************************************************************
 * Task:     Bsw_QM_Event_Task_Core0
 * Priority: 170
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Bsw_P100ms_Task_Core5)
{
  Core[5][4]++;
  Tm_Start(54);
  Clm_runnable_100ms();
  Tm_Stop(54);
  TerminateTask();
}

#if (defined(__TASKING__))
#define OS_CORE6_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif

