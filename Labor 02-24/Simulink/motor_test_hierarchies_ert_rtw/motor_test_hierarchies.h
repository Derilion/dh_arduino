/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motor_test_hierarchies.h
 *
 * Code generated for Simulink model 'motor_test_hierarchies'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 16 13:15:09 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_motor_test_hierarchies_h_
#define RTW_HEADER_motor_test_hierarchies_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef motor_test_hierarchies_COMMON_INCLUDES_
# define motor_test_hierarchies_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "arduino_digitaloutput_lct.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* motor_test_hierarchies_COMMON_INCLUDES_ */

#include "motor_test_hierarchies_types.h"

/* Shared type includes */
#include "multiword_types.h"
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
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals for system '<S1>/hl' */
typedef struct {
  uint8_T DataTypeConversion;          /* '<S9>/Data Type Conversion' */
} B_hl_motor_test_hierarchies_T;

/* Block states (auto storage) for system '<S1>/hl' */
typedef struct {
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S4>/Scope1' */
} DW_hl_motor_test_hierarchies_T;

/* Block signals (auto storage) */
typedef struct {
  real_T enable;                       /* '<Root>/enable' */
  uint8_T DataTypeConversion;          /* '<S15>/Data Type Conversion' */
  uint8_T DataTypeConversion_b;        /* '<S11>/Data Type Conversion' */
  B_hl_motor_test_hierarchies_T vl;    /* '<S1>/vl' */
  B_hl_motor_test_hierarchies_T hl;    /* '<S1>/hl' */
} B_motor_test_hierarchies_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWs_PWORK;                      /* '<S3>/FromWs' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S7>/Scope1' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_e;                    /* '<S5>/Scope1' */

  struct {
    int_T PrevIndex;
  } FromWs_IWORK;                      /* '<S3>/FromWs' */

  DW_hl_motor_test_hierarchies_T vl;   /* '<S1>/vl' */
  DW_hl_motor_test_hierarchies_T hl;   /* '<S1>/hl' */
} DW_motor_test_hierarchies_T;

/* Parameters for system: '<S1>/hl' */
struct P_hl_motor_test_hierarchies_T_ {
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S8>/Digital Output'
                                        */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S9>/PWM'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S4>/Constant3'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S4>/Switch1'
                                        */
};

/* Parameters (auto storage) */
struct P_motor_test_hierarchies_T_ {
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S10>/Digital Output'
                                        */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S11>/PWM'
                                        */
  uint32_T DigitalOutput_pinNumber_a;  /* Mask Parameter: DigitalOutput_pinNumber_a
                                        * Referenced by: '<S14>/Digital Output'
                                        */
  uint32_T PWM_pinNumber_n;            /* Mask Parameter: PWM_pinNumber_n
                                        * Referenced by: '<S15>/PWM'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S5>/Switch'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S5>/Constant3'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S5>/Switch1'
                                        */
  real_T Constant2_Value_n;            /* Expression: 0
                                        * Referenced by: '<S7>/Constant2'
                                        */
  real_T Switch_Threshold_k;           /* Expression: 0
                                        * Referenced by: '<S7>/Switch'
                                        */
  real_T Constant3_Value_f;            /* Expression: 0
                                        * Referenced by: '<S7>/Constant3'
                                        */
  real_T Switch1_Threshold_o;          /* Expression: 0
                                        * Referenced by: '<S7>/Switch1'
                                        */
  real_T enable_Value;                 /* Expression: 1
                                        * Referenced by: '<Root>/enable'
                                        */
  real_T direction_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/direction'
                                        */
  P_hl_motor_test_hierarchies_T vl;    /* '<S1>/vl' */
  P_hl_motor_test_hierarchies_T hl;    /* '<S1>/hl' */
};

/* Real-time Model Data Structure */
struct tag_RTM_motor_test_hierarchie_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

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
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_motor_test_hierarchies_T motor_test_hierarchies_P;

/* Block signals (auto storage) */
extern B_motor_test_hierarchies_T motor_test_hierarchies_B;

/* Block states (auto storage) */
extern DW_motor_test_hierarchies_T motor_test_hierarchies_DW;

/* Model entry point functions */
extern void motor_test_hierarchies_initialize(void);
extern void motor_test_hierarchies_step(void);
extern void motor_test_hierarchies_terminate(void);

/* Real-time Model object */
extern RT_MODEL_motor_test_hierarchi_T *const motor_test_hierarchies_M;

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
 * '<Root>' : 'motor_test_hierarchies'
 * '<S1>'   : 'motor_test_hierarchies/Motorensteuerung'
 * '<S2>'   : 'motor_test_hierarchies/Repeating Sequence Stair1'
 * '<S3>'   : 'motor_test_hierarchies/Signal Builder'
 * '<S4>'   : 'motor_test_hierarchies/Motorensteuerung/hl'
 * '<S5>'   : 'motor_test_hierarchies/Motorensteuerung/hr'
 * '<S6>'   : 'motor_test_hierarchies/Motorensteuerung/vl'
 * '<S7>'   : 'motor_test_hierarchies/Motorensteuerung/vr'
 * '<S8>'   : 'motor_test_hierarchies/Motorensteuerung/hl/M'
 * '<S9>'   : 'motor_test_hierarchies/Motorensteuerung/hl/PWM E'
 * '<S10>'  : 'motor_test_hierarchies/Motorensteuerung/hr/Digital Output M'
 * '<S11>'  : 'motor_test_hierarchies/Motorensteuerung/hr/PWM E'
 * '<S12>'  : 'motor_test_hierarchies/Motorensteuerung/vl/M'
 * '<S13>'  : 'motor_test_hierarchies/Motorensteuerung/vl/PWM E'
 * '<S14>'  : 'motor_test_hierarchies/Motorensteuerung/vr/Digital Output'
 * '<S15>'  : 'motor_test_hierarchies/Motorensteuerung/vr/PWM'
 * '<S16>'  : 'motor_test_hierarchies/Repeating Sequence Stair1/LimitedCounter'
 * '<S17>'  : 'motor_test_hierarchies/Repeating Sequence Stair1/LimitedCounter/Increment Real World'
 * '<S18>'  : 'motor_test_hierarchies/Repeating Sequence Stair1/LimitedCounter/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_motor_test_hierarchies_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
