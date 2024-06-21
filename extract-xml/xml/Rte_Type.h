/**
 * ********************************************************************************************************************
 * @file Rte_Type.h
 * @brief Rte Type define
 * @author zhito 
 * @version 1.0.0
 * @date 2023-12-11 13:21:55
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

/*************J6L_ADUCAN_START:*************/
# define Rte_TypeDef_SG_CCVS1_sg
typedef struct
{
  uint8 CCVS1_PBSwitch;
  uint8 CCVS1_CruiseCtrlPauseSwitch;
  uint16 CCVS1_WheelBasedVehSpd;
  uint8 CruiseCtrlActive;
  uint8 CCVS1_CruiseCtrlEnbSwitch;
  uint8 CCVS1_BrakeSwitch;
  uint8 CCVS1_ClutchSwitch;
  uint8 CCVS1_CruiseCtrlSetSwitch;
  uint8 CCVS1_CruiseCtrlResumeSwitch;
  uint8 CCVS1_CruiseCtrlSetSpd;
  uint8 CCVS1_PTOManagmentState;
  uint8 CCVS1_CruiseCtrlState;
} SG_CCVS1_sg;

# define Rte_TypeDef_SG_ETC2_sg
typedef struct
{
  uint8 ETC2_TransSelectedGear;
  uint16 ETC2_TransActualGearRatio;
  uint8 ETC2_TransCurrentGear;
} SG_ETC2_sg;

# define Rte_TypeDef_SG_DM1_EPB_sg
typedef struct
{
  uint8 DM1_EPB_ProtectLamp;
  uint8 DM1_EPB_AmberWarningLamp;
  uint8 DM1_EPB_RedStopLamp;
  uint8 DM1_EPB_MalfunctionIndicatorLamp;
  uint8 DM1_EPB_SAELamp_Reserved;
  uint8 DM1_EPB_SPN8_LeastSignificantBit;
  uint8 DM1_EPB_SPN_secondByteOfSPN;
  uint8 DM1_EPB_FMI;
  uint8 DM1_EPB_SPN3MmostSignificantBit;
  uint8 DM1_EPB_OccurrenceCount;
  boolean DM1_EPB_SPNConversionMethod;
} SG_DM1_EPB_sg;

# define Rte_TypeDef_SG_EPB1_sg
typedef struct
{
  uint8 EPB1_PressOfSpringBrakeChamber;
  uint8 EPB1_ReasonForInhibitOfRelease;
  uint8 EPB1_ReasonForInhibitOfApply;
  uint8 EPB1_AmberWarnLampStat;
  uint8 EPB1_RedStopLampStat;
  uint8 EPB1_StateOfInhibitOfEPBRelease;
  uint8 EPB1_StateOfEPB;
  uint8 EPB1_WorkModeOfEPB;
  uint8 EPB1_TrailerTestActivationState;
  uint8 EPB1_StateOfInhibitOfEPBApply;
  uint8 EPB1_EPBHCUInParkState;
  uint8 EPB1_EPBHCUInReleaseState;
  uint8 EPB1_PstnOfEPBHCU;
} SG_EPB1_sg;

# define Rte_TypeDef_SG_DM1_ABS_sg
typedef struct
{
  uint8 DM1_ABS_ProtectLamp;
  uint8 DM1_ABS_AmberWarningLamp;
  uint8 DM1_ABS_RedStopLamp;
  uint8 DM1_ABS_MalfunctionIndicatorLamp;
  uint8 DM1_ABS_SPN8_LeastSignificantBit;
  uint8 DM1_ABS_SPN_secondByteOfSPN;
  uint8 DM1_ABS_FMI;
  uint8 DM1_ABS_SPN3MmostSignificantBit;
  uint8 DM1_ABS_OccurrenceCount;
  boolean DM1_ABS_SPNConversionMethod;
} SG_DM1_ABS_sg;

# define Rte_TypeDef_SG_EBC1_sg
typedef struct
{
  uint8 EBC1_ASREngCtrlActive;
  uint8 EBC1_ASRBrakeCtrlActive;
  uint8 EBC1_ABSActive;
  uint8 EBC1_EBSBrakeSwitch;
  uint8 EBC1_BrakePedalPstn;
  uint8 EBC1_ABSOffroadSwitch;
  uint8 EBC1_ASROffroadSwitch;
  uint8 EBC1_ASRHillHolderSwitch;
  uint8 EBC1_ABSFullyOperational;
  uint8 EBC1_EBSRedWarnSignal;
  uint8 EBC1_ABSOrEBSAmberWarnSignal;
  uint8 EBC1_ATCOrASRInfoSignal;
  uint8 EBC1_SourceAddressOfCtrlDevice;
  uint8 EBC1_TractorMountTrailerABSWarn;
} SG_EBC1_sg;

# define Rte_TypeDef_SG_EBC2_sg
typedef struct
{
  uint16 EBC2_FrontAxleSpeed;
  uint8 EBC2_RelativeSpdFrontAxleLWhl;
  uint8 EBC2_RelativeSpdFrontAxleRWhl;
  uint8 EBC2_RelativeSpdRearAxle1LWhl;
  uint8 EBC2_RelativeSpdRearAxle1RWhl;
  uint8 EBC2_RelativeSpdRearAxle2LWhl;
  uint8 EBC2_RelativeSpdRearAxle2RWhl;
} SG_EBC2_sg;

# define Rte_TypeDef_SG_EBC5_sg
typedef struct
{
  uint8 EBC5_BrakeTempWarning;
  uint8 EBC5_HaltBrakeMode;
  uint8 EBC5_HillHolderMode;
  uint8 EBC5_FoundationBrakeUse;
  uint8 EBC5_XBRSysState;
  uint8 EBC5_XBRActiveCtrlMode;
  uint8 EBC5_XBRAccelLim;
  uint8 EBC5_EmergencyBrakeActive;
} SG_EBC5_sg;

# define Rte_TypeDef_SG_ESC1_sg
typedef struct
{
  uint16 ESC1_ActualInnerWheelSteerAng;
  uint8 ESC1_AxleLocation;
  uint8 ESC1_StatOfSteerAxle;
  uint8 ESC1_AxleLoweringInhibit;
  uint8 ESC1_SteerType;
  uint8 ESC1_TypeOfSteerForces;
  uint8 ESC1_TypeOfSteerTrans;
} SG_ESC1_sg;

# define Rte_TypeDef_SG_CVW_sg
typedef struct
{
  uint16 CVW_PoweredVehWeight;
  uint16 CVW_GrossCombineVehWeight;
} SG_CVW_sg;

# define Rte_TypeDef_SG_VDC2_sg
typedef struct
{
  uint16 VDC2_SteerWheelAng;
  uint8 VDC2_SteerWheelTurnCounter;
  uint8 VDC2_SteerWheelAngSensorType;
  uint16 VDC2_YawRate;
  uint16 VDC2_LateralAccel;
  uint8 VDC2_LongitudinalAccel;
} SG_VDC2_sg;

# define Rte_TypeDef_SG_LC_ADU_sg
typedef struct
{
  uint8 LC_ADU_RunLightCmd;
  uint8 LC_ADU_LowBeamHeadLightCmd;
  uint8 LC_ADU_HighBeamHeadLightCmd;
  uint8 LC_ADU_TractorFrontFogLightsCmd;
  uint8 LC_ADU_RightTurnSignalLightsCmd;
  uint8 LC_ADU_LeftTurnSignalLightsCmd;
  uint8 LC_ADU_BackUpLightAndHornCmd;
  uint8 LC_ADU_ImplementMarkerLightCmd;
  uint8 LC_ADU_RearFogLightCmd;
} SG_LC_ADU_sg;

# define Rte_TypeDef_SG_LC_sg
typedef struct
{
  uint8 LC_RunLightCmd;
  uint8 LC_LowBeamHeadLightCmd;
  uint8 LC_HighBeamHeadLightCmd;
  uint8 LC_TractorFrontFogLightsCmd;
  uint8 LC_RightTurnSignalLightsCmd;
  uint8 LC_LeftTurnSignalLightsCmd;
  uint8 LC_BackUpLightAndAlarmHornCmd;
  uint8 LC_CenterStopLightCmd;
  uint8 LC_ImplementMarkerLightCmd;
  uint8 LC_RearFogLightCmd;
  uint8 LC_DriverSideDomeLight;
  uint8 LC_PassengerSideDomeLight;
} SG_LC_sg;

# define Rte_TypeDef_SG_DC2_sg
typedef struct
{
  uint8 DC2_LockStatOfDoor1;
  uint8 DC2_OpenStatOfDoor1;
  uint8 DC2_LockStatOfDoor2;
  uint8 DC2_OpenStatOfDoor2;
} SG_DC2_sg;

# define Rte_TypeDef_SG_MCU1_sg
typedef struct
{
  uint8 MCU1_MotorWorkMode;
  uint8 MCU1_MotorRotateDirection;
  uint8 MCU1_MotorSysStat;
  uint8 MCU1_ActualMotorTrqHR;
  uint8 MCU1_MaxOutputMotorTrqHR;
  uint8 MCU1_MotorTrq;
  uint8 MCU1_MaxOutputMotorTrq;
  uint16 MCU1_MotorSpd;
  uint8 MCU1_HighVoltOffPermit;
  uint8 MCU1_MotorDischargeStat;
  uint8 MCU1_MotorFaliureStat;
  uint8 MCU1_MsgCounter;
  uint8 MCU1_MsgChecksum;
} SG_MCU1_sg;

# define Rte_TypeDef_SG_DM1_EPS_sg
typedef struct
{
  uint8 DM1_EPS_ProtectLamp;
  uint8 DM1_EPS_AmberWarningLamp;
  uint8 DM1_EPS_RedStopLamp;
  uint8 DM1_EPS_MalfunctionIndicatorLamp;
  uint8 DM1_EPS_SAELamp_Reserved;
  uint8 DM1_EPS_SPN8_LeastSignificantBit;
  uint8 DM1_EPS_SPN_secondByteOfSPN;
  uint8 DM1_EPS_FMI;
  uint8 DM1_EPS_SPN3MmostSignificantBit;
  uint8 DM1_EPS_OccurrenceCount;
  boolean DM1_EPS_SPNConversionMethod;
} SG_DM1_EPS_sg;

# define Rte_TypeDef_SG_EPS1_ZF_sg
typedef struct
{
  uint16 EPS1_ColumnTrq;
  uint16 EPS1_ColumnVelocity;
  uint16 EPS1_PullCompensation;
  boolean EPS1_ColumnTrqQF;
  boolean EPS1_ColumnVelocityQF;
  boolean EPS1_IgnitionState;
  boolean EPS1_HandsOffDetected;
  boolean EPS1_HandsOnDetected;
  uint8 EPS1_MessageChecksum;
  uint8 EPS1_MessageCounter;
} SG_EPS1_ZF_sg;

# define Rte_TypeDef_SG_EPS2_ZF_sg
typedef struct
{
  uint16 EPS2_AbsSteerPstn;
  uint16 EPS2_ExtInputCmdEcho;
  uint8 EPS2_StatusOrError;
  uint8 EPS2_ActualMode;
  uint8 EPS2_ReqMode;
  boolean EPS2_AbsSteerPstnQF;
  uint8 EPS2_MessageChecksum;
  uint8 EPS2_MessageCounter;
} SG_EPS2_ZF_sg;

# define Rte_TypeDef_SG_TIRE1_sg
typedef struct
{
  uint8 TIRE1_Location;
  uint8 TIRE1_Press;
  uint16 TIRE1_Temp;
  uint8 TIRE1_Stat;
  uint8 TIRE1_ExtendTirePressSupport;
  uint16 TIRE1_AirLeakageRate;
  uint8 TIRE1_PressThresholdDetect;
} SG_TIRE1_sg;

# define Rte_TypeDef_SG_TIRE2_sg
typedef struct
{
  uint8 TIRE2_Location;
  uint16 TIRE2_PressExtendRange;
  uint16 TIRE2_ReqTirePress;
} SG_TIRE2_sg;

# define Rte_TypeDef_SG_TIRE3_sg
typedef struct
{
  uint8 TIRE3_TireLocation;
  uint8 TIRE3_TireSensorMatchStat;
  uint8 TIRE3_TireSensorSelfLearningStat;
  uint8 TIRE3_TireSensorElectricalFault;
  uint8 TIRE3_TireTemThresholdDetection;
} SG_TIRE3_sg;

# define Rte_TypeDef_SG_DM1_TPMS_sg
typedef struct
{
  uint8 DM1_TPMS_ProtectLamp;
  uint8 DM1_TPMS_AmberWarningLamp;
  uint8 DM1_TPMS_RedStopLamp;
  uint8 DM1_TPMS_MalfunctionLamp;
  uint8 DM1_TPMS_SAELamp_Reserved;
  uint8 DM1_TPMS_SPN_LeastSignificantBit;
  uint8 DM1_TPMS_SPN_secondByteOfSPN;
  uint8 DM1_TPMS_FMI;
  uint8 DM1_TPMS_SPN3MmostSignificantBit;
  uint8 DM1_TPMS_OccurrenceCount;
  boolean DM1_TPMS_SPNConversionMethod;
} SG_DM1_TPMS_sg;

# define Rte_TypeDef_SG_EEC2_sg
typedef struct
{
  uint8 EEC2_AccelPedal1LowIdleSwitch;
  uint8 EEC2_AccelPedalKickdownSwitch;
  uint8 EEC2_AccelPedalPstn;
  uint8 EEC2_PercentLoadAtCurrentSpd;
} SG_EEC2_sg;

