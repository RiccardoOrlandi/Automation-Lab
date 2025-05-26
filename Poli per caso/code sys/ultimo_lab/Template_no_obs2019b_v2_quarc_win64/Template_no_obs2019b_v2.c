/*
 * Template_no_obs2019b_v2.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Template_no_obs2019b_v2".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Fri May 23 12:01:08 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Template_no_obs2019b_v2.h"
#include "Template_no_obs2019b_v2_private.h"
#include "Template_no_obs2019b_v2_dt.h"

/* Block signals (default storage) */
B_Template_no_obs2019b_v2_T Template_no_obs2019b_v2_B;

/* Continuous states */
X_Template_no_obs2019b_v2_T Template_no_obs2019b_v2_X;

/* Block states (default storage) */
DW_Template_no_obs2019b_v2_T Template_no_obs2019b_v2_DW;

/* Real-time model */
RT_MODEL_Template_no_obs2019b_T Template_no_obs2019b_v2_M_;
RT_MODEL_Template_no_obs2019b_T *const Template_no_obs2019b_v2_M =
  &Template_no_obs2019b_v2_M_;

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
  int_T nXc = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Template_no_obs2019b_v2_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T y;
  real_T sr;
  real_T si;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

/* Model step function */
void Template_no_obs2019b_v2_step(void)
{
  /* local block i/o variables */
  real_T rtb_BallPositionandCurrent_o2;
  real_T rtb_WhiteNoise;
  if (rtmIsMajorTimeStep(Template_no_obs2019b_v2_M)) {
    /* set solver stop time */
    if (!(Template_no_obs2019b_v2_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Template_no_obs2019b_v2_M->solverInfo,
                            ((Template_no_obs2019b_v2_M->Timing.clockTickH0 + 1)
        * Template_no_obs2019b_v2_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Template_no_obs2019b_v2_M->solverInfo,
                            ((Template_no_obs2019b_v2_M->Timing.clockTick0 + 1) *
        Template_no_obs2019b_v2_M->Timing.stepSize0 +
        Template_no_obs2019b_v2_M->Timing.clockTickH0 *
        Template_no_obs2019b_v2_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Template_no_obs2019b_v2_M)) {
    Template_no_obs2019b_v2_M->Timing.t[0] = rtsiGetT
      (&Template_no_obs2019b_v2_M->solverInfo);
  }

  {
    real_T rtb_ManualSwitch3;
    real_T u0;
    real_T tmp;
    if (rtmIsMajorTimeStep(Template_no_obs2019b_v2_M)) {
      /* Sin: '<Root>/Sine Wave' */
      if (Template_no_obs2019b_v2_DW.systemEnable != 0) {
        rtb_ManualSwitch3 = Template_no_obs2019b_v2_P.SineWave_Freq *
          (((Template_no_obs2019b_v2_M->Timing.clockTick1+
             Template_no_obs2019b_v2_M->Timing.clockTickH1* 4294967296.0)) *
           0.002);
        Template_no_obs2019b_v2_DW.lastSin = sin(rtb_ManualSwitch3);
        Template_no_obs2019b_v2_DW.lastCos = cos(rtb_ManualSwitch3);
        Template_no_obs2019b_v2_DW.systemEnable = 0;
      }

      Template_no_obs2019b_v2_B.SineWave = ((Template_no_obs2019b_v2_DW.lastSin *
        Template_no_obs2019b_v2_P.SineWave_PCos +
        Template_no_obs2019b_v2_DW.lastCos *
        Template_no_obs2019b_v2_P.SineWave_PSin) *
        Template_no_obs2019b_v2_P.SineWave_HCos +
        (Template_no_obs2019b_v2_DW.lastCos *
         Template_no_obs2019b_v2_P.SineWave_PCos -
         Template_no_obs2019b_v2_DW.lastSin *
         Template_no_obs2019b_v2_P.SineWave_PSin) *
        Template_no_obs2019b_v2_P.SineWave_Hsin) *
        Template_no_obs2019b_v2_P.SineWave_Amp +
        Template_no_obs2019b_v2_P.SineWave_Bias;

      /* End of Sin: '<Root>/Sine Wave' */

      /* Sin: '<S3>/Sine Wave' */
      if (Template_no_obs2019b_v2_DW.systemEnable_a != 0) {
        rtb_ManualSwitch3 = Template_no_obs2019b_v2_P.SineWave_Freq_o *
          (((Template_no_obs2019b_v2_M->Timing.clockTick1+
             Template_no_obs2019b_v2_M->Timing.clockTickH1* 4294967296.0)) *
           0.002);
        Template_no_obs2019b_v2_DW.lastSin_l = sin(rtb_ManualSwitch3);
        Template_no_obs2019b_v2_DW.lastCos_m = cos(rtb_ManualSwitch3);
        Template_no_obs2019b_v2_DW.systemEnable_a = 0;
      }

      Template_no_obs2019b_v2_B.SineWave_n =
        ((Template_no_obs2019b_v2_DW.lastSin_l *
          Template_no_obs2019b_v2_P.SineWave_PCos_h +
          Template_no_obs2019b_v2_DW.lastCos_m *
          Template_no_obs2019b_v2_P.SineWave_PSin_d) *
         Template_no_obs2019b_v2_P.SineWave_HCos_o +
         (Template_no_obs2019b_v2_DW.lastCos_m *
          Template_no_obs2019b_v2_P.SineWave_PCos_h -
          Template_no_obs2019b_v2_DW.lastSin_l *
          Template_no_obs2019b_v2_P.SineWave_PSin_d) *
         Template_no_obs2019b_v2_P.SineWave_Hsin_n) *
        Template_no_obs2019b_v2_P.SineWave_Amp_n +
        Template_no_obs2019b_v2_P.SineWave_Bias_i;

      /* End of Sin: '<S3>/Sine Wave' */

      /* Step: '<S3>/Step1' incorporates:
       *  Step: '<S3>/Step'
       *  Step: '<S3>/Step2'
       */
      u0 = (((Template_no_obs2019b_v2_M->Timing.clockTick1+
              Template_no_obs2019b_v2_M->Timing.clockTickH1* 4294967296.0)) *
            0.002);
      if (u0 < Template_no_obs2019b_v2_P.Step1_Time) {
        rtb_BallPositionandCurrent_o2 = Template_no_obs2019b_v2_P.Step1_Y0;
      } else {
        rtb_BallPositionandCurrent_o2 = Template_no_obs2019b_v2_P.Step1_YFinal;
      }

      /* End of Step: '<S3>/Step1' */

      /* Step: '<S3>/Step2' */
      if (u0 < Template_no_obs2019b_v2_P.Step2_Time) {
        rtb_WhiteNoise = Template_no_obs2019b_v2_P.Step2_Y0;
      } else {
        rtb_WhiteNoise = Template_no_obs2019b_v2_P.Step2_YFinal;
      }

      /* Step: '<S3>/Step' */
      if (u0 < Template_no_obs2019b_v2_P.Step_Time_c) {
        u0 = Template_no_obs2019b_v2_P.Step_Y0_a;
      } else {
        u0 = Template_no_obs2019b_v2_P.Step_YFinal_j;
      }

      /* Sum: '<S3>/Add' */
      Template_no_obs2019b_v2_B.Add = (u0 + rtb_BallPositionandCurrent_o2) +
        rtb_WhiteNoise;
    }

    /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
     *  Clock: '<S3>/Clock'
     *  Switch: '<S3>/Switch'
     */
    if (Template_no_obs2019b_v2_P.ManualSwitch1_CurrentSetting == 1) {
      /* ManualSwitch: '<Root>/Manual Switch' incorporates:
       *  Clock: '<Root>/Clock'
       *  Step: '<Root>/Step'
       *  Switch: '<Root>/Switch'
       */
      if (Template_no_obs2019b_v2_P.ManualSwitch_CurrentSetting == 1) {
        /* Step: '<Root>/Step' */
        if (Template_no_obs2019b_v2_M->Timing.t[0] <
            Template_no_obs2019b_v2_P.Step_Time) {
          Template_no_obs2019b_v2_B.ManualSwitch1 =
            Template_no_obs2019b_v2_P.Step_Y0;
        } else {
          Template_no_obs2019b_v2_B.ManualSwitch1 =
            Template_no_obs2019b_v2_P.Step_YFinal;
        }
      } else if (Template_no_obs2019b_v2_M->Timing.t[0] >
                 Template_no_obs2019b_v2_P.Switch_Threshold_e) {
        /* Switch: '<Root>/Switch' */
        Template_no_obs2019b_v2_B.ManualSwitch1 =
          Template_no_obs2019b_v2_B.SineWave;
      } else if (Template_no_obs2019b_v2_M->Timing.t[0] <
                 Template_no_obs2019b_v2_P.Step_Time) {
        /* Step: '<Root>/Step' */
        Template_no_obs2019b_v2_B.ManualSwitch1 =
          Template_no_obs2019b_v2_P.Step_Y0;
      } else {
        Template_no_obs2019b_v2_B.ManualSwitch1 =
          Template_no_obs2019b_v2_P.Step_YFinal;
      }

      /* End of ManualSwitch: '<Root>/Manual Switch' */
    } else if (Template_no_obs2019b_v2_M->Timing.t[0] >
               Template_no_obs2019b_v2_P.Switch_Threshold) {
      /* Switch: '<S3>/Switch' */
      Template_no_obs2019b_v2_B.ManualSwitch1 =
        Template_no_obs2019b_v2_B.SineWave_n;
    } else {
      Template_no_obs2019b_v2_B.ManualSwitch1 = Template_no_obs2019b_v2_B.Add;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch1' */
    if (rtmIsMajorTimeStep(Template_no_obs2019b_v2_M)) {
      /* S-Function (hil_read_analog_block): '<S2>/Ball Position and Current' */

      /* S-Function Block: Template_no_obs2019b_v2/Subsystem/Ball Position and Current (hil_read_analog_block) */
      {
        t_error result = hil_read_analog
          (Template_no_obs2019b_v2_DW.HILInitialize_Card,
           Template_no_obs2019b_v2_P.BallPositionandCurrent_channels, 2,
           &Template_no_obs2019b_v2_DW.BallPositionandCurrent_Buffer[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Template_no_obs2019b_v2_M, _rt_error_message);
        }

        rtb_WhiteNoise =
          Template_no_obs2019b_v2_DW.BallPositionandCurrent_Buffer[0];
        rtb_BallPositionandCurrent_o2 =
          Template_no_obs2019b_v2_DW.BallPositionandCurrent_Buffer[1];
      }

      /* Gain: '<S2>/Gain1' incorporates:
       *  Constant: '<S2>/Constant'
       *  Sum: '<S2>/Add1'
       */
      Template_no_obs2019b_v2_B.posizione =
        (Template_no_obs2019b_v2_P.offset_posizione_volt + rtb_WhiteNoise) *
        Template_no_obs2019b_v2_P.Kb;

      /* Sum: '<S2>/Add' incorporates:
       *  Constant: '<S2>/Constant1'
       */
      Template_no_obs2019b_v2_B.corrente = rtb_BallPositionandCurrent_o2 +
        Template_no_obs2019b_v2_P.offset_corrente_volt;

      /* RandomNumber: '<S1>/White Noise' */
      rtb_WhiteNoise = Template_no_obs2019b_v2_DW.NextOutput;

      /* Gain: '<S1>/Output' */
      Template_no_obs2019b_v2_B.Output = sqrt
        (Template_no_obs2019b_v2_P.BandLimitedWhiteNoise_Cov) /
        0.044721359549995794 * rtb_WhiteNoise;
    }

    /* TransferFcn: '<Root>/Transfer Fcn' */
    rtb_ManualSwitch3 = Template_no_obs2019b_v2_P.TransferFcn_C *
      Template_no_obs2019b_v2_X.TransferFcn_CSTATE;

    /* ManualSwitch: '<Root>/Manual Switch3' incorporates:
     *  ManualSwitch: '<Root>/Manual Switch2'
     *  Sum: '<Root>/Sum3'
     */
    if (Template_no_obs2019b_v2_P.ManualSwitch3_CurrentSetting == 1) {
      /* ManualSwitch: '<Root>/Manual Switch2' */
      if (Template_no_obs2019b_v2_P.ManualSwitch2_CurrentSetting == 1) {
        rtb_ManualSwitch3 = Template_no_obs2019b_v2_B.posizione;
      }
    } else {
      if (Template_no_obs2019b_v2_P.ManualSwitch2_CurrentSetting == 1) {
        /* ManualSwitch: '<Root>/Manual Switch2' */
        rtb_ManualSwitch3 = Template_no_obs2019b_v2_B.posizione;
      }

      rtb_ManualSwitch3 += Template_no_obs2019b_v2_B.Output;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch3' */

    /* TransferFcn: '<S4>/Transfer Fcn' */
    Template_no_obs2019b_v2_B.pos_filtro = 0.0;
    Template_no_obs2019b_v2_B.pos_filtro +=
      Template_no_obs2019b_v2_P.TransferFcn_C_j *
      Template_no_obs2019b_v2_X.TransferFcn_CSTATE_j;

    /* TransferFcn: '<S4>/Transfer Fcn1' */
    Template_no_obs2019b_v2_B.curr_filtrato = 0.0;
    Template_no_obs2019b_v2_B.curr_filtrato +=
      Template_no_obs2019b_v2_P.TransferFcn1_C *
      Template_no_obs2019b_v2_X.TransferFcn1_CSTATE;

    /* Sum: '<S4>/Sum' incorporates:
     *  ManualSwitch: '<S4>/Manual Switch'
     */
    if (Template_no_obs2019b_v2_P.ManualSwitch_CurrentSetting_h == 1) {
      u0 = Template_no_obs2019b_v2_B.posizione;
    } else {
      u0 = Template_no_obs2019b_v2_B.pos_filtro;
    }

    /* ManualSwitch: '<S4>/Manual Switch1' */
    if (Template_no_obs2019b_v2_P.ManualSwitch1_CurrentSetting_a == 1) {
      tmp = Template_no_obs2019b_v2_B.corrente;
    } else {
      tmp = Template_no_obs2019b_v2_B.curr_filtrato;
    }

    /* End of ManualSwitch: '<S4>/Manual Switch1' */

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<S4>/Constant'
     *  Constant: '<S4>/Constant1'
     *  Gain: '<Root>/Gain'
     *  Gain: '<S4>/Gain'
     *  Integrator: '<Root>/Integrator'
     *  Sum: '<Root>/Sum1'
     *  Sum: '<S4>/Sum'
     *  Sum: '<S4>/Sum1'
     *  TransferFcn: '<S4>/Transfer Fcn2'
     */
    u0 = ((0.0 - Template_no_obs2019b_v2_P.Ken_eta *
           Template_no_obs2019b_v2_X.Integrator_CSTATE) - (((u0 -
             Template_no_obs2019b_v2_P.x1_eq0) *
            Template_no_obs2019b_v2_P.Ken_x[0] + (tmp -
             Template_no_obs2019b_v2_P.x2_eq0) *
            Template_no_obs2019b_v2_P.Ken_x[1]) +
           (Template_no_obs2019b_v2_P.TransferFcn2_C *
            Template_no_obs2019b_v2_X.TransferFcn2_CSTATE +
            Template_no_obs2019b_v2_P.TransferFcn2_D *
            Template_no_obs2019b_v2_B.posizione) *
           Template_no_obs2019b_v2_P.Ken_x[2])) + Template_no_obs2019b_v2_P.u;

    /* Saturate: '<Root>/Saturation' */
    if (u0 > Template_no_obs2019b_v2_P.Saturation_UpperSat) {
      u0 = Template_no_obs2019b_v2_P.Saturation_UpperSat;
    } else {
      if (u0 < Template_no_obs2019b_v2_P.Saturation_LowerSat) {
        u0 = Template_no_obs2019b_v2_P.Saturation_LowerSat;
      }
    }

    /* End of Saturate: '<Root>/Saturation' */

    /* Gain: '<S2>/Gain' */
    Template_no_obs2019b_v2_B.Gain = Template_no_obs2019b_v2_P.Gain_Gain * u0;
    if (rtmIsMajorTimeStep(Template_no_obs2019b_v2_M)) {
      /* S-Function (hil_write_analog_block): '<S2>/Voltage' */

      /* S-Function Block: Template_no_obs2019b_v2/Subsystem/Voltage (hil_write_analog_block) */
      {
        t_error result;
        result = hil_write_analog(Template_no_obs2019b_v2_DW.HILInitialize_Card,
          &Template_no_obs2019b_v2_P.Voltage_channels, 1,
          &Template_no_obs2019b_v2_B.Gain);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Template_no_obs2019b_v2_M, _rt_error_message);
        }
      }
    }

    /* Sum: '<Root>/Sum2' */
    Template_no_obs2019b_v2_B.Sum2 = Template_no_obs2019b_v2_B.ManualSwitch1 -
      rtb_ManualSwitch3;
  }

  if (rtmIsMajorTimeStep(Template_no_obs2019b_v2_M)) {
    real_T HoldSine;
    if (rtmIsMajorTimeStep(Template_no_obs2019b_v2_M)) {
      /* Update for Sin: '<Root>/Sine Wave' */
      HoldSine = Template_no_obs2019b_v2_DW.lastSin;
      Template_no_obs2019b_v2_DW.lastSin = Template_no_obs2019b_v2_DW.lastSin *
        Template_no_obs2019b_v2_P.SineWave_HCos +
        Template_no_obs2019b_v2_DW.lastCos *
        Template_no_obs2019b_v2_P.SineWave_Hsin;
      Template_no_obs2019b_v2_DW.lastCos = Template_no_obs2019b_v2_DW.lastCos *
        Template_no_obs2019b_v2_P.SineWave_HCos - HoldSine *
        Template_no_obs2019b_v2_P.SineWave_Hsin;

      /* Update for Sin: '<S3>/Sine Wave' */
      HoldSine = Template_no_obs2019b_v2_DW.lastSin_l;
      Template_no_obs2019b_v2_DW.lastSin_l =
        Template_no_obs2019b_v2_DW.lastSin_l *
        Template_no_obs2019b_v2_P.SineWave_HCos_o +
        Template_no_obs2019b_v2_DW.lastCos_m *
        Template_no_obs2019b_v2_P.SineWave_Hsin_n;
      Template_no_obs2019b_v2_DW.lastCos_m =
        Template_no_obs2019b_v2_DW.lastCos_m *
        Template_no_obs2019b_v2_P.SineWave_HCos_o - HoldSine *
        Template_no_obs2019b_v2_P.SineWave_Hsin_n;

      /* Update for RandomNumber: '<S1>/White Noise' */
      Template_no_obs2019b_v2_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
        (&Template_no_obs2019b_v2_DW.RandSeed) *
        Template_no_obs2019b_v2_P.WhiteNoise_StdDev +
        Template_no_obs2019b_v2_P.WhiteNoise_Mean;
    }

    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, (real_T)Template_no_obs2019b_v2_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(Template_no_obs2019b_v2_M)) {/* Sample time: [0.002s, 0.0s] */
      rtExtModeUpload(1, (real_T)(((Template_no_obs2019b_v2_M->Timing.clockTick1
        +Template_no_obs2019b_v2_M->Timing.clockTickH1* 4294967296.0)) * 0.002));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Template_no_obs2019b_v2_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(Template_no_obs2019b_v2_M)!=-1) &&
          !((rtmGetTFinal(Template_no_obs2019b_v2_M)-
             (((Template_no_obs2019b_v2_M->Timing.clockTick1+
                Template_no_obs2019b_v2_M->Timing.clockTickH1* 4294967296.0)) *
              0.002)) > (((Template_no_obs2019b_v2_M->Timing.clockTick1+
                           Template_no_obs2019b_v2_M->Timing.clockTickH1*
                           4294967296.0)) * 0.002) * (DBL_EPSILON))) {
        rtmSetErrorStatus(Template_no_obs2019b_v2_M, "Simulation finished");
      }

      if (rtmGetStopRequested(Template_no_obs2019b_v2_M)) {
        rtmSetErrorStatus(Template_no_obs2019b_v2_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&Template_no_obs2019b_v2_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Template_no_obs2019b_v2_M->Timing.clockTick0)) {
      ++Template_no_obs2019b_v2_M->Timing.clockTickH0;
    }

    Template_no_obs2019b_v2_M->Timing.t[0] = rtsiGetSolverStopTime
      (&Template_no_obs2019b_v2_M->solverInfo);

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
      Template_no_obs2019b_v2_M->Timing.clockTick1++;
      if (!Template_no_obs2019b_v2_M->Timing.clockTick1) {
        Template_no_obs2019b_v2_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Template_no_obs2019b_v2_derivatives(void)
{
  XDot_Template_no_obs2019b_v2_T *_rtXdot;
  _rtXdot = ((XDot_Template_no_obs2019b_v2_T *)
             Template_no_obs2019b_v2_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = Template_no_obs2019b_v2_B.Sum2;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += Template_no_obs2019b_v2_P.TransferFcn_A *
    Template_no_obs2019b_v2_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += Template_no_obs2019b_v2_B.posizione;

  /* Derivatives for TransferFcn: '<S4>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE_j = 0.0;
  _rtXdot->TransferFcn_CSTATE_j += Template_no_obs2019b_v2_P.TransferFcn_A_e *
    Template_no_obs2019b_v2_X.TransferFcn_CSTATE_j;
  _rtXdot->TransferFcn_CSTATE_j += Template_no_obs2019b_v2_B.posizione;

  /* Derivatives for TransferFcn: '<S4>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += Template_no_obs2019b_v2_P.TransferFcn1_A *
    Template_no_obs2019b_v2_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += Template_no_obs2019b_v2_B.corrente;

  /* Derivatives for TransferFcn: '<S4>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE = 0.0;
  _rtXdot->TransferFcn2_CSTATE += Template_no_obs2019b_v2_P.TransferFcn2_A *
    Template_no_obs2019b_v2_X.TransferFcn2_CSTATE;
  _rtXdot->TransferFcn2_CSTATE += Template_no_obs2019b_v2_B.posizione;
}

/* Model initialize function */
void Template_no_obs2019b_v2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Template_no_obs2019b_v2_M, 0,
                sizeof(RT_MODEL_Template_no_obs2019b_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Template_no_obs2019b_v2_M->solverInfo,
                          &Template_no_obs2019b_v2_M->Timing.simTimeStep);
    rtsiSetTPtr(&Template_no_obs2019b_v2_M->solverInfo, &rtmGetTPtr
                (Template_no_obs2019b_v2_M));
    rtsiSetStepSizePtr(&Template_no_obs2019b_v2_M->solverInfo,
                       &Template_no_obs2019b_v2_M->Timing.stepSize0);
    rtsiSetdXPtr(&Template_no_obs2019b_v2_M->solverInfo,
                 &Template_no_obs2019b_v2_M->derivs);
    rtsiSetContStatesPtr(&Template_no_obs2019b_v2_M->solverInfo, (real_T **)
                         &Template_no_obs2019b_v2_M->contStates);
    rtsiSetNumContStatesPtr(&Template_no_obs2019b_v2_M->solverInfo,
      &Template_no_obs2019b_v2_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Template_no_obs2019b_v2_M->solverInfo,
      &Template_no_obs2019b_v2_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Template_no_obs2019b_v2_M->solverInfo,
      &Template_no_obs2019b_v2_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Template_no_obs2019b_v2_M->solverInfo,
      &Template_no_obs2019b_v2_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Template_no_obs2019b_v2_M->solverInfo,
                          (&rtmGetErrorStatus(Template_no_obs2019b_v2_M)));
    rtsiSetRTModelPtr(&Template_no_obs2019b_v2_M->solverInfo,
                      Template_no_obs2019b_v2_M);
  }

  rtsiSetSimTimeStep(&Template_no_obs2019b_v2_M->solverInfo, MAJOR_TIME_STEP);
  Template_no_obs2019b_v2_M->intgData.f[0] = Template_no_obs2019b_v2_M->odeF[0];
  Template_no_obs2019b_v2_M->contStates = ((X_Template_no_obs2019b_v2_T *)
    &Template_no_obs2019b_v2_X);
  rtsiSetSolverData(&Template_no_obs2019b_v2_M->solverInfo, (void *)
                    &Template_no_obs2019b_v2_M->intgData);
  rtsiSetSolverName(&Template_no_obs2019b_v2_M->solverInfo,"ode1");
  rtmSetTPtr(Template_no_obs2019b_v2_M,
             &Template_no_obs2019b_v2_M->Timing.tArray[0]);
  rtmSetTFinal(Template_no_obs2019b_v2_M, -1);
  Template_no_obs2019b_v2_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  Template_no_obs2019b_v2_M->Sizes.checksums[0] = (4150879501U);
  Template_no_obs2019b_v2_M->Sizes.checksums[1] = (2595145612U);
  Template_no_obs2019b_v2_M->Sizes.checksums[2] = (1004518628U);
  Template_no_obs2019b_v2_M->Sizes.checksums[3] = (2914224237U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    Template_no_obs2019b_v2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Template_no_obs2019b_v2_M->extModeInfo,
      &Template_no_obs2019b_v2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Template_no_obs2019b_v2_M->extModeInfo,
                        Template_no_obs2019b_v2_M->Sizes.checksums);
    rteiSetTPtr(Template_no_obs2019b_v2_M->extModeInfo, rtmGetTPtr
                (Template_no_obs2019b_v2_M));
  }

  /* block I/O */
  {
    Template_no_obs2019b_v2_B.SineWave = 0.0;
    Template_no_obs2019b_v2_B.SineWave_n = 0.0;
    Template_no_obs2019b_v2_B.Add = 0.0;
    Template_no_obs2019b_v2_B.ManualSwitch1 = 0.0;
    Template_no_obs2019b_v2_B.posizione = 0.0;
    Template_no_obs2019b_v2_B.corrente = 0.0;
    Template_no_obs2019b_v2_B.Output = 0.0;
    Template_no_obs2019b_v2_B.pos_filtro = 0.0;
    Template_no_obs2019b_v2_B.curr_filtrato = 0.0;
    Template_no_obs2019b_v2_B.Gain = 0.0;
    Template_no_obs2019b_v2_B.Sum2 = 0.0;
  }

  /* states (continuous) */
  {
    (void) memset((void *)&Template_no_obs2019b_v2_X, 0,
                  sizeof(X_Template_no_obs2019b_v2_T));
  }

  /* states (dwork) */
  (void) memset((void *)&Template_no_obs2019b_v2_DW, 0,
                sizeof(DW_Template_no_obs2019b_v2_T));
  Template_no_obs2019b_v2_DW.HILInitialize_AOVoltages[0] = 0.0;
  Template_no_obs2019b_v2_DW.HILInitialize_AOVoltages[1] = 0.0;
  Template_no_obs2019b_v2_DW.lastSin = 0.0;
  Template_no_obs2019b_v2_DW.lastCos = 0.0;
  Template_no_obs2019b_v2_DW.lastSin_l = 0.0;
  Template_no_obs2019b_v2_DW.lastCos_m = 0.0;
  Template_no_obs2019b_v2_DW.BallPositionandCurrent_Buffer[0] = 0.0;
  Template_no_obs2019b_v2_DW.BallPositionandCurrent_Buffer[1] = 0.0;
  Template_no_obs2019b_v2_DW.NextOutput = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Template_no_obs2019b_v2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Template_no_obs2019b_v2/HIL Initialize (hil_initialize_block) */
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
                      &Template_no_obs2019b_v2_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Template_no_obs2019b_v2_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (Template_no_obs2019b_v2_DW.HILInitialize_Card,
       "d0=digital;d1=digital;led=auto;update_rate=normal;decimation=1", 63);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Template_no_obs2019b_v2_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Template_no_obs2019b_v2_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Template_no_obs2019b_v2_M, _rt_error_message);
      return;
    }

    if (!is_switching) {
      result = hil_set_analog_input_ranges
        (Template_no_obs2019b_v2_DW.HILInitialize_Card, analog_input_channels,
         2U,
         analog_input_minimums, analog_input_maximums);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Template_no_obs2019b_v2_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_set_analog_output_ranges
        (Template_no_obs2019b_v2_DW.HILInitialize_Card, analog_output_channels,
         2U,
         analog_output_minimums, analog_output_maximums);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Template_no_obs2019b_v2_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_write_analog(Template_no_obs2019b_v2_DW.HILInitialize_Card,
        analog_output_channels, 2U, initial_analog_outputs);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Template_no_obs2019b_v2_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_set_encoder_quadrature_mode
        (Template_no_obs2019b_v2_DW.HILInitialize_Card, encoder_input_channels,
         2U, (t_encoder_quadrature_mode *) encoder_quadrature);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Template_no_obs2019b_v2_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_set_encoder_counts
        (Template_no_obs2019b_v2_DW.HILInitialize_Card, encoder_input_channels,
         2U, initial_encoder_counts);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Template_no_obs2019b_v2_M, _rt_error_message);
        return;
      }
    }
  }

  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* InitializeConditions for RandomNumber: '<S1>/White Noise' */
    tmp = floor(Template_no_obs2019b_v2_P.BandLimitedWhiteNoise_seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    r = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)r << 16U)) + t) << 16U) + t) + r;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    Template_no_obs2019b_v2_DW.RandSeed = tseed;
    Template_no_obs2019b_v2_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&Template_no_obs2019b_v2_DW.RandSeed) *
      Template_no_obs2019b_v2_P.WhiteNoise_StdDev +
      Template_no_obs2019b_v2_P.WhiteNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S1>/White Noise' */

    /* InitializeConditions for Integrator: '<Root>/Integrator' */
    Template_no_obs2019b_v2_X.Integrator_CSTATE =
      Template_no_obs2019b_v2_P.Integrator_IC;

    /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
    Template_no_obs2019b_v2_X.TransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S4>/Transfer Fcn' */
    Template_no_obs2019b_v2_X.TransferFcn_CSTATE_j = 0.0;

    /* InitializeConditions for TransferFcn: '<S4>/Transfer Fcn1' */
    Template_no_obs2019b_v2_X.TransferFcn1_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S4>/Transfer Fcn2' */
    Template_no_obs2019b_v2_X.TransferFcn2_CSTATE = 0.0;
  }

  /* Enable for Sin: '<Root>/Sine Wave' */
  Template_no_obs2019b_v2_DW.systemEnable = 1;

  /* Enable for Sin: '<S3>/Sine Wave' */
  Template_no_obs2019b_v2_DW.systemEnable_a = 1;
}

