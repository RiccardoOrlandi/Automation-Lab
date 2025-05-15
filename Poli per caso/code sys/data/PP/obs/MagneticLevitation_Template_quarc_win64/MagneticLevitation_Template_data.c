/*
 * MagneticLevitation_Template_data.c
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

/* Block parameters (default storage) */
P_MagneticLevitation_Template_T MagneticLevitation_Template_P = {
  /* Variable: A_ob
   * Referenced by: '<S3>/State-Space'
   */
  { -899.999999999839, 0.0, -199999.9999999454, 0.0, -700.0, 0.0, 1.0, 0.0, 0.0
  },

  /* Variable: B_ob
   * Referenced by: '<S3>/State-Space'
   */
  { 0.0, 2.6968716289104639, 0.0, 899.999999999839, 0.0, 202179.9999999454, 0.0,
    673.68257820927727, 13.414630388976668 },

  /* Variable: C_ob
   * Referenced by: '<S3>/State-Space'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /* Variable: Kb
   * Referenced by: '<S2>/Gain1'
   */
  0.0033,

  /* Variable: Ken_eta
   * Referenced by: '<Root>/K_eta1'
   */
  -19349.023601418645,

  /* Variable: Ken_x
   * Referenced by: '<Root>/Gain'
   */
  { 14959.559390107599, 51.423500000041983, 311.795694605335 },

  /* Variable: Upper_bound_V
   * Referenced by: '<Root>/Saturation'
   */
  23.0,

  /* Variable: offset_corrente_volt
   * Referenced by: '<S2>/Constant1'
   */
  -0.0166,

  /* Variable: offset_posizione_volt
   * Referenced by: '<S2>/Constant'
   */
  -0.0231,

  /* Variable: u
   * Referenced by: '<Root>/Constant1'
   */
  14.272608670405981,

  /* Variable: x1_eq0
   * Referenced by:
   *   '<Root>/Constant2'
   *   '<S3>/Constant'
   *   '<S4>/Constant'
   */
  0.003,

  /* Variable: x2_eq0
   * Referenced by:
   *   '<Root>/Constant4'
   *   '<S3>/Constant1'
   *   '<S4>/Constant1'
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
   * Referenced by: '<Root>/Integrator2'
   */
  0.0,

  /* Expression: [-x1_eq0, -x2_eq0, 0]
   * Referenced by: '<S3>/State-Space'
   */
  { -0.003, -1.4625822278430067, 0.0 },

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S4>/Transfer Fcn'
   */
  -333.33333333333331,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S4>/Transfer Fcn'
   */
  333.33333333333331,

  /* Computed Parameter: TransferFcn1_A
   * Referenced by: '<S4>/Transfer Fcn1'
   */
  -333.33333333333331,

  /* Computed Parameter: TransferFcn1_C
   * Referenced by: '<S4>/Transfer Fcn1'
   */
  333.33333333333331,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/White Noise'
   */
  0.0,

  /* Computed Parameter: WhiteNoise_StdDev
   * Referenced by: '<S1>/White Noise'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Sine Wave'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Sine Wave'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 4e-3
   * Referenced by: '<Root>/Constant'
   */
  0.004,

  /* Expression: 2
   * Referenced by: '<Root>/Step'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 0.005
   * Referenced by: '<Root>/Step'
   */
  0.005,

  /* Expression: 1
   * Referenced by: '<Root>/Sine Wave1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Sine Wave1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.0,

  /* Computed Parameter: TransferFcn_A_o
   * Referenced by: '<Root>/Transfer Fcn'
   */
  -333.33333333333331,

  /* Computed Parameter: TransferFcn_C_i
   * Referenced by: '<Root>/Transfer Fcn'
   */
  -111111.11111111109,

  /* Computed Parameter: TransferFcn_D
   * Referenced by: '<Root>/Transfer Fcn'
   */
  333.33333333333331,

  /* Expression: 1/3
   * Referenced by: '<S2>/Gain'
   */
  0.33333333333333331,

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

  /* Computed Parameter: ManualSwitch3_CurrentSetting
   * Referenced by: '<Root>/Manual Switch3'
   */
  0U,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  1U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<S4>/Manual Switch1'
   */
  0U,

  /* Computed Parameter: ManualSwitch2_CurrentSetting
   * Referenced by: '<S4>/Manual Switch2'
   */
  0U,

  /* Computed Parameter: ManualSwitch_CurrentSetting_d
   * Referenced by: '<S4>/Manual Switch'
   */
  0U,

  /* Computed Parameter: ManualSwitch2_CurrentSetting_f
   * Referenced by: '<Root>/Manual Switch2'
   */
  1U,

  /* Computed Parameter: ManualSwitch4_CurrentSetting
   * Referenced by: '<Root>/Manual Switch4'
   */
  1U,

  /* Expression: file_name_argument
   * Referenced by: '<Root>/To Host File'
   */
  { 100U, 97U, 116U, 97U, 95U, 49U, 51U, 45U, 77U, 97U, 121U, 45U, 50U, 48U, 50U,
    53U, 95U, 49U, 55U, 45U, 52U, 51U, 45U, 50U, 48U, 46U, 109U, 97U, 116U, 0U },

  /* Expression: variable_name_argument
   * Referenced by: '<Root>/To Host File'
   */
  { 100U, 97U, 116U, 97U, 95U, 49U, 51U, 95U, 77U, 97U, 121U, 95U, 50U, 48U, 50U,
    53U, 95U, 49U, 55U, 95U, 52U, 51U, 95U, 50U, 48U, 0U },

  /* Computed Parameter: ToHostFile_FileFormat
   * Referenced by: '<Root>/To Host File'
   */
  2U
};
