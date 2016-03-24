/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Abstandsregler.h
 *
 * Code generated for Simulink model 'Abstandsregler'.
 *
 * Model version                  : 1.27
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 23 16:57:04 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Abstandsregler_h_
#define RTW_HEADER_Abstandsregler_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef Abstandsregler_COMMON_INCLUDES_
# define Abstandsregler_COMMON_INCLUDES_
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
#include "arduino_analoginput_lct.h"
#include "arduino_digitalinput_lct.h"
#endif                                 /* Abstandsregler_COMMON_INCLUDES_ */

#include "Abstandsregler_types.h"

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

/* Block signals for system '<S22>/Subsystem' */
typedef struct {
  real_T Add;                          /* '<S31>/Add' */
} B_Subsystem_Abstandsregler_T;

/* Block states (auto storage) for system '<S22>/Subsystem' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<S31>/Delay' */
  int8_T Subsystem_SubsysRanBC;        /* '<S22>/Subsystem' */
} DW_Subsystem_Abstandsregler_T;

/* Zero-crossing (trigger) state for system '<S22>/Subsystem' */
typedef struct {
  ZCSigState Subsystem_Trig_ZCE;       /* '<S22>/Subsystem' */
} ZCE_Subsystem_Abstandsregler_T;

/* Block signals (auto storage) */
typedef struct {
  real_T Zustandsvariablenfilter_m[3]; /* '<S26>/Zustandsvariablenfilter' */
  real_T Add;                          /* '<S1>/Add' */
  real_T Integrator;                   /* '<S9>/Integrator' */
  real_T Saturate;                     /* '<S9>/Saturate' */
  real_T Integrator_i;                 /* '<S39>/Integrator' */
  real_T Zustandsvariablenfilter[3];   /* '<S24>/Zustandsvariablenfilter' */
  real_T Add_d;                        /* '<S6>/Add' */
  real_T Integrator_n;                 /* '<S40>/Integrator' */
  real_T Saturate_f;                   /* '<S40>/Saturate' */
  real_T Integrator_is;                /* '<S41>/Integrator' */
  real_T Integrator_i4;                /* '<S42>/Integrator' */
  real_T r1Altwerte[4];                /* '<S23>/r+1 Altwerte' */
  real_T r1Altwerte_n[4];              /* '<S24>/r+1 Altwerte' */
  real_T r1Altwerte_o[4];              /* '<S25>/r+1 Altwerte' */
  real_T r1Altwerte_h[4];              /* '<S26>/r+1 Altwerte' */
  uint32_T Gain;                       /* '<S1>/Gain' */
  B_Subsystem_Abstandsregler_T Subsystem3;/* '<S22>/Subsystem3' */
  B_Subsystem_Abstandsregler_T Subsystem2;/* '<S22>/Subsystem2' */
  B_Subsystem_Abstandsregler_T Subsystem1;/* '<S22>/Subsystem1' */
  B_Subsystem_Abstandsregler_T Subsystem;/* '<S22>/Subsystem' */
} B_Abstandsregler_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S9>/Integrator' */
  real_T Zustandsvariablenfilter_DSTATE[3];/* '<S23>/Zustandsvariablenfilter' */
  real_T Integrator_DSTATE_o;          /* '<S39>/Integrator' */
  real_T Zustandsvariablenfilter_DSTAT_n[3];/* '<S24>/Zustandsvariablenfilter' */
  real_T Integrator_DSTATE_g;          /* '<S40>/Integrator' */
  real_T Zustandsvariablenfilter_DSTAT_o[3];/* '<S25>/Zustandsvariablenfilter' */
  real_T Integrator_DSTATE_k;          /* '<S41>/Integrator' */
  real_T Zustandsvariablenfilter_DSTAT_c[3];/* '<S26>/Zustandsvariablenfilter' */
  real_T Integrator_DSTATE_gl;         /* '<S42>/Integrator' */
  real_T r1Altwerte_DSTATE[4];         /* '<S23>/r+1 Altwerte' */
  real_T r1Altwerte_DSTATE_o[4];       /* '<S24>/r+1 Altwerte' */
  real_T r1Altwerte_DSTATE_a[4];       /* '<S25>/r+1 Altwerte' */
  real_T r1Altwerte_DSTATE_g[4];       /* '<S26>/r+1 Altwerte' */
  struct {
    void *LoggedData[3];
  } Scope_PWORK;                       /* '<S1>/Scope' */

  struct {
    void *LoggedData[4];
  } Scope_PWORK_c;                     /* '<S6>/Scope' */

  boolean_T DelayInput1_DSTATE;        /* '<S27>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_c;      /* '<S28>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_o;      /* '<S29>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_ol;     /* '<S30>/Delay Input1' */
  DW_Subsystem_Abstandsregler_T Subsystem3;/* '<S22>/Subsystem3' */
  DW_Subsystem_Abstandsregler_T Subsystem2;/* '<S22>/Subsystem2' */
  DW_Subsystem_Abstandsregler_T Subsystem1;/* '<S22>/Subsystem1' */
  DW_Subsystem_Abstandsregler_T Subsystem;/* '<S22>/Subsystem' */
} DW_Abstandsregler_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCE_Subsystem_Abstandsregler_T Subsystem3;/* '<S22>/Subsystem' */
  ZCE_Subsystem_Abstandsregler_T Subsystem2;/* '<S22>/Subsystem' */
  ZCE_Subsystem_Abstandsregler_T Subsystem1;/* '<S22>/Subsystem' */
  ZCE_Subsystem_Abstandsregler_T Subsystem;/* '<S22>/Subsystem' */
} PrevZCX_Abstandsregler_T;