# define Rte_TypeDef_SG_TSC1_ACCE_sg
typedef struct
{
  uint8 TSC1_ACCE_EngOvrrdCtrlMode;
  uint8 TSC1_ACCE_ReqSpdCtrlConditions;
  uint8 TSC1_ACCE_OvrrdCtrlModePriority;
  uint8 TSC1_ACCE_EngReqTrqOrTrqLim;
  uint8 TSC1_ACCE_TransRate;
  uint8 TSC1_ACCE_CtrlPurpose;
  uint8 TSC1_ACCE_EngReqTrqHR;
  uint8 TSC1_ACCE_MessageCounter;
  uint8 TSC1_ACCE_MessageChecksum;
} SG_TSC1_ACCE_sg;

# define Rte_TypeDef_SG_XBR2_sg
typedef struct
{
  uint16 XBR2_ExtAccelDemand;
  uint8 XBR2_EBIMode;
  uint8 XBR2_Priority;
  uint8 XBR2_CtrlMode;
  uint8 XBR2_MessageCounter;
  uint8 XBR2_MessageChecksum;
} SG_XBR2_sg;

# define Rte_TypeDef_SG_TC1_ADU_sg
typedef struct
{
  uint8 TC1_ADU_TransReqGear;
} SG_TC1_ADU_sg;

# define Rte_TypeDef_SG_EPB2_sg
typedef struct
{
  uint8 EPB2_ExtPressDemandForEPB;
  uint8 EPB2_ExtInhibitReqForPBRelease;
  uint8 EPB2_ExtInhibitReqForPBApply;
  uint8 EPB2_ExtApplyReqForEPB;
  uint8 EPB2_ExtReleaseReqForEPB;
  uint8 EPB2_AutoDrvState;
  uint8 EPB2_MessageCounter;
  uint8 EPB2_MessageChecksum;
} SG_EPB2_sg;

# define Rte_TypeDef_SG_ADU1_sg
typedef struct
{
  uint8 ADU1_ADUStat;
  uint16 ADU1_ADUTargetSpd;
  uint8 ADU1_ADUBrakeSwitch;
  uint16 ADU1_ADUTargetAccel;
} SG_ADU1_sg;

# define Rte_TypeDef_SG_ADU_Cmd_sg
typedef struct
{
  uint8 ADU_Cmd_FrontWiperSwitchCmd;
  uint8 ADU_Cmd_FrontWasherSwitchCmd;
  uint8 ADU_Cmd_ADUToBCM;
  uint8 ADU_Cmd_DrvDoor1UnlockReq;
  uint8 ADU_Cmd_PassengerDoor2UnlockReq;
  uint8 ADU_Cmd_BackBrakeLightCmd;
  uint8 ADU_Cmd_HornCmd;
} SG_ADU_Cmd_sg;

# define Rte_TypeDef_SG_VCU_Status_sg
typedef struct
{
  uint8 VCU_Status_VCUMode;
  uint8 VCU_Status_ManualBrakeSwitch;
  uint8 VCU_Status_ManualAccelPedalPstn;
  uint16 VCU_Status_VCUAutoToManualTips;
  uint8 VCU_Status_ActualMaxDrivePctTrq;
} SG_VCU_Status_sg;

# define Rte_TypeDef_SG_OWW_sg
typedef struct
{
  uint8 OWW_FrontOperatorWiperSwitch;
  uint8 OWW_FrontOperatorWasherSwitch;
} SG_OWW_sg;

# define Rte_TypeDef_SG_SC_sg
typedef struct
{
  uint8 SC_IGOffPostnLightAlert;
  uint8 SC_LDWSwitchStat;
  uint8 SC_FCWSwitchStat;
  uint8 SC_ReverseGearSwitch;
  uint8 SC_RearWorkLampSwitch;
  uint8 SC_SleepAreaLightSwitch;
  uint8 SC_IndoorLightSwitch;
  uint8 SC_HornSwitch;
  uint8 SC_HornSelectionSwitch;
  uint8 SC_CabDoorWarnOFFSwitch;
  uint8 SC_AutoLightCtrlSwitch;
} SG_SC_sg;

# define Rte_TypeDef_SG_BCU_sg
typedef struct
{
  uint8 BCU_IgnitionPstn;
  uint8 BCU_DriverSeatBeltAlert;
  uint8 BCU_PassengerSeatBeltAlert;
} SG_BCU_sg;

# define Rte_TypeDef_SG_HCU_BMS_sg
typedef struct
{
  uint8 HCU_BMS_HCUSysStat;
  uint8 HCU_BMS_ReadyToDriveStat;
  uint8 HCU_BMS_PermitCharge;
  uint16 HCU_BMS_EnduranceMileage;
  uint8 HCU_BMS_SleepCmd;
  uint8 HCU_BMS_HighVoltSysFailStat;
} SG_HCU_BMS_sg;

# define Rte_TypeDef_SG_BMS1_sg
typedef struct
{
  uint16 BMS1_PowerBattVolt;
  uint16 BMS1_PowerBattCurrent;
  uint8 BMS1_PowerBattSOC;
  uint8 BMS1_PowerBattSysStat;
  uint8 BMS1_PowerBattChargeReq;
  uint8 BMS1_PowerBattChargeStat;
  uint8 BMS1_PowerBattHeatStat;
  uint8 BMS1_MsgCounter;
  uint8 BMS1_MsgChecksum;
} SG_BMS1_sg;

# define Rte_TypeDef_SG_BMS5_sg
typedef struct
{
  uint8 BMS5_BMSMainNgtvCoilDrvStat;
  uint8 BMS5_PowerBattSOH;
  uint8 BMS5_MainNgtvRelayDisconnectReq;
  uint8 BMS5_MainNgtvRelayStat;
  uint8 BMS5_BattPackHeatCtrlCmdPstv;
  uint8 BMS5_BattPackHeatCtrlCmdNgtv;
  uint8 BMS5_ChargePlugConnectionStat;
  uint8 BMS5_ChargePlug2ConnectionStat;
  uint8 BMS5_ChargeRelayStatPstv;
  uint8 BMS5_ChargeRelayStatNgtv;
} SG_BMS5_sg;

# define Rte_TypeDef_SG_VD_sg
typedef struct
{
  uint32 VD_TripDistance;
  uint32 VD_TotalVehDistance;
} SG_VD_sg;

# define Rte_TypeDef_SG_DM1_BCM_sg
typedef struct
{
  uint8 DM1_BCM_AmberWarningLamp;
  uint8 DM1_BCM_RedStopLamp;
  uint8 DM1_BCM_SAELamp_Reserved;
  uint8 DM1_BCM_SPN8_LeastSignificantBit;
  uint8 DM1_BCM_SPN_secondByteOfSPN;
  uint8 DM1_BCM_FMI;
  uint8 DM1_BCM_SPN3MmostSignificantBit;
  uint8 DM1_BCM_OccurrenceCount;
  boolean DM1_BCM_SPNConversionMethod;
} SG_DM1_BCM_sg;

# define Rte_TypeDef_SG_TSC1_ACCDR_sg
typedef struct
{
  uint8 TSC1_ACCDR_EngOvrrdCtrlMode;
  uint8 TSC1_ACCDR_ReqSpdCtrlConditions;
  uint8 TSC1_ACCDR_OvrrdCtrlModePriority;
  uint8 TSC1_ACCDR_EngReqTrqOrTrqLim;
  uint8 TSC1_ACCDR_TransRate;
  uint8 TSC1_ACCDR_CtrlPurpose;
  uint8 TSC1_ACCDR_EngReqTrqHR;
  uint8 TSC1_ACCDR_MessageCounter;
  uint8 TSC1_ACCDR_MessageChecksum;
} SG_TSC1_ACCDR_sg;

# define Rte_TypeDef_SG_EC_EM1_sg
typedef struct
{
  uint16 EC_EM1_EngSpdAtPoint1;
  uint16 EC_EM1_EngReferenceTrq;
  uint8 EC_EM1_SupportVariableRateTSC1;
} SG_EC_EM1_sg;

# define Rte_TypeDef_SG_LD_sg
typedef struct
{
  uint8 LD_RunLight;
  uint8 LD_LowBeamHeadLightData;
  uint8 LD_HighBeamHeadLightData;
  uint8 LD_RightTurnSignalLights;
  uint8 LD_LeftTurnSignalLights;
  uint8 LD_FrontFogLights;
  uint8 LD_RearFogLights;
  uint8 LD_BackUpLightAndAlarmHorn;
  uint8 LD_CenterStopLight;
  uint8 LD_ImplementMarkerLightData;
} SG_LD_sg;

# define Rte_TypeDef_SG_BCM_Status_sg
typedef struct
{
  uint8 BCM_Status_BCMRespStat;
  uint8 BCM_Status_BackBrakeLightStat;
  uint8 BCM_Status_HornStat;
  uint8 BCM_Status_WiperStat;
} SG_BCM_Status_sg;

# define Rte_TypeDef_SG_DM1_BMS_sg
typedef struct
{
  uint8 DM1_BMS_AmberWarningLamp;
  uint8 DM1_BMS_RedStopLamp;
  uint8 DM1_BMS_SAELamp_Reserved;
  uint8 DM1_BMS_SPN8_LeastSignificantBit;
  uint8 DM1_BMS_SPN_secondByteOfSPN;
  uint8 DM1_BMS_FMI;
  uint8 DM1_BMS_SPN3MmostSignificantBit;
  uint8 DM1_BMS_OccurrenceCount;
  boolean DM1_BMS_SPNConversionMethod;
} SG_DM1_BMS_sg;

# define Rte_TypeDef_SG_DM1_PTU_sg
typedef struct
{
  uint8 DM1_PTU_AmberWarningLamp;
  uint8 DM1_PTU_RedStopLamp;
  uint8 DM1_PTU_SAELamp_Reserved;
  uint8 DM1_PTU_SPN8_LeastSignificantBit;
  uint8 DM1_PTU_SPN_secondByteOfSPN;
  uint8 DM1_PTU_FMI;
  uint8 DM1_PTU_SPN3MmostSignificantBit;
  uint8 DM1_PTU_OccurrenceCount;
  boolean DM1_PTU_SPNConversionMethod;
} SG_DM1_PTU_sg;

# define Rte_TypeDef_SG_DM1_DCDC2_sg
typedef struct
{
  uint8 DM1_DCDC2_AmberWarningLamp;
  uint8 DM1_DCDC2_RedStopLamp;
  uint8 DM1_DCDC2_SAELamp_Reserved;
  uint8 DM1_DCDC2_SPN_LeastSgnificantBit;
  uint8 DM1_DCDC2_SPN_secondByteOfSPN;
  uint8 DM1_DCDC2_FMI;
  uint8 DM1_DCDC2_SPNMmostSignificantBit;
  uint8 DM1_DCDC2_OccurrenceCount;
  boolean DM1_DCDC2_SPNConversionMethod;
} SG_DM1_DCDC2_sg;

# define Rte_TypeDef_SG_DM1_APCU_sg
typedef struct
{
  uint8 DM1_APCU_AmberWarningLamp;
  uint8 DM1_APCU_RedStopLamp;
  uint8 DM1_APCU_SAELamp_Reserved;
  uint8 DM1_APCU_SPN_LeastSignificantBit;
  uint8 DM1_APCU_SPN_secondByteOfSPN;
  uint8 DM1_APCU_FMI;
  uint8 DM1_APCU_SPN3MmostSignificantBit;
  uint8 DM1_APCU_OccurrenceCount;
  boolean DM1_APCU_SPNConversionMethod;
} SG_DM1_APCU_sg;

# define Rte_TypeDef_SG_EPSO1_sg
typedef struct
{
  uint16 EPSO1_SteerAng;
  uint16 EPSO1_SteerAngSpd;
  uint8 EPSO1_ElectricalSteerSupRedLv;
  uint8 EPSO1_EmergencySteerStat;
  uint8 EPSO1_AmberWarnLampStat;
  uint8 EPSO1_RedStopLampState;
  uint8 EPSO1_SysState;
  uint8 EPSO1_MessageCounter;
  uint8 EPSO1_MessageChecksum;
} SG_EPSO1_sg;

# define Rte_TypeDef_SG_EPSO2_sg
typedef struct
{
  uint16 EPSO2_DriverTrq;
  uint16 EPSO2_MotorTrq;
  uint8 EPSO2_HandsOffProbability;
  uint8 EPSO2_ExtCtrlMode;
  uint8 EPSO2_SteerWheelVibrationMode;
  uint8 EPSO2_MessageCounter;
  uint8 EPSO2_MessageChecksum;
} SG_EPSO2_sg;

# define Rte_TypeDef_SG_XBR1_sg
typedef struct
{
  uint16 XBR1_ExtAccelDemand;
  uint8 XBR1_EBIMode;
  uint8 XBR1_Priority;
  uint8 XBR1_CtrlMode;
  uint8 XBR1_MessageCounter;
  uint8 XBR1_MessageChecksum;
} SG_XBR1_sg;

# define Rte_TypeDef_SG_EPSI1_sg
typedef struct
{
  uint16 EPSI1_MotorTrqReq;
  uint16 EPSI1_SteerAngReq;
  uint16 EPSI1_FBFTrqReq;
  uint8 EPSI1_ExtCtrlModeReq;
  uint8 EPSI1_MessageCounter;
  uint8 EPSI1_MessageChecksum;
} SG_EPSI1_sg;

# define Rte_TypeDef_SG_EPSI2_sg
typedef struct
{
  uint8 EPSI2_ActiveReturnWeightReq;
  uint8 EPSI2_AngCtrlWeightReq;
  uint8 EPSI2_AngCtrTrqLimReq;
  uint8 EPSI2_MessageCounter;
  uint8 EPSI2_MessageChecksum;
} SG_EPSI2_sg;

