/*
 * feedback_2019.h
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

#ifndef RTW_HEADER_feedback_2019_h_
#define RTW_HEADER_feedback_2019_h_
#include <math.h>
#include <float.h>
#include <string.h>
#ifndef feedback_2019_COMMON_INCLUDES_
# define feedback_2019_COMMON_INCLUDES_
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
#endif                                 /* feedback_2019_COMMON_INCLUDES_ */

#include "feedback_2019_types.h"

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
  real_T Step;                         /* '<Root>/Step' */
  real_T posizione;                    /* '<S2>/Gain1' */
  real_T corrente;                     /* '<S2>/Add' */
  real_T FilterCoefficient;            /* '<S40>/Filter Coefficient' */
  real_T TransferFcn;                  /* '<S3>/Transfer Fcn' */
  real_T TransferFcn1;                 /* '<S3>/Transfer Fcn1' */
  real_T TransferFcn2;                 /* '<S3>/Transfer Fcn2' */
  real_T Saturation;                   /* '<Root>/Saturation' */
  real_T TmpSignalConversionAtStateobser[3];
  real_T Gain;                         /* '<S2>/Gain' */
  real_T IntegralGain;                 /* '<S34>/Integral Gain' */
  real_T K[3];                         /* '<S3>/MATLAB Function1' */
  real_T beta;                         /* '<S3>/MATLAB Function' */
} B_feedback_2019_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T HILInitialize_AOVoltages[2];  /* '<Root>/HIL Initialize' */
  real_T BallPositionandCurrent_Buffer[2];/* '<S2>/Ball Position and Current' */
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
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  void *ToHostFile_PWORK[2];           /* '<Root>/To Host File' */
  void *Voltage_PWORK;                 /* '<S2>/Voltage' */
  struct {
    void *LoggedData;
  } Scope_PWORK_d;                     /* '<S3>/Scope' */

  struct {
    void *LoggedData[4];
  } Scope1_PWORK_n;                    /* '<S3>/Scope1' */

  uint32_T ToHostFile_SamplesCount;    /* '<Root>/To Host File' */
  uint32_T ToHostFile_ArrayNameLength; /* '<Root>/To Host File' */
} DW_feedback_2019_T;

/* Continuous states (default storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<S1>/Transfer Fcn' */
  real_T Integrator_CSTATE;            /* '<S37>/Integrator' */
  real_T Filter_CSTATE;                /* '<S32>/Filter' */
  real_T TransferFcn1_CSTATE;          /* '<S1>/Transfer Fcn1' */
  real_T Stateobserver_CSTATE[3];      /* '<S1>/State observer' */
  real_T TransferFcn_CSTATE_g;         /* '<S3>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE_e;        /* '<S3>/Transfer Fcn1' */
  real_T TransferFcn2_CSTATE;          /* '<S3>/Transfer Fcn2' */
} X_feedback_2019_T;

