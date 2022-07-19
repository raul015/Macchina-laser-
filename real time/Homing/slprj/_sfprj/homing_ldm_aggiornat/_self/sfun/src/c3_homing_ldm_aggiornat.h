#ifndef __c3_homing_ldm_aggiornat_h__
#define __c3_homing_ldm_aggiornat_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_homing_ldm_aggiornatInstanceStruct
#define typedef_SFc3_homing_ldm_aggiornatInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c3_dataWrittenToVector[15];
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  void *c3_fEmlrtCtx;
  int32_T *c3_sfEvent;
  uint8_T *c3_is_active_c3_homing_ldm_aggiornat;
  uint8_T *c3_is_c3_homing_ldm_aggiornat;
  uint8_T *c3_is_Homing1;
  uint8_T *c3_is_Homing2;
  real_T *c3_fcx;
  real_T *c3_Vel_x_out;
  real_T *c3_Vel_x;
  real_T *c3_ok_x;
  real_T *c3_ok_y;
  real_T *c3_Vel_y;
  real_T *c3_Vel_y_out;
  real_T *c3_fcy;
  real_T *c3_Pos_x;
  real_T *c3_dx;
  real_T *c3_ok_x_2;
  real_T *c3_v_sp_x;
  real_T *c3_a;
  real_T *c3_v_sp_y;
  real_T *c3_ay;
  real_T *c3_Pos_y;
  real_T *c3_ok_y_2;
  real_T *c3_dy;
  real_T *c3_clock;
  real_T *c3_bx;
  real_T *c3_by;
  real_T *c3_inizio_traiettoria;
} SFc3_homing_ldm_aggiornatInstanceStruct;

#endif                                 /*typedef_SFc3_homing_ldm_aggiornatInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_homing_ldm_aggiornat_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c3_homing_ldm_aggiornat_get_check_sum(mxArray *plhs[]);
extern void c3_homing_ldm_aggiornat_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
