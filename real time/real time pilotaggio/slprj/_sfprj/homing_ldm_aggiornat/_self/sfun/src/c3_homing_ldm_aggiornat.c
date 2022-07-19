/* Include files */

#include "homing_ldm_aggiornat_sfun.h"
#include "c3_homing_ldm_aggiornat.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "homing_ldm_aggiornat_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c3_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c3_IN_Homing1                  ((uint8_T)1U)
#define c3_IN_Pilotaggio               ((uint8_T)2U)
#define c3_IN_Fine                     ((uint8_T)1U)
#define c3_IN_Fine_homing1             ((uint8_T)2U)
#define c3_IN_Homing_x                 ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_c_debug_family_names[13] = { "nargin", "nargout", "x_i",
  "xp_i", "y_i", "yp_i", "u", "t_m", "riff_iniziale", "xx", "xxp", "yy", "yyp" };

static const char * c3_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_j_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_k_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_m_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_n_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

/* Function Declarations */
static void initialize_c3_homing_ldm_aggiornat
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance);
static void initialize_params_c3_homing_ldm_aggiornat
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance);
static void enable_c3_homing_ldm_aggiornat
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance);
static void disable_c3_homing_ldm_aggiornat
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_homing_ldm_aggiornat
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance);
static void ext_mode_exec_c3_homing_ldm_aggiornat
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_homing_ldm_aggiornat
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance);
static void set_sim_state_c3_homing_ldm_aggiornat
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance, const mxArray *c3_st);
static void c3_set_sim_state_side_effects_c3_homing_ldm_aggiornat
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance);
static void finalize_c3_homing_ldm_aggiornat
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance);
static void sf_gateway_c3_homing_ldm_aggiornat
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance);
static void mdl_start_c3_homing_ldm_aggiornat
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance);
static void initSimStructsc3_homing_ldm_aggiornat
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance);
static void c3_Pilotaggio(SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance);
static void c3_Homing1(SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance);
static void c3_exit_internal_Homing1(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance);
static real_T c3_interp1(SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance,
  real_T c3_varargin_1[3320], real_T c3_varargin_2[3320], real_T c3_varargin_3,
  real_T c3_varargin_5);
static void c3_error(SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance);
static void c3_b_error(SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance);
static real_T c3_b_interp1(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, real_T c3_varargin_1[3320], real_T c3_varargin_2[3320], real_T
  c3_varargin_3);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_nargout, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_c_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_b_y[3320]);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_d_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_interpolazione_tempi2(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, real_T c3_b_x_i[3320], real_T c3_xp_i[3320], real_T c3_y_i
  [3320], real_T c3_yp_i[3320], real_T c3_u, real_T c3_c_t_m[3320], real_T
  c3_riff_iniziale, real_T *c3_xx, real_T *c3_xxp, real_T *c3_yy, real_T *c3_yyp);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_e_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_f_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_b_is_Pilotaggio, const char_T *c3_identifier);
static uint8_T c3_g_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_h_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_b_dataWrittenToVector, const char_T
  *c3_identifier, boolean_T c3_b_y[33]);
static void c3_i_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T c3_b_y[33]);
static const mxArray *c3_j_emlrt_marshallIn
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance, const mxArray
   *c3_b_setSimStateSideEffectsInfo, const char_T *c3_identifier);
static const mxArray *c3_k_emlrt_marshallIn
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance, const mxArray *c3_u,
   const emlrtMsgIdentifier *c3_parentId);
static const mxArray *sf_get_hover_data_for_msg
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance, int32_T c3_ssid);
static void c3_init_sf_message_store_memory
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance);
static void init_dsm_address_info(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_homing_ldm_aggiornat
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc3_homing_ldm_aggiornat(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  *chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_doSetSimStateSideEffects = 0U;
  chartInstance->c3_setSimStateSideEffectsInfo = NULL;
  *chartInstance->c3_is_Homing1 = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_is_Pilotaggio = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_is_active_c3_homing_ldm_aggiornat = 0U;
  *chartInstance->c3_is_c3_homing_ldm_aggiornat = c3_IN_NO_ACTIVE_CHILD;
}

static void initialize_params_c3_homing_ldm_aggiornat
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance)
{
  real_T c3_dv0[3320];
  int32_T c3_i0;
  real_T c3_dv1[3320];
  int32_T c3_i1;
  real_T c3_dv2[3320];
  int32_T c3_i2;
  real_T c3_dv3[3320];
  int32_T c3_i3;
  real_T c3_dv4[3320];
  int32_T c3_i4;
  sf_mex_import_named("Vel_asse_x", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c3_dv0, 0, 0, 0U, 1, 0U, 2, 1, 3320);
  for (c3_i0 = 0; c3_i0 < 3320; c3_i0++) {
    chartInstance->c3_Vel_asse_x[c3_i0] = c3_dv0[c3_i0];
  }

  sf_mex_import_named("Vel_asse_y", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      c3_dv1, 0, 0, 0U, 1, 0U, 2, 1, 3320);
  for (c3_i1 = 0; c3_i1 < 3320; c3_i1++) {
    chartInstance->c3_Vel_asse_y[c3_i1] = c3_dv1[c3_i1];
  }

  sf_mex_import_named("time", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                      c3_dv2, 0, 0, 0U, 1, 0U, 2, 1, 3320);
  for (c3_i2 = 0; c3_i2 < 3320; c3_i2++) {
    chartInstance->c3_time[c3_i2] = c3_dv2[c3_i2];
  }

  sf_mex_import_named("x", sf_mex_get_sfun_param(chartInstance->S, 3, 0), c3_dv3,
                      0, 0, 0U, 1, 0U, 2, 1, 3320);
  for (c3_i3 = 0; c3_i3 < 3320; c3_i3++) {
    chartInstance->c3_x[c3_i3] = c3_dv3[c3_i3];
  }

  sf_mex_import_named("y", sf_mex_get_sfun_param(chartInstance->S, 4, 0), c3_dv4,
                      0, 0, 0U, 1, 0U, 2, 1, 3320);
  for (c3_i4 = 0; c3_i4 < 3320; c3_i4++) {
    chartInstance->c3_y[c3_i4] = c3_dv4[c3_i4];
  }
}

static void enable_c3_homing_ldm_aggiornat
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_homing_ldm_aggiornat
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_homing_ldm_aggiornat
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance)
{
  uint32_T c3_prevAniVal;
  c3_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (*chartInstance->c3_is_active_c3_homing_ldm_aggiornat == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_c3_homing_ldm_aggiornat == c3_IN_Pilotaggio) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_Pilotaggio == c3_IN_Pilotaggio) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_Pilotaggio == c3_IN_Fine) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_c3_homing_ldm_aggiornat == c3_IN_Homing1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_Homing1 == c3_IN_Homing_x) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_Homing1 == c3_IN_Fine_homing1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_Homing1 == c3_IN_Fine) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c3_sfEvent);
  }

  _SFD_SET_ANIMATION(c3_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static void ext_mode_exec_c3_homing_ldm_aggiornat
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance)
{
  c3_update_debugger_state_c3_homing_ldm_aggiornat(chartInstance);
}