# define Rte_TypeDef_SG_FBCM_sg
typedef struct
{
  uint8 FBCM_DriverWindowSwitch;
  uint8 FBCM_DriverCtrlPasgrWindowSwitch;
  uint8 FBCM_PassengerWindowSwitch;
  uint8 FBCM_CabDoorsLockSwitch;
  uint8 FBCM_BackMirrorHeatSwitch;
  uint8 FBCM_BackMirrorSelectSwitch;
  uint8 FBCM_BackMirrorAdjustSwch;
  uint8 FBCM_VehAntiTheftStat;
  uint8 FBCM_RmtLightInspectCmd;
  uint8 FBCM_RmtSearchVehCmd;
  uint8 FBCM_LockOrUnlockSuccessAlert;
  uint8 FBCM_RMKeyBattStat;
} SG_FBCM_sg;

# define Rte_TypeDef_SG_PS1_sg
typedef struct
{
  uint8 PS1_PowerOffBeforeLeaveVehWarn;
  uint8 PS1_NoLegalSmartKeyInsideVehWarn;
  uint8 PS1_NoLegalSmartKeyIDWarn;
  uint8 PS1_SmartStartConditionWarn;
  uint8 PS1_ESCLNotUnlockWarn;
  uint8 PS1_ESCLNotLockWarn;
  uint8 PS1_SmartKeyBattStat;
  uint8 PS1_PowerMainSwchNotClosed;
  uint8 PS1_RmtLightInspectionCmd;
  uint8 PS1_RmtSearchVehCmd;
  uint8 PS1_IgnitionPstn;
  uint8 PS1_EngRmtStartAndStopStat;
  uint8 PS1_IgnitionRmtCtrlStat;
  uint8 PS1_RmtLockOrUnlockStat;
  uint8 PS1_RmtSearchVehStat;
  uint8 PS1_VehRmtCtrlMode;
  uint8 PS1_TurnLightCtrlCmd;
} SG_PS1_sg;

# define Rte_TypeDef_SG_ENGSC_FM_sg
typedef struct
{
  uint8 ENGSC_FM_EngStartReq;
  uint8 ENGSC_FM_EngStartAbortReq;
  uint8 ENGSC_FM_MsgCounter;
  uint8 ENGSC_FM_MsgChecksum;
} SG_ENGSC_FM_sg;

# define Rte_TypeDef_SG_ATR_FM_sg
typedef struct
{
  uint8 ATR_FM_AntiTheftEncryIndicatStat;
  uint8 ATR_FM_AntiTheftDesireExitMode;
  uint8 ATR_FM_AntiTheftCmdStat;
  uint8 ATR_FM_AntiTheftPassword[7];
} SG_ATR_FM_sg;

# define Rte_TypeDef_SG_ATS_PS_sg
typedef struct
{
  uint8 ATS_PS_AntiTheftEncrySeedIndicat;
  uint8 ATS_PS_AntiTheftPasswordValid;
  uint8 ATS_PS_AntiTheftComponentStat;
  uint8 ATS_PS_AntiTheftModifyPassword;
  uint8 ATS_PS_AntiTheftRandomNumber[7];
} SG_ATS_PS_sg;

# define Rte_TypeDef_SG_Lcks_Cmd1_sg
typedef struct
{
  uint8 Lcks_Cmd1_DesiredOperateMode;
  uint16 Lcks_Cmd1_CmdFromExtController;
  uint8 Lcks_Cmd1_MessageCounter;
  uint8 Lcks_Cmd1_MessageChecksum;
} SG_Lcks_Cmd1_sg;

# define Rte_TypeDef_SG_TPCM_EPB_sg
typedef struct
{
  uint8 TPCM_EPB[8];
} SG_TPCM_EPB_sg;

# define Rte_TypeDef_SG_TPDT_EPB_sg
typedef struct
{
  uint8 TPDT_EPB[8];
} SG_TPDT_EPB_sg;

# define Rte_TypeDef_SG_TPCM_EBS_sg
typedef struct
{
  uint8 TPCM_EBS[8];
} SG_TPCM_EBS_sg;

# define Rte_TypeDef_SG_TPDT_EBS_sg
typedef struct
{
  uint8 TPDT_EBS[8];
} SG_TPDT_EBS_sg;

# define Rte_TypeDef_SG_TPCM_EPS_sg
typedef struct
{
  uint8 TPCM_EPS[8];
} SG_TPCM_EPS_sg;

# define Rte_TypeDef_SG_TPDT_EPS_sg
typedef struct
{
  uint8 TPDT_EPS[8];
} SG_TPDT_EPS_sg;

# define Rte_TypeDef_SG_TPCM_BCM_sg
typedef struct
{
  uint8 TPCM_BCM[8];
} SG_TPCM_BCM_sg;

# define Rte_TypeDef_SG_TPDT_BCM_sg
typedef struct
{
  uint8 TPDT_BCM[8];
} SG_TPDT_BCM_sg;

# define Rte_TypeDef_SG_TPCM_TPMS_sg
typedef struct
{
  uint8 TPCM_TPMS[8];
} SG_TPCM_TPMS_sg;

# define Rte_TypeDef_SG_TPDT_TPMS_sg
typedef struct
{
  uint8 TPDT_TPMS[8];
} SG_TPDT_TPMS_sg;

# define Rte_TypeDef_SG_TPCM_BMS_sg
typedef struct
{
  uint8 TPCM_BMS[8];
} SG_TPCM_BMS_sg;

# define Rte_TypeDef_SG_TPDT_BMS_sg
typedef struct
{
  uint8 TPDT_BMS[8];
} SG_TPDT_BMS_sg;

# define Rte_TypeDef_SG_TPCM_VCU_sg
typedef struct
{
  uint16 TPCM_VCU;
} SG_TPCM_VCU_sg;

# define Rte_TypeDef_SG_TPDT_VCU_sg
typedef struct
{
  uint16 TPDT_VCU;
} SG_TPDT_VCU_sg;

# define Rte_TypeDef_SG_TPCM_PTU_sg
typedef struct
{
  uint16 TPCM_PTU;
} SG_TPCM_PTU_sg;

# define Rte_TypeDef_SG_TPDT_PTU_sg
typedef struct
{
  uint16 TPDT_PTU;
} SG_TPDT_PTU_sg;

# define Rte_TypeDef_SG_TPCM_DCDC2_sg
typedef struct
{
  uint16 TPCM_DCDC2;
} SG_TPCM_DCDC2_sg;

# define Rte_TypeDef_SG_TPDT_DCDC2_sg
typedef struct
{
  uint16 TPDT_DCDC2;
} SG_TPDT_DCDC2_sg;

# define Rte_TypeDef_SG_TPCM_APCU_sg
typedef struct
{
  uint16 TPCM_APCU;
} SG_TPCM_APCU_sg;

# define Rte_TypeDef_SG_TPDT_APCU_sg
typedef struct
{
  uint16 TPDT_APCU;
} SG_TPDT_APCU_sg;

# define Rte_TypeDef_SG_HRW_sg
typedef struct
{
  uint16 HRW_FrontAxleLeftWheelSpd;
  uint16 HRW_FrontAxleRightWheelSpd;
  uint16 HRW_RearAxleLeftWheelSpd;
  uint16 HRW_RearAxleRightWheelSpd;
} SG_HRW_sg;

# define Rte_TypeDef_SG_ADUSt_sg
typedef struct
{
  uint8 ADUSt_ADCtrlStat;
  boolean ADUSt_EBStat;
  uint8 ADUSt_EBSrc;
  uint8 ADUSt_ADCtrlReq;
  uint8 ADUSt_LiveCounter;
} SG_ADUSt_sg;

# define Rte_TypeDef_SG_RDUSt_sg
typedef struct
{
  uint8 RDUSt_RmtCtrlStat;
  boolean RDUSt_SafetyMode;
  boolean RDUSt_EBStat;
  uint8 RDUSt_EBSrc;
  uint8 RDUSt_ADCtrlEnable;
  uint8 RDUSt_RmtCtrlEnable;
  uint8 RDUSt_RmtCtrlEnableResp;
  uint8 RDUSt_RmtPowerOnOff;
  boolean RDUSt_RDUSleepCmd;
  uint8 RDUSt_DriveTorqueLimit;
  uint8 RDUSt_BrakeDeccelLimit;
  uint8 RDUSt_VehicleSpdLimit;
  uint16 RDUSt_ErrorStat;
  uint8 RDUSt_LiveCounter;
} SG_RDUSt_sg;

# define Rte_TypeDef_SG_IGWSt_sg
typedef struct
{
  uint8 IGWSt_IGWStat;
  uint8 IGWSt_RouteStat;
  uint16 IGWSt_ErrorStat;
  uint8 IGWSt_LiveCounter;
} SG_IGWSt_sg;

/*************J6L_ADUCAN_END:*************/
/*************GNSS_START:*************/
# define Rte_TypeDef_SG_ADU_Cmd_AECS_sg
typedef struct
{
  uint8 ACS_Enable_Status;
  uint8 ACS_Enable_Status_Counter;
  uint8 V_ADU_Temp_M;
  uint8 V_ADU_Inter_W;
  uint8 V_ADU_Temp_Valid;
  uint8 ACS_Fan_Pwm_Req;
  uint8 ACS_Pump_Pwm_Req;
} SG_ADU_Cmd_AECS_sg;

# define Rte_TypeDef_SG_AECS_Feedback1_sg
typedef struct
{
  uint8 Inlet_RadiatorTemp;
  uint8 Outlet_RadiatorTemp;
  uint8 Fan_AmbientTemp;
  uint8 ECU_AmbientTemp;
  uint8 AECS_Voltage;
  uint8 Fan_SpeedPercent;
  uint8 Pump_SpeedPercent;
  uint8 AECS_Status;
  uint8 Over_Temp_level;
  uint8 AECS_Alive_Counter1;
} SG_AECS_Feedback1_sg;

# define Rte_TypeDef_SG_AECS_Feedback2_sg
typedef struct
{
  uint8 Coolant_Alarm;
  uint8 Fan_AmbientTemp_Alarm;
  uint8 ECU_AmbientTemp_Alarm;
  uint8 Voltage_Alarm;
  uint8 Fan_hardware_Fault;
  uint8 ECU_hardware_Fault;
  uint8 Pump_hardware_Fault;
  uint8 Water_Thermometer_Alarm;
  uint8 AECS_Alive_Counter2;
} SG_AECS_Feedback2_sg;

# define Rte_TypeDef_SG_ACS_Calibration_ADU_sg
typedef struct
{
  uint8 K_ACS_Temp_RFS;
  uint8 K_ACS_Temp_W;
  uint8 K_ACS_Temp_C;
  uint8 K_TimeLast_Over_Temp;
  uint8 K_ADU_Temp_RPS;
  uint8 K_ADU_Temp_RFS;
  uint8 K_ADU_Temp_W;
  uint8 K_ADU_Temp_C;
} SG_ACS_Calibration_ADU_sg;

# define Rte_TypeDef_SG_Time_sg
typedef struct
{
  uint16 GpsWeek;
  uint32 GpsTime;
} SG_Time_sg;

# define Rte_TypeDef_SG_Ang_Rate_Raw_IMU_sg
typedef struct
{
  uint32 AngRateRawX;
  uint32 AngRateRawY;
  uint32 AngRateRawZ;
} SG_Ang_Rate_Raw_IMU_sg;

# define Rte_TypeDef_SG_Accel_IMU_Raw_sg
typedef struct
{
  uint32 AccelRawX;
  uint32 AccelRawY;
  uint32 AccelRawZ;
} SG_Accel_IMU_Raw_sg;

# define Rte_TypeDef_SG_InsStatus_sg
typedef struct
{
  uint8 system_state;
  uint8 GpsNumSatsUsed;
  uint8 satellite_status;
  uint8 GpsNumSats2Used;
  uint16 GpsAge;
  uint8 GpsNumSats;
  uint8 GpsNumSats2;
} SG_InsStatus_sg;

# define Rte_TypeDef_SG_LatitudeLongitude_sg
typedef struct
{
  uint32 PosLat;
  uint32 PosLon;
} SG_LatitudeLongitude_sg;

# define Rte_TypeDef_SG_Altitude_sg
typedef struct
{
  uint32 PosAlt;
} SG_Altitude_sg;

# define Rte_TypeDef_SG_PosSigma_sg
typedef struct
{
  uint32 PosESigma;
  uint32 PosNsigma;
  uint32 PosUsigma;
} SG_PosSigma_sg;

# define Rte_TypeDef_SG_VelocityLevel_sg
typedef struct
{
  uint16 VelE;
  uint16 VelN;
  uint16 VelU;
  uint16 Vel;
} SG_VelocityLevel_sg;

# define Rte_TypeDef_SG_VelocityLevelSigma_sg
typedef struct
{
  uint16 VelESigma;
  uint16 VelNSigma;
  uint16 VelUSigma;
  uint16 VelSigma;
} SG_VelocityLevelSigma_sg;

# define Rte_TypeDef_SG_Accel_Vehicle_sg
typedef struct
{
  uint32 AccelX;
  uint32 AccelY;
  uint32 AccelZ;
} SG_Accel_Vehicle_sg;

# define Rte_TypeDef_SG_HeadingPitchRoll_sg
typedef struct
{
  uint16 AngleHeading;
  uint16 AnglePitch;
  uint16 AngleRoll;
} SG_HeadingPitchRoll_sg;

# define Rte_TypeDef_SG_HeadingPitchRollSigma_sg
typedef struct
{
  uint32 AngleHeadingSigma;
  uint32 AnglePitchSigma;
  uint32 AngleRollSigma;
} SG_HeadingPitchRollSigma_sg;

# define Rte_TypeDef_SG_AngRateVehicle_sg
typedef struct
{
  uint32 AngRateX;
  uint32 AngRateY;
  uint32 AngRateZ;
} SG_AngRateVehicle_sg;

# define Rte_TypeDef_SG_Longitude_sg
typedef struct
{
  uint8 PosLon2[8];
} SG_Longitude_sg;

