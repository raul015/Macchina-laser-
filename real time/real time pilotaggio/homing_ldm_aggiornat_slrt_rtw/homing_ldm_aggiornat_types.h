/*
 * homing_ldm_aggiornat_types.h
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

#ifndef RTW_HEADER_homing_ldm_aggiornat_types_h_
#define RTW_HEADER_homing_ldm_aggiornat_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_0cTP9OGKNIwjZ53OR7EfCC_
#define DEFINED_TYPEDEF_FOR_struct_0cTP9OGKNIwjZ53OR7EfCC_

typedef struct {
  real_T g1;
  real_T g2;
  real_T w0;
  real_T csi;
  creal_T poli[2];
  real_T G[2];
  real_T A[4];
  real_T B[2];
  real_T Ac[4];
  real_T Astar[4];
  real_T G_place[2];
  real_T Ac_place[4];
  real_T Astar_place[4];
} struct_0cTP9OGKNIwjZ53OR7EfCC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_p4a3fbOfYyoF57AQ0TsR2D_
#define DEFINED_TYPEDEF_FOR_struct_p4a3fbOfYyoF57AQ0TsR2D_

typedef struct {
  real_T Jm;
  real_T n;
  real_T Cm;
  real_T Jp1;
  real_T Jp2;
  real_T Jp3;
  real_T m;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T r1;
  real_T r2;
  real_T r3;
  real_T a1;
  real_T a2;
  real_T L1;
  real_T L2;
  real_T kcs1;
  real_T kcs2;
  real_T W1;
  real_T W2;
  real_T k1;
  real_T k2;
  real_T k3;
  real_T k4;
  real_T M[16];
  real_T K[16];
  real_T z;
  real_T tau;
  real_T V[16];
  real_T D[16];
  real_T i;
} struct_p4a3fbOfYyoF57AQ0TsR2D;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_MxqrZmnGbOcHrCh1hlquB_
#define DEFINED_TYPEDEF_FOR_struct_MxqrZmnGbOcHrCh1hlquB_

typedef struct {
  real_T Jm;
  real_T n;
  real_T Cm;
  real_T Jp1;
  real_T Jp2;
  real_T Jp3;
  real_T Mx;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T r1;
  real_T r2;
  real_T r3;
  real_T a1;
  real_T a2;
  real_T L1;
  real_T L2;
  real_T kcs1;
  real_T kcs2;
  real_T W1;
  real_T W2;
  real_T k1;
  real_T k2;
  real_T k3;
  real_T k4;
  real_T My[16];
  real_T Ky[16];
  real_T z;
  real_T tau;
  real_T Vy[16];
  real_T Dy[16];
  real_T i;
} struct_MxqrZmnGbOcHrCh1hlquB;

#endif

/* Parameters (auto storage) */
typedef struct P_homing_ldm_aggiornat_T_ P_homing_ldm_aggiornat_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_homing_ldm_aggiornat_T RT_MODEL_homing_ldm_aggiornat_T;

#endif                                 /* RTW_HEADER_homing_ldm_aggiornat_types_h_ */
