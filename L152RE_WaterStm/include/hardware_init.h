/*
 * hardware_init.h
 *
 *  Created on: Sep 16, 2016
 *      Author: unix
 */

#ifndef HARDWARE_INIT_H_
#define HARDWARE_INIT_H_

#include "stm32l1xx_hal.h"
#include "cmsis_os.h"

/** \def EEMEM_1
    Attribute expression causing a variable to be allocated within the
    .eeprom1 section.	*/
#define EEMEM_1 __attribute__((section(".eeprom1")))


typedef enum { false, true } bool;
//Pin Macros
#define _SET(type,name,bit)          HAL_GPIO_WritePin(type ## name, GPIO_PIN_##bit, GPIO_PIN_SET)
#define _CLEAR(type,name,bit)        HAL_GPIO_WritePin(type ## name, GPIO_PIN_##bit, GPIO_PIN_RESET)
#define _TOGGLE(type,name,bit)       HAL_GPIO_TogglePin(type ## name, GPIO_PIN_##bit)
#define _GET(type,name,bit)          HAL_GPIO_ReadPin(type ## name, GPIO_PIN_##bit)
//#define _PUT(type,name,bit,value)    type ## name = ( type ## name & ( ~ _BV(bit)) ) | ( ( 1 & (unsigned char)value ) << bit )

//these macros are used by end user
//#define __OUTPUT(pin)         _SET(PORT,pin)
//#define __INPUT(pin)          _CLEAR(DDR,pin)
#define __HIGH(pin)           _SET(GPIO,pin)
#define __LOW(pin)            _CLEAR(GPIO,pin)
#define __TOGGLE(pin)         _TOGGLE(GPIO,pin)
#define __READ(pin)           _GET(GPIO,pin)

// Set Pins
#define LCD_ChipSelect B,0
#define LCD_CMD A,4
#define LCD_SPI_CS B,6
#define LCD_SPI_D/C C,8

#define TOUCH_CS C,6
#define TOUCH_INT C,5

#define LCD_Reset A,10
#define LCD_WR A,1
#define LCD_RD A,0
#define PORTAMSK_RS_W_R 0b0000000100010011
#define TempSensor_SS B,8 //Temperature slave select Pin, Arduino connector D5
#define RtrEnc_CLK A,10 // Arduino connector D2
#define RtrEnc_DT B,5 // Arduino connector D4
#define RtrEnc_SWTCH B,3 // Arduino connector D3
#define RED_LED A,1	  //PIN A1 at Arduino UNO/Duemilanove
#define GREEN_LED A,4	  //PIN A2 at Arduino UNO/Duemilanove
#define BLUE_LED A,5 //0      //PIN A0 at Arduino UNO/Duemilanove
#define RELAY_PIN B,10     //PIN 06 at Arduino UNO/Duemilanove
#define TEST_PIN A,9

void MX_GPIO_Init(void);
extern I2C_HandleTypeDef hi2c1;
#endif /* HARDWARE_INIT_H_ */