/* Parameters for system: '<S2>/hl' */
struct P_hl_Abstandsregler_T_ {
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S14>/Digital Output'
                                        */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S15>/PWM'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S10>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S10>/Constant2'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S10>/Switch'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S10>/Switch1'
                                        */
};

/* Parameters for system: '<S22>/Subsystem' */
struct P_Subsystem_Abstandsregler_T_ {
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S31>/Constant1'
                                        */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S31>/Out1'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S31>/Delay'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S31>/Switch'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S31>/Constant'
                                        */
  uint16_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S31>/Delay'
                                        */
};

/* Parameters (auto storage) */
struct P_Abstandsregler_T_ {
  real_T AB1[4];                       /* Variable: AB1
                                        * Referenced by:
                                        *   '<S23>/r+1 Altwerte'
                                        *   '<S24>/r+1 Altwerte'
                                        *   '<S25>/r+1 Altwerte'
                                        *   '<S26>/r+1 Altwerte'
                                        */
  real_T AB2[3];                       /* Variable: AB2
                                        * Referenced by:
                                        *   '<S23>/Zustandsvariablenfilter'
                                        *   '<S24>/Zustandsvariablenfilter'
                                        *   '<S25>/Zustandsvariablenfilter'
                                        *   '<S26>/Zustandsvariablenfilter'
                                        */
  real_T AD[9];                        /* Variable: AD
                                        * Referenced by:
                                        *   '<S23>/Zustandsvariablenfilter'
                                        *   '<S24>/Zustandsvariablenfilter'
                                        *   '<S25>/Zustandsvariablenfilter'
                                        *   '<S26>/Zustandsvariablenfilter'
                                        */
  real_T BD[12];                       /* Variable: BD
                                        * Referenced by:
                                        *   '<S23>/Zustandsvariablenfilter'
                                        *   '<S24>/Zustandsvariablenfilter'
                                        *   '<S25>/Zustandsvariablenfilter'
                                        *   '<S26>/Zustandsvariablenfilter'
                                        */
  real_T DiscretePIDController_LowerSatu;/* Mask Parameter: DiscretePIDController_LowerSatu
                                          * Referenced by: '<S9>/Saturate'
                                          */
  real_T DiscretePIDController_LowerSa_i;/* Mask Parameter: DiscretePIDController_LowerSa_i
                                          * Referenced by: '<S39>/Saturate'
                                          */
  real_T DiscretePIDController_LowerSa_p;/* Mask Parameter: DiscretePIDController_LowerSa_p
                                          * Referenced by: '<S40>/Saturate'
                                          */
  real_T DiscretePIDController_LowerS_pn;/* Mask Parameter: DiscretePIDController_LowerS_pn
                                          * Referenced by: '<S41>/Saturate'
                                          */
  real_T DiscretePIDController_LowerSa_e;/* Mask Parameter: DiscretePIDController_LowerSa_e
                                          * Referenced by: '<S42>/Saturate'
                                          */
  real_T DiscretePIDController_UpperSatu;/* Mask Parameter: DiscretePIDController_UpperSatu
                                          * Referenced by: '<S9>/Saturate'
                                          */
  real_T DiscretePIDController_UpperSa_m;/* Mask Parameter: DiscretePIDController_UpperSa_m
                                          * Referenced by: '<S39>/Saturate'
                                          */
  real_T DiscretePIDController_UpperSa_b;/* Mask Parameter: DiscretePIDController_UpperSa_b
                                          * Referenced by: '<S40>/Saturate'
                                          */
  real_T DiscretePIDController_UpperSa_o;/* Mask Parameter: DiscretePIDController_UpperSa_o
                                          * Referenced by: '<S41>/Saturate'
                                          */
  real_T DiscretePIDController_UpperSa_l;/* Mask Parameter: DiscretePIDController_UpperSa_l
                                          * Referenced by: '<S42>/Saturate'
                                          */
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S16>/Digital Output'
                                        */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S17>/PWM'
                                        */
  uint32_T DigitalOutput_pinNumber_n;  /* Mask Parameter: DigitalOutput_pinNumber_n
                                        * Referenced by: '<S20>/Digital Output'
                                        */
  uint32_T PWM_pinNumber_g;            /* Mask Parameter: PWM_pinNumber_g
                                        * Referenced by: '<S21>/PWM'
                                        */
  boolean_T DetectRisePositive_vinit;  /* Mask Parameter: DetectRisePositive_vinit
                                        * Referenced by: '<S27>/Delay Input1'
                                        */
  boolean_T DetectRisePositive1_vinit; /* Mask Parameter: DetectRisePositive1_vinit
                                        * Referenced by: '<S28>/Delay Input1'
                                        */
  boolean_T DetectRisePositive2_vinit; /* Mask Parameter: DetectRisePositive2_vinit
                                        * Referenced by: '<S29>/Delay Input1'
                                        */
  boolean_T DetectRisePositive3_vinit; /* Mask Parameter: DetectRisePositive3_vinit
                                        * Referenced by: '<S30>/Delay Input1'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S11>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S11>/Constant2'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S11>/Switch'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S11>/Switch1'
                                        */
  real_T Constant3_Value_k;            /* Expression: 0
                                        * Referenced by: '<S13>/Constant3'
                                        */
  real_T Constant2_Value_j;            /* Expression: 0
                                        * Referenced by: '<S13>/Constant2'
                                        */
  real_T Switch_Threshold_n;           /* Expression: 0
                                        * Referenced by: '<S13>/Switch'
                                        */
  real_T Switch1_Threshold_k;          /* Expression: 0
                                        * Referenced by: '<S13>/Switch1'
                                        */
  real_T enable_Value;                 /* Expression: 1
                                        * Referenced by: '<Root>/enable'
                                        */
  real_T Constant_Value;               /* Expression: 30
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 10
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant2_Value_jd;           /* Expression: 1
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S9>/Integrator'
                                        */
  real_T Integrator_IC;                /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S9>/Integrator'
                                        */
  real_T Constant1_Value_b;            /* Expression: 25
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Constant_Value_g;             /* Expression: 100
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Zustandsvariablenfilter_C[9]; /* Expression: eye(n)
                                        * Referenced by: '<S23>/Zustandsvariablenfilter'
                                        */
  real_T Zustandsvariablenfilter_D[12];/* Expression: zeros(n,r+1)
                                        * Referenced by: '<S23>/Zustandsvariablenfilter'
                                        */
  real_T Constant2_Value_n;            /* Expression: 4
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T Constant3_Value_i;            /* Expression: 10
                                        * Referenced by: '<S5>/Constant3'
                                        */
  real_T Integrator_gainval_p;         /* Computed Parameter: Integrator_gainval_p
                                        * Referenced by: '<S39>/Integrator'
                                        */
  real_T Integrator_IC_p;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S39>/Integrator'
                                        */
  real_T direction_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/direction'
                                        */
  real_T maxClicksproSec_Value;        /* Expression: 25
                                        * Referenced by: '<S6>/maxClicksproSec'
                                        */
  real_T prozent_Value;                /* Expression: 100
                                        * Referenced by: '<S6>/prozent'
                                        */
  real_T Zustandsvariablenfilter_C_n[9];/* Expression: eye(n)
                                         * Referenced by: '<S24>/Zustandsvariablenfilter'
                                         */
  real_T Zustandsvariablenfilter_D_m[12];/* Expression: zeros(n,r+1)
                                          * Referenced by: '<S24>/Zustandsvariablenfilter'
                                          */
  real_T p_Value;                      /* Expression: 4
                                        * Referenced by: '<S6>/p'
                                        */
  real_T i_Value;                      /* Expression: 10
                                        * Referenced by: '<S6>/i'
                                        */
  real_T Integrator_gainval_o;         /* Computed Parameter: Integrator_gainval_o
                                        * Referenced by: '<S40>/Integrator'
                                        */
  real_T Integrator_IC_f;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S40>/Integrator'
                                        */
  real_T Constant1_Value_c;            /* Expression: 25
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Constant_Value_f;             /* Expression: 100
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Zustandsvariablenfilter_C_m[9];/* Expression: eye(n)
                                         * Referenced by: '<S25>/Zustandsvariablenfilter'
                                         */
  real_T Zustandsvariablenfilter_D_l[12];/* Expression: zeros(n,r+1)
                                          * Referenced by: '<S25>/Zustandsvariablenfilter'
                                          */
  real_T Constant2_Value_l;            /* Expression: 4
                                        * Referenced by: '<S7>/Constant2'
                                        */
  real_T Constant3_Value_m;            /* Expression: 10
                                        * Referenced by: '<S7>/Constant3'
                                        */
  real_T Integrator_gainval_k;         /* Computed Parameter: Integrator_gainval_k
                                        * Referenced by: '<S41>/Integrator'
                                        */
  real_T Integrator_IC_n;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S41>/Integrator'
                                        */
  real_T Constant1_Value_e;            /* Expression: 25
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real_T Constant_Value_o;             /* Expression: 100
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Zustandsvariablenfilter_C_p[9];/* Expression: eye(n)
                                         * Referenced by: '<S26>/Zustandsvariablenfilter'
                                         */
  real_T Zustandsvariablenfilter_D_p[12];/* Expression: zeros(n,r+1)
                                          * Referenced by: '<S26>/Zustandsvariablenfilter'
                                          */
  real_T Constant2_Value_i;            /* Expression: 4
                                        * Referenced by: '<S8>/Constant2'
                                        */
  real_T Constant3_Value_e;            /* Expression: 10
                                        * Referenced by: '<S8>/Constant3'
                                        */
  real_T Integrator_gainval_n;         /* Computed Parameter: Integrator_gainval_n
                                        * Referenced by: '<S42>/Integrator'
                                        */
  real_T Integrator_IC_i;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S42>/Integrator'
                                        */
  real_T Constant_Value_j;             /* Expression: 0
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T r1Altwerte_A[4];              /* Computed Parameter: r1Altwerte_A
                                        * Referenced by: '<S23>/r+1 Altwerte'
                                        */
  real_T r1Altwerte_C[16];             /* Computed Parameter: r1Altwerte_C
                                        * Referenced by: '<S23>/r+1 Altwerte'
                                        */
  real_T r1Altwerte_A_i[4];            /* Computed Parameter: r1Altwerte_A_i
                                        * Referenced by: '<S24>/r+1 Altwerte'
                                        */
  real_T r1Altwerte_C_b[16];           /* Computed Parameter: r1Altwerte_C_b
                                        * Referenced by: '<S24>/r+1 Altwerte'
                                        */
  real_T r1Altwerte_A_h[4];            /* Computed Parameter: r1Altwerte_A_h
                                        * Referenced by: '<S25>/r+1 Altwerte'
                                        */
  real_T r1Altwerte_C_j[16];           /* Computed Parameter: r1Altwerte_C_j
                                        * Referenced by: '<S25>/r+1 Altwerte'
                                        */
  real_T r1Altwerte_A_ix[4];           /* Computed Parameter: r1Altwerte_A_ix
                                        * Referenced by: '<S26>/r+1 Altwerte'
                                        */
  real_T r1Altwerte_C_js[16];          /* Computed Parameter: r1Altwerte_C_js
                                        * Referenced by: '<S26>/r+1 Altwerte'
                                        */
  uint32_T Abstandssensor_p1;          /* Computed Parameter: Abstandssensor_p1
                                        * Referenced by: '<S1>/Abstandssensor'
                                        */
  uint32_T HL_p1;                      /* Computed Parameter: HL_p1
                                        * Referenced by: '<S22>/HL'
                                        */
  uint32_T HR_p1;                      /* Computed Parameter: HR_p1
                                        * Referenced by: '<S22>/HR'
                                        */
  uint32_T VR_p1;                      /* Computed Parameter: VR_p1
                                        * Referenced by: '<S22>/VR'
                                        */
  uint32_T VL_p1;                      /* Computed Parameter: VL_p1
                                        * Referenced by: '<S22>/VL'
                                        */
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S1>/Gain'
                                        */
  boolean_T Constant_Value_k;          /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S35>/Constant'
                                        */
  boolean_T Constant_Value_fr;         /* Computed Parameter: Constant_Value_fr
                                        * Referenced by: '<S36>/Constant'
                                        */
  boolean_T Constant_Value_od;         /* Computed Parameter: Constant_Value_od
                                        * Referenced by: '<S37>/Constant'
                                        */
  boolean_T Constant_Value_fp;         /* Computed Parameter: Constant_Value_fp
                                        * Referenced by: '<S38>/Constant'
                                        */
  P_Subsystem_Abstandsregler_T Subsystem3;/* '<S22>/Subsystem3' */
  P_Subsystem_Abstandsregler_T Subsystem2;/* '<S22>/Subsystem2' */
  P_Subsystem_Abstandsregler_T Subsystem1;/* '<S22>/Subsystem1' */
  P_Subsystem_Abstandsregler_T Subsystem;/* '<S22>/Subsystem' */
  P_hl_Abstandsregler_T vl;            /* '<S2>/vl' */
  P_hl_Abstandsregler_T hl;            /* '<S2>/hl' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Abstandsregler_T {
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
extern P_Abstandsregler_T Abstandsregler_P;

/* Block signals (auto storage) */
extern B_Abstandsregler_T Abstandsregler_B;

/* Block states (auto storage) */
extern DW_Abstandsregler_T Abstandsregler_DW;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_Abstandsregler_T Abstandsregler_PrevZCX;

/* Model entry point functions */
extern void Abstandsregler_initialize(void);
extern void Abstandsregler_step(void);
extern void Abstandsregler_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Abstandsregler_T *const Abstandsregler_M;

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
 * '<Root>' : 'Abstandsregler'
 * '<S1>'   : 'Abstandsregler/Abstandsregler 30 cm'
 * '<S2>'   : 'Abstandsregler/Motorensteuerung'
 * '<S3>'   : 'Abstandsregler/Signal Builder1'
 * '<S4>'   : 'Abstandsregler/Subsystem'
 * '<S5>'   : 'Abstandsregler/regler_hl'
 * '<S6>'   : 'Abstandsregler/regler_hr'
 * '<S7>'   : 'Abstandsregler/regler_vl'
 * '<S8>'   : 'Abstandsregler/regler_vr'
 * '<S9>'   : 'Abstandsregler/Abstandsregler 30 cm/Discrete PID Controller'
 * '<S10>'  : 'Abstandsregler/Motorensteuerung/hl'
 * '<S11>'  : 'Abstandsregler/Motorensteuerung/hr'
 * '<S12>'  : 'Abstandsregler/Motorensteuerung/vl'
 * '<S13>'  : 'Abstandsregler/Motorensteuerung/vr'
 * '<S14>'  : 'Abstandsregler/Motorensteuerung/hl/M'
 * '<S15>'  : 'Abstandsregler/Motorensteuerung/hl/PWM E'
 * '<S16>'  : 'Abstandsregler/Motorensteuerung/hr/Digital Output M'
 * '<S17>'  : 'Abstandsregler/Motorensteuerung/hr/PWM E'
 * '<S18>'  : 'Abstandsregler/Motorensteuerung/vl/M'
 * '<S19>'  : 'Abstandsregler/Motorensteuerung/vl/PWM E'
 * '<S20>'  : 'Abstandsregler/Motorensteuerung/vr/Digital Output'
 * '<S21>'  : 'Abstandsregler/Motorensteuerung/vr/PWM'
 * '<S22>'  : 'Abstandsregler/Subsystem/Subsystem Drehzahl'
 * '<S23>'  : 'Abstandsregler/Subsystem/v hl'
 * '<S24>'  : 'Abstandsregler/Subsystem/v hr'
 * '<S25>'  : 'Abstandsregler/Subsystem/v vl'
 * '<S26>'  : 'Abstandsregler/Subsystem/v vr'
 * '<S27>'  : 'Abstandsregler/Subsystem/Subsystem Drehzahl/Detect Rise Positive'
 * '<S28>'  : 'Abstandsregler/Subsystem/Subsystem Drehzahl/Detect Rise Positive1'
 * '<S29>'  : 'Abstandsregler/Subsystem/Subsystem Drehzahl/Detect Rise Positive2'
 * '<S30>'  : 'Abstandsregler/Subsystem/Subsystem Drehzahl/Detect Rise Positive3'
 * '<S31>'  : 'Abstandsregler/Subsystem/Subsystem Drehzahl/Subsystem'
 * '<S32>'  : 'Abstandsregler/Subsystem/Subsystem Drehzahl/Subsystem1'
 * '<S33>'  : 'Abstandsregler/Subsystem/Subsystem Drehzahl/Subsystem2'
 * '<S34>'  : 'Abstandsregler/Subsystem/Subsystem Drehzahl/Subsystem3'
 * '<S35>'  : 'Abstandsregler/Subsystem/Subsystem Drehzahl/Detect Rise Positive/Positive'
 * '<S36>'  : 'Abstandsregler/Subsystem/Subsystem Drehzahl/Detect Rise Positive1/Positive'
 * '<S37>'  : 'Abstandsregler/Subsystem/Subsystem Drehzahl/Detect Rise Positive2/Positive'
 * '<S38>'  : 'Abstandsregler/Subsystem/Subsystem Drehzahl/Detect Rise Positive3/Positive'
 * '<S39>'  : 'Abstandsregler/regler_hl/Discrete PID Controller'
 * '<S40>'  : 'Abstandsregler/regler_hr/Discrete PID Controller'
 * '<S41>'  : 'Abstandsregler/regler_vl/Discrete PID Controller'
 * '<S42>'  : 'Abstandsregler/regler_vr/Discrete PID Controller'
 */
#endif                                 /* RTW_HEADER_Abstandsregler_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
