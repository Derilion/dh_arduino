/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AbstandSensorReferenz.h
 *
 * Code generated for Simulink model 'AbstandSensorReferenz'.
 *
 * Model version                  : 1.29
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 23 17:12:14 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AbstandSensorReferenz_h_
#define RTW_HEADER_AbstandSensorReferenz_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef AbstandSensorReferenz_COMMON_INCLUDES_
# define AbstandSensorReferenz_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "arduino_analoginput_lct.h"
#endif                                 /* AbstandSensorReferenz_COMMON_INCLUDES_ */

#include "AbstandSensorReferenz_types.h"

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

/* Block signals (auto storage) */
typedef struct {
  uint16_T Abstandssensor;             /* '<Root>/Abstandssensor' */
} B_AbstandSensorReferenz_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */
} DW_AbstandSensorReferenz_T;

/* Parameters (auto storage) */
struct P_AbstandSensorReferenz_T_ {
  uint32_T Abstandssensor_p1;          /* Computed Parameter: Abstandssensor_p1
                                        * Referenced by: '<Root>/Abstandssensor'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_AbstandSensorReferenz_T {
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
extern P_AbstandSensorReferenz_T AbstandSensorReferenz_P;

/* Block signals (auto storage) */
extern B_AbstandSensorReferenz_T AbstandSensorReferenz_B;

/* Block states (auto storage) */
extern DW_AbstandSensorReferenz_T AbstandSensorReferenz_DW;

/* Model entry point functions */
extern void AbstandSensorReferenz_initialize(void);
extern void AbstandSensorReferenz_step(void);
extern void AbstandSensorReferenz_terminate(void);

/* Real-time Model object */
extern RT_MODEL_AbstandSensorReferen_T *const AbstandSensorReferenz_M;

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
 * '<Root>' : 'AbstandSensorReferenz'
 */
#endif                                 /* RTW_HEADER_AbstandSensorReferenz_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
