/*
 * direct_power_control.h
 *
 * Code generation for model "direct_power_control".
 *
 * Model version              : 1.297
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Thu Mar 29 19:29:51 2018
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_direct_power_control_h_
#define RTW_HEADER_direct_power_control_h_
#include <stddef.h>
#include <math.h>
#include <float.h>
#include <string.h>
#ifndef direct_power_control_COMMON_INCLUDES_
# define direct_power_control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* direct_power_control_COMMON_INCLUDES_ */

#include "direct_power_control_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Ia;                           /* '<S5>/Transfer Fcn' */
  real_T Ia_k;                         /* '<S5>/Transfer Fcn1' */
  real_T TransferFcn2;                 /* '<S5>/Transfer Fcn2' */
  real_T Gain[2];                      /* '<S17>/Gain' */
  real_T Integrator[2];                /* '<S16>/Integrator' */
  real_T Product4;                     /* '<S15>/Product4' */
  real_T Product5;                     /* '<S15>/Product5' */
  real_T Gain_g;                       /* '<S5>/Gain' */
  real_T Sum;                          /* '<S8>/Sum' */
  real_T Sum1;                         /* '<S8>/Sum1' */
  real_T Divide;                       /* '<S18>/Divide' */
  real_T TrigonometricFunction;        /* '<S18>/Trigonometric Function' */
  real_T Switch;                       /* '<S18>/Switch' */
  real_T Sum2;                         /* '<S24>/Sum2' */
  real_T Sum4;                         /* '<S24>/Sum4' */
  real_T ManualSwitch[3];              /* '<Root>/Manual Switch' */
  real_T Gain1[2];                     /* '<S19>/Gain1' */
  real_T Divide_n;                     /* '<S20>/Divide' */
  real_T TrigonometricFunction_l;      /* '<S20>/Trigonometric Function' */
  real_T Switch_k;                     /* '<S20>/Switch' */
  real_T ManualSwitch1;                /* '<S3>/Manual Switch1' */
  real_T dp;                           /* '<S8>/dp' */
  real_T dq;                           /* '<S8>/dq' */
  real_T IntegralGain;                 /* '<S9>/Integral Gain' */
  real_T usalpha;                      /* '<S16>/Product' */
  real_T usbeta;                       /* '<S16>/Product1' */
  real_T Sum_e[2];                     /* '<S16>/Sum' */
  real_T Gain8;                        /* '<S24>/Gain8' */
  real_T Gain1_n;                      /* '<S4>/Gain1' */
  real_T Sum_n;                        /* '<S5>/Sum' */
  real_T Sum2_g;                       /* '<S5>/Sum2' */
  real_T Sum3;                         /* '<S5>/Sum3' */
  real_T Sum4_e;                       /* '<S5>/Sum4' */
  real_T dq_j[2];                      /* '<S22>/MATLAB Function' */
  real_T y;                            /* '<S12>/MATLAB Function' */
  real_T Sa;                           /* '<S13>/MATLAB Function' */
  real_T Sb;                           /* '<S13>/MATLAB Function' */
  real_T Sc;                           /* '<S13>/MATLAB Function' */
} B_direct_power_control_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T TimeStampA;                   /* '<S24>/Derivative1' */
  real_T LastUAtTimeA;                 /* '<S24>/Derivative1' */
  real_T TimeStampB;                   /* '<S24>/Derivative1' */
  real_T LastUAtTimeB;                 /* '<S24>/Derivative1' */
  real_T TimeStampA_m;                 /* '<S24>/Derivative' */
  real_T LastUAtTimeA_j;               /* '<S24>/Derivative' */
  real_T TimeStampB_g;                 /* '<S24>/Derivative' */
  real_T LastUAtTimeB_a;               /* '<S24>/Derivative' */
  real_T TimeStampA_p;                 /* '<S16>/Derivative' */
  real_T LastUAtTimeA_a[2];            /* '<S16>/Derivative' */
  real_T TimeStampB_c;                 /* '<S16>/Derivative' */
  real_T LastUAtTimeB_n[2];            /* '<S16>/Derivative' */
  struct {
    void *LoggedData;
  } we_PWORK;                          /* '<Root>/we' */

  struct {
    void *LoggedData;
  } Sourcecurrents_PWORK;              /* '<Root>/Source currents' */

  struct {
    void *LoggedData;
  } power_PWORK;                       /* '<Root>/power ' */

  struct {
    void *LoggedData;
  } err_p_PWORK;                       /* '<Root>/err_p' */

  struct {
    void *LoggedData;
  } err_q_PWORK;                       /* '<Root>/err_q' */

  struct {
    void *LoggedData;
  } Udc_PWORK;                         /* '<Root>/Udc' */

  struct {
    void *LoggedData;
  } gamma_PWORK;                       /* '<Root>/gamma' */

  struct {
    void *LoggedData;
  } Sourcevoltage_PWORK;               /* '<Root>/Source voltage ' */

  struct {
    void *LoggedData;
  } Switchtable_PWORK;                 /* '<S13>/Switch table' */

  struct {
    void *LoggedData;
  } binaryword_PWORK;                  /* '<S13>/binary word' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S16>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S16>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S16>/Scope2' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_d;                    /* '<S18>/Scope1' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<S18>/Scope3' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_k;                    /* '<S20>/Scope1' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_e;                    /* '<S20>/Scope3' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_m;                    /* '<S4>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK_a;                     /* '<S24>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_i;                    /* '<S24>/Scope1' */

  boolean_T dp_Mode;                   /* '<S8>/dp' */
  boolean_T dq_Mode;                   /* '<S8>/dq' */
} DW_direct_power_control_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Ia;                           /* '<S5>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE;          /* '<S5>/Transfer Fcn1' */
  real_T TransferFcn2_CSTATE;          /* '<S5>/Transfer Fcn2' */
  real_T Integrator_CSTATE[2];         /* '<S16>/Integrator' */
  real_T Integrator_CSTATE_e;          /* '<S5>/Integrator' */
  real_T Integrator_CSTATE_c;          /* '<S9>/Integrator' */
  real_T Integrator_CSTATE_b;          /* '<S4>/Integrator' */
} X_direct_power_control_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Ia;                           /* '<S5>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE;          /* '<S5>/Transfer Fcn1' */
  real_T TransferFcn2_CSTATE;          /* '<S5>/Transfer Fcn2' */
  real_T Integrator_CSTATE[2];         /* '<S16>/Integrator' */
  real_T Integrator_CSTATE_e;          /* '<S5>/Integrator' */
  real_T Integrator_CSTATE_c;          /* '<S9>/Integrator' */
  real_T Integrator_CSTATE_b;          /* '<S4>/Integrator' */
} XDot_direct_power_control_T;

