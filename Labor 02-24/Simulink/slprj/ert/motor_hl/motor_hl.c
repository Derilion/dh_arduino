/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motor_hl.c
 *
 * Code generated for Simulink model 'motor_hl'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 02 15:53:50 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "motor_hl.h"
#include "motor_hl_private.h"

P_motor_hl_T motor_hl_P = {
  14U,                                 /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S1>/Digital Output'
                                        */
  8U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S2>/PWM'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
  0.0                                  /* Expression: 0
                                        * Referenced by: '<Root>/Switch1'
                                        */
};

/* Start for referenced model: 'motor_hl' */
void motor_hl_Start(void)
{
  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S1>/Digital Output' */
  MW_pinModeOutput(motor_hl_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
  MW_pinModeOutput(motor_hl_P.PWM_pinNumber);
}

/* Output and update for referenced model: 'motor_hl' */
void motor_hl(const real_T *rtu_enable, const real_T *rtu_power, const real_T
              *rtu_direction)
{
  real_T rtu_enable_0;
  uint8_T rtu_enable_1;

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  if (*rtu_enable > motor_hl_P.Switch_Threshold) {
    rtu_enable_0 = *rtu_direction;
  } else {
    rtu_enable_0 = motor_hl_P.Constant2_Value;
  }

  /* End of Switch: '<Root>/Switch' */

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  if (rtu_enable_0 < 256.0) {
    if (rtu_enable_0 >= 0.0) {
      rtu_enable_1 = (uint8_T)rtu_enable_0;
    } else {
      rtu_enable_1 = 0U;
    }
  } else {
    rtu_enable_1 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S1>/Digital Output' */
  MW_digitalWrite(motor_hl_P.DigitalOutput_pinNumber, rtu_enable_1);

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  if (*rtu_enable > motor_hl_P.Switch1_Threshold) {
    rtu_enable_0 = *rtu_power;
  } else {
    rtu_enable_0 = motor_hl_P.Constant3_Value;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  if (rtu_enable_0 < 256.0) {
    if (rtu_enable_0 >= 0.0) {
      rtu_enable_1 = (uint8_T)rtu_enable_0;
    } else {
      rtu_enable_1 = 0U;
    }
  } else {
    rtu_enable_1 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S2>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
  MW_analogWrite(motor_hl_P.PWM_pinNumber, rtu_enable_1);
}

/* Model initialize function */
void motor_hl_initialize(const char_T **rt_errorStatus, RT_MODEL_motor_hl_T *
  const motor_hl_M)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(motor_hl_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
