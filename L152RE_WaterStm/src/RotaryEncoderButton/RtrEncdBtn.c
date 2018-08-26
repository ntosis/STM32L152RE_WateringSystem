#include "RtrEncdBtn.h"
#include <stdlib.h>
//#include "heatingSys.h"
//#include <eeprom_calib.h>

bool clicked=false;
bool doubleClicked=false;
bool onStateofProgram=false;
uint8_t holdCnt=0;
//step between Heating/Cooling
uint8_t smartCntUp=0;
uint8_t smartCntDown=0;
uint8_t smartCntFlag=0;
volatile uint8_t signalButton = 0;
volatile int8_t up = 0;
volatile bool TurnDetected = false;

void initRtrEncoder() {

    GPIO_InitTypeDef GPIO_InitStruct;
    /*Configure GPIO pin : Arduino Connector D2_Pin (PA10) RtrEnc_CLK */
     GPIO_InitStruct.Pin = GPIO_PIN_10;
     GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
     GPIO_InitStruct.Pull = GPIO_NOPULL;
     GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
     HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

     /*Configure GPIO pin : Arduino Connector D4_Pin (PB5) RtrEnc_DT */
     GPIO_InitStruct.Pin = GPIO_PIN_5;
     GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
     GPIO_InitStruct.Pull = GPIO_NOPULL;
     GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
     HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

     /*Configure GPIO pin : Arduino Connector D3_Pin (PB3) RtrEnc_SWTCH */
      GPIO_InitStruct.Pin = GPIO_PIN_3;
      GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
      GPIO_InitStruct.Pull = GPIO_NOPULL;
      GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
      HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

void readEncoder(void)
{
        static const int8_t lookup_table[] = {0,0,0,-1,0,0,1,0,0,1,0,0,-1,0,0,0};
        static uint8_t enc_val = 0;

        enc_val = enc_val << 2;
        uint8_t readPins =0;

        readPins = !( __READ(RtrEnc_CLK))<<1;
        readPins |= !(__READ(RtrEnc_DT));

        enc_val = enc_val | (readPins);

        up = up + lookup_table[enc_val & 0b1111];
        int8_t result = lookup_table[enc_val & 0b1111];
        if(!(result==0)) {

            TurnDetected = true;

        }
}

void readButton(const portTickType now) {

    static uint8_t stateOfSwitch=0;

    stateOfSwitch |= !(__READ(RtrEnc_SWTCH));
    //bit masking for the 7,6 th bits.
    if ((stateOfSwitch&0b11)==1) {
    ArrayOfClicks[pnt].timeOfClick= now;
    ArrayOfClicks[pnt].clicked=true;
    pnt++;
         //
    if(pnt==5) pnt=0;
    if(signalButton<2) signalButton++;
    }
    //store the state for the next scan;
    stateOfSwitch = stateOfSwitch<<1;
}

void checkStruct() {

 pnt=0;
 clicked=false;
 doubleClicked=false;
  for(int i=0;i<5;i++) {
         if(i<4){
         if(ArrayOfClicks[i].clicked==true)  {
             if(ArrayOfClicks[i+1].clicked==true) {
            	int16_t dt= (ArrayOfClicks[i+1].timeOfClick)-(ArrayOfClicks[i].timeOfClick);
               if(dt<700) {
            	   doubleClicked=true;
                   //jump to next incoming signal.
            	   i++;
            	   continue;
                }
               else clicked=true;
             }
             else clicked=true;
         }
       }
       else if(i==4) {
         if(ArrayOfClicks[i].clicked==true)  {
        	if(ArrayOfClicks[0].clicked==true) {
               int16_t dt= (ArrayOfClicks[0].timeOfClick)-(ArrayOfClicks[i].timeOfClick);
               dt=abs(dt);
               if(dt<700) {
            	   doubleClicked=true;
               //i++;
            	   continue;
             }
               else clicked=true;

             }
             else clicked=true;
         }
       }
  }
    for(int i=0;i<5;i++) {
      ArrayOfClicks[i].clicked=false;
      ArrayOfClicks[i].timeOfClick=0;
    }
}

uint8_t returnStateofProgram() {return onStateofProgram;}
void smartChangeBtwnHeatCool() {

	if(smartCntUp>smartCnt_C)  //Calibrations parameter
	    {

		if(SOLLtemperature<0)

			{SOLLtemperature= 22;}
	}

	else if(smartCntDown>smartCnt_C) {

		if(SOLLtemperature > 0)

					{SOLLtemperature= -22;}

	}
}
void resetSmartCnt() {
	if(smartCntFlag) {
		smartCntFlag=0;
	}
	else {
	smartCntUp=0;
	smartCntDown=0;
	}
}
