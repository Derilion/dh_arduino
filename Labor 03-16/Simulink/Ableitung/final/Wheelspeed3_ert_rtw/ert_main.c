/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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
#include "rtwtypes.h"
#include <ext_work.h>
#include <ext_svr.h>
#include <ext_share.h>
#include <updown.h>

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

  sei();
  Wheelspeed3_step();

  /* Get model outputs here */
  cli();
  OverrunFlag--;
  rtExtModeCheckEndTrigger();
}

int main(void)
{
  volatile boolean_T runModel = 1;
  float modelBaseRate = 0.01;
  float systemClock = 0;
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(Wheelspeed3_M, 0);

  /* initialize external mode */
  rtParseArgsForExtMode(0, NULL);
  Wheelspeed3_initialize();
  sei();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(Wheelspeed3_M));
  rtExtModeCheckInit(2);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(Wheelspeed3_M->extModeInfo, 2, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(Wheelspeed3_M, true);
    }
  }

  rtERTExtModeStartMsg();
  cli();
  configureArduinoAVRTimer();
  runModel =
    (rtmGetErrorStatus(Wheelspeed3_M) == (NULL)) && !rtmGetStopRequested
    (Wheelspeed3_M);
  sei();
  sei();
  while (runModel) {
    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(Wheelspeed3_M->extModeInfo, 2, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(Wheelspeed3_M, true);
      }
    }

    runModel =
      (rtmGetErrorStatus(Wheelspeed3_M) == (NULL)) && !rtmGetStopRequested
      (Wheelspeed3_M);
  }

  rtExtModeShutdown(2);

  /* Disable rt_OneStep() here */

  /* Terminate model */
  Wheelspeed3_terminate();
  cli();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
