#ifndef RTW_HEADER_Ctrl_Subsystem_h_
#define RTW_HEADER_Ctrl_Subsystem_h_
#include <stddef.h>
#ifndef Ctrl_Subsystem_COMMON_INCLUDES_
# define Ctrl_Subsystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Ctrl_Subsystem_COMMON_INCLUDES_ */

#include "pid.h"
#include <eeprom_calib.h>
#include "Ctrl_Subsystem_private.h"
#include "hardware_init.h"
/* Macros for accessing real-time model data structure */
#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  boolean_T UnitDelay1_DSTATE;         /* '<S2>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_fbw3;    /* '<S4>/Unit Delay1' */
} DW_Ctrl_Subsystem;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  boolean_T Out1;                      /* '<Root>/Out1' */
  boolean_T Out2;                      /* '<Root>/Out2' */
  boolean_T Out3;                      /* '<Root>/Out3' */
  boolean_T Out4;                      /* '<Root>/Out4' */
} ExtY_Ctrl_Subsystem;

/* Block states (auto storage) */
extern DW_Ctrl_Subsystem Ctrl_Subsystem_DW;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_Ctrl_Subsystem Ctrl_Subsystem_Y;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern boolean_T isCoolingOn;          /* '<S5>/Compare' */
extern boolean_T selectProgram;        /* '<S2>/XOR1' */
extern boolean_T stateOfProgram;       /* '<S4>/XOR1' */
extern boolean_T isHeatingOn;          /* '<S3>/NOT' */
/* Model entry point functions */
extern void Ctrl_Subsystem_initialize(void);
extern void Ctrl_Subsystem_step(void);

/* Exported data declaration */

/* Const memory section */
/* Declaration for custom storage class: Const */
extern const boolean_T setOffSecondLvlinManual;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S11>/Scope' : Unused code path elimination
 * Block '<S11>/Scope1' : Unused code path elimination
 * Block '<S19>/Scope' : Unused code path elimination
 * Block '<S19>/Scope1' : Unused code path elimination
 * Block '<S4>/Scope' : Unused code path elimination
 */

 /* Here is the system hierarchy for this model
 *
 * '<Root>' : 'training2'
 * '<S1>'   : 'training2/Ctrl_Subsystem'
 * '<S2>'   : 'training2/Ctrl_Subsystem/Auto//Man selection '
 * '<S3>'   : 'training2/Ctrl_Subsystem/Core'
 * '<S4>'   : 'training2/Ctrl_Subsystem/On//Off'
 * '<S5>'   : 'training2/Ctrl_Subsystem/Core/Compare To Zero'
 * '<S6>'   : 'training2/Ctrl_Subsystem/Core/Cooling'
 * '<S7>'   : 'training2/Ctrl_Subsystem/Core/Heating'
 * '<S8>'   : 'training2/Ctrl_Subsystem/Core/Cooling/Compare To Zero'
 * '<S9>'   : 'training2/Ctrl_Subsystem/Core/Cooling/If Action Auto program'
 * '<S10>'  : 'training2/Ctrl_Subsystem/Core/Cooling/If Action Manual program'
 * '<S11>'  : 'training2/Ctrl_Subsystem/Core/Cooling/If Action Auto program/Cooling main system'
 * '<S12>'  : 'training2/Ctrl_Subsystem/Core/Cooling/If Action Auto program/PID Controller'
 * '<S13>'  : 'training2/Ctrl_Subsystem/Core/Cooling/If Action Auto program/Cooling main system/Cooling PID 1 level'
 * '<S14>'  : 'training2/Ctrl_Subsystem/Core/Cooling/If Action Auto program/Cooling main system/Coooling PID 2 levels'
 * '<S15>'  : 'training2/Ctrl_Subsystem/Core/Cooling/If Action Auto program/Cooling main system/Cooling PID 1 level/Compare To Zero'
 * '<S16>'  : 'training2/Ctrl_Subsystem/Core/Heating/Compare To Zero'
 * '<S17>'  : 'training2/Ctrl_Subsystem/Core/Heating/If Action Auto program'
 * '<S18>'  : 'training2/Ctrl_Subsystem/Core/Heating/If Action Manual program'
 * '<S19>'  : 'training2/Ctrl_Subsystem/Core/Heating/If Action Auto program/Heating main system'
 * '<S20>'  : 'training2/Ctrl_Subsystem/Core/Heating/If Action Auto program/PID Controller'
 * '<S21>'  : 'training2/Ctrl_Subsystem/Core/Heating/If Action Auto program/Heating main system/Heating PID 1 level'
 * '<S22>'  : 'training2/Ctrl_Subsystem/Core/Heating/If Action Auto program/Heating main system/Heating PID 2 levels'
 * '<S23>'  : 'training2/Ctrl_Subsystem/Core/Heating/If Action Auto program/Heating main system/Heating PID 1 level/Compare To Zero'
 */
#endif                                 /* RTW_HEADER_Ctrl_Subsystem_h_ */
