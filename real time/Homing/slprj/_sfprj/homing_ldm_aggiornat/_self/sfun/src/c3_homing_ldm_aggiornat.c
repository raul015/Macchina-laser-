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
#define c3_IN_Homing2                  ((uint8_T)2U)
#define c3_IN_Fine                     ((uint8_T)1U)
#define c3_IN_Fine_homing1             ((uint8_T)2U)
#define c3_IN_Homing_x                 ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_j_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_k_debug_family_names[2] = { "nargin", "nargout" };

static const char * c3_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_m_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_n_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_o_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c3_p_debug_family_names[3] = { "nargin", "nargout",
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
static void c3_Homing1(SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance);
static void c3_exit_internal_Homing1(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance);
static void c3_Homing2(SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance);
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
static boolean_T c3_c_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_d_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_e_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_b_is_Homing1, const char_T *c3_identifier);
static uint8_T c3_f_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_g_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_b_dataWrittenToVector, const char_T
  *c3_identifier, boolean_T c3_y[15]);
static void c3_h_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T c3_y[15]);
static const mxArray *c3_i_emlrt_marshallIn
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance, const mxArray
   *c3_b_setSimStateSideEffectsInfo, const char_T *c3_identifier);
static const mxArray *c3_j_emlrt_marshallIn
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
  *chartInstance->c3_is_Homing2 = c3_IN_NO_ACTIVE_CHILD;
  *chartInstance->c3_is_active_c3_homing_ldm_aggiornat = 0U;
  *chartInstance->c3_is_c3_homing_ldm_aggiornat = c3_IN_NO_ACTIVE_CHILD;
}

