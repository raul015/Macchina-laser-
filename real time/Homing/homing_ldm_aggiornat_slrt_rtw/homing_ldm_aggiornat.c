/*
 * homing_ldm_aggiornat.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "homing_ldm_aggiornat".
 *
 * Model version              : 1.44
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Wed Nov 24 17:41:39 2021
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "homing_ldm_aggiornat_capi.h"
#include "homing_ldm_aggiornat.h"
#include "homing_ldm_aggiornat_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define homing_ldm_a_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define homing_ldm_aggi_IN_Fine_homing1 ((uint8_T)2U)
#define homing_ldm_aggiorna_IN_Homing_x ((uint8_T)3U)
#define homing_ldm_aggiornat_CALL_EVENT (-1)
#define homing_ldm_aggiornat_IN_Fine   ((uint8_T)1U)
#define homing_ldm_aggiornat_IN_Homing1 ((uint8_T)1U)
#define homing_ldm_aggiornat_IN_Homing2 ((uint8_T)2U)

/* Block signals (auto storage) */
B_homing_ldm_aggiornat_T homing_ldm_aggiornat_B;

/* Block states (auto storage) */
DW_homing_ldm_aggiornat_T homing_ldm_aggiornat_DW;

/* Real-time model */
RT_MODEL_homing_ldm_aggiornat_T homing_ldm_aggiornat_M_;
RT_MODEL_homing_ldm_aggiornat_T *const homing_ldm_aggiornat_M =
  &homing_ldm_aggiornat_M_;

