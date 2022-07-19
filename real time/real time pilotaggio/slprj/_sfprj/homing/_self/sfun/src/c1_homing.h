#ifndef __c1_homing_h__
#define __c1_homing_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_homingInstanceStruct
#define typedef_SFc1_homingInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c1_dataWrittenToVector[12];
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
  void *c1_fEmlrtCtx;
  int32_T *c1_sfEvent;
  uint8_T *c1_is_active_c1_homing;
  uint8_T *c1_is_c1_homing;
  uint8_T *c1_is_Homing;
  real_T *c1_fcx;
  real_T *c1_Vel_x_out;
  real_T *c1_Vel_x;
  real_T *c1_ok_x;
  real_T *c1_ok_y;
  real_T *c1_Vel_y;
  real_T *c1_Vel_y_out;
  real_T *c1_fcy;
  real_T *c1_Pos_x;
  real_T *c1_dx;
  real_T *c1_ok_x_2;
  real_T *c1_v_sp_x;
  real_T *c1_v_sp_y;
  real_T *c1_Pos_y;
  real_T *c1_ok_y_2;
  real_T *c1_dy;
  real_T *c1_bx;
  real_T *c1_by;
} SFc1_homingInstanceStruct;

#endif                                 /*typedef_SFc1_homingInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_homing_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_homing_get_check_sum(mxArray *plhs[]);
extern void c1_homing_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
