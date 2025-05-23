/*
 * feedback_2019_data.c
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

/* Block parameters (default storage) */
P_feedback_2019_T feedback_2019_P = {
  /* Variable: A_ob
   * Referenced by: '<S1>/State observer'
   */
  { -1206.3753573113538, 0.0, -661856.0237847137, 0.0, -15.000010912011263, 0.0,
    1.0, 0.0, 0.0 },

  /* Variable: B_ob
   * Referenced by: '<S1>/State observer'
   */
  { 0.0, 2.6968716289104639, 0.0, 1206.3753573113538, 0.0, 664036.0237847137,
    0.0, -11.317410878711495, 13.414630388976668 },

  /* Variable: C_ob
   * Referenced by: '<S1>/State observer'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /* Variable: Kb
   * Referenced by: '<S2>/Gain1'
   */
  0.0033,

  /* Variable: offset_corrente_volt
   * Referenced by: '<S2>/Constant1'
   */
  -0.0166,

  /* Variable: offset_posizione_volt
   * Referenced by: '<S2>/Constant'
   */
  -0.0231,

  /* Variable: u
   * Referenced by: '<S1>/Constant'
   */
  14.272608670405981,

  /* Variable: x1_eq0
   * Referenced by: '<S1>/Constant1'
   */
  0.003,

  /* Variable: x2_eq0
   * Referenced by: '<S1>/Constant2'
   */
  1.4625822278430067,

  /* Mask Parameter: PIDController_D
   * Referenced by: '<S31>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S34>/Integral Gain'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S32>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_i
   * Referenced by: '<S37>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S40>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S42>/Proportional Gain'
   */
  0.0,

  /* Mask Parameter: Subsystem1_p1
   * Referenced by: '<S3>/Constant1'
   */
  -100.0,

  /* Mask Parameter: Subsystem1_p2
   * Referenced by: '<S3>/Constant2'
   */
  -60.0,

  /* Mask Parameter: Subsystem1_p3
   * Referenced by: '<S3>/Constant3'
   */
  -70.0,

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

  /* Expression: 2
   * Referenced by: '<Root>/Step'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 0.004
   * Referenced by: '<Root>/Step'
   */
  0.004,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S1>/Transfer Fcn'
   */
  -333.33333333333331,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S1>/Transfer Fcn'
   */
  333.33333333333331,

  /* Computed Parameter: TransferFcn1_A
   * Referenced by: '<S1>/Transfer Fcn1'
   */
  -333.33333333333331,

  /* Computed Parameter: TransferFcn1_C
   * Referenced by: '<S1>/Transfer Fcn1'
   */
  333.33333333333331,

  /* Expression: [0;0;0]
   * Referenced by: '<S1>/State observer'
   */
  { 0.0, 0.0, 0.0 },

  /* Computed Parameter: TransferFcn_A_f
   * Referenced by: '<S3>/Transfer Fcn'
   */
  -333.33333333333331,

  /* Computed Parameter: TransferFcn_C_j
   * Referenced by: '<S3>/Transfer Fcn'
   */
  -111111.11111111109,

  /* Computed Parameter: TransferFcn_D
   * Referenced by: '<S3>/Transfer Fcn'
   */
  333.33333333333331,

  /* Computed Parameter: TransferFcn1_A_c
   * Referenced by: '<S3>/Transfer Fcn1'
   */
  -333.33333333333331,

  /* Computed Parameter: TransferFcn1_C_a
   * Referenced by: '<S3>/Transfer Fcn1'
   */
  -111111.11111111109,

  /* Computed Parameter: TransferFcn1_D
   * Referenced by: '<S3>/Transfer Fcn1'
   */
  333.33333333333331,

  /* Computed Parameter: TransferFcn2_A
   * Referenced by: '<S3>/Transfer Fcn2'
   */
  -333.33333333333331,

  /* Computed Parameter: TransferFcn2_C
   * Referenced by: '<S3>/Transfer Fcn2'
   */
  -111111.11111111109,

  /* Computed Parameter: TransferFcn2_D
   * Referenced by: '<S3>/Transfer Fcn2'
   */
  333.33333333333331,

  /* Expression: [0, 2.4405e-05, 0.0657, 0.0120, 9.7585, 0.3708]'
   * Referenced by: '<S3>/Constant'
   */
  { 0.0, 2.4405E-5, 0.0657, 0.012, 9.7585, 0.3708 },

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

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<S1>/Manual Switch1'
   */
  0U,

  /* Computed Parameter: ManualSwitch2_CurrentSetting
   * Referenced by: '<S1>/Manual Switch2'
   */
  0U,

  /* Expression: file_name_argument
   * Referenced by: '<Root>/To Host File'
   */
  { 100U, 97U, 116U, 97U, 95U, 50U, 51U, 45U, 77U, 97U, 121U, 45U, 50U, 48U, 50U,
    53U, 95U, 49U, 50U, 45U, 50U, 56U, 45U, 48U, 49U, 46U, 109U, 97U, 116U, 0U },

  /* Expression: variable_name_argument
   * Referenced by: '<Root>/To Host File'
   */
  { 100U, 97U, 116U, 97U, 95U, 50U, 51U, 95U, 77U, 97U, 121U, 95U, 50U, 48U, 50U,
    53U, 95U, 49U, 50U, 95U, 50U, 56U, 95U, 48U, 49U, 0U },

  /* Computed Parameter: ToHostFile_FileFormat
   * Referenced by: '<Root>/To Host File'
   */
  2U
};
