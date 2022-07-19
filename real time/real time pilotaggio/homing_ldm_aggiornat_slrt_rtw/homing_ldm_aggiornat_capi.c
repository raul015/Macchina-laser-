/*
 * homing_ldm_aggiornat_capi.c
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

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "homing_ldm_aggiornat_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "homing_ldm_aggiornat.h"
#include "homing_ldm_aggiornat_capi.h"
#include "homing_ldm_aggiornat_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               (NULL)
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 1, TARGET_STRING("Chart/p1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 1, 1, TARGET_STRING("Chart/p2"),
    TARGET_STRING(""), 1, 0, 0, 0, 0 },

  { 2, 1, TARGET_STRING("Chart/p3"),
    TARGET_STRING(""), 2, 0, 0, 0, 0 },

  { 3, 1, TARGET_STRING("Chart/p4"),
    TARGET_STRING(""), 3, 0, 0, 0, 0 },

  { 4, 1, TARGET_STRING("Chart/p5"),
    TARGET_STRING(""), 4, 0, 0, 0, 0 },

  { 5, 1, TARGET_STRING("Chart/p6"),
    TARGET_STRING(""), 5, 0, 0, 0, 0 },

  { 6, 1, TARGET_STRING("Chart/p7"),
    TARGET_STRING(""), 6, 0, 0, 0, 0 },

  { 7, 1, TARGET_STRING("Chart/p8"),
    TARGET_STRING(""), 7, 0, 0, 0, 0 },

  { 8, 1, TARGET_STRING("Chart/p9"),
    TARGET_STRING(""), 8, 0, 0, 0, 0 },

  { 9, 1, TARGET_STRING("Chart/p10"),
    TARGET_STRING(""), 9, 0, 0, 0, 0 },

  { 10, 0, TARGET_STRING("Clock"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 11, 0, TARGET_STRING("Constant11"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 12, 0, TARGET_STRING("Constant12"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 13, 0, TARGET_STRING("Constant13"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 14, 0, TARGET_STRING("Constant14"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 15, 0, TARGET_STRING("Constant15"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 16, 0, TARGET_STRING("Constant16"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 17, 0, TARGET_STRING("Constant6"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 18, 0, TARGET_STRING("Gain1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 19, 0, TARGET_STRING("Gain10"),
    TARGET_STRING("posizione motore x"), 0, 0, 0, 0, 0 },

  { 20, 0, TARGET_STRING("Gain11"),
    TARGET_STRING("posizione carrello y"), 0, 0, 0, 0, 0 },

  { 21, 0, TARGET_STRING("Gain12"),
    TARGET_STRING("posizione motore y"), 0, 0, 0, 0, 0 },

  { 22, 0, TARGET_STRING("Gain13"),
    TARGET_STRING("posizione carrello x"), 0, 0, 0, 0, 0 },

  { 23, 0, TARGET_STRING("Gain2"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 24, 0, TARGET_STRING("Gain3"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 25, 0, TARGET_STRING("Gain5"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 26, 0, TARGET_STRING("PCI 6229 ENC 4"),
    TARGET_STRING("posizione motore x"), 0, 0, 0, 0, 0 },

  { 27, 0, TARGET_STRING("PCI 6229 ENC 5"),
    TARGET_STRING("pozione motore y"), 0, 0, 0, 0, 0 },

  { 28, 0, TARGET_STRING("PCI 6229 ENC 6"),
    TARGET_STRING("posizione carrello y"), 0, 0, 0, 0, 0 },

  { 29, 0, TARGET_STRING("PCI 6229 ENC 7"),
    TARGET_STRING("posizione carrello x"), 0, 0, 0, 0, 0 },

  { 30, 0, TARGET_STRING("PCI-6229 DI/p1"),
    TARGET_STRING("fc x sx"), 0, 0, 0, 0, 0 },

  { 31, 0, TARGET_STRING("PCI-6229 DI/p2"),
    TARGET_STRING("fc x dx"), 1, 0, 0, 0, 0 },

  { 32, 0, TARGET_STRING("PCI-6229 DI/p3"),
    TARGET_STRING("fc y high"), 2, 0, 0, 0, 0 },

  { 33, 0, TARGET_STRING("PCI-6229 DI/p4"),
    TARGET_STRING("fc y down"), 3, 0, 0, 0, 0 },

  { 34, 0, TARGET_STRING("Sum1"),
    TARGET_STRING("sommax"), 0, 0, 0, 0, 0 },

  { 35, 0, TARGET_STRING("Sum6"),
    TARGET_STRING("sommay"), 0, 0, 0, 0, 0 },

  { 36, 0, TARGET_STRING("Dot Product1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 37, 0, TARGET_STRING("Dot Product2"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 38, 0, TARGET_STRING("Dot Product3"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 39, 0, TARGET_STRING("Dot Product4"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 40, 0, TARGET_STRING("Dot Product7"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 41, 0, TARGET_STRING("Dot Product8"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 42, 0, TARGET_STRING("Discrete Derivative4/Diff"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 43, 0, TARGET_STRING("Discrete Derivative4/TSamp"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 44, 0, TARGET_STRING("Discrete Derivative4/UD"),
    TARGET_STRING("U(k-1)"), 0, 0, 0, 0, 0 },

  { 45, 0, TARGET_STRING("Discrete Derivative5/Diff"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 46, 0, TARGET_STRING("Discrete Derivative5/TSamp"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 47, 0, TARGET_STRING("Discrete Derivative5/UD"),
    TARGET_STRING("U(k-1)"), 0, 0, 0, 0, 0 },

  { 48, 0, TARGET_STRING("Discrete Derivative6/Diff"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 49, 0, TARGET_STRING("Discrete Derivative6/TSamp"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 50, 0, TARGET_STRING("Discrete Derivative6/UD"),
    TARGET_STRING("U(k-1)"), 0, 0, 0, 0, 0 },

  { 51, 0, TARGET_STRING("Discrete Derivative7/Diff"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 52, 0, TARGET_STRING("Discrete Derivative7/TSamp"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 53, 0, TARGET_STRING("Discrete Derivative7/UD"),
    TARGET_STRING("U(k-1)"), 0, 0, 0, 0, 0 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 54, TARGET_STRING("Discrete Derivative4"),
    TARGET_STRING("ICPrevScaledInput"), 0, 0, 0 },

  { 55, TARGET_STRING("Discrete Derivative5"),
    TARGET_STRING("ICPrevScaledInput"), 0, 0, 0 },

  { 56, TARGET_STRING("Discrete Derivative6"),
    TARGET_STRING("ICPrevScaledInput"), 0, 0, 0 },

  { 57, TARGET_STRING("Discrete Derivative7"),
    TARGET_STRING("ICPrevScaledInput"), 0, 0, 0 },

  { 58, TARGET_STRING("Constant6"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 59, TARGET_STRING("Gain1"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 60, TARGET_STRING("Gain10"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 61, TARGET_STRING("Gain11"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 62, TARGET_STRING("Gain12"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 63, TARGET_STRING("Gain13"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 64, TARGET_STRING("Gain2"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 65, TARGET_STRING("Gain3"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 66, TARGET_STRING("Gain5"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 67, TARGET_STRING("PCI 6229 ENC 4"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 68, TARGET_STRING("PCI 6229 ENC 4"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 69, TARGET_STRING("PCI 6229 ENC 4"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 70, TARGET_STRING("PCI 6229 ENC 4"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 71, TARGET_STRING("PCI 6229 ENC 4"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 72, TARGET_STRING("PCI 6229 ENC 4"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 73, TARGET_STRING("PCI 6229 ENC 4"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 74, TARGET_STRING("PCI 6229 ENC 4"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 75, TARGET_STRING("PCI 6229 ENC 4"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 76, TARGET_STRING("PCI 6229 ENC 4"),
    TARGET_STRING("P10"), 0, 1, 0 },

  { 77, TARGET_STRING("PCI 6229 ENC 5"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 78, TARGET_STRING("PCI 6229 ENC 5"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 79, TARGET_STRING("PCI 6229 ENC 5"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 80, TARGET_STRING("PCI 6229 ENC 5"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 81, TARGET_STRING("PCI 6229 ENC 5"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 82, TARGET_STRING("PCI 6229 ENC 5"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 83, TARGET_STRING("PCI 6229 ENC 5"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 84, TARGET_STRING("PCI 6229 ENC 5"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 85, TARGET_STRING("PCI 6229 ENC 5"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 86, TARGET_STRING("PCI 6229 ENC 5"),
    TARGET_STRING("P10"), 0, 1, 0 },

  { 87, TARGET_STRING("PCI 6229 ENC 6"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 88, TARGET_STRING("PCI 6229 ENC 6"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 89, TARGET_STRING("PCI 6229 ENC 6"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 90, TARGET_STRING("PCI 6229 ENC 6"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 91, TARGET_STRING("PCI 6229 ENC 6"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 92, TARGET_STRING("PCI 6229 ENC 6"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 93, TARGET_STRING("PCI 6229 ENC 6"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 94, TARGET_STRING("PCI 6229 ENC 6"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 95, TARGET_STRING("PCI 6229 ENC 6"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 96, TARGET_STRING("PCI 6229 ENC 6"),
    TARGET_STRING("P10"), 0, 1, 0 },

  { 97, TARGET_STRING("PCI 6229 ENC 7"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 98, TARGET_STRING("PCI 6229 ENC 7"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 99, TARGET_STRING("PCI 6229 ENC 7"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 100, TARGET_STRING("PCI 6229 ENC 7"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 101, TARGET_STRING("PCI 6229 ENC 7"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 102, TARGET_STRING("PCI 6229 ENC 7"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 103, TARGET_STRING("PCI 6229 ENC 7"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 104, TARGET_STRING("PCI 6229 ENC 7"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 105, TARGET_STRING("PCI 6229 ENC 7"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 106, TARGET_STRING("PCI 6229 ENC 7"),
    TARGET_STRING("P10"), 0, 1, 0 },

  { 107, TARGET_STRING("PCI-6229 DA1"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 108, TARGET_STRING("PCI-6229 DA1"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 109, TARGET_STRING("PCI-6229 DA1"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 110, TARGET_STRING("PCI-6229 DA1"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 111, TARGET_STRING("PCI-6229 DA1"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 112, TARGET_STRING("PCI-6229 DA1"),
    TARGET_STRING("P6"), 0, 1, 0 },

  { 113, TARGET_STRING("PCI-6229 DA1"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 114, TARGET_STRING("PCI-6229 DA2"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 115, TARGET_STRING("PCI-6229 DA2"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 116, TARGET_STRING("PCI-6229 DA2"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 117, TARGET_STRING("PCI-6229 DA2"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 118, TARGET_STRING("PCI-6229 DA2"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 119, TARGET_STRING("PCI-6229 DA2"),
    TARGET_STRING("P6"), 0, 1, 0 },

  { 120, TARGET_STRING("PCI-6229 DA2"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 121, TARGET_STRING("PCI-6229 DI"),
    TARGET_STRING("P1"), 0, 2, 0 },

  { 122, TARGET_STRING("PCI-6229 DI"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 123, TARGET_STRING("PCI-6229 DI"),
    TARGET_STRING("P3"), 0, 1, 0 },

  { 124, TARGET_STRING("PCI-6229 DI"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 125, TARGET_STRING("PCI-6229 DI"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 126, TARGET_STRING("PCI-6229 DO2"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 127, TARGET_STRING("PCI-6229 DO2"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 128, TARGET_STRING("PCI-6229 DO2"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 129, TARGET_STRING("PCI-6229 DO2"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 130, TARGET_STRING("PCI-6229 DO2"),
    TARGET_STRING("P5"), 0, 1, 0 },

  { 131, TARGET_STRING("PCI-6229 DO2"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 132, TARGET_STRING("PCI-6229 DO2"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 133, TARGET_STRING("Discrete Derivative4/TSamp"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 134, TARGET_STRING("Discrete Derivative5/TSamp"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 135, TARGET_STRING("Discrete Derivative6/TSamp"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 136, TARGET_STRING("Discrete Derivative7/TSamp"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 137, TARGET_STRING("parx"), 1, 0, 0 },

  { 138, TARGET_STRING("pary"), 2, 0, 0 },

  { 139, TARGET_STRING("ppx_c"), 4, 0, 0 },

  { 140, TARGET_STRING("ppy_c"), 4, 0, 0 },

  { 141, TARGET_STRING("Vel_asse_x"), 0, 8, 0 },

  { 142, TARGET_STRING("Vel_asse_y"), 0, 8, 0 },

  { 143, TARGET_STRING("time"), 0, 8, 0 },

  { 144, TARGET_STRING("x"), 0, 8, 0 },

  { 145, TARGET_STRING("y"), 0, 8, 0 },

  { 0, (NULL), 0, 0, 0 }
};

#ifndef HOST_CAPI_BUILD

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &homing_ldm_aggiornat_B.Vel_x_out,   /* 0: Signal */
  &homing_ldm_aggiornat_B.ok_x,        /* 1: Signal */
  &homing_ldm_aggiornat_B.ok_y,        /* 2: Signal */
  &homing_ldm_aggiornat_B.Vel_y_out,   /* 3: Signal */
  &homing_ldm_aggiornat_B.ok_x_2,      /* 4: Signal */
  &homing_ldm_aggiornat_B.ok_y_2,      /* 5: Signal */
  &homing_ldm_aggiornat_B.tensionex,   /* 6: Signal */
  &homing_ldm_aggiornat_B.tensioney,   /* 7: Signal */
  &homing_ldm_aggiornat_B.ok_x_3,      /* 8: Signal */
  &homing_ldm_aggiornat_B.ok_y_3,      /* 9: Signal */
  &homing_ldm_aggiornat_B.Clock,       /* 10: Signal */
  &homing_ldm_aggiornat_B.Constant11,  /* 11: Signal */
  &homing_ldm_aggiornat_B.Constant12,  /* 12: Signal */
  &homing_ldm_aggiornat_B.Constant13,  /* 13: Signal */
  &homing_ldm_aggiornat_B.Constant14,  /* 14: Signal */
  &homing_ldm_aggiornat_B.Constant15,  /* 15: Signal */
  &homing_ldm_aggiornat_B.Constant16,  /* 16: Signal */
  &homing_ldm_aggiornat_B.Constant6,   /* 17: Signal */
  &homing_ldm_aggiornat_B.Gain1,       /* 18: Signal */
  &homing_ldm_aggiornat_B.posizionemotorex_i,/* 19: Signal */
  &homing_ldm_aggiornat_B.posizionecarrelloy_e,/* 20: Signal */
  &homing_ldm_aggiornat_B.posizionemotorey,/* 21: Signal */
  &homing_ldm_aggiornat_B.posizionecarrellox_n,/* 22: Signal */
  &homing_ldm_aggiornat_B.Gain2,       /* 23: Signal */
  &homing_ldm_aggiornat_B.Gain3,       /* 24: Signal */
  &homing_ldm_aggiornat_B.Gain5,       /* 25: Signal */
  &homing_ldm_aggiornat_B.posizionemotorex,/* 26: Signal */
  &homing_ldm_aggiornat_B.pozionemotorey,/* 27: Signal */
  &homing_ldm_aggiornat_B.posizionecarrelloy,/* 28: Signal */
  &homing_ldm_aggiornat_B.posizionecarrellox,/* 29: Signal */
  &homing_ldm_aggiornat_B.fcxsx,       /* 30: Signal */
  &homing_ldm_aggiornat_B.fcxdx,       /* 31: Signal */
  &homing_ldm_aggiornat_B.fcyhigh,     /* 32: Signal */
  &homing_ldm_aggiornat_B.fcydown,     /* 33: Signal */
  &homing_ldm_aggiornat_B.sommax,      /* 34: Signal */
  &homing_ldm_aggiornat_B.sommay,      /* 35: Signal */
  &homing_ldm_aggiornat_B.DotProduct1, /* 36: Signal */
  &homing_ldm_aggiornat_B.DotProduct2, /* 37: Signal */
  &homing_ldm_aggiornat_B.DotProduct3, /* 38: Signal */
  &homing_ldm_aggiornat_B.DotProduct4, /* 39: Signal */
  &homing_ldm_aggiornat_B.DotProduct7, /* 40: Signal */
  &homing_ldm_aggiornat_B.DotProduct8, /* 41: Signal */
  &homing_ldm_aggiornat_B.Diff_e,      /* 42: Signal */
  &homing_ldm_aggiornat_B.TSamp_c,     /* 43: Signal */
  &homing_ldm_aggiornat_B.Uk1_l,       /* 44: Signal */
  &homing_ldm_aggiornat_B.Diff,        /* 45: Signal */
  &homing_ldm_aggiornat_B.TSamp,       /* 46: Signal */
  &homing_ldm_aggiornat_B.Uk1,         /* 47: Signal */
  &homing_ldm_aggiornat_B.Diff_d,      /* 48: Signal */
  &homing_ldm_aggiornat_B.TSamp_l,     /* 49: Signal */
  &homing_ldm_aggiornat_B.Uk1_b,       /* 50: Signal */
  &homing_ldm_aggiornat_B.Diff_k,      /* 51: Signal */
  &homing_ldm_aggiornat_B.TSamp_b,     /* 52: Signal */
  &homing_ldm_aggiornat_B.Uk1_a,       /* 53: Signal */
  &homing_ldm_aggiornat_P.DiscreteDerivative4_ICPrevScale,/* 54: Mask Parameter */
  &homing_ldm_aggiornat_P.DiscreteDerivative5_ICPrevScale,/* 55: Mask Parameter */
  &homing_ldm_aggiornat_P.DiscreteDerivative6_ICPrevScale,/* 56: Mask Parameter */
  &homing_ldm_aggiornat_P.DiscreteDerivative7_ICPrevScale,/* 57: Mask Parameter */
  &homing_ldm_aggiornat_P.Constant6_Value,/* 58: Block Parameter */
  &homing_ldm_aggiornat_P.Gain1_Gain,  /* 59: Block Parameter */
  &homing_ldm_aggiornat_P.Gain10_Gain, /* 60: Block Parameter */
  &homing_ldm_aggiornat_P.Gain11_Gain, /* 61: Block Parameter */
  &homing_ldm_aggiornat_P.Gain12_Gain, /* 62: Block Parameter */
  &homing_ldm_aggiornat_P.Gain13_Gain, /* 63: Block Parameter */
  &homing_ldm_aggiornat_P.Gain2_Gain,  /* 64: Block Parameter */
  &homing_ldm_aggiornat_P.Gain3_Gain,  /* 65: Block Parameter */
  &homing_ldm_aggiornat_P.Gain5_Gain,  /* 66: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC4_P1,/* 67: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC4_P2,/* 68: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC4_P3,/* 69: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC4_P4,/* 70: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC4_P5,/* 71: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC4_P6,/* 72: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC4_P7,/* 73: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC4_P8,/* 74: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC4_P9,/* 75: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC4_P10[0],/* 76: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC5_P1,/* 77: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC5_P2,/* 78: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC5_P3,/* 79: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC5_P4,/* 80: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC5_P5,/* 81: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC5_P6,/* 82: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC5_P7,/* 83: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC5_P8,/* 84: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC5_P9,/* 85: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC5_P10[0],/* 86: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC6_P1,/* 87: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC6_P2,/* 88: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC6_P3,/* 89: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC6_P4,/* 90: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC6_P5,/* 91: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC6_P6,/* 92: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC6_P7,/* 93: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC6_P8,/* 94: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC6_P9,/* 95: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC6_P10[0],/* 96: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC7_P1,/* 97: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC7_P2,/* 98: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC7_P3,/* 99: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC7_P4,/* 100: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC7_P5,/* 101: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC7_P6,/* 102: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC7_P7,/* 103: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC7_P8,/* 104: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC7_P9,/* 105: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229ENC7_P10[0],/* 106: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229DA1_P1,/* 107: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229DA1_P2,/* 108: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229DA1_P3,/* 109: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229DA1_P4,/* 110: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229DA1_P5,/* 111: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229DA1_P6[0],/* 112: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229DA1_P7,/* 113: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229DA2_P1,/* 114: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229DA2_P2,/* 115: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229DA2_P3,/* 116: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229DA2_P4,/* 117: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229DA2_P5,/* 118: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229DA2_P6[0],/* 119: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229DA2_P7,/* 120: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229DI_P1[0],/* 121: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229DI_P2,/* 122: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229DI_P3[0],/* 123: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229DI_P4,/* 124: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229DI_P5,/* 125: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229DO2_P1,/* 126: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229DO2_P2,/* 127: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229DO2_P3,/* 128: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229DO2_P4,/* 129: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229DO2_P5[0],/* 130: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229DO2_P6,/* 131: Block Parameter */
  &homing_ldm_aggiornat_P.PCI6229DO2_P7,/* 132: Block Parameter */
  &homing_ldm_aggiornat_P.TSamp_WtEt_j,/* 133: Block Parameter */
  &homing_ldm_aggiornat_P.TSamp_WtEt,  /* 134: Block Parameter */
  &homing_ldm_aggiornat_P.TSamp_WtEt_b,/* 135: Block Parameter */
  &homing_ldm_aggiornat_P.TSamp_WtEt_h,/* 136: Block Parameter */
  &homing_ldm_aggiornat_P.parx,        /* 137: Model Parameter */
  &homing_ldm_aggiornat_P.pary,        /* 138: Model Parameter */
  &homing_ldm_aggiornat_P.ppx_c,       /* 139: Model Parameter */
  &homing_ldm_aggiornat_P.ppy_c,       /* 140: Model Parameter */
  &homing_ldm_aggiornat_P.Vel_asse_x[0],/* 141: Model Parameter */
  &homing_ldm_aggiornat_P.Vel_asse_y[0],/* 142: Model Parameter */
  &homing_ldm_aggiornat_P.time[0],     /* 143: Model Parameter */
  &homing_ldm_aggiornat_P.x[0],        /* 144: Model Parameter */
  &homing_ldm_aggiornat_P.y[0],        /* 145: Model Parameter */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