/* Model output function */
static void homing_ldm_aggiornat_output(void)
{
  boolean_T sf_internal_predicateOutput;
  real_T tmp;
  real_T tmp_0;

  /* S-Function (dinipcim): '<Root>/PCI-6229 DI' */

  /* Level2 S-Function Block: '<Root>/PCI-6229 DI' (dinipcim) */
  {
    SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[0];
    sfcnOutputs(rts,1);
  }

  /* S-Function (encnipcim): '<Root>/PCI 6229 ENC 7' */

  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 7' (encnipcim) */
  {
    SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[1];
    sfcnOutputs(rts,1);
  }

  /* Gain: '<Root>/Gain13' */
  homing_ldm_aggiornat_B.posizionecarrellox_n =
    homing_ldm_aggiornat_P.Gain13_Gain *
    homing_ldm_aggiornat_B.posizionecarrellox;

  /* S-Function (encnipcim): '<Root>/PCI 6229 ENC 6' */

  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 6' (encnipcim) */
  {
    SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[2];
    sfcnOutputs(rts,1);
  }

  /* Gain: '<Root>/Gain11' */
  homing_ldm_aggiornat_B.posizionecarrelloy_e =
    homing_ldm_aggiornat_P.Gain11_Gain *
    homing_ldm_aggiornat_B.posizionecarrelloy;

  /* SampleTimeMath: '<S3>/TSamp'
   *
   * About '<S3>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  homing_ldm_aggiornat_B.TSamp = homing_ldm_aggiornat_B.posizionecarrelloy_e *
    homing_ldm_aggiornat_P.TSamp_WtEt;

  /* UnitDelay: '<S3>/UD' */
  homing_ldm_aggiornat_B.Uk1 = homing_ldm_aggiornat_DW.UD_DSTATE;

  /* Sum: '<S3>/Diff' */
  homing_ldm_aggiornat_B.Diff = homing_ldm_aggiornat_B.TSamp -
    homing_ldm_aggiornat_B.Uk1;

  /* SampleTimeMath: '<S5>/TSamp'
   *
   * About '<S5>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  homing_ldm_aggiornat_B.TSamp_b = homing_ldm_aggiornat_B.posizionecarrellox_n *
    homing_ldm_aggiornat_P.TSamp_WtEt_h;

  /* UnitDelay: '<S5>/UD' */
  homing_ldm_aggiornat_B.Uk1_a = homing_ldm_aggiornat_DW.UD_DSTATE_p;

  /* Sum: '<S5>/Diff' */
  homing_ldm_aggiornat_B.Diff_k = homing_ldm_aggiornat_B.TSamp_b -
    homing_ldm_aggiornat_B.Uk1_a;

  /* Clock: '<Root>/Clock' */
  homing_ldm_aggiornat_B.Clock = homing_ldm_aggiornat_M->Timing.t[0];

  /* Chart: '<Root>/Chart' */
  /* Gateway: Chart */
  homing_ldm_aggiornat_DW.sfEvent = homing_ldm_aggiornat_CALL_EVENT;

  /* During: Chart */
  if (homing_ldm_aggiornat_DW.is_active_c3_homing_ldm_aggiorn == 0U) {
    /* Entry: Chart */
    homing_ldm_aggiornat_DW.is_active_c3_homing_ldm_aggiorn = 1U;

    /* Entry Internal: Chart */
    /* Transition: '<S1>:148' */
    homing_ldm_aggiornat_DW.is_c3_homing_ldm_aggiornat =
      homing_ldm_aggiornat_IN_Homing1;

    /* Entry Internal 'Homing1': '<S1>:144' */
    /* Transition: '<S1>:146' */
    homing_ldm_aggiornat_DW.is_Homing1 = homing_ldm_aggiorna_IN_Homing_x;

    /* Entry 'Homing_x': '<S1>:150' */
    homing_ldm_aggiornat_DW.v_sp_x = -2.1;
    homing_ldm_aggiornat_DW.v_sp_y = 1.2;
    homing_ldm_aggiornat_B.ok_x = 1.0;
    homing_ldm_aggiornat_B.ok_y = 1.0;
    homing_ldm_aggiornat_B.ok_x_2 = 0.0;
  } else if (homing_ldm_aggiornat_DW.is_c3_homing_ldm_aggiornat ==
             homing_ldm_aggiornat_IN_Homing1) {
    /* During 'Homing1': '<S1>:144' */
    if (homing_ldm_aggiornat_DW.inizio_traiettoria == 1.0) {
      /* Transition: '<S1>:166' */
      /* Exit Internal 'Homing1': '<S1>:144' */
      homing_ldm_aggiornat_DW.is_Homing1 = homing_ldm_a_IN_NO_ACTIVE_CHILD;
      homing_ldm_aggiornat_DW.is_c3_homing_ldm_aggiornat =
        homing_ldm_aggiornat_IN_Homing2;

      /* Entry Internal 'Homing2': '<S1>:165' */
      /* Transition: '<S1>:167' */
      homing_ldm_aggiornat_DW.is_Homing2 = homing_ldm_aggiorna_IN_Homing_x;

      /* Entry 'Homing_x': '<S1>:170' */
      homing_ldm_aggiornat_DW.v_sp_x = -2.1;
      homing_ldm_aggiornat_DW.v_sp_y = 1.2;
      homing_ldm_aggiornat_B.ok_x = 1.0;
      homing_ldm_aggiornat_B.ok_y = 1.0;
      homing_ldm_aggiornat_B.ok_x_2 = 0.0;
    } else {
      switch (homing_ldm_aggiornat_DW.is_Homing1) {
       case homing_ldm_aggiornat_IN_Fine:
        homing_ldm_aggiornat_B.ok_y_2 = 0.0;
        homing_ldm_aggiornat_B.ok_x_2 = 0.0;

        /* During 'Fine': '<S1>:149' */
        homing_ldm_aggiornat_DW.inizio_traiettoria = 1.0;
        break;

       case homing_ldm_aggi_IN_Fine_homing1:
        homing_ldm_aggiornat_B.ok_y_2 = 1.0;
        homing_ldm_aggiornat_B.ok_x_2 = 1.0;
        homing_ldm_aggiornat_B.ok_x = 0.0;
        homing_ldm_aggiornat_B.ok_y = 0.0;

        /* During 'Fine_homing1': '<S1>:145' */
        sf_internal_predicateOutput = ((homing_ldm_aggiornat_DW.dx > 0.5) &&
          (homing_ldm_aggiornat_DW.dy > 0.5));
        if (sf_internal_predicateOutput) {
          /* Transition: '<S1>:147' */
          homing_ldm_aggiornat_DW.is_Homing1 = homing_ldm_aggiornat_IN_Fine;

          /* Entry 'Fine': '<S1>:149' */
          homing_ldm_aggiornat_B.ok_y_2 = 0.0;
          homing_ldm_aggiornat_B.ok_x_2 = 0.0;
          homing_ldm_aggiornat_DW.inizio_traiettoria = 0.0;
        } else {
          homing_ldm_aggiornat_B.Vel_x_out = homing_ldm_aggiornat_DW.v_sp_x -
            homing_ldm_aggiornat_B.Diff_k;
          homing_ldm_aggiornat_DW.dx =
            homing_ldm_aggiornat_B.posizionecarrellox_n -
            homing_ldm_aggiornat_DW.bx;
          if (homing_ldm_aggiornat_DW.dx > 0.5) {
            homing_ldm_aggiornat_B.Vel_x_out = 0.0;
          }

          homing_ldm_aggiornat_B.Vel_y_out = homing_ldm_aggiornat_DW.v_sp_y -
            homing_ldm_aggiornat_B.Diff;
          homing_ldm_aggiornat_DW.dy = fabs
            (homing_ldm_aggiornat_B.posizionecarrelloy_e -
             homing_ldm_aggiornat_DW.by);
          if (homing_ldm_aggiornat_DW.dy > 0.5) {
            homing_ldm_aggiornat_B.Vel_y_out = 0.0;
          }
        }
        break;

       default:
        homing_ldm_aggiornat_B.ok_x_2 = 0.0;
        homing_ldm_aggiornat_B.ok_x = 1.0;
        homing_ldm_aggiornat_B.ok_y = 1.0;

        /* During 'Homing_x': '<S1>:150' */
        sf_internal_predicateOutput = ((homing_ldm_aggiornat_B.fcxsx == 0.0) &&
          (homing_ldm_aggiornat_B.fcydown == 0.0));
        if (sf_internal_predicateOutput) {
          /* Transition: '<S1>:155' */
          homing_ldm_aggiornat_DW.is_Homing1 = homing_ldm_aggi_IN_Fine_homing1;

          /* Entry 'Fine_homing1': '<S1>:145' */
          homing_ldm_aggiornat_B.ok_y = 0.0;
          homing_ldm_aggiornat_B.ok_x = 0.0;
          homing_ldm_aggiornat_DW.bx =
            homing_ldm_aggiornat_B.posizionecarrellox_n;
          homing_ldm_aggiornat_DW.by =
            homing_ldm_aggiornat_B.posizionecarrelloy_e;
          homing_ldm_aggiornat_DW.v_sp_x = 2.1;
          homing_ldm_aggiornat_DW.v_sp_y = -1.2;
          homing_ldm_aggiornat_B.ok_x_2 = 1.0;
          homing_ldm_aggiornat_B.ok_y_2 = 1.0;
        } else {
          homing_ldm_aggiornat_B.Vel_x_out = homing_ldm_aggiornat_DW.v_sp_x -
            homing_ldm_aggiornat_B.Diff_k;
          homing_ldm_aggiornat_B.Vel_y_out = homing_ldm_aggiornat_DW.v_sp_y -
            homing_ldm_aggiornat_B.Diff;
        }
        break;
      }
    }
  } else {
    /* During 'Homing2': '<S1>:165' */
    switch (homing_ldm_aggiornat_DW.is_Homing2) {
     case homing_ldm_aggiornat_IN_Fine:
      homing_ldm_aggiornat_B.ok_y_2 = 0.0;
      homing_ldm_aggiornat_B.ok_x_2 = 0.0;

      /* During 'Fine': '<S1>:168' */
      break;

     case homing_ldm_aggi_IN_Fine_homing1:
      homing_ldm_aggiornat_B.ok_y_2 = 1.0;
      homing_ldm_aggiornat_B.ok_x_2 = 1.0;
      homing_ldm_aggiornat_B.ok_x = 0.0;
      homing_ldm_aggiornat_B.ok_y = 0.0;

      /* During 'Fine_homing1': '<S1>:172' */
      sf_internal_predicateOutput = ((homing_ldm_aggiornat_DW.dx > 0.5) &&
        (homing_ldm_aggiornat_DW.dy > 0.5));
      if (sf_internal_predicateOutput) {
        /* Transition: '<S1>:173' */
        homing_ldm_aggiornat_DW.is_Homing2 = homing_ldm_aggiornat_IN_Fine;

        /* Entry 'Fine': '<S1>:168' */
        homing_ldm_aggiornat_B.ok_y_2 = 0.0;
        homing_ldm_aggiornat_B.ok_x_2 = 0.0;
      } else {
        homing_ldm_aggiornat_B.Vel_x_out = homing_ldm_aggiornat_DW.v_sp_x -
          homing_ldm_aggiornat_B.Diff_k;
        homing_ldm_aggiornat_DW.dx = homing_ldm_aggiornat_B.posizionecarrellox_n
          - homing_ldm_aggiornat_DW.bx;
        if (homing_ldm_aggiornat_DW.dx > 0.5) {
          homing_ldm_aggiornat_B.Vel_x_out = 0.0;
        }

        homing_ldm_aggiornat_B.Vel_y_out = homing_ldm_aggiornat_DW.v_sp_y -
          homing_ldm_aggiornat_B.Diff;
        homing_ldm_aggiornat_DW.dy = fabs
          (homing_ldm_aggiornat_B.posizionecarrelloy_e -
           homing_ldm_aggiornat_DW.by);
        if (homing_ldm_aggiornat_DW.dy > 0.5) {
          homing_ldm_aggiornat_B.Vel_y_out = 0.0;
        }
      }
      break;

     default:
      homing_ldm_aggiornat_B.ok_x_2 = 0.0;
      homing_ldm_aggiornat_B.ok_x = 1.0;
      homing_ldm_aggiornat_B.ok_y = 1.0;

      /* During 'Homing_x': '<S1>:170' */
      sf_internal_predicateOutput = ((homing_ldm_aggiornat_B.fcxsx == 0.0) &&
        (homing_ldm_aggiornat_B.fcydown == 0.0));
      if (sf_internal_predicateOutput) {
        /* Transition: '<S1>:175' */
        homing_ldm_aggiornat_DW.is_Homing2 = homing_ldm_aggi_IN_Fine_homing1;

        /* Entry 'Fine_homing1': '<S1>:172' */
        homing_ldm_aggiornat_B.ok_y = 0.0;
        homing_ldm_aggiornat_B.ok_x = 0.0;
        homing_ldm_aggiornat_DW.bx = homing_ldm_aggiornat_B.posizionecarrellox_n;
        homing_ldm_aggiornat_DW.by = homing_ldm_aggiornat_B.posizionecarrelloy_e;
        homing_ldm_aggiornat_DW.v_sp_x = 2.1;
        homing_ldm_aggiornat_DW.v_sp_y = -1.2;
        homing_ldm_aggiornat_B.ok_x_2 = 1.0;
        homing_ldm_aggiornat_B.ok_y_2 = 1.0;
      } else {
        homing_ldm_aggiornat_B.Vel_x_out = homing_ldm_aggiornat_DW.v_sp_x -
          homing_ldm_aggiornat_B.Diff_k;
        homing_ldm_aggiornat_B.Vel_y_out = homing_ldm_aggiornat_DW.v_sp_y -
          homing_ldm_aggiornat_B.Diff;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* Gain: '<Root>/Gain1' */
  homing_ldm_aggiornat_B.Gain1 = homing_ldm_aggiornat_P.Gain1_Gain *
    homing_ldm_aggiornat_B.Vel_x_out;

  /* Gain: '<Root>/Gain2' */
  homing_ldm_aggiornat_B.Gain2 = homing_ldm_aggiornat_P.Gain2_Gain *
    homing_ldm_aggiornat_B.Vel_y_out;

  /* Gain: '<Root>/Gain3' */
  homing_ldm_aggiornat_B.Gain3 = homing_ldm_aggiornat_P.Gain3_Gain *
    homing_ldm_aggiornat_B.Vel_x_out;

  /* DotProduct: '<Root>/Dot Product1' */
  tmp = homing_ldm_aggiornat_B.Gain1;
  tmp_0 = homing_ldm_aggiornat_B.ok_x;
  homing_ldm_aggiornat_B.DotProduct1 = tmp * tmp_0;

  /* DotProduct: '<Root>/Dot Product7' */
  tmp = homing_ldm_aggiornat_B.Gain3;
  tmp_0 = homing_ldm_aggiornat_B.ok_x_2;
  homing_ldm_aggiornat_B.DotProduct7 = tmp * tmp_0;

  /* Sum: '<Root>/Sum1' */
  homing_ldm_aggiornat_B.Sum1 = homing_ldm_aggiornat_B.DotProduct1 +
    homing_ldm_aggiornat_B.DotProduct7;

  /* S-Function (danipcim): '<Root>/PCI-6229 DA1' */

  /* Level2 S-Function Block: '<Root>/PCI-6229 DA1' (danipcim) */
  {
    SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[3];
    sfcnOutputs(rts,1);
  }

  /* DotProduct: '<Root>/Dot Product2' */
  tmp = homing_ldm_aggiornat_B.Gain2;
  tmp_0 = homing_ldm_aggiornat_B.ok_y;
  homing_ldm_aggiornat_B.DotProduct2 = tmp * tmp_0;

  /* Gain: '<Root>/Gain5' */
  homing_ldm_aggiornat_B.Gain5 = homing_ldm_aggiornat_P.Gain5_Gain *
    homing_ldm_aggiornat_B.Vel_y_out;

  /* DotProduct: '<Root>/Dot Product8' */
  tmp = homing_ldm_aggiornat_B.Gain5;
  tmp_0 = homing_ldm_aggiornat_B.ok_y_2;
  homing_ldm_aggiornat_B.DotProduct8 = tmp * tmp_0;

  /* Sum: '<Root>/Sum6' */
  homing_ldm_aggiornat_B.Sum6 = homing_ldm_aggiornat_B.DotProduct2 +
    homing_ldm_aggiornat_B.DotProduct8;

  /* S-Function (danipcim): '<Root>/PCI-6229 DA2' */

  /* Level2 S-Function Block: '<Root>/PCI-6229 DA2' (danipcim) */
  {
    SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[4];
    sfcnOutputs(rts,1);
  }

  /* Constant: '<Root>/Constant6' */
  homing_ldm_aggiornat_B.Constant6 = homing_ldm_aggiornat_P.Constant6_Value;

  /* S-Function (donipcim): '<Root>/PCI-6229 DO2' */

  /* Level2 S-Function Block: '<Root>/PCI-6229 DO2' (donipcim) */
  {
    SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[5];
    sfcnOutputs(rts,1);
  }

  /* S-Function (encnipcim): '<Root>/PCI 6229 ENC 4' */

  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 4' (encnipcim) */
  {
    SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[6];
    sfcnOutputs(rts,1);
  }

  /* Gain: '<Root>/Gain10' */
  homing_ldm_aggiornat_B.posizionemotorex_i = homing_ldm_aggiornat_P.Gain10_Gain
    * homing_ldm_aggiornat_B.posizionemotorex;

  /* SampleTimeMath: '<S2>/TSamp'
   *
   * About '<S2>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  homing_ldm_aggiornat_B.TSamp_c = homing_ldm_aggiornat_B.posizionemotorex_i *
    homing_ldm_aggiornat_P.TSamp_WtEt_j;

  /* UnitDelay: '<S2>/UD' */
  homing_ldm_aggiornat_B.Uk1_l = homing_ldm_aggiornat_DW.UD_DSTATE_d;

  /* Sum: '<S2>/Diff' */
  homing_ldm_aggiornat_B.Diff_e = homing_ldm_aggiornat_B.TSamp_c -
    homing_ldm_aggiornat_B.Uk1_l;

  /* S-Function (encnipcim): '<Root>/PCI 6229 ENC 5' */

  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 5' (encnipcim) */
  {
    SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[7];
    sfcnOutputs(rts,1);
  }

  /* Gain: '<Root>/Gain12' */
  homing_ldm_aggiornat_B.posizionemotorey = homing_ldm_aggiornat_P.Gain12_Gain *
    homing_ldm_aggiornat_B.pozionemotorey;

  /* SampleTimeMath: '<S4>/TSamp'
   *
   * About '<S4>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  homing_ldm_aggiornat_B.TSamp_l = homing_ldm_aggiornat_B.posizionemotorey *
    homing_ldm_aggiornat_P.TSamp_WtEt_b;

  /* UnitDelay: '<S4>/UD' */
  homing_ldm_aggiornat_B.Uk1_b = homing_ldm_aggiornat_DW.UD_DSTATE_b;

  /* Sum: '<S4>/Diff' */
  homing_ldm_aggiornat_B.Diff_d = homing_ldm_aggiornat_B.TSamp_l -
    homing_ldm_aggiornat_B.Uk1_b;
}

/* Model update function */
static void homing_ldm_aggiornat_update(void)
{
  /* Update for UnitDelay: '<S3>/UD' */
  homing_ldm_aggiornat_DW.UD_DSTATE = homing_ldm_aggiornat_B.TSamp;

  /* Update for UnitDelay: '<S5>/UD' */
  homing_ldm_aggiornat_DW.UD_DSTATE_p = homing_ldm_aggiornat_B.TSamp_b;

  /* Update for UnitDelay: '<S2>/UD' */
  homing_ldm_aggiornat_DW.UD_DSTATE_d = homing_ldm_aggiornat_B.TSamp_c;

  /* Update for UnitDelay: '<S4>/UD' */
  homing_ldm_aggiornat_DW.UD_DSTATE_b = homing_ldm_aggiornat_B.TSamp_l;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++homing_ldm_aggiornat_M->Timing.clockTick0)) {
    ++homing_ldm_aggiornat_M->Timing.clockTickH0;
  }

  homing_ldm_aggiornat_M->Timing.t[0] =
    homing_ldm_aggiornat_M->Timing.clockTick0 *
    homing_ldm_aggiornat_M->Timing.stepSize0 +
    homing_ldm_aggiornat_M->Timing.clockTickH0 *
    homing_ldm_aggiornat_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++homing_ldm_aggiornat_M->Timing.clockTick1)) {
      ++homing_ldm_aggiornat_M->Timing.clockTickH1;
    }

    homing_ldm_aggiornat_M->Timing.t[1] =
      homing_ldm_aggiornat_M->Timing.clockTick1 *
      homing_ldm_aggiornat_M->Timing.stepSize1 +
      homing_ldm_aggiornat_M->Timing.clockTickH1 *
      homing_ldm_aggiornat_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
