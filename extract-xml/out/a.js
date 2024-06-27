let a = `
#define Rte_IrvIWrite_EM_20ms_EMOutp(data)  \
(  \
    Rte_Irv_control_swc_sweep_EMOutp_oEMOutp = *(data) \
)
            `

            console.info(a);