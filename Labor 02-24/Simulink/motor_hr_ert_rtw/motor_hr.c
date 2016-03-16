/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motor_hr.c
 *
 * Code generated for Simulink model 'motor_hr'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 02 15:32:22 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "motor_hr.h"
#include "motor_hr_private.h"
#include "motor_hr_dt.h"

/* Block states (auto storage) */
DW_motor_hr_T motor_hr_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_motor_hr_T motor_hr_U;

/* Real-time model */
RT_MODEL_motor_hr_T motor_hr_M_;
RT_MODEL_motor_hr_T *const motor_hr_M = &motor_hr_M_;

/* Model step function */
void motor_hr_step(void)
{
  real_T tmp;
  uint8_T tmp_0;

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Inport: '<Root>/direction'
   *  Inport: '<Root>/enable'
   */
  if (motor_hr_U.enable > motor_hr_P.Switch_Threshold) {
    tmp = motor_hr_U.direction;
  } else {
    tmp = motor_hr_P.Constant2_Value;
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
  MW_digitalWrite(motor_hr_P.DigitalOutput_pinNumber, tmp_0);

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Inport: '<Root>/enable'
   *  Inport: '<Root>/power'
   */
  if (motor_hr_U.enable > motor_hr_P.Switch1_Threshold) {
    tmp = motor_hr_U.power;
  } else {
    tmp = motor_hr_P.Constant3_Value;
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
  MW_analogWrite(motor_hr_P.PWM_pinNumber, tmp_0);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [20.0s, 0.0s] */
    rtExtModeUpload(0, motor_hr_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [20.0s, 0.0s] */
    if ((rtmGetTFinal(motor_hr_M)!=-1) &&
        !((rtmGetTFinal(motor_hr_M)-motor_hr_M->Timing.taskTime0) >
          motor_hr_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(motor_hr_M, "Simulation finished");
    }

    if (rtmGetStopRequested(motor_hr_M)) {
      rtmSetErrorStatus(motor_hr_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  motor_hr_M->Timing.taskTime0 =
    (++motor_hr_M->Timing.clockTick0) * motor_hr_M->Timing.stepSize0;
}

/* Model initialize function */
void motor_hr_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)motor_hr_M, 0,
                sizeof(RT_MODEL_motor_hr_T));
  rtmSetTFinal(motor_hr_M, 1000.0);
  motor_hr_M->Timing.stepSize0 = 20.0;

  /* External mode info */
  motor_hr_M->Sizes.checksums[0] = (822641153U);
  motor_hr_M->Sizes.checksums[1] = (2911569967U);
  motor_hr_M->Sizes.checksums[2] = (108929926U);
  motor_hr_M->Sizes.checksums[3] = (297514658U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    motor_hr_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(motor_hr_M->extModeInfo,
      &motor_hr_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(motor_hr_M->extModeInfo, motor_hr_M->Sizes.checksums);
    rteiSetTPtr(motor_hr_M->extModeInfo, rtmGetTPtr(motor_hr_M));
  }

  /* states (dwork) */
  (void) memset((void *)&motor_hr_DW, 0,
                sizeof(DW_motor_hr_T));

  /* external inputs */
  (void) memset((void *)&motor_hr_U, 0,
                sizeof(ExtU_motor_hr_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    motor_hr_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S1>/Digital Output' */
  MW_pinModeOutput(motor_hr_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
  MW_pinModeOutput(motor_hr_P.PWM_pinNumber);
}

/* Model terminate function */
void motor_hr_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
