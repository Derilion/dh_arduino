/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Wheelspeed3_data.c
 *
 * Code generated for Simulink model 'Wheelspeed3'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 16 14:12:39 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Wheelspeed3.h"
#include "Wheelspeed3_private.h"

/* Block parameters (auto storage) */
P_Wheelspeed3_T Wheelspeed3_P = {
  7U,                                  /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S21>/Digital Output'
                                        */
  6U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S22>/PWM'
                                        */
  4U,                                  /* Mask Parameter: DigitalOutput_pinNumber_n
                                        * Referenced by: '<S25>/Digital Output'
                                        */
  5U,                                  /* Mask Parameter: PWM_pinNumber_g
                                        * Referenced by: '<S26>/PWM'
                                        */
  0,                                   /* Mask Parameter: DetectRisePositive_vinit
                                        * Referenced by: '<S1>/Delay Input1'
                                        */
  0,                                   /* Mask Parameter: DetectRisePositive1_vinit
                                        * Referenced by: '<S2>/Delay Input1'
                                        */
  0,                                   /* Mask Parameter: DetectRisePositive2_vinit
                                        * Referenced by: '<S3>/Delay Input1'
                                        */
  0,                                   /* Mask Parameter: DetectRisePositive3_vinit
                                        * Referenced by: '<S4>/Delay Input1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/Constant3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/Switch1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S18>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S18>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S18>/Constant3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S18>/Switch1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/enable'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/direction'
                                        */
  18U,                                 /* Computed Parameter: DigitalInput_p1
                                        * Referenced by: '<Root>/Digital Input'
                                        */
  19U,                                 /* Computed Parameter: DigitalInput1_p1
                                        * Referenced by: '<Root>/Digital Input1'
                                        */
  2U,                                  /* Computed Parameter: DigitalInput2_p1
                                        * Referenced by: '<Root>/Digital Input2'
                                        */
  3U,                                  /* Computed Parameter: DigitalInput3_p1
                                        * Referenced by: '<Root>/Digital Input3'
                                        */
  0,                                   /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S11>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S12>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S13>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S14>/Constant'
                                        */

  /* Start of '<Root>/Subsystem7' */
  {
    0.0,                               /* Computed Parameter: n_Y0
                                        * Referenced by: '<S10>/n'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S10>/Delay1'
                                        */
    0.1,                               /* Expression: 1/10
                                        * Referenced by: '<S10>/Constant'
                                        */
    1U                                 /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S10>/Delay1'
                                        */
  }
  /* End of '<Root>/Subsystem7' */
  ,

  /* Start of '<Root>/Subsystem3' */
  {
    0.0,                               /* Computed Parameter: n_Y0
                                        * Referenced by: '<S9>/n'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S9>/Delay1'
                                        */
    0.1,                               /* Expression: 1/10
                                        * Referenced by: '<S9>/Constant'
                                        */
    1U                                 /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S9>/Delay1'
                                        */
  }
  /* End of '<Root>/Subsystem3' */
  ,

  /* Start of '<Root>/Subsystem2' */
  {
    0.0,                               /* Computed Parameter: n_Y0
                                        * Referenced by: '<S8>/n'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S8>/Delay1'
                                        */
    0.1,                               /* Expression: 1/10
                                        * Referenced by: '<S8>/Constant'
                                        */
    1U                                 /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S8>/Delay1'
                                        */
  }
  /* End of '<Root>/Subsystem2' */
  ,

  /* Start of '<Root>/Subsystem1' */
  {
    0.0,                               /* Computed Parameter: n_Y0
                                        * Referenced by: '<S7>/n'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S7>/Delay1'
                                        */
    0.1,                               /* Expression: 1/10
                                        * Referenced by: '<S7>/Constant'
                                        */
    1U                                 /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S7>/Delay1'
                                        */
  }
  /* End of '<Root>/Subsystem1' */
  ,

  /* Start of '<S5>/vl' */
  {
    15U,                               /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S23>/Digital Output'
                                        */
    9U,                                /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S24>/PWM'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S17>/Constant2'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S17>/Switch'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S17>/Constant3'
                                        */
    0.0                                /* Expression: 0
                                        * Referenced by: '<S17>/Switch1'
                                        */
  }
  /* End of '<S5>/vl' */
  ,

  /* Start of '<S5>/hl' */
  {
    14U,                               /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S19>/Digital Output'
                                        */
    8U,                                /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S20>/PWM'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S15>/Constant2'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S15>/Switch'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S15>/Constant3'
                                        */
    0.0                                /* Expression: 0
                                        * Referenced by: '<S15>/Switch1'
                                        */
  }
  /* End of '<S5>/hl' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