static const mxArray *get_sim_state_c3_homing_ldm_aggiornat
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_b_y = NULL;
  real_T c3_hoistedGlobal;
  const mxArray *c3_c_y = NULL;
  real_T c3_b_hoistedGlobal;
  const mxArray *c3_d_y = NULL;
  real_T c3_c_hoistedGlobal;
  const mxArray *c3_e_y = NULL;
  real_T c3_d_hoistedGlobal;
  const mxArray *c3_f_y = NULL;
  real_T c3_e_hoistedGlobal;
  const mxArray *c3_g_y = NULL;
  real_T c3_f_hoistedGlobal;
  const mxArray *c3_h_y = NULL;
  real_T c3_g_hoistedGlobal;
  const mxArray *c3_i_y = NULL;
  real_T c3_h_hoistedGlobal;
  const mxArray *c3_j_y = NULL;
  real_T c3_i_hoistedGlobal;
  const mxArray *c3_k_y = NULL;
  real_T c3_j_hoistedGlobal;
  const mxArray *c3_l_y = NULL;
  real_T c3_k_hoistedGlobal;
  const mxArray *c3_m_y = NULL;
  real_T c3_l_hoistedGlobal;
  const mxArray *c3_n_y = NULL;
  real_T c3_m_hoistedGlobal;
  const mxArray *c3_o_y = NULL;
  real_T c3_n_hoistedGlobal;
  const mxArray *c3_p_y = NULL;
  real_T c3_o_hoistedGlobal;
  const mxArray *c3_q_y = NULL;
  real_T c3_p_hoistedGlobal;
  const mxArray *c3_r_y = NULL;
  real_T c3_q_hoistedGlobal;
  const mxArray *c3_s_y = NULL;
  real_T c3_r_hoistedGlobal;
  const mxArray *c3_t_y = NULL;
  real_T c3_s_hoistedGlobal;
  const mxArray *c3_u_y = NULL;
  real_T c3_t_hoistedGlobal;
  const mxArray *c3_v_y = NULL;
  real_T c3_u_hoistedGlobal;
  const mxArray *c3_w_y = NULL;
  real_T c3_v_hoistedGlobal;
  const mxArray *c3_x_y = NULL;
  real_T c3_w_hoistedGlobal;
  const mxArray *c3_y_y = NULL;
  real_T c3_x_hoistedGlobal;
  const mxArray *c3_ab_y = NULL;
  real_T c3_y_hoistedGlobal;
  const mxArray *c3_bb_y = NULL;
  real_T c3_ab_hoistedGlobal;
  const mxArray *c3_cb_y = NULL;
  real_T c3_bb_hoistedGlobal;
  const mxArray *c3_db_y = NULL;
  real_T c3_cb_hoistedGlobal;
  const mxArray *c3_eb_y = NULL;
  real_T c3_db_hoistedGlobal;
  const mxArray *c3_fb_y = NULL;
  uint8_T c3_eb_hoistedGlobal;
  const mxArray *c3_gb_y = NULL;
  uint8_T c3_fb_hoistedGlobal;
  const mxArray *c3_hb_y = NULL;
  uint8_T c3_gb_hoistedGlobal;
  const mxArray *c3_ib_y = NULL;
  uint8_T c3_hb_hoistedGlobal;
  const mxArray *c3_jb_y = NULL;
  const mxArray *c3_kb_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_createcellmatrix(34, 1), false);
  c3_hoistedGlobal = *chartInstance->c3_Vel_x_out;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_hoistedGlobal, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c3_b_y, 0, c3_c_y);
  c3_b_hoistedGlobal = *chartInstance->c3_Vel_y_out;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_b_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 1, c3_d_y);
  c3_c_hoistedGlobal = *chartInstance->c3_ok_x;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_c_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 2, c3_e_y);
  c3_d_hoistedGlobal = *chartInstance->c3_ok_x_2;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_d_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 3, c3_f_y);
  c3_e_hoistedGlobal = *chartInstance->c3_ok_x_3;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_e_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 4, c3_g_y);
  c3_f_hoistedGlobal = *chartInstance->c3_ok_y;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_f_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 5, c3_h_y);
  c3_g_hoistedGlobal = *chartInstance->c3_ok_y_2;
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_g_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 6, c3_i_y);
  c3_h_hoistedGlobal = *chartInstance->c3_ok_y_3;
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", &c3_h_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 7, c3_j_y);
  c3_i_hoistedGlobal = *chartInstance->c3_tensionex;
  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y", &c3_i_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 8, c3_k_y);
  c3_j_hoistedGlobal = *chartInstance->c3_tensioney;
  c3_l_y = NULL;
  sf_mex_assign(&c3_l_y, sf_mex_create("y", &c3_j_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 9, c3_l_y);
  c3_k_hoistedGlobal = *chartInstance->c3_appoggio;
  c3_m_y = NULL;
  sf_mex_assign(&c3_m_y, sf_mex_create("y", &c3_k_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 10, c3_m_y);
  c3_l_hoistedGlobal = *chartInstance->c3_bx;
  c3_n_y = NULL;
  sf_mex_assign(&c3_n_y, sf_mex_create("y", &c3_l_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 11, c3_n_y);
  c3_m_hoistedGlobal = *chartInstance->c3_by;
  c3_o_y = NULL;
  sf_mex_assign(&c3_o_y, sf_mex_create("y", &c3_m_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 12, c3_o_y);
  c3_n_hoistedGlobal = *chartInstance->c3_deltax;
  c3_p_y = NULL;
  sf_mex_assign(&c3_p_y, sf_mex_create("y", &c3_n_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 13, c3_p_y);
  c3_o_hoistedGlobal = *chartInstance->c3_deltaxp;
  c3_q_y = NULL;
  sf_mex_assign(&c3_q_y, sf_mex_create("y", &c3_o_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 14, c3_q_y);
  c3_p_hoistedGlobal = *chartInstance->c3_deltay;
  c3_r_y = NULL;
  sf_mex_assign(&c3_r_y, sf_mex_create("y", &c3_p_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 15, c3_r_y);
  c3_q_hoistedGlobal = *chartInstance->c3_deltayp;
  c3_s_y = NULL;
  sf_mex_assign(&c3_s_y, sf_mex_create("y", &c3_q_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 16, c3_s_y);
  c3_r_hoistedGlobal = *chartInstance->c3_dx;
  c3_t_y = NULL;
  sf_mex_assign(&c3_t_y, sf_mex_create("y", &c3_r_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 17, c3_t_y);
  c3_s_hoistedGlobal = *chartInstance->c3_dy;
  c3_u_y = NULL;
  sf_mex_assign(&c3_u_y, sf_mex_create("y", &c3_s_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 18, c3_u_y);
  c3_t_hoistedGlobal = *chartInstance->c3_inizio_traiettoria;
  c3_v_y = NULL;
  sf_mex_assign(&c3_v_y, sf_mex_create("y", &c3_t_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 19, c3_v_y);
  c3_u_hoistedGlobal = *chartInstance->c3_rif_iniziale;
  c3_w_y = NULL;
  sf_mex_assign(&c3_w_y, sf_mex_create("y", &c3_u_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 20, c3_w_y);
  c3_v_hoistedGlobal = *chartInstance->c3_rifx;
  c3_x_y = NULL;
  sf_mex_assign(&c3_x_y, sf_mex_create("y", &c3_v_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 21, c3_x_y);
  c3_w_hoistedGlobal = *chartInstance->c3_rifxp;
  c3_y_y = NULL;
  sf_mex_assign(&c3_y_y, sf_mex_create("y", &c3_w_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 22, c3_y_y);
  c3_x_hoistedGlobal = *chartInstance->c3_rify;
  c3_ab_y = NULL;
  sf_mex_assign(&c3_ab_y, sf_mex_create("y", &c3_x_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 23, c3_ab_y);
  c3_y_hoistedGlobal = *chartInstance->c3_rifyp;
  c3_bb_y = NULL;
  sf_mex_assign(&c3_bb_y, sf_mex_create("y", &c3_y_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 24, c3_bb_y);
  c3_ab_hoistedGlobal = *chartInstance->c3_t;
  c3_cb_y = NULL;
  sf_mex_assign(&c3_cb_y, sf_mex_create("y", &c3_ab_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 25, c3_cb_y);
  c3_bb_hoistedGlobal = *chartInstance->c3_t1;
  c3_db_y = NULL;
  sf_mex_assign(&c3_db_y, sf_mex_create("y", &c3_bb_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 26, c3_db_y);
  c3_cb_hoistedGlobal = *chartInstance->c3_v_sp_x;
  c3_eb_y = NULL;
  sf_mex_assign(&c3_eb_y, sf_mex_create("y", &c3_cb_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 27, c3_eb_y);
  c3_db_hoistedGlobal = *chartInstance->c3_v_sp_y;
  c3_fb_y = NULL;
  sf_mex_assign(&c3_fb_y, sf_mex_create("y", &c3_db_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 28, c3_fb_y);
  c3_eb_hoistedGlobal = *chartInstance->c3_is_active_c3_homing_ldm_aggiornat;
  c3_gb_y = NULL;
  sf_mex_assign(&c3_gb_y, sf_mex_create("y", &c3_eb_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 29, c3_gb_y);
  c3_fb_hoistedGlobal = *chartInstance->c3_is_c3_homing_ldm_aggiornat;
  c3_hb_y = NULL;
  sf_mex_assign(&c3_hb_y, sf_mex_create("y", &c3_fb_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 30, c3_hb_y);
  c3_gb_hoistedGlobal = *chartInstance->c3_is_Pilotaggio;
  c3_ib_y = NULL;
  sf_mex_assign(&c3_ib_y, sf_mex_create("y", &c3_gb_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 31, c3_ib_y);
  c3_hb_hoistedGlobal = *chartInstance->c3_is_Homing1;
  c3_jb_y = NULL;
  sf_mex_assign(&c3_jb_y, sf_mex_create("y", &c3_hb_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_b_y, 32, c3_jb_y);
  c3_kb_y = NULL;
  sf_mex_assign(&c3_kb_y, sf_mex_create("y",
    chartInstance->c3_dataWrittenToVector, 11, 0U, 1U, 0U, 1, 33), false);
  sf_mex_setcell(c3_b_y, 33, c3_kb_y);
  sf_mex_assign(&c3_st, c3_b_y, false);
  return c3_st;
}

static void set_sim_state_c3_homing_ldm_aggiornat
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  boolean_T c3_bv0[33];
  int32_T c3_i5;
  c3_u = sf_mex_dup(c3_st);
  *chartInstance->c3_Vel_x_out = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Vel_x_out", c3_u, 0)), "Vel_x_out");
  *chartInstance->c3_Vel_y_out = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Vel_y_out", c3_u, 1)), "Vel_y_out");
  *chartInstance->c3_ok_x = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("ok_x", c3_u, 2)), "ok_x");
  *chartInstance->c3_ok_x_2 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("ok_x_2", c3_u, 3)), "ok_x_2");
  *chartInstance->c3_ok_x_3 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("ok_x_3", c3_u, 4)), "ok_x_3");
  *chartInstance->c3_ok_y = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("ok_y", c3_u, 5)), "ok_y");
  *chartInstance->c3_ok_y_2 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("ok_y_2", c3_u, 6)), "ok_y_2");
  *chartInstance->c3_ok_y_3 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("ok_y_3", c3_u, 7)), "ok_y_3");
  *chartInstance->c3_tensionex = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("tensionex", c3_u, 8)), "tensionex");
  *chartInstance->c3_tensioney = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("tensioney", c3_u, 9)), "tensioney");
  *chartInstance->c3_appoggio = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("appoggio", c3_u, 10)), "appoggio");
  *chartInstance->c3_bx = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("bx", c3_u, 11)), "bx");
  *chartInstance->c3_by = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("by", c3_u, 12)), "by");
  *chartInstance->c3_deltax = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("deltax", c3_u, 13)), "deltax");
  *chartInstance->c3_deltaxp = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("deltaxp", c3_u, 14)), "deltaxp");
  *chartInstance->c3_deltay = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("deltay", c3_u, 15)), "deltay");
  *chartInstance->c3_deltayp = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("deltayp", c3_u, 16)), "deltayp");
  *chartInstance->c3_dx = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("dx", c3_u, 17)), "dx");
  *chartInstance->c3_dy = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("dy", c3_u, 18)), "dy");
  *chartInstance->c3_inizio_traiettoria = c3_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("inizio_traiettoria", c3_u, 19)),
    "inizio_traiettoria");
  *chartInstance->c3_rif_iniziale = c3_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("rif_iniziale", c3_u, 20)), "rif_iniziale");
  *chartInstance->c3_rifx = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("rifx", c3_u, 21)), "rifx");
  *chartInstance->c3_rifxp = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("rifxp", c3_u, 22)), "rifxp");
  *chartInstance->c3_rify = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("rify", c3_u, 23)), "rify");
  *chartInstance->c3_rifyp = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("rifyp", c3_u, 24)), "rifyp");
  *chartInstance->c3_t = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("t", c3_u, 25)), "t");
  *chartInstance->c3_t1 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("t1", c3_u, 26)), "t1");
  *chartInstance->c3_v_sp_x = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("v_sp_x", c3_u, 27)), "v_sp_x");
  *chartInstance->c3_v_sp_y = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("v_sp_y", c3_u, 28)), "v_sp_y");
  *chartInstance->c3_is_active_c3_homing_ldm_aggiornat = c3_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(
       "is_active_c3_homing_ldm_aggiornat", c3_u, 29)),
     "is_active_c3_homing_ldm_aggiornat");
  *chartInstance->c3_is_c3_homing_ldm_aggiornat = c3_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_c3_homing_ldm_aggiornat", c3_u,
       30)), "is_c3_homing_ldm_aggiornat");
  *chartInstance->c3_is_Pilotaggio = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_Pilotaggio", c3_u, 31)), "is_Pilotaggio");
  *chartInstance->c3_is_Homing1 = c3_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_Homing1", c3_u, 32)), "is_Homing1");
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "dataWrittenToVector", c3_u, 33)), "dataWrittenToVector", c3_bv0);
  for (c3_i5 = 0; c3_i5 < 33; c3_i5++) {
    chartInstance->c3_dataWrittenToVector[c3_i5] = c3_bv0[c3_i5];
  }

  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "setSimStateSideEffectsInfo", c3_u, 34)), "setSimStateSideEffectsInfo"),
                true);
  sf_mex_destroy(&c3_u);
  chartInstance->c3_doSetSimStateSideEffects = 1U;
  c3_update_debugger_state_c3_homing_ldm_aggiornat(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void c3_set_sim_state_side_effects_c3_homing_ldm_aggiornat
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance)
{
  if (chartInstance->c3_doSetSimStateSideEffects != 0) {
    chartInstance->c3_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c3_homing_ldm_aggiornat
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c3_setSimStateSideEffectsInfo);
}

static void sf_gateway_c3_homing_ldm_aggiornat
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[2];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 0.0;
  c3_set_sim_state_side_effects_c3_homing_ldm_aggiornat(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, *chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_iy, 31U, 1U, 0U,
                        *chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ix, 30U, 1U, 0U,
                        *chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_g1y, 29U, 1U, 0U,
                        *chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_g2y, 28U, 1U, 0U,
                        *chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_g1x, 27U, 1U, 0U,
                        *chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_g2x, 26U, 1U, 0U,
                        *chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_clock, 25U, 1U, 0U,
                        *chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Pos_y, 24U, 1U, 0U,
                        *chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Pos_x, 23U, 1U, 0U,
                        *chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_fcy, 22U, 1U, 0U,
                        *chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Vel_y, 21U, 1U, 0U,
                        *chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Vel_x, 20U, 1U, 0U,
                        *chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_fcx, 19U, 1U, 0U,
                        *chartInstance->c3_sfEvent, false);
  *chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, *chartInstance->c3_sfEvent);
  if (*chartInstance->c3_is_active_c3_homing_ldm_aggiornat == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_active_c3_homing_ldm_aggiornat = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_c3_homing_ldm_aggiornat = c3_IN_Homing1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_Homing1 = c3_IN_Homing_x;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_e_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    *chartInstance->c3_v_sp_x = -2.1;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v_sp_x, 17U, 4U, 3U,
                          *chartInstance->c3_sfEvent, false);
    *chartInstance->c3_v_sp_y = 1.2;
    chartInstance->c3_dataWrittenToVector[7U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v_sp_y, 18U, 4U, 3U,
                          *chartInstance->c3_sfEvent, false);
    *chartInstance->c3_ok_x = 1.0;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_x, 33U, 4U, 3U,
                          *chartInstance->c3_sfEvent, false);
    *chartInstance->c3_ok_y = 1.0;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_y, 34U, 4U, 3U,
                          *chartInstance->c3_sfEvent, false);
    *chartInstance->c3_ok_x_2 = 0.0;
    chartInstance->c3_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_x_2, 36U, 4U, 3U,
                          *chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    switch (*chartInstance->c3_is_c3_homing_ldm_aggiornat) {
     case c3_IN_Homing1:
      CV_CHART_EVAL(0, 0, 1);
      c3_Homing1(chartInstance);
      break;

     case c3_IN_Pilotaggio:
      CV_CHART_EVAL(0, 0, 2);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                   *chartInstance->c3_sfEvent);
      switch (*chartInstance->c3_is_Pilotaggio) {
       case c3_IN_Fine:
        CV_STATE_EVAL(4, 0, 1);
        *chartInstance->c3_ok_x_2 = 0.0;
        chartInstance->c3_dataWrittenToVector[5U] = true;
        *chartInstance->c3_ok_y_2 = 0.0;
        chartInstance->c3_dataWrittenToVector[8U] = true;
        *chartInstance->c3_ok_x = 0.0;
        chartInstance->c3_dataWrittenToVector[1U] = true;
        *chartInstance->c3_ok_y = 0.0;
        chartInstance->c3_dataWrittenToVector[2U] = true;
        *chartInstance->c3_ok_y_3 = 0.0;
        chartInstance->c3_dataWrittenToVector[20U] = true;
        *chartInstance->c3_ok_x_3 = 0.0;
        chartInstance->c3_dataWrittenToVector[19U] = true;
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                     *chartInstance->c3_sfEvent);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, *chartInstance->c3_sfEvent);
        break;

       case c3_IN_Pilotaggio:
        CV_STATE_EVAL(4, 0, 2);
        c3_Pilotaggio(chartInstance);
        break;

       default:
        CV_STATE_EVAL(4, 0, 0);

        /* Unreachable state, for coverage only */
        *chartInstance->c3_is_Pilotaggio = c3_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c3_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, *chartInstance->c3_sfEvent);
      break;

     default:
      CV_CHART_EVAL(0, 0, 0);

      /* Unreachable state, for coverage only */
      *chartInstance->c3_is_c3_homing_ldm_aggiornat = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c3_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_homing_ldm_aggiornatMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c3_homing_ldm_aggiornat
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance)
{
  c3_init_sf_message_store_memory(chartInstance);
}