/* State derivatives (default storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<S1>/Transfer Fcn' */
  real_T Integrator_CSTATE;            /* '<S37>/Integrator' */
  real_T Filter_CSTATE;                /* '<S32>/Filter' */
  real_T TransferFcn1_CSTATE;          /* '<S1>/Transfer Fcn1' */
  real_T Stateobserver_CSTATE[3];      /* '<S1>/State observer' */
  real_T TransferFcn_CSTATE_g;         /* '<S3>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE_e;        /* '<S3>/Transfer Fcn1' */
  real_T TransferFcn2_CSTATE;          /* '<S3>/Transfer Fcn2' */
} XDot_feedback_2019_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn_CSTATE;        /* '<S1>/Transfer Fcn' */
  boolean_T Integrator_CSTATE;         /* '<S37>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S32>/Filter' */
  boolean_T TransferFcn1_CSTATE;       /* '<S1>/Transfer Fcn1' */
  boolean_T Stateobserver_CSTATE[3];   /* '<S1>/State observer' */
  boolean_T TransferFcn_CSTATE_g;      /* '<S3>/Transfer Fcn' */
  boolean_T TransferFcn1_CSTATE_e;     /* '<S3>/Transfer Fcn1' */
  boolean_T TransferFcn2_CSTATE;       /* '<S3>/Transfer Fcn2' */
} XDis_feedback_2019_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters (default storage) */
struct P_feedback_2019_T_ {
  real_T A_ob[9];                      /* Variable: A_ob
                                        * Referenced by: '<S1>/State observer'
                                        */
  real_T B_ob[9];                      /* Variable: B_ob
                                        * Referenced by: '<S1>/State observer'
                                        */
  real_T C_ob[9];                      /* Variable: C_ob
                                        * Referenced by: '<S1>/State observer'
                                        */
  real_T Kb;                           /* Variable: Kb
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T offset_corrente_volt;         /* Variable: offset_corrente_volt
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T offset_posizione_volt;        /* Variable: offset_posizione_volt
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T u;                            /* Variable: u
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T x1_eq0;                       /* Variable: x1_eq0
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T x2_eq0;                       /* Variable: x2_eq0
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S31>/Derivative Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S34>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S32>/Filter'
                               */
  real_T PIDController_InitialConditio_i;
                              /* Mask Parameter: PIDController_InitialConditio_i
                               * Referenced by: '<S37>/Integrator'
                               */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S40>/Filter Coefficient'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S42>/Proportional Gain'
                                        */
  real_T Subsystem1_p1;                /* Mask Parameter: Subsystem1_p1
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Subsystem1_p2;                /* Mask Parameter: Subsystem1_p2
                                        * Referenced by: '<S3>/Constant2'
                                        */
  real_T Subsystem1_p3;                /* Mask Parameter: Subsystem1_p3
                                        * Referenced by: '<S3>/Constant3'
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
  real_T Step_Time;                    /* Expression: 2
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 0.004
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S1>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S1>/Transfer Fcn'
                                        */
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<S1>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<S1>/Transfer Fcn1'
                                        */
  real_T Stateobserver_InitialCondition[3];/* Expression: [0;0;0]
                                            * Referenced by: '<S1>/State observer'
                                            */
  real_T TransferFcn_A_f;              /* Computed Parameter: TransferFcn_A_f
                                        * Referenced by: '<S3>/Transfer Fcn'
                                        */
  real_T TransferFcn_C_j;              /* Computed Parameter: TransferFcn_C_j
                                        * Referenced by: '<S3>/Transfer Fcn'
                                        */
  real_T TransferFcn_D;                /* Computed Parameter: TransferFcn_D
                                        * Referenced by: '<S3>/Transfer Fcn'
                                        */
  real_T TransferFcn1_A_c;             /* Computed Parameter: TransferFcn1_A_c
                                        * Referenced by: '<S3>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C_a;             /* Computed Parameter: TransferFcn1_C_a
                                        * Referenced by: '<S3>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_D;               /* Computed Parameter: TransferFcn1_D
                                        * Referenced by: '<S3>/Transfer Fcn1'
                                        */
  real_T TransferFcn2_A;               /* Computed Parameter: TransferFcn2_A
                                        * Referenced by: '<S3>/Transfer Fcn2'
                                        */
  real_T TransferFcn2_C;               /* Computed Parameter: TransferFcn2_C
                                        * Referenced by: '<S3>/Transfer Fcn2'
                                        */
  real_T TransferFcn2_D;               /* Computed Parameter: TransferFcn2_D
                                        * Referenced by: '<S3>/Transfer Fcn2'
                                        */
  real_T Constant_Value[6];
                 /* Expression: [0, 2.4405e-05, 0.0657, 0.0120, 9.7585, 0.3708]'
                  * Referenced by: '<S3>/Constant'
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
  uint8_T ManualSwitch1_CurrentSetting;
                             /* Computed Parameter: ManualSwitch1_CurrentSetting
                              * Referenced by: '<S1>/Manual Switch1'
                              */
  uint8_T ManualSwitch2_CurrentSetting;
                             /* Computed Parameter: ManualSwitch2_CurrentSetting
                              * Referenced by: '<S1>/Manual Switch2'
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
struct tag_RTM_feedback_2019_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_feedback_2019_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][10];
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
extern P_feedback_2019_T feedback_2019_P;

/* Block signals (default storage) */
extern B_feedback_2019_T feedback_2019_B;

/* Continuous states (default storage) */
extern X_feedback_2019_T feedback_2019_X;

/* Block states (default storage) */
extern DW_feedback_2019_T feedback_2019_DW;

/* Model entry point functions */
extern void feedback_2019_initialize(void);
extern void feedback_2019_step(void);
extern void feedback_2019_terminate(void);

/* Real-time Model object */
extern RT_MODEL_feedback_2019_T *const feedback_2019_M;

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
 * '<Root>' : 'feedback_2019'
 * '<S1>'   : 'feedback_2019/Reduced OBSERVER'
 * '<S2>'   : 'feedback_2019/Subsystem'
 * '<S3>'   : 'feedback_2019/Subsystem1'
 * '<S4>'   : 'feedback_2019/Reduced OBSERVER/MATLAB Function'
 * '<S5>'   : 'feedback_2019/Subsystem1/MATLAB Function'
 * '<S6>'   : 'feedback_2019/Subsystem1/MATLAB Function1'
 * '<S7>'   : 'feedback_2019/Subsystem1/PID Controller'
 * '<S8>'   : 'feedback_2019/Subsystem1/PID Controller/Anti-windup'
 * '<S9>'   : 'feedback_2019/Subsystem1/PID Controller/D Gain'
 * '<S10>'  : 'feedback_2019/Subsystem1/PID Controller/Filter'
 * '<S11>'  : 'feedback_2019/Subsystem1/PID Controller/Filter ICs'
 * '<S12>'  : 'feedback_2019/Subsystem1/PID Controller/I Gain'
 * '<S13>'  : 'feedback_2019/Subsystem1/PID Controller/Ideal P Gain'
 * '<S14>'  : 'feedback_2019/Subsystem1/PID Controller/Ideal P Gain Fdbk'
 * '<S15>'  : 'feedback_2019/Subsystem1/PID Controller/Integrator'
 * '<S16>'  : 'feedback_2019/Subsystem1/PID Controller/Integrator ICs'
 * '<S17>'  : 'feedback_2019/Subsystem1/PID Controller/N Copy'
 * '<S18>'  : 'feedback_2019/Subsystem1/PID Controller/N Gain'
 * '<S19>'  : 'feedback_2019/Subsystem1/PID Controller/P Copy'
 * '<S20>'  : 'feedback_2019/Subsystem1/PID Controller/Parallel P Gain'
 * '<S21>'  : 'feedback_2019/Subsystem1/PID Controller/Reset Signal'
 * '<S22>'  : 'feedback_2019/Subsystem1/PID Controller/Saturation'
 * '<S23>'  : 'feedback_2019/Subsystem1/PID Controller/Saturation Fdbk'
 * '<S24>'  : 'feedback_2019/Subsystem1/PID Controller/Sum'
 * '<S25>'  : 'feedback_2019/Subsystem1/PID Controller/Sum Fdbk'
 * '<S26>'  : 'feedback_2019/Subsystem1/PID Controller/Tracking Mode'
 * '<S27>'  : 'feedback_2019/Subsystem1/PID Controller/Tracking Mode Sum'
 * '<S28>'  : 'feedback_2019/Subsystem1/PID Controller/postSat Signal'
 * '<S29>'  : 'feedback_2019/Subsystem1/PID Controller/preSat Signal'
 * '<S30>'  : 'feedback_2019/Subsystem1/PID Controller/Anti-windup/Passthrough'
 * '<S31>'  : 'feedback_2019/Subsystem1/PID Controller/D Gain/Internal Parameters'
 * '<S32>'  : 'feedback_2019/Subsystem1/PID Controller/Filter/Cont. Filter'
 * '<S33>'  : 'feedback_2019/Subsystem1/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S34>'  : 'feedback_2019/Subsystem1/PID Controller/I Gain/Internal Parameters'
 * '<S35>'  : 'feedback_2019/Subsystem1/PID Controller/Ideal P Gain/Passthrough'
 * '<S36>'  : 'feedback_2019/Subsystem1/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S37>'  : 'feedback_2019/Subsystem1/PID Controller/Integrator/Continuous'
 * '<S38>'  : 'feedback_2019/Subsystem1/PID Controller/Integrator ICs/Internal IC'
 * '<S39>'  : 'feedback_2019/Subsystem1/PID Controller/N Copy/Disabled'
 * '<S40>'  : 'feedback_2019/Subsystem1/PID Controller/N Gain/Internal Parameters'
 * '<S41>'  : 'feedback_2019/Subsystem1/PID Controller/P Copy/Disabled'
 * '<S42>'  : 'feedback_2019/Subsystem1/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S43>'  : 'feedback_2019/Subsystem1/PID Controller/Reset Signal/Disabled'
 * '<S44>'  : 'feedback_2019/Subsystem1/PID Controller/Saturation/Passthrough'
 * '<S45>'  : 'feedback_2019/Subsystem1/PID Controller/Saturation Fdbk/Disabled'
 * '<S46>'  : 'feedback_2019/Subsystem1/PID Controller/Sum/Sum_PID'
 * '<S47>'  : 'feedback_2019/Subsystem1/PID Controller/Sum Fdbk/Disabled'
 * '<S48>'  : 'feedback_2019/Subsystem1/PID Controller/Tracking Mode/Disabled'
 * '<S49>'  : 'feedback_2019/Subsystem1/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S50>'  : 'feedback_2019/Subsystem1/PID Controller/postSat Signal/Forward_Path'
 * '<S51>'  : 'feedback_2019/Subsystem1/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_feedback_2019_h_ */
