/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Abstandsregler.c
 *
 * Code generated for Simulink model 'Abstandsregler'.
 *
 * Model version                  : 1.27
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 23 16:57:04 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Abstandsregler.h"
#include "Abstandsregler_private.h"
#include "Abstandsregler_dt.h"

/* Block signals (auto storage) */
B_Abstandsregler_T Abstandsregler_B;

/* Block states (auto storage) */
DW_Abstandsregler_T Abstandsregler_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Abstandsregler_T Abstandsregler_PrevZCX;

/* Real-time model */
RT_MODEL_Abstandsregler_T Abstandsregler_M_;
RT_MODEL_Abstandsregler_T *const Abstandsregler_M = &Abstandsregler_M_;

/*
 * Start for atomic system:
 *    '<S2>/hl'
 *    '<S2>/vl'
 */
void Abstandsregler_hl_Start(P_hl_Abstandsregler_T *localP)
{
  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S14>/Digital Output' */
  MW_pinModeOutput(localP->DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S15>/PWM' */
  MW_pinModeOutput(localP->PWM_pinNumber);
}

/*
 * Output and update for atomic system:
 *    '<S2>/hl'
 *    '<S2>/vl'
 */
void Abstandsregler_hl(real_T rtu_enable, real_T rtu_power, real_T rtu_direction,
  P_hl_Abstandsregler_T *localP)
{
  real_T rtu_enable_0;
  uint8_T rtu_enable_1;

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S10>/Constant2'
   */
  if (rtu_enable > localP->Switch_Threshold) {
    rtu_enable_0 = rtu_direction;
  } else {
    rtu_enable_0 = localP->Constant2_Value;
  }

  /* End of Switch: '<S10>/Switch' */

  /* DataTypeConversion: '<S14>/Data Type Conversion' */
  if (rtu_enable_0 < 256.0) {
    if (rtu_enable_0 >= 0.0) {
      rtu_enable_1 = (uint8_T)rtu_enable_0;
    } else {
      rtu_enable_1 = 0U;
    }
  } else {
    rtu_enable_1 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S14>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S14>/Digital Output' */
  MW_digitalWrite(localP->DigitalOutput_pinNumber, rtu_enable_1);

  /* Switch: '<S10>/Switch1' incorporates:
   *  Constant: '<S10>/Constant3'
   */
  if (rtu_enable > localP->Switch1_Threshold) {
    rtu_enable_0 = rtu_power;
  } else {
    rtu_enable_0 = localP->Constant3_Value;
  }

  /* End of Switch: '<S10>/Switch1' */

  /* DataTypeConversion: '<S15>/Data Type Conversion' */
  if (rtu_enable_0 < 256.0) {
    if (rtu_enable_0 >= 0.0) {
      rtu_enable_1 = (uint8_T)rtu_enable_0;
    } else {
      rtu_enable_1 = 0U;
    }
  } else {
    rtu_enable_1 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S15>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S15>/PWM' */
  MW_analogWrite(localP->PWM_pinNumber, rtu_enable_1);
}

/*
 * Initial conditions for trigger system:
 *    '<S22>/Subsystem'
 *    '<S22>/Subsystem1'
 *    '<S22>/Subsystem2'
 *    '<S22>/Subsystem3'
 */
void Abstandsregler_Subsystem_Init(DW_Subsystem_Abstandsregler_T *localDW,
  P_Subsystem_Abstandsregler_T *localP)
{
  /* InitializeConditions for Delay: '<S31>/Delay' */
  localDW->Delay_DSTATE = localP->Delay_InitialCondition;
}

/*
 * Start for trigger system:
 *    '<S22>/Subsystem'
 *    '<S22>/Subsystem1'
 *    '<S22>/Subsystem2'
 *    '<S22>/Subsystem3'
 */
void Abstandsregler_Subsystem_Start(B_Subsystem_Abstandsregler_T *localB,
  P_Subsystem_Abstandsregler_T *localP)
{
  /* VirtualOutportStart for Outport: '<S31>/Out1' */
  localB->Add = localP->Out1_Y0;
}

/*
 * Output and update for trigger system:
 *    '<S22>/Subsystem'
 *    '<S22>/Subsystem1'
 *    '<S22>/Subsystem2'
 *    '<S22>/Subsystem3'
 */
void Abstandsregler_Subsystem(boolean_T rtu_Trigger, real_T rtu_reset,
  B_Subsystem_Abstandsregler_T *localB, DW_Subsystem_Abstandsregler_T *localDW,
  P_Subsystem_Abstandsregler_T *localP, ZCE_Subsystem_Abstandsregler_T *localZCE)
{
  real_T rtu_reset_0;

  /* Outputs for Triggered SubSystem: '<S22>/Subsystem' incorporates:
   *  TriggerPort: '<S31>/Trigger'
   */
  if (rtu_Trigger && (localZCE->Subsystem_Trig_ZCE != POS_ZCSIG)) {
    /* Switch: '<S31>/Switch' incorporates:
     *  Constant: '<S31>/Constant1'
     *  Delay: '<S31>/Delay'
     */
    if (rtu_reset > localP->Switch_Threshold) {
      rtu_reset_0 = localP->Constant1_Value;
    } else {
      rtu_reset_0 = localDW->Delay_DSTATE;
    }

    /* End of Switch: '<S31>/Switch' */

    /* Sum: '<S31>/Add' incorporates:
     *  Constant: '<S31>/Constant'
     */
    localB->Add = rtu_reset_0 + localP->Constant_Value;

    /* Update for Delay: '<S31>/Delay' */
    localDW->Delay_DSTATE = localB->Add;
    localDW->Subsystem_SubsysRanBC = 4;
  }

  localZCE->Subsystem_Trig_ZCE = rtu_Trigger;

  /* End of Outputs for SubSystem: '<S22>/Subsystem' */
}

/* Model step function */
void Abstandsregler_step(void)
{
  /* local block i/o variables */
  real_T rtb_Saturate;
  real_T rtb_Saturate_f;
  boolean_T rtb_Compare;
  boolean_T rtb_FixPtRelationalOperator;
  boolean_T rtb_Compare_c;
  boolean_T rtb_FixPtRelationalOperator_k;
  boolean_T rtb_Compare_f;
  boolean_T rtb_FixPtRelationalOperator_d;
  boolean_T rtb_Compare_p;
  boolean_T rtb_FixPtRelationalOperator_c;

  {
    uint16_T rtb_Abstandssensor_0;
    int_T i;
    boolean_T rtb_HL_0;
    real_T rtb_Sum;
    real_T tmp;
    uint8_T tmp_0;

    /* Reset subsysRan breadcrumbs */
    srClearBC(Abstandsregler_DW.Subsystem.Subsystem_SubsysRanBC);

    /* S-Function (arduinoanaloginput_sfcn): '<S1>/Abstandssensor' */
    rtb_Abstandssensor_0 = MW_analogRead(Abstandsregler_P.Abstandssensor_p1);

    /* Gain: '<S1>/Gain' incorporates:
     *  S-Function (arduinoanaloginput_sfcn): '<S1>/Abstandssensor'
     */
    Abstandsregler_B.Gain = (uint32_T)Abstandsregler_P.Gain_Gain *
      rtb_Abstandssensor_0;

    /* Sum: '<S1>/Add' incorporates:
     *  Constant: '<S1>/Constant'
     */
    Abstandsregler_B.Add = Abstandsregler_P.Constant_Value - (real_T)
      Abstandsregler_B.Gain * 1.9073486328125E-6;

    /* DiscreteIntegrator: '<S9>/Integrator' incorporates:
     *  Constant: '<S1>/Constant2'
     *  Product: '<S9>/IOut'
     */
    Abstandsregler_B.Integrator = Abstandsregler_B.Add *
      Abstandsregler_P.Constant2_Value_jd * Abstandsregler_P.Integrator_gainval
      + Abstandsregler_DW.Integrator_DSTATE;

    /* Sum: '<S9>/Sum' incorporates:
     *  Constant: '<S1>/Constant1'
     *  Product: '<S9>/POut'
     */
    rtb_Sum = Abstandsregler_B.Add * Abstandsregler_P.Constant1_Value +
      Abstandsregler_B.Integrator;

    /* Saturate: '<S9>/Saturate' */
    if (rtb_Sum > Abstandsregler_P.DiscretePIDController_UpperSatu) {
      Abstandsregler_B.Saturate =
        Abstandsregler_P.DiscretePIDController_UpperSatu;
    } else if (rtb_Sum < Abstandsregler_P.DiscretePIDController_LowerSatu) {
      Abstandsregler_B.Saturate =
        Abstandsregler_P.DiscretePIDController_LowerSatu;
    } else {
      Abstandsregler_B.Saturate = rtb_Sum;
    }

    /* End of Saturate: '<S9>/Saturate' */

    /* DiscreteStateSpace: '<S23>/Zustandsvariablenfilter' */
    for (i = 0; i < 3; i++) {
      Abstandsregler_B.Zustandsvariablenfilter_m[i] =
        Abstandsregler_P.Zustandsvariablenfilter_C[i + 6] *
        Abstandsregler_DW.Zustandsvariablenfilter_DSTATE[2] +
        (Abstandsregler_P.Zustandsvariablenfilter_C[i + 3] *
         Abstandsregler_DW.Zustandsvariablenfilter_DSTATE[1] +
         Abstandsregler_P.Zustandsvariablenfilter_C[i] *
         Abstandsregler_DW.Zustandsvariablenfilter_DSTATE[0]);
    }

    /* End of DiscreteStateSpace: '<S23>/Zustandsvariablenfilter' */

    /* Sum: '<S5>/Add' incorporates:
     *  Constant: '<S5>/Constant'
     *  Constant: '<S5>/Constant1'
     *  Product: '<S5>/Divide'
     */
    rtb_Sum = Abstandsregler_B.Saturate * Abstandsregler_P.Constant1_Value_b /
      Abstandsregler_P.Constant_Value_g -
      Abstandsregler_B.Zustandsvariablenfilter_m[1];

    /* DiscreteIntegrator: '<S39>/Integrator' incorporates:
     *  Constant: '<S5>/Constant3'
     *  Product: '<S39>/IOut'
     */
    Abstandsregler_B.Integrator_i = rtb_Sum * Abstandsregler_P.Constant3_Value_i
      * Abstandsregler_P.Integrator_gainval_p +
      Abstandsregler_DW.Integrator_DSTATE_o;

    /* Sum: '<S39>/Sum' incorporates:
     *  Constant: '<S5>/Constant2'
     *  Product: '<S39>/POut'
     */
    rtb_Sum = rtb_Sum * Abstandsregler_P.Constant2_Value_n +
      Abstandsregler_B.Integrator_i;

    /* Saturate: '<S39>/Saturate' */
    if (rtb_Sum > Abstandsregler_P.DiscretePIDController_UpperSa_m) {
      rtb_Saturate = Abstandsregler_P.DiscretePIDController_UpperSa_m;
    } else if (rtb_Sum < Abstandsregler_P.DiscretePIDController_LowerSa_i) {
      rtb_Saturate = Abstandsregler_P.DiscretePIDController_LowerSa_i;
    } else {
      rtb_Saturate = rtb_Sum;
    }

    /* End of Saturate: '<S39>/Saturate' */

    /* Outputs for Atomic SubSystem: '<S2>/hl' */

    /* Constant: '<Root>/enable' incorporates:
     *  Constant: '<Root>/direction'
     */
    Abstandsregler_hl(Abstandsregler_P.enable_Value, rtb_Saturate,
                      Abstandsregler_P.direction_Value, (P_hl_Abstandsregler_T *)
                      &Abstandsregler_P.hl);

    /* End of Outputs for SubSystem: '<S2>/hl' */

    /* DiscreteStateSpace: '<S24>/Zustandsvariablenfilter' */
    for (i = 0; i < 3; i++) {
      Abstandsregler_B.Zustandsvariablenfilter[i] = 0.0;
      Abstandsregler_B.Zustandsvariablenfilter[i] +=
        Abstandsregler_P.Zustandsvariablenfilter_C_n[i] *
        Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_n[0];
      Abstandsregler_B.Zustandsvariablenfilter[i] +=
        Abstandsregler_P.Zustandsvariablenfilter_C_n[i + 3] *
        Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_n[1];
      Abstandsregler_B.Zustandsvariablenfilter[i] +=
        Abstandsregler_P.Zustandsvariablenfilter_C_n[i + 6] *
        Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_n[2];
    }

    /* End of DiscreteStateSpace: '<S24>/Zustandsvariablenfilter' */

    /* Sum: '<S6>/Add' incorporates:
     *  Constant: '<S6>/maxClicksproSec'
     *  Constant: '<S6>/prozent'
     *  Product: '<S6>/Divide'
     */
    Abstandsregler_B.Add_d = Abstandsregler_B.Saturate *
      Abstandsregler_P.maxClicksproSec_Value / Abstandsregler_P.prozent_Value -
      Abstandsregler_B.Zustandsvariablenfilter[1];

    /* DiscreteIntegrator: '<S40>/Integrator' incorporates:
     *  Constant: '<S6>/i'
     *  Product: '<S40>/IOut'
     */
    Abstandsregler_B.Integrator_n = Abstandsregler_B.Add_d *
      Abstandsregler_P.i_Value * Abstandsregler_P.Integrator_gainval_o +
      Abstandsregler_DW.Integrator_DSTATE_g;

    /* Sum: '<S40>/Sum' incorporates:
     *  Constant: '<S6>/p'
     *  Product: '<S40>/POut'
     */
    rtb_Sum = Abstandsregler_B.Add_d * Abstandsregler_P.p_Value +
      Abstandsregler_B.Integrator_n;

    /* Saturate: '<S40>/Saturate' */
    if (rtb_Sum > Abstandsregler_P.DiscretePIDController_UpperSa_b) {
      Abstandsregler_B.Saturate_f =
        Abstandsregler_P.DiscretePIDController_UpperSa_b;
    } else if (rtb_Sum < Abstandsregler_P.DiscretePIDController_LowerSa_p) {
      Abstandsregler_B.Saturate_f =
        Abstandsregler_P.DiscretePIDController_LowerSa_p;
    } else {
      Abstandsregler_B.Saturate_f = rtb_Sum;
    }

    /* End of Saturate: '<S40>/Saturate' */

    /* Outputs for Atomic SubSystem: '<S2>/hr' */
    /* Switch: '<S11>/Switch' incorporates:
     *  Constant: '<Root>/direction'
     *  Constant: '<Root>/enable'
     *  Constant: '<S11>/Constant2'
     */
    if (Abstandsregler_P.enable_Value > Abstandsregler_P.Switch_Threshold) {
      tmp = Abstandsregler_P.direction_Value;
    } else {
      tmp = Abstandsregler_P.Constant2_Value;
    }

    /* End of Switch: '<S11>/Switch' */

    /* DataTypeConversion: '<S16>/Data Type Conversion' */
    if (tmp < 256.0) {
      if (tmp >= 0.0) {
        tmp_0 = (uint8_T)tmp;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    /* End of DataTypeConversion: '<S16>/Data Type Conversion' */

    /* S-Function (arduinodigitaloutput_sfcn): '<S16>/Digital Output' */
    MW_digitalWrite(Abstandsregler_P.DigitalOutput_pinNumber, tmp_0);

    /* Switch: '<S11>/Switch1' incorporates:
     *  Constant: '<Root>/enable'
     *  Constant: '<S11>/Constant3'
     */
    if (Abstandsregler_P.enable_Value > Abstandsregler_P.Switch1_Threshold) {
      tmp = Abstandsregler_B.Saturate_f;
    } else {
      tmp = Abstandsregler_P.Constant3_Value;
    }

    /* End of Switch: '<S11>/Switch1' */

    /* DataTypeConversion: '<S17>/Data Type Conversion' */
    if (tmp < 256.0) {
      if (tmp >= 0.0) {
        tmp_0 = (uint8_T)tmp;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    /* End of DataTypeConversion: '<S17>/Data Type Conversion' */

    /* S-Function (arduinoanalogoutput_sfcn): '<S17>/PWM' */
    MW_analogWrite(Abstandsregler_P.PWM_pinNumber, tmp_0);

    /* End of Outputs for SubSystem: '<S2>/hr' */

    /* DiscreteStateSpace: '<S25>/Zustandsvariablenfilter' */
    for (i = 0; i < 3; i++) {
      Abstandsregler_B.Zustandsvariablenfilter_m[i] =
        Abstandsregler_P.Zustandsvariablenfilter_C_m[i + 6] *
        Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_o[2] +
        (Abstandsregler_P.Zustandsvariablenfilter_C_m[i + 3] *
         Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_o[1] +
         Abstandsregler_P.Zustandsvariablenfilter_C_m[i] *
         Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_o[0]);
    }

    /* End of DiscreteStateSpace: '<S25>/Zustandsvariablenfilter' */

    /* Sum: '<S7>/Add' incorporates:
     *  Constant: '<S7>/Constant'
     *  Constant: '<S7>/Constant1'
     *  Product: '<S7>/Divide'
     */
    rtb_Sum = Abstandsregler_B.Saturate * Abstandsregler_P.Constant1_Value_c /
      Abstandsregler_P.Constant_Value_f -
      Abstandsregler_B.Zustandsvariablenfilter_m[1];

    /* DiscreteIntegrator: '<S41>/Integrator' incorporates:
     *  Constant: '<S7>/Constant3'
     *  Product: '<S41>/IOut'
     */
    Abstandsregler_B.Integrator_is = rtb_Sum *
      Abstandsregler_P.Constant3_Value_m * Abstandsregler_P.Integrator_gainval_k
      + Abstandsregler_DW.Integrator_DSTATE_k;

    /* Sum: '<S41>/Sum' incorporates:
     *  Constant: '<S7>/Constant2'
     *  Product: '<S41>/POut'
     */
    rtb_Sum = rtb_Sum * Abstandsregler_P.Constant2_Value_l +
      Abstandsregler_B.Integrator_is;

    /* Saturate: '<S41>/Saturate' */
    if (rtb_Sum > Abstandsregler_P.DiscretePIDController_UpperSa_o) {
      rtb_Saturate_f = Abstandsregler_P.DiscretePIDController_UpperSa_o;
    } else if (rtb_Sum < Abstandsregler_P.DiscretePIDController_LowerS_pn) {
      rtb_Saturate_f = Abstandsregler_P.DiscretePIDController_LowerS_pn;
    } else {
      rtb_Saturate_f = rtb_Sum;
    }

    /* End of Saturate: '<S41>/Saturate' */

    /* Outputs for Atomic SubSystem: '<S2>/vl' */

    /* Constant: '<Root>/enable' incorporates:
     *  Constant: '<Root>/direction'
     */
    Abstandsregler_hl(Abstandsregler_P.enable_Value, rtb_Saturate_f,
                      Abstandsregler_P.direction_Value, (P_hl_Abstandsregler_T *)
                      &Abstandsregler_P.vl);

    /* End of Outputs for SubSystem: '<S2>/vl' */

    /* DiscreteStateSpace: '<S26>/Zustandsvariablenfilter' */
    for (i = 0; i < 3; i++) {
      Abstandsregler_B.Zustandsvariablenfilter_m[i] =
        Abstandsregler_P.Zustandsvariablenfilter_C_p[i + 6] *
        Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_c[2] +
        (Abstandsregler_P.Zustandsvariablenfilter_C_p[i + 3] *
         Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_c[1] +
         Abstandsregler_P.Zustandsvariablenfilter_C_p[i] *
         Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_c[0]);
    }

    /* End of DiscreteStateSpace: '<S26>/Zustandsvariablenfilter' */

    /* Sum: '<S8>/Add' incorporates:
     *  Constant: '<S8>/Constant'
     *  Constant: '<S8>/Constant1'
     *  Product: '<S8>/Divide'
     */
    rtb_Sum = Abstandsregler_B.Saturate * Abstandsregler_P.Constant1_Value_e /
      Abstandsregler_P.Constant_Value_o -
      Abstandsregler_B.Zustandsvariablenfilter_m[1];

    /* DiscreteIntegrator: '<S42>/Integrator' incorporates:
     *  Constant: '<S8>/Constant3'
     *  Product: '<S42>/IOut'
     */
    Abstandsregler_B.Integrator_i4 = rtb_Sum *
      Abstandsregler_P.Constant3_Value_e * Abstandsregler_P.Integrator_gainval_n
      + Abstandsregler_DW.Integrator_DSTATE_gl;

    /* Sum: '<S42>/Sum' incorporates:
     *  Constant: '<S8>/Constant2'
     *  Product: '<S42>/POut'
     */
    rtb_Sum = rtb_Sum * Abstandsregler_P.Constant2_Value_i +
      Abstandsregler_B.Integrator_i4;

    /* Outputs for Atomic SubSystem: '<S2>/vr' */
    /* Switch: '<S13>/Switch' incorporates:
     *  Constant: '<Root>/direction'
     *  Constant: '<Root>/enable'
     *  Constant: '<S13>/Constant2'
     */
    if (Abstandsregler_P.enable_Value > Abstandsregler_P.Switch_Threshold_n) {
      tmp = Abstandsregler_P.direction_Value;
    } else {
      tmp = Abstandsregler_P.Constant2_Value_j;
    }

    /* End of Switch: '<S13>/Switch' */

    /* DataTypeConversion: '<S20>/Data Type Conversion' */
    if (tmp < 256.0) {
      if (tmp >= 0.0) {
        tmp_0 = (uint8_T)tmp;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    /* End of DataTypeConversion: '<S20>/Data Type Conversion' */

    /* S-Function (arduinodigitaloutput_sfcn): '<S20>/Digital Output' */
    MW_digitalWrite(Abstandsregler_P.DigitalOutput_pinNumber_n, tmp_0);

    /* Switch: '<S13>/Switch1' incorporates:
     *  Constant: '<Root>/enable'
     *  Constant: '<S13>/Constant3'
     */
    if (Abstandsregler_P.enable_Value > Abstandsregler_P.Switch1_Threshold_k) {
      /* Saturate: '<S42>/Saturate' */
      if (rtb_Sum > Abstandsregler_P.DiscretePIDController_UpperSa_l) {
        rtb_Sum = Abstandsregler_P.DiscretePIDController_UpperSa_l;
      } else {
        if (rtb_Sum < Abstandsregler_P.DiscretePIDController_LowerSa_e) {
          rtb_Sum = Abstandsregler_P.DiscretePIDController_LowerSa_e;
        }
      }

      /* End of Saturate: '<S42>/Saturate' */
    } else {
      rtb_Sum = Abstandsregler_P.Constant3_Value_k;
    }

    /* End of Switch: '<S13>/Switch1' */

    /* DataTypeConversion: '<S21>/Data Type Conversion' */
    if (rtb_Sum < 256.0) {
      if (rtb_Sum >= 0.0) {
        tmp_0 = (uint8_T)rtb_Sum;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    /* End of DataTypeConversion: '<S21>/Data Type Conversion' */

    /* S-Function (arduinoanalogoutput_sfcn): '<S21>/PWM' */
    MW_analogWrite(Abstandsregler_P.PWM_pinNumber_g, tmp_0);

    /* End of Outputs for SubSystem: '<S2>/vr' */

    /* S-Function (arduinodigitalinput_sfcn): '<S22>/HL' */
    rtb_HL_0 = MW_digitalRead(Abstandsregler_P.HL_p1);

    /* RelationalOperator: '<S35>/Compare' incorporates:
     *  Constant: '<S35>/Constant'
     *  S-Function (arduinodigitalinput_sfcn): '<S22>/HL'
     */
    rtb_Compare = ((int16_T)rtb_HL_0 > (int16_T)
                   Abstandsregler_P.Constant_Value_k);

    /* RelationalOperator: '<S27>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S27>/Delay Input1'
     */
    rtb_FixPtRelationalOperator = ((int16_T)rtb_Compare > (int16_T)
      Abstandsregler_DW.DelayInput1_DSTATE);

    /* S-Function (arduinodigitalinput_sfcn): '<S22>/HR' */
    rtb_HL_0 = MW_digitalRead(Abstandsregler_P.HR_p1);

    /* RelationalOperator: '<S36>/Compare' incorporates:
     *  Constant: '<S36>/Constant'
     *  S-Function (arduinodigitalinput_sfcn): '<S22>/HR'
     */
    rtb_Compare_c = ((int16_T)rtb_HL_0 > (int16_T)
                     Abstandsregler_P.Constant_Value_fr);

    /* RelationalOperator: '<S28>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S28>/Delay Input1'
     */
    rtb_FixPtRelationalOperator_k = ((int16_T)rtb_Compare_c > (int16_T)
      Abstandsregler_DW.DelayInput1_DSTATE_c);

    /* S-Function (arduinodigitalinput_sfcn): '<S22>/VR' */
    rtb_HL_0 = MW_digitalRead(Abstandsregler_P.VR_p1);

    /* RelationalOperator: '<S37>/Compare' incorporates:
     *  Constant: '<S37>/Constant'
     *  S-Function (arduinodigitalinput_sfcn): '<S22>/VR'
     */
    rtb_Compare_f = ((int16_T)rtb_HL_0 > (int16_T)
                     Abstandsregler_P.Constant_Value_od);

    /* RelationalOperator: '<S29>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S29>/Delay Input1'
     */
    rtb_FixPtRelationalOperator_d = ((int16_T)rtb_Compare_f > (int16_T)
      Abstandsregler_DW.DelayInput1_DSTATE_o);

    /* S-Function (arduinodigitalinput_sfcn): '<S22>/VL' */
    rtb_HL_0 = MW_digitalRead(Abstandsregler_P.VL_p1);

    /* RelationalOperator: '<S38>/Compare' incorporates:
     *  Constant: '<S38>/Constant'
     *  S-Function (arduinodigitalinput_sfcn): '<S22>/VL'
     */
    rtb_Compare_p = ((int16_T)rtb_HL_0 > (int16_T)
                     Abstandsregler_P.Constant_Value_fp);

    /* RelationalOperator: '<S30>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S30>/Delay Input1'
     */
    rtb_FixPtRelationalOperator_c = ((int16_T)rtb_Compare_p > (int16_T)
      Abstandsregler_DW.DelayInput1_DSTATE_ol);

    /* Outputs for Triggered SubSystem: '<S22>/Subsystem' */

    /* Constant: '<S22>/Constant' */
    Abstandsregler_Subsystem(rtb_FixPtRelationalOperator_k,
      Abstandsregler_P.Constant_Value_j, &Abstandsregler_B.Subsystem,
      &Abstandsregler_DW.Subsystem, (P_Subsystem_Abstandsregler_T *)
      &Abstandsregler_P.Subsystem, &Abstandsregler_PrevZCX.Subsystem);

    /* End of Outputs for SubSystem: '<S22>/Subsystem' */

    /* Outputs for Triggered SubSystem: '<S22>/Subsystem1' */
    Abstandsregler_Subsystem(rtb_FixPtRelationalOperator_d,
      Abstandsregler_P.Constant_Value_j, &Abstandsregler_B.Subsystem1,
      &Abstandsregler_DW.Subsystem1, (P_Subsystem_Abstandsregler_T *)
      &Abstandsregler_P.Subsystem1, &Abstandsregler_PrevZCX.Subsystem1);

    /* End of Outputs for SubSystem: '<S22>/Subsystem1' */

    /* Outputs for Triggered SubSystem: '<S22>/Subsystem2' */
    Abstandsregler_Subsystem(rtb_FixPtRelationalOperator_c,
      Abstandsregler_P.Constant_Value_j, &Abstandsregler_B.Subsystem2,
      &Abstandsregler_DW.Subsystem2, (P_Subsystem_Abstandsregler_T *)
      &Abstandsregler_P.Subsystem2, &Abstandsregler_PrevZCX.Subsystem2);

    /* End of Outputs for SubSystem: '<S22>/Subsystem2' */

    /* Outputs for Triggered SubSystem: '<S22>/Subsystem3' */
    Abstandsregler_Subsystem(rtb_FixPtRelationalOperator,
      Abstandsregler_P.Constant_Value_j, &Abstandsregler_B.Subsystem3,
      &Abstandsregler_DW.Subsystem3, (P_Subsystem_Abstandsregler_T *)
      &Abstandsregler_P.Subsystem3, &Abstandsregler_PrevZCX.Subsystem3);

    /* End of Outputs for SubSystem: '<S22>/Subsystem3' */

    /* DiscreteStateSpace: '<S23>/r+1 Altwerte' */
    {
      Abstandsregler_B.r1Altwerte[0] = Abstandsregler_P.r1Altwerte_C[0]*
        Abstandsregler_DW.r1Altwerte_DSTATE[0]
        + Abstandsregler_P.r1Altwerte_C[4]*Abstandsregler_DW.r1Altwerte_DSTATE[1]
        + Abstandsregler_P.r1Altwerte_C[8]*Abstandsregler_DW.r1Altwerte_DSTATE[2]
        + Abstandsregler_P.r1Altwerte_C[12]*Abstandsregler_DW.r1Altwerte_DSTATE
        [3];
      Abstandsregler_B.r1Altwerte[1] = Abstandsregler_P.r1Altwerte_C[1]*
        Abstandsregler_DW.r1Altwerte_DSTATE[0]
        + Abstandsregler_P.r1Altwerte_C[5]*Abstandsregler_DW.r1Altwerte_DSTATE[1]
        + Abstandsregler_P.r1Altwerte_C[9]*Abstandsregler_DW.r1Altwerte_DSTATE[2]
        + Abstandsregler_P.r1Altwerte_C[13]*Abstandsregler_DW.r1Altwerte_DSTATE
        [3];
      Abstandsregler_B.r1Altwerte[2] = Abstandsregler_P.r1Altwerte_C[2]*
        Abstandsregler_DW.r1Altwerte_DSTATE[0]
        + Abstandsregler_P.r1Altwerte_C[6]*Abstandsregler_DW.r1Altwerte_DSTATE[1]
        + Abstandsregler_P.r1Altwerte_C[10]*Abstandsregler_DW.r1Altwerte_DSTATE
        [2]
        + Abstandsregler_P.r1Altwerte_C[14]*Abstandsregler_DW.r1Altwerte_DSTATE
        [3];
      Abstandsregler_B.r1Altwerte[3] = Abstandsregler_P.r1Altwerte_C[3]*
        Abstandsregler_DW.r1Altwerte_DSTATE[0]
        + Abstandsregler_P.r1Altwerte_C[7]*Abstandsregler_DW.r1Altwerte_DSTATE[1]
        + Abstandsregler_P.r1Altwerte_C[11]*Abstandsregler_DW.r1Altwerte_DSTATE
        [2]
        + Abstandsregler_P.r1Altwerte_C[15]*Abstandsregler_DW.r1Altwerte_DSTATE
        [3];
    }

    /* DiscreteStateSpace: '<S24>/r+1 Altwerte' */
    {
      Abstandsregler_B.r1Altwerte_n[0] = Abstandsregler_P.r1Altwerte_C_b[0]*
        Abstandsregler_DW.r1Altwerte_DSTATE_o[0]
        + Abstandsregler_P.r1Altwerte_C_b[4]*
        Abstandsregler_DW.r1Altwerte_DSTATE_o[1]
        + Abstandsregler_P.r1Altwerte_C_b[8]*
        Abstandsregler_DW.r1Altwerte_DSTATE_o[2]
        + Abstandsregler_P.r1Altwerte_C_b[12]*
        Abstandsregler_DW.r1Altwerte_DSTATE_o[3];
      Abstandsregler_B.r1Altwerte_n[1] = Abstandsregler_P.r1Altwerte_C_b[1]*
        Abstandsregler_DW.r1Altwerte_DSTATE_o[0]
        + Abstandsregler_P.r1Altwerte_C_b[5]*
        Abstandsregler_DW.r1Altwerte_DSTATE_o[1]
        + Abstandsregler_P.r1Altwerte_C_b[9]*
        Abstandsregler_DW.r1Altwerte_DSTATE_o[2]
        + Abstandsregler_P.r1Altwerte_C_b[13]*
        Abstandsregler_DW.r1Altwerte_DSTATE_o[3];
      Abstandsregler_B.r1Altwerte_n[2] = Abstandsregler_P.r1Altwerte_C_b[2]*
        Abstandsregler_DW.r1Altwerte_DSTATE_o[0]
        + Abstandsregler_P.r1Altwerte_C_b[6]*
        Abstandsregler_DW.r1Altwerte_DSTATE_o[1]
        + Abstandsregler_P.r1Altwerte_C_b[10]*
        Abstandsregler_DW.r1Altwerte_DSTATE_o[2]
        + Abstandsregler_P.r1Altwerte_C_b[14]*
        Abstandsregler_DW.r1Altwerte_DSTATE_o[3];
      Abstandsregler_B.r1Altwerte_n[3] = Abstandsregler_P.r1Altwerte_C_b[3]*
        Abstandsregler_DW.r1Altwerte_DSTATE_o[0]
        + Abstandsregler_P.r1Altwerte_C_b[7]*
        Abstandsregler_DW.r1Altwerte_DSTATE_o[1]
        + Abstandsregler_P.r1Altwerte_C_b[11]*
        Abstandsregler_DW.r1Altwerte_DSTATE_o[2]
        + Abstandsregler_P.r1Altwerte_C_b[15]*
        Abstandsregler_DW.r1Altwerte_DSTATE_o[3];
    }

    /* DiscreteStateSpace: '<S25>/r+1 Altwerte' */
    {
      Abstandsregler_B.r1Altwerte_o[0] = Abstandsregler_P.r1Altwerte_C_j[0]*
        Abstandsregler_DW.r1Altwerte_DSTATE_a[0]
        + Abstandsregler_P.r1Altwerte_C_j[4]*
        Abstandsregler_DW.r1Altwerte_DSTATE_a[1]
        + Abstandsregler_P.r1Altwerte_C_j[8]*
        Abstandsregler_DW.r1Altwerte_DSTATE_a[2]
        + Abstandsregler_P.r1Altwerte_C_j[12]*
        Abstandsregler_DW.r1Altwerte_DSTATE_a[3];
      Abstandsregler_B.r1Altwerte_o[1] = Abstandsregler_P.r1Altwerte_C_j[1]*
        Abstandsregler_DW.r1Altwerte_DSTATE_a[0]
        + Abstandsregler_P.r1Altwerte_C_j[5]*
        Abstandsregler_DW.r1Altwerte_DSTATE_a[1]
        + Abstandsregler_P.r1Altwerte_C_j[9]*
        Abstandsregler_DW.r1Altwerte_DSTATE_a[2]
        + Abstandsregler_P.r1Altwerte_C_j[13]*
        Abstandsregler_DW.r1Altwerte_DSTATE_a[3];
      Abstandsregler_B.r1Altwerte_o[2] = Abstandsregler_P.r1Altwerte_C_j[2]*
        Abstandsregler_DW.r1Altwerte_DSTATE_a[0]
        + Abstandsregler_P.r1Altwerte_C_j[6]*
        Abstandsregler_DW.r1Altwerte_DSTATE_a[1]
        + Abstandsregler_P.r1Altwerte_C_j[10]*
        Abstandsregler_DW.r1Altwerte_DSTATE_a[2]
        + Abstandsregler_P.r1Altwerte_C_j[14]*
        Abstandsregler_DW.r1Altwerte_DSTATE_a[3];
      Abstandsregler_B.r1Altwerte_o[3] = Abstandsregler_P.r1Altwerte_C_j[3]*
        Abstandsregler_DW.r1Altwerte_DSTATE_a[0]
        + Abstandsregler_P.r1Altwerte_C_j[7]*
        Abstandsregler_DW.r1Altwerte_DSTATE_a[1]
        + Abstandsregler_P.r1Altwerte_C_j[11]*
        Abstandsregler_DW.r1Altwerte_DSTATE_a[2]
        + Abstandsregler_P.r1Altwerte_C_j[15]*
        Abstandsregler_DW.r1Altwerte_DSTATE_a[3];
    }

    /* DiscreteStateSpace: '<S26>/r+1 Altwerte' */
    {
      Abstandsregler_B.r1Altwerte_h[0] = Abstandsregler_P.r1Altwerte_C_js[0]*
        Abstandsregler_DW.r1Altwerte_DSTATE_g[0]
        + Abstandsregler_P.r1Altwerte_C_js[4]*
        Abstandsregler_DW.r1Altwerte_DSTATE_g[1]
        + Abstandsregler_P.r1Altwerte_C_js[8]*
        Abstandsregler_DW.r1Altwerte_DSTATE_g[2]
        + Abstandsregler_P.r1Altwerte_C_js[12]*
        Abstandsregler_DW.r1Altwerte_DSTATE_g[3];
      Abstandsregler_B.r1Altwerte_h[1] = Abstandsregler_P.r1Altwerte_C_js[1]*
        Abstandsregler_DW.r1Altwerte_DSTATE_g[0]
        + Abstandsregler_P.r1Altwerte_C_js[5]*
        Abstandsregler_DW.r1Altwerte_DSTATE_g[1]
        + Abstandsregler_P.r1Altwerte_C_js[9]*
        Abstandsregler_DW.r1Altwerte_DSTATE_g[2]
        + Abstandsregler_P.r1Altwerte_C_js[13]*
        Abstandsregler_DW.r1Altwerte_DSTATE_g[3];
      Abstandsregler_B.r1Altwerte_h[2] = Abstandsregler_P.r1Altwerte_C_js[2]*
        Abstandsregler_DW.r1Altwerte_DSTATE_g[0]
        + Abstandsregler_P.r1Altwerte_C_js[6]*
        Abstandsregler_DW.r1Altwerte_DSTATE_g[1]
        + Abstandsregler_P.r1Altwerte_C_js[10]*
        Abstandsregler_DW.r1Altwerte_DSTATE_g[2]
        + Abstandsregler_P.r1Altwerte_C_js[14]*
        Abstandsregler_DW.r1Altwerte_DSTATE_g[3];
      Abstandsregler_B.r1Altwerte_h[3] = Abstandsregler_P.r1Altwerte_C_js[3]*
        Abstandsregler_DW.r1Altwerte_DSTATE_g[0]
        + Abstandsregler_P.r1Altwerte_C_js[7]*
        Abstandsregler_DW.r1Altwerte_DSTATE_g[1]
        + Abstandsregler_P.r1Altwerte_C_js[11]*
        Abstandsregler_DW.r1Altwerte_DSTATE_g[2]
        + Abstandsregler_P.r1Altwerte_C_js[15]*
        Abstandsregler_DW.r1Altwerte_DSTATE_g[3];
    }
  }

  {
    int_T i;
    real_T xnew[3];
    real_T xnew_0[3];
    real_T xnew_1;

    /* Update for DiscreteIntegrator: '<S9>/Integrator' */
    Abstandsregler_DW.Integrator_DSTATE = Abstandsregler_B.Integrator;

    /* Update for DiscreteStateSpace: '<S23>/Zustandsvariablenfilter' */
    for (i = 0; i < 3; i++) {
      xnew_1 = Abstandsregler_P.BD[i] * Abstandsregler_B.r1Altwerte[0] +
        (Abstandsregler_P.AD[i + 6] *
         Abstandsregler_DW.Zustandsvariablenfilter_DSTATE[2] +
         (Abstandsregler_P.AD[i + 3] *
          Abstandsregler_DW.Zustandsvariablenfilter_DSTATE[1] +
          Abstandsregler_P.AD[i] *
          Abstandsregler_DW.Zustandsvariablenfilter_DSTATE[0]));
      xnew_1 += Abstandsregler_P.BD[i + 3] * Abstandsregler_B.r1Altwerte[1];
      xnew_1 += Abstandsregler_P.BD[i + 6] * Abstandsregler_B.r1Altwerte[2];
      xnew_1 += Abstandsregler_P.BD[i + 9] * Abstandsregler_B.r1Altwerte[3];
      xnew[i] = xnew_1;
    }

    /* Update for DiscreteIntegrator: '<S39>/Integrator' */
    Abstandsregler_DW.Integrator_DSTATE_o = Abstandsregler_B.Integrator_i;
    for (i = 0; i < 3; i++) {
      /* Update for DiscreteStateSpace: '<S23>/Zustandsvariablenfilter' */
      Abstandsregler_DW.Zustandsvariablenfilter_DSTATE[i] = xnew[i];

      /* Update for DiscreteStateSpace: '<S24>/Zustandsvariablenfilter' */
      xnew_1 = Abstandsregler_P.BD[i] * Abstandsregler_B.r1Altwerte_n[0] +
        (Abstandsregler_P.AD[i + 6] *
         Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_n[2] +
         (Abstandsregler_P.AD[i + 3] *
          Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_n[1] +
          Abstandsregler_P.AD[i] *
          Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_n[0]));
      xnew_1 += Abstandsregler_P.BD[i + 3] * Abstandsregler_B.r1Altwerte_n[1];
      xnew_1 += Abstandsregler_P.BD[i + 6] * Abstandsregler_B.r1Altwerte_n[2];
      xnew_1 += Abstandsregler_P.BD[i + 9] * Abstandsregler_B.r1Altwerte_n[3];
      xnew_0[i] = xnew_1;
    }

    /* Update for DiscreteIntegrator: '<S40>/Integrator' */
    Abstandsregler_DW.Integrator_DSTATE_g = Abstandsregler_B.Integrator_n;
    for (i = 0; i < 3; i++) {
      /* Update for DiscreteStateSpace: '<S24>/Zustandsvariablenfilter' */
      Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_n[i] = xnew_0[i];

      /* Update for DiscreteStateSpace: '<S25>/Zustandsvariablenfilter' */
      xnew_1 = Abstandsregler_P.BD[i] * Abstandsregler_B.r1Altwerte_o[0] +
        (Abstandsregler_P.AD[i + 6] *
         Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_o[2] +
         (Abstandsregler_P.AD[i + 3] *
          Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_o[1] +
          Abstandsregler_P.AD[i] *
          Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_o[0]));
      xnew_1 += Abstandsregler_P.BD[i + 3] * Abstandsregler_B.r1Altwerte_o[1];
      xnew_1 += Abstandsregler_P.BD[i + 6] * Abstandsregler_B.r1Altwerte_o[2];
      xnew_1 += Abstandsregler_P.BD[i + 9] * Abstandsregler_B.r1Altwerte_o[3];
      xnew[i] = xnew_1;
    }

    /* Update for DiscreteIntegrator: '<S41>/Integrator' */
    Abstandsregler_DW.Integrator_DSTATE_k = Abstandsregler_B.Integrator_is;
    for (i = 0; i < 3; i++) {
      /* Update for DiscreteStateSpace: '<S25>/Zustandsvariablenfilter' */
      Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_o[i] = xnew[i];

      /* Update for DiscreteStateSpace: '<S26>/Zustandsvariablenfilter' */
      xnew_1 = Abstandsregler_P.BD[i] * Abstandsregler_B.r1Altwerte_h[0] +
        (Abstandsregler_P.AD[i + 6] *
         Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_c[2] +
         (Abstandsregler_P.AD[i + 3] *
          Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_c[1] +
          Abstandsregler_P.AD[i] *
          Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_c[0]));
      xnew_1 += Abstandsregler_P.BD[i + 3] * Abstandsregler_B.r1Altwerte_h[1];
      xnew_1 += Abstandsregler_P.BD[i + 6] * Abstandsregler_B.r1Altwerte_h[2];
      xnew_1 += Abstandsregler_P.BD[i + 9] * Abstandsregler_B.r1Altwerte_h[3];
      xnew_0[i] = xnew_1;
    }

    /* Update for DiscreteStateSpace: '<S26>/Zustandsvariablenfilter' */
    Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_c[0] = xnew_0[0];
    Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_c[1] = xnew_0[1];
    Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_c[2] = xnew_0[2];

    /* Update for DiscreteIntegrator: '<S42>/Integrator' */
    Abstandsregler_DW.Integrator_DSTATE_gl = Abstandsregler_B.Integrator_i4;

    /* Update for UnitDelay: '<S27>/Delay Input1' */
    Abstandsregler_DW.DelayInput1_DSTATE = rtb_Compare;

    /* Update for UnitDelay: '<S28>/Delay Input1' */
    Abstandsregler_DW.DelayInput1_DSTATE_c = rtb_Compare_c;

    /* Update for UnitDelay: '<S29>/Delay Input1' */
    Abstandsregler_DW.DelayInput1_DSTATE_o = rtb_Compare_f;

    /* Update for UnitDelay: '<S30>/Delay Input1' */
    Abstandsregler_DW.DelayInput1_DSTATE_ol = rtb_Compare_p;

    /* Update for DiscreteStateSpace: '<S23>/r+1 Altwerte' */
    {
      real_T xtmp = Abstandsregler_B.Subsystem3.Add;
      xtmp += (Abstandsregler_P.r1Altwerte_A[0])*
        Abstandsregler_DW.r1Altwerte_DSTATE[0]
        + (Abstandsregler_P.r1Altwerte_A[1])*
        Abstandsregler_DW.r1Altwerte_DSTATE[1]
        + (Abstandsregler_P.r1Altwerte_A[2])*
        Abstandsregler_DW.r1Altwerte_DSTATE[2]
        + (Abstandsregler_P.r1Altwerte_A[3])*
        Abstandsregler_DW.r1Altwerte_DSTATE[3];
      Abstandsregler_DW.r1Altwerte_DSTATE[3] =
        Abstandsregler_DW.r1Altwerte_DSTATE[2];
      Abstandsregler_DW.r1Altwerte_DSTATE[2] =
        Abstandsregler_DW.r1Altwerte_DSTATE[1];
      Abstandsregler_DW.r1Altwerte_DSTATE[1] =
        Abstandsregler_DW.r1Altwerte_DSTATE[0];
      Abstandsregler_DW.r1Altwerte_DSTATE[0] = xtmp;
    }

    /* Update for DiscreteStateSpace: '<S24>/r+1 Altwerte' */
    {
      real_T xtmp = Abstandsregler_B.Subsystem.Add;
      xtmp += (Abstandsregler_P.r1Altwerte_A_i[0])*
        Abstandsregler_DW.r1Altwerte_DSTATE_o[0]
        + (Abstandsregler_P.r1Altwerte_A_i[1])*
        Abstandsregler_DW.r1Altwerte_DSTATE_o[1]
        + (Abstandsregler_P.r1Altwerte_A_i[2])*
        Abstandsregler_DW.r1Altwerte_DSTATE_o[2]
        + (Abstandsregler_P.r1Altwerte_A_i[3])*
        Abstandsregler_DW.r1Altwerte_DSTATE_o[3];
      Abstandsregler_DW.r1Altwerte_DSTATE_o[3] =
        Abstandsregler_DW.r1Altwerte_DSTATE_o[2];
      Abstandsregler_DW.r1Altwerte_DSTATE_o[2] =
        Abstandsregler_DW.r1Altwerte_DSTATE_o[1];
      Abstandsregler_DW.r1Altwerte_DSTATE_o[1] =
        Abstandsregler_DW.r1Altwerte_DSTATE_o[0];
      Abstandsregler_DW.r1Altwerte_DSTATE_o[0] = xtmp;
    }

    /* Update for DiscreteStateSpace: '<S25>/r+1 Altwerte' */
    {
      real_T xtmp = Abstandsregler_B.Subsystem2.Add;
      xtmp += (Abstandsregler_P.r1Altwerte_A_h[0])*
        Abstandsregler_DW.r1Altwerte_DSTATE_a[0]
        + (Abstandsregler_P.r1Altwerte_A_h[1])*
        Abstandsregler_DW.r1Altwerte_DSTATE_a[1]
        + (Abstandsregler_P.r1Altwerte_A_h[2])*
        Abstandsregler_DW.r1Altwerte_DSTATE_a[2]
        + (Abstandsregler_P.r1Altwerte_A_h[3])*
        Abstandsregler_DW.r1Altwerte_DSTATE_a[3];
      Abstandsregler_DW.r1Altwerte_DSTATE_a[3] =
        Abstandsregler_DW.r1Altwerte_DSTATE_a[2];
      Abstandsregler_DW.r1Altwerte_DSTATE_a[2] =
        Abstandsregler_DW.r1Altwerte_DSTATE_a[1];
      Abstandsregler_DW.r1Altwerte_DSTATE_a[1] =
        Abstandsregler_DW.r1Altwerte_DSTATE_a[0];
      Abstandsregler_DW.r1Altwerte_DSTATE_a[0] = xtmp;
    }

    /* Update for DiscreteStateSpace: '<S26>/r+1 Altwerte' */
    {
      real_T xtmp = Abstandsregler_B.Subsystem1.Add;
      xtmp += (Abstandsregler_P.r1Altwerte_A_ix[0])*
        Abstandsregler_DW.r1Altwerte_DSTATE_g[0]
        + (Abstandsregler_P.r1Altwerte_A_ix[1])*
        Abstandsregler_DW.r1Altwerte_DSTATE_g[1]
        + (Abstandsregler_P.r1Altwerte_A_ix[2])*
        Abstandsregler_DW.r1Altwerte_DSTATE_g[2]
        + (Abstandsregler_P.r1Altwerte_A_ix[3])*
        Abstandsregler_DW.r1Altwerte_DSTATE_g[3];
      Abstandsregler_DW.r1Altwerte_DSTATE_g[3] =
        Abstandsregler_DW.r1Altwerte_DSTATE_g[2];
      Abstandsregler_DW.r1Altwerte_DSTATE_g[2] =
        Abstandsregler_DW.r1Altwerte_DSTATE_g[1];
      Abstandsregler_DW.r1Altwerte_DSTATE_g[1] =
        Abstandsregler_DW.r1Altwerte_DSTATE_g[0];
      Abstandsregler_DW.r1Altwerte_DSTATE_g[0] = xtmp;
    }
  }

  /* External mode */
  rtExtModeUploadCheckTrigger(2);

  {                                    /* Sample time: [0.0s, 0.0s] */
    rtExtModeUpload(0, Abstandsregler_M->Timing.t[0]);
  }

  {                                    /* Sample time: [0.01s, 0.0s] */
    rtExtModeUpload(1, ((Abstandsregler_M->Timing.clockTick1) * 0.01));
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(Abstandsregler_M)!=-1) &&
        !((rtmGetTFinal(Abstandsregler_M)-Abstandsregler_M->Timing.t[0]) >
          Abstandsregler_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(Abstandsregler_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Abstandsregler_M)) {
      rtmSetErrorStatus(Abstandsregler_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Abstandsregler_M->Timing.t[0] =
    (++Abstandsregler_M->Timing.clockTick0) * Abstandsregler_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Abstandsregler_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Abstandsregler_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Abstandsregler_M, 0,
                sizeof(RT_MODEL_Abstandsregler_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Abstandsregler_M->solverInfo,
                          &Abstandsregler_M->Timing.simTimeStep);
    rtsiSetTPtr(&Abstandsregler_M->solverInfo, &rtmGetTPtr(Abstandsregler_M));
    rtsiSetStepSizePtr(&Abstandsregler_M->solverInfo,
                       &Abstandsregler_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Abstandsregler_M->solverInfo, (&rtmGetErrorStatus
      (Abstandsregler_M)));
    rtsiSetRTModelPtr(&Abstandsregler_M->solverInfo, Abstandsregler_M);
  }

  rtsiSetSimTimeStep(&Abstandsregler_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Abstandsregler_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Abstandsregler_M, &Abstandsregler_M->Timing.tArray[0]);
  rtmSetTFinal(Abstandsregler_M, 100.0);
  Abstandsregler_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Abstandsregler_M->Sizes.checksums[0] = (2178771138U);
  Abstandsregler_M->Sizes.checksums[1] = (180325398U);
  Abstandsregler_M->Sizes.checksums[2] = (1871106949U);
  Abstandsregler_M->Sizes.checksums[3] = (2760714203U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[21];
    Abstandsregler_M->extModeInfo = (&rt_ExtModeInfo);
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
      &Abstandsregler_DW.Subsystem.Subsystem_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &Abstandsregler_DW.Subsystem.Subsystem_SubsysRanBC;
    systemRan[15] = (sysRanDType *)
      &Abstandsregler_DW.Subsystem1.Subsystem_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &Abstandsregler_DW.Subsystem1.Subsystem_SubsysRanBC;
    systemRan[17] = (sysRanDType *)
      &Abstandsregler_DW.Subsystem2.Subsystem_SubsysRanBC;
    systemRan[18] = (sysRanDType *)
      &Abstandsregler_DW.Subsystem2.Subsystem_SubsysRanBC;
    systemRan[19] = (sysRanDType *)
      &Abstandsregler_DW.Subsystem3.Subsystem_SubsysRanBC;
    systemRan[20] = (sysRanDType *)
      &Abstandsregler_DW.Subsystem3.Subsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(Abstandsregler_M->extModeInfo,
      &Abstandsregler_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Abstandsregler_M->extModeInfo,
                        Abstandsregler_M->Sizes.checksums);
    rteiSetTPtr(Abstandsregler_M->extModeInfo, rtmGetTPtr(Abstandsregler_M));
  }

  /* block I/O */
  (void) memset(((void *) &Abstandsregler_B), 0,
                sizeof(B_Abstandsregler_T));

  /* states (dwork) */
  (void) memset((void *)&Abstandsregler_DW, 0,
                sizeof(DW_Abstandsregler_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Abstandsregler_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S1>/Abstandssensor' */
  MW_pinModeAnalogInput(Abstandsregler_P.Abstandssensor_p1);

  /* Start for Atomic SubSystem: '<S2>/hl' */
  Abstandsregler_hl_Start((P_hl_Abstandsregler_T *)&Abstandsregler_P.hl);

  /* End of Start for SubSystem: '<S2>/hl' */

  /* Start for Atomic SubSystem: '<S2>/hr' */
  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S16>/Digital Output' */
  MW_pinModeOutput(Abstandsregler_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S17>/PWM' */
  MW_pinModeOutput(Abstandsregler_P.PWM_pinNumber);

  /* End of Start for SubSystem: '<S2>/hr' */

  /* Start for Atomic SubSystem: '<S2>/vl' */
  Abstandsregler_hl_Start((P_hl_Abstandsregler_T *)&Abstandsregler_P.vl);

  /* End of Start for SubSystem: '<S2>/vl' */

  /* Start for Atomic SubSystem: '<S2>/vr' */
  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S20>/Digital Output' */
  MW_pinModeOutput(Abstandsregler_P.DigitalOutput_pinNumber_n);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S21>/PWM' */
  MW_pinModeOutput(Abstandsregler_P.PWM_pinNumber_g);

  /* End of Start for SubSystem: '<S2>/vr' */
  /* Start for S-Function (arduinodigitalinput_sfcn): '<S22>/HL' */
  MW_pinModeInput(Abstandsregler_P.HL_p1);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S22>/HR' */
  MW_pinModeInput(Abstandsregler_P.HR_p1);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S22>/VR' */
  MW_pinModeInput(Abstandsregler_P.VR_p1);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S22>/VL' */
  MW_pinModeInput(Abstandsregler_P.VL_p1);

  /* Start for Triggered SubSystem: '<S22>/Subsystem' */
  Abstandsregler_Subsystem_Start(&Abstandsregler_B.Subsystem,
    (P_Subsystem_Abstandsregler_T *)&Abstandsregler_P.Subsystem);

  /* End of Start for SubSystem: '<S22>/Subsystem' */

  /* Start for Triggered SubSystem: '<S22>/Subsystem1' */
  Abstandsregler_Subsystem_Start(&Abstandsregler_B.Subsystem1,
    (P_Subsystem_Abstandsregler_T *)&Abstandsregler_P.Subsystem1);

  /* End of Start for SubSystem: '<S22>/Subsystem1' */

  /* Start for Triggered SubSystem: '<S22>/Subsystem2' */
  Abstandsregler_Subsystem_Start(&Abstandsregler_B.Subsystem2,
    (P_Subsystem_Abstandsregler_T *)&Abstandsregler_P.Subsystem2);

  /* End of Start for SubSystem: '<S22>/Subsystem2' */

  /* Start for Triggered SubSystem: '<S22>/Subsystem3' */
  Abstandsregler_Subsystem_Start(&Abstandsregler_B.Subsystem3,
    (P_Subsystem_Abstandsregler_T *)&Abstandsregler_P.Subsystem3);

  /* End of Start for SubSystem: '<S22>/Subsystem3' */
  Abstandsregler_PrevZCX.Subsystem3.Subsystem_Trig_ZCE = POS_ZCSIG;
  Abstandsregler_PrevZCX.Subsystem2.Subsystem_Trig_ZCE = POS_ZCSIG;
  Abstandsregler_PrevZCX.Subsystem1.Subsystem_Trig_ZCE = POS_ZCSIG;
  Abstandsregler_PrevZCX.Subsystem.Subsystem_Trig_ZCE = POS_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S9>/Integrator' */
  Abstandsregler_DW.Integrator_DSTATE = Abstandsregler_P.Integrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S39>/Integrator' */
  Abstandsregler_DW.Integrator_DSTATE_o = Abstandsregler_P.Integrator_IC_p;

  /* InitializeConditions for DiscreteIntegrator: '<S40>/Integrator' */
  Abstandsregler_DW.Integrator_DSTATE_g = Abstandsregler_P.Integrator_IC_f;

  /* InitializeConditions for DiscreteIntegrator: '<S41>/Integrator' */
  Abstandsregler_DW.Integrator_DSTATE_k = Abstandsregler_P.Integrator_IC_n;

  /* InitializeConditions for DiscreteStateSpace: '<S23>/Zustandsvariablenfilter' */
  Abstandsregler_DW.Zustandsvariablenfilter_DSTATE[0] = Abstandsregler_P.AB2[0];

  /* InitializeConditions for DiscreteStateSpace: '<S24>/Zustandsvariablenfilter' */
  Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_n[0] = Abstandsregler_P.AB2[0];

  /* InitializeConditions for DiscreteStateSpace: '<S25>/Zustandsvariablenfilter' */
  Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_o[0] = Abstandsregler_P.AB2[0];

  /* InitializeConditions for DiscreteStateSpace: '<S26>/Zustandsvariablenfilter' */
  Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_c[0] = Abstandsregler_P.AB2[0];

  /* InitializeConditions for DiscreteStateSpace: '<S23>/Zustandsvariablenfilter' */
  Abstandsregler_DW.Zustandsvariablenfilter_DSTATE[1] = Abstandsregler_P.AB2[1];

  /* InitializeConditions for DiscreteStateSpace: '<S24>/Zustandsvariablenfilter' */
  Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_n[1] = Abstandsregler_P.AB2[1];

  /* InitializeConditions for DiscreteStateSpace: '<S25>/Zustandsvariablenfilter' */
  Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_o[1] = Abstandsregler_P.AB2[1];

  /* InitializeConditions for DiscreteStateSpace: '<S26>/Zustandsvariablenfilter' */
  Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_c[1] = Abstandsregler_P.AB2[1];

  /* InitializeConditions for DiscreteStateSpace: '<S23>/Zustandsvariablenfilter' */
  Abstandsregler_DW.Zustandsvariablenfilter_DSTATE[2] = Abstandsregler_P.AB2[2];

  /* InitializeConditions for DiscreteStateSpace: '<S24>/Zustandsvariablenfilter' */
  Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_n[2] = Abstandsregler_P.AB2[2];

  /* InitializeConditions for DiscreteStateSpace: '<S25>/Zustandsvariablenfilter' */
  Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_o[2] = Abstandsregler_P.AB2[2];

  /* InitializeConditions for DiscreteStateSpace: '<S26>/Zustandsvariablenfilter' */
  Abstandsregler_DW.Zustandsvariablenfilter_DSTAT_c[2] = Abstandsregler_P.AB2[2];

  /* InitializeConditions for DiscreteIntegrator: '<S42>/Integrator' */
  Abstandsregler_DW.Integrator_DSTATE_gl = Abstandsregler_P.Integrator_IC_i;

  /* InitializeConditions for UnitDelay: '<S27>/Delay Input1' */
  Abstandsregler_DW.DelayInput1_DSTATE =
    Abstandsregler_P.DetectRisePositive_vinit;

  /* InitializeConditions for UnitDelay: '<S28>/Delay Input1' */
  Abstandsregler_DW.DelayInput1_DSTATE_c =
    Abstandsregler_P.DetectRisePositive1_vinit;

  /* InitializeConditions for UnitDelay: '<S29>/Delay Input1' */
  Abstandsregler_DW.DelayInput1_DSTATE_o =
    Abstandsregler_P.DetectRisePositive2_vinit;

  /* InitializeConditions for UnitDelay: '<S30>/Delay Input1' */
  Abstandsregler_DW.DelayInput1_DSTATE_ol =
    Abstandsregler_P.DetectRisePositive3_vinit;

  /* InitializeConditions for Triggered SubSystem: '<S22>/Subsystem' */
  Abstandsregler_Subsystem_Init(&Abstandsregler_DW.Subsystem,
    (P_Subsystem_Abstandsregler_T *)&Abstandsregler_P.Subsystem);

  /* End of InitializeConditions for SubSystem: '<S22>/Subsystem' */

  /* InitializeConditions for Triggered SubSystem: '<S22>/Subsystem1' */
  Abstandsregler_Subsystem_Init(&Abstandsregler_DW.Subsystem1,
    (P_Subsystem_Abstandsregler_T *)&Abstandsregler_P.Subsystem1);

  /* End of InitializeConditions for SubSystem: '<S22>/Subsystem1' */

  /* InitializeConditions for Triggered SubSystem: '<S22>/Subsystem2' */
  Abstandsregler_Subsystem_Init(&Abstandsregler_DW.Subsystem2,
    (P_Subsystem_Abstandsregler_T *)&Abstandsregler_P.Subsystem2);

  /* End of InitializeConditions for SubSystem: '<S22>/Subsystem2' */

  /* InitializeConditions for Triggered SubSystem: '<S22>/Subsystem3' */
  Abstandsregler_Subsystem_Init(&Abstandsregler_DW.Subsystem3,
    (P_Subsystem_Abstandsregler_T *)&Abstandsregler_P.Subsystem3);

  /* End of InitializeConditions for SubSystem: '<S22>/Subsystem3' */

  /* InitializeConditions for DiscreteStateSpace: '<S23>/r+1 Altwerte' */
  Abstandsregler_DW.r1Altwerte_DSTATE[0] = Abstandsregler_P.AB1[0];
  Abstandsregler_DW.r1Altwerte_DSTATE[1] = Abstandsregler_P.AB1[1];
  Abstandsregler_DW.r1Altwerte_DSTATE[2] = Abstandsregler_P.AB1[2];
  Abstandsregler_DW.r1Altwerte_DSTATE[3] = Abstandsregler_P.AB1[3];

  /* InitializeConditions for DiscreteStateSpace: '<S24>/r+1 Altwerte' */
  Abstandsregler_DW.r1Altwerte_DSTATE_o[0] = Abstandsregler_P.AB1[0];
  Abstandsregler_DW.r1Altwerte_DSTATE_o[1] = Abstandsregler_P.AB1[1];
  Abstandsregler_DW.r1Altwerte_DSTATE_o[2] = Abstandsregler_P.AB1[2];
  Abstandsregler_DW.r1Altwerte_DSTATE_o[3] = Abstandsregler_P.AB1[3];

  /* InitializeConditions for DiscreteStateSpace: '<S25>/r+1 Altwerte' */
  Abstandsregler_DW.r1Altwerte_DSTATE_a[0] = Abstandsregler_P.AB1[0];
  Abstandsregler_DW.r1Altwerte_DSTATE_a[1] = Abstandsregler_P.AB1[1];
  Abstandsregler_DW.r1Altwerte_DSTATE_a[2] = Abstandsregler_P.AB1[2];
  Abstandsregler_DW.r1Altwerte_DSTATE_a[3] = Abstandsregler_P.AB1[3];

  /* InitializeConditions for DiscreteStateSpace: '<S26>/r+1 Altwerte' */
  Abstandsregler_DW.r1Altwerte_DSTATE_g[0] = Abstandsregler_P.AB1[0];
  Abstandsregler_DW.r1Altwerte_DSTATE_g[1] = Abstandsregler_P.AB1[1];
  Abstandsregler_DW.r1Altwerte_DSTATE_g[2] = Abstandsregler_P.AB1[2];
  Abstandsregler_DW.r1Altwerte_DSTATE_g[3] = Abstandsregler_P.AB1[3];
}

/* Model terminate function */
void Abstandsregler_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