# define Rte_TypeDef_SG_Latitude_sg
typedef struct
{
  uint8 PosLat2[8];
} SG_Latitude_sg;

/*************GNSS_END:*************/
/*************ARS430_START:*************/
# define Rte_TypeDef_SG_RDF_State_sg
typedef struct
{
  uint8 CRC_SG_RS_Pkt;
  uint8 SQC_SG_RS_Pkt;
  uint8 WakeupRsn_RS_RDF;
  uint8 System_RS_Availability;
  uint8 Blockage_RS_State;
} SG_RDF_State_sg;

# define Rte_TypeDef_SG_RDF_C01_sg
typedef struct
{
  uint8 CRC_SG_RDF_C01_Pkt;
  uint8 SQC_SG_RDF_C01_Pkt;
  uint8 Obj_ID1;
  uint8 RCS_Obj_Cval;
  uint8 TypeObj_Stat_RDF;
  uint8 Obj_eClassification;
  uint8 TnlObsrv_Stat_RDF;
  uint8 uiDynConfidence;
  uint8 uiProbabilityOfExistence;
  uint8 LossObj_Stat_RDF;
  uint8 eMaintenanceState;
} SG_RDF_C01_sg;

# define Rte_TypeDef_SG_RDF_C02_sg
typedef struct
{
  uint8 CRC_SG_RDF_C02_Pkt;
  uint8 SQC_SG_RDF_C02_Pkt;
  uint16 Dist_Y_Obj_Cval_RDF;
  uint16 Dist_X_Obj_Cval_RDF;
  uint8 WidthObj_Cval_RDF;
  uint8 Obj_ID2;
  uint8 Accel_X_Obj_Cval_RDF;
} SG_RDF_C02_sg;

# define Rte_TypeDef_SG_RDF_C03_sg
typedef struct
{
  uint8 CRC_SG_RDF_C03_Pkt;
  uint8 SQC_SG_RDF_C03_Pkt;
  uint16 Spd_X_Obj_Cval_RDF;
  uint8 Obj_ID3;
  uint8 Obj_ucObstacleProbability;
  uint16 Obj_uiLifeCycles;
} SG_RDF_C03_sg;

# define Rte_TypeDef_SG_RDF_C04_sg
typedef struct
{
  uint8 CRC_SG_RDF_C04_Pkt;
  uint8 SQC_SG_RDF_C04_Pkt;
  uint8 StdRng_Y_Obj_Cval_RDF;
  uint8 StdRng_X_Obj_Cval_RDF;
  uint8 StdRngSpd_Y_ObjStati_Cval_RDF;
  uint8 StdRngSpd_X_Obj_Cval_RDF;
  uint16 Spd_Y_Obj_Cval_RDF;
  uint8 Obj_ID4;
} SG_RDF_C04_sg;

# define Rte_TypeDef_SG_RDF_DM1_sg
typedef struct
{
  uint8 DTC_PL_Stat_RDF;
  uint8 DTC_AWL_Stat_RDF;
  uint8 DTC_RSL_Stat_RDF;
  uint8 DTC_MIL_Stat_RDF;
  uint8 DTC_PL_Flash_Stat_RDF;
  uint8 DTC_AWL_Flash_Stat_RDF;
  uint8 DTC_RSL_Flash_Stat_RDF;
  uint8 DTC_MIL_Flash_Stat_RDF;
  uint32 DTC_Stat_RDF;
  uint8 DTC_OccCnt_RDF;
  boolean DTC_SPN_ConvMd_RDF;
} SG_RDF_DM1_sg;

# define Rte_TypeDef_SG_SCA_sg
typedef struct
{
  uint8 CRC_SG_SCA_Pkt;
  uint8 SQC_SG_SCA_Pkt;
  uint8 VehLongMotStateExt_SCA;
  uint8 DrvDirec_Stat_SCA;
  uint8 IgnSw_Stat_SCA;
} SG_SCA_sg;

# define Rte_TypeDef_SG_HRW_FR_sg
typedef struct
{
  uint8 CRC_SG_HRW_FR_Pkt;
  uint8 SQC_SG_HRW_FR_Pkt;
  uint16 SpdFtAxleLtWhl_Cval;
  uint16 SpdFtAxleRtWhl_Cval;
} SG_HRW_FR_sg;

# define Rte_TypeDef_SG_HRW_RE_sg
typedef struct
{
  uint8 CRC_SG_HRW_RE_Pkt;
  uint8 SQC_SG_HRW_RE_Pkt;
  uint16 SpdR_AxleLtWhl_Cval;
  uint16 SpdR_AxleRtWhl_Cval;
} SG_HRW_RE_sg;

# define Rte_TypeDef_SG_BS_E7_sg
typedef struct
{
  uint8 CRC_SG_BS_E7_Pkt;
  uint8 SQC_SG_BS_E7_Pkt;
  uint16 YawRateCorr_Cval_BS;
  uint8 LongitudinalAcceleration_Cval_BS;
} SG_BS_E7_sg;

# define Rte_TypeDef_SG_Brak_Sta_sg
typedef struct
{
  uint8 CRC_SG_Brak_Sta_Pkt;
  uint8 SQC_SG_Brak_Sta_Pkt;
  uint8 ATC_EngCtrl_Stat;
  uint8 ATC_BrkCtrl_Stat;
  uint8 ABS_Actv_Stat;
  uint8 EBS_BrkSw_Rq;
} SG_Brak_Sta_sg;

# define Rte_TypeDef_SG_CI_sg
typedef struct
{
  uint8 Year;
  uint8 Month;
  uint8 Date;
  uint32 Serial_Num;
} SG_CI_sg;

# define Rte_TypeDef_SG_D_RQ_RDF_F1_241_sg
typedef struct
{
  uint8 D_RQ_RDF_F1_241[8];
} SG_D_RQ_RDF_F1_241_sg;

# define Rte_TypeDef_SG_D_RS_RDF_F1_241_sg
typedef struct
{
  uint8 D_RS_RDF_F1_241[8];
} SG_D_RS_RDF_F1_241_sg;

# define Rte_TypeDef_SG_D_RQ_GLOBAL_UDS_F1_241_sg
typedef struct
{
  uint8 D_RQ_GLOBAL_UDS_F1_241[8];
} SG_D_RQ_GLOBAL_UDS_F1_241_sg;

/*************ARS430_END:*************/
/*************ARS408_START:*************/
# define Rte_TypeDef_SG_RadarState_sg
typedef struct
{
  boolean RadarState_NVMwriteStatus;
  boolean RadarState_NVMReadStatus;
  uint16 RadarState_MaxDistanceCfg;
  boolean RadarState_Persistent_Error;
  boolean RadarState_Interference;
  boolean RadarState_Temperature_Error;
  boolean RadarState_Temporary_Error;
  boolean RadarState_Voltage_Error;
  uint8 RadarState_RadarPowerCfg;
  uint8 RadarState_SortIndex;
  uint8 RadarState_SensorID;
  uint8 RadarState_MotionRxState;
  boolean RadarState_SendExtInfoCfg;
  boolean RadarState_SendQualityCfg;
  uint8 RadarState_OutputTypeCfg;
  boolean RadarState_CtrlRelayCfg;
  uint8 RadarState_RCS_Threshold;
} SG_RadarState_sg;

# define Rte_TypeDef_SG_VersionID_sg
typedef struct
{
  uint8 Version_MajorRelease;
  uint8 Version_MinorRelease;
  uint8 Version_PatchLevel;
  boolean Version_ExtendedRange;
  boolean Version_CountryCode;
} SG_VersionID_sg;

# define Rte_TypeDef_SG_Obj_0_Status_sg
typedef struct
{
  uint8 Obj_NofObjects;
  uint16 Obj_MeasCounter;
  uint8 Obj_InterfaceVersion;
} SG_Obj_0_Status_sg;

# define Rte_TypeDef_SG_Obj_1_General_sg
typedef struct
{
  uint8 Obj_ID;
  uint16 Obj_DistLong;
  uint16 Obj_DistLat;
  uint16 Obj_VrelLong;
  uint16 Obj_VrelLat;
  uint8 Obj_DynProp;
  uint8 Obj_RCS;
} SG_Obj_1_General_sg;

# define Rte_TypeDef_SG_Obj_2_Quality_sg
typedef struct
{
  uint8 Obj_ID;
  uint8 Obj_DistLong_rms;
  uint8 Obj_DistLat_rms;
  uint8 Obj_VrelLong_rms;
  uint8 Obj_VrelLat_rms;
  uint8 Obj_ArelLong_rms;
  uint8 Obj_ArelLat_rms;
  uint8 Obj_Orientation_rms;
  uint8 Obj_ProbOfExist;
  uint8 Obj_MeasState;
} SG_Obj_2_Quality_sg;

# define Rte_TypeDef_SG_Obj_3_Extended_sg
typedef struct
{
  uint8 Obj_ID;
  uint16 Obj_ArelLong;
  uint16 Obj_ArelLat;
  uint8 Obj_Class;
  uint16 Obj_OrientationAngle;
  uint8 Obj_Length;
  uint8 Obj_Width;
} SG_Obj_3_Extended_sg;

/*************ARS408_END:*************/
/*************DEV_START:*************/
# define Rte_TypeDef_SG_msg_XCP_Response_MyECU_sg
typedef struct
{
  uint8 Signal_XCP_Response_MyECU[8];
} SG_msg_XCP_Response_MyECU_sg;

# define Rte_TypeDef_SG_msg_XCP_Request_MyECU_sg
typedef struct
{
  uint8 Signal_XCP_Request_MyECU[8];
} SG_msg_XCP_Request_MyECU_sg;

# define Rte_TypeDef_SG_TaskInfo_sg
typedef struct
{
  uint8 AverExcnt;
  uint32 AverExtime;
  uint8 AverPercnt;
  uint32 AverPertime;
  uint8 Coreindex;
  uint8 Excount;
  uint32 Exmax;
  uint32 Exmin;
  uint32 Extime;
  uint8 Percount;
  uint8 PerFtEn;
  uint32 Permax;
  uint32 Permin;
  uint32 Pertime;
  uint8 Runableindex;
  uint32 SumExtime;
  uint32 SumPertime;
  uint8 Taskindex;
  uint8 TmFlag;
} SG_TaskInfo_sg;

# define Rte_TypeDef_SG_CpuInfo_sg
typedef struct
{
  uint16 CpuLoad_Core0;
  uint16 Cpuload_Core0_Max;
  uint16 Cpuload_Core0_Min;
  uint16 CpuLoad_Core1;
  uint16 Cpuload_Core1_Max;
  uint16 Cpuload_Core1_Min;
  uint16 CpuLoad_Core2;
  uint16 Cpuload_Core2_Max;
  uint16 Cpuload_Core2_Min;
  uint16 CpuLoad_Core3;
  uint16 Cpuload_Core3_Max;
  uint16 Cpuload_Core3_Min;
  uint16 CpuLoad_Core4;
  uint16 Cpuload_Core4_Max;
  uint16 Cpuload_Core4_Min;
  uint16 CpuLoad_Core5;
  uint16 Cpuload_Core5_Max;
  uint16 Cpuload_Core5_Min;
  uint8 Current_Time[8];
  uint8 Error_Time[8];
  uint16 Error_Time_CNT;
  uint8 VER_Head;
  uint8 VER_Major;
  uint8 VER_Revise;
  uint8 VER_Sub;
} SG_CpuInfo_sg;

# define Rte_TypeDef_SG_FrameDiagInfo_sg
typedef struct
{
  uint32 ARS430_LoseFrame;
  uint32 ZIC_LoseFrame;
  uint32 GNSS_LoseFrame;
  uint32 CR5TP_RF_LoseFrame;
  uint32 CR5TP_LF_LoseFrame;
  uint32 ARS408_LoseFrame;
  uint32 ARS430_TimeFault;
  uint32 ZIC_TimeFault;
  uint32 GNSS_TimeFault;
  uint32 CR5TP_RF_TimeFault;
  uint32 CR5TP_LF_TimeFault;
  uint32 ARS408_TimeFault;
} SG_FrameDiagInfo_sg;

# define Rte_TypeDef_SG_EMR_EventInfo_sg
typedef struct
{
  uint16 EMR_EventInfo1;
  uint16 EMR_EventInfo2;
  uint16 EMR_EventInfo3;
  uint16 EMR_EventInfo4;
  uint16 EMR_EventInfo5;
  uint16 EMR_EventInfo6;
  uint16 EMR_EventInfo7;
  uint16 EMR_EventInfo8;
  uint16 EMR_EventInfo9;
  uint16 EMR_EventInfo10;
  uint16 EMR_EventInfo11;
  uint16 EMR_EventInfo12;
  uint16 EMR_EventInfo13;
  uint16 EMR_EventInfo14;
  uint16 EMR_EventInfo15;
  uint16 EMR_EventInfo16;
  uint16 EMR_EventInfo17;
  uint16 EMR_EventInfo18;
  uint16 EMR_EventInfo19;
  uint16 EMR_EventInfo20;
  uint16 EMR_EventInfo21;
  uint16 EMR_EventInfo22;
  uint16 EMR_EventInfo23;
  uint16 EMR_EventInfo24;
  uint16 EMR_EventInfo25;
  uint16 EMR_EventInfo26;
  uint16 EMR_EventInfo27;
  uint16 EMR_EventInfo28;
  uint16 EMR_EventInfo29;
  uint16 EMR_EventInfo30;
  uint16 EMR_EventInfo31;
  uint16 EMR_EventInfo32;
} SG_EMR_EventInfo_sg;

