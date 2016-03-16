/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled2.c
 *
 * Code generated for Simulink model 'untitled2'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 02 14:23:54 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled2.h"
#include "untitled2_private.h"
#include "untitled2_dt.h"

/* Block signals (auto storage) */
B_untitled2_T untitled2_B;

/* Block states (auto storage) */
DW_untitled2_T untitled2_DW;

/* Real-time model */
RT_MODEL_untitled2_T untitled2_M_;
RT_MODEL_untitled2_T *const untitled2_M = &untitled2_M_;

/* Model step function */
void untitled2_step(void)
{
  real_T tmp;
  uint8_T tmp_0;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator1' */
  untitled2_B.PulseGenerator1 = (untitled2_DW.clockTickCounter <
    untitled2_P.PulseGenerator1_Duty) && (untitled2_DW.clockTickCounter >= 0L) ?
    untitled2_P.PulseGenerator1_Amp : 0.0;
  if (untitled2_DW.clockTickCounter >= untitled2_P.PulseGenerator1_Period - 1.0)
  {
    untitled2_DW.clockTickCounter = 0L;
  } else {
    untitled2_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator1' */

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant2'
   */
  if (untitled2_B.PulseGenerator1 > untitled2_P.Switch_Threshold) {
    tmp = untitled2_P.Constant_Value;
  } else {
    tmp = untitled2_P.Constant2_Value;
  }

  /* End of Switch: '<Root>/Switch' */

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S1>/Digital Output' */
  MW_digitalWrite(untitled2_P.DigitalOutput_pinNumber, tmp_0);

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   */
  if (untitled2_B.PulseGenerator1 > untitled2_P.Switch1_Threshold) {
    tmp = untitled2_P.Constant4_Value;
  } else {
    tmp = untitled2_P.Constant3_Value;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S2>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
  MW_analogWrite(untitled2_P.PWM_pinNumber, tmp_0);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [2.0s, 0.0s] */
    rtExtModeUpload(0, untitled2_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [2.0s, 0.0s] */
    if ((rtmGetTFinal(untitled2_M)!=-1) &&
        !((rtmGetTFinal(untitled2_M)-untitled2_M->Timing.taskTime0) >
          untitled2_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(untitled2_M, "Simulation finished");
    }

    if (rtmGetStopRequested(untitled2_M)) {
      rtmSetErrorStatus(untitled2_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled2_M->Timing.taskTime0 =
    (++untitled2_M->Timing.clockTick0) * untitled2_M->Timing.stepSize0;
}

/* Model initialize function */
void untitled2_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)untitled2_M, 0,
                sizeof(RT_MODEL_untitled2_T));
  rtmSetTFinal(untitled2_M, 1000.0);
  untitled2_M->Timing.stepSize0 = 2.0;

  /* External mode info */
  untitled2_M->Sizes.checksums[0] = (1585571519U);
  untitled2_M->Sizes.checksums[1] = (646146860U);
  untitled2_M->Sizes.checksums[2] = (4052890089U);
  untitled2_M->Sizes.checksums[3] = (3624953326U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    untitled2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled2_M->extModeInfo,
      &untitled2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled2_M->extModeInfo, untitled2_M->Sizes.checksums);
    rteiSetTPtr(untitled2_M->extModeInfo, rtmGetTPtr(untitled2_M));
  }

  /* block I/O */
  (void) memset(((void *) &untitled2_B), 0,
                sizeof(B_untitled2_T));

  /* states (dwork) */
  (void) memset((void *)&untitled2_DW, 0,
                sizeof(DW_untitled2_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    untitled2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator1' */
  untitled2_DW.clockTickCounter = 0L;

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S1>/Digital Output' */
  MW_pinModeOutput(untitled2_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
  MW_pinModeOutput(untitled2_P.PWM_pinNumber);
}

/* Model terminate function */
void untitled2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