static void initSimStructsc3_homing_ldm_aggiornat
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_Pilotaggio(SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  real_T c3_hoistedGlobal;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_b_y;
  real_T c3_b_hoistedGlobal;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_g_x;
  real_T c3_c_y;
  real_T c3_c_hoistedGlobal;
  real_T c3_h_x;
  real_T c3_i_x;
  real_T c3_j_x;
  real_T c3_d_y;
  real_T c3_d_hoistedGlobal;
  real_T c3_k_x;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_l_x;
  real_T c3_b_nargin = 0.0;
  real_T c3_m_x;
  real_T c3_b_nargout = 0.0;
  real_T c3_e_y;
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  int32_T c3_i10;
  real_T c3_d0;
  real_T c3_d1;
  real_T c3_d2;
  real_T c3_d3;
  real_T c3_d4;
  real_T c3_d5;
  real_T c3_d6;
  real_T c3_d7;
  real_T c3_e_hoistedGlobal;
  const mxArray *c3_f_y = NULL;
  real_T c3_f_hoistedGlobal;
  const mxArray *c3_g_y = NULL;
  real_T c3_g_hoistedGlobal;
  const mxArray *c3_h_y = NULL;
  real_T c3_h_hoistedGlobal;
  const mxArray *c3_i_y = NULL;
  real_T c3_i_hoistedGlobal;
  real_T c3_j_hoistedGlobal;
  real_T c3_k_hoistedGlobal;
  real_T c3_l_hoistedGlobal;
  real_T c3_m_hoistedGlobal;
  real_T c3_A;
  real_T c3_n_x;
  real_T c3_o_x;
  real_T c3_n_hoistedGlobal;
  real_T c3_o_hoistedGlobal;
  real_T c3_p_hoistedGlobal;
  real_T c3_q_hoistedGlobal;
  real_T c3_r_hoistedGlobal;
  real_T c3_b_A;
  real_T c3_p_x;
  real_T c3_q_x;
  boolean_T guard1 = false;
  *chartInstance->c3_ok_y_3 = 1.0;
  chartInstance->c3_dataWrittenToVector[20U] = true;
  *chartInstance->c3_ok_x_3 = 1.0;
  chartInstance->c3_dataWrittenToVector[19U] = true;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, *chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_k_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  if (!chartInstance->c3_dataWrittenToVector[17U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(38U, 5U, 1U, *chartInstance->c3_sfEvent,
      false);
  }

  c3_hoistedGlobal = *chartInstance->c3_tensionex;
  c3_b_x = c3_hoistedGlobal;
  c3_c_x = c3_b_x;
  c3_d_x = c3_c_x;
  c3_b_y = muDoubleScalarAbs(c3_d_x);
  c3_b_hoistedGlobal = *chartInstance->c3_tensionex;
  c3_e_x = c3_b_hoistedGlobal;
  c3_f_x = c3_e_x;
  c3_g_x = c3_f_x;
  c3_c_y = muDoubleScalarAbs(c3_g_x);
  guard1 = false;
  if (CV_EML_COND(1, 0, 0, CV_RELATIONAL_EVAL(5U, 1U, 0, c3_b_y, 10.0, -1, 0U,
        c3_c_y == 10.0))) {
    guard1 = true;
  } else {
    if (!chartInstance->c3_dataWrittenToVector[18U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(39U, 5U, 1U, *chartInstance->c3_sfEvent,
        false);
    }

    c3_c_hoistedGlobal = *chartInstance->c3_tensioney;
    c3_h_x = c3_c_hoistedGlobal;
    c3_i_x = c3_h_x;
    c3_j_x = c3_i_x;
    c3_d_y = muDoubleScalarAbs(c3_j_x);
    c3_d_hoistedGlobal = *chartInstance->c3_tensioney;
    c3_k_x = c3_d_hoistedGlobal;
    c3_l_x = c3_k_x;
    c3_m_x = c3_l_x;
    c3_e_y = muDoubleScalarAbs(c3_m_x);
    if (CV_EML_COND(1, 0, 1, CV_RELATIONAL_EVAL(5U, 1U, 1, c3_d_y, 10.0, -1, 0U,
          c3_e_y == 10.0))) {
      guard1 = true;
    } else {
      CV_EML_MCDC(1, 0, 0, false);
      CV_EML_IF(1, 0, 0, false);
      c3_out = false;
    }
  }

  if (guard1) {
    CV_EML_MCDC(1, 0, 0, true);
    CV_EML_IF(1, 0, 0, true);
    c3_out = true;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, *chartInstance->c3_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_Pilotaggio = c3_IN_Fine;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    *chartInstance->c3_ok_y = 0.0;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_y, 34U, 4U, 5U,
                          *chartInstance->c3_sfEvent, false);
    *chartInstance->c3_ok_x = 0.0;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_x, 33U, 4U, 5U,
                          *chartInstance->c3_sfEvent, false);
    *chartInstance->c3_ok_y_2 = 0.0;
    chartInstance->c3_dataWrittenToVector[8U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_y_2, 37U, 4U, 5U,
                          *chartInstance->c3_sfEvent, false);
    *chartInstance->c3_ok_x_2 = 0.0;
    chartInstance->c3_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_x_2, 36U, 4U, 5U,
                          *chartInstance->c3_sfEvent, false);
    *chartInstance->c3_ok_y_3 = 0.0;
    chartInstance->c3_dataWrittenToVector[20U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_y_3, 41U, 4U, 5U,
                          *chartInstance->c3_sfEvent, false);
    *chartInstance->c3_ok_x_3 = 0.0;
    chartInstance->c3_dataWrittenToVector[19U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_x_3, 40U, 4U, 5U,
                          *chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U, *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_b_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[27U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 6U, *chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_t = *chartInstance->c3_clock - *chartInstance->c3_t1;
    chartInstance->c3_dataWrittenToVector[28U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_t, 0U, 4U, 6U,
                          *chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[27U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(1U, 4U, 6U, *chartInstance->c3_sfEvent,
        false);
    }

    if (CV_EML_IF(6, 1, 0, *chartInstance->c3_clock - *chartInstance->c3_t1 ==
                  0.0)) {
      *chartInstance->c3_rif_iniziale = *chartInstance->c3_t;
      chartInstance->c3_dataWrittenToVector[26U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_rif_iniziale, 12U, 4U, 6U,
                            *chartInstance->c3_sfEvent, false);
    } else {
      if (!chartInstance->c3_dataWrittenToVector[28U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 6U, *chartInstance->c3_sfEvent,
          false);
      }
    }

    if (!chartInstance->c3_dataWrittenToVector[28U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 6U, *chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[26U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(12U, 4U, 6U, *chartInstance->c3_sfEvent,
        false);
    }

    for (c3_i6 = 0; c3_i6 < 3320; c3_i6++) {
      chartInstance->c3_dv5[c3_i6] = chartInstance->c3_x[c3_i6];
    }

    for (c3_i7 = 0; c3_i7 < 3320; c3_i7++) {
      chartInstance->c3_dv6[c3_i7] = chartInstance->c3_Vel_asse_x[c3_i7];
    }

    for (c3_i8 = 0; c3_i8 < 3320; c3_i8++) {
      chartInstance->c3_dv7[c3_i8] = chartInstance->c3_y[c3_i8];
    }

    for (c3_i9 = 0; c3_i9 < 3320; c3_i9++) {
      chartInstance->c3_dv8[c3_i9] = chartInstance->c3_Vel_asse_y[c3_i9];
    }

    for (c3_i10 = 0; c3_i10 < 3320; c3_i10++) {
      chartInstance->c3_dv9[c3_i10] = chartInstance->c3_time[c3_i10];
    }

    c3_interpolazione_tempi2(chartInstance, chartInstance->c3_dv5,
      chartInstance->c3_dv6, chartInstance->c3_dv7, chartInstance->c3_dv8,
      *chartInstance->c3_t, chartInstance->c3_dv9,
      *chartInstance->c3_rif_iniziale, &c3_d0, &c3_d1, &c3_d2, &c3_d3);
    c3_d4 = c3_d0;
    c3_d5 = c3_d1;
    c3_d6 = c3_d2;
    c3_d7 = c3_d3;
    *chartInstance->c3_rifx = c3_d4;
    chartInstance->c3_dataWrittenToVector[21U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_rifx, 13U, 4U, 6U,
                          *chartInstance->c3_sfEvent, false);
    *chartInstance->c3_rifxp = c3_d5;
    chartInstance->c3_dataWrittenToVector[22U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_rifxp, 14U, 4U, 6U,
                          *chartInstance->c3_sfEvent, false);
    *chartInstance->c3_rify = c3_d6;
    chartInstance->c3_dataWrittenToVector[23U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_rify, 15U, 4U, 6U,
                          *chartInstance->c3_sfEvent, false);
    *chartInstance->c3_rifyp = c3_d7;
    chartInstance->c3_dataWrittenToVector[24U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_rifyp, 16U, 4U, 6U,
                          *chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[21U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(13U, 4U, 6U, *chartInstance->c3_sfEvent,
        false);
    }

    sf_mex_printf("%s =\\n", "rifx");
    c3_e_hoistedGlobal = *chartInstance->c3_rifx;
    c3_f_y = NULL;
    sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_hoistedGlobal, 0, 0U, 0U, 0U,
      0), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_f_y);
    if (!chartInstance->c3_dataWrittenToVector[22U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(14U, 4U, 6U, *chartInstance->c3_sfEvent,
        false);
    }

    sf_mex_printf("%s =\\n", "rifxp");
    c3_f_hoistedGlobal = *chartInstance->c3_rifxp;
    c3_g_y = NULL;
    sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_f_hoistedGlobal, 0, 0U, 0U, 0U,
      0), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_g_y);
    if (!chartInstance->c3_dataWrittenToVector[23U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(15U, 4U, 6U, *chartInstance->c3_sfEvent,
        false);
    }

    sf_mex_printf("%s =\\n", "rify");
    c3_g_hoistedGlobal = *chartInstance->c3_rify;
    c3_h_y = NULL;
    sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_g_hoistedGlobal, 0, 0U, 0U, 0U,
      0), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_h_y);
    if (!chartInstance->c3_dataWrittenToVector[24U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(16U, 4U, 6U, *chartInstance->c3_sfEvent,
        false);
    }

    sf_mex_printf("%s =\\n", "rifyp");
    c3_h_hoistedGlobal = *chartInstance->c3_rifyp;
    c3_i_y = NULL;
    sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_h_hoistedGlobal, 0, 0U, 0U, 0U,
      0), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_i_y);
    if (!chartInstance->c3_dataWrittenToVector[21U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(13U, 4U, 6U, *chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_deltax = *chartInstance->c3_Pos_x -
      *chartInstance->c3_rifx;
    chartInstance->c3_dataWrittenToVector[15U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_deltax, 5U, 4U, 6U,
                          *chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[23U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(15U, 4U, 6U, *chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_deltay = *chartInstance->c3_Pos_y -
      *chartInstance->c3_rify;
    chartInstance->c3_dataWrittenToVector[16U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_deltay, 7U, 4U, 6U,
                          *chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[22U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(14U, 4U, 6U, *chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_deltaxp = *chartInstance->c3_Vel_x -
      *chartInstance->c3_rifxp;
    chartInstance->c3_dataWrittenToVector[13U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_deltaxp, 6U, 4U, 6U,
                          *chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[24U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(16U, 4U, 6U, *chartInstance->c3_sfEvent,
        false);
    }

    *chartInstance->c3_deltayp = *chartInstance->c3_Vel_y -
      *chartInstance->c3_rifyp;
    chartInstance->c3_dataWrittenToVector[14U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_deltayp, 8U, 4U, 6U,
                          *chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[13U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 4U, 6U, *chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[15U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 4U, 6U, *chartInstance->c3_sfEvent,
        false);
    }

    c3_i_hoistedGlobal = *chartInstance->c3_ix;
    c3_j_hoistedGlobal = *chartInstance->c3_deltaxp;
    c3_k_hoistedGlobal = *chartInstance->c3_g2x;
    c3_l_hoistedGlobal = *chartInstance->c3_deltax;
    c3_m_hoistedGlobal = *chartInstance->c3_g1x;
    c3_A = c3_i_hoistedGlobal * (-c3_j_hoistedGlobal * c3_k_hoistedGlobal -
      c3_l_hoistedGlobal * c3_m_hoistedGlobal);
    c3_n_x = c3_A;
    c3_o_x = c3_n_x;
    *chartInstance->c3_tensionex = c3_o_x / 30.0;
    chartInstance->c3_dataWrittenToVector[17U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_tensionex, 38U, 4U, 6U,
                          *chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[14U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 6U, *chartInstance->c3_sfEvent,
        false);
    }

    if (!chartInstance->c3_dataWrittenToVector[16U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 6U, *chartInstance->c3_sfEvent,
        false);
    }

    c3_n_hoistedGlobal = *chartInstance->c3_iy;
    c3_o_hoistedGlobal = *chartInstance->c3_deltayp;
    c3_p_hoistedGlobal = *chartInstance->c3_g2y;
    c3_q_hoistedGlobal = *chartInstance->c3_deltay;
    c3_r_hoistedGlobal = *chartInstance->c3_g1y;
    c3_b_A = c3_n_hoistedGlobal * (-c3_o_hoistedGlobal * c3_p_hoistedGlobal -
      c3_q_hoistedGlobal * c3_r_hoistedGlobal);
    c3_p_x = c3_b_A;
    c3_q_x = c3_p_x;
    *chartInstance->c3_tensioney = c3_q_x / 50.0;
    chartInstance->c3_dataWrittenToVector[18U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_tensioney, 39U, 4U, 6U,
                          *chartInstance->c3_sfEvent, false);
    if (!chartInstance->c3_dataWrittenToVector[18U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(39U, 4U, 6U, *chartInstance->c3_sfEvent,
        false);
    }

    if (CV_EML_IF(6, 1, 1, *chartInstance->c3_tensioney > 1.4)) {
      *chartInstance->c3_tensioney = 1.4;
      chartInstance->c3_dataWrittenToVector[18U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_tensioney, 39U, 4U, 6U,
                            *chartInstance->c3_sfEvent, false);
    }

    if (!chartInstance->c3_dataWrittenToVector[18U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(39U, 4U, 6U, *chartInstance->c3_sfEvent,
        false);
    }

    if (CV_EML_IF(6, 1, 2, *chartInstance->c3_tensioney < -1.4)) {
      *chartInstance->c3_tensioney = -1.4;
      chartInstance->c3_dataWrittenToVector[18U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_tensioney, 39U, 4U, 6U,
                            *chartInstance->c3_sfEvent, false);
    }

    if (!chartInstance->c3_dataWrittenToVector[17U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(38U, 4U, 6U, *chartInstance->c3_sfEvent,
        false);
    }

    if (CV_EML_IF(6, 1, 3, *chartInstance->c3_tensionex > 2.2)) {
      *chartInstance->c3_tensionex = 2.2;
      chartInstance->c3_dataWrittenToVector[17U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_tensionex, 38U, 4U, 6U,
                            *chartInstance->c3_sfEvent, false);
    }

    if (!chartInstance->c3_dataWrittenToVector[17U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(38U, 4U, 6U, *chartInstance->c3_sfEvent,
        false);
    }

    if (CV_EML_IF(6, 1, 4, *chartInstance->c3_tensionex < -2.2)) {
      *chartInstance->c3_tensionex = -2.2;
      chartInstance->c3_dataWrittenToVector[17U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_tensionex, 38U, 4U, 6U,
                            *chartInstance->c3_sfEvent, false);
    }

    _SFD_SYMBOL_SCOPE_POP();
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, *chartInstance->c3_sfEvent);
}

static void c3_Homing1(SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  boolean_T c3_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_b_nargin = 0.0;
  real_T c3_c_nargin = 0.0;
  real_T c3_b_nargout = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_d_nargout = 1.0;
  real_T c3_e_nargin = 0.0;
  boolean_T c3_b_out;
  real_T c3_e_nargout = 1.0;
  boolean_T c3_c_out;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 0.0;
  real_T c3_g_nargin = 0.0;
  real_T c3_h_nargin = 0.0;
  real_T c3_g_nargout = 0.0;
  real_T c3_h_nargout = 0.0;
  real_T c3_i_nargin = 0.0;
  real_T c3_i_nargout = 0.0;
  real_T c3_hoistedGlobal;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d_x;
  boolean_T guard1 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U, *chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_n_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  if (!chartInstance->c3_dataWrittenToVector[12U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(11U, 5U, 6U, *chartInstance->c3_sfEvent,
      false);
  }

  c3_out = CV_EML_IF(6, 0, 0, *chartInstance->c3_inizio_traiettoria == 1.0);
  _SFD_SYMBOL_SCOPE_POP();
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, *chartInstance->c3_sfEvent);
    c3_exit_internal_Homing1(chartInstance);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_c3_homing_ldm_aggiornat = c3_IN_Pilotaggio;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_Pilotaggio = c3_IN_Pilotaggio;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    *chartInstance->c3_t1 = *chartInstance->c3_clock;
    chartInstance->c3_dataWrittenToVector[27U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_t1, 1U, 4U, 6U,
                          *chartInstance->c3_sfEvent, false);
    *chartInstance->c3_ok_y_3 = 1.0;
    chartInstance->c3_dataWrittenToVector[20U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_y_3, 41U, 4U, 6U,
                          *chartInstance->c3_sfEvent, false);
    *chartInstance->c3_ok_x_3 = 1.0;
    chartInstance->c3_dataWrittenToVector[19U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_x_3, 40U, 4U, 6U,
                          *chartInstance->c3_sfEvent, false);
    *chartInstance->c3_deltax = 0.0;
    chartInstance->c3_dataWrittenToVector[15U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_deltax, 5U, 4U, 6U,
                          *chartInstance->c3_sfEvent, false);
    *chartInstance->c3_deltay = 0.0;
    chartInstance->c3_dataWrittenToVector[16U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_deltay, 7U, 4U, 6U,
                          *chartInstance->c3_sfEvent, false);
    *chartInstance->c3_deltaxp = 0.0;
    chartInstance->c3_dataWrittenToVector[13U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_deltaxp, 6U, 4U, 6U,
                          *chartInstance->c3_sfEvent, false);
    *chartInstance->c3_deltayp = 0.0;
    chartInstance->c3_dataWrittenToVector[14U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_deltayp, 8U, 4U, 6U,
                          *chartInstance->c3_sfEvent, false);
    *chartInstance->c3_appoggio = 1.0;
    chartInstance->c3_dataWrittenToVector[25U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_appoggio, 2U, 4U, 6U,
                          *chartInstance->c3_sfEvent, false);
    *chartInstance->c3_rif_iniziale = 0.0;
    chartInstance->c3_dataWrittenToVector[26U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_rif_iniziale, 12U, 4U, 6U,
                          *chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, *chartInstance->c3_sfEvent);
    switch (*chartInstance->c3_is_Homing1) {
     case c3_IN_Fine:
      CV_STATE_EVAL(0, 0, 1);
      *chartInstance->c3_ok_x_2 = 0.0;
      chartInstance->c3_dataWrittenToVector[5U] = true;
      *chartInstance->c3_ok_y_2 = 0.0;
      chartInstance->c3_dataWrittenToVector[8U] = true;
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_j_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      *chartInstance->c3_inizio_traiettoria = 1.0;
      chartInstance->c3_dataWrittenToVector[12U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_inizio_traiettoria, 11U, 4U, 1U, *
                            chartInstance->c3_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *chartInstance->c3_sfEvent);
      break;

     case c3_IN_Fine_homing1:
      CV_STATE_EVAL(0, 0, 2);
      *chartInstance->c3_ok_x_2 = 1.0;
      chartInstance->c3_dataWrittenToVector[5U] = true;
      *chartInstance->c3_ok_y_2 = 1.0;
      chartInstance->c3_dataWrittenToVector[8U] = true;
      *chartInstance->c3_ok_x = 0.0;
      chartInstance->c3_dataWrittenToVector[1U] = true;
      *chartInstance->c3_ok_y = 0.0;
      chartInstance->c3_dataWrittenToVector[2U] = true;
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_m_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_c_sf_marshallOut,
        c3_c_sf_marshallIn);
      if (!chartInstance->c3_dataWrittenToVector[4U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 5U, 3U, *chartInstance->c3_sfEvent,
          false);
      }

      guard1 = false;
      if (CV_EML_COND(3, 0, 0, CV_RELATIONAL_EVAL(5U, 3U, 0,
            *chartInstance->c3_dx, 0.6, -1, 4U, *chartInstance->c3_dx > 0.6))) {
        if (CV_EML_COND(3, 0, 1, CV_RELATIONAL_EVAL(5U, 3U, 1,
              *chartInstance->c3_dy, 0.4, -1, 4U, *chartInstance->c3_dy > 0.4)))
        {
          CV_EML_MCDC(3, 0, 0, true);
          CV_EML_IF(3, 0, 0, true);
          c3_c_out = true;
        } else {
          guard1 = true;
        }
      } else {
        if (!chartInstance->c3_dataWrittenToVector[9U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 5U, 3U,
            *chartInstance->c3_sfEvent, false);
        }

        guard1 = true;
      }

      if (guard1) {
        CV_EML_MCDC(3, 0, 0, false);
        CV_EML_IF(3, 0, 0, false);
        c3_c_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, *chartInstance->c3_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_Homing1 = c3_IN_Fine;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_i_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        *chartInstance->c3_ok_y_2 = 0.0;
        chartInstance->c3_dataWrittenToVector[8U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_y_2, 37U, 4U, 1U,
                              *chartInstance->c3_sfEvent, false);
        *chartInstance->c3_ok_x_2 = 0.0;
        chartInstance->c3_dataWrittenToVector[5U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_x_2, 36U, 4U, 1U,
                              *chartInstance->c3_sfEvent, false);
        *chartInstance->c3_inizio_traiettoria = 0.0;
        chartInstance->c3_dataWrittenToVector[12U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_inizio_traiettoria, 11U, 4U, 1U,
                              *chartInstance->c3_sfEvent, false);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     *chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_h_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[6U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(17U, 4U, 2U,
            *chartInstance->c3_sfEvent, false);
        }

        *chartInstance->c3_Vel_x_out = *chartInstance->c3_v_sp_x -
          *chartInstance->c3_Vel_x;
        chartInstance->c3_dataWrittenToVector[0U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Vel_x_out, 32U, 4U, 2U,
                              *chartInstance->c3_sfEvent, false);
        if (!chartInstance->c3_dataWrittenToVector[10U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 2U,
            *chartInstance->c3_sfEvent, false);
        }

        *chartInstance->c3_dx = *chartInstance->c3_Pos_x - *chartInstance->c3_bx;
        chartInstance->c3_dataWrittenToVector[4U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dx, 9U, 4U, 2U,
                              *chartInstance->c3_sfEvent, false);
        if (!chartInstance->c3_dataWrittenToVector[4U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U,
            *chartInstance->c3_sfEvent, false);
        }

        sf_mex_printf("%s =\\n", "dx");
        c3_hoistedGlobal = *chartInstance->c3_dx;
        c3_b_y = NULL;
        sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_hoistedGlobal, 0, 0U, 0U,
          0U, 0), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c3_b_y);
        if (!chartInstance->c3_dataWrittenToVector[4U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(9U, 4U, 2U,
            *chartInstance->c3_sfEvent, false);
        }

        if (CV_EML_IF(2, 1, 0, *chartInstance->c3_dx > 0.6)) {
          *chartInstance->c3_Vel_x_out = 0.0;
          chartInstance->c3_dataWrittenToVector[0U] = true;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Vel_x_out, 32U, 4U, 2U,
                                *chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[7U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(18U, 4U, 2U,
            *chartInstance->c3_sfEvent, false);
        }

        *chartInstance->c3_Vel_y_out = *chartInstance->c3_v_sp_y -
          *chartInstance->c3_Vel_y;
        chartInstance->c3_dataWrittenToVector[3U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Vel_y_out, 35U, 4U, 2U,
                              *chartInstance->c3_sfEvent, false);
        if (!chartInstance->c3_dataWrittenToVector[11U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 2U,
            *chartInstance->c3_sfEvent, false);
        }

        c3_b_hoistedGlobal = *chartInstance->c3_Pos_y;
        c3_c_hoistedGlobal = *chartInstance->c3_by;
        c3_b_x = c3_b_hoistedGlobal - c3_c_hoistedGlobal;
        c3_c_x = c3_b_x;
        c3_d_x = c3_c_x;
        *chartInstance->c3_dy = muDoubleScalarAbs(c3_d_x);
        chartInstance->c3_dataWrittenToVector[9U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dy, 10U, 4U, 2U,
                              *chartInstance->c3_sfEvent, false);
        if (!chartInstance->c3_dataWrittenToVector[9U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(10U, 4U, 2U,
            *chartInstance->c3_sfEvent, false);
        }

        if (CV_EML_IF(2, 1, 1, *chartInstance->c3_dy > 0.4)) {
          *chartInstance->c3_Vel_y_out = 0.0;
          chartInstance->c3_dataWrittenToVector[3U] = true;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Vel_y_out, 35U, 4U, 2U,
                                *chartInstance->c3_sfEvent, false);
        }

        _SFD_SYMBOL_SCOPE_POP();
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, *chartInstance->c3_sfEvent);
      break;

     case c3_IN_Homing_x:
      CV_STATE_EVAL(0, 0, 3);
      *chartInstance->c3_ok_x_2 = 0.0;
      chartInstance->c3_dataWrittenToVector[5U] = true;
      *chartInstance->c3_ok_x = 1.0;
      chartInstance->c3_dataWrittenToVector[1U] = true;
      *chartInstance->c3_ok_y = 1.0;
      chartInstance->c3_dataWrittenToVector[2U] = true;
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                   *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_l_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_c_sf_marshallOut,
        c3_c_sf_marshallIn);
      if (CV_EML_COND(4, 0, 0, CV_RELATIONAL_EVAL(5U, 4U, 0,
            *chartInstance->c3_fcx, 0.0, -1, 0U, *chartInstance->c3_fcx == 0.0))
          && CV_EML_COND(4, 0, 1, CV_RELATIONAL_EVAL(5U, 4U, 1,
            *chartInstance->c3_fcy, 0.0, -1, 0U, *chartInstance->c3_fcy == 0.0)))
      {
        CV_EML_MCDC(4, 0, 0, true);
        CV_EML_IF(4, 0, 0, true);
        c3_b_out = true;
      } else {
        CV_EML_MCDC(4, 0, 0, false);
        CV_EML_IF(4, 0, 0, false);
        c3_b_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, *chartInstance->c3_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_Homing1 = c3_IN_Fine_homing1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_g_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        *chartInstance->c3_ok_y = 0.0;
        chartInstance->c3_dataWrittenToVector[2U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_y, 34U, 4U, 2U,
                              *chartInstance->c3_sfEvent, false);
        *chartInstance->c3_ok_x = 0.0;
        chartInstance->c3_dataWrittenToVector[1U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_x, 33U, 4U, 2U,
                              *chartInstance->c3_sfEvent, false);
        *chartInstance->c3_bx = *chartInstance->c3_Pos_x;
        chartInstance->c3_dataWrittenToVector[10U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_bx, 3U, 4U, 2U,
                              *chartInstance->c3_sfEvent, false);
        *chartInstance->c3_by = *chartInstance->c3_Pos_y;
        chartInstance->c3_dataWrittenToVector[11U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_by, 4U, 4U, 2U,
                              *chartInstance->c3_sfEvent, false);
        *chartInstance->c3_v_sp_x = 2.1;
        chartInstance->c3_dataWrittenToVector[6U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v_sp_x, 17U, 4U, 2U,
                              *chartInstance->c3_sfEvent, false);
        *chartInstance->c3_v_sp_y = -1.2;
        chartInstance->c3_dataWrittenToVector[7U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v_sp_y, 18U, 4U, 2U,
                              *chartInstance->c3_sfEvent, false);
        *chartInstance->c3_ok_x_2 = 1.0;
        chartInstance->c3_dataWrittenToVector[5U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_x_2, 36U, 4U, 2U,
                              *chartInstance->c3_sfEvent, false);
        *chartInstance->c3_ok_y_2 = 1.0;
        chartInstance->c3_dataWrittenToVector[8U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_y_2, 37U, 4U, 2U,
                              *chartInstance->c3_sfEvent, false);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                     *chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_f_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[6U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(17U, 4U, 3U,
            *chartInstance->c3_sfEvent, false);
        }

        *chartInstance->c3_Vel_x_out = *chartInstance->c3_v_sp_x -
          *chartInstance->c3_Vel_x;
        chartInstance->c3_dataWrittenToVector[0U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Vel_x_out, 32U, 4U, 3U,
                              *chartInstance->c3_sfEvent, false);
        if (!chartInstance->c3_dataWrittenToVector[7U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(18U, 4U, 3U,
            *chartInstance->c3_sfEvent, false);
        }

        *chartInstance->c3_Vel_y_out = *chartInstance->c3_v_sp_y -
          *chartInstance->c3_Vel_y;
        chartInstance->c3_dataWrittenToVector[3U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Vel_y_out, 35U, 4U, 3U,
                              *chartInstance->c3_sfEvent, false);
        _SFD_SYMBOL_SCOPE_POP();
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, *chartInstance->c3_sfEvent);
      break;

     default:
      CV_STATE_EVAL(0, 0, 0);

      /* Unreachable state, for coverage only */
      *chartInstance->c3_is_Homing1 = c3_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c3_sfEvent);
      break;
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *chartInstance->c3_sfEvent);
}

static void c3_exit_internal_Homing1(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance)
{
  switch (*chartInstance->c3_is_Homing1) {
   case c3_IN_Fine:
    CV_STATE_EVAL(0, 1, 1);
    *chartInstance->c3_is_Homing1 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Fine_homing1:
    CV_STATE_EVAL(0, 1, 2);
    *chartInstance->c3_is_Homing1 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Homing_x:
    CV_STATE_EVAL(0, 1, 3);
    *chartInstance->c3_is_Homing1 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(0, 1, 0);
    *chartInstance->c3_is_Homing1 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c3_sfEvent);
    break;
  }
}

static real_T c3_interp1(SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance,
  real_T c3_varargin_1[3320], real_T c3_varargin_2[3320], real_T c3_varargin_3,
  real_T c3_varargin_5)
{
  real_T c3_Vq;
  real_T c3_exin;
  real_T c3_exout;
  real_T c3_b_exin;
  int32_T c3_i11;
  real_T c3_xi;
  real_T c3_b_y[3320];
  int32_T c3_i12;
  real_T c3_extrapval;
  real_T c3_b_x[3320];
  int32_T c3_k;
  real_T c3_c_x;
  int32_T c3_j1;
  boolean_T c3_b;
  int32_T c3_b_k;
  int32_T c3_b_j1;
  real_T c3_xtmp;
  real_T c3_b_xi;
  real_T c3_yi;
  int32_T c3_j2;
  real_T c3_minx;
  real_T c3_b_xtmp;
  real_T c3_maxx;
  real_T c3_c_xi;
  real_T c3_b_minx;
  real_T c3_b_maxx;
  real_T c3_d_x;
  boolean_T c3_b_b;
  real_T c3_d_xi;
  int32_T c3_low_i;
  int32_T c3_low_ip1;
  int32_T c3_high_i;
  int32_T c3_n;
  int32_T c3_b_low_i;
  real_T c3_xn;
  int32_T c3_b_high_i;
  real_T c3_xnp1;
  int32_T c3_mid_i;
  real_T c3_A;
  real_T c3_B;
  real_T c3_e_x;
  real_T c3_c_y;
  real_T c3_f_x;
  real_T c3_d_y;
  real_T c3_r;
  real_T c3_onemr;
  real_T c3_y1;
  real_T c3_y2;
  int32_T exitg1;
  c3_exin = c3_varargin_5;
  c3_exout = c3_exin;
  c3_b_exin = c3_exout;
  for (c3_i11 = 0; c3_i11 < 3320; c3_i11++) {
    c3_b_y[c3_i11] = c3_varargin_2[c3_i11];
  }

  c3_xi = c3_varargin_3;
  for (c3_i12 = 0; c3_i12 < 3320; c3_i12++) {
    c3_b_x[c3_i12] = c3_varargin_1[c3_i12];
  }

  c3_extrapval = c3_b_exin;
  c3_k = 0;
  do {
    exitg1 = 0;
    if (c3_k + 1 < 3321) {
      c3_c_x = c3_b_x[c3_k];
      c3_b = muDoubleScalarIsNaN(c3_c_x);
      if (c3_b) {
        c3_error(chartInstance);
        exitg1 = 1;
      } else {
        c3_k++;
      }
    } else {
      if (c3_b_x[1] < c3_b_x[0]) {
        for (c3_j1 = 1; c3_j1 < 1661; c3_j1++) {
          c3_xtmp = c3_b_x[c3_j1 - 1];
          c3_b_x[c3_j1 - 1] = c3_b_x[3320 - c3_j1];
          c3_b_x[3320 - c3_j1] = c3_xtmp;
        }

        for (c3_b_j1 = 0; c3_b_j1 + 1 < 1661; c3_b_j1++) {
          c3_j2 = 3319 - c3_b_j1;
          c3_b_xtmp = c3_b_y[c3_b_j1];
          c3_b_y[c3_b_j1] = c3_b_y[c3_j2];
          c3_b_y[c3_j2] = c3_b_xtmp;
        }
      }

      for (c3_b_k = 0; c3_b_k + 2 < 3321; c3_b_k++) {
        if (c3_b_x[c3_b_k + 1] <= c3_b_x[c3_b_k]) {
          c3_b_error(chartInstance);
        }
      }

      c3_b_xi = c3_xi;
      c3_yi = c3_extrapval;
      c3_Vq = c3_yi;
      c3_minx = c3_b_x[0];
      c3_maxx = c3_b_x[3319];
      c3_c_xi = c3_b_xi;
      c3_b_minx = c3_minx;
      c3_b_maxx = c3_maxx;
      c3_d_x = c3_c_xi;
      c3_b_b = muDoubleScalarIsNaN(c3_d_x);
      if (c3_b_b) {
        c3_Vq = rtNaN;
      } else if ((c3_c_xi > c3_b_maxx) || (c3_c_xi < c3_b_minx)) {
      } else {
        c3_d_xi = c3_c_xi;
        c3_low_i = 1;
        c3_low_ip1 = 1;
        c3_high_i = 3320;
        while (c3_high_i > c3_low_ip1 + 1) {
          c3_b_low_i = c3_low_i;
          c3_b_high_i = c3_high_i;
          c3_mid_i = (c3_b_low_i + c3_b_high_i) >> 1;
          if (c3_d_xi >= c3_b_x[c3_mid_i - 1]) {
            c3_low_i = c3_mid_i;
            c3_low_ip1 = c3_mid_i;
          } else {
            c3_high_i = c3_mid_i;
          }
        }

        c3_n = c3_low_i;
        c3_xn = c3_b_x[c3_n - 1];
        c3_xnp1 = c3_b_x[c3_n];
        c3_A = c3_c_xi - c3_xn;
        c3_B = c3_xnp1 - c3_xn;
        c3_e_x = c3_A;
        c3_c_y = c3_B;
        c3_f_x = c3_e_x;
        c3_d_y = c3_c_y;
        c3_r = c3_f_x / c3_d_y;
        c3_onemr = 1.0 - c3_r;
        if (c3_r == 0.0) {
          c3_y1 = c3_b_y[c3_n - 1];
          c3_Vq = c3_y1;
        } else if (c3_r == 1.0) {
          c3_y2 = c3_b_y[c3_n];
          c3_Vq = c3_y2;
        } else {
          c3_y1 = c3_b_y[c3_n - 1];
          c3_y2 = c3_b_y[c3_n];
          if (c3_y1 == c3_y2) {
            c3_Vq = c3_y1;
          } else {
            c3_Vq = c3_onemr * c3_y1 + c3_r * c3_y2;
          }
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c3_Vq;
}

static void c3_error(SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance)
{
  const mxArray *c3_b_y = NULL;
  static char_T c3_cv0[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'n', 't',
    'e', 'r', 'p', '1', ':', 'N', 'a', 'N', 'i', 'n', 'X' };

  (void)chartInstance;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv0, 10, 0U, 1U, 0U, 2, 1, 21),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c3_b_y));
}

static void c3_b_error(SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance)
{
  const mxArray *c3_b_y = NULL;
  static char_T c3_cv1[35] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', 'e', 'r', 'p', '1', '_', 'n', 'o', 'n',
    'M', 'o', 'n', 'o', 't', 'o', 'n', 'i', 'c', 'X' };

  (void)chartInstance;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_cv1, 10, 0U, 1U, 0U, 2, 1, 35),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c3_b_y));
}

static real_T c3_b_interp1(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, real_T c3_varargin_1[3320], real_T c3_varargin_2[3320], real_T
  c3_varargin_3)
{
  real_T c3_Vq;
  int32_T c3_i13;
  real_T c3_xi;
  real_T c3_b_y[3320];
  int32_T c3_i14;
  int32_T c3_k;
  real_T c3_b_x[3320];
  real_T c3_c_x;
  int32_T c3_j1;
  boolean_T c3_b;
  int32_T c3_b_k;
  int32_T c3_b_j1;
  real_T c3_xtmp;
  real_T c3_b_xi;
  real_T c3_minx;
  int32_T c3_j2;
  real_T c3_maxx;
  real_T c3_b_xtmp;
  real_T c3_c_xi;
  real_T c3_b_minx;
  real_T c3_b_maxx;
  real_T c3_d_x;
  boolean_T c3_b_b;
  real_T c3_d_xi;
  int32_T c3_low_i;
  int32_T c3_low_ip1;
  int32_T c3_high_i;
  int32_T c3_n;
  int32_T c3_b_low_i;
  real_T c3_xn;
  int32_T c3_b_high_i;
  real_T c3_xnp1;
  int32_T c3_mid_i;
  real_T c3_A;
  real_T c3_B;
  real_T c3_e_x;
  real_T c3_c_y;
  real_T c3_f_x;
  real_T c3_d_y;
  real_T c3_r;
  real_T c3_onemr;
  real_T c3_y1;
  real_T c3_y2;
  int32_T exitg1;
  for (c3_i13 = 0; c3_i13 < 3320; c3_i13++) {
    c3_b_y[c3_i13] = c3_varargin_2[c3_i13];
  }

  c3_xi = c3_varargin_3;
  for (c3_i14 = 0; c3_i14 < 3320; c3_i14++) {
    c3_b_x[c3_i14] = c3_varargin_1[c3_i14];
  }

  c3_k = 0;
  do {
    exitg1 = 0;
    if (c3_k + 1 < 3321) {
      c3_c_x = c3_b_x[c3_k];
      c3_b = muDoubleScalarIsNaN(c3_c_x);
      if (c3_b) {
        c3_error(chartInstance);
        exitg1 = 1;
      } else {
        c3_k++;
      }
    } else {
      if (c3_b_x[1] < c3_b_x[0]) {
        for (c3_j1 = 1; c3_j1 < 1661; c3_j1++) {
          c3_xtmp = c3_b_x[c3_j1 - 1];
          c3_b_x[c3_j1 - 1] = c3_b_x[3320 - c3_j1];
          c3_b_x[3320 - c3_j1] = c3_xtmp;
        }

        for (c3_b_j1 = 0; c3_b_j1 + 1 < 1661; c3_b_j1++) {
          c3_j2 = 3319 - c3_b_j1;
          c3_b_xtmp = c3_b_y[c3_b_j1];
          c3_b_y[c3_b_j1] = c3_b_y[c3_j2];
          c3_b_y[c3_j2] = c3_b_xtmp;
        }
      }

      for (c3_b_k = 0; c3_b_k + 2 < 3321; c3_b_k++) {
        if (c3_b_x[c3_b_k + 1] <= c3_b_x[c3_b_k]) {
          c3_b_error(chartInstance);
        }
      }

      c3_b_xi = c3_xi;
      c3_Vq = 0.0;
      c3_minx = c3_b_x[0];
      c3_maxx = c3_b_x[3319];
      c3_c_xi = c3_b_xi;
      c3_b_minx = c3_minx;
      c3_b_maxx = c3_maxx;
      c3_d_x = c3_c_xi;
      c3_b_b = muDoubleScalarIsNaN(c3_d_x);
      if (c3_b_b) {
        c3_Vq = rtNaN;
      } else if ((c3_c_xi > c3_b_maxx) || (c3_c_xi < c3_b_minx)) {
      } else {
        c3_d_xi = c3_c_xi;
        c3_low_i = 1;
        c3_low_ip1 = 1;
        c3_high_i = 3320;
        while (c3_high_i > c3_low_ip1 + 1) {
          c3_b_low_i = c3_low_i;
          c3_b_high_i = c3_high_i;
          c3_mid_i = (c3_b_low_i + c3_b_high_i) >> 1;
          if (c3_d_xi >= c3_b_x[c3_mid_i - 1]) {
            c3_low_i = c3_mid_i;
            c3_low_ip1 = c3_mid_i;
          } else {
            c3_high_i = c3_mid_i;
          }
        }

        c3_n = c3_low_i;
        c3_xn = c3_b_x[c3_n - 1];
        c3_xnp1 = c3_b_x[c3_n];
        c3_A = c3_c_xi - c3_xn;
        c3_B = c3_xnp1 - c3_xn;
        c3_e_x = c3_A;
        c3_c_y = c3_B;
        c3_f_x = c3_e_x;
        c3_d_y = c3_c_y;
        c3_r = c3_f_x / c3_d_y;
        c3_onemr = 1.0 - c3_r;
        if (c3_r == 0.0) {
          c3_y1 = c3_b_y[c3_n - 1];
          c3_Vq = c3_y1;
        } else if (c3_r == 1.0) {
          c3_y2 = c3_b_y[c3_n];
          c3_Vq = c3_y2;
        } else {
          c3_y1 = c3_b_y[c3_n - 1];
          c3_y2 = c3_b_y[c3_n];
          if (c3_y1 == c3_y2) {
            c3_Vq = c3_y1;
          } else {
            c3_Vq = c3_onemr * c3_y1 + c3_r * c3_y2;
          }
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c3_Vq;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)(c3_machineNumber);
  (void)(c3_chartNumber);
  (void)(c3_instanceNumber);
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance;
  chartInstance = (SFc3_homing_ldm_aggiornatInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_nargout, const char_T *c3_identifier)
{
  real_T c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout),
    &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  return c3_b_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_b_y;
  real_T c3_d8;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d8, 1, 0, 0U, 0, 0U, 0);
  c3_b_y = c3_d8;
  sf_mex_destroy(&c3_u);
  return c3_b_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_b_y;
  SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance;
  chartInstance = (SFc3_homing_ldm_aggiornatInstanceStruct *)chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout),
    &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_b_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_i15;
  const mxArray *c3_b_y = NULL;
  real_T c3_u[3320];
  SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance;
  chartInstance = (SFc3_homing_ldm_aggiornatInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  for (c3_i15 = 0; c3_i15 < 3320; c3_i15++) {
    c3_u[c3_i15] = (*(real_T (*)[3320])c3_inData)[c3_i15];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 1, 3320),
                false);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static void c3_c_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_b_y[3320])
{
  real_T c3_dv10[3320];
  int32_T c3_i16;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv10, 1, 0, 0U, 1, 0U, 2, 1,
                3320);
  for (c3_i16 = 0; c3_i16 < 3320; c3_i16++) {
    c3_b_y[c3_i16] = c3_dv10[c3_i16];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_c_t_m;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_b_y[3320];
  int32_T c3_i17;
  SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance;
  chartInstance = (SFc3_homing_ldm_aggiornatInstanceStruct *)chartInstanceVoid;
  c3_c_t_m = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_c_t_m), &c3_thisId, c3_b_y);
  sf_mex_destroy(&c3_c_t_m);
  for (c3_i17 = 0; c3_i17 < 3320; c3_i17++) {
    (*(real_T (*)[3320])c3_outData)[c3_i17] = c3_b_y[c3_i17];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  boolean_T c3_u;
  const mxArray *c3_b_y = NULL;
  SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance;
  chartInstance = (SFc3_homing_ldm_aggiornatInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static boolean_T c3_d_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_b_y;
  boolean_T c3_b0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b0, 1, 11, 0U, 0, 0U, 0);
  c3_b_y = c3_b0;
  sf_mex_destroy(&c3_u);
  return c3_b_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sf_internal_predicateOutput;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_b_y;
  SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance;
  chartInstance = (SFc3_homing_ldm_aggiornatInstanceStruct *)chartInstanceVoid;
  c3_sf_internal_predicateOutput = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_sf_internal_predicateOutput), &c3_thisId);
  sf_mex_destroy(&c3_sf_internal_predicateOutput);
  *(boolean_T *)c3_outData = c3_b_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_homing_ldm_aggiornat_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static void c3_interpolazione_tempi2(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, real_T c3_b_x_i[3320], real_T c3_xp_i[3320], real_T c3_y_i
  [3320], real_T c3_yp_i[3320], real_T c3_u, real_T c3_c_t_m[3320], real_T
  c3_riff_iniziale, real_T *c3_xx, real_T *c3_xxp, real_T *c3_yy, real_T *c3_yyp)
{
  uint32_T c3_debug_family_var_map[13];
  real_T c3_nargin = 7.0;
  real_T c3_nargout = 4.0;
  int32_T c3_i18;
  int32_T c3_i19;
  int32_T c3_i20;
  int32_T c3_i21;
  real_T c3_b_xp_i[3320];
  int32_T c3_i22;
  int32_T c3_i23;
  real_T c3_d_t_m[3320];
  real_T c3_b_y_i[3320];
  int32_T c3_i24;
  int32_T c3_i25;
  real_T c3_e_t_m[3320];
  real_T c3_b_yp_i[3320];
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c3_c_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_x_i, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_xp_i, 3U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_y_i, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_yp_i, 5U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_u, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_c_t_m, 7U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_riff_iniziale, 8U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_xx, 9U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_xxp, 10U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_yy, 11U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_yyp, 12U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(7, 0);
  _SFD_EML_CALL(7U, *chartInstance->c3_sfEvent, 3);
  for (c3_i18 = 0; c3_i18 < 3320; c3_i18++) {
    chartInstance->c3_t_m[c3_i18] = c3_c_t_m[c3_i18];
  }

  for (c3_i19 = 0; c3_i19 < 3320; c3_i19++) {
    chartInstance->c3_x_i[c3_i19] = c3_b_x_i[c3_i19];
  }

  *c3_xx = c3_interp1(chartInstance, chartInstance->c3_t_m,
                      chartInstance->c3_x_i, c3_u, c3_riff_iniziale);
  _SFD_EML_CALL(7U, *chartInstance->c3_sfEvent, 4);
  for (c3_i20 = 0; c3_i20 < 3320; c3_i20++) {
    chartInstance->c3_b_t_m[c3_i20] = c3_c_t_m[c3_i20];
  }

  for (c3_i21 = 0; c3_i21 < 3320; c3_i21++) {
    c3_b_xp_i[c3_i21] = c3_xp_i[c3_i21];
  }

  *c3_xxp = c3_b_interp1(chartInstance, chartInstance->c3_b_t_m, c3_b_xp_i, c3_u);
  _SFD_EML_CALL(7U, *chartInstance->c3_sfEvent, 7);
  for (c3_i22 = 0; c3_i22 < 3320; c3_i22++) {
    c3_d_t_m[c3_i22] = c3_c_t_m[c3_i22];
  }

  for (c3_i23 = 0; c3_i23 < 3320; c3_i23++) {
    c3_b_y_i[c3_i23] = c3_y_i[c3_i23];
  }

  *c3_yy = c3_interp1(chartInstance, c3_d_t_m, c3_b_y_i, c3_u, c3_riff_iniziale);
  _SFD_EML_CALL(7U, *chartInstance->c3_sfEvent, 8);
  for (c3_i24 = 0; c3_i24 < 3320; c3_i24++) {
    c3_e_t_m[c3_i24] = c3_c_t_m[c3_i24];
  }

  for (c3_i25 = 0; c3_i25 < 3320; c3_i25++) {
    c3_b_yp_i[c3_i25] = c3_yp_i[c3_i25];
  }

  *c3_yyp = c3_b_interp1(chartInstance, c3_e_t_m, c3_b_yp_i, c3_u);
  _SFD_EML_CALL(7U, *chartInstance->c3_sfEvent, -8);
  _SFD_SYMBOL_SCOPE_POP();
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_u;
  const mxArray *c3_b_y = NULL;
  SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance;
  chartInstance = (SFc3_homing_ldm_aggiornatInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_e_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_b_y;
  int32_T c3_i26;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i26, 1, 6, 0U, 0, 0U, 0);
  c3_b_y = c3_i26;
  sf_mex_destroy(&c3_u);
  return c3_b_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_b_y;
  SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance;
  chartInstance = (SFc3_homing_ldm_aggiornatInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_b_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  uint8_T c3_u;
  const mxArray *c3_b_y = NULL;
  SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance;
  chartInstance = (SFc3_homing_ldm_aggiornatInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint8_T *)c3_inData;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static uint8_T c3_f_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_b_is_Pilotaggio, const char_T *c3_identifier)
{
  uint8_T c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_is_Pilotaggio),
    &c3_thisId);
  sf_mex_destroy(&c3_b_is_Pilotaggio);
  return c3_b_y;
}

static uint8_T c3_g_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_b_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_b_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_b_y;
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_is_Pilotaggio;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_b_y;
  SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance;
  chartInstance = (SFc3_homing_ldm_aggiornatInstanceStruct *)chartInstanceVoid;
  c3_b_is_Pilotaggio = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_b_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_is_Pilotaggio),
    &c3_thisId);
  sf_mex_destroy(&c3_b_is_Pilotaggio);
  *(uint8_T *)c3_outData = c3_b_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static void c3_h_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_b_dataWrittenToVector, const char_T
  *c3_identifier, boolean_T c3_b_y[33])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_dataWrittenToVector),
                        &c3_thisId, c3_b_y);
  sf_mex_destroy(&c3_b_dataWrittenToVector);
}

static void c3_i_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T c3_b_y[33])
{
  boolean_T c3_bv1[33];
  int32_T c3_i27;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_bv1, 1, 11, 0U, 1, 0U, 1, 33);
  for (c3_i27 = 0; c3_i27 < 33; c3_i27++) {
    c3_b_y[c3_i27] = c3_bv1[c3_i27];
  }

  sf_mex_destroy(&c3_u);
}

