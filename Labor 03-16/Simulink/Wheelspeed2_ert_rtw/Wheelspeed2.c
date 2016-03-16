/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Wheelspeed2.c
 *
 * Code generated for Simulink model 'Wheelspeed2'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 16 13:52:08 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Wheelspeed2.h"
#include "Wheelspeed2_private.h"
#include "Wheelspeed2_dt.h"

/* Block signals (auto storage) */
B_Wheelspeed2_T Wheelspeed2_B;

/* Block states (auto storage) */
DW_Wheelspeed2_T Wheelspeed2_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Wheelspeed2_T Wheelspeed2_PrevZCX;

/* Real-time model */
RT_MODEL_Wheelspeed2_T Wheelspeed2_M_;
RT_MODEL_Wheelspeed2_T *const Wheelspeed2_M = &Wheelspeed2_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Wheelspeed2_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(Wheelspeed2_M, 2));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (Wheelspeed2_M->Timing.TaskCounters.TID[1] == 0) {
    Wheelspeed2_M->Timing.RateInteraction.TID1_2 =
      (Wheelspeed2_M->Timing.TaskCounters.TID[2] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Wheelspeed2_M->Timing.TaskCounters.TID[2])++;
  if ((Wheelspeed2_M->Timing.TaskCounters.TID[2]) > 24) {/* Sample time: [0.25s, 0.0s] */
    Wheelspeed2_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * Start for atomic system:
 *    '<S5>/hl'
 *    '<S5>/vl'
 */
void Wheelspeed2_hl_Start(P_hl_Wheelspeed2_T *localP)
{
  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S20>/Digital Output' */
  MW_pinModeOutput(localP->DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S21>/PWM' */
  MW_pinModeOutput(localP->PWM_pinNumber);
}

/*
 * Output and update for atomic system:
 *    '<S5>/hl'
 *    '<S5>/vl'
 */
void Wheelspeed2_hl(real_T rtu_enable, real_T rtu_power, real_T rtu_direction,
                    B_hl_Wheelspeed2_T *localB, P_hl_Wheelspeed2_T *localP)
{
  real_T rtu_enable_0;
  uint8_T rtu_enable_1;

  /* Switch: '<S16>/Switch' incorporates:
   *  Constant: '<S16>/Constant2'
   */
  if (rtu_enable > localP->Switch_Threshold) {
    rtu_enable_0 = rtu_direction;
  } else {
    rtu_enable_0 = localP->Constant2_Value;
  }

  /* End of Switch: '<S16>/Switch' */

  /* DataTypeConversion: '<S20>/Data Type Conversion' */
  if (rtu_enable_0 < 256.0) {
    if (rtu_enable_0 >= 0.0) {
      rtu_enable_1 = (uint8_T)rtu_enable_0;
    } else {
      rtu_enable_1 = 0U;
    }
  } else {
    rtu_enable_1 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S20>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S20>/Digital Output' */
  MW_digitalWrite(localP->DigitalOutput_pinNumber, rtu_enable_1);

  /* Constant: '<S16>/Constant3' */
  localB->Constant3 = localP->Constant3_Value;

  /* Switch: '<S16>/Switch1' incorporates:
   *  DataTypeConversion: '<S21>/Data Type Conversion'
   */
  if (rtu_enable > localP->Switch1_Threshold) {
    /* DataTypeConversion: '<S21>/Data Type Conversion' */
    if (rtu_power < 256.0) {
      if (rtu_power >= 0.0) {
        localB->DataTypeConversion = (uint8_T)rtu_power;
      } else {
        localB->DataTypeConversion = 0U;
      }
    } else {
      localB->DataTypeConversion = MAX_uint8_T;
    }
  } else if (localB->Constant3 < 256.0) {
    /* DataTypeConversion: '<S21>/Data Type Conversion' */
    if (localB->Constant3 >= 0.0) {
      localB->DataTypeConversion = (uint8_T)localB->Constant3;
    } else {
      localB->DataTypeConversion = 0U;
    }
  } else {
    /* DataTypeConversion: '<S21>/Data Type Conversion' */
    localB->DataTypeConversion = MAX_uint8_T;
  }

  /* End of Switch: '<S16>/Switch1' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S21>/PWM' */
  MW_analogWrite(localP->PWM_pinNumber, localB->DataTypeConversion);
}

/*
 * Initial conditions for trigger system:
 *    '<Root>/Subsystem'
 *    '<Root>/Subsystem1'
 *    '<Root>/Subsystem2'
 *    '<Root>/Subsystem3'
 */
void Wheelspeed2_Subsystem_Init(DW_Subsystem_Wheelspeed2_T *localDW,
  P_Subsystem_Wheelspeed2_T *localP)
{
  /* InitializeConditions for Delay: '<S7>/Delay' */
  localDW->Delay_DSTATE = localP->Delay_InitialCondition;
}

/*
 * Start for trigger system:
 *    '<Root>/Subsystem'
 *    '<Root>/Subsystem1'
 *    '<Root>/Subsystem2'
 *    '<Root>/Subsystem3'
 */
void Wheelspeed2_Subsystem_Start(B_Subsystem_Wheelspeed2_T *localB,
  P_Subsystem_Wheelspeed2_T *localP)
{
  /* VirtualOutportStart for Outport: '<S7>/Out1' */
  localB->Add = localP->Out1_Y0;
}

/*
 * Output and update for trigger system:
 *    '<Root>/Subsystem'
 *    '<Root>/Subsystem1'
 *    '<Root>/Subsystem2'
 *    '<Root>/Subsystem3'
 */
void Wheelspeed2_Subsystem(boolean_T rtu_Trigger, real_T rtu_reset,
  B_Subsystem_Wheelspeed2_T *localB, DW_Subsystem_Wheelspeed2_T *localDW,
  P_Subsystem_Wheelspeed2_T *localP, ZCE_Subsystem_Wheelspeed2_T *localZCE)
{
  real_T rtu_reset_0;

  /* Outputs for Triggered SubSystem: '<Root>/Subsystem' incorporates:
   *  TriggerPort: '<S7>/Trigger'
   */
  if (rtu_Trigger && (localZCE->Subsystem_Trig_ZCE != POS_ZCSIG)) {
    /* Switch: '<S7>/Switch' incorporates:
     *  Constant: '<S7>/Constant1'
     *  Delay: '<S7>/Delay'
     */
    if (rtu_reset > localP->Switch_Threshold) {
      rtu_reset_0 = localP->Constant1_Value;
    } else {
      rtu_reset_0 = localDW->Delay_DSTATE;
    }

    /* End of Switch: '<S7>/Switch' */

    /* Sum: '<S7>/Add' incorporates:
     *  Constant: '<S7>/Constant'
     */
    localB->Add = rtu_reset_0 + localP->Constant_Value;

    /* Update for Delay: '<S7>/Delay' */
    localDW->Delay_DSTATE = localB->Add;
    localDW->Subsystem_SubsysRanBC = 4;
  }

  localZCE->Subsystem_Trig_ZCE = rtu_Trigger;

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */
}

/* Model step function for TID0 */
void Wheelspeed2_step0(void)           /* Sample time: [0.0s, 0.0s] */
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

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(Wheelspeed2_DW.Subsystem.Subsystem_SubsysRanBC);

  /* S-Function (arduinodigitalinput_sfcn): '<Root>/Digital Input' */
  Wheelspeed2_B.DigitalInput = MW_digitalRead(Wheelspeed2_P.DigitalInput_p1);

  /* S-Function (arduinodigitalinput_sfcn): '<Root>/Digital Input1' */
  Wheelspeed2_B.DigitalInput1 = MW_digitalRead(Wheelspeed2_P.DigitalInput1_p1);

  /* S-Function (arduinodigitalinput_sfcn): '<Root>/Digital Input2' */
  Wheelspeed2_B.DigitalInput2 = MW_digitalRead(Wheelspeed2_P.DigitalInput2_p1);

  /* S-Function (arduinodigitalinput_sfcn): '<Root>/Digital Input3' */
  Wheelspeed2_B.DigitalInput3 = MW_digitalRead(Wheelspeed2_P.DigitalInput3_p1);

  /* RateTransition: '<Root>/Rate Transition' */
  if (Wheelspeed2_M->Timing.RateInteraction.TID1_2) {
    Wheelspeed2_B.RateTransition = Wheelspeed2_DW.RateTransition_Buffer0;
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* RelationalOperator: '<S12>/Compare' incorporates:
   *  Constant: '<S12>/Constant'
   */
  rtb_Compare = ((int16_T)Wheelspeed2_B.DigitalInput > (int16_T)
                 Wheelspeed2_P.Constant_Value);

  /* RelationalOperator: '<S1>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S1>/Delay Input1'
   */
  rtb_FixPtRelationalOperator = ((int16_T)rtb_Compare > (int16_T)
    Wheelspeed2_DW.DelayInput1_DSTATE);

  /* Outputs for Triggered SubSystem: '<Root>/Subsystem3' */
  Wheelspeed2_Subsystem(rtb_FixPtRelationalOperator,
                        Wheelspeed2_B.RateTransition, &Wheelspeed2_B.Subsystem3,
                        &Wheelspeed2_DW.Subsystem3, (P_Subsystem_Wheelspeed2_T *)
                        &Wheelspeed2_P.Subsystem3,
                        &Wheelspeed2_PrevZCX.Subsystem3);

  /* End of Outputs for SubSystem: '<Root>/Subsystem3' */

  /* RateTransition: '<Root>/Rate Transition1' */
  if (Wheelspeed2_M->Timing.RateInteraction.TID1_2) {
    Wheelspeed2_B.RateTransition1 = Wheelspeed2_B.Subsystem3.Add;
  }

  /* End of RateTransition: '<Root>/Rate Transition1' */

  /* RelationalOperator: '<S13>/Compare' incorporates:
   *  Constant: '<S13>/Constant'
   */
  rtb_Compare_i = ((int16_T)Wheelspeed2_B.DigitalInput1 > (int16_T)
                   Wheelspeed2_P.Constant_Value_b);

  /* RelationalOperator: '<S2>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S2>/Delay Input1'
   */
  rtb_FixPtRelationalOperator_e = ((int16_T)rtb_Compare_i > (int16_T)
    Wheelspeed2_DW.DelayInput1_DSTATE_e);

  /* Outputs for Triggered SubSystem: '<Root>/Subsystem' */
  Wheelspeed2_Subsystem(rtb_FixPtRelationalOperator_e,
                        Wheelspeed2_B.RateTransition, &Wheelspeed2_B.Subsystem,
                        &Wheelspeed2_DW.Subsystem, (P_Subsystem_Wheelspeed2_T *)
                        &Wheelspeed2_P.Subsystem, &Wheelspeed2_PrevZCX.Subsystem);

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* RateTransition: '<Root>/Rate Transition2' */
  if (Wheelspeed2_M->Timing.RateInteraction.TID1_2) {
    Wheelspeed2_B.RateTransition2 = Wheelspeed2_B.Subsystem.Add;
  }

  /* End of RateTransition: '<Root>/Rate Transition2' */

  /* RelationalOperator: '<S14>/Compare' incorporates:
   *  Constant: '<S14>/Constant'
   */
  rtb_Compare_c = ((int16_T)Wheelspeed2_B.DigitalInput2 > (int16_T)
                   Wheelspeed2_P.Constant_Value_p);

  /* RelationalOperator: '<S3>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S3>/Delay Input1'
   */
  rtb_FixPtRelationalOperator_d = ((int16_T)rtb_Compare_c > (int16_T)
    Wheelspeed2_DW.DelayInput1_DSTATE_h);

  /* Outputs for Triggered SubSystem: '<Root>/Subsystem1' */
  Wheelspeed2_Subsystem(rtb_FixPtRelationalOperator_d,
                        Wheelspeed2_B.RateTransition, &Wheelspeed2_B.Subsystem1,
                        &Wheelspeed2_DW.Subsystem1, (P_Subsystem_Wheelspeed2_T *)
                        &Wheelspeed2_P.Subsystem1,
                        &Wheelspeed2_PrevZCX.Subsystem1);

  /* End of Outputs for SubSystem: '<Root>/Subsystem1' */

  /* RateTransition: '<Root>/Rate Transition3' */
  if (Wheelspeed2_M->Timing.RateInteraction.TID1_2) {
    Wheelspeed2_B.RateTransition3 = Wheelspeed2_B.Subsystem1.Add;
  }

  /* End of RateTransition: '<Root>/Rate Transition3' */

  /* RelationalOperator: '<S15>/Compare' incorporates:
   *  Constant: '<S15>/Constant'
   */
  rtb_Compare_cm = ((int16_T)Wheelspeed2_B.DigitalInput3 > (int16_T)
                    Wheelspeed2_P.Constant_Value_m);

  /* RelationalOperator: '<S4>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S4>/Delay Input1'
   */
  rtb_FixPtRelationalOperator_a = ((int16_T)rtb_Compare_cm > (int16_T)
    Wheelspeed2_DW.DelayInput1_DSTATE_k);

  /* Outputs for Triggered SubSystem: '<Root>/Subsystem2' */
  Wheelspeed2_Subsystem(rtb_FixPtRelationalOperator_a,
                        Wheelspeed2_B.RateTransition, &Wheelspeed2_B.Subsystem2,
                        &Wheelspeed2_DW.Subsystem2, (P_Subsystem_Wheelspeed2_T *)
                        &Wheelspeed2_P.Subsystem2,
                        &Wheelspeed2_PrevZCX.Subsystem2);

  /* End of Outputs for SubSystem: '<Root>/Subsystem2' */

  /* RateTransition: '<Root>/Rate Transition4' */
  if (Wheelspeed2_M->Timing.RateInteraction.TID1_2) {
    Wheelspeed2_B.RateTransition4 = Wheelspeed2_B.Subsystem2.Add;
  }

  /* End of RateTransition: '<Root>/Rate Transition4' */

  /* Constant: '<Root>/enable' */
  Wheelspeed2_B.enable = Wheelspeed2_P.enable_Value;

  /* FromWorkspace: '<S6>/FromWs' */
  {
    real_T *pDataValues = (real_T *) Wheelspeed2_DW.FromWs_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) Wheelspeed2_DW.FromWs_PWORK.TimePtr;
    int_T currTimeIndex = Wheelspeed2_DW.FromWs_IWORK.PrevIndex;
    real_T t = Wheelspeed2_M->Timing.t[0];

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

    Wheelspeed2_DW.FromWs_IWORK.PrevIndex = currTimeIndex;

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
  Wheelspeed2_hl(Wheelspeed2_B.enable, rtb_FromWs, Wheelspeed2_P.direction_Value,
                 &Wheelspeed2_B.hl, (P_hl_Wheelspeed2_T *)&Wheelspeed2_P.hl);

  /* End of Outputs for SubSystem: '<S5>/hl' */

  /* Outputs for Atomic SubSystem: '<S5>/hr' */
  /* Switch: '<S17>/Switch' incorporates:
   *  Constant: '<Root>/direction'
   *  Constant: '<S17>/Constant2'
   */
  if (Wheelspeed2_B.enable > Wheelspeed2_P.Switch_Threshold) {
    tmp = Wheelspeed2_P.direction_Value;
  } else {
    tmp = Wheelspeed2_P.Constant2_Value;
  }

  /* End of Switch: '<S17>/Switch' */

  /* DataTypeConversion: '<S22>/Data Type Conversion' */
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S22>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S22>/Digital Output' */
  MW_digitalWrite(Wheelspeed2_P.DigitalOutput_pinNumber, tmp_0);

  /* Constant: '<S17>/Constant3' */
  Wheelspeed2_B.Constant3_i = Wheelspeed2_P.Constant3_Value;

  /* Switch: '<S17>/Switch1' incorporates:
   *  DataTypeConversion: '<S23>/Data Type Conversion'
   */
  if (Wheelspeed2_B.enable > Wheelspeed2_P.Switch1_Threshold) {
    /* DataTypeConversion: '<S23>/Data Type Conversion' */
    if (rtb_FromWs < 256.0) {
      if (rtb_FromWs >= 0.0) {
        Wheelspeed2_B.DataTypeConversion_i = (uint8_T)rtb_FromWs;
      } else {
        Wheelspeed2_B.DataTypeConversion_i = 0U;
      }
    } else {
      Wheelspeed2_B.DataTypeConversion_i = MAX_uint8_T;
    }
  } else if (Wheelspeed2_B.Constant3_i < 256.0) {
    /* DataTypeConversion: '<S23>/Data Type Conversion' */
    if (Wheelspeed2_B.Constant3_i >= 0.0) {
      Wheelspeed2_B.DataTypeConversion_i = (uint8_T)Wheelspeed2_B.Constant3_i;
    } else {
      Wheelspeed2_B.DataTypeConversion_i = 0U;
    }
  } else {
    /* DataTypeConversion: '<S23>/Data Type Conversion' */
    Wheelspeed2_B.DataTypeConversion_i = MAX_uint8_T;
  }

  /* End of Switch: '<S17>/Switch1' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S23>/PWM' */
  MW_analogWrite(Wheelspeed2_P.PWM_pinNumber, Wheelspeed2_B.DataTypeConversion_i);

  /* Outputs for Atomic SubSystem: '<S5>/vl' */

  /* Constant: '<Root>/direction' */
  Wheelspeed2_hl(Wheelspeed2_B.enable, rtb_FromWs, Wheelspeed2_P.direction_Value,
                 &Wheelspeed2_B.vl, (P_hl_Wheelspeed2_T *)&Wheelspeed2_P.vl);

  /* End of Outputs for SubSystem: '<S5>/vl' */

  /* Outputs for Atomic SubSystem: '<S5>/vr' */
  /* Switch: '<S19>/Switch' incorporates:
   *  Constant: '<Root>/direction'
   *  Constant: '<S19>/Constant2'
   */
  if (Wheelspeed2_B.enable > Wheelspeed2_P.Switch_Threshold_n) {
    tmp = Wheelspeed2_P.direction_Value;
  } else {
    tmp = Wheelspeed2_P.Constant2_Value_j;
  }

  /* End of Switch: '<S19>/Switch' */

  /* DataTypeConversion: '<S26>/Data Type Conversion' */
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S26>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S26>/Digital Output' */
  MW_digitalWrite(Wheelspeed2_P.DigitalOutput_pinNumber_n, tmp_0);

  /* Constant: '<S19>/Constant3' */
  Wheelspeed2_B.Constant3 = Wheelspeed2_P.Constant3_Value_k;

  /* Switch: '<S19>/Switch1' incorporates:
   *  DataTypeConversion: '<S27>/Data Type Conversion'
   */
  if (Wheelspeed2_B.enable > Wheelspeed2_P.Switch1_Threshold_k) {
    /* DataTypeConversion: '<S27>/Data Type Conversion' */
    if (rtb_FromWs < 256.0) {
      if (rtb_FromWs >= 0.0) {
        Wheelspeed2_B.DataTypeConversion = (uint8_T)rtb_FromWs;
      } else {
        Wheelspeed2_B.DataTypeConversion = 0U;
      }
    } else {
      Wheelspeed2_B.DataTypeConversion = MAX_uint8_T;
    }
  } else if (Wheelspeed2_B.Constant3 < 256.0) {
    /* DataTypeConversion: '<S27>/Data Type Conversion' */
    if (Wheelspeed2_B.Constant3 >= 0.0) {
      Wheelspeed2_B.DataTypeConversion = (uint8_T)Wheelspeed2_B.Constant3;
    } else {
      Wheelspeed2_B.DataTypeConversion = 0U;
    }
  } else {
    /* DataTypeConversion: '<S27>/Data Type Conversion' */
    Wheelspeed2_B.DataTypeConversion = MAX_uint8_T;
  }

  /* End of Switch: '<S19>/Switch1' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S27>/PWM' */
  MW_analogWrite(Wheelspeed2_P.PWM_pinNumber_g, Wheelspeed2_B.DataTypeConversion);

  /* Update for UnitDelay: '<S1>/Delay Input1' */
  Wheelspeed2_DW.DelayInput1_DSTATE = rtb_Compare;

  /* Update for UnitDelay: '<S2>/Delay Input1' */
  Wheelspeed2_DW.DelayInput1_DSTATE_e = rtb_Compare_i;

  /* Update for UnitDelay: '<S3>/Delay Input1' */
  Wheelspeed2_DW.DelayInput1_DSTATE_h = rtb_Compare_c;

  /* Update for UnitDelay: '<S4>/Delay Input1' */
  Wheelspeed2_DW.DelayInput1_DSTATE_k = rtb_Compare_cm;

  /* External mode */
  rtExtModeUploadCheckTrigger(3);
  rtExtModeUpload(1, Wheelspeed2_M->Timing.t[0]);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(Wheelspeed2_M)!=-1) &&
        !((rtmGetTFinal(Wheelspeed2_M)-Wheelspeed2_M->Timing.t[0]) >
          Wheelspeed2_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(Wheelspeed2_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Wheelspeed2_M)) {
      rtmSetErrorStatus(Wheelspeed2_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Wheelspeed2_M->Timing.t[0] =
    (++Wheelspeed2_M->Timing.clockTick0) * Wheelspeed2_M->Timing.stepSize0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Wheelspeed2_M->Timing.clockTick1++;
}

/* Model step function for TID2 */
void Wheelspeed2_step2(void)           /* Sample time: [0.25s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_PulseGenerator;
  ZCEventType zcEvent;

  /* Reset subsysRan breadcrumbs */
  srClearBC(Wheelspeed2_DW.Subsystem4_SubsysRanBC);

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (Wheelspeed2_DW.clockTickCounter <
                        Wheelspeed2_P.PulseGenerator_Duty) &&
    (Wheelspeed2_DW.clockTickCounter >= 0L) ? Wheelspeed2_P.PulseGenerator_Amp :
    0.0;
  if (Wheelspeed2_DW.clockTickCounter >= Wheelspeed2_P.PulseGenerator_Period -
      1.0) {
    Wheelspeed2_DW.clockTickCounter = 0L;
  } else {
    Wheelspeed2_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* Outputs for Triggered SubSystem: '<Root>/Subsystem4' incorporates:
   *  TriggerPort: '<S11>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &Wheelspeed2_PrevZCX.Subsystem4_Trig_ZCE,
                     (rtb_PulseGenerator));
  if (zcEvent != NO_ZCEVENT) {
    /* Gain: '<S11>/Gain' */
    Wheelspeed2_B.Gain = Wheelspeed2_P.Gain_Gain * Wheelspeed2_B.RateTransition1;

    /* Gain: '<S11>/Gain1' */
    Wheelspeed2_B.Gain1 = Wheelspeed2_P.Gain1_Gain *
      Wheelspeed2_B.RateTransition2;

    /* Gain: '<S11>/Gain2' */
    Wheelspeed2_B.Gain2 = Wheelspeed2_P.Gain2_Gain *
      Wheelspeed2_B.RateTransition3;

    /* Gain: '<S11>/Gain3' */
    Wheelspeed2_B.Gain3 = Wheelspeed2_P.Gain3_Gain *
      Wheelspeed2_B.RateTransition4;
    Wheelspeed2_DW.Subsystem4_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<Root>/Subsystem4' */

  /* Update for RateTransition: '<Root>/Rate Transition' */
  Wheelspeed2_DW.RateTransition_Buffer0 = rtb_PulseGenerator;
  rtExtModeUpload(2, ((Wheelspeed2_M->Timing.clockTick2) * 0.25));

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.25, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Wheelspeed2_M->Timing.clockTick2++;
}

/* Model initialize function */
void Wheelspeed2_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Wheelspeed2_M, 0,
                sizeof(RT_MODEL_Wheelspeed2_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Wheelspeed2_M->solverInfo,
                          &Wheelspeed2_M->Timing.simTimeStep);
    rtsiSetTPtr(&Wheelspeed2_M->solverInfo, &rtmGetTPtr(Wheelspeed2_M));
    rtsiSetStepSizePtr(&Wheelspeed2_M->solverInfo,
                       &Wheelspeed2_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Wheelspeed2_M->solverInfo, (&rtmGetErrorStatus
      (Wheelspeed2_M)));
    rtsiSetRTModelPtr(&Wheelspeed2_M->solverInfo, Wheelspeed2_M);
  }

  rtsiSetSimTimeStep(&Wheelspeed2_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Wheelspeed2_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Wheelspeed2_M, &Wheelspeed2_M->Timing.tArray[0]);
  rtmSetTFinal(Wheelspeed2_M, 100.0);
  Wheelspeed2_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Wheelspeed2_M->Sizes.checksums[0] = (3228538237U);
  Wheelspeed2_M->Sizes.checksums[1] = (3343485765U);
  Wheelspeed2_M->Sizes.checksums[2] = (739621266U);
  Wheelspeed2_M->Sizes.checksums[3] = (2000682727U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[18];
    Wheelspeed2_M->extModeInfo = (&rt_ExtModeInfo);
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
      &Wheelspeed2_DW.Subsystem.Subsystem_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &Wheelspeed2_DW.Subsystem.Subsystem_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &Wheelspeed2_DW.Subsystem1.Subsystem_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &Wheelspeed2_DW.Subsystem1.Subsystem_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &Wheelspeed2_DW.Subsystem2.Subsystem_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &Wheelspeed2_DW.Subsystem2.Subsystem_SubsysRanBC;
    systemRan[15] = (sysRanDType *)
      &Wheelspeed2_DW.Subsystem3.Subsystem_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &Wheelspeed2_DW.Subsystem3.Subsystem_SubsysRanBC;
    systemRan[17] = (sysRanDType *)&Wheelspeed2_DW.Subsystem4_SubsysRanBC;
    rteiSetModelMappingInfoPtr(Wheelspeed2_M->extModeInfo,
      &Wheelspeed2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Wheelspeed2_M->extModeInfo,
                        Wheelspeed2_M->Sizes.checksums);
    rteiSetTPtr(Wheelspeed2_M->extModeInfo, rtmGetTPtr(Wheelspeed2_M));
  }

  /* block I/O */
  (void) memset(((void *) &Wheelspeed2_B), 0,
                sizeof(B_Wheelspeed2_T));

  /* states (dwork) */
  (void) memset((void *)&Wheelspeed2_DW, 0,
                sizeof(DW_Wheelspeed2_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Wheelspeed2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (arduinodigitalinput_sfcn): '<Root>/Digital Input' */
  MW_pinModeInput(Wheelspeed2_P.DigitalInput_p1);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<Root>/Digital Input1' */
  MW_pinModeInput(Wheelspeed2_P.DigitalInput1_p1);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<Root>/Digital Input2' */
  MW_pinModeInput(Wheelspeed2_P.DigitalInput2_p1);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<Root>/Digital Input3' */
  MW_pinModeInput(Wheelspeed2_P.DigitalInput3_p1);

  /* Start for RateTransition: '<Root>/Rate Transition' */
  Wheelspeed2_B.RateTransition = Wheelspeed2_P.RateTransition_X0;

  /* Start for Triggered SubSystem: '<Root>/Subsystem3' */
  Wheelspeed2_Subsystem_Start(&Wheelspeed2_B.Subsystem3,
    (P_Subsystem_Wheelspeed2_T *)&Wheelspeed2_P.Subsystem3);

  /* End of Start for SubSystem: '<Root>/Subsystem3' */

  /* Start for Triggered SubSystem: '<Root>/Subsystem' */
  Wheelspeed2_Subsystem_Start(&Wheelspeed2_B.Subsystem,
    (P_Subsystem_Wheelspeed2_T *)&Wheelspeed2_P.Subsystem);

  /* End of Start for SubSystem: '<Root>/Subsystem' */

  /* Start for Triggered SubSystem: '<Root>/Subsystem1' */
  Wheelspeed2_Subsystem_Start(&Wheelspeed2_B.Subsystem1,
    (P_Subsystem_Wheelspeed2_T *)&Wheelspeed2_P.Subsystem1);

  /* End of Start for SubSystem: '<Root>/Subsystem1' */

  /* Start for Triggered SubSystem: '<Root>/Subsystem2' */
  Wheelspeed2_Subsystem_Start(&Wheelspeed2_B.Subsystem2,
    (P_Subsystem_Wheelspeed2_T *)&Wheelspeed2_P.Subsystem2);

  /* End of Start for SubSystem: '<Root>/Subsystem2' */

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  Wheelspeed2_DW.clockTickCounter = 0L;

  /* Start for Triggered SubSystem: '<Root>/Subsystem4' */
  /* VirtualOutportStart for Outport: '<S11>/Out1' */
  Wheelspeed2_B.Gain = Wheelspeed2_P.Out1_Y0;

  /* VirtualOutportStart for Outport: '<S11>/Out2' */
  Wheelspeed2_B.Gain1 = Wheelspeed2_P.Out2_Y0;

  /* VirtualOutportStart for Outport: '<S11>/Out3' */
  Wheelspeed2_B.Gain2 = Wheelspeed2_P.Out3_Y0;

  /* VirtualOutportStart for Outport: '<S11>/Out4' */
  Wheelspeed2_B.Gain3 = Wheelspeed2_P.Out4_Y0;

  /* End of Start for SubSystem: '<Root>/Subsystem4' */
  /* Start for FromWorkspace: '<S6>/FromWs' */
  {
    static real_T pTimeValues0[] = { 0.0, 1.0, 1.0, 2.0, 2.0, 4.0, 4.0, 6.0, 6.0,
      7.0 } ;

    static real_T pDataValues0[] = { 0.0, 128.0, 128.0, 128.0, 128.0, 255.0,
      255.0, 255.0, 255.0, 0.0 } ;

    Wheelspeed2_DW.FromWs_PWORK.TimePtr = (void *) pTimeValues0;
    Wheelspeed2_DW.FromWs_PWORK.DataPtr = (void *) pDataValues0;
    Wheelspeed2_DW.FromWs_IWORK.PrevIndex = 0;
  }

  /* Start for Atomic SubSystem: '<S5>/hl' */
  Wheelspeed2_hl_Start((P_hl_Wheelspeed2_T *)&Wheelspeed2_P.hl);

  /* End of Start for SubSystem: '<S5>/hl' */

  /* Start for Atomic SubSystem: '<S5>/hr' */
  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S22>/Digital Output' */
  MW_pinModeOutput(Wheelspeed2_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S23>/PWM' */
  MW_pinModeOutput(Wheelspeed2_P.PWM_pinNumber);

  /* Start for Atomic SubSystem: '<S5>/vl' */
  Wheelspeed2_hl_Start((P_hl_Wheelspeed2_T *)&Wheelspeed2_P.vl);

  /* End of Start for SubSystem: '<S5>/vl' */

  /* Start for Atomic SubSystem: '<S5>/vr' */
  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S26>/Digital Output' */
  MW_pinModeOutput(Wheelspeed2_P.DigitalOutput_pinNumber_n);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S27>/PWM' */
  MW_pinModeOutput(Wheelspeed2_P.PWM_pinNumber_g);
  Wheelspeed2_PrevZCX.Subsystem4_Trig_ZCE = UNINITIALIZED_ZCSIG;
  Wheelspeed2_PrevZCX.Subsystem3.Subsystem_Trig_ZCE = POS_ZCSIG;
  Wheelspeed2_PrevZCX.Subsystem2.Subsystem_Trig_ZCE = POS_ZCSIG;
  Wheelspeed2_PrevZCX.Subsystem1.Subsystem_Trig_ZCE = POS_ZCSIG;
  Wheelspeed2_PrevZCX.Subsystem.Subsystem_Trig_ZCE = POS_ZCSIG;

  /* InitializeConditions for RateTransition: '<Root>/Rate Transition' */
  Wheelspeed2_DW.RateTransition_Buffer0 = Wheelspeed2_P.RateTransition_X0;

  /* InitializeConditions for UnitDelay: '<S1>/Delay Input1' */
  Wheelspeed2_DW.DelayInput1_DSTATE = Wheelspeed2_P.DetectRisePositive_vinit;

  /* InitializeConditions for Triggered SubSystem: '<Root>/Subsystem3' */
  Wheelspeed2_Subsystem_Init(&Wheelspeed2_DW.Subsystem3,
    (P_Subsystem_Wheelspeed2_T *)&Wheelspeed2_P.Subsystem3);

  /* End of InitializeConditions for SubSystem: '<Root>/Subsystem3' */

  /* InitializeConditions for UnitDelay: '<S2>/Delay Input1' */
  Wheelspeed2_DW.DelayInput1_DSTATE_e = Wheelspeed2_P.DetectRisePositive1_vinit;

  /* InitializeConditions for Triggered SubSystem: '<Root>/Subsystem' */
  Wheelspeed2_Subsystem_Init(&Wheelspeed2_DW.Subsystem,
    (P_Subsystem_Wheelspeed2_T *)&Wheelspeed2_P.Subsystem);

  /* End of InitializeConditions for SubSystem: '<Root>/Subsystem' */

  /* InitializeConditions for UnitDelay: '<S3>/Delay Input1' */
  Wheelspeed2_DW.DelayInput1_DSTATE_h = Wheelspeed2_P.DetectRisePositive2_vinit;

  /* InitializeConditions for Triggered SubSystem: '<Root>/Subsystem1' */
  Wheelspeed2_Subsystem_Init(&Wheelspeed2_DW.Subsystem1,
    (P_Subsystem_Wheelspeed2_T *)&Wheelspeed2_P.Subsystem1);

  /* End of InitializeConditions for SubSystem: '<Root>/Subsystem1' */

  /* InitializeConditions for UnitDelay: '<S4>/Delay Input1' */
  Wheelspeed2_DW.DelayInput1_DSTATE_k = Wheelspeed2_P.DetectRisePositive3_vinit;

  /* InitializeConditions for Triggered SubSystem: '<Root>/Subsystem2' */
  Wheelspeed2_Subsystem_Init(&Wheelspeed2_DW.Subsystem2,
    (P_Subsystem_Wheelspeed2_T *)&Wheelspeed2_P.Subsystem2);

  /* End of InitializeConditions for SubSystem: '<Root>/Subsystem2' */
}

/* Model terminate function */
void Wheelspeed2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
