/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Motor_Test_All.h
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

#ifndef RTW_HEADER_Motor_Test_All_h_
#define RTW_HEADER_Motor_Test_All_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef Motor_Test_All_COMMON_INCLUDES_
# define Motor_Test_All_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                                 /* Motor_Test_All_COMMON_INCLUDES_ */

#include "Motor_Test_All_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "model_reference_types.h"

/* Child system includes */
#include "motor_vr.h"
#include "motor_vl.h"
#include "motor_hr.h"
#include "motor_hl.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) ((const char_T **)(&((rtm)->errorStatus)))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint8_T Output_DSTATE;               /* '<S2>/Output' */
  MdlrefDW_motor_hl_T Model_DWORK1;    /* '<Root>/Model' */
  MdlrefDW_motor_vr_T Model1_DWORK1;   /* '<Root>/Model1' */
  MdlrefDW_motor_vl_T Model2_DWORK1;   /* '<Root>/Model2' */
  MdlrefDW_motor_hr_T Model3_DWORK1;   /* '<Root>/Model3' */
} DW_Motor_Test_All_T;

/* Parameters (auto storage) */
struct P_Motor_Test_All_T_ {
  real_T RepeatingSequenceStair_OutValue[18];/* Mask Parameter: RepeatingSequenceStair_OutValue
                                              * Referenced by: '<S1>/Vector'
                                              */
  uint8_T LimitedCounter_uplimit;      /* Mask Parameter: LimitedCounter_uplimit
                                        * Referenced by: '<S4>/FixPt Switch'
                                        */
  real_T enable_Value;                 /* Expression: 1
                                        * Referenced by: '<Root>/enable'
                                        */
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S4>/Constant'
                                        */
  uint8_T Output_InitialCondition;     /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S2>/Output'
                                        */
  uint8_T FixPtConstant_Value;         /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S3>/FixPt Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Motor_Test_All_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Motor_Test_All_T Motor_Test_All_P;

/* Block states (auto storage) */
extern DW_Motor_Test_All_T Motor_Test_All_DW;

/* Model entry point functions */
extern void Motor_Test_All_initialize(void);
extern void Motor_Test_All_step(void);
extern void Motor_Test_All_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Motor_Test_All_T *const Motor_Test_All_M;

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
 * '<Root>' : 'Motor_Test_All'
 * '<S1>'   : 'Motor_Test_All/Repeating Sequence Stair'
 * '<S2>'   : 'Motor_Test_All/Repeating Sequence Stair/LimitedCounter'
 * '<S3>'   : 'Motor_Test_All/Repeating Sequence Stair/LimitedCounter/Increment Real World'
 * '<S4>'   : 'Motor_Test_All/Repeating Sequence Stair/LimitedCounter/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_Motor_Test_All_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
