/*
 * Wheelspeed3_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Wheelspeed3".
 *
 * Model version              : 1.9
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Wed Mar 16 14:12:39 2016
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
  { (char_T *)(&Wheelspeed3_B.Clock), 0, 0, 2 },

  { (char_T *)(&Wheelspeed3_B.DataTypeConversion), 3, 0, 2 },

  { (char_T *)(&Wheelspeed3_B.DigitalInput), 8, 0, 4 },

  { (char_T *)(&Wheelspeed3_B.Subsystem7.Divide), 0, 0, 1 },

  { (char_T *)(&Wheelspeed3_B.Subsystem3.Divide), 0, 0, 1 },

  { (char_T *)(&Wheelspeed3_B.Subsystem2.Divide), 0, 0, 1 },

  { (char_T *)(&Wheelspeed3_B.Subsystem1.Divide), 0, 0, 1 },

  { (char_T *)(&Wheelspeed3_B.vl.DataTypeConversion), 3, 0, 1 },

  { (char_T *)(&Wheelspeed3_B.hl.DataTypeConversion), 3, 0, 1 }
  ,

  { (char_T *)(&Wheelspeed3_DW.Scope_PWORK.LoggedData), 11, 0, 5 },

  { (char_T *)(&Wheelspeed3_DW.FromWs_IWORK.PrevIndex), 10, 0, 1 },

  { (char_T *)(&Wheelspeed3_DW.DelayInput1_DSTATE), 8, 0, 4 },

  { (char_T *)(&Wheelspeed3_DW.Subsystem7.Delay1_DSTATE), 0, 0, 1 },

  { (char_T *)(&Wheelspeed3_DW.Subsystem7.Subsystem1_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&Wheelspeed3_DW.Subsystem3.Delay1_DSTATE), 0, 0, 1 },

  { (char_T *)(&Wheelspeed3_DW.Subsystem3.Subsystem1_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&Wheelspeed3_DW.Subsystem2.Delay1_DSTATE), 0, 0, 1 },

  { (char_T *)(&Wheelspeed3_DW.Subsystem2.Subsystem1_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&Wheelspeed3_DW.Subsystem1.Delay1_DSTATE), 0, 0, 1 },

  { (char_T *)(&Wheelspeed3_DW.Subsystem1.Subsystem1_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&Wheelspeed3_DW.vl.Scope1_PWORK.LoggedData), 11, 0, 1 },

  { (char_T *)(&Wheelspeed3_DW.hl.Scope1_PWORK.LoggedData), 11, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  22U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Wheelspeed3_P.DigitalOutput_pinNumber), 7, 0, 4 },

  { (char_T *)(&Wheelspeed3_P.DetectRisePositive_vinit), 8, 0, 4 },

  { (char_T *)(&Wheelspeed3_P.Constant2_Value), 0, 0, 10 },

  { (char_T *)(&Wheelspeed3_P.DigitalInput_p1), 7, 0, 4 },

  { (char_T *)(&Wheelspeed3_P.Constant_Value), 8, 0, 4 },

  { (char_T *)(&Wheelspeed3_P.Subsystem7.n_Y0), 0, 0, 3 },

  { (char_T *)(&Wheelspeed3_P.Subsystem7.Delay1_DelayLength), 5, 0, 1 },

  { (char_T *)(&Wheelspeed3_P.Subsystem3.n_Y0), 0, 0, 3 },

  { (char_T *)(&Wheelspeed3_P.Subsystem3.Delay1_DelayLength), 5, 0, 1 },

  { (char_T *)(&Wheelspeed3_P.Subsystem2.n_Y0), 0, 0, 3 },

  { (char_T *)(&Wheelspeed3_P.Subsystem2.Delay1_DelayLength), 5, 0, 1 },

  { (char_T *)(&Wheelspeed3_P.Subsystem1.n_Y0), 0, 0, 3 },

  { (char_T *)(&Wheelspeed3_P.Subsystem1.Delay1_DelayLength), 5, 0, 1 },

  { (char_T *)(&Wheelspeed3_P.vl.DigitalOutput_pinNumber), 7, 0, 2 },

  { (char_T *)(&Wheelspeed3_P.vl.Constant2_Value), 0, 0, 4 },

  { (char_T *)(&Wheelspeed3_P.hl.DigitalOutput_pinNumber), 7, 0, 2 },

  { (char_T *)(&Wheelspeed3_P.hl.Constant2_Value), 0, 0, 4 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  17U,
  rtPTransitions
};

/* [EOF] Wheelspeed3_dt.h */
