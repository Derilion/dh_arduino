/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Wheelspeed3.h
 *
 * Code generated for Simulink model 'Wheelspeed3'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 16 14:06:12 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Wheelspeed3_h_
#define RTW_HEADER_Wheelspeed3_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef Wheelspeed3_COMMON_INCLUDES_
# define Wheelspeed3_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "arduino_digitaloutput_lct.h"
#include "arduino_analogoutput_lct.h"
#include "arduino_digitalinput_lct.h"
#endif                                 /* Wheelspeed3_COMMON_INCLUDES_ */

#include "Wheelspeed3_types.h"

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

/* Block signals for system '<S5>/hl' */
typedef struct {
  uint8_T DataTypeConversion;          /* '<S20>/Data Type Conversion' */
} B_hl_Wheelspeed3_T;

/* Block states (auto storage) for system '<S5>/hl' */
typedef struct {
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S15>/Scope1' */
} DW_hl_Wheelspeed3_T;

/* Block signals (auto storage) */
typedef struct {
  real_T Clock;                        /* '<Root>/Clock' */
  real_T enable;                       /* '<Root>/enable' */
  real_T Divide;                       /* '<S7>/Divide' */
  uint8_T DataTypeConversion;          /* '<S26>/Data Type Conversion' */
  uint8_T DataTypeConversion_i;        /* '<S22>/Data Type Conversion' */
  boolean_T DigitalInput;              /* '<Root>/Digital Input' */
  boolean_T DigitalInput1;             /* '<Root>/Digital Input1' */
  boolean_T DigitalInput2;             /* '<Root>/Digital Input2' */
  boolean_T DigitalInput3;             /* '<Root>/Digital Input3' */
  B_hl_Wheelspeed3_T vl;               /* '<S5>/vl' */
  B_hl_Wheelspeed3_T hl;               /* '<S5>/hl' */
} B_Wheelspeed3_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Delay1_DSTATE;                /* '<S7>/Delay1' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWs_PWORK;                      /* '<S6>/FromWs' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_b;                    /* '<S18>/Scope1' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_k;                    /* '<S16>/Scope1' */

  struct {
    int_T PrevIndex;
  } FromWs_IWORK;                      /* '<S6>/FromWs' */

  boolean_T DelayInput1_DSTATE;        /* '<S1>/Delay Input1' */
  int8_T Subsystem3_SubsysRanBC;       /* '<Root>/Subsystem3' */
  DW_hl_Wheelspeed3_T vl;              /* '<S5>/vl' */
  DW_hl_Wheelspeed3_T hl;              /* '<S5>/hl' */
} DW_Wheelspeed3_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Subsystem3_Trig_ZCE;      /* '<Root>/Subsystem3' */
} PrevZCX_Wheelspeed3_T;

/* Parameters for system: '<S5>/hl' */
struct P_hl_Wheelspeed3_T_ {
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S19>/Digital Output'
                                        */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S20>/PWM'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S15>/Constant2'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S15>/Switch'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S15>/Constant3'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S15>/Switch1'
                                        */
};

