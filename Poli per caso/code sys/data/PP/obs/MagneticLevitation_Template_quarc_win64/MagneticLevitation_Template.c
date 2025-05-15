/*
 * MagneticLevitation_Template.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "MagneticLevitation_Template".
 *
 * Model version              : 1.63
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Tue May 13 17:43:21 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MagneticLevitation_Template.h"
#include "MagneticLevitation_Template_private.h"
#include "MagneticLevitation_Template_dt.h"

/* Block signals (default storage) */
B_MagneticLevitation_Template_T MagneticLevitation_Template_B;

/* Continuous states */
X_MagneticLevitation_Template_T MagneticLevitation_Template_X;

/* Block states (default storage) */
DW_MagneticLevitation_Templat_T MagneticLevitation_Template_DW;

/* Real-time model */
RT_MODEL_MagneticLevitation_T_T MagneticLevitation_Template_M_;
RT_MODEL_MagneticLevitation_T_T *const MagneticLevitation_Template_M =
  &MagneticLevitation_Template_M_;

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
  int_T nXc = 7;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  MagneticLevitation_Template_derivatives();
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
void MagneticLevitation_Template_step(void)
{
  /* local block i/o variables */
  real_T rtb_BallPositionandCurrent_o1;
  real_T rtb_WhiteNoise;
  int_T iy;
  real_T rtb_ManualSwitch_idx_0;
  real_T rtb_ManualSwitch_idx_1;
  real_T rtb_ManualSwitch_idx_2;
  if (rtmIsMajorTimeStep(MagneticLevitation_Template_M)) {
    /* set solver stop time */
    if (!(MagneticLevitation_Template_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&MagneticLevitation_Template_M->solverInfo,
                            ((MagneticLevitation_Template_M->Timing.clockTickH0
        + 1) * MagneticLevitation_Template_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&MagneticLevitation_Template_M->solverInfo,
                            ((MagneticLevitation_Template_M->Timing.clockTick0 +
        1) * MagneticLevitation_Template_M->Timing.stepSize0 +
        MagneticLevitation_Template_M->Timing.clockTickH0 *
        MagneticLevitation_Template_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(MagneticLevitation_Template_M)) {
    MagneticLevitation_Template_M->Timing.t[0] = rtsiGetT
      (&MagneticLevitation_Template_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(MagneticLevitation_Template_M)) {
  }

  /* StateSpace: '<S3>/State-Space' */
  for (iy = 0; iy < 3; iy++) {
    MagneticLevitation_Template_B.StateSpace[iy] = 0.0;
    MagneticLevitation_Template_B.StateSpace[iy] +=
      MagneticLevitation_Template_P.C_ob[iy] *
      MagneticLevitation_Template_X.StateSpace_CSTATE[0];
    MagneticLevitation_Template_B.StateSpace[iy] +=
      MagneticLevitation_Template_P.C_ob[iy + 3] *
      MagneticLevitation_Template_X.StateSpace_CSTATE[1];
    MagneticLevitation_Template_B.StateSpace[iy] +=
      MagneticLevitation_Template_P.C_ob[iy + 6] *
      MagneticLevitation_Template_X.StateSpace_CSTATE[2];
  }

  /* End of StateSpace: '<S3>/State-Space' */
  if (rtmIsMajorTimeStep(MagneticLevitation_Template_M)) {
    /* S-Function (hil_read_analog_block): '<S2>/Ball Position and Current' */

    /* S-Function Block: MagneticLevitation_Template/Subsystem/Ball Position and Current (hil_read_analog_block) */
    {
      t_error result = hil_read_analog
        (MagneticLevitation_Template_DW.HILInitialize_Card,
         MagneticLevitation_Template_P.BallPositionandCurrent_channels, 2,
         &MagneticLevitation_Template_DW.BallPositionandCurrent_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MagneticLevitation_Template_M, _rt_error_message);
      }

      rtb_BallPositionandCurrent_o1 =
        MagneticLevitation_Template_DW.BallPositionandCurrent_Buffer[0];
      rtb_WhiteNoise =
        MagneticLevitation_Template_DW.BallPositionandCurrent_Buffer[1];
    }

    /* Gain: '<S2>/Gain1' incorporates:
     *  Constant: '<S2>/Constant'
     *  Sum: '<S2>/Add1'
     */
    MagneticLevitation_Template_B.posizione =
      (MagneticLevitation_Template_P.offset_posizione_volt +
       rtb_BallPositionandCurrent_o1) * MagneticLevitation_Template_P.Kb;

    /* Sum: '<S2>/Add' incorporates:
     *  Constant: '<S2>/Constant1'
     */
    MagneticLevitation_Template_B.corrente = rtb_WhiteNoise +
      MagneticLevitation_Template_P.offset_corrente_volt;
  }

  /* ManualSwitch: '<S4>/Manual Switch' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   *  ManualSwitch: '<S4>/Manual Switch1'
   *  Sum: '<S4>/Sum'
   *  Sum: '<S4>/Sum1'
   */
  if (MagneticLevitation_Template_P.ManualSwitch_CurrentSetting_d == 1) {
    rtb_ManualSwitch_idx_0 = MagneticLevitation_Template_B.StateSpace[0];
    rtb_ManualSwitch_idx_1 = MagneticLevitation_Template_B.StateSpace[1];
    rtb_ManualSwitch_idx_2 = MagneticLevitation_Template_B.StateSpace[2];
  } else {
    if (MagneticLevitation_Template_P.ManualSwitch1_CurrentSetting == 1) {
      /* ManualSwitch: '<S4>/Manual Switch1' */
      rtb_ManualSwitch_idx_1 = MagneticLevitation_Template_B.posizione;
    } else {
      /* ManualSwitch: '<S4>/Manual Switch1' incorporates:
       *  TransferFcn: '<S4>/Transfer Fcn'
       */
      rtb_ManualSwitch_idx_1 = MagneticLevitation_Template_P.TransferFcn_C *
        MagneticLevitation_Template_X.TransferFcn_CSTATE;
    }

    rtb_ManualSwitch_idx_0 = rtb_ManualSwitch_idx_1 -
      MagneticLevitation_Template_P.x1_eq0;

    /* ManualSwitch: '<S4>/Manual Switch2' incorporates:
     *  Constant: '<S4>/Constant'
     *  Sum: '<S4>/Sum'
     *  TransferFcn: '<S4>/Transfer Fcn1'
     */
    if (MagneticLevitation_Template_P.ManualSwitch2_CurrentSetting == 1) {
      rtb_ManualSwitch_idx_1 = MagneticLevitation_Template_B.corrente;
    } else {
      rtb_ManualSwitch_idx_1 = MagneticLevitation_Template_P.TransferFcn1_C *
        MagneticLevitation_Template_X.TransferFcn1_CSTATE;
    }

    /* End of ManualSwitch: '<S4>/Manual Switch2' */
    rtb_ManualSwitch_idx_1 -= MagneticLevitation_Template_P.x2_eq0;
    rtb_ManualSwitch_idx_2 = MagneticLevitation_Template_B.StateSpace[2];
  }

  /* End of ManualSwitch: '<S4>/Manual Switch' */

  /* Sum: '<Root>/Add1' incorporates:
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/K_eta1'
   *  Integrator: '<Root>/Integrator2'
   */
  rtb_ManualSwitch_idx_0 = (0.0 - MagneticLevitation_Template_P.Ken_eta *
    MagneticLevitation_Template_X.Integrator2_CSTATE) -
    ((MagneticLevitation_Template_P.Ken_x[0] * rtb_ManualSwitch_idx_0 +
      MagneticLevitation_Template_P.Ken_x[1] * rtb_ManualSwitch_idx_1) +
     MagneticLevitation_Template_P.Ken_x[2] * rtb_ManualSwitch_idx_2);

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  rtb_ManualSwitch_idx_1 = MagneticLevitation_Template_P.u +
    rtb_ManualSwitch_idx_0;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_ManualSwitch_idx_1 > MagneticLevitation_Template_P.Upper_bound_V) {
    MagneticLevitation_Template_B.Saturation =
      MagneticLevitation_Template_P.Upper_bound_V;
  } else if (rtb_ManualSwitch_idx_1 <
             MagneticLevitation_Template_P.Saturation_LowerSat) {
    MagneticLevitation_Template_B.Saturation =
      MagneticLevitation_Template_P.Saturation_LowerSat;
  } else {
    MagneticLevitation_Template_B.Saturation = rtb_ManualSwitch_idx_1;
  }

  /* End of Saturate: '<Root>/Saturation' */
  if (rtmIsMajorTimeStep(MagneticLevitation_Template_M)) {
    /* RandomNumber: '<S1>/White Noise' */
    rtb_WhiteNoise = MagneticLevitation_Template_DW.NextOutput;

    /* Gain: '<S1>/Output' */
    MagneticLevitation_Template_B.Output = sqrt
      (MagneticLevitation_Template_P.BandLimitedWhiteNoise_Cov) /
      0.044721359549995794 * rtb_WhiteNoise;
  }

  /* ManualSwitch: '<Root>/Manual Switch2' incorporates:
   *  ManualSwitch: '<Root>/Manual Switch'
   *  Sum: '<Root>/Sum1'
   */
  if (MagneticLevitation_Template_P.ManualSwitch2_CurrentSetting_f == 1) {
    MagneticLevitation_Template_B.ManualSwitch2 =
      MagneticLevitation_Template_B.posizione;
  } else {
    if (MagneticLevitation_Template_P.ManualSwitch_CurrentSetting == 1) {
      /* ManualSwitch: '<Root>/Manual Switch' */
      rtb_ManualSwitch_idx_1 = MagneticLevitation_Template_B.Output;
    } else {
      /* ManualSwitch: '<Root>/Manual Switch' incorporates:
       *  Sin: '<Root>/Sine Wave'
       */
      rtb_ManualSwitch_idx_1 = sin(MagneticLevitation_Template_P.SineWave_Freq *
        MagneticLevitation_Template_M->Timing.t[0] +
        MagneticLevitation_Template_P.SineWave_Phase) *
        MagneticLevitation_Template_P.SineWave_Amp +
        MagneticLevitation_Template_P.SineWave_Bias;
    }

    MagneticLevitation_Template_B.ManualSwitch2 =
      MagneticLevitation_Template_B.posizione + rtb_ManualSwitch_idx_1;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch2' */
  if (rtmIsMajorTimeStep(MagneticLevitation_Template_M)) {
  }

  /* ManualSwitch: '<Root>/Manual Switch4' incorporates:
   *  Sin: '<Root>/Sine Wave1'
   */
  if (MagneticLevitation_Template_P.ManualSwitch4_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/Manual Switch3' incorporates:
     *  Constant: '<Root>/Constant'
     *  Step: '<Root>/Step'
     */
    if (MagneticLevitation_Template_P.ManualSwitch3_CurrentSetting == 1) {
      MagneticLevitation_Template_B.ManualSwitch4 =
        MagneticLevitation_Template_P.Constant_Value;
    } else if (MagneticLevitation_Template_M->Timing.t[0] <
               MagneticLevitation_Template_P.Step_Time) {
      /* Step: '<Root>/Step' */
      MagneticLevitation_Template_B.ManualSwitch4 =
        MagneticLevitation_Template_P.Step_Y0;
    } else {
      MagneticLevitation_Template_B.ManualSwitch4 =
        MagneticLevitation_Template_P.Step_YFinal;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch3' */
  } else {
    MagneticLevitation_Template_B.ManualSwitch4 = sin
      (MagneticLevitation_Template_P.SineWave1_Freq *
       MagneticLevitation_Template_M->Timing.t[0] +
       MagneticLevitation_Template_P.SineWave1_Phase) *
      MagneticLevitation_Template_P.SineWave1_Amp +
      MagneticLevitation_Template_P.SineWave1_Bias;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch4' */
  if (rtmIsMajorTimeStep(MagneticLevitation_Template_M)) {
    /* Sum: '<Root>/Sum2' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    MagneticLevitation_Template_B.x1 = MagneticLevitation_Template_B.posizione -
      MagneticLevitation_Template_P.x1_eq0;

    /* Sum: '<Root>/Sum3' incorporates:
     *  Constant: '<Root>/Constant4'
     */
    MagneticLevitation_Template_B.x2 = MagneticLevitation_Template_B.corrente -
      MagneticLevitation_Template_P.x2_eq0;
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  MagneticLevitation_Template_B.TransferFcn = 0.0;
  MagneticLevitation_Template_B.TransferFcn +=
    MagneticLevitation_Template_P.TransferFcn_C_i *
    MagneticLevitation_Template_X.TransferFcn_CSTATE_b;
  MagneticLevitation_Template_B.TransferFcn +=
    MagneticLevitation_Template_P.TransferFcn_D *
    MagneticLevitation_Template_B.posizione;
  if (rtmIsMajorTimeStep(MagneticLevitation_Template_M)) {
  }

  /* Sum: '<Root>/Add' */
  MagneticLevitation_Template_B.Add =
    MagneticLevitation_Template_B.ManualSwitch4 -
    MagneticLevitation_Template_B.ManualSwitch2;

  /* Gain: '<S2>/Gain' */
  MagneticLevitation_Template_B.Gain = MagneticLevitation_Template_P.Gain_Gain *
    MagneticLevitation_Template_B.Saturation;
  if (rtmIsMajorTimeStep(MagneticLevitation_Template_M)) {
    /* S-Function (hil_write_analog_block): '<S2>/Voltage' */

    /* S-Function Block: MagneticLevitation_Template/Subsystem/Voltage (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog
        (MagneticLevitation_Template_DW.HILInitialize_Card,
         &MagneticLevitation_Template_P.Voltage_channels, 1,
         &MagneticLevitation_Template_B.Gain);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MagneticLevitation_Template_M, _rt_error_message);
      }
    }

    /* Sum: '<S3>/Sum' incorporates:
     *  Constant: '<S3>/Constant'
     */
    MagneticLevitation_Template_B.Sum = MagneticLevitation_Template_B.posizione
      - MagneticLevitation_Template_P.x1_eq0;

    /* Sum: '<S3>/Sum1' incorporates:
     *  Constant: '<S3>/Constant1'
     */
    MagneticLevitation_Template_B.Sum1 = MagneticLevitation_Template_B.corrente
      - MagneticLevitation_Template_P.x2_eq0;
  }

  /* SignalConversion generated from: '<S3>/State-Space' */
  MagneticLevitation_Template_B.TmpSignalConversionAtStateSpace[0] =
    rtb_ManualSwitch_idx_0;
  MagneticLevitation_Template_B.TmpSignalConversionAtStateSpace[1] =
    MagneticLevitation_Template_B.Sum;
  MagneticLevitation_Template_B.TmpSignalConversionAtStateSpace[2] =
    MagneticLevitation_Template_B.Sum1;
  if (rtmIsMajorTimeStep(MagneticLevitation_Template_M)) {
    if (rtmIsMajorTimeStep(MagneticLevitation_Template_M)) {
      /* Update for RandomNumber: '<S1>/White Noise' */
      MagneticLevitation_Template_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
        (&MagneticLevitation_Template_DW.RandSeed) *
        MagneticLevitation_Template_P.WhiteNoise_StdDev +
        MagneticLevitation_Template_P.WhiteNoise_Mean;
    }

    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, (real_T)MagneticLevitation_Template_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(MagneticLevitation_Template_M)) {/* Sample time: [0.002s, 0.0s] */
      rtExtModeUpload(1, (real_T)
                      (((MagneticLevitation_Template_M->Timing.clockTick1+
                         MagneticLevitation_Template_M->Timing.clockTickH1*
                         4294967296.0)) * 0.002));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(MagneticLevitation_Template_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(MagneticLevitation_Template_M)!=-1) &&
          !((rtmGetTFinal(MagneticLevitation_Template_M)-
             (((MagneticLevitation_Template_M->Timing.clockTick1+
                MagneticLevitation_Template_M->Timing.clockTickH1* 4294967296.0))
              * 0.002)) > (((MagneticLevitation_Template_M->Timing.clockTick1+
                             MagneticLevitation_Template_M->Timing.clockTickH1*
                             4294967296.0)) * 0.002) * (DBL_EPSILON))) {
        rtmSetErrorStatus(MagneticLevitation_Template_M, "Simulation finished");
      }

      if (rtmGetStopRequested(MagneticLevitation_Template_M)) {
        rtmSetErrorStatus(MagneticLevitation_Template_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&MagneticLevitation_Template_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++MagneticLevitation_Template_M->Timing.clockTick0)) {
      ++MagneticLevitation_Template_M->Timing.clockTickH0;
    }

    MagneticLevitation_Template_M->Timing.t[0] = rtsiGetSolverStopTime
      (&MagneticLevitation_Template_M->solverInfo);

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
      MagneticLevitation_Template_M->Timing.clockTick1++;
      if (!MagneticLevitation_Template_M->Timing.clockTick1) {
        MagneticLevitation_Template_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void MagneticLevitation_Template_derivatives(void)
{
  int_T is;
  XDot_MagneticLevitation_Templ_T *_rtXdot;
  _rtXdot = ((XDot_MagneticLevitation_Templ_T *)
             MagneticLevitation_Template_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = MagneticLevitation_Template_B.Add;

  /* Derivatives for StateSpace: '<S3>/State-Space' */
  for (is = 0; is < 3; is++) {
    _rtXdot->StateSpace_CSTATE[is] = 0.0;
    _rtXdot->StateSpace_CSTATE[is] += MagneticLevitation_Template_P.A_ob[is] *
      MagneticLevitation_Template_X.StateSpace_CSTATE[0];
    _rtXdot->StateSpace_CSTATE[is] += MagneticLevitation_Template_P.A_ob[is + 3]
      * MagneticLevitation_Template_X.StateSpace_CSTATE[1];
    _rtXdot->StateSpace_CSTATE[is] += MagneticLevitation_Template_P.A_ob[is + 6]
      * MagneticLevitation_Template_X.StateSpace_CSTATE[2];
    _rtXdot->StateSpace_CSTATE[is] += MagneticLevitation_Template_P.B_ob[is] *
      MagneticLevitation_Template_B.TmpSignalConversionAtStateSpace[0];
    _rtXdot->StateSpace_CSTATE[is] += MagneticLevitation_Template_P.B_ob[is + 3]
      * MagneticLevitation_Template_B.TmpSignalConversionAtStateSpace[1];
    _rtXdot->StateSpace_CSTATE[is] += MagneticLevitation_Template_P.B_ob[is + 6]
      * MagneticLevitation_Template_B.TmpSignalConversionAtStateSpace[2];
  }

  /* End of Derivatives for StateSpace: '<S3>/State-Space' */

  /* Derivatives for TransferFcn: '<S4>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += MagneticLevitation_Template_P.TransferFcn_A *
    MagneticLevitation_Template_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += MagneticLevitation_Template_B.posizione;

  /* Derivatives for TransferFcn: '<S4>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += MagneticLevitation_Template_P.TransferFcn1_A *
    MagneticLevitation_Template_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += MagneticLevitation_Template_B.corrente;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE_b = 0.0;
  _rtXdot->TransferFcn_CSTATE_b += MagneticLevitation_Template_P.TransferFcn_A_o
    * MagneticLevitation_Template_X.TransferFcn_CSTATE_b;
  _rtXdot->TransferFcn_CSTATE_b += MagneticLevitation_Template_B.posizione;
}

/* Model initialize function */
void MagneticLevitation_Template_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)MagneticLevitation_Template_M, 0,
                sizeof(RT_MODEL_MagneticLevitation_T_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&MagneticLevitation_Template_M->solverInfo,
                          &MagneticLevitation_Template_M->Timing.simTimeStep);
    rtsiSetTPtr(&MagneticLevitation_Template_M->solverInfo, &rtmGetTPtr
                (MagneticLevitation_Template_M));
    rtsiSetStepSizePtr(&MagneticLevitation_Template_M->solverInfo,
                       &MagneticLevitation_Template_M->Timing.stepSize0);
    rtsiSetdXPtr(&MagneticLevitation_Template_M->solverInfo,
                 &MagneticLevitation_Template_M->derivs);
    rtsiSetContStatesPtr(&MagneticLevitation_Template_M->solverInfo, (real_T **)
                         &MagneticLevitation_Template_M->contStates);
    rtsiSetNumContStatesPtr(&MagneticLevitation_Template_M->solverInfo,
      &MagneticLevitation_Template_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&MagneticLevitation_Template_M->solverInfo,
      &MagneticLevitation_Template_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&MagneticLevitation_Template_M->solverInfo,
       &MagneticLevitation_Template_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&MagneticLevitation_Template_M->solverInfo,
      &MagneticLevitation_Template_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&MagneticLevitation_Template_M->solverInfo,
                          (&rtmGetErrorStatus(MagneticLevitation_Template_M)));
    rtsiSetRTModelPtr(&MagneticLevitation_Template_M->solverInfo,
                      MagneticLevitation_Template_M);
  }

  rtsiSetSimTimeStep(&MagneticLevitation_Template_M->solverInfo, MAJOR_TIME_STEP);
  MagneticLevitation_Template_M->intgData.f[0] =
    MagneticLevitation_Template_M->odeF[0];
  MagneticLevitation_Template_M->contStates = ((X_MagneticLevitation_Template_T *)
    &MagneticLevitation_Template_X);
  rtsiSetSolverData(&MagneticLevitation_Template_M->solverInfo, (void *)
                    &MagneticLevitation_Template_M->intgData);
  rtsiSetSolverName(&MagneticLevitation_Template_M->solverInfo,"ode1");
  rtmSetTPtr(MagneticLevitation_Template_M,
             &MagneticLevitation_Template_M->Timing.tArray[0]);
  rtmSetTFinal(MagneticLevitation_Template_M, -1);
  MagneticLevitation_Template_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  MagneticLevitation_Template_M->Sizes.checksums[0] = (2502346040U);
  MagneticLevitation_Template_M->Sizes.checksums[1] = (1448473795U);
  MagneticLevitation_Template_M->Sizes.checksums[2] = (1011222565U);
  MagneticLevitation_Template_M->Sizes.checksums[3] = (1854269446U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    MagneticLevitation_Template_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(MagneticLevitation_Template_M->extModeInfo,
      &MagneticLevitation_Template_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(MagneticLevitation_Template_M->extModeInfo,
                        MagneticLevitation_Template_M->Sizes.checksums);
    rteiSetTPtr(MagneticLevitation_Template_M->extModeInfo, rtmGetTPtr
                (MagneticLevitation_Template_M));
  }

  /* block I/O */
  {
    MagneticLevitation_Template_B.StateSpace[0] = 0.0;
    MagneticLevitation_Template_B.StateSpace[1] = 0.0;
    MagneticLevitation_Template_B.StateSpace[2] = 0.0;
    MagneticLevitation_Template_B.posizione = 0.0;
    MagneticLevitation_Template_B.corrente = 0.0;
    MagneticLevitation_Template_B.Saturation = 0.0;
    MagneticLevitation_Template_B.Output = 0.0;
    MagneticLevitation_Template_B.ManualSwitch2 = 0.0;
    MagneticLevitation_Template_B.ManualSwitch4 = 0.0;
    MagneticLevitation_Template_B.x1 = 0.0;
    MagneticLevitation_Template_B.x2 = 0.0;
    MagneticLevitation_Template_B.TransferFcn = 0.0;
    MagneticLevitation_Template_B.Add = 0.0;
    MagneticLevitation_Template_B.Gain = 0.0;
    MagneticLevitation_Template_B.Sum = 0.0;
    MagneticLevitation_Template_B.Sum1 = 0.0;
    MagneticLevitation_Template_B.TmpSignalConversionAtStateSpace[0] = 0.0;
    MagneticLevitation_Template_B.TmpSignalConversionAtStateSpace[1] = 0.0;
    MagneticLevitation_Template_B.TmpSignalConversionAtStateSpace[2] = 0.0;
  }

  /* states (continuous) */
  {
    (void) memset((void *)&MagneticLevitation_Template_X, 0,
                  sizeof(X_MagneticLevitation_Template_T));
  }

  /* states (dwork) */
  (void) memset((void *)&MagneticLevitation_Template_DW, 0,
                sizeof(DW_MagneticLevitation_Templat_T));
  MagneticLevitation_Template_DW.HILInitialize_AOVoltages[0] = 0.0;
  MagneticLevitation_Template_DW.HILInitialize_AOVoltages[1] = 0.0;
  MagneticLevitation_Template_DW.BallPositionandCurrent_Buffer[0] = 0.0;
  MagneticLevitation_Template_DW.BallPositionandCurrent_Buffer[1] = 0.0;
  MagneticLevitation_Template_DW.NextOutput = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    MagneticLevitation_Template_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: MagneticLevitation_Template/HIL Initialize (hil_initialize_block) */
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
                      &MagneticLevitation_Template_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(MagneticLevitation_Template_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (MagneticLevitation_Template_DW.HILInitialize_Card,
       "d0=digital;d1=digital;led=auto;update_rate=normal;decimation=1", 63);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(MagneticLevitation_Template_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear
      (MagneticLevitation_Template_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(MagneticLevitation_Template_M, _rt_error_message);
      return;
    }

    if (!is_switching) {
      result = hil_set_analog_input_ranges
        (MagneticLevitation_Template_DW.HILInitialize_Card,
         analog_input_channels, 2U,
         analog_input_minimums, analog_input_maximums);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MagneticLevitation_Template_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_set_analog_output_ranges
        (MagneticLevitation_Template_DW.HILInitialize_Card,
         analog_output_channels, 2U,
         analog_output_minimums, analog_output_maximums);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MagneticLevitation_Template_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_write_analog
        (MagneticLevitation_Template_DW.HILInitialize_Card,
         analog_output_channels, 2U, initial_analog_outputs);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MagneticLevitation_Template_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_set_encoder_quadrature_mode
        (MagneticLevitation_Template_DW.HILInitialize_Card,
         encoder_input_channels, 2U, (t_encoder_quadrature_mode *)
         encoder_quadrature);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MagneticLevitation_Template_M, _rt_error_message);
        return;
      }
    }

    if (!is_switching) {
      result = hil_set_encoder_counts
        (MagneticLevitation_Template_DW.HILInitialize_Card,
         encoder_input_channels, 2U, initial_encoder_counts);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MagneticLevitation_Template_M, _rt_error_message);
        return;
      }
    }
  }

  {
    uint32_T tseed;
    int32_T r;
    int32_T t;
    real_T tmp;

    /* InitializeConditions for Integrator: '<Root>/Integrator2' */
    MagneticLevitation_Template_X.Integrator2_CSTATE =
      MagneticLevitation_Template_P.Integrator2_IC;

    /* InitializeConditions for StateSpace: '<S3>/State-Space' */
    MagneticLevitation_Template_X.StateSpace_CSTATE[0] =
      MagneticLevitation_Template_P.StateSpace_InitialCondition[0];
    MagneticLevitation_Template_X.StateSpace_CSTATE[1] =
      MagneticLevitation_Template_P.StateSpace_InitialCondition[1];
    MagneticLevitation_Template_X.StateSpace_CSTATE[2] =
      MagneticLevitation_Template_P.StateSpace_InitialCondition[2];

    /* InitializeConditions for TransferFcn: '<S4>/Transfer Fcn' */
    MagneticLevitation_Template_X.TransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S4>/Transfer Fcn1' */
    MagneticLevitation_Template_X.TransferFcn1_CSTATE = 0.0;

    /* InitializeConditions for RandomNumber: '<S1>/White Noise' */
    tmp = floor(MagneticLevitation_Template_P.BandLimitedWhiteNoise_seed);
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

    MagneticLevitation_Template_DW.RandSeed = tseed;
    MagneticLevitation_Template_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&MagneticLevitation_Template_DW.RandSeed) *
      MagneticLevitation_Template_P.WhiteNoise_StdDev +
      MagneticLevitation_Template_P.WhiteNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S1>/White Noise' */

    /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
    MagneticLevitation_Template_X.TransferFcn_CSTATE_b = 0.0;
  }
}

/* Model terminate function */
void MagneticLevitation_Template_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: MagneticLevitation_Template/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    static const t_uint analog_output_channels[2U] = {
      0
      , 1
    };

    hil_task_stop_all(MagneticLevitation_Template_DW.HILInitialize_Card);
    hil_monitor_stop_all(MagneticLevitation_Template_DW.HILInitialize_Card);
    is_switching = false;
    if ((MagneticLevitation_Template_P.HILInitialize_AOTerminate &&
         !is_switching) || (MagneticLevitation_Template_P.HILInitialize_AOExit &&
         is_switching)) {
      MagneticLevitation_Template_DW.HILInitialize_AOVoltages[0] =
        MagneticLevitation_Template_P.HILInitialize_AOFinal;
      MagneticLevitation_Template_DW.HILInitialize_AOVoltages[1] =
        MagneticLevitation_Template_P.HILInitialize_AOFinal;
      num_final_analog_outputs = 2U;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog
        (MagneticLevitation_Template_DW.HILInitialize_Card,
         analog_output_channels, num_final_analog_outputs,
         &MagneticLevitation_Template_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(MagneticLevitation_Template_M, _rt_error_message);
      }
    }

    hil_task_delete_all(MagneticLevitation_Template_DW.HILInitialize_Card);
    hil_monitor_delete_all(MagneticLevitation_Template_DW.HILInitialize_Card);
    hil_close(MagneticLevitation_Template_DW.HILInitialize_Card);
    MagneticLevitation_Template_DW.HILInitialize_Card = NULL;
  }
}
