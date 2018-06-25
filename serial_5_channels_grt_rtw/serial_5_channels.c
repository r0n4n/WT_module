/*
 * serial_5_channels.c
 *
 * Code generation for model "serial_5_channels".
 *
 * Model version              : 1.57
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Mon Jun 04 17:31:22 2018
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Microchip->dsPIC
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "serial_5_channels.h"
#include "serial_5_channels_private.h"

/* Block states (auto storage) */
DW_serial_5_channels_T serial_5_channels_DW;

/* Real-time model */
RT_MODEL_serial_5_channels_T serial_5_channels_M_;
RT_MODEL_serial_5_channels_T *const serial_5_channels_M = &serial_5_channels_M_;

/* Model step function */
void serial_5_channels_step(void)
{
  /* local block i/o variables */
  real32_T rtb_SerialReceive1[5];

  /* Scope: '<Root>/Scope' */
  {
    StructLogVar *svar = (StructLogVar *)
      serial_5_channels_DW.Scope_PWORK.LoggedData;
    LogVar *var = svar->signals.values;

    /* signals */
    {
      real32_T up0[1];
      up0[0] = rtb_SerialReceive1[0];
      rt_UpdateLogVar((LogVar *)var, up0, 0);
    }
  }

  /* Scope: '<Root>/Scope1' */
  {
    StructLogVar *svar = (StructLogVar *)
      serial_5_channels_DW.Scope1_PWORK.LoggedData;
    LogVar *var = svar->signals.values;

    /* signals */
    {
      real32_T up0[1];
      up0[0] = rtb_SerialReceive1[1];
      rt_UpdateLogVar((LogVar *)var, up0, 0);
    }
  }

  /* Scope: '<Root>/Scope2' */
  {
    StructLogVar *svar = (StructLogVar *)
      serial_5_channels_DW.Scope2_PWORK.LoggedData;
    LogVar *var = svar->signals.values;

    /* signals */
    {
      real32_T up0[1];
      up0[0] = rtb_SerialReceive1[2];
      rt_UpdateLogVar((LogVar *)var, up0, 0);
    }
  }

  /* Scope: '<Root>/Scope3' */
  {
    StructLogVar *svar = (StructLogVar *)
      serial_5_channels_DW.Scope3_PWORK.LoggedData;
    LogVar *var = svar->signals.values;

    /* signals */
    {
      real32_T up0[1];
      up0[0] = rtb_SerialReceive1[3];
      rt_UpdateLogVar((LogVar *)var, up0, 0);
    }
  }

  /* Scope: '<Root>/Scope4' */
  {
    StructLogVar *svar = (StructLogVar *)
      serial_5_channels_DW.Scope4_PWORK.LoggedData;
    LogVar *var = svar->signals.values;

    /* signals */
    {
      real32_T up0[1];
      up0[0] = rtb_SerialReceive1[4];
      rt_UpdateLogVar((LogVar *)var, up0, 0);
    }
  }

  /* Matfile logging */
  rt_UpdateTXYLogVars(serial_5_channels_M->rtwLogInfo,
                      (serial_5_channels_M->Timing.t));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(serial_5_channels_M)!=-1) &&
        !((rtmGetTFinal(serial_5_channels_M)-serial_5_channels_M->Timing.t[0]) >
          serial_5_channels_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(serial_5_channels_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++serial_5_channels_M->Timing.clockTick0)) {
    ++serial_5_channels_M->Timing.clockTickH0;
  }

  serial_5_channels_M->Timing.t[0] = serial_5_channels_M->Timing.clockTick0 *
    serial_5_channels_M->Timing.stepSize0 +
    serial_5_channels_M->Timing.clockTickH0 *
    serial_5_channels_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    serial_5_channels_M->Timing.clockTick1++;
    if (!serial_5_channels_M->Timing.clockTick1) {
      serial_5_channels_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void serial_5_channels_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)serial_5_channels_M, 0,
                sizeof(RT_MODEL_serial_5_channels_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&serial_5_channels_M->solverInfo,
                          &serial_5_channels_M->Timing.simTimeStep);
    rtsiSetTPtr(&serial_5_channels_M->solverInfo, &rtmGetTPtr
                (serial_5_channels_M));
    rtsiSetStepSizePtr(&serial_5_channels_M->solverInfo,
                       &serial_5_channels_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&serial_5_channels_M->solverInfo, (&rtmGetErrorStatus
      (serial_5_channels_M)));
    rtsiSetRTModelPtr(&serial_5_channels_M->solverInfo, serial_5_channels_M);
  }

  rtsiSetSimTimeStep(&serial_5_channels_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&serial_5_channels_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(serial_5_channels_M, &serial_5_channels_M->Timing.tArray[0]);
  rtmSetTFinal(serial_5_channels_M, 0.2);
  serial_5_channels_M->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    serial_5_channels_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(serial_5_channels_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(serial_5_channels_M->rtwLogInfo, (NULL));
    rtliSetLogT(serial_5_channels_M->rtwLogInfo, "tout");
    rtliSetLogX(serial_5_channels_M->rtwLogInfo, "");
    rtliSetLogXFinal(serial_5_channels_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(serial_5_channels_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(serial_5_channels_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(serial_5_channels_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(serial_5_channels_M->rtwLogInfo, 1);
    rtliSetLogY(serial_5_channels_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(serial_5_channels_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(serial_5_channels_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&serial_5_channels_DW, 0,
                sizeof(DW_serial_5_channels_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(serial_5_channels_M->rtwLogInfo, 0.0,
    rtmGetTFinal(serial_5_channels_M), serial_5_channels_M->Timing.stepSize0,
    (&rtmGetErrorStatus(serial_5_channels_M)));

  /* Start for Scope: '<Root>/Scope' */
  {
    RTWLogSignalInfo rt_ScopeSignalInfo;
    static int_T rt_ScopeSignalWidths[] = { 1 };

    static int_T rt_ScopeSignalNumDimensions[] = { 2 };

    static int_T rt_ScopeSignalDimensions[] = { 1, 1 };

    static void *rt_ScopeCurrSigDims[] = { (NULL), (NULL) };

    static int_T rt_ScopeCurrSigDimsSize[] = { 2, 2 };

    static const char_T *rt_ScopeSignalLabels[] = { "" };

    static char_T rt_ScopeSignalTitles[] = "";
    static int_T rt_ScopeSignalTitleLengths[] = { 0 };

    static boolean_T rt_ScopeSignalIsVarDims[] = { 0 };

    static int_T rt_ScopeSignalPlotStyles[] = { 1 };

    BuiltInDTypeId dTypes[1] = { SS_SINGLE };

    static char_T rt_ScopeBlockName[] = "serial_5_channels/Scope";
    rt_ScopeSignalInfo.numSignals = 1;
    rt_ScopeSignalInfo.numCols = rt_ScopeSignalWidths;
    rt_ScopeSignalInfo.numDims = rt_ScopeSignalNumDimensions;
    rt_ScopeSignalInfo.dims = rt_ScopeSignalDimensions;
    rt_ScopeSignalInfo.isVarDims = rt_ScopeSignalIsVarDims;
    rt_ScopeSignalInfo.currSigDims = rt_ScopeCurrSigDims;
    rt_ScopeSignalInfo.currSigDimsSize = rt_ScopeCurrSigDimsSize;
    rt_ScopeSignalInfo.dataTypes = dTypes;
    rt_ScopeSignalInfo.complexSignals = (NULL);
    rt_ScopeSignalInfo.frameData = (NULL);
    rt_ScopeSignalInfo.labels.cptr = rt_ScopeSignalLabels;
    rt_ScopeSignalInfo.titles = rt_ScopeSignalTitles;
    rt_ScopeSignalInfo.titleLengths = rt_ScopeSignalTitleLengths;
    rt_ScopeSignalInfo.plotStyles = rt_ScopeSignalPlotStyles;
    rt_ScopeSignalInfo.blockNames.cptr = (NULL);
    rt_ScopeSignalInfo.stateNames.cptr = (NULL);
    rt_ScopeSignalInfo.crossMdlRef = (NULL);
    rt_ScopeSignalInfo.dataTypeConvert = (NULL);
    serial_5_channels_DW.Scope_PWORK.LoggedData = rt_CreateStructLogVar(
      serial_5_channels_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(serial_5_channels_M),
      serial_5_channels_M->Timing.stepSize0,
      (&rtmGetErrorStatus(serial_5_channels_M)),
      "ScopeData",
      0,
      0,
      1,
      0.001,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (serial_5_channels_DW.Scope_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for Scope: '<Root>/Scope1' */
  {
    RTWLogSignalInfo rt_ScopeSignalInfo;
    static int_T rt_ScopeSignalWidths[] = { 1 };

    static int_T rt_ScopeSignalNumDimensions[] = { 2 };

    static int_T rt_ScopeSignalDimensions[] = { 1, 1 };

    static void *rt_ScopeCurrSigDims[] = { (NULL), (NULL) };

    static int_T rt_ScopeCurrSigDimsSize[] = { 2, 2 };

    static const char_T *rt_ScopeSignalLabels[] = { "" };

    static char_T rt_ScopeSignalTitles[] = "";
    static int_T rt_ScopeSignalTitleLengths[] = { 0 };

    static boolean_T rt_ScopeSignalIsVarDims[] = { 0 };

    static int_T rt_ScopeSignalPlotStyles[] = { 1 };

    BuiltInDTypeId dTypes[1] = { SS_SINGLE };

    static char_T rt_ScopeBlockName[] = "serial_5_channels/Scope1";
    rt_ScopeSignalInfo.numSignals = 1;
    rt_ScopeSignalInfo.numCols = rt_ScopeSignalWidths;
    rt_ScopeSignalInfo.numDims = rt_ScopeSignalNumDimensions;
    rt_ScopeSignalInfo.dims = rt_ScopeSignalDimensions;
    rt_ScopeSignalInfo.isVarDims = rt_ScopeSignalIsVarDims;
    rt_ScopeSignalInfo.currSigDims = rt_ScopeCurrSigDims;
    rt_ScopeSignalInfo.currSigDimsSize = rt_ScopeCurrSigDimsSize;
    rt_ScopeSignalInfo.dataTypes = dTypes;
    rt_ScopeSignalInfo.complexSignals = (NULL);
    rt_ScopeSignalInfo.frameData = (NULL);
    rt_ScopeSignalInfo.labels.cptr = rt_ScopeSignalLabels;
    rt_ScopeSignalInfo.titles = rt_ScopeSignalTitles;
    rt_ScopeSignalInfo.titleLengths = rt_ScopeSignalTitleLengths;
    rt_ScopeSignalInfo.plotStyles = rt_ScopeSignalPlotStyles;
    rt_ScopeSignalInfo.blockNames.cptr = (NULL);
    rt_ScopeSignalInfo.stateNames.cptr = (NULL);
    rt_ScopeSignalInfo.crossMdlRef = (NULL);
    rt_ScopeSignalInfo.dataTypeConvert = (NULL);
    serial_5_channels_DW.Scope1_PWORK.LoggedData = rt_CreateStructLogVar(
      serial_5_channels_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(serial_5_channels_M),
      serial_5_channels_M->Timing.stepSize0,
      (&rtmGetErrorStatus(serial_5_channels_M)),
      "ScopeData1",
      0,
      0,
      1,
      0.001,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (serial_5_channels_DW.Scope1_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for Scope: '<Root>/Scope2' */
  {
    RTWLogSignalInfo rt_ScopeSignalInfo;
    static int_T rt_ScopeSignalWidths[] = { 1 };

    static int_T rt_ScopeSignalNumDimensions[] = { 2 };

    static int_T rt_ScopeSignalDimensions[] = { 1, 1 };

    static void *rt_ScopeCurrSigDims[] = { (NULL), (NULL) };

    static int_T rt_ScopeCurrSigDimsSize[] = { 2, 2 };

    static const char_T *rt_ScopeSignalLabels[] = { "" };

    static char_T rt_ScopeSignalTitles[] = "";
    static int_T rt_ScopeSignalTitleLengths[] = { 0 };

    static boolean_T rt_ScopeSignalIsVarDims[] = { 0 };

    static int_T rt_ScopeSignalPlotStyles[] = { 1 };

    BuiltInDTypeId dTypes[1] = { SS_SINGLE };

    static char_T rt_ScopeBlockName[] = "serial_5_channels/Scope2";
    rt_ScopeSignalInfo.numSignals = 1;
    rt_ScopeSignalInfo.numCols = rt_ScopeSignalWidths;
    rt_ScopeSignalInfo.numDims = rt_ScopeSignalNumDimensions;
    rt_ScopeSignalInfo.dims = rt_ScopeSignalDimensions;
    rt_ScopeSignalInfo.isVarDims = rt_ScopeSignalIsVarDims;
    rt_ScopeSignalInfo.currSigDims = rt_ScopeCurrSigDims;
    rt_ScopeSignalInfo.currSigDimsSize = rt_ScopeCurrSigDimsSize;
    rt_ScopeSignalInfo.dataTypes = dTypes;
    rt_ScopeSignalInfo.complexSignals = (NULL);
    rt_ScopeSignalInfo.frameData = (NULL);
    rt_ScopeSignalInfo.labels.cptr = rt_ScopeSignalLabels;
    rt_ScopeSignalInfo.titles = rt_ScopeSignalTitles;
    rt_ScopeSignalInfo.titleLengths = rt_ScopeSignalTitleLengths;
    rt_ScopeSignalInfo.plotStyles = rt_ScopeSignalPlotStyles;
    rt_ScopeSignalInfo.blockNames.cptr = (NULL);
    rt_ScopeSignalInfo.stateNames.cptr = (NULL);
    rt_ScopeSignalInfo.crossMdlRef = (NULL);
    rt_ScopeSignalInfo.dataTypeConvert = (NULL);
    serial_5_channels_DW.Scope2_PWORK.LoggedData = rt_CreateStructLogVar(
      serial_5_channels_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(serial_5_channels_M),
      serial_5_channels_M->Timing.stepSize0,
      (&rtmGetErrorStatus(serial_5_channels_M)),
      "ScopeData2",
      0,
      5000,
      1,
      0.001,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (serial_5_channels_DW.Scope2_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for Scope: '<Root>/Scope3' */
  {
    RTWLogSignalInfo rt_ScopeSignalInfo;
    static int_T rt_ScopeSignalWidths[] = { 1 };

    static int_T rt_ScopeSignalNumDimensions[] = { 2 };

    static int_T rt_ScopeSignalDimensions[] = { 1, 1 };

    static void *rt_ScopeCurrSigDims[] = { (NULL), (NULL) };

    static int_T rt_ScopeCurrSigDimsSize[] = { 2, 2 };

    static const char_T *rt_ScopeSignalLabels[] = { "" };

    static char_T rt_ScopeSignalTitles[] = "";
    static int_T rt_ScopeSignalTitleLengths[] = { 0 };

    static boolean_T rt_ScopeSignalIsVarDims[] = { 0 };

    static int_T rt_ScopeSignalPlotStyles[] = { 1 };

    BuiltInDTypeId dTypes[1] = { SS_SINGLE };

    static char_T rt_ScopeBlockName[] = "serial_5_channels/Scope3";
    rt_ScopeSignalInfo.numSignals = 1;
    rt_ScopeSignalInfo.numCols = rt_ScopeSignalWidths;
    rt_ScopeSignalInfo.numDims = rt_ScopeSignalNumDimensions;
    rt_ScopeSignalInfo.dims = rt_ScopeSignalDimensions;
    rt_ScopeSignalInfo.isVarDims = rt_ScopeSignalIsVarDims;
    rt_ScopeSignalInfo.currSigDims = rt_ScopeCurrSigDims;
    rt_ScopeSignalInfo.currSigDimsSize = rt_ScopeCurrSigDimsSize;
    rt_ScopeSignalInfo.dataTypes = dTypes;
    rt_ScopeSignalInfo.complexSignals = (NULL);
    rt_ScopeSignalInfo.frameData = (NULL);
    rt_ScopeSignalInfo.labels.cptr = rt_ScopeSignalLabels;
    rt_ScopeSignalInfo.titles = rt_ScopeSignalTitles;
    rt_ScopeSignalInfo.titleLengths = rt_ScopeSignalTitleLengths;
    rt_ScopeSignalInfo.plotStyles = rt_ScopeSignalPlotStyles;
    rt_ScopeSignalInfo.blockNames.cptr = (NULL);
    rt_ScopeSignalInfo.stateNames.cptr = (NULL);
    rt_ScopeSignalInfo.crossMdlRef = (NULL);
    rt_ScopeSignalInfo.dataTypeConvert = (NULL);
    serial_5_channels_DW.Scope3_PWORK.LoggedData = rt_CreateStructLogVar(
      serial_5_channels_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(serial_5_channels_M),
      serial_5_channels_M->Timing.stepSize0,
      (&rtmGetErrorStatus(serial_5_channels_M)),
      "ScopeData3",
      0,
      0,
      1,
      0.001,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (serial_5_channels_DW.Scope3_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for Scope: '<Root>/Scope4' */
  {
    RTWLogSignalInfo rt_ScopeSignalInfo;
    static int_T rt_ScopeSignalWidths[] = { 1 };

    static int_T rt_ScopeSignalNumDimensions[] = { 2 };

    static int_T rt_ScopeSignalDimensions[] = { 1, 1 };

    static void *rt_ScopeCurrSigDims[] = { (NULL), (NULL) };

    static int_T rt_ScopeCurrSigDimsSize[] = { 2, 2 };

    static const char_T *rt_ScopeSignalLabels[] = { "" };

    static char_T rt_ScopeSignalTitles[] = "";
    static int_T rt_ScopeSignalTitleLengths[] = { 0 };

    static boolean_T rt_ScopeSignalIsVarDims[] = { 0 };

    static int_T rt_ScopeSignalPlotStyles[] = { 1 };

    BuiltInDTypeId dTypes[1] = { SS_SINGLE };

    static char_T rt_ScopeBlockName[] = "serial_5_channels/Scope4";
    rt_ScopeSignalInfo.numSignals = 1;
    rt_ScopeSignalInfo.numCols = rt_ScopeSignalWidths;
    rt_ScopeSignalInfo.numDims = rt_ScopeSignalNumDimensions;
    rt_ScopeSignalInfo.dims = rt_ScopeSignalDimensions;
    rt_ScopeSignalInfo.isVarDims = rt_ScopeSignalIsVarDims;
    rt_ScopeSignalInfo.currSigDims = rt_ScopeCurrSigDims;
    rt_ScopeSignalInfo.currSigDimsSize = rt_ScopeCurrSigDimsSize;
    rt_ScopeSignalInfo.dataTypes = dTypes;
    rt_ScopeSignalInfo.complexSignals = (NULL);
    rt_ScopeSignalInfo.frameData = (NULL);
    rt_ScopeSignalInfo.labels.cptr = rt_ScopeSignalLabels;
    rt_ScopeSignalInfo.titles = rt_ScopeSignalTitles;
    rt_ScopeSignalInfo.titleLengths = rt_ScopeSignalTitleLengths;
    rt_ScopeSignalInfo.plotStyles = rt_ScopeSignalPlotStyles;
    rt_ScopeSignalInfo.blockNames.cptr = (NULL);
    rt_ScopeSignalInfo.stateNames.cptr = (NULL);
    rt_ScopeSignalInfo.crossMdlRef = (NULL);
    rt_ScopeSignalInfo.dataTypeConvert = (NULL);
    serial_5_channels_DW.Scope4_PWORK.LoggedData = rt_CreateStructLogVar(
      serial_5_channels_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(serial_5_channels_M),
      serial_5_channels_M->Timing.stepSize0,
      (&rtmGetErrorStatus(serial_5_channels_M)),
      "ScopeData4",
      0,
      0,
      1,
      0.001,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (serial_5_channels_DW.Scope4_PWORK.LoggedData == (NULL))
      return;
  }
}

/* Model terminate function */
void serial_5_channels_terminate(void)
{
  /* (no terminate code required) */
}
