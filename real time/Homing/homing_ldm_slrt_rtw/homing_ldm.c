/*
 * homing_ldm.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "homing_ldm".
 *
 * Model version              : 1.42
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Mon Aug 02 11:01:59 2021
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "homing_ldm_capi.h"
#include "homing_ldm.h"
#include "homing_ldm_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define homing_ldm_CALL_EVENT          (-1)
#define homing_ldm_IN_Fine             ((uint8_T)1U)
#define homing_ldm_IN_Fine_homing1     ((uint8_T)2U)
#define homing_ldm_IN_Homing           ((uint8_T)1U)
#define homing_ldm_IN_Homing_x         ((uint8_T)3U)
#define homing_ldm_IN_Homing_y         ((uint8_T)4U)
#define homing_ldm_IN_NO_ACTIVE_CHILD  ((uint8_T)0U)
#define homing_ldm_IN_Posizionamento_y ((uint8_T)5U)

/* Block signals (auto storage) */
B_homing_ldm_T homing_ldm_B;

/* Block states (auto storage) */
DW_homing_ldm_T homing_ldm_DW;

/* Real-time model */
RT_MODEL_homing_ldm_T homing_ldm_M_;
RT_MODEL_homing_ldm_T *const homing_ldm_M = &homing_ldm_M_;

/* Forward declaration for local functions */
static void Constant_Acceleration_ADIM_par(real_T x, const real_T par[2], real_T
  *G, real_T *F, real_T *f);
static real_T homing_ldm_Evaluate_Trajectory(real_T t);

/* Function for Chart: '<Root>/Chart' */
static void Constant_Acceleration_ADIM_par(real_T x, const real_T par[2], real_T
  *G, real_T *F, real_T *f)
{
  real_T A;
  real_T B;
  real_T a;

  /* MATLAB Function 'Constant_Acceleration_ADIM_par': '<S1>:128' */
  /*  function [G,F,f] = Constant_Acceleration_ADIM_par(x,par) */
  /*  prof. Paolo Righettini */
  /*  Progettazione Funzionale di Sistemi Meccanici e Meccatronici */
  /*  */
  /*  x = t/td */
  /*  par(1) = adimensional time (start point at maximum velocity) */
  /*  par(2) = adimensional time (end point at maximum velocity) */
  /*  G = adimensionalized displacement */
  /*  F = adimensionalized velocity */
  /*  f = adimensionalized acceleration */
  /* '<S1>:128:12' */
  *G = 0.0;

  /* '<S1>:128:13' */
  *F = 0.0;

  /* '<S1>:128:14' */
  *f = 0.0;

  /* '<S1>:128:15' */
  /* '<S1>:128:16' */
  /* '<S1>:128:20' */
  A = 2.0 / (((1.0 - par[0]) + par[1]) * par[0]);

  /* '<S1>:128:21' */
  B = 2.0 / (((1.0 - par[0]) + par[1]) * (1.0 - par[1]));
  if ((x >= 0.0) && (x <= par[0])) {
    /* '<S1>:128:23' */
    /* '<S1>:128:24' */
    *f = A;

    /* '<S1>:128:25' */
    *F = A * x;

    /* '<S1>:128:26' */
    *G = 0.5 * A * (x * x);
  } else if ((x > par[0]) && (x < par[1])) {
    /* '<S1>:128:27' */
    /* '<S1>:128:28' */
    /* '<S1>:128:29' */
    *F = A * par[0];

    /* '<S1>:128:30' */
    *G = (x - par[0] / 2.0) * (A * par[0]);
  } else {
    if ((x >= par[1]) && (x <= 1.0)) {
      /* '<S1>:128:31' */
      /* '<S1>:128:32' */
      *f = -B;

      /* '<S1>:128:33' */
      *F = A * par[0] - (x - par[1]) * B;

      /* '<S1>:128:34' */
      a = x - par[1];
      *G = (x - par[0] / 2.0) * (A * par[0]) - B / 2.0 * (a * a);
    }
  }
}

