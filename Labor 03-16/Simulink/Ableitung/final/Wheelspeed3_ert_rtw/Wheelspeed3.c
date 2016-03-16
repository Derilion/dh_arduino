/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Wheelspeed3.c
 *
 * Code generated for Simulink model 'Wheelspeed3'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 16 14:12:39 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Wheelspeed3.h"
#include "Wheelspeed3_private.h"
#include "Wheelspeed3_dt.h"

/* Block signals (auto storage) */
B_Wheelspeed3_T Wheelspeed3_B;

/* Block states (auto storage) */
DW_Wheelspeed3_T Wheelspeed3_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Wheelspeed3_T Wheelspeed3_PrevZCX;

/* Real-time model */
RT_MODEL_Wheelspeed3_T Wheelspeed3_M_;
RT_MODEL_Wheelspeed3_T *const Wheelspeed3_M = &Wheelspeed3_M_;

/*
 * Start for atomic system:
 *    '<S5>/hl'
 *    '<S5>/vl'
 */
void Wheelspeed3_hl_Start(P_hl_Wheelspeed3_T *localP)
{
  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S19>/Digital Output' */
  MW_pinModeOutput(localP->DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S20>/PWM' */
  MW_pinModeOutput(localP->PWM_pinNumber);
}

/*
 * Output and update for atomic system:
 *    '<S5>/hl'
 *    '<S5>/vl'
 */
void Wheelspeed3_hl(real_T rtu_enable, real_T rtu_power, real_T rtu_direction,
                    B_hl_Wheelspeed3_T *localB, P_hl_Wheelspeed3_T *localP)
{
  real_T rtu_enable_0;
  uint8_T rtu_enable_1;

  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S15>/Constant2'
   */
  if (rtu_enable > localP->Switch_Threshold) {
    rtu_enable_0 = rtu_direction;
  } else {
    rtu_enable_0 = localP->Constant2_Value;
  }

  /* End of Switch: '<S15>/Switch' */

  /* DataTypeConversion: '<S19>/Data Type Conversion' */
  if (rtu_enable_0 < 256.0) {
    if (rtu_enable_0 >= 0.0) {
      rtu_enable_1 = (uint8_T)rtu_enable_0;
    } else {
      rtu_enable_1 = 0U;
    }
  } else {
    rtu_enable_1 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S19>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S19>/Digital Output' */
  MW_digitalWrite(localP->DigitalOutput_pinNumber, rtu_enable_1);

  /* Switch: '<S15>/Switch1' incorporates:
   *  Constant: '<S15>/Constant3'
   *  DataTypeConversion: '<S20>/Data Type Conversion'
   */
  if (rtu_enable > localP->Switch1_Threshold) {
    /* DataTypeConversion: '<S20>/Data Type Conversion' */
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
    /* DataTypeConversion: '<S20>/Data Type Conversion' incorporates:
     *  Constant: '<S15>/Constant3'
     */
    if (localP->Constant3_Value >= 0.0) {
      localB->DataTypeConversion = (uint8_T)localP->Constant3_Value;
    } else {
      localB->DataTypeConversion = 0U;
    }
  } else {
    /* DataTypeConversion: '<S20>/Data Type Conversion' */
    localB->DataTypeConversion = MAX_uint8_T;
  }

  /* End of Switch: '<S15>/Switch1' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S20>/PWM' */
  MW_analogWrite(localP->PWM_pinNumber, localB->DataTypeConversion);
}

/*
 * Initial conditions for trigger system:
 *    '<Root>/Subsystem1'
 *    '<Root>/Subsystem2'
 *    '<Root>/Subsystem3'
 *    '<Root>/Subsystem7'
 */
void Wheelspeed3_Subsystem1_Init(DW_Subsystem1_Wheelspeed3_T *localDW,
  P_Subsystem1_Wheelspeed3_T *localP)
{
  /* InitializeConditions for Delay: '<S7>/Delay1' */
  localDW->Delay1_DSTATE = localP->Delay1_InitialCondition;
}

/*
 * Start for trigger system:
 *    '<Root>/Subsystem1'
 *    '<Root>/Subsystem2'
 *    '<Root>/Subsystem3'
 *    '<Root>/Subsystem7'
 */
void Wheelspeed3_Subsystem1_Start(B_Subsystem1_Wheelspeed3_T *localB,
  P_Subsystem1_Wheelspeed3_T *localP)
{
  /* VirtualOutportStart for Outport: '<S7>/n' */
  localB->Divide = localP->n_Y0;
}

/*
 * Output and update for trigger system:
 *    '<Root>/Subsystem1'
 *    '<Root>/Subsystem2'
 *    '<Root>/Subsystem3'
 *    '<Root>/Subsystem7'
 */
void Wheelspeed3_Subsystem1(boolean_T rtu_Trigger, real_T rtu_In1,
  B_Subsystem1_Wheelspeed3_T *localB, DW_Subsystem1_Wheelspeed3_T *localDW,
  P_Subsystem1_Wheelspeed3_T *localP, ZCE_Subsystem1_Wheelspeed3_T *localZCE)
{
  /* Outputs for Triggered SubSystem: '<Root>/Subsystem1' incorporates:
   *  TriggerPort: '<S7>/Trigger'
   */
  if (rtu_Trigger && (localZCE->Subsystem1_Trig_ZCE != POS_ZCSIG)) {
    /* Product: '<S7>/Divide' incorporates:
     *  Constant: '<S7>/Constant'
     *  Delay: '<S7>/Delay1'
     *  Sum: '<S7>/Add1'
     */
    localB->Divide = localP->Constant_Value / (rtu_In1 - localDW->Delay1_DSTATE);

    /* Update for Delay: '<S7>/Delay1' */
    localDW->Delay1_DSTATE = rtu_In1;
    localDW->Subsystem1_SubsysRanBC = 4;
  }

  localZCE->Subsystem1_Trig_ZCE = rtu_Trigger;

  /* End of Outputs for SubSystem: '<Root>/Subsystem1' */
}

/* Model step function */
void Wheelspeed3_step(void)
{
  /* local block i/o variables */
  real_T rtb_FromWs;
  boolean_T rtb_Compare;
  boolean_T rtb_FixPtRelationalOperator;
  boolean_T rtb_Compare_i;
  boolean_T rtb_FixPtRelationalOperator_e;
  boolean_T rtb_Compare_c;
  boolean_T rtb_FixPtRelationalOperator_d;
  boolean_T rtb_Compare_cm;
  boolean_T rtb_FixPtRelationalOperator_a;
  real_T tmp;
  uint8_T tmp_0;

  /* Reset subsysRan breadcrumbs */
  srClearBC(Wheelspeed3_DW.Subsystem1.Subsystem1_SubsysRanBC);

  /* Clock: '<Root>/Clock' */
  Wheelspeed3_B.Clock = Wheelspeed3_M->Timing.t[0];

  /* S-Function (arduinodigitalinput_sfcn): '<Root>/Digital Input' */
  Wheelspeed3_B.DigitalInput = MW_digitalRead(Wheelspeed3_P.DigitalInput_p1);

  /* RelationalOperator: '<S11>/Compare' incorporates:
   *  Constant: '<S11>/Constant'
   */
  rtb_Compare = ((int16_T)Wheelspeed3_B.DigitalInput > (int16_T)
                 Wheelspeed3_P.Constant_Value);

  /* RelationalOperator: '<S1>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S1>/Delay Input1'
   */
  rtb_FixPtRelationalOperator = ((int16_T)rtb_Compare > (int16_T)
    Wheelspeed3_DW.DelayInput1_DSTATE);

  /* Outputs for Triggered SubSystem: '<Root>/Subsystem3' */
  Wheelspeed3_Subsystem1(rtb_FixPtRelationalOperator, Wheelspeed3_B.Clock,
    &Wheelspeed3_B.Subsystem3, &Wheelspeed3_DW.Subsystem3,
    (P_Subsystem1_Wheelspeed3_T *)&Wheelspeed3_P.Subsystem3,
    &Wheelspeed3_PrevZCX.Subsystem3);

  /* End of Outputs for SubSystem: '<Root>/Subsystem3' */

  /* S-Function (arduinodigitalinput_sfcn): '<Root>/Digital Input1' */
  Wheelspeed3_B.DigitalInput1 = MW_digitalRead(Wheelspeed3_P.DigitalInput1_p1);

  /* RelationalOperator: '<S12>/Compare' incorporates:
   *  Constant: '<S12>/Constant'
   */
  rtb_Compare_i = ((int16_T)Wheelspeed3_B.DigitalInput1 > (int16_T)
                   Wheelspeed3_P.Constant_Value_b);

  /* RelationalOperator: '<S2>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S2>/Delay Input1'
   */
  rtb_FixPtRelationalOperator_e = ((int16_T)rtb_Compare_i > (int16_T)
    Wheelspeed3_DW.DelayInput1_DSTATE_e);

  /* Outputs for Triggered SubSystem: '<Root>/Subsystem1' */
  Wheelspeed3_Subsystem1(rtb_FixPtRelationalOperator_e, Wheelspeed3_B.Clock,
    &Wheelspeed3_B.Subsystem1, &Wheelspeed3_DW.Subsystem1,
    (P_Subsystem1_Wheelspeed3_T *)&Wheelspeed3_P.Subsystem1,
    &Wheelspeed3_PrevZCX.Subsystem1);

  /* End of Outputs for SubSystem: '<Root>/Subsystem1' */

  /* S-Function (arduinodigitalinput_sfcn): '<Root>/Digital Input2' */
  Wheelspeed3_B.DigitalInput2 = MW_digitalRead(Wheelspeed3_P.DigitalInput2_p1);

  /* RelationalOperator: '<S13>/Compare' incorporates:
   *  Constant: '<S13>/Constant'
   */
  rtb_Compare_c = ((int16_T)Wheelspeed3_B.DigitalInput2 > (int16_T)
                   Wheelspeed3_P.Constant_Value_p);

  /* RelationalOperator: '<S3>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S3>/Delay Input1'
   */
  rtb_FixPtRelationalOperator_d = ((int16_T)rtb_Compare_c > (int16_T)
    Wheelspeed3_DW.DelayInput1_DSTATE_h);

  /* Outputs for Triggered SubSystem: '<Root>/Subsystem2' */
  Wheelspeed3_Subsystem1(rtb_FixPtRelationalOperator_d, Wheelspeed3_B.Clock,
    &Wheelspeed3_B.Subsystem2, &Wheelspeed3_DW.Subsystem2,
    (P_Subsystem1_Wheelspeed3_T *)&Wheelspeed3_P.Subsystem2,
    &Wheelspeed3_PrevZCX.Subsystem2);

  /* End of Outputs for SubSystem: '<Root>/Subsystem2' */

  /* S-Function (arduinodigitalinput_sfcn): '<Root>/Digital Input3' */
  Wheelspeed3_B.DigitalInput3 = MW_digitalRead(Wheelspeed3_P.DigitalInput3_p1);

  /* RelationalOperator: '<S14>/Compare' incorporates:
   *  Constant: '<S14>/Constant'
   */
  rtb_Compare_cm = ((int16_T)Wheelspeed3_B.DigitalInput3 > (int16_T)
                    Wheelspeed3_P.Constant_Value_m);

  /* RelationalOperator: '<S4>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S4>/Delay Input1'
   */
  rtb_FixPtRelationalOperator_a = ((int16_T)rtb_Compare_cm > (int16_T)
    Wheelspeed3_DW.DelayInput1_DSTATE_k);

  /* Outputs for Triggered SubSystem: '<Root>/Subsystem7' */
  Wheelspeed3_Subsystem1(rtb_FixPtRelationalOperator_a, Wheelspeed3_B.Clock,
    &Wheelspeed3_B.Subsystem7, &Wheelspeed3_DW.Subsystem7,
    (P_Subsystem1_Wheelspeed3_T *)&Wheelspeed3_P.Subsystem7,
    &Wheelspeed3_PrevZCX.Subsystem7);

  /* End of Outputs for SubSystem: '<Root>/Subsystem7' */

  /* Constant: '<Root>/enable' */
  Wheelspeed3_B.enable = Wheelspeed3_P.enable_Value;

  /* FromWorkspace: '<S6>/FromWs' */
  {
    real_T *pDataValues = (real_T *) Wheelspeed3_DW.FromWs_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) Wheelspeed3_DW.FromWs_PWORK.TimePtr;
    int_T currTimeIndex = Wheelspeed3_DW.FromWs_IWORK.PrevIndex;
    real_T t = Wheelspeed3_M->Timing.t[0];

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

    Wheelspeed3_DW.FromWs_IWORK.PrevIndex = currTimeIndex;

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

  /* Outputs for Atomic SubSystem: '<S5>/hl' */

  /* Constant: '<Root>/direction' */
  Wheelspeed3_hl(Wheelspeed3_B.enable, rtb_FromWs, Wheelspeed3_P.direction_Value,
                 &Wheelspeed3_B.hl, (P_hl_Wheelspeed3_T *)&Wheelspeed3_P.hl);

  /* End of Outputs for SubSystem: '<S5>/hl' */

  /* Outputs for Atomic SubSystem: '<S5>/hr' */
  /* Switch: '<S16>/Switch' incorporates:
   *  Constant: '<Root>/direction'
   *  Constant: '<S16>/Constant2'
   */
  if (Wheelspeed3_B.enable > Wheelspeed3_P.Switch_Threshold) {
    tmp = Wheelspeed3_P.direction_Value;
  } else {
    tmp = Wheelspeed3_P.Constant2_Value;
  }

  /* End of Switch: '<S16>/Switch' */

  /* DataTypeConversion: '<S21>/Data Type Conversion' */
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S21>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S21>/Digital Output' */
  MW_digitalWrite(Wheelspeed3_P.DigitalOutput_pinNumber, tmp_0);

  /* Switch: '<S16>/Switch1' incorporates:
   *  Constant: '<S16>/Constant3'
   *  DataTypeConversion: '<S22>/Data Type Conversion'
   */
  if (Wheelspeed3_B.enable > Wheelspeed3_P.Switch1_Threshold) {
    /* DataTypeConversion: '<S22>/Data Type Conversion' */
    if (rtb_FromWs < 256.0) {
      if (rtb_FromWs >= 0.0) {
        Wheelspeed3_B.DataTypeConversion_i = (uint8_T)rtb_FromWs;
      } else {
        Wheelspeed3_B.DataTypeConversion_i = 0U;
      }
    } else {
      Wheelspeed3_B.DataTypeConversion_i = MAX_uint8_T;
    }
  } else if (Wheelspeed3_P.Constant3_Value < 256.0) {
    /* DataTypeConversion: '<S22>/Data Type Conversion' incorporates:
     *  Constant: '<S16>/Constant3'
     */
    if (Wheelspeed3_P.Constant3_Value >= 0.0) {
      Wheelspeed3_B.DataTypeConversion_i = (uint8_T)
        Wheelspeed3_P.Constant3_Value;
    } else {
      Wheelspeed3_B.DataTypeConversion_i = 0U;
    }
  } else {
    /* DataTypeConversion: '<S22>/Data Type Conversion' */
    Wheelspeed3_B.DataTypeConversion_i = MAX_uint8_T;
  }

  /* End of Switch: '<S16>/Switch1' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S22>/PWM' */
  MW_analogWrite(Wheelspeed3_P.PWM_pinNumber, Wheelspeed3_B.DataTypeConversion_i);

  /* Outputs for Atomic SubSystem: '<S5>/vl' */

  /* Constant: '<Root>/direction' */
  Wheelspeed3_hl(Wheelspeed3_B.enable, rtb_FromWs, Wheelspeed3_P.direction_Value,
                 &Wheelspeed3_B.vl, (P_hl_Wheelspeed3_T *)&Wheelspeed3_P.vl);

  /* End of Outputs for SubSystem: '<S5>/vl' */

  /* Outputs for Atomic SubSystem: '<S5>/vr' */
  /* Switch: '<S18>/Switch' incorporates:
   *  Constant: '<Root>/direction'
   *  Constant: '<S18>/Constant2'
   */
  if (Wheelspeed3_B.enable > Wheelspeed3_P.Switch_Threshold_n) {
    tmp = Wheelspeed3_P.direction_Value;
  } else {
    tmp = Wheelspeed3_P.Constant2_Value_j;
  }

  /* End of Switch: '<S18>/Switch' */

  /* DataTypeConversion: '<S25>/Data Type Conversion' */
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S25>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S25>/Digital Output' */
  MW_digitalWrite(Wheelspeed3_P.DigitalOutput_pinNumber_n, tmp_0);

  /* Switch: '<S18>/Switch1' incorporates:
   *  Constant: '<S18>/Constant3'
   *  DataTypeConversion: '<S26>/Data Type Conversion'
   */
  if (Wheelspeed3_B.enable > Wheelspeed3_P.Switch1_Threshold_k) {
    /* DataTypeConversion: '<S26>/Data Type Conversion' */
    if (rtb_FromWs < 256.0) {
      if (rtb_FromWs >= 0.0) {
        Wheelspeed3_B.DataTypeConversion = (uint8_T)rtb_FromWs;
      } else {
        Wheelspeed3_B.DataTypeConversion = 0U;
      }
    } else {
      Wheelspeed3_B.DataTypeConversion = MAX_uint8_T;
    }
  } else if (Wheelspeed3_P.Constant3_Value_k < 256.0) {
    /* DataTypeConversion: '<S26>/Data Type Conversion' incorporates:
     *  Constant: '<S18>/Constant3'
     */
    if (Wheelspeed3_P.Constant3_Value_k >= 0.0) {
      Wheelspeed3_B.DataTypeConversion = (uint8_T)
        Wheelspeed3_P.Constant3_Value_k;
    } else {
      Wheelspeed3_B.DataTypeConversion = 0U;
    }
  } else {
    /* DataTypeConversion: '<S26>/Data Type Conversion' */
    Wheelspeed3_B.DataTypeConversion = MAX_uint8_T;
  }

  /* End of Switch: '<S18>/Switch1' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S26>/PWM' */
  MW_analogWrite(Wheelspeed3_P.PWM_pinNumber_g, Wheelspeed3_B.DataTypeConversion);

  /* Update for UnitDelay: '<S1>/Delay Input1' */
  Wheelspeed3_DW.DelayInput1_DSTATE = rtb_Compare;

  /* Update for UnitDelay: '<S2>/Delay Input1' */
  Wheelspeed3_DW.DelayInput1_DSTATE_e = rtb_Compare_i;

  /* Update for UnitDelay: '<S3>/Delay Input1' */
  Wheelspeed3_DW.DelayInput1_DSTATE_h = rtb_Compare_c;

  /* Update for UnitDelay: '<S4>/Delay Input1' */
  Wheelspeed3_DW.DelayInput1_DSTATE_k = rtb_Compare_cm;

  /* External mode */
  rtExtModeUploadCheckTrigger(2);

  {                                    /* Sample time: [0.0s, 0.0s] */
    rtExtModeUpload(0, Wheelspeed3_M->Timing.t[0]);
  }

  {                                    /* Sample time: [0.01s, 0.0s] */
    rtExtModeUpload(1, ((Wheelspeed3_M->Timing.clockTick1) * 0.01));
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(Wheelspeed3_M)!=-1) &&
        !((rtmGetTFinal(Wheelspeed3_M)-Wheelspeed3_M->Timing.t[0]) >
          Wheelspeed3_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(Wheelspeed3_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Wheelspeed3_M)) {
      rtmSetErrorStatus(Wheelspeed3_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Wheelspeed3_M->Timing.t[0] =
    (++Wheelspeed3_M->Timing.clockTick0) * Wheelspeed3_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Wheelspeed3_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Wheelspeed3_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Wheelspeed3_M, 0,
                sizeof(RT_MODEL_Wheelspeed3_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Wheelspeed3_M->solverInfo,
                          &Wheelspeed3_M->Timing.simTimeStep);
    rtsiSetTPtr(&Wheelspeed3_M->solverInfo, &rtmGetTPtr(Wheelspeed3_M));
    rtsiSetStepSizePtr(&Wheelspeed3_M->solverInfo,
                       &Wheelspeed3_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Wheelspeed3_M->solverInfo, (&rtmGetErrorStatus
      (Wheelspeed3_M)));
    rtsiSetRTModelPtr(&Wheelspeed3_M->solverInfo, Wheelspeed3_M);
  }

  rtsiSetSimTimeStep(&Wheelspeed3_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Wheelspeed3_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Wheelspeed3_M, &Wheelspeed3_M->Timing.tArray[0]);
  rtmSetTFinal(Wheelspeed3_M, 10.0);
  Wheelspeed3_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Wheelspeed3_M->Sizes.checksums[0] = (1031562914U);
  Wheelspeed3_M->Sizes.checksums[1] = (3028526292U);
  Wheelspeed3_M->Sizes.checksums[2] = (1033216974U);
  Wheelspeed3_M->Sizes.checksums[3] = (2441498185U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[13];
    Wheelspeed3_M->extModeInfo = (&rt_ExtModeInfo);
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
    systemRan[9] = (sysRanDType *)
      &Wheelspeed3_DW.Subsystem1.Subsystem1_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &Wheelspeed3_DW.Subsystem2.Subsystem1_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &Wheelspeed3_DW.Subsystem3.Subsystem1_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &Wheelspeed3_DW.Subsystem7.Subsystem1_SubsysRanBC;
    rteiSetModelMappingInfoPtr(Wheelspeed3_M->extModeInfo,
      &Wheelspeed3_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Wheelspeed3_M->extModeInfo,
                        Wheelspeed3_M->Sizes.checksums);
    rteiSetTPtr(Wheelspeed3_M->extModeInfo, rtmGetTPtr(Wheelspeed3_M));
  }

  /* block I/O */
  (void) memset(((void *) &Wheelspeed3_B), 0,
                sizeof(B_Wheelspeed3_T));

  /* states (dwork) */
  (void) memset((void *)&Wheelspeed3_DW, 0,
                sizeof(DW_Wheelspeed3_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Wheelspeed3_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (arduinodigitalinput_sfcn): '<Root>/Digital Input' */
  MW_pinModeInput(Wheelspeed3_P.DigitalInput_p1);

  /* Start for Triggered SubSystem: '<Root>/Subsystem3' */
  Wheelspeed3_Subsystem1_Start(&Wheelspeed3_B.Subsystem3,
    (P_Subsystem1_Wheelspeed3_T *)&Wheelspeed3_P.Subsystem3);

  /* End of Start for SubSystem: '<Root>/Subsystem3' */

  /* Start for S-Function (arduinodigitalinput_sfcn): '<Root>/Digital Input1' */
  MW_pinModeInput(Wheelspeed3_P.DigitalInput1_p1);

  /* Start for Triggered SubSystem: '<Root>/Subsystem1' */
  Wheelspeed3_Subsystem1_Start(&Wheelspeed3_B.Subsystem1,
    (P_Subsystem1_Wheelspeed3_T *)&Wheelspeed3_P.Subsystem1);

  /* End of Start for SubSystem: '<Root>/Subsystem1' */

  /* Start for S-Function (arduinodigitalinput_sfcn): '<Root>/Digital Input2' */
  MW_pinModeInput(Wheelspeed3_P.DigitalInput2_p1);

  /* Start for Triggered SubSystem: '<Root>/Subsystem2' */
  Wheelspeed3_Subsystem1_Start(&Wheelspeed3_B.Subsystem2,
    (P_Subsystem1_Wheelspeed3_T *)&Wheelspeed3_P.Subsystem2);

  /* End of Start for SubSystem: '<Root>/Subsystem2' */

  /* Start for S-Function (arduinodigitalinput_sfcn): '<Root>/Digital Input3' */
  MW_pinModeInput(Wheelspeed3_P.DigitalInput3_p1);

  /* Start for Triggered SubSystem: '<Root>/Subsystem7' */
  Wheelspeed3_Subsystem1_Start(&Wheelspeed3_B.Subsystem7,
    (P_Subsystem1_Wheelspeed3_T *)&Wheelspeed3_P.Subsystem7);

  /* End of Start for SubSystem: '<Root>/Subsystem7' */

  /* Start for FromWorkspace: '<S6>/FromWs' */
  {
    static real_T pTimeValues0[] = { 0.0, 1.0, 1.0, 2.0, 2.0, 4.0, 4.0, 6.0, 6.0,
      7.0 } ;

    static real_T pDataValues0[] = { 0.0, 128.0, 128.0, 128.0, 128.0, 255.0,
      255.0, 255.0, 255.0, 0.0 } ;

    Wheelspeed3_DW.FromWs_PWORK.TimePtr = (void *) pTimeValues0;
    Wheelspeed3_DW.FromWs_PWORK.DataPtr = (void *) pDataValues0;
    Wheelspeed3_DW.FromWs_IWORK.PrevIndex = 0;
  }

  /* Start for Atomic SubSystem: '<S5>/hl' */
  Wheelspeed3_hl_Start((P_hl_Wheelspeed3_T *)&Wheelspeed3_P.hl);

  /* End of Start for SubSystem: '<S5>/hl' */

  /* Start for Atomic SubSystem: '<S5>/hr' */
  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S21>/Digital Output' */
  MW_pinModeOutput(Wheelspeed3_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S22>/PWM' */
  MW_pinModeOutput(Wheelspeed3_P.PWM_pinNumber);

  /* Start for Atomic SubSystem: '<S5>/vl' */
  Wheelspeed3_hl_Start((P_hl_Wheelspeed3_T *)&Wheelspeed3_P.vl);

  /* End of Start for SubSystem: '<S5>/vl' */

  /* Start for Atomic SubSystem: '<S5>/vr' */
  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S25>/Digital Output' */
  MW_pinModeOutput(Wheelspeed3_P.DigitalOutput_pinNumber_n);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S26>/PWM' */
  MW_pinModeOutput(Wheelspeed3_P.PWM_pinNumber_g);
  Wheelspeed3_PrevZCX.Subsystem7.Subsystem1_Trig_ZCE = POS_ZCSIG;
  Wheelspeed3_PrevZCX.Subsystem3.Subsystem1_Trig_ZCE = POS_ZCSIG;
  Wheelspeed3_PrevZCX.Subsystem2.Subsystem1_Trig_ZCE = POS_ZCSIG;
  Wheelspeed3_PrevZCX.Subsystem1.Subsystem1_Trig_ZCE = POS_ZCSIG;

  /* InitializeConditions for UnitDelay: '<S1>/Delay Input1' */
  Wheelspeed3_DW.DelayInput1_DSTATE = Wheelspeed3_P.DetectRisePositive_vinit;

  /* InitializeConditions for Triggered SubSystem: '<Root>/Subsystem3' */
  Wheelspeed3_Subsystem1_Init(&Wheelspeed3_DW.Subsystem3,
    (P_Subsystem1_Wheelspeed3_T *)&Wheelspeed3_P.Subsystem3);

  /* End of InitializeConditions for SubSystem: '<Root>/Subsystem3' */

  /* InitializeConditions for UnitDelay: '<S2>/Delay Input1' */
  Wheelspeed3_DW.DelayInput1_DSTATE_e = Wheelspeed3_P.DetectRisePositive1_vinit;

  /* InitializeConditions for Triggered SubSystem: '<Root>/Subsystem1' */
  Wheelspeed3_Subsystem1_Init(&Wheelspeed3_DW.Subsystem1,
    (P_Subsystem1_Wheelspeed3_T *)&Wheelspeed3_P.Subsystem1);

  /* End of InitializeConditions for SubSystem: '<Root>/Subsystem1' */

  /* InitializeConditions for UnitDelay: '<S3>/Delay Input1' */
  Wheelspeed3_DW.DelayInput1_DSTATE_h = Wheelspeed3_P.DetectRisePositive2_vinit;

  /* InitializeConditions for Triggered SubSystem: '<Root>/Subsystem2' */
  Wheelspeed3_Subsystem1_Init(&Wheelspeed3_DW.Subsystem2,
    (P_Subsystem1_Wheelspeed3_T *)&Wheelspeed3_P.Subsystem2);

  /* End of InitializeConditions for SubSystem: '<Root>/Subsystem2' */

  /* InitializeConditions for UnitDelay: '<S4>/Delay Input1' */
  Wheelspeed3_DW.DelayInput1_DSTATE_k = Wheelspeed3_P.DetectRisePositive3_vinit;

  /* InitializeConditions for Triggered SubSystem: '<Root>/Subsystem7' */
  Wheelspeed3_Subsystem1_Init(&Wheelspeed3_DW.Subsystem7,
    (P_Subsystem1_Wheelspeed3_T *)&Wheelspeed3_P.Subsystem7);

  /* End of InitializeConditions for SubSystem: '<Root>/Subsystem7' */
}

/* Model terminate function */
void Wheelspeed3_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
