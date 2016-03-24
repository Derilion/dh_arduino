/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Geschwindigkeitsregler.c
 *
 * Code generated for Simulink model 'Geschwindigkeitsregler'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 23 16:01:11 2016
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
  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S15>/Digital Output' */
  MW_pinModeOutput(localP->DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S16>/PWM' */
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

  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S11>/Constant2'
   */
  if (rtu_enable > localP->Switch_Threshold) {
    rtu_enable_0 = rtu_direction;
  } else {
    rtu_enable_0 = localP->Constant2_Value;
  }

  /* End of Switch: '<S11>/Switch' */

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

  /* S-Function (arduinodigitaloutput_sfcn): '<S15>/Digital Output' */
  MW_digitalWrite(localP->DigitalOutput_pinNumber, rtu_enable_1);

  /* Switch: '<S11>/Switch1' incorporates:
   *  Constant: '<S11>/Constant3'
   *  DataTypeConversion: '<S16>/Data Type Conversion'
   */
  if (rtu_enable > localP->Switch1_Threshold) {
    /* DataTypeConversion: '<S16>/Data Type Conversion' */
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
    /* DataTypeConversion: '<S16>/Data Type Conversion' incorporates:
     *  Constant: '<S11>/Constant3'
     */
    if (localP->Constant3_Value >= 0.0) {
      localB->DataTypeConversion = (uint8_T)localP->Constant3_Value;
    } else {
      localB->DataTypeConversion = 0U;
    }
  } else {
    /* DataTypeConversion: '<S16>/Data Type Conversion' */
    localB->DataTypeConversion = MAX_uint8_T;
  }

  /* End of Switch: '<S11>/Switch1' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S16>/PWM' */
  MW_analogWrite(localP->PWM_pinNumber, localB->DataTypeConversion);
}

/*
 * Initial conditions for trigger system:
 *    '<S23>/Subsystem'
 *    '<S23>/Subsystem1'
 *    '<S23>/Subsystem2'
 *    '<S23>/Subsystem3'
 */
void Geschwindigkeits_Subsystem_Init(DW_Subsystem_Geschwindigkeits_T *localDW,
  P_Subsystem_Geschwindigkeitsr_T *localP)
{
  /* InitializeConditions for Delay: '<S32>/Delay' */
  localDW->Delay_DSTATE = localP->Delay_InitialCondition;
}

/*
 * Start for trigger system:
 *    '<S23>/Subsystem'
 *    '<S23>/Subsystem1'
 *    '<S23>/Subsystem2'
 *    '<S23>/Subsystem3'
 */
void Geschwindigkeit_Subsystem_Start(B_Subsystem_Geschwindigkeitsr_T *localB,
  P_Subsystem_Geschwindigkeitsr_T *localP)
{
  /* VirtualOutportStart for Outport: '<S32>/Out1' */
  localB->Add = localP->Out1_Y0;
}

/*
 * Output and update for trigger system:
 *    '<S23>/Subsystem'
 *    '<S23>/Subsystem1'
 *    '<S23>/Subsystem2'
 *    '<S23>/Subsystem3'
 */
void Geschwindigkeitsregle_Subsystem(boolean_T rtu_Trigger, real_T rtu_reset,
  B_Subsystem_Geschwindigkeitsr_T *localB, DW_Subsystem_Geschwindigkeits_T
  *localDW, P_Subsystem_Geschwindigkeitsr_T *localP,
  ZCE_Subsystem_Geschwindigkeit_T *localZCE)
{
  real_T rtu_reset_0;

  /* Outputs for Triggered SubSystem: '<S23>/Subsystem' incorporates:
   *  TriggerPort: '<S32>/Trigger'
   */
  if (rtu_Trigger && (localZCE->Subsystem_Trig_ZCE != POS_ZCSIG)) {
    /* Switch: '<S32>/Switch' incorporates:
     *  Constant: '<S32>/Constant1'
     *  Delay: '<S32>/Delay'
     */
    if (rtu_reset > localP->Switch_Threshold) {
      rtu_reset_0 = localP->Constant1_Value;
    } else {
      rtu_reset_0 = localDW->Delay_DSTATE;
    }

    /* End of Switch: '<S32>/Switch' */

    /* Sum: '<S32>/Add' incorporates:
     *  Constant: '<S32>/Constant'
     */
    localB->Add = rtu_reset_0 + localP->Constant_Value;

    /* Update for Delay: '<S32>/Delay' */
    localDW->Delay_DSTATE = localB->Add;
    localDW->Subsystem_SubsysRanBC = 4;
  }

  localZCE->Subsystem_Trig_ZCE = rtu_Trigger;

  /* End of Outputs for SubSystem: '<S23>/Subsystem' */
}