# define Rte_TypeDef_SG_EMR_Info_sg
typedef struct
{
  boolean LRRdrErr;
  boolean RRRdrErr;
  boolean RRCamErr;
  boolean LRCamErr;
  boolean TurnLvrErr;
  boolean DMSErr;
  boolean DMSAbnormal;
  boolean HODErr;
  boolean FrntLongCamErr;
  boolean EPBErr;
  boolean CCPErr;
  boolean DrvrTrqErr;
  boolean BrkPedlPstnErr;
  boolean AccelPedlPstnErr;
  boolean SPSwtErr;
  boolean MSWErr;
  boolean RotyKnobSigErr;
  boolean EPBSwtErr;
  boolean HzrdSwtErr;
  boolean HzrdSigErr;
  boolean DoorLockErr;
  boolean LowSpdModeErr;
  boolean TirePSigErr;
  boolean FuLvlErr;
  boolean FLMidDisCamErr;
  boolean FRMidDisCamErr;
  boolean FNearDisCamErr;
  boolean FLcornrCamErr;
  boolean FRcornrCamErr;
  boolean FrntLongRdrErr;
  boolean LFCornrRdrErr;
  boolean FRcornrRdrErr;
  boolean FrntMidLdrErr;
  boolean H2PUErr;
  boolean LvDegrdSocErr;
  boolean BSDSocErr;
  boolean LvDegrdMultiCamErr;
  boolean MultiCamErr;
  boolean LvDegrdEBSErr;
  boolean AEBEBSErr;
  boolean ABSErr;
  boolean ESCErr;
  boolean EMSErr;
  boolean LvDegrdTCUErr;
  boolean TCUErr;
  boolean BCMErr;
  boolean BrkPedlCmplErr;
  boolean VehSpdSigErr;
  boolean WhlSpdSigErr;
  boolean AccelSigErr;
  boolean StrAnglSigErr;
  boolean YawRateSigErr;
  boolean StrAnglSpdErr;
  boolean StrSupRedLvErr;
  boolean StrMotTrqErr;
  boolean EmergeStrStat;
  boolean CH2Busoff;
  boolean PTBusoff;
  boolean ComBusoff;
  boolean FrntRdrBusoff;
  boolean H2PUCommErr;
  boolean LidarETH3CommErr;
  boolean ZICBusoff;
  boolean EPSSeriousErr;
  boolean EPSStateErr;
  boolean PMSErr;
  boolean LvDegrdMCUErr;
  boolean BSDMCUErr;
  boolean CH1Busoff;
  boolean PMSLightErr;
  boolean ETH1CommErr;
  boolean BrkWireCtrlNoSatisfy;
  boolean FuncSafeCPLv4Err;
  boolean FuncSafeCPLv3Err;
  boolean LDWSwtErr;
  boolean BSDSwtErr;
  boolean AEBSwtErr;
  boolean MCUCheckFinished;
  uint8 PDUTimeOut;
  uint8 EMR_DataNumber;
  uint16 Core0Cpuload;
  uint16 Core1Cpuload;
  uint16 Core2Cpuload;
  uint16 Core3Cpuload;
  uint16 Core4Cpuload;
  uint16 Core5Cpuload;
  uint8 TimeStanmp_Reserved[8];
} SG_EMR_Info_sg;

# define Rte_TypeDef_SG_DIAG_RQ_sg
typedef struct
{
  uint8 DIAG_RQ1[8];
} SG_DIAG_RQ_sg;

# define Rte_TypeDef_SG_DIAG_RS_sg
typedef struct
{
  uint8 DIAG_RS1[8];
} SG_DIAG_RS_sg;

# define Rte_TypeDef_SG_PhysDiagReqMsg_69_F2_Vic4_sg
typedef struct
{
  uint8 PhysDiagReqSig_69_F2[8];
} SG_PhysDiagReqMsg_69_F2_Vic4_sg;

# define Rte_TypeDef_SG_PhysDiagReqMsg_6B_F2_Vic4_sg
typedef struct
{
  uint8 PhysDiagReqSig_6B_F2[8];
} SG_PhysDiagReqMsg_6B_F2_Vic4_sg;

# define Rte_TypeDef_SG_PhysDiagRespMsg_F2_69_Vic4_sg
typedef struct
{
  uint8 PhysDiagRespSig_F2_69[8];
} SG_PhysDiagRespMsg_F2_69_Vic4_sg;

# define Rte_TypeDef_SG_PhysDiagRespMsg_F2_6B_Vic4_sg
typedef struct
{
  uint8 PhysDiagRespSig_F2_6B[8];
} SG_PhysDiagRespMsg_F2_6B_Vic4_sg;

# define Rte_TypeDef_SG_DiagFaultStat_SRRF_sg
typedef struct
{
  uint8 DiagFaultStat_SRRF_EcuAdr;
  uint16 DiagFaultStat_SRRF_DtcIdA;
  uint8 DiagFaultStat_SRRF_FailTA;
  uint16 DiagFaultStat_SRRF_DtcIdB;
  uint8 DiagFaultStat_SRRF_FailTB;
  boolean DiagFaultStat_SRRF_sg_UB;
} SG_DiagFaultStat_SRRF_sg;

# define Rte_TypeDef_SG_DiagFaultStat_SRLF_sg
typedef struct
{
  uint8 DiagFaultStat_SRLF_EcuAdr;
  uint16 DiagFaultStat_SRLF_DtcIdA;
  uint8 DiagFaultStat_SRLF_FailTA;
  uint16 DiagFaultStat_SRLF_DtcIdB;
  uint8 DiagFaultStat_SRLF_FailTB;
  boolean DiagFaultStat_SRLF_sg_UB;
} SG_DiagFaultStat_SRLF_sg;

# define Rte_TypeDef_SG_TesterFuncDiagMsg_sg
typedef struct
{
  uint8 FuncDiagDataTester[8];
} SG_TesterFuncDiagMsg_sg;

/*************DEV_END:*************/
# define Rte_TypeDef_Rx_Flag_Type
typedef enum {
  RX_FLAG_DEF = 0x00,
  RX_FLAG_RCV,
  RX_FLAG_CLR, 
} Rx_Flag_Type;

# define Rte_TypeDef_CCVS1_SigStatusType
typedef struct 
{
  uint8 brakeSwitchStat:1u;
  uint8 reserve:7u;
} CCVS1_SigStatusType;

# define Rte_TypeDef_EBC1_SigStatusType
typedef struct 
{
  uint8 brakePedalPstnStat:1u;
  uint8 reserve:7u;
} EBC1_SigStatusType;

# define Rte_TypeDef_EBC2_SigStatusType
typedef struct 
{
  uint8 frontAxleSpeedStat:1u;
  uint8 relSpdFAxleLWhlStat:1u;
  uint8 relSpdFAxleRWhlStat:1u;
  uint8 relSpdRAxleLWhlStat:1u;
  uint8 relSpdRAxleRWhlStat:1u;
  uint8 reserve:3u;
} EBC2_SigStatusType;

# define Rte_TypeDef_EEC2_SigStatusType
typedef struct 
{
  uint8 accelPedalPstnStat:1u;
  uint8 reserve:7u;
} EEC2_SigStatusType;

# define Rte_TypeDef_EPB1_SigStatusType
typedef struct 
{
  uint8 stateOfEPBStat:1u;
  uint8 reserve:7u;
} EPB1_SigStatusType;

# define Rte_TypeDef_EPS2_SigStatusType
typedef struct 
{
  uint8 absSteerPstnStat:1u;
  uint8 actualModeStat:1u;
  uint8 reserve:6u;
} EPS2_SigStatusType;

# define Rte_TypeDef_ETC2_SigStatusType
typedef struct 
{
  uint8 transCurGearStat:1u;
  uint8 transActGearRatioStat:1u;
  uint8 reserve:6u;
} ETC2_SigStatusType;

# define Rte_TypeDef_LC_SigStatusType
typedef struct 
{
  uint8 leftTurnSigLightsCmdStat:1u;
  uint8 rightTurnSigLightsCmdStat:1u;
  uint8 highBeamHeadLightCmdStat:1u;
  uint8 lowBeamHeadLightCmdStat:1u;
  uint8 reserve:4u;
} LC_SigStatusType;

# define Rte_TypeDef_MCU1_SigStatusType
typedef struct 
{
  uint8 motorTrqStat:1u;
  uint8 reserve:7u;
} MCU1_SigStatusType;

# define Rte_TypeDef_PS1_SigStatusType
typedef struct 
{
  uint8 ignitionPstnStat:1u;
  uint8 reserve:7u;
} PS1_SigStatusType;

# define Rte_TypeDef_VCU_Status_SigStatusType
typedef struct 
{
  uint8 VCUModeStat:1u;
  uint8 reserve:7u;
} VCU_Status_SigStatusType;

# define Rte_TypeDef_VDC2_SigStatusType
typedef struct 
{
  uint8 longitudinalAccStat:1u;
  uint8 lateralAccStat:1u;
  uint8 yawRateStat:1u;
  uint8 reserve:5u;
} VDC2_SigStatusType;

# define Rte_TypeDef_rt_rt_Array_uint8_6876
typedef uint8 rt_Array_uint8_6876[6876];

# define Rte_TypeDef_rt_rt_Array_uint8_5192
typedef uint8 rt_Array_uint8_5192[5192];

# define Rte_TypeDef_rt_rt_Array_uint8_224
typedef uint8 rt_Array_uint8_224[224];

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

# define Rte_TypeDef_RxSocAdminDataType

typedef struct
{
  ADMInfoSOC2MCU ADMData;
  LocalizationInfo LocalizationData;
  PlanningInfo PlanningData;
} RxSocAdminDataType;

# define Rte_TypeDef_Signal_Status_Type
typedef enum {
  SIG_ST_NOT_RCV = 0x00, //未收到过该信号
  SIG_ST_NRM = 0x01, //收到了信号，信号值正常
  SIG_ST_ABNRM = 0x02, //收到了信号，信号值异常
  SIG_ST_NOT_UD = 0x03, //信号未更新
  SIG_ST_NOT_SUP = 0x04, //不支持该信号
  SIG_ST_MAX = 0xFFFFFFFF
} Signal_Status_Type;

# define Rte_TypeDef_Project_ID

typedef enum {
  ZT_DEFAULT = 0x00, //初始值
  ZT_1301 = 0x01, //编队项目
  ZT_2103 = 0x02, //高速项目
  ZT_2106 = 0x03, //环卫项目
  ZT_2366 = 0x04, //劲旅项目
  PROJECT_MAX = 0xFFFFFFFF
} Project_ID;

# define Rte_TypeDef_ZT_1301_Message_Type

