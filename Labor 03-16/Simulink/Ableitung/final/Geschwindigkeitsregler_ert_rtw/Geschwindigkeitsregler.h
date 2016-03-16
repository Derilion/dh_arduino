/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Geschwindigkeitsregler.h
 *
 * Code generated for Simulink model 'Geschwindigkeitsregler'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 16 16:21:22 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Geschwindigkeitsregler_h_
#define RTW_HEADER_Geschwindigkeitsregler_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef Geschwindigkeitsregler_COMMON_INCLUDES_
# define Geschwindigkeitsregler_COMMON_INCLUDES_
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
#endif                                 /* Geschwindigkeitsregler_COMMON_INCLUDES_ */

#include "Geschwindigkeitsregler_types.h"

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
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block states (auto storage) for system '<S1>/hl' */
typedef struct {
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S5>/Scope1' */
} DW_hl_Geschwindigkeitsregler_T;

/* Block signals for system '<S17>/Subsystem' */
typedef struct {
  real_T Add;                          /* '<S26>/Add' */
} B_Subsystem_Geschwindigkeitsr_T;

/* Block states (auto storage) for system '<S17>/Subsystem' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<S26>/Delay' */
  int8_T Subsystem_SubsysRanBC;        /* '<S17>/Subsystem' */
} DW_Subsystem_Geschwindigkeits_T;

/* Zero-crossing (trigger) state for system '<S17>/Subsystem' */
typedef struct {
  ZCSigState Subsystem_Trig_ZCE;       /* '<S17>/Subsystem' */
} ZCE_Subsystem_Geschwindigkeit_T;

/* Block signals (auto storage) */
typedef struct {
  real_T Zustandsvariablenfilter_da[3];/* '<S18>/Zustandsvariablenfilter' */
  real_T r1Altwerte[4];                /* '<S18>/r+1 Altwerte' */
  real_T r1Altwerte_n[4];              /* '<S19>/r+1 Altwerte' */
  real_T r1Altwerte_o[4];              /* '<S20>/r+1 Altwerte' */
  real_T r1Altwerte_h[4];              /* '<S21>/r+1 Altwerte' */
  real_T xnew[3];
  real_T enable;                       /* '<Root>/enable' */
  real_T Divide;                       /* '<S4>/Divide' */
  real_T Zustandsvariablenfilter[3];   /* '<S19>/Zustandsvariablenfilter' */
  real_T diffferenzN;                  /* '<S4>/diffferenzN' */
  real_T Switch1;                      /* '<S4>/Switch1' */
  real_T Zustandsvariablenfilter_a[3]; /* '<S20>/Zustandsvariablenfilter' */
  real_T Zustandsvariablenfilter_d[3]; /* '<S21>/Zustandsvariablenfilter' */
  boolean_T HL;                        /* '<S17>/HL' */
  boolean_T HR;                        /* '<S17>/HR' */
  boolean_T VR;                        /* '<S17>/VR' */
  boolean_T VL;                        /* '<S17>/VL' */
  B_Subsystem_Geschwindigkeitsr_T Subsystem3;/* '<S17>/Subsystem3' */
  B_Subsystem_Geschwindigkeitsr_T Subsystem2;/* '<S17>/Subsystem2' */
  B_Subsystem_Geschwindigkeitsr_T Subsystem1;/* '<S17>/Subsystem1' */
  B_Subsystem_Geschwindigkeitsr_T Subsystem;/* '<S17>/Subsystem' */
} B_Geschwindigkeitsregler_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Zustandsvariablenfilter_DSTATE[3];/* '<S19>/Zustandsvariablenfilter' */
  real_T Delay_DSTATE[2];              /* '<S4>/Delay' */
  real_T Zustandsvariablenfilter_DSTAT_o[3];/* '<S20>/Zustandsvariablenfilter' */
  real_T Zustandsvariablenfilter_DSTAT_c[3];/* '<S21>/Zustandsvariablenfilter' */
  real_T Zustandsvariablenfilter_DSTAT_e[3];/* '<S18>/Zustandsvariablenfilter' */
  real_T r1Altwerte_DSTATE[4];         /* '<S18>/r+1 Altwerte' */
  real_T r1Altwerte_DSTATE_o[4];       /* '<S19>/r+1 Altwerte' */
  real_T r1Altwerte_DSTATE_a[4];       /* '<S20>/r+1 Altwerte' */
  real_T r1Altwerte_DSTATE_g[4];       /* '<S21>/r+1 Altwerte' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<Root>/Scope4' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_e;                    /* '<S17>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_h;                     /* '<S4>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_b;                    /* '<S8>/Scope1' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_k;                    /* '<S6>/Scope1' */

  boolean_T DelayInput1_DSTATE;        /* '<S22>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_c;      /* '<S23>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_o;      /* '<S24>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_ol;     /* '<S25>/Delay Input1' */
  DW_Subsystem_Geschwindigkeits_T Subsystem3;/* '<S17>/Subsystem3' */
  DW_Subsystem_Geschwindigkeits_T Subsystem2;/* '<S17>/Subsystem2' */
  DW_Subsystem_Geschwindigkeits_T Subsystem1;/* '<S17>/Subsystem1' */
  DW_Subsystem_Geschwindigkeits_T Subsystem;/* '<S17>/Subsystem' */
  DW_hl_Geschwindigkeitsregler_T vl;   /* '<S1>/vl' */
  DW_hl_Geschwindigkeitsregler_T hl;   /* '<S1>/hl' */
} DW_Geschwindigkeitsregler_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCE_Subsystem_Geschwindigkeit_T Subsystem3;/* '<S17>/Subsystem' */
  ZCE_Subsystem_Geschwindigkeit_T Subsystem2;/* '<S17>/Subsystem' */
  ZCE_Subsystem_Geschwindigkeit_T Subsystem1;/* '<S17>/Subsystem' */
  ZCE_Subsystem_Geschwindigkeit_T Subsystem;/* '<S17>/Subsystem' */
} PrevZCX_Geschwindigkeitsregle_T;