/* Model step function */
void Geschwindigkeitsregler_step(void)
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
    int_T i;
    boolean_T rtb_HL_0;
    real_T rtb_Sum;
    real_T tmp;
    uint8_T tmp_0;

    /* Reset subsysRan breadcrumbs */
    srClearBC(Geschwindigkeitsregler_DW.Subsystem.Subsystem_SubsysRanBC);

    /* FromWorkspace: '<S3>/FromWs' */
    {
      real_T *pDataValues = (real_T *)
        Geschwindigkeitsregler_DW.FromWs_PWORK.DataPtr;
      real_T *pTimeValues = (real_T *)
        Geschwindigkeitsregler_DW.FromWs_PWORK.TimePtr;
      int_T currTimeIndex = Geschwindigkeitsregler_DW.FromWs_IWORK.PrevIndex;
      real_T t = Geschwindigkeitsregler_M->Timing.t[0];
      if (t > pTimeValues[9]) {
        {
          int_T elIdx;
          for (elIdx = 0; elIdx < 2; ++elIdx) {
            (&Geschwindigkeitsregler_B.FromWs[0])[elIdx] = 0.0;
          }
        }
      } else {
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
              {
                int_T elIdx;
                for (elIdx = 0; elIdx < 2; ++elIdx) {
                  (&Geschwindigkeitsregler_B.FromWs[0])[elIdx] =
                    pDataValues[currTimeIndex];
                  pDataValues += 10;
                }
              }
            } else {
              {
                int_T elIdx;
                for (elIdx = 0; elIdx < 2; ++elIdx) {
                  (&Geschwindigkeitsregler_B.FromWs[0])[elIdx] =
                    pDataValues[currTimeIndex + 1];
                  pDataValues += 10;
                }
              }
            }
          } else {
            real_T f1 = (t2 - t) / (t2 - t1);
            real_T f2 = 1.0 - f1;
            real_T d1;
            real_T d2;
            int_T TimeIndex= currTimeIndex;

            {
              int_T elIdx;
              for (elIdx = 0; elIdx < 2; ++elIdx) {
                d1 = pDataValues[TimeIndex];
                d2 = pDataValues[TimeIndex + 1];
                (&Geschwindigkeitsregler_B.FromWs[0])[elIdx] = (real_T)
                  rtInterpolate(d1, d2, f1, f2);
                pDataValues += 10;
              }
            }
          }
        }
      }
    }

    /* DiscreteStateSpace: '<S24>/Zustandsvariablenfilter' */
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

    /* End of DiscreteStateSpace: '<S24>/Zustandsvariablenfilter' */

    /* Sum: '<S7>/Add' incorporates:
     *  Constant: '<S7>/Constant'
     *  Constant: '<S7>/Constant1'
     *  Product: '<S7>/Divide'
     */
    rtb_Sum = Geschwindigkeitsregler_B.FromWs[0] *
      Geschwindigkeitsregler_P.Constant1_Value /
      Geschwindigkeitsregler_P.Constant_Value -
      Geschwindigkeitsregler_B.Zustandsvariablenfilter[1];

    /* Product: '<S52>/IOut' incorporates:
     *  Constant: '<S7>/Constant3'
     */
    Geschwindigkeitsregler_B.IOut = rtb_Sum *
      Geschwindigkeitsregler_P.Constant3_Value_i;

    /* DiscreteIntegrator: '<S52>/Integrator' */
    Geschwindigkeitsregler_B.Integrator =
      Geschwindigkeitsregler_P.Integrator_gainval *
      Geschwindigkeitsregler_B.IOut +
      Geschwindigkeitsregler_DW.Integrator_DSTATE;

    /* Sum: '<S52>/Sum' incorporates:
     *  Constant: '<S7>/Constant2'
     *  Product: '<S52>/POut'
     */
    rtb_Sum = rtb_Sum * Geschwindigkeitsregler_P.Constant2_Value_n +
      Geschwindigkeitsregler_B.Integrator;

    /* Saturate: '<S52>/Saturate' */
    if (rtb_Sum > Geschwindigkeitsregler_P.DiscretePIDController_UpperSatu) {
      rtb_Saturate = Geschwindigkeitsregler_P.DiscretePIDController_UpperSatu;
    } else if (rtb_Sum <
               Geschwindigkeitsregler_P.DiscretePIDController_LowerSatu) {
      rtb_Saturate = Geschwindigkeitsregler_P.DiscretePIDController_LowerSatu;
    } else {
      rtb_Saturate = rtb_Sum;
    }

    /* End of Saturate: '<S52>/Saturate' */

    /* Outputs for Atomic SubSystem: '<S1>/hl' */

    /* Constant: '<Root>/enable' incorporates:
     *  Constant: '<Root>/direction'
     */
    Geschwindigkeitsregler_hl(Geschwindigkeitsregler_P.enable_Value,
      rtb_Saturate, Geschwindigkeitsregler_P.direction_Value,
      &Geschwindigkeitsregler_B.hl, (P_hl_Geschwindigkeitsregler_T *)
      &Geschwindigkeitsregler_P.hl);

    /* End of Outputs for SubSystem: '<S1>/hl' */

    /* DiscreteStateSpace: '<S25>/Zustandsvariablenfilter' */
    for (i = 0; i < 3; i++) {
      Geschwindigkeitsregler_B.Zustandsvariablenfilter_g[i] = 0.0;
      Geschwindigkeitsregler_B.Zustandsvariablenfilter_g[i] +=
        Geschwindigkeitsregler_P.Zustandsvariablenfilter_C_n[i] *
        Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_n[0];
      Geschwindigkeitsregler_B.Zustandsvariablenfilter_g[i] +=
        Geschwindigkeitsregler_P.Zustandsvariablenfilter_C_n[i + 3] *
        Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_n[1];
      Geschwindigkeitsregler_B.Zustandsvariablenfilter_g[i] +=
        Geschwindigkeitsregler_P.Zustandsvariablenfilter_C_n[i + 6] *
        Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_n[2];
    }

    /* End of DiscreteStateSpace: '<S25>/Zustandsvariablenfilter' */

    /* Sum: '<S8>/Add' incorporates:
     *  Constant: '<S8>/maxClicksproSec'
     *  Constant: '<S8>/prozent'
     *  Product: '<S8>/Divide'
     */
    Geschwindigkeitsregler_B.Add = Geschwindigkeitsregler_B.FromWs[0] *
      Geschwindigkeitsregler_P.maxClicksproSec_Value /
      Geschwindigkeitsregler_P.prozent_Value -
      Geschwindigkeitsregler_B.Zustandsvariablenfilter_g[1];

    /* Product: '<S53>/IOut' incorporates:
     *  Constant: '<S8>/i'
     */
    Geschwindigkeitsregler_B.IOut_p = Geschwindigkeitsregler_B.Add *
      Geschwindigkeitsregler_P.i_Value;

    /* DiscreteIntegrator: '<S53>/Integrator' */
    Geschwindigkeitsregler_B.Integrator_n =
      Geschwindigkeitsregler_P.Integrator_gainval_o *
      Geschwindigkeitsregler_B.IOut_p +
      Geschwindigkeitsregler_DW.Integrator_DSTATE_g;

    /* Sum: '<S53>/Sum' incorporates:
     *  Constant: '<S8>/p'
     *  Product: '<S53>/POut'
     */
    rtb_Sum = Geschwindigkeitsregler_B.Add * Geschwindigkeitsregler_P.p_Value +
      Geschwindigkeitsregler_B.Integrator_n;

    /* Saturate: '<S53>/Saturate' */
    if (rtb_Sum > Geschwindigkeitsregler_P.DiscretePIDController_UpperSa_b) {
      Geschwindigkeitsregler_B.Saturate =
        Geschwindigkeitsregler_P.DiscretePIDController_UpperSa_b;
    } else if (rtb_Sum <
               Geschwindigkeitsregler_P.DiscretePIDController_LowerSa_p) {
      Geschwindigkeitsregler_B.Saturate =
        Geschwindigkeitsregler_P.DiscretePIDController_LowerSa_p;
    } else {
      Geschwindigkeitsregler_B.Saturate = rtb_Sum;
    }

    /* End of Saturate: '<S53>/Saturate' */

    /* Outputs for Atomic SubSystem: '<S1>/hr' */
    /* Switch: '<S12>/Switch' incorporates:
     *  Constant: '<Root>/direction'
     *  Constant: '<Root>/enable'
     *  Constant: '<S12>/Constant2'
     */
    if (Geschwindigkeitsregler_P.enable_Value >
        Geschwindigkeitsregler_P.Switch_Threshold) {
      tmp = Geschwindigkeitsregler_P.direction_Value;
    } else {
      tmp = Geschwindigkeitsregler_P.Constant2_Value;
    }

    /* End of Switch: '<S12>/Switch' */

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

    /* S-Function (arduinodigitaloutput_sfcn): '<S17>/Digital Output' */
    MW_digitalWrite(Geschwindigkeitsregler_P.DigitalOutput_pinNumber, tmp_0);

    /* Switch: '<S12>/Switch1' incorporates:
     *  Constant: '<Root>/enable'
     *  Constant: '<S12>/Constant3'
     *  DataTypeConversion: '<S18>/Data Type Conversion'
     */
    if (Geschwindigkeitsregler_P.enable_Value >
        Geschwindigkeitsregler_P.Switch1_Threshold) {
      /* DataTypeConversion: '<S18>/Data Type Conversion' */
      if (Geschwindigkeitsregler_B.Saturate < 256.0) {
        if (Geschwindigkeitsregler_B.Saturate >= 0.0) {
          Geschwindigkeitsregler_B.DataTypeConversion_i = (uint8_T)
            Geschwindigkeitsregler_B.Saturate;
        } else {
          Geschwindigkeitsregler_B.DataTypeConversion_i = 0U;
        }
      } else {
        Geschwindigkeitsregler_B.DataTypeConversion_i = MAX_uint8_T;
      }
    } else if (Geschwindigkeitsregler_P.Constant3_Value < 256.0) {
      /* DataTypeConversion: '<S18>/Data Type Conversion' incorporates:
       *  Constant: '<S12>/Constant3'
       */
      if (Geschwindigkeitsregler_P.Constant3_Value >= 0.0) {
        Geschwindigkeitsregler_B.DataTypeConversion_i = (uint8_T)
          Geschwindigkeitsregler_P.Constant3_Value;
      } else {
        Geschwindigkeitsregler_B.DataTypeConversion_i = 0U;
      }
    } else {
      /* DataTypeConversion: '<S18>/Data Type Conversion' */
      Geschwindigkeitsregler_B.DataTypeConversion_i = MAX_uint8_T;
    }

    /* End of Switch: '<S12>/Switch1' */

    /* S-Function (arduinoanalogoutput_sfcn): '<S18>/PWM' */
    MW_analogWrite(Geschwindigkeitsregler_P.PWM_pinNumber,
                   Geschwindigkeitsregler_B.DataTypeConversion_i);

    /* End of Outputs for SubSystem: '<S1>/hr' */

    /* DiscreteStateSpace: '<S26>/Zustandsvariablenfilter' */
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

    /* End of DiscreteStateSpace: '<S26>/Zustandsvariablenfilter' */

    /* Sum: '<S9>/Add' incorporates:
     *  Constant: '<S9>/Constant'
     *  Constant: '<S9>/Constant1'
     *  Product: '<S9>/Divide'
     */
    rtb_Sum = Geschwindigkeitsregler_B.FromWs[0] *
      Geschwindigkeitsregler_P.Constant1_Value_c /
      Geschwindigkeitsregler_P.Constant_Value_f -
      Geschwindigkeitsregler_B.Zustandsvariablenfilter_a[1];

    /* Product: '<S54>/IOut' incorporates:
     *  Constant: '<S9>/Constant3'
     */
    Geschwindigkeitsregler_B.IOut_d = rtb_Sum *
      Geschwindigkeitsregler_P.Constant3_Value_m;

    /* DiscreteIntegrator: '<S54>/Integrator' */
    Geschwindigkeitsregler_B.Integrator_i =
      Geschwindigkeitsregler_P.Integrator_gainval_k *
      Geschwindigkeitsregler_B.IOut_d +
      Geschwindigkeitsregler_DW.Integrator_DSTATE_k;

    /* Sum: '<S54>/Sum' incorporates:
     *  Constant: '<S9>/Constant2'
     *  Product: '<S54>/POut'
     */
    rtb_Sum = rtb_Sum * Geschwindigkeitsregler_P.Constant2_Value_l +
      Geschwindigkeitsregler_B.Integrator_i;

    /* Saturate: '<S54>/Saturate' */
    if (rtb_Sum > Geschwindigkeitsregler_P.DiscretePIDController_UpperSa_o) {
      rtb_Saturate_f = Geschwindigkeitsregler_P.DiscretePIDController_UpperSa_o;
    } else if (rtb_Sum <
               Geschwindigkeitsregler_P.DiscretePIDController_LowerS_pn) {
      rtb_Saturate_f = Geschwindigkeitsregler_P.DiscretePIDController_LowerS_pn;
    } else {
      rtb_Saturate_f = rtb_Sum;
    }

    /* End of Saturate: '<S54>/Saturate' */

    /* Outputs for Atomic SubSystem: '<S1>/vl' */

    /* Constant: '<Root>/enable' incorporates:
     *  Constant: '<Root>/direction'
     */
    Geschwindigkeitsregler_hl(Geschwindigkeitsregler_P.enable_Value,
      rtb_Saturate_f, Geschwindigkeitsregler_P.direction_Value,
      &Geschwindigkeitsregler_B.vl, (P_hl_Geschwindigkeitsregler_T *)
      &Geschwindigkeitsregler_P.vl);

    /* End of Outputs for SubSystem: '<S1>/vl' */

    /* DiscreteStateSpace: '<S27>/Zustandsvariablenfilter' */
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

    /* End of DiscreteStateSpace: '<S27>/Zustandsvariablenfilter' */

    /* Sum: '<S10>/Add' incorporates:
     *  Constant: '<S10>/Constant'
     *  Constant: '<S10>/Constant1'
     *  Product: '<S10>/Divide'
     */
    rtb_Sum = Geschwindigkeitsregler_B.FromWs[0] *
      Geschwindigkeitsregler_P.Constant1_Value_e /
      Geschwindigkeitsregler_P.Constant_Value_o -
      Geschwindigkeitsregler_B.Zustandsvariablenfilter_d[1];

    /* Product: '<S55>/IOut' incorporates:
     *  Constant: '<S10>/Constant3'
     */
    Geschwindigkeitsregler_B.IOut_dm = rtb_Sum *
      Geschwindigkeitsregler_P.Constant3_Value_e;

    /* DiscreteIntegrator: '<S55>/Integrator' */
    Geschwindigkeitsregler_B.Integrator_i4 =
      Geschwindigkeitsregler_P.Integrator_gainval_n *
      Geschwindigkeitsregler_B.IOut_dm +
      Geschwindigkeitsregler_DW.Integrator_DSTATE_gl;

    /* Outputs for Atomic SubSystem: '<S1>/vr' */
    /* Switch: '<S14>/Switch' incorporates:
     *  Constant: '<Root>/direction'
     *  Constant: '<Root>/enable'
     *  Constant: '<S14>/Constant2'
     */
    if (Geschwindigkeitsregler_P.enable_Value >
        Geschwindigkeitsregler_P.Switch_Threshold_n) {
      tmp = Geschwindigkeitsregler_P.direction_Value;
    } else {
      tmp = Geschwindigkeitsregler_P.Constant2_Value_j;
    }

    /* End of Switch: '<S14>/Switch' */

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
    MW_digitalWrite(Geschwindigkeitsregler_P.DigitalOutput_pinNumber_n, tmp_0);

    /* Switch: '<S14>/Switch1' incorporates:
     *  Constant: '<Root>/enable'
     *  Constant: '<S14>/Constant3'
     *  DataTypeConversion: '<S22>/Data Type Conversion'
     */
    if (Geschwindigkeitsregler_P.enable_Value >
        Geschwindigkeitsregler_P.Switch1_Threshold_k) {
      /* Sum: '<S55>/Sum' incorporates:
       *  Constant: '<S10>/Constant2'
       *  Product: '<S55>/POut'
       */
      rtb_Sum = rtb_Sum * Geschwindigkeitsregler_P.Constant2_Value_i +
        Geschwindigkeitsregler_B.Integrator_i4;

      /* Saturate: '<S55>/Saturate' */
      if (rtb_Sum > Geschwindigkeitsregler_P.DiscretePIDController_UpperSa_l) {
        /* DataTypeConversion: '<S22>/Data Type Conversion' */
        rtb_Sum = Geschwindigkeitsregler_P.DiscretePIDController_UpperSa_l;
      } else {
        if (rtb_Sum < Geschwindigkeitsregler_P.DiscretePIDController_LowerSa_e)
        {
          /* DataTypeConversion: '<S22>/Data Type Conversion' */
          rtb_Sum = Geschwindigkeitsregler_P.DiscretePIDController_LowerSa_e;
        }
      }

      /* End of Saturate: '<S55>/Saturate' */

      /* DataTypeConversion: '<S22>/Data Type Conversion' */
      if (rtb_Sum < 256.0) {
        if (rtb_Sum >= 0.0) {
          Geschwindigkeitsregler_B.DataTypeConversion = (uint8_T)rtb_Sum;
        } else {
          Geschwindigkeitsregler_B.DataTypeConversion = 0U;
        }
      } else {
        Geschwindigkeitsregler_B.DataTypeConversion = MAX_uint8_T;
      }
    } else if (Geschwindigkeitsregler_P.Constant3_Value_k < 256.0) {
      /* DataTypeConversion: '<S22>/Data Type Conversion' incorporates:
       *  Constant: '<S14>/Constant3'
       */
      if (Geschwindigkeitsregler_P.Constant3_Value_k >= 0.0) {
        Geschwindigkeitsregler_B.DataTypeConversion = (uint8_T)
          Geschwindigkeitsregler_P.Constant3_Value_k;
      } else {
        Geschwindigkeitsregler_B.DataTypeConversion = 0U;
      }
    } else {
      /* DataTypeConversion: '<S22>/Data Type Conversion' */
      Geschwindigkeitsregler_B.DataTypeConversion = MAX_uint8_T;
    }

    /* End of Switch: '<S14>/Switch1' */

    /* S-Function (arduinoanalogoutput_sfcn): '<S22>/PWM' */
    MW_analogWrite(Geschwindigkeitsregler_P.PWM_pinNumber_g,
                   Geschwindigkeitsregler_B.DataTypeConversion);

    /* End of Outputs for SubSystem: '<S1>/vr' */

    /* S-Function (arduinodigitalinput_sfcn): '<S23>/HL' */
    rtb_HL_0 = MW_digitalRead(Geschwindigkeitsregler_P.HL_p1);

    /* RelationalOperator: '<S36>/Compare' incorporates:
     *  Constant: '<S36>/Constant'
     *  S-Function (arduinodigitalinput_sfcn): '<S23>/HL'
     */
    rtb_Compare = ((int16_T)rtb_HL_0 > (int16_T)
                   Geschwindigkeitsregler_P.Constant_Value_k);

    /* RelationalOperator: '<S28>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S28>/Delay Input1'
     */
    rtb_FixPtRelationalOperator = ((int16_T)rtb_Compare > (int16_T)
      Geschwindigkeitsregler_DW.DelayInput1_DSTATE);

    /* S-Function (arduinodigitalinput_sfcn): '<S23>/HR' */
    rtb_HL_0 = MW_digitalRead(Geschwindigkeitsregler_P.HR_p1);

    /* RelationalOperator: '<S37>/Compare' incorporates:
     *  Constant: '<S37>/Constant'
     *  S-Function (arduinodigitalinput_sfcn): '<S23>/HR'
     */
    rtb_Compare_c = ((int16_T)rtb_HL_0 > (int16_T)
                     Geschwindigkeitsregler_P.Constant_Value_fr);

    /* RelationalOperator: '<S29>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S29>/Delay Input1'
     */
    rtb_FixPtRelationalOperator_k = ((int16_T)rtb_Compare_c > (int16_T)
      Geschwindigkeitsregler_DW.DelayInput1_DSTATE_c);

    /* S-Function (arduinodigitalinput_sfcn): '<S23>/VR' */
    rtb_HL_0 = MW_digitalRead(Geschwindigkeitsregler_P.VR_p1);

    /* RelationalOperator: '<S38>/Compare' incorporates:
     *  Constant: '<S38>/Constant'
     *  S-Function (arduinodigitalinput_sfcn): '<S23>/VR'
     */
    rtb_Compare_f = ((int16_T)rtb_HL_0 > (int16_T)
                     Geschwindigkeitsregler_P.Constant_Value_od);

    /* RelationalOperator: '<S30>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S30>/Delay Input1'
     */
    rtb_FixPtRelationalOperator_d = ((int16_T)rtb_Compare_f > (int16_T)
      Geschwindigkeitsregler_DW.DelayInput1_DSTATE_o);

    /* S-Function (arduinodigitalinput_sfcn): '<S23>/VL' */
    rtb_HL_0 = MW_digitalRead(Geschwindigkeitsregler_P.VL_p1);

    /* RelationalOperator: '<S39>/Compare' incorporates:
     *  Constant: '<S39>/Constant'
     *  S-Function (arduinodigitalinput_sfcn): '<S23>/VL'
     */
    rtb_Compare_p = ((int16_T)rtb_HL_0 > (int16_T)
                     Geschwindigkeitsregler_P.Constant_Value_fp);

    /* RelationalOperator: '<S31>/FixPt Relational Operator' incorporates:
     *  UnitDelay: '<S31>/Delay Input1'
     */
    rtb_FixPtRelationalOperator_c = ((int16_T)rtb_Compare_p > (int16_T)
      Geschwindigkeitsregler_DW.DelayInput1_DSTATE_ol);

    /* Outputs for Triggered SubSystem: '<S23>/Subsystem' */

    /* Constant: '<S23>/Constant' */
    Geschwindigkeitsregle_Subsystem(rtb_FixPtRelationalOperator_k,
      Geschwindigkeitsregler_P.Constant_Value_j,
      &Geschwindigkeitsregler_B.Subsystem, &Geschwindigkeitsregler_DW.Subsystem,
      (P_Subsystem_Geschwindigkeitsr_T *)&Geschwindigkeitsregler_P.Subsystem,
      &Geschwindigkeitsregler_PrevZCX.Subsystem);

    /* End of Outputs for SubSystem: '<S23>/Subsystem' */

    /* Outputs for Triggered SubSystem: '<S23>/Subsystem1' */
    Geschwindigkeitsregle_Subsystem(rtb_FixPtRelationalOperator_d,
      Geschwindigkeitsregler_P.Constant_Value_j,
      &Geschwindigkeitsregler_B.Subsystem1,
      &Geschwindigkeitsregler_DW.Subsystem1, (P_Subsystem_Geschwindigkeitsr_T *)
      &Geschwindigkeitsregler_P.Subsystem1,
      &Geschwindigkeitsregler_PrevZCX.Subsystem1);

    /* End of Outputs for SubSystem: '<S23>/Subsystem1' */

    /* Outputs for Triggered SubSystem: '<S23>/Subsystem2' */
    Geschwindigkeitsregle_Subsystem(rtb_FixPtRelationalOperator_c,
      Geschwindigkeitsregler_P.Constant_Value_j,
      &Geschwindigkeitsregler_B.Subsystem2,
      &Geschwindigkeitsregler_DW.Subsystem2, (P_Subsystem_Geschwindigkeitsr_T *)
      &Geschwindigkeitsregler_P.Subsystem2,
      &Geschwindigkeitsregler_PrevZCX.Subsystem2);

    /* End of Outputs for SubSystem: '<S23>/Subsystem2' */

    /* Outputs for Triggered SubSystem: '<S23>/Subsystem3' */
    Geschwindigkeitsregle_Subsystem(rtb_FixPtRelationalOperator,
      Geschwindigkeitsregler_P.Constant_Value_j,
      &Geschwindigkeitsregler_B.Subsystem3,
      &Geschwindigkeitsregler_DW.Subsystem3, (P_Subsystem_Geschwindigkeitsr_T *)
      &Geschwindigkeitsregler_P.Subsystem3,
      &Geschwindigkeitsregler_PrevZCX.Subsystem3);

    /* End of Outputs for SubSystem: '<S23>/Subsystem3' */

    /* DiscreteStateSpace: '<S24>/r+1 Altwerte' */
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

    /* DiscreteStateSpace: '<S25>/r+1 Altwerte' */
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

    /* DiscreteStateSpace: '<S26>/r+1 Altwerte' */
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

    /* DiscreteStateSpace: '<S27>/r+1 Altwerte' */
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
  }

  {
    int_T i;
    real_T xnew[3];
    real_T xnew_0[3];
    real_T xnew_1;

    /* Update for DiscreteStateSpace: '<S24>/Zustandsvariablenfilter' */
    for (i = 0; i < 3; i++) {
      xnew_1 = Geschwindigkeitsregler_P.BD[i] *
        Geschwindigkeitsregler_B.r1Altwerte[0] + (Geschwindigkeitsregler_P.AD[i
        + 6] * Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTATE[2] +
        (Geschwindigkeitsregler_P.AD[i + 3] *
         Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTATE[1] +
         Geschwindigkeitsregler_P.AD[i] *
         Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTATE[0]));
      xnew_1 += Geschwindigkeitsregler_P.BD[i + 3] *
        Geschwindigkeitsregler_B.r1Altwerte[1];
      xnew_1 += Geschwindigkeitsregler_P.BD[i + 6] *
        Geschwindigkeitsregler_B.r1Altwerte[2];
      xnew_1 += Geschwindigkeitsregler_P.BD[i + 9] *
        Geschwindigkeitsregler_B.r1Altwerte[3];
      xnew[i] = xnew_1;
    }

    /* Update for DiscreteIntegrator: '<S52>/Integrator' */
    Geschwindigkeitsregler_DW.Integrator_DSTATE =
      Geschwindigkeitsregler_B.Integrator;
    for (i = 0; i < 3; i++) {
      /* Update for DiscreteStateSpace: '<S24>/Zustandsvariablenfilter' */
      Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTATE[i] = xnew[i];

      /* Update for DiscreteStateSpace: '<S25>/Zustandsvariablenfilter' */
      xnew_1 = Geschwindigkeitsregler_P.BD[i] *
        Geschwindigkeitsregler_B.r1Altwerte_n[0] +
        (Geschwindigkeitsregler_P.AD[i + 6] *
         Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_n[2] +
         (Geschwindigkeitsregler_P.AD[i + 3] *
          Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_n[1] +
          Geschwindigkeitsregler_P.AD[i] *
          Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_n[0]));
      xnew_1 += Geschwindigkeitsregler_P.BD[i + 3] *
        Geschwindigkeitsregler_B.r1Altwerte_n[1];
      xnew_1 += Geschwindigkeitsregler_P.BD[i + 6] *
        Geschwindigkeitsregler_B.r1Altwerte_n[2];
      xnew_1 += Geschwindigkeitsregler_P.BD[i + 9] *
        Geschwindigkeitsregler_B.r1Altwerte_n[3];
      xnew_0[i] = xnew_1;
    }

    /* Update for DiscreteIntegrator: '<S53>/Integrator' */
    Geschwindigkeitsregler_DW.Integrator_DSTATE_g =
      Geschwindigkeitsregler_B.Integrator_n;
    for (i = 0; i < 3; i++) {
      /* Update for DiscreteStateSpace: '<S25>/Zustandsvariablenfilter' */
      Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_n[i] = xnew_0[i];

      /* Update for DiscreteStateSpace: '<S26>/Zustandsvariablenfilter' */
      xnew_1 = Geschwindigkeitsregler_P.BD[i] *
        Geschwindigkeitsregler_B.r1Altwerte_o[0] +
        (Geschwindigkeitsregler_P.AD[i + 6] *
         Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_o[2] +
         (Geschwindigkeitsregler_P.AD[i + 3] *
          Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_o[1] +
          Geschwindigkeitsregler_P.AD[i] *
          Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_o[0]));
      xnew_1 += Geschwindigkeitsregler_P.BD[i + 3] *
        Geschwindigkeitsregler_B.r1Altwerte_o[1];
      xnew_1 += Geschwindigkeitsregler_P.BD[i + 6] *
        Geschwindigkeitsregler_B.r1Altwerte_o[2];
      xnew_1 += Geschwindigkeitsregler_P.BD[i + 9] *
        Geschwindigkeitsregler_B.r1Altwerte_o[3];
      xnew[i] = xnew_1;
    }

    /* Update for DiscreteIntegrator: '<S54>/Integrator' */
    Geschwindigkeitsregler_DW.Integrator_DSTATE_k =
      Geschwindigkeitsregler_B.Integrator_i;
    for (i = 0; i < 3; i++) {
      /* Update for DiscreteStateSpace: '<S26>/Zustandsvariablenfilter' */
      Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_o[i] = xnew[i];

      /* Update for DiscreteStateSpace: '<S27>/Zustandsvariablenfilter' */
      xnew_1 = Geschwindigkeitsregler_P.BD[i] *
        Geschwindigkeitsregler_B.r1Altwerte_h[0] +
        (Geschwindigkeitsregler_P.AD[i + 6] *
         Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_c[2] +
         (Geschwindigkeitsregler_P.AD[i + 3] *
          Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_c[1] +
          Geschwindigkeitsregler_P.AD[i] *
          Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_c[0]));
      xnew_1 += Geschwindigkeitsregler_P.BD[i + 3] *
        Geschwindigkeitsregler_B.r1Altwerte_h[1];
      xnew_1 += Geschwindigkeitsregler_P.BD[i + 6] *
        Geschwindigkeitsregler_B.r1Altwerte_h[2];
      xnew_1 += Geschwindigkeitsregler_P.BD[i + 9] *
        Geschwindigkeitsregler_B.r1Altwerte_h[3];
      xnew_0[i] = xnew_1;
    }

    /* Update for DiscreteStateSpace: '<S27>/Zustandsvariablenfilter' */
    Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_c[0] = xnew_0[0];
    Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_c[1] = xnew_0[1];
    Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_c[2] = xnew_0[2];

    /* Update for DiscreteIntegrator: '<S55>/Integrator' */
    Geschwindigkeitsregler_DW.Integrator_DSTATE_gl =
      Geschwindigkeitsregler_B.Integrator_i4;

    /* Update for UnitDelay: '<S28>/Delay Input1' */
    Geschwindigkeitsregler_DW.DelayInput1_DSTATE = rtb_Compare;

    /* Update for UnitDelay: '<S29>/Delay Input1' */
    Geschwindigkeitsregler_DW.DelayInput1_DSTATE_c = rtb_Compare_c;

    /* Update for UnitDelay: '<S30>/Delay Input1' */
    Geschwindigkeitsregler_DW.DelayInput1_DSTATE_o = rtb_Compare_f;

    /* Update for UnitDelay: '<S31>/Delay Input1' */
    Geschwindigkeitsregler_DW.DelayInput1_DSTATE_ol = rtb_Compare_p;

    /* Update for DiscreteStateSpace: '<S24>/r+1 Altwerte' */
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

    /* Update for DiscreteStateSpace: '<S25>/r+1 Altwerte' */
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

    /* Update for DiscreteStateSpace: '<S26>/r+1 Altwerte' */
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

    /* Update for DiscreteStateSpace: '<S27>/r+1 Altwerte' */
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
  rtmSetTFinal(Geschwindigkeitsregler_M, 9.0);
  Geschwindigkeitsregler_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Geschwindigkeitsregler_M->Sizes.checksums[0] = (1877328200U);
  Geschwindigkeitsregler_M->Sizes.checksums[1] = (874492353U);
  Geschwindigkeitsregler_M->Sizes.checksums[2] = (2356479961U);
  Geschwindigkeitsregler_M->Sizes.checksums[3] = (4197152515U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[17];
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
      &Geschwindigkeitsregler_DW.Subsystem1.Subsystem_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &Geschwindigkeitsregler_DW.Subsystem1.Subsystem_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &Geschwindigkeitsregler_DW.Subsystem2.Subsystem_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &Geschwindigkeitsregler_DW.Subsystem2.Subsystem_SubsysRanBC;
    systemRan[15] = (sysRanDType *)
      &Geschwindigkeitsregler_DW.Subsystem3.Subsystem_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &Geschwindigkeitsregler_DW.Subsystem3.Subsystem_SubsysRanBC;
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

    static real_T pDataValues0[] = { -0.0, 0.0, 0.0, 50.0, 49.0, 49.0, 49.0,
      100.0, 98.5, 0.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0,
      100.0, 100.0 } ;

    Geschwindigkeitsregler_DW.FromWs_PWORK.TimePtr = (void *) pTimeValues0;
    Geschwindigkeitsregler_DW.FromWs_PWORK.DataPtr = (void *) pDataValues0;
    Geschwindigkeitsregler_DW.FromWs_IWORK.PrevIndex = 0;
  }

  /* Start for Atomic SubSystem: '<S1>/hl' */
  Geschwindigkeitsregler_hl_Start((P_hl_Geschwindigkeitsregler_T *)
    &Geschwindigkeitsregler_P.hl);

  /* End of Start for SubSystem: '<S1>/hl' */

  /* Start for Atomic SubSystem: '<S1>/hr' */
  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S17>/Digital Output' */
  MW_pinModeOutput(Geschwindigkeitsregler_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S18>/PWM' */
  MW_pinModeOutput(Geschwindigkeitsregler_P.PWM_pinNumber);

  /* End of Start for SubSystem: '<S1>/hr' */

  /* Start for Atomic SubSystem: '<S1>/vl' */
  Geschwindigkeitsregler_hl_Start((P_hl_Geschwindigkeitsregler_T *)
    &Geschwindigkeitsregler_P.vl);

  /* End of Start for SubSystem: '<S1>/vl' */

  /* Start for Atomic SubSystem: '<S1>/vr' */
  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S21>/Digital Output' */
  MW_pinModeOutput(Geschwindigkeitsregler_P.DigitalOutput_pinNumber_n);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S22>/PWM' */
  MW_pinModeOutput(Geschwindigkeitsregler_P.PWM_pinNumber_g);

  /* End of Start for SubSystem: '<S1>/vr' */

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S23>/HL' */
  MW_pinModeInput(Geschwindigkeitsregler_P.HL_p1);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S23>/HR' */
  MW_pinModeInput(Geschwindigkeitsregler_P.HR_p1);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S23>/VR' */
  MW_pinModeInput(Geschwindigkeitsregler_P.VR_p1);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<S23>/VL' */
  MW_pinModeInput(Geschwindigkeitsregler_P.VL_p1);

  /* Start for Triggered SubSystem: '<S23>/Subsystem' */
  Geschwindigkeit_Subsystem_Start(&Geschwindigkeitsregler_B.Subsystem,
    (P_Subsystem_Geschwindigkeitsr_T *)&Geschwindigkeitsregler_P.Subsystem);

  /* End of Start for SubSystem: '<S23>/Subsystem' */

  /* Start for Triggered SubSystem: '<S23>/Subsystem1' */
  Geschwindigkeit_Subsystem_Start(&Geschwindigkeitsregler_B.Subsystem1,
    (P_Subsystem_Geschwindigkeitsr_T *)&Geschwindigkeitsregler_P.Subsystem1);

  /* End of Start for SubSystem: '<S23>/Subsystem1' */

  /* Start for Triggered SubSystem: '<S23>/Subsystem2' */
  Geschwindigkeit_Subsystem_Start(&Geschwindigkeitsregler_B.Subsystem2,
    (P_Subsystem_Geschwindigkeitsr_T *)&Geschwindigkeitsregler_P.Subsystem2);

  /* End of Start for SubSystem: '<S23>/Subsystem2' */

  /* Start for Triggered SubSystem: '<S23>/Subsystem3' */
  Geschwindigkeit_Subsystem_Start(&Geschwindigkeitsregler_B.Subsystem3,
    (P_Subsystem_Geschwindigkeitsr_T *)&Geschwindigkeitsregler_P.Subsystem3);

  /* End of Start for SubSystem: '<S23>/Subsystem3' */
  Geschwindigkeitsregler_PrevZCX.Subsystem3.Subsystem_Trig_ZCE = POS_ZCSIG;
  Geschwindigkeitsregler_PrevZCX.Subsystem2.Subsystem_Trig_ZCE = POS_ZCSIG;
  Geschwindigkeitsregler_PrevZCX.Subsystem1.Subsystem_Trig_ZCE = POS_ZCSIG;
  Geschwindigkeitsregler_PrevZCX.Subsystem.Subsystem_Trig_ZCE = POS_ZCSIG;

  /* InitializeConditions for DiscreteIntegrator: '<S52>/Integrator' */
  Geschwindigkeitsregler_DW.Integrator_DSTATE =
    Geschwindigkeitsregler_P.Integrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S53>/Integrator' */
  Geschwindigkeitsregler_DW.Integrator_DSTATE_g =
    Geschwindigkeitsregler_P.Integrator_IC_f;

  /* InitializeConditions for DiscreteIntegrator: '<S54>/Integrator' */
  Geschwindigkeitsregler_DW.Integrator_DSTATE_k =
    Geschwindigkeitsregler_P.Integrator_IC_n;

  /* InitializeConditions for DiscreteStateSpace: '<S24>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTATE[0] =
    Geschwindigkeitsregler_P.AB2[0];

  /* InitializeConditions for DiscreteStateSpace: '<S25>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_n[0] =
    Geschwindigkeitsregler_P.AB2[0];

  /* InitializeConditions for DiscreteStateSpace: '<S26>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_o[0] =
    Geschwindigkeitsregler_P.AB2[0];

  /* InitializeConditions for DiscreteStateSpace: '<S27>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_c[0] =
    Geschwindigkeitsregler_P.AB2[0];

  /* InitializeConditions for DiscreteStateSpace: '<S24>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTATE[1] =
    Geschwindigkeitsregler_P.AB2[1];

  /* InitializeConditions for DiscreteStateSpace: '<S25>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_n[1] =
    Geschwindigkeitsregler_P.AB2[1];

  /* InitializeConditions for DiscreteStateSpace: '<S26>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_o[1] =
    Geschwindigkeitsregler_P.AB2[1];

  /* InitializeConditions for DiscreteStateSpace: '<S27>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_c[1] =
    Geschwindigkeitsregler_P.AB2[1];

  /* InitializeConditions for DiscreteStateSpace: '<S24>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTATE[2] =
    Geschwindigkeitsregler_P.AB2[2];

  /* InitializeConditions for DiscreteStateSpace: '<S25>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_n[2] =
    Geschwindigkeitsregler_P.AB2[2];

  /* InitializeConditions for DiscreteStateSpace: '<S26>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_o[2] =
    Geschwindigkeitsregler_P.AB2[2];

  /* InitializeConditions for DiscreteStateSpace: '<S27>/Zustandsvariablenfilter' */
  Geschwindigkeitsregler_DW.Zustandsvariablenfilter_DSTAT_c[2] =
    Geschwindigkeitsregler_P.AB2[2];

  /* InitializeConditions for DiscreteIntegrator: '<S55>/Integrator' */
  Geschwindigkeitsregler_DW.Integrator_DSTATE_gl =
    Geschwindigkeitsregler_P.Integrator_IC_i;

  /* InitializeConditions for UnitDelay: '<S28>/Delay Input1' */
  Geschwindigkeitsregler_DW.DelayInput1_DSTATE =
    Geschwindigkeitsregler_P.DetectRisePositive_vinit;

  /* InitializeConditions for UnitDelay: '<S29>/Delay Input1' */
  Geschwindigkeitsregler_DW.DelayInput1_DSTATE_c =
    Geschwindigkeitsregler_P.DetectRisePositive1_vinit;

  /* InitializeConditions for UnitDelay: '<S30>/Delay Input1' */
  Geschwindigkeitsregler_DW.DelayInput1_DSTATE_o =
    Geschwindigkeitsregler_P.DetectRisePositive2_vinit;

  /* InitializeConditions for UnitDelay: '<S31>/Delay Input1' */
  Geschwindigkeitsregler_DW.DelayInput1_DSTATE_ol =
    Geschwindigkeitsregler_P.DetectRisePositive3_vinit;

  /* InitializeConditions for Triggered SubSystem: '<S23>/Subsystem' */
  Geschwindigkeits_Subsystem_Init(&Geschwindigkeitsregler_DW.Subsystem,
    (P_Subsystem_Geschwindigkeitsr_T *)&Geschwindigkeitsregler_P.Subsystem);

  /* End of InitializeConditions for SubSystem: '<S23>/Subsystem' */

  /* InitializeConditions for Triggered SubSystem: '<S23>/Subsystem1' */
  Geschwindigkeits_Subsystem_Init(&Geschwindigkeitsregler_DW.Subsystem1,
    (P_Subsystem_Geschwindigkeitsr_T *)&Geschwindigkeitsregler_P.Subsystem1);

  /* End of InitializeConditions for SubSystem: '<S23>/Subsystem1' */

  /* InitializeConditions for Triggered SubSystem: '<S23>/Subsystem2' */
  Geschwindigkeits_Subsystem_Init(&Geschwindigkeitsregler_DW.Subsystem2,
    (P_Subsystem_Geschwindigkeitsr_T *)&Geschwindigkeitsregler_P.Subsystem2);

  /* End of InitializeConditions for SubSystem: '<S23>/Subsystem2' */

  /* InitializeConditions for Triggered SubSystem: '<S23>/Subsystem3' */
  Geschwindigkeits_Subsystem_Init(&Geschwindigkeitsregler_DW.Subsystem3,
    (P_Subsystem_Geschwindigkeitsr_T *)&Geschwindigkeitsregler_P.Subsystem3);

  /* End of InitializeConditions for SubSystem: '<S23>/Subsystem3' */

  /* InitializeConditions for DiscreteStateSpace: '<S24>/r+1 Altwerte' */
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[0] = Geschwindigkeitsregler_P.AB1
    [0];
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[1] = Geschwindigkeitsregler_P.AB1
    [1];
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[2] = Geschwindigkeitsregler_P.AB1
    [2];
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE[3] = Geschwindigkeitsregler_P.AB1
    [3];

  /* InitializeConditions for DiscreteStateSpace: '<S25>/r+1 Altwerte' */
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[0] =
    Geschwindigkeitsregler_P.AB1[0];
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[1] =
    Geschwindigkeitsregler_P.AB1[1];
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[2] =
    Geschwindigkeitsregler_P.AB1[2];
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_o[3] =
    Geschwindigkeitsregler_P.AB1[3];

  /* InitializeConditions for DiscreteStateSpace: '<S26>/r+1 Altwerte' */
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[0] =
    Geschwindigkeitsregler_P.AB1[0];
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[1] =
    Geschwindigkeitsregler_P.AB1[1];
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[2] =
    Geschwindigkeitsregler_P.AB1[2];
  Geschwindigkeitsregler_DW.r1Altwerte_DSTATE_a[3] =
    Geschwindigkeitsregler_P.AB1[3];

  /* InitializeConditions for DiscreteStateSpace: '<S27>/r+1 Altwerte' */
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
