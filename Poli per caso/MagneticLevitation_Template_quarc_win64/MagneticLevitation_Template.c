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
#include "MagneticLevitation_Template_dt.h"

/* Block signals (default storage) */
B_MagneticLevitation_Template_T MagneticLevitation_Template_B;

/* Block states (default storage) */
DW_MagneticLevitation_Templat_T MagneticLevitation_Template_DW;

/* Real-time model */
RT_MODEL_MagneticLevitation_T_T MagneticLevitation_Template_M_;
RT_MODEL_MagneticLevitation_T_T *const MagneticLevitation_Template_M =
  &MagneticLevitation_Template_M_;

/* Model step function */
void MagneticLevitation_Template_step(void)
{
  real_T tmp;

  /* S-Function (hil_read_analog_block): '<Root>/Ball Position and Current' */

  /* S-Function Block: MagneticLevitation_Template/Ball Position and Current (hil_read_analog_block) */
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

    MagneticLevitation_Template_B.BallPositionandCurrent_o1 =
      MagneticLevitation_Template_DW.BallPositionandCurrent_Buffer[0];
    MagneticLevitation_Template_B.BallPositionandCurrent_o2 =
      MagneticLevitation_Template_DW.BallPositionandCurrent_Buffer[1];
  }

  /* Step: '<Root>/Step' */
  if (MagneticLevitation_Template_M->Timing.t[0] <
      MagneticLevitation_Template_P.Step_Time) {
    tmp = MagneticLevitation_Template_P.Step_Y0;
  } else {
    tmp = MagneticLevitation_Template_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* Gain: '<Root>/Gain' */
  MagneticLevitation_Template_B.Gain = MagneticLevitation_Template_P.Gain_Gain *
    tmp;

  /* S-Function (hil_write_analog_block): '<Root>/Voltage' */

  /* S-Function Block: MagneticLevitation_Template/Voltage (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(MagneticLevitation_Template_DW.HILInitialize_Card,
      &MagneticLevitation_Template_P.Voltage_channels, 1,
      &MagneticLevitation_Template_B.Gain);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(MagneticLevitation_Template_M, _rt_error_message);
    }
  }

  /* External mode */
  rtExtModeUploadCheckTrigger(2);

  {                                    /* Sample time: [0.0s, 0.0s] */
    rtExtModeUpload(0, (real_T)MagneticLevitation_Template_M->Timing.t[0]);
  }

  {                                    /* Sample time: [0.002s, 0.0s] */
    rtExtModeUpload(1, (real_T)
                    (((MagneticLevitation_Template_M->Timing.clockTick1+
                       MagneticLevitation_Template_M->Timing.clockTickH1*
                       4294967296.0)) * 0.002));
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(MagneticLevitation_Template_M)!=-1) &&
        !((rtmGetTFinal(MagneticLevitation_Template_M)-
           MagneticLevitation_Template_M->Timing.t[0]) >
          MagneticLevitation_Template_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(MagneticLevitation_Template_M, "Simulation finished");
    }

    if (rtmGetStopRequested(MagneticLevitation_Template_M)) {
      rtmSetErrorStatus(MagneticLevitation_Template_M, "Simulation finished");
    }
  }

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

  MagneticLevitation_Template_M->Timing.t[0] =
    MagneticLevitation_Template_M->Timing.clockTick0 *
    MagneticLevitation_Template_M->Timing.stepSize0 +
    MagneticLevitation_Template_M->Timing.clockTickH0 *
    MagneticLevitation_Template_M->Timing.stepSize0 * 4294967296.0;

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
}

/* Model initialize function */
void MagneticLevitation_Template_initialize(void)
{
  /* Registration code */

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
    rtsiSetErrorStatusPtr(&MagneticLevitation_Template_M->solverInfo,
                          (&rtmGetErrorStatus(MagneticLevitation_Template_M)));
    rtsiSetRTModelPtr(&MagneticLevitation_Template_M->solverInfo,
                      MagneticLevitation_Template_M);
  }

  rtsiSetSimTimeStep(&MagneticLevitation_Template_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&MagneticLevitation_Template_M->solverInfo,
                    "FixedStepDiscrete");
  rtmSetTPtr(MagneticLevitation_Template_M,
             &MagneticLevitation_Template_M->Timing.tArray[0]);
  rtmSetTFinal(MagneticLevitation_Template_M, -1);
  MagneticLevitation_Template_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  MagneticLevitation_Template_M->Sizes.checksums[0] = (444092263U);
  MagneticLevitation_Template_M->Sizes.checksums[1] = (1534876886U);
  MagneticLevitation_Template_M->Sizes.checksums[2] = (3240152666U);
  MagneticLevitation_Template_M->Sizes.checksums[3] = (1459424145U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    MagneticLevitation_Template_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(MagneticLevitation_Template_M->extModeInfo,
      &MagneticLevitation_Template_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(MagneticLevitation_Template_M->extModeInfo,
                        MagneticLevitation_Template_M->Sizes.checksums);
    rteiSetTPtr(MagneticLevitation_Template_M->extModeInfo, rtmGetTPtr
                (MagneticLevitation_Template_M));
  }

  /* block I/O */
  {
    MagneticLevitation_Template_B.BallPositionandCurrent_o1 = 0.0;
    MagneticLevitation_Template_B.BallPositionandCurrent_o2 = 0.0;
    MagneticLevitation_Template_B.Gain = 0.0;
  }

  /* states (dwork) */
  (void) memset((void *)&MagneticLevitation_Template_DW, 0,
                sizeof(DW_MagneticLevitation_Templat_T));
  MagneticLevitation_Template_DW.HILInitialize_AOVoltages[0] = 0.0;
  MagneticLevitation_Template_DW.HILInitialize_AOVoltages[1] = 0.0;
  MagneticLevitation_Template_DW.BallPositionandCurrent_Buffer[0] = 0.0;
  MagneticLevitation_Template_DW.BallPositionandCurrent_Buffer[1] = 0.0;

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
