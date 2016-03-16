/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Motor_Test_All_data.c
 *
 * Code generated for Simulink model 'Motor_Test_All'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 02 15:57:22 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Motor_Test_All.h"
#include "Motor_Test_All_private.h"

/* Block parameters (auto storage) */
P_Motor_Test_All_T Motor_Test_All_P = {
  /*  Mask Parameter: RepeatingSequenceStair_OutValue
   * Referenced by: '<S1>/Vector'
   */
  { 0.0, 50.0, 100.0, 150.0, 200.0, 255.0, 200.0, 150.0, 100.0, 50.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  17U,                                 /* Mask Parameter: LimitedCounter_uplimit
                                        * Referenced by: '<S4>/FixPt Switch'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/enable'
                                        */
  0U,                                  /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S4>/Constant'
                                        */
  0U,                                  /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S2>/Output'
                                        */
  1U                                   /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S3>/FixPt Constant'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
