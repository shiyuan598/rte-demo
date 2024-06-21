/**
 * ********************************************************************************************************************
 * @file Rte_OsApplication_Core1.c
 * @brief Rte Interface for OsApplication_Core1
 * @author zhito 
 * @version 1.0.0
 * @date 2023-12-11 13:21:55
 * @copyright Copyright (c) Zhito Co., Ltd. 2020-2035. All rights reserved.
 * ********************************************************************************************************************
 */
#include "shared.h"
#include "SchM_StbM.h"
#include "SchM_EthTSyn.h"
#include "SchM_Xcp.h"
#include "EthTSyn_Types.h"
#include "EthIf_GenTypes.h"
#include "Eth_17_GEthMac_PBcfg.h"
#include "TIM.h"
#include "EthSM_Cfg.h"
#include "../test/rtps_interface.h"
#include "Rte_control_swc_sweep.h"
#include "Rte_CddMsgUpd.h"
#include "Rte_IDCProxy.h"
#include "NV_SWC_Shell.h"

VAR(RxSocAdminDataType, RTE_VAR_NOINIT_NOCACHE) Rte_RxSocAdminData_oRxSocAdminData;

VAR(rt_Array_uint8_100, RTE_VAR_INIT_NOCACHE) Rte_UpdateMgr_AdminData_MirrorBlock_oUpdateMgr_AdminData_MirrorBlock = {0u};

VAR(rt_Array_uint8_128, RTE_VAR_INIT_NOCACHE) Rte_Orin0RxData_oOrin0RxData = {0u};

VAR(rt_Array_uint8_128, RTE_VAR_INIT_NOCACHE) Rte_Orin1RxData_oOrin1RxData = {0u};

VAR(rt_Array_uint8_128, RTE_VAR_INIT_NOCACHE) Rte_Orin2RxData_oOrin2RxData = {0u};

VAR(rt_Array_uint8_128, RTE_VAR_INIT_NOCACHE) Rte_Orin3RxData_oOrin3RxData = {0u};

VAR(rt_Array_uint8_12, RTE_VAR_INIT_NOCACHE) Rte_Core2TimeStamp_oCore2TimeStamp = {0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u};

VAR(rt_Array_uint8_12, RTE_VAR_INIT_NOCACHE) Rte_Core0TimeStamp_oCore0TimeStamp = {0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u};

VAR(rt_Array_uint8_12, RTE_VAR_INIT_NOCACHE) Rte_Core3TimeStamp_oCore3TimeStamp = {0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u};

VAR(rt_Array_uint8_12, RTE_VAR_INIT_NOCACHE) Rte_Core5TimeStamp_oCore5TimeStamp = {0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u,0u};

