/* Include files */

#include "modelInterface.h"
#include "m_ghzL9u6H4AUvnUT3cRQ5DB.h"

/* Type Definitions */

/* Named Constants */
#define SlaveAddress_                  (104.0)
#define RegisterAddressEnable_         (false)
#define RegisterAddress_               (59.0)
#define Datalength_                    (14.0)
#define SampleTime_                    (0.01)

/* Variable Declarations */

/* Variable Definitions */
static emlrtMCInfo emlrtMCI = { 14, 25, "warning",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\warning.m"
};

static emlrtMCInfo b_emlrtMCI = { 14, 9, "warning",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\warning.m"
};

static emlrtMCInfo c_emlrtMCI = { 1, 1, "SystemProp",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+coder\\SystemProp.p"
};

static emlrtMCInfo d_emlrtMCI = { 1, 1, "SystemCore",
  "C:\\Program Files\\MATLAB\\R2015b\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+coder\\SystemCore.p"
};

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB
  *moduleInstance);
static const mxArray *mw__internal__getSimState__fcn
  (InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB *moduleInstance);
static codertarget_arduinobase_internal_arduinoI2CRead emlrt_marshallIn
  (InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB *moduleInstance, const mxArray
   *b_sysobj, const char_T *identifier);
static codertarget_arduinobase_internal_arduinoI2CRead b_emlrt_marshallIn
  (InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB *moduleInstance, const mxArray *u,
   const emlrtMsgIdentifier *parentId);
static int32_T c_emlrt_marshallIn(InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId);
static boolean_T d_emlrt_marshallIn(InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB
  *moduleInstance, const mxArray *b_sysobj_not_empty, const char_T *identifier);
static boolean_T e_emlrt_marshallIn(InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId);
static void mw__internal__setSimState__fcn(InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB
  *moduleInstance, const mxArray *st);
static const mxArray *message(InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB
  *moduleInstance, const mxArray *b, const mxArray *c, emlrtMCInfo *location);
static void error(InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB *moduleInstance, const
                  mxArray *b, emlrtMCInfo *location);
static int32_T f_emlrt_marshallIn(InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId);
static boolean_T g_emlrt_marshallIn(InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId);
static void init_simulink_io_address(InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB *moduleInstance)
{
  codertarget_arduinobase_internal_arduinoI2CRead *obj;
  int32_T i0;
  static char_T cv0[51] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'L', 'o', 'c', 'k', 'e', 'd', 'R', 'e', 'l', 'e',
    'a', 's', 'e', 'd', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

  char_T u[51];
  const mxArray *y;
  static const int32_T iv0[2] = { 1, 51 };

  const mxArray *m0;
  static char_T cv1[5] = { 's', 'e', 't', 'u', 'p' };

  char_T b_u[5];
  const mxArray *b_y;
  static const int32_T iv1[2] = { 1, 5 };

  init_simulink_io_address(moduleInstance);
  if (!moduleInstance->sysobj_not_empty) {
    moduleInstance->sysobj.isInitialized = 0;
    moduleInstance->sysobj_not_empty = true;
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isInitialized != 0) {
    for (i0 = 0; i0 < 51; i0++) {
      u[i0] = cv0[i0];
    }

    y = NULL;
    m0 = emlrtCreateCharArray(2, iv0);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 51, m0, &u[0]);
    emlrtAssign(&y, m0);
    for (i0 = 0; i0 < 5; i0++) {
      b_u[i0] = cv1[i0];
    }

    b_y = NULL;
    m0 = emlrtCreateCharArray(2, iv1);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 5, m0, &b_u[0]);
    emlrtAssign(&b_y, m0);
    error(moduleInstance, message(moduleInstance, y, b_y, &d_emlrtMCI),
          &d_emlrtMCI);
  }

  obj->isInitialized = 1;
}

static void cgxe_mdl_initialize(InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB
  *moduleInstance)
{
  codertarget_arduinobase_internal_arduinoI2CRead *obj;
  int32_T i1;
  static char_T cv2[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  char_T u[45];
  const mxArray *y;
  static const int32_T iv2[2] = { 1, 45 };

  const mxArray *m1;
  static char_T cv3[8] = { 'i', 's', 'L', 'o', 'c', 'k', 'e', 'd' };

  char_T b_u[8];
  const mxArray *b_y;
  static const int32_T iv3[2] = { 1, 8 };

  boolean_T flag;
  char_T c_u[45];
  const mxArray *c_y;
  static const int32_T iv4[2] = { 1, 45 };

  static char_T cv4[5] = { 'r', 'e', 's', 'e', 't' };

  char_T d_u[5];
  const mxArray *d_y;
  static const int32_T iv5[2] = { 1, 5 };

  if (!moduleInstance->sysobj_not_empty) {
    moduleInstance->sysobj.isInitialized = 0;
    moduleInstance->sysobj_not_empty = true;
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isInitialized == 2) {
    for (i1 = 0; i1 < 45; i1++) {
      u[i1] = cv2[i1];
    }

    y = NULL;
    m1 = emlrtCreateCharArray(2, iv2);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 45, m1, &u[0]);
    emlrtAssign(&y, m1);
    for (i1 = 0; i1 < 8; i1++) {
      b_u[i1] = cv3[i1];
    }

    b_y = NULL;
    m1 = emlrtCreateCharArray(2, iv3);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 8, m1, &b_u[0]);
    emlrtAssign(&b_y, m1);
    error(moduleInstance, message(moduleInstance, y, b_y, &d_emlrtMCI),
          &d_emlrtMCI);
  }

  flag = (obj->isInitialized == 1);
  if (flag && (moduleInstance->sysobj.isInitialized == 2)) {
    for (i1 = 0; i1 < 45; i1++) {
      c_u[i1] = cv2[i1];
    }

    c_y = NULL;
    m1 = emlrtCreateCharArray(2, iv4);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 45, m1, &c_u[0]);
    emlrtAssign(&c_y, m1);
    for (i1 = 0; i1 < 5; i1++) {
      d_u[i1] = cv4[i1];
    }

    d_y = NULL;
    m1 = emlrtCreateCharArray(2, iv5);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 5, m1, &d_u[0]);
    emlrtAssign(&d_y, m1);
    error(moduleInstance, message(moduleInstance, c_y, d_y, &d_emlrtMCI),
          &d_emlrtMCI);
  }
}

static void cgxe_mdl_outputs(InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB
  *moduleInstance)
{
  codertarget_arduinobase_internal_arduinoI2CRead *obj;
  int32_T i2;
  static char_T cv5[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  char_T u[45];
  const mxArray *y;
  static const int32_T iv6[2] = { 1, 45 };

  const mxArray *m2;
  static char_T cv6[4] = { 's', 't', 'e', 'p' };

  char_T b_u[4];
  const mxArray *b_y;
  static const int32_T iv7[2] = { 1, 4 };

  static char_T cv7[51] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'L', 'o', 'c', 'k', 'e', 'd', 'R', 'e', 'l', 'e',
    'a', 's', 'e', 'd', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

  char_T c_u[51];
  const mxArray *c_y;
  static const int32_T iv8[2] = { 1, 51 };

  static char_T cv8[5] = { 's', 'e', 't', 'u', 'p' };

  char_T d_u[5];
  const mxArray *d_y;
  static const int32_T iv9[2] = { 1, 5 };

  if (!moduleInstance->sysobj_not_empty) {
    moduleInstance->sysobj.isInitialized = 0;
    moduleInstance->sysobj_not_empty = true;
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isInitialized == 2) {
    for (i2 = 0; i2 < 45; i2++) {
      u[i2] = cv5[i2];
    }

    y = NULL;
    m2 = emlrtCreateCharArray(2, iv6);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 45, m2, &u[0]);
    emlrtAssign(&y, m2);
    for (i2 = 0; i2 < 4; i2++) {
      b_u[i2] = cv6[i2];
    }

    b_y = NULL;
    m2 = emlrtCreateCharArray(2, iv7);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 4, m2, &b_u[0]);
    emlrtAssign(&b_y, m2);
    error(moduleInstance, message(moduleInstance, y, b_y, &d_emlrtMCI),
          &d_emlrtMCI);
  }

  if (obj->isInitialized != 1) {
    if (obj->isInitialized != 0) {
      for (i2 = 0; i2 < 51; i2++) {
        c_u[i2] = cv7[i2];
      }

      c_y = NULL;
      m2 = emlrtCreateCharArray(2, iv8);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 51, m2, &c_u
        [0]);
      emlrtAssign(&c_y, m2);
      for (i2 = 0; i2 < 5; i2++) {
        d_u[i2] = cv8[i2];
      }

      d_y = NULL;
      m2 = emlrtCreateCharArray(2, iv9);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 5, m2, &d_u[0]);
      emlrtAssign(&d_y, m2);
      error(moduleInstance, message(moduleInstance, c_y, d_y, &d_emlrtMCI),
            &d_emlrtMCI);
    }

    obj->isInitialized = 1;
  }

  for (i2 = 0; i2 < 14; i2++) {
    (*moduleInstance->b_y0)[i2] = 0U;
  }
}

static void cgxe_mdl_update(InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB
  *moduleInstance)
{
  codertarget_arduinobase_internal_arduinoI2CRead *obj;
  int32_T i3;
  static char_T cv9[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  char_T u[45];
  const mxArray *y;
  static const int32_T iv10[2] = { 1, 45 };

  const mxArray *m3;
  static char_T cv10[8] = { 'i', 's', 'L', 'o', 'c', 'k', 'e', 'd' };

  char_T b_u[8];
  const mxArray *b_y;
  static const int32_T iv11[2] = { 1, 8 };

  boolean_T flag;
  char_T c_u[45];
  const mxArray *c_y;
  static const int32_T iv12[2] = { 1, 45 };

  static char_T cv11[7] = { 'r', 'e', 'l', 'e', 'a', 's', 'e' };

  char_T d_u[7];
  const mxArray *d_y;
  static const int32_T iv13[2] = { 1, 7 };

  if (!moduleInstance->sysobj_not_empty) {
    moduleInstance->sysobj.isInitialized = 0;
    moduleInstance->sysobj_not_empty = true;
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isInitialized == 2) {
    for (i3 = 0; i3 < 45; i3++) {
      u[i3] = cv9[i3];
    }

    y = NULL;
    m3 = emlrtCreateCharArray(2, iv10);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 45, m3, &u[0]);
    emlrtAssign(&y, m3);
    for (i3 = 0; i3 < 8; i3++) {
      b_u[i3] = cv10[i3];
    }

    b_y = NULL;
    m3 = emlrtCreateCharArray(2, iv11);
    emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 8, m3, &b_u[0]);
    emlrtAssign(&b_y, m3);
    error(moduleInstance, message(moduleInstance, y, b_y, &d_emlrtMCI),
          &d_emlrtMCI);
  }

  flag = (obj->isInitialized == 1);
  if (flag) {
    obj = &moduleInstance->sysobj;
    if (moduleInstance->sysobj.isInitialized == 2) {
      for (i3 = 0; i3 < 45; i3++) {
        c_u[i3] = cv9[i3];
      }

      c_y = NULL;
      m3 = emlrtCreateCharArray(2, iv12);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 45, m3, &c_u
        [0]);
      emlrtAssign(&c_y, m3);
      for (i3 = 0; i3 < 7; i3++) {
        d_u[i3] = cv11[i3];
      }

      d_y = NULL;
      m3 = emlrtCreateCharArray(2, iv13);
      emlrtInitCharArrayR2013a(moduleInstance->emlrtRootTLSGlobal, 7, m3, &d_u[0]);
      emlrtAssign(&d_y, m3);
      error(moduleInstance, message(moduleInstance, c_y, d_y, &d_emlrtMCI),
            &d_emlrtMCI);
    }

    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }
}

static const mxArray *mw__internal__getSimState__fcn
  (InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB *moduleInstance)
{
  const mxArray *st;
  const mxArray *y;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m4;
  const mxArray *d_y;
  st = NULL;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellMatrix(2, 1));
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  c_y = NULL;
  m4 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)mxGetData(m4) = moduleInstance->sysobj.isInitialized;
  emlrtAssign(&c_y, m4);
  emlrtAddField(b_y, c_y, "isInitialized", 0);
  emlrtSetCell(y, 0, b_y);
  d_y = NULL;
  m4 = emlrtCreateLogicalScalar(moduleInstance->sysobj_not_empty);
  emlrtAssign(&d_y, m4);
  emlrtSetCell(y, 1, d_y);
  emlrtAssign(&st, y);
  return st;
}

static codertarget_arduinobase_internal_arduinoI2CRead emlrt_marshallIn
  (InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB *moduleInstance, const mxArray
   *b_sysobj, const char_T *identifier)
{
  codertarget_arduinobase_internal_arduinoI2CRead y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(moduleInstance, emlrtAlias(b_sysobj), &thisId);
  emlrtDestroyArray(&b_sysobj);
  return y;
}

static codertarget_arduinobase_internal_arduinoI2CRead b_emlrt_marshallIn
  (InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB *moduleInstance, const mxArray *u,
   const emlrtMsgIdentifier *parentId)
{
  codertarget_arduinobase_internal_arduinoI2CRead y;
  emlrtMsgIdentifier thisId;
  static const int32_T dims = 0;
  static const char * fieldNames[1] = { "isInitialized" };

  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(moduleInstance->emlrtRootTLSGlobal, parentId, u, 1,
    fieldNames, 0U, &dims);
  thisId.fIdentifier = "isInitialized";
  y.isInitialized = c_emlrt_marshallIn(moduleInstance, emlrtAlias
    (emlrtGetFieldR2013a(moduleInstance->emlrtRootTLSGlobal, u, 0,
    "isInitialized")), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static int32_T c_emlrt_marshallIn(InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId)
{
  int32_T y;
  y = f_emlrt_marshallIn(moduleInstance, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static boolean_T d_emlrt_marshallIn(InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB
  *moduleInstance, const mxArray *b_sysobj_not_empty, const char_T *identifier)
{
  boolean_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = e_emlrt_marshallIn(moduleInstance, emlrtAlias(b_sysobj_not_empty), &thisId);
  emlrtDestroyArray(&b_sysobj_not_empty);
  return y;
}

static boolean_T e_emlrt_marshallIn(InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = g_emlrt_marshallIn(moduleInstance, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void mw__internal__setSimState__fcn(InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB
  *moduleInstance, const mxArray *st)
{
  const mxArray *u;
  u = emlrtAlias(st);
  moduleInstance->sysobj = emlrt_marshallIn(moduleInstance, emlrtAlias
    (emlrtGetCell(moduleInstance->emlrtRootTLSGlobal, "sysobj", u, 0)), "sysobj");
  moduleInstance->sysobj_not_empty = d_emlrt_marshallIn(moduleInstance,
    emlrtAlias(emlrtGetCell(moduleInstance->emlrtRootTLSGlobal,
    "sysobj_not_empty", u, 1)), "sysobj_not_empty");
  emlrtDestroyArray(&u);
  emlrtDestroyArray(&st);
}

static const mxArray *message(InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB
  *moduleInstance, const mxArray *b, const mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m5;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(moduleInstance->emlrtRootTLSGlobal, 1, &m5, 2,
    pArrays, "message", true, location);
}

static void error(InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB *moduleInstance, const
                  mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(moduleInstance->emlrtRootTLSGlobal, 0, NULL, 1, &pArray,
                        "error", true, location);
}

static int32_T f_emlrt_marshallIn(InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId)
{
  int32_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(moduleInstance->emlrtRootTLSGlobal, msgId, src,
    "int32", false, 0U, &dims);
  ret = *(int32_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static boolean_T g_emlrt_marshallIn(InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId)
{
  boolean_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(moduleInstance->emlrtRootTLSGlobal, msgId, src,
    "logical", false, 0U, &dims);
  ret = *mxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void init_simulink_io_address(InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = cgxertGetEMLRTCtx(moduleInstance->S, 0);
  moduleInstance->covInst = (covrtInstance *)cgxertGetCovrtInstance
    (moduleInstance->S, 0);
  moduleInstance->b_y0 = (uint16_T (*)[14])cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
}

/* CGXE Glue Code */
static void mdlOutputs_ghzL9u6H4AUvnUT3cRQ5DB(SimStruct *S, int_T tid)
{
  InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB *moduleInstance =
    (InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_ghzL9u6H4AUvnUT3cRQ5DB(SimStruct *S)
{
  InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB *moduleInstance =
    (InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_ghzL9u6H4AUvnUT3cRQ5DB(SimStruct *S, int_T tid)
{
  InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB *moduleInstance =
    (InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static mxArray* getSimState_ghzL9u6H4AUvnUT3cRQ5DB(SimStruct *S)
{
  mxArray* mxSS;
  InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB *moduleInstance =
    (InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB *)cgxertGetRuntimeInstance(S);
  mxSS = (mxArray *) mw__internal__getSimState__fcn(moduleInstance);
  return mxSS;
}

static void setSimState_ghzL9u6H4AUvnUT3cRQ5DB(SimStruct *S, const mxArray *ss)
{
  InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB *moduleInstance =
    (InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB *)cgxertGetRuntimeInstance(S);
  mw__internal__setSimState__fcn(moduleInstance, emlrtAlias(ss));
}

static void mdlTerminate_ghzL9u6H4AUvnUT3cRQ5DB(SimStruct *S)
{
  InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB *moduleInstance =
    (InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlStart_ghzL9u6H4AUvnUT3cRQ5DB(SimStruct *S)
{
  InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB *moduleInstance =
    (InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB *)calloc(1, sizeof
    (InstanceStruct_ghzL9u6H4AUvnUT3cRQ5DB));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_ghzL9u6H4AUvnUT3cRQ5DB);
  ssSetmdlInitializeConditions(S, mdlInitialize_ghzL9u6H4AUvnUT3cRQ5DB);
  ssSetmdlUpdate(S, mdlUpdate_ghzL9u6H4AUvnUT3cRQ5DB);
  ssSetmdlTerminate(S, mdlTerminate_ghzL9u6H4AUvnUT3cRQ5DB);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_ghzL9u6H4AUvnUT3cRQ5DB(SimStruct *S)
{
}

void method_dispatcher_ghzL9u6H4AUvnUT3cRQ5DB(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_ghzL9u6H4AUvnUT3cRQ5DB(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_ghzL9u6H4AUvnUT3cRQ5DB(S);
    break;

   case SS_CALL_MDL_GET_SIM_STATE:
    *((mxArray**) data) = getSimState_ghzL9u6H4AUvnUT3cRQ5DB(S);
    break;

   case SS_CALL_MDL_SET_SIM_STATE:
    setSimState_ghzL9u6H4AUvnUT3cRQ5DB(S, (const mxArray *) data);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: ghzL9u6H4AUvnUT3cRQ5DB.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_ghzL9u6H4AUvnUT3cRQ5DB_BuildInfoUpdate(void)
{
  mxArray * mxBIArgs;
  mxArray * elem_1;
  mxArray * elem_2;
  mxArray * elem_3;
  mxArray * elem_4;
  mxArray * elem_5;
  mxArray * elem_6;
  mxArray * elem_7;
  mxArray * elem_8;
  mxArray * elem_9;
  mxArray * elem_10;
  mxBIArgs = mxCreateCellMatrix(1,3);
  elem_1 = mxCreateCellMatrix(1,6);
  elem_2 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,0,elem_2);
  elem_3 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,1,elem_3);
  elem_4 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,2,elem_4);
  elem_5 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,3,elem_5);
  elem_6 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,4,elem_6);
  elem_7 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,5,elem_7);
  mxSetCell(mxBIArgs,0,elem_1);
  elem_8 = mxCreateCellMatrix(1,1);
  elem_9 = mxCreateString("codertarget.arduinobase.internal.arduinoI2CRead");
  mxSetCell(elem_8,0,elem_9);
  mxSetCell(mxBIArgs,1,elem_8);
  elem_10 = mxCreateCellMatrix(1,0);
  mxSetCell(mxBIArgs,2,elem_10);
  return mxBIArgs;
}
