/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motor_test_hierarchies.c
 *
 * Code generated for Simulink model 'motor_test_hierarchies'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 02 17:11:29 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "motor_test_hierarchies.h"
#include "motor_test_hierarchies_private.h"
#include "motor_test_hierarchies_dt.h"

/* Block signals (auto storage) */
B_motor_test_hierarchies_T motor_test_hierarchies_B;

/* Block states (auto storage) */
DW_motor_test_hierarchies_T motor_test_hierarchies_DW;

/* Real-time model */
RT_MODEL_motor_test_hierarchi_T motor_test_hierarchies_M_;
RT_MODEL_motor_test_hierarchi_T *const motor_test_hierarchies_M =
  &motor_test_hierarchies_M_;

/*
 * Start for atomic system:
 *    '<S1>/hl'
 *    '<S1>/vl'
 */
void motor_test_hierarchies_hl_Start(P_hl_motor_test_hierarchies_T *localP)
{
  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S6>/Digital Output' */
  MW_pinModeOutput(localP->DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S7>/PWM' */
  MW_pinModeOutput(localP->PWM_pinNumber);
}

/*
 * Output and update for atomic system:
 *    '<S1>/hl'
 *    '<S1>/vl'
 */
void motor_test_hierarchies_hl(real_T rtu_enable, real_T rtu_power, real_T
  rtu_direction, P_hl_motor_test_hierarchies_T *localP)
{
  real_T rtu_enable_0;
  uint8_T rtu_enable_1;

  /* Switch: '<S2>/Switch' incorporates:
   *  Constant: '<S2>/Constant2'
   */
  if (rtu_enable > localP->Switch_Threshold) {
    rtu_enable_0 = rtu_direction;
  } else {
    rtu_enable_0 = localP->Constant2_Value;
  }

  /* End of Switch: '<S2>/Switch' */

  /* DataTypeConversion: '<S6>/Data Type Conversion' */
  if (rtu_enable_0 < 256.0) {
    if (rtu_enable_0 >= 0.0) {
      rtu_enable_1 = (uint8_T)rtu_enable_0;
    } else {
      rtu_enable_1 = 0U;
    }
  } else {
    rtu_enable_1 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S6>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S6>/Digital Output' */
  MW_digitalWrite(localP->DigitalOutput_pinNumber, rtu_enable_1);

  /* Switch: '<S2>/Switch1' incorporates:
   *  Constant: '<S2>/Constant3'
   */
  if (rtu_enable > localP->Switch1_Threshold) {
    rtu_enable_0 = rtu_power;
  } else {
    rtu_enable_0 = localP->Constant3_Value;
  }

  /* End of Switch: '<S2>/Switch1' */

  /* DataTypeConversion: '<S7>/Data Type Conversion' */
  if (rtu_enable_0 < 256.0) {
    if (rtu_enable_0 >= 0.0) {
      rtu_enable_1 = (uint8_T)rtu_enable_0;
    } else {
      rtu_enable_1 = 0U;
    }
  } else {
    rtu_enable_1 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S7>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S7>/PWM' */
  MW_analogWrite(localP->PWM_pinNumber, rtu_enable_1);
}

/* Model step function */
void motor_test_hierarchies_step(void)
{
  real_T tmp;
  uint8_T tmp_0;

  /* Constant: '<Root>/enable' */
  motor_test_hierarchies_B.enable = motor_test_hierarchies_P.enable_Value;

  /* Outputs for Atomic SubSystem: '<S1>/hl' */

  /* Constant: '<Root>/fullspeed' incorporates:
   *  Constant: '<Root>/direction'
   */
  motor_test_hierarchies_hl(motor_test_hierarchies_B.enable,
    motor_test_hierarchies_P.fullspeed_Value,
    motor_test_hierarchies_P.direction_Value, (P_hl_motor_test_hierarchies_T *)
    &motor_test_hierarchies_P.hl);

  /* End of Outputs for SubSystem: '<S1>/hl' */

  /* Outputs for Atomic SubSystem: '<S1>/hr' */
  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<Root>/direction'
   *  Constant: '<S3>/Constant2'
   */
  if (motor_test_hierarchies_B.enable >
      motor_test_hierarchies_P.Switch_Threshold) {
    tmp = motor_test_hierarchies_P.direction_Value;
  } else {
    tmp = motor_test_hierarchies_P.Constant2_Value;
  }

  /* End of Switch: '<S3>/Switch' */

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S8>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S8>/Digital Output' */
  MW_digitalWrite(motor_test_hierarchies_P.DigitalOutput_pinNumber, tmp_0);

  /* Switch: '<S3>/Switch1' incorporates:
   *  Constant: '<Root>/fullspeed'
   *  Constant: '<S3>/Constant3'
   */
  if (motor_test_hierarchies_B.enable >
      motor_test_hierarchies_P.Switch1_Threshold) {
    tmp = motor_test_hierarchies_P.fullspeed_Value;
  } else {
    tmp = motor_test_hierarchies_P.Constant3_Value;
  }

  /* End of Switch: '<S3>/Switch1' */

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S9>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S9>/PWM' */
  MW_analogWrite(motor_test_hierarchies_P.PWM_pinNumber, tmp_0);

  /* Outputs for Atomic SubSystem: '<S1>/vl' */

  /* Constant: '<Root>/fullspeed' incorporates:
   *  Constant: '<Root>/direction'
   */
  motor_test_hierarchies_hl(motor_test_hierarchies_B.enable,
    motor_test_hierarchies_P.fullspeed_Value,
    motor_test_hierarchies_P.direction_Value, (P_hl_motor_test_hierarchies_T *)
    &motor_test_hierarchies_P.vl);

  /* End of Outputs for SubSystem: '<S1>/vl' */

  /* Outputs for Atomic SubSystem: '<S1>/vr' */
  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<Root>/direction'
   *  Constant: '<S5>/Constant2'
   */
  if (motor_test_hierarchies_B.enable >
      motor_test_hierarchies_P.Switch_Threshold_k) {
    tmp = motor_test_hierarchies_P.direction_Value;
  } else {
    tmp = motor_test_hierarchies_P.Constant2_Value_n;
  }

  /* End of Switch: '<S5>/Switch' */

  /* DataTypeConversion: '<S12>/Data Type Conversion' */
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S12>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S12>/Digital Output' */
  MW_digitalWrite(motor_test_hierarchies_P.DigitalOutput_pinNumber_a, tmp_0);

  /* Switch: '<S5>/Switch1' incorporates:
   *  Constant: '<Root>/fullspeed'
   *  Constant: '<S5>/Constant3'
   */
  if (motor_test_hierarchies_B.enable >
      motor_test_hierarchies_P.Switch1_Threshold_o) {
    tmp = motor_test_hierarchies_P.fullspeed_Value;
  } else {
    tmp = motor_test_hierarchies_P.Constant3_Value_f;
  }

  /* End of Switch: '<S5>/Switch1' */

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S13>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S13>/PWM' */
  MW_analogWrite(motor_test_hierarchies_P.PWM_pinNumber_n, tmp_0);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [4.0s, 0.0s] */
    rtExtModeUpload(0, motor_test_hierarchies_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [4.0s, 0.0s] */
    if ((rtmGetTFinal(motor_test_hierarchies_M)!=-1) &&
        !((rtmGetTFinal(motor_test_hierarchies_M)-
           motor_test_hierarchies_M->Timing.taskTime0) >
          motor_test_hierarchies_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(motor_test_hierarchies_M, "Simulation finished");
    }

    if (rtmGetStopRequested(motor_test_hierarchies_M)) {
      rtmSetErrorStatus(motor_test_hierarchies_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  motor_test_hierarchies_M->Timing.taskTime0 =
    (++motor_test_hierarchies_M->Timing.clockTick0) *
    motor_test_hierarchies_M->Timing.stepSize0;
}

/* Model initialize function */
void motor_test_hierarchies_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)motor_test_hierarchies_M, 0,
                sizeof(RT_MODEL_motor_test_hierarchi_T));
  rtmSetTFinal(motor_test_hierarchies_M, 200.0);
  motor_test_hierarchies_M->Timing.stepSize0 = 4.0;

  /* External mode info */
  motor_test_hierarchies_M->Sizes.checksums[0] = (3103162009U);
  motor_test_hierarchies_M->Sizes.checksums[1] = (1198544638U);
  motor_test_hierarchies_M->Sizes.checksums[2] = (2547898473U);
  motor_test_hierarchies_M->Sizes.checksums[3] = (911837978U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[13];
    motor_test_hierarchies_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(motor_test_hierarchies_M->extModeInfo,
      &motor_test_hierarchies_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(motor_test_hierarchies_M->extModeInfo,
                        motor_test_hierarchies_M->Sizes.checksums);
    rteiSetTPtr(motor_test_hierarchies_M->extModeInfo, rtmGetTPtr
                (motor_test_hierarchies_M));
  }

  /* block I/O */
  (void) memset(((void *) &motor_test_hierarchies_B), 0,
                sizeof(B_motor_test_hierarchies_T));

  /* states (dwork) */
  (void) memset((void *)&motor_test_hierarchies_DW, 0,
                sizeof(DW_motor_test_hierarchies_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    motor_test_hierarchies_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for Atomic SubSystem: '<S1>/hl' */
  motor_test_hierarchies_hl_Start((P_hl_motor_test_hierarchies_T *)
    &motor_test_hierarchies_P.hl);

  /* End of Start for SubSystem: '<S1>/hl' */

  /* Start for Atomic SubSystem: '<S1>/hr' */
  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S8>/Digital Output' */
  MW_pinModeOutput(motor_test_hierarchies_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S9>/PWM' */
  MW_pinModeOutput(motor_test_hierarchies_P.PWM_pinNumber);

  /* Start for Atomic SubSystem: '<S1>/vl' */
  motor_test_hierarchies_hl_Start((P_hl_motor_test_hierarchies_T *)
    &motor_test_hierarchies_P.vl);

  /* End of Start for SubSystem: '<S1>/vl' */

  /* Start for Atomic SubSystem: '<S1>/vr' */
  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S12>/Digital Output' */
  MW_pinModeOutput(motor_test_hierarchies_P.DigitalOutput_pinNumber_a);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S13>/PWM' */
  MW_pinModeOutput(motor_test_hierarchies_P.PWM_pinNumber_n);
}

/* Model terminate function */
void motor_test_hierarchies_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
