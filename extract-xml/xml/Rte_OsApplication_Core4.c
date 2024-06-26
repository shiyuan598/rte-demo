/**
 * ********************************************************************************************************************
 * @file Rte_OsApplication_Core4.c
 * @brief Rte Interface for OsApplication_Core4
 * @author zhito 
 * @version 1.0.0
 * @date 2023-12-11 13:21:55
 * @copyright Copyright (c) Zhito Co., Ltd. 2020-2035. All rights reserved.
 * ********************************************************************************************************************
 */
#include "shared.h"
#include "Rte_Type.h"
extern uint8_t Core[6][10];
#if (defined(__TASKING__))
#define OS_CORE4_START_SEC_CODE
#include "Os_MemMap.h"
#endif

void idle_hook_core4(void);
void idle_hook_core4(void)
{
  idle_hook_body();
}

/**********************************************************************************************************************
 * Task:     Bsw_QM_Event_Task_Core0
 * Priority: 170
 * Schedule: FULL
 *********************************************************************************************************************/
 TASK(Bsw_Init_Task_Core4)
 {
   Core[4][0]++;
   Tm_Start(40);
   EcuM_StartupTwo();
   Rte_Start();    
   while (((volatile uint8)Rte_InitState) != RTE_STATE_INIT)
    {

    }
   Tm_Stop(40);
   TerminateTask();
 }
 /**********************************************************************************************************************
 * Task:     Bsw_QM_Event_Task_Core0
 * Priority: 170
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Bsw_P1ms_Task_Core4)
{
	Core[4][1]++;
  Tm_Start(41);
  Tm_Stop(41); 
  TerminateTask();
}
 /**********************************************************************************************************************
 * Task:     Bsw_QM_Event_Task_Core0
 * Priority: 170
 * Schedule: FULL
 *********************************************************************************************************************/

TASK(Bsw_P5ms_Task_Core4)
{
	Core[4][2]++;
  Tm_Start(42);
  Tm_Stop(42);
  TerminateTask();
}
 /**********************************************************************************************************************
 * Task:     Bsw_QM_Event_Task_Core0
 * Priority: 170
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Bsw_P10ms_Task_Core4)
{
	Core[4][3]++;
  Tm_Start(43);
  EcuM_MainFunction();  
  Tm_Stop(43);
  TerminateTask();
}
 /**********************************************************************************************************************
 * Task:     Bsw_QM_Event_Task_Core0
 * Priority: 170
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(Bsw_P100ms_Task_Core4)
{
  Core[4][4]++;
  Tm_Start(44);
  Clm_runnable_100ms();
  Tm_Stop(44);  

  TerminateTask();
}


#if (defined(__TASKING__))
#define OS_CORE4_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif

