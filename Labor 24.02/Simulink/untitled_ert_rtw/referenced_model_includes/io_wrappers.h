/* 
 * Wrappers to make I/O functions available with C linkage. This allows C++
 * methods to be called from C code.
 *
 * Copyright 2011-2014 The MathWorks, Inc. */
#ifndef _IO_WRAPPERS_H_
#define _IO_WRAPPERS_H_
#include <inttypes.h>
#include <stdio.h> /* for size_t */

#ifdef __cplusplus
extern "C" {
#endif

void Serial_begin(int port, long r);
void Serial_read(int port, int showOutStatus, uint8_t *outData, int16_t *outStatus);
void Serial_write(int port, uint8_t * c, size_t s);
void MW_pinModeAnalogInput(uint32_t pinNumber);

#if _RTT_NUMSERVOS_ != 0 
void MW_servoAttach(uint8_t nServo, uint8_t pinNumber);
void MW_servoWrite(uint8_t nServo, uint8_t inValue);
int MW_servoRead(uint8_t nServo);
#endif  

#if _RTT_UDP_ != 0
uint8_t MW_EthernetAndUDPBeginMW_EthernetAndUDPBegin(uint8_t udpindex, uint32_t localPort);
int MW_UDPFinalWrite(uint8_t udpindex, uint8_t data,uint8_t remoteIPOctect1,uint8_t remoteIPOctect2,uint8_t remoteIPOctect3,uint8_t remoteIPOctect4, uint32_t remoteport);
void MW_UDPFinalRead(uint8_t udpindex, uint8_t *data,int *outStatus);
#endif

#if defined(_RTT_THINGSPEAK_) || (_RTT_TCP_ != 0)
void MW_EthernetAndTCPServerBegin(uint8_t tcpindex, uint32_t serverPort);
#endif
#if _RTT_TCP_ != 0
void MW_TCPFinalWrite(uint8_t tcpindex, uint8_t data, uint32_t serverPort);
void MW_TCPFinalread(uint8_t tcpindex, uint8_t *data, uint32_t serverPort,int *outStatus);
#endif

#if _RTT_WIFI_UDP_ != 0
uint8_t MW_WifiAndUDPBegin(uint8_t wifiudpindex, uint32_t localPort);
int MW_WifiUDPFinalWrite(uint8_t wifiudpindex, uint8_t data,uint8_t remoteIPOctect1,uint8_t remoteIPOctect2,uint8_t remoteIPOctect3,uint8_t remoteIPOctect4, uint32_t remoteport);
void MW_WifiUDPFinalRead(uint8_t wifiudpindex, uint8_t *data,int *outStatus);
#endif

#if defined(_RTT_THINGSPEAK_WIFI_) || _RTT_WIFI_TCP_ !=0  
void MW_WifiAndWifiTCPServerBegin(uint8_t wifitcpindex, uint32_t serverport);
#endif
#if  _RTT_WIFI_TCP_ !=0
void MW_WifiTCPFinalread(uint8_t wifitcpindex, uint8_t *data, uint32_t serverport, int *outStatus);
void MW_WifiTCPFinalWrite(uint8_t wifitcpindex, uint8_t data, uint32_t serverport);
#endif

#if defined(_ROTH_LEONARDO_)
void MW_usbattach();
#endif
#ifdef __cplusplus
}
#endif
#endif