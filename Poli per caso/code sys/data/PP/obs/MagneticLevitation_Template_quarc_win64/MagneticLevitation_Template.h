/*
 * MagneticLevitation_Template.h
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

#ifndef RTW_HEADER_MagneticLevitation_Template_h_
#define RTW_HEADER_MagneticLevitation_Template_h_
#include <math.h>
#include <float.h>
#include <string.h>
#ifndef MagneticLevitation_Template_COMMON_INCLUDES_
# define MagneticLevitation_Template_COMMON_INCLUDES_
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
#endif                        /* MagneticLevitation_Template_COMMON_INCLUDES_ */

#include "MagneticLevitation_Template_types.h"

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
  real_T StateSpace[3];                /* '<S3>/State-Space' */
  real_T posizione;                    /* '<S2>/Gain1' */
  real_T corrente;                     /* '<S2>/Add' */
  real_T Saturation;                   /* '<Root>/Saturation' */
  real_T Output;                       /* '<S1>/Output' */
  real_T ManualSwitch2;                /* '<Root>/Manual Switch2' */
  real_T ManualSwitch4;                /* '<Root>/Manual Switch4' */
  real_T x1;                           /* '<Root>/Sum2' */
  real_T x2;                           /* '<Root>/Sum3' */
  real_T TransferFcn;                  /* '<Root>/Transfer Fcn' */
  real_T Add;                          /* '<Root>/Add' */
  real_T Gain;                         /* '<S2>/Gain' */
  real_T Sum;                          /* '<S3>/Sum' */
  real_T Sum1;                         /* '<S3>/Sum1' */
  real_T TmpSignalConversionAtStateSpace[3];
} B_MagneticLevitation_Template_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T HILInitialize_AOVoltages[2];  /* '<Root>/HIL Initialize' */
  real_T BallPositionandCurrent_Buffer[2];/* '<S2>/Ball Position and Current' */
  real_T NextOutput;                   /* '<S1>/White Noise' */
  t_uint64 ToHostFile_PointsWritten;   /* '<Root>/To Host File' */
  t_card HILInitialize_Card;           /* '<Root>/HIL Initialize' */
  void *BallPositionandCurrent_PWORK;  /* '<S2>/Ball Position and Current' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

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
  uint32_T RandSeed;                   /* '<S1>/White Noise' */
  uint32_T ToHostFile_SamplesCount;    /* '<Root>/To Host File' */
  uint32_T ToHostFile_ArrayNameLength; /* '<Root>/To Host File' */
} DW_MagneticLevitation_Templat_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
  real_T StateSpace_CSTATE[3];         /* '<S3>/State-Space' */
  real_T TransferFcn_CSTATE;           /* '<S4>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE;          /* '<S4>/Transfer Fcn1' */
  real_T TransferFcn_CSTATE_b;         /* '<Root>/Transfer Fcn' */
} X_MagneticLevitation_Template_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
  real_T StateSpace_CSTATE[3];         /* '<S3>/State-Space' */
  real_T TransferFcn_CSTATE;           /* '<S4>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE;          /* '<S4>/Transfer Fcn1' */
  real_T TransferFcn_CSTATE_b;         /* '<Root>/Transfer Fcn' */
} XDot_MagneticLevitation_Templ_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator2_CSTATE;        /* '<Root>/Integrator2' */
  boolean_T StateSpace_CSTATE[3];      /* '<S3>/State-Space' */
  boolean_T TransferFcn_CSTATE;        /* '<S4>/Transfer Fcn' */
  boolean_T TransferFcn1_CSTATE;       /* '<S4>/Transfer Fcn1' */
  boolean_T TransferFcn_CSTATE_b;      /* '<Root>/Transfer Fcn' */
} XDis_MagneticLevitation_Templ_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters (default storage) */
struct P_MagneticLevitation_Template_T_ {
  real_T A_ob[9];                      /* Variable: A_ob
                                        * Referenced by: '<S3>/State-Space'
                                        */
  real_T B_ob[9];                      /* Variable: B_ob
                                        * Referenced by: '<S3>/State-Space'
                                        */
  real_T C_ob[9];                      /* Variable: C_ob
                                        * Referenced by: '<S3>/State-Space'
                                        */
  real_T Kb;                           /* Variable: Kb
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T Ken_eta;                      /* Variable: Ken_eta
                                        * Referenced by: '<Root>/K_eta1'
                                        */
  real_T Ken_x[3];                     /* Variable: Ken_x
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Upper_bound_V;                /* Variable: Upper_bound_V
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T offset_corrente_volt;         /* Variable: offset_corrente_volt
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T offset_posizione_volt;        /* Variable: offset_posizione_volt
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T u;                            /* Variable: u
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T x1_eq0;                       /* Variable: x1_eq0
                                        * Referenced by:
                                        *   '<Root>/Constant2'
                                        *   '<S3>/Constant'
                                        *   '<S4>/Constant'
                                        */
  real_T x2_eq0;                       /* Variable: x2_eq0
                                        * Referenced by:
                                        *   '<Root>/Constant4'
                                        *   '<S3>/Constant1'
                                        *   '<S4>/Constant1'
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
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator2'
                                        */
  real_T StateSpace_InitialCondition[3];/* Expression: [-x1_eq0, -x2_eq0, 0]
                                         * Referenced by: '<S3>/State-Space'
                                         */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S4>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S4>/Transfer Fcn'
                                        */
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<S4>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<S4>/Transfer Fcn1'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T WhiteNoise_Mean;              /* Expression: 0
                                        * Referenced by: '<S1>/White Noise'
                                        */
  real_T WhiteNoise_StdDev;            /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S1>/White Noise'
                                        */
  real_T SineWave_Amp;                 /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T Constant_Value;               /* Expression: 4e-3
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Step_Time;                    /* Expression: 2
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 0.005
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T SineWave1_Amp;                /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Bias;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Freq;               /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Phase;              /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T TransferFcn_A_o;              /* Computed Parameter: TransferFcn_A_o
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T TransferFcn_C_i;              /* Computed Parameter: TransferFcn_C_i
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T TransferFcn_D;                /* Computed Parameter: TransferFcn_D
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/3
                                        * Referenced by: '<S2>/Gain'
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
  uint8_T ManualSwitch3_CurrentSetting;
                             /* Computed Parameter: ManualSwitch3_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch3'
                              */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<Root>/Manual Switch'
                               */
  uint8_T ManualSwitch1_CurrentSetting;
                             /* Computed Parameter: ManualSwitch1_CurrentSetting
                              * Referenced by: '<S4>/Manual Switch1'
                              */
  uint8_T ManualSwitch2_CurrentSetting;
                             /* Computed Parameter: ManualSwitch2_CurrentSetting
                              * Referenced by: '<S4>/Manual Switch2'
                              */
  uint8_T ManualSwitch_CurrentSetting_d;
                            /* Computed Parameter: ManualSwitch_CurrentSetting_d
                             * Referenced by: '<S4>/Manual Switch'
                             */
  uint8_T ManualSwitch2_CurrentSetting_f;
                           /* Computed Parameter: ManualSwitch2_CurrentSetting_f
                            * Referenced by: '<Root>/Manual Switch2'
                            */
  uint8_T ManualSwitch4_CurrentSetting;
                             /* Computed Parameter: ManualSwitch4_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch4'
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
};

/* Real-time Model Data Structure */
struct tag_RTM_MagneticLevitation_Te_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_MagneticLevitation_Template_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][7];
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
extern P_MagneticLevitation_Template_T MagneticLevitation_Template_P;

/* Block signals (default storage) */
extern B_MagneticLevitation_Template_T MagneticLevitation_Template_B;

/* Continuous states (default storage) */
extern X_MagneticLevitation_Template_T MagneticLevitation_Template_X;

/* Block states (default storage) */
extern DW_MagneticLevitation_Templat_T MagneticLevitation_Template_DW;

/* Model entry point functions */
extern void MagneticLevitation_Template_initialize(void);
extern void MagneticLevitation_Template_step(void);
extern void MagneticLevitation_Template_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MagneticLevitation_T_T *const MagneticLevitation_Template_M;

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
 * '<Root>' : 'MagneticLevitation_Template'
 * '<S1>'   : 'MagneticLevitation_Template/Band-Limited White Noise'
 * '<S2>'   : 'MagneticLevitation_Template/Subsystem'
 * '<S3>'   : 'MagneticLevitation_Template/Subsystem2'
 * '<S4>'   : 'MagneticLevitation_Template/Subsystem3'
 */
#endif                           /* RTW_HEADER_MagneticLevitation_Template_h_ */