typedef struct
{
    uint32 remote_engstarorstopbutton;
    /*Description: 远程点火关闭开关;Unit:  ; MinValue:0 ; MaxValue: 3; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/ 
    Signal_Status_Type remote_engstarorstopbutton_status;
    /*Description: 远程点火关闭开关信号接收状态
    * 0：未收到该信号
    * 1：收到该信号且该信号正常
    * 2：该信号异常;Unit:  ; MinValue:0; MaxValue:2; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/ 
    uint32 remote_engstarorstopbutton_dT;
    /*Description: 远程点火关闭开关信号时延;Unit:ms  ; MinValue: ; MaxValue: ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:;1301*/ 
    
    float32 engspd;
    /*Description: 发动机转速;Unit:rpm  ; MinValue:0 ; MaxValue: 8031.875; InitValue:0 ; ErrorValue:floatMax ; PS: ;  Projects:1301;*/ 
    Signal_Status_Type engspd_status;
    /*Description: 发动机转速信号接收状态
    * 0：未收到该信号
    * 1：收到该信号且该信号正常
    * 2：该信号异常;Unit:  ; MinValue:0; MaxValue:2; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/ 
    uint32 engspd_dT;
    /*Description: 发动机转速信号时延;Unit:ms  ; MinValue: ; MaxValue: ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:;1301*/ 

    uint32 Switch_ADCtrl;
    /*Description: 自动驾驶功能开关
    * Enum:
    * 0x0:自动驾驶关闭
    * 0x1:自动驾驶打开(默认)  ;  Unit: ; MinValue: 0; MaxValue:3 ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    Signal_Status_Type Switch_ADCtrl_status;
    /*Description: 自动驾驶功能开关信号接收状态;
    *  0：未收到该信号
    *  1：收到该信号且该信号正常
    *  2：该信号异常Unit:  ; MinValue: 0; MaxValue:2; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    uint32 Switch_ADCtrl_dT;
    /*Description: 自动驾驶功能开关信号时延; Unit: ms   ; MinValue: ; MaxValue:  ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/

    uint32 Switch_FaultN02;
    /*Description: 2号故障开关
    * Enum:
    * 0x0:无故障(默认)
    * 0x1:模拟故障  ;  Unit: ; MinValue: 0; MaxValue:3 ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    Signal_Status_Type Switch_FaultN02_status;
    /*Description: 2号故障开关信号接收状态;
    *  0：未收到该信号
    *  1：收到该信号且该信号正常
    *  2：该信号异常Unit:  ; MinValue: 0; MaxValue:2; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    uint32 Switch_FaultN02_dT;
    /*Description: 2号故障开关信号时延; Unit: ms   ; MinValue: ; MaxValue:  ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/

    uint32 Switch_FaultN01;
    /*Description: 1号故障开关
    * Enum:
    * 0x0:无故障(默认)
    * 0x1:模拟故障  ;  Unit: ; MinValue: 0; MaxValue:3 ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    Signal_Status_Type Switch_FaultN01_status;
    /*Description: 1号故障开关信号接收状态;
    *  0：未收到该信号
    *  1：收到该信号且该信号正常
    *  2：该信号异常Unit:  ; MinValue: 0; MaxValue:2; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    uint32 Switch_FaultN01_dT;
    /*Description: 1号故障开关信号时延; Unit: ms   ; MinValue: ; MaxValue:  ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/

    uint32 Switch_IG_Off;
    /*Description: 遥控熄火按钮
    * Enum:
    * 0x0:无作用
    * 0x1:车队熄火  ;  Unit: ; MinValue: 0; MaxValue:3 ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    Signal_Status_Type Switch_IG_Off_status;
    /*Description: 遥控熄火按钮信号接收状态;
    *  0：未收到该信号
    *  1：收到该信号且该信号正常
    *  2：该信号异常Unit:  ; MinValue: 0; MaxValue:2; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    uint32 Switch_IG_Off_dT;
    /*Description: 遥控熄火按钮信号时延; Unit: ms   ; MinValue: ; MaxValue:  ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/

    uint32 Switch_IG_On;
    /*Description: 遥控点火按钮
    * Enum:
    * 0x0:无作用
    * 0x1:车队点火  ;  Unit: ; MinValue: 0; MaxValue:3 ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    Signal_Status_Type Switch_IG_On_status;
    /*Description: 遥控点火按钮信号接收状态;
    *  0：未收到该信号
    *  1：收到该信号且该信号正常
    *  2：该信号异常Unit:  ; MinValue: 0; MaxValue:2; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    uint32 Switch_IG_On_dT;
    /*Description: 遥控点火按钮信号时延; Unit: ms   ; MinValue: ; MaxValue:  ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/

    uint32 Switch_Load0;
    /*Description: 0吨载荷开关
    * Enum:
    * 0x0:无作用(默认)
    * 0x1:0吨载荷  ;  Unit: ; MinValue: 0; MaxValue:3 ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    Signal_Status_Type Switch_Load0_status;
    /*Description: 0吨载荷开关信号接收状态;
    *  0：未收到该信号
    *  1：收到该信号且该信号正常
    *  2：该信号异常Unit:  ; MinValue: 0; MaxValue:2; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    uint32 Switch_Load0_dT;
    /*Description: 0吨载荷开关信号时延; Unit: ms   ; MinValue: ; MaxValue:  ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/

    uint32 Switch_Load12;
    /*Description: 12吨载荷开关
    * Enum:
    * 0x0:无作用(默认)
    * 0x1:12吨载荷  ;  Unit: ; MinValue: 0; MaxValue:3 ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    Signal_Status_Type Switch_Load12_status;
    /*Description: 12吨载荷开关信号接收状态;
    *  0：未收到该信号
    *  1：收到该信号且该信号正常
    *  2：该信号异常Unit:  ; MinValue: 0; MaxValue:2; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    uint32 Switch_Load12_dT;
    /*Description: 12吨载荷开关信号时延; Unit: ms   ; MinValue: ; MaxValue:  ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/

    uint32 Switch_Load4;
    /*Description: 4吨载荷开关
    * Enum:
    * 0x0:无作用(默认)
    * 0x1:4吨载荷  ;  Unit: ; MinValue: 0; MaxValue:3 ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    Signal_Status_Type Switch_Load4_status;
    /*Description: 4吨载荷开关信号接收状态;
    *  0：未收到该信号
    *  1：收到该信号且该信号正常
    *  2：该信号异常Unit:  ; MinValue: 0; MaxValue:2; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    uint32 Switch_Load4_dT;
    /*Description: 4吨载荷开关信号时延; Unit: ms   ; MinValue: ; MaxValue:  ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/

    uint32 Switch_Load8;
    /*Description: 8吨载荷开关
    * Enum:
    * 0x0:无作用(默认)
    * 0x1:8吨载荷  ;  Unit: ; MinValue: 0; MaxValue:3 ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    Signal_Status_Type Switch_Load8_status;
    /*Description: 8吨载荷开关信号接收状态;
    *  0：未收到该信号
    *  1：收到该信号且该信号正常
    *  2：该信号异常Unit:  ; MinValue: 0; MaxValue:2; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    uint32 Switch_Load8_dT;
    /*Description: 8吨载荷开关信号时延; Unit: ms   ; MinValue: ; MaxValue:  ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/

    uint32 Switch_PlatoonCancel;
    /*Description: 编队取消摁扭
    * Enum:
    * 0x0:无作用
    * 0x1:编队取消  ;  Unit: ; MinValue: 0; MaxValue:3 ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    Signal_Status_Type Switch_PlatoonCancel_status;
    /*Description: 编队取消摁扭信号接收状态;
    *  0：未收到该信号
    *  1：收到该信号且该信号正常
    *  2：该信号异常Unit:  ; MinValue: 0; MaxValue:2; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    uint32 Switch_PlatoonCancel_dT;
    /*Description: 编队取消摁扭信号时延; Unit: ms   ; MinValue: ; MaxValue:  ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/

    uint32 Switch_PlatoonDriveActive;
    /*Description: 行驶激活按钮
    * Enum:
    * 0x0:无作用
    * 0x1:启动激活  ;  Unit: ; MinValue: 0; MaxValue:3 ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    Signal_Status_Type Switch_PlatoonDriveActive_status;
    /*Description: 行驶激活按钮信号接收状态;
    *  0：未收到该信号
    *  1：收到该信号且该信号正常
    *  2：该信号异常Unit:  ; MinValue: 0; MaxValue:2; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    uint32 Switch_PlatoonDriveActive_dT;
    /*Description: 行驶激活按钮信号时延; Unit: ms   ; MinValue: ; MaxValue:  ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/

    uint32 Switch_PlatoonDriveDeactive;
    /*Description: 行驶取消按钮
    * Enum:
    * 0x0:无作用
    * 0x1:行驶取消  ;  Unit: ; MinValue: 0; MaxValue:3 ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    Signal_Status_Type Switch_PlatoonDriveDeactive_status;
    /*Description: 行驶取消按钮信号接收状态;
    *  0：未收到该信号
    *  1：收到该信号且该信号正常
    *  2：该信号异常Unit:  ; MinValue: 0; MaxValue:2; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    uint32 Switch_PlatoonDriveDeactive_dT;
    /*Description: 行驶取消按钮信号时延; Unit: ms   ; MinValue: ; MaxValue:  ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/

    uint32 Switch_PlatoonMode;
    /*Description: 编队模式开关
    * Enum:
    * 0x0:跟车(默认)
    * 0x1:头车  ;  Unit: ; MinValue: 0; MaxValue:3 ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    Signal_Status_Type Switch_PlatoonMode_status;
    /*Description: 编队模式开关信号接收状态;
    *  0：未收到该信号
    *  1：收到该信号且该信号正常
    *  2：该信号异常Unit:  ; MinValue: 0; MaxValue:2; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    uint32 Switch_PlatoonMode_dT;
    /*Description: 编队模式开关信号时延; Unit: ms   ; MinValue: ; MaxValue:  ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/

    uint32 Switch_PlatoonType;
    /*Description: 队形开关
    * Enum:
    * 0x0:一字型(默认)
    * 0x1:品字型  ;  Unit: ; MinValue: 0; MaxValue:15 ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    Signal_Status_Type Switch_PlatoonType_status;
    /*Description: 队形开关信号接收状态;
    *  0：未收到该信号
    *  1：收到该信号且该信号正常
    *  2：该信号异常Unit:  ; MinValue: 0; MaxValue:2; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    uint32 Switch_PlatoonType_dT;
    /*Description: 队形开关信号时延; Unit: ms   ; MinValue: ; MaxValue:  ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/

    uint32 IGWSt_RouteStat;
    /*Description: 网关仲裁后的响应指令源
    * Enum:
    * 0x0:Default
    * 0x1:ADU
    * 0x2:RDU
    * 0x3:RCU
    * 0x4:IGW  ;  Unit: ; MinValue: 0; MaxValue:7 ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    Signal_Status_Type IGWSt_RouteStat_status;
    /*Description: 网关仲裁后的响应指令源信号接收状态;
    *  0：未收到该信号
    *  1：收到该信号且该信号正常
    *  2：该信号异常Unit:  ; MinValue: 0; MaxValue:2; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/
    uint32 IGWSt_RouteStat_dT;
    /*Description: 网关仲裁后的响应指令源信号时延; Unit: ms   ; MinValue: ; MaxValue:  ; InitValue:0 ; ErrorValue:uint32_tMax ; PS: ;  Projects:1301;*/

} ZT_1301_Message_Type;

# define Rte_TypeDef_ZT_2103_Message_Type

typedef struct
{
  uint32 ZT_2103_Reserved;
} ZT_2103_Message_Type;

# define Rte_TypeDef_ZT_2106_Message_Type

/** ZT_2106 Signal Definition */
typedef struct
{
  uint32 ZT_2106_Reserved;
} ZT_2106_Message_Type;

# define Rte_TypeDef_ZT_2366_Message_Type

/** ZT_2366 Signal Definition */
typedef struct
{
  uint32 ZT_2366_Reserved;
} ZT_2366_Message_Type;

# define Rte_TypeDef_Product_Message_Type

typedef union {
  uint32 Space_Def[150];
  ZT_1301_Message_Type ZT_1301_Message_Data;
  ZT_2103_Message_Type ZT_2103_Message_Data;
  ZT_2106_Message_Type ZT_2106_Message_Data;
  ZT_2366_Message_Type ZT_2366_Message_Data;
} Product_Message_Type;

# define Rte_TypeDef_Chassis_Info_Type

