/*
 * direct_power_control.c
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

/* Block signals (auto storage) */
B_direct_power_control_T direct_power_control_B;

/* Continuous states */
X_direct_power_control_T direct_power_control_X;

/* Block states (auto storage) */
DW_direct_power_control_T direct_power_control_DW;

/* Real-time model */
RT_MODEL_direct_power_control_T direct_power_control_M_;
RT_MODEL_direct_power_control_T *const direct_power_control_M =
  &direct_power_control_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 8;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  direct_power_control_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  direct_power_control_step();
  direct_power_control_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  direct_power_control_step();
  direct_power_control_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void direct_power_control_step(void)
{
  /* local block i/o variables */
  real_T rtb_Clock;
  if (rtmIsMajorTimeStep(direct_power_control_M)) {
    /* set solver stop time */
    if (!(direct_power_control_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&direct_power_control_M->solverInfo,
                            ((direct_power_control_M->Timing.clockTickH0 + 1) *
        direct_power_control_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&direct_power_control_M->solverInfo,
                            ((direct_power_control_M->Timing.clockTick0 + 1) *
        direct_power_control_M->Timing.stepSize0 +
        direct_power_control_M->Timing.clockTickH0 *
        direct_power_control_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(direct_power_control_M)) {
    direct_power_control_M->Timing.t[0] = rtsiGetT
      (&direct_power_control_M->solverInfo);
  }

  {
    real_T *lastU;
    real_T (*lastU_0)[2];
    real_T up;
    real_T down;
    real_T rtb_Gain4_c;
    real_T rtb_Gain5;
    real_T rtb_Sum2_p;
    real_T rtb_Gain1_b;
    if (rtmIsMajorTimeStep(direct_power_control_M)) {
    }

    /* TransferFcn: '<S5>/Transfer Fcn' */
    direct_power_control_B.Ia = 0.0;
    direct_power_control_B.Ia += direct_power_control_P.TransferFcn_C *
      direct_power_control_X.Ia;

    /* TransferFcn: '<S5>/Transfer Fcn1' */
    direct_power_control_B.Ia_k = 0.0;
    direct_power_control_B.Ia_k += direct_power_control_P.TransferFcn1_C *
      direct_power_control_X.TransferFcn1_CSTATE;

    /* TransferFcn: '<S5>/Transfer Fcn2' */
    direct_power_control_B.TransferFcn2 = 0.0;
    direct_power_control_B.TransferFcn2 += direct_power_control_P.TransferFcn2_C
      * direct_power_control_X.TransferFcn2_CSTATE;
    if (rtmIsMajorTimeStep(direct_power_control_M)) {
      /* Scope: '<Root>/Source currents' */
      if (rtmIsMajorTimeStep(direct_power_control_M)) {
        real_T u[4];
        u[0] = (((direct_power_control_M->Timing.clockTick1+
                  direct_power_control_M->Timing.clockTickH1* 4294967296.0)) *
                1.0E-5);
        u[1] = direct_power_control_B.Ia;
        u[2] = direct_power_control_B.Ia_k;
        u[3] = direct_power_control_B.TransferFcn2;
        rt_UpdateLogVar((LogVar *)
                        direct_power_control_DW.Sourcecurrents_PWORK.LoggedData,
                        u, 0);
      }
    }

    /* Gain: '<S17>/Gain' incorporates:
     *  Gain: '<S17>/Gain1'
     *  SignalConversion: '<S17>/TmpSignal ConversionAtGain1Inport1'
     */
    direct_power_control_B.Gain[0] = (direct_power_control_P.Gain1_Gain[0] *
      direct_power_control_B.Ia + direct_power_control_P.Gain1_Gain[2] *
      direct_power_control_B.Ia_k) * direct_power_control_P.Gain_Gain;
    direct_power_control_B.Gain[1] = (direct_power_control_P.Gain1_Gain[1] *
      direct_power_control_B.Ia + direct_power_control_P.Gain1_Gain[3] *
      direct_power_control_B.Ia_k) * direct_power_control_P.Gain_Gain;

    /* Integrator: '<S16>/Integrator' */
    direct_power_control_B.Integrator[0] =
      direct_power_control_X.Integrator_CSTATE[0];
    direct_power_control_B.Integrator[1] =
      direct_power_control_X.Integrator_CSTATE[1];

    /* Clock: '<S7>/Clock' */
    rtb_Clock = direct_power_control_M->Timing.t[0];

    /* ManualSwitch: '<S2>/Manual Switch' incorporates:
     *  Constant: '<S2>/RPM'
     *  Constant: '<S7>/Constant'
     *  Constant: '<S7>/Constant1'
     *  Product: '<S7>/Product'
     *  Sum: '<S7>/Output'
     *  Sum: '<S7>/Sum'
     */
    if (direct_power_control_P.ManualSwitch_CurrentSetting == 1) {
      /* Step: '<S7>/Step' */
      if (direct_power_control_M->Timing.t[0] <
          direct_power_control_P.Ramp_start) {
        rtb_Gain5 = direct_power_control_P.Step_Y0;
      } else {
        rtb_Gain5 = direct_power_control_P.Ramp_slope;
      }

      /* End of Step: '<S7>/Step' */
      rtb_Gain4_c = (rtb_Clock - direct_power_control_P.Ramp_start) * rtb_Gain5
        + direct_power_control_P.Ramp_X0;
    } else {
      rtb_Gain4_c = direct_power_control_P.RPM_Value;
    }

    /* End of ManualSwitch: '<S2>/Manual Switch' */

    /* Gain: '<S4>/Gain4' */
    rtb_Gain4_c *= direct_power_control_P.rpm2radps;

    /* Gain: '<S24>/Gain5' */
    rtb_Gain5 = direct_power_control_P.p * rtb_Gain4_c;

    /* Product: '<S15>/Product4' incorporates:
     *  Product: '<S15>/Product'
     *  Product: '<S15>/Product1'
     *  Sum: '<S15>/Sum'
     */
    direct_power_control_B.Product4 = (direct_power_control_B.Gain[1] *
      direct_power_control_B.Integrator[0] - direct_power_control_B.Integrator[1]
      * direct_power_control_B.Gain[0]) * rtb_Gain5;

    /* Product: '<S15>/Product5' incorporates:
     *  Product: '<S15>/Product2'
     *  Product: '<S15>/Product3'
     *  Sum: '<S15>/Sum1'
     */
    direct_power_control_B.Product5 = (direct_power_control_B.Integrator[0] *
      direct_power_control_B.Gain[0] + direct_power_control_B.Gain[1] *
      direct_power_control_B.Integrator[1]) * rtb_Gain5;
    if (rtmIsMajorTimeStep(direct_power_control_M)) {
    }

    /* Gain: '<S5>/Gain' incorporates:
     *  Integrator: '<S5>/Integrator'
     */
    direct_power_control_B.Gain_g = 1.0 / direct_power_control_P.C *
      direct_power_control_X.Integrator_CSTATE_e;

    /* Sum: '<S3>/Sum2' incorporates:
     *  Constant: '<Root>/Udcref'
     */
    rtb_Sum2_p = direct_power_control_P.Udcref - direct_power_control_B.Gain_g;

    /* Sum: '<S8>/Sum' incorporates:
     *  Gain: '<S9>/Proportional Gain'
     *  Integrator: '<S9>/Integrator'
     *  Product: '<S3>/Product'
     *  Sum: '<S9>/Sum'
     */
    direct_power_control_B.Sum = (direct_power_control_P.PIDController_P *
      rtb_Sum2_p + direct_power_control_X.Integrator_CSTATE_c) *
      direct_power_control_B.Gain_g - direct_power_control_B.Product4;
    if (rtmIsMajorTimeStep(direct_power_control_M)) {
      /* Scope: '<Root>/err_p' */
      if (rtmIsMajorTimeStep(direct_power_control_M)) {
        real_T u[2];
        u[0] = (((direct_power_control_M->Timing.clockTick1+
                  direct_power_control_M->Timing.clockTickH1* 4294967296.0)) *
                1.0E-5);
        u[1] = direct_power_control_B.Sum;
        rt_UpdateLogVar((LogVar *)direct_power_control_DW.err_p_PWORK.LoggedData,
                        u, 0);
      }
    }

    /* Sum: '<S8>/Sum1' incorporates:
     *  Constant: '<S8>/qref'
     */
    direct_power_control_B.Sum1 = direct_power_control_P.qref_Value -
      direct_power_control_B.Product5;
    if (rtmIsMajorTimeStep(direct_power_control_M)) {
      /* Scope: '<Root>/err_q' */
      if (rtmIsMajorTimeStep(direct_power_control_M)) {
        real_T u[2];
        u[0] = (((direct_power_control_M->Timing.clockTick1+
                  direct_power_control_M->Timing.clockTickH1* 4294967296.0)) *
                1.0E-5);
        u[1] = direct_power_control_B.Sum1;
        rt_UpdateLogVar((LogVar *)direct_power_control_DW.err_q_PWORK.LoggedData,
                        u, 0);
      }

      /* Scope: '<Root>/Udc' */
      if (rtmIsMajorTimeStep(direct_power_control_M)) {
        real_T u[2];
        u[0] = (((direct_power_control_M->Timing.clockTick1+
                  direct_power_control_M->Timing.clockTickH1* 4294967296.0)) *
                1.0E-5);
        u[1] = direct_power_control_B.Gain_g;
        rt_UpdateLogVar((LogVar *)direct_power_control_DW.Udc_PWORK.LoggedData,
                        u, 0);
      }
    }

    /* Product: '<S18>/Divide' */
    direct_power_control_B.Divide = direct_power_control_B.Integrator[1] /
      direct_power_control_B.Integrator[0];

    /* Trigonometry: '<S18>/Trigonometric Function' */
    direct_power_control_B.TrigonometricFunction = atan
      (direct_power_control_B.Divide);

    /* Switch: '<S18>/Switch' incorporates:
     *  Constant: '<S18>/Constant'
     *  Sum: '<S18>/Sum'
     */
    if (direct_power_control_B.Integrator[0] >
        direct_power_control_P.Switch_Threshold) {
      direct_power_control_B.Switch =
        direct_power_control_B.TrigonometricFunction;
    } else {
      direct_power_control_B.Switch =
        direct_power_control_B.TrigonometricFunction +
        direct_power_control_P.Constant_Value;
    }

    /* End of Switch: '<S18>/Switch' */

    /* MATLAB Function: '<S22>/MATLAB Function' incorporates:
     *  Integrator: '<S4>/Integrator'
     *  SignalConversion: '<S25>/TmpSignal ConversionAt SFunction Inport1'
     */
    /* MATLAB Function 'Wind turbine model1/a-b-c to dq/MATLAB Function': '<S25>:1' */
    /*  transformation from d-q to a-b-c */
    /*  based on "COMMANDE VECTORIELLE DES MACHINES ASYNCHRONES & SYNCHRONES"  */
    /*  5ème Année GE Option ISIP INSA LYON */
    /*  http://docinsa.insa-lyon.fr/polycop/download.php?id=160503&id2=0  */
    /* '<S25>:1:10' */
    /* '<S25>:1:11' */
    /* '<S25>:1:12' */
    /* '<S25>:1:14' */
    /* '<S25>:1:15' */
    /* '<S25>:1:17' */
    direct_power_control_B.dq_j[0] = (cos
      (direct_power_control_X.Integrator_CSTATE_b - 2.0943951023931953) *
      direct_power_control_B.Ia_k + cos
      (direct_power_control_X.Integrator_CSTATE_b) * direct_power_control_B.Ia)
      + cos(direct_power_control_X.Integrator_CSTATE_b + 2.0943951023931953) *
      direct_power_control_B.TransferFcn2;

    /* '<S25>:1:18' */
    direct_power_control_B.dq_j[1] = (-sin
      (direct_power_control_X.Integrator_CSTATE_b) * direct_power_control_B.Ia -
      sin(direct_power_control_X.Integrator_CSTATE_b - 2.0943951023931953) *
      direct_power_control_B.Ia_k) - sin
      (direct_power_control_X.Integrator_CSTATE_b + 2.0943951023931953) *
      direct_power_control_B.TransferFcn2;

    /* '<S25>:1:21' */
    direct_power_control_B.dq_j[0] *= 0.816496580927726;
    direct_power_control_B.dq_j[1] *= 0.816496580927726;

    /* Derivative: '<S24>/Derivative1' */
    if ((direct_power_control_DW.TimeStampA >= direct_power_control_M->Timing.t
         [0]) && (direct_power_control_DW.TimeStampB >=
                  direct_power_control_M->Timing.t[0])) {
      rtb_Gain1_b = 0.0;
    } else {
      rtb_Gain1_b = direct_power_control_DW.TimeStampA;
      lastU = &direct_power_control_DW.LastUAtTimeA;
      if (direct_power_control_DW.TimeStampA <
          direct_power_control_DW.TimeStampB) {
        if (direct_power_control_DW.TimeStampB <
            direct_power_control_M->Timing.t[0]) {
          rtb_Gain1_b = direct_power_control_DW.TimeStampB;
          lastU = &direct_power_control_DW.LastUAtTimeB;
        }
      } else {
        if (direct_power_control_DW.TimeStampA >=
            direct_power_control_M->Timing.t[0]) {
          rtb_Gain1_b = direct_power_control_DW.TimeStampB;
          lastU = &direct_power_control_DW.LastUAtTimeB;
        }
      }

      rtb_Gain1_b = (direct_power_control_B.dq_j[0] - *lastU) /
        (direct_power_control_M->Timing.t[0] - rtb_Gain1_b);
    }

    /* End of Derivative: '<S24>/Derivative1' */

    /* Sum: '<S24>/Sum2' incorporates:
     *  Gain: '<S24>/Gain'
     *  Gain: '<S24>/Gain2'
     *  Gain: '<S24>/Gain4'
     *  Product: '<S24>/Product'
     *  Sum: '<S24>/Sum'
     */
    direct_power_control_B.Sum2 = (direct_power_control_P.Rs *
      direct_power_control_B.dq_j[0] + direct_power_control_P.Ls * rtb_Gain1_b)
      - direct_power_control_B.dq_j[1] * rtb_Gain5 * direct_power_control_P.Ls;

    /* Derivative: '<S24>/Derivative' */
    if ((direct_power_control_DW.TimeStampA_m >=
         direct_power_control_M->Timing.t[0]) &&
        (direct_power_control_DW.TimeStampB_g >=
         direct_power_control_M->Timing.t[0])) {
      rtb_Gain1_b = 0.0;
    } else {
      rtb_Gain1_b = direct_power_control_DW.TimeStampA_m;
      lastU = &direct_power_control_DW.LastUAtTimeA_j;
      if (direct_power_control_DW.TimeStampA_m <
          direct_power_control_DW.TimeStampB_g) {
        if (direct_power_control_DW.TimeStampB_g <
            direct_power_control_M->Timing.t[0]) {
          rtb_Gain1_b = direct_power_control_DW.TimeStampB_g;
          lastU = &direct_power_control_DW.LastUAtTimeB_a;
        }
      } else {
        if (direct_power_control_DW.TimeStampA_m >=
            direct_power_control_M->Timing.t[0]) {
          rtb_Gain1_b = direct_power_control_DW.TimeStampB_g;
          lastU = &direct_power_control_DW.LastUAtTimeB_a;
        }
      }

      rtb_Gain1_b = (direct_power_control_B.dq_j[1] - *lastU) /
        (direct_power_control_M->Timing.t[0] - rtb_Gain1_b);
    }

    /* End of Derivative: '<S24>/Derivative' */

    /* Sum: '<S24>/Sum4' incorporates:
     *  Gain: '<S24>/Gain1'
     *  Gain: '<S24>/Gain3'
     *  Gain: '<S24>/Gain6'
     *  Gain: '<S24>/Gain7'
     *  Product: '<S24>/Product1'
     *  Sum: '<S24>/Sum1'
     *  Sum: '<S24>/Sum3'
     */
    direct_power_control_B.Sum4 = (rtb_Gain5 * direct_power_control_B.dq_j[0] *
      direct_power_control_P.Ls + (direct_power_control_P.Rs *
      direct_power_control_B.dq_j[1] + direct_power_control_P.Ls * rtb_Gain1_b))
      + direct_power_control_P.Ka * rtb_Gain5;

    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Integrator: '<S4>/Integrator'
     *  MATLAB Function: '<S23>/MATLAB Function'
     *  SignalConversion: '<S26>/TmpSignal ConversionAt SFunction Inport1'
     *  Sin: '<S1>/Ua'
     *  Sin: '<S1>/Ub'
     *  Sin: '<S1>/Uc'
     */
    /* MATLAB Function 'Wind turbine model1/d-q to a-b-c/MATLAB Function': '<S26>:1' */
    /*  transformation from d-q to a-b-c */
    /*  based on "COMMANDE VECTORIELLE DES MACHINES ASYNCHRONES & SYNCHRONES"  */
    /*  5ème Année GE Option ISIP INSA LYON */
    /*  http://docinsa.insa-lyon.fr/polycop/download.php?id=160503&id2=0  */
    /* '<S26>:1:11' */
    /* '<S26>:1:12' */
    /* '<S26>:1:13' */
    /* '<S26>:1:15' */
    /* '<S26>:1:16' */
    /* '<S26>:1:17' */
    /* '<S26>:1:19' */
    if (direct_power_control_P.ManualSwitch_CurrentSetting_h == 1) {
      direct_power_control_B.ManualSwitch[0] = sin(direct_power_control_P.w *
        direct_power_control_M->Timing.t[0] + direct_power_control_P.Ua_Phase) *
        direct_power_control_P.U + direct_power_control_P.Ua_Bias;
      direct_power_control_B.ManualSwitch[1] = sin(direct_power_control_P.w *
        direct_power_control_M->Timing.t[0] + direct_power_control_P.Ub_Phase) *
        direct_power_control_P.U + direct_power_control_P.Ub_Bias;
      direct_power_control_B.ManualSwitch[2] = sin(direct_power_control_P.w *
        direct_power_control_M->Timing.t[0] + direct_power_control_P.Uc_Phase) *
        direct_power_control_P.U + direct_power_control_P.Uc_Bias;
    } else {
      direct_power_control_B.ManualSwitch[0] = (cos
        (direct_power_control_X.Integrator_CSTATE_b) *
        direct_power_control_B.Sum2 - sin
        (direct_power_control_X.Integrator_CSTATE_b) *
        direct_power_control_B.Sum4) * 0.816496580927726;
      direct_power_control_B.ManualSwitch[1] = (cos
        (direct_power_control_X.Integrator_CSTATE_b - 2.0943951023931953) *
        direct_power_control_B.Sum2 - sin
        (direct_power_control_X.Integrator_CSTATE_b - 2.0943951023931953) *
        direct_power_control_B.Sum4) * 0.816496580927726;
      direct_power_control_B.ManualSwitch[2] = (cos
        (direct_power_control_X.Integrator_CSTATE_b + 2.0943951023931953) *
        direct_power_control_B.Sum2 - sin
        (direct_power_control_X.Integrator_CSTATE_b + 2.0943951023931953) *
        direct_power_control_B.Sum4) * 0.816496580927726;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch' */

    /* SignalConversion: '<S19>/TmpSignal ConversionAtGainInport1' incorporates:
     *  Sum: '<S19>/Sum'
     *  Sum: '<S19>/Sum1'
     */
    rtb_Gain5 = direct_power_control_B.ManualSwitch[0] -
      direct_power_control_B.ManualSwitch[1];
    up = direct_power_control_B.ManualSwitch[1] -
      direct_power_control_B.ManualSwitch[2];

    /* Gain: '<S19>/Gain1' incorporates:
     *  Gain: '<S19>/Gain'
     */
    direct_power_control_B.Gain1[0] = (direct_power_control_P.Gain_Gain_f[0] *
      rtb_Gain5 + direct_power_control_P.Gain_Gain_f[2] * up) *
      direct_power_control_P.Gain1_Gain_d;
    direct_power_control_B.Gain1[1] = (direct_power_control_P.Gain_Gain_f[1] *
      rtb_Gain5 + direct_power_control_P.Gain_Gain_f[3] * up) *
      direct_power_control_P.Gain1_Gain_d;

    /* Product: '<S20>/Divide' */
    direct_power_control_B.Divide_n = direct_power_control_B.Gain1[1] /
      direct_power_control_B.Gain1[0];

    /* Trigonometry: '<S20>/Trigonometric Function' */
    direct_power_control_B.TrigonometricFunction_l = atan
      (direct_power_control_B.Divide_n);

    /* Switch: '<S20>/Switch' incorporates:
     *  Constant: '<S20>/Constant'
     *  Sum: '<S20>/Sum'
     */
    if (direct_power_control_B.Gain1[0] >
        direct_power_control_P.Switch_Threshold_m) {
      direct_power_control_B.Switch_k =
        direct_power_control_B.TrigonometricFunction_l;
    } else {
      direct_power_control_B.Switch_k =
        direct_power_control_B.TrigonometricFunction_l +
        direct_power_control_P.Constant_Value_m;
    }

    /* End of Switch: '<S20>/Switch' */

    /* ManualSwitch: '<S3>/Manual Switch1' */
    if (direct_power_control_P.ManualSwitch1_CurrentSetting == 1) {
      direct_power_control_B.ManualSwitch1 = direct_power_control_B.Switch;
    } else {
      direct_power_control_B.ManualSwitch1 = direct_power_control_B.Switch_k;
    }

    /* End of ManualSwitch: '<S3>/Manual Switch1' */
    if (rtmIsMajorTimeStep(direct_power_control_M)) {
      /* Scope: '<Root>/Source voltage ' */
      if (rtmIsMajorTimeStep(direct_power_control_M)) {
        real_T u[4];
        u[0] = (((direct_power_control_M->Timing.clockTick1+
                  direct_power_control_M->Timing.clockTickH1* 4294967296.0)) *
                1.0E-5);
        u[1] = direct_power_control_B.ManualSwitch[0];
        u[2] = direct_power_control_B.ManualSwitch[1];
        u[3] = direct_power_control_B.ManualSwitch[2];
        rt_UpdateLogVar((LogVar *)
                        direct_power_control_DW.Sourcevoltage_PWORK.LoggedData,
                        u, 0);
      }
    }

    /* Relay: '<S8>/dp' */
    if (rtmIsMajorTimeStep(direct_power_control_M)) {
      if (direct_power_control_B.Sum >= direct_power_control_P.Hp) {
        direct_power_control_DW.dp_Mode = true;
      } else {
        if (direct_power_control_B.Sum <= -direct_power_control_P.Hp) {
          direct_power_control_DW.dp_Mode = false;
        }
      }
    }

    if (direct_power_control_DW.dp_Mode) {
      direct_power_control_B.dp = direct_power_control_P.dp_YOn;
    } else {
      direct_power_control_B.dp = direct_power_control_P.dp_YOff;
    }

    /* End of Relay: '<S8>/dp' */

    /* Relay: '<S8>/dq' */
    if (rtmIsMajorTimeStep(direct_power_control_M)) {
      if (direct_power_control_B.Sum1 >= direct_power_control_P.Hq) {
        direct_power_control_DW.dq_Mode = true;
      } else {
        if (direct_power_control_B.Sum1 <= -direct_power_control_P.Hq) {
          direct_power_control_DW.dq_Mode = false;
        }
      }
    }

    if (direct_power_control_DW.dq_Mode) {
      direct_power_control_B.dq = direct_power_control_P.dq_YOn;
    } else {
      direct_power_control_B.dq = direct_power_control_P.dq_YOff;
    }

    /* End of Relay: '<S8>/dq' */

    /* MATLAB Function: '<S12>/MATLAB Function' */
    rtb_Gain1_b = direct_power_control_B.ManualSwitch1;

    /* MATLAB Function 'Udc controller/Sector selection /MATLAB Function': '<S21>:1' */
    /*  persistent n ;  */
    /*  n = 1 ;  */
    /*   */
    /*  % gamma */
    /*  up = (n-1)*pi/6  ;  */
    /*  down = (n-2)*pi/6 ;   */
    /*  % n  */
    /*   */
    /*  if (n>=11 && gamma <0 )  */
    /*      gamma = gamma + 2*pi ;  */
    /*  end  */
    /*  while (down >=gamma || gamma > up)  */
    /*      if n==12  */
    /*          n=1 ;  */
    /*      else  */
    /*          n=n+1   */
    /*      end */
    /*     if (n>=11 && gamma <0 )  */
    /*      gamma = gamma + 2*pi ;  */
    /*     end  */
    /*      up = (n-1)*pi/6   */
    /*      down = (n-2)*pi/6  */
    /*      gamma */
    /*  end  */
    /*  y=n  */
    /*  gamma */
    if (direct_power_control_B.ManualSwitch1 < -0.52359877559829882) {
      /* '<S21>:1:33' */
      /* '<S21>:1:34' */
      rtb_Gain1_b = direct_power_control_B.ManualSwitch1 + 6.2831853071795862;
    }

    /* '<S21>:1:36' */
    rtb_Gain5 = 1.0;

    /* '<S21>:1:37' */
    up = 0.0;

    /* '<S21>:1:38' */
    down = -0.52359877559829882;
    while ((down >= rtb_Gain1_b) || (rtb_Gain1_b > up)) {
      /* '<S21>:1:40' */
      if (rtb_Gain5 == 12.0) {
        /* '<S21>:1:41' */
        /* '<S21>:1:42' */
        rtb_Gain5 = 1.0;
      } else {
        /* '<S21>:1:44' */
        rtb_Gain5++;
      }

      /* '<S21>:1:46' */
      up = (rtb_Gain5 - 1.0) * 3.1415926535897931 / 6.0;

      /* '<S21>:1:47' */
      down = (rtb_Gain5 - 2.0) * 3.1415926535897931 / 6.0;
    }

    /* '<S21>:1:49' */
    direct_power_control_B.y = rtb_Gain5;

    /* End of MATLAB Function: '<S12>/MATLAB Function' */

    /* MATLAB Function: '<S13>/MATLAB Function' incorporates:
     *  Constant: '<S13>/Constant'
     *  Constant: '<S13>/Constant1'
     *  Constant: '<S13>/Constant2'
     *  Constant: '<S13>/Constant3'
     */
    /* MATLAB Function 'Udc controller/Direct Power controller/Switching Table /MATLAB Function': '<S14>:1' */
    /*  global sp10 sp11 sp00 sp01 */
    /*   */
    /*  sp10= load('sp10.mat') ;  */
    /*  sp11=load('sp11.mat');  */
    /*  sp00=load('sp00.mat'); */
    /*  sp01 =load('sp01.mat');  */
    /* persistent Sa Sb Sc   */
    /* '<S14>:1:10' */
    direct_power_control_B.Sa = 0.0;

    /* '<S14>:1:11' */
    direct_power_control_B.Sb = 0.0;

    /* '<S14>:1:12' */
    direct_power_control_B.Sc = 0.0;
    switch ((int32_T)direct_power_control_B.dp) {
     case 1:
      switch ((int32_T)direct_power_control_B.dq) {
       case 0:
        /* '<S14>:1:18' */
        direct_power_control_B.Sa = direct_power_control_P.sp10[(int32_T)
          direct_power_control_B.y - 1];

        /* '<S14>:1:19' */
        direct_power_control_B.Sb = direct_power_control_P.sp10[(int32_T)
          direct_power_control_B.y + 11];

        /* '<S14>:1:20' */
        direct_power_control_B.Sc = direct_power_control_P.sp10[(int32_T)
          direct_power_control_B.y + 23];
        break;

       case 1:
        /* '<S14>:1:22' */
        direct_power_control_B.Sa = direct_power_control_P.sp11[(int32_T)
          direct_power_control_B.y - 1];

        /* '<S14>:1:23' */
        direct_power_control_B.Sb = direct_power_control_P.sp11[(int32_T)
          direct_power_control_B.y + 11];

        /* '<S14>:1:24' */
        direct_power_control_B.Sc = direct_power_control_P.sp11[(int32_T)
          direct_power_control_B.y + 23];
        break;
      }
      break;

     case 0:
      switch ((int32_T)direct_power_control_B.dq) {
       case 0:
        /* '<S14>:1:29' */
        direct_power_control_B.Sa = direct_power_control_P.sp00[(int32_T)
          direct_power_control_B.y - 1];

        /* '<S14>:1:30' */
        direct_power_control_B.Sb = direct_power_control_P.sp00[(int32_T)
          direct_power_control_B.y + 11];

        /* '<S14>:1:31' */
        direct_power_control_B.Sc = direct_power_control_P.sp00[(int32_T)
          direct_power_control_B.y + 23];
        break;

       case 1:
        /* '<S14>:1:33' */
        direct_power_control_B.Sa = direct_power_control_P.sp01[(int32_T)
          direct_power_control_B.y - 1];

        /* '<S14>:1:34' */
        direct_power_control_B.Sb = direct_power_control_P.sp01[(int32_T)
          direct_power_control_B.y + 11];

        /* '<S14>:1:35' */
        direct_power_control_B.Sc = direct_power_control_P.sp01[(int32_T)
          direct_power_control_B.y + 23];
        break;
      }
      break;
    }

    /* End of MATLAB Function: '<S13>/MATLAB Function' */
    if (rtmIsMajorTimeStep(direct_power_control_M)) {
    }

    /* Gain: '<S9>/Integral Gain' */
    direct_power_control_B.IntegralGain = direct_power_control_P.PIDController_I
      * rtb_Sum2_p;
    if (rtmIsMajorTimeStep(direct_power_control_M)) {
    }

    /* Product: '<S16>/Product' incorporates:
     *  Gain: '<S16>/Gain'
     *  Gain: '<S16>/Gain2'
     *  Sum: '<S16>/Sum1'
     *  Sum: '<S16>/Sum2'
     */
    direct_power_control_B.usalpha = (direct_power_control_B.Sa -
      (direct_power_control_B.Sb + direct_power_control_B.Sc) *
      direct_power_control_P.Gain2_Gain) * direct_power_control_P.Gain_Gain_d *
      direct_power_control_B.Gain_g;

    /* Product: '<S16>/Product1' incorporates:
     *  Gain: '<S16>/Gain3'
     *  Sum: '<S16>/Sum3'
     */
    direct_power_control_B.usbeta = (direct_power_control_B.Sb -
      direct_power_control_B.Sc) * direct_power_control_P.Gain3_Gain *
      direct_power_control_B.Gain_g;
    if (rtmIsMajorTimeStep(direct_power_control_M)) {
    }

    /* Derivative: '<S16>/Derivative' */
    if ((direct_power_control_DW.TimeStampA_p >=
         direct_power_control_M->Timing.t[0]) &&
        (direct_power_control_DW.TimeStampB_c >=
         direct_power_control_M->Timing.t[0])) {
      up = 0.0;
      rtb_Gain5 = 0.0;
    } else {
      rtb_Gain1_b = direct_power_control_DW.TimeStampA_p;
      lastU_0 = (real_T (*)[2])direct_power_control_DW.LastUAtTimeA_a;
      if (direct_power_control_DW.TimeStampA_p <
          direct_power_control_DW.TimeStampB_c) {
        if (direct_power_control_DW.TimeStampB_c <
            direct_power_control_M->Timing.t[0]) {
          rtb_Gain1_b = direct_power_control_DW.TimeStampB_c;
          lastU_0 = (real_T (*)[2])direct_power_control_DW.LastUAtTimeB_n;
        }
      } else {
        if (direct_power_control_DW.TimeStampA_p >=
            direct_power_control_M->Timing.t[0]) {
          rtb_Gain1_b = direct_power_control_DW.TimeStampB_c;
          lastU_0 = (real_T (*)[2])direct_power_control_DW.LastUAtTimeB_n;
        }
      }

      rtb_Gain1_b = direct_power_control_M->Timing.t[0] - rtb_Gain1_b;
      up = (direct_power_control_B.Gain[0] - (*lastU_0)[0]) / rtb_Gain1_b;
      rtb_Gain5 = (direct_power_control_B.Gain[1] - (*lastU_0)[1]) / rtb_Gain1_b;
    }

    /* End of Derivative: '<S16>/Derivative' */

    /* Gain: '<S16>/Gain1' */
    up *= direct_power_control_P.L;

    /* Sum: '<S16>/Sum' incorporates:
     *  Gain: '<S16>/Gain1'
     */
    direct_power_control_B.Sum_e[0] = up + direct_power_control_B.usalpha;
    direct_power_control_B.Sum_e[1] = direct_power_control_P.L * rtb_Gain5 +
      direct_power_control_B.usbeta;
    if (rtmIsMajorTimeStep(direct_power_control_M)) {
    }

    /* Gain: '<S24>/Gain8' incorporates:
     *  Gain: '<S24>/Gain9'
     */
    direct_power_control_B.Gain8 = direct_power_control_P.Ka *
      direct_power_control_B.dq_j[1] * direct_power_control_P.p;
    if (rtmIsMajorTimeStep(direct_power_control_M)) {
    }

    /* Gain: '<S4>/Gain1' */
    direct_power_control_B.Gain1_n = direct_power_control_P.p * rtb_Gain4_c;
    if (rtmIsMajorTimeStep(direct_power_control_M)) {
    }

    /* Gain: '<S5>/Gain1' incorporates:
     *  Sum: '<S5>/Sum8'
     */
    rtb_Gain1_b = ((direct_power_control_B.Sa + direct_power_control_B.Sb) +
                   direct_power_control_B.Sc) *
      direct_power_control_P.Gain1_Gain_c;

    /* Sum: '<S5>/Sum' incorporates:
     *  Constant: '<Root>/iload'
     *  Product: '<S5>/Product'
     *  Product: '<S5>/Product1'
     *  Product: '<S5>/Product2'
     *  Sum: '<S5>/Sum1'
     */
    direct_power_control_B.Sum_n = ((direct_power_control_B.Ia *
      direct_power_control_B.Sa + direct_power_control_B.Ia_k *
      direct_power_control_B.Sb) + direct_power_control_B.TransferFcn2 *
      direct_power_control_B.Sc) - direct_power_control_P.iload_Value;

    /* Sum: '<S5>/Sum2' incorporates:
     *  Product: '<S5>/Product3'
     *  Sum: '<S5>/Sum5'
     */
    direct_power_control_B.Sum2_g = direct_power_control_B.ManualSwitch[0] -
      (direct_power_control_B.Sa - rtb_Gain1_b) * direct_power_control_B.Gain_g;

    /* Sum: '<S5>/Sum3' incorporates:
     *  Product: '<S5>/Product4'
     *  Sum: '<S5>/Sum6'
     */
    direct_power_control_B.Sum3 = direct_power_control_B.ManualSwitch[1] -
      (direct_power_control_B.Sb - rtb_Gain1_b) * direct_power_control_B.Gain_g;

    /* Sum: '<S5>/Sum4' incorporates:
     *  Product: '<S5>/Product5'
     *  Sum: '<S5>/Sum7'
     */
    direct_power_control_B.Sum4_e = direct_power_control_B.ManualSwitch[2] -
      (direct_power_control_B.Sc - rtb_Gain1_b) * direct_power_control_B.Gain_g;
  }

  if (rtmIsMajorTimeStep(direct_power_control_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(direct_power_control_M->rtwLogInfo,
                        (direct_power_control_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(direct_power_control_M)) {
    real_T *lastU;
    real_T (*lastU_0)[2];

    /* Update for Derivative: '<S24>/Derivative1' */
    if (direct_power_control_DW.TimeStampA == (rtInf)) {
      direct_power_control_DW.TimeStampA = direct_power_control_M->Timing.t[0];
      lastU = &direct_power_control_DW.LastUAtTimeA;
    } else if (direct_power_control_DW.TimeStampB == (rtInf)) {
      direct_power_control_DW.TimeStampB = direct_power_control_M->Timing.t[0];
      lastU = &direct_power_control_DW.LastUAtTimeB;
    } else if (direct_power_control_DW.TimeStampA <
               direct_power_control_DW.TimeStampB) {
      direct_power_control_DW.TimeStampA = direct_power_control_M->Timing.t[0];
      lastU = &direct_power_control_DW.LastUAtTimeA;
    } else {
      direct_power_control_DW.TimeStampB = direct_power_control_M->Timing.t[0];
      lastU = &direct_power_control_DW.LastUAtTimeB;
    }

    *lastU = direct_power_control_B.dq_j[0];

    /* End of Update for Derivative: '<S24>/Derivative1' */

    /* Update for Derivative: '<S24>/Derivative' */
    if (direct_power_control_DW.TimeStampA_m == (rtInf)) {
      direct_power_control_DW.TimeStampA_m = direct_power_control_M->Timing.t[0];
      lastU = &direct_power_control_DW.LastUAtTimeA_j;
    } else if (direct_power_control_DW.TimeStampB_g == (rtInf)) {
      direct_power_control_DW.TimeStampB_g = direct_power_control_M->Timing.t[0];
      lastU = &direct_power_control_DW.LastUAtTimeB_a;
    } else if (direct_power_control_DW.TimeStampA_m <
               direct_power_control_DW.TimeStampB_g) {
      direct_power_control_DW.TimeStampA_m = direct_power_control_M->Timing.t[0];
      lastU = &direct_power_control_DW.LastUAtTimeA_j;
    } else {
      direct_power_control_DW.TimeStampB_g = direct_power_control_M->Timing.t[0];
      lastU = &direct_power_control_DW.LastUAtTimeB_a;
    }

    *lastU = direct_power_control_B.dq_j[1];

    /* End of Update for Derivative: '<S24>/Derivative' */

    /* Update for Derivative: '<S16>/Derivative' */
    if (direct_power_control_DW.TimeStampA_p == (rtInf)) {
      direct_power_control_DW.TimeStampA_p = direct_power_control_M->Timing.t[0];
      lastU_0 = (real_T (*)[2])direct_power_control_DW.LastUAtTimeA_a;
    } else if (direct_power_control_DW.TimeStampB_c == (rtInf)) {
      direct_power_control_DW.TimeStampB_c = direct_power_control_M->Timing.t[0];
      lastU_0 = (real_T (*)[2])direct_power_control_DW.LastUAtTimeB_n;
    } else if (direct_power_control_DW.TimeStampA_p <
               direct_power_control_DW.TimeStampB_c) {
      direct_power_control_DW.TimeStampA_p = direct_power_control_M->Timing.t[0];
      lastU_0 = (real_T (*)[2])direct_power_control_DW.LastUAtTimeA_a;
    } else {
      direct_power_control_DW.TimeStampB_c = direct_power_control_M->Timing.t[0];
      lastU_0 = (real_T (*)[2])direct_power_control_DW.LastUAtTimeB_n;
    }

    (*lastU_0)[0] = direct_power_control_B.Gain[0];
    (*lastU_0)[1] = direct_power_control_B.Gain[1];

    /* End of Update for Derivative: '<S16>/Derivative' */
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(direct_power_control_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(direct_power_control_M)!=-1) &&
          !((rtmGetTFinal(direct_power_control_M)-
             (((direct_power_control_M->Timing.clockTick1+
                direct_power_control_M->Timing.clockTickH1* 4294967296.0)) *
              1.0E-5)) > (((direct_power_control_M->Timing.clockTick1+
                            direct_power_control_M->Timing.clockTickH1*
                            4294967296.0)) * 1.0E-5) * (DBL_EPSILON))) {
        rtmSetErrorStatus(direct_power_control_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&direct_power_control_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++direct_power_control_M->Timing.clockTick0)) {
      ++direct_power_control_M->Timing.clockTickH0;
    }

    direct_power_control_M->Timing.t[0] = rtsiGetSolverStopTime
      (&direct_power_control_M->solverInfo);

    {
      /* Update absolute timer for sample time: [1.0E-5s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 1.0E-5, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      direct_power_control_M->Timing.clockTick1++;
      if (!direct_power_control_M->Timing.clockTick1) {
        direct_power_control_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void direct_power_control_derivatives(void)
{
  XDot_direct_power_control_T *_rtXdot;
  _rtXdot = ((XDot_direct_power_control_T *)
             direct_power_control_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S5>/Transfer Fcn' */
  _rtXdot->Ia = 0.0;
  _rtXdot->Ia += direct_power_control_P.TransferFcn_A *
    direct_power_control_X.Ia;
  _rtXdot->Ia += direct_power_control_B.Sum2_g;

  /* Derivatives for TransferFcn: '<S5>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += direct_power_control_P.TransferFcn1_A *
    direct_power_control_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += direct_power_control_B.Sum3;

  /* Derivatives for TransferFcn: '<S5>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE = 0.0;
  _rtXdot->TransferFcn2_CSTATE += direct_power_control_P.TransferFcn2_A *
    direct_power_control_X.TransferFcn2_CSTATE;
  _rtXdot->TransferFcn2_CSTATE += direct_power_control_B.Sum4_e;

  /* Derivatives for Integrator: '<S16>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = direct_power_control_B.Sum_e[0];
  _rtXdot->Integrator_CSTATE[1] = direct_power_control_B.Sum_e[1];

  /* Derivatives for Integrator: '<S5>/Integrator' */
  _rtXdot->Integrator_CSTATE_e = direct_power_control_B.Sum_n;

  /* Derivatives for Integrator: '<S9>/Integrator' */
  _rtXdot->Integrator_CSTATE_c = direct_power_control_B.IntegralGain;

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE_b = direct_power_control_B.Gain1_n;
}

/* Model initialize function */
void direct_power_control_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)direct_power_control_M, 0,
                sizeof(RT_MODEL_direct_power_control_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&direct_power_control_M->solverInfo,
                          &direct_power_control_M->Timing.simTimeStep);
    rtsiSetTPtr(&direct_power_control_M->solverInfo, &rtmGetTPtr
                (direct_power_control_M));
    rtsiSetStepSizePtr(&direct_power_control_M->solverInfo,
                       &direct_power_control_M->Timing.stepSize0);
    rtsiSetdXPtr(&direct_power_control_M->solverInfo,
                 &direct_power_control_M->ModelData.derivs);
    rtsiSetContStatesPtr(&direct_power_control_M->solverInfo, (real_T **)
                         &direct_power_control_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&direct_power_control_M->solverInfo,
      &direct_power_control_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&direct_power_control_M->solverInfo,
                          (&rtmGetErrorStatus(direct_power_control_M)));
    rtsiSetRTModelPtr(&direct_power_control_M->solverInfo,
                      direct_power_control_M);
  }

  rtsiSetSimTimeStep(&direct_power_control_M->solverInfo, MAJOR_TIME_STEP);
  direct_power_control_M->ModelData.intgData.y =
    direct_power_control_M->ModelData.odeY;
  direct_power_control_M->ModelData.intgData.f[0] =
    direct_power_control_M->ModelData.odeF[0];
  direct_power_control_M->ModelData.intgData.f[1] =
    direct_power_control_M->ModelData.odeF[1];
  direct_power_control_M->ModelData.intgData.f[2] =
    direct_power_control_M->ModelData.odeF[2];
  direct_power_control_M->ModelData.contStates = ((X_direct_power_control_T *)
    &direct_power_control_X);
  rtsiSetSolverData(&direct_power_control_M->solverInfo, (void *)
                    &direct_power_control_M->ModelData.intgData);
  rtsiSetSolverName(&direct_power_control_M->solverInfo,"ode3");
  rtmSetTPtr(direct_power_control_M, &direct_power_control_M->Timing.tArray[0]);
  rtmSetTFinal(direct_power_control_M, 10.0);
  direct_power_control_M->Timing.stepSize0 = 1.0E-5;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    direct_power_control_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(direct_power_control_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(direct_power_control_M->rtwLogInfo, (NULL));
    rtliSetLogT(direct_power_control_M->rtwLogInfo, "tout");
    rtliSetLogX(direct_power_control_M->rtwLogInfo, "");
    rtliSetLogXFinal(direct_power_control_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(direct_power_control_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(direct_power_control_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(direct_power_control_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(direct_power_control_M->rtwLogInfo, 1);
    rtliSetLogY(direct_power_control_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(direct_power_control_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(direct_power_control_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &direct_power_control_B), 0,
                sizeof(B_direct_power_control_T));

  /* states (continuous) */
  {
    (void) memset((void *)&direct_power_control_X, 0,
                  sizeof(X_direct_power_control_T));
  }

  /* states (dwork) */
  (void) memset((void *)&direct_power_control_DW, 0,
                sizeof(DW_direct_power_control_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(direct_power_control_M->rtwLogInfo, 0.0,
    rtmGetTFinal(direct_power_control_M),
    direct_power_control_M->Timing.stepSize0, (&rtmGetErrorStatus
    (direct_power_control_M)));

  /* Start for Scope: '<Root>/Source currents' */
  {
    int_T numCols = 4;
    direct_power_control_DW.Sourcecurrents_PWORK.LoggedData = rt_CreateLogVar(
      direct_power_control_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(direct_power_control_M),
      direct_power_control_M->Timing.stepSize0,
      (&rtmGetErrorStatus(direct_power_control_M)),
      "Iabc",
      SS_DOUBLE,
      0,
      0,
      0,
      4,
      1,
      (int_T *)&numCols,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      1.0E-5,
      1);
    if (direct_power_control_DW.Sourcecurrents_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for Scope: '<Root>/err_p' */
  {
    int_T numCols = 2;
    direct_power_control_DW.err_p_PWORK.LoggedData = rt_CreateLogVar(
      direct_power_control_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(direct_power_control_M),
      direct_power_control_M->Timing.stepSize0,
      (&rtmGetErrorStatus(direct_power_control_M)),
      "err_p",
      SS_DOUBLE,
      0,
      0,
      0,
      2,
      1,
      (int_T *)&numCols,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      1.0E-5,
      1);
    if (direct_power_control_DW.err_p_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for Scope: '<Root>/err_q' */
  {
    int_T numCols = 2;
    direct_power_control_DW.err_q_PWORK.LoggedData = rt_CreateLogVar(
      direct_power_control_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(direct_power_control_M),
      direct_power_control_M->Timing.stepSize0,
      (&rtmGetErrorStatus(direct_power_control_M)),
      "err_q",
      SS_DOUBLE,
      0,
      0,
      0,
      2,
      1,
      (int_T *)&numCols,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      1.0E-5,
      1);
    if (direct_power_control_DW.err_q_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for Scope: '<Root>/Udc' */
  {
    int_T numCols = 2;
    direct_power_control_DW.Udc_PWORK.LoggedData = rt_CreateLogVar(
      direct_power_control_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(direct_power_control_M),
      direct_power_control_M->Timing.stepSize0,
      (&rtmGetErrorStatus(direct_power_control_M)),
      "Udc",
      SS_DOUBLE,
      0,
      0,
      0,
      2,
      1,
      (int_T *)&numCols,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      1.0E-5,
      1);
    if (direct_power_control_DW.Udc_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for Scope: '<Root>/Source voltage ' */
  {
    int_T numCols = 4;
    direct_power_control_DW.Sourcevoltage_PWORK.LoggedData = rt_CreateLogVar(
      direct_power_control_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(direct_power_control_M),
      direct_power_control_M->Timing.stepSize0,
      (&rtmGetErrorStatus(direct_power_control_M)),
      "Uabc",
      SS_DOUBLE,
      0,
      0,
      0,
      4,
      1,
      (int_T *)&numCols,
      NO_LOGVALDIMS,
      (NULL),
      (NULL),
      0,
      1,
      1.0E-5,
      1);
    if (direct_power_control_DW.Sourcevoltage_PWORK.LoggedData == (NULL))
      return;
  }

  /* InitializeConditions for TransferFcn: '<S5>/Transfer Fcn' */
  direct_power_control_X.Ia = 0.0;

  /* InitializeConditions for TransferFcn: '<S5>/Transfer Fcn1' */
  direct_power_control_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S5>/Transfer Fcn2' */
  direct_power_control_X.TransferFcn2_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S16>/Integrator' */
  direct_power_control_X.Integrator_CSTATE[0] =
    direct_power_control_P.Integrator_IC;
  direct_power_control_X.Integrator_CSTATE[1] =
    direct_power_control_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  direct_power_control_X.Integrator_CSTATE_e =
    direct_power_control_P.Integrator_IC_a;

  /* InitializeConditions for Integrator: '<S9>/Integrator' */
  direct_power_control_X.Integrator_CSTATE_c =
    direct_power_control_P.Integrator_IC_f;

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  direct_power_control_X.Integrator_CSTATE_b =
    direct_power_control_P.Integrator_IC_p;

  /* InitializeConditions for Derivative: '<S24>/Derivative1' */
  direct_power_control_DW.TimeStampA = (rtInf);
  direct_power_control_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<S24>/Derivative' */
  direct_power_control_DW.TimeStampA_m = (rtInf);
  direct_power_control_DW.TimeStampB_g = (rtInf);

  /* InitializeConditions for Derivative: '<S16>/Derivative' */
  direct_power_control_DW.TimeStampA_p = (rtInf);
  direct_power_control_DW.TimeStampB_c = (rtInf);
}

/* Model terminate function */
void direct_power_control_terminate(void)
{
  /* (no terminate code required) */
}