static void homing_ldm_aggiornat_initialize(void)
{
  /* Start for S-Function (dinipcim): '<Root>/PCI-6229 DI' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DI' (dinipcim) */
  {
    SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (encnipcim): '<Root>/PCI 6229 ENC 7' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 7' (encnipcim) */
  {
    SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (encnipcim): '<Root>/PCI 6229 ENC 6' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 6' (encnipcim) */
  {
    SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (danipcim): '<Root>/PCI-6229 DA1' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DA1' (danipcim) */
  {
    SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (danipcim): '<Root>/PCI-6229 DA2' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DA2' (danipcim) */
  {
    SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<Root>/Constant6' */
  homing_ldm_aggiornat_B.Constant6 = homing_ldm_aggiornat_P.Constant6_Value;

  /* Start for S-Function (donipcim): '<Root>/PCI-6229 DO2' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DO2' (donipcim) */
  {
    SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[5];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (encnipcim): '<Root>/PCI 6229 ENC 4' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 4' (encnipcim) */
  {
    SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (encnipcim): '<Root>/PCI 6229 ENC 5' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 5' (encnipcim) */
  {
    SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[7];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S3>/UD' */
  homing_ldm_aggiornat_DW.UD_DSTATE =
    homing_ldm_aggiornat_P.DiscreteDerivative5_ICPrevScale;

  /* InitializeConditions for UnitDelay: '<S5>/UD' */
  homing_ldm_aggiornat_DW.UD_DSTATE_p =
    homing_ldm_aggiornat_P.DiscreteDerivative7_ICPrevScale;

  /* InitializeConditions for UnitDelay: '<S2>/UD' */
  homing_ldm_aggiornat_DW.UD_DSTATE_d =
    homing_ldm_aggiornat_P.DiscreteDerivative4_ICPrevScale;

  /* InitializeConditions for UnitDelay: '<S4>/UD' */
  homing_ldm_aggiornat_DW.UD_DSTATE_b =
    homing_ldm_aggiornat_P.DiscreteDerivative6_ICPrevScale;

  /* SystemInitialize for Chart: '<Root>/Chart' */
  homing_ldm_aggiornat_DW.sfEvent = homing_ldm_aggiornat_CALL_EVENT;
  homing_ldm_aggiornat_DW.is_Homing1 = homing_ldm_a_IN_NO_ACTIVE_CHILD;
  homing_ldm_aggiornat_DW.is_Homing2 = homing_ldm_a_IN_NO_ACTIVE_CHILD;
  homing_ldm_aggiornat_DW.is_active_c3_homing_ldm_aggiorn = 0U;
  homing_ldm_aggiornat_DW.is_c3_homing_ldm_aggiornat =
    homing_ldm_a_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
static void homing_ldm_aggiornat_terminate(void)
{
  /* Terminate for S-Function (dinipcim): '<Root>/PCI-6229 DI' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DI' (dinipcim) */
  {
    SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (encnipcim): '<Root>/PCI 6229 ENC 7' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 7' (encnipcim) */
  {
    SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (encnipcim): '<Root>/PCI 6229 ENC 6' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 6' (encnipcim) */
  {
    SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (danipcim): '<Root>/PCI-6229 DA1' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DA1' (danipcim) */
  {
    SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (danipcim): '<Root>/PCI-6229 DA2' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DA2' (danipcim) */
  {
    SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (donipcim): '<Root>/PCI-6229 DO2' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DO2' (donipcim) */
  {
    SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (encnipcim): '<Root>/PCI 6229 ENC 4' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 4' (encnipcim) */
  {
    SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (encnipcim): '<Root>/PCI 6229 ENC 5' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 5' (encnipcim) */
  {
    SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[7];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  homing_ldm_aggiornat_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  homing_ldm_aggiornat_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  homing_ldm_aggiornat_initialize();
}

void MdlTerminate(void)
{
  homing_ldm_aggiornat_terminate();
}

/* Registration function */
RT_MODEL_homing_ldm_aggiornat_T *homing_ldm_aggiornat(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)homing_ldm_aggiornat_M, 0,
                sizeof(RT_MODEL_homing_ldm_aggiornat_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&homing_ldm_aggiornat_M->solverInfo,
                          &homing_ldm_aggiornat_M->Timing.simTimeStep);
    rtsiSetTPtr(&homing_ldm_aggiornat_M->solverInfo, &rtmGetTPtr
                (homing_ldm_aggiornat_M));
    rtsiSetStepSizePtr(&homing_ldm_aggiornat_M->solverInfo,
                       &homing_ldm_aggiornat_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&homing_ldm_aggiornat_M->solverInfo,
                          (&rtmGetErrorStatus(homing_ldm_aggiornat_M)));
    rtsiSetRTModelPtr(&homing_ldm_aggiornat_M->solverInfo,
                      homing_ldm_aggiornat_M);
  }

  rtsiSetSimTimeStep(&homing_ldm_aggiornat_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&homing_ldm_aggiornat_M->solverInfo,"FixedStepDiscrete");
  homing_ldm_aggiornat_M->solverInfoPtr = (&homing_ldm_aggiornat_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = homing_ldm_aggiornat_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    homing_ldm_aggiornat_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    homing_ldm_aggiornat_M->Timing.sampleTimes =
      (&homing_ldm_aggiornat_M->Timing.sampleTimesArray[0]);
    homing_ldm_aggiornat_M->Timing.offsetTimes =
      (&homing_ldm_aggiornat_M->Timing.offsetTimesArray[0]);

    /* task periods */
    homing_ldm_aggiornat_M->Timing.sampleTimes[0] = (0.0);
    homing_ldm_aggiornat_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    homing_ldm_aggiornat_M->Timing.offsetTimes[0] = (0.0);
    homing_ldm_aggiornat_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(homing_ldm_aggiornat_M, &homing_ldm_aggiornat_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = homing_ldm_aggiornat_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    homing_ldm_aggiornat_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(homing_ldm_aggiornat_M, -1);
  homing_ldm_aggiornat_M->Timing.stepSize0 = 0.001;
  homing_ldm_aggiornat_M->Timing.stepSize1 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    homing_ldm_aggiornat_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(homing_ldm_aggiornat_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(homing_ldm_aggiornat_M->rtwLogInfo, (NULL));
    rtliSetLogT(homing_ldm_aggiornat_M->rtwLogInfo, "tout");
    rtliSetLogX(homing_ldm_aggiornat_M->rtwLogInfo, "");
    rtliSetLogXFinal(homing_ldm_aggiornat_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(homing_ldm_aggiornat_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(homing_ldm_aggiornat_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(homing_ldm_aggiornat_M->rtwLogInfo, 0);
    rtliSetLogDecimation(homing_ldm_aggiornat_M->rtwLogInfo, 1);
    rtliSetLogY(homing_ldm_aggiornat_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(homing_ldm_aggiornat_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(homing_ldm_aggiornat_M->rtwLogInfo, (NULL));
  }

  homing_ldm_aggiornat_M->solverInfoPtr = (&homing_ldm_aggiornat_M->solverInfo);
  homing_ldm_aggiornat_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&homing_ldm_aggiornat_M->solverInfo, 0.001);
  rtsiSetSolverMode(&homing_ldm_aggiornat_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  homing_ldm_aggiornat_M->blockIO = ((void *) &homing_ldm_aggiornat_B);
  (void) memset(((void *) &homing_ldm_aggiornat_B), 0,
                sizeof(B_homing_ldm_aggiornat_T));

  /* parameters */
  homing_ldm_aggiornat_M->defaultParam = ((real_T *)&homing_ldm_aggiornat_P);

  /* states (dwork) */
  homing_ldm_aggiornat_M->dwork = ((void *) &homing_ldm_aggiornat_DW);
  (void) memset((void *)&homing_ldm_aggiornat_DW, 0,
                sizeof(DW_homing_ldm_aggiornat_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  homing_ldm_aggiornat_InitializeDataMapInfo(homing_ldm_aggiornat_M);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &homing_ldm_aggiornat_M->NonInlinedSFcns.sfcnInfo;
    homing_ldm_aggiornat_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(homing_ldm_aggiornat_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &homing_ldm_aggiornat_M->Sizes.numSampTimes);
    homing_ldm_aggiornat_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (homing_ldm_aggiornat_M)[0]);
    homing_ldm_aggiornat_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (homing_ldm_aggiornat_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,homing_ldm_aggiornat_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(homing_ldm_aggiornat_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(homing_ldm_aggiornat_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (homing_ldm_aggiornat_M));
    rtssSetStepSizePtr(sfcnInfo, &homing_ldm_aggiornat_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (homing_ldm_aggiornat_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &homing_ldm_aggiornat_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &homing_ldm_aggiornat_M->zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &homing_ldm_aggiornat_M->blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &homing_ldm_aggiornat_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &homing_ldm_aggiornat_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &homing_ldm_aggiornat_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &homing_ldm_aggiornat_M->solverInfoPtr);
  }

  homing_ldm_aggiornat_M->Sizes.numSFcns = (8);

  /* register each child */
  {
    (void) memset((void *)
                  &homing_ldm_aggiornat_M->NonInlinedSFcns.childSFunctions[0], 0,
                  8*sizeof(SimStruct));
    homing_ldm_aggiornat_M->childSfunctions =
      (&homing_ldm_aggiornat_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 8; i++) {
        homing_ldm_aggiornat_M->childSfunctions[i] =
          (&homing_ldm_aggiornat_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: homing_ldm_aggiornat/<Root>/PCI-6229 DI (dinipcim) */
    {
      SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &homing_ldm_aggiornat_M->NonInlinedSFcns.blkInfo2
                         [0]);
      }

      ssSetRTWSfcnInfo(rts, homing_ldm_aggiornat_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &homing_ldm_aggiornat_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &homing_ldm_aggiornat_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &homing_ldm_aggiornat_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &homing_ldm_aggiornat_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &homing_ldm_aggiornat_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 4);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &homing_ldm_aggiornat_B.fcxsx));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &homing_ldm_aggiornat_B.fcxdx));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &homing_ldm_aggiornat_B.fcyhigh));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            &homing_ldm_aggiornat_B.fcydown));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6229 DI");
      ssSetPath(rts, "homing_ldm_aggiornat/PCI-6229 DI");
      ssSetRTModel(rts,homing_ldm_aggiornat_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229DI_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229DI_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229DI_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229DI_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229DI_P5_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &homing_ldm_aggiornat_DW.PCI6229DI_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &homing_ldm_aggiornat_DW.PCI6229DI_IWORK);
      }

      /* registration */
      dinipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: homing_ldm_aggiornat/<Root>/PCI 6229 ENC 7 (encnipcim) */
    {
      SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &homing_ldm_aggiornat_M->NonInlinedSFcns.blkInfo2
                         [1]);
      }

      ssSetRTWSfcnInfo(rts, homing_ldm_aggiornat_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &homing_ldm_aggiornat_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &homing_ldm_aggiornat_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &homing_ldm_aggiornat_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &homing_ldm_aggiornat_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &homing_ldm_aggiornat_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &homing_ldm_aggiornat_B.posizionecarrellox));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI 6229 ENC 7");
      ssSetPath(rts, "homing_ldm_aggiornat/PCI 6229 ENC 7");
      ssSetRTModel(rts,homing_ldm_aggiornat_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC7_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC7_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC7_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC7_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC7_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC7_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC7_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC7_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC7_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC7_P10_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &homing_ldm_aggiornat_DW.PCI6229ENC7_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &homing_ldm_aggiornat_DW.PCI6229ENC7_PWORK);
      }

      /* registration */
      encnipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: homing_ldm_aggiornat/<Root>/PCI 6229 ENC 6 (encnipcim) */
    {
      SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod =
        homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &homing_ldm_aggiornat_M->NonInlinedSFcns.blkInfo2
                         [2]);
      }

      ssSetRTWSfcnInfo(rts, homing_ldm_aggiornat_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &homing_ldm_aggiornat_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &homing_ldm_aggiornat_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &homing_ldm_aggiornat_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &homing_ldm_aggiornat_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &homing_ldm_aggiornat_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &homing_ldm_aggiornat_B.posizionecarrelloy));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI 6229 ENC 6");
      ssSetPath(rts, "homing_ldm_aggiornat/PCI 6229 ENC 6");
      ssSetRTModel(rts,homing_ldm_aggiornat_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC6_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC6_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC6_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC6_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC6_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC6_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC6_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC6_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC6_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC6_P10_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &homing_ldm_aggiornat_DW.PCI6229ENC6_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &homing_ldm_aggiornat_DW.PCI6229ENC6_PWORK);
      }

      /* registration */
      encnipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: homing_ldm_aggiornat/<Root>/PCI-6229 DA1 (danipcim) */
    {
      SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod =
        homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset =
        homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &homing_ldm_aggiornat_M->NonInlinedSFcns.blkInfo2
                         [3]);
      }

      ssSetRTWSfcnInfo(rts, homing_ldm_aggiornat_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &homing_ldm_aggiornat_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &homing_ldm_aggiornat_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &homing_ldm_aggiornat_M->NonInlinedSFcns.methods4[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &homing_ldm_aggiornat_M->NonInlinedSFcns.statesInfo2[3]);
        ssSetPeriodicStatesInfo(rts,
          &homing_ldm_aggiornat_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &homing_ldm_aggiornat_B.Sum1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6229 DA1");
      ssSetPath(rts, "homing_ldm_aggiornat/PCI-6229 DA1");
      ssSetRTModel(rts,homing_ldm_aggiornat_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229DA1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229DA1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229DA1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229DA1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229DA1_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229DA1_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229DA1_P7_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &homing_ldm_aggiornat_DW.PCI6229DA1_RWORK[0]);
      ssSetIWork(rts, (int_T *) &homing_ldm_aggiornat_DW.PCI6229DA1_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &homing_ldm_aggiornat_DW.PCI6229DA1_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 41);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &homing_ldm_aggiornat_DW.PCI6229DA1_IWORK[0]);
      }

      /* registration */
      danipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: homing_ldm_aggiornat/<Root>/PCI-6229 DA2 (danipcim) */
    {
      SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod =
        homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset =
        homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &homing_ldm_aggiornat_M->NonInlinedSFcns.blkInfo2
                         [4]);
      }

      ssSetRTWSfcnInfo(rts, homing_ldm_aggiornat_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &homing_ldm_aggiornat_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &homing_ldm_aggiornat_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &homing_ldm_aggiornat_M->NonInlinedSFcns.methods4[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &homing_ldm_aggiornat_M->NonInlinedSFcns.statesInfo2[4]);
        ssSetPeriodicStatesInfo(rts,
          &homing_ldm_aggiornat_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &homing_ldm_aggiornat_B.Sum6;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6229 DA2");
      ssSetPath(rts, "homing_ldm_aggiornat/PCI-6229 DA2");
      ssSetRTModel(rts,homing_ldm_aggiornat_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229DA2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229DA2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229DA2_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229DA2_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229DA2_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229DA2_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229DA2_P7_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &homing_ldm_aggiornat_DW.PCI6229DA2_RWORK[0]);
      ssSetIWork(rts, (int_T *) &homing_ldm_aggiornat_DW.PCI6229DA2_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &homing_ldm_aggiornat_DW.PCI6229DA2_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 41);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &homing_ldm_aggiornat_DW.PCI6229DA2_IWORK[0]);
      }

      /* registration */
      danipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: homing_ldm_aggiornat/<Root>/PCI-6229 DO2 (donipcim) */
    {
      SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod =
        homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset =
        homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &homing_ldm_aggiornat_M->NonInlinedSFcns.blkInfo2
                         [5]);
      }

      ssSetRTWSfcnInfo(rts, homing_ldm_aggiornat_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &homing_ldm_aggiornat_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &homing_ldm_aggiornat_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &homing_ldm_aggiornat_M->NonInlinedSFcns.methods4[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &homing_ldm_aggiornat_M->NonInlinedSFcns.statesInfo2[5]);
        ssSetPeriodicStatesInfo(rts,
          &homing_ldm_aggiornat_M->NonInlinedSFcns.periodicStatesInfo[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &homing_ldm_aggiornat_B.Constant6;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6229 DO2");
      ssSetPath(rts, "homing_ldm_aggiornat/PCI-6229 DO2");
      ssSetRTModel(rts,homing_ldm_aggiornat_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229DO2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229DO2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229DO2_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229DO2_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229DO2_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229DO2_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229DO2_P7_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &homing_ldm_aggiornat_DW.PCI6229DO2_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn5.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn5.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &homing_ldm_aggiornat_DW.PCI6229DO2_IWORK);
      }

      /* registration */
      donipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: homing_ldm_aggiornat/<Root>/PCI 6229 ENC 4 (encnipcim) */
    {
      SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod =
        homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset =
        homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &homing_ldm_aggiornat_M->NonInlinedSFcns.blkInfo2
                         [6]);
      }

      ssSetRTWSfcnInfo(rts, homing_ldm_aggiornat_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &homing_ldm_aggiornat_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &homing_ldm_aggiornat_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &homing_ldm_aggiornat_M->NonInlinedSFcns.methods4[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &homing_ldm_aggiornat_M->NonInlinedSFcns.statesInfo2[6]);
        ssSetPeriodicStatesInfo(rts,
          &homing_ldm_aggiornat_M->NonInlinedSFcns.periodicStatesInfo[6]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &homing_ldm_aggiornat_B.posizionemotorex));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI 6229 ENC 4");
      ssSetPath(rts, "homing_ldm_aggiornat/PCI 6229 ENC 4");
      ssSetRTModel(rts,homing_ldm_aggiornat_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC4_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC4_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC4_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC4_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC4_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC4_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC4_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC4_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC4_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC4_P10_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &homing_ldm_aggiornat_DW.PCI6229ENC4_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn6.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn6.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &homing_ldm_aggiornat_DW.PCI6229ENC4_PWORK);
      }

      /* registration */
      encnipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: homing_ldm_aggiornat/<Root>/PCI 6229 ENC 5 (encnipcim) */
    {
      SimStruct *rts = homing_ldm_aggiornat_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod =
        homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset =
        homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &homing_ldm_aggiornat_M->NonInlinedSFcns.blkInfo2
                         [7]);
      }

      ssSetRTWSfcnInfo(rts, homing_ldm_aggiornat_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &homing_ldm_aggiornat_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &homing_ldm_aggiornat_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &homing_ldm_aggiornat_M->NonInlinedSFcns.methods4[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &homing_ldm_aggiornat_M->NonInlinedSFcns.statesInfo2[7]);
        ssSetPeriodicStatesInfo(rts,
          &homing_ldm_aggiornat_M->NonInlinedSFcns.periodicStatesInfo[7]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &homing_ldm_aggiornat_B.pozionemotorey));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI 6229 ENC 5");
      ssSetPath(rts, "homing_ldm_aggiornat/PCI 6229 ENC 5");
      ssSetRTModel(rts,homing_ldm_aggiornat_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC5_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC5_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC5_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC5_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC5_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC5_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC5_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC5_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC5_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       homing_ldm_aggiornat_P.PCI6229ENC5_P10_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &homing_ldm_aggiornat_DW.PCI6229ENC5_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn7.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &homing_ldm_aggiornat_M->NonInlinedSFcns.Sfcn7.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &homing_ldm_aggiornat_DW.PCI6229ENC5_PWORK);
      }

      /* registration */
      encnipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }
  }

  /* Initialize Sizes */
  homing_ldm_aggiornat_M->Sizes.numContStates = (0);/* Number of continuous states */
  homing_ldm_aggiornat_M->Sizes.numY = (0);/* Number of model outputs */
  homing_ldm_aggiornat_M->Sizes.numU = (0);/* Number of model inputs */
  homing_ldm_aggiornat_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  homing_ldm_aggiornat_M->Sizes.numSampTimes = (2);/* Number of sample times */
  homing_ldm_aggiornat_M->Sizes.numBlocks = (64);/* Number of blocks */
  homing_ldm_aggiornat_M->Sizes.numBlockIO = (42);/* Number of block outputs */
  homing_ldm_aggiornat_M->Sizes.numBlockPrms = (226);/* Sum of parameter "widths" */
  return homing_ldm_aggiornat_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