/* Parameters for system: '<S1>/hl' */
struct P_hl_Geschwindigkeitsregler_T_ {
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S9>/Digital Output'
                                        */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S10>/PWM'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S5>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S5>/Switch'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S5>/Switch1'
                                        */
};

/* Parameters for system: '<S17>/Subsystem' */
struct P_Subsystem_Geschwindigkeitsr_T_ {
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S26>/Constant1'
                                        */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S26>/Out1'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S26>/Delay'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S26>/Switch'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S26>/Constant'
                                        */
  uint16_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S26>/Delay'
                                        */
};

/* Parameters (auto storage) */
struct P_Geschwindigkeitsregler_T_ {
  real_T AB1[4];                       /* Variable: AB1
                                        * Referenced by:
                                        *   '<S18>/r+1 Altwerte'
                                        *   '<S19>/r+1 Altwerte'
                                        *   '<S20>/r+1 Altwerte'
                                        *   '<S21>/r+1 Altwerte'
                                        */
  real_T AB2[3];                       /* Variable: AB2
                                        * Referenced by:
                                        *   '<S18>/Zustandsvariablenfilter'
                                        *   '<S19>/Zustandsvariablenfilter'
                                        *   '<S20>/Zustandsvariablenfilter'
                                        *   '<S21>/Zustandsvariablenfilter'
                                        */
  real_T AD[9];                        /* Variable: AD
                                        * Referenced by:
                                        *   '<S18>/Zustandsvariablenfilter'
                                        *   '<S19>/Zustandsvariablenfilter'
                                        *   '<S20>/Zustandsvariablenfilter'
                                        *   '<S21>/Zustandsvariablenfilter'
                                        */
  real_T BD[12];                       /* Variable: BD
                                        * Referenced by:
                                        *   '<S18>/Zustandsvariablenfilter'
                                        *   '<S19>/Zustandsvariablenfilter'
                                        *   '<S20>/Zustandsvariablenfilter'
                                        *   '<S21>/Zustandsvariablenfilter'
                                        */
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S11>/Digital Output'
                                        */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S12>/PWM'
                                        */
  uint32_T DigitalOutput_pinNumber_n;  /* Mask Parameter: DigitalOutput_pinNumber_n
                                        * Referenced by: '<S15>/Digital Output'
                                        */
  uint32_T PWM_pinNumber_g;            /* Mask Parameter: PWM_pinNumber_g
                                        * Referenced by: '<S16>/PWM'
                                        */
  boolean_T DetectRisePositive_vinit;  /* Mask Parameter: DetectRisePositive_vinit
                                        * Referenced by: '<S22>/Delay Input1'
                                        */
  boolean_T DetectRisePositive1_vinit; /* Mask Parameter: DetectRisePositive1_vinit
                                        * Referenced by: '<S23>/Delay Input1'
                                        */
  boolean_T DetectRisePositive2_vinit; /* Mask Parameter: DetectRisePositive2_vinit
                                        * Referenced by: '<S24>/Delay Input1'
                                        */
  boolean_T DetectRisePositive3_vinit; /* Mask Parameter: DetectRisePositive3_vinit
                                        * Referenced by: '<S25>/Delay Input1'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S6>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S6>/Switch'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S6>/Switch1'
                                        */
  real_T Constant3_Value_k;            /* Expression: 0
                                        * Referenced by: '<S8>/Constant3'
                                        */
  real_T Constant2_Value_j;            /* Expression: 0
                                        * Referenced by: '<S8>/Constant2'
                                        */
  real_T Switch_Threshold_n;           /* Expression: 0
                                        * Referenced by: '<S8>/Switch'
                                        */
  real_T Switch1_Threshold_k;          /* Expression: 0
                                        * Referenced by: '<S8>/Switch1'
                                        */
  real_T powerMAX4_Value;              /* Expression: 0
                                        * Referenced by: '<S4>/powerMAX4'
                                        */
  real_T powerMAX3_Value;              /* Expression: 255
                                        * Referenced by: '<S4>/powerMAX3'
                                        */
  real_T powerMAX2_Value;              /* Expression: -1
                                        * Referenced by: '<S4>/powerMAX2'
                                        */
  real_T powerMAX1_Value;              /* Expression: 1
                                        * Referenced by: '<S4>/powerMAX1'
                                        */
  real_T enable_Value;                 /* Expression: 1
                                        * Referenced by: '<Root>/enable'
                                        */
  real_T direction1_Value;             /* Expression: 150
                                        * Referenced by: '<Root>/direction1'
                                        */
  real_T direction_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/direction'
                                        */
  real_T Constant1_Value;              /* Expression: 2.1
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 255
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Zustandsvariablenfilter_C[9]; /* Expression: eye(n)
                                        * Referenced by: '<S19>/Zustandsvariablenfilter'
                                        */
  real_T Zustandsvariablenfilter_D[12];/* Expression: zeros(n,r+1)
                                        * Referenced by: '<S19>/Zustandsvariablenfilter'
                                        */
  real_T powerMAX_Value;               /* Expression: 255
                                        * Referenced by: '<S4>/powerMAX'
                                        */
  real_T NMAX_Value;                   /* Expression: 2.1
                                        * Referenced by: '<S4>/NMAX'
                                        */
  real_T Switch_Threshold_b;           /* Expression: 0
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S4>/Delay'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S4>/Switch2'
                                        */
  real_T Switch1_Threshold_kd;         /* Expression: -25555555
                                        * Referenced by: '<S4>/Switch1'
                                        */
  real_T Zustandsvariablenfilter_C_m[9];/* Expression: eye(n)
                                         * Referenced by: '<S20>/Zustandsvariablenfilter'
                                         */
  real_T Zustandsvariablenfilter_D_l[12];/* Expression: zeros(n,r+1)
                                          * Referenced by: '<S20>/Zustandsvariablenfilter'
                                          */
  real_T Zustandsvariablenfilter_C_p[9];/* Expression: eye(n)
                                         * Referenced by: '<S21>/Zustandsvariablenfilter'
                                         */
  real_T Zustandsvariablenfilter_D_p[12];/* Expression: zeros(n,r+1)
                                          * Referenced by: '<S21>/Zustandsvariablenfilter'
                                          */
  real_T Zustandsvariablenfilter_C_l[9];/* Expression: eye(n)
                                         * Referenced by: '<S18>/Zustandsvariablenfilter'
                                         */
  real_T Zustandsvariablenfilter_D_a[12];/* Expression: zeros(n,r+1)
                                          * Referenced by: '<S18>/Zustandsvariablenfilter'
                                          */
  real_T Constant_Value_j;             /* Expression: 0
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T r1Altwerte_A[4];              /* Computed Parameter: r1Altwerte_A
                                        * Referenced by: '<S18>/r+1 Altwerte'
                                        */
  real_T r1Altwerte_C[16];             /* Computed Parameter: r1Altwerte_C
                                        * Referenced by: '<S18>/r+1 Altwerte'
                                        */
  real_T r1Altwerte_A_i[4];            /* Computed Parameter: r1Altwerte_A_i
                                        * Referenced by: '<S19>/r+1 Altwerte'
                                        */
  real_T r1Altwerte_C_b[16];           /* Computed Parameter: r1Altwerte_C_b
                                        * Referenced by: '<S19>/r+1 Altwerte'
                                        */
  real_T r1Altwerte_A_h[4];            /* Computed Parameter: r1Altwerte_A_h
                                        * Referenced by: '<S20>/r+1 Altwerte'
                                        */
  real_T r1Altwerte_C_j[16];           /* Computed Parameter: r1Altwerte_C_j
                                        * Referenced by: '<S20>/r+1 Altwerte'
                                        */
  real_T r1Altwerte_A_ix[4];           /* Computed Parameter: r1Altwerte_A_ix
                                        * Referenced by: '<S21>/r+1 Altwerte'
                                        */
  real_T r1Altwerte_C_js[16];          /* Computed Parameter: r1Altwerte_C_js
                                        * Referenced by: '<S21>/r+1 Altwerte'
                                        */
  uint32_T HL_p1;                      /* Computed Parameter: HL_p1
                                        * Referenced by: '<S17>/HL'
                                        */
  uint32_T HR_p1;                      /* Computed Parameter: HR_p1
                                        * Referenced by: '<S17>/HR'
                                        */
  uint32_T VR_p1;                      /* Computed Parameter: VR_p1
                                        * Referenced by: '<S17>/VR'
                                        */
  uint32_T VL_p1;                      /* Computed Parameter: VL_p1
                                        * Referenced by: '<S17>/VL'
                                        */
  uint16_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S4>/Delay'
                                        */
  boolean_T Constant_Value_k;          /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S30>/Constant'
                                        */
  boolean_T Constant_Value_f;          /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S31>/Constant'
                                        */
  boolean_T Constant_Value_o;          /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S32>/Constant'
                                        */
  boolean_T Constant_Value_fp;         /* Computed Parameter: Constant_Value_fp
                                        * Referenced by: '<S33>/Constant'
                                        */
  P_Subsystem_Geschwindigkeitsr_T Subsystem3;/* '<S17>/Subsystem3' */
  P_Subsystem_Geschwindigkeitsr_T Subsystem2;/* '<S17>/Subsystem2' */
  P_Subsystem_Geschwindigkeitsr_T Subsystem1;/* '<S17>/Subsystem1' */
  P_Subsystem_Geschwindigkeitsr_T Subsystem;/* '<S17>/Subsystem' */
  P_hl_Geschwindigkeitsregler_T vl;    /* '<S1>/vl' */
  P_hl_Geschwindigkeitsregler_T hl;    /* '<S1>/hl' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Geschwindigkeitsregle_T {
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
extern P_Geschwindigkeitsregler_T Geschwindigkeitsregler_P;

/* Block signals (auto storage) */
extern B_Geschwindigkeitsregler_T Geschwindigkeitsregler_B;

/* Block states (auto storage) */
extern DW_Geschwindigkeitsregler_T Geschwindigkeitsregler_DW;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_Geschwindigkeitsregle_T Geschwindigkeitsregler_PrevZCX;

/* Model entry point functions */
extern void Geschwindigkeitsregler_initialize(void);
extern void Geschwindigkeitsregler_step(void);
extern void Geschwindigkeitsregler_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Geschwindigkeitsregl_T *const Geschwindigkeitsregler_M;

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
 * '<Root>' : 'Geschwindigkeitsregler'
 * '<S1>'   : 'Geschwindigkeitsregler/Motorensteuerung'
 * '<S2>'   : 'Geschwindigkeitsregler/Subsystem'
 * '<S3>'   : 'Geschwindigkeitsregler/Subsystem Drehzahl_ALT'
 * '<S4>'   : 'Geschwindigkeitsregler/Subsystem1'
 * '<S5>'   : 'Geschwindigkeitsregler/Motorensteuerung/hl'
 * '<S6>'   : 'Geschwindigkeitsregler/Motorensteuerung/hr'
 * '<S7>'   : 'Geschwindigkeitsregler/Motorensteuerung/vl'
 * '<S8>'   : 'Geschwindigkeitsregler/Motorensteuerung/vr'
 * '<S9>'   : 'Geschwindigkeitsregler/Motorensteuerung/hl/M'
 * '<S10>'  : 'Geschwindigkeitsregler/Motorensteuerung/hl/PWM E'
 * '<S11>'  : 'Geschwindigkeitsregler/Motorensteuerung/hr/Digital Output M'
 * '<S12>'  : 'Geschwindigkeitsregler/Motorensteuerung/hr/PWM E'
 * '<S13>'  : 'Geschwindigkeitsregler/Motorensteuerung/vl/M'
 * '<S14>'  : 'Geschwindigkeitsregler/Motorensteuerung/vl/PWM E'
 * '<S15>'  : 'Geschwindigkeitsregler/Motorensteuerung/vr/Digital Output'
 * '<S16>'  : 'Geschwindigkeitsregler/Motorensteuerung/vr/PWM'
 * '<S17>'  : 'Geschwindigkeitsregler/Subsystem/Subsystem Drehzahl'
 * '<S18>'  : 'Geschwindigkeitsregler/Subsystem/v hl'
 * '<S19>'  : 'Geschwindigkeitsregler/Subsystem/v hr'
 * '<S20>'  : 'Geschwindigkeitsregler/Subsystem/v vl'
 * '<S21>'  : 'Geschwindigkeitsregler/Subsystem/v vr'
 * '<S22>'  : 'Geschwindigkeitsregler/Subsystem/Subsystem Drehzahl/Detect Rise Positive'
 * '<S23>'  : 'Geschwindigkeitsregler/Subsystem/Subsystem Drehzahl/Detect Rise Positive1'
 * '<S24>'  : 'Geschwindigkeitsregler/Subsystem/Subsystem Drehzahl/Detect Rise Positive2'
 * '<S25>'  : 'Geschwindigkeitsregler/Subsystem/Subsystem Drehzahl/Detect Rise Positive3'
 * '<S26>'  : 'Geschwindigkeitsregler/Subsystem/Subsystem Drehzahl/Subsystem'
 * '<S27>'  : 'Geschwindigkeitsregler/Subsystem/Subsystem Drehzahl/Subsystem1'
 * '<S28>'  : 'Geschwindigkeitsregler/Subsystem/Subsystem Drehzahl/Subsystem2'
 * '<S29>'  : 'Geschwindigkeitsregler/Subsystem/Subsystem Drehzahl/Subsystem3'
 * '<S30>'  : 'Geschwindigkeitsregler/Subsystem/Subsystem Drehzahl/Detect Rise Positive/Positive'
 * '<S31>'  : 'Geschwindigkeitsregler/Subsystem/Subsystem Drehzahl/Detect Rise Positive1/Positive'
 * '<S32>'  : 'Geschwindigkeitsregler/Subsystem/Subsystem Drehzahl/Detect Rise Positive2/Positive'
 * '<S33>'  : 'Geschwindigkeitsregler/Subsystem/Subsystem Drehzahl/Detect Rise Positive3/Positive'
 * '<S34>'  : 'Geschwindigkeitsregler/Subsystem Drehzahl_ALT/Detect Rise Positive'
 * '<S35>'  : 'Geschwindigkeitsregler/Subsystem Drehzahl_ALT/Detect Rise Positive1'
 * '<S36>'  : 'Geschwindigkeitsregler/Subsystem Drehzahl_ALT/Detect Rise Positive2'
 * '<S37>'  : 'Geschwindigkeitsregler/Subsystem Drehzahl_ALT/Detect Rise Positive3'
 * '<S38>'  : 'Geschwindigkeitsregler/Subsystem Drehzahl_ALT/Subsystem1'
 * '<S39>'  : 'Geschwindigkeitsregler/Subsystem Drehzahl_ALT/Subsystem2'
 * '<S40>'  : 'Geschwindigkeitsregler/Subsystem Drehzahl_ALT/Subsystem3'
 * '<S41>'  : 'Geschwindigkeitsregler/Subsystem Drehzahl_ALT/Subsystem7'
 * '<S42>'  : 'Geschwindigkeitsregler/Subsystem Drehzahl_ALT/Detect Rise Positive/Positive'
 * '<S43>'  : 'Geschwindigkeitsregler/Subsystem Drehzahl_ALT/Detect Rise Positive1/Positive'
 * '<S44>'  : 'Geschwindigkeitsregler/Subsystem Drehzahl_ALT/Detect Rise Positive2/Positive'
 * '<S45>'  : 'Geschwindigkeitsregler/Subsystem Drehzahl_ALT/Detect Rise Positive3/Positive'
 */
#endif                                 /* RTW_HEADER_Geschwindigkeitsregler_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
