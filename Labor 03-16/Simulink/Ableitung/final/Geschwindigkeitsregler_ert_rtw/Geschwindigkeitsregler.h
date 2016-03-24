/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Geschwindigkeitsregler.h
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

#ifndef RTW_HEADER_Geschwindigkeitsregler_h_
#define RTW_HEADER_Geschwindigkeitsregler_h_
#include <math.h>
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
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals for system '<S1>/hl' */
typedef struct {
  uint8_T DataTypeConversion;          /* '<S16>/Data Type Conversion' */
} B_hl_Geschwindigkeitsregler_T;

/* Block signals for system '<S23>/Subsystem' */
typedef struct {
  real_T Add;                          /* '<S32>/Add' */
} B_Subsystem_Geschwindigkeitsr_T;

/* Block states (auto storage) for system '<S23>/Subsystem' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<S32>/Delay' */
  int8_T Subsystem_SubsysRanBC;        /* '<S23>/Subsystem' */
} DW_Subsystem_Geschwindigkeits_T;

/* Zero-crossing (trigger) state for system '<S23>/Subsystem' */
typedef struct {
  ZCSigState Subsystem_Trig_ZCE;       /* '<S23>/Subsystem' */
} ZCE_Subsystem_Geschwindigkeit_T;

/* Block signals (auto storage) */
typedef struct {
  real_T FromWs[2];                    /* '<S3>/FromWs' */
  real_T Zustandsvariablenfilter[3];   /* '<S24>/Zustandsvariablenfilter' */
  real_T IOut;                         /* '<S52>/IOut' */
  real_T Integrator;                   /* '<S52>/Integrator' */
  real_T Zustandsvariablenfilter_g[3]; /* '<S25>/Zustandsvariablenfilter' */
  real_T Add;                          /* '<S8>/Add' */
  real_T IOut_p;                       /* '<S53>/IOut' */
  real_T Integrator_n;                 /* '<S53>/Integrator' */
  real_T Saturate;                     /* '<S53>/Saturate' */
  real_T Zustandsvariablenfilter_a[3]; /* '<S26>/Zustandsvariablenfilter' */
  real_T IOut_d;                       /* '<S54>/IOut' */
  real_T Integrator_i;                 /* '<S54>/Integrator' */
  real_T Zustandsvariablenfilter_d[3]; /* '<S27>/Zustandsvariablenfilter' */
  real_T IOut_dm;                      /* '<S55>/IOut' */
  real_T Integrator_i4;                /* '<S55>/Integrator' */
  real_T r1Altwerte[4];                /* '<S24>/r+1 Altwerte' */
  real_T r1Altwerte_n[4];              /* '<S25>/r+1 Altwerte' */
  real_T r1Altwerte_o[4];              /* '<S26>/r+1 Altwerte' */
  real_T r1Altwerte_h[4];              /* '<S27>/r+1 Altwerte' */
  uint8_T DataTypeConversion;          /* '<S22>/Data Type Conversion' */
  uint8_T DataTypeConversion_i;        /* '<S18>/Data Type Conversion' */
  B_Subsystem_Geschwindigkeitsr_T Subsystem3;/* '<S23>/Subsystem3' */
  B_Subsystem_Geschwindigkeitsr_T Subsystem2;/* '<S23>/Subsystem2' */
  B_Subsystem_Geschwindigkeitsr_T Subsystem1;/* '<S23>/Subsystem1' */
  B_Subsystem_Geschwindigkeitsr_T Subsystem;/* '<S23>/Subsystem' */
  B_hl_Geschwindigkeitsregler_T vl;    /* '<S1>/vl' */
  B_hl_Geschwindigkeitsregler_T hl;    /* '<S1>/hl' */
} B_Geschwindigkeitsregler_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Zustandsvariablenfilter_DSTATE[3];/* '<S24>/Zustandsvariablenfilter' */
  real_T Integrator_DSTATE;            /* '<S52>/Integrator' */
  real_T Zustandsvariablenfilter_DSTAT_n[3];/* '<S25>/Zustandsvariablenfilter' */
  real_T Integrator_DSTATE_g;          /* '<S53>/Integrator' */
  real_T Zustandsvariablenfilter_DSTAT_o[3];/* '<S26>/Zustandsvariablenfilter' */
  real_T Integrator_DSTATE_k;          /* '<S54>/Integrator' */
  real_T Zustandsvariablenfilter_DSTAT_c[3];/* '<S27>/Zustandsvariablenfilter' */
  real_T Integrator_DSTATE_gl;         /* '<S55>/Integrator' */
  real_T r1Altwerte_DSTATE[4];         /* '<S24>/r+1 Altwerte' */
  real_T r1Altwerte_DSTATE_o[4];       /* '<S25>/r+1 Altwerte' */
  real_T r1Altwerte_DSTATE_a[4];       /* '<S26>/r+1 Altwerte' */
  real_T r1Altwerte_DSTATE_g[4];       /* '<S27>/r+1 Altwerte' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWs_PWORK;                      /* '<S3>/FromWs' */

  struct {
    void *LoggedData[4];
  } Scope_PWORK;                       /* '<S8>/Scope' */

  struct {
    int_T PrevIndex;
  } FromWs_IWORK;                      /* '<S3>/FromWs' */

  boolean_T DelayInput1_DSTATE;        /* '<S28>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_c;      /* '<S29>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_o;      /* '<S30>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_ol;     /* '<S31>/Delay Input1' */
  DW_Subsystem_Geschwindigkeits_T Subsystem3;/* '<S23>/Subsystem3' */
  DW_Subsystem_Geschwindigkeits_T Subsystem2;/* '<S23>/Subsystem2' */
  DW_Subsystem_Geschwindigkeits_T Subsystem1;/* '<S23>/Subsystem1' */
  DW_Subsystem_Geschwindigkeits_T Subsystem;/* '<S23>/Subsystem' */
} DW_Geschwindigkeitsregler_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCE_Subsystem_Geschwindigkeit_T Subsystem3;/* '<S23>/Subsystem' */
  ZCE_Subsystem_Geschwindigkeit_T Subsystem2;/* '<S23>/Subsystem' */
  ZCE_Subsystem_Geschwindigkeit_T Subsystem1;/* '<S23>/Subsystem' */
  ZCE_Subsystem_Geschwindigkeit_T Subsystem;/* '<S23>/Subsystem' */
} PrevZCX_Geschwindigkeitsregle_T;

