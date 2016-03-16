/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Geschwindigkeitsregler_data.c
 *
 * Code generated for Simulink model 'Geschwindigkeitsregler'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 16 16:21:22 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Geschwindigkeitsregler.h"
#include "Geschwindigkeitsregler_private.h"

/* Block parameters (auto storage) */
P_Geschwindigkeitsregler_T Geschwindigkeitsregler_P = {
  /*  Variable: AB1
   * Referenced by:
   *   '<S18>/r+1 Altwerte'
   *   '<S19>/r+1 Altwerte'
   *   '<S20>/r+1 Altwerte'
   *   '<S21>/r+1 Altwerte'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Variable: AB2
   * Referenced by:
   *   '<S18>/Zustandsvariablenfilter'
   *   '<S19>/Zustandsvariablenfilter'
   *   '<S20>/Zustandsvariablenfilter'
   *   '<S21>/Zustandsvariablenfilter'
   */
  { 0.0, 0.0, 0.0 },

  /*  Variable: AD
   * Referenced by:
   *   '<S18>/Zustandsvariablenfilter'
   *   '<S19>/Zustandsvariablenfilter'
   *   '<S20>/Zustandsvariablenfilter'
   *   '<S21>/Zustandsvariablenfilter'
   */
  { 0.99995994085004714, -0.011891104770813191, -2.3278861617252722,
    0.0099871479927783249, 0.99617488464384985, -0.75288028395840612,
    4.7938296870583056E-5, 0.0093847375876814042, 0.87824279399853855 },

  /*  Variable: BD
   * Referenced by:
   *   '<S18>/Zustandsvariablenfilter'
   *   '<S19>/Zustandsvariablenfilter'
   *   '<S20>/Zustandsvariablenfilter'
   *   '<S21>/Zustandsvariablenfilter'
   */
  { 5.7220157895133316E-6, 0.0025455605188296959, 0.89774541806609154,
    4.0034845763877217E-5, 0.011271133302365247, 1.8189071226792364,
    -7.0390630393700157E-6, -0.0023908236242906056, -0.48616769902488322,
    1.3413514390053949E-6, 0.00046523457390885395, 0.097401320004827568 },
  7U,                                  /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S11>/Digital Output'
                                        */
  6U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S12>/PWM'
                                        */
  4U,                                  /* Mask Parameter: DigitalOutput_pinNumber_n
                                        * Referenced by: '<S15>/Digital Output'
                                        */
  5U,                                  /* Mask Parameter: PWM_pinNumber_g
                                        * Referenced by: '<S16>/PWM'
                                        */
  0,                                   /* Mask Parameter: DetectRisePositive_vinit
                                        * Referenced by: '<S22>/Delay Input1'
                                        */
  0,                                   /* Mask Parameter: DetectRisePositive1_vinit
                                        * Referenced by: '<S23>/Delay Input1'
                                        */
  0,                                   /* Mask Parameter: DetectRisePositive2_vinit
                                        * Referenced by: '<S24>/Delay Input1'
                                        */
  0,                                   /* Mask Parameter: DetectRisePositive3_vinit
                                        * Referenced by: '<S25>/Delay Input1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Constant3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Switch1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Switch1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/powerMAX4'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<S4>/powerMAX3'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S4>/powerMAX2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/powerMAX1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/enable'
                                        */
  150.0,                               /* Expression: 150
                                        * Referenced by: '<Root>/direction1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/direction'
                                        */
  2.1,                                 /* Expression: 2.1
                                        * Referenced by: '<S4>/Constant1'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<S4>/Constant'
                                        */

  /*  Expression: eye(n)
   * Referenced by: '<S19>/Zustandsvariablenfilter'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /*  Expression: zeros(n,r+1)
   * Referenced by: '<S19>/Zustandsvariablenfilter'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  255.0,                               /* Expression: 255
                                        * Referenced by: '<S4>/powerMAX'
                                        */
  2.1,                                 /* Expression: 2.1
                                        * Referenced by: '<S4>/NMAX'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Switch'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S4>/Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Switch2'
                                        */
  -2.5555555E+7,                       /* Expression: -25555555
                                        * Referenced by: '<S4>/Switch1'
                                        */

  /*  Expression: eye(n)
   * Referenced by: '<S20>/Zustandsvariablenfilter'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /*  Expression: zeros(n,r+1)
   * Referenced by: '<S20>/Zustandsvariablenfilter'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: eye(n)
   * Referenced by: '<S21>/Zustandsvariablenfilter'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /*  Expression: zeros(n,r+1)
   * Referenced by: '<S21>/Zustandsvariablenfilter'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: eye(n)
   * Referenced by: '<S18>/Zustandsvariablenfilter'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /*  Expression: zeros(n,r+1)
   * Referenced by: '<S18>/Zustandsvariablenfilter'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/Constant'
                                        */

  /*  Computed Parameter: r1Altwerte_A
   * Referenced by: '<S18>/r+1 Altwerte'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: r1Altwerte_C
   * Referenced by: '<S18>/r+1 Altwerte'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0 },

  /*  Computed Parameter: r1Altwerte_A_i
   * Referenced by: '<S19>/r+1 Altwerte'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: r1Altwerte_C_b
   * Referenced by: '<S19>/r+1 Altwerte'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0 },

  /*  Computed Parameter: r1Altwerte_A_h
   * Referenced by: '<S20>/r+1 Altwerte'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: r1Altwerte_C_j
   * Referenced by: '<S20>/r+1 Altwerte'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0 },

  /*  Computed Parameter: r1Altwerte_A_ix
   * Referenced by: '<S21>/r+1 Altwerte'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: r1Altwerte_C_js
   * Referenced by: '<S21>/r+1 Altwerte'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0 },
  18U,                                 /* Computed Parameter: HL_p1
                                        * Referenced by: '<S17>/HL'
                                        */
  19U,                                 /* Computed Parameter: HR_p1
                                        * Referenced by: '<S17>/HR'
                                        */
  2U,                                  /* Computed Parameter: VR_p1
                                        * Referenced by: '<S17>/VR'
                                        */
  3U,                                  /* Computed Parameter: VL_p1
                                        * Referenced by: '<S17>/VL'
                                        */
  2U,                                  /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S4>/Delay'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S30>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S31>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S32>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_fp
                                        * Referenced by: '<S33>/Constant'
                                        */

  /* Start of '<S17>/Subsystem3' */
  {
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S29>/Constant1'
                                        */
    0.0,                               /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S29>/Out1'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S29>/Delay'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S29>/Switch'
                                        */
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S29>/Constant'
                                        */
    1U                                 /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S29>/Delay'
                                        */
  }
  /* End of '<S17>/Subsystem3' */
  ,

  /* Start of '<S17>/Subsystem2' */
  {
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S28>/Constant1'
                                        */
    0.0,                               /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S28>/Out1'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S28>/Delay'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S28>/Switch'
                                        */
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S28>/Constant'
                                        */
    1U                                 /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S28>/Delay'
                                        */
  }
  /* End of '<S17>/Subsystem2' */
  ,

  /* Start of '<S17>/Subsystem1' */
  {
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S27>/Constant1'
                                        */
    0.0,                               /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S27>/Out1'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S27>/Delay'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S27>/Switch'
                                        */
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S27>/Constant'
                                        */
    1U                                 /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S27>/Delay'
                                        */
  }
  /* End of '<S17>/Subsystem1' */
  ,

  /* Start of '<S17>/Subsystem' */
  {
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S26>/Constant1'
                                        */
    0.0,                               /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S26>/Out1'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S26>/Delay'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S26>/Switch'
                                        */
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S26>/Constant'
                                        */
    1U                                 /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S26>/Delay'
                                        */
  }
  /* End of '<S17>/Subsystem' */
  ,

  /* Start of '<S1>/vl' */
  {
    15U,                               /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S13>/Digital Output'
                                        */
    9U,                                /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S14>/PWM'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S7>/Constant3'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S7>/Constant2'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S7>/Switch'
                                        */
    0.0                                /* Expression: 0
                                        * Referenced by: '<S7>/Switch1'
                                        */
  }
  /* End of '<S1>/vl' */
  ,

  /* Start of '<S1>/hl' */
  {
    14U,                               /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S9>/Digital Output'
                                        */
    8U,                                /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S10>/PWM'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S5>/Constant3'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S5>/Constant2'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S5>/Switch'
                                        */
    0.0                                /* Expression: 0
                                        * Referenced by: '<S5>/Switch1'
                                        */
  }
  /* End of '<S1>/hl' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
