/*
 * heatingsys.h
 *
 *  Created on: Nov 27, 2015
 *      Author: unix
 */

#ifndef HEATINGSYS_H_
#define HEATINGSYS_H_

#include "hardware_init.h"
//#include "ds1307.h"
#include "RtrEncdBtn.h"
#include "Ctrl_Subsystem.h"
void updateSollTemperature(void);
void autoProgram();
void LEDfunction(void);
void initLEDs(void);
uint16_t returnDebugInfo();
extern boolean_T stateOfProgram; /* '<S5>/XOR1' */
extern bool selectProgram; /* '<S2>/XOR1' */
extern bool autoProgramTimeEnabled;
extern int8_t SOLLtemperature;
//extern ExtY_Ctrl_Subsystem Ctrl_Subsystem_Y; /* '<S1>/Logical Operator' */



#endif /* HEATINGSYS_H_ */
