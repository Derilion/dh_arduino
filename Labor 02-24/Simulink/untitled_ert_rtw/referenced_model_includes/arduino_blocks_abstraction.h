/* Copyright 2011-2012 The MathWorks, Inc. */

/*
 *   arduino_blocks_abstraction.h 
 */

#include "rtwtypes.h"
#include "Arduino.h"

#define MW_pinModeOutput(pinNumber) pinMode(pinNumber, OUTPUT)
#define MW_pinModeInput(pinNumber) pinMode(pinNumber, INPUT)

#define MW_digitalWrite(pinNumber, valueRef) digitalWrite(pinNumber, valueRef)
#define MW_digitalRead(pinNumber) digitalRead(pinNumber)

#define MW_analogWrite(pinNumber, valueRef) analogWrite(pinNumber, valueRef)
#define MW_analogRead(pinNumber) analogRead(pinNumber)
