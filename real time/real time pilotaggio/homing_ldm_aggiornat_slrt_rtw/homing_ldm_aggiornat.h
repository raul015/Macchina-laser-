/*
 * homing_ldm_aggiornat.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "homing_ldm_aggiornat".
 *
 * Model version              : 1.54
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Thu Dec 16 15:28:36 2021
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_homing_ldm_aggiornat_h_
#define RTW_HEADER_homing_ldm_aggiornat_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#include "rtw_modelmap.h"
#ifndef homing_ldm_aggiornat_COMMON_INCLUDES_
# define homing_ldm_aggiornat_COMMON_INCLUDES_
#include <xpcdatatypes.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#include "xpcimports.h"
#endif                                 /* homing_ldm_aggiornat_COMMON_INCLUDES_ */

#include "homing_ldm_aggiornat_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ()
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ()
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ()
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ()
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
# define rtmGetSelf(rtm)               ()
#endif

#ifndef rtmSetSelf
# define rtmSetSelf(rtm, val)          ()
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)
#define rtModel_homing_ldm_aggiornat   RT_MODEL_homing_ldm_aggiornat_T

/* Definition for use in the target main file */
#define homing_ldm_aggiornat_rtModel   RT_MODEL_homing_ldm_aggiornat_T

/* user code (top of export header file) */
#include "xpcdatatypes.h"

