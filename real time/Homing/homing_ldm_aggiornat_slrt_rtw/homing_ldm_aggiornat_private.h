/*
 * homing_ldm_aggiornat_private.h
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

#ifndef RTW_HEADER_homing_ldm_aggiornat_private_h_
#define RTW_HEADER_homing_ldm_aggiornat_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern const serialfifoptr serialfifoground;
extern const bcmsglist1553 bcmsg1553ground;
extern const bcstatus1553 bcstatground;
extern const bmmsglist1553 bmmsg1553ground;
extern void dinipcim(SimStruct *rts);
extern void encnipcim(SimStruct *rts);
extern void danipcim(SimStruct *rts);
extern void donipcim(SimStruct *rts);

#endif                                 /* RTW_HEADER_homing_ldm_aggiornat_private_h_ */
