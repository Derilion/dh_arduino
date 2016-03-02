#ifndef __ghzL9u6H4AUvnUT3cRQ5DB_h__
#define __ghzL9u6H4AUvnUT3cRQ5DB_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_tag_sMXuVOqiR8VrXITXlaWuyyE
#define struct_tag_sMXuVOqiR8VrXITXlaWuyyE

struct tag_sMXuVOqiR8VrXITXlaWuyyE
{
  real_T uint8;
  real_T uint16;
};

#endif                                 /*struct_tag_sMXuVOqiR8VrXITXlaWuyyE*/

#ifndef typedef_sMXuVOqiR8VrXITXlaWuyyE
#define typedef_sMXuVOqiR8VrXITXlaWuyyE

typedef struct tag_sMXuVOqiR8VrXITXlaWuyyE sMXuVOqiR8VrXITXlaWuyyE;

#endif                                 /*typedef_sMXuVOqiR8VrXITXlaWuyyE*/

#ifndef struct_tag_saG5948SFTrUFnIbVUb0TZH
#define struct_tag_saG5948SFTrUFnIbVUb0TZH

struct tag_saG5948SFTrUFnIbVUb0TZH
{
  int32_T isInitialized;
};

#endif                                 /*struct_tag_saG5948SFTrUFnIbVUb0TZH*/

#ifndef typedef_codertarget_arduinobase_internal_arduinoI2CRead
#define typedef_codertarget_arduinobase_internal_arduinoI2CRead

typedef struct tag_saG5948SFTrUFnIbVUb0TZH
  codertarget_arduinobase_internal_arduinoI2CRead;

#endif                                 /*typedef_codertarget_arduinobase_internal_arduinoI2CRead*/

#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct {
  char_T f0[7];
} struct_T;

#endif                                 /*typedef_struct_T*/

#ifndef typedef_b_struct_T
#define typedef_b_struct_T

typedef struct {
  char_T f0[4];
  char_T f1[7];
  char_T f2[6];
  char_T f3[2];
  real_T f4;
  char_T f5[2];
  real_T f6;
} b_struct_T;

#endif                                 /*typedef_b_struct_T*/

#ifndef typedef_InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB
#define typedef_InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB

typedef struct {
  SimStruct *S;
  codertarget_arduinobase_internal_arduinoI2CRead sysobj;
  boolean_T sysobj_not_empty;
  void *emlrtRootTLSGlobal;
  covrtInstance *covInst;
  uint16_T (*b_y0)[14];
} InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB;

#endif                                 /*typedef_InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_ghzL9u6H4AUvnUT3cRQ5DB(SimStruct *S, int_T method,
  void* data);

#endif
