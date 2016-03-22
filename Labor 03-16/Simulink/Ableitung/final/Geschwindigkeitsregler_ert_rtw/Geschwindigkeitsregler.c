/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Geschwindigkeitsregler.c
 *
 * Code generated for Simulink model 'Geschwindigkeitsregler'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 16 17:58:00 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Geschwindigkeitsregler.h"
#include "Geschwindigkeitsregler_private.h"
#include "Geschwindigkeitsregler_dt.h"

/* Block signals (auto storage) */
B_Geschwindigkeitsregler_T Geschwindigkeitsregler_B;

/* Block states (auto storage) */
DW_Geschwindigkeitsregler_T Geschwindigkeitsregler_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Geschwindigkeitsregle_T Geschwindigkeitsregler_PrevZCX;

/* Real-time model */
RT_MODEL_Geschwindigkeitsregl_T Geschwindigkeitsregler_M_;
RT_MODEL_Geschwindigkeitsregl_T *const Geschwindigkeitsregler_M =
  &Geschwindigkeitsregler_M_;

/*
 * Start for atomic system:
 *    '<S1>/hl'
 *    '<S1>/vl'
 */
void Geschwindigkeitsregler_hl_Start(P_hl_Geschwindigkeitsregler_T *localP)
{
  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S12>/Digital Output' */
  MW_pinModeOutput(localP->DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S13>/PWM' */
  MW_pinModeOutput(localP->PWM_pinNumber);
}

/*
 * Output and update for atomic system:
 *    '<S1>/hl'
 *    '<S1>/vl'
 */
void Geschwindigkeitsregler_hl(real_T rtu_enable, real_T rtu_power, real_T
  rtu_direction, B_hl_Geschwindigkeitsregler_T *localB,
  P_hl_Geschwindigkeitsregler_T *localP)
{
  real_T rtu_enable_0;
  uint8_T rtu_enable_1;

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S8>/Constant2'
   */
  if (rtu_enable > localP->Switch_Threshold) {
    rtu_enable_0 = rtu_direction;
  } else {
    rtu_enable_0 = localP->Constant2_Value;
  }

  /* End of Switch: '<S8>/Switch' */

  /* DataTypeConversion: '<S12>/Data Type Conversion' */
  if (rtu_enable_0 < 256.0) {
    if (rtu_enable_0 >= 0.0) {
      rtu_enable_1 = (uint8_T)rtu_enable_0;
    } else {
      rtu_enable_1 = 0U;
    }
  } else {
    rtu_enable_1 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S12>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S12>/Digital Output' */
  MW_digitalWrite(localP->DigitalOutput_pinNumber, rtu_enable_1);

  /* Switch: '<S8>/Switch1' incorporates:
   *  Constant: '<S8>/Constant3'
   *  DataTypeConversion: '<S13>/Data Type Conversion'
   */
  if (rtu_enable > localP->Switch1_Threshold) {
    /* DataTypeConversion: '<S13>/Data Type Conversion' */
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
    /* DataTypeConversion: '<S13>/Data Type Conversion' incorporates:
     *  Constant: '<S8>/Constant3'
     */
    if (localP->Constant3_Value >= 0.0) {
      localB->DataTypeConversion = (uint8_T)localP->Constant3_Value;
    } else {
      localB->DataTypeConversion = 0U;
    }
  } else {
    /* DataTypeConversion: '<S13>/Data Type Conversion' */
    localB->DataTypeConversion = MAX_uint8_T;
  }

  /* End of Switch: '<S8>/Switch1' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S13>/PWM' */
  MW_analogWrite(localP->PWM_pinNumber, localB->DataTypeConversion);
}

/*
 * Initial conditions for trigger system:
 *    '<S20>/Subsystem'
 *    '<S20>/Subsystem3'
 */
void Geschwindigkeits_Subsystem_Init(DW_Subsystem_Geschwindigkeits_T *localDW,
  P_Subsystem_Geschwindigkeitsr_T *localP)
{
  /* InitializeConditions for Delay: '<S29>/Delay' */
  localDW->Delay_DSTATE = localP->Delay_InitialCondition;
}

/*
 * Start for trigger system:
 *    '<S20>/Subsystem'
 *    '<S20>/Subsystem3'
 */
void Geschwindigkeit_Subsystem_Start(B_Subsystem_Geschwindigkeitsr_T *localB,
  P_Subsystem_Geschwindigkeitsr_T *localP)
{
  /* VirtualOutportStart for Outport: '<S29>/Out1' */
  localB->Add = localP->Out1_Y0;
}

/*
 * Output and update for trigger system:
 *    '<S20>/Subsystem'
 *    '<S20>/Subsystem3'
 */
void Geschwindigkeitsregle_Subsystem(boolean_T rtu_Trigger, real_T rtu_reset,
  B_Subsystem_Geschwindigkeitsr_T *localB, DW_Subsystem_Geschwindigkeits_T
  *localDW, P_Subsystem_Geschwindigkeitsr_T *localP,
  ZCE_Subsystem_Geschwindigkeit_T *localZCE)
{
  real_T rtu_reset_0;

  /* Outputs for Triggered SubSystem: '<S20>/Subsystem' incorporates:
   *  TriggerPort: '<S29>/Trigger'
   */
  if (rtu_Trigger && (localZCE->Subsystem_Trig_ZCE != POS_ZCSIG)) {
    /* Switch: '<S29>/Switch' incorporates:
     *  Constant: '<S29>/Constant1'
     *  Delay: '<S29>/Delay'
     */
    if (rtu_reset > localP->Switch_Threshold) {
      rtu_reset_0 = localP->Constant1_Value;
    } else {
      rtu_reset_0 = localDW->Delay_DSTATE;
    }

    /* End of Switch: '<S29>/Switch' */

    /* Sum: '<S29>/Add' incorporates:
     *  Constant: '<S29>/Constant'
     */
    localB->Add = rtu_reset_0 + localP->Constant_Value;

    /* Update for Delay: '<S29>/Delay' */
    localDW->Delay_DSTATE = localB->Add;
    localDW->Subsystem_SubsysRanBC = 4;
  }

  localZCE->Subsystem_Trig_ZCE = rtu_Trigger;

  /* End of Outputs for SubSystem: '<S20>/Subsystem' */
}

/* Model step function */
void Geschwindigkeitsregler_step(void)
{
  /* local block i/o variables */
  real_T rtb_FromWs;
  boolean_T rtb_Compare;
  boolean_T rtb_FixPtRelationalOperator;
  boolean_T rtb_Compare_c;
  boolean_T rtb_FixPtRelationalOperator_k;
  boolean_T rtb_Compare_f;
  boolean_T rtb_Compare_p;

  {
    int_T i;
    boolean_T rtb_HL_0;
    real_T rtb_Switch2;
    uint8_T tmp;

    /* Reset subsysRan breadcrumbs */
    srClearBC(Geschwindigkeitsregler_DW.Subsystem.Subsystem_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Geschwindigkeitsregler_DW.Subsystem1_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(Geschwindigkeitsregler_DW.Subsystem2_SubsysRanBC);

    /* FromWorkspace: '<S3>/FromWs' */
    {
      real_T *pDataValues = (real_T *)
        Geschwindigkeitsregler_DW.FromWs_PWORK.DataPtr;
      real_T *pTimeValues = (real_T *)
        Geschwindigkeitsregler_DW.FromWs_PWORK.TimePtr;
      int_T currTimeIndex = Geschwindigkeitsregler_DW.FromWs_IWORK.PrevIndex;
      real_T t = Geschwindigkeitsregler_M->Timing.t[0];

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

      Geschwindigkeitsregler_DW.FromWs_IWORK.PrevIndex = currTimeIndex;

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

    /* Constant: '<Root>/enable' incorporates:
     *  Constant: '<Root>/direction'
     */
    Geschwindigkeitsregler_hl(Geschwindigkeitsregler_P.enable_Value, rtb_FromWs,
      Geschwindigkeitsregler_P.direction_Value, &Geschwindigkeitsregler_B.hl,
      (P_hl_Geschwindigkeitsregler_T *)&Geschwindigkeitsregler_P.hl);

    /* End of Outputs for SubSystem: '<S1>/hl' */

    /* Gain: '<S7>/Gain2' incorporates:
     *  Constant: '<S7>/Constant'
     *  Constant: '<S7>/Constant1'
     *  Product: '<S7>/Divide'
     */
    Geschwindigkeitsregler_B.Gain2 = rtb_FromWs *
      Geschwindigkeitsregler_P.Constant1_Value /
      Geschwindigkeitsregler_P.Constant_Value *
      Geschwindigkeitsregler_P.Gain2_Gain;

    /* DiscreteStateSpace: '<S22>/Zustandsvariablenfilter' */
    for (i = 0; i < 3; i++) {
      Geschwindigkeitsregler_B.Zustandsvariablenfilter[i] = 0.0;
      Geschwindigkeitsregler_B.Zustandsvariablenfilter[i] +=
        Geschwindigkeitsregler_P.Zustandsvariablenfilter_C[i] *
        Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTATE[0];
      Geschwindigkeitsregler_B.Zustandsvariablenfilter[i] +=
        Geschwindigkeitsregler_P.Zustandsvariablenfilter_C[i + 3] *
        Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTATE[1];
      Geschwindigkeitsregler_B.Zustandsvariablenfilter[i] +=
        Geschwindigkeitsregler_P.Zustandsvariablenfilter_C[i + 6] *
        Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTATE[2];
    }

    /* End of DiscreteStateSpace: '<S22>/Zustandsvariablenfilter' */

    /* Gain: '<S7>/Gain1' */
    Geschwindigkeitsregler_B.Gain1 = Geschwindigkeitsregler_P.Gain1_Gain *
      Geschwindigkeitsregler_B.Zustandsvariablenfilter[1];

    /* Gain: '<S7>/Gain' incorporates:
     *  Sum: '<S7>/Sum'
     */
    Geschwindigkeitsregler_B.Gain = (Geschwindigkeitsregler_B.Gain2 +
      Geschwindigkeitsregler_B.Gain1) * Geschwindigkeitsregler_P.Gain_Gain;

    /* Outputs for Atomic SubSystem: '<S1>/hr' */
    /* Switch: '<S9>/Switch' incorporates:
     *  Constant: '<Root>/direction'
     *  Constant: '<Root>/enable'
     *  Constant: '<S9>/Constant2'
     */
    if (Geschwindigkeitsregler_P.enable_Value >
        Geschwindigkeitsregler_P.Switch_Threshold) {
      rtb_Switch2 = Geschwindigkeitsregler_P.direction_Value;
    } else {
      rtb_Switch2 = Geschwindigkeitsregler_P.Constant2_Value;
    }

    /* End of Switch: '<S9>/Switch' */

    /* DataTypeConversion: '<S14>/Data Type Conversion' */
    if (rtb_Switch2 < 256.0) {
      if (rtb_Switch2 >= 0.0) {
        tmp = (uint8_T)rtb_Switch2;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    /* End of DataTypeConversion: '<S14>/Data Type Conversion' */

    /* S-Function (arduinodigitaloutput_sfcn): '<S14>/Digital Output' */
    MW_digitalWrite(Geschwindigkeitsregler_P.DigitalOutput_pinNumber, tmp);

    /* Switch: '<S9>/Switch1' incorporates:
     *  Constant: '<Root>/enable'
     *  Constant: '<S9>/Constant3'
     *  DataTypeConversion: '<S15>/Data Type Conversion'
     */
    if (Geschwindigkeitsregler_P.enable_Value >
        Geschwindigkeitsregler_P.Switch1_Threshold) {
      /* DataTypeConversion: '<S15>/Data Type Conversion' */
      if (Geschwindigkeitsregler_B.Gain < 256.0) {
        if (Geschwindigkeitsregler_B.Gain >= 0.0) {
          Geschwindigkeitsregler_B.DataTypeConversion_i = (uint8_T)
            Geschwindigkeitsregler_B.Gain;
        } else {
          Geschwindigkeitsregler_B.DataTypeConversion_i = 0U;
        }
      } else {
        Geschwindigkeitsregler_B.DataTypeConversion_i = MAX_uint8_T;
      }
    } else if (Geschwindigkeitsregler_P.Constant3_Value < 256.0) {
      /* DataTypeConversion: '<S15>/Data Type Conversion' incorporates:
       *  Constant: '<S9>/Constant3'
       */
      if (Geschwindigkeitsregler_P.Constant3_Value >= 0.0) {
        Geschwindigkeitsregler_B.DataTypeConversion_i = (uint8_T)
          Geschwindigkeitsregler_P.Constant3_Value;
      } else {
        Geschwindigkeitsregler_B.DataTypeConversion_i = 0U;
      }
    } else {
      /* DataTypeConversion: '<S15>/Data Type Conversion' */
      Geschwindigkeitsregler_B.DataTypeConversion_i = MAX_uint8_T;
    }

    /* End of Switch: '<S9>/Switch1' */

    /* S-Function (arduinoanalogoutput_sfcn): '<S15>/PWM' */
    MW_analogWrite(Geschwindigkeitsregler_P.PWM_pinNumber,
                   Geschwindigkeitsregler_B.DataTypeConversion_i);

    /* End of Outputs for SubSystem: '<S1>/hr' */

    /* Outputs for Atomic SubSystem: '<S1>/vl' */

    /* Constant: '<Root>/enable' incorporates:
     *  Constant: '<Root>/direction'
     */
    Geschwindigkeitsregler_hl(Geschwindigkeitsregler_P.enable_Value, rtb_FromWs,
      Geschwindigkeitsregler_P.direction_Value, &Geschwindigkeitsregler_B.vl,
      (P_hl_Geschwindigkeitsregler_T *)&Geschwindigkeitsregler_P.vl);

    /* End of Outputs for SubSystem: '<S1>/vl' */

    /* Outputs for Atomic SubSystem: '<S1>/vr' */
    /* Switch: '<S11>/Switch' incorporates:
     *  Constant: '<Root>/direction'
     *  Constant: '<Root>/enable'
     *  Constant: '<S11>/Constant2'
     */
    if (Geschwindigkeitsregler_P.enable_Value >
        Geschwindigkeitsregler_P.Switch_Threshold_n) {
      rtb_Switch2 = Geschwindigkeitsregler_P.direction_Value;
    } else {
      rtb_Switch2 = Geschwindigkeitsregler_P.Constant2_Value_j;
    }

    /* End of Switch: '<S11>/Switch' */

    /* DataTypeConversion: '<S18>/Data Type Conversion' */
    if (rtb_Switch2 < 256.0) {
      if (rtb_Switch2 >= 0.0) {
        tmp = (uint8_T)rtb_Switch2;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint8_T;
    }

    /* End of DataTypeConversion: '<S18>/Data Type Conversion' */

    /* S-Function (arduinodigitaloutput_sfcn): '<S18>/Digital Output' */
    MW_digitalWrite(Geschwindigkeitsregler_P.DigitalOutput_pinNumber_n, tmp);

    /* Switch: '<S11>/Switch1' incorporates:
     *  Constant: '<Root>/enable'
     *  Constant: '<S11>/Constant3'
     *  DataTypeConversion: '<S19>/Data Type Conversion'
     */
    if (Geschwindigkeitsregler_P.enable_Value >
        Geschwindigkeitsregler_P.Switch1_Threshold_k) {
      /* DataTypeConversion: '<S19>/Data Type Conversion' */
      if (rtb_FromWs < 256.0) {
        if (rtb_FromWs >= 0.0) {
          Geschwindigkeitsregler_B.DataTypeConversion = (uint8_T)rtb_FromWs;
        } else {
          Geschwindigkeitsregler_B.DataTypeConversion = 0U;
        }
      } else {
        Geschwindigkeitsregler_B.DataTypeConversion = MAX_uint8_T;
      }
    } else if (Geschwindigkeitsregler_P.Constant3_Value_k < 256.0) {
      /* DataTypeConversion: '<S19>/Data Type Conversion' incorporates:
       *  Constant: '<S11>/Constant3'
       */
      if (Geschwindigkeitsregler_P.Constant3_Value_k >= 0.0) {
        Geschwindigkeitsregler_B.DataTypeConversion = (uint8_T)
          Geschwindigkeitsregler_P.Constant3_Value_k;
      } else {
        Geschwindigkeitsregler_B.DataTypeConversion = 0U;
      }
    } else {
      /* DataTypeConversion: '<S19>/Data Type Conversion' */
      Geschwindigkeitsregler_B.DataTypeConversion = MAX_uint8_T;
    }

    /* End of Switch: '<S11>/Switch1' */

    /* S-Function (arduinoanalogoutput_sfcn): '<S19>/PWM' */
    MW_analogWrite(Geschwindigkeitsregler_P.PWM_pinNumber_g,
                   Geschwindigkeitsregler_B.DataTypeConversion);

    /* End of Outputs for SubSystem: '<S1>/vr' */

    /* DiscreteStateSpace: '<S21>/Zustandsvariablenfilter' */
    for (i = 0; i < 3; i++) {
      Geschwindigkeitsregler_B.Zustandsvariablenfilter_d[i] = 0.0;
      Geschwindigkeitsregler_B.Zustandsvariablenfilter_d[i] +=
        Geschwindigkeitsregler_P.Zustandsvariablenfilter_C_l[i] *
        Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_e[0];
      Geschwindigkeitsregler_B.Zustandsvariablenfilter_d[i] +=
        Geschwindigkeitsregler_P.Zustandsvariablenfilter_C_l[i + 3] *
        Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_e[1];
      Geschwindigkeitsregler_B.Zustandsvariablenfilter_d[i] +=
        Geschwindigkeitsregler_P.Zustandsvariablenfilter_C_l[i + 6] *
        Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_e[2];
    }

    /* End of DiscreteStateSpace: '<S21>/Zustandsvariablenfilter' */

    /* S-Function (arduinodigitalinput_sfcn): '<S20>/HL' */
    rtb_HL_0 = MW_digitalRead(Geschwindigkeitsregler_P.HL_p1);

    /* RelationalOperator: '<S33>/Compare' incorporates:
     *  Constant: '<S33>/Constant'
     *  S-Function (arduinodigitalinput_sfcn): '<S20>/HL'
     */
    rtb_Compare = ((int16_T)rtb_HL_0 > (int16_T)
                   Geschwindigkeitsregler_P.Constant_Value_k);

    /* RelationalOperator: '<S25>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S25>/Delay Input1'
     */
    rtb_FixPtRelationalOperator = ((int16_T)rtb_Compare > (int16_T)
      Geschwindigkeitsregler_DW.DelayInput1_DSTATE);

    /* S-Function (arduinodigitalinput_sfcn): '<S20>/HR' */
    rtb_HL_0 = MW_digitalRead(Geschwindigkeitsregler_P.HR_p1);

    /* RelationalOperator: '<S34>/Compare' incorporates:
     *  Constant: '<S34>/Constant'
     *  S-Function (arduinodigitalinput_sfcn): '<S20>/HR'
     */
    rtb_Compare_c = ((int16_T)rtb_HL_0 > (int16_T)
                     Geschwindigkeitsregler_P.Constant_Value_fr);

    /* RelationalOperator: '<S26>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S26>/Delay Input1'
     */
    rtb_FixPtRelationalOperator_k = ((int16_T)rtb_Compare_c > (int16_T)
      Geschwindigkeitsregler_DW.DelayInput1_DSTATE_c);

    /* S-Function (arduinodigitalinput_sfcn): '<S20>/VR' */
    rtb_HL_0 = MW_digitalRead(Geschwindigkeitsregler_P.VR_p1);

    /* RelationalOperator: '<S35>/Compare' incorporates:
     *  Constant: '<S35>/Constant'
     *  S-Function (arduinodigitalinput_sfcn): '<S20>/VR'
     */
    rtb_Compare_f = ((int16_T)rtb_HL_0 > (int16_T)
                     Geschwindigkeitsregler_P.Constant_Value_o);

    /* S-Function (arduinodigitalinput_sfcn): '<S20>/VL' */
    rtb_HL_0 = MW_digitalRead(Geschwindigkeitsregler_P.VL_p1);

    /* RelationalOperator: '<S36>/Compare' incorporates:
     *  Constant: '<S36>/Constant'
     *  S-Function (arduinodigitalinput_sfcn): '<S20>/VL'
     */
    rtb_Compare_p = ((int16_T)rtb_HL_0 > (int16_T)
                     Geschwindigkeitsregler_P.Constant_Value_fp);

    /* Outputs for Triggered SubSystem: '<S20>/Subsystem' */

    /* Constant: '<S20>/Constant' */
    Geschwindigkeitsregle_Subsystem(rtb_FixPtRelationalOperator_k,
      Geschwindigkeitsregler_P.Constant_Value_j,
      &Geschwindigkeitsregler_B.Subsystem, &Geschwindigkeitsregler_DW.Subsystem,
      (P_Subsystem_Geschwindigkeitsr_T *)&Geschwindigkeitsregler_P.Subsystem,
      &Geschwindigkeitsregler_PrevZCX.Subsystem);

    /* End of Outputs for SubSystem: '<S20>/Subsystem' */

    /* Outputs for Triggered SubSystem: '<S20>/Subsystem3' */
    Geschwindigkeitsregle_Subsystem(rtb_FixPtRelationalOperator,
      Geschwindigkeitsregler_P.Constant_Value_j,
      &Geschwindigkeitsregler_B.Subsystem3,
      &Geschwindigkeitsregler_DW.Subsystem3, (P_Subsystem_Geschwindigkeitsr_T *)
      &Geschwindigkeitsregler_P.Subsystem3,
      &Geschwindigkeitsregler_PrevZCX.Subsystem3);

    /* End of Outputs for SubSystem: '<S20>/Subsystem3' */

    /* DiscreteStateSpace: '<S21>/r+1 Altwerte' */
    {
      Geschwindigkeitsregler_B.r1Altwerte[0] =
        Geschwindigkeitsregler_P.r1Altwerte_C[0]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[0]
        + Geschwindigkeitsregler_P.r1Altwerte_C[4]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[1]
        + Geschwindigkeitsregler_P.r1Altwerte_C[8]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[2]
        + Geschwindigkeitsregler_P.r1Altwerte_C[12]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[3];
      Geschwindigkeitsregler_B.r1Altwerte[1] =
        Geschwindigkeitsregler_P.r1Altwerte_C[1]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[0]
        + Geschwindigkeitsregler_P.r1Altwerte_C[5]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[1]
        + Geschwindigkeitsregler_P.r1Altwerte_C[9]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[2]
        + Geschwindigkeitsregler_P.r1Altwerte_C[13]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[3];
      Geschwindigkeitsregler_B.r1Altwerte[2] =
        Geschwindigkeitsregler_P.r1Altwerte_C[2]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[0]
        + Geschwindigkeitsregler_P.r1Altwerte_C[6]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[1]
        + Geschwindigkeitsregler_P.r1Altwerte_C[10]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[2]
        + Geschwindigkeitsregler_P.r1Altwerte_C[14]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[3];
      Geschwindigkeitsregler_B.r1Altwerte[3] =
        Geschwindigkeitsregler_P.r1Altwerte_C[3]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[0]
        + Geschwindigkeitsregler_P.r1Altwerte_C[7]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[1]
        + Geschwindigkeitsregler_P.r1Altwerte_C[11]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[2]
        + Geschwindigkeitsregler_P.r1Altwerte_C[15]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[3];
    }

    /* DiscreteStateSpace: '<S22>/r+1 Altwerte' */
    {
      Geschwindigkeitsregler_B.r1Altwerte_n[0] =
        Geschwindigkeitsregler_P.r1Altwerte_C_b[0]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[0]
        + Geschwindigkeitsregler_P.r1Altwerte_C_b[4]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[1]
        + Geschwindigkeitsregler_P.r1Altwerte_C_b[8]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[2]
        + Geschwindigkeitsregler_P.r1Altwerte_C_b[12]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[3];
      Geschwindigkeitsregler_B.r1Altwerte_n[1] =
        Geschwindigkeitsregler_P.r1Altwerte_C_b[1]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[0]
        + Geschwindigkeitsregler_P.r1Altwerte_C_b[5]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[1]
        + Geschwindigkeitsregler_P.r1Altwerte_C_b[9]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[2]
        + Geschwindigkeitsregler_P.r1Altwerte_C_b[13]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[3];
      Geschwindigkeitsregler_B.r1Altwerte_n[2] =
        Geschwindigkeitsregler_P.r1Altwerte_C_b[2]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[0]
        + Geschwindigkeitsregler_P.r1Altwerte_C_b[6]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[1]
        + Geschwindigkeitsregler_P.r1Altwerte_C_b[10]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[2]
        + Geschwindigkeitsregler_P.r1Altwerte_C_b[14]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[3];
      Geschwindigkeitsregler_B.r1Altwerte_n[3] =
        Geschwindigkeitsregler_P.r1Altwerte_C_b[3]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[0]
        + Geschwindigkeitsregler_P.r1Altwerte_C_b[7]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[1]
        + Geschwindigkeitsregler_P.r1Altwerte_C_b[11]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[2]
        + Geschwindigkeitsregler_P.r1Altwerte_C_b[15]*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[3];
    }

    /* Product: '<S6>/Divide' incorporates:
     *  Constant: '<S6>/Constant'
     *  Constant: '<S6>/Constant1'
     */
    Geschwindigkeitsregler_B.Divide = 0.0 *
      Geschwindigkeitsregler_P.Constant1_Value_c /
      Geschwindigkeitsregler_P.Constant_Value_f;

    /* Sum: '<S6>/diffferenzN' */
    Geschwindigkeitsregler_B.diffferenzN = Geschwindigkeitsregler_B.Divide;

    /* Switch: '<S6>/Switch' incorporates:
     *  Constant: '<S6>/NMAX'
     *  Constant: '<S6>/powerMAX'
     *  Constant: '<S6>/powerMAX1'
     *  Constant: '<S6>/powerMAX2'
     *  Product: '<S6>/Divide1'
     */
    if (Geschwindigkeitsregler_B.diffferenzN *
        Geschwindigkeitsregler_P.powerMAX_Value /
        Geschwindigkeitsregler_P.NMAX_Value >
        Geschwindigkeitsregler_P.Switch_Threshold_b) {
      rtb_Switch2 = Geschwindigkeitsregler_P.powerMAX1_Value;
    } else {
      rtb_Switch2 = Geschwindigkeitsregler_P.powerMAX2_Value;
    }

    /* End of Switch: '<S6>/Switch' */

    /* Sum: '<S6>/new POWER' incorporates:
     *  Delay: '<S6>/Delay'
     */
    rtb_Switch2 += Geschwindigkeitsregler_DW.Delay_DSTATE[0];

    /* Switch: '<S6>/Switch2' incorporates:
     *  Constant: '<S6>/powerMAX4'
     */
    if (!(rtb_Switch2 > Geschwindigkeitsregler_P.Switch2_Threshold)) {
      rtb_Switch2 = Geschwindigkeitsregler_P.powerMAX4_Value;
    }

    /* End of Switch: '<S6>/Switch2' */

    /* Switch: '<S6>/Switch1' incorporates:
     *  Constant: '<S6>/powerMAX3'
     */
    if (rtb_Switch2 > Geschwindigkeitsregler_P.Switch1_Threshold_kd) {
      Geschwindigkeitsregler_B.Switch1 =
        Geschwindigkeitsregler_P.powerMAX3_Value;
    } else {
      Geschwindigkeitsregler_B.Switch1 = rtb_Switch2;
    }

    /* End of Switch: '<S6>/Switch1' */
  }

  {
    int_T i;
    real_T xnew[3];
    real_T xnew_0[3];
    real_T xnew_1;

    /* Update for DiscreteStateSpace: '<S22>/Zustandsvariablenfilter' incorporates:
     *  Update for DiscreteStateSpace: '<S21>/Zustandsvariablenfilter'
     */
    for (i = 0; i < 3; i++) {
      xnew_1 = Geschwindigkeitsregler_P.BD[i] *
        Geschwindigkeitsregler_B.r1Altwerte_n[0] +
        (Geschwindigkeitsregler_P.AD[i + 6] *
         Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTATE[2] +
         (Geschwindigkeitsregler_P.AD[i + 3] *
          Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTATE[1] +
          Geschwindigkeitsregler_P.AD[i] *
          Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTATE[0]));
      xnew_1 += Geschwindigkeitsregler_P.BD[i + 3] *
        Geschwindigkeitsregler_B.r1Altwerte_n[1];
      xnew_1 += Geschwindigkeitsregler_P.BD[i + 6] *
        Geschwindigkeitsregler_B.r1Altwerte_n[2];
      xnew_1 += Geschwindigkeitsregler_P.BD[i + 9] *
        Geschwindigkeitsregler_B.r1Altwerte_n[3];
      xnew[i] = xnew_1;
    }

    for (i = 0; i < 3; i++) {
      Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTATE[i] = xnew[i];
      xnew_1 = Geschwindigkeitsregler_P.BD[i] *
        Geschwindigkeitsregler_B.r1Altwerte[0] + (Geschwindigkeitsregler_P.AD[i
        + 6] * Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_e[2] +
        (Geschwindigkeitsregler_P.AD[i + 3] *
         Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_e[1] +
         Geschwindigkeitsregler_P.AD[i] *
         Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_e[0]));
      xnew_1 += Geschwindigkeitsregler_P.BD[i + 3] *
        Geschwindigkeitsregler_B.r1Altwerte[1];
      xnew_1 += Geschwindigkeitsregler_P.BD[i + 6] *
        Geschwindigkeitsregler_B.r1Altwerte[2];
      xnew_1 += Geschwindigkeitsregler_P.BD[i + 9] *
        Geschwindigkeitsregler_B.r1Altwerte[3];
      xnew_0[i] = xnew_1;
    }

    /* End of Update for DiscreteStateSpace: '<S22>/Zustandsvariablenfilter' */

    /* Update for DiscreteStateSpace: '<S21>/Zustandsvariablenfilter' */
    Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_e[0] = xnew_0[0];
    Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_e[1] = xnew_0[1];
    Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_e[2] = xnew_0[2];

    /* Update for UnitDelay: '<S25>/Delay Input1' */
    Geschwindigkeitsregler_DW.DelayInput1_DSTATE = rtb_Compare;

    /* Update for UnitDelay: '<S26>/Delay Input1' */
    Geschwindigkeitsregler_DW.DelayInput1_DSTATE_c = rtb_Compare_c;

    /* Update for UnitDelay: '<S27>/Delay Input1' */
    Geschwindigkeitsregler_DW.DelayInput1_DSTATE_o = rtb_Compare_f;

    /* Update for UnitDelay: '<S28>/Delay Input1' */
    Geschwindigkeitsregler_DW.DelayInput1_DSTATE_ol = rtb_Compare_p;

    /* Update for DiscreteStateSpace: '<S21>/r+1 Altwerte' */
    {
      real_T xtmp = Geschwindigkeitsregler_B.Subsystem3.Add;
      xtmp += (Geschwindigkeitsregler_P.r1Altwerte_A[0])*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[0]
        + (Geschwindigkeitsregler_P.r1Altwerte_A[1])*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[1]
        + (Geschwindigkeitsregler_P.r1Altwerte_A[2])*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[2]
        + (Geschwindigkeitsregler_P.r1Altwerte_A[3])*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[3];
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[3] =
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[2];
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[2] =
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[1];
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[1] =
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[0];
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[0] = xtmp;
    }

    /* Update for DiscreteStateSpace: '<S22>/r+1 Altwerte' */
    {
      real_T xtmp = Geschwindigkeitsregler_B.Subsystem.Add;
      xtmp += (Geschwindigkeitsregler_P.r1Altwerte_A_i[0])*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[0]
        + (Geschwindigkeitsregler_P.r1Altwerte_A_i[1])*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[1]
        + (Geschwindigkeitsregler_P.r1Altwerte_A_i[2])*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[2]
        + (Geschwindigkeitsregler_P.r1Altwerte_A_i[3])*
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[3];
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[3] =
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[2];
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[2] =
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[1];
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[1] =
        Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[0];
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[0] = xtmp;
    }

    /* Update for Delay: '<S6>/Delay' */
    Geschwindigkeitsregler_DW.Delay_DSTATE[0] =
      Geschwindigkeitsregler_DW.Delay_DSTATE[1];
    Geschwindigkeitsregler_DW.Delay_DSTATE[1] = Geschwindigkeitsregler_B.Switch1;
  }

  /* External mode */
  rtExtModeUploadCheckTrigger(2);

  {                                    /* Sample time: [0.0s, 0.0s] */
    rtExtModeUpload(0, Geschwindigkeitsregler_M->Timing.t[0]);
  }

  {                                    /* Sample time: [0.01s, 0.0s] */
    rtExtModeUpload(1, ((Geschwindigkeitsregler_M->Timing.clockTick1) * 0.01));
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(Geschwindigkeitsregler_M)!=-1) &&
        !((rtmGetTFinal(Geschwindigkeitsregler_M)-
           Geschwindigkeitsregler_M->Timing.t[0]) >
          Geschwindigkeitsregler_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(Geschwindigkeitsregler_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Geschwindigkeitsregler_M)) {
      rtmSetErrorStatus(Geschwindigkeitsregler_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Geschwindigkeitsregler_M->Timing.t[0] =
    (++Geschwindigkeitsregler_M->Timing.clockTick0) *
    Geschwindigkeitsregler_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Geschwindigkeitsregler_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Geschwindigkeitsregler_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Geschwindigkeitsregler_M, 0,
                sizeof(RT_MODEL_Geschwindigkeitsregl_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Geschwindigkeitsregler_M->solverInfo,
                          &Geschwindigkeitsregler_M->Timing.simTimeStep);
    rtsiSetTPtr(&Geschwindigkeitsregler_M->solverInfo, &rtmGetTPtr
                (Geschwindigkeitsregler_M));
    rtsiSetStepSizePtr(&Geschwindigkeitsregler_M->solverInfo,
                       &Geschwindigkeitsregler_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Geschwindigkeitsregler_M->solverInfo,
                          (&rtmGetErrorStatus(Geschwindigkeitsregler_M)));
    rtsiSetRTModelPtr(&Geschwindigkeitsregler_M->solverInfo,
                      Geschwindigkeitsregler_M);
  }

  rtsiSetSimTimeStep(&Geschwindigkeitsregler_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Geschwindigkeitsregler_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Geschwindigkeitsregler_M, &Geschwindigkeitsregler_M->Timing.tArray
             [0]);
  rtmSetTFinal(Geschwindigkeitsregler_M, 10.0);
  Geschwindigkeitsregler_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Geschwindigkeitsregler_M->Sizes.checksums[0] = (4234395340U);
  Geschwindigkeitsregler_M->Sizes.checksums[1] = (4170173558U);
  Geschwindigkeitsregler_M->Sizes.checksums[2] = (1145180606U);
  Geschwindigkeitsregler_M->Sizes.checksums[3] = (3896224851U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[19];
    Geschwindigkeitsregler_M->extModeInfo = (&rt_ExtModeInfo);
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
      &Geschwindigkeitsregler_DW.Subsystem.Subsystem_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &Geschwindigkeitsregler_DW.Subsystem.Subsystem_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &Geschwindigkeitsregler_DW.Subsystem1_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &Geschwindigkeitsregler_DW.Subsystem2_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &Geschwindigkeitsregler_DW.Subsystem3.Subsystem_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &Geschwindigkeitsregler_DW.Subsystem3.Subsystem_SubsysRanBC;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Geschwindigkeitsregler_M->extModeInfo,
      &Geschwindigkeitsregler_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Geschwindigkeitsregler_M->extModeInfo,
                        Geschwindigkeitsregler_M->Sizes.checksums);
    rteiSetTPtr(Geschwindigkeitsregler_M->extModeInfo, rtmGetTPtr
                (Geschwindigkeitsregler_M));
  }

  /* block I/O */
  (void) memset(((void *) &Geschwindigkeitsregler_B), 0,
                sizeof(B_Geschwindigkeitsregler_T));

  /* states (dwork) */
  (void) memset((void *)&Geschwindigkeitsregler_DW, 0,
                sizeof(DW_Geschwindigkeitsregler_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Geschwindigkeitsregler_M->SpecialInfo.mappingInfo = (&dtInfo);
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

    static real_T pDataValues0[] = { -0.0, 71.0, 99.0, 100.5, 21.5, 99.5, 60.5,
      60.5, 98.5, 0.0 } ;

    Geschwindigkeitsregler_DW.FromWs_PWORK.TimePtr = (void *) pTimeValues0;
    Geschwindigkeitsregler_DW.FromWs_PWORK.DataPtr = (void *) pDataValues0;
    Geschwindigkeitsregler_DW.FromWs_IWORK.PrevIndex = 0;
  }

  /* Start for Atomic SubSystem: '<S1>/hl' */
  Geschwindigkeitsregler_hl_Start((P_hl_Geschwindigkeitsregler_T *)
    &Geschwindigkeitsregler_P.hl);

  /* End of Start for SubSystem: '<S1>/hl' */

  /* Start for Atomic SubSystem: '<S1>/hr' */
  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S14>/Digital Output' */
  MW_pinModeOutput(Geschwindigkeitsregler_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S15>/PWM' */
  MW_pinModeOutput(Geschwindigkeitsregler_P.PWM_pinNumber);

  /* End of Start for SubSystem: '<S1>/hr' */

  /* Start for Atomic SubSystem: '<S1>/vl' */
  Geschwindigkeitsregler_hl_Start((P_hl_Geschwindigkeitsregler_T *)
    &Geschwindigkeitsregler_P.vl);

  /* End of Start for SubSystem: '<S1>/vl' */

  /* Start for Atomic SubSystem: '<S1>/vr' */
  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S18>/Digital Output' */
  MW_pinModeOutput(Geschwindigkeitsregler_P.DigitalOutput_pinNumber_n);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S19>/PWM' */
  MW_pinModeOutput(Geschwindigkeitsregler_P.PWM_pinNumber_g);

  /* End of Start for SubSystem: '<S1>/vr' */
  /* Start for S-Function (arduinodigitalinput_sfcn): '<S20>/HL' */
  MW_pinModeInput(Geschwindigkeitsregler_P.HL_p1);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S20>/HR' */
  MW_pinModeInput(Geschwindigkeitsregler_P.HR_p1);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S20>/VR' */
  MW_pinModeInput(Geschwindigkeitsregler_P.VR_p1);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S20>/VL' */
  MW_pinModeInput(Geschwindigkeitsregler_P.VL_p1);

  /* Start for Triggered SubSystem: '<S20>/Subsystem' */
  Geschwindigkeit_Subsystem_Start(&Geschwindigkeitsregler_B.Subsystem,
    (P_Subsystem_Geschwindigkeitsr_T *)&Geschwindigkeitsregler_P.Subsystem);

  /* End of Start for SubSystem: '<S20>/Subsystem' */

  /* Start for Triggered SubSystem: '<S20>/Subsystem3' */
  Geschwindigkeit_Subsystem_Start(&Geschwindigkeitsregler_B.Subsystem3,
    (P_Subsystem_Geschwindigkeitsr_T *)&Geschwindigkeitsregler_P.Subsystem3);

  /* End of Start for SubSystem: '<S20>/Subsystem3' */
  Geschwindigkeitsregler_PrevZCX.Subsystem1_Trig_ZCE = POS_ZCSIG;
  Geschwindigkeitsregler_PrevZCX.Subsystem2_Trig_ZCE = POS_ZCSIG;
  Geschwindigkeitsregler_PrevZCX.Subsystem3.Subsystem_Trig_ZCE = POS_ZCSIG;
  Geschwindigkeitsregler_PrevZCX.Subsystem.Subsystem_Trig_ZCE = POS_ZCSIG;

  /* InitializeConditions for DiscreteStateSpace: '<S22>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTATE[0] =
    Geschwindigkeitsregler_P.AB2[0];

  /* InitializeConditions for DiscreteStateSpace: '<S21>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_e[0] =
    Geschwindigkeitsregler_P.AB2[0];

  /* InitializeConditions for DiscreteStateSpace: '<S22>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTATE[1] =
    Geschwindigkeitsregler_P.AB2[1];

  /* InitializeConditions for DiscreteStateSpace: '<S21>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_e[1] =
    Geschwindigkeitsregler_P.AB2[1];

  /* InitializeConditions for DiscreteStateSpace: '<S22>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTATE[2] =
    Geschwindigkeitsregler_P.AB2[2];

  /* InitializeConditions for DiscreteStateSpace: '<S21>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_e[2] =
    Geschwindigkeitsregler_P.AB2[2];

  /* InitializeConditions for UnitDelay: '<S25>/Delay Input1' */
  Geschwindigkeitsregler_DW.DelayInput1_DSTATE =
    Geschwindigkeitsregler_P.DetectRisePositive_vinit;

  /* InitializeConditions for UnitDelay: '<S26>/Delay Input1' */
  Geschwindigkeitsregler_DW.DelayInput1_DSTATE_c =
    Geschwindigkeitsregler_P.DetectRisePositive1_vinit;

  /* InitializeConditions for UnitDelay: '<S27>/Delay Input1' */
  Geschwindigkeitsregler_DW.DelayInput1_DSTATE_o =
    Geschwindigkeitsregler_P.DetectRisePositive2_vinit;

  /* InitializeConditions for UnitDelay: '<S28>/Delay Input1' */
  Geschwindigkeitsregler_DW.DelayInput1_DSTATE_ol =
    Geschwindigkeitsregler_P.DetectRisePositive3_vinit;

  /* InitializeConditions for Triggered SubSystem: '<S20>/Subsystem' */
  Geschwindigkeits_Subsystem_Init(&Geschwindigkeitsregler_DW.Subsystem,
    (P_Subsystem_Geschwindigkeitsr_T *)&Geschwindigkeitsregler_P.Subsystem);

  /* End of InitializeConditions for SubSystem: '<S20>/Subsystem' */

  /* InitializeConditions for Triggered SubSystem: '<S20>/Subsystem3' */
  Geschwindigkeits_Subsystem_Init(&Geschwindigkeitsregler_DW.Subsystem3,
    (P_Subsystem_Geschwindigkeitsr_T *)&Geschwindigkeitsregler_P.Subsystem3);

  /* End of InitializeConditions for SubSystem: '<S20>/Subsystem3' */

  /* InitializeConditions for DiscreteStateSpace: '<S21>/r+1 Altwerte' */
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[0] = Geschwindigkeitsregler_P.AB1
    [0];
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[1] = Geschwindigkeitsregler_P.AB1
    [1];
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[2] = Geschwindigkeitsregler_P.AB1
    [2];
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[3] = Geschwindigkeitsregler_P.AB1
    [3];

  /* InitializeConditions for DiscreteStateSpace: '<S22>/r+1 Altwerte' */
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[0] =
    Geschwindigkeitsregler_P.AB1[0];
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[1] =
    Geschwindigkeitsregler_P.AB1[1];
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[2] =
    Geschwindigkeitsregler_P.AB1[2];
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[3] =
    Geschwindigkeitsregler_P.AB1[3];

  /* InitializeConditions for Delay: '<S6>/Delay' */
  Geschwindigkeitsregler_DW.Delay_DSTATE[0] =
    Geschwindigkeitsregler_P.Delay_InitialCondition;
  Geschwindigkeitsregler_DW.Delay_DSTATE[1] =
    Geschwindigkeitsregler_P.Delay_InitialCondition;
}

/* Model terminate function */
void Geschwindigkeitsregler_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