/* Parameters (auto storage) */
struct P_Wheelspeed3_T_ {
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S21>/Digital Output'
                                        */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S22>/PWM'
                                        */
  uint32_T DigitalOutput_pinNumber_n;  /* Mask Parameter: DigitalOutput_pinNumber_n
                                        * Referenced by: '<S25>/Digital Output'
                                        */
  uint32_T PWM_pinNumber_g;            /* Mask Parameter: PWM_pinNumber_g
                                        * Referenced by: '<S26>/PWM'
                                        */
  boolean_T DetectRisePositive_vinit;  /* Mask Parameter: DetectRisePositive_vinit
                                        * Referenced by: '<S1>/Delay Input1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S16>/Constant2'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S16>/Switch'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S16>/Constant3'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S16>/Switch1'
                                        */
  real_T Constant2_Value_j;            /* Expression: 0
                                        * Referenced by: '<S18>/Constant2'
                                        */
  real_T Switch_Threshold_n;           /* Expression: 0
                                        * Referenced by: '<S18>/Switch'
                                        */
  real_T Constant3_Value_k;            /* Expression: 0
                                        * Referenced by: '<S18>/Constant3'
                                        */
  real_T Switch1_Threshold_k;          /* Expression: 0
                                        * Referenced by: '<S18>/Switch1'
                                        */
  real_T dPhi_Y0;                      /* Computed Parameter: dPhi_Y0
                                        * Referenced by: '<S7>/dPhi'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S7>/Delay1'
                                        */
  real_T Constant_Value;               /* Expression: 36
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T enable_Value;                 /* Expression: 1
                                        * Referenced by: '<Root>/enable'
                                        */
  real_T direction_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/direction'
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
  uint16_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<S7>/Delay1'
                                        */
  boolean_T Constant_Value_l;          /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S11>/Constant'
                                        */
  P_hl_Wheelspeed3_T vl;               /* '<S5>/vl' */
  P_hl_Wheelspeed3_T hl;               /* '<S5>/hl' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Wheelspeed3_T {
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
extern P_Wheelspeed3_T Wheelspeed3_P;

/* Block signals (auto storage) */
extern B_Wheelspeed3_T Wheelspeed3_B;

/* Block states (auto storage) */
extern DW_Wheelspeed3_T Wheelspeed3_DW;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_Wheelspeed3_T Wheelspeed3_PrevZCX;

/* Model entry point functions */
extern void Wheelspeed3_initialize(void);
extern void Wheelspeed3_step(void);
extern void Wheelspeed3_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Wheelspeed3_T *const Wheelspeed3_M;

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
 * '<Root>' : 'Wheelspeed3'
 * '<S1>'   : 'Wheelspeed3/Detect Rise Positive'
 * '<S2>'   : 'Wheelspeed3/Detect Rise Positive1'
 * '<S3>'   : 'Wheelspeed3/Detect Rise Positive2'
 * '<S4>'   : 'Wheelspeed3/Detect Rise Positive3'
 * '<S5>'   : 'Wheelspeed3/Motorensteuerung'
 * '<S6>'   : 'Wheelspeed3/Signal Builder'
 * '<S7>'   : 'Wheelspeed3/Subsystem3'
 * '<S8>'   : 'Wheelspeed3/Subsystem4'
 * '<S9>'   : 'Wheelspeed3/Subsystem5'
 * '<S10>'  : 'Wheelspeed3/Subsystem6'
 * '<S11>'  : 'Wheelspeed3/Detect Rise Positive/Positive'
 * '<S12>'  : 'Wheelspeed3/Detect Rise Positive1/Positive'
 * '<S13>'  : 'Wheelspeed3/Detect Rise Positive2/Positive'
 * '<S14>'  : 'Wheelspeed3/Detect Rise Positive3/Positive'
 * '<S15>'  : 'Wheelspeed3/Motorensteuerung/hl'
 * '<S16>'  : 'Wheelspeed3/Motorensteuerung/hr'
 * '<S17>'  : 'Wheelspeed3/Motorensteuerung/vl'
 * '<S18>'  : 'Wheelspeed3/Motorensteuerung/vr'
 * '<S19>'  : 'Wheelspeed3/Motorensteuerung/hl/M'
 * '<S20>'  : 'Wheelspeed3/Motorensteuerung/hl/PWM E'
 * '<S21>'  : 'Wheelspeed3/Motorensteuerung/hr/Digital Output M'
 * '<S22>'  : 'Wheelspeed3/Motorensteuerung/hr/PWM E'
 * '<S23>'  : 'Wheelspeed3/Motorensteuerung/vl/M'
 * '<S24>'  : 'Wheelspeed3/Motorensteuerung/vl/PWM E'
 * '<S25>'  : 'Wheelspeed3/Motorensteuerung/vr/Digital Output'
 * '<S26>'  : 'Wheelspeed3/Motorensteuerung/vr/PWM'
 */
#endif                                 /* RTW_HEADER_Wheelspeed3_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