/* Function for Chart: '<Root>/Chart' */
static real_T homing_ldm_Evaluate_Trajectory(real_T t)
{
  real_T X;
  real_T G;
  real_T F;
  real_T f;
  real_T tmp[2];

  /* MATLAB Function 'Evaluate_Trajectory': '<S1>:113' */
  /* '<S1>:113:32' */
  /* '<S1>:113:12' */
  /*  parametri: */
  /*  t: tempo assolu */
  /*  h: spostamento richiesto */
  /* '<S1>:113:6' */
  X = 0.0;

  /* '<S1>:113:10' */
  /* '<S1>:113:12' */
  /* ta di ogni singolo ramo perche' composta */
  /* '<S1>:113:17' */
  /* '<S1>:113:18' */
  /* '<S1>:113:19' */
  /* '<S1>:113:22' */
  /* '<S1>:113:23' */
  /* '<S1>:113:24' */
  /* '<S1>:113:25' */
  /*  Total time */
  if ((t >= 0.0) && (t <= 0.2)) {
    /* '<S1>:113:28' */
    /*  Interval N°1  */
    /* tempo di azionamento */
    /* '<S1>:113:30' */
    /* tempo adimensionale */
    /* '<S1>:113:32' */
    tmp[0] = 0.33333333333333331;
    tmp[1] = 0.66666666666666663;
    Constant_Acceleration_ADIM_par(t / 0.2, tmp, &G, &F, &f);

    /* '<S1>:113:34' */
    X = F * 0.5 / 0.2;
  }

  if ((t > 0.2) && (t <= 0.53333333333333333)) {
    /* '<S1>:113:38' */
    /*  Interval N°2  */
    /* '<S1>:113:40' */
    X = 0.0;
  }

  if ((t > 0.53333333333333333) && (t <= 0.8666666666666667)) {
    /* '<S1>:113:44' */
    /*  Interval N°3 */
    /* '<S1>:113:46' */
    /* '<S1>:113:48' */
    tmp[0] = 0.33333333333333331;
    tmp[1] = 0.66666666666666663;
    Constant_Acceleration_ADIM_par((t - 0.53333333333333333) /
      0.33333333333333331, tmp, &G, &F, &f);

    /* '<S1>:113:51' */
    X = -(F * 0.5 / 0.33333333333333331);
  }

  if (t > 0.8666666666666667) {
    /* '<S1>:113:55' */
    /*  Interval N°4     */
    /* '<S1>:113:57' */
    X = 0.0;
  }

  /* '<S1>:113:61' */
  /* pos, vel, acc */
  return X;
}

