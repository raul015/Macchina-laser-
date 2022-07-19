/*
 * lettura_finecorsa_data.c
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

#include "lettura_finecorsa.h"
#include "lettura_finecorsa_private.h"

/* Block parameters (auto storage) */
P_lettura_finecorsa_T lettura_finecorsa_P = {
  0.0,                                 /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                        * Referenced by: '<S2>/UD'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative1_ICPrevScale
                                        * Referenced by: '<S3>/UD'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative2_ICPrevScale
                                        * Referenced by: '<S4>/UD'
                                        */
  0.0,                                 /* Mask Parameter: DiscreteDerivative3_ICPrevScale
                                        * Referenced by: '<S5>/UD'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */

  /*  Computed Parameter: PCI6229DO1_P1_Size
   * Referenced by: '<Root>/PCI-6229 DO1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<Root>/PCI-6229 DO1'
                                        */

  /*  Computed Parameter: PCI6229DO1_P2_Size
   * Referenced by: '<Root>/PCI-6229 DO1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: reset
                                        * Referenced by: '<Root>/PCI-6229 DO1'
                                        */

  /*  Computed Parameter: PCI6229DO1_P3_Size
   * Referenced by: '<Root>/PCI-6229 DO1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initValue
                                        * Referenced by: '<Root>/PCI-6229 DO1'
                                        */

  /*  Computed Parameter: PCI6229DO1_P4_Size
   * Referenced by: '<Root>/PCI-6229 DO1'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampletime
                                        * Referenced by: '<Root>/PCI-6229 DO1'
                                        */

  /*  Computed Parameter: PCI6229DO1_P5_Size
   * Referenced by: '<Root>/PCI-6229 DO1'
   */
  { 1.0, 2.0 },

  /*  Expression: slot
   * Referenced by: '<Root>/PCI-6229 DO1'
   */
  { 4.0, 12.0 },

  /*  Computed Parameter: PCI6229DO1_P6_Size
   * Referenced by: '<Root>/PCI-6229 DO1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: control
                                        * Referenced by: '<Root>/PCI-6229 DO1'
                                        */

  /*  Computed Parameter: PCI6229DO1_P7_Size
   * Referenced by: '<Root>/PCI-6229 DO1'
   */
  { 1.0, 1.0 },
  29.0,                                /* Expression: boardType
                                        * Referenced by: '<Root>/PCI-6229 DO1'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Constant2'
                                        */

  /*  Computed Parameter: PCI6229DA_P1_Size
   * Referenced by: '<Root>/PCI-6229 DA'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<Root>/PCI-6229 DA'
                                        */

  /*  Computed Parameter: PCI6229DA_P2_Size
   * Referenced by: '<Root>/PCI-6229 DA'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: range
                                        * Referenced by: '<Root>/PCI-6229 DA'
                                        */

  /*  Computed Parameter: PCI6229DA_P3_Size
   * Referenced by: '<Root>/PCI-6229 DA'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: reset
                                        * Referenced by: '<Root>/PCI-6229 DA'
                                        */

  /*  Computed Parameter: PCI6229DA_P4_Size
   * Referenced by: '<Root>/PCI-6229 DA'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initValue
                                        * Referenced by: '<Root>/PCI-6229 DA'
                                        */

  /*  Computed Parameter: PCI6229DA_P5_Size
   * Referenced by: '<Root>/PCI-6229 DA'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampletime
                                        * Referenced by: '<Root>/PCI-6229 DA'
                                        */

  /*  Computed Parameter: PCI6229DA_P6_Size
   * Referenced by: '<Root>/PCI-6229 DA'
   */
  { 1.0, 2.0 },

  /*  Expression: slot
   * Referenced by: '<Root>/PCI-6229 DA'
   */
  { 4.0, 12.0 },

  /*  Computed Parameter: PCI6229DA_P7_Size
   * Referenced by: '<Root>/PCI-6229 DA'
   */
  { 1.0, 1.0 },
  29.0,                                /* Expression: boardType
                                        * Referenced by: '<Root>/PCI-6229 DA'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Constant3'
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
  { 4.0, 15.0 },

  /*  Computed Parameter: PCI6229DA1_P7_Size
   * Referenced by: '<Root>/PCI-6229 DA1'
   */
  { 1.0, 1.0 },
  29.0,                                /* Expression: boardType
                                        * Referenced by: '<Root>/PCI-6229 DA1'
                                        */

  /*  Computed Parameter: PCI6229ENC_P1_Size
   * Referenced by: '<Root>/PCI 6229 ENC '
   */
  { 1.0, 1.0 },
  29.0,                                /* Expression: device
                                        * Referenced by: '<Root>/PCI 6229 ENC '
                                        */

  /*  Computed Parameter: PCI6229ENC_P2_Size
   * Referenced by: '<Root>/PCI 6229 ENC '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: channel
                                        * Referenced by: '<Root>/PCI 6229 ENC '
                                        */

  /*  Computed Parameter: PCI6229ENC_P3_Size
   * Referenced by: '<Root>/PCI 6229 ENC '
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: countMode
                                        * Referenced by: '<Root>/PCI 6229 ENC '
                                        */

  /*  Computed Parameter: PCI6229ENC_P4_Size
   * Referenced by: '<Root>/PCI 6229 ENC '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initCount
                                        * Referenced by: '<Root>/PCI 6229 ENC '
                                        */

  /*  Computed Parameter: PCI6229ENC_P5_Size
   * Referenced by: '<Root>/PCI 6229 ENC '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: reload
                                        * Referenced by: '<Root>/PCI 6229 ENC '
                                        */

  /*  Computed Parameter: PCI6229ENC_P6_Size
   * Referenced by: '<Root>/PCI 6229 ENC '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: indexPhase
                                        * Referenced by: '<Root>/PCI 6229 ENC '
                                        */

  /*  Computed Parameter: PCI6229ENC_P7_Size
   * Referenced by: '<Root>/PCI 6229 ENC '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: filter
                                        * Referenced by: '<Root>/PCI 6229 ENC '
                                        */

  /*  Computed Parameter: PCI6229ENC_P8_Size
   * Referenced by: '<Root>/PCI 6229 ENC '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: outmask
                                        * Referenced by: '<Root>/PCI 6229 ENC '
                                        */

  /*  Computed Parameter: PCI6229ENC_P9_Size
   * Referenced by: '<Root>/PCI 6229 ENC '
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<Root>/PCI 6229 ENC '
                                        */

  /*  Computed Parameter: PCI6229ENC_P10_Size
   * Referenced by: '<Root>/PCI 6229 ENC '
   */
  { 1.0, 2.0 },

  /*  Expression: slot
   * Referenced by: '<Root>/PCI 6229 ENC '
   */
  { 4.0, 12.0 },
  0.0015339807878856412,               /* Expression: 2*pi/(4096)
                                        * Referenced by: '<Root>/Gain'
                                        */
  1000.0,                              /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S2>/TSamp'
                                        */

  /*  Computed Parameter: PCI6229ENC2_P1_Size
   * Referenced by: '<Root>/PCI 6229 ENC 2'
   */
  { 1.0, 1.0 },
  29.0,                                /* Expression: device
                                        * Referenced by: '<Root>/PCI 6229 ENC 2'
                                        */

  /*  Computed Parameter: PCI6229ENC2_P2_Size
   * Referenced by: '<Root>/PCI 6229 ENC 2'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: channel
                                        * Referenced by: '<Root>/PCI 6229 ENC 2'
                                        */

  /*  Computed Parameter: PCI6229ENC2_P3_Size
   * Referenced by: '<Root>/PCI 6229 ENC 2'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: countMode
                                        * Referenced by: '<Root>/PCI 6229 ENC 2'
                                        */

  /*  Computed Parameter: PCI6229ENC2_P4_Size
   * Referenced by: '<Root>/PCI 6229 ENC 2'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initCount
                                        * Referenced by: '<Root>/PCI 6229 ENC 2'
                                        */

  /*  Computed Parameter: PCI6229ENC2_P5_Size
   * Referenced by: '<Root>/PCI 6229 ENC 2'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: reload
                                        * Referenced by: '<Root>/PCI 6229 ENC 2'
                                        */

  /*  Computed Parameter: PCI6229ENC2_P6_Size
   * Referenced by: '<Root>/PCI 6229 ENC 2'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: indexPhase
                                        * Referenced by: '<Root>/PCI 6229 ENC 2'
                                        */

  /*  Computed Parameter: PCI6229ENC2_P7_Size
   * Referenced by: '<Root>/PCI 6229 ENC 2'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: filter
                                        * Referenced by: '<Root>/PCI 6229 ENC 2'
                                        */

  /*  Computed Parameter: PCI6229ENC2_P8_Size
   * Referenced by: '<Root>/PCI 6229 ENC 2'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: outmask
                                        * Referenced by: '<Root>/PCI 6229 ENC 2'
                                        */

  /*  Computed Parameter: PCI6229ENC2_P9_Size
   * Referenced by: '<Root>/PCI 6229 ENC 2'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<Root>/PCI 6229 ENC 2'
                                        */

  /*  Computed Parameter: PCI6229ENC2_P10_Size
   * Referenced by: '<Root>/PCI 6229 ENC 2'
   */
  { 1.0, 2.0 },

  /*  Expression: slot
   * Referenced by: '<Root>/PCI 6229 ENC 2'
   */
  { 4.0, 15.0 },
  -5.0E-6,                             /* Expression: -5e-6
                                        * Referenced by: '<Root>/Gain1'
                                        */
  1000.0,                              /* Computed Parameter: TSamp_WtEt_j
                                        * Referenced by: '<S3>/TSamp'
                                        */

  /*  Computed Parameter: PCI6229ENC1_P1_Size
   * Referenced by: '<Root>/PCI 6229 ENC 1'
   */
  { 1.0, 1.0 },
  29.0,                                /* Expression: device
                                        * Referenced by: '<Root>/PCI 6229 ENC 1'
                                        */

  /*  Computed Parameter: PCI6229ENC1_P2_Size
   * Referenced by: '<Root>/PCI 6229 ENC 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<Root>/PCI 6229 ENC 1'
                                        */

  /*  Computed Parameter: PCI6229ENC1_P3_Size
   * Referenced by: '<Root>/PCI 6229 ENC 1'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: countMode
                                        * Referenced by: '<Root>/PCI 6229 ENC 1'
                                        */

  /*  Computed Parameter: PCI6229ENC1_P4_Size
   * Referenced by: '<Root>/PCI 6229 ENC 1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initCount
                                        * Referenced by: '<Root>/PCI 6229 ENC 1'
                                        */

  /*  Computed Parameter: PCI6229ENC1_P5_Size
   * Referenced by: '<Root>/PCI 6229 ENC 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: reload
                                        * Referenced by: '<Root>/PCI 6229 ENC 1'
                                        */

  /*  Computed Parameter: PCI6229ENC1_P6_Size
   * Referenced by: '<Root>/PCI 6229 ENC 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: indexPhase
                                        * Referenced by: '<Root>/PCI 6229 ENC 1'
                                        */

  /*  Computed Parameter: PCI6229ENC1_P7_Size
   * Referenced by: '<Root>/PCI 6229 ENC 1'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: filter
                                        * Referenced by: '<Root>/PCI 6229 ENC 1'
                                        */

  /*  Computed Parameter: PCI6229ENC1_P8_Size
   * Referenced by: '<Root>/PCI 6229 ENC 1'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: outmask
                                        * Referenced by: '<Root>/PCI 6229 ENC 1'
                                        */

  /*  Computed Parameter: PCI6229ENC1_P9_Size
   * Referenced by: '<Root>/PCI 6229 ENC 1'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<Root>/PCI 6229 ENC 1'
                                        */

  /*  Computed Parameter: PCI6229ENC1_P10_Size
   * Referenced by: '<Root>/PCI 6229 ENC 1'
   */
  { 1.0, 2.0 },

  /*  Expression: slot
   * Referenced by: '<Root>/PCI 6229 ENC 1'
   */
  { 4.0, 12.0 },
  0.0015339807878856412,               /* Expression: 2*pi/(1024*4)
                                        * Referenced by: '<Root>/Gain2'
                                        */
  1000.0,                              /* Computed Parameter: TSamp_WtEt_f
                                        * Referenced by: '<S4>/TSamp'
                                        */

  /*  Computed Parameter: PCI6229ENC3_P1_Size
   * Referenced by: '<Root>/PCI 6229 ENC 3'
   */
  { 1.0, 1.0 },
  29.0,                                /* Expression: device
                                        * Referenced by: '<Root>/PCI 6229 ENC 3'
                                        */

  /*  Computed Parameter: PCI6229ENC3_P2_Size
   * Referenced by: '<Root>/PCI 6229 ENC 3'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<Root>/PCI 6229 ENC 3'
                                        */

  /*  Computed Parameter: PCI6229ENC3_P3_Size
   * Referenced by: '<Root>/PCI 6229 ENC 3'
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: countMode
                                        * Referenced by: '<Root>/PCI 6229 ENC 3'
                                        */

  /*  Computed Parameter: PCI6229ENC3_P4_Size
   * Referenced by: '<Root>/PCI 6229 ENC 3'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initCount
                                        * Referenced by: '<Root>/PCI 6229 ENC 3'
                                        */

  /*  Computed Parameter: PCI6229ENC3_P5_Size
   * Referenced by: '<Root>/PCI 6229 ENC 3'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: reload
                                        * Referenced by: '<Root>/PCI 6229 ENC 3'
                                        */

  /*  Computed Parameter: PCI6229ENC3_P6_Size
   * Referenced by: '<Root>/PCI 6229 ENC 3'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: indexPhase
                                        * Referenced by: '<Root>/PCI 6229 ENC 3'
                                        */

  /*  Computed Parameter: PCI6229ENC3_P7_Size
   * Referenced by: '<Root>/PCI 6229 ENC 3'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: filter
                                        * Referenced by: '<Root>/PCI 6229 ENC 3'
                                        */

  /*  Computed Parameter: PCI6229ENC3_P8_Size
   * Referenced by: '<Root>/PCI 6229 ENC 3'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: outmask
                                        * Referenced by: '<Root>/PCI 6229 ENC 3'
                                        */

  /*  Computed Parameter: PCI6229ENC3_P9_Size
   * Referenced by: '<Root>/PCI 6229 ENC 3'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<Root>/PCI 6229 ENC 3'
                                        */

  /*  Computed Parameter: PCI6229ENC3_P10_Size
   * Referenced by: '<Root>/PCI 6229 ENC 3'
   */
  { 1.0, 2.0 },

  /*  Expression: slot
   * Referenced by: '<Root>/PCI 6229 ENC 3'
   */
  { 4.0, 15.0 },
  -5.0E-6,                             /* Expression: -5e-6
                                        * Referenced by: '<Root>/Gain3'
                                        */
  1000.0,                              /* Computed Parameter: TSamp_WtEt_b
                                        * Referenced by: '<S5>/TSamp'
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
  29.0                                 /* Expression: boardType
                                        * Referenced by: '<Root>/PCI-6229 DI'
                                        */
};
