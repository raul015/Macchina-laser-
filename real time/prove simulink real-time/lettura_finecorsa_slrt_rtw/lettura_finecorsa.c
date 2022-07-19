/*
 * lettura_finecorsa.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "lettura_finecorsa".
 *
 * Model version              : 1.3
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Wed Jun 30 15:07:59 2021
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "lettura_finecorsa_capi.h"
#include "lettura_finecorsa.h"
#include "lettura_finecorsa_private.h"

/* Block signals (auto storage) */
B_lettura_finecorsa_T lettura_finecorsa_B;

/* Block states (auto storage) */
DW_lettura_finecorsa_T lettura_finecorsa_DW;

/* Real-time model */
RT_MODEL_lettura_finecorsa_T lettura_finecorsa_M_;
RT_MODEL_lettura_finecorsa_T *const lettura_finecorsa_M = &lettura_finecorsa_M_;

/* Model output function */
static void lettura_finecorsa_output(void)
{
  /* Constant: '<Root>/Constant1' */
  lettura_finecorsa_B.Constant1 = lettura_finecorsa_P.Constant1_Value;

  /* S-Function (donipcim): '<Root>/PCI-6229 DO1' */

  /* Level2 S-Function Block: '<Root>/PCI-6229 DO1' (donipcim) */
  {
    SimStruct *rts = lettura_finecorsa_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<Root>/Constant2' */
  lettura_finecorsa_B.Constant2 = lettura_finecorsa_P.Constant2_Value;

  /* S-Function (danipcim): '<Root>/PCI-6229 DA' */

  /* Level2 S-Function Block: '<Root>/PCI-6229 DA' (danipcim) */
  {
    SimStruct *rts = lettura_finecorsa_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<Root>/Constant3' */
  lettura_finecorsa_B.Constant3 = lettura_finecorsa_P.Constant3_Value;

  /* S-Function (danipcim): '<Root>/PCI-6229 DA1' */

  /* Level2 S-Function Block: '<Root>/PCI-6229 DA1' (danipcim) */
  {
    SimStruct *rts = lettura_finecorsa_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  /* S-Function (encnipcim): '<Root>/PCI 6229 ENC ' */

  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC ' (encnipcim) */
  {
    SimStruct *rts = lettura_finecorsa_M->childSfunctions[3];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<Root>/Gain' */
  lettura_finecorsa_B.posizionemotorex_n = lettura_finecorsa_P.Gain_Gain *
    lettura_finecorsa_B.posizionemotorex;

  /* SampleTimeMath: '<S2>/TSamp'
   *
   * About '<S2>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  lettura_finecorsa_B.TSamp = lettura_finecorsa_B.posizionemotorex_n *
    lettura_finecorsa_P.TSamp_WtEt;

  /* UnitDelay: '<S2>/UD' */
  lettura_finecorsa_B.Uk1 = lettura_finecorsa_DW.UD_DSTATE;

  /* Sum: '<S2>/Diff' */
  lettura_finecorsa_B.Diff = lettura_finecorsa_B.TSamp - lettura_finecorsa_B.Uk1;

  /* S-Function (encnipcim): '<Root>/PCI 6229 ENC 2' */

  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 2' (encnipcim) */
  {
    SimStruct *rts = lettura_finecorsa_M->childSfunctions[4];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<Root>/Gain1' */
  lettura_finecorsa_B.posizionecarrelloy_n = lettura_finecorsa_P.Gain1_Gain *
    lettura_finecorsa_B.posizionecarrelloy;

  /* SampleTimeMath: '<S3>/TSamp'
   *
   * About '<S3>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  lettura_finecorsa_B.TSamp_h = lettura_finecorsa_B.posizionecarrelloy_n *
    lettura_finecorsa_P.TSamp_WtEt_j;

  /* UnitDelay: '<S3>/UD' */
  lettura_finecorsa_B.Uk1_i = lettura_finecorsa_DW.UD_DSTATE_c;

  /* Sum: '<S3>/Diff' */
  lettura_finecorsa_B.Diff_d = lettura_finecorsa_B.TSamp_h -
    lettura_finecorsa_B.Uk1_i;

  /* S-Function (encnipcim): '<Root>/PCI 6229 ENC 1' */

  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 1' (encnipcim) */
  {
    SimStruct *rts = lettura_finecorsa_M->childSfunctions[5];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<Root>/Gain2' */
  lettura_finecorsa_B.posizionemotorey = lettura_finecorsa_P.Gain2_Gain *
    lettura_finecorsa_B.pozionemotorey;

  /* SampleTimeMath: '<S4>/TSamp'
   *
   * About '<S4>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  lettura_finecorsa_B.TSamp_d = lettura_finecorsa_B.posizionemotorey *
    lettura_finecorsa_P.TSamp_WtEt_f;

  /* UnitDelay: '<S4>/UD' */
  lettura_finecorsa_B.Uk1_j = lettura_finecorsa_DW.UD_DSTATE_e;

  /* Sum: '<S4>/Diff' */
  lettura_finecorsa_B.Diff_i = lettura_finecorsa_B.TSamp_d -
    lettura_finecorsa_B.Uk1_j;

  /* S-Function (encnipcim): '<Root>/PCI 6229 ENC 3' */

  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 3' (encnipcim) */
  {
    SimStruct *rts = lettura_finecorsa_M->childSfunctions[6];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<Root>/Gain3' */
  lettura_finecorsa_B.posizionecarrellox_n = lettura_finecorsa_P.Gain3_Gain *
    lettura_finecorsa_B.posizionecarrellox;

  /* SampleTimeMath: '<S5>/TSamp'
   *
   * About '<S5>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  lettura_finecorsa_B.TSamp_e = lettura_finecorsa_B.posizionecarrellox_n *
    lettura_finecorsa_P.TSamp_WtEt_b;

  /* UnitDelay: '<S5>/UD' */
  lettura_finecorsa_B.Uk1_e = lettura_finecorsa_DW.UD_DSTATE_a;

  /* Sum: '<S5>/Diff' */
  lettura_finecorsa_B.Diff_p = lettura_finecorsa_B.TSamp_e -
    lettura_finecorsa_B.Uk1_e;

  /* S-Function (dinipcim): '<Root>/PCI-6229 DI' */

  /* Level2 S-Function Block: '<Root>/PCI-6229 DI' (dinipcim) */
  {
    SimStruct *rts = lettura_finecorsa_M->childSfunctions[7];
    sfcnOutputs(rts,0);
  }
}

/* Model update function */
static void lettura_finecorsa_update(void)
{
  /* Update for UnitDelay: '<S2>/UD' */
  lettura_finecorsa_DW.UD_DSTATE = lettura_finecorsa_B.TSamp;

  /* Update for UnitDelay: '<S3>/UD' */
  lettura_finecorsa_DW.UD_DSTATE_c = lettura_finecorsa_B.TSamp_h;

  /* Update for UnitDelay: '<S4>/UD' */
  lettura_finecorsa_DW.UD_DSTATE_e = lettura_finecorsa_B.TSamp_d;

  /* Update for UnitDelay: '<S5>/UD' */
  lettura_finecorsa_DW.UD_DSTATE_a = lettura_finecorsa_B.TSamp_e;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++lettura_finecorsa_M->Timing.clockTick0)) {
    ++lettura_finecorsa_M->Timing.clockTickH0;
  }

  lettura_finecorsa_M->Timing.t[0] = lettura_finecorsa_M->Timing.clockTick0 *
    lettura_finecorsa_M->Timing.stepSize0 +
    lettura_finecorsa_M->Timing.clockTickH0 *
    lettura_finecorsa_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void lettura_finecorsa_initialize(void)
{
  /* Start for Constant: '<Root>/Constant1' */
  lettura_finecorsa_B.Constant1 = lettura_finecorsa_P.Constant1_Value;

  /* Start for S-Function (donipcim): '<Root>/PCI-6229 DO1' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DO1' (donipcim) */
  {
    SimStruct *rts = lettura_finecorsa_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<Root>/Constant2' */
  lettura_finecorsa_B.Constant2 = lettura_finecorsa_P.Constant2_Value;

  /* Start for S-Function (danipcim): '<Root>/PCI-6229 DA' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DA' (danipcim) */
  {
    SimStruct *rts = lettura_finecorsa_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<Root>/Constant3' */
  lettura_finecorsa_B.Constant3 = lettura_finecorsa_P.Constant3_Value;

  /* Start for S-Function (danipcim): '<Root>/PCI-6229 DA1' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DA1' (danipcim) */
  {
    SimStruct *rts = lettura_finecorsa_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (encnipcim): '<Root>/PCI 6229 ENC ' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC ' (encnipcim) */
  {
    SimStruct *rts = lettura_finecorsa_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (encnipcim): '<Root>/PCI 6229 ENC 2' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 2' (encnipcim) */
  {
    SimStruct *rts = lettura_finecorsa_M->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (encnipcim): '<Root>/PCI 6229 ENC 1' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 1' (encnipcim) */
  {
    SimStruct *rts = lettura_finecorsa_M->childSfunctions[5];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (encnipcim): '<Root>/PCI 6229 ENC 3' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 3' (encnipcim) */
  {
    SimStruct *rts = lettura_finecorsa_M->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dinipcim): '<Root>/PCI-6229 DI' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DI' (dinipcim) */
  {
    SimStruct *rts = lettura_finecorsa_M->childSfunctions[7];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S2>/UD' */
  lettura_finecorsa_DW.UD_DSTATE =
    lettura_finecorsa_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for UnitDelay: '<S3>/UD' */
  lettura_finecorsa_DW.UD_DSTATE_c =
    lettura_finecorsa_P.DiscreteDerivative1_ICPrevScale;

  /* InitializeConditions for UnitDelay: '<S4>/UD' */
  lettura_finecorsa_DW.UD_DSTATE_e =
    lettura_finecorsa_P.DiscreteDerivative2_ICPrevScale;

  /* InitializeConditions for UnitDelay: '<S5>/UD' */
  lettura_finecorsa_DW.UD_DSTATE_a =
    lettura_finecorsa_P.DiscreteDerivative3_ICPrevScale;
}

/* Model terminate function */
static void lettura_finecorsa_terminate(void)
{
  /* Terminate for S-Function (donipcim): '<Root>/PCI-6229 DO1' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DO1' (donipcim) */
  {
    SimStruct *rts = lettura_finecorsa_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (danipcim): '<Root>/PCI-6229 DA' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DA' (danipcim) */
  {
    SimStruct *rts = lettura_finecorsa_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (danipcim): '<Root>/PCI-6229 DA1' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DA1' (danipcim) */
  {
    SimStruct *rts = lettura_finecorsa_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (encnipcim): '<Root>/PCI 6229 ENC ' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC ' (encnipcim) */
  {
    SimStruct *rts = lettura_finecorsa_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (encnipcim): '<Root>/PCI 6229 ENC 2' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 2' (encnipcim) */
  {
    SimStruct *rts = lettura_finecorsa_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (encnipcim): '<Root>/PCI 6229 ENC 1' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 1' (encnipcim) */
  {
    SimStruct *rts = lettura_finecorsa_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (encnipcim): '<Root>/PCI 6229 ENC 3' */
  /* Level2 S-Function Block: '<Root>/PCI 6229 ENC 3' (encnipcim) */
  {
    SimStruct *rts = lettura_finecorsa_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dinipcim): '<Root>/PCI-6229 DI' */
  /* Level2 S-Function Block: '<Root>/PCI-6229 DI' (dinipcim) */
  {
    SimStruct *rts = lettura_finecorsa_M->childSfunctions[7];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  lettura_finecorsa_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  lettura_finecorsa_update();
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
  lettura_finecorsa_initialize();
}

void MdlTerminate(void)
{
  lettura_finecorsa_terminate();
}

/* Registration function */
RT_MODEL_lettura_finecorsa_T *lettura_finecorsa(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)lettura_finecorsa_M, 0,
                sizeof(RT_MODEL_lettura_finecorsa_T));
  rtsiSetSolverName(&lettura_finecorsa_M->solverInfo,"FixedStepDiscrete");
  lettura_finecorsa_M->solverInfoPtr = (&lettura_finecorsa_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = lettura_finecorsa_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    lettura_finecorsa_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    lettura_finecorsa_M->Timing.sampleTimes =
      (&lettura_finecorsa_M->Timing.sampleTimesArray[0]);
    lettura_finecorsa_M->Timing.offsetTimes =
      (&lettura_finecorsa_M->Timing.offsetTimesArray[0]);

    /* task periods */
    lettura_finecorsa_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    lettura_finecorsa_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(lettura_finecorsa_M, &lettura_finecorsa_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = lettura_finecorsa_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    lettura_finecorsa_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(lettura_finecorsa_M, -1);
  lettura_finecorsa_M->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    lettura_finecorsa_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(lettura_finecorsa_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(lettura_finecorsa_M->rtwLogInfo, (NULL));
    rtliSetLogT(lettura_finecorsa_M->rtwLogInfo, "tout");
    rtliSetLogX(lettura_finecorsa_M->rtwLogInfo, "");
    rtliSetLogXFinal(lettura_finecorsa_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(lettura_finecorsa_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(lettura_finecorsa_M->rtwLogInfo, 2);
    rtliSetLogMaxRows(lettura_finecorsa_M->rtwLogInfo, 0);
    rtliSetLogDecimation(lettura_finecorsa_M->rtwLogInfo, 1);
    rtliSetLogY(lettura_finecorsa_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(lettura_finecorsa_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(lettura_finecorsa_M->rtwLogInfo, (NULL));
  }

  lettura_finecorsa_M->solverInfoPtr = (&lettura_finecorsa_M->solverInfo);
  lettura_finecorsa_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&lettura_finecorsa_M->solverInfo, 0.001);
  rtsiSetSolverMode(&lettura_finecorsa_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  lettura_finecorsa_M->blockIO = ((void *) &lettura_finecorsa_B);
  (void) memset(((void *) &lettura_finecorsa_B), 0,
                sizeof(B_lettura_finecorsa_T));

  /* parameters */
  lettura_finecorsa_M->defaultParam = ((real_T *)&lettura_finecorsa_P);

  /* states (dwork) */
  lettura_finecorsa_M->dwork = ((void *) &lettura_finecorsa_DW);
  (void) memset((void *)&lettura_finecorsa_DW, 0,
                sizeof(DW_lettura_finecorsa_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  lettura_finecorsa_InitializeDataMapInfo(lettura_finecorsa_M);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &lettura_finecorsa_M->NonInlinedSFcns.sfcnInfo;
    lettura_finecorsa_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(lettura_finecorsa_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &lettura_finecorsa_M->Sizes.numSampTimes);
    lettura_finecorsa_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (lettura_finecorsa_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,lettura_finecorsa_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(lettura_finecorsa_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(lettura_finecorsa_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (lettura_finecorsa_M));
    rtssSetStepSizePtr(sfcnInfo, &lettura_finecorsa_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(lettura_finecorsa_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &lettura_finecorsa_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &lettura_finecorsa_M->zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &lettura_finecorsa_M->blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &lettura_finecorsa_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &lettura_finecorsa_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &lettura_finecorsa_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &lettura_finecorsa_M->solverInfoPtr);
  }

  lettura_finecorsa_M->Sizes.numSFcns = (8);

  /* register each child */
  {
    (void) memset((void *)&lettura_finecorsa_M->NonInlinedSFcns.childSFunctions
                  [0], 0,
                  8*sizeof(SimStruct));
    lettura_finecorsa_M->childSfunctions =
      (&lettura_finecorsa_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 8; i++) {
        lettura_finecorsa_M->childSfunctions[i] =
          (&lettura_finecorsa_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: lettura_finecorsa/<Root>/PCI-6229 DO1 (donipcim) */
    {
      SimStruct *rts = lettura_finecorsa_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = lettura_finecorsa_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = lettura_finecorsa_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = lettura_finecorsa_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &lettura_finecorsa_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, lettura_finecorsa_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &lettura_finecorsa_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &lettura_finecorsa_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &lettura_finecorsa_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &lettura_finecorsa_M->NonInlinedSFcns.statesInfo2
                         [0]);
        ssSetPeriodicStatesInfo(rts,
          &lettura_finecorsa_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &lettura_finecorsa_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &lettura_finecorsa_B.Constant1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6229 DO1");
      ssSetPath(rts, "lettura_finecorsa/PCI-6229 DO1");
      ssSetRTModel(rts,lettura_finecorsa_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)lettura_finecorsa_P.PCI6229DO1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)lettura_finecorsa_P.PCI6229DO1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)lettura_finecorsa_P.PCI6229DO1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)lettura_finecorsa_P.PCI6229DO1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)lettura_finecorsa_P.PCI6229DO1_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)lettura_finecorsa_P.PCI6229DO1_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)lettura_finecorsa_P.PCI6229DO1_P7_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &lettura_finecorsa_DW.PCI6229DO1_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &lettura_finecorsa_DW.PCI6229DO1_IWORK);
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

    /* Level2 S-Function Block: lettura_finecorsa/<Root>/PCI-6229 DA (danipcim) */
    {
      SimStruct *rts = lettura_finecorsa_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = lettura_finecorsa_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = lettura_finecorsa_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = lettura_finecorsa_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &lettura_finecorsa_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, lettura_finecorsa_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &lettura_finecorsa_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &lettura_finecorsa_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &lettura_finecorsa_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &lettura_finecorsa_M->NonInlinedSFcns.statesInfo2
                         [1]);
        ssSetPeriodicStatesInfo(rts,
          &lettura_finecorsa_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &lettura_finecorsa_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &lettura_finecorsa_B.Constant2;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6229 DA");
      ssSetPath(rts, "lettura_finecorsa/PCI-6229 DA");
      ssSetRTModel(rts,lettura_finecorsa_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)lettura_finecorsa_P.PCI6229DA_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)lettura_finecorsa_P.PCI6229DA_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)lettura_finecorsa_P.PCI6229DA_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)lettura_finecorsa_P.PCI6229DA_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)lettura_finecorsa_P.PCI6229DA_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)lettura_finecorsa_P.PCI6229DA_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)lettura_finecorsa_P.PCI6229DA_P7_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &lettura_finecorsa_DW.PCI6229DA_RWORK[0]);
      ssSetIWork(rts, (int_T *) &lettura_finecorsa_DW.PCI6229DA_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &lettura_finecorsa_DW.PCI6229DA_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 41);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &lettura_finecorsa_DW.PCI6229DA_IWORK[0]);
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

    /* Level2 S-Function Block: lettura_finecorsa/<Root>/PCI-6229 DA1 (danipcim) */
    {
      SimStruct *rts = lettura_finecorsa_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = lettura_finecorsa_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = lettura_finecorsa_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = lettura_finecorsa_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &lettura_finecorsa_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, lettura_finecorsa_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &lettura_finecorsa_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &lettura_finecorsa_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &lettura_finecorsa_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &lettura_finecorsa_M->NonInlinedSFcns.statesInfo2
                         [2]);
        ssSetPeriodicStatesInfo(rts,
          &lettura_finecorsa_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &lettura_finecorsa_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &lettura_finecorsa_B.Constant3;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6229 DA1");
      ssSetPath(rts, "lettura_finecorsa/PCI-6229 DA1");
      ssSetRTModel(rts,lettura_finecorsa_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)lettura_finecorsa_P.PCI6229DA1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)lettura_finecorsa_P.PCI6229DA1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)lettura_finecorsa_P.PCI6229DA1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)lettura_finecorsa_P.PCI6229DA1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)lettura_finecorsa_P.PCI6229DA1_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)lettura_finecorsa_P.PCI6229DA1_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)lettura_finecorsa_P.PCI6229DA1_P7_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &lettura_finecorsa_DW.PCI6229DA1_RWORK[0]);
      ssSetIWork(rts, (int_T *) &lettura_finecorsa_DW.PCI6229DA1_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 6);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &lettura_finecorsa_DW.PCI6229DA1_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 41);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &lettura_finecorsa_DW.PCI6229DA1_IWORK[0]);
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

    /* Level2 S-Function Block: lettura_finecorsa/<Root>/PCI 6229 ENC  (encnipcim) */
    {
      SimStruct *rts = lettura_finecorsa_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = lettura_finecorsa_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = lettura_finecorsa_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = lettura_finecorsa_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &lettura_finecorsa_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, lettura_finecorsa_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &lettura_finecorsa_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &lettura_finecorsa_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &lettura_finecorsa_M->NonInlinedSFcns.methods4[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &lettura_finecorsa_M->NonInlinedSFcns.statesInfo2
                         [3]);
        ssSetPeriodicStatesInfo(rts,
          &lettura_finecorsa_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &lettura_finecorsa_B.posizionemotorex));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI 6229 ENC ");
      ssSetPath(rts, "lettura_finecorsa/PCI 6229 ENC ");
      ssSetRTModel(rts,lettura_finecorsa_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)lettura_finecorsa_P.PCI6229ENC_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)lettura_finecorsa_P.PCI6229ENC_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)lettura_finecorsa_P.PCI6229ENC_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)lettura_finecorsa_P.PCI6229ENC_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)lettura_finecorsa_P.PCI6229ENC_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)lettura_finecorsa_P.PCI6229ENC_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)lettura_finecorsa_P.PCI6229ENC_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)lettura_finecorsa_P.PCI6229ENC_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)lettura_finecorsa_P.PCI6229ENC_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)lettura_finecorsa_P.PCI6229ENC_P10_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &lettura_finecorsa_DW.PCI6229ENC_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &lettura_finecorsa_DW.PCI6229ENC_PWORK);
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

    /* Level2 S-Function Block: lettura_finecorsa/<Root>/PCI 6229 ENC 2 (encnipcim) */
    {
      SimStruct *rts = lettura_finecorsa_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = lettura_finecorsa_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = lettura_finecorsa_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = lettura_finecorsa_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &lettura_finecorsa_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, lettura_finecorsa_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &lettura_finecorsa_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &lettura_finecorsa_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &lettura_finecorsa_M->NonInlinedSFcns.methods4[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &lettura_finecorsa_M->NonInlinedSFcns.statesInfo2
                         [4]);
        ssSetPeriodicStatesInfo(rts,
          &lettura_finecorsa_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &lettura_finecorsa_B.posizionecarrelloy));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI 6229 ENC 2");
      ssSetPath(rts, "lettura_finecorsa/PCI 6229 ENC 2");
      ssSetRTModel(rts,lettura_finecorsa_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)lettura_finecorsa_P.PCI6229ENC2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)lettura_finecorsa_P.PCI6229ENC2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)lettura_finecorsa_P.PCI6229ENC2_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)lettura_finecorsa_P.PCI6229ENC2_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)lettura_finecorsa_P.PCI6229ENC2_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)lettura_finecorsa_P.PCI6229ENC2_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)lettura_finecorsa_P.PCI6229ENC2_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)lettura_finecorsa_P.PCI6229ENC2_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)lettura_finecorsa_P.PCI6229ENC2_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       lettura_finecorsa_P.PCI6229ENC2_P10_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &lettura_finecorsa_DW.PCI6229ENC2_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &lettura_finecorsa_DW.PCI6229ENC2_PWORK);
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

    /* Level2 S-Function Block: lettura_finecorsa/<Root>/PCI 6229 ENC 1 (encnipcim) */
    {
      SimStruct *rts = lettura_finecorsa_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = lettura_finecorsa_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = lettura_finecorsa_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = lettura_finecorsa_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &lettura_finecorsa_M->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, lettura_finecorsa_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &lettura_finecorsa_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &lettura_finecorsa_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &lettura_finecorsa_M->NonInlinedSFcns.methods4[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &lettura_finecorsa_M->NonInlinedSFcns.statesInfo2
                         [5]);
        ssSetPeriodicStatesInfo(rts,
          &lettura_finecorsa_M->NonInlinedSFcns.periodicStatesInfo[5]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &lettura_finecorsa_B.pozionemotorey));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI 6229 ENC 1");
      ssSetPath(rts, "lettura_finecorsa/PCI 6229 ENC 1");
      ssSetRTModel(rts,lettura_finecorsa_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)lettura_finecorsa_P.PCI6229ENC1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)lettura_finecorsa_P.PCI6229ENC1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)lettura_finecorsa_P.PCI6229ENC1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)lettura_finecorsa_P.PCI6229ENC1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)lettura_finecorsa_P.PCI6229ENC1_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)lettura_finecorsa_P.PCI6229ENC1_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)lettura_finecorsa_P.PCI6229ENC1_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)lettura_finecorsa_P.PCI6229ENC1_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)lettura_finecorsa_P.PCI6229ENC1_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       lettura_finecorsa_P.PCI6229ENC1_P10_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &lettura_finecorsa_DW.PCI6229ENC1_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn5.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn5.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &lettura_finecorsa_DW.PCI6229ENC1_PWORK);
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

    /* Level2 S-Function Block: lettura_finecorsa/<Root>/PCI 6229 ENC 3 (encnipcim) */
    {
      SimStruct *rts = lettura_finecorsa_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = lettura_finecorsa_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = lettura_finecorsa_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = lettura_finecorsa_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &lettura_finecorsa_M->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, lettura_finecorsa_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &lettura_finecorsa_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &lettura_finecorsa_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &lettura_finecorsa_M->NonInlinedSFcns.methods4[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &lettura_finecorsa_M->NonInlinedSFcns.statesInfo2
                         [6]);
        ssSetPeriodicStatesInfo(rts,
          &lettura_finecorsa_M->NonInlinedSFcns.periodicStatesInfo[6]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &lettura_finecorsa_B.posizionecarrellox));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI 6229 ENC 3");
      ssSetPath(rts, "lettura_finecorsa/PCI 6229 ENC 3");
      ssSetRTModel(rts,lettura_finecorsa_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)lettura_finecorsa_P.PCI6229ENC3_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)lettura_finecorsa_P.PCI6229ENC3_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)lettura_finecorsa_P.PCI6229ENC3_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)lettura_finecorsa_P.PCI6229ENC3_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)lettura_finecorsa_P.PCI6229ENC3_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)lettura_finecorsa_P.PCI6229ENC3_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)lettura_finecorsa_P.PCI6229ENC3_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)lettura_finecorsa_P.PCI6229ENC3_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)lettura_finecorsa_P.PCI6229ENC3_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       lettura_finecorsa_P.PCI6229ENC3_P10_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &lettura_finecorsa_DW.PCI6229ENC3_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn6.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn6.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &lettura_finecorsa_DW.PCI6229ENC3_PWORK);
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

    /* Level2 S-Function Block: lettura_finecorsa/<Root>/PCI-6229 DI (dinipcim) */
    {
      SimStruct *rts = lettura_finecorsa_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = lettura_finecorsa_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = lettura_finecorsa_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = lettura_finecorsa_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &lettura_finecorsa_M->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, lettura_finecorsa_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &lettura_finecorsa_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &lettura_finecorsa_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &lettura_finecorsa_M->NonInlinedSFcns.methods4[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &lettura_finecorsa_M->NonInlinedSFcns.statesInfo2
                         [7]);
        ssSetPeriodicStatesInfo(rts,
          &lettura_finecorsa_M->NonInlinedSFcns.periodicStatesInfo[7]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 4);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &lettura_finecorsa_B.PCI6229DI_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &lettura_finecorsa_B.PCI6229DI_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &lettura_finecorsa_B.PCI6229DI_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            &lettura_finecorsa_B.PCI6229DI_o4));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6229 DI");
      ssSetPath(rts, "lettura_finecorsa/PCI-6229 DI");
      ssSetRTModel(rts,lettura_finecorsa_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)lettura_finecorsa_P.PCI6229DI_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)lettura_finecorsa_P.PCI6229DI_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)lettura_finecorsa_P.PCI6229DI_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)lettura_finecorsa_P.PCI6229DI_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)lettura_finecorsa_P.PCI6229DI_P5_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &lettura_finecorsa_DW.PCI6229DI_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn7.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &lettura_finecorsa_M->NonInlinedSFcns.Sfcn7.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &lettura_finecorsa_DW.PCI6229DI_IWORK);
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
  }

  /* Initialize Sizes */
  lettura_finecorsa_M->Sizes.numContStates = (0);/* Number of continuous states */
  lettura_finecorsa_M->Sizes.numY = (0);/* Number of model outputs */
  lettura_finecorsa_M->Sizes.numU = (0);/* Number of model inputs */
  lettura_finecorsa_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  lettura_finecorsa_M->Sizes.numSampTimes = (1);/* Number of sample times */
  lettura_finecorsa_M->Sizes.numBlocks = (52);/* Number of blocks */
  lettura_finecorsa_M->Sizes.numBlockIO = (27);/* Number of block outputs */
  lettura_finecorsa_M->Sizes.numBlockPrms = (224);/* Sum of parameter "widths" */
  return lettura_finecorsa_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