#if (defined(__TASKING__))
#define OS_CORE1_START_SEC_CODE
#include "Os_MemMap.h"
#endif

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDCProxy_ARS408_Info_ETH_oARS408_Info_ETH(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_ARS408_Info_ETH_oARS408_Info_ETH);
  (void)memcpy(data,Rte_ARS408_Info_ETH_oARS408_Info_ETH,sizeof(rt_Array_uint8_6876));
  (void)ReleaseSpinlock(Rte_Spinlock_ARS408_Info_ETH_oARS408_Info_ETH);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDCProxy_ARS408_ETH_Tx_Flag_oARS408_ETH_Tx_Flag(boolean* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_ARS408_ETH_Tx_Flag_oARS408_ETH_Tx_Flag);
  *data = Rte_ARS408_ETH_Tx_Flag_oARS408_ETH_Tx_Flag;
  if(TRUE == Rte_ARS408_ETH_Tx_Flag_oARS408_ETH_Tx_Flag)
  {
    Rte_ARS408_ETH_Tx_Flag_oARS408_ETH_Tx_Flag = FALSE;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_ARS408_ETH_Tx_Flag_oARS408_ETH_Tx_Flag);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDCProxy_ARS430_Info_ETH_oARS430_Info_ETH(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_ARS430_Info_ETH_oARS430_Info_ETH);
  (void)memcpy(data,Rte_ARS430_Info_ETH_oARS430_Info_ETH,sizeof(rt_Array_uint8_5192));
  (void)ReleaseSpinlock(Rte_Spinlock_ARS430_Info_ETH_oARS430_Info_ETH);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDCProxy_ARS430_ETH_Tx_Flag_oARS430_ETH_Tx_Flag(boolean* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_ARS430_ETH_Tx_Flag_oARS430_ETH_Tx_Flag);
  *data = Rte_ARS430_ETH_Tx_Flag_oARS430_ETH_Tx_Flag;
  if(TRUE == Rte_ARS430_ETH_Tx_Flag_oARS430_ETH_Tx_Flag)
  {
    Rte_ARS430_ETH_Tx_Flag_oARS430_ETH_Tx_Flag = FALSE;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_ARS430_ETH_Tx_Flag_oARS430_ETH_Tx_Flag);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDCProxy_GNSS_Info_ETH_oGNSS_Info_ETH(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_GNSS_Info_ETH_oGNSS_Info_ETH);
  (void)memcpy(data,Rte_GNSS_Info_ETH_oGNSS_Info_ETH,sizeof(rt_Array_uint8_224));
  (void)ReleaseSpinlock(Rte_Spinlock_GNSS_Info_ETH_oGNSS_Info_ETH);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MSDCProxy_GNSS_ETH_Tx_Flag_oGNSS_ETH_Tx_Flag(boolean* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_GNSS_ETH_Tx_Flag_oGNSS_ETH_Tx_Flag);
  *data = Rte_GNSS_ETH_Tx_Flag_oGNSS_ETH_Tx_Flag;
  if(TRUE == Rte_GNSS_ETH_Tx_Flag_oGNSS_ETH_Tx_Flag)
  {
    Rte_GNSS_ETH_Tx_Flag_oGNSS_ETH_Tx_Flag = FALSE;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_GNSS_ETH_Tx_Flag_oGNSS_ETH_Tx_Flag);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IDCProxy_RxSocAdminData_oRxSocAdminData(RxSocAdminDataType* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_RxSocAdminData_oRxSocAdminData);
  if(sizeof(RxSocAdminDataType) > 200u)
  {
    (void)memcpy(&Rte_RxSocAdminData_oRxSocAdminData,data,sizeof(RxSocAdminDataType));
  }
  else
  {
    Rte_RxSocAdminData_oRxSocAdminData = *data;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_RxSocAdminData_oRxSocAdminData);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IDCProxy_TxSocAdminData_oTxSocAdminData(TxSocAdminDataType* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_TxSocAdminData_oTxSocAdminData);
  if(sizeof(TxSocAdminDataType) > 200u)
  {
    (void)memcpy(data,&Rte_TxSocAdminData_oTxSocAdminData,sizeof(TxSocAdminDataType));
  }
  else
  {
    *data = Rte_TxSocAdminData_oTxSocAdminData;
  }
  (void)ReleaseSpinlock(Rte_Spinlock_TxSocAdminData_oTxSocAdminData);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CGI610PROXY_Cgi610_1_Data_oCgi610_1_Data(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Cgi610_1_Data_oCgi610_1_Data);
  (void)memcpy(data,Rte_Cgi610_1_Data_oCgi610_1_Data,sizeof(rt_Array_uint8_208));
  (void)ReleaseSpinlock(Rte_Spinlock_Cgi610_1_Data_oCgi610_1_Data);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CGI610PROXY_Cgi610_2_Data_oCgi610_2_Data(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Cgi610_2_Data_oCgi610_2_Data);
  (void)memcpy(data,Rte_Cgi610_2_Data_oCgi610_2_Data,sizeof(rt_Array_uint8_208));
  (void)ReleaseSpinlock(Rte_Spinlock_Cgi610_2_Data_oCgi610_2_Data);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CGI610PROXY_Cgi610_3_Data_oCgi610_3_Data(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Cgi610_3_Data_oCgi610_3_Data);
  (void)memcpy(data,Rte_Cgi610_3_Data_oCgi610_3_Data,sizeof(rt_Array_uint8_208));
  (void)ReleaseSpinlock(Rte_Spinlock_Cgi610_3_Data_oCgi610_3_Data);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CGI610PROXY_Cgi610_4_Data_oCgi610_4_Data(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Cgi610_4_Data_oCgi610_4_Data);
  (void)memcpy(data,Rte_Cgi610_4_Data_oCgi610_4_Data,sizeof(rt_Array_uint8_208));
  (void)ReleaseSpinlock(Rte_Spinlock_Cgi610_4_Data_oCgi610_4_Data);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CGI610PROXY_Cgi610_5_Data_oCgi610_5_Data(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Cgi610_5_Data_oCgi610_5_Data);
  (void)memcpy(data,Rte_Cgi610_5_Data_oCgi610_5_Data,sizeof(rt_Array_uint8_208));
  (void)ReleaseSpinlock(Rte_Spinlock_Cgi610_5_Data_oCgi610_5_Data);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_UpdateManage_UpdateMgr_AdminData_MirrorBlock_oUpdateMgr_AdminData_MirrorBlock(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)memcpy(data,Rte_UpdateMgr_AdminData_MirrorBlock_oUpdateMgr_AdminData_MirrorBlock,sizeof(rt_Array_uint8_100));

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_UpdateManage_UpdateMgr_AdminData_MirrorBlock_oUpdateMgr_AdminData_MirrorBlock(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  (void)memcpy(Rte_UpdateMgr_AdminData_MirrorBlock_oUpdateMgr_AdminData_MirrorBlock,data,sizeof(rt_Array_uint8_100));

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PowMgrProxy_Orin0RxData_oOrin0RxData(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Orin0RxData_oOrin0RxData);
  (void)memcpy(Rte_Orin0RxData_oOrin0RxData,data,sizeof(rt_Array_uint8_128));
  (void)ReleaseSpinlock(Rte_Spinlock_Orin0RxData_oOrin0RxData);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PowMgrProxy_Orin1RxData_oOrin1RxData(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Orin1RxData_oOrin1RxData);
  (void)memcpy(Rte_Orin1RxData_oOrin1RxData,data,sizeof(rt_Array_uint8_128));
  (void)ReleaseSpinlock(Rte_Spinlock_Orin1RxData_oOrin1RxData);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PowMgrProxy_Orin2RxData_oOrin2RxData(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Orin2RxData_oOrin2RxData);
  (void)memcpy(Rte_Orin2RxData_oOrin2RxData,data,sizeof(rt_Array_uint8_128));
  (void)ReleaseSpinlock(Rte_Spinlock_Orin2RxData_oOrin2RxData);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PowMgrProxy_Orin3RxData_oOrin3RxData(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Orin3RxData_oOrin3RxData);
  (void)memcpy(Rte_Orin3RxData_oOrin3RxData,data,sizeof(rt_Array_uint8_128));
  (void)ReleaseSpinlock(Rte_Spinlock_Orin3RxData_oOrin3RxData);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_TIM_Core2TimeStamp_oCore2TimeStamp(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Core2TimeStamp_oCore2TimeStamp);
  (void)memcpy(Rte_Core2TimeStamp_oCore2TimeStamp,data,sizeof(rt_Array_uint8_12));
  (void)ReleaseSpinlock(Rte_Spinlock_Core2TimeStamp_oCore2TimeStamp);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_TIM_Core0TimeStamp_oCore0TimeStamp(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Core0TimeStamp_oCore0TimeStamp);
  (void)memcpy(Rte_Core0TimeStamp_oCore0TimeStamp,data,sizeof(rt_Array_uint8_12));
  (void)ReleaseSpinlock(Rte_Spinlock_Core0TimeStamp_oCore0TimeStamp);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_TIM_Core3TimeStamp_oCore3TimeStamp(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Core3TimeStamp_oCore3TimeStamp);
  (void)memcpy(Rte_Core3TimeStamp_oCore3TimeStamp,data,sizeof(rt_Array_uint8_12));
  (void)ReleaseSpinlock(Rte_Spinlock_Core3TimeStamp_oCore3TimeStamp);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_TIM_Core5TimeStamp_oCore5TimeStamp(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_Core5TimeStamp_oCore5TimeStamp);
  (void)memcpy(Rte_Core5TimeStamp_oCore5TimeStamp,data,sizeof(rt_Array_uint8_12));
  (void)ReleaseSpinlock(Rte_Spinlock_Core5TimeStamp_oCore5TimeStamp);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PPSProxy_PpsStatus_oPpsStatus(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_PpsStatus_oPpsStatus);
  (void)memcpy(data,Rte_PpsStatus_oPpsStatus,sizeof(rt_Array_uint8_200));
  (void)ReleaseSpinlock(Rte_Spinlock_PpsStatus_oPpsStatus);
  Rte_EnableOSInterrupts();

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PowMgrProxy_PowerMngComData_oPowerMngComData(uint8* data)
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_DisableOSInterrupts();
  (void)GetSpinlock(Rte_Spinlock_PowerMngComData_oPowerMngComData);
  (void)memcpy(data,Rte_PowerMngComData_oPowerMngComData,sizeof(rt_Array_uint8_1024));
  (void)ReleaseSpinlock(Rte_Spinlock_PowerMngComData_oPowerMngComData);
  Rte_EnableOSInterrupts();

  return ret;
}
/**********************************************************************************************************************
 * Task:     Bsw_QM_Event_Task_Core0
 * Priority: 170
 * Schedule: FULL
 *********************************************************************************************************************/
void idle_hook_core1(void);
void idle_hook_core1(void)
{
  idle_hook_body();
}
extern uint8_t Core[6][10];
/********************************************************************************************************************