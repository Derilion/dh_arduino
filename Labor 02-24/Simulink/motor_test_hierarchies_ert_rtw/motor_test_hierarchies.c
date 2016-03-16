/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motor_test_hierarchies.c
 *
 * Code generated for Simulink model 'motor_test_hierarchies'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 16 13:15:09 2016
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
  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S8>/Digital Output' */
  MW_pinModeOutput(localP->DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S9>/PWM' */
  MW_pinModeOutput(localP->PWM_pinNumber);
}

/*
 * Output and update for atomic system:
 *    '<S1>/hl'
 *    '<S1>/vl'
 */
void motor_test_hierarchies_hl(real_T rtu_enable, real_T rtu_power, real_T
  rtu_direction, B_hl_motor_test_hierarchies_T *localB,
  P_hl_motor_test_hierarchies_T *localP)
{
  real_T rtu_enable_0;
  uint8_T rtu_enable_1;

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant2'
   */
  if (rtu_enable > localP->Switch_Threshold) {
    rtu_enable_0 = rtu_direction;
  } else {
    rtu_enable_0 = localP->Constant2_Value;
  }

  /* End of Switch: '<S4>/Switch' */

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  if (rtu_enable_0 < 256.0) {
    if (rtu_enable_0 >= 0.0) {
      rtu_enable_1 = (uint8_T)rtu_enable_0;
    } else {
      rtu_enable_1 = 0U;
    }
  } else {
    rtu_enable_1 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S8>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S8>/Digital Output' */
  MW_digitalWrite(localP->DigitalOutput_pinNumber, rtu_enable_1);

  /* Switch: '<S4>/Switch1' incorporates:
   *  Constant: '<S4>/Constant3'
   *  DataTypeConversion: '<S9>/Data Type Conversion'
   */
  if (rtu_enable > localP->Switch1_Threshold) {
    /* DataTypeConversion: '<S9>/Data Type Conversion' */
    if (rtu_power < 256.0) {
      if (rtu_power >= 0.0) {
        localB->DataTypeConversion = (uint8_T)rtu_power;
      } else {
        localB->DataTypeConversion = 0U;
      }
    } else {
      localB->DataTypeConversion = MAX_uint8_T;
    }
  } else if (localP->Constant3_Value < 256.0) {
    /* DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
     *  Constant: '<S4>/Constant3'
     */
    if (localP->Constant3_Value >= 0.0) {
      localB->DataTypeConversion = (uint8_T)localP->Constant3_Value;
    } else {
      localB->DataTypeConversion = 0U;
    }
  } else {
    /* DataTypeConversion: '<S9>/Data Type Conversion' */
    localB->DataTypeConversion = MAX_uint8_T;
  }

  /* End of Switch: '<S4>/Switch1' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S9>/PWM' */
  MW_analogWrite(localP->PWM_pinNumber, localB->DataTypeConversion);
}

/* Model step function */
void motor_test_hierarchies_step(void)
{
  /* local block i/o variables */
  real_T rtb_FromWs;
  real_T tmp;
  uint8_T tmp_0;

  /* Constant: '<Root>/enable' */
  motor_test_hierarchies_B.enable = motor_test_hierarchies_P.enable_Value;

  /* FromWorkspace: '<S3>/FromWs' */
  {
    real_T *pDataValues = (real_T *)
      motor_test_hierarchies_DW.FromWs_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      motor_test_hierarchies_DW.FromWs_PWORK.TimePtr;
    int_T currTimeIndex = motor_test_hierarchies_DW.FromWs_IWORK.PrevIndex;
    real_T t = motor_test_hierarchies_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[9]) {
      currTimeIndex = 8;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    motor_test_hierarchies_DW.FromWs_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          rtb_FromWs = pDataValues[currTimeIndex];
        } else {
          rtb_FromWs = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        rtb_FromWs = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 10;
      }
    }
  }

  /* Outputs for Atomic SubSystem: '<S1>/hl' */

  /* Constant: '<Root>/direction' */
  motor_test_hierarchies_hl(motor_test_hierarchies_B.enable, rtb_FromWs,
    motor_test_hierarchies_P.direction_Value, &motor_test_hierarchies_B.hl,
    (P_hl_motor_test_hierarchies_T *)&motor_test_hierarchies_P.hl);

  /* End of Outputs for SubSystem: '<S1>/hl' */

  /* Outputs for Atomic SubSystem: '<S1>/hr' */
  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<Root>/direction'
   *  Constant: '<S5>/Constant2'
   */
  if (motor_test_hierarchies_B.enable >
      motor_test_hierarchies_P.Switch_Threshold) {
    tmp = motor_test_hierarchies_P.direction_Value;
  } else {
    tmp = motor_test_hierarchies_P.Constant2_Value;
  }

  /* End of Switch: '<S5>/Switch' */

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S10>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S10>/Digital Output' */
  MW_digitalWrite(motor_test_hierarchies_P.DigitalOutput_pinNumber, tmp_0);

  /* Switch: '<S5>/Switch1' incorporates:
   *  Constant: '<S5>/Constant3'
   *  DataTypeConversion: '<S11>/Data Type Conversion'
   */
  if (motor_test_hierarchies_B.enable >
      motor_test_hierarchies_P.Switch1_Threshold) {
    /* DataTypeConversion: '<S11>/Data Type Conversion' */
    if (rtb_FromWs < 256.0) {
      if (rtb_FromWs >= 0.0) {
        motor_test_hierarchies_B.DataTypeConversion_b = (uint8_T)rtb_FromWs;
      } else {
        motor_test_hierarchies_B.DataTypeConversion_b = 0U;
      }
    } else {
      motor_test_hierarchies_B.DataTypeConversion_b = MAX_uint8_T;
    }
  } else if (motor_test_hierarchies_P.Constant3_Value < 256.0) {
    /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
     *  Constant: '<S5>/Constant3'
     */
    if (motor_test_hierarchies_P.Constant3_Value >= 0.0) {
      motor_test_hierarchies_B.DataTypeConversion_b = (uint8_T)
        motor_test_hierarchies_P.Constant3_Value;
    } else {
      motor_test_hierarchies_B.DataTypeConversion_b = 0U;
    }
  } else {
    /* DataTypeConversion: '<S11>/Data Type Conversion' */
    motor_test_hierarchies_B.DataTypeConversion_b = MAX_uint8_T;
  }

  /* End of Switch: '<S5>/Switch1' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S11>/PWM' */
  MW_analogWrite(motor_test_hierarchies_P.PWM_pinNumber,
                 motor_test_hierarchies_B.DataTypeConversion_b);

  /* Outputs for Atomic SubSystem: '<S1>/vl' */

  /* Constant: '<Root>/direction' */
  motor_test_hierarchies_hl(motor_test_hierarchies_B.enable, rtb_FromWs,
    motor_test_hierarchies_P.direction_Value, &motor_test_hierarchies_B.vl,
    (P_hl_motor_test_hierarchies_T *)&motor_test_hierarchies_P.vl);

  /* End of Outputs for SubSystem: '<S1>/vl' */

  /* Outputs for Atomic SubSystem: '<S1>/vr' */
  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<Root>/direction'
   *  Constant: '<S7>/Constant2'
   */
  if (motor_test_hierarchies_B.enable >
      motor_test_hierarchies_P.Switch_Threshold_k) {
    tmp = motor_test_hierarchies_P.direction_Value;
  } else {
    tmp = motor_test_hierarchies_P.Constant2_Value_n;
  }

  /* End of Switch: '<S7>/Switch' */

  /* DataTypeConversion: '<S14>/Data Type Conversion' */
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S14>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S14>/Digital Output' */
  MW_digitalWrite(motor_test_hierarchies_P.DigitalOutput_pinNumber_a, tmp_0);

  /* Switch: '<S7>/Switch1' incorporates:
   *  Constant: '<S7>/Constant3'
   *  DataTypeConversion: '<S15>/Data Type Conversion'
   */
  if (motor_test_hierarchies_B.enable >
      motor_test_hierarchies_P.Switch1_Threshold_o) {
    /* DataTypeConversion: '<S15>/Data Type Conversion' */
    if (rtb_FromWs < 256.0) {
      if (rtb_FromWs >= 0.0) {
        motor_test_hierarchies_B.DataTypeConversion = (uint8_T)rtb_FromWs;
      } else {
        motor_test_hierarchies_B.DataTypeConversion = 0U;
      }
    } else {
      motor_test_hierarchies_B.DataTypeConversion = MAX_uint8_T;
    }
  } else if (motor_test_hierarchies_P.Constant3_Value_f < 256.0) {
    /* DataTypeConversion: '<S15>/Data Type Conversion' incorporates:
     *  Constant: '<S7>/Constant3'
     */
    if (motor_test_hierarchies_P.Constant3_Value_f >= 0.0) {
      motor_test_hierarchies_B.DataTypeConversion = (uint8_T)
        motor_test_hierarchies_P.Constant3_Value_f;
    } else {
      motor_test_hierarchies_B.DataTypeConversion = 0U;
    }
  } else {
    /* DataTypeConversion: '<S15>/Data Type Conversion' */
    motor_test_hierarchies_B.DataTypeConversion = MAX_uint8_T;
  }

  /* End of Switch: '<S7>/Switch1' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S15>/PWM' */
  MW_analogWrite(motor_test_hierarchies_P.PWM_pinNumber_n,
                 motor_test_hierarchies_B.DataTypeConversion);

  /* External mode */
  rtExtModeUploadCheckTrigger(2);

  {                                    /* Sample time: [0.0s, 0.0s] */
    rtExtModeUpload(0, motor_test_hierarchies_M->Timing.t[0]);
  }

  {                                    /* Sample time: [1.0s, 0.0s] */
    rtExtModeUpload(1, ((motor_test_hierarchies_M->Timing.clockTick1) ));
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(motor_test_hierarchies_M)!=-1) &&
        !((rtmGetTFinal(motor_test_hierarchies_M)-
           motor_test_hierarchies_M->Timing.t[0]) >
          motor_test_hierarchies_M->Timing.t[0] * (DBL_EPSILON))) {
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
  motor_test_hierarchies_M->Timing.t[0] =
    (++motor_test_hierarchies_M->Timing.clockTick0) *
    motor_test_hierarchies_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [1.0s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 1.0, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    motor_test_hierarchies_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void motor_test_hierarchies_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)motor_test_hierarchies_M, 0,
                sizeof(RT_MODEL_motor_test_hierarchi_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&motor_test_hierarchies_M->solverInfo,
                          &motor_test_hierarchies_M->Timing.simTimeStep);
    rtsiSetTPtr(&motor_test_hierarchies_M->solverInfo, &rtmGetTPtr
                (motor_test_hierarchies_M));
    rtsiSetStepSizePtr(&motor_test_hierarchies_M->solverInfo,
                       &motor_test_hierarchies_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&motor_test_hierarchies_M->solverInfo,
                          (&rtmGetErrorStatus(motor_test_hierarchies_M)));
    rtsiSetRTModelPtr(&motor_test_hierarchies_M->solverInfo,
                      motor_test_hierarchies_M);
  }

  rtsiSetSimTimeStep(&motor_test_hierarchies_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&motor_test_hierarchies_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(motor_test_hierarchies_M, &motor_test_hierarchies_M->Timing.tArray
             [0]);
  rtmSetTFinal(motor_test_hierarchies_M, 200.0);
  motor_test_hierarchies_M->Timing.stepSize0 = 1.0;

  /* External mode info */
  motor_test_hierarchies_M->Sizes.checksums[0] = (1277721381U);
  motor_test_hierarchies_M->Sizes.checksums[1] = (3056422068U);
  motor_test_hierarchies_M->Sizes.checksums[2] = (826496824U);
  motor_test_hierarchies_M->Sizes.checksums[3] = (767811506U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
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

  /* Start for FromWorkspace: '<S3>/FromWs' */
  {
    static real_T pTimeValues0[] = { 0.0, 1.0, 1.0, 2.0, 2.0, 4.0, 4.0, 6.0, 6.0,
      7.0 } ;

    static real_T pDataValues0[] = { 0.0, 128.0, 128.0, 128.0, 128.0, 255.0,
      255.0, 255.0, 255.0, 0.0 } ;

    motor_test_hierarchies_DW.FromWs_PWORK.TimePtr = (void *) pTimeValues0;
    motor_test_hierarchies_DW.FromWs_PWORK.DataPtr = (void *) pDataValues0;
    motor_test_hierarchies_DW.FromWs_IWORK.PrevIndex = 0;
  }

  /* Start for Atomic SubSystem: '<S1>/hl' */
  motor_test_hierarchies_hl_Start((P_hl_motor_test_hierarchies_T *)
    &motor_test_hierarchies_P.hl);

  /* End of Start for SubSystem: '<S1>/hl' */

  /* Start for Atomic SubSystem: '<S1>/hr' */
  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S10>/Digital Output' */
  MW_pinModeOutput(motor_test_hierarchies_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S11>/PWM' */
  MW_pinModeOutput(motor_test_hierarchies_P.PWM_pinNumber);

  /* Start for Atomic SubSystem: '<S1>/vl' */
  motor_test_hierarchies_hl_Start((P_hl_motor_test_hierarchies_T *)
    &motor_test_hierarchies_P.vl);

  /* End of Start for SubSystem: '<S1>/vl' */

  /* Start for Atomic SubSystem: '<S1>/vr' */
  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S14>/Digital Output' */
  MW_pinModeOutput(motor_test_hierarchies_P.DigitalOutput_pinNumber_a);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S15>/PWM' */
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
