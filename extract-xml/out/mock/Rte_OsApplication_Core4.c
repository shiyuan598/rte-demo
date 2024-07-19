

/**
 * ********************************************************************************************************************
 * @file Rte_OsApplication_Core4.c
 * @brief Rte Interface for OsApplication_Core4
 * @author zhito 
 * @version 1.0.0
 * @date 2024-07-04 19:18:06
 * @copyright Copyright (c) Zhito Co., Ltd. 2020-2035. All rights reserved.
 * ********************************************************************************************************************
 */

#include "shared.h"
#include "IDC.h"
#include "Rte_control_swc_sweep.h"
#include "Rte_CddMsgUpd.h"
#include "ee_oo_api_osek.h"


VAR(LocalizationInfo, RTE_VAR_INIT_NOCACHE) Rte_LocalizationInfo_oLocalizationInfo = {
  0U, 0U, 0U, 0U, 0U, 0.0, 0.0F, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F},
  {0.0F, 0.0F, 0.0F}, 0.0F, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, {0.0F, 0.0F, 0.0F}, 0.0, 0U, {0.0,
  0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, 0.0, 0.0, 0.0
};

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IDC_LocalizationInfo_oLocalizationInfo(LocalizationInfo* data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_DisableOSInterrupts();
    (void)GetSpinlock(Rte_Spinlock_LocalizationInfo_oLocalizationInfo);
    Rte_LocalizationInfo_oLocalizationInfo = *(data);
    (void)ReleaseSpinlock(Rte_Spinlock_LocalizationInfo_oLocalizationInfo);
    Rte_EnableOSInterrupts();
    return ret;
}

