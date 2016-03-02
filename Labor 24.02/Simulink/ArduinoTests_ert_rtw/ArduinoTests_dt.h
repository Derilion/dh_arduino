/*
 * ArduinoTests_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ArduinoTests".
 *
 * Model version              : 1.4
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Wed Feb 24 17:40:41 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&ArduinoTests_B.Add), 0, 0, 1 },

  { (char_T *)(&ArduinoTests_B.AnalogInput), 5, 0, 1 },

  { (char_T *)(&ArduinoTests_B.DigitalInput), 8, 0, 4 }
  ,

  { (char_T *)(&ArduinoTests_DW.Delay_DSTATE), 0, 0, 1 },

  { (char_T *)(&ArduinoTests_DW.Scope_PWORK.LoggedData), 11, 0, 3 },

  { (char_T *)(&ArduinoTests_DW.clockTickCounter), 6, 0, 1 },

  { (char_T *)(&ArduinoTests_DW.DelayInput1_DSTATE), 8, 0, 4 },

  { (char_T *)(&ArduinoTests_DW.Subsystem_SubsysRanBC), 2, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  8U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&ArduinoTests_P.DetectRisePositive_vinit), 8, 0, 4 },

  { (char_T *)(&ArduinoTests_P.Constant1_Value), 0, 0, 9 },

  { (char_T *)(&ArduinoTests_P.AnalogInput_p1), 7, 0, 5 },

  { (char_T *)(&ArduinoTests_P.Delay_DelayLength), 5, 0, 1 },

  { (char_T *)(&ArduinoTests_P.Constant_Value_l), 8, 0, 4 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] ArduinoTests_dt.h */
