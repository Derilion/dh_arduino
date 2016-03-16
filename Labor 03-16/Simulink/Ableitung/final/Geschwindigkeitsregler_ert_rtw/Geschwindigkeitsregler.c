/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Geschwindigkeitsregler.c
 *
 * Code generated for Simulink model 'Geschwindigkeitsregler'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 16 16:21:22 2016
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
  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S9>/Digital Output' */
  MW_pinModeOutput(localP->DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S10>/PWM' */
  MW_pinModeOutput(localP->PWM_pinNumber);
}

/*
 * Output and update for atomic system:
 *    '<S1>/hl'
 *    '<S1>/vl'
 */
void Geschwindigkeitsregler_hl(real_T rtu_enable, real_T rtu_power, real_T
  rtu_direction, P_hl_Geschwindigkeitsregler_T *localP)
{
  real_T rtu_enable_0;
  uint8_T rtu_enable_1;

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/Constant2'
   */
  if (rtu_enable > localP->Switch_Threshold) {
    rtu_enable_0 = rtu_direction;
  } else {
    rtu_enable_0 = localP->Constant2_Value;
  }

  /* End of Switch: '<S5>/Switch' */

  /* DataTypeConversion: '<S9>/Data Type Conversion' */
  if (rtu_enable_0 < 256.0) {
    if (rtu_enable_0 >= 0.0) {
      rtu_enable_1 = (uint8_T)rtu_enable_0;
    } else {
      rtu_enable_1 = 0U;
    }
  } else {
    rtu_enable_1 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S9>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S9>/Digital Output' */
  MW_digitalWrite(localP->DigitalOutput_pinNumber, rtu_enable_1);

  /* Switch: '<S5>/Switch1' incorporates:
   *  Constant: '<S5>/Constant3'
   */
  if (rtu_enable > localP->Switch1_Threshold) {
    rtu_enable_0 = rtu_power;
  } else {
    rtu_enable_0 = localP->Constant3_Value;
  }

  /* End of Switch: '<S5>/Switch1' */

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  if (rtu_enable_0 < 256.0) {
    if (rtu_enable_0 >= 0.0) {
      rtu_enable_1 = (uint8_T)rtu_enable_0;
    } else {
      rtu_enable_1 = 0U;
    }
  } else {
    rtu_enable_1 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S10>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S10>/PWM' */
  MW_analogWrite(localP->PWM_pinNumber, rtu_enable_1);
}

/*
 * Initial conditions for trigger system:
 *    '<S17>/Subsystem'
 *    '<S17>/Subsystem1'
 *    '<S17>/Subsystem2'
 *    '<S17>/Subsystem3'
 */
void Geschwindigkeits_Subsystem_Init(DW_Subsystem_Geschwindigkeits_T *localDW,
  P_Subsystem_Geschwindigkeitsr_T *localP)
{
  /* InitializeConditions for Delay: '<S26>/Delay' */
  localDW->Delay_DSTATE = localP->Delay_InitialCondition;
}

/*
 * Start for trigger system:
 *    '<S17>/Subsystem'
 *    '<S17>/Subsystem1'
 *    '<S17>/Subsystem2'
 *    '<S17>/Subsystem3'
 */
void Geschwindigkeit_Subsystem_Start(B_Subsystem_Geschwindigkeitsr_T *localB,
  P_Subsystem_Geschwindigkeitsr_T *localP)
{
  /* VirtualOutportStart for Outport: '<S26>/Out1' */
  localB->Add = localP->Out1_Y0;
}

/*
 * Output and update for trigger system:
 *    '<S17>/Subsystem'
 *    '<S17>/Subsystem1'
 *    '<S17>/Subsystem2'
 *    '<S17>/Subsystem3'
 */
void Geschwindigkeitsregle_Subsystem(boolean_T rtu_Trigger, real_T rtu_reset,
  B_Subsystem_Geschwindigkeitsr_T *localB, DW_Subsystem_Geschwindigkeits_T
  *localDW, P_Subsystem_Geschwindigkeitsr_T *localP,
  ZCE_Subsystem_Geschwindigkeit_T *localZCE)
{
  real_T rtu_reset_0;

  /* Outputs for Triggered SubSystem: '<S17>/Subsystem' incorporates:
   *  TriggerPort: '<S26>/Trigger'
   */
  if (rtu_Trigger && (localZCE->Subsystem_Trig_ZCE != POS_ZCSIG)) {
    /* Switch: '<S26>/Switch' incorporates:
     *  Constant: '<S26>/Constant1'
     *  Delay: '<S26>/Delay'
     */
    if (rtu_reset > localP->Switch_Threshold) {
      rtu_reset_0 = localP->Constant1_Value;
    } else {
      rtu_reset_0 = localDW->Delay_DSTATE;
    }

    /* End of Switch: '<S26>/Switch' */

    /* Sum: '<S26>/Add' incorporates:
     *  Constant: '<S26>/Constant'
     */
    localB->Add = rtu_reset_0 + localP->Constant_Value;

    /* Update for Delay: '<S26>/Delay' */
    localDW->Delay_DSTATE = localB->Add;
    localDW->Subsystem_SubsysRanBC = 4;
  }

  localZCE->Subsystem_Trig_ZCE = rtu_Trigger;

  /* End of Outputs for SubSystem: '<S17>/Subsystem' */
}

/* Model step function */
void Geschwindigkeitsregler_step(void)
{
  int_T i;
  real_T xnew[3];
  real_T rtb_Switch2;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_m;
  boolean_T rtb_Compare_f;
  boolean_T rtb_Compare_c;
  real_T rtb_newPOWER;
  uint8_T tmp;

  /* Reset subsysRan breadcrumbs */
  srClearBC(Geschwindigkeitsregler_DW.Subsystem.Subsystem_SubsysRanBC);

  /* Constant: '<Root>/enable' */
  Geschwindigkeitsregler_B.enable = Geschwindigkeitsregler_P.enable_Value;

  /* Outputs for Atomic SubSystem: '<S1>/hl' */

  /* Constant: '<Root>/direction1' incorporates:
   *  Constant: '<Root>/direction'
   */
  Geschwindigkeitsregler_hl(Geschwindigkeitsregler_B.enable,
    Geschwindigkeitsregler_P.direction1_Value,
    Geschwindigkeitsregler_P.direction_Value, (P_hl_Geschwindigkeitsregler_T *)
    &Geschwindigkeitsregler_P.hl);

  /* End of Outputs for SubSystem: '<S1>/hl' */

  /* Product: '<S4>/Divide' incorporates:
   *  Constant: '<Root>/direction1'
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   */
  Geschwindigkeitsregler_B.Divide = Geschwindigkeitsregler_P.direction1_Value *
    Geschwindigkeitsregler_P.Constant1_Value /
    Geschwindigkeitsregler_P.Constant_Value;

  /* DiscreteStateSpace: '<S19>/Zustandsvariablenfilter' */
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

  /* End of DiscreteStateSpace: '<S19>/Zustandsvariablenfilter' */

  /* Sum: '<S4>/diffferenzN' */
  Geschwindigkeitsregler_B.diffferenzN = Geschwindigkeitsregler_B.Divide -
    Geschwindigkeitsregler_B.Zustandsvariablenfilter[1];

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/NMAX'
   *  Constant: '<S4>/powerMAX'
   *  Constant: '<S4>/powerMAX1'
   *  Constant: '<S4>/powerMAX2'
   *  Product: '<S4>/Divide1'
   */
  if (Geschwindigkeitsregler_B.diffferenzN *
      Geschwindigkeitsregler_P.powerMAX_Value /
      Geschwindigkeitsregler_P.NMAX_Value >
      Geschwindigkeitsregler_P.Switch_Threshold_b) {
    rtb_Switch2 = Geschwindigkeitsregler_P.powerMAX1_Value;
  } else {
    rtb_Switch2 = Geschwindigkeitsregler_P.powerMAX2_Value;
  }

  /* End of Switch: '<S4>/Switch' */

  /* Sum: '<S4>/new POWER' incorporates:
   *  Delay: '<S4>/Delay'
   */
  rtb_newPOWER = rtb_Switch2 + Geschwindigkeitsregler_DW.Delay_DSTATE[0];

  /* Switch: '<S4>/Switch2' incorporates:
   *  Constant: '<S4>/powerMAX4'
   */
  if (rtb_newPOWER > Geschwindigkeitsregler_P.Switch2_Threshold) {
    rtb_Switch2 = rtb_newPOWER;
  } else {
    rtb_Switch2 = Geschwindigkeitsregler_P.powerMAX4_Value;
  }

  /* End of Switch: '<S4>/Switch2' */

  /* Switch: '<S4>/Switch1' incorporates:
   *  Constant: '<S4>/powerMAX3'
   */
  if (rtb_Switch2 > Geschwindigkeitsregler_P.Switch1_Threshold_kd) {
    Geschwindigkeitsregler_B.Switch1 = Geschwindigkeitsregler_P.powerMAX3_Value;
  } else {
    Geschwindigkeitsregler_B.Switch1 = rtb_Switch2;
  }

  /* End of Switch: '<S4>/Switch1' */

  /* Outputs for Atomic SubSystem: '<S1>/hr' */
  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<Root>/direction'
   *  Constant: '<S6>/Constant2'
   */
  if (Geschwindigkeitsregler_B.enable >
      Geschwindigkeitsregler_P.Switch_Threshold) {
    rtb_Switch2 = Geschwindigkeitsregler_P.direction_Value;
  } else {
    rtb_Switch2 = Geschwindigkeitsregler_P.Constant2_Value;
  }

  /* End of Switch: '<S6>/Switch' */

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  if (rtb_Switch2 < 256.0) {
    if (rtb_Switch2 >= 0.0) {
      tmp = (uint8_T)rtb_Switch2;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S11>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S11>/Digital Output' */
  MW_digitalWrite(Geschwindigkeitsregler_P.DigitalOutput_pinNumber, tmp);

  /* Switch: '<S6>/Switch1' incorporates:
   *  Constant: '<S6>/Constant3'
   */
  if (Geschwindigkeitsregler_B.enable >
      Geschwindigkeitsregler_P.Switch1_Threshold) {
    rtb_Switch2 = Geschwindigkeitsregler_B.Switch1;
  } else {
    rtb_Switch2 = Geschwindigkeitsregler_P.Constant3_Value;
  }

  /* End of Switch: '<S6>/Switch1' */

  /* DataTypeConversion: '<S12>/Data Type Conversion' */
  if (rtb_Switch2 < 256.0) {
    if (rtb_Switch2 >= 0.0) {
      tmp = (uint8_T)rtb_Switch2;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S12>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S12>/PWM' */
  MW_analogWrite(Geschwindigkeitsregler_P.PWM_pinNumber, tmp);

  /* Outputs for Atomic SubSystem: '<S1>/vl' */

  /* Constant: '<Root>/direction1' incorporates:
   *  Constant: '<Root>/direction'
   */
  Geschwindigkeitsregler_hl(Geschwindigkeitsregler_B.enable,
    Geschwindigkeitsregler_P.direction1_Value,
    Geschwindigkeitsregler_P.direction_Value, (P_hl_Geschwindigkeitsregler_T *)
    &Geschwindigkeitsregler_P.vl);

  /* End of Outputs for SubSystem: '<S1>/vl' */

  /* Outputs for Atomic SubSystem: '<S1>/vr' */
  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<Root>/direction'
   *  Constant: '<S8>/Constant2'
   */
  if (Geschwindigkeitsregler_B.enable >
      Geschwindigkeitsregler_P.Switch_Threshold_n) {
    rtb_Switch2 = Geschwindigkeitsregler_P.direction_Value;
  } else {
    rtb_Switch2 = Geschwindigkeitsregler_P.Constant2_Value_j;
  }

  /* End of Switch: '<S8>/Switch' */

  /* DataTypeConversion: '<S15>/Data Type Conversion' */
  if (rtb_Switch2 < 256.0) {
    if (rtb_Switch2 >= 0.0) {
      tmp = (uint8_T)rtb_Switch2;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S15>/Digital Output' */
  MW_digitalWrite(Geschwindigkeitsregler_P.DigitalOutput_pinNumber_n, tmp);

  /* Switch: '<S8>/Switch1' incorporates:
   *  Constant: '<Root>/direction1'
   *  Constant: '<S8>/Constant3'
   */
  if (Geschwindigkeitsregler_B.enable >
      Geschwindigkeitsregler_P.Switch1_Threshold_k) {
    rtb_Switch2 = Geschwindigkeitsregler_P.direction1_Value;
  } else {
    rtb_Switch2 = Geschwindigkeitsregler_P.Constant3_Value_k;
  }

  /* End of Switch: '<S8>/Switch1' */

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  if (rtb_Switch2 < 256.0) {
    if (rtb_Switch2 >= 0.0) {
      tmp = (uint8_T)rtb_Switch2;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S16>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S16>/PWM' */
  MW_analogWrite(Geschwindigkeitsregler_P.PWM_pinNumber_g, tmp);

  /* DiscreteStateSpace: '<S20>/Zustandsvariablenfilter' */
  for (i = 0; i < 3; i++) {
    Geschwindigkeitsregler_B.Zustandsvariablenfilter_a[i] = 0.0;
    Geschwindigkeitsregler_B.Zustandsvariablenfilter_a[i] +=
      Geschwindigkeitsregler_P.Zustandsvariablenfilter_C_m[i] *
      Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_o[0];
    Geschwindigkeitsregler_B.Zustandsvariablenfilter_a[i] +=
      Geschwindigkeitsregler_P.Zustandsvariablenfilter_C_m[i + 3] *
      Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_o[1];
    Geschwindigkeitsregler_B.Zustandsvariablenfilter_a[i] +=
      Geschwindigkeitsregler_P.Zustandsvariablenfilter_C_m[i + 6] *
      Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_o[2];
  }

  /* End of DiscreteStateSpace: '<S20>/Zustandsvariablenfilter' */

  /* DiscreteStateSpace: '<S21>/Zustandsvariablenfilter' */
  for (i = 0; i < 3; i++) {
    Geschwindigkeitsregler_B.Zustandsvariablenfilter_d[i] = 0.0;
    Geschwindigkeitsregler_B.Zustandsvariablenfilter_d[i] +=
      Geschwindigkeitsregler_P.Zustandsvariablenfilter_C_p[i] *
      Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_c[0];
    Geschwindigkeitsregler_B.Zustandsvariablenfilter_d[i] +=
      Geschwindigkeitsregler_P.Zustandsvariablenfilter_C_p[i + 3] *
      Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_c[1];
    Geschwindigkeitsregler_B.Zustandsvariablenfilter_d[i] +=
      Geschwindigkeitsregler_P.Zustandsvariablenfilter_C_p[i + 6] *
      Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_c[2];
  }

  /* End of DiscreteStateSpace: '<S21>/Zustandsvariablenfilter' */

  /* DiscreteStateSpace: '<S18>/Zustandsvariablenfilter' */
  for (i = 0; i < 3; i++) {
    Geschwindigkeitsregler_B.Zustandsvariablenfilter_da[i] = 0.0;
    Geschwindigkeitsregler_B.Zustandsvariablenfilter_da[i] +=
      Geschwindigkeitsregler_P.Zustandsvariablenfilter_C_l[i] *
      Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_e[0];
    Geschwindigkeitsregler_B.Zustandsvariablenfilter_da[i] +=
      Geschwindigkeitsregler_P.Zustandsvariablenfilter_C_l[i + 3] *
      Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_e[1];
    Geschwindigkeitsregler_B.Zustandsvariablenfilter_da[i] +=
      Geschwindigkeitsregler_P.Zustandsvariablenfilter_C_l[i + 6] *
      Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_e[2];
  }

  /* End of DiscreteStateSpace: '<S18>/Zustandsvariablenfilter' */

  /* S-Function (arduinodigitalinput_sfcn): '<S17>/HL' */
  Geschwindigkeitsregler_B.HL = MW_digitalRead(Geschwindigkeitsregler_P.HL_p1);

  /* S-Function (arduinodigitalinput_sfcn): '<S17>/HR' */
  Geschwindigkeitsregler_B.HR = MW_digitalRead(Geschwindigkeitsregler_P.HR_p1);

  /* S-Function (arduinodigitalinput_sfcn): '<S17>/VR' */
  Geschwindigkeitsregler_B.VR = MW_digitalRead(Geschwindigkeitsregler_P.VR_p1);

  /* S-Function (arduinodigitalinput_sfcn): '<S17>/VL' */
  Geschwindigkeitsregler_B.VL = MW_digitalRead(Geschwindigkeitsregler_P.VL_p1);

  /* RelationalOperator: '<S30>/Compare' incorporates:
   *  Constant: '<S30>/Constant'
   */
  rtb_Compare = ((int16_T)Geschwindigkeitsregler_B.HL > (int16_T)
                 Geschwindigkeitsregler_P.Constant_Value_k);

  /* RelationalOperator: '<S31>/Compare' incorporates:
   *  Constant: '<S31>/Constant'
   */
  rtb_Compare_m = ((int16_T)Geschwindigkeitsregler_B.HR > (int16_T)
                   Geschwindigkeitsregler_P.Constant_Value_f);

  /* RelationalOperator: '<S32>/Compare' incorporates:
   *  Constant: '<S32>/Constant'
   */
  rtb_Compare_f = ((int16_T)Geschwindigkeitsregler_B.VR > (int16_T)
                   Geschwindigkeitsregler_P.Constant_Value_o);

  /* RelationalOperator: '<S33>/Compare' incorporates:
   *  Constant: '<S33>/Constant'
   */
  rtb_Compare_c = ((int16_T)Geschwindigkeitsregler_B.VL > (int16_T)
                   Geschwindigkeitsregler_P.Constant_Value_fp);

  /* Outputs for Triggered SubSystem: '<S17>/Subsystem' */

  /* RelationalOperator: '<S23>/FixPt Relational Operator' incorporates:
   *  Constant: '<S17>/Constant'
   *  UnitDelay: '<S23>/Delay Input1'
   */
  Geschwindigkeitsregle_Subsystem((int16_T)rtb_Compare_m > (int16_T)
    Geschwindigkeitsregler_DW.DelayInput1_DSTATE_c,
    Geschwindigkeitsregler_P.Constant_Value_j,
    &Geschwindigkeitsregler_B.Subsystem, &Geschwindigkeitsregler_DW.Subsystem,
    (P_Subsystem_Geschwindigkeitsr_T *)&Geschwindigkeitsregler_P.Subsystem,
    &Geschwindigkeitsregler_PrevZCX.Subsystem);

  /* End of Outputs for SubSystem: '<S17>/Subsystem' */

  /* Outputs for Triggered SubSystem: '<S17>/Subsystem1' */

  /* RelationalOperator: '<S24>/FixPt Relational Operator' incorporates:
   *  Constant: '<S17>/Constant'
   *  UnitDelay: '<S24>/Delay Input1'
   */
  Geschwindigkeitsregle_Subsystem((int16_T)rtb_Compare_f > (int16_T)
    Geschwindigkeitsregler_DW.DelayInput1_DSTATE_o,
    Geschwindigkeitsregler_P.Constant_Value_j,
    &Geschwindigkeitsregler_B.Subsystem1, &Geschwindigkeitsregler_DW.Subsystem1,
    (P_Subsystem_Geschwindigkeitsr_T *)&Geschwindigkeitsregler_P.Subsystem1,
    &Geschwindigkeitsregler_PrevZCX.Subsystem1);

  /* End of Outputs for SubSystem: '<S17>/Subsystem1' */

  /* Outputs for Triggered SubSystem: '<S17>/Subsystem2' */

  /* RelationalOperator: '<S25>/FixPt Relational Operator' incorporates:
   *  Constant: '<S17>/Constant'
   *  UnitDelay: '<S25>/Delay Input1'
   */
  Geschwindigkeitsregle_Subsystem((int16_T)rtb_Compare_c > (int16_T)
    Geschwindigkeitsregler_DW.DelayInput1_DSTATE_ol,
    Geschwindigkeitsregler_P.Constant_Value_j,
    &Geschwindigkeitsregler_B.Subsystem2, &Geschwindigkeitsregler_DW.Subsystem2,
    (P_Subsystem_Geschwindigkeitsr_T *)&Geschwindigkeitsregler_P.Subsystem2,
    &Geschwindigkeitsregler_PrevZCX.Subsystem2);

  /* End of Outputs for SubSystem: '<S17>/Subsystem2' */

  /* Outputs for Triggered SubSystem: '<S17>/Subsystem3' */

  /* RelationalOperator: '<S22>/FixPt Relational Operator' incorporates:
   *  Constant: '<S17>/Constant'
   *  UnitDelay: '<S22>/Delay Input1'
   */
  Geschwindigkeitsregle_Subsystem((int16_T)rtb_Compare > (int16_T)
    Geschwindigkeitsregler_DW.DelayInput1_DSTATE,
    Geschwindigkeitsregler_P.Constant_Value_j,
    &Geschwindigkeitsregler_B.Subsystem3, &Geschwindigkeitsregler_DW.Subsystem3,
    (P_Subsystem_Geschwindigkeitsr_T *)&Geschwindigkeitsregler_P.Subsystem3,
    &Geschwindigkeitsregler_PrevZCX.Subsystem3);

  /* End of Outputs for SubSystem: '<S17>/Subsystem3' */

  /* DiscreteStateSpace: '<S18>/r+1 Altwerte' */
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

  /* DiscreteStateSpace: '<S19>/r+1 Altwerte' */
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

  /* DiscreteStateSpace: '<S20>/r+1 Altwerte' */
  {
    Geschwindigkeitsregler_B.r1Altwerte_o[0] =
      Geschwindigkeitsregler_P.r1Altwerte_C_j[0]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[0]
      + Geschwindigkeitsregler_P.r1Altwerte_C_j[4]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[1]
      + Geschwindigkeitsregler_P.r1Altwerte_C_j[8]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[2]
      + Geschwindigkeitsregler_P.r1Altwerte_C_j[12]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[3];
    Geschwindigkeitsregler_B.r1Altwerte_o[1] =
      Geschwindigkeitsregler_P.r1Altwerte_C_j[1]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[0]
      + Geschwindigkeitsregler_P.r1Altwerte_C_j[5]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[1]
      + Geschwindigkeitsregler_P.r1Altwerte_C_j[9]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[2]
      + Geschwindigkeitsregler_P.r1Altwerte_C_j[13]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[3];
    Geschwindigkeitsregler_B.r1Altwerte_o[2] =
      Geschwindigkeitsregler_P.r1Altwerte_C_j[2]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[0]
      + Geschwindigkeitsregler_P.r1Altwerte_C_j[6]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[1]
      + Geschwindigkeitsregler_P.r1Altwerte_C_j[10]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[2]
      + Geschwindigkeitsregler_P.r1Altwerte_C_j[14]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[3];
    Geschwindigkeitsregler_B.r1Altwerte_o[3] =
      Geschwindigkeitsregler_P.r1Altwerte_C_j[3]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[0]
      + Geschwindigkeitsregler_P.r1Altwerte_C_j[7]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[1]
      + Geschwindigkeitsregler_P.r1Altwerte_C_j[11]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[2]
      + Geschwindigkeitsregler_P.r1Altwerte_C_j[15]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[3];
  }

  /* DiscreteStateSpace: '<S21>/r+1 Altwerte' */
  {
    Geschwindigkeitsregler_B.r1Altwerte_h[0] =
      Geschwindigkeitsregler_P.r1Altwerte_C_js[0]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[0]
      + Geschwindigkeitsregler_P.r1Altwerte_C_js[4]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[1]
      + Geschwindigkeitsregler_P.r1Altwerte_C_js[8]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[2]
      + Geschwindigkeitsregler_P.r1Altwerte_C_js[12]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[3];
    Geschwindigkeitsregler_B.r1Altwerte_h[1] =
      Geschwindigkeitsregler_P.r1Altwerte_C_js[1]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[0]
      + Geschwindigkeitsregler_P.r1Altwerte_C_js[5]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[1]
      + Geschwindigkeitsregler_P.r1Altwerte_C_js[9]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[2]
      + Geschwindigkeitsregler_P.r1Altwerte_C_js[13]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[3];
    Geschwindigkeitsregler_B.r1Altwerte_h[2] =
      Geschwindigkeitsregler_P.r1Altwerte_C_js[2]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[0]
      + Geschwindigkeitsregler_P.r1Altwerte_C_js[6]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[1]
      + Geschwindigkeitsregler_P.r1Altwerte_C_js[10]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[2]
      + Geschwindigkeitsregler_P.r1Altwerte_C_js[14]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[3];
    Geschwindigkeitsregler_B.r1Altwerte_h[3] =
      Geschwindigkeitsregler_P.r1Altwerte_C_js[3]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[0]
      + Geschwindigkeitsregler_P.r1Altwerte_C_js[7]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[1]
      + Geschwindigkeitsregler_P.r1Altwerte_C_js[11]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[2]
      + Geschwindigkeitsregler_P.r1Altwerte_C_js[15]*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[3];
  }

  /* Update for DiscreteStateSpace: '<S19>/Zustandsvariablenfilter' */
  for (i = 0; i < 3; i++) {
    rtb_Switch2 = Geschwindigkeitsregler_P.BD[i] *
      Geschwindigkeitsregler_B.r1Altwerte_n[0] + (Geschwindigkeitsregler_P.AD[i
      + 6] * Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTATE[2] +
      (Geschwindigkeitsregler_P.AD[i + 3] *
       Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTATE[1] +
       Geschwindigkeitsregler_P.AD[i] *
       Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTATE[0]));
    rtb_Switch2 += Geschwindigkeitsregler_P.BD[i + 3] *
      Geschwindigkeitsregler_B.r1Altwerte_n[1];
    rtb_Switch2 += Geschwindigkeitsregler_P.BD[i + 6] *
      Geschwindigkeitsregler_B.r1Altwerte_n[2];
    rtb_Switch2 += Geschwindigkeitsregler_P.BD[i + 9] *
      Geschwindigkeitsregler_B.r1Altwerte_n[3];
    Geschwindigkeitsregler_B.xnew[i] = rtb_Switch2;
  }

  /* Update for Delay: '<S4>/Delay' */
  Geschwindigkeitsregler_DW.Delay_DSTATE[0] =
    Geschwindigkeitsregler_DW.Delay_DSTATE[1];
  Geschwindigkeitsregler_DW.Delay_DSTATE[1] = rtb_newPOWER;
  for (i = 0; i < 3; i++) {
    /* Update for DiscreteStateSpace: '<S19>/Zustandsvariablenfilter' */
    Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTATE[i] =
      Geschwindigkeitsregler_B.xnew[i];

    /* Update for DiscreteStateSpace: '<S20>/Zustandsvariablenfilter' */
    rtb_Switch2 = Geschwindigkeitsregler_P.BD[i] *
      Geschwindigkeitsregler_B.r1Altwerte_o[0] + (Geschwindigkeitsregler_P.AD[i
      + 6] * Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_o[2] +
      (Geschwindigkeitsregler_P.AD[i + 3] *
       Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_o[1] +
       Geschwindigkeitsregler_P.AD[i] *
       Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_o[0]));
    rtb_Switch2 += Geschwindigkeitsregler_P.BD[i + 3] *
      Geschwindigkeitsregler_B.r1Altwerte_o[1];
    rtb_Switch2 += Geschwindigkeitsregler_P.BD[i + 6] *
      Geschwindigkeitsregler_B.r1Altwerte_o[2];
    rtb_Switch2 += Geschwindigkeitsregler_P.BD[i + 9] *
      Geschwindigkeitsregler_B.r1Altwerte_o[3];
    xnew[i] = rtb_Switch2;
  }

  for (i = 0; i < 3; i++) {
    /* Update for DiscreteStateSpace: '<S20>/Zustandsvariablenfilter' */
    Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_o[i] = xnew[i];

    /* Update for DiscreteStateSpace: '<S21>/Zustandsvariablenfilter' */
    rtb_Switch2 = Geschwindigkeitsregler_P.BD[i] *
      Geschwindigkeitsregler_B.r1Altwerte_h[0] + (Geschwindigkeitsregler_P.AD[i
      + 6] * Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_c[2] +
      (Geschwindigkeitsregler_P.AD[i + 3] *
       Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_c[1] +
       Geschwindigkeitsregler_P.AD[i] *
       Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_c[0]));
    rtb_Switch2 += Geschwindigkeitsregler_P.BD[i + 3] *
      Geschwindigkeitsregler_B.r1Altwerte_h[1];
    rtb_Switch2 += Geschwindigkeitsregler_P.BD[i + 6] *
      Geschwindigkeitsregler_B.r1Altwerte_h[2];
    rtb_Switch2 += Geschwindigkeitsregler_P.BD[i + 9] *
      Geschwindigkeitsregler_B.r1Altwerte_h[3];
    Geschwindigkeitsregler_B.xnew[i] = rtb_Switch2;
  }

  for (i = 0; i < 3; i++) {
    /* Update for DiscreteStateSpace: '<S21>/Zustandsvariablenfilter' */
    Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_c[i] =
      Geschwindigkeitsregler_B.xnew[i];

    /* Update for DiscreteStateSpace: '<S18>/Zustandsvariablenfilter' */
    rtb_Switch2 = Geschwindigkeitsregler_P.BD[i] *
      Geschwindigkeitsregler_B.r1Altwerte[0] + (Geschwindigkeitsregler_P.AD[i +
      6] * Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_e[2] +
      (Geschwindigkeitsregler_P.AD[i + 3] *
       Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_e[1] +
       Geschwindigkeitsregler_P.AD[i] *
       Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_e[0]));
    rtb_Switch2 += Geschwindigkeitsregler_P.BD[i + 3] *
      Geschwindigkeitsregler_B.r1Altwerte[1];
    rtb_Switch2 += Geschwindigkeitsregler_P.BD[i + 6] *
      Geschwindigkeitsregler_B.r1Altwerte[2];
    rtb_Switch2 += Geschwindigkeitsregler_P.BD[i + 9] *
      Geschwindigkeitsregler_B.r1Altwerte[3];
    xnew[i] = rtb_Switch2;
  }

  /* Update for DiscreteStateSpace: '<S18>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_e[0] = xnew[0];
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_e[1] = xnew[1];
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_e[2] = xnew[2];

  /* Update for UnitDelay: '<S22>/Delay Input1' */
  Geschwindigkeitsregler_DW.DelayInput1_DSTATE = rtb_Compare;

  /* Update for UnitDelay: '<S23>/Delay Input1' */
  Geschwindigkeitsregler_DW.DelayInput1_DSTATE_c = rtb_Compare_m;

  /* Update for UnitDelay: '<S24>/Delay Input1' */
  Geschwindigkeitsregler_DW.DelayInput1_DSTATE_o = rtb_Compare_f;

  /* Update for UnitDelay: '<S25>/Delay Input1' */
  Geschwindigkeitsregler_DW.DelayInput1_DSTATE_ol = rtb_Compare_c;

  /* Update for DiscreteStateSpace: '<S18>/r+1 Altwerte' */
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

  /* Update for DiscreteStateSpace: '<S19>/r+1 Altwerte' */
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

  /* Update for DiscreteStateSpace: '<S20>/r+1 Altwerte' */
  {
    real_T xtmp = Geschwindigkeitsregler_B.Subsystem2.Add;
    xtmp += (Geschwindigkeitsregler_P.r1Altwerte_A_h[0])*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[0]
      + (Geschwindigkeitsregler_P.r1Altwerte_A_h[1])*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[1]
      + (Geschwindigkeitsregler_P.r1Altwerte_A_h[2])*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[2]
      + (Geschwindigkeitsregler_P.r1Altwerte_A_h[3])*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[3];
    Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[3] =
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[2];
    Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[2] =
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[1];
    Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[1] =
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[0];
    Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[0] = xtmp;
  }

  /* Update for DiscreteStateSpace: '<S21>/r+1 Altwerte' */
  {
    real_T xtmp = Geschwindigkeitsregler_B.Subsystem1.Add;
    xtmp += (Geschwindigkeitsregler_P.r1Altwerte_A_ix[0])*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[0]
      + (Geschwindigkeitsregler_P.r1Altwerte_A_ix[1])*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[1]
      + (Geschwindigkeitsregler_P.r1Altwerte_A_ix[2])*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[2]
      + (Geschwindigkeitsregler_P.r1Altwerte_A_ix[3])*
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[3];
    Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[3] =
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[2];
    Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[2] =
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[1];
    Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[1] =
      Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[0];
    Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[0] = xtmp;
  }

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.01s, 0.0s] */
    rtExtModeUpload(0, Geschwindigkeitsregler_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(Geschwindigkeitsregler_M)!=-1) &&
        !((rtmGetTFinal(Geschwindigkeitsregler_M)-
           Geschwindigkeitsregler_M->Timing.taskTime0) >
          Geschwindigkeitsregler_M->Timing.taskTime0 * (DBL_EPSILON))) {
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
  Geschwindigkeitsregler_M->Timing.taskTime0 =
    (++Geschwindigkeitsregler_M->Timing.clockTick0) *
    Geschwindigkeitsregler_M->Timing.stepSize0;
}

/* Model initialize function */
void Geschwindigkeitsregler_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Geschwindigkeitsregler_M, 0,
                sizeof(RT_MODEL_Geschwindigkeitsregl_T));
  rtmSetTFinal(Geschwindigkeitsregler_M, 10.0);
  Geschwindigkeitsregler_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Geschwindigkeitsregler_M->Sizes.checksums[0] = (904689316U);
  Geschwindigkeitsregler_M->Sizes.checksums[1] = (2109258987U);
  Geschwindigkeitsregler_M->Sizes.checksums[2] = (4056733999U);
  Geschwindigkeitsregler_M->Sizes.checksums[3] = (1866508756U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[25];
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
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = (sysRanDType *)
      &Geschwindigkeitsregler_DW.Subsystem.Subsystem_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &Geschwindigkeitsregler_DW.Subsystem.Subsystem_SubsysRanBC;
    systemRan[15] = (sysRanDType *)
      &Geschwindigkeitsregler_DW.Subsystem1.Subsystem_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &Geschwindigkeitsregler_DW.Subsystem1.Subsystem_SubsysRanBC;
    systemRan[17] = (sysRanDType *)
      &Geschwindigkeitsregler_DW.Subsystem2.Subsystem_SubsysRanBC;
    systemRan[18] = (sysRanDType *)
      &Geschwindigkeitsregler_DW.Subsystem2.Subsystem_SubsysRanBC;
    systemRan[19] = (sysRanDType *)
      &Geschwindigkeitsregler_DW.Subsystem3.Subsystem_SubsysRanBC;
    systemRan[20] = (sysRanDType *)
      &Geschwindigkeitsregler_DW.Subsystem3.Subsystem_SubsysRanBC;
    systemRan[21] = &rtAlwaysEnabled;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = &rtAlwaysEnabled;
    systemRan[24] = &rtAlwaysEnabled;
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

  /* Start for Atomic SubSystem: '<S1>/hl' */
  Geschwindigkeitsregler_hl_Start((P_hl_Geschwindigkeitsregler_T *)
    &Geschwindigkeitsregler_P.hl);

  /* End of Start for SubSystem: '<S1>/hl' */

  /* Start for Atomic SubSystem: '<S1>/hr' */
  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S11>/Digital Output' */
  MW_pinModeOutput(Geschwindigkeitsregler_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S12>/PWM' */
  MW_pinModeOutput(Geschwindigkeitsregler_P.PWM_pinNumber);

  /* Start for Atomic SubSystem: '<S1>/vl' */
  Geschwindigkeitsregler_hl_Start((P_hl_Geschwindigkeitsregler_T *)
    &Geschwindigkeitsregler_P.vl);

  /* End of Start for SubSystem: '<S1>/vl' */

  /* Start for Atomic SubSystem: '<S1>/vr' */
  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S15>/Digital Output' */
  MW_pinModeOutput(Geschwindigkeitsregler_P.DigitalOutput_pinNumber_n);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S16>/PWM' */
  MW_pinModeOutput(Geschwindigkeitsregler_P.PWM_pinNumber_g);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S17>/HL' */
  MW_pinModeInput(Geschwindigkeitsregler_P.HL_p1);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S17>/HR' */
  MW_pinModeInput(Geschwindigkeitsregler_P.HR_p1);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S17>/VR' */
  MW_pinModeInput(Geschwindigkeitsregler_P.VR_p1);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S17>/VL' */
  MW_pinModeInput(Geschwindigkeitsregler_P.VL_p1);

  /* Start for Triggered SubSystem: '<S17>/Subsystem' */
  Geschwindigkeit_Subsystem_Start(&Geschwindigkeitsregler_B.Subsystem,
    (P_Subsystem_Geschwindigkeitsr_T *)&Geschwindigkeitsregler_P.Subsystem);

  /* End of Start for SubSystem: '<S17>/Subsystem' */

  /* Start for Triggered SubSystem: '<S17>/Subsystem1' */
  Geschwindigkeit_Subsystem_Start(&Geschwindigkeitsregler_B.Subsystem1,
    (P_Subsystem_Geschwindigkeitsr_T *)&Geschwindigkeitsregler_P.Subsystem1);

  /* End of Start for SubSystem: '<S17>/Subsystem1' */

  /* Start for Triggered SubSystem: '<S17>/Subsystem2' */
  Geschwindigkeit_Subsystem_Start(&Geschwindigkeitsregler_B.Subsystem2,
    (P_Subsystem_Geschwindigkeitsr_T *)&Geschwindigkeitsregler_P.Subsystem2);

  /* End of Start for SubSystem: '<S17>/Subsystem2' */

  /* Start for Triggered SubSystem: '<S17>/Subsystem3' */
  Geschwindigkeit_Subsystem_Start(&Geschwindigkeitsregler_B.Subsystem3,
    (P_Subsystem_Geschwindigkeitsr_T *)&Geschwindigkeitsregler_P.Subsystem3);

  /* End of Start for SubSystem: '<S17>/Subsystem3' */
  Geschwindigkeitsregler_PrevZCX.Subsystem3.Subsystem_Trig_ZCE = POS_ZCSIG;
  Geschwindigkeitsregler_PrevZCX.Subsystem2.Subsystem_Trig_ZCE = POS_ZCSIG;
  Geschwindigkeitsregler_PrevZCX.Subsystem1.Subsystem_Trig_ZCE = POS_ZCSIG;
  Geschwindigkeitsregler_PrevZCX.Subsystem.Subsystem_Trig_ZCE = POS_ZCSIG;

  /* InitializeConditions for DiscreteStateSpace: '<S19>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTATE[0] =
    Geschwindigkeitsregler_P.AB2[0];
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTATE[1] =
    Geschwindigkeitsregler_P.AB2[1];
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTATE[2] =
    Geschwindigkeitsregler_P.AB2[2];

  /* InitializeConditions for Delay: '<S4>/Delay' */
  Geschwindigkeitsregler_DW.Delay_DSTATE[0] =
    Geschwindigkeitsregler_P.Delay_InitialCondition;
  Geschwindigkeitsregler_DW.Delay_DSTATE[1] =
    Geschwindigkeitsregler_P.Delay_InitialCondition;

  /* InitializeConditions for DiscreteStateSpace: '<S20>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_o[0] =
    Geschwindigkeitsregler_P.AB2[0];

  /* InitializeConditions for DiscreteStateSpace: '<S21>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_c[0] =
    Geschwindigkeitsregler_P.AB2[0];

  /* InitializeConditions for DiscreteStateSpace: '<S18>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_e[0] =
    Geschwindigkeitsregler_P.AB2[0];

  /* InitializeConditions for DiscreteStateSpace: '<S20>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_o[1] =
    Geschwindigkeitsregler_P.AB2[1];

  /* InitializeConditions for DiscreteStateSpace: '<S21>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_c[1] =
    Geschwindigkeitsregler_P.AB2[1];

  /* InitializeConditions for DiscreteStateSpace: '<S18>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_e[1] =
    Geschwindigkeitsregler_P.AB2[1];

  /* InitializeConditions for DiscreteStateSpace: '<S20>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_o[2] =
    Geschwindigkeitsregler_P.AB2[2];

  /* InitializeConditions for DiscreteStateSpace: '<S21>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_c[2] =
    Geschwindigkeitsregler_P.AB2[2];

  /* InitializeConditions for DiscreteStateSpace: '<S18>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_e[2] =
    Geschwindigkeitsregler_P.AB2[2];

  /* InitializeConditions for UnitDelay: '<S22>/Delay Input1' */
  Geschwindigkeitsregler_DW.DelayInput1_DSTATE =
    Geschwindigkeitsregler_P.DetectRisePositive_vinit;

  /* InitializeConditions for UnitDelay: '<S23>/Delay Input1' */
  Geschwindigkeitsregler_DW.DelayInput1_DSTATE_c =
    Geschwindigkeitsregler_P.DetectRisePositive1_vinit;

  /* InitializeConditions for UnitDelay: '<S24>/Delay Input1' */
  Geschwindigkeitsregler_DW.DelayInput1_DSTATE_o =
    Geschwindigkeitsregler_P.DetectRisePositive2_vinit;

  /* InitializeConditions for UnitDelay: '<S25>/Delay Input1' */
  Geschwindigkeitsregler_DW.DelayInput1_DSTATE_ol =
    Geschwindigkeitsregler_P.DetectRisePositive3_vinit;

  /* InitializeConditions for Triggered SubSystem: '<S17>/Subsystem' */
  Geschwindigkeits_Subsystem_Init(&Geschwindigkeitsregler_DW.Subsystem,
    (P_Subsystem_Geschwindigkeitsr_T *)&Geschwindigkeitsregler_P.Subsystem);

  /* End of InitializeConditions for SubSystem: '<S17>/Subsystem' */

  /* InitializeConditions for Triggered SubSystem: '<S17>/Subsystem1' */
  Geschwindigkeits_Subsystem_Init(&Geschwindigkeitsregler_DW.Subsystem1,
    (P_Subsystem_Geschwindigkeitsr_T *)&Geschwindigkeitsregler_P.Subsystem1);

  /* End of InitializeConditions for SubSystem: '<S17>/Subsystem1' */

  /* InitializeConditions for Triggered SubSystem: '<S17>/Subsystem2' */
  Geschwindigkeits_Subsystem_Init(&Geschwindigkeitsregler_DW.Subsystem2,
    (P_Subsystem_Geschwindigkeitsr_T *)&Geschwindigkeitsregler_P.Subsystem2);

  /* End of InitializeConditions for SubSystem: '<S17>/Subsystem2' */

  /* InitializeConditions for Triggered SubSystem: '<S17>/Subsystem3' */
  Geschwindigkeits_Subsystem_Init(&Geschwindigkeitsregler_DW.Subsystem3,
    (P_Subsystem_Geschwindigkeitsr_T *)&Geschwindigkeitsregler_P.Subsystem3);

  /* End of InitializeConditions for SubSystem: '<S17>/Subsystem3' */

  /* InitializeConditions for DiscreteStateSpace: '<S18>/r+1 Altwerte' */
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[0] = Geschwindigkeitsregler_P.AB1
    [0];
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[1] = Geschwindigkeitsregler_P.AB1
    [1];
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[2] = Geschwindigkeitsregler_P.AB1
    [2];
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[3] = Geschwindigkeitsregler_P.AB1
    [3];

  /* InitializeConditions for DiscreteStateSpace: '<S19>/r+1 Altwerte' */
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[0] =
    Geschwindigkeitsregler_P.AB1[0];
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[1] =
    Geschwindigkeitsregler_P.AB1[1];
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[2] =
    Geschwindigkeitsregler_P.AB1[2];
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[3] =
    Geschwindigkeitsregler_P.AB1[3];

  /* InitializeConditions for DiscreteStateSpace: '<S20>/r+1 Altwerte' */
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[0] =
    Geschwindigkeitsregler_P.AB1[0];
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[1] =
    Geschwindigkeitsregler_P.AB1[1];
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[2] =
    Geschwindigkeitsregler_P.AB1[2];
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[3] =
    Geschwindigkeitsregler_P.AB1[3];

  /* InitializeConditions for DiscreteStateSpace: '<S21>/r+1 Altwerte' */
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[0] =
    Geschwindigkeitsregler_P.AB1[0];
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[1] =
    Geschwindigkeitsregler_P.AB1[1];
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[2] =
    Geschwindigkeitsregler_P.AB1[2];
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_g[3] =
    Geschwindigkeitsregler_P.AB1[3];
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
