/*
 * feedback_lin_RLS_Template_2019_data.c
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

/* Block parameters (default storage) */
P_feedback_lin_RLS_Template_2_T feedback_lin_RLS_Template_201_P = {
  /* Variable: A_ob
   * Referenced by: '<S1>/State observer'
   */
  { -450.0000000000216, 0.0, -50000.00000000462, 0.0, -280.0, 0.0, 1.0, 0.0, 0.0
  },

  /* Variable: B_ob
   * Referenced by: '<S1>/State observer'
   */
  { 0.0, 2.6968716289104639, 0.0, 450.0000000000216, 0.0, 52180.00000000462, 0.0,
    253.68257820927724, 13.414630388976668 },

  /* Variable: C_ob
   * Referenced by: '<S1>/State observer'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /* Variable: Kb
   * Referenced by: '<S2>/Gain1'
   */
  0.0033,

  /* Variable: Lc_mod
   * Referenced by: '<S5>/Constant2'
   */
  0.3708,

  /* Variable: Rtot_mod
   * Referenced by: '<S5>/Constant1'
   */
  9.7585,

  /* Variable: k_mag
   * Referenced by: '<S55>/Delay'
   */
  2.4405E-5,

  /* Variable: k_mag_mod
   * Referenced by: '<S5>/Constant'
   */
  2.4405E-5,

  /* Variable: m
   * Referenced by:
   *   '<S55>/Constant2'
   *   '<S55>/Delay'
   */
  0.0657,

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

  /* Variable: y0
   * Referenced by: '<S55>/Constant1'
   */
  0.012,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S37>/Integral Gain'
   */
  3000.0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S40>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S45>/Proportional Gain'
   */
  100.0,

  /* Mask Parameter: Subsystem_mu
   * Referenced by: '<S55>/Constant'
   */
  0.98,

  /* Mask Parameter: Subsystem1_mu
   * Referenced by: '<S56>/Constant'
   */
  0.99,

  /* Mask Parameter: Subsystem2_p1
   * Referenced by: '<S4>/Constant1'
   */
  -100.0,

  /* Mask Parameter: Subsystem2_p2
   * Referenced by: '<S4>/Constant2'
   */
  -60.0,

  /* Mask Parameter: Subsystem2_p3
   * Referenced by: '<S4>/Constant3'
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

  /* Expression: 3
   * Referenced by: '<Root>/Switch'
   */
  3.0,

  /* Expression: 15
   * Referenced by: '<Root>/Switch2'
   */
  15.0,

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

  /* Expression: 0.0005
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.0005,

  /* Expression: 0.004
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.004,

  /* Expression: 10
   * Referenced by: '<Root>/Sine Wave1'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<Root>/Step1'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step1'
   */
  0.0,

  /* Expression: 0.003
   * Referenced by: '<Root>/Step1'
   */
  0.003,

  /* Expression: 0.0008
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0008,

  /* Expression: 0.004
   * Referenced by: '<Root>/Sine Wave'
   */
  0.004,

  /* Expression: 10
   * Referenced by: '<Root>/Sine Wave'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
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

  /* Expression: 10
   * Referenced by: '<Root>/Switch1'
   */
  10.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S1>/Transfer Fcn'
   */
  -200.0,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S1>/Transfer Fcn'
   */
  200.0,

  /* Computed Parameter: TransferFcn1_A
   * Referenced by: '<S1>/Transfer Fcn1'
   */
  -200.0,

  /* Computed Parameter: TransferFcn1_C
   * Referenced by: '<S1>/Transfer Fcn1'
   */
  200.0,

  /* Computed Parameter: TransferFcn2_A
   * Referenced by: '<S1>/Transfer Fcn2'
   */
  -200.0,

  /* Computed Parameter: TransferFcn2_C
   * Referenced by: '<S1>/Transfer Fcn2'
   */
  -40000.0,

  /* Computed Parameter: TransferFcn2_D
   * Referenced by: '<S1>/Transfer Fcn2'
   */
  200.0,

  /* Computed Parameter: TransferFcn_A_g
   * Referenced by: '<S4>/Transfer Fcn'
   */
  -333.33333333333331,

  /* Computed Parameter: TransferFcn_C_b
   * Referenced by: '<S4>/Transfer Fcn'
   */
  -111111.11111111109,

  /* Computed Parameter: TransferFcn_D
   * Referenced by: '<S4>/Transfer Fcn'
   */
  333.33333333333331,

  /* Computed Parameter: TransferFcn1_A_p
   * Referenced by: '<S4>/Transfer Fcn1'
   */
  -333.33333333333331,

  /* Computed Parameter: TransferFcn1_C_b
   * Referenced by: '<S4>/Transfer Fcn1'
   */
  -111111.11111111109,

  /* Computed Parameter: TransferFcn1_D
   * Referenced by: '<S4>/Transfer Fcn1'
   */
  333.33333333333331,

  /* Computed Parameter: TransferFcn2_A_k
   * Referenced by: '<S4>/Transfer Fcn2'
   */
  -333.33333333333331,

  /* Computed Parameter: TransferFcn2_C_j
   * Referenced by: '<S4>/Transfer Fcn2'
   */
  -111111.11111111109,

  /* Computed Parameter: TransferFcn2_D_g
   * Referenced by: '<S4>/Transfer Fcn2'
   */
  333.33333333333331,

  /* Expression: inv(S0)
   * Referenced by: '<S55>/Delay1'
   */
  100.0,

  /* Expression: 0.0
   * Referenced by: '<S58>/Delay1'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S58>/Gain'
   */
  2.0,

  /* Expression: 0.0
   * Referenced by: '<S58>/Delay2'
   */
  0.0,

  /* Expression: 0.002^2*9.81
   * Referenced by: '<S58>/Constant'
   */
  3.924E-5,

  /* Expression: [0, 0, 0]'
   * Referenced by: '<S5>/Delay3'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 1e-4
   * Referenced by: '<S5>/Saturation'
   */
  0.0001,

  /* Expression: 1e-6
   * Referenced by: '<S5>/Saturation'
   */
  1.0E-6,

  /* Expression: [th0(1)*0.002/th0(2); 0.002/th0(2)]
   * Referenced by: '<S56>/Delay'
   */
  { 0.052634843581445517, 0.0053937432578209273 },

  /* Expression: inv(S0)
   * Referenced by: '<S56>/Delay1'
   */
  { 10.0, -0.0, -0.0, 10.0 },

  /* Expression: 0.0
   * Referenced by: '<S58>/Delay3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Delay2'
   */
  0.0,

  /* Expression: 13
   * Referenced by: '<S5>/Saturation1'
   */
  13.0,

  /* Expression: 0
   * Referenced by: '<S5>/Saturation1'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S5>/Saturation2'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S5>/Saturation2'
   */
  0.0,

  /* Expression: [k_aero, y0, m, k_mag, Lc]'
   * Referenced by: '<S4>/Constant'
   */
  { 0.0, 0.012, 0.0657, 2.4405E-5, 0.3708 },

  /* Expression: 23
   * Referenced by: '<Root>/Saturation'
   */
  23.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation'
   */
  0.0,

  /* Expression: [0;0;0]
   * Referenced by: '<S1>/State observer'
   */
  { 0.0, 0.0, 0.0 },

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
    53U, 95U, 49U, 51U, 45U, 48U, 53U, 45U, 49U, 48U, 46U, 109U, 97U, 116U, 0U },

  /* Expression: variable_name_argument
   * Referenced by: '<Root>/To Host File'
   */
  { 100U, 97U, 116U, 97U, 95U, 50U, 51U, 95U, 77U, 97U, 121U, 95U, 50U, 48U, 50U,
    53U, 95U, 49U, 51U, 95U, 48U, 53U, 95U, 49U, 48U, 0U },

  /* Computed Parameter: ToHostFile_FileFormat
   * Referenced by: '<Root>/To Host File'
   */
  2U
};
