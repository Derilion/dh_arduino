/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motor_hr.h
 *
 * Code generated for Simulink model 'motor_hr'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 02 15:53:56 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_motor_hr_h_
#define RTW_HEADER_motor_hr_h_
#ifndef motor_hr_COMMON_INCLUDES_
# define motor_hr_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_digitaloutput_lct.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* motor_hr_COMMON_INCLUDES_ */

#include "motor_hr_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "model_reference_types.h"

/* Parameters (auto storage) */
struct P_motor_hr_T_ {
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S1>/Digital Output'
                                        */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S2>/PWM'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_motor_hr_T {
  const char_T **errorStatus;
};

typedef struct {
  RT_MODEL_motor_hr_T rtm;
} MdlrefDW_motor_hr_T;

/* Model reference registration function */
extern void motor_hr_initialize(const char_T **rt_errorStatus,
  RT_MODEL_motor_hr_T *const motor_hr_M);
extern void motor_hr_Start(void);
extern void motor_hr(const real_T *rtu_enable, const real_T *rtu_power, const
                     real_T *rtu_direction);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'motor_hr'
 * '<S1>'   : 'motor_hr/Digital Output'
 * '<S2>'   : 'motor_hr/PWM'
 */
#endif                                 /* RTW_HEADER_motor_hr_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