/* Model terminate function */
void Template_no_obs2019b_v2_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Template_no_obs2019b_v2/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    static const t_uint analog_output_channels[2U] = {
      0
      , 1
    };

    hil_task_stop_all(Template_no_obs2019b_v2_DW.HILInitialize_Card);
    hil_monitor_stop_all(Template_no_obs2019b_v2_DW.HILInitialize_Card);
    is_switching = false;
    if ((Template_no_obs2019b_v2_P.HILInitialize_AOTerminate && !is_switching) ||
        (Template_no_obs2019b_v2_P.HILInitialize_AOExit && is_switching)) {
      Template_no_obs2019b_v2_DW.HILInitialize_AOVoltages[0] =
        Template_no_obs2019b_v2_P.HILInitialize_AOFinal;
      Template_no_obs2019b_v2_DW.HILInitialize_AOVoltages[1] =
        Template_no_obs2019b_v2_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(Template_no_obs2019b_v2_DW.HILInitialize_Card,
        analog_output_channels, num_final_analog_outputs,
        &Template_no_obs2019b_v2_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Template_no_obs2019b_v2_M, _rt_error_message);
      }
    }

    hil_task_delete_all(Template_no_obs2019b_v2_DW.HILInitialize_Card);
    hil_monitor_delete_all(Template_no_obs2019b_v2_DW.HILInitialize_Card);
    hil_close(Template_no_obs2019b_v2_DW.HILInitialize_Card);
    Template_no_obs2019b_v2_DW.HILInitialize_Card = NULL;
  }
}