/* Block signals (auto storage) */
typedef struct {
  real_T b_y[3320];
  real_T b_x[3320];
  real_T b_y_m[3320];
  real_T b_x_c[3320];
  real_T fcxsx;                        /* '<Root>/PCI-6229 DI' */
  real_T fcxdx;                        /* '<Root>/PCI-6229 DI' */
  real_T fcyhigh;                      /* '<Root>/PCI-6229 DI' */
  real_T fcydown;                      /* '<Root>/PCI-6229 DI' */
  real_T posizionecarrellox;           /* '<Root>/PCI 6229 ENC 7' */
  real_T posizionecarrellox_n;         /* '<Root>/Gain13' */
  real_T posizionecarrelloy;           /* '<Root>/PCI 6229 ENC 6' */
  real_T posizionecarrelloy_e;         /* '<Root>/Gain11' */
  real_T TSamp;                        /* '<S3>/TSamp' */
  real_T Uk1;                          /* '<S3>/UD' */
  real_T Diff;                         /* '<S3>/Diff' */
  real_T TSamp_b;                      /* '<S5>/TSamp' */
  real_T Uk1_a;                        /* '<S5>/UD' */
  real_T Diff_k;                       /* '<S5>/Diff' */
  real_T Clock;                        /* '<Root>/Clock' */
  real_T Constant11;                   /* '<Root>/Constant11' */
  real_T Constant12;                   /* '<Root>/Constant12' */
  real_T Constant13;                   /* '<Root>/Constant13' */
  real_T Constant14;                   /* '<Root>/Constant14' */
  real_T Constant15;                   /* '<Root>/Constant15' */
  real_T Constant16;                   /* '<Root>/Constant16' */
  real_T Gain1;                        /* '<Root>/Gain1' */
  real_T DotProduct1;                  /* '<Root>/Dot Product1' */
  real_T DotProduct3;                  /* '<Root>/Dot Product3' */
  real_T DotProduct4;                  /* '<Root>/Dot Product4' */
  real_T Gain2;                        /* '<Root>/Gain2' */
  real_T Gain3;                        /* '<Root>/Gain3' */
  real_T DotProduct7;                  /* '<Root>/Dot Product7' */
  real_T sommax;                       /* '<Root>/Sum1' */
  real_T DotProduct2;                  /* '<Root>/Dot Product2' */
  real_T Gain5;                        /* '<Root>/Gain5' */
  real_T DotProduct8;                  /* '<Root>/Dot Product8' */
  real_T sommay;                       /* '<Root>/Sum6' */
  real_T Constant6;                    /* '<Root>/Constant6' */
  real_T posizionemotorex;             /* '<Root>/PCI 6229 ENC 4' */
  real_T posizionemotorex_i;           /* '<Root>/Gain10' */
  real_T TSamp_c;                      /* '<S2>/TSamp' */
  real_T Uk1_l;                        /* '<S2>/UD' */
  real_T Diff_e;                       /* '<S2>/Diff' */
  real_T pozionemotorey;               /* '<Root>/PCI 6229 ENC 5' */
  real_T posizionemotorey;             /* '<Root>/Gain12' */
  real_T TSamp_l;                      /* '<S4>/TSamp' */
  real_T Uk1_b;                        /* '<S4>/UD' */
  real_T Diff_d;                       /* '<S4>/Diff' */
  real_T DataTypeConversion;           /* '<S6>/Data Type Conversion' */
  real_T DataTypeConversion1;          /* '<S6>/Data Type Conversion1' */
  real_T TmpSignalConversionAtsfunxyInpo[2];
  real_T Vel_x_out;                    /* '<Root>/Chart' */
  real_T ok_x;                         /* '<Root>/Chart' */
  real_T ok_y;                         /* '<Root>/Chart' */
  real_T Vel_y_out;                    /* '<Root>/Chart' */
  real_T ok_x_2;                       /* '<Root>/Chart' */
  real_T ok_y_2;                       /* '<Root>/Chart' */
  real_T tensionex;                    /* '<Root>/Chart' */
  real_T tensioney;                    /* '<Root>/Chart' */
  real_T ok_x_3;                       /* '<Root>/Chart' */
  real_T ok_y_3;                       /* '<Root>/Chart' */
} B_homing_ldm_aggiornat_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S3>/UD' */
  real_T UD_DSTATE_p;                  /* '<S5>/UD' */
  real_T UD_DSTATE_d;                  /* '<S2>/UD' */
  real_T UD_DSTATE_b;                  /* '<S4>/UD' */
  real_T dx;                           /* '<Root>/Chart' */
  real_T v_sp_x;                       /* '<Root>/Chart' */
  real_T v_sp_y;                       /* '<Root>/Chart' */
  real_T dy;                           /* '<Root>/Chart' */
  real_T bx;                           /* '<Root>/Chart' */
  real_T by;                           /* '<Root>/Chart' */
  real_T inizio_traiettoria;           /* '<Root>/Chart' */
  real_T deltaxp;                      /* '<Root>/Chart' */
  real_T deltayp;                      /* '<Root>/Chart' */
  real_T deltax;                       /* '<Root>/Chart' */
  real_T deltay;                       /* '<Root>/Chart' */
  real_T rifx;                         /* '<Root>/Chart' */
  real_T rifxp;                        /* '<Root>/Chart' */
  real_T rify;                         /* '<Root>/Chart' */
  real_T rifyp;                        /* '<Root>/Chart' */
  real_T appoggio;                     /* '<Root>/Chart' */
  real_T rif_iniziale;                 /* '<Root>/Chart' */
  real_T t1;                           /* '<Root>/Chart' */
  real_T t;                            /* '<Root>/Chart' */
  real_T PCI6229DA1_RWORK[6];          /* '<Root>/PCI-6229 DA1' */
  real_T PCI6229DA2_RWORK[6];          /* '<Root>/PCI-6229 DA2' */
  void *PCI6229ENC7_PWORK;             /* '<Root>/PCI 6229 ENC 7' */
  void *PCI6229ENC6_PWORK;             /* '<Root>/PCI 6229 ENC 6' */
  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedFor_;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedFo_f;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedFo_m;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedF_f0;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedFo_n;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedFo_k;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedFo_l;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedFo_e;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedF_f2;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedFo_a;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedF_ac;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedF_mz;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedF_mt;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedFo_c;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedF_ap;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedF_ej;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedFo_j;   /* synthesized block */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<Root>/Scope4' */

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      /* '<Root>/Scope5' */

  struct {
    void *LoggedData;
  } Scope6_PWORK;                      /* '<Root>/Scope6' */

  struct {
    void *LoggedData;
  } Scope7_PWORK;                      /* '<Root>/Scope7' */

  struct {
    void *LoggedData;
  } Scope8_PWORK;                      /* '<Root>/Scope8' */

  struct {
    void *LoggedData;
  } Scope9_PWORK;                      /* '<Root>/Scope9' */

  void *PCI6229ENC4_PWORK;             /* '<Root>/PCI 6229 ENC 4' */
  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedF_eo;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedFo_o;   /* synthesized block */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  void *PCI6229ENC5_PWORK;             /* '<Root>/PCI 6229 ENC 5' */
  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedF_c2;   /* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } HiddenToAsyncQueue_InsertedFo_p;   /* synthesized block */

  struct {
    void *LoggedData[2];
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  int32_T sfEvent;                     /* '<Root>/Chart' */
  int_T PCI6229DI_IWORK;               /* '<Root>/PCI-6229 DI' */
  int_T PCI6229DA1_IWORK[41];          /* '<Root>/PCI-6229 DA1' */
  int_T PCI6229DA2_IWORK[41];          /* '<Root>/PCI-6229 DA2' */
  int_T PCI6229DO2_IWORK;              /* '<Root>/PCI-6229 DO2' */
  uint8_T is_active_c3_homing_ldm_aggiorn;/* '<Root>/Chart' */
  uint8_T is_c3_homing_ldm_aggiornat;  /* '<Root>/Chart' */
  uint8_T is_Pilotaggio;               /* '<Root>/Chart' */
  uint8_T is_Homing1;                  /* '<Root>/Chart' */
} DW_homing_ldm_aggiornat_T;

