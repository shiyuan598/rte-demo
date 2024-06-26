/**
 * ********************************************************************************************************************
 * @file Rte_IDCProxy.h
 * @brief Rte Interface for IDCProxy
 * @author zhito 
 * @version 1.0.0
 * @date 2023-12-11 13:21:55
 * @copyright Copyright (c) Zhito Co., Ltd. 2020-2035. All rights reserved.
 * ********************************************************************************************************************
 */
#ifndef RTE_IDCPROXY_H
#define RTE_IDCPROXY_H

#include "Rte_Type.h"

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IDCProxy_RxSocAdminData_oRxSocAdminData(RxSocAdminDataType* data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IDCProxy_TxSocAdminData_oTxSocAdminData(TxSocAdminDataType* data);

#endif
