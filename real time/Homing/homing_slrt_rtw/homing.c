/*
 * homing.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "homing".
 *
 * Model version              : 1.16
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Wed Nov 24 17:21:55 2021
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "homing_capi.h"
#include "homing.h"
#include "homing_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define homing_CALL_EVENT              (-1)
#define homing_IN_Fine                 ((uint8_T)1U)
#define homing_IN_Fine_homing1         ((uint8_T)2U)
#define homing_IN_Homing               ((uint8_T)1U)
#define homing_IN_Homing_x             ((uint8_T)3U)
#define homing_IN_NO_ACTIVE_CHILD      ((uint8_T)0U)

/* Block signals (auto storage) */
B_homing_T homing_B;

/* Block states (auto storage) */
DW_homing_T homing_DW;

/* Real-time model */
RT_MODEL_homing_T homing_M_;
RT_MODEL_homing_T *const homing_M = &homing_M_;

/* Model output function */
static void homing_output(void)
{
  boolean_T sf_internal_predicateOutput;
  real_T tmp;
  real_T tmp_0;

  /* S-Function (dinipcim): '<Root>/PCI-6229 DI' */

  /* Level2 S-Function Block: '<Root>/PCI-6229 DI' (dinipcim) */
  {
    SimStruct *rts = homing_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* S-Function (encnipcim): '<Root>/PCI 6229 ENC 2' */

  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 2' (encnipcim) */
  {
    SimStruct *rts = homing_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<Root>/Gain1' */
  homing_B.posizionecarrelloy_n = homing_P.Gain1_Gain *
    homing_B.posizionecarrelloy;

  /* S-Function (encnipcim): '<Root>/PCI 6229 ENC 3' */

  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 3' (encnipcim) */
  {
    SimStruct *rts = homing_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<Root>/Gain3' */
  homing_B.posizionecarrellox_n = homing_P.Gain3_Gain *
    homing_B.posizionecarrellox;

  /* SampleTimeMath: '<S4>/TSamp'
   *
   * About '<S4>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  homing_B.TSamp = homing_B.posizionecarrelloy_n * homing_P.TSamp_WtEt;

  /* UnitDelay: '<S4>/UD' */
  homing_B.Uk1 = homing_DW.UD_DSTATE;

  /* Sum: '<S4>/Diff' */
  homing_B.Diff = homing_B.TSamp - homing_B.Uk1;

  /* SampleTimeMath: '<S6>/TSamp'
   *
   * About '<S6>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  homing_B.TSamp_e = homing_B.posizionecarrellox_n * homing_P.TSamp_WtEt_b;

  /* UnitDelay: '<S6>/UD' */
  homing_B.Uk1_e = homing_DW.UD_DSTATE_a;

  /* Sum: '<S6>/Diff' */
  homing_B.Diff_p = homing_B.TSamp_e - homing_B.Uk1_e;

  /* Chart: '<Root>/Chart' */
  /* Gateway: Chart */
  homing_DW.sfEvent = homing_CALL_EVENT;

  /* During: Chart */
  if (homing_DW.is_active_c3_homing == 0U) {
    /* Entry: Chart */
    homing_DW.is_active_c3_homing = 1U;

    /* Entry Internal: Chart */
    /* Transition: '<S1>:45' */
    homing_DW.is_c3_homing = homing_IN_Homing;

    /* Entry Internal 'Homing': '<S1>:44' */
    /* Transition: '<S1>:27' */
    homing_DW.is_Homing = homing_IN_Homing_x;

    /* Entry 'Homing_x': '<S1>:26' */
    homing_DW.v_sp_x = -2.1;
    homing_DW.v_sp_y = 1.2;
    homing_B.ok_x = 1.0;
    homing_B.ok_y = 1.0;
    homing_B.ok_x_2 = 0.0;
  } else {
    /* During 'Homing': '<S1>:44' */
    switch (homing_DW.is_Homing) {
     case homing_IN_Fine:
      homing_B.ok_x_2 = 0.0;
      homing_B.ok_y_2 = 0.0;

      /* During 'Fine': '<S1>:92' */
      break;

     case homing_IN_Fine_homing1:
      homing_B.ok_x_2 = 1.0;
      homing_B.ok_y = 0.0;
      homing_B.ok_x = 0.0;
      homing_B.ok_y_2 = 1.0;

      /* During 'Fine_homing1': '<S1>:59' */
      sf_internal_predicateOutput = ((homing_DW.dx > 0.5) && (homing_DW.dy > 0.5));
      if (sf_internal_predicateOutput) {
        /* Transition: '<S1>:93' */
        homing_DW.is_Homing = homing_IN_Fine;

        /* Entry 'Fine': '<S1>:92' */
        homing_B.ok_y_2 = 0.0;
        homing_B.ok_x_2 = 0.0;
      } else {
        homing_B.Vel_x_out = homing_DW.v_sp_x - homing_B.Diff_p;
        homing_DW.dx = homing_B.posizionecarrellox_n - homing_DW.bx;
        if (homing_DW.dx > 0.5) {
          homing_B.Vel_x_out = 0.0;
        }

        homing_B.Vel_y_out = homing_DW.v_sp_y - homing_B.Diff;
        homing_DW.dy = fabs(homing_B.posizionecarrelloy_n - homing_DW.by);
        if (homing_DW.dy > 0.5) {
          homing_B.Vel_y_out = 0.0;
        }
      }
      break;

     default:
      homing_B.ok_x_2 = 0.0;
      homing_B.ok_y = 1.0;
      homing_B.ok_x = 1.0;

      /* During 'Homing_x': '<S1>:26' */
      sf_internal_predicateOutput = ((homing_B.fcxsx == 0.0) &&
        (homing_B.fcydown == 0.0));
      if (sf_internal_predicateOutput) {
        /* Transition: '<S1>:104' */
        homing_DW.is_Homing = homing_IN_Fine_homing1;

        /* Entry 'Fine_homing1': '<S1>:59' */
        homing_B.ok_y = 0.0;
        homing_B.ok_x = 0.0;
        homing_DW.bx = homing_B.posizionecarrellox_n;
        homing_DW.by = homing_B.posizionecarrelloy_n;
        homing_DW.v_sp_x = 2.1;
        homing_DW.v_sp_y = -1.2;
        homing_B.ok_x_2 = 1.0;
        homing_B.ok_y_2 = 1.0;
      } else {
        homing_B.Vel_x_out = homing_DW.v_sp_x - homing_B.Diff_p;
        homing_B.Vel_y_out = homing_DW.v_sp_y - homing_B.Diff;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* Gain: '<Root>/Gain4' */
  homing_B.Gain4 = homing_P.Gain4_Gain * homing_B.Vel_x_out;

  /* DotProduct: '<Root>/Dot Product3' */
  tmp = homing_B.Gain4;
  tmp_0 = homing_B.ok_x;
  homing_B.DotProduct3 = tmp * tmp_0;

  /* Gain: '<Root>/Gain8' */
  homing_B.Gain8 = homing_P.Gain8_Gain * homing_B.Vel_x_out;

  /* DotProduct: '<Root>/Dot Product5' */
  tmp = homing_B.Gain8;
  tmp_0 = homing_B.ok_x_2;
  homing_B.DotProduct5 = tmp * tmp_0;

  /* Sum: '<Root>/Sum2' */
  homing_B.Sum2 = homing_B.DotProduct3 + homing_B.DotProduct5;

  /* S-Function (danipcim): '<Root>/PCI-6229 DA4' */

  /* Level2 S-Function Block: '<Root>/PCI-6229 DA4' (danipcim) */
  {
    SimStruct *rts = homing_M->childSfunctions[3];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<Root>/Gain7' */
  homing_B.Gain7 = homing_P.Gain7_Gain * homing_B.Vel_y_out;

  /* DotProduct: '<Root>/Dot Product4' */
  tmp = homing_B.Gain7;
  tmp_0 = homing_B.ok_y;
  homing_B.DotProduct4 = tmp * tmp_0;

  /* Gain: '<Root>/Gain9' */
  homing_B.Gain9 = homing_P.Gain9_Gain * homing_B.Vel_y_out;

  /* DotProduct: '<Root>/Dot Product6' */
  tmp = homing_B.Gain9;
  tmp_0 = homing_B.ok_y_2;
  homing_B.DotProduct6 = tmp * tmp_0;

  /* Sum: '<Root>/Sum3' */
  homing_B.Sum3 = homing_B.DotProduct4 + homing_B.DotProduct6;

  /* S-Function (danipcim): '<Root>/PCI-6229 DA5' */

  /* Level2 S-Function Block: '<Root>/PCI-6229 DA5' (danipcim) */
  {
    SimStruct *rts = homing_M->childSfunctions[4];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<Root>/Constant1' */
  homing_B.Constant1 = homing_P.Constant1_Value;

  /* S-Function (donipcim): '<Root>/PCI-6229 DO1' */

  /* Level2 S-Function Block: '<Root>/PCI-6229 DO1' (donipcim) */
  {
    SimStruct *rts = homing_M->childSfunctions[5];
    sfcnOutputs(rts,0);
  }

  /* S-Function (encnipcim): '<Root>/PCI 6229 ENC ' */

  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC ' (encnipcim) */
  {
    SimStruct *rts = homing_M->childSfunctions[6];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<Root>/Gain' */
  homing_B.posizionemotorex_n = homing_P.Gain_Gain * homing_B.posizionemotorex;

  /* SampleTimeMath: '<S3>/TSamp'
   *
   * About '<S3>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  homing_B.TSamp_m = homing_B.posizionemotorex_n * homing_P.TSamp_WtEt_e;

  /* UnitDelay: '<S3>/UD' */
  homing_B.Uk1_j = homing_DW.UD_DSTATE_p;

  /* Sum: '<S3>/Diff' */
  homing_B.Diff_a = homing_B.TSamp_m - homing_B.Uk1_j;

  /* S-Function (encnipcim): '<Root>/PCI 6229 ENC 1' */

  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 1' (encnipcim) */
  {
    SimStruct *rts = homing_M->childSfunctions[7];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<Root>/Gain2' */
  homing_B.posizionemotorey = homing_P.Gain2_Gain * homing_B.pozionemotorey;

  /* SampleTimeMath: '<S5>/TSamp'
   *
   * About '<S5>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  homing_B.TSamp_d = homing_B.posizionemotorey * homing_P.TSamp_WtEt_f;

  /* UnitDelay: '<S5>/UD' */
  homing_B.Uk1_jq = homing_DW.UD_DSTATE_e;

  /* Sum: '<S5>/Diff' */
  homing_B.Diff_i = homing_B.TSamp_d - homing_B.Uk1_jq;
}

/* Model update function */
static void homing_update(void)
{
  /* Update for UnitDelay: '<S4>/UD' */
  homing_DW.UD_DSTATE = homing_B.TSamp;

  /* Update for UnitDelay: '<S6>/UD' */
  homing_DW.UD_DSTATE_a = homing_B.TSamp_e;

  /* Update for UnitDelay: '<S3>/UD' */
  homing_DW.UD_DSTATE_p = homing_B.TSamp_m;

  /* Update for UnitDelay: '<S5>/UD' */
  homing_DW.UD_DSTATE_e = homing_B.TSamp_d;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++homing_M->Timing.clockTick0)) {
    ++homing_M->Timing.clockTickH0;
  }

  homing_M->Timing.t[0] = homing_M->Timing.clockTick0 *
    homing_M->Timing.stepSize0 + homing_M->Timing.clockTickH0 *
    homing_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void homing_initialize(void)
{
  /* Start for S-Function (dinipcim): '<Root>/PCI-6229 DI' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DI' (dinipcim) */
  {
    SimStruct *rts = homing_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (encnipcim): '<Root>/PCI 6229 ENC 2' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 2' (encnipcim) */
  {
    SimStruct *rts = homing_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (encnipcim): '<Root>/PCI 6229 ENC 3' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 3' (encnipcim) */
  {
    SimStruct *rts = homing_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (danipcim): '<Root>/PCI-6229 DA4' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DA4' (danipcim) */
  {
    SimStruct *rts = homing_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (danipcim): '<Root>/PCI-6229 DA5' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DA5' (danipcim) */
  {
    SimStruct *rts = homing_M->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<Root>/Constant1' */
  homing_B.Constant1 = homing_P.Constant1_Value;

  /* Start for S-Function (donipcim): '<Root>/PCI-6229 DO1' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DO1' (donipcim) */
  {
    SimStruct *rts = homing_M->childSfunctions[5];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (encnipcim): '<Root>/PCI 6229 ENC ' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC ' (encnipcim) */
  {
    SimStruct *rts = homing_M->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (encnipcim): '<Root>/PCI 6229 ENC 1' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 1' (encnipcim) */
  {
    SimStruct *rts = homing_M->childSfunctions[7];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S4>/UD' */
  homing_DW.UD_DSTATE = homing_P.DiscreteDerivative1_ICPrevScale;

  /* InitializeConditions for UnitDelay: '<S6>/UD' */
  homing_DW.UD_DSTATE_a = homing_P.DiscreteDerivative3_ICPrevScale;

  /* InitializeConditions for UnitDelay: '<S3>/UD' */
  homing_DW.UD_DSTATE_p = homing_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for UnitDelay: '<S5>/UD' */
  homing_DW.UD_DSTATE_e = homing_P.DiscreteDerivative2_ICPrevScale;

  /* SystemInitialize for Chart: '<Root>/Chart' */
  homing_DW.sfEvent = homing_CALL_EVENT;
  homing_DW.is_Homing = homing_IN_NO_ACTIVE_CHILD;
  homing_DW.is_active_c3_homing = 0U;
  homing_DW.is_c3_homing = homing_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
static void homing_terminate(void)
{
  /* Terminate for S-Function (dinipcim): '<Root>/PCI-6229 DI' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DI' (dinipcim) */
  {
    SimStruct *rts = homing_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (encnipcim): '<Root>/PCI 6229 ENC 2' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 2' (encnipcim) */
  {
    SimStruct *rts = homing_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (encnipcim): '<Root>/PCI 6229 ENC 3' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 3' (encnipcim) */
  {
    SimStruct *rts = homing_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (danipcim): '<Root>/PCI-6229 DA4' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DA4' (danipcim) */
  {
    SimStruct *rts = homing_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (danipcim): '<Root>/PCI-6229 DA5' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DA5' (danipcim) */
  {
    SimStruct *rts = homing_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (donipcim): '<Root>/PCI-6229 DO1' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DO1' (donipcim) */
  {
    SimStruct *rts = homing_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (encnipcim): '<Root>/PCI 6229 ENC ' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC ' (encnipcim) */
  {
    SimStruct *rts = homing_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (encnipcim): '<Root>/PCI 6229 ENC 1' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 1' (encnipcim) */
  {
    SimStruct *rts = homing_M->childSfunctions[7];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  homing_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  homing_update();
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
  homing_initialize();
}

void MdlTerminate(void)
{
  homing_terminate();
}

/* Registration function */
RT_MODEL_homing_T *homing(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)homing_M, 0,
                sizeof(RT_MODEL_homing_T));
  rtsiSetSolverName(&homing_M->solverInfo,"FixedStepDiscrete");
  homing_M->solverInfoPtr = (&homing_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = homing_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    homing_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    homing_M->Timing.sampleTimes = (&homing_M->Timing.sampleTimesArray[0]);
    homing_M->Timing.offsetTimes = (&homing_M->Timing.offsetTimesArray[0]);

    /* task periods */
    homing_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    homing_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(homing_M, &homing_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = homing_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    homing_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(homing_M, -1);
  homing_M->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    homing_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(homing_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(homing_M->rtwLogInfo, (NULL));
    rtliSetLogT(homing_M->rtwLogInfo, "tout");
    rtliSetLogX(homing_M->rtwLogInfo, "");
    rtliSetLogXFinal(homing_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(homing_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(homing_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(homing_M->rtwLogInfo, 0);
    rtliSetLogDecimation(homing_M->rtwLogInfo, 1);
    rtliSetLogY(homing_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(homing_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(homing_M->rtwLogInfo, (NULL));
  }

  homing_M->solverInfoPtr = (&homing_M->solverInfo);
  homing_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&homing_M->solverInfo, 0.001);
  rtsiSetSolverMode(&homing_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  homing_M->blockIO = ((void *) &homing_B);
  (void) memset(((void *) &homing_B), 0,
                sizeof(B_homing_T));

  /* parameters */
  homing_M->defaultParam = ((real_T *)&homing_P);

  /* states (dwork) */
  homing_M->dwork = ((void *) &homing_DW);
  (void) memset((void *)&homing_DW, 0,
                sizeof(DW_homing_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  homing_InitializeDataMapInfo(homing_M);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &homing_M->NonInlinedSFcns.sfcnInfo;
    homing_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(homing_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &homing_M->Sizes.numSampTimes);
    homing_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(homing_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,homing_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(homing_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(homing_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(homing_M));
    rtssSetStepSizePtr(sfcnInfo, &homing_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(homing_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo, &homing_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &homing_M->zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &homing_M->blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &homing_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &homing_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &homing_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &homing_M->solverInfoPtr);
  }

  homing_M->Sizes.numSFcns = (8);

  /* register each child */
  {
    (void) memset((void *)&homing_M->NonInlinedSFcns.childSFunctions[0], 0,
                  8*sizeof(SimStruct));
    homing_M->childSfunctions = (&homing_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 8; i++) {
        homing_M->childSfunctions[i] =
          (&homing_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: homing/<Root>/PCI-6229 DI (dinipcim) */
    {
      SimStruct *rts = homing_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = homing_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = homing_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = homing_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &homing_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, homing_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &homing_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &homing_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &homing_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &homing_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &homing_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &homing_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 4);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &homing_B.fcxsx));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &homing_B.fcxdx));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &homing_B.fcyhigh));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &homing_B.fcydown));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6229 DI");
      ssSetPath(rts, "homing/PCI-6229 DI");
      ssSetRTModel(rts,homing_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &homing_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)homing_P.PCI6229DI_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)homing_P.PCI6229DI_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)homing_P.PCI6229DI_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)homing_P.PCI6229DI_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)homing_P.PCI6229DI_P5_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &homing_DW.PCI6229DI_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &homing_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &homing_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &homing_DW.PCI6229DI_IWORK);
      }

      /* registration */
      dinipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

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

    /* Level2 S-Function Block: homing/<Root>/PCI 6229 ENC 2 (encnipcim) */
    {
      SimStruct *rts = homing_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = homing_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = homing_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = homing_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &homing_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, homing_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &homing_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &homing_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &homing_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &homing_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &homing_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &homing_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &homing_B.posizionecarrelloy));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI 6229 ENC 2");
      ssSetPath(rts, "homing/PCI 6229 ENC 2");
      ssSetRTModel(rts,homing_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &homing_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)homing_P.PCI6229ENC2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)homing_P.PCI6229ENC2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)homing_P.PCI6229ENC2_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)homing_P.PCI6229ENC2_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)homing_P.PCI6229ENC2_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)homing_P.PCI6229ENC2_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)homing_P.PCI6229ENC2_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)homing_P.PCI6229ENC2_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)homing_P.PCI6229ENC2_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)homing_P.PCI6229ENC2_P10_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &homing_DW.PCI6229ENC2_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &homing_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &homing_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &homing_DW.PCI6229ENC2_PWORK);
      }

      /* registration */
      encnipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: homing/<Root>/PCI 6229 ENC 3 (encnipcim) */
    {
      SimStruct *rts = homing_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = homing_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = homing_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = homing_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &homing_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, homing_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &homing_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &homing_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &homing_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &homing_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &homing_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &homing_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &homing_B.posizionecarrellox));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI 6229 ENC 3");
      ssSetPath(rts, "homing/PCI 6229 ENC 3");
      ssSetRTModel(rts,homing_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &homing_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)homing_P.PCI6229ENC3_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)homing_P.PCI6229ENC3_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)homing_P.PCI6229ENC3_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)homing_P.PCI6229ENC3_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)homing_P.PCI6229ENC3_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)homing_P.PCI6229ENC3_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)homing_P.PCI6229ENC3_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)homing_P.PCI6229ENC3_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)homing_P.PCI6229ENC3_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)homing_P.PCI6229ENC3_P10_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &homing_DW.PCI6229ENC3_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &homing_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &homing_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &homing_DW.PCI6229ENC3_PWORK);
      }

      /* registration */
      encnipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: homing/<Root>/PCI-6229 DA4 (danipcim) */
    {
      SimStruct *rts = homing_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = homing_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = homing_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = homing_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &homing_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, homing_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &homing_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &homing_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &homing_M->NonInlinedSFcns.methods4[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &homing_M->NonInlinedSFcns.statesInfo2[3]);
        ssSetPeriodicStatesInfo(rts,
          &homing_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &homing_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &homing_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &homing_B.Sum2;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6229 DA4");
      ssSetPath(rts, "homing/PCI-6229 DA4");
      ssSetRTModel(rts,homing_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &homing_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)homing_P.PCI6229DA4_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)homing_P.PCI6229DA4_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)homing_P.PCI6229DA4_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)homing_P.PCI6229DA4_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)homing_P.PCI6229DA4_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)homing_P.PCI6229DA4_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)homing_P.PCI6229DA4_P7_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &homing_DW.PCI6229DA4_RWORK[0]);
      ssSetIWork(rts, (int_T *) &homing_DW.PCI6229DA4_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &homing_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &homing_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &homing_DW.PCI6229DA4_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 41);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &homing_DW.PCI6229DA4_IWORK[0]);
      }

      /* registration */
      danipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: homing/<Root>/PCI-6229 DA5 (danipcim) */
    {
      SimStruct *rts = homing_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = homing_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = homing_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = homing_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &homing_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, homing_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &homing_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &homing_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &homing_M->NonInlinedSFcns.methods4[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &homing_M->NonInlinedSFcns.statesInfo2[4]);
        ssSetPeriodicStatesInfo(rts,
          &homing_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &homing_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &homing_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &homing_B.Sum3;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6229 DA5");
      ssSetPath(rts, "homing/PCI-6229 DA5");
      ssSetRTModel(rts,homing_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &homing_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)homing_P.PCI6229DA5_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)homing_P.PCI6229DA5_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)homing_P.PCI6229DA5_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)homing_P.PCI6229DA5_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)homing_P.PCI6229DA5_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)homing_P.PCI6229DA5_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)homing_P.PCI6229DA5_P7_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &homing_DW.PCI6229DA5_RWORK[0]);
      ssSetIWork(rts, (int_T *) &homing_DW.PCI6229DA5_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &homing_M->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &homing_M->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &homing_DW.PCI6229DA5_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 41);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &homing_DW.PCI6229DA5_IWORK[0]);
      }

      /* registration */
      danipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: homing/<Root>/PCI-6229 DO1 (donipcim) */
    {
      SimStruct *rts = homing_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = homing_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = homing_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = homing_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &homing_M->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, homing_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &homing_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &homing_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &homing_M->NonInlinedSFcns.methods4[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &homing_M->NonInlinedSFcns.statesInfo2[5]);
        ssSetPeriodicStatesInfo(rts,
          &homing_M->NonInlinedSFcns.periodicStatesInfo[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &homing_M->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &homing_M->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &homing_B.Constant1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6229 DO1");
      ssSetPath(rts, "homing/PCI-6229 DO1");
      ssSetRTModel(rts,homing_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &homing_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)homing_P.PCI6229DO1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)homing_P.PCI6229DO1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)homing_P.PCI6229DO1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)homing_P.PCI6229DO1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)homing_P.PCI6229DO1_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)homing_P.PCI6229DO1_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)homing_P.PCI6229DO1_P7_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &homing_DW.PCI6229DO1_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &homing_M->NonInlinedSFcns.Sfcn5.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &homing_M->NonInlinedSFcns.Sfcn5.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &homing_DW.PCI6229DO1_IWORK);
      }

      /* registration */
      donipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: homing/<Root>/PCI 6229 ENC  (encnipcim) */
    {
      SimStruct *rts = homing_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = homing_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = homing_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = homing_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &homing_M->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, homing_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &homing_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &homing_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &homing_M->NonInlinedSFcns.methods4[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &homing_M->NonInlinedSFcns.statesInfo2[6]);
        ssSetPeriodicStatesInfo(rts,
          &homing_M->NonInlinedSFcns.periodicStatesInfo[6]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &homing_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &homing_B.posizionemotorex));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI 6229 ENC ");
      ssSetPath(rts, "homing/PCI 6229 ENC ");
      ssSetRTModel(rts,homing_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &homing_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)homing_P.PCI6229ENC_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)homing_P.PCI6229ENC_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)homing_P.PCI6229ENC_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)homing_P.PCI6229ENC_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)homing_P.PCI6229ENC_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)homing_P.PCI6229ENC_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)homing_P.PCI6229ENC_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)homing_P.PCI6229ENC_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)homing_P.PCI6229ENC_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)homing_P.PCI6229ENC_P10_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &homing_DW.PCI6229ENC_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &homing_M->NonInlinedSFcns.Sfcn6.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &homing_M->NonInlinedSFcns.Sfcn6.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &homing_DW.PCI6229ENC_PWORK);
      }

      /* registration */
      encnipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: homing/<Root>/PCI 6229 ENC 1 (encnipcim) */
    {
      SimStruct *rts = homing_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = homing_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = homing_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = homing_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &homing_M->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, homing_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &homing_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &homing_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &homing_M->NonInlinedSFcns.methods4[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &homing_M->NonInlinedSFcns.statesInfo2[7]);
        ssSetPeriodicStatesInfo(rts,
          &homing_M->NonInlinedSFcns.periodicStatesInfo[7]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &homing_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &homing_B.pozionemotorey));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI 6229 ENC 1");
      ssSetPath(rts, "homing/PCI 6229 ENC 1");
      ssSetRTModel(rts,homing_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &homing_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)homing_P.PCI6229ENC1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)homing_P.PCI6229ENC1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)homing_P.PCI6229ENC1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)homing_P.PCI6229ENC1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)homing_P.PCI6229ENC1_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)homing_P.PCI6229ENC1_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)homing_P.PCI6229ENC1_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)homing_P.PCI6229ENC1_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)homing_P.PCI6229ENC1_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)homing_P.PCI6229ENC1_P10_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &homing_DW.PCI6229ENC1_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &homing_M->NonInlinedSFcns.Sfcn7.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &homing_M->NonInlinedSFcns.Sfcn7.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &homing_DW.PCI6229ENC1_PWORK);
      }

      /* registration */
      encnipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }
  }

  /* Initialize Sizes */
  homing_M->Sizes.numContStates = (0); /* Number of continuous states */
  homing_M->Sizes.numY = (0);          /* Number of model outputs */
  homing_M->Sizes.numU = (0);          /* Number of model inputs */
  homing_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  homing_M->Sizes.numSampTimes = (1);  /* Number of sample times */
  homing_M->Sizes.numBlocks = (60);    /* Number of blocks */
  homing_M->Sizes.numBlockIO = (41);   /* Number of block outputs */
  homing_M->Sizes.numBlockPrms = (226);/* Sum of parameter "widths" */
  return homing_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
