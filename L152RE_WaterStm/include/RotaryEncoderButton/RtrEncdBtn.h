#ifndef _RTRENCDBTN_H_
#define _RTRENCDBTN_H_

#include "hardware_init.h"
#include "eeprom_calib.h"
//#include <avr/interrupt.h>
//#include "timerInterrupt.h"
//#include "ds1307.h"

/*
 * The ports for the pins are defined in hardware_init.h
 * The D2 D3 D4 are used for the rotary encoder
 */
extern volatile uint8_t signalButton;
extern volatile bool TurnDetected ;
extern volatile int8_t up;
extern int8_t SOLLtemperature;
extern uint8_t smartCntUp;
extern uint8_t smartCntDown;
extern uint8_t smartCntFlag;

void initRtrEncoder();
void readButton(const portTickType now);
void readEncoder(void);
inline void checkHoldButton(void);
void checkStruct();
void resetSmartCnt(void);
uint8_t returnStateofProgram();
void smartChangeBtwnHeatCool(void);



typedef struct {
portTickType timeOfClick;
bool clicked;
} click;

static click ArrayOfClicks[5];
extern bool clicked;
extern bool doubleClicked;
extern bool onStateofProgram;

extern volatile uint8_t signalButton; // not to be optimized
static volatile uint8_t pnt=0;
uint8_t holdCnt;


void inline checkHoldButton(void) {

	if(!__READ(RtrEnc_SWTCH)) {  			//if button is logical LOW

		holdCnt++;

	}

	else if(__READ(RtrEnc_SWTCH)) {

		holdCnt=0;

	}

	if(holdCnt>4) setTimeLoop(); //this task is called every 800ms, for 3 sec we calculate a value ~ 4
}

#endif
