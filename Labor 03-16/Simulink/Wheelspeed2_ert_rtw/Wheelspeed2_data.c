/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Wheelspeed2_data.c
 *
 * Code generated for Simulink model 'Wheelspeed2'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 16 13:52:08 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Wheelspeed2.h"
#include "Wheelspeed2_private.h"

/* Block parameters (auto storage) */
P_Wheelspeed2_T Wheelspeed2_P = {
  7U,                                  /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S22>/Digital Output'
                                        */
  6U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S23>/PWM'
                                        */
  4U,                                  /* Mask Parameter: DigitalOutput_pinNumber_n
                                        * Referenced by: '<S26>/Digital Output'
                                        */
  5U,                                  /* Mask Parameter: PWM_pinNumber_g
                                        * Referenced by: '<S27>/PWM'
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
                                        * Referenced by: '<S17>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/Constant3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/Switch1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S19>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S19>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S19>/Constant3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S19>/Switch1'
                                        */
  0.0,                                 /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S11>/Out1'
                                        */
  0.0,                                 /* Computed Parameter: Out2_Y0
                                        * Referenced by: '<S11>/Out2'
                                        */
  0.0,                                 /* Computed Parameter: Out3_Y0
                                        * Referenced by: '<S11>/Out3'
                                        */
  0.0,                                 /* Computed Parameter: Out4_Y0
                                        * Referenced by: '<S11>/Out4'
                                        */
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<S11>/Gain'
                                        */
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<S11>/Gain1'
                                        */
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<S11>/Gain2'
                                        */
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<S11>/Gain3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Rate Transition'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  2.0,                                 /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  1.0,                                 /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
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
                                        * Referenced by: '<S12>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S13>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S14>/Constant'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S15>/Constant'
                                        */

  /* Start of '<Root>/Subsystem3' */
  {
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S10>/Constant1'
                                        */
    0.0,                               /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S10>/Out1'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S10>/Delay'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S10>/Switch'
                                        */
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S10>/Constant'
                                        */
    1U                                 /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S10>/Delay'
                                        */
  }
  /* End of '<Root>/Subsystem3' */
  ,

  /* Start of '<Root>/Subsystem2' */
  {
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S9>/Constant1'
                                        */
    0.0,                               /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S9>/Out1'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S9>/Delay'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S9>/Switch'
                                        */
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S9>/Constant'
                                        */
    1U                                 /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S9>/Delay'
                                        */
  }
  /* End of '<Root>/Subsystem2' */
  ,

  /* Start of '<Root>/Subsystem1' */
  {
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S8>/Constant1'
                                        */
    0.0,                               /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S8>/Out1'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S8>/Delay'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S8>/Switch'
                                        */
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S8>/Constant'
                                        */
    1U                                 /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S8>/Delay'
                                        */
  }
  /* End of '<Root>/Subsystem1' */
  ,

  /* Start of '<Root>/Subsystem' */
  {
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S7>/Constant1'
                                        */
    0.0,                               /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S7>/Out1'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S7>/Delay'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S7>/Switch'
                                        */
    1.0,                               /* Expression: 1
                                        * Referenced by: '<S7>/Constant'
                                        */
    1U                                 /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S7>/Delay'
                                        */
  }
  /* End of '<Root>/Subsystem' */
  ,

  /* Start of '<S5>/vl' */
  {
    15U,                               /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S24>/Digital Output'
                                        */
    9U,                                /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S25>/PWM'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S18>/Constant2'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S18>/Switch'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S18>/Constant3'
                                        */
    0.0                                /* Expression: 0
                                        * Referenced by: '<S18>/Switch1'
                                        */
  }
  /* End of '<S5>/vl' */
  ,

  /* Start of '<S5>/hl' */
  {
    14U,                               /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S20>/Digital Output'
                                        */
    8U,                                /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S21>/PWM'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S16>/Constant2'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S16>/Switch'
                                        */
    0.0,                               /* Expression: 0
                                        * Referenced by: '<S16>/Constant3'
                                        */
    0.0                                /* Expression: 0
                                        * Referenced by: '<S16>/Switch1'
                                        */
  }
  /* End of '<S5>/hl' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
