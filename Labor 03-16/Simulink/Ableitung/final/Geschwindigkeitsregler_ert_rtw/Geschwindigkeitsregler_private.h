/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Geschwindigkeitsregler_private.h
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

#ifndef RTW_HEADER_Geschwindigkeitsregler_private_h_
#define RTW_HEADER_Geschwindigkeitsregler_private_h_
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

/* Used by FromWorkspace Block: '<S3>/FromWs' */
#ifndef rtInterpolate
# define rtInterpolate(v1,v2,f1,f2)    (((v1)==(v2))?((double)(v1)): (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif

#ifndef rtRound
# define rtRound(v)                    ( ((v) >= 0) ? floor((v) + 0.5) : ceil((v) - 0.5) )
#endif

extern void Geschwindigkeitsregler_hl_Start(P_hl_Geschwindigkeitsregler_T
  *localP);
extern void Geschwindigkeitsregler_hl(real_T rtu_enable, real_T rtu_power,
  real_T rtu_direction, B_hl_Geschwindigkeitsregler_T *localB,
  P_hl_Geschwindigkeitsregler_T *localP);
extern void Geschwindigkeits_Subsystem_Init(DW_Subsystem_Geschwindigkeits_T
  *localDW, P_Subsystem_Geschwindigkeitsr_T *localP);
extern void Geschwindigkeit_Subsystem_Start(B_Subsystem_Geschwindigkeitsr_T
  *localB, P_Subsystem_Geschwindigkeitsr_T *localP);
extern void Geschwindigkeitsregle_Subsystem(boolean_T rtu_Trigger, real_T
  rtu_reset, B_Subsystem_Geschwindigkeitsr_T *localB,
  DW_Subsystem_Geschwindigkeits_T *localDW, P_Subsystem_Geschwindigkeitsr_T
  *localP, ZCE_Subsystem_Geschwindigkeit_T *localZCE);

#endif                                 /* RTW_HEADER_Geschwindigkeitsregler_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