/* State disabled  */
typedef struct {
  boolean_T Ia;                        /* '<S5>/Transfer Fcn' */
  boolean_T TransferFcn1_CSTATE;       /* '<S5>/Transfer Fcn1' */
  boolean_T TransferFcn2_CSTATE;       /* '<S5>/Transfer Fcn2' */
  boolean_T Integrator_CSTATE[2];      /* '<S16>/Integrator' */
  boolean_T Integrator_CSTATE_e;       /* '<S5>/Integrator' */
  boolean_T Integrator_CSTATE_c;       /* '<S9>/Integrator' */
  boolean_T Integrator_CSTATE_b;       /* '<S4>/Integrator' */
} XDis_direct_power_control_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (auto storage) */
struct P_direct_power_control_T_ {
  real_T C;                            /* Variable: C
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T Hp;                           /* Variable: Hp
                                        * Referenced by: '<S8>/dp'
                                        */
  real_T Hq;                           /* Variable: Hq
                                        * Referenced by: '<S8>/dq'
                                        */
  real_T Ka;                           /* Variable: Ka
                                        * Referenced by:
                                        *   '<S24>/Gain7'
                                        *   '<S24>/Gain9'
                                        */
  real_T L;                            /* Variable: L
                                        * Referenced by: '<S16>/Gain1'
                                        */
  real_T Ls;                           /* Variable: Ls
                                        * Referenced by:
                                        *   '<S24>/Gain2'
                                        *   '<S24>/Gain3'
                                        *   '<S24>/Gain4'
                                        *   '<S24>/Gain6'
                                        */
  real_T Rs;                           /* Variable: Rs
                                        * Referenced by:
                                        *   '<S24>/Gain'
                                        *   '<S24>/Gain1'
                                        */
  real_T U;                            /* Variable: U
                                        * Referenced by:
                                        *   '<S1>/Ua'
                                        *   '<S1>/Ub'
                                        *   '<S1>/Uc'
                                        */
  real_T Udcref;                       /* Variable: Udcref
                                        * Referenced by: '<Root>/Udcref'
                                        */
  real_T p;                            /* Variable: p
                                        * Referenced by:
                                        *   '<S4>/Gain1'
                                        *   '<S24>/Gain5'
                                        *   '<S24>/Gain8'
                                        */
  real_T rpm2radps;                    /* Variable: rpm2radps
                                        * Referenced by: '<S4>/Gain4'
                                        */
  real_T sp00[36];                     /* Variable: sp00
                                        * Referenced by: '<S13>/Constant2'
                                        */
  real_T sp01[36];                     /* Variable: sp01
                                        * Referenced by: '<S13>/Constant3'
                                        */
  real_T sp10[36];                     /* Variable: sp10
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T sp11[36];                     /* Variable: sp11
                                        * Referenced by: '<S13>/Constant1'
                                        */
  real_T w;                            /* Variable: w
                                        * Referenced by:
                                        *   '<S1>/Ua'
                                        *   '<S1>/Ub'
                                        *   '<S1>/Uc'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S9>/Integral Gain'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S9>/Proportional Gain'
                                        */
  real_T Ramp_X0;                      /* Mask Parameter: Ramp_X0
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Ramp_slope;                   /* Mask Parameter: Ramp_slope
                                        * Referenced by: '<S7>/Step'
                                        */
  real_T Ramp_start;                   /* Mask Parameter: Ramp_start
                                        * Referenced by:
                                        *   '<S7>/Constant'
                                        *   '<S7>/Step'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S5>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S5>/Transfer Fcn'
                                        */
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<S5>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<S5>/Transfer Fcn1'
                                        */
  real_T TransferFcn2_A;               /* Computed Parameter: TransferFcn2_A
                                        * Referenced by: '<S5>/Transfer Fcn2'
                                        */
  real_T TransferFcn2_C;               /* Computed Parameter: TransferFcn2_C
                                        * Referenced by: '<S5>/Transfer Fcn2'
                                        */
  real_T Gain1_Gain[4];                /* Expression: [3/2 0 ; sqrt(3)/2 sqrt(3)]
                                        * Referenced by: '<S17>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: sqrt(2/3)
                                        * Referenced by: '<S17>/Gain'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S16>/Integrator'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S7>/Step'
                                        */
  real_T RPM_Value;                    /* Expression: 500
                                        * Referenced by: '<S2>/RPM'
                                        */
  real_T Integrator_IC_a;              /* Expression: 0
                                        * Referenced by: '<S5>/Integrator'
                                        */
  real_T Integrator_IC_f;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S9>/Integrator'
                                        */
  real_T qref_Value;                   /* Expression: 0
                                        * Referenced by: '<S8>/qref'
                                        */
  real_T Constant_Value;               /* Expression: pi
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S18>/Switch'
                                        */
  real_T Ua_Bias;                      /* Expression: 0
                                        * Referenced by: '<S1>/Ua'
                                        */
  real_T Ua_Phase;                     /* Expression: 0
                                        * Referenced by: '<S1>/Ua'
                                        */
  real_T Ub_Bias;                      /* Expression: 0
                                        * Referenced by: '<S1>/Ub'
                                        */
  real_T Ub_Phase;                     /* Expression: -2*pi/3
                                        * Referenced by: '<S1>/Ub'
                                        */
  real_T Uc_Bias;                      /* Expression: 0
                                        * Referenced by: '<S1>/Uc'
                                        */
  real_T Uc_Phase;                     /* Expression: -4*pi/3
                                        * Referenced by: '<S1>/Uc'
                                        */
  real_T Integrator_IC_p;              /* Expression: 0
                                        * Referenced by: '<S4>/Integrator'
                                        */
  real_T Gain_Gain_f[4];               /* Expression: [1 1/2 ; 0 sqrt(3)/2]
                                        * Referenced by: '<S19>/Gain'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: sqrt(2/3)
                                        * Referenced by: '<S19>/Gain1'
                                        */
  real_T Constant_Value_m;             /* Expression: pi
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T Switch_Threshold_m;           /* Expression: 0
                                        * Referenced by: '<S20>/Switch'
                                        */
  real_T dp_YOn;                       /* Expression: 1
                                        * Referenced by: '<S8>/dp'
                                        */
  real_T dp_YOff;                      /* Expression: 0
                                        * Referenced by: '<S8>/dp'
                                        */
  real_T dq_YOn;                       /* Expression: 1
                                        * Referenced by: '<S8>/dq'
                                        */
  real_T dq_YOff;                      /* Expression: 0
                                        * Referenced by: '<S8>/dq'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/2
                                        * Referenced by: '<S16>/Gain2'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 2/3
                                        * Referenced by: '<S16>/Gain'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1/sqrt(3)
                                        * Referenced by: '<S16>/Gain3'
                                        */
  real_T iload_Value;                  /* Expression: 0
                                        * Referenced by: '<Root>/iload'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: 1/3
                                        * Referenced by: '<S5>/Gain1'
                                        */
  uint8_T ManualSwitch_CurrentSetting; /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<S2>/Manual Switch'
                                        */
  uint8_T ManualSwitch_CurrentSetting_h;/* Computed Parameter: ManualSwitch_CurrentSetting_h
                                         * Referenced by: '<Root>/Manual Switch'
                                         */
  uint8_T ManualSwitch1_CurrentSetting;/* Computed Parameter: ManualSwitch1_CurrentSetting
                                        * Referenced by: '<S3>/Manual Switch1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_direct_power_control_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    X_direct_power_control_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[8];
    real_T odeF[3][8];
    ODE3_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_direct_power_control_T direct_power_control_P;

/* Block signals (auto storage) */
extern B_direct_power_control_T direct_power_control_B;

/* Continuous states (auto storage) */
extern X_direct_power_control_T direct_power_control_X;

/* Block states (auto storage) */
extern DW_direct_power_control_T direct_power_control_DW;

/* Model entry point functions */
extern void direct_power_control_initialize(void);
extern void direct_power_control_step(void);
extern void direct_power_control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_direct_power_control_T *const direct_power_control_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'direct_power_control'
 * '<S1>'   : 'direct_power_control/Source bloc'
 * '<S2>'   : 'direct_power_control/Speed generation'
 * '<S3>'   : 'direct_power_control/Udc controller'
 * '<S4>'   : 'direct_power_control/Wind turbine model1'
 * '<S5>'   : 'direct_power_control/plan:rectifier'
 * '<S6>'   : 'direct_power_control/powergui'
 * '<S7>'   : 'direct_power_control/Speed generation/Ramp'
 * '<S8>'   : 'direct_power_control/Udc controller/Direct Power controller'
 * '<S9>'   : 'direct_power_control/Udc controller/PID Controller'
 * '<S10>'  : 'direct_power_control/Udc controller/Power Estimation '
 * '<S11>'  : 'direct_power_control/Udc controller/Power Estimator 1'
 * '<S12>'  : 'direct_power_control/Udc controller/Sector selection '
 * '<S13>'  : 'direct_power_control/Udc controller/Direct Power controller/Switching Table '
 * '<S14>'  : 'direct_power_control/Udc controller/Direct Power controller/Switching Table /MATLAB Function'
 * '<S15>'  : 'direct_power_control/Udc controller/Power Estimation /Power Estimator '
 * '<S16>'  : 'direct_power_control/Udc controller/Power Estimation /Virtual flux estimator'
 * '<S17>'  : 'direct_power_control/Udc controller/Power Estimation /Virtual flux estimator/abc to alpha-beta'
 * '<S18>'  : 'direct_power_control/Udc controller/Power Estimation /Virtual flux estimator/gamma'
 * '<S19>'  : 'direct_power_control/Udc controller/Power Estimator 1/gamma_estimator '
 * '<S20>'  : 'direct_power_control/Udc controller/Power Estimator 1/gamma_estimator /gamma1'
 * '<S21>'  : 'direct_power_control/Udc controller/Sector selection /MATLAB Function'
 * '<S22>'  : 'direct_power_control/Wind turbine model1/a-b-c to dq'
 * '<S23>'  : 'direct_power_control/Wind turbine model1/d-q to a-b-c'
 * '<S24>'  : 'direct_power_control/Wind turbine model1/synchronous machine'
 * '<S25>'  : 'direct_power_control/Wind turbine model1/a-b-c to dq/MATLAB Function'
 * '<S26>'  : 'direct_power_control/Wind turbine model1/d-q to a-b-c/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_direct_power_control_h_ */
