/*
 * homing_ldm_capi.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "homing_ldm".
 *
 * Model version              : 1.43
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Thu Nov 25 16:40:08 2021
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "homing_ldm_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "homing_ldm.h"
#include "homing_ldm_capi.h"
#include "homing_ldm_private.h"
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
    TARGET_STRING("X"), 6, 0, 0, 0, 0 },

  { 7, 0, TARGET_STRING("Clock"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 8, 0, TARGET_STRING("Constant1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 9, 0, TARGET_STRING("Gain"),
    TARGET_STRING("posizione motore x"), 0, 0, 0, 0, 0 },

  { 10, 0, TARGET_STRING("Gain1"),
    TARGET_STRING("posizione carrello y"), 0, 0, 0, 0, 0 },

  { 11, 0, TARGET_STRING("Gain2"),
    TARGET_STRING("posizione motore y"), 0, 0, 0, 0, 0 },

  { 12, 0, TARGET_STRING("Gain3"),
    TARGET_STRING("posizione carrello x"), 0, 0, 0, 0, 0 },

  { 13, 0, TARGET_STRING("Gain4"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 14, 0, TARGET_STRING("Gain7"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 15, 0, TARGET_STRING("Gain8"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 16, 0, TARGET_STRING("Gain9"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 17, 0, TARGET_STRING("PCI 6229 ENC "),
    TARGET_STRING("posizione motore x"), 0, 0, 0, 0, 0 },

  { 18, 0, TARGET_STRING("PCI 6229 ENC 1"),
    TARGET_STRING("pozione motore y"), 0, 0, 0, 0, 0 },

  { 19, 0, TARGET_STRING("PCI 6229 ENC 2"),
    TARGET_STRING("posizione carrello y"), 0, 0, 0, 0, 0 },

  { 20, 0, TARGET_STRING("PCI 6229 ENC 3"),
    TARGET_STRING("posizione carrello x"), 0, 0, 0, 0, 0 },

  { 21, 0, TARGET_STRING("PCI-6229 DI/p1"),
    TARGET_STRING("fc x sx"), 0, 0, 0, 0, 0 },

  { 22, 0, TARGET_STRING("PCI-6229 DI/p2"),
    TARGET_STRING("fc x dx"), 1, 0, 0, 0, 0 },

  { 23, 0, TARGET_STRING("PCI-6229 DI/p3"),
    TARGET_STRING("fc y high"), 2, 0, 0, 0, 0 },

  { 24, 0, TARGET_STRING("PCI-6229 DI/p4"),
    TARGET_STRING("fc y down"), 3, 0, 0, 0, 0 },

  { 25, 0, TARGET_STRING("Sum2"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 26, 0, TARGET_STRING("Sum3"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 27, 0, TARGET_STRING("Sum4"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 28, 0, TARGET_STRING("Sum5"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 29, 0, TARGET_STRING("Dot Product3"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 30, 0, TARGET_STRING("Dot Product4"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 31, 0, TARGET_STRING("Dot Product5"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 32, 0, TARGET_STRING("Dot Product6"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 33, 0, TARGET_STRING("Discrete Derivative/Diff"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 34, 0, TARGET_STRING("Discrete Derivative/TSamp"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 35, 0, TARGET_STRING("Discrete Derivative/UD"),
    TARGET_STRING("U(k-1)"), 0, 0, 0, 0, 0 },

  { 36, 0, TARGET_STRING("Discrete Derivative1/Diff"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 37, 0, TARGET_STRING("Discrete Derivative1/TSamp"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 38, 0, TARGET_STRING("Discrete Derivative1/UD"),
    TARGET_STRING("U(k-1)"), 0, 0, 0, 0, 0 },

  { 39, 0, TARGET_STRING("Discrete Derivative2/Diff"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 40, 0, TARGET_STRING("Discrete Derivative2/TSamp"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 41, 0, TARGET_STRING("Discrete Derivative2/UD"),
    TARGET_STRING("U(k-1)"), 0, 0, 0, 0, 0 },

  { 42, 0, TARGET_STRING("Discrete Derivative3/Diff"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 43, 0, TARGET_STRING("Discrete Derivative3/TSamp"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 44, 0, TARGET_STRING("Discrete Derivative3/UD"),
    TARGET_STRING("U(k-1)"), 0, 0, 0, 0, 0 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 45, TARGET_STRING("Discrete Derivative"),
    TARGET_STRING("ICPrevScaledInput"), 0, 0, 0 },

  { 46, TARGET_STRING("Discrete Derivative1"),
    TARGET_STRING("ICPrevScaledInput"), 0, 0, 0 },

  { 47, TARGET_STRING("Discrete Derivative2"),
    TARGET_STRING("ICPrevScaledInput"), 0, 0, 0 },

  { 48, TARGET_STRING("Discrete Derivative3"),
    TARGET_STRING("ICPrevScaledInput"), 0, 0, 0 },

  { 49, TARGET_STRING("Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 50, TARGET_STRING("Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 51, TARGET_STRING("Gain1"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 52, TARGET_STRING("Gain2"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 53, TARGET_STRING("Gain3"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 54, TARGET_STRING("Gain4"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 55, TARGET_STRING("Gain7"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 56, TARGET_STRING("Gain8"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 57, TARGET_STRING("Gain9"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 58, TARGET_STRING("PCI 6229 ENC "),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 59, TARGET_STRING("PCI 6229 ENC "),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 60, TARGET_STRING("PCI 6229 ENC "),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 61, TARGET_STRING("PCI 6229 ENC "),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 62, TARGET_STRING("PCI 6229 ENC "),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 63, TARGET_STRING("PCI 6229 ENC "),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 64, TARGET_STRING("PCI 6229 ENC "),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 65, TARGET_STRING("PCI 6229 ENC "),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 66, TARGET_STRING("PCI 6229 ENC "),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 67, TARGET_STRING("PCI 6229 ENC "),
    TARGET_STRING("P10"), 0, 1, 0 },

  { 68, TARGET_STRING("PCI 6229 ENC 1"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 69, TARGET_STRING("PCI 6229 ENC 1"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 70, TARGET_STRING("PCI 6229 ENC 1"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 71, TARGET_STRING("PCI 6229 ENC 1"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 72, TARGET_STRING("PCI 6229 ENC 1"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 73, TARGET_STRING("PCI 6229 ENC 1"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 74, TARGET_STRING("PCI 6229 ENC 1"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 75, TARGET_STRING("PCI 6229 ENC 1"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 76, TARGET_STRING("PCI 6229 ENC 1"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 77, TARGET_STRING("PCI 6229 ENC 1"),
    TARGET_STRING("P10"), 0, 1, 0 },

  { 78, TARGET_STRING("PCI 6229 ENC 2"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 79, TARGET_STRING("PCI 6229 ENC 2"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 80, TARGET_STRING("PCI 6229 ENC 2"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 81, TARGET_STRING("PCI 6229 ENC 2"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 82, TARGET_STRING("PCI 6229 ENC 2"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 83, TARGET_STRING("PCI 6229 ENC 2"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 84, TARGET_STRING("PCI 6229 ENC 2"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 85, TARGET_STRING("PCI 6229 ENC 2"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 86, TARGET_STRING("PCI 6229 ENC 2"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 87, TARGET_STRING("PCI 6229 ENC 2"),
    TARGET_STRING("P10"), 0, 1, 0 },

  { 88, TARGET_STRING("PCI 6229 ENC 3"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 89, TARGET_STRING("PCI 6229 ENC 3"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 90, TARGET_STRING("PCI 6229 ENC 3"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 91, TARGET_STRING("PCI 6229 ENC 3"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 92, TARGET_STRING("PCI 6229 ENC 3"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 93, TARGET_STRING("PCI 6229 ENC 3"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 94, TARGET_STRING("PCI 6229 ENC 3"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 95, TARGET_STRING("PCI 6229 ENC 3"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 96, TARGET_STRING("PCI 6229 ENC 3"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 97, TARGET_STRING("PCI 6229 ENC 3"),
    TARGET_STRING("P10"), 0, 1, 0 },

  { 98, TARGET_STRING("PCI-6229 DA4"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 99, TARGET_STRING("PCI-6229 DA4"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 100, TARGET_STRING("PCI-6229 DA4"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 101, TARGET_STRING("PCI-6229 DA4"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 102, TARGET_STRING("PCI-6229 DA4"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 103, TARGET_STRING("PCI-6229 DA4"),
    TARGET_STRING("P6"), 0, 1, 0 },

  { 104, TARGET_STRING("PCI-6229 DA4"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 105, TARGET_STRING("PCI-6229 DA5"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 106, TARGET_STRING("PCI-6229 DA5"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 107, TARGET_STRING("PCI-6229 DA5"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 108, TARGET_STRING("PCI-6229 DA5"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 109, TARGET_STRING("PCI-6229 DA5"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 110, TARGET_STRING("PCI-6229 DA5"),
    TARGET_STRING("P6"), 0, 1, 0 },

  { 111, TARGET_STRING("PCI-6229 DA5"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 112, TARGET_STRING("PCI-6229 DI"),
    TARGET_STRING("P1"), 0, 2, 0 },

  { 113, TARGET_STRING("PCI-6229 DI"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 114, TARGET_STRING("PCI-6229 DI"),
    TARGET_STRING("P3"), 0, 1, 0 },

  { 115, TARGET_STRING("PCI-6229 DI"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 116, TARGET_STRING("PCI-6229 DI"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 117, TARGET_STRING("PCI-6229 DO1"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 118, TARGET_STRING("PCI-6229 DO1"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 119, TARGET_STRING("PCI-6229 DO1"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 120, TARGET_STRING("PCI-6229 DO1"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 121, TARGET_STRING("PCI-6229 DO1"),
    TARGET_STRING("P5"), 0, 1, 0 },

  { 122, TARGET_STRING("PCI-6229 DO1"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 123, TARGET_STRING("PCI-6229 DO1"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 124, TARGET_STRING("Discrete Derivative/TSamp"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 125, TARGET_STRING("Discrete Derivative1/TSamp"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 126, TARGET_STRING("Discrete Derivative2/TSamp"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 127, TARGET_STRING("Discrete Derivative3/TSamp"),
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
  &homing_ldm_B.Vel_x_out,             /* 0: Signal */
  &homing_ldm_B.ok_x,                  /* 1: Signal */
  &homing_ldm_B.ok_y,                  /* 2: Signal */
  &homing_ldm_B.Vel_y_out,             /* 3: Signal */
  &homing_ldm_B.ok_x_2,                /* 4: Signal */
  &homing_ldm_B.ok_y_2,                /* 5: Signal */
  &homing_ldm_B.X_,                    /* 6: Signal */
  &homing_ldm_B.Clock,                 /* 7: Signal */
  &homing_ldm_B.Constant1,             /* 8: Signal */
  &homing_ldm_B.posizionemotorex_n,    /* 9: Signal */
  &homing_ldm_B.posizionecarrelloy_n,  /* 10: Signal */
  &homing_ldm_B.posizionemotorey,      /* 11: Signal */
  &homing_ldm_B.posizionecarrellox_n,  /* 12: Signal */
  &homing_ldm_B.Gain4,                 /* 13: Signal */
  &homing_ldm_B.Gain7,                 /* 14: Signal */
  &homing_ldm_B.Gain8,                 /* 15: Signal */
  &homing_ldm_B.Gain9,                 /* 16: Signal */
  &homing_ldm_B.posizionemotorex,      /* 17: Signal */
  &homing_ldm_B.pozionemotorey,        /* 18: Signal */
  &homing_ldm_B.posizionecarrelloy,    /* 19: Signal */
  &homing_ldm_B.posizionecarrellox,    /* 20: Signal */
  &homing_ldm_B.fcxsx,                 /* 21: Signal */
  &homing_ldm_B.fcxdx,                 /* 22: Signal */
  &homing_ldm_B.fcyhigh,               /* 23: Signal */
  &homing_ldm_B.fcydown,               /* 24: Signal */
  &homing_ldm_B.Sum2,                  /* 25: Signal */
  &homing_ldm_B.Sum3,                  /* 26: Signal */
  &homing_ldm_B.Sum4,                  /* 27: Signal */
  &homing_ldm_B.Sum5,                  /* 28: Signal */
  &homing_ldm_B.DotProduct3,           /* 29: Signal */
  &homing_ldm_B.DotProduct4,           /* 30: Signal */
  &homing_ldm_B.DotProduct5,           /* 31: Signal */
  &homing_ldm_B.DotProduct6,           /* 32: Signal */
  &homing_ldm_B.Diff_a,                /* 33: Signal */
  &homing_ldm_B.TSamp_m,               /* 34: Signal */
  &homing_ldm_B.Uk1_j,                 /* 35: Signal */
  &homing_ldm_B.Diff_d,                /* 36: Signal */
  &homing_ldm_B.TSamp_h,               /* 37: Signal */
  &homing_ldm_B.Uk1_i,                 /* 38: Signal */
  &homing_ldm_B.Diff_i,                /* 39: Signal */
  &homing_ldm_B.TSamp_d,               /* 40: Signal */
  &homing_ldm_B.Uk1_jq,                /* 41: Signal */
  &homing_ldm_B.Diff,                  /* 42: Signal */
  &homing_ldm_B.TSamp,                 /* 43: Signal */
  &homing_ldm_B.Uk1,                   /* 44: Signal */
  &homing_ldm_P.DiscreteDerivative_ICPrevScaled,/* 45: Mask Parameter */
  &homing_ldm_P.DiscreteDerivative1_ICPrevScale,/* 46: Mask Parameter */
  &homing_ldm_P.DiscreteDerivative2_ICPrevScale,/* 47: Mask Parameter */
  &homing_ldm_P.DiscreteDerivative3_ICPrevScale,/* 48: Mask Parameter */
  &homing_ldm_P.Constant1_Value,       /* 49: Block Parameter */
  &homing_ldm_P.Gain_Gain,             /* 50: Block Parameter */
  &homing_ldm_P.Gain1_Gain,            /* 51: Block Parameter */
  &homing_ldm_P.Gain2_Gain,            /* 52: Block Parameter */
  &homing_ldm_P.Gain3_Gain,            /* 53: Block Parameter */
  &homing_ldm_P.Gain4_Gain,            /* 54: Block Parameter */
  &homing_ldm_P.Gain7_Gain,            /* 55: Block Parameter */
  &homing_ldm_P.Gain8_Gain,            /* 56: Block Parameter */
  &homing_ldm_P.Gain9_Gain,            /* 57: Block Parameter */
  &homing_ldm_P.PCI6229ENC_P1,         /* 58: Block Parameter */
  &homing_ldm_P.PCI6229ENC_P2,         /* 59: Block Parameter */
  &homing_ldm_P.PCI6229ENC_P3,         /* 60: Block Parameter */
  &homing_ldm_P.PCI6229ENC_P4,         /* 61: Block Parameter */
  &homing_ldm_P.PCI6229ENC_P5,         /* 62: Block Parameter */
  &homing_ldm_P.PCI6229ENC_P6,         /* 63: Block Parameter */
  &homing_ldm_P.PCI6229ENC_P7,         /* 64: Block Parameter */
  &homing_ldm_P.PCI6229ENC_P8,         /* 65: Block Parameter */
  &homing_ldm_P.PCI6229ENC_P9,         /* 66: Block Parameter */
  &homing_ldm_P.PCI6229ENC_P10[0],     /* 67: Block Parameter */
  &homing_ldm_P.PCI6229ENC1_P1,        /* 68: Block Parameter */
  &homing_ldm_P.PCI6229ENC1_P2,        /* 69: Block Parameter */
  &homing_ldm_P.PCI6229ENC1_P3,        /* 70: Block Parameter */
  &homing_ldm_P.PCI6229ENC1_P4,        /* 71: Block Parameter */
  &homing_ldm_P.PCI6229ENC1_P5,        /* 72: Block Parameter */
  &homing_ldm_P.PCI6229ENC1_P6,        /* 73: Block Parameter */
  &homing_ldm_P.PCI6229ENC1_P7,        /* 74: Block Parameter */
  &homing_ldm_P.PCI6229ENC1_P8,        /* 75: Block Parameter */
  &homing_ldm_P.PCI6229ENC1_P9,        /* 76: Block Parameter */
  &homing_ldm_P.PCI6229ENC1_P10[0],    /* 77: Block Parameter */
  &homing_ldm_P.PCI6229ENC2_P1,        /* 78: Block Parameter */
  &homing_ldm_P.PCI6229ENC2_P2,        /* 79: Block Parameter */
  &homing_ldm_P.PCI6229ENC2_P3,        /* 80: Block Parameter */
  &homing_ldm_P.PCI6229ENC2_P4,        /* 81: Block Parameter */
  &homing_ldm_P.PCI6229ENC2_P5,        /* 82: Block Parameter */
  &homing_ldm_P.PCI6229ENC2_P6,        /* 83: Block Parameter */
  &homing_ldm_P.PCI6229ENC2_P7,        /* 84: Block Parameter */
  &homing_ldm_P.PCI6229ENC2_P8,        /* 85: Block Parameter */
  &homing_ldm_P.PCI6229ENC2_P9,        /* 86: Block Parameter */
  &homing_ldm_P.PCI6229ENC2_P10[0],    /* 87: Block Parameter */
  &homing_ldm_P.PCI6229ENC3_P1,        /* 88: Block Parameter */
  &homing_ldm_P.PCI6229ENC3_P2,        /* 89: Block Parameter */
  &homing_ldm_P.PCI6229ENC3_P3,        /* 90: Block Parameter */
  &homing_ldm_P.PCI6229ENC3_P4,        /* 91: Block Parameter */
  &homing_ldm_P.PCI6229ENC3_P5,        /* 92: Block Parameter */
  &homing_ldm_P.PCI6229ENC3_P6,        /* 93: Block Parameter */
  &homing_ldm_P.PCI6229ENC3_P7,        /* 94: Block Parameter */
  &homing_ldm_P.PCI6229ENC3_P8,        /* 95: Block Parameter */
  &homing_ldm_P.PCI6229ENC3_P9,        /* 96: Block Parameter */
  &homing_ldm_P.PCI6229ENC3_P10[0],    /* 97: Block Parameter */
  &homing_ldm_P.PCI6229DA4_P1,         /* 98: Block Parameter */
  &homing_ldm_P.PCI6229DA4_P2,         /* 99: Block Parameter */
  &homing_ldm_P.PCI6229DA4_P3,         /* 100: Block Parameter */
  &homing_ldm_P.PCI6229DA4_P4,         /* 101: Block Parameter */
  &homing_ldm_P.PCI6229DA4_P5,         /* 102: Block Parameter */
  &homing_ldm_P.PCI6229DA4_P6[0],      /* 103: Block Parameter */
  &homing_ldm_P.PCI6229DA4_P7,         /* 104: Block Parameter */
  &homing_ldm_P.PCI6229DA5_P1,         /* 105: Block Parameter */
  &homing_ldm_P.PCI6229DA5_P2,         /* 106: Block Parameter */
  &homing_ldm_P.PCI6229DA5_P3,         /* 107: Block Parameter */
  &homing_ldm_P.PCI6229DA5_P4,         /* 108: Block Parameter */
  &homing_ldm_P.PCI6229DA5_P5,         /* 109: Block Parameter */
  &homing_ldm_P.PCI6229DA5_P6[0],      /* 110: Block Parameter */
  &homing_ldm_P.PCI6229DA5_P7,         /* 111: Block Parameter */
  &homing_ldm_P.PCI6229DI_P1[0],       /* 112: Block Parameter */
  &homing_ldm_P.PCI6229DI_P2,          /* 113: Block Parameter */
  &homing_ldm_P.PCI6229DI_P3[0],       /* 114: Block Parameter */
  &homing_ldm_P.PCI6229DI_P4,          /* 115: Block Parameter */
  &homing_ldm_P.PCI6229DI_P5,          /* 116: Block Parameter */
  &homing_ldm_P.PCI6229DO1_P1,         /* 117: Block Parameter */
  &homing_ldm_P.PCI6229DO1_P2,         /* 118: Block Parameter */
  &homing_ldm_P.PCI6229DO1_P3,         /* 119: Block Parameter */
  &homing_ldm_P.PCI6229DO1_P4,         /* 120: Block Parameter */
  &homing_ldm_P.PCI6229DO1_P5[0],      /* 121: Block Parameter */
  &homing_ldm_P.PCI6229DO1_P6,         /* 122: Block Parameter */
  &homing_ldm_P.PCI6229DO1_P7,         /* 123: Block Parameter */
  &homing_ldm_P.TSamp_WtEt_e,          /* 124: Block Parameter */
  &homing_ldm_P.TSamp_WtEt_j,          /* 125: Block Parameter */
  &homing_ldm_P.TSamp_WtEt_f,          /* 126: Block Parameter */
  &homing_ldm_P.TSamp_WtEt,            /* 127: Block Parameter */
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
  { rtBlockSignals, 45,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 83,
    rtModelParameters, 0 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 3973694538U,
    2320114687U,
    2432879279U,
    631891228U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  homing_ldm_GetCAPIStaticMap()
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void homing_ldm_InitializeDataMapInfo(RT_MODEL_homing_ldm_T *const homing_ldm_M)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(homing_ldm_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(homing_ldm_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(homing_ldm_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(homing_ldm_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(homing_ldm_M->DataMapInfo.mmi, rtVarDimsAddrMap);

  /* Cache C-API rtp Address and size  into the Real-Time Model Data structure */
  homing_ldm_M->DataMapInfo.mmi.InstanceMap.rtpAddress = rtmGetDefaultParam
    (homing_ldm_M);
  homing_ldm_M->DataMapInfo.mmi.staticMap->rtpSize = sizeof(P_homing_ldm_T);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(homing_ldm_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(homing_ldm_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(homing_ldm_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void homing_ldm_host_InitializeDataMapInfo(homing_ldm_host_DataMapInfo_T
    *dataMap, const char *path)
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

/* EOF: homing_ldm_capi.c */
