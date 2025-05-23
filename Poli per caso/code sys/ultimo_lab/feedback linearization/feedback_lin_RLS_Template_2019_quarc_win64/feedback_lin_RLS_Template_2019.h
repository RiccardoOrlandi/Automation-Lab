/*
 * feedback_lin_RLS_Template_2019.h
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

#ifndef RTW_HEADER_feedback_lin_RLS_Template_2019_h_
#define RTW_HEADER_feedback_lin_RLS_Template_2019_h_
#include <math.h>
#include <float.h>
#include <string.h>
#ifndef feedback_lin_RLS_Template_2019_COMMON_INCLUDES_
# define feedback_lin_RLS_Template_2019_COMMON_INCLUDES_
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
#endif                     /* feedback_lin_RLS_Template_2019_COMMON_INCLUDES_ */

#include "feedback_lin_RLS_Template_2019_types.h"

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

#define feedback_lin_RLS_Template_2019_M (feedback_lin_RLS_Template_20_M)

/* Block signals (default storage) */
typedef struct {
  real_T corrente;                     /* '<S2>/Add' */
  real_T Switch1;                      /* '<Root>/Switch1' */
  real_T posizione;                    /* '<S2>/Gain1' */
  real_T ManualSwitch1;                /* '<S1>/Manual Switch1' */
  real_T ManualSwitch2;                /* '<S1>/Manual Switch2' */
  real_T TransferFcn2;                 /* '<S1>/Transfer Fcn2' */
  real_T TransferFcn;                  /* '<S4>/Transfer Fcn' */
  real_T TransferFcn1;                 /* '<S4>/Transfer Fcn1' */
  real_T TransferFcn2_a;               /* '<S4>/Transfer Fcn2' */
  real_T Saturation;                   /* '<Root>/Saturation' */
  real_T TmpSignalConversionAtStateobser[3];
  real_T Gain;                         /* '<S2>/Gain' */
  real_T IntegralGain;                 /* '<S37>/Integral Gain' */
  real_T Constant;                     /* '<S5>/Constant' */
  real_T Constant1;                    /* '<S5>/Constant1' */
  real_T Constant2;                    /* '<S5>/Constant2' */
  real_T R;                            /* '<S56>/MATLAB Function2' */
  real_T Lc;                           /* '<S56>/MATLAB Function2' */
  real_T tho[2];                       /* '<S56>/MATLAB Function' */
  real_T Vo[4];                        /* '<S56>/MATLAB Function' */
  real_T k_mag;                        /* '<S55>/MATLAB Function1' */
  real_T tho_g;                        /* '<S55>/MATLAB Function' */
  real_T Vo_g;                         /* '<S55>/MATLAB Function' */
  real_T theta[6];                     /* '<S4>/MATLAB Function2' */
  real_T K[3];                         /* '<S4>/MATLAB Function1' */
  real_T beta;                         /* '<S4>/MATLAB Function' */
  real_T x3_hat;                       /* '<S1>/MATLAB Function' */
} B_feedback_lin_RLS_Template_2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<S55>/Delay' */
  real_T Delay1_DSTATE;                /* '<S55>/Delay1' */
  real_T Delay1_DSTATE_p;              /* '<S58>/Delay1' */
  real_T Delay2_DSTATE;                /* '<S58>/Delay2' */
  real_T Delay3_DSTATE[3];             /* '<S5>/Delay3' */
  real_T Delay_DSTATE_d[2];            /* '<S56>/Delay' */
  real_T Delay1_DSTATE_f[4];           /* '<S56>/Delay1' */
  real_T Delay3_DSTATE_b;              /* '<S58>/Delay3' */
  real_T Delay1_DSTATE_a[3];           /* '<S5>/Delay1' */
  real_T Delay2_DSTATE_h;              /* '<S5>/Delay2' */
  real_T HILInitialize_AOVoltages[2];  /* '<Root>/HIL Initialize' */
  real_T BallPositionandCurrent_Buffer[2];/* '<S2>/Ball Position and Current' */
  t_uint64 ToHostFile_PointsWritten;   /* '<Root>/To Host File' */
  t_card HILInitialize_Card;           /* '<Root>/HIL Initialize' */
  void *BallPositionandCurrent_PWORK;  /* '<S2>/Ball Position and Current' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  void *ToHostFile_PWORK[2];           /* '<Root>/To Host File' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK_e;                     /* '<S1>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK_a;                    /* '<S1>/Scope1' */

  void *Voltage_PWORK;                 /* '<S2>/Voltage' */
  struct {
    void *LoggedData;
  } Scope_PWORK_m;                     /* '<S4>/Scope' */

  struct {
    void *LoggedData[4];
  } Scope1_PWORK_b;                    /* '<S4>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_mr;                    /* '<S5>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK_b2;                   /* '<S5>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope2_PWORK_d;                    /* '<S5>/Scope2' */

  uint32_T ToHostFile_SamplesCount;    /* '<Root>/To Host File' */
  uint32_T ToHostFile_ArrayNameLength; /* '<Root>/To Host File' */
} DW_feedback_lin_RLS_Template__T;

