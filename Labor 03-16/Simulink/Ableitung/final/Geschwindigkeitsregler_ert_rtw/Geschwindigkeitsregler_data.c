/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Geschwindigkeitsregler_data.c
 *
 * Code generated for Simulink model 'Geschwindigkeitsregler'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 16 17:58:00 2016
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
   *   '<S21>/r+1 Altwerte'
   *   '<S22>/r+1 Altwerte'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Variable: AB2
   * Referenced by:
   *   '<S21>/Zustandsvariablenfilter'
   *   '<S22>/Zustandsvariablenfilter'
   */
  { 0.0, 0.0, 0.0 },

  /*  Variable: AD
   * Referenced by:
   *   '<S21>/Zustandsvariablenfilter'
   *   '<S22>/Zustandsvariablenfilter'
   */
  { 0.99995994085004714, -0.011891104770813191, -2.3278861617252722,
    0.0099871479927783249, 0.99617488464384985, -0.75288028395840612,
    4.7938296870583056E-5, 0.0093847375876814042, 0.87824279399853855 },

  /*  Variable: BD
   * Referenced by:
   *   '<S21>/Zustandsvariablenfilter'
   *   '<S22>/Zustandsvariablenfilter'
   */
  { 5.7220157895133316E-6, 0.0025455605188296959, 0.89774541806609154,
    4.0034845763877217E-5, 0.011271133302365247, 1.8189071226792364,
    -7.0390630393700157E-6, -0.0023908236242906056, -0.48616769902488322,
    1.3413514390053949E-6, 0.00046523457390885395, 0.097401320004827568 },
  7U,                                  /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S14>/Digital Output'
                                        */
  6U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S15>/PWM'
                                        */
  4U,                                  /* Mask Parameter: DigitalOutput_pinNumber_n
                                        * Referenced by: '<S18>/Digital Output'
                                        */
  5U,                                  /* Mask Parameter: PWM_pinNumber_g
                                        * Referenced by: '<S19>/PWM'
                                        */
  0,                                   /* Mask Parameter: DetectRisePositive_vinit
                                        * Referenced by: '<S25>/Delay Input1'
                                        */
  0,                                   /* Mask Parameter: DetectRisePositive1_vinit
                                        * Referenced by: '<S26>/Delay Input1'
                                        */
  0,                                   /* Mask Parameter: DetectRisePositive2_vinit
                                        * Referenced by: '<S27>/Delay Input1'
                                        */
  0,                                   /* Mask Parameter: DetectRisePositive3_vinit
                                        * Referenced by: '<S28>/Delay Input1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Constant3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Switch1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Constant3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/Switch1'
                                        */
  0.0,                                 /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S30>/Out1'
                                        */
  0.0,                                 /* Computed Parameter: Out1_Y0_a
                                        * Referenced by: '<S31>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/powerMAX4'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<S6>/powerMAX3'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S6>/powerMAX2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S6>/powerMAX1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/enable'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/direction'
                                        */
  21.0,                                /* Expression: 21
                                        * Referenced by: '<S7>/Constant1'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<S7>/Constant'
                                        */
  0.9,                                 /* Expression: 0.9
                                        * Referenced by: '<S7>/Gain2'
                                        */

  /*  Expression: eye(n)
   * Referenced by: '<S22>/Zustandsvariablenfilter'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /*  Expression: zeros(n,r+1)
   * Referenced by: '<S22>/Zustandsvariablenfilter'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  0.4,                                 /* Expression: 0.4
                                        * Referenced by: '<S7>/Gain1'
                                        */
  12.142857142857142,                  /* Expression: 255/21
                                        * Referenced by: '<S7>/Gain'
                                        */

  /*  Expression: eye(n)
   * Referenced by: '<S21>/Zustandsvariablenfilter'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /*  Expression: zeros(n,r+1)
   * Referenced by: '<S21>/Zustandsvariablenfilter'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S20>/Constant'
                                        */

  /*  Computed Parameter: r1Altwerte_A
   * Referenced by: '<S21>/r+1 Altwerte'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: r1Altwerte_C
   * Referenced by: '<S21>/r+1 Altwerte'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0 },

  /*  Computed Parameter: r1Altwerte_A_i
   * Referenced by: '<S22>/r+1 Altwerte'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: r1Altwerte_C_b
   * Referenced by: '<S22>/r+1 Altwerte'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0 },
  21.0,                                /* Expression: 21
                                        * Referenced by: '<S6>/Constant1'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<S6>/Constant'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<S6>/powerMAX'
                                        */
  21.0,                                /* Expression: 21
                                        * Referenced by: '<S6>/NMAX'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Switch'
                                        */
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S6>/Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Switch2'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<S6>/Switch1'
                                        */
  18U,                                 /* Computed Parameter: HL_p1
                                        * Referenced by: '<S20>/HL'
                                        */
  19U,                                 /* Computed Parameter: HR_p1
                                        * Referenced by: '<S20>/HR'
                                        */
  2U,                                  /* Computed Parameter: VR_p1
                                        * Referenced by: '<S20>/VR'
                                        */
  3U,                                  /* Computed Parameter: VL_p1
                                        * Referenced by: '<S20>/VL'
                                        */
  2U,                                  /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S6>/Delay'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S33>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_fr
                                        * Referenced by: '<S34>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S35>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_fp
                                        * Referenced by: '<S36>/Constant'
                                        */

  /* Start of '<S20>/Subsystem3' */
  {
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S32>/Constant1'
                                        */
    0.0,                               /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S32>/Out1'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S32>/Delay'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S32>/Switch'
                                        */
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S32>/Constant'
                                        */
    1U                                 /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S32>/Delay'
                                        */
  }
  /* End of '<S20>/Subsystem3' */
  ,

  /* Start of '<S20>/Subsystem' */
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
  /* End of '<S20>/Subsystem' */
  ,

  /* Start of '<S1>/vl' */
  {
    15U,                               /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S16>/Digital Output'
                                        */
    9U,                                /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S17>/PWM'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S10>/Constant2'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S10>/Switch'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S10>/Constant3'
                                        */
    0.0                                /* Expression: 0
                                        * Referenced by: '<S10>/Switch1'
                                        */
  }
  /* End of '<S1>/vl' */
  ,

  /* Start of '<S1>/hl' */
  {
    14U,                               /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S12>/Digital Output'
                                        */
    8U,                                /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S13>/PWM'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S8>/Constant2'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S8>/Switch'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S8>/Constant3'
                                        */
    0.0                                /* Expression: 0
                                        * Referenced by: '<S8>/Switch1'
                                        */
  }
  /* End of '<S1>/hl' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