#endif

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 },

  { "struct", "struct_p4a3fbOfYyoF57AQ0TsR2D", 32, 1, sizeof
    (struct_p4a3fbOfYyoF57AQ0TsR2D), SS_STRUCT, 0, 0 },

  { "struct", "struct_MxqrZmnGbOcHrCh1hlquB", 32, 33, sizeof
    (struct_MxqrZmnGbOcHrCh1hlquB), SS_STRUCT, 0, 0 },

  { "struct", "creal_T", 0, 0, sizeof(creal_T), SS_DOUBLE, 1, 0 },

  { "struct", "struct_0cTP9OGKNIwjZ53OR7EfCC", 13, 65, sizeof
    (struct_0cTP9OGKNIwjZ53OR7EfCC), SS_STRUCT, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },

  { "Jm", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, Jm), 0, 3, 0 },

  { "n", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, n), 0, 3, 0 },

  { "Cm", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, Cm), 0, 3, 0 },

  { "Jp1", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, Jp1), 0, 3, 0 },

  { "Jp2", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, Jp2), 0, 3, 0 },

  { "Jp3", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, Jp3), 0, 3, 0 },

  { "m", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, m), 0, 3, 0 },

  { "d1", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, d1), 0, 3, 0 },

  { "d2", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, d2), 0, 3, 0 },

  { "d3", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, d3), 0, 3, 0 },

  { "r1", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, r1), 0, 3, 0 },

  { "r2", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, r2), 0, 3, 0 },

  { "r3", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, r3), 0, 3, 0 },

  { "a1", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, a1), 0, 3, 0 },

  { "a2", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, a2), 0, 3, 0 },

  { "L1", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, L1), 0, 3, 0 },

  { "L2", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, L2), 0, 3, 0 },

  { "kcs1", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, kcs1), 0, 3, 0 },

  { "kcs2", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, kcs2), 0, 3, 0 },

  { "W1", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, W1), 0, 3, 0 },

  { "W2", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, W2), 0, 3, 0 },

  { "k1", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, k1), 0, 3, 0 },

  { "k2", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, k2), 0, 3, 0 },

  { "k3", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, k3), 0, 3, 0 },

  { "k4", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, k4), 0, 3, 0 },

  { "M", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, M), 0, 4, 0 },

  { "K", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, K), 0, 4, 0 },

  { "z", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, z), 0, 3, 0 },

  { "tau", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, tau), 0, 3, 0 },

  { "V", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, V), 0, 4, 0 },

  { "D", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, D), 0, 4, 0 },

  { "i", rt_offsetof(struct_p4a3fbOfYyoF57AQ0TsR2D, i), 0, 3, 0 },

  { "Jm", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, Jm), 0, 3, 0 },

  { "n", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, n), 0, 3, 0 },

  { "Cm", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, Cm), 0, 3, 0 },

  { "Jp1", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, Jp1), 0, 3, 0 },

  { "Jp2", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, Jp2), 0, 3, 0 },

  { "Jp3", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, Jp3), 0, 3, 0 },

  { "Mx", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, Mx), 0, 3, 0 },

  { "d1", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, d1), 0, 3, 0 },

  { "d2", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, d2), 0, 3, 0 },

  { "d3", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, d3), 0, 3, 0 },

  { "r1", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, r1), 0, 3, 0 },

  { "r2", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, r2), 0, 3, 0 },

  { "r3", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, r3), 0, 3, 0 },

  { "a1", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, a1), 0, 3, 0 },

  { "a2", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, a2), 0, 3, 0 },

  { "L1", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, L1), 0, 3, 0 },

  { "L2", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, L2), 0, 3, 0 },

  { "kcs1", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, kcs1), 0, 3, 0 },

  { "kcs2", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, kcs2), 0, 3, 0 },

  { "W1", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, W1), 0, 3, 0 },

  { "W2", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, W2), 0, 3, 0 },

  { "k1", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, k1), 0, 3, 0 },

  { "k2", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, k2), 0, 3, 0 },

  { "k3", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, k3), 0, 3, 0 },

  { "k4", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, k4), 0, 3, 0 },

  { "My", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, My), 0, 4, 0 },

  { "Ky", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, Ky), 0, 4, 0 },

  { "z", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, z), 0, 3, 0 },

  { "tau", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, tau), 0, 3, 0 },

  { "Vy", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, Vy), 0, 4, 0 },

  { "Dy", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, Dy), 0, 4, 0 },

  { "i", rt_offsetof(struct_MxqrZmnGbOcHrCh1hlquB, i), 0, 3, 0 },

  { "g1", rt_offsetof(struct_0cTP9OGKNIwjZ53OR7EfCC, g1), 0, 3, 0 },

  { "g2", rt_offsetof(struct_0cTP9OGKNIwjZ53OR7EfCC, g2), 0, 3, 0 },

  { "w0", rt_offsetof(struct_0cTP9OGKNIwjZ53OR7EfCC, w0), 0, 3, 0 },

  { "csi", rt_offsetof(struct_0cTP9OGKNIwjZ53OR7EfCC, csi), 0, 3, 0 },

  { "poli", rt_offsetof(struct_0cTP9OGKNIwjZ53OR7EfCC, poli), 3, 5, 0 },

  { "G", rt_offsetof(struct_0cTP9OGKNIwjZ53OR7EfCC, G), 0, 5, 0 },

  { "A", rt_offsetof(struct_0cTP9OGKNIwjZ53OR7EfCC, A), 0, 6, 0 },

  { "B", rt_offsetof(struct_0cTP9OGKNIwjZ53OR7EfCC, B), 0, 7, 0 },

  { "Ac", rt_offsetof(struct_0cTP9OGKNIwjZ53OR7EfCC, Ac), 0, 6, 0 },

  { "Astar", rt_offsetof(struct_0cTP9OGKNIwjZ53OR7EfCC, Astar), 0, 6, 0 },

  { "G_place", rt_offsetof(struct_0cTP9OGKNIwjZ53OR7EfCC, G_place), 0, 5, 0 },

  { "Ac_place", rt_offsetof(struct_0cTP9OGKNIwjZ53OR7EfCC, Ac_place), 0, 6, 0 },

  { "Astar_place", rt_offsetof(struct_0cTP9OGKNIwjZ53OR7EfCC, Astar_place), 0, 6,
    0 }
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 },

  { rtwCAPI_VECTOR, 2, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 0, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 6, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 2, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 8, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 10, 2, 0 },

  { rtwCAPI_VECTOR, 12, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  1,                                   /* 2 */
  2,                                   /* 3 */
  1,                                   /* 4 */
  4,                                   /* 5 */
  4,                                   /* 6 */
  4,                                   /* 7 */
  2,                                   /* 8 */
  2,                                   /* 9 */
  2,                                   /* 10 */
  1,                                   /* 11 */
  1,                                   /* 12 */
  3320                                 /* 13 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.001, 0.0
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[1],
    1, 0 },

  { (const void *) &rtcapiStoredFloats[1], (const void *) &rtcapiStoredFloats[1],
    0, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals,
   *           rootInputs, numRootInputs,
   *           rootOutputs, numRootOutputs},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 54,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 83,
    rtModelParameters, 9 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 3840144589U,
    1656139086U,
    3114637401U,
    4285199147U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  homing_ldm_aggiornat_GetCAPIStaticMap()
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void homing_ldm_aggiornat_InitializeDataMapInfo(RT_MODEL_homing_ldm_aggiornat_T *
  const homing_ldm_aggiornat_M)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(homing_ldm_aggiornat_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(homing_ldm_aggiornat_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(homing_ldm_aggiornat_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(homing_ldm_aggiornat_M->DataMapInfo.mmi,
    rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(homing_ldm_aggiornat_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache C-API rtp Address and size  into the Real-Time Model Data structure */
  homing_ldm_aggiornat_M->DataMapInfo.mmi.InstanceMap.rtpAddress =
    rtmGetDefaultParam(homing_ldm_aggiornat_M);
  homing_ldm_aggiornat_M->DataMapInfo.mmi.staticMap->rtpSize = sizeof
    (P_homing_ldm_aggiornat_T);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(homing_ldm_aggiornat_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(homing_ldm_aggiornat_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(homing_ldm_aggiornat_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void homing_ldm_aggiornat_host_InitializeDataMapInfo
    (homing_ldm_aggiornat_host_DataMapInfo_T *dataMap, const char *path)
  {
    /* Set C-API version */
    rtwCAPI_SetVersion(dataMap->mmi, 1);

    /* Cache static C-API data into the Real-time Model Data structure */
    rtwCAPI_SetStaticMap(dataMap->mmi, &mmiStatic);

    /* host data address map is NULL */
    rtwCAPI_SetDataAddressMap(dataMap->mmi, NULL);

    /* host vardims address map is NULL */
    rtwCAPI_SetVarDimsAddressMap(dataMap->mmi, NULL);

    /* Set Instance specific path */
    rtwCAPI_SetPath(dataMap->mmi, path);
    rtwCAPI_SetFullPath(dataMap->mmi, NULL);

    /* Set reference to submodels */
    rtwCAPI_SetChildMMIArray(dataMap->mmi, (NULL));
    rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 0);
  }

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* EOF: homing_ldm_aggiornat_capi.c */