static const mxArray *c3_j_emlrt_marshallIn
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance, const mxArray
   *c3_b_setSimStateSideEffectsInfo, const char_T *c3_identifier)
{
  const mxArray *c3_b_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_b_y = NULL;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  sf_mex_assign(&c3_b_y, c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_b_y;
}

static const mxArray *c3_k_emlrt_marshallIn
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance, const mxArray *c3_u,
   const emlrtMsgIdentifier *c3_parentId)
{
  const mxArray *c3_b_y = NULL;
  (void)chartInstance;
  (void)c3_parentId;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_duplicatearraysafe(&c3_u), false);
  sf_mex_destroy(&c3_u);
  return c3_b_y;
}

static const mxArray *sf_get_hover_data_for_msg
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance, int32_T c3_ssid)
{
  const mxArray *c3_msgInfo;
  (void)chartInstance;
  (void)c3_ssid;
  c3_msgInfo = NULL;
  return NULL;
}

static void c3_init_sf_message_store_memory
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_dsm_address_info(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance)
{
  chartInstance->c3_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c3_sfEvent = (int32_T *)ssGetDWork_wrapper(chartInstance->S, 0);
  chartInstance->c3_is_active_c3_homing_ldm_aggiornat = (uint8_T *)
    ssGetDWork_wrapper(chartInstance->S, 1);
  chartInstance->c3_is_c3_homing_ldm_aggiornat = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_is_Pilotaggio = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 3);
  chartInstance->c3_is_Homing1 = (uint8_T *)ssGetDWork_wrapper(chartInstance->S,
    4);
  chartInstance->c3_fcx = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c3_Vel_x_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_Vel_x = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_ok_x = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_ok_y = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c3_Vel_y = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_Vel_y_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c3_fcy = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c3_Pos_x = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c3_dx = (real_T *)ssGetDWork_wrapper(chartInstance->S, 5);
  chartInstance->c3_ok_x_2 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c3_v_sp_x = (real_T *)ssGetDWork_wrapper(chartInstance->S, 6);
  chartInstance->c3_v_sp_y = (real_T *)ssGetDWork_wrapper(chartInstance->S, 7);
  chartInstance->c3_Pos_y = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c3_ok_y_2 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c3_dy = (real_T *)ssGetDWork_wrapper(chartInstance->S, 8);
  chartInstance->c3_clock = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c3_bx = (real_T *)ssGetDWork_wrapper(chartInstance->S, 9);
  chartInstance->c3_by = (real_T *)ssGetDWork_wrapper(chartInstance->S, 10);
  chartInstance->c3_inizio_traiettoria = (real_T *)ssGetDWork_wrapper
    (chartInstance->S, 11);
  chartInstance->c3_g2x = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c3_g1x = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c3_g2y = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c3_g1y = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 10);
  chartInstance->c3_deltaxp = (real_T *)ssGetDWork_wrapper(chartInstance->S, 12);
  chartInstance->c3_deltayp = (real_T *)ssGetDWork_wrapper(chartInstance->S, 13);
  chartInstance->c3_ix = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    11);
  chartInstance->c3_iy = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    12);
  chartInstance->c3_deltax = (real_T *)ssGetDWork_wrapper(chartInstance->S, 14);
  chartInstance->c3_deltay = (real_T *)ssGetDWork_wrapper(chartInstance->S, 15);
  chartInstance->c3_tensionex = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c3_tensioney = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c3_ok_x_3 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c3_ok_y_3 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 10);
  chartInstance->c3_rifx = (real_T *)ssGetDWork_wrapper(chartInstance->S, 16);
  chartInstance->c3_rifxp = (real_T *)ssGetDWork_wrapper(chartInstance->S, 17);
  chartInstance->c3_rify = (real_T *)ssGetDWork_wrapper(chartInstance->S, 18);
  chartInstance->c3_rifyp = (real_T *)ssGetDWork_wrapper(chartInstance->S, 19);
  chartInstance->c3_appoggio = (real_T *)ssGetDWork_wrapper(chartInstance->S, 20);
  chartInstance->c3_rif_iniziale = (real_T *)ssGetDWork_wrapper(chartInstance->S,
    21);
  chartInstance->c3_t1 = (real_T *)ssGetDWork_wrapper(chartInstance->S, 22);
  chartInstance->c3_t = (real_T *)ssGetDWork_wrapper(chartInstance->S, 23);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

