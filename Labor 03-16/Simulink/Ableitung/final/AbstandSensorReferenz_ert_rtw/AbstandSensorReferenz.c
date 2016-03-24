/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: AbstandSensorReferenz.c
 *
 * Code generated for Simulink model 'AbstandSensorReferenz'.
 *
 * Model version                  : 1.29
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Wed Mar 23 17:12:14 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AbstandSensorReferenz.h"
#include "AbstandSensorReferenz_private.h"
#include "AbstandSensorReferenz_dt.h"

/* Block signals (auto storage) */
B_AbstandSensorReferenz_T AbstandSensorReferenz_B;

/* Block states (auto storage) */
DW_AbstandSensorReferenz_T AbstandSensorReferenz_DW;

/* Real-time model */
RT_MODEL_AbstandSensorReferen_T AbstandSensorReferenz_M_;
RT_MODEL_AbstandSensorReferen_T *const AbstandSensorReferenz_M =
  &AbstandSensorReferenz_M_;

/* Model step function */
void AbstandSensorReferenz_step(void)
{
  /* S-Function (arduinoanaloginput_sfcn): '<Root>/Abstandssensor' */
  AbstandSensorReferenz_B.Abstandssensor = MW_analogRead
    (AbstandSensorReferenz_P.Abstandssensor_p1);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.01s, 0.0s] */
    rtExtModeUpload(0, AbstandSensorReferenz_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(AbstandSensorReferenz_M)!=-1) &&
        !((rtmGetTFinal(AbstandSensorReferenz_M)-
           AbstandSensorReferenz_M->Timing.taskTime0) >
          AbstandSensorReferenz_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(AbstandSensorReferenz_M, "Simulation finished");
    }

    if (rtmGetStopRequested(AbstandSensorReferenz_M)) {
      rtmSetErrorStatus(AbstandSensorReferenz_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  AbstandSensorReferenz_M->Timing.taskTime0 =
    (++AbstandSensorReferenz_M->Timing.clockTick0) *
    AbstandSensorReferenz_M->Timing.stepSize0;
}

/* Model initialize function */
void AbstandSensorReferenz_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)AbstandSensorReferenz_M, 0,
                sizeof(RT_MODEL_AbstandSensorReferen_T));
  rtmSetTFinal(AbstandSensorReferenz_M, 100.0);
  AbstandSensorReferenz_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  AbstandSensorReferenz_M->Sizes.checksums[0] = (2067882258U);
  AbstandSensorReferenz_M->Sizes.checksums[1] = (3967935318U);
  AbstandSensorReferenz_M->Sizes.checksums[2] = (1872022517U);
  AbstandSensorReferenz_M->Sizes.checksums[3] = (1646939142U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    AbstandSensorReferenz_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(AbstandSensorReferenz_M->extModeInfo,
      &AbstandSensorReferenz_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(AbstandSensorReferenz_M->extModeInfo,
                        AbstandSensorReferenz_M->Sizes.checksums);
    rteiSetTPtr(AbstandSensorReferenz_M->extModeInfo, rtmGetTPtr
                (AbstandSensorReferenz_M));
  }

  /* block I/O */
  (void) memset(((void *) &AbstandSensorReferenz_B), 0,
                sizeof(B_AbstandSensorReferenz_T));

  /* states (dwork) */
  (void) memset((void *)&AbstandSensorReferenz_DW, 0,
                sizeof(DW_AbstandSensorReferenz_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    AbstandSensorReferenz_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (arduinoanaloginput_sfcn): '<Root>/Abstandssensor' */
  MW_pinModeAnalogInput(AbstandSensorReferenz_P.Abstandssensor_p1);
}

/* Model terminate function */
void AbstandSensorReferenz_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
