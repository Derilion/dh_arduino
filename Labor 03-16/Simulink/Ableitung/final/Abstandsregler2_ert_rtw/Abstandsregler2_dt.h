/*
 * Abstandsregler2_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Abstandsregler2".
 *
 * Model version              : 1.28
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Wed Mar 23 17:32:47 2016
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
  { (char_T *)(&Abstandsregler2_B.uDLookupTable), 0, 0, 29 },

  { (char_T *)(&Abstandsregler2_B.Subsystem3.Add), 0, 0, 1 },

  { (char_T *)(&Abstandsregler2_B.Subsystem2.Add), 0, 0, 1 },

  { (char_T *)(&Abstandsregler2_B.Subsystem1.Add), 0, 0, 1 },

  { (char_T *)(&Abstandsregler2_B.Subsystem.Add), 0, 0, 1 }
  ,

  { (char_T *)(&Abstandsregler2_DW.Integrator_DSTATE), 0, 0, 33 },

  { (char_T *)(&Abstandsregler2_DW.Scope_PWORK.LoggedData[0]), 11, 0, 7 },

  { (char_T *)(&Abstandsregler2_DW.DelayInput1_DSTATE), 8, 0, 4 },

  { (char_T *)(&Abstandsregler2_DW.Subsystem3.Delay_DSTATE), 0, 0, 1 },

  { (char_T *)(&Abstandsregler2_DW.Subsystem3.Subsystem_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&Abstandsregler2_DW.Subsystem2.Delay_DSTATE), 0, 0, 1 },

  { (char_T *)(&Abstandsregler2_DW.Subsystem2.Subsystem_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&Abstandsregler2_DW.Subsystem1.Delay_DSTATE), 0, 0, 1 },

  { (char_T *)(&Abstandsregler2_DW.Subsystem1.Subsystem_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&Abstandsregler2_DW.Subsystem.Delay_DSTATE), 0, 0, 1 },

  { (char_T *)(&Abstandsregler2_DW.Subsystem.Subsystem_SubsysRanBC), 2, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  16U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Abstandsregler2_P.AB1[0]), 0, 0, 38 },

  { (char_T *)(&Abstandsregler2_P.DigitalOutput_pinNumber), 7, 0, 4 },

  { (char_T *)(&Abstandsregler2_P.DetectRisePositive_vinit), 8, 0, 4 },

  { (char_T *)(&Abstandsregler2_P.Constant3_Value), 0, 0, 224 },

  { (char_T *)(&Abstandsregler2_P.Abstandssensor_p1), 7, 0, 5 },

  { (char_T *)(&Abstandsregler2_P.Constant_Value_k), 8, 0, 4 },

  { (char_T *)(&Abstandsregler2_P.Subsystem3.Constant1_Value), 0, 0, 5 },

  { (char_T *)(&Abstandsregler2_P.Subsystem3.Delay_DelayLength), 5, 0, 1 },

  { (char_T *)(&Abstandsregler2_P.Subsystem2.Constant1_Value), 0, 0, 5 },

  { (char_T *)(&Abstandsregler2_P.Subsystem2.Delay_DelayLength), 5, 0, 1 },

  { (char_T *)(&Abstandsregler2_P.Subsystem1.Constant1_Value), 0, 0, 5 },

  { (char_T *)(&Abstandsregler2_P.Subsystem1.Delay_DelayLength), 5, 0, 1 },

  { (char_T *)(&Abstandsregler2_P.Subsystem.Constant1_Value), 0, 0, 5 },

  { (char_T *)(&Abstandsregler2_P.Subsystem.Delay_DelayLength), 5, 0, 1 },

  { (char_T *)(&Abstandsregler2_P.vl.DigitalOutput_pinNumber), 7, 0, 2 },

  { (char_T *)(&Abstandsregler2_P.vl.Constant3_Value), 0, 0, 4 },

  { (char_T *)(&Abstandsregler2_P.hl.DigitalOutput_pinNumber), 7, 0, 2 },

  { (char_T *)(&Abstandsregler2_P.hl.Constant3_Value), 0, 0, 4 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  18U,
  rtPTransitions
};

/* [EOF] Abstandsregler2_dt.h */
