/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motor_test_hierarchies_private.h
 *
 * Code generated for Simulink model 'motor_test_hierarchies'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 02 17:11:29 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_motor_test_hierarchies_private_h_
#define RTW_HEADER_motor_test_hierarchies_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

extern void motor_test_hierarchies_hl_Start(P_hl_motor_test_hierarchies_T
  *localP);
extern void motor_test_hierarchies_hl(real_T rtu_enable, real_T rtu_power,
  real_T rtu_direction, P_hl_motor_test_hierarchies_T *localP);

#endif                                 /* RTW_HEADER_motor_test_hierarchies_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
