

/**
 * ********************************************************************************************************************
 * @file Rte_Type.h
 * @brief Rte Type define
 * @author zhito 
 * @version 1.0.0
 * @date 2024-07-01 19:40:57
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

# define Rte_TypeDef_ComM_InhibitionStatusType
typedef uint8 ComM_InhibitionStatusType;

# define Rte_TypeDef_ComM_UserHandleType
typedef uint8 ComM_UserHandleType;

# define Rte_TypeDef_Csm_ConfigIdType
typedef uint16 Csm_ConfigIdType;

# define Rte_TypeDef_Dlt_ApplicationIDType
typedef uint32 Dlt_ApplicationIDType;

# define Rte_TypeDef_Dlt_ContextIDType
typedef uint32 Dlt_ContextIDType;

# define Rte_TypeDef_Dlt_MessageOptionsType
typedef uint8 Dlt_MessageOptionsType;

# define Rte_TypeDef_Dlt_SessionIDType
typedef uint32 Dlt_SessionIDType;

# define Rte_TypeDef_EcuM_TimeType
typedef uint32 EcuM_TimeType;

# define Rte_TypeDef_EcuM_UserType
typedef uint8 EcuM_UserType;

# define Rte_TypeDef_FiM_FunctionIdType
typedef uint8 FiM_FunctionIdType;

# define Rte_TypeDef_Serial_Num
typedef uint32 Serial_Num;

# define Rte_TypeDef_TimeInMicrosecondsType
typedef uint32 TimeInMicrosecondsType;

# define Rte_TypeDef_WdgM_CheckpointIdType
typedef uint16 WdgM_CheckpointIdType;

# define Rte_TypeDef_WdgM_ModeType
typedef uint8 WdgM_ModeType;

# define Rte_TypeDef_WdgM_SupervisedEntityIdType
typedef uint16 WdgM_SupervisedEntityIdType;

# define Rte_TypeDef_BswM_ESH_Mode
typedef uint8 BswM_ESH_Mode;

# define Rte_TypeDef_BswM_ESH_RunRequest
typedef uint8 BswM_ESH_RunRequest;

# define Rte_TypeDef_ComM_ModeType
typedef uint8 ComM_ModeType;

# define Rte_TypeDef_Crypto_KeyElementType
typedef uint32 Crypto_KeyElementType;

# define Rte_TypeDef_Crypto_OperationModeType
typedef uint8 Crypto_OperationModeType;

# define Rte_TypeDef_Crypto_VerifyResultType
typedef uint8 Crypto_VerifyResultType;

# define Rte_TypeDef_Csm_ResultType
typedef uint8 Csm_ResultType;

# define Rte_TypeDef_Csm_VerifyResultType
typedef uint8 Csm_VerifyResultType;

# define Rte_TypeDef_Dcm_CommunicationModeType
typedef uint8 Dcm_CommunicationModeType;

# define Rte_TypeDef_Dcm_ConfirmationStatusType
typedef uint8 Dcm_ConfirmationStatusType;

# define Rte_TypeDef_Dcm_ControlDtcSettingType
typedef uint8 Dcm_ControlDtcSettingType;

# define Rte_TypeDef_Dcm_DiagnosticSessionControlType
typedef uint8 Dcm_DiagnosticSessionControlType;

# define Rte_TypeDef_Dcm_EcuResetType
typedef uint8 Dcm_EcuResetType;

# define Rte_TypeDef_Dcm_NegativeResponseCodeType
typedef uint8 Dcm_NegativeResponseCodeType;

# define Rte_TypeDef_Dcm_OpStatusType
typedef uint8 Dcm_OpStatusType;

# define Rte_TypeDef_Dcm_ProtocolType
typedef uint8 Dcm_ProtocolType;

# define Rte_TypeDef_Dcm_RequestKindType
typedef uint8 Dcm_RequestKindType;

# define Rte_TypeDef_Dcm_SecLevelType
typedef uint8 Dcm_SecLevelType;

# define Rte_TypeDef_Dcm_SesCtrlType
typedef uint8 Dcm_SesCtrlType;

# define Rte_TypeDef_Dlt_GlobalStateType
typedef uint8 Dlt_GlobalStateType;

# define Rte_TypeDef_Dlt_MessageLogLevelType
typedef uint8 Dlt_MessageLogLevelType;

# define Rte_TypeDef_EcuM_BootTargetType
typedef uint8 EcuM_BootTargetType;
# define Rte_TypeDef_EcuM_ModeType
typedef uint8 EcuM_ModeType;
# define Rte_TypeDef_EcuM_ShutdownCauseType
typedef uint8 EcuM_ShutdownCauseType;
# define Rte_TypeDef_EcuM_StateType
typedef uint8 EcuM_StateType;

# define Rte_TypeDef_Double
typedef float64 Double;
# define Rte_TypeDef_Float
typedef float32 Float;
# define Rte_TypeDef_SInt16
typedef sint16 SInt16;
# define Rte_TypeDef_SInt32
typedef sint32 SInt32;
# define Rte_TypeDef_SInt8
typedef sint8 SInt8;
# define Rte_TypeDef_UInt16
typedef uint16 UInt16;
# define Rte_TypeDef_UInt32
typedef uint32 UInt32;
# define Rte_TypeDef_UInt8
typedef uint8 UInt8;
# define Rte_TypeDef_ByteDataBuffer
typedef struct
{
  uint16 DataBufferSize;
  uint32 DataBufferPtr;
} ByteDataBuffer;

typedef unsigned int Rte_BitType;
typedef struct
{
  Rte_BitType Rte_ModeSwitchAck_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode_Ack : 1;
  Rte_BitType Rte_ModeSwitchAck_Dcm_DcmControlDtcSetting_DcmControlDtcSetting_Ack : 1;
  Rte_BitType Rte_ModeSwitchAck_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Ack : 1;
  Rte_BitType Rte_ModeSwitchAck_Dcm_DcmEcuReset_DcmEcuReset_Ack : 1;
} Rte_OsApplication_NonTrusted_Core0_AckFlagsType;




# define Rte_TypeDef_J6L_RxBus
typedef struct
{
  float32 ATR_FM_AntiTheftCmdStat;
  float32 ATR_FM_AntiTheftDesireExitMode;
  float32 ATR_FM_AntiTheftEncryIndicatStat;
  float32 ATR_FM_AntiTheftPassword;
  float32 ATS_PS_AntiTheftComponentStat;
  float32 ATS_PS_AntiTheftEncrySeedIndicat;
  float32 ATS_PS_AntiTheftModifyPassword;
  float32 ATS_PS_AntiTheftPasswordValid;
  float32 ATS_PS_AntiTheftRandomNumber;
  float32 BCM_Status_BCMRespStat;
  float32 BCM_Status_BackBrakeLightStat;
  float32 BCM_Status_HornStat;
  float32 BCM_Status_WiperStat;
  float32 BCU_DriverSeatBeltAlert;
  float32 BCU_IgnitionPstn;
  float32 BCU_PassengerSeatBeltAlert;
  float32 BMS1_MsgChecksum;
  float32 BMS1_MsgCounter;
  float32 BMS1_PowerBattChargeReq;
  float32 BMS1_PowerBattChargeStat;
  float32 BMS1_PowerBattCurrent;
  float32 BMS1_PowerBattHeatStat;
  float32 BMS1_PowerBattSOC;
  float32 BMS1_PowerBattSysStat;
  float32 BMS1_PowerBattVolt;
  float32 BMS5_BMSMainNgtvCoilDrvStat;
  float32 BMS5_BattPackHeatCtrlCmdNgtv;
  float32 BMS5_BattPackHeatCtrlCmdPstv;
  float32 BMS5_ChargePlug2ConnectionStat;
  float32 BMS5_ChargePlugConnectionStat;
  float32 BMS5_ChargeRelayStatNgtv;
  float32 BMS5_ChargeRelayStatPstv;
  float32 BMS5_MainNgtvRelayDisconnectReq;
  float32 BMS5_MainNgtvRelayStat;
  float32 BMS5_PowerBattSOH;
  float32 CCVS1_BrakeSwitch;
  float32 CCVS1_ClutchSwitch;
  float32 CCVS1_CruiseCtrlEnbSwitch;
  float32 CCVS1_CruiseCtrlPauseSwitch;
  float32 CCVS1_CruiseCtrlResumeSwitch;
  float32 CCVS1_CruiseCtrlSetSpd;
  float32 CCVS1_CruiseCtrlSetSwitch;
  float32 CCVS1_CruiseCtrlState;
  float32 CCVS1_PBSwitch;
  float32 CCVS1_PTOManagmentState;
  float32 CCVS1_WheelBasedVehSpd;
  float32 CruiseCtrlActive;
  float32 CVW_GrossCombineVehWeight;
  float32 CVW_PoweredVehWeight;
  float32 DC2_LockStatOfDoor1;
  float32 DC2_LockStatOfDoor2;
  float32 DC2_OpenStatOfDoor1;
  float32 DC2_OpenStatOfDoor2;
  float32 DM1_ABS_AmberWarningLamp;
  float32 DM1_ABS_FMI;
  float32 DM1_ABS_MalfunctionIndicatorLamp;
  float32 DM1_ABS_OccurrenceCount;
  float32 DM1_ABS_ProtectLamp;
  float32 DM1_ABS_RedStopLamp;
  float32 DM1_ABS_SPN3MmostSignificantBit;
  float32 DM1_ABS_SPN8_LeastSignificantBit;
  float32 DM1_ABS_SPNConversionMethod;
  float32 DM1_ABS_SPN_secondByteOfSPN;
  float32 DM1_APCU_AmberWarningLamp;
  float32 DM1_APCU_FMI;
  float32 DM1_APCU_OccurrenceCount;
  float32 DM1_APCU_RedStopLamp;
  float32 DM1_APCU_SAELamp_Reserved;
  float32 DM1_APCU_SPN3MmostSignificantBit;
  float32 DM1_APCU_SPNConversionMethod;
  float32 DM1_APCU_SPN_LeastSignificantBit;
  float32 DM1_APCU_SPN_secondByteOfSPN;
  float32 DM1_BCM_AmberWarningLamp;
  float32 DM1_BCM_FMI;
  float32 DM1_BCM_OccurrenceCount;
  float32 DM1_BCM_RedStopLamp;
  float32 DM1_BCM_SAELamp_Reserved;
  float32 DM1_BCM_SPN3MmostSignificantBit;
  float32 DM1_BCM_SPN8_LeastSignificantBit;
  float32 DM1_BCM_SPNConversionMethod;
  float32 DM1_BCM_SPN_secondByteOfSPN;
  float32 DM1_BMS_AmberWarningLamp;
  float32 DM1_BMS_FMI;
  float32 DM1_BMS_OccurrenceCount;
  float32 DM1_BMS_RedStopLamp;
  float32 DM1_BMS_SAELamp_Reserved;
  float32 DM1_BMS_SPN3MmostSignificantBit;
  float32 DM1_BMS_SPN8_LeastSignificantBit;
  float32 DM1_BMS_SPNConversionMethod;
  float32 DM1_BMS_SPN_secondByteOfSPN;
  float32 DM1_DCDC2_AmberWarningLamp;
  float32 DM1_DCDC2_FMI;
  float32 DM1_DCDC2_OccurrenceCount;
  float32 DM1_DCDC2_RedStopLamp;
  float32 DM1_DCDC2_SAELamp_Reserved;
  float32 DM1_DCDC2_SPNConversionMethod;
  float32 DM1_DCDC2_SPNMmostSignificantBit;
  float32 DM1_DCDC2_SPN_LeastSgnificantBit;
  float32 DM1_DCDC2_SPN_secondByteOfSPN;
  float32 DM1_EPB_AmberWarningLamp;
  float32 DM1_EPB_FMI;
  float32 DM1_EPB_MalfunctionIndicatorLamp;
  float32 DM1_EPB_OccurrenceCount;
  float32 DM1_EPB_ProtectLamp;
  float32 DM1_EPB_RedStopLamp;
  float32 DM1_EPB_SAELamp_Reserved;
  float32 DM1_EPB_SPN3MmostSignificantBit;
  float32 DM1_EPB_SPN8_LeastSignificantBit;
  float32 DM1_EPB_SPNConversionMethod;
  float32 DM1_EPB_SPN_secondByteOfSPN;
  float32 DM1_EPS_AmberWarningLamp;
  float32 DM1_EPS_FMI;
  float32 DM1_EPS_MalfunctionIndicatorLamp;
  float32 DM1_EPS_OccurrenceCount;
  float32 DM1_EPS_ProtectLamp;
  float32 DM1_EPS_RedStopLamp;
  float32 DM1_EPS_SAELamp_Reserved;
  float32 DM1_EPS_SPN3MmostSignificantBit;
  float32 DM1_EPS_SPN8_LeastSignificantBit;
  float32 DM1_EPS_SPNConversionMethod;
  float32 DM1_EPS_SPN_secondByteOfSPN;
  float32 DM1_PTU_AmberWarningLamp;
  float32 DM1_PTU_FMI;
  float32 DM1_PTU_OccurrenceCount;
  float32 DM1_PTU_RedStopLamp;
  float32 DM1_PTU_SAELamp_Reserved;
  float32 DM1_PTU_SPN3MmostSignificantBit;
  float32 DM1_PTU_SPN8_LeastSignificantBit;
  float32 DM1_PTU_SPNConversionMethod;
  float32 DM1_PTU_SPN_secondByteOfSPN;
  float32 DM1_TPMS_AmberWarningLamp;
  float32 DM1_TPMS_FMI;
  float32 DM1_TPMS_MalfunctionLamp;
  float32 DM1_TPMS_OccurrenceCount;
  float32 DM1_TPMS_ProtectLamp;
  float32 DM1_TPMS_RedStopLamp;
  float32 DM1_TPMS_SAELamp_Reserved;
  float32 DM1_TPMS_SPN3MmostSignificantBit;
  float32 DM1_TPMS_SPNConversionMethod;
  float32 DM1_TPMS_SPN_LeastSignificantBit;
  float32 DM1_TPMS_SPN_secondByteOfSPN;
  float32 EBC1_ABSActive;
  float32 EBC1_ABSFullyOperational;
  float32 EBC1_ABSOffroadSwitch;
  float32 EBC1_ABSOrEBSAmberWarnSignal;
  float32 EBC1_ASRBrakeCtrlActive;
  float32 EBC1_ASREngCtrlActive;
  float32 EBC1_ASRHillHolderSwitch;
  float32 EBC1_ASROffroadSwitch;
  float32 EBC1_ATCOrASRInfoSignal;
  float32 EBC1_BrakePedalPstn;
  float32 EBC1_EBSBrakeSwitch;
  float32 EBC1_EBSRedWarnSignal;
  float32 EBC1_SourceAddressOfCtrlDevice;
  float32 EBC1_TractorMountTrailerABSWarn;
  float32 EBC2_FrontAxleSpeed;
  float32 EBC2_RelativeSpdFrontAxleLWhl;
  float32 EBC2_RelativeSpdFrontAxleRWhl;
  float32 EBC2_RelativeSpdRearAxle1LWhl;
  float32 EBC2_RelativeSpdRearAxle1RWhl;
  float32 EBC2_RelativeSpdRearAxle2LWhl;
  float32 EBC2_RelativeSpdRearAxle2RWhl;
  float32 EBC5_BrakeTempWarning;
  float32 EBC5_EmergencyBrakeActive;
  float32 EBC5_FoundationBrakeUse;
  float32 EBC5_HaltBrakeMode;
  float32 EBC5_HillHolderMode;
  float32 EBC5_XBRAccelLim;
  float32 EBC5_XBRActiveCtrlMode;
  float32 EBC5_XBRSysState;
  float32 EC_EM1_EngReferenceTrq;
  float32 EC_EM1_EngSpdAtPoint1;
  float32 EC_EM1_SupportVariableRateTSC1;
  float32 EEC2_AccelPedal1LowIdleSwitch;
  float32 EEC2_AccelPedalKickdownSwitch;
  float32 EEC2_AccelPedalPstn;
  float32 EEC2_PercentLoadAtCurrentSpd;
  float32 ENGSC_FM_EngStartAbortReq;
  float32 ENGSC_FM_EngStartReq;
  float32 ENGSC_FM_MsgChecksum;
  float32 ENGSC_FM_MsgCounter;
  float32 EPB1_AmberWarnLampStat;
  float32 EPB1_EPBHCUInParkState;
  float32 EPB1_EPBHCUInReleaseState;
  float32 EPB1_PressOfSpringBrakeChamber;
  float32 EPB1_PstnOfEPBHCU;
  float32 EPB1_ReasonForInhibitOfApply;
  float32 EPB1_ReasonForInhibitOfRelease;
  float32 EPB1_RedStopLampStat;
  float32 EPB1_StateOfEPB;
  float32 EPB1_StateOfInhibitOfEPBApply;
  float32 EPB1_StateOfInhibitOfEPBRelease;
  float32 EPB1_TrailerTestActivationState;
  float32 EPB1_WorkModeOfEPB;
  float32 EPS1_ColumnTrq;
  float32 EPS1_ColumnTrqQF;
  float32 EPS1_ColumnVelocity;
  float32 EPS1_ColumnVelocityQF;
  float32 EPS1_HandsOffDetected;
  float32 EPS1_HandsOnDetected;
  float32 EPS1_IgnitionState;
  float32 EPS1_MessageChecksum;
  float32 EPS1_MessageCounter;
  float32 EPS1_PullCompensation;
  float32 EPS2_AbsSteerPstn;
  float32 EPS2_AbsSteerPstnQF;
  float32 EPS2_ActualMode;
  float32 EPS2_ExtInputCmdEcho;
  float32 EPS2_MessageChecksum;
  float32 EPS2_MessageCounter;
  float32 EPS2_ReqMode;
  float32 EPS2_StatusOrError;
  float32 EPSO1_AmberWarnLampStat;
  float32 EPSO1_ElectricalSteerSupRedLv;
  float32 EPSO1_EmergencySteerStat;
  float32 EPSO1_MessageChecksum;
  float32 EPSO1_MessageCounter;
  float32 EPSO1_RedStopLampState;
  float32 EPSO1_SteerAng;
  float32 EPSO1_SteerAngSpd;
  float32 EPSO1_SysState;
  float32 EPSO2_DriverTrq;
  float32 EPSO2_ExtCtrlMode;
  float32 EPSO2_HandsOffProbability;
  float32 EPSO2_MessageChecksum;
  float32 EPSO2_MessageCounter;
  float32 EPSO2_MotorTrq;
  float32 EPSO2_SteerWheelVibrationMode;
  float32 ESC1_ActualInnerWheelSteerAng;
  float32 ESC1_AxleLocation;
  float32 ESC1_AxleLoweringInhibit;
  float32 ESC1_StatOfSteerAxle;
  float32 ESC1_SteerType;
  float32 ESC1_TypeOfSteerForces;
  float32 ESC1_TypeOfSteerTrans;
  float32 ETC2_TransActualGearRatio;
  float32 ETC2_TransCurrentGear;
  float32 ETC2_TransSelectedGear;
  float32 FBCM_BackMirrorAdjustSwch;
  float32 FBCM_BackMirrorHeatSwitch;
  float32 FBCM_BackMirrorSelectSwitch;
  float32 FBCM_CabDoorsLockSwitch;
  float32 FBCM_DriverCtrlPasgrWindowSwitch;
  float32 FBCM_DriverWindowSwitch;
  float32 FBCM_LockOrUnlockSuccessAlert;
  float32 FBCM_PassengerWindowSwitch;
  float32 FBCM_RMKeyBattStat;
  float32 FBCM_RmtLightInspectCmd;
  float32 FBCM_RmtSearchVehCmd;
  float32 FBCM_VehAntiTheftStat;
  float32 HCU_BMS_EnduranceMileage;
  float32 HCU_BMS_HCUSysStat;
  float32 HCU_BMS_HighVoltSysFailStat;
  float32 HCU_BMS_PermitCharge;
  float32 HCU_BMS_ReadyToDriveStat;
  float32 HCU_BMS_SleepCmd;
  float32 LC_BackUpLightAndAlarmHornCmd;
  float32 LC_CenterStopLightCmd;
  float32 LC_DriverSideDomeLight;
  float32 LC_HighBeamHeadLightCmd;
  float32 LC_ImplementMarkerLightCmd;
  float32 LC_LeftTurnSignalLightsCmd;
  float32 LC_LowBeamHeadLightCmd;
  float32 LC_PassengerSideDomeLight;
  float32 LC_RearFogLightCmd;
  float32 LC_RightTurnSignalLightsCmd;
  float32 LC_RunLightCmd;
  float32 LC_TractorFrontFogLightsCmd;
  float32 LD_BackUpLightAndAlarmHorn;
  float32 LD_CenterStopLight;
  float32 LD_FrontFogLights;
  float32 LD_HighBeamHeadLightData;
  float32 LD_ImplementMarkerLightData;
  float32 LD_LeftTurnSignalLights;
  float32 LD_LowBeamHeadLightData;
  float32 LD_RearFogLights;
  float32 LD_RightTurnSignalLights;
  float32 LD_RunLight;
  float32 MCU1_ActualMotorTrqHR;
  float32 MCU1_HighVoltOffPermit;
  float32 MCU1_MaxOutputMotorTrq;
  float32 MCU1_MaxOutputMotorTrqHR;
  float32 MCU1_MotorDischargeStat;
  float32 MCU1_MotorFaliureStat;
  float32 MCU1_MotorRotateDirection;
  float32 MCU1_MotorSpd;
  float32 MCU1_MotorSysStat;
  float32 MCU1_MotorTrq;
  float32 MCU1_MotorWorkMode;
  float32 MCU1_MsgChecksum;
  float32 MCU1_MsgCounter;
  float32 OWW_FrontOperatorWasherSwitch;
  float32 OWW_FrontOperatorWiperSwitch;
  float32 PS1_ESCLNotLockWarn;
  float32 PS1_ESCLNotUnlockWarn;
  float32 PS1_EngRmtStartAndStopStat;
  float32 PS1_IgnitionPstn;
  float32 PS1_IgnitionRmtCtrlStat;
  float32 PS1_NoLegalSmartKeyIDWarn;
  float32 PS1_NoLegalSmartKeyInsideVehWarn;
  float32 PS1_PowerMainSwchNotClosed;
  float32 PS1_PowerOffBeforeLeaveVehWarn;
  float32 PS1_RmtLightInspectionCmd;
  float32 PS1_RmtLockOrUnlockStat;
  float32 PS1_RmtSearchVehCmd;
  float32 PS1_RmtSearchVehStat;
  float32 PS1_SmartKeyBattStat;
  float32 PS1_SmartStartConditionWarn;
  float32 PS1_TurnLightCtrlCmd;
  float32 PS1_VehRmtCtrlMode;
  float32 SC_AutoLightCtrlSwitch;
  float32 SC_CabDoorWarnOFFSwitch;
  float32 SC_FCWSwitchStat;
  float32 SC_HornSelectionSwitch;
  float32 SC_HornSwitch;
  float32 SC_IGOffPostnLightAlert;
  float32 SC_IndoorLightSwitch;
  float32 SC_LDWSwitchStat;
  float32 SC_RearWorkLampSwitch;
  float32 SC_ReverseGearSwitch;
  float32 SC_SleepAreaLightSwitch;
  float32 TIRE1_AirLeakageRate;
  float32 TIRE1_ExtendTirePressSupport;
  float32 TIRE1_Location;
  float32 TIRE1_Press;
  float32 TIRE1_PressThresholdDetect;
  float32 TIRE1_Stat;
  float32 TIRE1_Temp;
  float32 TIRE2_Location;
  float32 TIRE2_PressExtendRange;
  float32 TIRE2_ReqTirePress;
  float32 TIRE3_TireLocation;
  float32 TIRE3_TireSensorElectricalFault;
  float32 TIRE3_TireSensorMatchStat;
  float32 TIRE3_TireSensorSelfLearningStat;
  float32 TIRE3_TireTemThresholdDetection;
  float32 TPCM_BCM;
  float32 TPCM_BMS;
  float32 TPCM_EBS;
  float32 TPCM_EPB;
  float32 TPCM_EPS;
  float32 TPCM_TPMS;
  float32 TPDT_BCM;
  float32 TPDT_BMS;
  float32 TPDT_EBS;
  float32 TPDT_EPB;
  float32 TPDT_EPS;
  float32 TPDT_TPMS;
  float32 VCU_Status_ActualMaxDrivePctTrq;
  float32 VCU_Status_ManualAccelPedalPstn;
  float32 VCU_Status_ManualBrakeSwitch;
  float32 VCU_Status_VCUAutoToManualTips;
  float32 VCU_Status_VCUMode;
  float32 VD_TotalVehDistance;
  float32 VD_TripDistance;
  float32 VDC2_LateralAccel;
  float32 VDC2_LongitudinalAccel;
  float32 VDC2_SteerWheelAng;
  float32 VDC2_SteerWheelAngSensorType;
  float32 VDC2_SteerWheelTurnCounter;
  float32 VDC2_YawRate;            
} J6L_RxBus;

# define Rte_TypeDef_rt_Array_Float_3
typedef float32 rt_Array_Float_3[3];

# define Rte_TypeDef_rt_Array_Float_4
typedef float32 rt_Array_Float_4[4];

# define Rte_TypeDef_rt_Array_Double_3
typedef float64 rt_Array_Double_3[3];

# define Rte_TypeDef_LocalizationInfo
typedef struct
{
  uint32 Rolling_Count;
  uint32 IDC_Time_L;
  uint32 IDC_Time_H;
  uint32 SDC_Time_L;
  uint32 SDC_Time_H;
  float64 timestamp_sec;
  float32 sequence_num;
  float32 position[3];
  float32 orientation[4];
  float32 linear_velocity[3];
  float32 linear_acceleration[3];
  float32 angular_velocity[3];
  float32 heading;
  float32 linear_acceleration_vrf[3];
  float32 angular_velocity_vrf[3];
  float32 euler_angles[3];
  float32 linear_velocity_vrf[3];
  float64 measurement_time;
  uint32 status;
  float64 pos_llh[3];
  float64 origin_llh[3];
  float64 global_offset[3];
  float64 mileage;
  float64 relative_distance;
  float64 relative_heading;            
} LocalizationInfo;

# define Rte_TypeDef_rt_Array_Float_100
typedef float32 rt_Array_Float_100[100];

# define Rte_TypeDef_TrajectoryPoint
typedef struct
{
  float32 x[100];
  float32 y[100];
  float32 z[100];
  float32 theta[100];
  float32 kappa[100];
  float32 s[100];
  float32 dkappa[100];
  float32 ddkappa[100];
  float32 v[100];
  float32 a[100];
  float32 relative_time[100];
  float32 da[100];
  float32 slope[100];            
} TrajectoryPoint;

# define Rte_TypeDef_PathPoint
typedef struct
{
  float32 x[100];
  float32 y[100];
  float32 z[100];
  float32 theta[100];
  float32 kappa[100];
  float32 s[100];
  float32 dkappa[100];            
} PathPoint;

# define Rte_TypeDef_VehicleSignal
typedef struct
{
  uint32 turn_signal;
  uint32 high_beam;
  uint32 low_beam;
  uint32 horn;
  uint32 emergency_light;            
} VehicleSignal;

# define Rte_TypeDef_PlanningInfo
typedef struct
{
  uint32 Rolling_Count;
  uint32 IDC_Time_L;
  uint32 IDC_Time_H;
  uint32 SDC_Time_L;
  uint32 SDC_Time_H;
  float64 timestamp_sec;
  uint32 sequence_num;
  float32 total_path_length;
  float32 total_path_time;
  uint32 trajectory_point_num;
  TrajectoryPoint trajectory_point;
  uint32 path_point_num;
  PathPoint path_point;
  uint32 is_estop;
  uint32 estop_reason;
  uint32 is_replan;
  uint32 replan_reason;
  uint32 gear;
  uint32 right_of_way_status;
  uint32 decision;
  uint32 task;
  uint32 lon_trajectory_type;
  uint32 lat_trajectory_type;
  uint32 scenario_type;
  uint32 driving_state;
  uint32 planning_state;
  uint32 working_mode;
  VehicleSignal vehicle_signal;
  float64 loc_timestamp_sec;
  float64 chassis_timestamp_sec;            
} PlanningInfo;

# define Rte_TypeDef_ADMInfoSOC2MCU
typedef struct
{
  uint32 Rolling_Count;
  uint32 IDC_Time_L;
  uint32 IDC_Time_H;
  uint32 SDC_Time_L;
  uint32 SDC_Time_H;
  uint32 soc_sts;
  uint32 soc_reserv_1;
  uint32 zloc_sts;
  uint32 zloc_reserv_1;
  uint32 zmap_sts;
  uint32 zmap_reserv_1;
  uint32 zloc_lidar_sts;
  uint32 zloc_lidar_reserv_1;
  uint32 perception_radar_sts;
  uint32 perception_radar_reserv_1;
  uint32 perception_camera_sts;
  uint32 perception_camera_reserv_1;
  uint32 perception_lidar_sts;
  uint32 perception_lidar_reserv_1;
  uint32 perception_fusion_sts;
  uint32 perception_fusion_reserv_1;
  uint32 prediction_sts;
  uint32 prediction_reserv_1;
  uint32 planning_sts;
  uint32 planning_reserv_1;
  uint32 routing_sts;
  uint32 routing_reserv_1;            
} ADMInfoSOC2MCU;

# define Rte_TypeDef_ChassisInfo
typedef struct
{
  uint32 Rolling_Count;
  uint32 IDC_Time_L;
  uint32 IDC_Time_H;
  uint32 SDC_Time_L;
  uint32 SDC_Time_H;
  float32 speed_mps;
  uint32 speed_mps_status;
  uint32 speed_mps_dT;
  float32 wheel_spd_fl;
  uint32 wheel_spd_fl_status;
  uint32 wheel_spd_fl_dT;
  float32 wheel_spd_fr;
  uint32 wheel_spd_fr_status;
  uint32 wheel_spd_fr_dT;
  float32 wheel_spd_rl;
  uint32 wheel_spd_rl_status;
  uint32 wheel_spd_rl_dT;
  float32 wheel_spd_rr;
  uint32 wheel_spd_rr_status;
  uint32 wheel_spd_rr_dT;
  float32 longitude_acc;
  uint32 longitude_acc_status;
  uint32 longitude_acc_dT;
  float32 lateral_acc;
  uint32 lateral_acc_status;
  uint32 lateral_acc_dT;
  float32 accel_pedal_position;
  uint32 accel_pedal_position_status;
  uint32 accel_pedal_position_dT;
  float32 brake_pedal_position;
  uint32 brake_pedal_position_status;
  uint32 brake_pedal_position_dT;
  sint32 gear_location;
  uint32 gear_location_status;
  uint32 gear_location_dT;
  uint32 brake_switch;
  uint32 brake_switch_status;
  uint32 brake_switch_dT;
  uint32 parking_brake_switch;
  uint32 parking_brake_switch_status;
  uint32 parking_brake_switch_dT;
  float32 motor_reference_torque;
  uint32 motor_reference_torque_status;
  uint32 motor_reference_torque_dT;
  float32 actual_motor_torque;
  uint32 actual_motor_torque_status;
  uint32 actual_motor_torque_dT;
  float32 engine_reference_torque;
  uint32 engine_reference_torque_status;
  uint32 engine_reference_torque_dT;
  float32 actual_engine_torque;
  uint32 actual_engine_torque_status;
  uint32 actual_engine_torque_dT;
  float32 gear_ratio;
  uint32 gear_ratio_status;
  uint32 gear_ratio_dT;
  float32 steering_angle;
  uint32 steering_angle_status;
  uint32 steering_angle_dT;
  float32 steering_angle_velocity;
  uint32 steering_angle_velocity_status;
  uint32 steering_angle_velocity_dT;
  float32 yaw_rate;
  uint32 yaw_rate_status;
  uint32 yaw_rate_dT;
  float32 driver_hand_torque;
  uint32 driver_hand_torque_status;
  uint32 driver_hand_torque_dT;
  uint32 left_turn_signal;
  uint32 left_turn_signal_status;
  uint32 left_turn_signal_dT;
  uint32 right_turn_signal;
  uint32 right_turn_signal_status;
  uint32 right_turn_signal_dT;
  uint32 auto_drving_main_swtich;
  uint32 auto_drving_main_swtich_status;
  uint32 auto_drving_main_swtich_dT;
  uint32 high_beam_signal;
  uint32 high_beam_signal_status;
  uint32 high_beam_signal_dT;
  uint32 low_beam_signal;
  uint32 low_beam_signal_status;
  uint32 low_beam_signal_dT;
  uint32 ignition_position;
  uint32 ignition_position_status;
  uint32 ignition_position_dT;
  uint32 is_ebs_normal;
  uint32 is_ebs_normal_status;
  uint32 is_ebs_normal_dT;
  uint32 is_eps_normal;
  uint32 is_eps_normal_status;
  uint32 is_eps_normal_dT;
  uint32 is_epb_normal;
  uint32 is_epb_normal_status;
  uint32 is_epb_normal_dT;
  uint32 is_vcu_normal;
  uint32 is_vcu_normal_status;
  uint32 is_vcu_normal_dT;
  float32 throttle_percentage;
  uint32 throttle_percentage_status;
  uint32 throttle_percentage_dT;
  uint32 deflector_rod;
  uint32 deflector_rod_status;
  uint32 deflector_rod_dT;
  float32 tire_pressure_fl;
  uint32 tire_pressure_fl_status;
  uint32 tire_pressure_fl_dT;
  float32 tire_pressure_fr;
  uint32 tire_pressure_fr_status;
  uint32 tire_pressure_fr_dT;
  float32 tire_pressure_rl;
  uint32 tire_pressure_rl_status;
  uint32 tire_pressure_rl_dT;
  float32 tire_pressure_rr;
  uint32 tire_pressure_rr_status;
  uint32 tire_pressure_rr_dT;
  float32 tire_angle_fl;
  uint32 tire_angle_fl_status;
  uint32 tire_angle_fl_dT;
  float32 tire_angle_fr;
  uint32 tire_angle_fr_status;
  uint32 tire_angle_fr_dT;
  uint32 wiper_switch;
  uint32 wiper_switch_status;
  uint32 wiper_switch_dT;
  uint32 wiper_water_switch;
  uint32 wiper_water_switch_status;
  uint32 wiper_water_switch_dT;
  float32 xbr_extacceldemand;
  sint32 tc1_transreqgear;
  float32 eps_steerangreq;            
} ChassisInfo;

# define Rte_TypeDef_ADMInfoMCU2SOC
typedef struct
{
  uint32 Rolling_Count;
  uint32 IDC_Time_L;
  uint32 IDC_Time_H;
  uint32 SDC_Time_L;
  uint32 SDC_Time_H;
  uint32 adm_admode;
  uint32 adm_2_pasv_diag;
  uint32 adm_2_err_diag;            
} ADMInfoMCU2SOC;

# define Rte_TypeDef_CtrlInfoMCU2SOC
typedef struct
{
  uint32 Rolling_Count;
  uint32 IDC_Time_L;
  uint32 IDC_Time_H;
  uint32 SDC_Time_L;
  uint32 SDC_Time_H;
  float32 latctrl_lat_dst_err;
  float32 latctrl_hding_angl_err;
  float32 latctrl_latctrl_status;
  float32 latctrl_proc_tar_str_whl_angl;
  float32 latctrl_tar_str_whl_angl;
  float32 latctrl_mpc_tar_yawrate;
  float32 latctrl_fd_fwd_tar_yawrate;
  float32 latctrl_tar_yawrate;
  float32 latctrl_prv_mpc_tar_yawrate;
  float32 latctrl_prv_fd_fwd_tar_yawrate;
  float32 latctrl_prv_tar_yawrate;
  float32 latctrl_fd_str_whl_angl;
  float32 latctrl_fd_fwd_str_whl_angl;
  float32 latctrl_yawrate_cps;
  float32 latctrl_estm_mass_level;
  float32 latctrl_max_str_whl_angl;
  float32 latctrl_str_whl_angl_rate;
  float32 latctrl_road_bump_enable;
  float32 latctrl_yawrate_controller_p;
  float32 latctrl_fdbk_amplify_enable;
  float32 latctrl_equal_wheel_base;
  float32 latctrl_cur_lat_err_wght;
  float32 latctrl_cur_hding_err_wght;
  float32 latctrl_cur_u_wght;
  float32 latctrl_cur_deltau_wght;
  float32 latctrl_prv_lat_err_wght;
  float32 latctrl_prv_hding_wght;
  float32 latctrl_prv_u_wght;
  float32 latctrl_prv_deltau_wght;
  float32 latctrl_fd_fwd_kappa;
  float32 latctrl_prv_kappa_str_whl_angl;
  float32 latctrl_prv_fd_fwd_kappa;
  float32 longctrl_brake_reqd;
  float32 longctrl_brake_accel_output;
  float32 longctrl_torque_command_output;
  float32 longctrl_accel_des;
  float32 longctrl_accel_limit_max;
  float32 longctrl_accel_limit_min;
  float32 longctrl_jerk_limit_max;
  float32 longctrl_jerk_limit_min;
  float32 longctrl_p_term_engine;
  float32 longctrl_i_term_engine;
  float32 longctrl_p_term_brake;
  float32 longctrl_i_term_brake;
  float32 longctrl_long_acc_comp;
  float32 longctr_speed_comp_longerr;
  float32 vse_lat_tilt_estmd_angl;
  float32 vse_estmd_mass;
  float32 vse_estmd_mass_reliab;
  float32 crm_lat_err;
  float32 crm_hding_err;
  float32 crm_ref_cur;
  float32 crm_long_err;
  float32 crm_spd_err;
  float32 crm_ref_accel;
  uint32 crm_loc_num;
  uint32 crm_trj_num;
  uint32 crm_lat_ref_indx;
  uint32 crm_long_ref_indx;
  uint32 adm_admode;
  uint32 adm_2_pasv_diag;
  uint32 adm_2_err_diag;            
} CtrlInfoMCU2SOC;

# define Rte_TypeDef_J6L_TxBus
typedef struct
{
  float32 ADU1_ADUBrakeSwitch;
  float32 ADU1_ADUStat;
  float32 ADU1_ADUTargetAccel;
  float32 ADU1_ADUTargetSpd;
  float32 ADU_Cmd_ADUToBCM;
  float32 ADU_Cmd_BackBrakeLightCmd;
  float32 ADU_Cmd_DrvDoor1UnlockReq;
  float32 ADU_Cmd_FrontWasherSwitchCmd;
  float32 ADU_Cmd_FrontWiperSwitchCmd;
  float32 ADU_Cmd_HornCmd;
  float32 ADU_Cmd_PassengerDoor2UnlockReq;
  float32 EPB2_AutoDrvState;
  float32 EPB2_ExtApplyReqForEPB;
  float32 EPB2_ExtInhibitReqForPBApply;
  float32 EPB2_ExtInhibitReqForPBRelease;
  float32 EPB2_ExtPressDemandForEPB;
  float32 EPB2_ExtReleaseReqForEPB;
  float32 EPB2_MessageChecksum;
  float32 EPB2_MessageCounter;
  float32 EPSI1_ExtCtrlModeReq;
  float32 EPSI1_FBFTrqReq;
  float32 EPSI1_MessageChecksum;
  float32 EPSI1_MessageCounter;
  float32 EPSI1_MotorTrqReq;
  float32 EPSI1_SteerAngReq;
  float32 EPSI2_ActiveReturnWeightReq;
  float32 EPSI2_AngCtrTrqLimReq;
  float32 EPSI2_AngCtrlWeightReq;
  float32 EPSI2_MessageChecksum;
  float32 EPSI2_MessageCounter;
  float32 LC_ADU_BackUpLightAndHornCmd;
  float32 LC_ADU_HighBeamHeadLightCmd;
  float32 LC_ADU_ImplementMarkerLightCmd;
  float32 LC_ADU_LeftTurnSignalLightsCmd;
  float32 LC_ADU_LowBeamHeadLightCmd;
  float32 LC_ADU_RearFogLightCmd;
  float32 LC_ADU_RightTurnSignalLightsCmd;
  float32 LC_ADU_RunLightCmd;
  float32 LC_ADU_TractorFrontFogLightsCmd;
  float32 Lcks_Cmd1_CmdFromExtController;
  float32 Lcks_Cmd1_DesiredOperateMode;
  float32 Lcks_Cmd1_MessageChecksum;
  float32 Lcks_Cmd1_MessageCounter;
  float32 TC1_ADU_TransReqGear;
  float32 TPCM_APCU;
  float32 TPCM_DCDC2;
  float32 TPCM_PTU;
  float32 TPCM_VCU;
  float32 TPDT_APCU;
  float32 TPDT_DCDC2;
  float32 TPDT_PTU;
  float32 TPDT_VCU;
  float32 TSC1_ACCDR_CtrlPurpose;
  float32 TSC1_ACCDR_EngOvrrdCtrlMode;
  float32 TSC1_ACCDR_EngReqTrqHR;
  float32 TSC1_ACCDR_EngReqTrqOrTrqLim;
  float32 TSC1_ACCDR_MessageChecksum;
  float32 TSC1_ACCDR_MessageCounter;
  float32 TSC1_ACCDR_OvrrdCtrlModePriority;
  float32 TSC1_ACCDR_ReqSpdCtrlConditions;
  float32 TSC1_ACCDR_TransRate;
  float32 TSC1_ACCE_CtrlPurpose;
  float32 TSC1_ACCE_EngOvrrdCtrlMode;
  float32 TSC1_ACCE_EngReqTrqHR;
  float32 TSC1_ACCE_EngReqTrqOrTrqLim;
  float32 TSC1_ACCE_MessageChecksum;
  float32 TSC1_ACCE_MessageCounter;
  float32 TSC1_ACCE_OvrrdCtrlModePriority;
  float32 TSC1_ACCE_ReqSpdCtrlConditions;
  float32 TSC1_ACCE_TransRate;
  float32 XBR1_CtrlMode;
  float32 XBR1_EBIMode;
  float32 XBR1_ExtAccelDemand;
  float32 XBR1_MessageChecksum;
  float32 XBR1_MessageCounter;
  float32 XBR1_Priority;
  float32 XBR2_CtrlMode;
  float32 XBR2_EBIMode;
  float32 XBR2_ExtAccelDemand;
  float32 XBR2_MessageChecksum;
  float32 XBR2_MessageCounter;
  float32 XBR2_Priority;            
} J6L_TxBus;

# define Rte_TypeDef_BusLatCtrl
typedef struct
{
  float32 LatCtrl_TarStrWhlAngl;
  boolean LatCtrl_StrWhlAnglCtrlActv;            
} BusLatCtrl;

# define Rte_TypeDef_BusEM
typedef struct
{
  boolean EM_Err;
  uint32 EM_Diag;            
} BusEM;

# define Rte_TypeDef_BusCRM
typedef struct
{
  float32 CRM_LatDstErr;
  float32 CRM_HdingAnglErr;
  float32 CRM_RefCrvt;
  float32 CRM_LongDstErr;
  float32 CRM_SpdErr;
  float32 CRM_RefAccel;
  float32 CRM_RefSlope;
  float32 CRM_RefSpd;            
} BusCRM;

# define Rte_TypeDef_BusADM
typedef struct
{
  uint8 ADM_ADMode;
  boolean ADM_ADActv;            
} BusADM;

# define Rte_TypeDef_BusLongCtrl
typedef struct
{
  float32 LongCtrl_FinalAccel;
  float32 LongCtrl_AccelProTerm;
  float32 LongCtrl_AccelIntgTerm;
  float32 LongCtrl_TotalSpdErr;
  float32 LongCtrl_DistPropTerm;
  float32 LongCtrl_DistIntgTerm;
  float32 LongCtrl_LongErr;
  float32 LongCtrl_RefAccel;
  float32 LongCtrl_SpdErr;
  float32 LongCtrl_RoadGrdAccel;
  float32 LongCtrl_AccelLimitMax;
  float32 LongCtrl_AccelLimitMin;
  float32 LongCtrl_JerkLimitMax;
  float32 LongCtrl_JerkLimitMin;
  float32 LongCtrl_TorqueProTerm;
  float32 LongCtrl_TorqueIntgTerm;
  float32 LongCtrl_FeedForward;
  float32 LongCtrl_TorqueReq;
  float32 LongCtrl_BrakeAccel;
  float32 LongCtrl_SpdComp;
  uint8 LongCtrl_BrakeReqd;            
} BusLongCtrl;

# define Rte_TypeDef_BusVSE
typedef struct
{
  float32 VSE_LatTiltEstmdAngl;
  float32 VSE_EstmdMass;
  boolean VSE_EstmdMassReliab;
  float32 VSE_LonTiltEstmdAngl;
  float64 x;
  float64 y;
  float64 z;
  float64 com_x;
  float64 com_y;
  float64 com_z;
  float64 timestamp;
  float64 roll;
  float64 pitch;
  float64 heading;
  float64 kappa;
  float64 linear_velocity;
  float64 angular_velocity;
  float64 linear_acceleration;
  sint8 gear;
  uint8 driving_mode;            
} BusVSE;

# define Rte_TypeDef_rt_Array_Float_22
typedef float32 rt_Array_Float_22[22];

# define Rte_TypeDef_rt_Array_Float_22_const
typedef float32 rt_Array_Float_22_const[22];

# define Rte_TypeDef_rt_Array_Float_292
typedef float32 rt_Array_Float_292[292];

# define Rte_TypeDef_rt_Array_Float_292_const
typedef float32 rt_Array_Float_292_const[292];

# define Rte_TypeDef_rt_Array_Float_25
typedef float32 rt_Array_Float_25[25];

# define Rte_TypeDef_rt_Array_Float_25_const
typedef float32 rt_Array_Float_25_const[25];

# define Rte_TypeDef_rt_Array_Float_7
typedef float32 rt_Array_Float_7[7];

# define Rte_TypeDef_rt_Array_Float_7_const
typedef float32 rt_Array_Float_7_const[7];

# define Rte_TypeDef_rt_Array_Float_5
typedef float32 rt_Array_Float_5[5];

# define Rte_TypeDef_rt_Array_Float_5_const
typedef float32 rt_Array_Float_5_const[5];

# define Rte_TypeDef_rt_Array_Float_2
typedef float32 rt_Array_Float_2[2];

# define Rte_TypeDef_rt_Array_Float_2_const
typedef float32 rt_Array_Float_2_const[2];

# define Rte_TypeDef_rt_Array_Float_9
typedef float32 rt_Array_Float_9[9];

# define Rte_TypeDef_rt_Array_Float_9_const
typedef float32 rt_Array_Float_9_const[9];

# define Rte_TypeDef_rt_Array_Float_8
typedef float32 rt_Array_Float_8[8];

# define Rte_TypeDef_rt_Array_Float_8_const
typedef float32 rt_Array_Float_8_const[8];







#endif
