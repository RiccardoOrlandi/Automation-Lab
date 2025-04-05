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
 * C source code generated on : Fri Mar  7 12:58:47 2025
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
  /* Mask Parameter: BallPositionandCurrent_channels
   * Referenced by: '<Root>/Ball Position and Current'
   */
  { 0U, 1U },

  /* Mask Parameter: Voltage_channels
   * Referenced by: '<Root>/Voltage'
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

  /* Expression: 1
   * Referenced by: '<Root>/Step'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: 23
   * Referenced by: '<Root>/Step'
   */
  23.0,

  /* Expression: 1/3
   * Referenced by: '<Root>/Gain'
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
   * Referenced by: '<Root>/Ball Position and Current'
   */
  1,

  /* Computed Parameter: Voltage_Active
   * Referenced by: '<Root>/Voltage'
   */
  0,

  /* Expression: file_name_argument
   * Referenced by: '<Root>/To Host File'
   */
  { 100U, 97U, 116U, 97U, 95U, 48U, 55U, 45U, 77U, 97U, 114U, 45U, 50U, 48U, 50U,
    53U, 95U, 49U, 50U, 45U, 53U, 56U, 45U, 52U, 54U, 46U, 109U, 97U, 116U, 0U },

  /* Expression: variable_name_argument
   * Referenced by: '<Root>/To Host File'
   */
  { 100U, 97U, 116U, 97U, 95U, 48U, 55U, 95U, 77U, 97U, 114U, 95U, 50U, 48U, 50U,
    53U, 95U, 49U, 50U, 95U, 53U, 56U, 95U, 52U, 54U, 0U },

  /* Computed Parameter: ToHostFile_FileFormat
   * Referenced by: '<Root>/To Host File'
   */
  2U
};
