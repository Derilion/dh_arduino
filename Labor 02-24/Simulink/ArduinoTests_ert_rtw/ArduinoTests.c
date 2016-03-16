/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ArduinoTests.c
 *
 * Code generated for Simulink model 'ArduinoTests'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Feb 24 17:40:41 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ArduinoTests.h"
#include "ArduinoTests_private.h"
#include "ArduinoTests_dt.h"

/* Block signals (auto storage) */
B_ArduinoTests_T ArduinoTests_B;

/* Block states (auto storage) */
DW_ArduinoTests_T ArduinoTests_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_ArduinoTests_T ArduinoTests_PrevZCX;

/* Real-time model */
RT_MODEL_ArduinoTests_T ArduinoTests_M_;
RT_MODEL_ArduinoTests_T *const ArduinoTests_M = &ArduinoTests_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void ArduinoTests_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(ArduinoTests_M, 1));
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
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (ArduinoTests_M->Timing.TaskCounters.TID[1])++;
  if ((ArduinoTests_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    ArduinoTests_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void ArduinoTests_step0(void)          /* Sample time: [0.01s, 0.0s] */
{
  real_T rtb_PulseGenerator;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_p;
  boolean_T rtb_Compare_a;
  boolean_T rtb_Compare_m;
  boolean_T rtb_BitwiseOperator;

  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(ArduinoTests_DW.Subsystem_SubsysRanBC);

  /* S-Function (arduinodigitalinput_sfcn): '<Root>/Digital Input' */
  ArduinoTests_B.DigitalInput = MW_digitalRead(ArduinoTests_P.DigitalInput_p1);

  /* S-Function (arduinodigitalinput_sfcn): '<Root>/Digital Input1' */
  ArduinoTests_B.DigitalInput1 = MW_digitalRead(ArduinoTests_P.DigitalInput1_p1);

  /* S-Function (arduinodigitalinput_sfcn): '<Root>/Digital Input2' */
  ArduinoTests_B.DigitalInput2 = MW_digitalRead(ArduinoTests_P.DigitalInput2_p1);

  /* S-Function (arduinodigitalinput_sfcn): '<Root>/Digital Input3' */
  ArduinoTests_B.DigitalInput3 = MW_digitalRead(ArduinoTests_P.DigitalInput3_p1);

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (ArduinoTests_DW.clockTickCounter <
                        ArduinoTests_P.PulseGenerator_Duty) &&
    (ArduinoTests_DW.clockTickCounter >= 0L) ? ArduinoTests_P.PulseGenerator_Amp
    : 0.0;
  if (ArduinoTests_DW.clockTickCounter >= ArduinoTests_P.PulseGenerator_Period -
      1.0) {
    ArduinoTests_DW.clockTickCounter = 0L;
  } else {
    ArduinoTests_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* RelationalOperator: '<S7>/Compare' incorporates:
   *  Constant: '<S7>/Constant'
   */
  rtb_Compare = ((int16_T)ArduinoTests_B.DigitalInput > (int16_T)
                 ArduinoTests_P.Constant_Value_l);

  /* RelationalOperator: '<S8>/Compare' incorporates:
   *  Constant: '<S8>/Constant'
   */
  rtb_Compare_p = ((int16_T)ArduinoTests_B.DigitalInput1 > (int16_T)
                   ArduinoTests_P.Constant_Value_b);

  /* RelationalOperator: '<S9>/Compare' incorporates:
   *  Constant: '<S9>/Constant'
   */
  rtb_Compare_a = ((int16_T)ArduinoTests_B.DigitalInput2 > (int16_T)
                   ArduinoTests_P.Constant_Value_p);

  /* RelationalOperator: '<S10>/Compare' incorporates:
   *  Constant: '<S10>/Constant'
   */
  rtb_Compare_m = ((int16_T)ArduinoTests_B.DigitalInput3 > (int16_T)
                   ArduinoTests_P.Constant_Value_m);

  /* S-Function (sfix_bitop): '<Root>/Bitwise Operator' incorporates:
   *  RelationalOperator: '<S1>/FixPt Relational Operator'
   *  RelationalOperator: '<S2>/FixPt Relational Operator'
   *  RelationalOperator: '<S3>/FixPt Relational Operator'
   *  RelationalOperator: '<S4>/FixPt Relational Operator'
   *  UnitDelay: '<S1>/Delay Input1'
   *  UnitDelay: '<S2>/Delay Input1'
   *  UnitDelay: '<S3>/Delay Input1'
   *  UnitDelay: '<S4>/Delay Input1'
   */
  rtb_BitwiseOperator = (((int16_T)rtb_Compare > (int16_T)
    ArduinoTests_DW.DelayInput1_DSTATE) || ((int16_T)rtb_Compare_p > (int16_T)
    ArduinoTests_DW.DelayInput1_DSTATE_e) || ((int16_T)rtb_Compare_a > (int16_T)
    ArduinoTests_DW.DelayInput1_DSTATE_h) || ((int16_T)rtb_Compare_m > (int16_T)
    ArduinoTests_DW.DelayInput1_DSTATE_k));

  /* Outputs for Triggered SubSystem: '<Root>/Subsystem' incorporates:
   *  TriggerPort: '<S6>/Trigger'
   */
  if (rtb_BitwiseOperator && (ArduinoTests_PrevZCX.Subsystem_Trig_ZCE !=
       POS_ZCSIG)) {
    /* Switch: '<S6>/Switch' incorporates:
     *  Constant: '<S6>/Constant1'
     *  Delay: '<S6>/Delay'
     */
    if (rtb_PulseGenerator > ArduinoTests_P.Switch_Threshold) {
      rtb_PulseGenerator = ArduinoTests_P.Constant1_Value;
    } else {
      rtb_PulseGenerator = ArduinoTests_DW.Delay_DSTATE;
    }

    /* End of Switch: '<S6>/Switch' */

    /* Sum: '<S6>/Add' incorporates:
     *  Constant: '<S6>/Constant'
     */
    ArduinoTests_B.Add = rtb_PulseGenerator + ArduinoTests_P.Constant_Value;

    /* Update for Delay: '<S6>/Delay' */
    ArduinoTests_DW.Delay_DSTATE = ArduinoTests_B.Add;
    ArduinoTests_DW.Subsystem_SubsysRanBC = 4;
  }

  ArduinoTests_PrevZCX.Subsystem_Trig_ZCE = rtb_BitwiseOperator;

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */

  /* Update for UnitDelay: '<S1>/Delay Input1' */
  ArduinoTests_DW.DelayInput1_DSTATE = rtb_Compare;

  /* Update for UnitDelay: '<S2>/Delay Input1' */
  ArduinoTests_DW.DelayInput1_DSTATE_e = rtb_Compare_p;

  /* Update for UnitDelay: '<S3>/Delay Input1' */
  ArduinoTests_DW.DelayInput1_DSTATE_h = rtb_Compare_a;

  /* Update for UnitDelay: '<S4>/Delay Input1' */
  ArduinoTests_DW.DelayInput1_DSTATE_k = rtb_Compare_m;

  /* External mode */
  rtExtModeUploadCheckTrigger(2);
  rtExtModeUpload(0, ArduinoTests_M->Timing.taskTime0);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(ArduinoTests_M)!=-1) &&
        !((rtmGetTFinal(ArduinoTests_M)-ArduinoTests_M->Timing.taskTime0) >
          ArduinoTests_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(ArduinoTests_M, "Simulation finished");
    }

    if (rtmGetStopRequested(ArduinoTests_M)) {
      rtmSetErrorStatus(ArduinoTests_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ArduinoTests_M->Timing.taskTime0 =
    (++ArduinoTests_M->Timing.clockTick0) * ArduinoTests_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void ArduinoTests_step1(void)          /* Sample time: [0.1s, 0.0s] */
{
  /* S-Function (arduinoanaloginput_sfcn): '<Root>/Analog Input' */
  ArduinoTests_B.AnalogInput = MW_analogRead(ArduinoTests_P.AnalogInput_p1);
  rtExtModeUpload(1, ((ArduinoTests_M->Timing.clockTick1) * 0.1));

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  ArduinoTests_M->Timing.clockTick1++;
}

/* Model initialize function */
void ArduinoTests_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)ArduinoTests_M, 0,
                sizeof(RT_MODEL_ArduinoTests_T));
  rtmSetTFinal(ArduinoTests_M, 100.0);
  ArduinoTests_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  ArduinoTests_M->Sizes.checksums[0] = (2486536749U);
  ArduinoTests_M->Sizes.checksums[1] = (2631617736U);
  ArduinoTests_M->Sizes.checksums[2] = (4155998414U);
  ArduinoTests_M->Sizes.checksums[3] = (3184614457U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    ArduinoTests_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&ArduinoTests_DW.Subsystem_SubsysRanBC;
    systemRan[2] = (sysRanDType *)&ArduinoTests_DW.Subsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(ArduinoTests_M->extModeInfo,
      &ArduinoTests_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ArduinoTests_M->extModeInfo,
                        ArduinoTests_M->Sizes.checksums);
    rteiSetTPtr(ArduinoTests_M->extModeInfo, rtmGetTPtr(ArduinoTests_M));
  }

  /* block I/O */
  (void) memset(((void *) &ArduinoTests_B), 0,
                sizeof(B_ArduinoTests_T));

  /* states (dwork) */
  (void) memset((void *)&ArduinoTests_DW, 0,
                sizeof(DW_ArduinoTests_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ArduinoTests_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (arduinoanaloginput_sfcn): '<Root>/Analog Input' */
  MW_pinModeAnalogInput(ArduinoTests_P.AnalogInput_p1);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<Root>/Digital Input' */
  MW_pinModeInput(ArduinoTests_P.DigitalInput_p1);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<Root>/Digital Input1' */
  MW_pinModeInput(ArduinoTests_P.DigitalInput1_p1);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<Root>/Digital Input2' */
  MW_pinModeInput(ArduinoTests_P.DigitalInput2_p1);

  /* Start for S-Function (arduinodigitalinput_sfcn): '<Root>/Digital Input3' */
  MW_pinModeInput(ArduinoTests_P.DigitalInput3_p1);

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  ArduinoTests_DW.clockTickCounter = 0L;

  /* Start for Triggered SubSystem: '<Root>/Subsystem' */
  /* VirtualOutportStart for Outport: '<S6>/Out1' */
  ArduinoTests_B.Add = ArduinoTests_P.Out1_Y0;

  /* End of Start for SubSystem: '<Root>/Subsystem' */
  ArduinoTests_PrevZCX.Subsystem_Trig_ZCE = POS_ZCSIG;

  /* InitializeConditions for UnitDelay: '<S1>/Delay Input1' */
  ArduinoTests_DW.DelayInput1_DSTATE = ArduinoTests_P.DetectRisePositive_vinit;

  /* InitializeConditions for UnitDelay: '<S2>/Delay Input1' */
  ArduinoTests_DW.DelayInput1_DSTATE_e =
    ArduinoTests_P.DetectRisePositive1_vinit;

  /* InitializeConditions for UnitDelay: '<S3>/Delay Input1' */
  ArduinoTests_DW.DelayInput1_DSTATE_h =
    ArduinoTests_P.DetectRisePositive2_vinit;

  /* InitializeConditions for UnitDelay: '<S4>/Delay Input1' */
  ArduinoTests_DW.DelayInput1_DSTATE_k =
    ArduinoTests_P.DetectRisePositive3_vinit;

  /* InitializeConditions for Triggered SubSystem: '<Root>/Subsystem' */
  /* InitializeConditions for Delay: '<S6>/Delay' */
  ArduinoTests_DW.Delay_DSTATE = ArduinoTests_P.Delay_InitialCondition;

  /* End of InitializeConditions for SubSystem: '<Root>/Subsystem' */
}

/* Model terminate function */
void ArduinoTests_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
