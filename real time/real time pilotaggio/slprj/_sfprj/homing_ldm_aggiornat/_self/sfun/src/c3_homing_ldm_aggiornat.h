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
  real_T c3_Vel_asse_x[3320];
  real_T c3_Vel_asse_y[3320];
  real_T c3_time[3320];
  real_T c3_x[3320];
  real_T c3_y[3320];
  boolean_T c3_dataWrittenToVector[33];
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  real_T c3_dv5[3320];
  real_T c3_dv6[3320];
  real_T c3_dv7[3320];
  real_T c3_dv8[3320];
  real_T c3_dv9[3320];
  real_T c3_t_m[3320];
  real_T c3_x_i[3320];
  real_T c3_b_t_m[3320];
  void *c3_fEmlrtCtx;
  int32_T *c3_sfEvent;
  uint8_T *c3_is_active_c3_homing_ldm_aggiornat;
  uint8_T *c3_is_c3_homing_ldm_aggiornat;
  uint8_T *c3_is_Pilotaggio;
  uint8_T *c3_is_Homing1;
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
  real_T *c3_v_sp_y;
  real_T *c3_Pos_y;
  real_T *c3_ok_y_2;
  real_T *c3_dy;
  real_T *c3_clock;
  real_T *c3_bx;
  real_T *c3_by;
  real_T *c3_inizio_traiettoria;
  real_T *c3_g2x;
  real_T *c3_g1x;
  real_T *c3_g2y;
  real_T *c3_g1y;
  real_T *c3_deltaxp;
  real_T *c3_deltayp;
  real_T *c3_ix;
  real_T *c3_iy;
  real_T *c3_deltax;
  real_T *c3_deltay;
  real_T *c3_tensionex;
  real_T *c3_tensioney;
  real_T *c3_ok_x_3;
  real_T *c3_ok_y_3;
  real_T *c3_rifx;
  real_T *c3_rifxp;
  real_T *c3_rify;
  real_T *c3_rifyp;
  real_T *c3_appoggio;
  real_T *c3_rif_iniziale;
  real_T *c3_t1;
  real_T *c3_t;
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