typedef struct
{
  uint32 Rolling_Count;
  uint32 IDC_Time_L;
  uint32 IDC_Time_H;
  uint32 SDC_Time_L;
  uint32 SDC_Time_H;
  /* 自车车速  Unit:m/s */
	float32 speed_mps;
   /* 自车车速信号接收状态 */
	Signal_Status_Type speed_mps_status;
   /* 自车车速信号时延 ms */
	uint32 speed_mps_dT;

   /* 左前轮轮速  Unit:m/s */
	float32 wheel_spd_fl;
   /* 左前轮轮速信号接收状态 */
	Signal_Status_Type wheel_spd_fl_status;
   /* 左前轮轮速信号时延 ms */
	uint32 wheel_spd_fl_dT;

   /* 右前轮轮速  Unit:m/s */
	float32 wheel_spd_fr;
   /* 右前轮轮速信号接收状态 */
	Signal_Status_Type wheel_spd_fr_status;
   /* 右前轮轮速信号时延 ms */
	uint32 wheel_spd_fr_dT;

   /* 左后轮轮速  Unit:m/s */
	float32 wheel_spd_rl;
   /* 左后轮轮速信号接收状态 */
	Signal_Status_Type wheel_spd_rl_status;
   /* 左后轮轮速信号时延 ms */
	uint32 wheel_spd_rl_dT;

   /* 右后轮轮速  Unit:m/s */
	float32 wheel_spd_rr;
   /* 右后轮轮速信号接收状态 */
	Signal_Status_Type wheel_spd_rr_status;
   /* 右后轮轮速信号时延 ms */
	uint32 wheel_spd_rr_dT;

   /* 自车纵向加速度  Unit:m/s^2 */
	float32 longitude_acc;
   /* 自车纵向加速度信号接收状态 */
	Signal_Status_Type longitude_acc_status;
   /* 自车纵向加速度信号时延 ms */
	uint32 longitude_acc_dT; 

   /* 自车横向加速度  Unit:m/s^2 */
	float32 lateral_acc;
   /* 自车横向加速度信号接收状态 */
	Signal_Status_Type lateral_acc_status;
   /* 自车横向加速度信号时延 ms */
	uint32 lateral_acc_dT;

   /* 加速踏板位置百分比  Unit:%<"\%"> */
	float32 accel_pedal_position;
   /* 加速踏板位置百分比信号接收状态 */
	Signal_Status_Type accel_pedal_position_status;
   /* 加速踏板位置百分比信号时延 ms */
	uint32 accel_pedal_position_dT;

   /* 制动踏板位置百分比  Unit:%<"\%"> */
	float32 brake_pedal_position;
   /* 制动踏板位置百分比信号接收状态 */
	Signal_Status_Type brake_pedal_position_status;
   /* 制动踏板位置百分比信号时延 ms */
	uint32 brake_pedal_position_dT;

   /* 当前挡位 */
  	sint32 gear_location;
   /* 当前挡位信号接收状态 */
	Signal_Status_Type gear_location_status;
   /* 当前挡位信号时延 ms */
	uint32 gear_location_dT;	

   /* 制动是否触发
     Enum:
     0x0:De-actived
     0x1:Actived
   */
  	uint32 brake_switch;
   /* 制动开关信号接收状态 */
	Signal_Status_Type brake_switch_status;
   /* 制动开关信号时延 ms */
	uint32 brake_switch_dT;

   /* 手刹是否激活
     Enum:
     0x0:De-actived
     0x1:Actived
   */
	uint32 parking_brake_switch;
   /* 手刹开关信号接收状态 */
	Signal_Status_Type parking_brake_switch_status;
   /* 手刹开关信号时延 ms */
	uint32 parking_brake_switch_dT;

   /* 电机参考扭矩  Unit:Nm */
  	float32 motor_reference_torque;
   /* 电机参考扭矩信号接收状态 */
	Signal_Status_Type motor_reference_torque_status;
   /* 电机参考扭矩信号时延 ms */
	uint32 motor_reference_torque_dT;

   /* 电机实际扭矩  Unit:%<"\%"> */
	float32 actual_motor_torque;
   /* 电机实际扭矩信号接收状态 */
	Signal_Status_Type actual_motor_torque_status;
   /* 电机实际扭矩信号时延 ms */
	uint32 actual_motor_torque_dT;

   /* 发动机参考扭矩  Unit:Nm */
	float32 engine_reference_torque;
   /* 发动机参考扭矩信号接收状态 */
	Signal_Status_Type engine_reference_torque_status;
   /* 发动机参考扭矩信号时延 ms */
	uint32 engine_reference_torque_dT;

   /* 发动机实际扭矩  Unit:%<"\%"> */
	float32 actual_engine_torque;
   /* 发动机实际扭矩信号接收状态 */
	Signal_Status_Type actual_engine_torque_status;
   /* 发动机实际扭矩信号时延 ms */
	uint32 actual_engine_torque_dT;

   /* 转速比 */
	float32 gear_ratio;
   /* 转速比信号接收状态 */
	Signal_Status_Type gear_ratio_status;
   /* 转速比信号时延 ms */
	uint32 gear_ratio_dT;

   /* 转向角度  Unit:rad */
	float32 steering_angle;
   /* 转向角度信号接收状态 */
	Signal_Status_Type steering_angle_status;
   /* 转向角度信号时延 ms */
	uint32 steering_angle_dT;

   /* 转向角度变化率  Unit:rad/s */
	float32 steering_angle_velocity;
   /* 转向角度变化率信号接收状态 */
	Signal_Status_Type steering_angle_velocity_status;
   /* 转向角度变化率信号时延 ms */
	uint32 steering_angle_velocity_dT;

   /* 自车横摆率  Unit:rad/s */
	float32 yaw_rate;
   /* 自车横摆率信号接收状态 */
	Signal_Status_Type yaw_rate_status;
   /* 自车横摆率信号时延 ms */
	uint32 yaw_rate_dT;	

   /* 驾驶员手力矩  Unit:Nm */
	float32 driver_hand_torque;
   /* 驾驶员手力矩信号接收状态 */
	Signal_Status_Type driver_hand_torque_status;
   /* 驾驶员手力矩信号时延 ms */
	uint32 driver_hand_torque_dT;

   /* 左转向灯状态
     Enum:
     0x0:De-actived
     0x1:Actived
   */
	uint32 left_turn_signal;
   /* 左转向灯状态信号接收状态 */
	Signal_Status_Type left_turn_signal_status;
   /* 左转向灯状态信号时延 ms */
	uint32 left_turn_signal_dT;

   /* 右转向灯状态
     Enum:
     0x0:De-actived
     0x1:Actived
   */
	uint32 right_turn_signal;
   /* 右转向灯状态信号接收状态 */
	Signal_Status_Type right_turn_signal_status;
   /* 右转向灯状态信号时延 ms */
	uint32 right_turn_signal_dT;

   /* 自动驾驶主开关
     0 -  OFF
     1 -  ON 
   */
	uint32 auto_drving_main_swtich;
   /* 自动驾驶主开关信号接收状态 */
	Signal_Status_Type auto_drving_main_swtich_status;
   /* 自动驾驶主开关信号时延 ms */
	uint32 auto_drving_main_swtich_dT;

   /* 远光灯信号 
     Enum:
     0x0:De-actived
     0x1:Actived 
   */
	uint32 high_beam_signal;
   /* 远光灯信号信号接收状态 */
	Signal_Status_Type high_beam_signal_status;
   /* 远光灯信号信号时延 ms */
	uint32 high_beam_signal_dT;
   
   /* 近光灯信号
     Enum:
     0x0:De-actived
     0x1:Actived  
   */
	uint32 low_beam_signal;
   /* 近光灯信号信号接收状态 */
	Signal_Status_Type low_beam_signal_status;
   /* 近光灯信号信号时延 ms */
	uint32 low_beam_signal_dT;

   /* 点火开关状态
     Enum:
     0x0:Off
     0x1:ACC
     0x2:ON
     0x3:Start 
   */
	uint32 ignition_position;
   /* 点火开关状态信号接收状态 */
	Signal_Status_Type ignition_position_status;
   /* 点火开关状态信号时延 ms */
	uint32 ignition_position_dT;

   /* ebs状态 
     Enum:
     0x0:Abnormal
     0x1:Normal    
   */
	uint32 is_ebs_normal;
   /* ebs状态信号接收状态 */
	Signal_Status_Type is_ebs_normal_status;
   /* ebs状态信号时延 ms */
	uint32 is_ebs_normal_dT;
	
   /* eps状态
     Enum:
     0x0:Abnormal
     0x1:Normal    
   */
	uint32 is_eps_normal;
   /* eps状态信号接收状态 */
	Signal_Status_Type is_eps_normal_status;
   /* eps状态信号时延 ms */
	uint32 is_eps_normal_dT;

   /* epb状态
     Enum:
     0x0:Abnormal
     0x1:Normal   
   */
	uint32 is_epb_normal;
   /* epb状态信号接收状态 */
	Signal_Status_Type is_epb_normal_status;
   /* 信号时延 ms */
	uint32 is_epb_normal_dT;

   /* vcu状态 
     Enum:
     0x0:Abnormal
     0x1:Normal   
  */
	uint32 is_vcu_normal;
   /* vcu状态信号接收状态 */
	Signal_Status_Type is_vcu_normal_status;
   /* vcu状态信号时延 ms */
	uint32 is_vcu_normal_dT;

   /* 油门百分比 */
	float32 throttle_percentage;
   /* 油门百分比信号接收状态 */
	Signal_Status_Type throttle_percentage_status;
   /* 油门百分比信号时延 ms */
	uint32 throttle_percentage_dT;

   /* 拨杆请求 
     Enum:
     0x0:Req
     0x1:NoReq   
  */
	uint32 deflector_rod;
   /* 拨杆请求信号接收状态 */
	Signal_Status_Type deflector_rod_status;
   /* 拨杆请求信号时延 ms */
	uint32 deflector_rod_dT;

   /* 左前轮胎压 */
	float32 tire_pressure_fl;
   /* 左前轮胎压信号接收状态 */
	Signal_Status_Type tire_pressure_fl_status;
   /* 左前轮胎压信号时延 ms */
	uint32 tire_pressure_fl_dT;

   /* 右前轮胎压 */
	float32 tire_pressure_fr;
   /* 右前轮胎压信号接收状态 */
	Signal_Status_Type tire_pressure_fr_status;
   /* 右前轮胎压信号时延 ms */
	uint32 tire_pressure_fr_dT;

   /* 左后轮胎压 */
	float32 tire_pressure_rl;
   /* 左后轮胎压信号接收状态 */
	Signal_Status_Type tire_pressure_rl_status;
   /* 左后轮胎压信号时延 ms */
	uint32 tire_pressure_rl_dT;

   /* 右后轮胎压 */
	float32 tire_pressure_rr;
   /* 右后轮胎压信号接收状态 */
	Signal_Status_Type tire_pressure_rr_status;
   /* 右后轮胎压信号时延 ms */
	uint32 tire_pressure_rr_dT;

   /* 左前轮转向角度 */
	float32 tire_angle_fl;
   /* 左前轮转向角度信号接收状态 */
	Signal_Status_Type tire_angle_fl_status;
   /* 左前轮转向角度信号时延 ms */
	uint32 tire_angle_fl_dT;

   /* 右前轮转向角度 */
	float32 tire_angle_fr;
   /* 右前轮转向角度信号接收状态 */
	Signal_Status_Type tire_angle_fr_status;
   /* 右前轮转向角度信号时延 ms */
	uint32 tire_angle_fr_dT;

   /* 雨刮是否打开 */
	uint32 wiper_switch;
   /* 雨刮开关信号接收状态 */
	Signal_Status_Type wiper_switch_status;
   /* 雨刮开关信号时延 ms */
	uint32 wiper_switch_dT;

   /* 雨刮水开关 */
	uint32 wiper_water_switch;
   /* 雨刮水开关信号接收状态 */
	Signal_Status_Type wiper_water_switch_status;
   /* 雨刮水开关信号时延 ms */
	uint32 wiper_water_switch_dT;

   /* 目标减速度需求值, unit:m/s2 */
	float32 xbr_extacceldemand;

   /* 档位需求值, d/n/r */
	sint32 tc1_transreqgear;

   /* 转向角度需求值, deg */
	float32 eps_steerangreq;
  /*保留字段，新增的公共信号可使用此字段*/
  uint32 Reserved_Arr[60];
    /*项目独有的信号字段*/
  Project_ID Project_Id;
  Product_Message_Type Product_Message_Data;
} Chassis_Info_Type;

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

# define Rte_TypeDef_TxSocAdminDataType

typedef struct
{
  Chassis_Info_Type ChassisData;
  CtrlInfoMCU2SOC CtrlData;
  ADMInfoMCU2SOC ADMData;
} TxSocAdminDataType;

# define Rte_TypeDef_rt_rt_Array_uint8_208
typedef uint8 rt_Array_uint8_208[208];

# define Rte_TypeDef_rt_rt_Array_uint8_16
typedef uint8 rt_Array_uint8_16[16];

# define Rte_TypeDef_rt_rt_Array_uint8_4
typedef uint8 rt_Array_uint8_4[4];

# define Rte_TypeDef_rt_rt_Array_uint8_10
typedef uint8 rt_Array_uint8_10[10];

# define Rte_TypeDef_rt_rt_Array_uint8_17
typedef uint8 rt_Array_uint8_17[17];

# define Rte_TypeDef_rt_rt_Array_uint8_100
typedef uint8 rt_Array_uint8_100[100];

# define Rte_TypeDef_rt_rt_Array_uint8_180
typedef uint8 rt_Array_uint8_180[180];

# define Rte_TypeDef_rt_rt_Array_uint8_128
typedef uint8 rt_Array_uint8_128[128];

# define Rte_TypeDef_rt_rt_Array_uint8_12
typedef uint8 rt_Array_uint8_12[12];

# define Rte_TypeDef_rt_rt_Array_uint8_200
typedef uint8 rt_Array_uint8_200[200];
# define Rte_TypeDef_rt_rt_Array_uint8_1024
typedef uint8 rt_Array_uint8_1024[1024];
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

# define Rte_TypeDef_BusEM
typedef struct
{
  boolean EM_Err;
  uint32 EM_Diag;
} BusEM;

# define Rte_TypeDef_BusADM
typedef struct
{
  uint8 ADM_ADMode;
  boolean ADM_ADActv;
} BusADM;

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

# define Rte_TypeDef_BusLatCtrl
typedef struct
{
  float32 LatCtrl_TarStrWhlAngl;
  boolean LatCtrl_StrWhlAnglCtrlActv;
} BusLatCtrl;

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

# define Rte_DisableOSInterrupts() \
{\
  { \
    DISABLE(); \
  } \
}

# define Rte_EnableOSInterrupts() \
{\
  { \
    ENABLE(); \
  } \
} 