/* Model output function */
static void homing_ldm_output(void)
{
  real_T tmp;
  real_T tmp_0;

  /* S-Function (dinipcim): '<Root>/PCI-6229 DI' */

  /* Level2 S-Function Block: '<Root>/PCI-6229 DI' (dinipcim) */
  {
    SimStruct *rts = homing_ldm_M->childSfunctions[0];
    sfcnOutputs(rts,1);
  }

  /* S-Function (encnipcim): '<Root>/PCI 6229 ENC 2' */

  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 2' (encnipcim) */
  {
    SimStruct *rts = homing_ldm_M->childSfunctions[1];
    sfcnOutputs(rts,1);
  }

  /* Gain: '<Root>/Gain1' */
  homing_ldm_B.posizionecarrelloy_n = homing_ldm_P.Gain1_Gain *
    homing_ldm_B.posizionecarrelloy;

  /* S-Function (encnipcim): '<Root>/PCI 6229 ENC 3' */

  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 3' (encnipcim) */
  {
    SimStruct *rts = homing_ldm_M->childSfunctions[2];
    sfcnOutputs(rts,1);
  }

  /* Gain: '<Root>/Gain3' */
  homing_ldm_B.posizionecarrellox_n = homing_ldm_P.Gain3_Gain *
    homing_ldm_B.posizionecarrellox;

  /* SampleTimeMath: '<S5>/TSamp'
   *
   * About '<S5>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  homing_ldm_B.TSamp = homing_ldm_B.posizionecarrellox_n *
    homing_ldm_P.TSamp_WtEt;

  /* UnitDelay: '<S5>/UD' */
  homing_ldm_B.Uk1 = homing_ldm_DW.UD_DSTATE;

  /* Sum: '<S5>/Diff' */
  homing_ldm_B.Diff = homing_ldm_B.TSamp - homing_ldm_B.Uk1;

  /* SampleTimeMath: '<S3>/TSamp'
   *
   * About '<S3>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  homing_ldm_B.TSamp_h = homing_ldm_B.posizionecarrelloy_n *
    homing_ldm_P.TSamp_WtEt_j;

  /* UnitDelay: '<S3>/UD' */
  homing_ldm_B.Uk1_i = homing_ldm_DW.UD_DSTATE_c;

  /* Sum: '<S3>/Diff' */
  homing_ldm_B.Diff_d = homing_ldm_B.TSamp_h - homing_ldm_B.Uk1_i;

  /* Clock: '<Root>/Clock' */
  homing_ldm_B.Clock = homing_ldm_M->Timing.t[0];

  /* Chart: '<Root>/Chart' */
  /* Gateway: Chart */
  homing_ldm_DW.sfEvent = homing_ldm_CALL_EVENT;

  /* During: Chart */
  if (homing_ldm_DW.is_active_c3_homing_ldm == 0U) {
    /* Entry: Chart */
    homing_ldm_DW.is_active_c3_homing_ldm = 1U;

    /* Entry Internal: Chart */
    /* Transition: '<S1>:45' */
    homing_ldm_DW.is_c3_homing_ldm = homing_ldm_IN_Homing;

    /* Entry Internal 'Homing': '<S1>:44' */
    /* Transition: '<S1>:27' */
    homing_ldm_DW.is_Homing = homing_ldm_IN_Homing_x;

    /* Entry 'Homing_x': '<S1>:26' */
    homing_ldm_DW.v_sp_x = -2.1;
    homing_ldm_B.ok_x = 1.0;
    homing_ldm_B.ok_x_2 = 0.0;
  } else {
    /* During 'Homing': '<S1>:44' */
    switch (homing_ldm_DW.is_Homing) {
     case homing_ldm_IN_Fine:
      homing_ldm_B.ok_x_2 = 0.0;
      homing_ldm_B.ok_y_2 = 0.0;

      /* During 'Fine': '<S1>:92' */
      break;

     case homing_ldm_IN_Fine_homing1:
      homing_ldm_B.ok_y = 0.0;
      homing_ldm_B.ok_x_2 = 1.0;
      homing_ldm_B.ok_x = 0.0;

      /* During 'Fine_homing1': '<S1>:59' */
      if (homing_ldm_DW.dx > 0.5) {
        /* Transition: '<S1>:75' */
        homing_ldm_DW.is_Homing = homing_ldm_IN_Posizionamento_y;

        /* Entry 'Posizionamento_y': '<S1>:77' */
        homing_ldm_B.ok_x_2 = 0.0;
        homing_ldm_DW.ay = homing_ldm_B.posizionecarrelloy_n;
        homing_ldm_DW.v_sp_y = -1.3;
        homing_ldm_B.ok_y_2 = 1.0;
      } else {
        homing_ldm_DW.t = homing_ldm_B.Clock - homing_ldm_DW.t1;

        /* [G_,F_,f_]=Constant_Acceleration_ADIM_par(t,[1/3,1/3,1/3]); */
        homing_ldm_B.X_ = homing_ldm_Evaluate_Trajectory(homing_ldm_DW.t);
        homing_ldm_B.Vel_x_out = homing_ldm_B.X_;
        homing_ldm_DW.dx = homing_ldm_B.posizionecarrellox_n - homing_ldm_DW.a;
      }
      break;

     case homing_ldm_IN_Homing_x:
      homing_ldm_B.ok_x_2 = 0.0;
      homing_ldm_B.ok_x = 1.0;

      /* During 'Homing_x': '<S1>:26' */
      if (homing_ldm_B.fcxsx == 0.0) {
        /* Transition: '<S1>:29' */
        homing_ldm_DW.is_Homing = homing_ldm_IN_Homing_y;

        /* Entry 'Homing_y': '<S1>:46' */
        homing_ldm_B.ok_x = 0.0;
        homing_ldm_DW.v_sp_y = 1.2;
        homing_ldm_B.ok_y = 1.0;
      } else {
        homing_ldm_B.Vel_x_out = homing_ldm_DW.v_sp_x;
      }
      break;

     case homing_ldm_IN_Homing_y:
      homing_ldm_B.ok_y = 1.0;
      homing_ldm_B.ok_x = 0.0;

      /* During 'Homing_y': '<S1>:46' */
      if (homing_ldm_B.fcydown == 0.0) {
        /* Transition: '<S1>:58' */
        homing_ldm_DW.is_Homing = homing_ldm_IN_Fine_homing1;

        /* Entry 'Fine_homing1': '<S1>:59' */
        homing_ldm_B.ok_y = 0.0;
        homing_ldm_B.ok_x = 0.0;
        homing_ldm_DW.a = homing_ldm_B.posizionecarrellox_n;
        homing_ldm_B.ok_x_2 = 1.0;
        homing_ldm_DW.t1 = homing_ldm_B.Clock;

        /* X=0; */
        /* G_=0; */
        /* F_=0; */
        /* f_=0; */
      } else {
        homing_ldm_B.Vel_y_out = homing_ldm_DW.v_sp_y - homing_ldm_B.Diff_d;
      }
      break;

     default:
      homing_ldm_B.ok_x_2 = 0.0;
      homing_ldm_B.ok_y_2 = 1.0;

      /* During 'Posizionamento_y': '<S1>:77' */
      if (homing_ldm_DW.dy > 0.5) {
        /* Transition: '<S1>:93' */
        homing_ldm_DW.is_Homing = homing_ldm_IN_Fine;

        /* Entry 'Fine': '<S1>:92' */
        homing_ldm_B.ok_y_2 = 0.0;
        homing_ldm_B.ok_x_2 = 0.0;
      } else {
        homing_ldm_B.Vel_y_out = homing_ldm_DW.v_sp_y - homing_ldm_B.Diff_d;
        homing_ldm_DW.dy = fabs(homing_ldm_B.posizionecarrelloy_n -
          homing_ldm_DW.ay);
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */
  /* Sum: '<Root>/Sum4' */
  homing_ldm_B.Sum4 = homing_ldm_B.Vel_x_out - homing_ldm_B.Diff;

  /* Gain: '<Root>/Gain4' */
  homing_ldm_B.Gain4 = homing_ldm_P.Gain4_Gain * homing_ldm_B.Sum4;

  /* DotProduct: '<Root>/Dot Product3' */
  tmp = homing_ldm_B.Gain4;
  tmp_0 = homing_ldm_B.ok_x;
  homing_ldm_B.DotProduct3 = tmp * tmp_0;

  /* Sum: '<Root>/Sum5' */
  homing_ldm_B.Sum5 = homing_ldm_B.Vel_x_out - homing_ldm_B.Diff;

  /* Gain: '<Root>/Gain8' */
  homing_ldm_B.Gain8 = homing_ldm_P.Gain8_Gain * homing_ldm_B.Sum5;

  /* DotProduct: '<Root>/Dot Product5' */
  tmp = homing_ldm_B.Gain8;
  tmp_0 = homing_ldm_B.ok_x_2;
  homing_ldm_B.DotProduct5 = tmp * tmp_0;

  /* Sum: '<Root>/Sum2' */
  homing_ldm_B.Sum2 = homing_ldm_B.DotProduct3 + homing_ldm_B.DotProduct5;

  /* S-Function (danipcim): '<Root>/PCI-6229 DA4' */

  /* Level2 S-Function Block: '<Root>/PCI-6229 DA4' (danipcim) */
  {
    SimStruct *rts = homing_ldm_M->childSfunctions[3];
    sfcnOutputs(rts,1);
  }

  /* Gain: '<Root>/Gain7' */
  homing_ldm_B.Gain7 = homing_ldm_P.Gain7_Gain * homing_ldm_B.Vel_y_out;

  /* DotProduct: '<Root>/Dot Product4' */
  tmp = homing_ldm_B.Gain7;
  tmp_0 = homing_ldm_B.ok_y;
  homing_ldm_B.DotProduct4 = tmp * tmp_0;

  /* Gain: '<Root>/Gain9' */
  homing_ldm_B.Gain9 = homing_ldm_P.Gain9_Gain * homing_ldm_B.Vel_y_out;

  /* DotProduct: '<Root>/Dot Product6' */
  tmp = homing_ldm_B.Gain9;
  tmp_0 = homing_ldm_B.ok_y_2;
  homing_ldm_B.DotProduct6 = tmp * tmp_0;

  /* Sum: '<Root>/Sum3' */
  homing_ldm_B.Sum3 = homing_ldm_B.DotProduct4 + homing_ldm_B.DotProduct6;

  /* S-Function (danipcim): '<Root>/PCI-6229 DA5' */

  /* Level2 S-Function Block: '<Root>/PCI-6229 DA5' (danipcim) */
  {
    SimStruct *rts = homing_ldm_M->childSfunctions[4];
    sfcnOutputs(rts,1);
  }

  /* Constant: '<Root>/Constant1' */
  homing_ldm_B.Constant1 = homing_ldm_P.Constant1_Value;

  /* S-Function (donipcim): '<Root>/PCI-6229 DO1' */

  /* Level2 S-Function Block: '<Root>/PCI-6229 DO1' (donipcim) */
  {
    SimStruct *rts = homing_ldm_M->childSfunctions[5];
    sfcnOutputs(rts,1);
  }

  /* S-Function (encnipcim): '<Root>/PCI 6229 ENC ' */

  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC ' (encnipcim) */
  {
    SimStruct *rts = homing_ldm_M->childSfunctions[6];
    sfcnOutputs(rts,1);
  }

  /* Gain: '<Root>/Gain' */
  homing_ldm_B.posizionemotorex_n = homing_ldm_P.Gain_Gain *
    homing_ldm_B.posizionemotorex;

  /* SampleTimeMath: '<S2>/TSamp'
   *
   * About '<S2>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  homing_ldm_B.TSamp_m = homing_ldm_B.posizionemotorex_n *
    homing_ldm_P.TSamp_WtEt_e;

  /* UnitDelay: '<S2>/UD' */
  homing_ldm_B.Uk1_j = homing_ldm_DW.UD_DSTATE_p;

  /* Sum: '<S2>/Diff' */
  homing_ldm_B.Diff_a = homing_ldm_B.TSamp_m - homing_ldm_B.Uk1_j;

  /* S-Function (encnipcim): '<Root>/PCI 6229 ENC 1' */

  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 1' (encnipcim) */
  {
    SimStruct *rts = homing_ldm_M->childSfunctions[7];
    sfcnOutputs(rts,1);
  }

  /* Gain: '<Root>/Gain2' */
  homing_ldm_B.posizionemotorey = homing_ldm_P.Gain2_Gain *
    homing_ldm_B.pozionemotorey;

  /* SampleTimeMath: '<S4>/TSamp'
   *
   * About '<S4>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  homing_ldm_B.TSamp_d = homing_ldm_B.posizionemotorey *
    homing_ldm_P.TSamp_WtEt_f;

  /* UnitDelay: '<S4>/UD' */
  homing_ldm_B.Uk1_jq = homing_ldm_DW.UD_DSTATE_e;

  /* Sum: '<S4>/Diff' */
  homing_ldm_B.Diff_i = homing_ldm_B.TSamp_d - homing_ldm_B.Uk1_jq;
}

/* Model update function */
static void homing_ldm_update(void)
{
  /* Update for UnitDelay: '<S5>/UD' */
  homing_ldm_DW.UD_DSTATE = homing_ldm_B.TSamp;

  /* Update for UnitDelay: '<S3>/UD' */
  homing_ldm_DW.UD_DSTATE_c = homing_ldm_B.TSamp_h;

  /* Update for UnitDelay: '<S2>/UD' */
  homing_ldm_DW.UD_DSTATE_p = homing_ldm_B.TSamp_m;

  /* Update for UnitDelay: '<S4>/UD' */
  homing_ldm_DW.UD_DSTATE_e = homing_ldm_B.TSamp_d;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++homing_ldm_M->Timing.clockTick0)) {
    ++homing_ldm_M->Timing.clockTickH0;
  }

  homing_ldm_M->Timing.t[0] = homing_ldm_M->Timing.clockTick0 *
    homing_ldm_M->Timing.stepSize0 + homing_ldm_M->Timing.clockTickH0 *
    homing_ldm_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++homing_ldm_M->Timing.clockTick1)) {
      ++homing_ldm_M->Timing.clockTickH1;
    }

    homing_ldm_M->Timing.t[1] = homing_ldm_M->Timing.clockTick1 *
      homing_ldm_M->Timing.stepSize1 + homing_ldm_M->Timing.clockTickH1 *
      homing_ldm_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