static void initialize_params_c3_homing_ldm_aggiornat
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance)
{
  (void)chartInstance;
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

  if (*chartInstance->c3_is_c3_homing_ldm_aggiornat == c3_IN_Homing1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c3_sfEvent);
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

  if (*chartInstance->c3_is_Homing1 == c3_IN_Homing_x) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_c3_homing_ldm_aggiornat == c3_IN_Homing2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_Homing2 == c3_IN_Fine) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_Homing2 == c3_IN_Homing_x) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, *chartInstance->c3_sfEvent);
  }

  if (*chartInstance->c3_is_Homing2 == c3_IN_Fine_homing1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, *chartInstance->c3_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *chartInstance->c3_sfEvent);
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
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  const mxArray *c3_c_y = NULL;
  real_T c3_c_hoistedGlobal;
  const mxArray *c3_d_y = NULL;
  real_T c3_d_hoistedGlobal;
  const mxArray *c3_e_y = NULL;
  real_T c3_e_hoistedGlobal;
  const mxArray *c3_f_y = NULL;
  real_T c3_f_hoistedGlobal;
  const mxArray *c3_g_y = NULL;
  real_T c3_g_hoistedGlobal;
  const mxArray *c3_h_y = NULL;
  real_T c3_h_hoistedGlobal;
  const mxArray *c3_i_y = NULL;
  real_T c3_i_hoistedGlobal;
  const mxArray *c3_j_y = NULL;
  real_T c3_j_hoistedGlobal;
  const mxArray *c3_k_y = NULL;
  real_T c3_k_hoistedGlobal;
  const mxArray *c3_l_y = NULL;
  real_T c3_l_hoistedGlobal;
  const mxArray *c3_m_y = NULL;
  real_T c3_m_hoistedGlobal;
  const mxArray *c3_n_y = NULL;
  real_T c3_n_hoistedGlobal;
  const mxArray *c3_o_y = NULL;
  real_T c3_o_hoistedGlobal;
  const mxArray *c3_p_y = NULL;
  uint8_T c3_p_hoistedGlobal;
  const mxArray *c3_q_y = NULL;
  uint8_T c3_q_hoistedGlobal;
  const mxArray *c3_r_y = NULL;
  uint8_T c3_r_hoistedGlobal;
  const mxArray *c3_s_y = NULL;
  uint8_T c3_s_hoistedGlobal;
  const mxArray *c3_t_y = NULL;
  const mxArray *c3_u_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(20, 1), false);
  c3_hoistedGlobal = *chartInstance->c3_Vel_x_out;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_hoistedGlobal, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *chartInstance->c3_Vel_y_out;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = *chartInstance->c3_ok_x;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = *chartInstance->c3_ok_x_2;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = *chartInstance->c3_ok_y;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_f_hoistedGlobal = *chartInstance->c3_ok_y_2;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_f_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_g_hoistedGlobal = *chartInstance->c3_a;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_g_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  c3_h_hoistedGlobal = *chartInstance->c3_ay;
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_h_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 7, c3_i_y);
  c3_i_hoistedGlobal = *chartInstance->c3_bx;
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", &c3_i_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 8, c3_j_y);
  c3_j_hoistedGlobal = *chartInstance->c3_by;
  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y", &c3_j_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 9, c3_k_y);
  c3_k_hoistedGlobal = *chartInstance->c3_dx;
  c3_l_y = NULL;
  sf_mex_assign(&c3_l_y, sf_mex_create("y", &c3_k_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 10, c3_l_y);
  c3_l_hoistedGlobal = *chartInstance->c3_dy;
  c3_m_y = NULL;
  sf_mex_assign(&c3_m_y, sf_mex_create("y", &c3_l_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 11, c3_m_y);
  c3_m_hoistedGlobal = *chartInstance->c3_inizio_traiettoria;
  c3_n_y = NULL;
  sf_mex_assign(&c3_n_y, sf_mex_create("y", &c3_m_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 12, c3_n_y);
  c3_n_hoistedGlobal = *chartInstance->c3_v_sp_x;
  c3_o_y = NULL;
  sf_mex_assign(&c3_o_y, sf_mex_create("y", &c3_n_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 13, c3_o_y);
  c3_o_hoistedGlobal = *chartInstance->c3_v_sp_y;
  c3_p_y = NULL;
  sf_mex_assign(&c3_p_y, sf_mex_create("y", &c3_o_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 14, c3_p_y);
  c3_p_hoistedGlobal = *chartInstance->c3_is_active_c3_homing_ldm_aggiornat;
  c3_q_y = NULL;
  sf_mex_assign(&c3_q_y, sf_mex_create("y", &c3_p_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 15, c3_q_y);
  c3_q_hoistedGlobal = *chartInstance->c3_is_c3_homing_ldm_aggiornat;
  c3_r_y = NULL;
  sf_mex_assign(&c3_r_y, sf_mex_create("y", &c3_q_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 16, c3_r_y);
  c3_r_hoistedGlobal = *chartInstance->c3_is_Homing1;
  c3_s_y = NULL;
  sf_mex_assign(&c3_s_y, sf_mex_create("y", &c3_r_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 17, c3_s_y);
  c3_s_hoistedGlobal = *chartInstance->c3_is_Homing2;
  c3_t_y = NULL;
  sf_mex_assign(&c3_t_y, sf_mex_create("y", &c3_s_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 18, c3_t_y);
  c3_u_y = NULL;
  sf_mex_assign(&c3_u_y, sf_mex_create("y",
    chartInstance->c3_dataWrittenToVector, 11, 0U, 1U, 0U, 1, 15), false);
  sf_mex_setcell(c3_y, 19, c3_u_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_homing_ldm_aggiornat
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  boolean_T c3_bv0[15];
  int32_T c3_i0;
  c3_u = sf_mex_dup(c3_st);
  *chartInstance->c3_Vel_x_out = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Vel_x_out", c3_u, 0)), "Vel_x_out");
  *chartInstance->c3_Vel_y_out = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Vel_y_out", c3_u, 1)), "Vel_y_out");
  *chartInstance->c3_ok_x = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("ok_x", c3_u, 2)), "ok_x");
  *chartInstance->c3_ok_x_2 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("ok_x_2", c3_u, 3)), "ok_x_2");
  *chartInstance->c3_ok_y = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("ok_y", c3_u, 4)), "ok_y");
  *chartInstance->c3_ok_y_2 = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("ok_y_2", c3_u, 5)), "ok_y_2");
  *chartInstance->c3_a = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("a", c3_u, 6)), "a");
  *chartInstance->c3_ay = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("ay", c3_u, 7)), "ay");
  *chartInstance->c3_bx = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("bx", c3_u, 8)), "bx");
  *chartInstance->c3_by = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("by", c3_u, 9)), "by");
  *chartInstance->c3_dx = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("dx", c3_u, 10)), "dx");
  *chartInstance->c3_dy = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("dy", c3_u, 11)), "dy");
  *chartInstance->c3_inizio_traiettoria = c3_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("inizio_traiettoria", c3_u, 12)),
    "inizio_traiettoria");
  *chartInstance->c3_v_sp_x = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("v_sp_x", c3_u, 13)), "v_sp_x");
  *chartInstance->c3_v_sp_y = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("v_sp_y", c3_u, 14)), "v_sp_y");
  *chartInstance->c3_is_active_c3_homing_ldm_aggiornat = c3_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(
       "is_active_c3_homing_ldm_aggiornat", c3_u, 15)),
     "is_active_c3_homing_ldm_aggiornat");
  *chartInstance->c3_is_c3_homing_ldm_aggiornat = c3_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_c3_homing_ldm_aggiornat", c3_u,
       16)), "is_c3_homing_ldm_aggiornat");
  *chartInstance->c3_is_Homing1 = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_Homing1", c3_u, 17)), "is_Homing1");
  *chartInstance->c3_is_Homing2 = c3_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_Homing2", c3_u, 18)), "is_Homing2");
  c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "dataWrittenToVector", c3_u, 19)), "dataWrittenToVector", c3_bv0);
  for (c3_i0 = 0; c3_i0 < 15; c3_i0++) {
    chartInstance->c3_dataWrittenToVector[c3_i0] = c3_bv0[c3_i0];
  }

  sf_mex_assign(&chartInstance->c3_setSimStateSideEffectsInfo,
                c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "setSimStateSideEffectsInfo", c3_u, 20)), "setSimStateSideEffectsInfo"),
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
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_clock, 15U, 1U, 0U,
                        *chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Pos_y, 14U, 1U, 0U,
                        *chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Pos_x, 13U, 1U, 0U,
                        *chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_fcy, 12U, 1U, 0U,
                        *chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Vel_y, 11U, 1U, 0U,
                        *chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Vel_x, 10U, 1U, 0U,
                        *chartInstance->c3_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_fcx, 9U, 1U, 0U,
                        *chartInstance->c3_sfEvent, false);
  *chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, *chartInstance->c3_sfEvent);
  if (*chartInstance->c3_is_active_c3_homing_ldm_aggiornat == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_active_c3_homing_ldm_aggiornat = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_c3_homing_ldm_aggiornat = c3_IN_Homing1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, *chartInstance->c3_sfEvent);
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
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v_sp_x, 7U, 4U, 3U,
                          *chartInstance->c3_sfEvent, false);
    *chartInstance->c3_v_sp_y = 1.2;
    chartInstance->c3_dataWrittenToVector[8U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v_sp_y, 8U, 4U, 3U,
                          *chartInstance->c3_sfEvent, false);
    *chartInstance->c3_ok_x = 1.0;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_x, 17U, 4U, 3U,
                          *chartInstance->c3_sfEvent, false);
    *chartInstance->c3_ok_y = 1.0;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_y, 18U, 4U, 3U,
                          *chartInstance->c3_sfEvent, false);
    *chartInstance->c3_ok_x_2 = 0.0;
    chartInstance->c3_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_x_2, 20U, 4U, 3U,
                          *chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    switch (*chartInstance->c3_is_c3_homing_ldm_aggiornat) {
     case c3_IN_Homing1:
      CV_CHART_EVAL(0, 0, 1);
      c3_Homing1(chartInstance);
      break;

     case c3_IN_Homing2:
      CV_CHART_EVAL(0, 0, 2);
      c3_Homing2(chartInstance);
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
  const mxArray *c3_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_c_x;
  boolean_T guard1 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, *chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_n_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  if (!chartInstance->c3_dataWrittenToVector[14U]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(6U, 5U, 4U, *chartInstance->c3_sfEvent,
      false);
  }

  c3_out = CV_EML_IF(4, 0, 0, CV_RELATIONAL_EVAL(5U, 4U, 0,
    *chartInstance->c3_inizio_traiettoria, 1.0, -1, 0U,
    *chartInstance->c3_inizio_traiettoria == 1.0));
  _SFD_SYMBOL_SCOPE_POP();
  if (c3_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, *chartInstance->c3_sfEvent);
    c3_exit_internal_Homing1(chartInstance);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_c3_homing_ldm_aggiornat = c3_IN_Homing2;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c3_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, *chartInstance->c3_sfEvent);
    *chartInstance->c3_is_Homing2 = c3_IN_Homing_x;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_h_debug_family_names,
      c3_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    *chartInstance->c3_v_sp_x = -2.1;
    chartInstance->c3_dataWrittenToVector[6U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v_sp_x, 7U, 4U, 7U,
                          *chartInstance->c3_sfEvent, false);
    *chartInstance->c3_v_sp_y = 1.2;
    chartInstance->c3_dataWrittenToVector[8U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v_sp_y, 8U, 4U, 7U,
                          *chartInstance->c3_sfEvent, false);
    *chartInstance->c3_ok_x = 1.0;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_x, 17U, 4U, 7U,
                          *chartInstance->c3_sfEvent, false);
    *chartInstance->c3_ok_y = 1.0;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_y, 18U, 4U, 7U,
                          *chartInstance->c3_sfEvent, false);
    *chartInstance->c3_ok_x_2 = 0.0;
    chartInstance->c3_dataWrittenToVector[5U] = true;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_x_2, 20U, 4U, 7U,
                          *chartInstance->c3_sfEvent, false);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, *chartInstance->c3_sfEvent);
    switch (*chartInstance->c3_is_Homing1) {
     case c3_IN_Fine:
      CV_STATE_EVAL(0, 0, 1);
      *chartInstance->c3_ok_y_2 = 0.0;
      chartInstance->c3_dataWrittenToVector[10U] = true;
      *chartInstance->c3_ok_x_2 = 0.0;
      chartInstance->c3_dataWrittenToVector[5U] = true;
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_d_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      *chartInstance->c3_inizio_traiettoria = 1.0;
      chartInstance->c3_dataWrittenToVector[14U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_inizio_traiettoria, 6U, 4U, 1U,
                            *chartInstance->c3_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *chartInstance->c3_sfEvent);
      break;

     case c3_IN_Fine_homing1:
      CV_STATE_EVAL(0, 0, 2);
      *chartInstance->c3_ok_y_2 = 1.0;
      chartInstance->c3_dataWrittenToVector[10U] = true;
      *chartInstance->c3_ok_x_2 = 1.0;
      chartInstance->c3_dataWrittenToVector[5U] = true;
      *chartInstance->c3_ok_x = 0.0;
      chartInstance->c3_dataWrittenToVector[1U] = true;
      *chartInstance->c3_ok_y = 0.0;
      chartInstance->c3_dataWrittenToVector[2U] = true;
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_m_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      if (!chartInstance->c3_dataWrittenToVector[4U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 5U, 1U, *chartInstance->c3_sfEvent,
          false);
      }

      guard1 = false;
      if (CV_EML_COND(1, 0, 0, CV_RELATIONAL_EVAL(5U, 1U, 0,
            *chartInstance->c3_dx, 0.5, -1, 4U, *chartInstance->c3_dx > 0.5))) {
        if (CV_EML_COND(1, 0, 1, CV_RELATIONAL_EVAL(5U, 1U, 1,
              *chartInstance->c3_dy, 0.5, -1, 4U, *chartInstance->c3_dy > 0.5)))
        {
          CV_EML_MCDC(1, 0, 0, true);
          CV_EML_IF(1, 0, 0, true);
          c3_c_out = true;
        } else {
          guard1 = true;
        }
      } else {
        if (!chartInstance->c3_dataWrittenToVector[11U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 5U, 1U,
            *chartInstance->c3_sfEvent, false);
        }

        guard1 = true;
      }

      if (guard1) {
        CV_EML_MCDC(1, 0, 0, false);
        CV_EML_IF(1, 0, 0, false);
        c3_c_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, *chartInstance->c3_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_Homing1 = c3_IN_Fine;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_c_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        *chartInstance->c3_ok_y_2 = 0.0;
        chartInstance->c3_dataWrittenToVector[10U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_y_2, 21U, 4U, 1U,
                              *chartInstance->c3_sfEvent, false);
        *chartInstance->c3_ok_x_2 = 0.0;
        chartInstance->c3_dataWrittenToVector[5U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_x_2, 20U, 4U, 1U,
                              *chartInstance->c3_sfEvent, false);
        *chartInstance->c3_inizio_traiettoria = 0.0;
        chartInstance->c3_dataWrittenToVector[14U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_inizio_traiettoria, 6U, 4U, 1U,
                              *chartInstance->c3_sfEvent, false);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     *chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_b_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_h_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        if (!chartInstance->c3_dataWrittenToVector[6U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 2U,
            *chartInstance->c3_sfEvent, false);
        }

        *chartInstance->c3_Vel_x_out = *chartInstance->c3_v_sp_x -
          *chartInstance->c3_Vel_x;
        chartInstance->c3_dataWrittenToVector[0U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Vel_x_out, 16U, 4U, 2U,
                              *chartInstance->c3_sfEvent, false);
        if (!chartInstance->c3_dataWrittenToVector[12U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 2U,
            *chartInstance->c3_sfEvent, false);
        }

        *chartInstance->c3_dx = *chartInstance->c3_Pos_x - *chartInstance->c3_bx;
        chartInstance->c3_dataWrittenToVector[4U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dx, 4U, 4U, 2U,
                              *chartInstance->c3_sfEvent, false);
        if (!chartInstance->c3_dataWrittenToVector[4U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 2U,
            *chartInstance->c3_sfEvent, false);
        }

        sf_mex_printf("%s =\\n", "dx");
        c3_hoistedGlobal = *chartInstance->c3_dx;
        c3_y = NULL;
        sf_mex_assign(&c3_y, sf_mex_create("y", &c3_hoistedGlobal, 0, 0U, 0U, 0U,
          0), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_y);
        if (!chartInstance->c3_dataWrittenToVector[4U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 2U,
            *chartInstance->c3_sfEvent, false);
        }

        if (CV_EML_IF(2, 1, 0, *chartInstance->c3_dx > 0.5)) {
          *chartInstance->c3_Vel_x_out = 0.0;
          chartInstance->c3_dataWrittenToVector[0U] = true;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Vel_x_out, 16U, 4U, 2U,
                                *chartInstance->c3_sfEvent, false);
        }

        if (!chartInstance->c3_dataWrittenToVector[8U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 2U,
            *chartInstance->c3_sfEvent, false);
        }

        *chartInstance->c3_Vel_y_out = *chartInstance->c3_v_sp_y -
          *chartInstance->c3_Vel_y;
        chartInstance->c3_dataWrittenToVector[3U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Vel_y_out, 19U, 4U, 2U,
                              *chartInstance->c3_sfEvent, false);
        if (!chartInstance->c3_dataWrittenToVector[13U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 2U,
            *chartInstance->c3_sfEvent, false);
        }

        c3_b_hoistedGlobal = *chartInstance->c3_Pos_y;
        c3_c_hoistedGlobal = *chartInstance->c3_by;
        c3_x = c3_b_hoistedGlobal - c3_c_hoistedGlobal;
        c3_b_x = c3_x;
        c3_c_x = c3_b_x;
        *chartInstance->c3_dy = muDoubleScalarAbs(c3_c_x);
        chartInstance->c3_dataWrittenToVector[11U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dy, 5U, 4U, 2U,
                              *chartInstance->c3_sfEvent, false);
        if (!chartInstance->c3_dataWrittenToVector[11U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 4U, 2U,
            *chartInstance->c3_sfEvent, false);
        }

        if (CV_EML_IF(2, 1, 1, *chartInstance->c3_dy > 0.5)) {
          *chartInstance->c3_Vel_y_out = 0.0;
          chartInstance->c3_dataWrittenToVector[3U] = true;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Vel_y_out, 19U, 4U, 2U,
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
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_l_debug_family_names,
        c3_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
        c3_b_sf_marshallIn);
      if (CV_EML_COND(3, 0, 0, CV_RELATIONAL_EVAL(5U, 3U, 0,
            *chartInstance->c3_fcx, 0.0, -1, 0U, *chartInstance->c3_fcx == 0.0))
          && CV_EML_COND(3, 0, 1, CV_RELATIONAL_EVAL(5U, 3U, 1,
            *chartInstance->c3_fcy, 0.0, -1, 0U, *chartInstance->c3_fcy == 0.0)))
      {
        CV_EML_MCDC(3, 0, 0, true);
        CV_EML_IF(3, 0, 0, true);
        c3_b_out = true;
      } else {
        CV_EML_MCDC(3, 0, 0, false);
        CV_EML_IF(3, 0, 0, false);
        c3_b_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c3_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, *chartInstance->c3_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c3_sfEvent);
        *chartInstance->c3_is_Homing1 = c3_IN_Fine_homing1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c3_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_debug_family_names,
          c3_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargin, 0U, c3_sf_marshallOut,
          c3_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_g_nargout, 1U,
          c3_sf_marshallOut, c3_sf_marshallIn);
        *chartInstance->c3_ok_y = 0.0;
        chartInstance->c3_dataWrittenToVector[2U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_y, 18U, 4U, 2U,
                              *chartInstance->c3_sfEvent, false);
        *chartInstance->c3_ok_x = 0.0;
        chartInstance->c3_dataWrittenToVector[1U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_x, 17U, 4U, 2U,
                              *chartInstance->c3_sfEvent, false);
        *chartInstance->c3_bx = *chartInstance->c3_Pos_x;
        chartInstance->c3_dataWrittenToVector[12U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_bx, 2U, 4U, 2U,
                              *chartInstance->c3_sfEvent, false);
        *chartInstance->c3_by = *chartInstance->c3_Pos_y;
        chartInstance->c3_dataWrittenToVector[13U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_by, 3U, 4U, 2U,
                              *chartInstance->c3_sfEvent, false);
        *chartInstance->c3_v_sp_x = 2.1;
        chartInstance->c3_dataWrittenToVector[6U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v_sp_x, 7U, 4U, 2U,
                              *chartInstance->c3_sfEvent, false);
        *chartInstance->c3_v_sp_y = -1.2;
        chartInstance->c3_dataWrittenToVector[8U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v_sp_y, 8U, 4U, 2U,
                              *chartInstance->c3_sfEvent, false);
        *chartInstance->c3_ok_x_2 = 1.0;
        chartInstance->c3_dataWrittenToVector[5U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_x_2, 20U, 4U, 2U,
                              *chartInstance->c3_sfEvent, false);
        *chartInstance->c3_ok_y_2 = 1.0;
        chartInstance->c3_dataWrittenToVector[10U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_y_2, 21U, 4U, 2U,
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
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 3U,
            *chartInstance->c3_sfEvent, false);
        }

        *chartInstance->c3_Vel_x_out = *chartInstance->c3_v_sp_x -
          *chartInstance->c3_Vel_x;
        chartInstance->c3_dataWrittenToVector[0U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Vel_x_out, 16U, 4U, 3U,
                              *chartInstance->c3_sfEvent, false);
        if (!chartInstance->c3_dataWrittenToVector[8U]) {
          _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 3U,
            *chartInstance->c3_sfEvent, false);
        }

        *chartInstance->c3_Vel_y_out = *chartInstance->c3_v_sp_y -
          *chartInstance->c3_Vel_y;
        chartInstance->c3_dataWrittenToVector[3U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Vel_y_out, 19U, 4U, 3U,
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

static void c3_Homing2(SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance)
{
  uint32_T c3_debug_family_var_map[3];
  real_T c3_nargin = 0.0;
  real_T c3_nargout = 1.0;
  real_T c3_b_nargin = 0.0;
  boolean_T c3_out;
  real_T c3_b_nargout = 1.0;
  boolean_T c3_b_out;
  uint32_T c3_b_debug_family_var_map[2];
  real_T c3_c_nargin = 0.0;
  real_T c3_c_nargout = 0.0;
  real_T c3_d_nargin = 0.0;
  real_T c3_e_nargin = 0.0;
  real_T c3_d_nargout = 0.0;
  real_T c3_e_nargout = 0.0;
  real_T c3_f_nargin = 0.0;
  real_T c3_f_nargout = 0.0;
  real_T c3_hoistedGlobal;
  const mxArray *c3_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_c_x;
  boolean_T guard1 = false;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U, *chartInstance->c3_sfEvent);
  switch (*chartInstance->c3_is_Homing2) {
   case c3_IN_Fine:
    CV_STATE_EVAL(4, 0, 1);
    *chartInstance->c3_ok_y_2 = 0.0;
    chartInstance->c3_dataWrittenToVector[10U] = true;
    *chartInstance->c3_ok_x_2 = 0.0;
    chartInstance->c3_dataWrittenToVector[5U] = true;
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, *chartInstance->c3_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Fine_homing1:
    CV_STATE_EVAL(4, 0, 2);
    *chartInstance->c3_ok_y_2 = 1.0;
    chartInstance->c3_dataWrittenToVector[10U] = true;
    *chartInstance->c3_ok_x_2 = 1.0;
    chartInstance->c3_dataWrittenToVector[5U] = true;
    *chartInstance->c3_ok_x = 0.0;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    *chartInstance->c3_ok_y = 0.0;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_o_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (!chartInstance->c3_dataWrittenToVector[4U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 5U, 6U, *chartInstance->c3_sfEvent,
        false);
    }

    guard1 = false;
    if (CV_EML_COND(6, 0, 0, CV_RELATIONAL_EVAL(5U, 6U, 0, *chartInstance->c3_dx,
          0.5, -1, 4U, *chartInstance->c3_dx > 0.5))) {
      if (CV_EML_COND(6, 0, 1, CV_RELATIONAL_EVAL(5U, 6U, 1,
            *chartInstance->c3_dy, 0.5, -1, 4U, *chartInstance->c3_dy > 0.5))) {
        CV_EML_MCDC(6, 0, 0, true);
        CV_EML_IF(6, 0, 0, true);
        c3_b_out = true;
      } else {
        guard1 = true;
      }
    } else {
      if (!chartInstance->c3_dataWrittenToVector[11U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 5U, 6U, *chartInstance->c3_sfEvent,
          false);
      }

      guard1 = true;
    }

    if (guard1) {
      CV_EML_MCDC(6, 0, 0, false);
      CV_EML_IF(6, 0, 0, false);
      c3_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, *chartInstance->c3_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_Homing2 = c3_IN_Fine;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_g_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_f_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      *chartInstance->c3_ok_y_2 = 0.0;
      chartInstance->c3_dataWrittenToVector[10U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_y_2, 21U, 4U, 5U,
                            *chartInstance->c3_sfEvent, false);
      *chartInstance->c3_ok_x_2 = 0.0;
      chartInstance->c3_dataWrittenToVector[5U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_x_2, 20U, 4U, 5U,
                            *chartInstance->c3_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                   *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_k_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_e_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      if (!chartInstance->c3_dataWrittenToVector[6U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 6U, *chartInstance->c3_sfEvent,
          false);
      }

      *chartInstance->c3_Vel_x_out = *chartInstance->c3_v_sp_x -
        *chartInstance->c3_Vel_x;
      chartInstance->c3_dataWrittenToVector[0U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Vel_x_out, 16U, 4U, 6U,
                            *chartInstance->c3_sfEvent, false);
      if (!chartInstance->c3_dataWrittenToVector[12U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(2U, 4U, 6U, *chartInstance->c3_sfEvent,
          false);
      }

      *chartInstance->c3_dx = *chartInstance->c3_Pos_x - *chartInstance->c3_bx;
      chartInstance->c3_dataWrittenToVector[4U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dx, 4U, 4U, 6U,
                            *chartInstance->c3_sfEvent, false);
      if (!chartInstance->c3_dataWrittenToVector[4U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 6U, *chartInstance->c3_sfEvent,
          false);
      }

      sf_mex_printf("%s =\\n", "dx");
      c3_hoistedGlobal = *chartInstance->c3_dx;
      c3_y = NULL;
      sf_mex_assign(&c3_y, sf_mex_create("y", &c3_hoistedGlobal, 0, 0U, 0U, 0U,
        0), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c3_y);
      if (!chartInstance->c3_dataWrittenToVector[4U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(4U, 4U, 6U, *chartInstance->c3_sfEvent,
          false);
      }

      if (CV_EML_IF(6, 1, 0, *chartInstance->c3_dx > 0.5)) {
        *chartInstance->c3_Vel_x_out = 0.0;
        chartInstance->c3_dataWrittenToVector[0U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Vel_x_out, 16U, 4U, 6U,
                              *chartInstance->c3_sfEvent, false);
      }

      if (!chartInstance->c3_dataWrittenToVector[8U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 6U, *chartInstance->c3_sfEvent,
          false);
      }

      *chartInstance->c3_Vel_y_out = *chartInstance->c3_v_sp_y -
        *chartInstance->c3_Vel_y;
      chartInstance->c3_dataWrittenToVector[3U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Vel_y_out, 19U, 4U, 6U,
                            *chartInstance->c3_sfEvent, false);
      if (!chartInstance->c3_dataWrittenToVector[13U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(3U, 4U, 6U, *chartInstance->c3_sfEvent,
          false);
      }

      c3_b_hoistedGlobal = *chartInstance->c3_Pos_y;
      c3_c_hoistedGlobal = *chartInstance->c3_by;
      c3_x = c3_b_hoistedGlobal - c3_c_hoistedGlobal;
      c3_b_x = c3_x;
      c3_c_x = c3_b_x;
      *chartInstance->c3_dy = muDoubleScalarAbs(c3_c_x);
      chartInstance->c3_dataWrittenToVector[11U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_dy, 5U, 4U, 6U,
                            *chartInstance->c3_sfEvent, false);
      if (!chartInstance->c3_dataWrittenToVector[11U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(5U, 4U, 6U, *chartInstance->c3_sfEvent,
          false);
      }

      if (CV_EML_IF(6, 1, 1, *chartInstance->c3_dy > 0.5)) {
        *chartInstance->c3_Vel_y_out = 0.0;
        chartInstance->c3_dataWrittenToVector[3U] = true;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Vel_y_out, 19U, 4U, 6U,
                              *chartInstance->c3_sfEvent, false);
      }

      _SFD_SYMBOL_SCOPE_POP();
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, *chartInstance->c3_sfEvent);
    break;

   case c3_IN_Homing_x:
    CV_STATE_EVAL(4, 0, 3);
    *chartInstance->c3_ok_x_2 = 0.0;
    chartInstance->c3_dataWrittenToVector[5U] = true;
    *chartInstance->c3_ok_x = 1.0;
    chartInstance->c3_dataWrittenToVector[1U] = true;
    *chartInstance->c3_ok_y = 1.0;
    chartInstance->c3_dataWrittenToVector[2U] = true;
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                 *chartInstance->c3_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c3_p_debug_family_names,
      c3_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
      c3_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_out, 2U, c3_b_sf_marshallOut,
      c3_b_sf_marshallIn);
    if (CV_EML_COND(7, 0, 0, CV_RELATIONAL_EVAL(5U, 7U, 0,
          *chartInstance->c3_fcx, 0.0, -1, 0U, *chartInstance->c3_fcx == 0.0)) &&
        CV_EML_COND(7, 0, 1, CV_RELATIONAL_EVAL(5U, 7U, 1,
          *chartInstance->c3_fcy, 0.0, -1, 0U, *chartInstance->c3_fcy == 0.0)))
    {
      CV_EML_MCDC(7, 0, 0, true);
      CV_EML_IF(7, 0, 0, true);
      c3_out = true;
    } else {
      CV_EML_MCDC(7, 0, 0, false);
      CV_EML_IF(7, 0, 0, false);
      c3_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c3_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, *chartInstance->c3_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, *chartInstance->c3_sfEvent);
      *chartInstance->c3_is_Homing2 = c3_IN_Fine_homing1;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_j_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_d_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      *chartInstance->c3_ok_y = 0.0;
      chartInstance->c3_dataWrittenToVector[2U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_y, 18U, 4U, 6U,
                            *chartInstance->c3_sfEvent, false);
      *chartInstance->c3_ok_x = 0.0;
      chartInstance->c3_dataWrittenToVector[1U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_x, 17U, 4U, 6U,
                            *chartInstance->c3_sfEvent, false);
      *chartInstance->c3_bx = *chartInstance->c3_Pos_x;
      chartInstance->c3_dataWrittenToVector[12U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_bx, 2U, 4U, 6U,
                            *chartInstance->c3_sfEvent, false);
      *chartInstance->c3_by = *chartInstance->c3_Pos_y;
      chartInstance->c3_dataWrittenToVector[13U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_by, 3U, 4U, 6U,
                            *chartInstance->c3_sfEvent, false);
      *chartInstance->c3_v_sp_x = 2.1;
      chartInstance->c3_dataWrittenToVector[6U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v_sp_x, 7U, 4U, 6U,
                            *chartInstance->c3_sfEvent, false);
      *chartInstance->c3_v_sp_y = -1.2;
      chartInstance->c3_dataWrittenToVector[8U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_v_sp_y, 8U, 4U, 6U,
                            *chartInstance->c3_sfEvent, false);
      *chartInstance->c3_ok_x_2 = 1.0;
      chartInstance->c3_dataWrittenToVector[5U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_x_2, 20U, 4U, 6U,
                            *chartInstance->c3_sfEvent, false);
      *chartInstance->c3_ok_y_2 = 1.0;
      chartInstance->c3_dataWrittenToVector[10U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ok_y_2, 21U, 4U, 6U,
                            *chartInstance->c3_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                   *chartInstance->c3_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c3_i_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargin, 0U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_c_nargout, 1U, c3_sf_marshallOut,
        c3_sf_marshallIn);
      if (!chartInstance->c3_dataWrittenToVector[6U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(7U, 4U, 7U, *chartInstance->c3_sfEvent,
          false);
      }

      *chartInstance->c3_Vel_x_out = *chartInstance->c3_v_sp_x -
        *chartInstance->c3_Vel_x;
      chartInstance->c3_dataWrittenToVector[0U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Vel_x_out, 16U, 4U, 7U,
                            *chartInstance->c3_sfEvent, false);
      if (!chartInstance->c3_dataWrittenToVector[8U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(8U, 4U, 7U, *chartInstance->c3_sfEvent,
          false);
      }

      *chartInstance->c3_Vel_y_out = *chartInstance->c3_v_sp_y -
        *chartInstance->c3_Vel_y;
      chartInstance->c3_dataWrittenToVector[3U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c3_Vel_y_out, 19U, 4U, 7U,
                            *chartInstance->c3_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, *chartInstance->c3_sfEvent);
    break;

   default:
    CV_STATE_EVAL(4, 0, 0);

    /* Unreachable state, for coverage only */
    *chartInstance->c3_is_Homing2 = c3_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c3_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, *chartInstance->c3_sfEvent);
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
  const mxArray *c3_y = NULL;
  SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance;
  chartInstance = (SFc3_homing_ldm_aggiornatInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_nargout, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance;
  chartInstance = (SFc3_homing_ldm_aggiornatInstanceStruct *)chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance;
  chartInstance = (SFc3_homing_ldm_aggiornatInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static boolean_T c3_c_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b0, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sf_internal_predicateOutput;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance;
  chartInstance = (SFc3_homing_ldm_aggiornatInstanceStruct *)chartInstanceVoid;
  c3_sf_internal_predicateOutput = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_sf_internal_predicateOutput), &c3_thisId);
  sf_mex_destroy(&c3_sf_internal_predicateOutput);
  *(boolean_T *)c3_outData = c3_y;
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

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance;
  chartInstance = (SFc3_homing_ldm_aggiornatInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_d_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i1;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i1, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i1;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance;
  chartInstance = (SFc3_homing_ldm_aggiornatInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  uint8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance;
  chartInstance = (SFc3_homing_ldm_aggiornatInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint8_T c3_e_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_b_is_Homing1, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_is_Homing1),
    &c3_thisId);
  sf_mex_destroy(&c3_b_is_Homing1);
  return c3_y;
}

static uint8_T c3_f_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_is_Homing1;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance;
  chartInstance = (SFc3_homing_ldm_aggiornatInstanceStruct *)chartInstanceVoid;
  c3_b_is_Homing1 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_is_Homing1),
    &c3_thisId);
  sf_mex_destroy(&c3_b_is_Homing1);
  *(uint8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static void c3_g_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_b_dataWrittenToVector, const char_T
  *c3_identifier, boolean_T c3_y[15])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_dataWrittenToVector),
                        &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_dataWrittenToVector);
}

static void c3_h_emlrt_marshallIn(SFc3_homing_ldm_aggiornatInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T c3_y[15])
{
  boolean_T c3_bv1[15];
  int32_T c3_i2;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_bv1, 1, 11, 0U, 1, 0U, 1, 15);
  for (c3_i2 = 0; c3_i2 < 15; c3_i2++) {
    c3_y[c3_i2] = c3_bv1[c3_i2];
  }

  sf_mex_destroy(&c3_u);
}

