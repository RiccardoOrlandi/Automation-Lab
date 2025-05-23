/*
 * feedback_lin_RLS_Template_2019.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "feedback_lin_RLS_Template_2019".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Fri May 23 13:05:15 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "feedback_lin_RLS_Template_2019.h"
#include "feedback_lin_RLS_Template_2019_private.h"
#include "feedback_lin_RLS_Template_2019_dt.h"

/* Block signals (default storage) */
B_feedback_lin_RLS_Template_2_T feedback_lin_RLS_Template_201_B;

/* Continuous states */
X_feedback_lin_RLS_Template_2_T feedback_lin_RLS_Template_201_X;

/* Block states (default storage) */
DW_feedback_lin_RLS_Template__T feedback_lin_RLS_Template_20_DW;

/* Real-time model */
RT_MODEL_feedback_lin_RLS_Tem_T feedback_lin_RLS_Template_20_M_;
RT_MODEL_feedback_lin_RLS_Tem_T *const feedback_lin_RLS_Template_20_M =
  &feedback_lin_RLS_Template_20_M_;

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
  feedback_lin_RLS_Template_2019_derivatives();
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
void feedback_lin_RLS_Template_2019_step(void)
{
  /* local block i/o variables */
  real_T rtb_Delay1_a;
  real_T rtb_TmpSignalConversionAtDelay1[3];
  real_T rtb_BallPositionandCurrent_o1;
  real_T rtb_BallPositionandCurrent_o2;
  real_T coeff[4];
  int32_T k;
  real_T beta;
  real_T xdot3;
  real_T dBdx2;
  real_T rtb_Add1_c;
  real_T rtb_Clock;
  real_T rtb_x_hat[3];
  real_T rtb_phi[2];
  real_T tmp[2];
  real_T xdot3_tmp;
  if (rtmIsMajorTimeStep(feedback_lin_RLS_Template_20_M)) {
    /* set solver stop time */
    if (!(feedback_lin_RLS_Template_20_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&feedback_lin_RLS_Template_20_M->solverInfo,
                            ((feedback_lin_RLS_Template_20_M->Timing.clockTickH0
        + 1) * feedback_lin_RLS_Template_20_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&feedback_lin_RLS_Template_20_M->solverInfo,
                            ((feedback_lin_RLS_Template_20_M->Timing.clockTick0
        + 1) * feedback_lin_RLS_Template_20_M->Timing.stepSize0 +
        feedback_lin_RLS_Template_20_M->Timing.clockTickH0 *
        feedback_lin_RLS_Template_20_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(feedback_lin_RLS_Template_20_M)) {
    feedback_lin_RLS_Template_20_M->Timing.t[0] = rtsiGetT
      (&feedback_lin_RLS_Template_20_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(feedback_lin_RLS_Template_20_M)) {
    /* S-Function (hil_read_analog_block): '<S2>/Ball Position and Current' */

    /* S-Function Block: feedback_lin_RLS_Template_2019/Subsystem/Ball Position and Current (hil_read_analog_block) */
    {
      t_error result = hil_read_analog
        (feedback_lin_RLS_Template_20_DW.HILInitialize_Card,
         feedback_lin_RLS_Template_201_P.BallPositionandCurrent_channels, 2,
         &feedback_lin_RLS_Template_20_DW.BallPositionandCurrent_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(feedback_lin_RLS_Template_20_M, _rt_error_message);
      }

      rtb_BallPositionandCurrent_o1 =
        feedback_lin_RLS_Template_20_DW.BallPositionandCurrent_Buffer[0];
      rtb_BallPositionandCurrent_o2 =
        feedback_lin_RLS_Template_20_DW.BallPositionandCurrent_Buffer[1];
    }

    /* Sum: '<S2>/Add' incorporates:
     *  Constant: '<S2>/Constant1'
     */
    feedback_lin_RLS_Template_201_B.corrente = rtb_BallPositionandCurrent_o2 +
      feedback_lin_RLS_Template_201_P.offset_corrente_volt;
  }

  /* Clock: '<Root>/Clock' */
  rtb_Clock = feedback_lin_RLS_Template_20_M->Timing.t[0];

  /* Switch: '<Root>/Switch1' incorporates:
   *  Step: '<Root>/Step'
   *  Switch: '<Root>/Switch'
   */
  if (rtb_Clock > feedback_lin_RLS_Template_201_P.Switch1_Threshold) {
    /* Switch: '<Root>/Switch2' incorporates:
     *  Sin: '<Root>/Sine Wave1'
     *  Step: '<Root>/Step1'
     */
    if (rtb_Clock > feedback_lin_RLS_Template_201_P.Switch2_Threshold) {
      feedback_lin_RLS_Template_201_B.Switch1 = sin
        (feedback_lin_RLS_Template_201_P.SineWave1_Freq *
         feedback_lin_RLS_Template_20_M->Timing.t[0] +
         feedback_lin_RLS_Template_201_P.SineWave1_Phase) *
        feedback_lin_RLS_Template_201_P.SineWave1_Amp +
        feedback_lin_RLS_Template_201_P.SineWave1_Bias;
    } else if (feedback_lin_RLS_Template_20_M->Timing.t[0] <
               feedback_lin_RLS_Template_201_P.Step1_Time) {
      /* Step: '<Root>/Step1' */
      feedback_lin_RLS_Template_201_B.Switch1 =
        feedback_lin_RLS_Template_201_P.Step1_Y0;
    } else {
      feedback_lin_RLS_Template_201_B.Switch1 =
        feedback_lin_RLS_Template_201_P.Step1_YFinal;
    }

    /* End of Switch: '<Root>/Switch2' */
  } else if (rtb_Clock > feedback_lin_RLS_Template_201_P.Switch_Threshold) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Sin: '<Root>/Sine Wave'
     */
    feedback_lin_RLS_Template_201_B.Switch1 = sin
      (feedback_lin_RLS_Template_201_P.SineWave_Freq *
       feedback_lin_RLS_Template_20_M->Timing.t[0] +
       feedback_lin_RLS_Template_201_P.SineWave_Phase) *
      feedback_lin_RLS_Template_201_P.SineWave_Amp +
      feedback_lin_RLS_Template_201_P.SineWave_Bias;
  } else if (feedback_lin_RLS_Template_20_M->Timing.t[0] <
             feedback_lin_RLS_Template_201_P.Step_Time) {
    /* Step: '<Root>/Step' */
    feedback_lin_RLS_Template_201_B.Switch1 =
      feedback_lin_RLS_Template_201_P.Step_Y0;
  } else {
    feedback_lin_RLS_Template_201_B.Switch1 =
      feedback_lin_RLS_Template_201_P.Step_YFinal;
  }

  /* End of Switch: '<Root>/Switch1' */
  if (rtmIsMajorTimeStep(feedback_lin_RLS_Template_20_M)) {
    /* Gain: '<S2>/Gain1' incorporates:
     *  Constant: '<S2>/Constant'
     *  Sum: '<S2>/Add1'
     */
    feedback_lin_RLS_Template_201_B.posizione =
      (feedback_lin_RLS_Template_201_P.offset_posizione_volt +
       rtb_BallPositionandCurrent_o1) * feedback_lin_RLS_Template_201_P.Kb;
  }

  /* ManualSwitch: '<S1>/Manual Switch1' incorporates:
   *  TransferFcn: '<S1>/Transfer Fcn'
   */
  if (feedback_lin_RLS_Template_201_P.ManualSwitch1_CurrentSetting == 1) {
    feedback_lin_RLS_Template_201_B.ManualSwitch1 =
      feedback_lin_RLS_Template_201_B.posizione;
  } else {
    feedback_lin_RLS_Template_201_B.ManualSwitch1 =
      feedback_lin_RLS_Template_201_P.TransferFcn_C *
      feedback_lin_RLS_Template_201_X.TransferFcn_CSTATE;
  }

  /* End of ManualSwitch: '<S1>/Manual Switch1' */

  /* Sum: '<S4>/Add1' */
  rtb_Add1_c = feedback_lin_RLS_Template_201_B.Switch1 -
    feedback_lin_RLS_Template_201_B.ManualSwitch1;

  /* ManualSwitch: '<S1>/Manual Switch2' incorporates:
   *  TransferFcn: '<S1>/Transfer Fcn1'
   */
  if (feedback_lin_RLS_Template_201_P.ManualSwitch2_CurrentSetting == 1) {
    feedback_lin_RLS_Template_201_B.ManualSwitch2 =
      feedback_lin_RLS_Template_201_B.corrente;
  } else {
    feedback_lin_RLS_Template_201_B.ManualSwitch2 =
      feedback_lin_RLS_Template_201_P.TransferFcn1_C *
      feedback_lin_RLS_Template_201_X.TransferFcn1_CSTATE;
  }

  /* End of ManualSwitch: '<S1>/Manual Switch2' */

  /* TransferFcn: '<S1>/Transfer Fcn2' */
  feedback_lin_RLS_Template_201_B.TransferFcn2 = 0.0;
  feedback_lin_RLS_Template_201_B.TransferFcn2 +=
    feedback_lin_RLS_Template_201_P.TransferFcn2_C *
    feedback_lin_RLS_Template_201_X.TransferFcn2_CSTATE;
  feedback_lin_RLS_Template_201_B.TransferFcn2 +=
    feedback_lin_RLS_Template_201_P.TransferFcn2_D *
    feedback_lin_RLS_Template_201_B.posizione;

  /* TransferFcn: '<S4>/Transfer Fcn' */
  feedback_lin_RLS_Template_201_B.TransferFcn = 0.0;
  feedback_lin_RLS_Template_201_B.TransferFcn +=
    feedback_lin_RLS_Template_201_P.TransferFcn_C_b *
    feedback_lin_RLS_Template_201_X.TransferFcn_CSTATE_o;
  feedback_lin_RLS_Template_201_B.TransferFcn +=
    feedback_lin_RLS_Template_201_P.TransferFcn_D *
    feedback_lin_RLS_Template_201_B.Switch1;

  /* TransferFcn: '<S4>/Transfer Fcn1' */
  feedback_lin_RLS_Template_201_B.TransferFcn1 = 0.0;
  feedback_lin_RLS_Template_201_B.TransferFcn1 +=
    feedback_lin_RLS_Template_201_P.TransferFcn1_C_b *
    feedback_lin_RLS_Template_201_X.TransferFcn1_CSTATE_e;
  feedback_lin_RLS_Template_201_B.TransferFcn1 +=
    feedback_lin_RLS_Template_201_P.TransferFcn1_D *
    feedback_lin_RLS_Template_201_B.TransferFcn;

  /* TransferFcn: '<S4>/Transfer Fcn2' */
  feedback_lin_RLS_Template_201_B.TransferFcn2_a = 0.0;
  feedback_lin_RLS_Template_201_B.TransferFcn2_a +=
    feedback_lin_RLS_Template_201_P.TransferFcn2_C_j *
    feedback_lin_RLS_Template_201_X.TransferFcn2_CSTATE_j;
  feedback_lin_RLS_Template_201_B.TransferFcn2_a +=
    feedback_lin_RLS_Template_201_P.TransferFcn2_D_g *
    feedback_lin_RLS_Template_201_B.TransferFcn1;
  if (rtmIsMajorTimeStep(feedback_lin_RLS_Template_20_M)) {
    /* Delay: '<S58>/Delay1' */
    rtb_Delay1_a = feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_p;

    /* MATLAB Function: '<S55>/Regressor' incorporates:
     *  Constant: '<S55>/Constant1'
     *  Delay: '<S5>/Delay3'
     */
    /* MATLAB Function 'Subsystem3/Subsystem/Regressor': '<S61>:1' */
    /* '<S61>:1:3' */
    xdot3 = feedback_lin_RLS_Template_20_DW.Delay3_DSTATE[1] /
      (feedback_lin_RLS_Template_201_P.y0 -
       feedback_lin_RLS_Template_20_DW.Delay3_DSTATE[0]);
    rtb_Clock = xdot3 * xdot3;

    /* MATLAB Function: '<S55>/MATLAB Function' incorporates:
     *  Constant: '<S55>/Constant'
     *  Constant: '<S58>/Constant'
     *  Delay: '<S55>/Delay'
     *  Delay: '<S55>/Delay1'
     *  Delay: '<S58>/Delay2'
     *  Gain: '<S58>/Gain'
     *  Sum: '<S58>/Add1'
     */
    /* MATLAB Function 'Subsystem3/Subsystem/MATLAB Function': '<S59>:1' */
    /* '<S59>:1:3' */
    xdot3_tmp = feedback_lin_RLS_Template_20_DW.Delay1_DSTATE * rtb_Clock *
      rtb_Clock;
    xdot3 = feedback_lin_RLS_Template_20_DW.Delay1_DSTATE /
      feedback_lin_RLS_Template_201_P.Subsystem_mu - xdot3_tmp *
      feedback_lin_RLS_Template_20_DW.Delay1_DSTATE / (xdot3_tmp +
      feedback_lin_RLS_Template_201_P.Subsystem_mu) /
      feedback_lin_RLS_Template_201_P.Subsystem_mu;

    /* '<S59>:1:4' */
    feedback_lin_RLS_Template_201_B.tho_g =
      ((((feedback_lin_RLS_Template_201_B.posizione -
          feedback_lin_RLS_Template_201_P.Gain_Gain * rtb_Delay1_a) +
         feedback_lin_RLS_Template_20_DW.Delay2_DSTATE) +
        feedback_lin_RLS_Template_201_P.Constant_Value) - rtb_Clock *
       feedback_lin_RLS_Template_20_DW.Delay_DSTATE) * (xdot3 * rtb_Clock) +
      feedback_lin_RLS_Template_20_DW.Delay_DSTATE;
    feedback_lin_RLS_Template_201_B.Vo_g = xdot3;

    /* MATLAB Function: '<S55>/MATLAB Function1' incorporates:
     *  Constant: '<S55>/Constant2'
     */
    /* MATLAB Function 'Subsystem3/Subsystem/MATLAB Function1': '<S60>:1' */
    /* '<S60>:1:3' */
    feedback_lin_RLS_Template_201_B.k_mag =
      feedback_lin_RLS_Template_201_B.tho_g * feedback_lin_RLS_Template_201_P.m /
      4.0E-6;

    /* MATLAB Function: '<S56>/regressor' incorporates:
     *  Delay: '<S5>/Delay1'
     *  Delay: '<S5>/Delay2'
     */
    /* MATLAB Function 'Subsystem3/Subsystem1/regressor': '<S64>:1' */
    /* '<S64>:1:3' */
    rtb_phi[0] = -feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_a[1];
    rtb_phi[1] = feedback_lin_RLS_Template_20_DW.Delay2_DSTATE_h;

    /* MATLAB Function: '<S56>/MATLAB Function' incorporates:
     *  Constant: '<S56>/Constant'
     *  Delay: '<S56>/Delay'
     *  Delay: '<S56>/Delay1'
     *  Delay: '<S58>/Delay3'
     *  Delay: '<S5>/Delay1'
     *  MATLAB Function: '<S56>/regressor'
     *  Sum: '<S58>/Add'
     */
    /* MATLAB Function 'Subsystem3/Subsystem1/MATLAB Function': '<S62>:1' */
    /* '<S62>:1:3' */
    rtb_Clock = feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_f[0] *
      -feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_a[1];
    xdot3 = rtb_Clock + feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_f[2] *
      rtb_phi[1];
    xdot3_tmp = feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_f[3] * rtb_phi[1];
    dBdx2 = feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_f[1] *
      -feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_a[1] + xdot3_tmp;
    coeff[0] = xdot3 * -feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_a[1];
    coeff[1] = dBdx2 * -feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_a[1];
    coeff[2] = xdot3 * rtb_phi[1];
    coeff[3] = dBdx2 * rtb_phi[1];
    rtb_Clock = ((rtb_Clock + rtb_phi[1] *
                  feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_f[1]) *
                 -feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_a[1] +
                 (-feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_a[1] *
                  feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_f[2] + xdot3_tmp)
                 * rtb_phi[1]) + feedback_lin_RLS_Template_201_P.Subsystem1_mu;

    /* '<S62>:1:4' */
    xdot3 = 0.0;
    for (k = 0; k < 2; k++) {
      xdot3 += rtb_phi[k] * feedback_lin_RLS_Template_20_DW.Delay_DSTATE_d[k];
      xdot3_tmp = coeff[k + 2];
      feedback_lin_RLS_Template_201_B.Vo[k] =
        feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_f[k] /
        feedback_lin_RLS_Template_201_P.Subsystem1_mu - (xdot3_tmp *
        feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_f[1] + coeff[k] *
        feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_f[0]) / rtb_Clock /
        feedback_lin_RLS_Template_201_P.Subsystem1_mu;
      dBdx2 = feedback_lin_RLS_Template_201_B.Vo[k] * rtb_phi[0];
      feedback_lin_RLS_Template_201_B.Vo[k + 2] =
        feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_f[k + 2] /
        feedback_lin_RLS_Template_201_P.Subsystem1_mu - (xdot3_tmp *
        feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_f[3] + coeff[k] *
        feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_f[2]) / rtb_Clock /
        feedback_lin_RLS_Template_201_P.Subsystem1_mu;
      dBdx2 += feedback_lin_RLS_Template_201_B.Vo[k + 2] * rtb_phi[1];
      tmp[k] = dBdx2;
    }

    rtb_Clock = (feedback_lin_RLS_Template_201_B.corrente -
                 feedback_lin_RLS_Template_20_DW.Delay3_DSTATE_b) - xdot3;
    feedback_lin_RLS_Template_201_B.tho[0] = tmp[0] * rtb_Clock +
      feedback_lin_RLS_Template_20_DW.Delay_DSTATE_d[0];
    feedback_lin_RLS_Template_201_B.tho[1] = tmp[1] * rtb_Clock +
      feedback_lin_RLS_Template_20_DW.Delay_DSTATE_d[1];

    /* End of MATLAB Function: '<S56>/MATLAB Function' */

    /* MATLAB Function: '<S56>/MATLAB Function2' */
    /* MATLAB Function 'Subsystem3/Subsystem1/MATLAB Function2': '<S63>:1' */
    /* '<S63>:1:3' */
    feedback_lin_RLS_Template_201_B.R = feedback_lin_RLS_Template_201_B.tho[0] /
      feedback_lin_RLS_Template_201_B.tho[1];

    /* '<S63>:1:4' */
    feedback_lin_RLS_Template_201_B.Lc = 0.002 /
      feedback_lin_RLS_Template_201_B.tho[1];

    /* MATLAB Function: '<S4>/MATLAB Function2' incorporates:
     *  Constant: '<S4>/Constant'
     */
    /* MATLAB Function 'Subsystem2/MATLAB Function2': '<S9>:1' */
    /* '<S9>:1:4' */
    /* '<S9>:1:6' */
    /* '<S9>:1:7' */
    /* '<S9>:1:8' */
    /* '<S9>:1:9' */
    /* '<S9>:1:10' */
    /* '<S9>:1:12' */
    feedback_lin_RLS_Template_201_B.theta[0] =
      feedback_lin_RLS_Template_201_P.Constant_Value_d[0];
    feedback_lin_RLS_Template_201_B.theta[1] =
      feedback_lin_RLS_Template_201_P.Constant_Value_d[3];
    feedback_lin_RLS_Template_201_B.theta[2] =
      feedback_lin_RLS_Template_201_P.Constant_Value_d[2];
    feedback_lin_RLS_Template_201_B.theta[3] =
      feedback_lin_RLS_Template_201_P.Constant_Value_d[1];

    /* Saturate: '<S5>/Saturation1' */
    if (feedback_lin_RLS_Template_201_B.R >
        feedback_lin_RLS_Template_201_P.Saturation1_UpperSat) {
      /* MATLAB Function: '<S4>/MATLAB Function2' */
      feedback_lin_RLS_Template_201_B.theta[4] =
        feedback_lin_RLS_Template_201_P.Saturation1_UpperSat;
    } else if (feedback_lin_RLS_Template_201_B.R <
               feedback_lin_RLS_Template_201_P.Saturation1_LowerSat) {
      /* MATLAB Function: '<S4>/MATLAB Function2' */
      feedback_lin_RLS_Template_201_B.theta[4] =
        feedback_lin_RLS_Template_201_P.Saturation1_LowerSat;
    } else {
      /* MATLAB Function: '<S4>/MATLAB Function2' */
      feedback_lin_RLS_Template_201_B.theta[4] =
        feedback_lin_RLS_Template_201_B.R;
    }

    /* End of Saturate: '<S5>/Saturation1' */

    /* MATLAB Function: '<S4>/MATLAB Function2' incorporates:
     *  Constant: '<S4>/Constant'
     */
    feedback_lin_RLS_Template_201_B.theta[5] =
      feedback_lin_RLS_Template_201_P.Constant_Value_d[4];

    /* MATLAB Function: '<S4>/MATLAB Function1' incorporates:
     *  Constant: '<S4>/Constant1'
     *  Constant: '<S4>/Constant2'
     *  Constant: '<S4>/Constant3'
     */
    /* MATLAB Function 'Subsystem2/MATLAB Function1': '<S8>:1' */
    /* '<S8>:1:3' */
    /* '<S8>:1:4' */
    coeff[0] = 1.0;
    coeff[1] = -feedback_lin_RLS_Template_201_P.Subsystem2_p1;
    coeff[2] = -feedback_lin_RLS_Template_201_P.Subsystem2_p2 *
      -feedback_lin_RLS_Template_201_P.Subsystem2_p1;
    for (k = 1; k + 1 > 1; k--) {
      coeff[k] -= coeff[k - 1] * feedback_lin_RLS_Template_201_P.Subsystem2_p2;
    }

    coeff[3] = -feedback_lin_RLS_Template_201_P.Subsystem2_p3 * coeff[2];
    for (k = 2; k + 1 > 1; k--) {
      coeff[k] -= coeff[k - 1] * feedback_lin_RLS_Template_201_P.Subsystem2_p3;
    }

    /* '<S8>:1:5' */
    feedback_lin_RLS_Template_201_B.K[0] = coeff[1];
    feedback_lin_RLS_Template_201_B.K[1] = coeff[2];
    feedback_lin_RLS_Template_201_B.K[2] = coeff[3];
    rtb_Clock = feedback_lin_RLS_Template_201_B.K[0];
    feedback_lin_RLS_Template_201_B.K[0] = feedback_lin_RLS_Template_201_B.K[2];
    feedback_lin_RLS_Template_201_B.K[2] = rtb_Clock;

    /* End of MATLAB Function: '<S4>/MATLAB Function1' */
  }

  /* MATLAB Function: '<S4>/MATLAB Function' incorporates:
   *  SignalConversion generated from: '<S7>/ SFunction '
   */
  /* MATLAB Function 'Subsystem2/MATLAB Function': '<S7>:1' */
  /* '<S7>:1:4' */
  /* '<S7>:1:5' */
  /* '<S7>:1:6' */
  /* '<S7>:1:7' */
  /* '<S7>:1:8' */
  /* '<S7>:1:9' */
  /* '<S7>:1:10' */
  /* '<S7>:1:13' */
  /* '<S7>:1:14' */
  /* '<S7>:1:15' */
  /* '<S7>:1:18' */
  rtb_Clock = feedback_lin_RLS_Template_201_B.theta[3] -
    feedback_lin_RLS_Template_201_B.ManualSwitch1;

  /* '<S7>:1:24' */
  xdot3 = feedback_lin_RLS_Template_201_B.ManualSwitch2 / rtb_Clock;
  xdot3_tmp = feedback_lin_RLS_Template_201_B.theta[0] /
    feedback_lin_RLS_Template_201_B.theta[2];
  xdot3 = (xdot3_tmp * feedback_lin_RLS_Template_201_B.TransferFcn2 +
           feedback_lin_RLS_Template_201_B.theta[1] /
           feedback_lin_RLS_Template_201_B.theta[2] * (xdot3 * xdot3)) - 9.81;

  /* '<S7>:1:27' */
  /* '<S7>:1:28' */
  dBdx2 = 2.0 * feedback_lin_RLS_Template_201_B.theta[1] *
    feedback_lin_RLS_Template_201_B.ManualSwitch2 / (rtb_Clock * rtb_Clock *
    feedback_lin_RLS_Template_201_B.theta[2]);

  /* '<S7>:1:29' */
  /* '<S7>:1:32' */
  /* '<S7>:1:35' */
  /* '<S7>:1:36' */
  beta = 1.0 / feedback_lin_RLS_Template_201_B.theta[5] * dBdx2;

  /* '<S7>:1:45' */
  /* '<S7>:1:46' */
  /* '<S7>:1:47' */
  /* '<S7>:1:52' */
  /* '<S7>:1:53' */
  /* '<S7>:1:54' */
  /* '<S7>:1:59' */
  /* '<S7>:1:63' */
  feedback_lin_RLS_Template_201_B.beta = beta;

  /* Sum: '<S4>/Add' incorporates:
   *  Gain: '<S45>/Proportional Gain'
   *  Integrator: '<S40>/Integrator'
   *  MATLAB Function: '<S4>/MATLAB Function'
   *  SignalConversion generated from: '<S7>/ SFunction '
   *  Sum: '<S49>/Sum'
   */
  rtb_Clock = ((((feedback_lin_RLS_Template_201_B.TransferFcn2_a -
                  (feedback_lin_RLS_Template_201_B.ManualSwitch1 -
                   feedback_lin_RLS_Template_201_B.Switch1) *
                  feedback_lin_RLS_Template_201_B.K[0]) -
                 (feedback_lin_RLS_Template_201_B.TransferFcn2 -
                  feedback_lin_RLS_Template_201_B.TransferFcn) *
                 feedback_lin_RLS_Template_201_B.K[1]) - (xdot3 -
    feedback_lin_RLS_Template_201_B.TransferFcn1) *
                feedback_lin_RLS_Template_201_B.K[2]) - ((2.0 *
    feedback_lin_RLS_Template_201_B.theta[1] *
    (feedback_lin_RLS_Template_201_B.ManualSwitch2 *
     feedback_lin_RLS_Template_201_B.ManualSwitch2) /
    (feedback_lin_RLS_Template_201_B.theta[2] * rt_powd_snf(rtb_Clock, 3.0)) *
    feedback_lin_RLS_Template_201_B.TransferFcn2 +
    -(feedback_lin_RLS_Template_201_B.theta[4] /
      feedback_lin_RLS_Template_201_B.theta[5]) *
    feedback_lin_RLS_Template_201_B.ManualSwitch2 * dBdx2) + xdot3_tmp * xdot3))
    / beta + (feedback_lin_RLS_Template_201_P.PIDController_P * rtb_Add1_c +
              feedback_lin_RLS_Template_201_X.Integrator_CSTATE);

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Clock > feedback_lin_RLS_Template_201_P.Saturation_UpperSat_h) {
    feedback_lin_RLS_Template_201_B.Saturation =
      feedback_lin_RLS_Template_201_P.Saturation_UpperSat_h;
  } else if (rtb_Clock < feedback_lin_RLS_Template_201_P.Saturation_LowerSat_p)
  {
    feedback_lin_RLS_Template_201_B.Saturation =
      feedback_lin_RLS_Template_201_P.Saturation_LowerSat_p;
  } else {
    feedback_lin_RLS_Template_201_B.Saturation = rtb_Clock;
  }

  /* End of Saturate: '<Root>/Saturation' */
  if (rtmIsMajorTimeStep(feedback_lin_RLS_Template_20_M)) {
  }

  /* StateSpace: '<S1>/State observer' */
  for (k = 0; k < 3; k++) {
    rtb_x_hat[k] = feedback_lin_RLS_Template_201_P.C_ob[k + 6] *
      feedback_lin_RLS_Template_201_X.Stateobserver_CSTATE[2] +
      (feedback_lin_RLS_Template_201_P.C_ob[k + 3] *
       feedback_lin_RLS_Template_201_X.Stateobserver_CSTATE[1] +
       feedback_lin_RLS_Template_201_P.C_ob[k] *
       feedback_lin_RLS_Template_201_X.Stateobserver_CSTATE[0]);
  }

  /* End of StateSpace: '<S1>/State observer' */

  /* MATLAB Function: '<S1>/MATLAB Function' */
  feedback_lin_RLS_Template_201_B.x3_hat = rtb_x_hat[2];

  /* MATLAB Function 'Reduced OBSERVER/MATLAB Function': '<S6>:1' */
  if ((rtb_x_hat[0] <= 0.0) && (feedback_lin_RLS_Template_201_B.x3_hat <= 0.0))
  {
    /* '<S6>:1:3' */
    /* '<S6>:1:4' */
    feedback_lin_RLS_Template_201_B.x3_hat = 0.0;
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function' */
  if (rtmIsMajorTimeStep(feedback_lin_RLS_Template_20_M)) {
  }

  /* SignalConversion generated from: '<S1>/State observer' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   *  Sum: '<S1>/Add'
   *  Sum: '<S1>/Add1'
   *  Sum: '<S1>/Add2'
   */
  feedback_lin_RLS_Template_201_B.TmpSignalConversionAtStateobser[0] =
    feedback_lin_RLS_Template_201_B.Saturation -
    feedback_lin_RLS_Template_201_P.u;
  feedback_lin_RLS_Template_201_B.TmpSignalConversionAtStateobser[1] =
    feedback_lin_RLS_Template_201_B.ManualSwitch1 -
    feedback_lin_RLS_Template_201_P.x1_eq0;
  feedback_lin_RLS_Template_201_B.TmpSignalConversionAtStateobser[2] =
    feedback_lin_RLS_Template_201_B.ManualSwitch2 -
    feedback_lin_RLS_Template_201_P.x2_eq0;

  /* Gain: '<S2>/Gain' */
  feedback_lin_RLS_Template_201_B.Gain =
    feedback_lin_RLS_Template_201_P.Gain_Gain_h *
    feedback_lin_RLS_Template_201_B.Saturation;
  if (rtmIsMajorTimeStep(feedback_lin_RLS_Template_20_M)) {
    /* S-Function (hil_write_analog_block): '<S2>/Voltage' */

    /* S-Function Block: feedback_lin_RLS_Template_2019/Subsystem/Voltage (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog
        (feedback_lin_RLS_Template_20_DW.HILInitialize_Card,
         &feedback_lin_RLS_Template_201_P.Voltage_channels, 1,
         &feedback_lin_RLS_Template_201_B.Gain);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(feedback_lin_RLS_Template_20_M, _rt_error_message);
      }
    }
  }

  /* Gain: '<S37>/Integral Gain' */
  feedback_lin_RLS_Template_201_B.IntegralGain =
    feedback_lin_RLS_Template_201_P.PIDController_I * rtb_Add1_c;
  if (rtmIsMajorTimeStep(feedback_lin_RLS_Template_20_M)) {
    /* Constant: '<S5>/Constant' */
    feedback_lin_RLS_Template_201_B.Constant =
      feedback_lin_RLS_Template_201_P.k_mag_mod;

    /* Constant: '<S5>/Constant1' */
    feedback_lin_RLS_Template_201_B.Constant1 =
      feedback_lin_RLS_Template_201_P.Rtot_mod;

    /* Constant: '<S5>/Constant2' */
    feedback_lin_RLS_Template_201_B.Constant2 =
      feedback_lin_RLS_Template_201_P.Lc_mod;

    /* SignalConversion generated from: '<S5>/Delay1' */
    rtb_TmpSignalConversionAtDelay1[0] =
      feedback_lin_RLS_Template_201_B.posizione;
    rtb_TmpSignalConversionAtDelay1[1] =
      feedback_lin_RLS_Template_201_B.corrente;
    rtb_TmpSignalConversionAtDelay1[2] =
      feedback_lin_RLS_Template_201_B.TransferFcn2;
  }

  if (rtmIsMajorTimeStep(feedback_lin_RLS_Template_20_M)) {
    if (rtmIsMajorTimeStep(feedback_lin_RLS_Template_20_M)) {
      /* Update for Delay: '<S55>/Delay' */
      feedback_lin_RLS_Template_20_DW.Delay_DSTATE =
        feedback_lin_RLS_Template_201_B.tho_g;

      /* Update for Delay: '<S55>/Delay1' */
      feedback_lin_RLS_Template_20_DW.Delay1_DSTATE =
        feedback_lin_RLS_Template_201_B.Vo_g;

      /* Update for Delay: '<S58>/Delay1' */
      feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_p =
        feedback_lin_RLS_Template_201_B.posizione;

      /* Update for Delay: '<S58>/Delay2' */
      feedback_lin_RLS_Template_20_DW.Delay2_DSTATE = rtb_Delay1_a;

      /* Update for Delay: '<S5>/Delay3' */
      feedback_lin_RLS_Template_20_DW.Delay3_DSTATE[0] =
        rtb_TmpSignalConversionAtDelay1[0];
      feedback_lin_RLS_Template_20_DW.Delay3_DSTATE[1] =
        rtb_TmpSignalConversionAtDelay1[1];
      feedback_lin_RLS_Template_20_DW.Delay3_DSTATE[2] =
        rtb_TmpSignalConversionAtDelay1[2];

      /* Update for Delay: '<S56>/Delay' */
      feedback_lin_RLS_Template_20_DW.Delay_DSTATE_d[0] =
        feedback_lin_RLS_Template_201_B.tho[0];
      feedback_lin_RLS_Template_20_DW.Delay_DSTATE_d[1] =
        feedback_lin_RLS_Template_201_B.tho[1];

      /* Update for Delay: '<S56>/Delay1' */
      feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_f[0] =
        feedback_lin_RLS_Template_201_B.Vo[0];
      feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_f[1] =
        feedback_lin_RLS_Template_201_B.Vo[1];
      feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_f[2] =
        feedback_lin_RLS_Template_201_B.Vo[2];
      feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_f[3] =
        feedback_lin_RLS_Template_201_B.Vo[3];

      /* Update for Delay: '<S58>/Delay3' */
      feedback_lin_RLS_Template_20_DW.Delay3_DSTATE_b =
        feedback_lin_RLS_Template_201_B.corrente;

      /* Update for Delay: '<S5>/Delay1' */
      feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_a[0] =
        rtb_TmpSignalConversionAtDelay1[0];
      feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_a[1] =
        rtb_TmpSignalConversionAtDelay1[1];
      feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_a[2] =
        rtb_TmpSignalConversionAtDelay1[2];

      /* Update for Delay: '<S5>/Delay2' */
      feedback_lin_RLS_Template_20_DW.Delay2_DSTATE_h =
        feedback_lin_RLS_Template_201_B.Saturation;
    }

    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, (real_T)feedback_lin_RLS_Template_20_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(feedback_lin_RLS_Template_20_M)) {/* Sample time: [0.002s, 0.0s] */
      rtExtModeUpload(1, (real_T)
                      (((feedback_lin_RLS_Template_20_M->Timing.clockTick1+
                         feedback_lin_RLS_Template_20_M->Timing.clockTickH1*
                         4294967296.0)) * 0.002));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(feedback_lin_RLS_Template_20_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(feedback_lin_RLS_Template_20_M)!=-1) &&
          !((rtmGetTFinal(feedback_lin_RLS_Template_20_M)-
             (((feedback_lin_RLS_Template_20_M->Timing.clockTick1+
                feedback_lin_RLS_Template_20_M->Timing.clockTickH1* 4294967296.0))
              * 0.002)) > (((feedback_lin_RLS_Template_20_M->Timing.clockTick1+
                             feedback_lin_RLS_Template_20_M->Timing.clockTickH1*
              4294967296.0)) * 0.002) * (DBL_EPSILON))) {
        rtmSetErrorStatus(feedback_lin_RLS_Template_20_M, "Simulation finished");
      }

      if (rtmGetStopRequested(feedback_lin_RLS_Template_20_M)) {
        rtmSetErrorStatus(feedback_lin_RLS_Template_20_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&feedback_lin_RLS_Template_20_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++feedback_lin_RLS_Template_20_M->Timing.clockTick0)) {
      ++feedback_lin_RLS_Template_20_M->Timing.clockTickH0;
    }

    feedback_lin_RLS_Template_20_M->Timing.t[0] = rtsiGetSolverStopTime
      (&feedback_lin_RLS_Template_20_M->solverInfo);

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
      feedback_lin_RLS_Template_20_M->Timing.clockTick1++;
      if (!feedback_lin_RLS_Template_20_M->Timing.clockTick1) {
        feedback_lin_RLS_Template_20_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void feedback_lin_RLS_Template_2019_derivatives(void)
{
  int_T ri;
  XDot_feedback_lin_RLS_Templat_T *_rtXdot;
  _rtXdot = ((XDot_feedback_lin_RLS_Templat_T *)
             feedback_lin_RLS_Template_20_M->derivs);

  /* Derivatives for TransferFcn: '<S1>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += feedback_lin_RLS_Template_201_P.TransferFcn_A *
    feedback_lin_RLS_Template_201_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += feedback_lin_RLS_Template_201_B.posizione;

  /* Derivatives for Integrator: '<S40>/Integrator' */
  _rtXdot->Integrator_CSTATE = feedback_lin_RLS_Template_201_B.IntegralGain;

  /* Derivatives for TransferFcn: '<S1>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += feedback_lin_RLS_Template_201_P.TransferFcn1_A
    * feedback_lin_RLS_Template_201_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += feedback_lin_RLS_Template_201_B.corrente;

  /* Derivatives for TransferFcn: '<S1>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE = 0.0;
  _rtXdot->TransferFcn2_CSTATE += feedback_lin_RLS_Template_201_P.TransferFcn2_A
    * feedback_lin_RLS_Template_201_X.TransferFcn2_CSTATE;
  _rtXdot->TransferFcn2_CSTATE += feedback_lin_RLS_Template_201_B.posizione;

  /* Derivatives for TransferFcn: '<S4>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE_o = 0.0;
  _rtXdot->TransferFcn_CSTATE_o +=
    feedback_lin_RLS_Template_201_P.TransferFcn_A_g *
    feedback_lin_RLS_Template_201_X.TransferFcn_CSTATE_o;
  _rtXdot->TransferFcn_CSTATE_o += feedback_lin_RLS_Template_201_B.Switch1;

  /* Derivatives for TransferFcn: '<S4>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE_e = 0.0;
  _rtXdot->TransferFcn1_CSTATE_e +=
    feedback_lin_RLS_Template_201_P.TransferFcn1_A_p *
    feedback_lin_RLS_Template_201_X.TransferFcn1_CSTATE_e;
  _rtXdot->TransferFcn1_CSTATE_e += feedback_lin_RLS_Template_201_B.TransferFcn;

  /* Derivatives for TransferFcn: '<S4>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE_j = 0.0;
  _rtXdot->TransferFcn2_CSTATE_j +=
    feedback_lin_RLS_Template_201_P.TransferFcn2_A_k *
    feedback_lin_RLS_Template_201_X.TransferFcn2_CSTATE_j;
  _rtXdot->TransferFcn2_CSTATE_j += feedback_lin_RLS_Template_201_B.TransferFcn1;

  /* Derivatives for StateSpace: '<S1>/State observer' */
  _rtXdot->Stateobserver_CSTATE[0] = 0.0;
  _rtXdot->Stateobserver_CSTATE[1] = 0.0;
  _rtXdot->Stateobserver_CSTATE[2] = 0.0;
  for (ri = 0; ri < 3; ri++) {
    _rtXdot->Stateobserver_CSTATE[ri] += feedback_lin_RLS_Template_201_P.A_ob[ri]
      * feedback_lin_RLS_Template_201_X.Stateobserver_CSTATE[0];
    _rtXdot->Stateobserver_CSTATE[ri] += feedback_lin_RLS_Template_201_P.A_ob[ri
      + 3] * feedback_lin_RLS_Template_201_X.Stateobserver_CSTATE[1];
    _rtXdot->Stateobserver_CSTATE[ri] += feedback_lin_RLS_Template_201_P.A_ob[ri
      + 6] * feedback_lin_RLS_Template_201_X.Stateobserver_CSTATE[2];
    _rtXdot->Stateobserver_CSTATE[ri] += feedback_lin_RLS_Template_201_P.B_ob[ri]
      * feedback_lin_RLS_Template_201_B.TmpSignalConversionAtStateobser[0];
    _rtXdot->Stateobserver_CSTATE[ri] += feedback_lin_RLS_Template_201_P.B_ob[ri
      + 3] * feedback_lin_RLS_Template_201_B.TmpSignalConversionAtStateobser[1];
    _rtXdot->Stateobserver_CSTATE[ri] += feedback_lin_RLS_Template_201_P.B_ob[ri
      + 6] * feedback_lin_RLS_Template_201_B.TmpSignalConversionAtStateobser[2];
  }

  /* End of Derivatives for StateSpace: '<S1>/State observer' */
}

/* Model initialize function */
void feedback_lin_RLS_Template_2019_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)feedback_lin_RLS_Template_20_M, 0,
                sizeof(RT_MODEL_feedback_lin_RLS_Tem_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&feedback_lin_RLS_Template_20_M->solverInfo,
                          &feedback_lin_RLS_Template_20_M->Timing.simTimeStep);
    rtsiSetTPtr(&feedback_lin_RLS_Template_20_M->solverInfo, &rtmGetTPtr
                (feedback_lin_RLS_Template_20_M));
    rtsiSetStepSizePtr(&feedback_lin_RLS_Template_20_M->solverInfo,
                       &feedback_lin_RLS_Template_20_M->Timing.stepSize0);
    rtsiSetdXPtr(&feedback_lin_RLS_Template_20_M->solverInfo,
                 &feedback_lin_RLS_Template_20_M->derivs);
    rtsiSetContStatesPtr(&feedback_lin_RLS_Template_20_M->solverInfo, (real_T **)
                         &feedback_lin_RLS_Template_20_M->contStates);
    rtsiSetNumContStatesPtr(&feedback_lin_RLS_Template_20_M->solverInfo,
      &feedback_lin_RLS_Template_20_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&feedback_lin_RLS_Template_20_M->solverInfo,
      &feedback_lin_RLS_Template_20_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&feedback_lin_RLS_Template_20_M->solverInfo,
       &feedback_lin_RLS_Template_20_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&feedback_lin_RLS_Template_20_M->solverInfo,
       &feedback_lin_RLS_Template_20_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&feedback_lin_RLS_Template_20_M->solverInfo,
                          (&rtmGetErrorStatus(feedback_lin_RLS_Template_20_M)));
    rtsiSetRTModelPtr(&feedback_lin_RLS_Template_20_M->solverInfo,
                      feedback_lin_RLS_Template_20_M);
  }

  rtsiSetSimTimeStep(&feedback_lin_RLS_Template_20_M->solverInfo,
                     MAJOR_TIME_STEP);
  feedback_lin_RLS_Template_20_M->intgData.f[0] =
    feedback_lin_RLS_Template_20_M->odeF[0];
  feedback_lin_RLS_Template_20_M->contStates = ((X_feedback_lin_RLS_Template_2_T
    *) &feedback_lin_RLS_Template_201_X);
  rtsiSetSolverData(&feedback_lin_RLS_Template_20_M->solverInfo, (void *)
                    &feedback_lin_RLS_Template_20_M->intgData);
  rtsiSetSolverName(&feedback_lin_RLS_Template_20_M->solverInfo,"ode1");
  rtmSetTPtr(feedback_lin_RLS_Template_20_M,
             &feedback_lin_RLS_Template_20_M->Timing.tArray[0]);
  rtmSetTFinal(feedback_lin_RLS_Template_20_M, -1);
  feedback_lin_RLS_Template_20_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  feedback_lin_RLS_Template_20_M->Sizes.checksums[0] = (1051783073U);
  feedback_lin_RLS_Template_20_M->Sizes.checksums[1] = (3936676692U);
  feedback_lin_RLS_Template_20_M->Sizes.checksums[2] = (1987929828U);
  feedback_lin_RLS_Template_20_M->Sizes.checksums[3] = (1925087470U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[13];
    feedback_lin_RLS_Template_20_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(feedback_lin_RLS_Template_20_M->extModeInfo,
      &feedback_lin_RLS_Template_20_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(feedback_lin_RLS_Template_20_M->extModeInfo,
                        feedback_lin_RLS_Template_20_M->Sizes.checksums);
    rteiSetTPtr(feedback_lin_RLS_Template_20_M->extModeInfo, rtmGetTPtr
                (feedback_lin_RLS_Template_20_M));
  }

  /* block I/O */
  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      feedback_lin_RLS_Template_201_B.theta[i] = 0.0;
    }

    feedback_lin_RLS_Template_201_B.corrente = 0.0;
    feedback_lin_RLS_Template_201_B.Switch1 = 0.0;
    feedback_lin_RLS_Template_201_B.posizione = 0.0;
    feedback_lin_RLS_Template_201_B.ManualSwitch1 = 0.0;
    feedback_lin_RLS_Template_201_B.ManualSwitch2 = 0.0;
    feedback_lin_RLS_Template_201_B.TransferFcn2 = 0.0;
    feedback_lin_RLS_Template_201_B.TransferFcn = 0.0;
    feedback_lin_RLS_Template_201_B.TransferFcn1 = 0.0;
    feedback_lin_RLS_Template_201_B.TransferFcn2_a = 0.0;
    feedback_lin_RLS_Template_201_B.Saturation = 0.0;
    feedback_lin_RLS_Template_201_B.TmpSignalConversionAtStateobser[0] = 0.0;
    feedback_lin_RLS_Template_201_B.TmpSignalConversionAtStateobser[1] = 0.0;
    feedback_lin_RLS_Template_201_B.TmpSignalConversionAtStateobser[2] = 0.0;
    feedback_lin_RLS_Template_201_B.Gain = 0.0;
    feedback_lin_RLS_Template_201_B.IntegralGain = 0.0;
    feedback_lin_RLS_Template_201_B.Constant = 0.0;
    feedback_lin_RLS_Template_201_B.Constant1 = 0.0;
    feedback_lin_RLS_Template_201_B.Constant2 = 0.0;
    feedback_lin_RLS_Template_201_B.R = 0.0;
    feedback_lin_RLS_Template_201_B.Lc = 0.0;
    feedback_lin_RLS_Template_201_B.tho[0] = 0.0;
    feedback_lin_RLS_Template_201_B.tho[1] = 0.0;
    feedback_lin_RLS_Template_201_B.Vo[0] = 0.0;
    feedback_lin_RLS_Template_201_B.Vo[1] = 0.0;
    feedback_lin_RLS_Template_201_B.Vo[2] = 0.0;
    feedback_lin_RLS_Template_201_B.Vo[3] = 0.0;
    feedback_lin_RLS_Template_201_B.k_mag = 0.0;
    feedback_lin_RLS_Template_201_B.tho_g = 0.0;
    feedback_lin_RLS_Template_201_B.Vo_g = 0.0;
    feedback_lin_RLS_Template_201_B.K[0] = 0.0;
    feedback_lin_RLS_Template_201_B.K[1] = 0.0;
    feedback_lin_RLS_Template_201_B.K[2] = 0.0;
    feedback_lin_RLS_Template_201_B.beta = 0.0;
    feedback_lin_RLS_Template_201_B.x3_hat = 0.0;
  }

  /* states (continuous) */
  {
    (void) memset((void *)&feedback_lin_RLS_Template_201_X, 0,
                  sizeof(X_feedback_lin_RLS_Template_2_T));
  }

  /* states (dwork) */
  (void) memset((void *)&feedback_lin_RLS_Template_20_DW, 0,
                sizeof(DW_feedback_lin_RLS_Template__T));
  feedback_lin_RLS_Template_20_DW.Delay_DSTATE = 0.0;
  feedback_lin_RLS_Template_20_DW.Delay1_DSTATE = 0.0;
  feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_p = 0.0;
  feedback_lin_RLS_Template_20_DW.Delay2_DSTATE = 0.0;
  feedback_lin_RLS_Template_20_DW.Delay3_DSTATE[0] = 0.0;
  feedback_lin_RLS_Template_20_DW.Delay3_DSTATE[1] = 0.0;
  feedback_lin_RLS_Template_20_DW.Delay3_DSTATE[2] = 0.0;
  feedback_lin_RLS_Template_20_DW.Delay_DSTATE_d[0] = 0.0;
  feedback_lin_RLS_Template_20_DW.Delay_DSTATE_d[1] = 0.0;
  feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_f[0] = 0.0;
  feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_f[1] = 0.0;
  feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_f[2] = 0.0;
  feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_f[3] = 0.0;
  feedback_lin_RLS_Template_20_DW.Delay3_DSTATE_b = 0.0;
  feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_a[0] = 0.0;
  feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_a[1] = 0.0;
  feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_a[2] = 0.0;
  feedback_lin_RLS_Template_20_DW.Delay2_DSTATE_h = 0.0;
  feedback_lin_RLS_Template_20_DW.HILInitialize_AOVoltages[0] = 0.0;
  feedback_lin_RLS_Template_20_DW.HILInitialize_AOVoltages[1] = 0.0;
  feedback_lin_RLS_Template_20_DW.BallPositionandCurrent_Buffer[0] = 0.0;
  feedback_lin_RLS_Template_20_DW.BallPositionandCurrent_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    feedback_lin_RLS_Template_20_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: feedback_lin_RLS_Template_2019/HIL Initialize (hil_initialize_block) */
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
    result = hil_open("q2_usb", "0",
                      &feedback_lin_RLS_Template_20_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(feedback_lin_RLS_Template_20_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (feedback_lin_RLS_Template_20_DW.HILInitialize_Card,
       "d0=digital;d1=digital;led=auto;update_rate=normal;decimation=1", 63);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(feedback_lin_RLS_Template_20_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear
      (feedback_lin_RLS_Template_20_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(feedback_lin_RLS_Template_20_M, _rt_error_message);
      return;
    }

    if (!is_switching) {
      result = hil_set_analog_input_ranges
        (feedback_lin_RLS_Template_20_DW.HILInitialize_Card,
         analog_input_channels, 2U,
         analog_input_minimums, analog_input_maximums);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(feedback_lin_RLS_Template_20_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_set_analog_output_ranges
        (feedback_lin_RLS_Template_20_DW.HILInitialize_Card,
         analog_output_channels, 2U,
         analog_output_minimums, analog_output_maximums);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(feedback_lin_RLS_Template_20_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_write_analog
        (feedback_lin_RLS_Template_20_DW.HILInitialize_Card,
         analog_output_channels, 2U, initial_analog_outputs);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(feedback_lin_RLS_Template_20_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_set_encoder_quadrature_mode
        (feedback_lin_RLS_Template_20_DW.HILInitialize_Card,
         encoder_input_channels, 2U, (t_encoder_quadrature_mode *)
         encoder_quadrature);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(feedback_lin_RLS_Template_20_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_set_encoder_counts
        (feedback_lin_RLS_Template_20_DW.HILInitialize_Card,
         encoder_input_channels, 2U, initial_encoder_counts);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(feedback_lin_RLS_Template_20_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for TransferFcn: '<S1>/Transfer Fcn' */
  feedback_lin_RLS_Template_201_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S40>/Integrator' */
  feedback_lin_RLS_Template_201_X.Integrator_CSTATE =
    feedback_lin_RLS_Template_201_P.PIDController_InitialConditionF;

  /* InitializeConditions for TransferFcn: '<S1>/Transfer Fcn1' */
  feedback_lin_RLS_Template_201_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S1>/Transfer Fcn2' */
  feedback_lin_RLS_Template_201_X.TransferFcn2_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S4>/Transfer Fcn' */
  feedback_lin_RLS_Template_201_X.TransferFcn_CSTATE_o = 0.0;

  /* InitializeConditions for TransferFcn: '<S4>/Transfer Fcn1' */
  feedback_lin_RLS_Template_201_X.TransferFcn1_CSTATE_e = 0.0;

  /* InitializeConditions for TransferFcn: '<S4>/Transfer Fcn2' */
  feedback_lin_RLS_Template_201_X.TransferFcn2_CSTATE_j = 0.0;

  /* InitializeConditions for Delay: '<S55>/Delay' */
  feedback_lin_RLS_Template_20_DW.Delay_DSTATE =
    feedback_lin_RLS_Template_201_P.k_mag * 4.0E-6 /
    feedback_lin_RLS_Template_201_P.m;

  /* InitializeConditions for Delay: '<S55>/Delay1' */
  feedback_lin_RLS_Template_20_DW.Delay1_DSTATE =
    feedback_lin_RLS_Template_201_P.Delay1_InitialCondition;

  /* InitializeConditions for Delay: '<S58>/Delay1' */
  feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_p =
    feedback_lin_RLS_Template_201_P.Delay1_InitialCondition_o;

  /* InitializeConditions for Delay: '<S58>/Delay2' */
  feedback_lin_RLS_Template_20_DW.Delay2_DSTATE =
    feedback_lin_RLS_Template_201_P.Delay2_InitialCondition;

  /* InitializeConditions for Delay: '<S5>/Delay3' */
  feedback_lin_RLS_Template_20_DW.Delay3_DSTATE[0] =
    feedback_lin_RLS_Template_201_P.Delay3_InitialCondition[0];
  feedback_lin_RLS_Template_20_DW.Delay3_DSTATE[1] =
    feedback_lin_RLS_Template_201_P.Delay3_InitialCondition[1];
  feedback_lin_RLS_Template_20_DW.Delay3_DSTATE[2] =
    feedback_lin_RLS_Template_201_P.Delay3_InitialCondition[2];

  /* InitializeConditions for Delay: '<S56>/Delay' */
  feedback_lin_RLS_Template_20_DW.Delay_DSTATE_d[0] =
    feedback_lin_RLS_Template_201_P.Delay_InitialCondition[0];
  feedback_lin_RLS_Template_20_DW.Delay_DSTATE_d[1] =
    feedback_lin_RLS_Template_201_P.Delay_InitialCondition[1];

  /* InitializeConditions for Delay: '<S56>/Delay1' */
  feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_f[0] =
    feedback_lin_RLS_Template_201_P.Delay1_InitialCondition_f[0];
  feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_f[1] =
    feedback_lin_RLS_Template_201_P.Delay1_InitialCondition_f[1];
  feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_f[2] =
    feedback_lin_RLS_Template_201_P.Delay1_InitialCondition_f[2];
  feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_f[3] =
    feedback_lin_RLS_Template_201_P.Delay1_InitialCondition_f[3];

  /* InitializeConditions for Delay: '<S58>/Delay3' */
  feedback_lin_RLS_Template_20_DW.Delay3_DSTATE_b =
    feedback_lin_RLS_Template_201_P.Delay3_InitialCondition_a;

  /* InitializeConditions for Delay: '<S5>/Delay2' */
  feedback_lin_RLS_Template_20_DW.Delay2_DSTATE_h =
    feedback_lin_RLS_Template_201_P.Delay2_InitialCondition_j;

  /* InitializeConditions for Delay: '<S5>/Delay1' */
  feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_a[0] =
    feedback_lin_RLS_Template_201_P.Delay1_InitialCondition_i;

  /* InitializeConditions for StateSpace: '<S1>/State observer' */
  feedback_lin_RLS_Template_201_X.Stateobserver_CSTATE[0] =
    feedback_lin_RLS_Template_201_P.Stateobserver_InitialCondition[0];

  /* InitializeConditions for Delay: '<S5>/Delay1' */
  feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_a[1] =
    feedback_lin_RLS_Template_201_P.Delay1_InitialCondition_i;

  /* InitializeConditions for StateSpace: '<S1>/State observer' */
  feedback_lin_RLS_Template_201_X.Stateobserver_CSTATE[1] =
    feedback_lin_RLS_Template_201_P.Stateobserver_InitialCondition[1];

  /* InitializeConditions for Delay: '<S5>/Delay1' */
  feedback_lin_RLS_Template_20_DW.Delay1_DSTATE_a[2] =
    feedback_lin_RLS_Template_201_P.Delay1_InitialCondition_i;

  /* InitializeConditions for StateSpace: '<S1>/State observer' */
  feedback_lin_RLS_Template_201_X.Stateobserver_CSTATE[2] =
    feedback_lin_RLS_Template_201_P.Stateobserver_InitialCondition[2];
}

/* Model terminate function */
void feedback_lin_RLS_Template_2019_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: feedback_lin_RLS_Template_2019/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    static const t_uint analog_output_channels[2U] = {
      0
      , 1
    };

    hil_task_stop_all(feedback_lin_RLS_Template_20_DW.HILInitialize_Card);
    hil_monitor_stop_all(feedback_lin_RLS_Template_20_DW.HILInitialize_Card);
    is_switching = false;
    if ((feedback_lin_RLS_Template_201_P.HILInitialize_AOTerminate &&
         !is_switching) || (feedback_lin_RLS_Template_201_P.HILInitialize_AOExit
         && is_switching)) {
      feedback_lin_RLS_Template_20_DW.HILInitialize_AOVoltages[0] =
        feedback_lin_RLS_Template_201_P.HILInitialize_AOFinal;
      feedback_lin_RLS_Template_20_DW.HILInitialize_AOVoltages[1] =
        feedback_lin_RLS_Template_201_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog
        (feedback_lin_RLS_Template_20_DW.HILInitialize_Card,
         analog_output_channels, num_final_analog_outputs,
         &feedback_lin_RLS_Template_20_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(feedback_lin_RLS_Template_20_M, _rt_error_message);
      }
    }

    hil_task_delete_all(feedback_lin_RLS_Template_20_DW.HILInitialize_Card);
    hil_monitor_delete_all(feedback_lin_RLS_Template_20_DW.HILInitialize_Card);
    hil_close(feedback_lin_RLS_Template_20_DW.HILInitialize_Card);
    feedback_lin_RLS_Template_20_DW.HILInitialize_Card = NULL;
  }
}
