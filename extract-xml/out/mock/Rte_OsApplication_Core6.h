

/**
 * ********************************************************************************************************************
 * @file Rte_OsApplication_Core6.c
 * @brief Rte Interface for OsApplication_Core6
 * @author zhito 
 * @version 1.0.0
 * @date 2024-07-03 11:40:21
 * @copyright Copyright (c) Zhito Co., Ltd. 2020-2035. All rights reserved.
 * ********************************************************************************************************************
 */

#include "shared.h"
#include "IDC.h"
#include "Rte_control_swc_sweep.h"
#include "Rte_CddMsgUpd.h"
#include "ee_oo_api_osek.h"
















FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_ADMInfoSOC2MCU_oADMInfoSOC2MCU(ADMInfoSOC2MCU* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_ADMInfoSOC2MCU_oADMInfoSOC2MCU);
  Rte_ADMInfoSOC2MCU_oADMInfoSOC2MCU = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_ADMInfoSOC2MCU_oADMInfoSOC2MCU);
  Rte_EnableOSInterrupts();
    
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_ChassisInp_oChassisInp(ChassisInfo* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_ChassisInp_oChassisInp);
  Rte_ChassisInp_oChassisInp = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_ChassisInp_oChassisInp);
  Rte_EnableOSInterrupts();
    
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_J6LCANRxInp_oJ6LCANRxInp(J6L_RxBus* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_J6LCANRxInp_oJ6LCANRxInp);
  Rte_J6LCANRxInp_oJ6LCANRxInp = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_J6LCANRxInp_oJ6LCANRxInp);
  Rte_EnableOSInterrupts();
    
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_PlanningInfo_oPlanningInfo(PlanningInfo* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_PlanningInfo_oPlanningInfo);
  Rte_PlanningInfo_oPlanningInfo = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_PlanningInfo_oPlanningInfo);
  Rte_EnableOSInterrupts();
    
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_ChassisInp_oChassisInp(ChassisInfo* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_ChassisInp_oChassisInp);
  Rte_ChassisInp_oChassisInp = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_ChassisInp_oChassisInp);
  Rte_EnableOSInterrupts();
    
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_LocalizationInfo_oLocalizationInfo(LocalizationInfo* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_LocalizationInfo_oLocalizationInfo);
  Rte_LocalizationInfo_oLocalizationInfo = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_LocalizationInfo_oLocalizationInfo);
  Rte_EnableOSInterrupts();
    
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_PlanningInfo_oPlanningInfo(PlanningInfo* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_PlanningInfo_oPlanningInfo);
  Rte_PlanningInfo_oPlanningInfo = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_PlanningInfo_oPlanningInfo);
  Rte_EnableOSInterrupts();
    
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CddMsgUpd_PlanningInfo_oPlanningInfo(PlanningInfo* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_PlanningInfo_oPlanningInfo);
  Rte_PlanningInfo_oPlanningInfo = *(data);
  (void)ReleaseSpinlock(Rte_Spinlock_PlanningInfo_oPlanningInfo);
  Rte_EnableOSInterrupts();
    
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_J6LCANTxOutp_oJ6LCANTxOutp(J6L_TxBus* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_J6LCANTxOutp_oJ6LCANTxOutp);
  (void)memcpy(&Rte_J6LCANTxOutp_oJ6LCANTxOutp, data, sizeof(J6L_TxBus));
  *(data) = Rte_J6LCANTxOutp_oJ6LCANTxOutp;
  (void)ReleaseSpinlock(Rte_Spinlock_J6LCANTxOutp_oJ6LCANTxOutp);
  Rte_EnableOSInterrupts();
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_ADMInfoMCU2SOC_oADMInfoMCU2SOC(ADMInfoMCU2SOC* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_ADMInfoMCU2SOC_oADMInfoMCU2SOC);
  (void)memcpy(&Rte_ADMInfoMCU2SOC_oADMInfoMCU2SOC, data, sizeof(ADMInfoMCU2SOC));
  *(data) = Rte_ADMInfoMCU2SOC_oADMInfoMCU2SOC;
  (void)ReleaseSpinlock(Rte_Spinlock_ADMInfoMCU2SOC_oADMInfoMCU2SOC);
  Rte_EnableOSInterrupts();
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CddMsgUpd_CtrlDebugInfoMCU2SOC_oCtrlDebugInfoMCU2SOC(CtrlInfoMCU2SOC* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_CtrlDebugInfoMCU2SOC_oCtrlDebugInfoMCU2SOC);
  (void)memcpy(&Rte_CtrlDebugInfoMCU2SOC_oCtrlDebugInfoMCU2SOC, data, sizeof(CtrlInfoMCU2SOC));
  *(data) = Rte_CtrlDebugInfoMCU2SOC_oCtrlDebugInfoMCU2SOC;
  (void)ReleaseSpinlock(Rte_Spinlock_CtrlDebugInfoMCU2SOC_oCtrlDebugInfoMCU2SOC);
  Rte_EnableOSInterrupts();
    return ret;
}