/* Backward compatible GRT Identifiers */
#define rtB                            homing_ldm_aggiornat_B
#define BlockIO                        B_homing_ldm_aggiornat_T
#define rtP                            homing_ldm_aggiornat_P
#define Parameters                     P_homing_ldm_aggiornat_T
#define rtDWork                        homing_ldm_aggiornat_DW
#define D_Work                         DW_homing_ldm_aggiornat_T

/* Parameters (auto storage) */
struct P_homing_ldm_aggiornat_T_ {
  struct_p4a3fbOfYyoF57AQ0TsR2D parx;  /* Variable: parx
                                        * Referenced by: '<Root>/Constant15'
                                        */
  struct_MxqrZmnGbOcHrCh1hlquB pary;   /* Variable: pary
                                        * Referenced by: '<Root>/Constant16'
                                        */
  struct_0cTP9OGKNIwjZ53OR7EfCC ppx_c; /* Variable: ppx_c
                                        * Referenced by:
                                        *   '<Root>/Constant11'
                                        *   '<Root>/Constant12'
                                        */
  struct_0cTP9OGKNIwjZ53OR7EfCC ppy_c; /* Variable: ppy_c
                                        * Referenced by:
                                        *   '<Root>/Constant13'
                                        *   '<Root>/Constant14'
                                        */
  real_T Vel_asse_x[3320];             /* Variable: Vel_asse_x
                                        * Referenced by: '<Root>/Chart'
                                        */
  real_T Vel_asse_y[3320];             /* Variable: Vel_asse_y
                                        * Referenced by: '<Root>/Chart'
                                        */
  real_T time[3320];                   /* Variable: time
                                        * Referenced by: '<Root>/Chart'
                                        */
  real_T x[3320];                      /* Variable: x
                                        * Referenced by: '<Root>/Chart'
                                        */
  real_T y[3320];                      /* Variable: y
                                        * Referenced by: '<Root>/Chart'
                                        */
  real_T DiscreteDerivative5_ICPrevScale;/* Mask Parameter: DiscreteDerivative5_ICPrevScale
                                          * Referenced by: '<S3>/UD'
                                          */
  real_T DiscreteDerivative7_ICPrevScale;/* Mask Parameter: DiscreteDerivative7_ICPrevScale
                                          * Referenced by: '<S5>/UD'
                                          */
  real_T DiscreteDerivative4_ICPrevScale;/* Mask Parameter: DiscreteDerivative4_ICPrevScale
                                          * Referenced by: '<S2>/UD'
                                          */
  real_T DiscreteDerivative6_ICPrevScale;/* Mask Parameter: DiscreteDerivative6_ICPrevScale
                                          * Referenced by: '<S4>/UD'
                                          */
  real_T PCI6229DI_P1_Size[2];         /* Computed Parameter: PCI6229DI_P1_Size
                                        * Referenced by: '<Root>/PCI-6229 DI'
                                        */
  real_T PCI6229DI_P1[4];              /* Expression: channel
                                        * Referenced by: '<Root>/PCI-6229 DI'
                                        */
  real_T PCI6229DI_P2_Size[2];         /* Computed Parameter: PCI6229DI_P2_Size
                                        * Referenced by: '<Root>/PCI-6229 DI'
                                        */
  real_T PCI6229DI_P2;                 /* Expression: sampletime
                                        * Referenced by: '<Root>/PCI-6229 DI'
                                        */
  real_T PCI6229DI_P3_Size[2];         /* Computed Parameter: PCI6229DI_P3_Size
                                        * Referenced by: '<Root>/PCI-6229 DI'
                                        */
  real_T PCI6229DI_P3[2];              /* Expression: slot
                                        * Referenced by: '<Root>/PCI-6229 DI'
                                        */
  real_T PCI6229DI_P4_Size[2];         /* Computed Parameter: PCI6229DI_P4_Size
                                        * Referenced by: '<Root>/PCI-6229 DI'
                                        */
  real_T PCI6229DI_P4;                 /* Expression: control
                                        * Referenced by: '<Root>/PCI-6229 DI'
                                        */
  real_T PCI6229DI_P5_Size[2];         /* Computed Parameter: PCI6229DI_P5_Size
                                        * Referenced by: '<Root>/PCI-6229 DI'
                                        */
  real_T PCI6229DI_P5;                 /* Expression: boardType
                                        * Referenced by: '<Root>/PCI-6229 DI'
                                        */
  real_T PCI6229ENC7_P1_Size[2];       /* Computed Parameter: PCI6229ENC7_P1_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */
  real_T PCI6229ENC7_P1;               /* Expression: device
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */
  real_T PCI6229ENC7_P2_Size[2];       /* Computed Parameter: PCI6229ENC7_P2_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */
  real_T PCI6229ENC7_P2;               /* Expression: channel
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */
  real_T PCI6229ENC7_P3_Size[2];       /* Computed Parameter: PCI6229ENC7_P3_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */
  real_T PCI6229ENC7_P3;               /* Expression: countMode
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */
  real_T PCI6229ENC7_P4_Size[2];       /* Computed Parameter: PCI6229ENC7_P4_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */
  real_T PCI6229ENC7_P4;               /* Expression: initCount
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */
  real_T PCI6229ENC7_P5_Size[2];       /* Computed Parameter: PCI6229ENC7_P5_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */
  real_T PCI6229ENC7_P5;               /* Expression: reload
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */
  real_T PCI6229ENC7_P6_Size[2];       /* Computed Parameter: PCI6229ENC7_P6_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */
  real_T PCI6229ENC7_P6;               /* Expression: indexPhase
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */
  real_T PCI6229ENC7_P7_Size[2];       /* Computed Parameter: PCI6229ENC7_P7_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */
  real_T PCI6229ENC7_P7;               /* Expression: filter
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */
  real_T PCI6229ENC7_P8_Size[2];       /* Computed Parameter: PCI6229ENC7_P8_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */
  real_T PCI6229ENC7_P8;               /* Expression: outmask
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */
  real_T PCI6229ENC7_P9_Size[2];       /* Computed Parameter: PCI6229ENC7_P9_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */
  real_T PCI6229ENC7_P9;               /* Expression: sampleTime
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */
  real_T PCI6229ENC7_P10_Size[2];      /* Computed Parameter: PCI6229ENC7_P10_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */
  real_T PCI6229ENC7_P10[2];           /* Expression: slot
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */
  real_T Gain13_Gain;                  /* Expression: -5e-6
                                        * Referenced by: '<Root>/Gain13'
                                        */
  real_T PCI6229ENC6_P1_Size[2];       /* Computed Parameter: PCI6229ENC6_P1_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */
  real_T PCI6229ENC6_P1;               /* Expression: device
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */
  real_T PCI6229ENC6_P2_Size[2];       /* Computed Parameter: PCI6229ENC6_P2_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */
  real_T PCI6229ENC6_P2;               /* Expression: channel
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */
  real_T PCI6229ENC6_P3_Size[2];       /* Computed Parameter: PCI6229ENC6_P3_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */
  real_T PCI6229ENC6_P3;               /* Expression: countMode
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */
  real_T PCI6229ENC6_P4_Size[2];       /* Computed Parameter: PCI6229ENC6_P4_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */
  real_T PCI6229ENC6_P4;               /* Expression: initCount
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */
  real_T PCI6229ENC6_P5_Size[2];       /* Computed Parameter: PCI6229ENC6_P5_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */
  real_T PCI6229ENC6_P5;               /* Expression: reload
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */
  real_T PCI6229ENC6_P6_Size[2];       /* Computed Parameter: PCI6229ENC6_P6_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */
  real_T PCI6229ENC6_P6;               /* Expression: indexPhase
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */
  real_T PCI6229ENC6_P7_Size[2];       /* Computed Parameter: PCI6229ENC6_P7_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */
  real_T PCI6229ENC6_P7;               /* Expression: filter
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */
  real_T PCI6229ENC6_P8_Size[2];       /* Computed Parameter: PCI6229ENC6_P8_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */
  real_T PCI6229ENC6_P8;               /* Expression: outmask
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */
  real_T PCI6229ENC6_P9_Size[2];       /* Computed Parameter: PCI6229ENC6_P9_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */
  real_T PCI6229ENC6_P9;               /* Expression: sampleTime
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */
  real_T PCI6229ENC6_P10_Size[2];      /* Computed Parameter: PCI6229ENC6_P10_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */
  real_T PCI6229ENC6_P10[2];           /* Expression: slot
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */
  real_T Gain11_Gain;                  /* Expression: -5e-6
                                        * Referenced by: '<Root>/Gain11'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S3>/TSamp'
                                        */
  real_T TSamp_WtEt_h;                 /* Computed Parameter: TSamp_WtEt_h
                                        * Referenced by: '<S5>/TSamp'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1.0989
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1.5942

                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1.0989
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1.5942

                                        * Referenced by: '<Root>/Gain5'
                                        */
  real_T PCI6229DA1_P1_Size[2];        /* Computed Parameter: PCI6229DA1_P1_Size
                                        * Referenced by: '<Root>/PCI-6229 DA1'
                                        */
  real_T PCI6229DA1_P1;                /* Expression: channel
                                        * Referenced by: '<Root>/PCI-6229 DA1'
                                        */
  real_T PCI6229DA1_P2_Size[2];        /* Computed Parameter: PCI6229DA1_P2_Size
                                        * Referenced by: '<Root>/PCI-6229 DA1'
                                        */
  real_T PCI6229DA1_P2;                /* Expression: range
                                        * Referenced by: '<Root>/PCI-6229 DA1'
                                        */
  real_T PCI6229DA1_P3_Size[2];        /* Computed Parameter: PCI6229DA1_P3_Size
                                        * Referenced by: '<Root>/PCI-6229 DA1'
                                        */
  real_T PCI6229DA1_P3;                /* Expression: reset
                                        * Referenced by: '<Root>/PCI-6229 DA1'
                                        */
  real_T PCI6229DA1_P4_Size[2];        /* Computed Parameter: PCI6229DA1_P4_Size
                                        * Referenced by: '<Root>/PCI-6229 DA1'
                                        */
  real_T PCI6229DA1_P4;                /* Expression: initValue
                                        * Referenced by: '<Root>/PCI-6229 DA1'
                                        */
  real_T PCI6229DA1_P5_Size[2];        /* Computed Parameter: PCI6229DA1_P5_Size
                                        * Referenced by: '<Root>/PCI-6229 DA1'
                                        */
  real_T PCI6229DA1_P5;                /* Expression: sampletime
                                        * Referenced by: '<Root>/PCI-6229 DA1'
                                        */
  real_T PCI6229DA1_P6_Size[2];        /* Computed Parameter: PCI6229DA1_P6_Size
                                        * Referenced by: '<Root>/PCI-6229 DA1'
                                        */
  real_T PCI6229DA1_P6[2];             /* Expression: slot
                                        * Referenced by: '<Root>/PCI-6229 DA1'
                                        */
  real_T PCI6229DA1_P7_Size[2];        /* Computed Parameter: PCI6229DA1_P7_Size
                                        * Referenced by: '<Root>/PCI-6229 DA1'
                                        */
  real_T PCI6229DA1_P7;                /* Expression: boardType
                                        * Referenced by: '<Root>/PCI-6229 DA1'
                                        */
  real_T PCI6229DA2_P1_Size[2];        /* Computed Parameter: PCI6229DA2_P1_Size
                                        * Referenced by: '<Root>/PCI-6229 DA2'
                                        */
  real_T PCI6229DA2_P1;                /* Expression: channel
                                        * Referenced by: '<Root>/PCI-6229 DA2'
                                        */
  real_T PCI6229DA2_P2_Size[2];        /* Computed Parameter: PCI6229DA2_P2_Size
                                        * Referenced by: '<Root>/PCI-6229 DA2'
                                        */
  real_T PCI6229DA2_P2;                /* Expression: range
                                        * Referenced by: '<Root>/PCI-6229 DA2'
                                        */
  real_T PCI6229DA2_P3_Size[2];        /* Computed Parameter: PCI6229DA2_P3_Size
                                        * Referenced by: '<Root>/PCI-6229 DA2'
                                        */
  real_T PCI6229DA2_P3;                /* Expression: reset
                                        * Referenced by: '<Root>/PCI-6229 DA2'
                                        */
  real_T PCI6229DA2_P4_Size[2];        /* Computed Parameter: PCI6229DA2_P4_Size
                                        * Referenced by: '<Root>/PCI-6229 DA2'
                                        */
  real_T PCI6229DA2_P4;                /* Expression: initValue
                                        * Referenced by: '<Root>/PCI-6229 DA2'
                                        */
  real_T PCI6229DA2_P5_Size[2];        /* Computed Parameter: PCI6229DA2_P5_Size
                                        * Referenced by: '<Root>/PCI-6229 DA2'
                                        */
  real_T PCI6229DA2_P5;                /* Expression: sampletime
                                        * Referenced by: '<Root>/PCI-6229 DA2'
                                        */
  real_T PCI6229DA2_P6_Size[2];        /* Computed Parameter: PCI6229DA2_P6_Size
                                        * Referenced by: '<Root>/PCI-6229 DA2'
                                        */
  real_T PCI6229DA2_P6[2];             /* Expression: slot
                                        * Referenced by: '<Root>/PCI-6229 DA2'
                                        */
  real_T PCI6229DA2_P7_Size[2];        /* Computed Parameter: PCI6229DA2_P7_Size
                                        * Referenced by: '<Root>/PCI-6229 DA2'
                                        */
  real_T PCI6229DA2_P7;                /* Expression: boardType
                                        * Referenced by: '<Root>/PCI-6229 DA2'
                                        */
  real_T Constant6_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T PCI6229DO2_P1_Size[2];        /* Computed Parameter: PCI6229DO2_P1_Size
                                        * Referenced by: '<Root>/PCI-6229 DO2'
                                        */
  real_T PCI6229DO2_P1;                /* Expression: channel
                                        * Referenced by: '<Root>/PCI-6229 DO2'
                                        */
  real_T PCI6229DO2_P2_Size[2];        /* Computed Parameter: PCI6229DO2_P2_Size
                                        * Referenced by: '<Root>/PCI-6229 DO2'
                                        */
  real_T PCI6229DO2_P2;                /* Expression: reset
                                        * Referenced by: '<Root>/PCI-6229 DO2'
                                        */
  real_T PCI6229DO2_P3_Size[2];        /* Computed Parameter: PCI6229DO2_P3_Size
                                        * Referenced by: '<Root>/PCI-6229 DO2'
                                        */
  real_T PCI6229DO2_P3;                /* Expression: initValue
                                        * Referenced by: '<Root>/PCI-6229 DO2'
                                        */
  real_T PCI6229DO2_P4_Size[2];        /* Computed Parameter: PCI6229DO2_P4_Size
                                        * Referenced by: '<Root>/PCI-6229 DO2'
                                        */
  real_T PCI6229DO2_P4;                /* Expression: sampletime
                                        * Referenced by: '<Root>/PCI-6229 DO2'
                                        */
  real_T PCI6229DO2_P5_Size[2];        /* Computed Parameter: PCI6229DO2_P5_Size
                                        * Referenced by: '<Root>/PCI-6229 DO2'
                                        */
  real_T PCI6229DO2_P5[2];             /* Expression: slot
                                        * Referenced by: '<Root>/PCI-6229 DO2'
                                        */
  real_T PCI6229DO2_P6_Size[2];        /* Computed Parameter: PCI6229DO2_P6_Size
                                        * Referenced by: '<Root>/PCI-6229 DO2'
                                        */
  real_T PCI6229DO2_P6;                /* Expression: control
                                        * Referenced by: '<Root>/PCI-6229 DO2'
                                        */
  real_T PCI6229DO2_P7_Size[2];        /* Computed Parameter: PCI6229DO2_P7_Size
                                        * Referenced by: '<Root>/PCI-6229 DO2'
                                        */
  real_T PCI6229DO2_P7;                /* Expression: boardType
                                        * Referenced by: '<Root>/PCI-6229 DO2'
                                        */
  real_T PCI6229ENC4_P1_Size[2];       /* Computed Parameter: PCI6229ENC4_P1_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */
  real_T PCI6229ENC4_P1;               /* Expression: device
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */
  real_T PCI6229ENC4_P2_Size[2];       /* Computed Parameter: PCI6229ENC4_P2_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */
  real_T PCI6229ENC4_P2;               /* Expression: channel
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */
  real_T PCI6229ENC4_P3_Size[2];       /* Computed Parameter: PCI6229ENC4_P3_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */
  real_T PCI6229ENC4_P3;               /* Expression: countMode
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */
  real_T PCI6229ENC4_P4_Size[2];       /* Computed Parameter: PCI6229ENC4_P4_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */
  real_T PCI6229ENC4_P4;               /* Expression: initCount
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */
  real_T PCI6229ENC4_P5_Size[2];       /* Computed Parameter: PCI6229ENC4_P5_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */
  real_T PCI6229ENC4_P5;               /* Expression: reload
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */
  real_T PCI6229ENC4_P6_Size[2];       /* Computed Parameter: PCI6229ENC4_P6_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */
  real_T PCI6229ENC4_P6;               /* Expression: indexPhase
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */
  real_T PCI6229ENC4_P7_Size[2];       /* Computed Parameter: PCI6229ENC4_P7_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */
  real_T PCI6229ENC4_P7;               /* Expression: filter
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */
  real_T PCI6229ENC4_P8_Size[2];       /* Computed Parameter: PCI6229ENC4_P8_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */
  real_T PCI6229ENC4_P8;               /* Expression: outmask
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */
  real_T PCI6229ENC4_P9_Size[2];       /* Computed Parameter: PCI6229ENC4_P9_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */
  real_T PCI6229ENC4_P9;               /* Expression: sampleTime
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */
  real_T PCI6229ENC4_P10_Size[2];      /* Computed Parameter: PCI6229ENC4_P10_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */
  real_T PCI6229ENC4_P10[2];           /* Expression: slot
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */
  real_T Gain10_Gain;                  /* Expression: 2*pi/(4096)
                                        * Referenced by: '<Root>/Gain10'
                                        */
  real_T TSamp_WtEt_j;                 /* Computed Parameter: TSamp_WtEt_j
                                        * Referenced by: '<S2>/TSamp'
                                        */
  real_T PCI6229ENC5_P1_Size[2];       /* Computed Parameter: PCI6229ENC5_P1_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */
  real_T PCI6229ENC5_P1;               /* Expression: device
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */
  real_T PCI6229ENC5_P2_Size[2];       /* Computed Parameter: PCI6229ENC5_P2_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */
  real_T PCI6229ENC5_P2;               /* Expression: channel
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */
  real_T PCI6229ENC5_P3_Size[2];       /* Computed Parameter: PCI6229ENC5_P3_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */
  real_T PCI6229ENC5_P3;               /* Expression: countMode
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */
  real_T PCI6229ENC5_P4_Size[2];       /* Computed Parameter: PCI6229ENC5_P4_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */
  real_T PCI6229ENC5_P4;               /* Expression: initCount
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */
  real_T PCI6229ENC5_P5_Size[2];       /* Computed Parameter: PCI6229ENC5_P5_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */
  real_T PCI6229ENC5_P5;               /* Expression: reload
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */
  real_T PCI6229ENC5_P6_Size[2];       /* Computed Parameter: PCI6229ENC5_P6_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */
  real_T PCI6229ENC5_P6;               /* Expression: indexPhase
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */
  real_T PCI6229ENC5_P7_Size[2];       /* Computed Parameter: PCI6229ENC5_P7_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */
  real_T PCI6229ENC5_P7;               /* Expression: filter
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */
  real_T PCI6229ENC5_P8_Size[2];       /* Computed Parameter: PCI6229ENC5_P8_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */
  real_T PCI6229ENC5_P8;               /* Expression: outmask
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */
  real_T PCI6229ENC5_P9_Size[2];       /* Computed Parameter: PCI6229ENC5_P9_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */
  real_T PCI6229ENC5_P9;               /* Expression: sampleTime
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */
  real_T PCI6229ENC5_P10_Size[2];      /* Computed Parameter: PCI6229ENC5_P10_Size
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */
  real_T PCI6229ENC5_P10[2];           /* Expression: slot
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */
  real_T Gain12_Gain;                  /* Expression: 2*pi/(1024*4)
                                        * Referenced by: '<Root>/Gain12'
                                        */
  real_T TSamp_WtEt_b;                 /* Computed Parameter: TSamp_WtEt_b
                                        * Referenced by: '<S4>/TSamp'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_homing_ldm_aggiornat_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[2];
    SimStruct childSFunctions[8];
    SimStruct *childSFunctionPtrs[8];
    struct _ssBlkInfo2 blkInfo2[8];
    struct _ssSFcnModelMethods2 methods2[8];
    struct _ssSFcnModelMethods3 methods3[8];
    struct _ssSFcnModelMethods4 methods4[8];
    struct _ssStatesInfo2 statesInfo2[8];
    ssPeriodicStatesInfo periodicStatesInfo[8];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[4];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[10];
      mxArray *params[10];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[10];
      mxArray *params[10];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn5;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[10];
      mxArray *params[10];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn6;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[10];
      mxArray *params[10];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn7;
  } NonInlinedSFcns;

  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T blkStateChange;
  void *dwork;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
  } DataMapInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_homing_ldm_aggiornat_T homing_ldm_aggiornat_P;

/* Block signals (auto storage) */
extern B_homing_ldm_aggiornat_T homing_ldm_aggiornat_B;

/* Block states (auto storage) */
extern DW_homing_ldm_aggiornat_T homing_ldm_aggiornat_DW;

/*====================*
 * External functions *
 *====================*/
extern homing_ldm_aggiornat_rtModel *homing_ldm_aggiornat(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  homing_ldm_aggiornat_GetCAPIStaticMap(void);

/* Real-time Model object */
extern RT_MODEL_homing_ldm_aggiornat_T *const homing_ldm_aggiornat_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'homing_ldm_aggiornat'
 * '<S1>'   : 'homing_ldm_aggiornat/Chart'
 * '<S2>'   : 'homing_ldm_aggiornat/Discrete Derivative4'
 * '<S3>'   : 'homing_ldm_aggiornat/Discrete Derivative5'
 * '<S4>'   : 'homing_ldm_aggiornat/Discrete Derivative6'
 * '<S5>'   : 'homing_ldm_aggiornat/Discrete Derivative7'
 * '<S6>'   : 'homing_ldm_aggiornat/XY Graph'
 */
#endif                                 /* RTW_HEADER_homing_ldm_aggiornat_h_ */
