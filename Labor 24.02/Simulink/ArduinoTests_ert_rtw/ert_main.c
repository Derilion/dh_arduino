/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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
#include "rtwtypes.h"
#include <ext_work.h>
#include <ext_svr.h>
#include <ext_share.h>
#include <updown.h>

volatile int IsrOverrun = 0;
boolean_T isRateRunning[2] = { 0, 0 };

boolean_T need2runFlags[2] = { 0, 0 };

void rt_OneStep(void)
{
  boolean_T eventFlags[2];

  /* Check base rate for overrun */
  if (isRateRunning[0]++) {
    IsrOverrun = 1;
    isRateRunning[0]--;                /* allow future iterations to succeed*/
    return;
  }

  /*
   * For a bare-board target (i.e., no operating system), the rates
   * that execute this base step are buffered locally to allow for
   * overlapping preemption.  The generated code includes function
   * writeCodeInfoFcn() which sets the rates
   * that need to run this time step.  The return values are 1 and 0
   * for true and false, respectively.
   */
  ArduinoTests_SetEventsForThisBaseStep(eventFlags);
  sei();
  ArduinoTests_step0();

  /* Get model outputs here */
  cli();
  isRateRunning[0]--;
  if (eventFlags[1]) {
    if (need2runFlags[1]++) {
      IsrOverrun = 1;
      need2runFlags[1]--;              /* allow future iterations to succeed*/
      return;
    }
  }

  if (need2runFlags[1]) {
    if (isRateRunning[1]) {
      /* Yield to higher priority*/
      return;
    }

    isRateRunning[1]++;
    sei();

    /* Step the model for subrate "1" */
    switch (1)
    {
     case 1 :
      ArduinoTests_step1();

      /* Get model outputs here */
      break;

     default :
      break;
    }

    cli();
    need2runFlags[1]--;
    isRateRunning[1]--;
  }

  rtExtModeCheckEndTrigger();
}

int main(void)
{
  volatile boolean_T runModel = 1;
  float modelBaseRate = 0.01;
  float systemClock = 0;
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(ArduinoTests_M, 0);

  /* initialize external mode */
  rtParseArgsForExtMode(0, NULL);
  ArduinoTests_initialize();
  sei();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(ArduinoTests_M));
  rtExtModeCheckInit(2);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(ArduinoTests_M->extModeInfo, 2, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(ArduinoTests_M, true);
    }
  }

  rtERTExtModeStartMsg();
  cli();
  configureArduinoAVRTimer();
  runModel =
    (rtmGetErrorStatus(ArduinoTests_M) == (NULL)) && !rtmGetStopRequested
    (ArduinoTests_M);
  sei();
  sei();
  while (runModel) {
    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(ArduinoTests_M->extModeInfo, 2, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(ArduinoTests_M, true);
      }
    }

    runModel =
      (rtmGetErrorStatus(ArduinoTests_M) == (NULL)) && !rtmGetStopRequested
      (ArduinoTests_M);
  }

  rtExtModeShutdown(2);

  /* Disable rt_OneStep() here */

  /* Terminate model */
  ArduinoTests_terminate();
  cli();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
