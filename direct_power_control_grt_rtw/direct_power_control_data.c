/*
 * direct_power_control_data.c
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

#include "direct_power_control.h"
#include "direct_power_control_private.h"

/* Block parameters (auto storage) */
P_direct_power_control_T direct_power_control_P = {
  0.00094,                             /* Variable: C
                                        * Referenced by: '<S5>/Gain'
                                        */
  80.0,                                /* Variable: Hp
                                        * Referenced by: '<S8>/dp'
                                        */
  80.0,                                /* Variable: Hq
                                        * Referenced by: '<S8>/dq'
                                        */
  0.15,                                /* Variable: Ka
                                        * Referenced by:
                                        *   '<S24>/Gain7'
                                        *   '<S24>/Gain9'
                                        */
  4.7,                                 /* Variable: L
                                        * Referenced by: '<S16>/Gain1'
                                        */
  0.0027,                              /* Variable: Ls
                                        * Referenced by:
                                        *   '<S24>/Gain2'
                                        *   '<S24>/Gain3'
                                        *   '<S24>/Gain4'
                                        *   '<S24>/Gain6'
                                        */
  1.137,                               /* Variable: Rs
                                        * Referenced by:
                                        *   '<S24>/Gain'
                                        *   '<S24>/Gain1'
                                        */
  311.0,                               /* Variable: U
                                        * Referenced by:
                                        *   '<S1>/Ua'
                                        *   '<S1>/Ub'
                                        *   '<S1>/Uc'
                                        */
  24.0,                                /* Variable: Udcref
                                        * Referenced by: '<Root>/Udcref'
                                        */
  4.0,                                 /* Variable: p
                                        * Referenced by:
                                        *   '<S4>/Gain1'
                                        *   '<S24>/Gain5'
                                        *   '<S24>/Gain8'
                                        */
  0.10471975511965977,                 /* Variable: rpm2radps
                                        * Referenced by: '<S4>/Gain4'
                                        */

  /*  Variable: sp00
   * Referenced by: '<S13>/Constant2'
   */
  { 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  /*  Variable: sp01
   * Referenced by: '<S13>/Constant3'
   */
  { 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 0.0 },

  /*  Variable: sp10
   * Referenced by: '<S13>/Constant'
   */
  { 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 1.0, 1.0, 1.0, 0.0 },

  /*  Variable: sp11
   * Referenced by: '<S13>/Constant1'
   */
  { 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0,
    0.0, 0.0, 1.0, 1.0, 0.0, 0.0 },
  314.15926535897933,                  /* Variable: w
                                        * Referenced by:
                                        *   '<S1>/Ua'
                                        *   '<S1>/Ub'
                                        *   '<S1>/Uc'
                                        */
  0.01,                                /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S9>/Integral Gain'
                                        */
  0.1,                                 /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S9>/Proportional Gain'
                                        */
  100.0,                               /* Mask Parameter: Ramp_X0
                                        * Referenced by: '<S7>/Constant1'
                                        */
  50.0,                                /* Mask Parameter: Ramp_slope
                                        * Referenced by: '<S7>/Step'
                                        */
  0.0,                                 /* Mask Parameter: Ramp_start
                                        * Referenced by:
                                        *   '<S7>/Constant'
                                        *   '<S7>/Step'
                                        */
  -0.021276595744680854,               /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S5>/Transfer Fcn'
                                        */
  0.21276595744680851,                 /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S5>/Transfer Fcn'
                                        */
  -0.021276595744680854,               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<S5>/Transfer Fcn1'
                                        */
  0.21276595744680851,                 /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<S5>/Transfer Fcn1'
                                        */
  -0.021276595744680854,               /* Computed Parameter: TransferFcn2_A
                                        * Referenced by: '<S5>/Transfer Fcn2'
                                        */
  0.21276595744680851,                 /* Computed Parameter: TransferFcn2_C
                                        * Referenced by: '<S5>/Transfer Fcn2'
                                        */

  /*  Expression: [3/2 0 ; sqrt(3)/2 sqrt(3)]
   * Referenced by: '<S17>/Gain1'
   */
  { 1.5, 0.8660254037844386, 0.0, 1.7320508075688772 },
  0.816496580927726,                   /* Expression: sqrt(2/3)
                                        * Referenced by: '<S17>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Step'
                                        */
  500.0,                               /* Expression: 500
                                        * Referenced by: '<S2>/RPM'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S9>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/qref'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S18>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S18>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Ua'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Ua'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Ub'
                                        */
  -2.0943951023931953,                 /* Expression: -2*pi/3
                                        * Referenced by: '<S1>/Ub'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Uc'
                                        */
  -4.1887902047863905,                 /* Expression: -4*pi/3
                                        * Referenced by: '<S1>/Uc'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Integrator'
                                        */

  /*  Expression: [1 1/2 ; 0 sqrt(3)/2]
   * Referenced by: '<S19>/Gain'
   */
  { 1.0, 0.0, 0.5, 0.8660254037844386 },
  0.816496580927726,                   /* Expression: sqrt(2/3)
                                        * Referenced by: '<S19>/Gain1'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S20>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S20>/Switch'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S8>/dp'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/dp'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S8>/dq'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/dq'
                                        */
  0.5,                                 /* Expression: 1/2
                                        * Referenced by: '<S16>/Gain2'
                                        */
  0.66666666666666663,                 /* Expression: 2/3
                                        * Referenced by: '<S16>/Gain'
                                        */
  0.57735026918962584,                 /* Expression: 1/sqrt(3)
                                        * Referenced by: '<S16>/Gain3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/iload'
                                        */
  0.33333333333333331,                 /* Expression: 1/3
                                        * Referenced by: '<S5>/Gain1'
                                        */
  0U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<S2>/Manual Switch'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting_h
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  0U                                   /* Computed Parameter: ManualSwitch1_CurrentSetting
                                        * Referenced by: '<S3>/Manual Switch1'
                                        */
};