/* Continuous states (default storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<S1>/Transfer Fcn' */
  real_T Integrator_CSTATE;            /* '<S40>/Integrator' */
  real_T TransferFcn1_CSTATE;          /* '<S1>/Transfer Fcn1' */
  real_T TransferFcn2_CSTATE;          /* '<S1>/Transfer Fcn2' */
  real_T TransferFcn_CSTATE_o;         /* '<S4>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE_e;        /* '<S4>/Transfer Fcn1' */
  real_T TransferFcn2_CSTATE_j;        /* '<S4>/Transfer Fcn2' */
  real_T Stateobserver_CSTATE[3];      /* '<S1>/State observer' */
} X_feedback_lin_RLS_Template_2_T;

/* State derivatives (default storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<S1>/Transfer Fcn' */
  real_T Integrator_CSTATE;            /* '<S40>/Integrator' */
  real_T TransferFcn1_CSTATE;          /* '<S1>/Transfer Fcn1' */
  real_T TransferFcn2_CSTATE;          /* '<S1>/Transfer Fcn2' */
  real_T TransferFcn_CSTATE_o;         /* '<S4>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE_e;        /* '<S4>/Transfer Fcn1' */
  real_T TransferFcn2_CSTATE_j;        /* '<S4>/Transfer Fcn2' */
  real_T Stateobserver_CSTATE[3];      /* '<S1>/State observer' */
} XDot_feedback_lin_RLS_Templat_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn_CSTATE;        /* '<S1>/Transfer Fcn' */
  boolean_T Integrator_CSTATE;         /* '<S40>/Integrator' */
  boolean_T TransferFcn1_CSTATE;       /* '<S1>/Transfer Fcn1' */
  boolean_T TransferFcn2_CSTATE;       /* '<S1>/Transfer Fcn2' */
  boolean_T TransferFcn_CSTATE_o;      /* '<S4>/Transfer Fcn' */
  boolean_T TransferFcn1_CSTATE_e;     /* '<S4>/Transfer Fcn1' */
  boolean_T TransferFcn2_CSTATE_j;     /* '<S4>/Transfer Fcn2' */
  boolean_T Stateobserver_CSTATE[3];   /* '<S1>/State observer' */
} XDis_feedback_lin_RLS_Templat_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters (default storage) */
struct P_feedback_lin_RLS_Template_2_T_ {
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
  real_T Lc_mod;                       /* Variable: Lc_mod
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T Rtot_mod;                     /* Variable: Rtot_mod
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T k_mag;                        /* Variable: k_mag
                                        * Referenced by: '<S55>/Delay'
                                        */
  real_T k_mag_mod;                    /* Variable: k_mag_mod
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T m;                            /* Variable: m
                                        * Referenced by:
                                        *   '<S55>/Constant2'
                                        *   '<S55>/Delay'
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
  real_T y0;                           /* Variable: y0
                                        * Referenced by: '<S55>/Constant1'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S37>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S40>/Integrator'
                               */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S45>/Proportional Gain'
                                        */
  real_T Subsystem_mu;                 /* Mask Parameter: Subsystem_mu
                                        * Referenced by: '<S55>/Constant'
                                        */
  real_T Subsystem1_mu;                /* Mask Parameter: Subsystem1_mu
                                        * Referenced by: '<S56>/Constant'
                                        */
  real_T Subsystem2_p1;                /* Mask Parameter: Subsystem2_p1
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Subsystem2_p2;                /* Mask Parameter: Subsystem2_p2
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real_T Subsystem2_p3;                /* Mask Parameter: Subsystem2_p3
                                        * Referenced by: '<S4>/Constant3'
                                        */
  uint32_T BallPositionandCurrent_channels[2];
                              /* Mask Parameter: BallPositionandCurrent_channels
                               * Referenced by: '<S2>/Ball Position and Current'
                               */
  uint32_T Voltage_channels;           /* Mask Parameter: Voltage_channels
                                        * Referenced by: '<S2>/Voltage'
                                        */
  real_T Switch_Threshold;             /* Expression: 3
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Switch2_Threshold;            /* Expression: 15
                                        * Referenced by: '<Root>/Switch2'
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
  real_T SineWave1_Amp;                /* Expression: 0.0005
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Bias;               /* Expression: 0.004
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Freq;               /* Expression: 10
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Phase;              /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T Step1_Time;                   /* Expression: 2
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step1_Y0;                     /* Expression: 0
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step1_YFinal;                 /* Expression: 0.003
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T SineWave_Amp;                 /* Expression: 0.0008
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0.004
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 10
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
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
  real_T Switch1_Threshold;            /* Expression: 10
                                        * Referenced by: '<Root>/Switch1'
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
  real_T TransferFcn2_A;               /* Computed Parameter: TransferFcn2_A
                                        * Referenced by: '<S1>/Transfer Fcn2'
                                        */
  real_T TransferFcn2_C;               /* Computed Parameter: TransferFcn2_C
                                        * Referenced by: '<S1>/Transfer Fcn2'
                                        */
  real_T TransferFcn2_D;               /* Computed Parameter: TransferFcn2_D
                                        * Referenced by: '<S1>/Transfer Fcn2'
                                        */
  real_T TransferFcn_A_g;              /* Computed Parameter: TransferFcn_A_g
                                        * Referenced by: '<S4>/Transfer Fcn'
                                        */
  real_T TransferFcn_C_b;              /* Computed Parameter: TransferFcn_C_b
                                        * Referenced by: '<S4>/Transfer Fcn'
                                        */
  real_T TransferFcn_D;                /* Computed Parameter: TransferFcn_D
                                        * Referenced by: '<S4>/Transfer Fcn'
                                        */
  real_T TransferFcn1_A_p;             /* Computed Parameter: TransferFcn1_A_p
                                        * Referenced by: '<S4>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C_b;             /* Computed Parameter: TransferFcn1_C_b
                                        * Referenced by: '<S4>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_D;               /* Computed Parameter: TransferFcn1_D
                                        * Referenced by: '<S4>/Transfer Fcn1'
                                        */
  real_T TransferFcn2_A_k;             /* Computed Parameter: TransferFcn2_A_k
                                        * Referenced by: '<S4>/Transfer Fcn2'
                                        */
  real_T TransferFcn2_C_j;             /* Computed Parameter: TransferFcn2_C_j
                                        * Referenced by: '<S4>/Transfer Fcn2'
                                        */
  real_T TransferFcn2_D_g;             /* Computed Parameter: TransferFcn2_D_g
                                        * Referenced by: '<S4>/Transfer Fcn2'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: inv(S0)
                                        * Referenced by: '<S55>/Delay1'
                                        */
  real_T Delay1_InitialCondition_o;    /* Expression: 0.0
                                        * Referenced by: '<S58>/Delay1'
                                        */
  real_T Gain_Gain;                    /* Expression: 2
                                        * Referenced by: '<S58>/Gain'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S58>/Delay2'
                                        */
  real_T Constant_Value;               /* Expression: 0.002^2*9.81
                                        * Referenced by: '<S58>/Constant'
                                        */
  real_T Delay3_InitialCondition[3];   /* Expression: [0, 0, 0]'
                                        * Referenced by: '<S5>/Delay3'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1e-4
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 1e-6
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T Delay_InitialCondition[2];
                              /* Expression: [th0(1)*0.002/th0(2); 0.002/th0(2)]
                               * Referenced by: '<S56>/Delay'
                               */
  real_T Delay1_InitialCondition_f[4]; /* Expression: inv(S0)
                                        * Referenced by: '<S56>/Delay1'
                                        */
  real_T Delay3_InitialCondition_a;    /* Expression: 0.0
                                        * Referenced by: '<S58>/Delay3'
                                        */
  real_T Delay1_InitialCondition_i;    /* Expression: 0
                                        * Referenced by: '<S5>/Delay1'
                                        */
  real_T Delay2_InitialCondition_j;    /* Expression: 0
                                        * Referenced by: '<S5>/Delay2'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 13
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 2
                                        * Referenced by: '<S5>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S5>/Saturation2'
                                        */
  real_T Constant_Value_d[5];         /* Expression: [k_aero, y0, m, k_mag, Lc]'
                                       * Referenced by: '<S4>/Constant'
                                       */
  real_T Saturation_UpperSat_h;        /* Expression: 23
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat_p;        /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Stateobserver_InitialCondition[3];/* Expression: [0;0;0]
                                            * Referenced by: '<S1>/State observer'
                                            */
  real_T Gain_Gain_h;                  /* Expression: 1/3
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
struct tag_RTM_feedback_lin_RLS_Temp_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_feedback_lin_RLS_Template_2_T *contStates;
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
extern P_feedback_lin_RLS_Template_2_T feedback_lin_RLS_Template_201_P;

/* Block signals (default storage) */
extern B_feedback_lin_RLS_Template_2_T feedback_lin_RLS_Template_201_B;

/* Continuous states (default storage) */
extern X_feedback_lin_RLS_Template_2_T feedback_lin_RLS_Template_201_X;

/* Block states (default storage) */
extern DW_feedback_lin_RLS_Template__T feedback_lin_RLS_Template_20_DW;

/* Model entry point functions */
extern void feedback_lin_RLS_Template_2019_initialize(void);
extern void feedback_lin_RLS_Template_2019_step(void);
extern void feedback_lin_RLS_Template_2019_terminate(void);

/* Real-time Model object */
extern RT_MODEL_feedback_lin_RLS_Tem_T *const feedback_lin_RLS_Template_20_M;

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
 * '<Root>' : 'feedback_lin_RLS_Template_2019'
 * '<S1>'   : 'feedback_lin_RLS_Template_2019/Reduced OBSERVER'
 * '<S2>'   : 'feedback_lin_RLS_Template_2019/Subsystem'
 * '<S3>'   : 'feedback_lin_RLS_Template_2019/Subsystem1'
 * '<S4>'   : 'feedback_lin_RLS_Template_2019/Subsystem2'
 * '<S5>'   : 'feedback_lin_RLS_Template_2019/Subsystem3'
 * '<S6>'   : 'feedback_lin_RLS_Template_2019/Reduced OBSERVER/MATLAB Function'
 * '<S7>'   : 'feedback_lin_RLS_Template_2019/Subsystem2/MATLAB Function'
 * '<S8>'   : 'feedback_lin_RLS_Template_2019/Subsystem2/MATLAB Function1'
 * '<S9>'   : 'feedback_lin_RLS_Template_2019/Subsystem2/MATLAB Function2'
 * '<S10>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller'
 * '<S11>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Anti-windup'
 * '<S12>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/D Gain'
 * '<S13>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Filter'
 * '<S14>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Filter ICs'
 * '<S15>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/I Gain'
 * '<S16>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Ideal P Gain'
 * '<S17>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Ideal P Gain Fdbk'
 * '<S18>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Integrator'
 * '<S19>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Integrator ICs'
 * '<S20>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/N Copy'
 * '<S21>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/N Gain'
 * '<S22>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/P Copy'
 * '<S23>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Parallel P Gain'
 * '<S24>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Reset Signal'
 * '<S25>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Saturation'
 * '<S26>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Saturation Fdbk'
 * '<S27>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Sum'
 * '<S28>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Sum Fdbk'
 * '<S29>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Tracking Mode'
 * '<S30>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Tracking Mode Sum'
 * '<S31>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/postSat Signal'
 * '<S32>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/preSat Signal'
 * '<S33>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Anti-windup/Passthrough'
 * '<S34>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/D Gain/Disabled'
 * '<S35>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Filter/Disabled'
 * '<S36>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Filter ICs/Disabled'
 * '<S37>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/I Gain/Internal Parameters'
 * '<S38>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Ideal P Gain/Passthrough'
 * '<S39>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S40>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Integrator/Continuous'
 * '<S41>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Integrator ICs/Internal IC'
 * '<S42>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S43>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/N Gain/Disabled'
 * '<S44>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/P Copy/Disabled'
 * '<S45>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S46>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Reset Signal/Disabled'
 * '<S47>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Saturation/Passthrough'
 * '<S48>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Saturation Fdbk/Disabled'
 * '<S49>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Sum/Sum_PI'
 * '<S50>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Sum Fdbk/Disabled'
 * '<S51>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Tracking Mode/Disabled'
 * '<S52>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S53>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/postSat Signal/Forward_Path'
 * '<S54>'  : 'feedback_lin_RLS_Template_2019/Subsystem2/PID Controller/preSat Signal/Forward_Path'
 * '<S55>'  : 'feedback_lin_RLS_Template_2019/Subsystem3/Subsystem'
 * '<S56>'  : 'feedback_lin_RLS_Template_2019/Subsystem3/Subsystem1'
 * '<S57>'  : 'feedback_lin_RLS_Template_2019/Subsystem3/Subsystem2'
 * '<S58>'  : 'feedback_lin_RLS_Template_2019/Subsystem3/compute output estimation'
 * '<S59>'  : 'feedback_lin_RLS_Template_2019/Subsystem3/Subsystem/MATLAB Function'
 * '<S60>'  : 'feedback_lin_RLS_Template_2019/Subsystem3/Subsystem/MATLAB Function1'
 * '<S61>'  : 'feedback_lin_RLS_Template_2019/Subsystem3/Subsystem/Regressor'
 * '<S62>'  : 'feedback_lin_RLS_Template_2019/Subsystem3/Subsystem1/MATLAB Function'
 * '<S63>'  : 'feedback_lin_RLS_Template_2019/Subsystem3/Subsystem1/MATLAB Function2'
 * '<S64>'  : 'feedback_lin_RLS_Template_2019/Subsystem3/Subsystem1/regressor'
 */
#endif                        /* RTW_HEADER_feedback_lin_RLS_Template_2019_h_ */
