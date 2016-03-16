/* Copyright 2013 The MathWorks, Inc. */

#ifndef ARDUINO_WIFITCPRECEIVE_LCT_H
#define ARDUINO_WIFITCPRECEIVE_LCT_H

#if defined(_RUNONTARGETHARDWARE_BUILD_)

/* This will be called by the target compiler */

#include "io_wrappers.h"
#include "arduino_blocks_abstraction.h"

#else

/* This will be compiled by MATLAB to create the Simulink block */
/* and for rapid accelerator mode as well */

/* Model Start function*/
#define MW_WifiAndWifiTCPServerBegin(wifitcpindex, serverPort) (0)

/* Model Step function*/
#define MW_WifiTCPFinalread(wifitcpindex, data, serverport, outStatus) (0)

#endif 

#endif /*arduino_wifitcpreceive_lct.h*/
 



