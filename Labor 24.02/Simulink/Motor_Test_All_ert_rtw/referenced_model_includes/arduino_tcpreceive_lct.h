/* Copyright 2011-2013 The MathWorks, Inc. */

#ifndef ARDUINO_TCPRECEIVE_LCT_H
#define ARDUINO_TCPRECEIVE_LCT_H

#if defined(_RUNONTARGETHARDWARE_BUILD_)

/* This will be called by the target compiler */

#include "io_wrappers.h"
#include "arduino_blocks_abstraction.h"

#else

/* This will be compiled by MATLAB to create the Simulink block */
/* and for rapid accelerator mode as well */

/* Model Start function*/
#define MW_EthernetAndTCPServerBegin(tcpindex, serverport) (0)


/* Model Step function*/
#define MW_TCPFinalread(tcpindex, data, serverport, outStatus) (0)


#endif 

#endif /*arduino_tcpreceive_lct.h*/
 



