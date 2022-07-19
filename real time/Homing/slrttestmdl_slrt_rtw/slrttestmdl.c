/*
 * slrttestmdl.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "slrttestmdl".
 *
 * Model version              : 1.16
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Wed Nov 24 15:39:27 2021
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "slrttestmdl_capi.h"
#include "slrttestmdl.h"
#include "slrttestmdl_private.h"

/* Block signals (auto storage) */
B_slrttestmdl_T slrttestmdl_B;

/* Continuous states */
X_slrttestmdl_T slrttestmdl_X;

/* Block states (auto storage) */
DW_slrttestmdl_T slrttestmdl_DW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_slrttestmdl_T slrttestmdl_Y;

/* Real-time model */
RT_MODEL_slrttestmdl_T slrttestmdl_M_;
RT_MODEL_slrttestmdl_T *const slrttestmdl_M = &slrttestmdl_M_;

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  slrttestmdl_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  slrttestmdl_output();
  slrttestmdl_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  slrttestmdl_output();
  slrttestmdl_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  slrttestmdl_output();
  slrttestmdl_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void slrttestmdl_output(void)
{
  real_T temp;
  if (rtmIsMajorTimeStep(slrttestmdl_M)) {
    /* set solver stop time */
    if (!(slrttestmdl_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&slrttestmdl_M->solverInfo,
                            ((slrttestmdl_M->Timing.clockTickH0 + 1) *
        slrttestmdl_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&slrttestmdl_M->solverInfo,
                            ((slrttestmdl_M->Timing.clockTick0 + 1) *
        slrttestmdl_M->Timing.stepSize0 + slrttestmdl_M->Timing.clockTickH0 *
        slrttestmdl_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(slrttestmdl_M)) {
    slrttestmdl_M->Timing.t[0] = rtsiGetT(&slrttestmdl_M->solverInfo);
  }

  /* Integrator: '<Root>/Integrator1' */
  slrttestmdl_B.Integrator1 = slrttestmdl_X.Integrator1_CSTATE;

  /* SignalGenerator: '<Root>/Signal Generator' */
  temp = slrttestmdl_P.SignalGenerator_Frequency * slrttestmdl_M->Timing.t[0];
  if (temp - floor(temp) >= 0.5) {
    slrttestmdl_B.SignalGenerator = slrttestmdl_P.SignalGenerator_Amplitude;
  } else {
    slrttestmdl_B.SignalGenerator = -slrttestmdl_P.SignalGenerator_Amplitude;
  }

  /* End of SignalGenerator: '<Root>/Signal Generator' */

  /* Outport: '<Root>/Outport' */
  slrttestmdl_Y.Outport[0] = slrttestmdl_B.Integrator1;
  slrttestmdl_Y.Outport[1] = slrttestmdl_B.SignalGenerator;
  if (rtmIsMajorTimeStep(slrttestmdl_M)) {
  }

  /* Gain: '<Root>/Gain' */
  slrttestmdl_B.Gain = slrttestmdl_P.Gain_Gain * slrttestmdl_B.Integrator1;

  /* Integrator: '<Root>/Integrator' */
  slrttestmdl_B.Integrator = slrttestmdl_X.Integrator_CSTATE;

  /* Gain: '<Root>/Gain1' */
  slrttestmdl_B.Gain1 = slrttestmdl_P.Gain1_Gain * slrttestmdl_B.Integrator;

  /* Gain: '<Root>/Gain2' */
  slrttestmdl_B.Gain2 = slrttestmdl_P.Gain2_Gain * slrttestmdl_B.SignalGenerator;

  /* Sum: '<Root>/Sum' */
  slrttestmdl_B.Sum = (slrttestmdl_B.Gain2 - slrttestmdl_B.Gain) -
    slrttestmdl_B.Gain1;
}

/* Model update function */
void slrttestmdl_update(void)
{
  if (rtmIsMajorTimeStep(slrttestmdl_M)) {
    rt_ertODEUpdateContinuousStates(&slrttestmdl_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++slrttestmdl_M->Timing.clockTick0)) {
    ++slrttestmdl_M->Timing.clockTickH0;
  }

  slrttestmdl_M->Timing.t[0] = rtsiGetSolverStopTime(&slrttestmdl_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.00025s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++slrttestmdl_M->Timing.clockTick1)) {
      ++slrttestmdl_M->Timing.clockTickH1;
    }

    slrttestmdl_M->Timing.t[1] = slrttestmdl_M->Timing.clockTick1 *
      slrttestmdl_M->Timing.stepSize1 + slrttestmdl_M->Timing.clockTickH1 *
      slrttestmdl_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void slrttestmdl_derivatives(void)
{
  XDot_slrttestmdl_T *_rtXdot;
  _rtXdot = ((XDot_slrttestmdl_T *) slrttestmdl_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = slrttestmdl_B.Integrator;

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = slrttestmdl_B.Sum;
}

/* Model initialize function */
void slrttestmdl_initialize(void)
{
  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  slrttestmdl_X.Integrator1_CSTATE = slrttestmdl_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  slrttestmdl_X.Integrator_CSTATE = slrttestmdl_P.Integrator_IC;
}

/* Model terminate function */
void slrttestmdl_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  slrttestmdl_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  slrttestmdl_update();
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
  slrttestmdl_initialize();
}

void MdlTerminate(void)
{
  slrttestmdl_terminate();
}

/* Registration function */
RT_MODEL_slrttestmdl_T *slrttestmdl(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)slrttestmdl_M, 0,
                sizeof(RT_MODEL_slrttestmdl_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&slrttestmdl_M->solverInfo,
                          &slrttestmdl_M->Timing.simTimeStep);
    rtsiSetTPtr(&slrttestmdl_M->solverInfo, &rtmGetTPtr(slrttestmdl_M));
    rtsiSetStepSizePtr(&slrttestmdl_M->solverInfo,
                       &slrttestmdl_M->Timing.stepSize0);
    rtsiSetdXPtr(&slrttestmdl_M->solverInfo, &slrttestmdl_M->derivs);
    rtsiSetContStatesPtr(&slrttestmdl_M->solverInfo, (real_T **)
                         &slrttestmdl_M->contStates);
    rtsiSetNumContStatesPtr(&slrttestmdl_M->solverInfo,
      &slrttestmdl_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&slrttestmdl_M->solverInfo,
      &slrttestmdl_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&slrttestmdl_M->solverInfo,
      &slrttestmdl_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&slrttestmdl_M->solverInfo,
      &slrttestmdl_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&slrttestmdl_M->solverInfo, (&rtmGetErrorStatus
      (slrttestmdl_M)));
    rtsiSetRTModelPtr(&slrttestmdl_M->solverInfo, slrttestmdl_M);
  }

  rtsiSetSimTimeStep(&slrttestmdl_M->solverInfo, MAJOR_TIME_STEP);
  slrttestmdl_M->intgData.y = slrttestmdl_M->odeY;
  slrttestmdl_M->intgData.f[0] = slrttestmdl_M->odeF[0];
  slrttestmdl_M->intgData.f[1] = slrttestmdl_M->odeF[1];
  slrttestmdl_M->intgData.f[2] = slrttestmdl_M->odeF[2];
  slrttestmdl_M->intgData.f[3] = slrttestmdl_M->odeF[3];
  slrttestmdl_M->contStates = ((real_T *) &slrttestmdl_X);
  rtsiSetSolverData(&slrttestmdl_M->solverInfo, (void *)&slrttestmdl_M->intgData);
  rtsiSetSolverName(&slrttestmdl_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = slrttestmdl_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    slrttestmdl_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    slrttestmdl_M->Timing.sampleTimes = (&slrttestmdl_M->
      Timing.sampleTimesArray[0]);
    slrttestmdl_M->Timing.offsetTimes = (&slrttestmdl_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    slrttestmdl_M->Timing.sampleTimes[0] = (0.0);
    slrttestmdl_M->Timing.sampleTimes[1] = (0.00025);

    /* task offsets */
    slrttestmdl_M->Timing.offsetTimes[0] = (0.0);
    slrttestmdl_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(slrttestmdl_M, &slrttestmdl_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = slrttestmdl_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    slrttestmdl_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(slrttestmdl_M, 0.2);
  slrttestmdl_M->Timing.stepSize0 = 0.00025;
  slrttestmdl_M->Timing.stepSize1 = 0.00025;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    slrttestmdl_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    /*
     * Set pointers to the data and signal info each state
     */
    {
      static int_T rt_LoggedStateWidths[] = {
        1,
        1
      };

      static int_T rt_LoggedStateNumDimensions[] = {
        1,
        1
      };

      static int_T rt_LoggedStateDimensions[] = {
        1,
        1
      };

      static boolean_T rt_LoggedStateIsVarDims[] = {
        0,
        0
      };

      static BuiltInDTypeId rt_LoggedStateDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedStateComplexSignals[] = {
        0,
        0
      };

      static const char_T *rt_LoggedStateLabels[] = {
        "CSTATE",
        "CSTATE"
      };

      static const char_T *rt_LoggedStateBlockNames[] = {
        "slrttestmdl/Integrator1",
        "slrttestmdl/Integrator"
      };

      static const char_T *rt_LoggedStateNames[] = {
        "",
        ""
      };

      static boolean_T rt_LoggedStateCrossMdlRef[] = {
        0,
        0
      };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedStateSignalInfo = {
        2,
        rt_LoggedStateWidths,
        rt_LoggedStateNumDimensions,
        rt_LoggedStateDimensions,
        rt_LoggedStateIsVarDims,
        (NULL),
        (NULL),
        rt_LoggedStateDataTypeIds,
        rt_LoggedStateComplexSignals,
        (NULL),

        { rt_LoggedStateLabels },
        (NULL),
        (NULL),
        (NULL),

        { rt_LoggedStateBlockNames },

        { rt_LoggedStateNames },
        rt_LoggedStateCrossMdlRef,
        rt_RTWLogDataTypeConvert
      };

      static void * rt_LoggedStateSignalPtrs[2];
      rtliSetLogXSignalPtrs(slrttestmdl_M->rtwLogInfo, (LogSignalPtrsType)
                            rt_LoggedStateSignalPtrs);
      rtliSetLogXSignalInfo(slrttestmdl_M->rtwLogInfo, &rt_LoggedStateSignalInfo);
      rt_LoggedStateSignalPtrs[0] = (void*)&slrttestmdl_X.Integrator1_CSTATE;
      rt_LoggedStateSignalPtrs[1] = (void*)&slrttestmdl_X.Integrator_CSTATE;
    }

    rtliSetLogT(slrttestmdl_M->rtwLogInfo, "tout");
    rtliSetLogX(slrttestmdl_M->rtwLogInfo, "xout");
    rtliSetLogXFinal(slrttestmdl_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(slrttestmdl_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(slrttestmdl_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(slrttestmdl_M->rtwLogInfo, 0);
    rtliSetLogDecimation(slrttestmdl_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &slrttestmdl_Y.Outport[0]
      };

      rtliSetLogYSignalPtrs(slrttestmdl_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        2
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        2
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "slrttestmdl/Outport" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          1,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(slrttestmdl_M->rtwLogInfo, rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
    }

    rtliSetLogY(slrttestmdl_M->rtwLogInfo, "yout");
  }

  slrttestmdl_M->solverInfoPtr = (&slrttestmdl_M->solverInfo);
  slrttestmdl_M->Timing.stepSize = (0.00025);
  rtsiSetFixedStepSize(&slrttestmdl_M->solverInfo, 0.00025);
  rtsiSetSolverMode(&slrttestmdl_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  slrttestmdl_M->blockIO = ((void *) &slrttestmdl_B);

  {
    slrttestmdl_B.Integrator1 = 0.0;
    slrttestmdl_B.SignalGenerator = 0.0;
    slrttestmdl_B.Gain = 0.0;
    slrttestmdl_B.Integrator = 0.0;
    slrttestmdl_B.Gain1 = 0.0;
    slrttestmdl_B.Gain2 = 0.0;
    slrttestmdl_B.Sum = 0.0;
  }

  /* parameters */
  slrttestmdl_M->defaultParam = ((real_T *)&slrttestmdl_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &slrttestmdl_X;
    slrttestmdl_M->contStates = (x);
    (void) memset((void *)&slrttestmdl_X, 0,
                  sizeof(X_slrttestmdl_T));
  }

  /* states (dwork) */
  slrttestmdl_M->dwork = ((void *) &slrttestmdl_DW);
  (void) memset((void *)&slrttestmdl_DW, 0,
                sizeof(DW_slrttestmdl_T));

  /* external outputs */
  slrttestmdl_M->outputs = (&slrttestmdl_Y);
  slrttestmdl_Y.Outport[0] = 0.0;
  slrttestmdl_Y.Outport[1] = 0.0;

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  slrttestmdl_InitializeDataMapInfo(slrttestmdl_M);

  /* Initialize Sizes */
  slrttestmdl_M->Sizes.numContStates = (2);/* Number of continuous states */
  slrttestmdl_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  slrttestmdl_M->Sizes.numY = (2);     /* Number of model outputs */
  slrttestmdl_M->Sizes.numU = (0);     /* Number of model inputs */
  slrttestmdl_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  slrttestmdl_M->Sizes.numSampTimes = (2);/* Number of sample times */
  slrttestmdl_M->Sizes.numBlocks = (9);/* Number of blocks */
  slrttestmdl_M->Sizes.numBlockIO = (7);/* Number of block outputs */
  slrttestmdl_M->Sizes.numBlockPrms = (7);/* Sum of parameter "widths" */
  return slrttestmdl_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
