/*
 * lettura_finecorsa_capi.c
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

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "lettura_finecorsa_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "lettura_finecorsa.h"
#include "lettura_finecorsa_capi.h"
#include "lettura_finecorsa_private.h"
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
  { 0, 0, TARGET_STRING("Constant1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 1, 0, TARGET_STRING("Constant2"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 2, 0, TARGET_STRING("Constant3"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 3, 0, TARGET_STRING("Gain"),
    TARGET_STRING("posizione motore x"), 0, 0, 0, 0, 0 },

  { 4, 0, TARGET_STRING("Gain1"),
    TARGET_STRING("posizione carrello y"), 0, 0, 0, 0, 0 },

  { 5, 0, TARGET_STRING("Gain2"),
    TARGET_STRING("posizione motore y"), 0, 0, 0, 0, 0 },

  { 6, 0, TARGET_STRING("Gain3"),
    TARGET_STRING("posizione carrello x"), 0, 0, 0, 0, 0 },

  { 7, 0, TARGET_STRING("PCI 6229 ENC "),
    TARGET_STRING("posizione motore x"), 0, 0, 0, 0, 0 },

  { 8, 0, TARGET_STRING("PCI 6229 ENC 1"),
    TARGET_STRING("pozione motore y"), 0, 0, 0, 0, 0 },

  { 9, 0, TARGET_STRING("PCI 6229 ENC 2"),
    TARGET_STRING("posizione carrello y"), 0, 0, 0, 0, 0 },

  { 10, 0, TARGET_STRING("PCI 6229 ENC 3"),
    TARGET_STRING("posizione carrello x"), 0, 0, 0, 0, 0 },

  { 11, 0, TARGET_STRING("PCI-6229 DI/p1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 12, 0, TARGET_STRING("PCI-6229 DI/p2"),
    TARGET_STRING(""), 1, 0, 0, 0, 0 },

  { 13, 0, TARGET_STRING("PCI-6229 DI/p3"),
    TARGET_STRING(""), 2, 0, 0, 0, 0 },

  { 14, 0, TARGET_STRING("PCI-6229 DI/p4"),
    TARGET_STRING(""), 3, 0, 0, 0, 0 },

  { 15, 0, TARGET_STRING("Discrete Derivative/Diff"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 16, 0, TARGET_STRING("Discrete Derivative/TSamp"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 17, 0, TARGET_STRING("Discrete Derivative/UD"),
    TARGET_STRING("U(k-1)"), 0, 0, 0, 0, 0 },

  { 18, 0, TARGET_STRING("Discrete Derivative1/Diff"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 19, 0, TARGET_STRING("Discrete Derivative1/TSamp"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 20, 0, TARGET_STRING("Discrete Derivative1/UD"),
    TARGET_STRING("U(k-1)"), 0, 0, 0, 0, 0 },

  { 21, 0, TARGET_STRING("Discrete Derivative2/Diff"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 22, 0, TARGET_STRING("Discrete Derivative2/TSamp"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 23, 0, TARGET_STRING("Discrete Derivative2/UD"),
    TARGET_STRING("U(k-1)"), 0, 0, 0, 0, 0 },

  { 24, 0, TARGET_STRING("Discrete Derivative3/Diff"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 25, 0, TARGET_STRING("Discrete Derivative3/TSamp"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 26, 0, TARGET_STRING("Discrete Derivative3/UD"),
    TARGET_STRING("U(k-1)"), 0, 0, 0, 0, 0 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 27, TARGET_STRING("Discrete Derivative"),
    TARGET_STRING("ICPrevScaledInput"), 0, 0, 0 },

  { 28, TARGET_STRING("Discrete Derivative1"),
    TARGET_STRING("ICPrevScaledInput"), 0, 0, 0 },

  { 29, TARGET_STRING("Discrete Derivative2"),
    TARGET_STRING("ICPrevScaledInput"), 0, 0, 0 },

  { 30, TARGET_STRING("Discrete Derivative3"),
    TARGET_STRING("ICPrevScaledInput"), 0, 0, 0 },

  { 31, TARGET_STRING("Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 32, TARGET_STRING("Constant2"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 33, TARGET_STRING("Constant3"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 34, TARGET_STRING("Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 35, TARGET_STRING("Gain1"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 36, TARGET_STRING("Gain2"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 37, TARGET_STRING("Gain3"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 38, TARGET_STRING("PCI 6229 ENC "),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 39, TARGET_STRING("PCI 6229 ENC "),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 40, TARGET_STRING("PCI 6229 ENC "),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 41, TARGET_STRING("PCI 6229 ENC "),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 42, TARGET_STRING("PCI 6229 ENC "),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 43, TARGET_STRING("PCI 6229 ENC "),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 44, TARGET_STRING("PCI 6229 ENC "),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 45, TARGET_STRING("PCI 6229 ENC "),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 46, TARGET_STRING("PCI 6229 ENC "),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 47, TARGET_STRING("PCI 6229 ENC "),
    TARGET_STRING("P10"), 0, 1, 0 },

  { 48, TARGET_STRING("PCI 6229 ENC 1"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 49, TARGET_STRING("PCI 6229 ENC 1"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 50, TARGET_STRING("PCI 6229 ENC 1"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 51, TARGET_STRING("PCI 6229 ENC 1"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 52, TARGET_STRING("PCI 6229 ENC 1"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 53, TARGET_STRING("PCI 6229 ENC 1"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 54, TARGET_STRING("PCI 6229 ENC 1"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 55, TARGET_STRING("PCI 6229 ENC 1"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 56, TARGET_STRING("PCI 6229 ENC 1"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 57, TARGET_STRING("PCI 6229 ENC 1"),
    TARGET_STRING("P10"), 0, 1, 0 },

  { 58, TARGET_STRING("PCI 6229 ENC 2"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 59, TARGET_STRING("PCI 6229 ENC 2"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 60, TARGET_STRING("PCI 6229 ENC 2"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 61, TARGET_STRING("PCI 6229 ENC 2"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 62, TARGET_STRING("PCI 6229 ENC 2"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 63, TARGET_STRING("PCI 6229 ENC 2"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 64, TARGET_STRING("PCI 6229 ENC 2"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 65, TARGET_STRING("PCI 6229 ENC 2"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 66, TARGET_STRING("PCI 6229 ENC 2"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 67, TARGET_STRING("PCI 6229 ENC 2"),
    TARGET_STRING("P10"), 0, 1, 0 },

  { 68, TARGET_STRING("PCI 6229 ENC 3"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 69, TARGET_STRING("PCI 6229 ENC 3"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 70, TARGET_STRING("PCI 6229 ENC 3"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 71, TARGET_STRING("PCI 6229 ENC 3"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 72, TARGET_STRING("PCI 6229 ENC 3"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 73, TARGET_STRING("PCI 6229 ENC 3"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 74, TARGET_STRING("PCI 6229 ENC 3"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 75, TARGET_STRING("PCI 6229 ENC 3"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 76, TARGET_STRING("PCI 6229 ENC 3"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 77, TARGET_STRING("PCI 6229 ENC 3"),
    TARGET_STRING("P10"), 0, 1, 0 },

  { 78, TARGET_STRING("PCI-6229 DA"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 79, TARGET_STRING("PCI-6229 DA"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 80, TARGET_STRING("PCI-6229 DA"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 81, TARGET_STRING("PCI-6229 DA"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 82, TARGET_STRING("PCI-6229 DA"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 83, TARGET_STRING("PCI-6229 DA"),
    TARGET_STRING("P6"), 0, 1, 0 },

  { 84, TARGET_STRING("PCI-6229 DA"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 85, TARGET_STRING("PCI-6229 DA1"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 86, TARGET_STRING("PCI-6229 DA1"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 87, TARGET_STRING("PCI-6229 DA1"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 88, TARGET_STRING("PCI-6229 DA1"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 89, TARGET_STRING("PCI-6229 DA1"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 90, TARGET_STRING("PCI-6229 DA1"),
    TARGET_STRING("P6"), 0, 1, 0 },

  { 91, TARGET_STRING("PCI-6229 DA1"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 92, TARGET_STRING("PCI-6229 DI"),
    TARGET_STRING("P1"), 0, 2, 0 },

  { 93, TARGET_STRING("PCI-6229 DI"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 94, TARGET_STRING("PCI-6229 DI"),
    TARGET_STRING("P3"), 0, 1, 0 },

  { 95, TARGET_STRING("PCI-6229 DI"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 96, TARGET_STRING("PCI-6229 DI"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 97, TARGET_STRING("PCI-6229 DO1"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 98, TARGET_STRING("PCI-6229 DO1"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 99, TARGET_STRING("PCI-6229 DO1"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 100, TARGET_STRING("PCI-6229 DO1"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 101, TARGET_STRING("PCI-6229 DO1"),
    TARGET_STRING("P5"), 0, 1, 0 },

  { 102, TARGET_STRING("PCI-6229 DO1"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 103, TARGET_STRING("PCI-6229 DO1"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 104, TARGET_STRING("Discrete Derivative/TSamp"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 105, TARGET_STRING("Discrete Derivative1/TSamp"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 106, TARGET_STRING("Discrete Derivative2/TSamp"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 107, TARGET_STRING("Discrete Derivative3/TSamp"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 0, (NULL), 0, 0, 0 }
};

#ifndef HOST_CAPI_BUILD

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &lettura_finecorsa_B.Constant1,      /* 0: Signal */
  &lettura_finecorsa_B.Constant2,      /* 1: Signal */
  &lettura_finecorsa_B.Constant3,      /* 2: Signal */
  &lettura_finecorsa_B.posizionemotorex_n,/* 3: Signal */
  &lettura_finecorsa_B.posizionecarrelloy_n,/* 4: Signal */
  &lettura_finecorsa_B.posizionemotorey,/* 5: Signal */
  &lettura_finecorsa_B.posizionecarrellox_n,/* 6: Signal */
  &lettura_finecorsa_B.posizionemotorex,/* 7: Signal */
  &lettura_finecorsa_B.pozionemotorey, /* 8: Signal */
  &lettura_finecorsa_B.posizionecarrelloy,/* 9: Signal */
  &lettura_finecorsa_B.posizionecarrellox,/* 10: Signal */
  &lettura_finecorsa_B.PCI6229DI_o1,   /* 11: Signal */
  &lettura_finecorsa_B.PCI6229DI_o2,   /* 12: Signal */
  &lettura_finecorsa_B.PCI6229DI_o3,   /* 13: Signal */
  &lettura_finecorsa_B.PCI6229DI_o4,   /* 14: Signal */
  &lettura_finecorsa_B.Diff,           /* 15: Signal */
  &lettura_finecorsa_B.TSamp,          /* 16: Signal */
  &lettura_finecorsa_B.Uk1,            /* 17: Signal */
  &lettura_finecorsa_B.Diff_d,         /* 18: Signal */
  &lettura_finecorsa_B.TSamp_h,        /* 19: Signal */
  &lettura_finecorsa_B.Uk1_i,          /* 20: Signal */
  &lettura_finecorsa_B.Diff_i,         /* 21: Signal */
  &lettura_finecorsa_B.TSamp_d,        /* 22: Signal */
  &lettura_finecorsa_B.Uk1_j,          /* 23: Signal */
  &lettura_finecorsa_B.Diff_p,         /* 24: Signal */
  &lettura_finecorsa_B.TSamp_e,        /* 25: Signal */
  &lettura_finecorsa_B.Uk1_e,          /* 26: Signal */
  &lettura_finecorsa_P.DiscreteDerivative_ICPrevScaled,/* 27: Mask Parameter */
  &lettura_finecorsa_P.DiscreteDerivative1_ICPrevScale,/* 28: Mask Parameter */
  &lettura_finecorsa_P.DiscreteDerivative2_ICPrevScale,/* 29: Mask Parameter */
  &lettura_finecorsa_P.DiscreteDerivative3_ICPrevScale,/* 30: Mask Parameter */
  &lettura_finecorsa_P.Constant1_Value,/* 31: Block Parameter */
  &lettura_finecorsa_P.Constant2_Value,/* 32: Block Parameter */
  &lettura_finecorsa_P.Constant3_Value,/* 33: Block Parameter */
  &lettura_finecorsa_P.Gain_Gain,      /* 34: Block Parameter */
  &lettura_finecorsa_P.Gain1_Gain,     /* 35: Block Parameter */
  &lettura_finecorsa_P.Gain2_Gain,     /* 36: Block Parameter */
  &lettura_finecorsa_P.Gain3_Gain,     /* 37: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC_P1,  /* 38: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC_P2,  /* 39: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC_P3,  /* 40: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC_P4,  /* 41: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC_P5,  /* 42: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC_P6,  /* 43: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC_P7,  /* 44: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC_P8,  /* 45: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC_P9,  /* 46: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC_P10[0],/* 47: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC1_P1, /* 48: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC1_P2, /* 49: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC1_P3, /* 50: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC1_P4, /* 51: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC1_P5, /* 52: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC1_P6, /* 53: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC1_P7, /* 54: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC1_P8, /* 55: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC1_P9, /* 56: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC1_P10[0],/* 57: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC2_P1, /* 58: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC2_P2, /* 59: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC2_P3, /* 60: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC2_P4, /* 61: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC2_P5, /* 62: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC2_P6, /* 63: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC2_P7, /* 64: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC2_P8, /* 65: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC2_P9, /* 66: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC2_P10[0],/* 67: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC3_P1, /* 68: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC3_P2, /* 69: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC3_P3, /* 70: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC3_P4, /* 71: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC3_P5, /* 72: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC3_P6, /* 73: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC3_P7, /* 74: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC3_P8, /* 75: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC3_P9, /* 76: Block Parameter */
  &lettura_finecorsa_P.PCI6229ENC3_P10[0],/* 77: Block Parameter */
  &lettura_finecorsa_P.PCI6229DA_P1,   /* 78: Block Parameter */
  &lettura_finecorsa_P.PCI6229DA_P2,   /* 79: Block Parameter */
  &lettura_finecorsa_P.PCI6229DA_P3,   /* 80: Block Parameter */
  &lettura_finecorsa_P.PCI6229DA_P4,   /* 81: Block Parameter */
  &lettura_finecorsa_P.PCI6229DA_P5,   /* 82: Block Parameter */
  &lettura_finecorsa_P.PCI6229DA_P6[0],/* 83: Block Parameter */
  &lettura_finecorsa_P.PCI6229DA_P7,   /* 84: Block Parameter */
  &lettura_finecorsa_P.PCI6229DA1_P1,  /* 85: Block Parameter */
  &lettura_finecorsa_P.PCI6229DA1_P2,  /* 86: Block Parameter */
  &lettura_finecorsa_P.PCI6229DA1_P3,  /* 87: Block Parameter */
  &lettura_finecorsa_P.PCI6229DA1_P4,  /* 88: Block Parameter */
  &lettura_finecorsa_P.PCI6229DA1_P5,  /* 89: Block Parameter */
  &lettura_finecorsa_P.PCI6229DA1_P6[0],/* 90: Block Parameter */
  &lettura_finecorsa_P.PCI6229DA1_P7,  /* 91: Block Parameter */
  &lettura_finecorsa_P.PCI6229DI_P1[0],/* 92: Block Parameter */
  &lettura_finecorsa_P.PCI6229DI_P2,   /* 93: Block Parameter */
  &lettura_finecorsa_P.PCI6229DI_P3[0],/* 94: Block Parameter */
  &lettura_finecorsa_P.PCI6229DI_P4,   /* 95: Block Parameter */
  &lettura_finecorsa_P.PCI6229DI_P5,   /* 96: Block Parameter */
  &lettura_finecorsa_P.PCI6229DO1_P1,  /* 97: Block Parameter */
  &lettura_finecorsa_P.PCI6229DO1_P2,  /* 98: Block Parameter */
  &lettura_finecorsa_P.PCI6229DO1_P3,  /* 99: Block Parameter */
  &lettura_finecorsa_P.PCI6229DO1_P4,  /* 100: Block Parameter */
  &lettura_finecorsa_P.PCI6229DO1_P5[0],/* 101: Block Parameter */
  &lettura_finecorsa_P.PCI6229DO1_P6,  /* 102: Block Parameter */
  &lettura_finecorsa_P.PCI6229DO1_P7,  /* 103: Block Parameter */
  &lettura_finecorsa_P.TSamp_WtEt,     /* 104: Block Parameter */
  &lettura_finecorsa_P.TSamp_WtEt_j,   /* 105: Block Parameter */
  &lettura_finecorsa_P.TSamp_WtEt_f,   /* 106: Block Parameter */
  &lettura_finecorsa_P.TSamp_WtEt_b,   /* 107: Block Parameter */
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
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 },

  { rtwCAPI_VECTOR, 2, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  1,                                   /* 2 */
  2,                                   /* 3 */
  1,                                   /* 4 */
  4                                    /* 5 */
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
  { rtBlockSignals, 27,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 81,
    rtModelParameters, 0 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 2833147121U,
    1628956143U,
    1035760546U,
    1951579891U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  lettura_finecorsa_GetCAPIStaticMap()
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void lettura_finecorsa_InitializeDataMapInfo(RT_MODEL_lettura_finecorsa_T *const
  lettura_finecorsa_M)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(lettura_finecorsa_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(lettura_finecorsa_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(lettura_finecorsa_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(lettura_finecorsa_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(lettura_finecorsa_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache C-API rtp Address and size  into the Real-Time Model Data structure */
  lettura_finecorsa_M->DataMapInfo.mmi.InstanceMap.rtpAddress =
    rtmGetDefaultParam(lettura_finecorsa_M);
  lettura_finecorsa_M->DataMapInfo.mmi.staticMap->rtpSize = sizeof
    (P_lettura_finecorsa_T);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(lettura_finecorsa_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(lettura_finecorsa_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(lettura_finecorsa_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void lettura_finecorsa_host_InitializeDataMapInfo
    (lettura_finecorsa_host_DataMapInfo_T *dataMap, const char *path)
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

/* EOF: lettura_finecorsa_capi.c */
