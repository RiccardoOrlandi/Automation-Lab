/*
 * feedback_2019_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(t_uint64),
  sizeof(t_card)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "t_uint64",
  "t_card"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&feedback_2019_B.Step), 0, 0, 17 }
  ,

  { (char_T *)(&feedback_2019_DW.HILInitialize_AOVoltages[0]), 0, 0, 4 },

  { (char_T *)(&feedback_2019_DW.ToHostFile_PointsWritten), 14, 0, 1 },

  { (char_T *)(&feedback_2019_DW.HILInitialize_Card), 15, 0, 1 },

  { (char_T *)(&feedback_2019_DW.BallPositionandCurrent_PWORK), 11, 0, 13 },

  { (char_T *)(&feedback_2019_DW.ToHostFile_SamplesCount), 7, 0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  6U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&feedback_2019_P.A_ob[0]), 0, 0, 42 },

  { (char_T *)(&feedback_2019_P.BallPositionandCurrent_channels[0]), 7, 0, 3 },

  { (char_T *)(&feedback_2019_P.HILInitialize_OOTerminate), 0, 0, 32 },

  { (char_T *)(&feedback_2019_P.ToHostFile_Decimation), 7, 0, 2 },

  { (char_T *)(&feedback_2019_P.HILInitialize_Active), 8, 0, 10 },

  { (char_T *)(&feedback_2019_P.ManualSwitch1_CurrentSetting), 3, 0, 59 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] feedback_2019_dt.h */
