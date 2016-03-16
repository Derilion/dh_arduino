/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test_motor.c
 *
 * Code generated for Simulink model 'test_motor'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 02 14:44:52 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test_motor.h"
#include "test_motor_private.h"
#include "test_motor_dt.h"

/* Block signals (auto storage) */
B_test_motor_T test_motor_B;

/* Block states (auto storage) */
DW_test_motor_T test_motor_DW;

/* Real-time model */
RT_MODEL_test_motor_T test_motor_M_;
RT_MODEL_test_motor_T *const test_motor_M = &test_motor_M_;

/* Model step function */
void test_motor_step(void)
{
  real_T tmp;
  uint8_T tmp_0;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator1' */
  test_motor_B.PulseGenerator1 = (test_motor_DW.clockTickCounter <
    test_motor_P.PulseGenerator1_Duty) && (test_motor_DW.clockTickCounter >= 0L)
    ? test_motor_P.PulseGenerator1_Amp : 0.0;
  if (test_motor_DW.clockTickCounter >= test_motor_P.PulseGenerator1_Period -
      1.0) {
    test_motor_DW.clockTickCounter = 0L;
  } else {
    test_motor_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator1' */

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant2'
   */
  if (test_motor_B.PulseGenerator1 > test_motor_P.Switch_Threshold) {
    tmp = test_motor_P.Constant_Value;
  } else {
    tmp = test_motor_P.Constant2_Value;
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
  MW_digitalWrite(test_motor_P.DigitalOutput_pinNumber, tmp_0);

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   */
  if (test_motor_B.PulseGenerator1 > test_motor_P.Switch1_Threshold) {
    tmp = test_motor_P.Constant4_Value;
  } else {
    tmp = test_motor_P.Constant3_Value;
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
  MW_analogWrite(test_motor_P.PWM_pinNumber, tmp_0);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [2.0s, 0.0s] */
    rtExtModeUpload(0, test_motor_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [2.0s, 0.0s] */
    if ((rtmGetTFinal(test_motor_M)!=-1) &&
        !((rtmGetTFinal(test_motor_M)-test_motor_M->Timing.taskTime0) >
          test_motor_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(test_motor_M, "Simulation finished");
    }

    if (rtmGetStopRequested(test_motor_M)) {
      rtmSetErrorStatus(test_motor_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  test_motor_M->Timing.taskTime0 =
    (++test_motor_M->Timing.clockTick0) * test_motor_M->Timing.stepSize0;
}

/* Model initialize function */
void test_motor_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)test_motor_M, 0,
                sizeof(RT_MODEL_test_motor_T));
  rtmSetTFinal(test_motor_M, 1000.0);
  test_motor_M->Timing.stepSize0 = 2.0;

  /* External mode info */
  test_motor_M->Sizes.checksums[0] = (264020774U);
  test_motor_M->Sizes.checksums[1] = (2949092035U);
  test_motor_M->Sizes.checksums[2] = (216050876U);
  test_motor_M->Sizes.checksums[3] = (1365563362U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    test_motor_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(test_motor_M->extModeInfo,
      &test_motor_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(test_motor_M->extModeInfo, test_motor_M->Sizes.checksums);
    rteiSetTPtr(test_motor_M->extModeInfo, rtmGetTPtr(test_motor_M));
  }

  /* block I/O */
  (void) memset(((void *) &test_motor_B), 0,
                sizeof(B_test_motor_T));

  /* states (dwork) */
  (void) memset((void *)&test_motor_DW, 0,
                sizeof(DW_test_motor_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    test_motor_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator1' */
  test_motor_DW.clockTickCounter = 0L;

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S1>/Digital Output' */
  MW_pinModeOutput(test_motor_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
  MW_pinModeOutput(test_motor_P.PWM_pinNumber);
}

/* Model terminate function */
void test_motor_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