extern VAR(SG_CCVS1_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_CCVS1_sg_oCCVS1_oJ6L_ADUCAN_Rx;
extern VAR(SG_ETC2_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_ETC2_sg_oETC2_oJ6L_ADUCAN_Rx;
extern VAR(SG_DM1_EPB_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_DM1_EPB_sg_oDM1_EPB_oJ6L_ADUCAN_Rx;
extern VAR(SG_EPB1_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_EPB1_sg_oEPB1_oJ6L_ADUCAN_Rx;
extern VAR(SG_DM1_ABS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_DM1_ABS_sg_oDM1_ABS_oJ6L_ADUCAN_Rx;
extern VAR(SG_EBC1_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_EBC1_sg_oEBC1_oJ6L_ADUCAN_Rx;
extern VAR(SG_EBC2_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_EBC2_sg_oEBC2_oJ6L_ADUCAN_Rx;
extern VAR(SG_EBC5_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_EBC5_sg_oEBC5_oJ6L_ADUCAN_Rx;
extern VAR(SG_ESC1_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_ESC1_sg_oESC1_oJ6L_ADUCAN_Rx;
extern VAR(SG_CVW_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_CVW_sg_oCVW_oJ6L_ADUCAN_Rx;
extern VAR(SG_VDC2_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_VDC2_sg_oVDC2_oJ6L_ADUCAN_Rx;
extern VAR(SG_LC_ADU_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_LC_ADU_sg_oLC_ADU_oJ6L_ADUCAN_Tx;
extern VAR(SG_LC_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_LC_sg_oLC_oJ6L_ADUCAN_Rx;
extern VAR(SG_DC2_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_DC2_sg_oDC2_oJ6L_ADUCAN_Rx;
extern VAR(SG_MCU1_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_MCU1_sg_oMCU1_oJ6L_ADUCAN_Rx;
extern VAR(SG_DM1_EPS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_DM1_EPS_sg_oDM1_EPS_oJ6L_ADUCAN_Rx;
extern VAR(SG_EPS1_ZF_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_EPS1_ZF_sg_oEPS1_ZF_oJ6L_ADUCAN_Rx;
extern VAR(SG_EPS2_ZF_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_EPS2_ZF_sg_oEPS2_ZF_oJ6L_ADUCAN_Rx;
extern VAR(SG_TIRE1_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TIRE1_sg_oTIRE1_oJ6L_ADUCAN_Rx;
extern VAR(SG_TIRE2_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TIRE2_sg_oTIRE2_oJ6L_ADUCAN_Rx;
extern VAR(SG_TIRE3_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TIRE3_sg_oTIRE3_oJ6L_ADUCAN_Rx;
extern VAR(SG_DM1_TPMS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_DM1_TPMS_sg_oDM1_TPMS_oJ6L_ADUCAN_Rx;
extern VAR(SG_EEC2_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_EEC2_sg_oEEC2_oJ6L_ADUCAN_Rx;
extern VAR(SG_TSC1_ACCE_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TSC1_ACCE_sg_oTSC1_ACCE_oJ6L_ADUCAN_Tx;
extern VAR(SG_XBR2_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_XBR2_sg_oXBR2_oJ6L_ADUCAN_Tx;
extern VAR(SG_TC1_ADU_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TC1_ADU_sg_oTC1_ADU_oJ6L_ADUCAN_Tx;
extern VAR(SG_EPB2_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_EPB2_sg_oEPB2_oJ6L_ADUCAN_Tx;
extern VAR(SG_ADU1_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_ADU1_sg_oADU1_oJ6L_ADUCAN_Tx;
extern VAR(SG_ADU_Cmd_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_ADU_Cmd_sg_oADU_Cmd_oJ6L_ADUCAN_Tx;
extern VAR(SG_VCU_Status_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_VCU_Status_sg_oVCU_Status_oJ6L_ADUCAN_Rx;
extern VAR(SG_OWW_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_OWW_sg_oOWW_oJ6L_ADUCAN_Rx;
extern VAR(SG_SC_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_SC_sg_oSC_oJ6L_ADUCAN_Rx;
extern VAR(SG_BCU_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_BCU_sg_oBCU_oJ6L_ADUCAN_Rx;
extern VAR(SG_HCU_BMS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_HCU_BMS_sg_oHCU_BMS_oJ6L_ADUCAN_Rx;
extern VAR(SG_BMS1_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_BMS1_sg_oBMS1_oJ6L_ADUCAN_Rx;
extern VAR(SG_BMS5_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_BMS5_sg_oBMS5_oJ6L_ADUCAN_Rx;
extern VAR(SG_VD_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_VD_sg_oVD_oJ6L_ADUCAN_Rx;
extern VAR(SG_DM1_BCM_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_DM1_BCM_sg_oDM1_BCM_oJ6L_ADUCAN_Rx;
extern VAR(SG_TSC1_ACCDR_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TSC1_ACCDR_sg_oTSC1_ACCDR_oJ6L_ADUCAN_Tx;
extern VAR(SG_EC_EM1_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_EC_EM1_sg_oEC_EM1_oJ6L_ADUCAN_Rx;
extern VAR(SG_LD_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_LD_sg_oLD_oJ6L_ADUCAN_Rx;
extern VAR(SG_BCM_Status_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_BCM_Status_sg_oBCM_Status_oJ6L_ADUCAN_Rx;
extern VAR(SG_DM1_BMS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_DM1_BMS_sg_oDM1_BMS_oJ6L_ADUCAN_Rx;
extern VAR(SG_DM1_PTU_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_DM1_PTU_sg_oDM1_PTU_oJ6L_ADUCAN_Rx;
extern VAR(SG_DM1_DCDC2_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_DM1_DCDC2_sg_oDM1_DCDC2_oJ6L_ADUCAN_Rx;
extern VAR(SG_DM1_APCU_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_DM1_APCU_sg_oDM1_APCU_oJ6L_ADUCAN_Rx;
extern VAR(SG_EPSO1_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_EPSO1_sg_oEPSO1_oJ6L_ADUCAN_Rx;
extern VAR(SG_EPSO2_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_EPSO2_sg_oEPSO2_oJ6L_ADUCAN_Rx;
extern VAR(SG_XBR1_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_XBR1_sg_oXBR1_oJ6L_ADUCAN_Tx;
extern VAR(SG_EPSI1_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_EPSI1_sg_oEPSI1_oJ6L_ADUCAN_Tx;
extern VAR(SG_EPSI2_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_EPSI2_sg_oEPSI2_oJ6L_ADUCAN_Tx;
extern VAR(SG_FBCM_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_FBCM_sg_oFBCM_oJ6L_ADUCAN_Rx;
extern VAR(SG_PS1_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_PS1_sg_oPS1_oJ6L_ADUCAN_Rx;
extern VAR(SG_ENGSC_FM_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_ENGSC_FM_sg_oENGSC_FM_oJ6L_ADUCAN_Tx;
extern VAR(SG_ATR_FM_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_ATR_FM_sg_oATR_FM_oJ6L_ADUCAN_Tx;
extern VAR(SG_ATS_PS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_ATS_PS_sg_oATS_PS_oJ6L_ADUCAN_Rx;
extern VAR(SG_Lcks_Cmd1_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_Lcks_Cmd1_sg_oLcks_Cmd1_oJ6L_ADUCAN_Tx;
extern VAR(SG_TPCM_EPB_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPCM_EPB_sg_oTPCM_EPB_oJ6L_ADUCAN_Rx;
extern VAR(SG_TPDT_EPB_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPDT_EPB_sg_oTPDT_EPB_oJ6L_ADUCAN_Rx;
extern VAR(SG_TPCM_EBS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPCM_EBS_sg_oTPCM_EBS_oJ6L_ADUCAN_Rx;
extern VAR(SG_TPDT_EBS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPDT_EBS_sg_oTPDT_EBS_oJ6L_ADUCAN_Rx;
extern VAR(SG_TPCM_EPS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPCM_EPS_sg_oTPCM_EPS_oJ6L_ADUCAN_Rx;
extern VAR(SG_TPDT_EPS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPDT_EPS_sg_oTPDT_EPS_oJ6L_ADUCAN_Rx;
extern VAR(SG_TPCM_BCM_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPCM_BCM_sg_oTPCM_BCM_oJ6L_ADUCAN_Rx;
extern VAR(SG_TPDT_BCM_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPDT_BCM_sg_oTPDT_BCM_oJ6L_ADUCAN_Rx;
extern VAR(SG_TPCM_TPMS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPCM_TPMS_sg_oTPCM_TPMS_oJ6L_ADUCAN_Rx;
extern VAR(SG_TPDT_TPMS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPDT_TPMS_sg_oTPDT_TPMS_oJ6L_ADUCAN_Rx;
extern VAR(SG_TPCM_BMS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPCM_BMS_sg_oTPCM_BMS_oJ6L_ADUCAN_Rx;
extern VAR(SG_TPDT_BMS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPDT_BMS_sg_oTPDT_BMS_oJ6L_ADUCAN_Rx;
extern VAR(SG_TPCM_VCU_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPCM_VCU_sg_oTPCM_VCU_oJ6L_ADUCAN_Rx;
extern VAR(SG_TPDT_VCU_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPDT_VCU_sg_oTPDT_VCU_oJ6L_ADUCAN_Rx;
extern VAR(SG_TPCM_PTU_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPCM_PTU_sg_oTPCM_PTU_oJ6L_ADUCAN_Rx;
extern VAR(SG_TPDT_PTU_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPDT_PTU_sg_oTPDT_PTU_oJ6L_ADUCAN_Rx;
extern VAR(SG_TPCM_DCDC2_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPCM_DCDC2_sg_oTPCM_DCDC2_oJ6L_ADUCAN_Rx;
extern VAR(SG_TPDT_DCDC2_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPDT_DCDC2_sg_oTPDT_DCDC2_oJ6L_ADUCAN_Rx;
extern VAR(SG_TPCM_APCU_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPCM_APCU_sg_oTPCM_APCU_oJ6L_ADUCAN_Rx;
extern VAR(SG_TPDT_APCU_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_TPDT_APCU_sg_oTPDT_APCU_oJ6L_ADUCAN_Rx;
extern VAR(SG_HRW_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_HRW_sg_oHRW_oJ6L_ADUCAN_Rx;
extern VAR(SG_ADUSt_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_ADUSt_sg_oADUSt_oJ6L_ADUCAN_Tx;
extern VAR(SG_RDUSt_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_RDUSt_sg_oRDUSt_oJ6L_ADUCAN_Rx;
extern VAR(SG_IGWSt_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_IGWSt_sg_oIGWSt_oJ6L_ADUCAN_Rx;
extern VAR(SG_ADU_Cmd_AECS_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_ADU_Cmd_AECS_sg_oADU_Cmd_AECS_oGNSSCooling_CANMatrix_Tx;
extern VAR(SG_ACS_Calibration_ADU_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_ACS_Calibration_ADU_sg_oACS_Calibration_ADU_oGNSSCooling_CANMatrix_Tx;
extern VAR(SG_Time_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_Time_sg_oTime_oGNSSCooling_CANMatrix_Rx;
extern VAR(SG_Ang_Rate_Raw_IMU_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_Ang_Rate_Raw_IMU_sg_oAng_Rate_Raw_IMU_oGNSSCooling_CANMatrix_Rx;
extern VAR(SG_Accel_IMU_Raw_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_Accel_IMU_Raw_sg_oAccel_IMU_Raw_oGNSSCooling_CANMatrix_Rx;
extern VAR(SG_InsStatus_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_InsStatus_sg_oInsStatus_oGNSSCooling_CANMatrix_Rx;
extern VAR(SG_LatitudeLongitude_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_LatitudeLongitude_sg_oLatitudeLongitude_oGNSSCooling_CANMatrix_Rx;
extern VAR(SG_Altitude_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_Altitude_sg_oAltitude_oGNSSCooling_CANMatrix_Rx;
extern VAR(SG_PosSigma_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_PosSigma_sg_oPosSigma_oGNSSCooling_CANMatrix_Rx;
extern VAR(SG_VelocityLevel_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_VelocityLevel_sg_oVelocityLevel_oGNSSCooling_CANMatrix_Rx;
extern VAR(SG_VelocityLevelSigma_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_VelocityLevelSigma_sg_oVelocityLevelSigma_oGNSSCooling_CANMatrix_Rx;
extern VAR(SG_Accel_Vehicle_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_Accel_Vehicle_sg_oAccel_Vehicle_oGNSSCooling_CANMatrix_Rx;
extern VAR(SG_HeadingPitchRoll_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_HeadingPitchRoll_sg_oHeadingPitchRoll_oGNSSCooling_CANMatrix_Rx;
extern VAR(SG_HeadingPitchRollSigma_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_HeadingPitchRollSigma_sg_oHeadingPitchRollSigma_oGNSSCooling_CANMatrix_Rx;
extern VAR(SG_AngRateVehicle_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_AngRateVehicle_sg_oAngRateVehicle_oGNSSCooling_CANMatrix_Rx;
extern VAR(SG_Longitude_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_Longitude_sg_oLongitude_oGNSSCooling_CANMatrix_Rx;
extern VAR(SG_Latitude_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_Latitude_sg_oLatitude_oGNSSCooling_CANMatrix_Rx;
extern VAR(SG_RDF_State_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_RDF_State_sg_oRDF_State_oRDF2_CANMatrix_F_Rx;
extern VAR(SG_SCA_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_SCA_sg_oSCA_oRDF2_CANMatrix_F_Tx;
extern VAR(SG_HRW_FR_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_HRW_FR_sg_oHRW_FR_oRDF2_CANMatrix_F_Tx;
extern VAR(SG_HRW_RE_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_HRW_RE_sg_oHRW_RE_oRDF2_CANMatrix_F_Tx;
extern VAR(SG_BS_E7_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_BS_E7_sg_oBS_E7_oRDF2_CANMatrix_F_Tx;
extern VAR(SG_Brak_Sta_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_Brak_Sta_sg_oBrak_Sta_oRDF2_CANMatrix_F_Tx;
extern VAR(SG_CI_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_CI_sg_oCI_oRDF2_CANMatrix_F_Rx;
extern VAR(SG_RadarState_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_RadarState_sg_oRadarState_oARS408_CANMatrix_Rx;
extern VAR(SG_VersionID_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_VersionID_sg_oVersionID_oARS408_CANMatrix_Rx;
extern VAR(SG_Obj_0_Status_sg, RTE_VAR_INIT_NOCACHE) Rte_SG_Obj_0_Status_sg_oObj_0_Status_oARS408_CANMatrix_Rx;
extern VAR(Rx_Flag_Type, RTE_VAR_INIT_NOCACHE) Rte_Rx_Flag_Arr_CCVS1_oRx_Flag_Arr_CCVS1;
extern VAR(Rx_Flag_Type, RTE_VAR_INIT_NOCACHE) Rte_Rx_Flag_Arr_EBC1_oRx_Flag_Arr_EBC1;
extern VAR(Rx_Flag_Type, RTE_VAR_INIT_NOCACHE) Rte_Rx_Flag_Arr_EBC2_oRx_Flag_Arr_EBC2;
extern VAR(Rx_Flag_Type, RTE_VAR_INIT_NOCACHE) Rte_Rx_Flag_Arr_EEC2_oRx_Flag_Arr_EEC2;
extern VAR(Rx_Flag_Type, RTE_VAR_INIT_NOCACHE) Rte_Rx_Flag_Arr_EPB1_oRx_Flag_Arr_EPB1;
extern VAR(Rx_Flag_Type, RTE_VAR_INIT_NOCACHE) Rte_Rx_Flag_Arr_EPS2_oRx_Flag_Arr_EPS2;
extern VAR(Rx_Flag_Type, RTE_VAR_INIT_NOCACHE) Rte_Rx_Flag_Arr_ETC2_oRx_Flag_Arr_ETC2;
extern VAR(Rx_Flag_Type, RTE_VAR_INIT_NOCACHE) Rte_Rx_Flag_Arr_LC_oRx_Flag_Arr_LC;
extern VAR(Rx_Flag_Type, RTE_VAR_INIT_NOCACHE) Rte_Rx_Flag_Arr_MCU1_oRx_Flag_Arr_MCU1;
extern VAR(Rx_Flag_Type, RTE_VAR_INIT_NOCACHE) Rte_Rx_Flag_Arr_PS1_oRx_Flag_Arr_PS1;
extern VAR(Rx_Flag_Type, RTE_VAR_INIT_NOCACHE) Rte_Rx_Flag_Arr_VCU_Status_oRx_Flag_Arr_VCU_Status;
extern VAR(Rx_Flag_Type, RTE_VAR_INIT_NOCACHE) Rte_Rx_Flag_Arr_VDC2_oRx_Flag_Arr_VDC2;
extern VAR(CCVS1_SigStatusType, RTE_VAR_INIT_NOCACHE) Rte_Rx_SigStat_Arr_CCVS1_oRx_SigStat_Arr_CCVS1;
extern VAR(EBC1_SigStatusType, RTE_VAR_INIT_NOCACHE) Rte_Rx_SigStat_Arr_EBC1_oRx_SigStat_Arr_EBC1;
extern VAR(EBC2_SigStatusType, RTE_VAR_INIT_NOCACHE) Rte_Rx_SigStat_Arr_EBC2_oRx_SigStat_