static void homing_ldm_initialize(void)
{
  /* Start for S-Function (dinipcim): '<Root>/PCI-6229 DI' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DI' (dinipcim) */
  {
    SimStruct *rts = homing_ldm_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (encnipcim): '<Root>/PCI 6229 ENC 2' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 2' (encnipcim) */
  {
    SimStruct *rts = homing_ldm_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (encnipcim): '<Root>/PCI 6229 ENC 3' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 3' (encnipcim) */
  {
    SimStruct *rts = homing_ldm_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (danipcim): '<Root>/PCI-6229 DA4' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DA4' (danipcim) */
  {
    SimStruct *rts = homing_ldm_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (danipcim): '<Root>/PCI-6229 DA5' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DA5' (danipcim) */
  {
    SimStruct *rts = homing_ldm_M->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<Root>/Constant1' */
  homing_ldm_B.Constant1 = homing_ldm_P.Constant1_Value;

  /* Start for S-Function (donipcim): '<Root>/PCI-6229 DO1' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DO1' (donipcim) */
  {
    SimStruct *rts = homing_ldm_M->childSfunctions[5];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (encnipcim): '<Root>/PCI 6229 ENC ' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC ' (encnipcim) */
  {
    SimStruct *rts = homing_ldm_M->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (encnipcim): '<Root>/PCI 6229 ENC 1' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 1' (encnipcim) */
  {
    SimStruct *rts = homing_ldm_M->childSfunctions[7];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S5>/UD' */
  homing_ldm_DW.UD_DSTATE = homing_ldm_P.DiscreteDerivative3_ICPrevScale;

  /* InitializeConditions for UnitDelay: '<S3>/UD' */
  homing_ldm_DW.UD_DSTATE_c = homing_ldm_P.DiscreteDerivative1_ICPrevScale;

  /* InitializeConditions for UnitDelay: '<S2>/UD' */
  homing_ldm_DW.UD_DSTATE_p = homing_ldm_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for UnitDelay: '<S4>/UD' */
  homing_ldm_DW.UD_DSTATE_e = homing_ldm_P.DiscreteDerivative2_ICPrevScale;

  /* SystemInitialize for Chart: '<Root>/Chart' */
  homing_ldm_DW.sfEvent = homing_ldm_CALL_EVENT;
  homing_ldm_DW.is_Homing = homing_ldm_IN_NO_ACTIVE_CHILD;
  homing_ldm_DW.is_active_c3_homing_ldm = 0U;
  homing_ldm_DW.is_c3_homing_ldm = homing_ldm_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
static void homing_ldm_terminate(void)
{
  /* Terminate for S-Function (dinipcim): '<Root>/PCI-6229 DI' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DI' (dinipcim) */
  {
    SimStruct *rts = homing_ldm_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (encnipcim): '<Root>/PCI 6229 ENC 2' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 2' (encnipcim) */
  {
    SimStruct *rts = homing_ldm_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (encnipcim): '<Root>/PCI 6229 ENC 3' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 3' (encnipcim) */
  {
    SimStruct *rts = homing_ldm_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (danipcim): '<Root>/PCI-6229 DA4' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DA4' (danipcim) */
  {
    SimStruct *rts = homing_ldm_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (danipcim): '<Root>/PCI-6229 DA5' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DA5' (danipcim) */
  {
    SimStruct *rts = homing_ldm_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (donipcim): '<Root>/PCI-6229 DO1' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DO1' (donipcim) */
  {
    SimStruct *rts = homing_ldm_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (encnipcim): '<Root>/PCI 6229 ENC ' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC ' (encnipcim) */
  {
    SimStruct *rts = homing_ldm_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (encnipcim): '<Root>/PCI 6229 ENC 1' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 1' (encnipcim) */
  {
    SimStruct *rts = homing_ldm_M->childSfunctions[7];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  homing_ldm_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  homing_ldm_update();
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
  homing_ldm_initialize();
}

void MdlTerminate(void)
{
  homing_ldm_terminate();
}

/* Registration function */
RT_MODEL_homing_ldm_T *homing_ldm(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)homing_ldm_M, 0,
                sizeof(RT_MODEL_homing_ldm_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&homing_ldm_M->solverInfo,
                          &homing_ldm_M->Timing.simTimeStep);
    rtsiSetTPtr(&homing_ldm_M->solverInfo, &rtmGetTPtr(homing_ldm_M));
    rtsiSetStepSizePtr(&homing_ldm_M->solverInfo,
                       &homing_ldm_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&homing_ldm_M->solverInfo, (&rtmGetErrorStatus
      (homing_ldm_M)));
    rtsiSetRTModelPtr(&homing_ldm_M->solverInfo, homing_ldm_M);
  }

  rtsiSetSimTimeStep(&homing_ldm_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&homing_ldm_M->solverInfo,"FixedStepDiscrete");
  homing_ldm_M->solverInfoPtr = (&homing_ldm_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = homing_ldm_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    homing_ldm_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    homing_ldm_M->Timing.sampleTimes = (&homing_ldm_M->Timing.sampleTimesArray[0]);
    homing_ldm_M->Timing.offsetTimes = (&homing_ldm_M->Timing.offsetTimesArray[0]);

    /* task periods */
    homing_ldm_M->Timing.sampleTimes[0] = (0.0);
    homing_ldm_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    homing_ldm_M->Timing.offsetTimes[0] = (0.0);
    homing_ldm_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(homing_ldm_M, &homing_ldm_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = homing_ldm_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    homing_ldm_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(homing_ldm_M, -1);
  homing_ldm_M->Timing.stepSize0 = 0.001;
  homing_ldm_M->Timing.stepSize1 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    homing_ldm_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(homing_ldm_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(homing_ldm_M->rtwLogInfo, (NULL));
    rtliSetLogT(homing_ldm_M->rtwLogInfo, "tout");
    rtliSetLogX(homing_ldm_M->rtwLogInfo, "");
    rtliSetLogXFinal(homing_ldm_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(homing_ldm_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(homing_ldm_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(homing_ldm_M->rtwLogInfo, 0);
    rtliSetLogDecimation(homing_ldm_M->rtwLogInfo, 1);
    rtliSetLogY(homing_ldm_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(homing_ldm_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(homing_ldm_M->rtwLogInfo, (NULL));
  }

  homing_ldm_M->solverInfoPtr = (&homing_ldm_M->solverInfo);
  homing_ldm_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&homing_ldm_M->solverInfo, 0.001);
  rtsiSetSolverMode(&homing_ldm_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  homing_ldm_M->blockIO = ((void *) &homing_ldm_B);
  (void) memset(((void *) &homing_ldm_B), 0,
                sizeof(B_homing_ldm_T));

  /* parameters */
  homing_ldm_M->defaultParam = ((real_T *)&homing_ldm_P);

  /* states (dwork) */
  homing_ldm_M->dwork = ((void *) &homing_ldm_DW);
  (void) memset((void *)&homing_ldm_DW, 0,
                sizeof(DW_homing_ldm_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  homing_ldm_InitializeDataMapInfo(homing_ldm_M);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &homing_ldm_M->NonInlinedSFcns.sfcnInfo;
    homing_ldm_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(homing_ldm_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &homing_ldm_M->Sizes.numSampTimes);
    homing_ldm_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(homing_ldm_M)[0]);
    homing_ldm_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(homing_ldm_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,homing_ldm_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(homing_ldm_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(homing_ldm_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(homing_ldm_M));
    rtssSetStepSizePtr(sfcnInfo, &homing_ldm_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(homing_ldm_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo, &homing_ldm_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &homing_ldm_M->zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &homing_ldm_M->blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &homing_ldm_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &homing_ldm_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &homing_ldm_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &homing_ldm_M->solverInfoPtr);
  }

  homing_ldm_M->Sizes.numSFcns = (8);

  /* register each child */
  {
    (void) memset((void *)&homing_ldm_M->NonInlinedSFcns.childSFunctions[0], 0,
                  8*sizeof(SimStruct));
    homing_ldm_M->childSfunctions =
      (&homing_ldm_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 8; i++) {
        homing_ldm_M->childSfunctions[i] =
          (&homing_ldm_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: homing_ldm/<Root>/PCI-6229 DI (dinipcim) */
    {
      SimStruct *rts = homing_ldm_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = homing_ldm_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = homing_ldm_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = homing_ldm_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &homing_ldm_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, homing_ldm_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &homing_ldm_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &homing_ldm_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &homing_ldm_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &homing_ldm_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &homing_ldm_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &homing_ldm_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 4);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &homing_ldm_B.fcxsx));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &homing_ldm_B.fcxdx));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &homing_ldm_B.fcyhigh));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &homing_ldm_B.fcydown));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6229 DI");
      ssSetPath(rts, "homing_ldm/PCI-6229 DI");
      ssSetRTModel(rts,homing_ldm_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &homing_ldm_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)homing_ldm_P.PCI6229DI_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)homing_ldm_P.PCI6229DI_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)homing_ldm_P.PCI6229DI_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)homing_ldm_P.PCI6229DI_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)homing_ldm_P.PCI6229DI_P5_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &homing_ldm_DW.PCI6229DI_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &homing_ldm_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &homing_ldm_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &homing_ldm_DW.PCI6229DI_IWORK);
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

    /* Level2 S-Function Block: homing_ldm/<Root>/PCI 6229 ENC 2 (encnipcim) */
    {
      SimStruct *rts = homing_ldm_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = homing_ldm_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = homing_ldm_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = homing_ldm_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &homing_ldm_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, homing_ldm_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &homing_ldm_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &homing_ldm_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &homing_ldm_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &homing_ldm_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &homing_ldm_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &homing_ldm_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &homing_ldm_B.posizionecarrelloy));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI 6229 ENC 2");
      ssSetPath(rts, "homing_ldm/PCI 6229 ENC 2");
      ssSetRTModel(rts,homing_ldm_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &homing_ldm_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)homing_ldm_P.PCI6229ENC2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)homing_ldm_P.PCI6229ENC2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)homing_ldm_P.PCI6229ENC2_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)homing_ldm_P.PCI6229ENC2_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)homing_ldm_P.PCI6229ENC2_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)homing_ldm_P.PCI6229ENC2_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)homing_ldm_P.PCI6229ENC2_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)homing_ldm_P.PCI6229ENC2_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)homing_ldm_P.PCI6229ENC2_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)homing_ldm_P.PCI6229ENC2_P10_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &homing_ldm_DW.PCI6229ENC2_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &homing_ldm_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &homing_ldm_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &homing_ldm_DW.PCI6229ENC2_PWORK);
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

    /* Level2 S-Function Block: homing_ldm/<Root>/PCI 6229 ENC 3 (encnipcim) */
    {
      SimStruct *rts = homing_ldm_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = homing_ldm_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = homing_ldm_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = homing_ldm_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &homing_ldm_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, homing_ldm_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &homing_ldm_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &homing_ldm_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &homing_ldm_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &homing_ldm_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &homing_ldm_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &homing_ldm_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &homing_ldm_B.posizionecarrellox));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI 6229 ENC 3");
      ssSetPath(rts, "homing_ldm/PCI 6229 ENC 3");
      ssSetRTModel(rts,homing_ldm_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &homing_ldm_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)homing_ldm_P.PCI6229ENC3_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)homing_ldm_P.PCI6229ENC3_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)homing_ldm_P.PCI6229ENC3_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)homing_ldm_P.PCI6229ENC3_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)homing_ldm_P.PCI6229ENC3_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)homing_ldm_P.PCI6229ENC3_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)homing_ldm_P.PCI6229ENC3_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)homing_ldm_P.PCI6229ENC3_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)homing_ldm_P.PCI6229ENC3_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)homing_ldm_P.PCI6229ENC3_P10_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &homing_ldm_DW.PCI6229ENC3_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &homing_ldm_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &homing_ldm_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &homing_ldm_DW.PCI6229ENC3_PWORK);
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

    /* Level2 S-Function Block: homing_ldm/<Root>/PCI-6229 DA4 (danipcim) */
    {
      SimStruct *rts = homing_ldm_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = homing_ldm_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = homing_ldm_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = homing_ldm_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &homing_ldm_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, homing_ldm_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &homing_ldm_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &homing_ldm_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &homing_ldm_M->NonInlinedSFcns.methods4[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &homing_ldm_M->NonInlinedSFcns.statesInfo2[3]);
        ssSetPeriodicStatesInfo(rts,
          &homing_ldm_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &homing_ldm_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &homing_ldm_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &homing_ldm_B.Sum2;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6229 DA4");
      ssSetPath(rts, "homing_ldm/PCI-6229 DA4");
      ssSetRTModel(rts,homing_ldm_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &homing_ldm_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)homing_ldm_P.PCI6229DA4_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)homing_ldm_P.PCI6229DA4_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)homing_ldm_P.PCI6229DA4_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)homing_ldm_P.PCI6229DA4_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)homing_ldm_P.PCI6229DA4_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)homing_ldm_P.PCI6229DA4_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)homing_ldm_P.PCI6229DA4_P7_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &homing_ldm_DW.PCI6229DA4_RWORK[0]);
      ssSetIWork(rts, (int_T *) &homing_ldm_DW.PCI6229DA4_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &homing_ldm_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &homing_ldm_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &homing_ldm_DW.PCI6229DA4_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 41);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &homing_ldm_DW.PCI6229DA4_IWORK[0]);
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

    /* Level2 S-Function Block: homing_ldm/<Root>/PCI-6229 DA5 (danipcim) */
    {
      SimStruct *rts = homing_ldm_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = homing_ldm_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = homing_ldm_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = homing_ldm_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &homing_ldm_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, homing_ldm_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &homing_ldm_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &homing_ldm_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &homing_ldm_M->NonInlinedSFcns.methods4[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &homing_ldm_M->NonInlinedSFcns.statesInfo2[4]);
        ssSetPeriodicStatesInfo(rts,
          &homing_ldm_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &homing_ldm_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &homing_ldm_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &homing_ldm_B.Sum3;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6229 DA5");
      ssSetPath(rts, "homing_ldm/PCI-6229 DA5");
      ssSetRTModel(rts,homing_ldm_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &homing_ldm_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)homing_ldm_P.PCI6229DA5_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)homing_ldm_P.PCI6229DA5_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)homing_ldm_P.PCI6229DA5_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)homing_ldm_P.PCI6229DA5_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)homing_ldm_P.PCI6229DA5_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)homing_ldm_P.PCI6229DA5_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)homing_ldm_P.PCI6229DA5_P7_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &homing_ldm_DW.PCI6229DA5_RWORK[0]);
      ssSetIWork(rts, (int_T *) &homing_ldm_DW.PCI6229DA5_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &homing_ldm_M->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &homing_ldm_M->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &homing_ldm_DW.PCI6229DA5_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 41);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &homing_ldm_DW.PCI6229DA5_IWORK[0]);
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

    /* Level2 S-Function Block: homing_ldm/<Root>/PCI-6229 DO1 (donipcim) */
    {
      SimStruct *rts = homing_ldm_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = homing_ldm_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = homing_ldm_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = homing_ldm_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &homing_ldm_M->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, homing_ldm_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &homing_ldm_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &homing_ldm_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &homing_ldm_M->NonInlinedSFcns.methods4[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &homing_ldm_M->NonInlinedSFcns.statesInfo2[5]);
        ssSetPeriodicStatesInfo(rts,
          &homing_ldm_M->NonInlinedSFcns.periodicStatesInfo[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &homing_ldm_M->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &homing_ldm_M->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &homing_ldm_B.Constant1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6229 DO1");
      ssSetPath(rts, "homing_ldm/PCI-6229 DO1");
      ssSetRTModel(rts,homing_ldm_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &homing_ldm_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)homing_ldm_P.PCI6229DO1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)homing_ldm_P.PCI6229DO1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)homing_ldm_P.PCI6229DO1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)homing_ldm_P.PCI6229DO1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)homing_ldm_P.PCI6229DO1_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)homing_ldm_P.PCI6229DO1_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)homing_ldm_P.PCI6229DO1_P7_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &homing_ldm_DW.PCI6229DO1_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &homing_ldm_M->NonInlinedSFcns.Sfcn5.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &homing_ldm_M->NonInlinedSFcns.Sfcn5.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &homing_ldm_DW.PCI6229DO1_IWORK);
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

    /* Level2 S-Function Block: homing_ldm/<Root>/PCI 6229 ENC  (encnipcim) */
    {
      SimStruct *rts = homing_ldm_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = homing_ldm_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = homing_ldm_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = homing_ldm_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &homing_ldm_M->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, homing_ldm_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &homing_ldm_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &homing_ldm_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &homing_ldm_M->NonInlinedSFcns.methods4[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &homing_ldm_M->NonInlinedSFcns.statesInfo2[6]);
        ssSetPeriodicStatesInfo(rts,
          &homing_ldm_M->NonInlinedSFcns.periodicStatesInfo[6]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &homing_ldm_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &homing_ldm_B.posizionemotorex));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI 6229 ENC ");
      ssSetPath(rts, "homing_ldm/PCI 6229 ENC ");
      ssSetRTModel(rts,homing_ldm_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &homing_ldm_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)homing_ldm_P.PCI6229ENC_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)homing_ldm_P.PCI6229ENC_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)homing_ldm_P.PCI6229ENC_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)homing_ldm_P.PCI6229ENC_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)homing_ldm_P.PCI6229ENC_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)homing_ldm_P.PCI6229ENC_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)homing_ldm_P.PCI6229ENC_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)homing_ldm_P.PCI6229ENC_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)homing_ldm_P.PCI6229ENC_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)homing_ldm_P.PCI6229ENC_P10_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &homing_ldm_DW.PCI6229ENC_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &homing_ldm_M->NonInlinedSFcns.Sfcn6.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &homing_ldm_M->NonInlinedSFcns.Sfcn6.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &homing_ldm_DW.PCI6229ENC_PWORK);
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

    /* Level2 S-Function Block: homing_ldm/<Root>/PCI 6229 ENC 1 (encnipcim) */
    {
      SimStruct *rts = homing_ldm_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = homing_ldm_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = homing_ldm_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = homing_ldm_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &homing_ldm_M->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, homing_ldm_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &homing_ldm_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &homing_ldm_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &homing_ldm_M->NonInlinedSFcns.methods4[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &homing_ldm_M->NonInlinedSFcns.statesInfo2[7]);
        ssSetPeriodicStatesInfo(rts,
          &homing_ldm_M->NonInlinedSFcns.periodicStatesInfo[7]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &homing_ldm_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &homing_ldm_B.pozionemotorey));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI 6229 ENC 1");
      ssSetPath(rts, "homing_ldm/PCI 6229 ENC 1");
      ssSetRTModel(rts,homing_ldm_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &homing_ldm_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)homing_ldm_P.PCI6229ENC1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)homing_ldm_P.PCI6229ENC1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)homing_ldm_P.PCI6229ENC1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)homing_ldm_P.PCI6229ENC1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)homing_ldm_P.PCI6229ENC1_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)homing_ldm_P.PCI6229ENC1_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)homing_ldm_P.PCI6229ENC1_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)homing_ldm_P.PCI6229ENC1_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)homing_ldm_P.PCI6229ENC1_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)homing_ldm_P.PCI6229ENC1_P10_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &homing_ldm_DW.PCI6229ENC1_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &homing_ldm_M->NonInlinedSFcns.Sfcn7.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &homing_ldm_M->NonInlinedSFcns.Sfcn7.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &homing_ldm_DW.PCI6229ENC1_PWORK);
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
  homing_ldm_M->Sizes.numContStates = (0);/* Number of continuous states */
  homing_ldm_M->Sizes.numY = (0);      /* Number of model outputs */
  homing_ldm_M->Sizes.numU = (0);      /* Number of model inputs */
  homing_ldm_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  homing_ldm_M->Sizes.numSampTimes = (2);/* Number of sample times */
  homing_ldm_M->Sizes.numBlocks = (67);/* Number of blocks */
  homing_ldm_M->Sizes.numBlockIO = (45);/* Number of block outputs */
  homing_ldm_M->Sizes.numBlockPrms = (226);/* Sum of parameter "widths" */
  return homing_ldm_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
