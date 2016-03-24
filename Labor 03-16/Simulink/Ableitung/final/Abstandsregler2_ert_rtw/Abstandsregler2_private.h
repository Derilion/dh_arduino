/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Abstandsregler2_private.h
 *
 * Code generated for Simulink model 'Abstandsregler2'.
 *
 * Model version                  : 1.28
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 23 17:32:47 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Abstandsregler2_private_h_
#define RTW_HEADER_Abstandsregler2_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

extern real_T look1_iu16bdtd_binlcpw(uint16_T u0, const real_T bp0[], const
  real_T table[], uint32_T maxIndex);
extern void Abstandsregler2_hl_Start(P_hl_Abstandsregler2_T *localP);
extern void Abstandsregler2_hl(real_T rtu_enable, real_T rtu_power, real_T
  rtu_direction, P_hl_Abstandsregler2_T *localP);
extern void Abstandsregler2_Subsystem_Init(DW_Subsystem_Abstandsregler2_T
  *localDW, P_Subsystem_Abstandsregler2_T *localP);
extern void Abstandsregler2_Subsystem_Start(B_Subsystem_Abstandsregler2_T
  *localB, P_Subsystem_Abstandsregler2_T *localP);
extern void Abstandsregler2_Subsystem(boolean_T rtu_Trigger, real_T rtu_reset,
  B_Subsystem_Abstandsregler2_T *localB, DW_Subsystem_Abstandsregler2_T *localDW,
  P_Subsystem_Abstandsregler2_T *localP, ZCE_Subsystem_Abstandsregler2_T
  *localZCE);

#endif                                 /* RTW_HEADER_Abstandsregler2_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
