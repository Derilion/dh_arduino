/* Copyright 2011-2012 The MathWorks, Inc. */

#ifndef ARDUINO_DIGITALINPUT_LCT_H
#define ARDUINO_DIGITALINPUT_LCT_H

#if defined(_RUNONTARGETHARDWARE_BUILD_)

/* This will be called by the target compiler */

#include "io_wrappers.h"
#include "arduino_blocks_abstraction.h"

#else

/* This will be compiled by MATLAB to create the Simulink block */
/* and for rapid accelerator mode as well */

/* Model Start function*/
#define MW_pinModeInput(pinNumber) (0)

/* Model Step function*/
#define MW_digitalRead(pinNumber) (0)

#endif

#endif /*arduino_digitalinput_lct.h*/
