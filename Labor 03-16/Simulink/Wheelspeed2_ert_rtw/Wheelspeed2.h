/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Wheelspeed2.h
 *
 * Code generated for Simulink model 'Wheelspeed2'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 16 13:52:08 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Wheelspeed2_h_
#define RTW_HEADER_Wheelspeed2_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef Wheelspeed2_COMMON_INCLUDES_
# define Wheelspeed2_COMMON_INCLUDES_
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
#endif                                 /* Wheelspeed2_COMMON_INCLUDES_ */

#include "Wheelspeed2_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_zcfcn.h"

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
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals for system '<S5>/hl' */
typedef struct {
  real_T Constant3;                    /* '<S16>/Constant3' */
  uint8_T DataTypeConversion;          /* '<S21>/Data Type Conversion' */
} B_hl_Wheelspeed2_T;

/* Block states (auto storage) for system '<S5>/hl' */
typedef struct {
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S16>/Scope1' */
} DW_hl_Wheelspeed2_T;

/* Block signals for system '<Root>/Subsystem' */
typedef struct {
  real_T Add;                          /* '<S7>/Add' */
} B_Subsystem_Wheelspeed2_T;

/* Block states (auto storage) for system '<Root>/Subsystem' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<S7>/Delay' */
  int8_T Subsystem_SubsysRanBC;        /* '<Root>/Subsystem' */
} DW_Subsystem_Wheelspeed2_T;

/* Zero-crossing (trigger) state for system '<Root>/Subsystem' */
typedef struct {
  ZCSigState Subsystem_Trig_ZCE;       /* '<Root>/Subsystem' */
} ZCE_Subsystem_Wheelspeed2_T;

/* Block signals (auto storage) */
typedef struct {
  real_T RateTransition;               /* '<Root>/Rate Transition' */
  real_T RateTransition1;              /* '<Root>/Rate Transition1' */
  real_T RateTransition2;              /* '<Root>/Rate Transition2' */
  real_T RateTransition3;              /* '<Root>/Rate Transition3' */
  real_T RateTransition4;              /* '<Root>/Rate Transition4' */
  real_T enable;                       /* '<Root>/enable' */
  real_T Gain;                         /* '<S11>/Gain' */
  real_T Gain1;                        /* '<S11>/Gain1' */
  real_T Gain2;                        /* '<S11>/Gain2' */
  real_T Gain3;                        /* '<S11>/Gain3' */
  real_T Constant3;                    /* '<S19>/Constant3' */
  real_T Constant3_i;                  /* '<S17>/Constant3' */
  uint8_T DataTypeConversion;          /* '<S27>/Data Type Conversion' */
  uint8_T DataTypeConversion_i;        /* '<S23>/Data Type Conversion' */
  boolean_T DigitalInput;              /* '<Root>/Digital Input' */
  boolean_T DigitalInput1;             /* '<Root>/Digital Input1' */
  boolean_T DigitalInput2;             /* '<Root>/Digital Input2' */
  boolean_T DigitalInput3;             /* '<Root>/Digital Input3' */
  B_Subsystem_Wheelspeed2_T Subsystem3;/* '<Root>/Subsystem3' */
  B_Subsystem_Wheelspeed2_T Subsystem2;/* '<Root>/Subsystem2' */
  B_Subsystem_Wheelspeed2_T Subsystem1;/* '<Root>/Subsystem1' */
  B_Subsystem_Wheelspeed2_T Subsystem; /* '<Root>/Subsystem' */
  B_hl_Wheelspeed2_T vl;               /* '<S5>/vl' */
  B_hl_Wheelspeed2_T hl;               /* '<S5>/hl' */
} B_Wheelspeed2_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T RateTransition_Buffer0;       /* '<Root>/Rate Transition' */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWs_PWORK;                      /* '<S6>/FromWs' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_b;                    /* '<S19>/Scope1' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_k;                    /* '<S17>/Scope1' */

  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  struct {
    int_T PrevIndex;
  } FromWs_IWORK;                      /* '<S6>/FromWs' */

  boolean_T DelayInput1_DSTATE;        /* '<S1>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_e;      /* '<S2>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_h;      /* '<S3>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_k;      /* '<S4>/Delay Input1' */
  int8_T Subsystem4_SubsysRanBC;       /* '<Root>/Subsystem4' */
  DW_Subsystem_Wheelspeed2_T Subsystem3;/* '<Root>/Subsystem3' */
  DW_Subsystem_Wheelspeed2_T Subsystem2;/* '<Root>/Subsystem2' */
  DW_Subsystem_Wheelspeed2_T Subsystem1;/* '<Root>/Subsystem1' */
  DW_Subsystem_Wheelspeed2_T Subsystem;/* '<Root>/Subsystem' */
  DW_hl_Wheelspeed2_T vl;              /* '<S5>/vl' */
  DW_hl_Wheelspeed2_T hl;              /* '<S5>/hl' */
} DW_Wheelspeed2_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Subsystem4_Trig_ZCE;      /* '<Root>/Subsystem4' */
  ZCE_Subsystem_Wheelspeed2_T Subsystem3;/* '<Root>/Subsystem' */
  ZCE_Subsystem_Wheelspeed2_T Subsystem2;/* '<Root>/Subsystem' */
  ZCE_Subsystem_Wheelspeed2_T Subsystem1;/* '<Root>/Subsystem' */
  ZCE_Subsystem_Wheelspeed2_T Subsystem;/* '<Root>/Subsystem' */
} PrevZCX_Wheelspeed2_T;

