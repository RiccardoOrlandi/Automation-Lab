/*
 * Template_obs_2019b_v2.h
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

#ifndef RTW_HEADER_Template_obs_2019b_v2_h_
#define RTW_HEADER_Template_obs_2019b_v2_h_
#include <math.h>
#include <float.h>
#include <string.h>
#ifndef Template_obs_2019b_v2_COMMON_INCLUDES_
# define Template_obs_2019b_v2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "hil.h"
#include "quanser_messages.h"
#include "quanser_extern.h"
#endif                              /* Template_obs_2019b_v2_COMMON_INCLUDES_ */

#include "Template_obs_2019b_v2_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T StateSpace[3];                /* '<S4>/State-Space' */
  real_T posizione;                    /* '<S2>/Gain1' */
  real_T corrente;                     /* '<S2>/Add' */
  real_T Sum2;                         /* '<Root>/Sum2' */
  real_T Sum;                          /* '<Root>/Sum' */
  real_T Step;                         /* '<Root>/Step' */
  real_T SineWave;                     /* '<Root>/Sine Wave' */
  real_T SineWave_b;                   /* '<S3>/Sine Wave' */
  real_T ManualSwitch1;                /* '<Root>/Manual Switch1' */
  real_T x1;                           /* '<Root>/Sum4' */
  real_T ManualSwitch5;                /* '<Root>/Manual Switch5' */
  real_T x1_h;                         /* '<Root>/Sum5' */
  real_T ManualSwitch6;                /* '<Root>/Manual Switch6' */
  real_T TransferFcn1;                 /* '<Root>/Transfer Fcn1' */
  real_T Output;                       /* '<S1>/Output' */
  real_T Gain;                         /* '<S2>/Gain' */
  real_T pos_filtro;                   /* '<S4>/Manual Switch' */
  real_T coorr_filtro;                 /* '<S4>/Transfer Fcn1' */
  real_T TmpSignalConversionAtStateSpace[3];
  real_T Sum1;                         /* '<Root>/Sum1' */
} B_Template_obs_2019b_v2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T HILInitialize_AOVoltages[2];  /* '<Root>/HIL Initialize' */
  real_T BallPositionandCurrent_Buffer[2];/* '<S2>/Ball Position and Current' */
  real_T lastSin;                      /* '<Root>/Sine Wave' */
  real_T lastCos;                      /* '<Root>/Sine Wave' */
  real_T lastSin_b;                    /* '<S3>/Sine Wave' */
  real_T lastCos_n;                    /* '<S3>/Sine Wave' */
  real_T NextOutput;                   /* '<S1>/White Noise' */
  t_uint64 ToHostFile_PointsWritten;   /* '<Root>/To Host File' */
  t_card HILInitialize_Card;           /* '<Root>/HIL Initialize' */
  void *BallPositionandCurrent_PWORK;  /* '<S2>/Ball Position and Current' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData[2];
  } Scope4_PWORK;                      /* '<Root>/Scope4' */

  struct {
    void *LoggedData[2];
  } Scope5_PWORK;                      /* '<Root>/Scope5' */

  struct {
    void *LoggedData[2];
  } Scope6_PWORK;                      /* '<Root>/Scope6' */

  void *ToHostFile_PWORK[2];           /* '<Root>/To Host File' */
  void *Voltage_PWORK;                 /* '<S2>/Voltage' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK_h;                     /* '<S4>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK_f;                    /* '<S4>/Scope1' */

  int32_T systemEnable;                /* '<Root>/Sine Wave' */
  int32_T systemEnable_p;              /* '<S3>/Sine Wave' */
  uint32_T ToHostFile_SamplesCount;    /* '<Root>/To Host File' */
  uint32_T ToHostFile_ArrayNameLength; /* '<Root>/To Host File' */
  uint32_T RandSeed;                   /* '<S1>/White Noise' */
} DW_Template_obs_2019b_v2_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T StateSpace_CSTATE[3];         /* '<S4>/State-Space' */
  real_T TransferFcn_CSTATE;           /* '<S5>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE;          /* '<S5>/Transfer Fcn1' */
  real_T TransferFcn2_CSTATE;          /* '<Root>/Transfer Fcn2' */
  real_T TransferFcn3_CSTATE;          /* '<Root>/Transfer Fcn3' */
  real_T TransferFcn1_CSTATE_m;        /* '<Root>/Transfer Fcn1' */
  real_T TransferFcn4_CSTATE;          /* '<Root>/Transfer Fcn4' */
  real_T TransferFcn_CSTATE_b;         /* '<S4>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE_k;        /* '<S4>/Transfer Fcn1' */
} X_Template_obs_2019b_v2_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T StateSpace_CSTATE[3];         /* '<S4>/State-Space' */
  real_T TransferFcn_CSTATE;           /* '<S5>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE;          /* '<S5>/Transfer Fcn1' */
  real_T TransferFcn2_CSTATE;          /* '<Root>/Transfer Fcn2' */
  real_T TransferFcn3_CSTATE;          /* '<Root>/Transfer Fcn3' */
  real_T TransferFcn1_CSTATE_m;        /* '<Root>/Transfer Fcn1' */
  real_T TransferFcn4_CSTATE;          /* '<Root>/Transfer Fcn4' */
  real_T TransferFcn_CSTATE_b;         /* '<S4>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE_k;        /* '<S4>/Transfer Fcn1' */
} XDot_Template_obs_2019b_v2_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator' */
  boolean_T StateSpace_CSTATE[3];      /* '<S4>/State-Space' */
  boolean_T TransferFcn_CSTATE;        /* '<S5>/Transfer Fcn' */
  boolean_T TransferFcn1_CSTATE;       /* '<S5>/Transfer Fcn1' */
  boolean_T TransferFcn2_CSTATE;       /* '<Root>/Transfer Fcn2' */
  boolean_T TransferFcn3_CSTATE;       /* '<Root>/Transfer Fcn3' */
  boolean_T TransferFcn1_CSTATE_m;     /* '<Root>/Transfer Fcn1' */
  boolean_T TransferFcn4_CSTATE;       /* '<Root>/Transfer Fcn4' */
  boolean_T TransferFcn_CSTATE_b;      /* '<S4>/Transfer Fcn' */
  boolean_T TransferFcn1_CSTATE_k;     /* '<S4>/Transfer Fcn1' */
} XDis_Template_obs_2019b_v2_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters (default storage) */
struct P_Template_obs_2019b_v2_T_ {
  real_T A_ob[9];                      /* Variable: A_ob
                                        * Referenced by: '<S4>/State-Space'
                                        */
  real_T B_ob[9];                      /* Variable: B_ob
                                        * Referenced by: '<S4>/State-Space'
                                        */
  real_T C_ob[9];                      /* Variable: C_ob
                                        * Referenced by: '<S4>/State-Space'
                                        */
  real_T Kb;                           /* Variable: Kb
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T Ken_eta;                      /* Variable: Ken_eta
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Ken_x[3];                     /* Variable: Ken_x
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T offset_corrente_volt;         /* Variable: offset_corrente_volt
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T offset_posizione_volt;        /* Variable: offset_posizione_volt
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T u;                            /* Variable: u
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T x1_eq0;                       /* Variable: x1_eq0
                                        * Referenced by:
                                        *   '<Root>/Constant2'
                                        *   '<S4>/Constant'
                                        *   '<S5>/Constant'
                                        */
  real_T x2_eq0;                       /* Variable: x2_eq0
                                        * Referenced by:
                                        *   '<Root>/Constant4'
                                        *   '<S4>/Constant1'
                                        *   '<S5>/Constant1'
                                        */
  real_T BandLimitedWhiteNoise_Cov; /* Mask Parameter: BandLimitedWhiteNoise_Cov
                                     * Referenced by: '<S1>/Output'
                                     */
  real_T BandLimitedWhiteNoise_seed;
                                   /* Mask Parameter: BandLimitedWhiteNoise_seed
                                    * Referenced by: '<S1>/White Noise'
                                    */
  uint32_T BallPositionandCurrent_channels[2];
                              /* Mask Parameter: BallPositionandCurrent_channels
                               * Referenced by: '<S2>/Ball Position and Current'
                               */
  uint32_T Voltage_channels;           /* Mask Parameter: Voltage_channels
                                        * Referenced by: '<S2>/Voltage'
                                        */
  real_T Switch_Threshold;             /* Expression: 15
                                        * Referenced by: '<S3>/Switch'
                                        */
  real_T Switch_Threshold_f;           /* Expression: 6
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T HILInitialize_OOTerminate;/* Expression: set_other_outputs_at_terminate
                                    * Referenced by: '<Root>/HIL Initialize'
                                    */
  real_T HILInitialize_OOExit;    /* Expression: set_other_outputs_at_switch_out
                                   * Referenced by: '<Root>/HIL Initialize'
                                   */
  real_T HILInitialize_AOFinal;        /* Expression: final_analog_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T HILInitialize_POFinal;        /* Expression: final_pwm_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T StateSpace_InitialCondition[3];/* Expression: [-x1_eq0, -x2_eq0, 0]
                                         * Referenced by: '<S4>/State-Space'
                                         */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S5>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S5>/Transfer Fcn'
                                        */
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<S5>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<S5>/Transfer Fcn1'
                                        */
  real_T Step_Time;                    /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 0.004
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T SineWave_Amp;                 /* Expression: 0.0005
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0.004
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Hsin;                /* Computed Parameter: SineWave_Hsin
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_HCos;                /* Computed Parameter: SineWave_HCos
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_PSin;                /* Computed Parameter: SineWave_PSin
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_PCos;                /* Computed Parameter: SineWave_PCos
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Amp_g;               /* Expression: 0.0015
                                        * Referenced by: '<S3>/Sine Wave'
                                        */
  real_T SineWave_Bias_f;              /* Expression: 0.005
                                        * Referenced by: '<S3>/Sine Wave'
                                        */
  real_T SineWave_Freq_o;              /* Expression: 1
                                        * Referenced by: '<S3>/Sine Wave'
                                        */
  real_T SineWave_Hsin_d;              /* Computed Parameter: SineWave_Hsin_d
                                        * Referenced by: '<S3>/Sine Wave'
                                        */
  real_T SineWave_HCos_d;              /* Computed Parameter: SineWave_HCos_d
                                        * Referenced by: '<S3>/Sine Wave'
                                        */
  real_T SineWave_PSin_a;              /* Computed Parameter: SineWave_PSin_a
                                        * Referenced by: '<S3>/Sine Wave'
                                        */
  real_T SineWave_PCos_h;              /* Computed Parameter: SineWave_PCos_h
                                        * Referenced by: '<S3>/Sine Wave'
                                        */
  real_T Step_Time_c;                  /* Expression: 3
                                        * Referenced by: '<S3>/Step'
                                        */
  real_T Step_Y0_a;                    /* Expression: 0
                                        * Referenced by: '<S3>/Step'
                                        */
  real_T Step_YFinal_c;                /* Expression: 0.003
                                        * Referenced by: '<S3>/Step'
                                        */
  real_T Step1_Time;                   /* Expression: 5
                                        * Referenced by: '<S3>/Step1'
                                        */
  real_T Step1_Y0;                     /* Expression: 0
                                        * Referenced by: '<S3>/Step1'
                                        */
  real_T Step1_YFinal;                 /* Expression: 0.006
                                        * Referenced by: '<S3>/Step1'
                                        */
  real_T Step2_Time;                   /* Expression: 10
                                        * Referenced by: '<S3>/Step2'
                                        */
  real_T Step2_Y0;                     /* Expression: 0
                                        * Referenced by: '<S3>/Step2'
                                        */
  real_T Step2_YFinal;                 /* Expression: -0.002
                                        * Referenced by: '<S3>/Step2'
                                        */
  real_T TransferFcn2_A;               /* Computed Parameter: TransferFcn2_A
                                        * Referenced by: '<Root>/Transfer Fcn2'
                                        */
  real_T TransferFcn2_C;               /* Computed Parameter: TransferFcn2_C
                                        * Referenced by: '<Root>/Transfer Fcn2'
                                        */
  real_T TransferFcn3_A;               /* Computed Parameter: TransferFcn3_A
                                        * Referenced by: '<Root>/Transfer Fcn3'
                                        */
  real_T TransferFcn3_C;               /* Computed Parameter: TransferFcn3_C
                                        * Referenced by: '<Root>/Transfer Fcn3'
                                        */
  real_T TransferFcn1_A_g;             /* Computed Parameter: TransferFcn1_A_g
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C_m;             /* Computed Parameter: TransferFcn1_C_m
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_D;               /* Computed Parameter: TransferFcn1_D
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  real_T WhiteNoise_Mean;              /* Expression: 0
                                        * Referenced by: '<S1>/White Noise'
                                        */
  real_T WhiteNoise_StdDev;            /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S1>/White Noise'
                                        */
  real_T TransferFcn4_A;               /* Computed Parameter: TransferFcn4_A
                                        * Referenced by: '<Root>/Transfer Fcn4'
                                        */
  real_T TransferFcn4_C;               /* Computed Parameter: TransferFcn4_C
                                        * Referenced by: '<Root>/Transfer Fcn4'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 23
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/3
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T TransferFcn_A_c;              /* Computed Parameter: TransferFcn_A_c
                                        * Referenced by: '<S4>/Transfer Fcn'
                                        */
  real_T TransferFcn_C_e;              /* Computed Parameter: TransferFcn_C_e
                                        * Referenced by: '<S4>/Transfer Fcn'
                                        */
  real_T TransferFcn1_A_c;             /* Computed Parameter: TransferFcn1_A_c
                                        * Referenced by: '<S4>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C_f;             /* Computed Parameter: TransferFcn1_C_f
                                        * Referenced by: '<S4>/Transfer Fcn1'
                                        */
  uint32_T ToHostFile_Decimation;   /* Computed Parameter: ToHostFile_Decimation
                                     * Referenced by: '<Root>/To Host File'
                                     */
  uint32_T ToHostFile_BitRate;         /* Computed Parameter: ToHostFile_BitRate
                                        * Referenced by: '<Root>/To Host File'
                                        */
  boolean_T HILInitialize_Active;    /* Computed Parameter: HILInitialize_Active
                                      * Referenced by: '<Root>/HIL Initialize'
                                      */
  boolean_T HILInitialize_AOTerminate;
                                /* Computed Parameter: HILInitialize_AOTerminate
                                 * Referenced by: '<Root>/HIL Initialize'
                                 */
  boolean_T HILInitialize_AOExit;    /* Computed Parameter: HILInitialize_AOExit
                                      * Referenced by: '<Root>/HIL Initialize'
                                      */
  boolean_T HILInitialize_DOTerminate;
                                /* Computed Parameter: HILInitialize_DOTerminate
                                 * Referenced by: '<Root>/HIL Initialize'
                                 */
  boolean_T HILInitialize_DOExit;    /* Computed Parameter: HILInitialize_DOExit
                                      * Referenced by: '<Root>/HIL Initialize'
                                      */
  boolean_T HILInitialize_POTerminate;
                                /* Computed Parameter: HILInitialize_POTerminate
                                 * Referenced by: '<Root>/HIL Initialize'
                                 */
  boolean_T HILInitialize_POExit;    /* Computed Parameter: HILInitialize_POExit
                                      * Referenced by: '<Root>/HIL Initialize'
                                      */
  boolean_T HILInitialize_DOFinal;  /* Computed Parameter: HILInitialize_DOFinal
                                     * Referenced by: '<Root>/HIL Initialize'
                                     */
  boolean_T BallPositionandCurrent_Active;
                            /* Computed Parameter: BallPositionandCurrent_Active
                             * Referenced by: '<S2>/Ball Position and Current'
                             */
  boolean_T Voltage_Active;            /* Computed Parameter: Voltage_Active
                                        * Referenced by: '<S2>/Voltage'
                                        */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<Root>/Manual Switch'
                               */
  uint8_T ManualSwitch1_CurrentSetting;
                             /* Computed Parameter: ManualSwitch1_CurrentSetting
                              * Referenced by: '<S5>/Manual Switch1'
                              */
  uint8_T ManualSwitch2_CurrentSetting;
                             /* Computed Parameter: ManualSwitch2_CurrentSetting
                              * Referenced by: '<S5>/Manual Switch2'
                              */
  uint8_T ManualSwitch_CurrentSetting_i;
                            /* Computed Parameter: ManualSwitch_CurrentSetting_i
                             * Referenced by: '<S5>/Manual Switch'
                             */
  uint8_T ManualSwitch1_CurrentSetting_m;
                           /* Computed Parameter: ManualSwitch1_CurrentSetting_m
                            * Referenced by: '<Root>/Manual Switch1'
                            */
  uint8_T ManualSwitch5_CurrentSetting;
                             /* Computed Parameter: ManualSwitch5_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch5'
                              */
  uint8_T ManualSwitch6_CurrentSetting;
                             /* Computed Parameter: ManualSwitch6_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch6'
                              */
  uint8_T ToHostFile_file_name[30];    /* Expression: file_name_argument
                                        * Referenced by: '<Root>/To Host File'
                                        */
  uint8_T ToHostFile_VarName[26];      /* Expression: variable_name_argument
                                        * Referenced by: '<Root>/To Host File'
                                        */
  uint8_T ToHostFile_FileFormat;    /* Computed Parameter: ToHostFile_FileFormat
                                     * Referenced by: '<Root>/To Host File'
                                     */
  uint8_T ManualSwitch3_CurrentSetting;
                             /* Computed Parameter: ManualSwitch3_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch3'
                              */
  uint8_T ManualSwitch2_CurrentSetting_n;
                           /* Computed Parameter: ManualSwitch2_CurrentSetting_n
                            * Referenced by: '<Root>/Manual Switch2'
                            */
  uint8_T ManualSwitch_CurrentSetting_l;
                            /* Computed Parameter: ManualSwitch_CurrentSetting_l
                             * Referenced by: '<S4>/Manual Switch'
                             */
  uint8_T ManualSwitch1_CurrentSetting_n;
                           /* Computed Parameter: ManualSwitch1_CurrentSetting_n
                            * Referenced by: '<S4>/Manual Switch1'
                            */
};

