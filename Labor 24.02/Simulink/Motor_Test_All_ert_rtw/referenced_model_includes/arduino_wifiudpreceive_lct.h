/* Copyright 2013 The MathWorks, Inc. */

#ifndef ARDUINO_WIFIUDPRECEIVE_LCT_H
#define ARDUINO_WIFIUDPRECEIVE_LCT_H

#if defined(_RUNONTARGETHARDWARE_BUILD_)

/* This will be called by the target compiler */

#include "io_wrappers.h"
#include "arduino_blocks_abstraction.h"

#else

/* This will be compiled by MATLAB to create the Simulink block */
/* and for rapid accelerator mode as well */

/* Model Start function*/
#define MW_WifiAndUDPBegin(wifiudpindex, localPort) (0)


/* Model Step function*/
#define MW_WifiUDPFinalRead(wifiudpindex, data, outStatus) (0)


#endif 

#endif /*arduino_wifiudpreceive_lct.h*/
 