/* Parameters for system: '<S5>/hl' */
struct P_hl_Wheelspeed2_T_ {
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S20>/Digital Output'
                                        */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S21>/PWM'
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
};

/* Parameters for system: '<Root>/Subsystem' */
struct P_Subsystem_Wheelspeed2_T_ {
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S7>/Out1'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S7>/Delay'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S7>/Switch'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S7>/Constant'
                                        */
  uint16_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S7>/Delay'
                                        */
};

/* Parameters (auto storage) */
struct P_Wheelspeed2_T_ {
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S22>/Digital Output'
                                        */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S23>/PWM'
                                        */
  uint32_T DigitalOutput_pinNumber_n;  /* Mask Parameter: DigitalOutput_pinNumber_n
                                        * Referenced by: '<S26>/Digital Output'
                                        */
  uint32_T PWM_pinNumber_g;            /* Mask Parameter: PWM_pinNumber_g
                                        * Referenced by: '<S27>/PWM'
                                        */
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
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S17>/Constant2'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S17>/Switch'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S17>/Constant3'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S17>/Switch1'
                                        */
  real_T Constant2_Value_j;            /* Expression: 0
                                        * Referenced by: '<S19>/Constant2'
                                        */
  real_T Switch_Threshold_n;           /* Expression: 0
                                        * Referenced by: '<S19>/Switch'
                                        */
  real_T Constant3_Value_k;            /* Expression: 0
                                        * Referenced by: '<S19>/Constant3'
                                        */
  real_T Switch1_Threshold_k;          /* Expression: 0
                                        * Referenced by: '<S19>/Switch1'
                                        */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S11>/Out1'
                                        */
  real_T Out2_Y0;                      /* Computed Parameter: Out2_Y0
                                        * Referenced by: '<S11>/Out2'
                                        */
  real_T Out3_Y0;                      /* Computed Parameter: Out3_Y0
                                        * Referenced by: '<S11>/Out3'
                                        */
  real_T Out4_Y0;                      /* Computed Parameter: Out4_Y0
                                        * Referenced by: '<S11>/Out4'
                                        */
  real_T Gain_Gain;                    /* Expression: 4
                                        * Referenced by: '<S11>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 4
                                        * Referenced by: '<S11>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 4
                                        * Referenced by: '<S11>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: 4
                                        * Referenced by: '<S11>/Gain3'
                                        */
  real_T RateTransition_X0;            /* Expression: 0
                                        * Referenced by: '<Root>/Rate Transition'
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
  boolean_T Constant_Value;            /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S12>/Constant'
                                        */
  boolean_T Constant_Value_b;          /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S13>/Constant'
                                        */
  boolean_T Constant_Value_p;          /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S14>/Constant'
                                        */
  boolean_T Constant_Value_m;          /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S15>/Constant'
                                        */
  P_Subsystem_Wheelspeed2_T Subsystem3;/* '<Root>/Subsystem3' */
  P_Subsystem_Wheelspeed2_T Subsystem2;/* '<Root>/Subsystem2' */
  P_Subsystem_Wheelspeed2_T Subsystem1;/* '<Root>/Subsystem1' */
  P_Subsystem_Wheelspeed2_T Subsystem; /* '<Root>/Subsystem' */
  P_hl_Wheelspeed2_T vl;               /* '<S5>/vl' */
  P_hl_Wheelspeed2_T hl;               /* '<S5>/hl' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Wheelspeed2_T {
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
    uint32_T clockTick2;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
    } RateInteraction;

    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Wheelspeed2_T Wheelspeed2_P;

/* Block signals (auto storage) */
extern B_Wheelspeed2_T Wheelspeed2_B;

/* Block states (auto storage) */
extern DW_Wheelspeed2_T Wheelspeed2_DW;

/* External function called from main */
extern void Wheelspeed2_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_Wheelspeed2_T Wheelspeed2_PrevZCX;

/* Model entry point functions */
extern void Wheelspeed2_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void Wheelspeed2_initialize(void);
extern void Wheelspeed2_step0(void);
extern void Wheelspeed2_step2(void);
extern void Wheelspeed2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Wheelspeed2_T *const Wheelspeed2_M;

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
 * '<Root>' : 'Wheelspeed2'
 * '<S1>'   : 'Wheelspeed2/Detect Rise Positive'
 * '<S2>'   : 'Wheelspeed2/Detect Rise Positive1'
 * '<S3>'   : 'Wheelspeed2/Detect Rise Positive2'
 * '<S4>'   : 'Wheelspeed2/Detect Rise Positive3'
 * '<S5>'   : 'Wheelspeed2/Motorensteuerung'
 * '<S6>'   : 'Wheelspeed2/Signal Builder'
 * '<S7>'   : 'Wheelspeed2/Subsystem'
 * '<S8>'   : 'Wheelspeed2/Subsystem1'
 * '<S9>'   : 'Wheelspeed2/Subsystem2'
 * '<S10>'  : 'Wheelspeed2/Subsystem3'
 * '<S11>'  : 'Wheelspeed2/Subsystem4'
 * '<S12>'  : 'Wheelspeed2/Detect Rise Positive/Positive'
 * '<S13>'  : 'Wheelspeed2/Detect Rise Positive1/Positive'
 * '<S14>'  : 'Wheelspeed2/Detect Rise Positive2/Positive'
 * '<S15>'  : 'Wheelspeed2/Detect Rise Positive3/Positive'
 * '<S16>'  : 'Wheelspeed2/Motorensteuerung/hl'
 * '<S17>'  : 'Wheelspeed2/Motorensteuerung/hr'
 * '<S18>'  : 'Wheelspeed2/Motorensteuerung/vl'
 * '<S19>'  : 'Wheelspeed2/Motorensteuerung/vr'
 * '<S20>'  : 'Wheelspeed2/Motorensteuerung/hl/M'
 * '<S21>'  : 'Wheelspeed2/Motorensteuerung/hl/PWM E'
 * '<S22>'  : 'Wheelspeed2/Motorensteuerung/hr/Digital Output M'
 * '<S23>'  : 'Wheelspeed2/Motorensteuerung/hr/PWM E'
 * '<S24>'  : 'Wheelspeed2/Motorensteuerung/vl/M'
 * '<S25>'  : 'Wheelspeed2/Motorensteuerung/vl/PWM E'
 * '<S26>'  : 'Wheelspeed2/Motorensteuerung/vr/Digital Output'
 * '<S27>'  : 'Wheelspeed2/Motorensteuerung/vr/PWM'
 */
#endif                                 /* RTW_HEADER_Wheelspeed2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
