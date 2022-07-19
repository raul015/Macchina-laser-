#ifndef RTW_HEADER_homing_ldm_cap_host_h_
#define RTW_HEADER_homing_ldm_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"

typedef struct {
  rtwCAPI_ModelMappingInfo mmi;
} homing_ldm_host_DataMapInfo_T;

#ifdef __cplusplus

extern "C" {

#endif

  void homing_ldm_host_InitializeDataMapInfo(homing_ldm_host_DataMapInfo_T
    *dataMap, const char *path);

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */
#endif                                 /* RTW_HEADER_homing_ldm_cap_host_h_ */

/* EOF: homing_ldm_capi_host.h */
