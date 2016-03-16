/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ArduinoTests.h
 *
 * Code generated for Simulink model 'ArduinoTests'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Feb 24 17:40:41 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ArduinoTests_h_
#define RTW_HEADER_ArduinoTests_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef ArduinoTests_COMMON_INCLUDES_
# define ArduinoTests_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "arduino_analoginput_lct.h"
#include "arduino_digitalinput_lct.h"
#endif                                 /* ArduinoTests_COMMON_INCLUDES_ */

#include "ArduinoTests_types.h"

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

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Add;                          /* '<S6>/Add' */
  uint16_T AnalogInput;                /* '<Root>/Analog Input' */
  boolean_T DigitalInput;              /* '<Root>/Digital Input' */
  boolean_T DigitalInput1;             /* '<Root>/Digital Input1' */
  boolean_T DigitalInput2;             /* '<Root>/Digital Input2' */
  boolean_T DigitalInput3;             /* '<Root>/Digital Input3' */
} B_ArduinoTests_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<S6>/Delay' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  boolean_T DelayInput1_DSTATE;        /* '<S1>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_e;      /* '<S2>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_h;      /* '<S3>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_k;      /* '<S4>/Delay Input1' */
  int8_T Subsystem_SubsysRanBC;        /* '<Root>/Subsystem' */
} DW_ArduinoTests_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Subsystem_Trig_ZCE;       /* '<Root>/Subsystem' */
} PrevZCX_ArduinoTests_T;

/* Parameters (auto storage) */
struct P_ArduinoTests_T_ {
  boolean_T DetectRisePositive_vinit;  /* Mask Parameter: DetectRisePositive_vinit
                                        * Referenced by: '<S1>/Delay Input1'
                                        */
  boolean_T DetectRisePositive1_vinit; /* Mask Parameter: DetectRisePositive1_vinit
                                        * Referenced by: '<S2>/Delay Input1'
                                        */
  boolean_T DetectRisePositive2_vinit; /* Mask Parameter: DetectRisePositive2_vinit
                                        * Referenced by: '<S3>/Delay Input1'
                                        */
  boolean_T DetectRisePositive3_vinit; /* Mask Parameter: DetectRisePositive3_vinit
                                        * Referenced by: '<S4>/Delay Input1'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S6>/Out1'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S6>/Delay'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S6>/Switch'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  uint32_T AnalogInput_p1;             /* Computed Parameter: AnalogInput_p1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  uint32_T DigitalInput_p1;            /* Computed Parameter: DigitalInput_p1
                                        * Referenced by: '<Root>/Digital Input'
                                        */
  uint32_T DigitalInput1_p1;           /* Computed Parameter: DigitalInput1_p1
                                        * Referenced by: '<Root>/Digital Input1'
                                        */
  uint32_T DigitalInput2_p1;           /* Computed Parameter: DigitalInput2_p1
                                        * Referenced by: '<Root>/Digital Input2'
                                        */
  uint32_T DigitalInput3_p1;           /* Computed Parameter: DigitalInput3_p1
                                        * Referenced by: '<Root>/Digital Input3'
                                        */
  uint16_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S6>/Delay'
                                        */
  boolean_T Constant_Value_l;          /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S7>/Constant'
                                        */
  boolean_T Constant_Value_b;          /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S8>/Constant'
                                        */
  boolean_T Constant_Value_p;          /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S9>/Constant'
                                        */
  boolean_T Constant_Value_m;          /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S10>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ArduinoTests_T {
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
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_ArduinoTests_T ArduinoTests_P;

/* Block signals (auto storage) */
extern B_ArduinoTests_T ArduinoTests_B;

/* Block states (auto storage) */
extern DW_ArduinoTests_T ArduinoTests_DW;

/* External function called from main */
extern void ArduinoTests_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_ArduinoTests_T ArduinoTests_PrevZCX;

/* Model entry point functions */
extern void ArduinoTests_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void ArduinoTests_initialize(void);
extern void ArduinoTests_step0(void);
extern void ArduinoTests_step1(void);
extern void ArduinoTests_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ArduinoTests_T *const ArduinoTests_M;

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
 * '<Root>' : 'ArduinoTests'
 * '<S1>'   : 'ArduinoTests/Detect Rise Positive'
 * '<S2>'   : 'ArduinoTests/Detect Rise Positive1'
 * '<S3>'   : 'ArduinoTests/Detect Rise Positive2'
 * '<S4>'   : 'ArduinoTests/Detect Rise Positive3'
 * '<S5>'   : 'ArduinoTests/IMU_Deactivated'
 * '<S6>'   : 'ArduinoTests/Subsystem'
 * '<S7>'   : 'ArduinoTests/Detect Rise Positive/Positive'
 * '<S8>'   : 'ArduinoTests/Detect Rise Positive1/Positive'
 * '<S9>'   : 'ArduinoTests/Detect Rise Positive2/Positive'
 * '<S10>'  : 'ArduinoTests/Detect Rise Positive3/Positive'
 */
#endif                                 /* RTW_HEADER_ArduinoTests_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
