/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Motor_Test_All.c
 *
 * Code generated for Simulink model 'Motor_Test_All'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 02 15:57:22 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Motor_Test_All.h"
#include "Motor_Test_All_private.h"
#include "Motor_Test_All_dt.h"

/* Block states (auto storage) */
DW_Motor_Test_All_T Motor_Test_All_DW;

/* Real-time model */
RT_MODEL_Motor_Test_All_T Motor_Test_All_M_;
RT_MODEL_Motor_Test_All_T *const Motor_Test_All_M = &Motor_Test_All_M_;

/* Model step function */
void Motor_Test_All_step(void)
{
  /* local block i/o variables */
  real_T rtb_Output;
  uint8_T rtb_FixPtSum1;

  /* MultiPortSwitch: '<S1>/Output' incorporates:
   *  Constant: '<S1>/Vector'
   *  UnitDelay: '<S2>/Output'
   */
  rtb_Output =
    Motor_Test_All_P.RepeatingSequenceStair_OutValue[Motor_Test_All_DW.Output_DSTATE];

  /* ModelReference: '<Root>/Model' */
  motor_hl(&Motor_Test_All_P.enable_Value, &rtb_Output,
           &Motor_Test_All_P.enable_Value);

  /* ModelReference: '<Root>/Model1' */
  motor_vr(&Motor_Test_All_P.enable_Value, &rtb_Output,
           &Motor_Test_All_P.enable_Value);

  /* ModelReference: '<Root>/Model2' */
  motor_vl(&Motor_Test_All_P.enable_Value, &rtb_Output,
           &Motor_Test_All_P.enable_Value);

  /* ModelReference: '<Root>/Model3' */
  motor_hr(&Motor_Test_All_P.enable_Value, &rtb_Output,
           &Motor_Test_All_P.enable_Value);

  /* Sum: '<S3>/FixPt Sum1' incorporates:
   *  Constant: '<S3>/FixPt Constant'
   *  UnitDelay: '<S2>/Output'
   */
  rtb_FixPtSum1 = (uint8_T)((uint16_T)Motor_Test_All_DW.Output_DSTATE +
    Motor_Test_All_P.FixPtConstant_Value);

  /* Switch: '<S4>/FixPt Switch' */
  if (rtb_FixPtSum1 > Motor_Test_All_P.LimitedCounter_uplimit) {
    /* Update for UnitDelay: '<S2>/Output' incorporates:
     *  Constant: '<S4>/Constant'
     */
    Motor_Test_All_DW.Output_DSTATE = Motor_Test_All_P.Constant_Value;
  } else {
    /* Update for UnitDelay: '<S2>/Output' */
    Motor_Test_All_DW.Output_DSTATE = rtb_FixPtSum1;
  }

  /* End of Switch: '<S4>/FixPt Switch' */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [10.0s, 0.0s] */
    rtExtModeUpload(0, Motor_Test_All_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [10.0s, 0.0s] */
    if ((rtmGetTFinal(Motor_Test_All_M)!=-1) &&
        !((rtmGetTFinal(Motor_Test_All_M)-Motor_Test_All_M->Timing.taskTime0) >
          Motor_Test_All_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Motor_Test_All_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Motor_Test_All_M)) {
      rtmSetErrorStatus(Motor_Test_All_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Motor_Test_All_M->Timing.taskTime0 =
    (++Motor_Test_All_M->Timing.clockTick0) * Motor_Test_All_M->Timing.stepSize0;
}

/* Model initialize function */
void Motor_Test_All_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Motor_Test_All_M, 0,
                sizeof(RT_MODEL_Motor_Test_All_T));
  rtmSetTFinal(Motor_Test_All_M, 100.0);
  Motor_Test_All_M->Timing.stepSize0 = 10.0;

  /* External mode info */
  Motor_Test_All_M->Sizes.checksums[0] = (391574619U);
  Motor_Test_All_M->Sizes.checksums[1] = (1808842219U);
  Motor_Test_All_M->Sizes.checksums[2] = (99353943U);
  Motor_Test_All_M->Sizes.checksums[3] = (1218331709U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    Motor_Test_All_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Motor_Test_All_M->extModeInfo,
      &Motor_Test_All_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Motor_Test_All_M->extModeInfo,
                        Motor_Test_All_M->Sizes.checksums);
    rteiSetTPtr(Motor_Test_All_M->extModeInfo, rtmGetTPtr(Motor_Test_All_M));
  }

  /* states (dwork) */
  (void) memset((void *)&Motor_Test_All_DW, 0,
                sizeof(DW_Motor_Test_All_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Motor_Test_All_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 18;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Model Initialize fcn for ModelReference Block: '<Root>/Model' */
  motor_hl_initialize(rtmGetErrorStatusPointer(Motor_Test_All_M),
                      &(Motor_Test_All_DW.Model_DWORK1.rtm));

  /* Model Initialize fcn for ModelReference Block: '<Root>/Model1' */
  motor_vr_initialize(rtmGetErrorStatusPointer(Motor_Test_All_M),
                      &(Motor_Test_All_DW.Model1_DWORK1.rtm));

  /* Model Initialize fcn for ModelReference Block: '<Root>/Model2' */
  motor_vl_initialize(rtmGetErrorStatusPointer(Motor_Test_All_M),
                      &(Motor_Test_All_DW.Model2_DWORK1.rtm));

  /* Model Initialize fcn for ModelReference Block: '<Root>/Model3' */
  motor_hr_initialize(rtmGetErrorStatusPointer(Motor_Test_All_M),
                      &(Motor_Test_All_DW.Model3_DWORK1.rtm));

  /* Start for ModelReference: '<Root>/Model' */
  motor_hl_Start();

  /* Start for ModelReference: '<Root>/Model1' */
  motor_vr_Start();

  /* Start for ModelReference: '<Root>/Model2' */
  motor_vl_Start();

  /* Start for ModelReference: '<Root>/Model3' */
  motor_hr_Start();

  /* InitializeConditions for UnitDelay: '<S2>/Output' */
  Motor_Test_All_DW.Output_DSTATE = Motor_Test_All_P.Output_InitialCondition;
}

/* Model terminate function */
void Motor_Test_All_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
