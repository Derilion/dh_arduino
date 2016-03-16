/*
 * untitled_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "untitled".
 *
 * Model version              : 1.0
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Wed Mar 02 15:25:46 2016
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
  2*sizeof(uint32_T),
  sizeof(MdlrefDW_motor_hl_T),
  sizeof(MdlrefDW_motor_vr_T),
  sizeof(MdlrefDW_motor_vl_T),
  sizeof(MdlrefDW_motor_hr_T)
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
  "timer_uint32_pair_T",
  "MdlrefDW_motor_hl_T",
  "MdlrefDW_motor_vr_T",
  "MdlrefDW_motor_vl_T",
  "MdlrefDW_motor_hr_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&untitled_DW.Output_DSTATE), 3, 0, 1 },

  { (char_T *)(&untitled_DW.Model_DWORK1), 14, 0, 1 },

  { (char_T *)(&untitled_DW.Model1_DWORK1), 15, 0, 1 },

  { (char_T *)(&untitled_DW.Model2_DWORK1), 16, 0, 1 },

  { (char_T *)(&untitled_DW.Model3_DWORK1), 17, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  5U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&untitled_P.RepeatingSequenceStair_OutValue[0]), 0, 0, 6 },

  { (char_T *)(&untitled_P.LimitedCounter_uplimit), 3, 0, 1 },

  { (char_T *)(&untitled_P.enable_Value), 0, 0, 1 },

  { (char_T *)(&untitled_P.Constant_Value), 3, 0, 3 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  4U,
  rtPTransitions
};

/* [EOF] untitled_dt.h */