/* Parameters for system: '<S1>/hl' */
struct P_hl_Geschwindigkeitsregler_T_ {
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S15>/Digital Output'
                                        */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S16>/PWM'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S11>/Constant2'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S11>/Switch'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S11>/Constant3'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S11>/Switch1'
                                        */
};

/* Parameters for system: '<S23>/Subsystem' */
struct P_Subsystem_Geschwindigkeitsr_T_ {
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S32>/Constant1'
                                        */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S32>/Out1'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0
                                        * Referenced by: '<S32>/Delay'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S32>/Switch'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S32>/Constant'
                                        */
  uint16_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S32>/Delay'
                                        */
};

/* Parameters (auto storage) */
struct P_Geschwindigkeitsregler_T_ {
  real_T AB1[4];                       /* Variable: AB1
                                        * Referenced by:
                                        *   '<S24>/r+1 Altwerte'
                                        *   '<S25>/r+1 Altwerte'
                                        *   '<S26>/r+1 Altwerte'
                                        *   '<S27>/r+1 Altwerte'
                                        */
  real_T AB2[3];                       /* Variable: AB2
                                        * Referenced by:
                                        *   '<S24>/Zustandsvariablenfilter'
                                        *   '<S25>/Zustandsvariablenfilter'
                                        *   '<S26>/Zustandsvariablenfilter'
                                        *   '<S27>/Zustandsvariablenfilter'
                                        */
  real_T AD[9];                        /* Variable: AD
                                        * Referenced by:
                                        *   '<S24>/Zustandsvariablenfilter'
                                        *   '<S25>/Zustandsvariablenfilter'
                                        *   '<S26>/Zustandsvariablenfilter'
                                        *   '<S27>/Zustandsvariablenfilter'
                                        */
  real_T BD[12];                       /* Variable: BD
                                        * Referenced by:
                                        *   '<S24>/Zustandsvariablenfilter'
                                        *   '<S25>/Zustandsvariablenfilter'
                                        *   '<S26>/Zustandsvariablenfilter'
                                        *   '<S27>/Zustandsvariablenfilter'
                                        */
  real_T DiscretePIDController_LowerSatu;/* Mask Parameter: DiscretePIDController_LowerSatu
                                          * Referenced by: '<S52>/Saturate'
                                          */
  real_T DiscretePIDController_LowerSa_p;/* Mask Parameter: DiscretePIDController_LowerSa_p
                                          * Referenced by: '<S53>/Saturate'
                                          */
  real_T DiscretePIDController_LowerS_pn;/* Mask Parameter: DiscretePIDController_LowerS_pn
                                          * Referenced by: '<S54>/Saturate'
                                          */
  real_T DiscretePIDController_LowerSa_e;/* Mask Parameter: DiscretePIDController_LowerSa_e
                                          * Referenced by: '<S55>/Saturate'
                                          */
  real_T DiscretePIDController_UpperSatu;/* Mask Parameter: DiscretePIDController_UpperSatu
                                          * Referenced by: '<S52>/Saturate'
                                          */
  real_T DiscretePIDController_UpperSa_b;/* Mask Parameter: DiscretePIDController_UpperSa_b
                                          * Referenced by: '<S53>/Saturate'
                                          */
  real_T DiscretePIDController_UpperSa_o;/* Mask Parameter: DiscretePIDController_UpperSa_o
                                          * Referenced by: '<S54>/Saturate'
                                          */
  real_T DiscretePIDController_UpperSa_l;/* Mask Parameter: DiscretePIDController_UpperSa_l
                                          * Referenced by: '<S55>/Saturate'
                                          */
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S17>/Digital Output'
                                        */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S18>/PWM'
                                        */
  uint32_T DigitalOutput_pinNumber_n;  /* Mask Parameter: DigitalOutput_pinNumber_n
                                        * Referenced by: '<S21>/Digital Output'
                                        */
  uint32_T PWM_pinNumber_g;            /* Mask Parameter: PWM_pinNumber_g
                                        * Referenced by: '<S22>/PWM'
                                        */
  boolean_T DetectRisePositive_vinit;  /* Mask Parameter: DetectRisePositive_vinit
                                        * Referenced by: '<S28>/Delay Input1'
                                        */
  boolean_T DetectRisePositive1_vinit; /* Mask Parameter: DetectRisePositive1_vinit
                                        * Referenced by: '<S29>/Delay Input1'
                                        */
  boolean_T DetectRisePositive2_vinit; /* Mask Parameter: DetectRisePositive2_vinit
                                        * Referenced by: '<S30>/Delay Input1'
                                        */
  boolean_T DetectRisePositive3_vinit; /* Mask Parameter: DetectRisePositive3_vinit
                                        * Referenced by: '<S31>/Delay Input1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S12>/Constant2'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S12>/Switch'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S12>/Constant3'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S12>/Switch1'
                                        */
  real_T Constant2_Value_j;            /* Expression: 0
                                        * Referenced by: '<S14>/Constant2'
                                        */
  real_T Switch_Threshold_n;           /* Expression: 0
                                        * Referenced by: '<S14>/Switch'
                                        */
  real_T Constant3_Value_k;            /* Expression: 0
                                        * Referenced by: '<S14>/Constant3'
                                        */
  real_T Switch1_Threshold_k;          /* Expression: 0
                                        * Referenced by: '<S14>/Switch1'
                                        */
  real_T enable_Value;                 /* Expression: 1
                                        * Referenced by: '<Root>/enable'
                                        */
  real_T Constant1_Value;              /* Expression: 25
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 100
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Zustandsvariablenfilter_C[9]; /* Expression: eye(n)
                                        * Referenced by: '<S24>/Zustandsvariablenfilter'
                                        */
  real_T Zustandsvariablenfilter_D[12];/* Expression: zeros(n,r+1)
                                        * Referenced by: '<S24>/Zustandsvariablenfilter'
                                        */
  real_T Constant2_Value_n;            /* Expression: 4
                                        * Referenced by: '<S7>/Constant2'
                                        */
  real_T Constant3_Value_i;            /* Expression: 10
                                        * Referenced by: '<S7>/Constant3'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S52>/Integrator'
                                        */
  real_T Integrator_IC;                /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S52>/Integrator'
                                        */
  real_T direction_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/direction'
                                        */
  real_T maxClicksproSec_Value;        /* Expression: 25
                                        * Referenced by: '<S8>/maxClicksproSec'
                                        */
  real_T prozent_Value;                /* Expression: 100
                                        * Referenced by: '<S8>/prozent'
                                        */
  real_T Zustandsvariablenfilter_C_n[9];/* Expression: eye(n)
                                         * Referenced by: '<S25>/Zustandsvariablenfilter'
                                         */
  real_T Zustandsvariablenfilter_D_m[12];/* Expression: zeros(n,r+1)
                                          * Referenced by: '<S25>/Zustandsvariablenfilter'
                                          */
  real_T p_Value;                      /* Expression: 4
                                        * Referenced by: '<S8>/p'
                                        */
  real_T i_Value;                      /* Expression: 10
                                        * Referenced by: '<S8>/i'
                                        */
  real_T Integrator_gainval_o;         /* Computed Parameter: Integrator_gainval_o
                                        * Referenced by: '<S53>/Integrator'
                                        */
  real_T Integrator_IC_f;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S53>/Integrator'
                                        */
  real_T Constant1_Value_c;            /* Expression: 25
                                        * Referenced by: '<S9>/Constant1'
                                        */
  real_T Constant_Value_f;             /* Expression: 100
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Zustandsvariablenfilter_C_m[9];/* Expression: eye(n)
                                         * Referenced by: '<S26>/Zustandsvariablenfilter'
                                         */
  real_T Zustandsvariablenfilter_D_l[12];/* Expression: zeros(n,r+1)
                                          * Referenced by: '<S26>/Zustandsvariablenfilter'
                                          */
  real_T Constant2_Value_l;            /* Expression: 4
                                        * Referenced by: '<S9>/Constant2'
                                        */
  real_T Constant3_Value_m;            /* Expression: 10
                                        * Referenced by: '<S9>/Constant3'
                                        */
  real_T Integrator_gainval_k;         /* Computed Parameter: Integrator_gainval_k
                                        * Referenced by: '<S54>/Integrator'
                                        */
  real_T Integrator_IC_n;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S54>/Integrator'
                                        */
  real_T Constant1_Value_e;            /* Expression: 25
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T Constant_Value_o;             /* Expression: 100
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Zustandsvariablenfilter_C_p[9];/* Expression: eye(n)
                                         * Referenced by: '<S27>/Zustandsvariablenfilter'
                                         */
  real_T Zustandsvariablenfilter_D_p[12];/* Expression: zeros(n,r+1)
                                          * Referenced by: '<S27>/Zustandsvariablenfilter'
                                          */
  real_T Constant2_Value_i;            /* Expression: 4
                                        * Referenced by: '<S10>/Constant2'
                                        */
  real_T Constant3_Value_e;            /* Expression: 10
                                        * Referenced by: '<S10>/Constant3'
                                        */
  real_T Integrator_gainval_n;         /* Computed Parameter: Integrator_gainval_n
                                        * Referenced by: '<S55>/Integrator'
                                        */
  real_T Integrator_IC_i;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S55>/Integrator'
                                        */
  real_T Constant_Value_j;             /* Expression: 0
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T r1Altwerte_A[4];              /* Computed Parameter: r1Altwerte_A
                                        * Referenced by: '<S24>/r+1 Altwerte'
                                        */
  real_T r1Altwerte_C[16];             /* Computed Parameter: r1Altwerte_C
                                        * Referenced by: '<S24>/r+1 Altwerte'
                                        */
  real_T r1Altwerte_A_i[4];            /* Computed Parameter: r1Altwerte_A_i
                                        * Referenced by: '<S25>/r+1 Altwerte'
                                        */
  real_T r1Altwerte_C_b[16];           /* Computed Parameter: r1Altwerte_C_b
                                        * Referenced by: '<S25>/r+1 Altwerte'
                                        */
  real_T r1Altwerte_A_h[4];            /* Computed Parameter: r1Altwerte_A_h
                                        * Referenced by: '<S26>/r+1 Altwerte'
                                        */
  real_T r1Altwerte_C_j[16];           /* Computed Parameter: r1Altwerte_C_j
                                        * Referenced by: '<S26>/r+1 Altwerte'
                                        */
  real_T r1Altwerte_A_ix[4];           /* Computed Parameter: r1Altwerte_A_ix
                                        * Referenced by: '<S27>/r+1 Altwerte'
                                        */
  real_T r1Altwerte_C_js[16];          /* Computed Parameter: r1Altwerte_C_js
                                        * Referenced by: '<S27>/r+1 Altwerte'
                                        */
  uint32_T HL_p1;                      /* Computed Parameter: HL_p1
                                        * Referenced by: '<S23>/HL'
                                        */
  uint32_T HR_p1;                      /* Computed Parameter: HR_p1
                                        * Referenced by: '<S23>/HR'
                                        */
  uint32_T VR_p1;                      /* Computed Parameter: VR_p1
                                        * Referenced by: '<S23>/VR'
                                        */
  uint32_T VL_p1;                      /* Computed Parameter: VL_p1
                                        * Referenced by: '<S23>/VL'
                                        */
  boolean_T Constant_Value_k;          /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S36>/Constant'
                                        */
  boolean_T Constant_Value_fr;         /* Computed Parameter: Constant_Value_fr
                                        * Referenced by: '<S37>/Constant'
                                        */
  boolean_T Constant_Value_od;         /* Computed Parameter: Constant_Value_od
                                        * Referenced by: '<S38>/Constant'
                                        */
  boolean_T Constant_Value_fp;         /* Computed Parameter: Constant_Value_fp
                                        * Referenced by: '<S39>/Constant'
                                        */
  P_Subsystem_Geschwindigkeitsr_T Subsystem3;/* '<S23>/Subsystem3' */
  P_Subsystem_Geschwindigkeitsr_T Subsystem2;/* '<S23>/Subsystem2' */
  P_Subsystem_Geschwindigkeitsr_T Subsystem1;/* '<S23>/Subsystem1' */
  P_Subsystem_Geschwindigkeitsr_T Subsystem;/* '<S23>/Subsystem' */
  P_hl_Geschwindigkeitsregler_T vl;    /* '<S1>/vl' */
  P_hl_Geschwindigkeitsregler_T hl;    /* '<S1>/hl' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Geschwindigkeitsregle_T {
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
 * '<S2>'   : 'Geschwindigkeitsregler/Signal Builder'
 * '<S3>'   : 'Geschwindigkeitsregler/Signal Builder1'
 * '<S4>'   : 'Geschwindigkeitsregler/Subsystem'
 * '<S5>'   : 'Geschwindigkeitsregler/Subsystem Drehzahl_ALT'
 * '<S6>'   : 'Geschwindigkeitsregler/Subsystem1'
 * '<S7>'   : 'Geschwindigkeitsregler/regler_hl'
 * '<S8>'   : 'Geschwindigkeitsregler/regler_hr'
 * '<S9>'   : 'Geschwindigkeitsregler/regler_vl'
 * '<S10>'  : 'Geschwindigkeitsregler/regler_vr'
 * '<S11>'  : 'Geschwindigkeitsregler/Motorensteuerung/hl'
 * '<S12>'  : 'Geschwindigkeitsregler/Motorensteuerung/hr'
 * '<S13>'  : 'Geschwindigkeitsregler/Motorensteuerung/vl'
 * '<S14>'  : 'Geschwindigkeitsregler/Motorensteuerung/vr'
 * '<S15>'  : 'Geschwindigkeitsregler/Motorensteuerung/hl/M'
 * '<S16>'  : 'Geschwindigkeitsregler/Motorensteuerung/hl/PWM E'
 * '<S17>'  : 'Geschwindigkeitsregler/Motorensteuerung/hr/Digital Output M'
 * '<S18>'  : 'Geschwindigkeitsregler/Motorensteuerung/hr/PWM E'
 * '<S19>'  : 'Geschwindigkeitsregler/Motorensteuerung/vl/M'
 * '<S20>'  : 'Geschwindigkeitsregler/Motorensteuerung/vl/PWM E'
 * '<S21>'  : 'Geschwindigkeitsregler/Motorensteuerung/vr/Digital Output'
 * '<S22>'  : 'Geschwindigkeitsregler/Motorensteuerung/vr/PWM'
 * '<S23>'  : 'Geschwindigkeitsregler/Subsystem/Subsystem Drehzahl'
 * '<S24>'  : 'Geschwindigkeitsregler/Subsystem/v hl'
 * '<S25>'  : 'Geschwindigkeitsregler/Subsystem/v hr'
 * '<S26>'  : 'Geschwindigkeitsregler/Subsystem/v vl'
 * '<S27>'  : 'Geschwindigkeitsregler/Subsystem/v vr'
 * '<S28>'  : 'Geschwindigkeitsregler/Subsystem/Subsystem Drehzahl/Detect Rise Positive'
 * '<S29>'  : 'Geschwindigkeitsregler/Subsystem/Subsystem Drehzahl/Detect Rise Positive1'
 * '<S30>'  : 'Geschwindigkeitsregler/Subsystem/Subsystem Drehzahl/Detect Rise Positive2'
 * '<S31>'  : 'Geschwindigkeitsregler/Subsystem/Subsystem Drehzahl/Detect Rise Positive3'
 * '<S32>'  : 'Geschwindigkeitsregler/Subsystem/Subsystem Drehzahl/Subsystem'
 * '<S33>'  : 'Geschwindigkeitsregler/Subsystem/Subsystem Drehzahl/Subsystem1'
 * '<S34>'  : 'Geschwindigkeitsregler/Subsystem/Subsystem Drehzahl/Subsystem2'
 * '<S35>'  : 'Geschwindigkeitsregler/Subsystem/Subsystem Drehzahl/Subsystem3'
 * '<S36>'  : 'Geschwindigkeitsregler/Subsystem/Subsystem Drehzahl/Detect Rise Positive/Positive'
 * '<S37>'  : 'Geschwindigkeitsregler/Subsystem/Subsystem Drehzahl/Detect Rise Positive1/Positive'
 * '<S38>'  : 'Geschwindigkeitsregler/Subsystem/Subsystem Drehzahl/Detect Rise Positive2/Positive'
 * '<S39>'  : 'Geschwindigkeitsregler/Subsystem/Subsystem Drehzahl/Detect Rise Positive3/Positive'
 * '<S40>'  : 'Geschwindigkeitsregler/Subsystem Drehzahl_ALT/Detect Rise Positive'
 * '<S41>'  : 'Geschwindigkeitsregler/Subsystem Drehzahl_ALT/Detect Rise Positive1'
 * '<S42>'  : 'Geschwindigkeitsregler/Subsystem Drehzahl_ALT/Detect Rise Positive2'
 * '<S43>'  : 'Geschwindigkeitsregler/Subsystem Drehzahl_ALT/Detect Rise Positive3'
 * '<S44>'  : 'Geschwindigkeitsregler/Subsystem Drehzahl_ALT/Subsystem1'
 * '<S45>'  : 'Geschwindigkeitsregler/Subsystem Drehzahl_ALT/Subsystem2'
 * '<S46>'  : 'Geschwindigkeitsregler/Subsystem Drehzahl_ALT/Subsystem3'
 * '<S47>'  : 'Geschwindigkeitsregler/Subsystem Drehzahl_ALT/Subsystem7'
 * '<S48>'  : 'Geschwindigkeitsregler/Subsystem Drehzahl_ALT/Detect Rise Positive/Positive'
 * '<S49>'  : 'Geschwindigkeitsregler/Subsystem Drehzahl_ALT/Detect Rise Positive1/Positive'
 * '<S50>'  : 'Geschwindigkeitsregler/Subsystem Drehzahl_ALT/Detect Rise Positive2/Positive'
 * '<S51>'  : 'Geschwindigkeitsregler/Subsystem Drehzahl_ALT/Detect Rise Positive3/Positive'
 * '<S52>'  : 'Geschwindigkeitsregler/regler_hl/Discrete PID Controller'
 * '<S53>'  : 'Geschwindigkeitsregler/regler_hr/Discrete PID Controller'
 * '<S54>'  : 'Geschwindigkeitsregler/regler_vl/Discrete PID Controller'
 * '<S55>'  : 'Geschwindigkeitsregler/regler_vr/Discrete PID Controller'
 */
#endif                                 /* RTW_HEADER_Geschwindigkeitsregler_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
