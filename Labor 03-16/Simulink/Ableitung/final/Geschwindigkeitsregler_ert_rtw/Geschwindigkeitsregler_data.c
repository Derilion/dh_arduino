/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Geschwindigkeitsregler_data.c
 *
 * Code generated for Simulink model 'Geschwindigkeitsregler'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 23 16:01:11 2016
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
   *   '<S24>/r+1 Altwerte'
   *   '<S25>/r+1 Altwerte'
   *   '<S26>/r+1 Altwerte'
   *   '<S27>/r+1 Altwerte'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Variable: AB2
   * Referenced by:
   *   '<S24>/Zustandsvariablenfilter'
   *   '<S25>/Zustandsvariablenfilter'
   *   '<S26>/Zustandsvariablenfilter'
   *   '<S27>/Zustandsvariablenfilter'
   */
  { 0.0, 0.0, 0.0 },

  /*  Variable: AD
   * Referenced by:
   *   '<S24>/Zustandsvariablenfilter'
   *   '<S25>/Zustandsvariablenfilter'
   *   '<S26>/Zustandsvariablenfilter'
   *   '<S27>/Zustandsvariablenfilter'
   */
  { 0.99995994085004714, -0.011891104770813191, -2.3278861617252722,
    0.0099871479927783249, 0.99617488464384985, -0.75288028395840612,
    4.7938296870583056E-5, 0.0093847375876814042, 0.87824279399853855 },

  /*  Variable: BD
   * Referenced by:
   *   '<S24>/Zustandsvariablenfilter'
   *   '<S25>/Zustandsvariablenfilter'
   *   '<S26>/Zustandsvariablenfilter'
   *   '<S27>/Zustandsvariablenfilter'
   */
  { 5.7220157895133316E-6, 0.0025455605188296959, 0.89774541806609154,
    4.0034845763877217E-5, 0.011271133302365247, 1.8189071226792364,
    -7.0390630393700157E-6, -0.0023908236242906056, -0.48616769902488322,
    1.3413514390053949E-6, 0.00046523457390885395, 0.097401320004827568 },
  0.0,                                 /* Mask Parameter: DiscretePIDController_LowerSatu
                                        * Referenced by: '<S52>/Saturate'
                                        */
  0.0,                                 /* Mask Parameter: DiscretePIDController_LowerSa_p
                                        * Referenced by: '<S53>/Saturate'
                                        */
  0.0,                                 /* Mask Parameter: DiscretePIDController_LowerS_pn
                                        * Referenced by: '<S54>/Saturate'
                                        */
  0.0,                                 /* Mask Parameter: DiscretePIDController_LowerSa_e
                                        * Referenced by: '<S55>/Saturate'
                                        */
  255.0,                               /* Mask Parameter: DiscretePIDController_UpperSatu
                                        * Referenced by: '<S52>/Saturate'
                                        */
  255.0,                               /* Mask Parameter: DiscretePIDController_UpperSa_b
                                        * Referenced by: '<S53>/Saturate'
                                        */
  255.0,                               /* Mask Parameter: DiscretePIDController_UpperSa_o
                                        * Referenced by: '<S54>/Saturate'
                                        */
  255.0,                               /* Mask Parameter: DiscretePIDController_UpperSa_l
                                        * Referenced by: '<S55>/Saturate'
                                        */
  7U,                                  /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S17>/Digital Output'
                                        */
  6U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S18>/PWM'
                                        */
  4U,                                  /* Mask Parameter: DigitalOutput_pinNumber_n
                                        * Referenced by: '<S21>/Digital Output'
                                        */
  5U,                                  /* Mask Parameter: PWM_pinNumber_g
                                        * Referenced by: '<S22>/PWM'
                                        */
  0,                                   /* Mask Parameter: DetectRisePositive_vinit
                                        * Referenced by: '<S28>/Delay Input1'
                                        */
  0,                                   /* Mask Parameter: DetectRisePositive1_vinit
                                        * Referenced by: '<S29>/Delay Input1'
                                        */
  0,                                   /* Mask Parameter: DetectRisePositive2_vinit
                                        * Referenced by: '<S30>/Delay Input1'
                                        */
  0,                                   /* Mask Parameter: DetectRisePositive3_vinit
                                        * Referenced by: '<S31>/Delay Input1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Constant3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Switch1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Constant3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Switch1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/enable'
                                        */
  25.0,                                /* Expression: 25
                                        * Referenced by: '<S7>/Constant1'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S7>/Constant'
                                        */

  /*  Expression: eye(n)
   * Referenced by: '<S24>/Zustandsvariablenfilter'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /*  Expression: zeros(n,r+1)
   * Referenced by: '<S24>/Zustandsvariablenfilter'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<S7>/Constant2'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S7>/Constant3'
                                        */
  0.01,                                /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S52>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S52>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/direction'
                                        */
  25.0,                                /* Expression: 25
                                        * Referenced by: '<S8>/maxClicksproSec'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S8>/prozent'
                                        */

  /*  Expression: eye(n)
   * Referenced by: '<S25>/Zustandsvariablenfilter'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /*  Expression: zeros(n,r+1)
   * Referenced by: '<S25>/Zustandsvariablenfilter'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<S8>/p'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S8>/i'
                                        */
  0.01,                                /* Computed Parameter: Integrator_gainval_o
                                        * Referenced by: '<S53>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S53>/Integrator'
                                        */
  25.0,                                /* Expression: 25
                                        * Referenced by: '<S9>/Constant1'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S9>/Constant'
                                        */

  /*  Expression: eye(n)
   * Referenced by: '<S26>/Zustandsvariablenfilter'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /*  Expression: zeros(n,r+1)
   * Referenced by: '<S26>/Zustandsvariablenfilter'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<S9>/Constant2'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S9>/Constant3'
                                        */
  0.01,                                /* Computed Parameter: Integrator_gainval_k
                                        * Referenced by: '<S54>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S54>/Integrator'
                                        */
  25.0,                                /* Expression: 25
                                        * Referenced by: '<S10>/Constant1'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S10>/Constant'
                                        */

  /*  Expression: eye(n)
   * Referenced by: '<S27>/Zustandsvariablenfilter'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /*  Expression: zeros(n,r+1)
   * Referenced by: '<S27>/Zustandsvariablenfilter'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<S10>/Constant2'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S10>/Constant3'
                                        */
  0.01,                                /* Computed Parameter: Integrator_gainval_n
                                        * Referenced by: '<S55>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S55>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S23>/Constant'
                                        */

  /*  Computed Parameter: r1Altwerte_A
   * Referenced by: '<S24>/r+1 Altwerte'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: r1Altwerte_C
   * Referenced by: '<S24>/r+1 Altwerte'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0 },

  /*  Computed Parameter: r1Altwerte_A_i
   * Referenced by: '<S25>/r+1 Altwerte'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: r1Altwerte_C_b
   * Referenced by: '<S25>/r+1 Altwerte'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0 },

  /*  Computed Parameter: r1Altwerte_A_h
   * Referenced by: '<S26>/r+1 Altwerte'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: r1Altwerte_C_j
   * Referenced by: '<S26>/r+1 Altwerte'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0 },

  /*  Computed Parameter: r1Altwerte_A_ix
   * Referenced by: '<S27>/r+1 Altwerte'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Computed Parameter: r1Altwerte_C_js
   * Referenced by: '<S27>/r+1 Altwerte'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0 },
  18U,                                 /* Computed Parameter: HL_p1
                                        * Referenced by: '<S23>/HL'
                                        */
  19U,                                 /* Computed Parameter: HR_p1
                                        * Referenced by: '<S23>/HR'
                                        */
  2U,                                  /* Computed Parameter: VR_p1
                                        * Referenced by: '<S23>/VR'
                                        */
  3U,                                  /* Computed Parameter: VL_p1
                                        * Referenced by: '<S23>/VL'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S36>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_fr
                                        * Referenced by: '<S37>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_od
                                        * Referenced by: '<S38>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_fp
                                        * Referenced by: '<S39>/Constant'
                                        */

  /* Start of '<S23>/Subsystem3' */
  {
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S35>/Constant1'
                                        */
    0.0,                               /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S35>/Out1'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S35>/Delay'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S35>/Switch'
                                        */
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S35>/Constant'
                                        */
    1U                                 /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S35>/Delay'
                                        */
  }
  /* End of '<S23>/Subsystem3' */
  ,

  /* Start of '<S23>/Subsystem2' */
  {
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S34>/Constant1'
                                        */
    0.0,                               /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S34>/Out1'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S34>/Delay'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S34>/Switch'
                                        */
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S34>/Constant'
                                        */
    1U                                 /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S34>/Delay'
                                        */
  }
  /* End of '<S23>/Subsystem2' */
  ,

  /* Start of '<S23>/Subsystem1' */
  {
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S33>/Constant1'
                                        */
    0.0,                               /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S33>/Out1'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S33>/Delay'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S33>/Switch'
                                        */
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S33>/Constant'
                                        */
    1U                                 /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S33>/Delay'
                                        */
  }
  /* End of '<S23>/Subsystem1' */
  ,

  /* Start of '<S23>/Subsystem' */
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
  /* End of '<S23>/Subsystem' */
  ,

  /* Start of '<S1>/vl' */
  {
    15U,                               /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S19>/Digital Output'
                                        */
    9U,                                /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S20>/PWM'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S13>/Constant2'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S13>/Switch'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S13>/Constant3'
                                        */
    0.0                                /* Expression: 0
                                        * Referenced by: '<S13>/Switch1'
                                        */
  }
  /* End of '<S1>/vl' */
  ,

  /* Start of '<S1>/hl' */
  {
    14U,                               /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S15>/Digital Output'
                                        */
    8U,                                /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S16>/PWM'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S11>/Constant2'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S11>/Switch'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S11>/Constant3'
                                        */
    0.0                                /* Expression: 0
                                        * Referenced by: '<S11>/Switch1'
                                        */
  }
  /* End of '<S1>/hl' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
