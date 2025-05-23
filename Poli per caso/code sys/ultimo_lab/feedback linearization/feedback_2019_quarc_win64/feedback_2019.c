/*
 * feedback_2019.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "feedback_2019".
 *
 * Model version              : 1.2
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Fri May 23 12:28:05 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "feedback_2019.h"
#include "feedback_2019_private.h"
#include "feedback_2019_dt.h"

/* Block signals (default storage) */
B_feedback_2019_T feedback_2019_B;

/* Continuous states */
X_feedback_2019_T feedback_2019_X;

/* Block states (default storage) */
DW_feedback_2019_T feedback_2019_DW;

/* Real-time model */
RT_MODEL_feedback_2019_T feedback_2019_M_;
RT_MODEL_feedback_2019_T *const feedback_2019_M = &feedback_2019_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 10;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  feedback_2019_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Model step function */
void feedback_2019_step(void)
{
  /* local block i/o variables */
  real_T rtb_BallPositionandCurrent_o1;
  real_T rtb_BallPositionandCurrent_o2;
  int_T iy;
  real_T coeff[4];
  real_T xtmp;
  real_T beta;
  real_T dBdx2;
  real_T rtb_ManualSwitch1;
  real_T rtb_Add1_b;
  real_T rtb_Add_d;
  real_T rtb_x_hat[3];
  real_T rtb_x3_hat;
  real_T xtmp_tmp;
  if (rtmIsMajorTimeStep(feedback_2019_M)) {
    /* set solver stop time */
    if (!(feedback_2019_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&feedback_2019_M->solverInfo,
                            ((feedback_2019_M->Timing.clockTickH0 + 1) *
        feedback_2019_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&feedback_2019_M->solverInfo,
                            ((feedback_2019_M->Timing.clockTick0 + 1) *
        feedback_2019_M->Timing.stepSize0 + feedback_2019_M->Timing.clockTickH0 *
        feedback_2019_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(feedback_2019_M)) {
    feedback_2019_M->Timing.t[0] = rtsiGetT(&feedback_2019_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(feedback_2019_M)) {
  }

  /* Step: '<Root>/Step' */
  if (feedback_2019_M->Timing.t[0] < feedback_2019_P.Step_Time) {
    feedback_2019_B.Step = feedback_2019_P.Step_Y0;
  } else {
    feedback_2019_B.Step = feedback_2019_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */
  if (rtmIsMajorTimeStep(feedback_2019_M)) {
    /* S-Function (hil_read_analog_block): '<S2>/Ball Position and Current' */

    /* S-Function Block: feedback_2019/Subsystem/Ball Position and Current (hil_read_analog_block) */
    {
      t_error result = hil_read_analog(feedback_2019_DW.HILInitialize_Card,
        feedback_2019_P.BallPositionandCurrent_channels, 2,
        &feedback_2019_DW.BallPositionandCurrent_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(feedback_2019_M, _rt_error_message);
      }

      rtb_BallPositionandCurrent_o1 =
        feedback_2019_DW.BallPositionandCurrent_Buffer[0];
      rtb_BallPositionandCurrent_o2 =
        feedback_2019_DW.BallPositionandCurrent_Buffer[1];
    }

    /* Gain: '<S2>/Gain1' incorporates:
     *  Constant: '<S2>/Constant'
     *  Sum: '<S2>/Add1'
     */
    feedback_2019_B.posizione = (feedback_2019_P.offset_posizione_volt +
      rtb_BallPositionandCurrent_o1) * feedback_2019_P.Kb;

    /* Sum: '<S2>/Add' incorporates:
     *  Constant: '<S2>/Constant1'
     */
    feedback_2019_B.corrente = rtb_BallPositionandCurrent_o2 +
      feedback_2019_P.offset_corrente_volt;
  }

  /* ManualSwitch: '<S1>/Manual Switch1' incorporates:
   *  TransferFcn: '<S1>/Transfer Fcn'
   */
  if (feedback_2019_P.ManualSwitch1_CurrentSetting == 1) {
    rtb_ManualSwitch1 = feedback_2019_B.posizione;
  } else {
    rtb_ManualSwitch1 = feedback_2019_P.TransferFcn_C *
      feedback_2019_X.TransferFcn_CSTATE;
  }

  /* End of ManualSwitch: '<S1>/Manual Switch1' */

  /* Sum: '<S3>/Add1' */
  rtb_Add1_b = feedback_2019_B.Step - rtb_ManualSwitch1;

  /* Gain: '<S40>/Filter Coefficient' incorporates:
   *  Gain: '<S31>/Derivative Gain'
   *  Integrator: '<S32>/Filter'
   *  Sum: '<S32>/SumD'
   */
  feedback_2019_B.FilterCoefficient = (feedback_2019_P.PIDController_D *
    rtb_Add1_b - feedback_2019_X.Filter_CSTATE) *
    feedback_2019_P.PIDController_N;

  /* TransferFcn: '<S1>/Transfer Fcn1' */
  rtb_Add_d = feedback_2019_P.TransferFcn1_C *
    feedback_2019_X.TransferFcn1_CSTATE;

  /* ManualSwitch: '<S1>/Manual Switch2' */
  if (feedback_2019_P.ManualSwitch2_CurrentSetting == 1) {
    rtb_Add_d = feedback_2019_B.corrente;
  }

  /* End of ManualSwitch: '<S1>/Manual Switch2' */

  /* StateSpace: '<S1>/State observer' */
  for (iy = 0; iy < 3; iy++) {
    rtb_x_hat[iy] = feedback_2019_P.C_ob[iy + 6] *
      feedback_2019_X.Stateobserver_CSTATE[2] + (feedback_2019_P.C_ob[iy + 3] *
      feedback_2019_X.Stateobserver_CSTATE[1] + feedback_2019_P.C_ob[iy] *
      feedback_2019_X.Stateobserver_CSTATE[0]);
  }

  /* End of StateSpace: '<S1>/State observer' */

  /* MATLAB Function: '<S1>/MATLAB Function' */
  rtb_x3_hat = rtb_x_hat[2];

  /* MATLAB Function 'Reduced OBSERVER/MATLAB Function': '<S4>:1' */
  if ((rtb_x_hat[0] <= 0.0) && (rtb_x_hat[2] <= 0.0)) {
    /* '<S4>:1:3' */
    /* '<S4>:1:4' */
    rtb_x3_hat = 0.0;
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function' */

  /* TransferFcn: '<S3>/Transfer Fcn' */
  feedback_2019_B.TransferFcn = 0.0;
  feedback_2019_B.TransferFcn += feedback_2019_P.TransferFcn_C_j *
    feedback_2019_X.TransferFcn_CSTATE_g;
  feedback_2019_B.TransferFcn += feedback_2019_P.TransferFcn_D *
    feedback_2019_B.Step;

  /* TransferFcn: '<S3>/Transfer Fcn1' */
  feedback_2019_B.TransferFcn1 = 0.0;
  feedback_2019_B.TransferFcn1 += feedback_2019_P.TransferFcn1_C_a *
    feedback_2019_X.TransferFcn1_CSTATE_e;
  feedback_2019_B.TransferFcn1 += feedback_2019_P.TransferFcn1_D *
    feedback_2019_B.TransferFcn;

  /* TransferFcn: '<S3>/Transfer Fcn2' */
  feedback_2019_B.TransferFcn2 = 0.0;
  feedback_2019_B.TransferFcn2 += feedback_2019_P.TransferFcn2_C *
    feedback_2019_X.TransferFcn2_CSTATE;
  feedback_2019_B.TransferFcn2 += feedback_2019_P.TransferFcn2_D *
    feedback_2019_B.TransferFcn1;
  if (rtmIsMajorTimeStep(feedback_2019_M)) {
    /* MATLAB Function: '<S3>/MATLAB Function1' incorporates:
     *  Constant: '<S3>/Constant1'
     *  Constant: '<S3>/Constant2'
     *  Constant: '<S3>/Constant3'
     */
    /* MATLAB Function 'Subsystem1/MATLAB Function1': '<S6>:1' */
    /* '<S6>:1:3' */
    /* '<S6>:1:4' */
    coeff[0] = 1.0;
    coeff[1] = -feedback_2019_P.Subsystem1_p1;
    coeff[2] = -feedback_2019_P.Subsystem1_p2 * -feedback_2019_P.Subsystem1_p1;
    for (iy = 1; iy + 1 > 1; iy--) {
      coeff[iy] -= coeff[iy - 1] * feedback_2019_P.Subsystem1_p2;
    }

    coeff[3] = -feedback_2019_P.Subsystem1_p3 * coeff[2];
    for (iy = 2; iy + 1 > 1; iy--) {
      coeff[iy] -= coeff[iy - 1] * feedback_2019_P.Subsystem1_p3;
    }

    /* '<S6>:1:5' */
    feedback_2019_B.K[0] = coeff[1];
    feedback_2019_B.K[1] = coeff[2];
    feedback_2019_B.K[2] = coeff[3];
    xtmp = feedback_2019_B.K[0];
    feedback_2019_B.K[0] = feedback_2019_B.K[2];
    feedback_2019_B.K[2] = xtmp;

    /* End of MATLAB Function: '<S3>/MATLAB Function1' */
  }

  /* SignalConversion generated from: '<S5>/ SFunction ' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   */
  rtb_x_hat[2] = rtb_x3_hat;

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  Constant: '<S3>/Constant'
   *  SignalConversion generated from: '<S5>/ SFunction '
   */
  /* MATLAB Function 'Subsystem1/MATLAB Function': '<S5>:1' */
  /* '<S5>:1:3' */
  /* '<S5>:1:4' */
  /* '<S5>:1:5' */
  /* '<S5>:1:6' */
  /* '<S5>:1:7' */
  /* '<S5>:1:8' */
  /* '<S5>:1:9' */
  /* '<S5>:1:12' */
  /* '<S5>:1:13' */
  /* '<S5>:1:14' */
  /* '<S5>:1:17' */
  rtb_x3_hat = feedback_2019_P.Constant_Value[3] - rtb_ManualSwitch1;

  /* '<S5>:1:23' */
  xtmp = rtb_Add_d / rtb_x3_hat;
  xtmp_tmp = feedback_2019_P.Constant_Value[0] / feedback_2019_P.Constant_Value
    [2];
  xtmp = (xtmp_tmp * rtb_x_hat[2] + feedback_2019_P.Constant_Value[1] /
          feedback_2019_P.Constant_Value[2] * (xtmp * xtmp)) - 9.81;

  /* '<S5>:1:26' */
  /* '<S5>:1:27' */
  dBdx2 = 2.0 * feedback_2019_P.Constant_Value[1] * rtb_Add_d / (rtb_x3_hat *
    rtb_x3_hat * feedback_2019_P.Constant_Value[2]);

  /* '<S5>:1:28' */
  /* '<S5>:1:31' */
  /* '<S5>:1:34' */
  /* '<S5>:1:35' */
  beta = 1.0 / feedback_2019_P.Constant_Value[5] * dBdx2;

  /* '<S5>:1:44' */
  /* '<S5>:1:45' */
  /* '<S5>:1:46' */
  /* '<S5>:1:51' */
  /* '<S5>:1:52' */
  /* '<S5>:1:53' */
  /* '<S5>:1:58' */
  /* '<S5>:1:62' */
  feedback_2019_B.beta = beta;

  /* Sum: '<S3>/Add' incorporates:
   *  Constant: '<S3>/Constant'
   *  Gain: '<S42>/Proportional Gain'
   *  Integrator: '<S37>/Integrator'
   *  MATLAB Function: '<S3>/MATLAB Function'
   *  SignalConversion generated from: '<S5>/ SFunction '
   *  Sum: '<S46>/Sum'
   */
  rtb_x3_hat = ((((feedback_2019_B.TransferFcn2 - (rtb_ManualSwitch1 -
    feedback_2019_B.Step) * feedback_2019_B.K[0]) - (rtb_x_hat[2] -
    feedback_2019_B.TransferFcn) * feedback_2019_B.K[1]) - (xtmp -
    feedback_2019_B.TransferFcn1) * feedback_2019_B.K[2]) - ((2.0 *
    feedback_2019_P.Constant_Value[1] * (rtb_Add_d * rtb_Add_d) /
    (feedback_2019_P.Constant_Value[2] * rt_powd_snf(rtb_x3_hat, 3.0)) *
    rtb_x_hat[2] + -(feedback_2019_P.Constant_Value[4] /
                     feedback_2019_P.Constant_Value[5]) * rtb_Add_d * dBdx2) +
    xtmp_tmp * xtmp)) / beta + ((feedback_2019_P.PIDController_P * rtb_Add1_b +
    feedback_2019_X.Integrator_CSTATE) + feedback_2019_B.FilterCoefficient);

  /* Saturate: '<Root>/Saturation' */
  if (rtb_x3_hat > feedback_2019_P.Saturation_UpperSat) {
    feedback_2019_B.Saturation = feedback_2019_P.Saturation_UpperSat;
  } else if (rtb_x3_hat < feedback_2019_P.Saturation_LowerSat) {
    feedback_2019_B.Saturation = feedback_2019_P.Saturation_LowerSat;
  } else {
    feedback_2019_B.Saturation = rtb_x3_hat;
  }

  /* End of Saturate: '<Root>/Saturation' */
  if (rtmIsMajorTimeStep(feedback_2019_M)) {
  }

  /* SignalConversion generated from: '<S1>/State observer' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   *  Sum: '<S1>/Add'
   *  Sum: '<S1>/Add1'
   *  Sum: '<S1>/Add2'
   */
  feedback_2019_B.TmpSignalConversionAtStateobser[0] =
    feedback_2019_B.Saturation - feedback_2019_P.u;
  feedback_2019_B.TmpSignalConversionAtStateobser[1] = rtb_ManualSwitch1 -
    feedback_2019_P.x1_eq0;
  feedback_2019_B.TmpSignalConversionAtStateobser[2] = rtb_Add_d -
    feedback_2019_P.x2_eq0;

  /* Gain: '<S2>/Gain' */
  feedback_2019_B.Gain = feedback_2019_P.Gain_Gain * feedback_2019_B.Saturation;
  if (rtmIsMajorTimeStep(feedback_2019_M)) {
    /* S-Function (hil_write_analog_block): '<S2>/Voltage' */

    /* S-Function Block: feedback_2019/Subsystem/Voltage (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(feedback_2019_DW.HILInitialize_Card,
        &feedback_2019_P.Voltage_channels, 1, &feedback_2019_B.Gain);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(feedback_2019_M, _rt_error_message);
      }
    }
  }

  /* Gain: '<S34>/Integral Gain' */
  feedback_2019_B.IntegralGain = feedback_2019_P.PIDController_I * rtb_Add1_b;
  if (rtmIsMajorTimeStep(feedback_2019_M)) {
    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, (real_T)feedback_2019_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(feedback_2019_M)) {/* Sample time: [0.002s, 0.0s] */
      rtExtModeUpload(1, (real_T)(((feedback_2019_M->Timing.clockTick1+
        feedback_2019_M->Timing.clockTickH1* 4294967296.0)) * 0.002));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(feedback_2019_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(feedback_2019_M)!=-1) &&
          !((rtmGetTFinal(feedback_2019_M)-(((feedback_2019_M->Timing.clockTick1
               +feedback_2019_M->Timing.clockTickH1* 4294967296.0)) * 0.002)) >
            (((feedback_2019_M->Timing.clockTick1+
               feedback_2019_M->Timing.clockTickH1* 4294967296.0)) * 0.002) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(feedback_2019_M, "Simulation finished");
      }

      if (rtmGetStopRequested(feedback_2019_M)) {
        rtmSetErrorStatus(feedback_2019_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&feedback_2019_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++feedback_2019_M->Timing.clockTick0)) {
      ++feedback_2019_M->Timing.clockTickH0;
    }

    feedback_2019_M->Timing.t[0] = rtsiGetSolverStopTime
      (&feedback_2019_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.002s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.002, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      feedback_2019_M->Timing.clockTick1++;
      if (!feedback_2019_M->Timing.clockTick1) {
        feedback_2019_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void feedback_2019_derivatives(void)
{
  int_T ri;
  XDot_feedback_2019_T *_rtXdot;
  _rtXdot = ((XDot_feedback_2019_T *) feedback_2019_M->derivs);

  /* Derivatives for TransferFcn: '<S1>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += feedback_2019_P.TransferFcn_A *
    feedback_2019_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += feedback_2019_B.posizione;

  /* Derivatives for Integrator: '<S37>/Integrator' */
  _rtXdot->Integrator_CSTATE = feedback_2019_B.IntegralGain;

  /* Derivatives for Integrator: '<S32>/Filter' */
  _rtXdot->Filter_CSTATE = feedback_2019_B.FilterCoefficient;

  /* Derivatives for TransferFcn: '<S1>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += feedback_2019_P.TransferFcn1_A *
    feedback_2019_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += feedback_2019_B.corrente;

  /* Derivatives for StateSpace: '<S1>/State observer' */
  _rtXdot->Stateobserver_CSTATE[0] = 0.0;
  _rtXdot->Stateobserver_CSTATE[1] = 0.0;
  _rtXdot->Stateobserver_CSTATE[2] = 0.0;
  for (ri = 0; ri < 3; ri++) {
    _rtXdot->Stateobserver_CSTATE[ri] += feedback_2019_P.A_ob[ri] *
      feedback_2019_X.Stateobserver_CSTATE[0];
    _rtXdot->Stateobserver_CSTATE[ri] += feedback_2019_P.A_ob[ri + 3] *
      feedback_2019_X.Stateobserver_CSTATE[1];
    _rtXdot->Stateobserver_CSTATE[ri] += feedback_2019_P.A_ob[ri + 6] *
      feedback_2019_X.Stateobserver_CSTATE[2];
    _rtXdot->Stateobserver_CSTATE[ri] += feedback_2019_P.B_ob[ri] *
      feedback_2019_B.TmpSignalConversionAtStateobser[0];
    _rtXdot->Stateobserver_CSTATE[ri] += feedback_2019_P.B_ob[ri + 3] *
      feedback_2019_B.TmpSignalConversionAtStateobser[1];
    _rtXdot->Stateobserver_CSTATE[ri] += feedback_2019_P.B_ob[ri + 6] *
      feedback_2019_B.TmpSignalConversionAtStateobser[2];
  }

  /* End of Derivatives for StateSpace: '<S1>/State observer' */

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE_g = 0.0;
  _rtXdot->TransferFcn_CSTATE_g += feedback_2019_P.TransferFcn_A_f *
    feedback_2019_X.TransferFcn_CSTATE_g;
  _rtXdot->TransferFcn_CSTATE_g += feedback_2019_B.Step;

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE_e = 0.0;
  _rtXdot->TransferFcn1_CSTATE_e += feedback_2019_P.TransferFcn1_A_c *
    feedback_2019_X.TransferFcn1_CSTATE_e;
  _rtXdot->TransferFcn1_CSTATE_e += feedback_2019_B.TransferFcn;

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE = 0.0;
  _rtXdot->TransferFcn2_CSTATE += feedback_2019_P.TransferFcn2_A *
    feedback_2019_X.TransferFcn2_CSTATE;
  _rtXdot->TransferFcn2_CSTATE += feedback_2019_B.TransferFcn1;
}

/* Model initialize function */
void feedback_2019_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)feedback_2019_M, 0,
                sizeof(RT_MODEL_feedback_2019_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&feedback_2019_M->solverInfo,
                          &feedback_2019_M->Timing.simTimeStep);
    rtsiSetTPtr(&feedback_2019_M->solverInfo, &rtmGetTPtr(feedback_2019_M));
    rtsiSetStepSizePtr(&feedback_2019_M->solverInfo,
                       &feedback_2019_M->Timing.stepSize0);
    rtsiSetdXPtr(&feedback_2019_M->solverInfo, &feedback_2019_M->derivs);
    rtsiSetContStatesPtr(&feedback_2019_M->solverInfo, (real_T **)
                         &feedback_2019_M->contStates);
    rtsiSetNumContStatesPtr(&feedback_2019_M->solverInfo,
      &feedback_2019_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&feedback_2019_M->solverInfo,
      &feedback_2019_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&feedback_2019_M->solverInfo,
      &feedback_2019_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&feedback_2019_M->solverInfo,
      &feedback_2019_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&feedback_2019_M->solverInfo, (&rtmGetErrorStatus
      (feedback_2019_M)));
    rtsiSetRTModelPtr(&feedback_2019_M->solverInfo, feedback_2019_M);
  }

  rtsiSetSimTimeStep(&feedback_2019_M->solverInfo, MAJOR_TIME_STEP);
  feedback_2019_M->intgData.f[0] = feedback_2019_M->odeF[0];
  feedback_2019_M->contStates = ((X_feedback_2019_T *) &feedback_2019_X);
  rtsiSetSolverData(&feedback_2019_M->solverInfo, (void *)
                    &feedback_2019_M->intgData);
  rtsiSetSolverName(&feedback_2019_M->solverInfo,"ode1");
  rtmSetTPtr(feedback_2019_M, &feedback_2019_M->Timing.tArray[0]);
  rtmSetTFinal(feedback_2019_M, -1);
  feedback_2019_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  feedback_2019_M->Sizes.checksums[0] = (1335590053U);
  feedback_2019_M->Sizes.checksums[1] = (1369214997U);
  feedback_2019_M->Sizes.checksums[2] = (254063470U);
  feedback_2019_M->Sizes.checksums[3] = (2600211770U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    feedback_2019_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(feedback_2019_M->extModeInfo,
      &feedback_2019_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(feedback_2019_M->extModeInfo,
                        feedback_2019_M->Sizes.checksums);
    rteiSetTPtr(feedback_2019_M->extModeInfo, rtmGetTPtr(feedback_2019_M));
  }

  /* block I/O */
  {
    feedback_2019_B.Step = 0.0;
    feedback_2019_B.posizione = 0.0;
    feedback_2019_B.corrente = 0.0;
    feedback_2019_B.FilterCoefficient = 0.0;
    feedback_2019_B.TransferFcn = 0.0;
    feedback_2019_B.TransferFcn1 = 0.0;
    feedback_2019_B.TransferFcn2 = 0.0;
    feedback_2019_B.Saturation = 0.0;
    feedback_2019_B.TmpSignalConversionAtStateobser[0] = 0.0;
    feedback_2019_B.TmpSignalConversionAtStateobser[1] = 0.0;
    feedback_2019_B.TmpSignalConversionAtStateobser[2] = 0.0;
    feedback_2019_B.Gain = 0.0;
    feedback_2019_B.IntegralGain = 0.0;
    feedback_2019_B.K[0] = 0.0;
    feedback_2019_B.K[1] = 0.0;
    feedback_2019_B.K[2] = 0.0;
    feedback_2019_B.beta = 0.0;
  }

  /* states (continuous) */
  {
    (void) memset((void *)&feedback_2019_X, 0,
                  sizeof(X_feedback_2019_T));
  }

  /* states (dwork) */
  (void) memset((void *)&feedback_2019_DW, 0,
                sizeof(DW_feedback_2019_T));
  feedback_2019_DW.HILInitialize_AOVoltages[0] = 0.0;
  feedback_2019_DW.HILInitialize_AOVoltages[1] = 0.0;
  feedback_2019_DW.BallPositionandCurrent_Buffer[0] = 0.0;
  feedback_2019_DW.BallPositionandCurrent_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    feedback_2019_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: feedback_2019/HIL Initialize (hil_initialize_block) */
  {
    static const t_uint analog_input_channels[2U] = {
      0
      , 1
    };

    static const t_double analog_input_minimums[2U] = {
      -10.0
      , -10.0
    };

    static const t_double analog_input_maximums[2U] = {
      10.0
      , 10.0
    };

    static const t_uint analog_output_channels[2U] = {
      0
      , 1
    };

    static const t_double analog_output_minimums[2U] = {
      -10.0
      , -10.0
    };

    static const t_double analog_output_maximums[2U] = {
      10.0
      , 10.0
    };

    static const t_double initial_analog_outputs[2U] = {
      0.0
      , 0.0
    };

    static const t_uint encoder_input_channels[2U] = {
      0
      , 1
    };

    static const t_encoder_quadrature_mode encoder_quadrature[2U] = {
      ENCODER_QUADRATURE_4X
      , ENCODER_QUADRATURE_4X
    };

    static const t_int32 initial_encoder_counts[2U] = {
      0
      , 0
    };

    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0", &feedback_2019_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(feedback_2019_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(feedback_2019_DW.HILInitialize_Card,
      "d0=digital;d1=digital;led=auto;update_rate=normal;decimation=1", 63);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(feedback_2019_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(feedback_2019_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(feedback_2019_M, _rt_error_message);
      return;
    }

    if (!is_switching) {
      result = hil_set_analog_input_ranges(feedback_2019_DW.HILInitialize_Card,
        analog_input_channels, 2U,
        analog_input_minimums, analog_input_maximums);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(feedback_2019_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_set_analog_output_ranges(feedback_2019_DW.HILInitialize_Card,
        analog_output_channels, 2U,
        analog_output_minimums, analog_output_maximums);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(feedback_2019_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_write_analog(feedback_2019_DW.HILInitialize_Card,
        analog_output_channels, 2U, initial_analog_outputs);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(feedback_2019_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_set_encoder_quadrature_mode
        (feedback_2019_DW.HILInitialize_Card, encoder_input_channels, 2U,
         (t_encoder_quadrature_mode *) encoder_quadrature);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(feedback_2019_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_set_encoder_counts(feedback_2019_DW.HILInitialize_Card,
        encoder_input_channels, 2U, initial_encoder_counts);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(feedback_2019_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for TransferFcn: '<S1>/Transfer Fcn' */
  feedback_2019_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S37>/Integrator' */
  feedback_2019_X.Integrator_CSTATE =
    feedback_2019_P.PIDController_InitialConditio_i;

  /* InitializeConditions for Integrator: '<S32>/Filter' */
  feedback_2019_X.Filter_CSTATE =
    feedback_2019_P.PIDController_InitialConditionF;

  /* InitializeConditions for TransferFcn: '<S1>/Transfer Fcn1' */
  feedback_2019_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for StateSpace: '<S1>/State observer' */
  feedback_2019_X.Stateobserver_CSTATE[0] =
    feedback_2019_P.Stateobserver_InitialCondition[0];
  feedback_2019_X.Stateobserver_CSTATE[1] =
    feedback_2019_P.Stateobserver_InitialCondition[1];
  feedback_2019_X.Stateobserver_CSTATE[2] =
    feedback_2019_P.Stateobserver_InitialCondition[2];

  /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn' */
  feedback_2019_X.TransferFcn_CSTATE_g = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn1' */
  feedback_2019_X.TransferFcn1_CSTATE_e = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn2' */
  feedback_2019_X.TransferFcn2_CSTATE = 0.0;
}

/* Model terminate function */
void feedback_2019_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: feedback_2019/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    static const t_uint analog_output_channels[2U] = {
      0
      , 1
    };

    hil_task_stop_all(feedback_2019_DW.HILInitialize_Card);
    hil_monitor_stop_all(feedback_2019_DW.HILInitialize_Card);
    is_switching = false;
    if ((feedback_2019_P.HILInitialize_AOTerminate && !is_switching) ||
        (feedback_2019_P.HILInitialize_AOExit && is_switching)) {
      feedback_2019_DW.HILInitialize_AOVoltages[0] =
        feedback_2019_P.HILInitialize_AOFinal;
      feedback_2019_DW.HILInitialize_AOVoltages[1] =
        feedback_2019_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(feedback_2019_DW.HILInitialize_Card,
        analog_output_channels, num_final_analog_outputs,
        &feedback_2019_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(feedback_2019_M, _rt_error_message);
      }
    }

    hil_task_delete_all(feedback_2019_DW.HILInitialize_Card);
    hil_monitor_delete_all(feedback_2019_DW.HILInitialize_Card);
    hil_close(feedback_2019_DW.HILInitialize_Card);
    feedback_2019_DW.HILInitialize_Card = NULL;
  }
}
