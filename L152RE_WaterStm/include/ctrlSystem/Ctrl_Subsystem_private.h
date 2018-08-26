  #ifndef RTW_HEADER_Ctrl_Subsystem_private_h_
  #define RTW_HEADER_Ctrl_Subsystem_private_h_
  #include "rtwtypes.h"

#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error "Code was generated for compiler with different sized uchar/char. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compiler's limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, which will disable the preprocessor word size checks."
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error "Code was generated for compiler with different sized ushort/short. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
//#error "Code was generated for compiler with different sized uint/int. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error "Code was generated for compiler with different sized ulong/long. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif


#ifndef __RTWTYPES_H__
  #error This file requires rtwtypes.h to be included
  #endif /* __RTWTYPES_H__ */


/* Computed Parameter: Constant_Value
 * Referenced by: '<S23>/Constant'
 */
#define rtcP_Constant_Value            (0)

/* Computed Parameter: Integrator_gainval
 * Referenced by: '<S20>/Integrator'
 */
#define rtcP_Integrator_gainval        (1)

/* Computed Parameter: Integrator_gainval_hkb1
 * Referenced by: '<S12>/Integrator'
 */
#define rtcP_Integrator_gainval_hkb1   (1)

/* Computed Parameter: FilterCoefficient_Gain
 * Referenced by: '<S20>/Filter Coefficient'
 */
#define rtcP_FilterCoefficient_Gain    (0)

/* Computed Parameter: FilterCoefficient_Gain_l2dy
 * Referenced by: '<S12>/Filter Coefficient'
 */
#define rtcP_FilterCoefficient_Gain_l2dy (0)

/* Computed Parameter: ProportionalGain_Gain
 * Referenced by: '<S20>/Proportional Gain'
 */
#define rtcP_ProportionalGain_Gain     (20480)

/* Computed Parameter: ProportionalGain_Gain_bbwv
 * Referenced by: '<S12>/Proportional Gain'
 */
#define rtcP_ProportionalGain_Gain_bbwv (20480)

/* Computed Parameter: reference_Value
 * Referenced by: '<S22>/reference'
 */
#define rtcP_reference_Value           (0)

/* Computed Parameter: reference1_Value
 * Referenced by: '<S22>/reference1'
 */
#define rtcP_reference1_Value          (-25)

/* Computed Parameter: reference2_Value
 * Referenced by: '<S22>/reference2'
 */
#define rtcP_reference2_Value          (0)

/* Computed Parameter: reference3_Value
 * Referenced by: '<S22>/reference3'
 */
#define rtcP_reference3_Value          (-25)

/* Computed Parameter: Constant_Value_km13
 * Referenced by: '<S16>/Constant'
 */
#define rtcP_Constant_Value_km13       (0)

/* Computed Parameter: Saturation_UpperSat
 * Referenced by: '<S7>/Saturation'
 */
#define rtcP_Saturation_UpperSat       (30)

/* Computed Parameter: Saturation_LowerSat
 * Referenced by: '<S7>/Saturation'
 */
#define rtcP_Saturation_LowerSat       (15)

/* Computed Parameter: Constant_Value_dj10
 * Referenced by: '<S8>/Constant'
 */
#define rtcP_Constant_Value_dj10       (0)

/* Computed Parameter: Gain_Gain
 * Referenced by: '<S6>/Gain'
 */
#define rtcP_Gain_Gain                 (-1)

/* Computed Parameter: Saturation_UpperSat_gwlq
 * Referenced by: '<S6>/Saturation'
 */
#define rtcP_Saturation_UpperSat_gwlq  (30)

/* Computed Parameter: Saturation_LowerSat_hjhp
 * Referenced by: '<S6>/Saturation'
 */
#define rtcP_Saturation_LowerSat_hjhp  (15)

/* Computed Parameter: Constant_Value_psko
 * Referenced by: '<S5>/Constant'
 */
#define rtcP_Constant_Value_psko       (0)

/* Computed Parameter: Constant_Value_ldvs
 * Referenced by: '<S21>/Constant'
 */
#define rtcP_Constant_Value_ldvs       (false)

/* Computed Parameter: DerivativeGain_Gain
 * Referenced by: '<S20>/Derivative Gain'
 */
#define rtcP_DerivativeGain_Gain       (75)

/* Computed Parameter: DerivativeGain_Gain_kbvg
 * Referenced by: '<S12>/Derivative Gain'
 */
#define rtcP_DerivativeGain_Gain_kbvg  (75)

/* Computed Parameter: IntegralGain_Gain
 * Referenced by: '<S20>/Integral Gain'
 */
#define rtcP_IntegralGain_Gain         (66)

/* Computed Parameter: IntegralGain_Gain_no5q
 * Referenced by: '<S12>/Integral Gain'
 */
#define rtcP_IntegralGain_Gain_no5q    (66)

/* Imported (extern) block signals */
extern uint8_T Temperature;            /* '<Root>/In1' */
extern int8_T SOLLtemperature;         /* '<Root>/In2' */
extern boolean_T doubleClicked;        /* '<Root>/In3' */
extern boolean_T clicked;              /* '<Root>/In4' */
extern boolean_T autoProgramTimeEnabled;/* '<Root>/In5' */
extern void Ctrl_Subsystem_HeatingPID2levels(int16_t rtu_In1, boolean_T
  *rty_Out1, boolean_T *rty_Out2);
extern void Ctrl_Subsystem_HeatingPID1level(int16_t rtu_In1, boolean_T *rty_Out1,
  boolean_T *rty_Out2);

#endif                                 /* RTW_HEADER_Ctrl_Subsystem_private_h_ */