static const mxArray *c3_i_emlrt_marshallIn
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance, const mxArray
   *c3_b_setSimStateSideEffectsInfo, const char_T *c3_identifier)
{
  const mxArray *c3_y = NULL;
  emlrtMsgIdentifier c3_thisId;
  c3_y = NULL;
  c3_thisId.fIdentifier = (const char *)c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  sf_mex_assign(&c3_y, c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_setSimStateSideEffectsInfo), &c3_thisId), false);
  sf_mex_destroy(&c3_b_setSimStateSideEffectsInfo);
  return c3_y;
}

static const mxArray *c3_j_emlrt_marshallIn
  (SFc3_homing_ldm_aggiornatInstanceStruct *chartInstance, const mxArray *c3_u,
   const emlrtMsgIdentifier *c3_parentId)
{
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  (void)c3_parentId;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_duplicatearraysafe(&c3_u), false);
  sf_mex_destroy(&c3_u);
  return c3_y;
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
  chartInstance->c3_is_Homing1 = (uint8_T *)ssGetDWork_wrapper(chartInstance->S,
    3);
  chartInstance->c3_is_Homing2 = (uint8_T *)ssGetDWork_wrapper(chartInstance->S,
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
  chartInstance->c3_a = (real_T *)ssGetDWork_wrapper(chartInstance->S, 7);
  chartInstance->c3_v_sp_y = (real_T *)ssGetDWork_wrapper(chartInstance->S, 8);
  chartInstance->c3_ay = (real_T *)ssGetDWork_wrapper(chartInstance->S, 9);
  chartInstance->c3_Pos_y = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c3_ok_y_2 = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c3_dy = (real_T *)ssGetDWork_wrapper(chartInstance->S, 10);
  chartInstance->c3_clock = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c3_bx = (real_T *)ssGetDWork_wrapper(chartInstance->S, 11);
  chartInstance->c3_by = (real_T *)ssGetDWork_wrapper(chartInstance->S, 12);
  chartInstance->c3_inizio_traiettoria = (real_T *)ssGetDWork_wrapper
    (chartInstance->S, 13);
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
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(495442685U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(357525523U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4104649908U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2856970746U);
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
    mxArray *mxChecksum = mxCreateString("FelysglIaIzftqJPPH74SF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,9,3,dataFields);

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
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[16],T\"Vel_x_out\",},{M[1],M[55],T\"Vel_y_out\",},{M[1],M[52],T\"ok_x\",},{M[1],M[79],T\"ok_x_2\",},{M[1],M[53],T\"ok_y\",},{M[1],M[90],T\"ok_y_2\",},{M[3],M[84],T\"a\",},{M[3],M[88],T\"ay\",},{M[3],M[176],T\"bx\",},{M[3],M[177],T\"by\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[3],M[80],T\"dx\",},{M[3],M[91],T\"dy\",},{M[3],M[178],T\"inizio_traiettoria\",},{M[3],M[81],T\"v_sp_x\",},{M[3],M[87],T\"v_sp_y\",},{M[8],M[0],T\"is_active_c3_homing_ldm_aggiornat\",},{M[9],M[0],T\"is_c3_homing_ldm_aggiornat\",},{M[9],M[144],T\"is_Homing1\",},{M[9],M[165],T\"is_Homing2\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 20, 10);
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
           8,
           0,
           22,
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
          _SFD_SET_DATA_PROPS(0,0,0,0,"a");
          _SFD_SET_DATA_PROPS(1,0,0,0,"ay");
          _SFD_SET_DATA_PROPS(2,0,0,0,"bx");
          _SFD_SET_DATA_PROPS(3,0,0,0,"by");
          _SFD_SET_DATA_PROPS(4,0,0,0,"dx");
          _SFD_SET_DATA_PROPS(5,0,0,0,"dy");
          _SFD_SET_DATA_PROPS(6,0,0,0,"inizio_traiettoria");
          _SFD_SET_DATA_PROPS(7,0,0,0,"v_sp_x");
          _SFD_SET_DATA_PROPS(8,0,0,0,"v_sp_y");
          _SFD_SET_DATA_PROPS(9,1,1,0,"fcx");
          _SFD_SET_DATA_PROPS(10,1,1,0,"Vel_x");
          _SFD_SET_DATA_PROPS(11,1,1,0,"Vel_y");
          _SFD_SET_DATA_PROPS(12,1,1,0,"fcy");
          _SFD_SET_DATA_PROPS(13,1,1,0,"Pos_x");
          _SFD_SET_DATA_PROPS(14,1,1,0,"Pos_y");
          _SFD_SET_DATA_PROPS(15,1,1,0,"clock");
          _SFD_SET_DATA_PROPS(16,2,0,1,"Vel_x_out");
          _SFD_SET_DATA_PROPS(17,2,0,1,"ok_x");
          _SFD_SET_DATA_PROPS(18,2,0,1,"ok_y");
          _SFD_SET_DATA_PROPS(19,2,0,1,"Vel_y_out");
          _SFD_SET_DATA_PROPS(20,2,0,1,"ok_x_2");
          _SFD_SET_DATA_PROPS(21,2,0,1,"ok_y_2");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
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
          _SFD_ST_SUBSTATE_COUNT(4,3);
          _SFD_ST_SUBSTATE_INDEX(4,0,5);
          _SFD_ST_SUBSTATE_INDEX(4,1,6);
          _SFD_ST_SUBSTATE_INDEX(4,2,7);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
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
          _SFD_CV_INIT_STATE(4,3,1,0,0,0,NULL,NULL);
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

        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(2,1,0,0,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,1,0,145,155,-1,178);
        _SFD_CV_INIT_EML_IF(2,1,1,221,231,-1,254);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,1,0,0,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,1,0,145,155,-1,178);
        _SFD_CV_INIT_EML_IF(6,1,1,221,231,-1,254);
        _SFD_CV_INIT_EML(3,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(3,0,0,1,17,1,17);

        {
          static int condStart[] = { 1, 11 };

          static int condEnd[] = { 7, 17 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(3,0,0,1,17,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(3,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(3,0,1,11,17,-1,0);
        _SFD_CV_INIT_EML(1,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(1,0,0,1,17,1,17);

        {
          static int condStart[] = { 1, 11 };

          static int condEnd[] = { 7, 17 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(1,0,0,1,17,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(1,0,0,1,7,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(1,0,1,11,17,-1,4);
        _SFD_CV_INIT_EML(4,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,22,1,22);
        _SFD_CV_INIT_EML_RELATIONAL(4,0,0,1,22,-1,0);
        _SFD_CV_INIT_EML(6,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(6,0,0,1,17,1,17);

        {
          static int condStart[] = { 1, 11 };

          static int condEnd[] = { 7, 17 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(6,0,0,1,17,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(6,0,0,1,7,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(6,0,1,11,17,-1,4);
        _SFD_CV_INIT_EML(7,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(7,0,0,1,17,1,17);

        {
          static int condStart[] = { 1, 11 };

          static int condEnd[] = { 7, 17 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(7,0,0,1,17,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(7,0,0,1,7,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(7,0,1,11,17,-1,0);
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
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
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
        _SFD_SET_DATA_VALUE_PTR(9U, (void *)chartInstance->c3_fcx);
        _SFD_SET_DATA_VALUE_PTR(16U, (void *)chartInstance->c3_Vel_x_out);
        _SFD_SET_DATA_VALUE_PTR(10U, (void *)chartInstance->c3_Vel_x);
        _SFD_SET_DATA_VALUE_PTR(17U, (void *)chartInstance->c3_ok_x);
        _SFD_SET_DATA_VALUE_PTR(18U, (void *)chartInstance->c3_ok_y);
        _SFD_SET_DATA_VALUE_PTR(11U, (void *)chartInstance->c3_Vel_y);
        _SFD_SET_DATA_VALUE_PTR(19U, (void *)chartInstance->c3_Vel_y_out);
        _SFD_SET_DATA_VALUE_PTR(12U, (void *)chartInstance->c3_fcy);
        _SFD_SET_DATA_VALUE_PTR(13U, (void *)chartInstance->c3_Pos_x);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)chartInstance->c3_dx);
        _SFD_SET_DATA_VALUE_PTR(20U, (void *)chartInstance->c3_ok_x_2);
        _SFD_SET_DATA_VALUE_PTR(7U, (void *)chartInstance->c3_v_sp_x);
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c3_a);
        _SFD_SET_DATA_VALUE_PTR(8U, (void *)chartInstance->c3_v_sp_y);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c3_ay);
        _SFD_SET_DATA_VALUE_PTR(14U, (void *)chartInstance->c3_Pos_y);
        _SFD_SET_DATA_VALUE_PTR(21U, (void *)chartInstance->c3_ok_y_2);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)chartInstance->c3_dy);
        _SFD_SET_DATA_VALUE_PTR(15U, (void *)chartInstance->c3_clock);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c3_bx);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c3_by);
        _SFD_SET_DATA_VALUE_PTR(6U, (void *)chartInstance->c3_inizio_traiettoria);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "s5Jjjeo1r1CTkljNkfTtSKE";
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
    "100 S1x4'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size','local_queue_dwork_idx','local_queue_id'{{T\"double\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1]},{T\"double\",,,,,,,M[0],M[],M[-1],M[-1]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 14, 10);
}

static uint32_T* sf_get_sfun_dwork_checksum()
{
  static uint32_T checksum[4] = { 1264693026U, 1034639115U, 2784939780U,
    4095230318U };

  return checksum;
}

static void mdlSetWorkWidths_c3_homing_ldm_aggiornat(SimStruct *S)
{
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,7);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,6);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=6; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 7; ++inPortIdx) {
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
  ssSetChecksum0(S,(752205061U));
  ssSetChecksum1(S,(1901355699U));
  ssSetChecksum2(S,(2296671913U));
  ssSetChecksum3(S,(1641003077U));
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