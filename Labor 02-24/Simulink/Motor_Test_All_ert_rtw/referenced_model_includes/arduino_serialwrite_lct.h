/* Copyright 2011-2012 The MathWorks, Inc. */

#ifndef ARDUINO_SERIALWRITE_LCT_H
#define ARDUINO_SERIALWRITE_LCT_H

#if defined(_RUNONTARGETHARDWARE_BUILD_)

/* This will be called by the target compiler */

#include "io_wrappers.h"
#include "arduino_blocks_abstraction.h"

#else

/* This will be compiled by MATLAB to create the Simulink block */
/* and for rapid accelerator mode as well */

/* Model Step function*/
#define Serial_write(portNumber,inData,size) (0)

#endif

#endif /*arduino_serialwrite_lct.h*/
 
