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

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_GpsPPS_PpsStatus_oPpsStatus(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_PpsStatus_oPpsStatus);
  (void)memcpy(Rte_PpsStatus_oPpsStatus,data,sizeof(rt_Array_uint8_200));
  (void)ReleaseSpinlock(Rte_Spinlock_PpsStatus_oPpsStatus);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PowMgr_PowerMngComData_oPowerMngComData(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_PowerMngComData_oPowerMngComData);
  (void)memcpy(Rte_PowerMngComData_oPowerMngComData,data,sizeof(rt_Array_uint8_1024));
  (void)ReleaseSpinlock(Rte_Spinlock_PowerMngComData_oPowerMngComData);
  Rte_EnableOSInterrupts();

  return ret;
}
/**********************************************************************************************************************
 * Task:     Bsw_QM_Event_Task_Core0
 * Priority: 170
 * Schedule: FULL
 *********************************************************************************************************************/
 TASK(Bsw_Init_Task_Core2)
 {
    Core[2][0]++;
    Tm_Start(20);
    EcuM_StartupTwo();
    Rte_Start();  
    Uart_Init( &Uart_Config  );
    ztuart_Init();
    zt_adc_init();
    CDD_Uart_Init();
    SWC_NvShell_Init();
    zt_uart_multicore_Init();
    PowerManager_Init();
    CGI610_Init();
    ZtSftyMon_Init();
    PPS_Init();
    while (((volatile uint8)Rte_InitState) != RTE_STATE_INIT)
    {

    }
    Tm_Stop(20);
    TerminateTask();
 }
/**********************************************************************************************************************
 * Task:     Bsw_QM_Event_Task_Core0
 * Priority: 170
 * Schedule: FULL
 *********************************************************************************************************************/
 TASK(Bsw_P1ms_Task_Core2)
 {
 	 Core[2][1]++;
   Tm_Start(21);
   CGI610_MainFunction();
   Tm_Stop(21);
   TerminateTask();
 }
/**********************************************************************************************************************
 * Task:     Bsw_QM_Event_Task_Core0
 * Priority: 170
 * Schedule: FULL
 *********************************************************************************************************************/
 TASK(Bsw_P5ms_Task_Core2)
 {
 	  Core[2][2]++;
    Tm_Start(22);
    Tm_Stop(22);
    TerminateTask();
 }
/**********************************************************************************************************************
 * Task:     Bsw_QM_Event_Task_Core0
 * Priority: 170
 * Schedule: FULL
 *********************************************************************************************************************/
 TASK(Bsw_P10ms_Task_Core2)
 {
 	  Core[2][3]++;
    Tm_Start(23);
    EcuM_MainFunction();      
    zt_uart_multicore_Mainfunction();
    SWC_NvShell_ProcessCmd();
    PowerManager_MainFunction();
    Spi_MainFunction_Handling();
    zt_adc_mainfunction();
    ZtSftyMon_MainFunction_10ms();
    Tm_Stop(23);
    TerminateTask();
 }
/**********************************************************************************************************************
 * Task:     Bsw_QM_Event_Task_Core0
 * Priority: 170
 * Schedule: FULL
 *********************************************************************************************************************/
 TASK(Bsw_P100ms_Task_Core2)
 {
   Core[2][4]++;
   Tm_Start(24);
   Clm_runnable_100ms();
   Tm_Stop(24);
   TerminateTask();
 }
/**********************************************************************************************************************
 * Task:     Bsw_QM_Event_Task_Core0
 * Priority: 170
 * Schedule: FULL
 *********************************************************************************************************************/
void idle_hook_core2(void);
void idle_hook_core2(void)
{
  idle_hook_body();
}


#if (defined(__TASKING__))
#define OS_CORE2_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif

