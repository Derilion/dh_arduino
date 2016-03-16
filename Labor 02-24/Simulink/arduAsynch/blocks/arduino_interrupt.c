/*
 * Copyright, MathWorks inc. 2014
 *
 * Arduino Asynchronous Interrupt Block.
 *
 */

#define S_FUNCTION_NAME arduino_interrupt
#define S_FUNCTION_LEVEL 2

#include "simstruc.h"

#define PIN_NUMBER          (ssGetSFcnParam(S,0))
#define INT_NUMBER          (ssGetSFcnParam(S,1))
#define INT_MODE            (ssGetSFcnParam(S,2))
#define SHOW_INPUTPORT      (ssGetSFcnParam(S,3))

#ifndef MATLAB_MEX_FILE
/* Since we have a target file for this S-function, declare an error here
 * so that, if for some reason this file is being used (instead of the
 * target file) for code generation, we can trap this problem at compile
 * time. */
#  error This_file_can_be_used_only_during_simulation_inside_Simulink
#endif

/*====================*
 * S-function methods *
 *====================*/

static void mdlInitializeSizes(SimStruct *S)
{
    ssSetNumSFcnParams(S, 4);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return; /* Parameter mismatch will be reported by Simulink */
    }

    ssSetSFcnParamNotTunable(        S, 0);
    ssSetSFcnParamNotTunable(        S, 1);
    ssSetSFcnParamNotTunable(        S, 2);
    ssSetSFcnParamNotTunable(        S, 3);
    if ((int_T)(mxGetPr(SHOW_INPUTPORT)[0])) {
        ssSetNumInputPorts(          S, 1);
        ssSetInputPortWidth(         S, 0, 1);
        ssSetInputPortDirectFeedThrough(S, 0, 1);
        ssSetInputPortDataType(      S, 0, DYNAMICALLY_TYPED);
    }
    else {
        ssSetNumInputPorts(          S, 0);
    }
    ssSetNumOutputPorts(             S, 1);
    ssSetOutputPortWidth(            S, 0, 1);
    ssSetNumIWork(                   S, 0);
    ssSetNumRWork(                   S, 0);
    ssSetNumPWork(                   S, 0);
    ssSetNumSampleTimes(             S, 1);
    ssSetNumContStates(              S, 0);
    ssSetNumDiscStates(              S, 0);
    ssSetNumModes(                   S, 0);
    ssSetNumNonsampledZCs(           S, 0);
    ssSetOptions(                    S, (SS_OPTION_EXCEPTION_FREE_CODE |
                                         SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME |
                                         SS_OPTION_ASYNCHRONOUS_INTERRUPT));
    ssSetTimeSource(S,SS_TIMESOURCE_BASERATE);
}


static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, FIXED_IN_MINOR_STEP_OFFSET);
    ssSetCallSystemOutput(S,0);   
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
    
    if (ssGetNumInputPorts(S) == 0) { 
        ssCallSystemWithTid(S, 0, tid);
    }
    else {
        InputPtrsType uPtrs = ssGetInputPortSignalPtrs(S,0);
       
        switch (ssGetInputPortDataType(S, 0))
        {
            case SS_DOUBLE:
              {
                InputRealPtrsType pU  = (InputRealPtrsType)uPtrs;
                if(*pU[0]) {
                    ssCallSystemWithTid(S,0,tid);
                }
                break;
              }
            case SS_SINGLE:
              {
                InputReal32PtrsType pU  = (InputReal32PtrsType)uPtrs;
                if(*pU[0]) {
                    ssCallSystemWithTid(S,0,tid);
                }
                break;
              }
            case SS_INT8:
              {
                InputInt8PtrsType pU  = (InputInt8PtrsType)uPtrs;
                if(*pU[0]) {
                    ssCallSystemWithTid(S,0,tid);
                }
                break;
              }
            case SS_UINT8:
              {
                InputUInt8PtrsType pU  = (InputUInt8PtrsType)uPtrs;
                if(*pU[0]) {
                    ssCallSystemWithTid(S,0,tid);
                }
                break;
              }
            case SS_INT16:
              {
                InputInt16PtrsType pU  = (InputInt16PtrsType)uPtrs;
                if(*pU[0]) {
                    ssCallSystemWithTid(S,0,tid);
                }
                break;
              }
            case SS_UINT16:
              {
                InputUInt16PtrsType pU  = (InputUInt16PtrsType)uPtrs;
                if(*pU[0]) {
                    ssCallSystemWithTid(S,0,tid);
                }
                break;
              }
            case SS_INT32:
              {
                InputInt32PtrsType pU  = (InputInt32PtrsType)uPtrs;
                if(*pU[0]) {
                    ssCallSystemWithTid(S,0,tid);
                }
                break;
              }
            case SS_UINT32:
              {
                InputUInt32PtrsType pU  = (InputUInt32PtrsType)uPtrs;
                if(*pU[0]) {
                    ssCallSystemWithTid(S,0,tid);
                }
                break;
              }
            case SS_BOOLEAN:
              {
                InputBooleanPtrsType pU  = (InputBooleanPtrsType)uPtrs;
                if(*pU[0]) {
                    ssCallSystemWithTid(S,0,tid);
                }
                break;
              }
        }
    }
}

static void mdlTerminate(SimStruct *S) {}

#define MDL_SET_INPUT_PORT_DATA_TYPE
static void mdlSetInputPortDataType(SimStruct *S, 
                                    int       port, 
                                    DTypeId   dataType)
{
    switch(dataType)
    {
        /* Accept Simulink data types */
      case SS_DOUBLE:
      case SS_SINGLE:
      case SS_INT8:
      case SS_UINT8: 
      case SS_INT16:
      case SS_UINT16:
      case SS_INT32:
      case SS_UINT32:
      case SS_BOOLEAN:
        ssSetInputPortDataType(S, 0, dataType);
        break;
        
      default:
        /* Reject proposed data type */
        ssSetErrorStatus(S,"Invalid input port data type");
        break;
    }
} /* mdlSetInputPortDataType */

#define MDL_SET_DEFAULT_PORT_DATA_TYPES
static void mdlSetDefaultPortDataTypes(SimStruct *S)
{
    /* Set input port data type to bool */
    ssSetInputPortDataType(  S, 0, SS_BOOLEAN);            

} /* mdlSetDefaultPortDataTypes */

#define MDL_RTW
static void mdlRTW(SimStruct *S)
{
    /* Write out parameters for this block.
     */
    char *str;
    real_T * modep;
    int mode;   
    
    modep = (real_T *)mxGetPr(INT_MODE);
    mode = (int)modep[0];
    str = malloc(10);
    
    switch (mode) {
        case 1:
            strcpy(str, "LOW");
            break;
        case 2:
            strcpy(str, "CHANGE");
            break;
        case 3:
            strcpy(str, "RISING");
            break;
        case 4:
            strcpy(str, "FALLING");
            break;
        default:
            strcpy(str, "ERROR");
            // Error out
            break;
    }

    if (!ssWriteRTWParamSettings(S, 3, 
                                 SSWRITE_VALUE_NUM,"IntNumber",
                                 (real_T) mxGetPr(INT_NUMBER)[0], 
                                 SSWRITE_VALUE_NUM,"PinNumber",
                                 (real_T) mxGetPr(PIN_NUMBER)[0], 
                                 SSWRITE_VALUE_STR, "IntMode",
                                 str)) {
        return; /* An error occurred which will be reported by SL */
    }
    free(str);
}

/*=============================*
 * Required S-function trailer *
 *=============================*/

#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif

/* EOF: arduino_interrupt1.c*/
