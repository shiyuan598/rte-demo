/**
 * ********************************************************************************************************************
 * @file Rte_OsApplication_Core2.c
 * @brief Rte Interface for OsApplication_Core2
 * @author zhito 
 * @version 1.0.0
 * @date 2023-12-11 13:21:55
 * @copyright Copyright (c) Zhito Co., Ltd. 2020-2035. All rights reserved.
 * ********************************************************************************************************************
 */
#include "shared.h"
#include "Rte_cgi610.h"
#include "cgi610.h"


VAR(rt_Array_uint8_208, RTE_VAR_INIT_NOCACHE) Rte_Cgi610_1_Data_oCgi610_1_Data = {0u};

VAR(rt_Array_uint8_208, RTE_VAR_INIT_NOCACHE) Rte_Cgi610_2_Data_oCgi610_2_Data = {0u};

VAR(rt_Array_uint8_208, RTE_VAR_INIT_NOCACHE) Rte_Cgi610_3_Data_oCgi610_3_Data = {0u};

VAR(rt_Array_uint8_208, RTE_VAR_INIT_NOCACHE) Rte_Cgi610_4_Data_oCgi610_4_Data = {0u};

VAR(rt_Array_uint8_208, RTE_VAR_INIT_NOCACHE) Rte_Cgi610_5_Data_oCgi610_5_Data = {0u};

VAR(rt_Array_uint8_180, RTE_VAR_INIT_NOCACHE) Rte_PwrMgr_AdminData_MirrorBlock_oPwrMgr_AdminData_MirrorBlock = {0u};

VAR(rt_Array_uint8_200, RTE_VAR_INIT_NOCACHE) Rte_PpsStatus_oPpsStatus = {0u};

VAR(rt_Array_uint8_1024, RTE_VAR_INIT_NOCACHE) Rte_PowerMngComData_oPowerMngComData = {0u};

extern uint8_t Core[6][10];
#if (defined(__TASKING__))
#define OS_CORE2_START_SEC_CODE
#include "Os_MemMap.h"
#endif

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_cgi610_Cgi610_1_Data_oCgi610_1_Data(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Cgi610_1_Data_oCgi610_1_Data);
  (void)memcpy(Rte_Cgi610_1_Data_oCgi610_1_Data,data,sizeof(rt_Array_uint8_208));
  (void)ReleaseSpinlock(Rte_Spinlock_Cgi610_1_Data_oCgi610_1_Data);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_cgi610_Cgi610_2_Data_oCgi610_2_Data(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Cgi610_2_Data_oCgi610_2_Data);
  (void)memcpy(Rte_Cgi610_2_Data_oCgi610_2_Data,data,sizeof(rt_Array_uint8_208));
  (void)ReleaseSpinlock(Rte_Spinlock_Cgi610_2_Data_oCgi610_2_Data);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_cgi610_Cgi610_3_Data_oCgi610_3_Data(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Cgi610_3_Data_oCgi610_3_Data);
  (void)memcpy(Rte_Cgi610_3_Data_oCgi610_3_Data,data,sizeof(rt_Array_uint8_208));
  (void)ReleaseSpinlock(Rte_Spinlock_Cgi610_3_Data_oCgi610_3_Data);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_cgi610_Cgi610_4_Data_oCgi610_4_Data(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Cgi610_4_Data_oCgi610_4_Data);
  (void)memcpy(Rte_Cgi610_4_Data_oCgi610_4_Data,data,sizeof(rt_Array_uint8_208));
  (void)ReleaseSpinlock(Rte_Spinlock_Cgi610_4_Data_oCgi610_4_Data);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_cgi610_Cgi610_5_Data_oCgi610_5_Data(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Cgi610_5_Data_oCgi610_5_Data);
  (void)memcpy(Rte_Cgi610_5_Data_oCgi610_5_Data,data,sizeof(rt_Array_uint8_208));
  (void)ReleaseSpinlock(Rte_Spinlock_Cgi610_5_Data_oCgi610_5_Data);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PowerManager_PwrMgr_AdminData_MirrorBlock_oPwrMgr_AdminData_MirrorBlock(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)memcpy(data,Rte_PwrMgr_AdminData_MirrorBlock_oPwrMgr_AdminData_MirrorBlock,sizeof(rt_Array_uint8_180));

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PowerManager_PwrMgr_AdminData_MirrorBlock_oPwrMgr_AdminData_MirrorBlock(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)memcpy(Rte_PwrMgr_AdminData_MirrorBlock_oPwrMgr_AdminData_MirrorBlock,data,sizeof(rt_Array_uint8_180));

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PowMgr_Orin0RxData_oOrin0RxData(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Orin0RxData_oOrin0RxData);
  (void)memcpy(data,Rte_Orin0RxData_oOrin0RxData,sizeof(rt_Array_uint8_128));
  (void)ReleaseSpinlock(Rte_Spinlock_Orin0RxData_oOrin0RxData);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PowMgr_Orin1RxData_oOrin1RxData(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Orin1RxData_oOrin1RxData);
  (void)memcpy(data,Rte_Orin1RxData_oOrin1RxData,sizeof(rt_Array_uint8_128));
  (void)ReleaseSpinlock(Rte_Spinlock_Orin1RxData_oOrin1RxData);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PowMgr_Orin2RxData_oOrin2RxData(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Orin2RxData_oOrin2RxData);
  (void)memcpy(data,Rte_Orin2RxData_oOrin2RxData,sizeof(rt_Array_uint8_128));
  (void)ReleaseSpinlock(Rte_Spinlock_Orin2RxData_oOrin2RxData);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PowMgr_Orin3RxData_oOrin3RxData(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Orin3RxData_oOrin3RxData);
  (void)memcpy(data,Rte_Orin3RxData_oOrin3RxData,sizeof(rt_Array_uint8_128));
  (void)ReleaseSpinlock(Rte_Spinlock_Orin3RxData_oOrin3RxData);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_cgi610_Core2TimeStamp_oCore2TimeStamp(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Core2TimeStamp_oCore2TimeStamp);
  (void)memcpy(data,Rte_Core2TimeStamp_oCore2TimeStamp,sizeof(rt_Array_uint8_12));
  (void)ReleaseSpinlock(Rte_Spinlock_Core2TimeStamp_oCore2TimeStamp);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PowMgr_Core2TimeStamp_oCore2TimeStamp(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Core2TimeStamp_oCore2TimeStamp);
  (void)memcpy(data,Rte_Core2TimeStamp_oCore2TimeStamp,sizeof(rt_Array_uint8_12));
  (void)ReleaseSpinlock(Rte_Spinlock_Core2TimeStamp_oCore2TimeStamp);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_GpsPPS_Core2TimeStamp_oCore2TimeStamp(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Core2TimeStamp_oCore2TimeStamp);
  (void)memcpy(data,Rte_Core2TimeStamp_oCore2TimeStamp,sizeof(rt_Array_uint8_12));
  (void)ReleaseSpinlock(Rte_Spinlock_Core2TimeStamp_oCore2TimeStamp);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Writ