/*
 * homing_ldm_aggiornat_data.c
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

#include "homing_ldm_aggiornat.h"
#include "homing_ldm_aggiornat_private.h"

/* Block parameters (auto storage) */
P_homing_ldm_aggiornat_T homing_ldm_aggiornat_P = {
  0.0,                                 /* Mask Parameter: DiscreteDerivative5_ICPrevScale
                                        * Referenced by: '<S3>/UD'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative7_ICPrevScale
                                        * Referenced by: '<S5>/UD'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative4_ICPrevScale
                                        * Referenced by: '<S2>/UD'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative6_ICPrevScale
                                        * Referenced by: '<S4>/UD'
                                        */

  /*  Computed Parameter: PCI6229DI_P1_Size
   * Referenced by: '<Root>/PCI-6229 DI'
   */
  { 1.0, 4.0 },

  /*  Expression: channel
   * Referenced by: '<Root>/PCI-6229 DI'
   */
  { 4.0, 5.0, 6.0, 7.0 },

  /*  Computed Parameter: PCI6229DI_P2_Size
   * Referenced by: '<Root>/PCI-6229 DI'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampletime
                                        * Referenced by: '<Root>/PCI-6229 DI'
                                        */

  /*  Computed Parameter: PCI6229DI_P3_Size
   * Referenced by: '<Root>/PCI-6229 DI'
   */
  { 1.0, 2.0 },

  /*  Expression: slot
   * Referenced by: '<Root>/PCI-6229 DI'
   */
  { 4.0, 12.0 },

  /*  Computed Parameter: PCI6229DI_P4_Size
   * Referenced by: '<Root>/PCI-6229 DI'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: control
                                        * Referenced by: '<Root>/PCI-6229 DI'
                                        */

  /*  Computed Parameter: PCI6229DI_P5_Size
   * Referenced by: '<Root>/PCI-6229 DI'
   */
  { 1.0, 1.0 },
  29.0,                                /* Expression: boardType
                                        * Referenced by: '<Root>/PCI-6229 DI'
                                        */

  /*  Computed Parameter: PCI6229ENC7_P1_Size
   * Referenced by: '<Root>/PCI 6229 ENC 7'
   */
  { 1.0, 1.0 },
  29.0,                                /* Expression: device
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */

  /*  Computed Parameter: PCI6229ENC7_P2_Size
   * Referenced by: '<Root>/PCI 6229 ENC 7'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */

  /*  Computed Parameter: PCI6229ENC7_P3_Size
   * Referenced by: '<Root>/PCI 6229 ENC 7'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: countMode
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */

  /*  Computed Parameter: PCI6229ENC7_P4_Size
   * Referenced by: '<Root>/PCI 6229 ENC 7'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initCount
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */

  /*  Computed Parameter: PCI6229ENC7_P5_Size
   * Referenced by: '<Root>/PCI 6229 ENC 7'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: reload
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */

  /*  Computed Parameter: PCI6229ENC7_P6_Size
   * Referenced by: '<Root>/PCI 6229 ENC 7'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: indexPhase
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */

  /*  Computed Parameter: PCI6229ENC7_P7_Size
   * Referenced by: '<Root>/PCI 6229 ENC 7'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: filter
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */

  /*  Computed Parameter: PCI6229ENC7_P8_Size
   * Referenced by: '<Root>/PCI 6229 ENC 7'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: outmask
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */

  /*  Computed Parameter: PCI6229ENC7_P9_Size
   * Referenced by: '<Root>/PCI 6229 ENC 7'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<Root>/PCI 6229 ENC 7'
                                        */

  /*  Computed Parameter: PCI6229ENC7_P10_Size
   * Referenced by: '<Root>/PCI 6229 ENC 7'
   */
  { 1.0, 2.0 },

  /*  Expression: slot
   * Referenced by: '<Root>/PCI 6229 ENC 7'
   */
  { 4.0, 15.0 },
  -5.0E-6,                             /* Expression: -5e-6
                                        * Referenced by: '<Root>/Gain13'
                                        */

  /*  Computed Parameter: PCI6229ENC6_P1_Size
   * Referenced by: '<Root>/PCI 6229 ENC 6'
   */
  { 1.0, 1.0 },
  29.0,                                /* Expression: device
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */

  /*  Computed Parameter: PCI6229ENC6_P2_Size
   * Referenced by: '<Root>/PCI 6229 ENC 6'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: channel
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */

  /*  Computed Parameter: PCI6229ENC6_P3_Size
   * Referenced by: '<Root>/PCI 6229 ENC 6'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: countMode
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */

  /*  Computed Parameter: PCI6229ENC6_P4_Size
   * Referenced by: '<Root>/PCI 6229 ENC 6'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initCount
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */

  /*  Computed Parameter: PCI6229ENC6_P5_Size
   * Referenced by: '<Root>/PCI 6229 ENC 6'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: reload
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */

  /*  Computed Parameter: PCI6229ENC6_P6_Size
   * Referenced by: '<Root>/PCI 6229 ENC 6'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: indexPhase
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */

  /*  Computed Parameter: PCI6229ENC6_P7_Size
   * Referenced by: '<Root>/PCI 6229 ENC 6'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: filter
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */

  /*  Computed Parameter: PCI6229ENC6_P8_Size
   * Referenced by: '<Root>/PCI 6229 ENC 6'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: outmask
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */

  /*  Computed Parameter: PCI6229ENC6_P9_Size
   * Referenced by: '<Root>/PCI 6229 ENC 6'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<Root>/PCI 6229 ENC 6'
                                        */

  /*  Computed Parameter: PCI6229ENC6_P10_Size
   * Referenced by: '<Root>/PCI 6229 ENC 6'
   */
  { 1.0, 2.0 },

  /*  Expression: slot
   * Referenced by: '<Root>/PCI 6229 ENC 6'
   */
  { 4.0, 15.0 },
  -5.0E-6,                             /* Expression: -5e-6
                                        * Referenced by: '<Root>/Gain11'
                                        */
  1000.0,                              /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S3>/TSamp'
                                        */
  1000.0,                              /* Computed Parameter: TSamp_WtEt_h
                                        * Referenced by: '<S5>/TSamp'
                                        */
  1.0989,                              /* Expression: 1.0989
                                        * Referenced by: '<Root>/Gain1'
                                        */
  1.5942,                              /* Expression: 1.5942

                                        * Referenced by: '<Root>/Gain2'
                                        */
  1.0989,                              /* Expression: 1.0989
                                        * Referenced by: '<Root>/Gain3'
                                        */

  /*  Computed Parameter: PCI6229DA1_P1_Size
   * Referenced by: '<Root>/PCI-6229 DA1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<Root>/PCI-6229 DA1'
                                        */

  /*  Computed Parameter: PCI6229DA1_P2_Size
   * Referenced by: '<Root>/PCI-6229 DA1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: range
                                        * Referenced by: '<Root>/PCI-6229 DA1'
                                        */

  /*  Computed Parameter: PCI6229DA1_P3_Size
   * Referenced by: '<Root>/PCI-6229 DA1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: reset
                                        * Referenced by: '<Root>/PCI-6229 DA1'
                                        */

  /*  Computed Parameter: PCI6229DA1_P4_Size
   * Referenced by: '<Root>/PCI-6229 DA1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initValue
                                        * Referenced by: '<Root>/PCI-6229 DA1'
                                        */

  /*  Computed Parameter: PCI6229DA1_P5_Size
   * Referenced by: '<Root>/PCI-6229 DA1'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampletime
                                        * Referenced by: '<Root>/PCI-6229 DA1'
                                        */

  /*  Computed Parameter: PCI6229DA1_P6_Size
   * Referenced by: '<Root>/PCI-6229 DA1'
   */
  { 1.0, 2.0 },

  /*  Expression: slot
   * Referenced by: '<Root>/PCI-6229 DA1'
   */
  { 4.0, 12.0 },

  /*  Computed Parameter: PCI6229DA1_P7_Size
   * Referenced by: '<Root>/PCI-6229 DA1'
   */
  { 1.0, 1.0 },
  29.0,                                /* Expression: boardType
                                        * Referenced by: '<Root>/PCI-6229 DA1'
                                        */
  1.5942,                              /* Expression: 1.5942

                                        * Referenced by: '<Root>/Gain5'
                                        */

  /*  Computed Parameter: PCI6229DA2_P1_Size
   * Referenced by: '<Root>/PCI-6229 DA2'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<Root>/PCI-6229 DA2'
                                        */

  /*  Computed Parameter: PCI6229DA2_P2_Size
   * Referenced by: '<Root>/PCI-6229 DA2'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: range
                                        * Referenced by: '<Root>/PCI-6229 DA2'
                                        */

  /*  Computed Parameter: PCI6229DA2_P3_Size
   * Referenced by: '<Root>/PCI-6229 DA2'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: reset
                                        * Referenced by: '<Root>/PCI-6229 DA2'
                                        */

  /*  Computed Parameter: PCI6229DA2_P4_Size
   * Referenced by: '<Root>/PCI-6229 DA2'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initValue
                                        * Referenced by: '<Root>/PCI-6229 DA2'
                                        */

  /*  Computed Parameter: PCI6229DA2_P5_Size
   * Referenced by: '<Root>/PCI-6229 DA2'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampletime
                                        * Referenced by: '<Root>/PCI-6229 DA2'
                                        */

  /*  Computed Parameter: PCI6229DA2_P6_Size
   * Referenced by: '<Root>/PCI-6229 DA2'
   */
  { 1.0, 2.0 },

  /*  Expression: slot
   * Referenced by: '<Root>/PCI-6229 DA2'
   */
  { 4.0, 15.0 },

  /*  Computed Parameter: PCI6229DA2_P7_Size
   * Referenced by: '<Root>/PCI-6229 DA2'
   */
  { 1.0, 1.0 },
  29.0,                                /* Expression: boardType
                                        * Referenced by: '<Root>/PCI-6229 DA2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant6'
                                        */

  /*  Computed Parameter: PCI6229DO2_P1_Size
   * Referenced by: '<Root>/PCI-6229 DO2'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<Root>/PCI-6229 DO2'
                                        */

  /*  Computed Parameter: PCI6229DO2_P2_Size
   * Referenced by: '<Root>/PCI-6229 DO2'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: reset
                                        * Referenced by: '<Root>/PCI-6229 DO2'
                                        */

  /*  Computed Parameter: PCI6229DO2_P3_Size
   * Referenced by: '<Root>/PCI-6229 DO2'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initValue
                                        * Referenced by: '<Root>/PCI-6229 DO2'
                                        */

  /*  Computed Parameter: PCI6229DO2_P4_Size
   * Referenced by: '<Root>/PCI-6229 DO2'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampletime
                                        * Referenced by: '<Root>/PCI-6229 DO2'
                                        */

  /*  Computed Parameter: PCI6229DO2_P5_Size
   * Referenced by: '<Root>/PCI-6229 DO2'
   */
  { 1.0, 2.0 },

  /*  Expression: slot
   * Referenced by: '<Root>/PCI-6229 DO2'
   */
  { 4.0, 12.0 },

  /*  Computed Parameter: PCI6229DO2_P6_Size
   * Referenced by: '<Root>/PCI-6229 DO2'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: control
                                        * Referenced by: '<Root>/PCI-6229 DO2'
                                        */

  /*  Computed Parameter: PCI6229DO2_P7_Size
   * Referenced by: '<Root>/PCI-6229 DO2'
   */
  { 1.0, 1.0 },
  29.0,                                /* Expression: boardType
                                        * Referenced by: '<Root>/PCI-6229 DO2'
                                        */

  /*  Computed Parameter: PCI6229ENC4_P1_Size
   * Referenced by: '<Root>/PCI 6229 ENC 4'
   */
  { 1.0, 1.0 },
  29.0,                                /* Expression: device
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */

  /*  Computed Parameter: PCI6229ENC4_P2_Size
   * Referenced by: '<Root>/PCI 6229 ENC 4'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: channel
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */

  /*  Computed Parameter: PCI6229ENC4_P3_Size
   * Referenced by: '<Root>/PCI 6229 ENC 4'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: countMode
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */

  /*  Computed Parameter: PCI6229ENC4_P4_Size
   * Referenced by: '<Root>/PCI 6229 ENC 4'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initCount
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */

  /*  Computed Parameter: PCI6229ENC4_P5_Size
   * Referenced by: '<Root>/PCI 6229 ENC 4'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: reload
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */

  /*  Computed Parameter: PCI6229ENC4_P6_Size
   * Referenced by: '<Root>/PCI 6229 ENC 4'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: indexPhase
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */

  /*  Computed Parameter: PCI6229ENC4_P7_Size
   * Referenced by: '<Root>/PCI 6229 ENC 4'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: filter
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */

  /*  Computed Parameter: PCI6229ENC4_P8_Size
   * Referenced by: '<Root>/PCI 6229 ENC 4'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: outmask
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */

  /*  Computed Parameter: PCI6229ENC4_P9_Size
   * Referenced by: '<Root>/PCI 6229 ENC 4'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<Root>/PCI 6229 ENC 4'
                                        */

  /*  Computed Parameter: PCI6229ENC4_P10_Size
   * Referenced by: '<Root>/PCI 6229 ENC 4'
   */
  { 1.0, 2.0 },

  /*  Expression: slot
   * Referenced by: '<Root>/PCI 6229 ENC 4'
   */
  { 4.0, 12.0 },
  0.0015339807878856412,               /* Expression: 2*pi/(4096)
                                        * Referenced by: '<Root>/Gain10'
                                        */
  1000.0,                              /* Computed Parameter: TSamp_WtEt_j
                                        * Referenced by: '<S2>/TSamp'
                                        */

  /*  Computed Parameter: PCI6229ENC5_P1_Size
   * Referenced by: '<Root>/PCI 6229 ENC 5'
   */
  { 1.0, 1.0 },
  29.0,                                /* Expression: device
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */

  /*  Computed Parameter: PCI6229ENC5_P2_Size
   * Referenced by: '<Root>/PCI 6229 ENC 5'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */

  /*  Computed Parameter: PCI6229ENC5_P3_Size
   * Referenced by: '<Root>/PCI 6229 ENC 5'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: countMode
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */

  /*  Computed Parameter: PCI6229ENC5_P4_Size
   * Referenced by: '<Root>/PCI 6229 ENC 5'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initCount
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */

  /*  Computed Parameter: PCI6229ENC5_P5_Size
   * Referenced by: '<Root>/PCI 6229 ENC 5'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: reload
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */

  /*  Computed Parameter: PCI6229ENC5_P6_Size
   * Referenced by: '<Root>/PCI 6229 ENC 5'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: indexPhase
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */

  /*  Computed Parameter: PCI6229ENC5_P7_Size
   * Referenced by: '<Root>/PCI 6229 ENC 5'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: filter
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */

  /*  Computed Parameter: PCI6229ENC5_P8_Size
   * Referenced by: '<Root>/PCI 6229 ENC 5'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: outmask
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */

  /*  Computed Parameter: PCI6229ENC5_P9_Size
   * Referenced by: '<Root>/PCI 6229 ENC 5'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<Root>/PCI 6229 ENC 5'
                                        */

  /*  Computed Parameter: PCI6229ENC5_P10_Size
   * Referenced by: '<Root>/PCI 6229 ENC 5'
   */
  { 1.0, 2.0 },

  /*  Expression: slot
   * Referenced by: '<Root>/PCI 6229 ENC 5'
   */
  { 4.0, 12.0 },
  0.0015339807878856412,               /* Expression: 2*pi/(1024*4)
                                        * Referenced by: '<Root>/Gain12'
                                        */
  1000.0                               /* Computed Parameter: TSamp_WtEt_b
                                        * Referenced by: '<S4>/TSamp'
                                        */
};