static uint32_T* sf_get_sfun_dwork_checksum(void);
void sf_c3_homing_ldm_aggiornat_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2404036773U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1146096490U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(524185927U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2530325772U);
}

mxArray* sf_c3_homing_ldm_aggiornat_get_post_codegen_info(void);
mxArray *sf_c3_homing_ldm_aggiornat_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("kZ1v6Xs1YJ3NatKDsMGQTH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,13,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(3320);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(3320);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(3320);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(3320);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(3320);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,10,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,19,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,14,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,14,"type",mxType);
    }

    mxSetField(mxData,14,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,15,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,15,"type",mxType);
    }

    mxSetField(mxData,15,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,16,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,16,"type",mxType);
    }

    mxSetField(mxData,16,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,17,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,17,"type",mxType);
    }

    mxSetField(mxData,17,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,18,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,18,"type",mxType);
    }

    mxSetField(mxData,18,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c3_homing_ldm_aggiornat_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_homing_ldm_aggiornat_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_homing_ldm_aggiornat_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("early");
  mxArray *fallbackReason = mxCreateString("ext_mode");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c3_homing_ldm_aggiornat_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_homing_ldm_aggiornat_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c3_homing_ldm_aggiornat(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[16],T\"Vel_x_out\",},{M[1],M[55],T\"Vel_y_out\",},{M[1],M[52],T\"ok_x\",},{M[1],M[79],T\"ok_x_2\",},{M[1],M[212],T\"ok_x_3\",},{M[1],M[53],T\"ok_y\",},{M[1],M[90],T\"ok_y_2\",},{M[1],M[214],T\"ok_y_3\",},{M[1],M[209],T\"tensionex\",},{M[1],M[210],T\"tensioney\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[246],T\"appoggio\",},{M[3],M[176],T\"bx\",},{M[3],M[177],T\"by\",},{M[3],M[195],T\"deltax\",},{M[3],M[199],T\"deltaxp\",},{M[3],M[196],T\"deltay\",},{M[3],M[200],T\"deltayp\",},{M[3],M[80],T\"dx\",},{M[3],M[91],T\"dy\",},{M[3],M[178],T\"inizio_traiettoria\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[255],T\"rif_iniziale\",},{M[3],M[241],T\"rifx\",},{M[3],M[242],T\"rifxp\",},{M[3],M[243],T\"rify\",},{M[3],M[244],T\"rifyp\",},{M[3],M[123],T\"t\",},{M[3],M[101],T\"t1\",},{M[3],M[81],T\"v_sp_x\",},{M[3],M[87],T\"v_sp_y\",},{M[8],M[0],T\"is_active_c3_homing_ldm_aggiornat\",}}",
    "100 S1x4'type','srcId','name','auxInfo'{{M[9],M[0],T\"is_c3_homing_ldm_aggiornat\",},{M[9],M[44],T\"is_Pilotaggio\",},{M[9],M[144],T\"is_Homing1\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 34, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_homing_ldm_aggiornat_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc3_homing_ldm_aggiornatInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance =
      (SFc3_homing_ldm_aggiornatInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _homing_ldm_aggiornatMachineNumber_,
           3,
           8,
           7,
           0,
           58,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_homing_ldm_aggiornatMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_homing_ldm_aggiornatMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _homing_ldm_aggiornatMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,0,0,0,"t");
          _SFD_SET_DATA_PROPS(1,0,0,0,"t1");
          _SFD_SET_DATA_PROPS(2,0,0,0,"appoggio");
          _SFD_SET_DATA_PROPS(3,0,0,0,"bx");
          _SFD_SET_DATA_PROPS(4,0,0,0,"by");
          _SFD_SET_DATA_PROPS(5,0,0,0,"deltax");
          _SFD_SET_DATA_PROPS(6,0,0,0,"deltaxp");
          _SFD_SET_DATA_PROPS(7,0,0,0,"deltay");
          _SFD_SET_DATA_PROPS(8,0,0,0,"deltayp");
          _SFD_SET_DATA_PROPS(9,0,0,0,"dx");
          _SFD_SET_DATA_PROPS(10,0,0,0,"dy");
          _SFD_SET_DATA_PROPS(11,0,0,0,"inizio_traiettoria");
          _SFD_SET_DATA_PROPS(12,0,0,0,"rif_iniziale");
          _SFD_SET_DATA_PROPS(13,0,0,0,"rifx");
          _SFD_SET_DATA_PROPS(14,0,0,0,"rifxp");
          _SFD_SET_DATA_PROPS(15,0,0,0,"rify");
          _SFD_SET_DATA_PROPS(16,0,0,0,"rifyp");
          _SFD_SET_DATA_PROPS(17,0,0,0,"v_sp_x");
          _SFD_SET_DATA_PROPS(18,0,0,0,"v_sp_y");
          _SFD_SET_DATA_PROPS(19,1,1,0,"fcx");
          _SFD_SET_DATA_PROPS(20,1,1,0,"Vel_x");
          _SFD_SET_DATA_PROPS(21,1,1,0,"Vel_y");
          _SFD_SET_DATA_PROPS(22,1,1,0,"fcy");
          _SFD_SET_DATA_PROPS(23,1,1,0,"Pos_x");
          _SFD_SET_DATA_PROPS(24,1,1,0,"Pos_y");
          _SFD_SET_DATA_PROPS(25,1,1,0,"clock");
          _SFD_SET_DATA_PROPS(26,1,1,0,"g2x");
          _SFD_SET_DATA_PROPS(27,1,1,0,"g1x");
          _SFD_SET_DATA_PROPS(28,1,1,0,"g2y");
          _SFD_SET_DATA_PROPS(29,1,1,0,"g1y");
          _SFD_SET_DATA_PROPS(30,1,1,0,"ix");
          _SFD_SET_DATA_PROPS(31,1,1,0,"iy");
          _SFD_SET_DATA_PROPS(32,2,0,1,"Vel_x_out");
          _SFD_SET_DATA_PROPS(33,2,0,1,"ok_x");
          _SFD_SET_DATA_PROPS(34,2,0,1,"ok_y");
          _SFD_SET_DATA_PROPS(35,2,0,1,"Vel_y_out");
          _SFD_SET_DATA_PROPS(36,2,0,1,"ok_x_2");
          _SFD_SET_DATA_PROPS(37,2,0,1,"ok_y_2");
          _SFD_SET_DATA_PROPS(38,2,0,1,"tensionex");
          _SFD_SET_DATA_PROPS(39,2,0,1,"tensioney");
          _SFD_SET_DATA_PROPS(40,2,0,1,"ok_x_3");
          _SFD_SET_DATA_PROPS(41,2,0,1,"ok_y_3");
          _SFD_SET_DATA_PROPS(42,8,0,0,"");
          _SFD_SET_DATA_PROPS(43,8,0,0,"");
          _SFD_SET_DATA_PROPS(44,8,0,0,"");
          _SFD_SET_DATA_PROPS(45,8,0,0,"");
          _SFD_SET_DATA_PROPS(46,8,0,0,"");
          _SFD_SET_DATA_PROPS(47,8,0,0,"");
          _SFD_SET_DATA_PROPS(48,8,0,0,"");
          _SFD_SET_DATA_PROPS(49,9,0,0,"");
          _SFD_SET_DATA_PROPS(50,9,0,0,"");
          _SFD_SET_DATA_PROPS(51,9,0,0,"");
          _SFD_SET_DATA_PROPS(52,9,0,0,"");
          _SFD_SET_DATA_PROPS(53,10,0,0,"Vel_asse_x");
          _SFD_SET_DATA_PROPS(54,10,0,0,"Vel_asse_y");
          _SFD_SET_DATA_PROPS(55,10,0,0,"time");
          _SFD_SET_DATA_PROPS(56,10,0,0,"x");
          _SFD_SET_DATA_PROPS(57,10,0,0,"y");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,2);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,4);
          _SFD_ST_SUBSTATE_COUNT(0,3);
          _SFD_ST_SUBSTATE_INDEX(0,0,1);
          _SFD_ST_SUBSTATE_INDEX(0,1,2);
          _SFD_ST_SUBSTATE_INDEX(0,2,3);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,2);
          _SFD_ST_SUBSTATE_INDEX(4,0,5);
          _SFD_ST_SUBSTATE_INDEX(4,1,6);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
        }

        _SFD_CV_INIT_CHART(2,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,3,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,2,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(7,1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(7,0,"interpolazione_tempi2",0,-1,318);
        _SFD_CV_INIT_EML(6,1,0,0,5,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,1,0,146,161,-1,187);
        _SFD_CV_INIT_EML_IF(6,1,1,571,587,-1,611);
        _SFD_CV_INIT_EML_IF(6,1,2,612,629,-1,654);
        _SFD_CV_INIT_EML_IF(6,1,3,655,671,-1,695);
        _SFD_CV_INIT_EML_IF(6,1,4,696,713,-1,738);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,1,0,145,155,-1,178);
        _SFD_CV_INIT_EML_IF(2,1,1,221,231,-1,254);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(1,0,0,1,42,1,42);

        {
          static int condStart[] = { 2, 24 };

          static int condEnd[] = { 20, 42 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(1,0,0,2,42,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(1,0,0,2,20,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(1,0,1,24,42,-1,0);
        _SFD_CV_INIT_EML(4,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(4,0,0,1,17,1,17);

        {
          static int condStart[] = { 1, 11 };

          static int condEnd[] = { 7, 17 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(4,0,0,1,17,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(4,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(4,0,1,11,17,-1,0);
        _SFD_CV_INIT_EML(3,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(3,0,0,1,17,1,17);

        {
          static int condStart[] = { 1, 11 };

          static int condEnd[] = { 7, 17 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(3,0,0,1,17,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(3,0,0,1,7,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(3,0,1,11,17,-1,4);
        _SFD_CV_INIT_EML(6,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,1,22,1,22);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(26,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(27,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(28,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(29,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(30,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(31,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(32,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(33,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(34,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(35,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(36,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(37,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(38,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(39,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(40,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(41,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(42,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(43,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(44,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(45,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(46,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(47,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(48,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(49,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(50,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(51,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295U;
          _SFD_SET_DATA_COMPILED_PROPS(52,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 3320U;
          _SFD_SET_DATA_COMPILED_PROPS(53,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)
            c3_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 3320U;
          _SFD_SET_DATA_COMPILED_PROPS(54,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)
            c3_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 3320U;
          _SFD_SET_DATA_COMPILED_PROPS(55,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)
            c3_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 3320U;
          _SFD_SET_DATA_COMPILED_PROPS(56,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)
            c3_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 3320U;
          _SFD_SET_DATA_COMPILED_PROPS(57,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)
            c3_b_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(42,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(43,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(44,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(45,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(46,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(47,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(48,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(49,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(50,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(51,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(52,(void *)(NULL));
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _homing_ldm_aggiornatMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance =
      (SFc3_homing_ldm_aggiornatInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(19U, (void *)chartInstance->c3_fcx);
        _SFD_SET_DATA_VALUE_PTR(32U, (void *)chartInstance->c3_Vel_x_out);
        _SFD_SET_DATA_VALUE_PTR(20U, (void *)chartInstance->c3_Vel_x);
        _SFD_SET_DATA_VALUE_PTR(33U, (void *)chartInstance->c3_ok_x);
        _SFD_SET_DATA_VALUE_PTR(34U, (void *)chartInstance->c3_ok_y);
        _SFD_SET_DATA_VALUE_PTR(21U, (void *)chartInstance->c3_Vel_y);
        _SFD_SET_DATA_VALUE_PTR(35U, (void *)chartInstance->c3_Vel_y_out);
        _SFD_SET_DATA_VALUE_PTR(22U, (void *)chartInstance->c3_fcy);
        _SFD_SET_DATA_VALUE_PTR(23U, (void *)chartInstance->c3_Pos_x);
        _SFD_SET_DATA_VALUE_PTR(9U, (void *)chartInstance->c3_dx);
        _SFD_SET_DATA_VALUE_PTR(36U, (void *)chartInstance->c3_ok_x_2);
        _SFD_SET_DATA_VALUE_PTR(17U, (void *)chartInstance->c3_v_sp_x);
        _SFD_SET_DATA_VALUE_PTR(18U, (void *)chartInstance->c3_v_sp_y);
        _SFD_SET_DATA_VALUE_PTR(24U, (void *)chartInstance->c3_Pos_y);
        _SFD_SET_DATA_VALUE_PTR(37U, (void *)chartInstance->c3_ok_y_2);
        _SFD_SET_DATA_VALUE_PTR(10U, (void *)chartInstance->c3_dy);
        _SFD_SET_DATA_VALUE_PTR(25U, (void *)chartInstance->c3_clock);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c3_bx);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)chartInstance->c3_by);
        _SFD_SET_DATA_VALUE_PTR(11U, (void *)
          chartInstance->c3_inizio_traiettoria);
        _SFD_SET_DATA_VALUE_PTR(26U, (void *)chartInstance->c3_g2x);
        _SFD_SET_DATA_VALUE_PTR(27U, (void *)chartInstance->c3_g1x);
        _SFD_SET_DATA_VALUE_PTR(28U, (void *)chartInstance->c3_g2y);
        _SFD_SET_DATA_VALUE_PTR(29U, (void *)chartInstance->c3_g1y);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)chartInstance->c3_deltaxp);
        _SFD_SET_DATA_VALUE_PTR(8U, (void *)chartInstance->c3_deltayp);
        _SFD_SET_DATA_VALUE_PTR(30U, (void *)chartInstance->c3_ix);
        _SFD_SET_DATA_VALUE_PTR(31U, (void *)chartInstance->c3_iy);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)chartInstance->c3_deltax);
        _SFD_SET_DATA_VALUE_PTR(7U, (void *)chartInstance->c3_deltay);
        _SFD_SET_DATA_VALUE_PTR(38U, (void *)chartInstance->c3_tensionex);
        _SFD_SET_DATA_VALUE_PTR(39U, (void *)chartInstance->c3_tensioney);
        _SFD_SET_DATA_VALUE_PTR(40U, (void *)chartInstance->c3_ok_x_3);
        _SFD_SET_DATA_VALUE_PTR(41U, (void *)chartInstance->c3_ok_y_3);
        _SFD_SET_DATA_VALUE_PTR(53U, (void *)&chartInstance->c3_Vel_asse_x);
        _SFD_SET_DATA_VALUE_PTR(54U, (void *)&chartInstance->c3_Vel_asse_y);
        _SFD_SET_DATA_VALUE_PTR(55U, (void *)&chartInstance->c3_time);
        _SFD_SET_DATA_VALUE_PTR(56U, (void *)&chartInstance->c3_x);
        _SFD_SET_DATA_VALUE_PTR(57U, (void *)&chartInstance->c3_y);
        _SFD_SET_DATA_VALUE_PTR(13U, (void *)chartInstance->c3_rifx);
        _SFD_SET_DATA_VALUE_PTR(14U, (void *)chartInstance->c3_rifxp);
        _SFD_SET_DATA_VALUE_PTR(15U, (void *)chartInstance->c3_rify);
        _SFD_SET_DATA_VALUE_PTR(16U, (void *)chartInstance->c3_rifyp);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c3_appoggio);
        _SFD_SET_DATA_VALUE_PTR(12U, (void *)chartInstance->c3_rif_iniziale);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c3_t1);
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c3_t);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "shWW5VNiK3wrAH140bCjOiB";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_homing_ldm_aggiornat_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 3, "dworkChecksum");
    if (mxRTWDWorkChecksum != NULL) {
      double *pr = mxGetPr(mxRTWDWorkChecksum);
      if ((uint32_T)pr[0] != sfunDWorkChecksum[0] ||
          (uint32_T)pr[1] != sfunDWorkChecksum[1] ||
          (uint32_T)pr[2] != sfunDWorkChecksum[2] ||
          (uint32_T)pr[3] != sfunDWorkChecksum[3]) {
        sf_mex_error_message("Code generation and simulation targets registered different sets of persistent variables for the block. "
                             "External or Rapid Accelerator mode simulation requires code generation and simulation targets to "
                             "register the same set of persistent variables for this block. "
                             "This discrepancy is typically caused by MATLAB functions that have different code paths for "
                             "simulation and code generation targets where these code paths define different sets of persistent variables. "
                             "Please identify these code paths in the offending block and rewrite the MATLAB code so that "
                             "the set of persistent variables is the same between simulation and code generation.");
      }
    }
  }
}

static void sf_opaque_initialize_c3_homing_ldm_aggiornat(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc3_homing_ldm_aggiornatInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc3_homing_ldm_aggiornatInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_homing_ldm_aggiornat
    ((SFc3_homing_ldm_aggiornatInstanceStruct*) chartInstanceVar);
  initialize_c3_homing_ldm_aggiornat((SFc3_homing_ldm_aggiornatInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_homing_ldm_aggiornat(void *chartInstanceVar)
{
  enable_c3_homing_ldm_aggiornat((SFc3_homing_ldm_aggiornatInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_homing_ldm_aggiornat(void *chartInstanceVar)
{
  disable_c3_homing_ldm_aggiornat((SFc3_homing_ldm_aggiornatInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_homing_ldm_aggiornat(void *chartInstanceVar)
{
  sf_gateway_c3_homing_ldm_aggiornat((SFc3_homing_ldm_aggiornatInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c3_homing_ldm_aggiornat(void
  *chartInstanceVar)
{
  ext_mode_exec_c3_homing_ldm_aggiornat((SFc3_homing_ldm_aggiornatInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_homing_ldm_aggiornat(SimStruct*
  S)
{
  return get_sim_state_c3_homing_ldm_aggiornat
    ((SFc3_homing_ldm_aggiornatInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_homing_ldm_aggiornat(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c3_homing_ldm_aggiornat((SFc3_homing_ldm_aggiornatInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c3_homing_ldm_aggiornat(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_homing_ldm_aggiornatInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_homing_ldm_aggiornat_optimization_info();
    }

    finalize_c3_homing_ldm_aggiornat((SFc3_homing_ldm_aggiornatInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_homing_ldm_aggiornat((SFc3_homing_ldm_aggiornatInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_homing_ldm_aggiornat(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_homing_ldm_aggiornat
      ((SFc3_homing_ldm_aggiornatInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

mxArray *sf_c3_homing_ldm_aggiornat_get_testpoint_info(void)
{
  return NULL;
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  const char *dworkEncStr[] = {
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id'{{T\"int32\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"uint8\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1]}}",
    "100 S1x10'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id'{{T\"double\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1]}}",
    "100 S1x4'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id'{{T\"double\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 24, 10);
}

static uint32_T* sf_get_sfun_dwork_checksum()
{
  static uint32_T checksum[4] = { 3841420121U, 528933471U, 2472234477U,
    2372519449U };

  return checksum;
}

static void mdlSetWorkWidths_c3_homing_ldm_aggiornat(SimStruct *S)
{
  /* Actual parameters from chart:
     Vel_asse_x Vel_asse_y time x y
   */
  const char_T *rtParamNames[] = { "Vel_asse_x", "Vel_asse_y", "time", "x", "y"
  };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for Vel_asse_x*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for Vel_asse_y*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for time*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);

  /* registration for x*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_DOUBLE);

  /* registration for y*/
  ssRegDlgParamAsRunTimeParam(S, 4, 4, rtParamNames[4], SS_DOUBLE);
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_homing_ldm_aggiornat_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 3);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 12, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,13);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,10);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=10; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 13; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1437129553U));
  ssSetChecksum1(S,(3493769222U));
  ssSetChecksum2(S,(2808453616U));
  ssSetChecksum3(S,(1899465254U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_homing_ldm_aggiornat(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c3_homing_ldm_aggiornat(SimStruct *S)
{
  SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance;
  chartInstance = (SFc3_homing_ldm_aggiornatInstanceStruct *)utMalloc(sizeof
    (SFc3_homing_ldm_aggiornatInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc3_homing_ldm_aggiornatInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_homing_ldm_aggiornat;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_homing_ldm_aggiornat;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_homing_ldm_aggiornat;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c3_homing_ldm_aggiornat;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_homing_ldm_aggiornat;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_homing_ldm_aggiornat;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_homing_ldm_aggiornat;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_homing_ldm_aggiornat;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_homing_ldm_aggiornat;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_homing_ldm_aggiornat;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_homing_ldm_aggiornat;
  chartInstance->chartInfo.callGetHoverDataForMsg =
    sf_opaque_get_hover_data_for_msg;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c3_homing_ldm_aggiornat;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c3_homing_ldm_aggiornat(chartInstance);
}

void c3_homing_ldm_aggiornat_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_homing_ldm_aggiornat(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_homing_ldm_aggiornat(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_homing_ldm_aggiornat(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_homing_ldm_aggiornat_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
