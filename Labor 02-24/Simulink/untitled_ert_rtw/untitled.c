/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 02 15:25:46 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "untitled_private.h"
#include "untitled_dt.h"

/* Block states (auto storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Model step function */
void untitled_step(void)
{
  /* local block i/o variables */
  real_T rtb_Output;
  uint8_T rtb_FixPtSum1;

  /* MultiPortSwitch: '<S1>/Output' incorporates:
   *  Constant: '<S1>/Vector'
   *  UnitDelay: '<S2>/Output'
   */
  rtb_Output =
    untitled_P.RepeatingSequenceStair_OutValue[untitled_DW.Output_DSTATE];

  /* ModelReference: '<Root>/Model' */
  motor_hl(&untitled_P.enable_Value, &rtb_Output, &untitled_P.enable_Value);

  /* ModelReference: '<Root>/Model1' */
  motor_vr(&untitled_P.enable_Value, &rtb_Output, &untitled_P.enable_Value);

  /* ModelReference: '<Root>/Model2' */
  motor_vl(&untitled_P.enable_Value, &rtb_Output, &untitled_P.enable_Value);

  /* ModelReference: '<Root>/Model3' */
  motor_hr(&untitled_P.enable_Value, &rtb_Output, &untitled_P.enable_Value);

  /* Sum: '<S3>/FixPt Sum1' incorporates:
   *  Constant: '<S3>/FixPt Constant'
   *  UnitDelay: '<S2>/Output'
   */
  rtb_FixPtSum1 = (uint8_T)((uint16_T)untitled_DW.Output_DSTATE +
    untitled_P.FixPtConstant_Value);

  /* Switch: '<S4>/FixPt Switch' */
  if (rtb_FixPtSum1 > untitled_P.LimitedCounter_uplimit) {
    /* Update for UnitDelay: '<S2>/Output' incorporates:
     *  Constant: '<S4>/Constant'
     */
    untitled_DW.Output_DSTATE = untitled_P.Constant_Value;
  } else {
    /* Update for UnitDelay: '<S2>/Output' */
    untitled_DW.Output_DSTATE = rtb_FixPtSum1;
  }

  /* End of Switch: '<S4>/FixPt Switch' */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [1.0s, 0.0s] */
    rtExtModeUpload(0, untitled_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [1.0s, 0.0s] */
    if ((rtmGetTFinal(untitled_M)!=-1) &&
        !((rtmGetTFinal(untitled_M)-untitled_M->Timing.taskTime0) >
          untitled_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(untitled_M, "Simulation finished");
    }

    if (rtmGetStopRequested(untitled_M)) {
      rtmSetErrorStatus(untitled_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled_M->Timing.taskTime0 =
    (++untitled_M->Timing.clockTick0) * untitled_M->Timing.stepSize0;
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)untitled_M, 0,
                sizeof(RT_MODEL_untitled_T));
  rtmSetTFinal(untitled_M, 10.0);
  untitled_M->Timing.stepSize0 = 1.0;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (161728124U);
  untitled_M->Sizes.checksums[1] = (589491741U);
  untitled_M->Sizes.checksums[2] = (2068084916U);
  untitled_M->Sizes.checksums[3] = (3520018775U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  /* states (dwork) */
  (void) memset((void *)&untitled_DW, 0,
                sizeof(DW_untitled_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    untitled_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 18;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Model Initialize fcn for ModelReference Block: '<Root>/Model' */
  motor_hl_initialize(rtmGetErrorStatusPointer(untitled_M),
                      &(untitled_DW.Model_DWORK1.rtm));

  /* Model Initialize fcn for ModelReference Block: '<Root>/Model1' */
  motor_vr_initialize(rtmGetErrorStatusPointer(untitled_M),
                      &(untitled_DW.Model1_DWORK1.rtm));

  /* Model Initialize fcn for ModelReference Block: '<Root>/Model2' */
  motor_vl_initialize(rtmGetErrorStatusPointer(untitled_M),
                      &(untitled_DW.Model2_DWORK1.rtm));

  /* Model Initialize fcn for ModelReference Block: '<Root>/Model3' */
  motor_hr_initialize(rtmGetErrorStatusPointer(untitled_M),
                      &(untitled_DW.Model3_DWORK1.rtm));

  /* Start for ModelReference: '<Root>/Model' */
  motor_hl_Start();

  /* Start for ModelReference: '<Root>/Model1' */
  motor_vr_Start();

  /* Start for ModelReference: '<Root>/Model2' */
  motor_vl_Start();

  /* Start for ModelReference: '<Root>/Model3' */
  motor_hr_Start();

  /* InitializeConditions for UnitDelay: '<S2>/Output' */
  untitled_DW.Output_DSTATE = untitled_P.Output_InitialCondition;
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