/* Real-time Model Data Structure */
struct tag_RTM_Template_obs_2019b_v2_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_Template_obs_2019b_v2_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][12];
  ODE1_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Template_obs_2019b_v2_T Template_obs_2019b_v2_P;

/* Block signals (default storage) */
extern B_Template_obs_2019b_v2_T Template_obs_2019b_v2_B;

/* Continuous states (default storage) */
extern X_Template_obs_2019b_v2_T Template_obs_2019b_v2_X;

/* Block states (default storage) */
extern DW_Template_obs_2019b_v2_T Template_obs_2019b_v2_DW;

/* Model entry point functions */
extern void Template_obs_2019b_v2_initialize(void);
extern void Template_obs_2019b_v2_step(void);
extern void Template_obs_2019b_v2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Template_obs_2019b_v_T *const Template_obs_2019b_v2_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Template_obs_2019b_v2'
 * '<S1>'   : 'Template_obs_2019b_v2/Band-Limited White Noise'
 * '<S2>'   : 'Template_obs_2019b_v2/Subsystem'
 * '<S3>'   : 'Template_obs_2019b_v2/Subsystem1'
 * '<S4>'   : 'Template_obs_2019b_v2/Subsystem2'
 * '<S5>'   : 'Template_obs_2019b_v2/Subsystem3'
 */
#endif                                 /* RTW_HEADER_Template_obs_2019b_v2_h_ */
