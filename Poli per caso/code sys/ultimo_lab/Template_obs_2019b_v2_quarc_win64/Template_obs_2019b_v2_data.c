/*
 * Template_obs_2019b_v2_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Template_obs_2019b_v2".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Fri May 23 13:29:31 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Template_obs_2019b_v2.h"
#include "Template_obs_2019b_v2_private.h"

/* Block parameters (default storage) */
P_Template_obs_2019b_v2_T Template_obs_2019b_v2_P = {
  /* Variable: A_ob
   * Referenced by: '<S4>/State-Space'
   */
  { -96.747519112604337, -0.008064065864891069, -2180.0412597364466,
    -0.0080640658648476332, -1536.8547773373655, 0.24115387340830274, 1.0, 0.0,
    0.0 },

  /* Variable: B_ob
   * Referenced by: '<S4>/State-Space'
   */
  { 0.0, 2.6968716289104639, 0.0, 96.747519112604337, 0.008064065864891069,
    4360.0412597364466, 0.0080640658648476332, 1510.5373555466426,
    13.173476515568366 },

  /* Variable: C_ob
   * Referenced by: '<S4>/State-Space'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /* Variable: Kb
   * Referenced by: '<S2>/Gain1'
   */
  0.0033,

  /* Variable: Ken_eta
   * Referenced by: '<Root>/Gain'
   */
  -54897.637806349718,

  /* Variable: Ken_x
   * Referenced by: '<Root>/Gain1'
   */
  { 30155.878639261235, 88.667171744067659, 938.48692908260625 },

  /* Variable: offset_corrente_volt
   * Referenced by: '<S2>/Constant1'
   */
  -0.0166,

  /* Variable: offset_posizione_volt
   * Referenced by: '<S2>/Constant'
   */
  -0.0231,

  /* Variable: u
   * Referenced by: '<Root>/Constant'
   */
  14.272608670405981,

  /* Variable: x1_eq0
   * Referenced by:
   *   '<Root>/Constant2'
   *   '<S4>/Constant'
   *   '<S5>/Constant'
   */
  0.003,

  /* Variable: x2_eq0
   * Referenced by:
   *   '<Root>/Constant4'
   *   '<S4>/Constant1'
   *   '<S5>/Constant1'
   */
  1.4625822278430067,

  /* Mask Parameter: BandLimitedWhiteNoise_Cov
   * Referenced by: '<S1>/Output'
   */
  1.79868E-13,

  /* Mask Parameter: BandLimitedWhiteNoise_seed
   * Referenced by: '<S1>/White Noise'
   */
  23341.0,

  /* Mask Parameter: BallPositionandCurrent_channels
   * Referenced by: '<S2>/Ball Position and Current'
   */
  { 0U, 1U },

  /* Mask Parameter: Voltage_channels
   * Referenced by: '<S2>/Voltage'
   */
  0U,

  /* Expression: 15
   * Referenced by: '<S3>/Switch'
   */
  15.0,

  /* Expression: 6
   * Referenced by: '<Root>/Switch'
   */
  6.0,

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Expression: [-x1_eq0, -x2_eq0, 0]
   * Referenced by: '<S4>/State-Space'
   */
  { -0.003, -1.4625822278430067, 0.0 },

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S5>/Transfer Fcn'
   */
  -33.333333333333336,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S5>/Transfer Fcn'
   */
  33.333333333333336,

  /* Computed Parameter: TransferFcn1_A
   * Referenced by: '<S5>/Transfer Fcn1'
   */
  -125.0,

  /* Computed Parameter: TransferFcn1_C
   * Referenced by: '<S5>/Transfer Fcn1'
   */
  125.0,

  /* Expression: 1
   * Referenced by: '<Root>/Step'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 0.004
   * Referenced by: '<Root>/Step'
   */
  0.004,

  /* Expression: 0.0005
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0005,

  /* Expression: 0.004
   * Referenced by: '<Root>/Sine Wave'
   */
  0.004,

  /* Expression: 1
   * Referenced by: '<Root>/Sine Wave'
   */
  1.0,

  /* Computed Parameter: SineWave_Hsin
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0019999986666669333,

  /* Computed Parameter: SineWave_HCos
   * Referenced by: '<Root>/Sine Wave'
   */
  0.99999800000066663,

  /* Computed Parameter: SineWave_PSin
   * Referenced by: '<Root>/Sine Wave'
   */
  -0.0019999986666669333,

  /* Computed Parameter: SineWave_PCos
   * Referenced by: '<Root>/Sine Wave'
   */
  0.99999800000066663,

  /* Expression: 0.0015
   * Referenced by: '<S3>/Sine Wave'
   */
  0.0015,

  /* Expression: 0.005
   * Referenced by: '<S3>/Sine Wave'
   */
  0.005,

  /* Expression: 1
   * Referenced by: '<S3>/Sine Wave'
   */
  1.0,

  /* Computed Parameter: SineWave_Hsin_d
   * Referenced by: '<S3>/Sine Wave'
   */
  0.0019999986666669333,

  /* Computed Parameter: SineWave_HCos_d
   * Referenced by: '<S3>/Sine Wave'
   */
  0.99999800000066663,

  /* Computed Parameter: SineWave_PSin_a
   * Referenced by: '<S3>/Sine Wave'
   */
  -0.0019999986666669333,

  /* Computed Parameter: SineWave_PCos_h
   * Referenced by: '<S3>/Sine Wave'
   */
  0.99999800000066663,

  /* Expression: 3
   * Referenced by: '<S3>/Step'
   */
  3.0,

  /* Expression: 0
   * Referenced by: '<S3>/Step'
   */
  0.0,

  /* Expression: 0.003
   * Referenced by: '<S3>/Step'
   */
  0.003,

  /* Expression: 5
   * Referenced by: '<S3>/Step1'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<S3>/Step1'
   */
  0.0,

  /* Expression: 0.006
   * Referenced by: '<S3>/Step1'
   */
  0.006,

  /* Expression: 10
   * Referenced by: '<S3>/Step2'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S3>/Step2'
   */
  0.0,

  /* Expression: -0.002
   * Referenced by: '<S3>/Step2'
   */
  -0.002,

  /* Computed Parameter: TransferFcn2_A
   * Referenced by: '<Root>/Transfer Fcn2'
   */
  -100.0,

  /* Computed Parameter: TransferFcn2_C
   * Referenced by: '<Root>/Transfer Fcn2'
   */
  100.0,

  /* Computed Parameter: TransferFcn3_A
   * Referenced by: '<Root>/Transfer Fcn3'
   */
  -125.0,

  /* Computed Parameter: TransferFcn3_C
   * Referenced by: '<Root>/Transfer Fcn3'
   */
  125.0,

  /* Computed Parameter: TransferFcn1_A_g
   * Referenced by: '<Root>/Transfer Fcn1'
   */
  -33.333333333333336,

  /* Computed Parameter: TransferFcn1_C_m
   * Referenced by: '<Root>/Transfer Fcn1'
   */
  -1111.1111111111113,

  /* Computed Parameter: TransferFcn1_D
   * Referenced by: '<Root>/Transfer Fcn1'
   */
  33.333333333333336,

  /* Expression: 0
   * Referenced by: '<S1>/White Noise'
   */
  0.0,

  /* Computed Parameter: WhiteNoise_StdDev
   * Referenced by: '<S1>/White Noise'
   */
  1.0,

  /* Computed Parameter: TransferFcn4_A
   * Referenced by: '<Root>/Transfer Fcn4'
   */
  -1.0,

  /* Computed Parameter: TransferFcn4_C
   * Referenced by: '<Root>/Transfer Fcn4'
   */
  1.0,

  /* Expression: 23
   * Referenced by: '<Root>/Saturation'
   */
  23.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation'
   */
  0.0,

  /* Expression: 1/3
   * Referenced by: '<S2>/Gain'
   */
  0.33333333333333331,

  /* Computed Parameter: TransferFcn_A_c
   * Referenced by: '<S4>/Transfer Fcn'
   */
  -33.333333333333336,

  /* Computed Parameter: TransferFcn_C_e
   * Referenced by: '<S4>/Transfer Fcn'
   */
  33.333333333333336,

  /* Computed Parameter: TransferFcn1_A_c
   * Referenced by: '<S4>/Transfer Fcn1'
   */
  -125.0,

  /* Computed Parameter: TransferFcn1_C_f
   * Referenced by: '<S4>/Transfer Fcn1'
   */
  125.0,

  /* Computed Parameter: ToHostFile_Decimation
   * Referenced by: '<Root>/To Host File'
   */
  1U,

  /* Computed Parameter: ToHostFile_BitRate
   * Referenced by: '<Root>/To Host File'
   */
  2000000U,

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: BallPositionandCurrent_Active
   * Referenced by: '<S2>/Ball Position and Current'
   */
  1,

  /* Computed Parameter: Voltage_Active
   * Referenced by: '<S2>/Voltage'
   */
  0,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  1U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<S5>/Manual Switch1'
   */
  0U,

  /* Computed Parameter: ManualSwitch2_CurrentSetting
   * Referenced by: '<S5>/Manual Switch2'
   */
  0U,

  /* Computed Parameter: ManualSwitch_CurrentSetting_i
   * Referenced by: '<S5>/Manual Switch'
   */
  0U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting_m
   * Referenced by: '<Root>/Manual Switch1'
   */
  1U,

  /* Computed Parameter: ManualSwitch5_CurrentSetting
   * Referenced by: '<Root>/Manual Switch5'
   */
  0U,

  /* Computed Parameter: ManualSwitch6_CurrentSetting
   * Referenced by: '<Root>/Manual Switch6'
   */
  1U,

  /* Expression: file_name_argument
   * Referenced by: '<Root>/To Host File'
   */
  { 100U, 97U, 116U, 97U, 95U, 50U, 51U, 45U, 77U, 97U, 121U, 45U, 50U, 48U, 50U,
    53U, 95U, 49U, 51U, 45U, 50U, 57U, 45U, 50U, 57U, 46U, 109U, 97U, 116U, 0U },

  /* Expression: variable_name_argument
   * Referenced by: '<Root>/To Host File'
   */
  { 100U, 97U, 116U, 97U, 95U, 50U, 51U, 95U, 77U, 97U, 121U, 95U, 50U, 48U, 50U,
    53U, 95U, 49U, 51U, 95U, 50U, 57U, 95U, 50U, 57U, 0U },

  /* Computed Parameter: ToHostFile_FileFormat
   * Referenced by: '<Root>/To Host File'
   */
  2U,

  /* Computed Parameter: ManualSwitch3_CurrentSetting
   * Referenced by: '<Root>/Manual Switch3'
   */
  1U,

  /* Computed Parameter: ManualSwitch2_CurrentSetting_n
   * Referenced by: '<Root>/Manual Switch2'
   */
  1U,

  /* Computed Parameter: ManualSwitch_CurrentSetting_l
   * Referenced by: '<S4>/Manual Switch'
   */
  1U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting_n
   * Referenced by: '<S4>/Manual Switch1'
   */
  0U
};
