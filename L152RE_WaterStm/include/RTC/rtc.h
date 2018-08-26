/*
 * rtc.h
 *
 *  Created on: Sep 20, 2016
 *      Author: unix
 */

#ifndef RTC_H_
#define RTC_H_

#include "hardware_init.h"
#include "stm32l1xx_ll_rtc.h"
#include "stm32l1xx_ll_rcc.h"
#include "stm32l1xx_ll_pwr.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Oscillator time-out values */
#define LSE_TIMEOUT_VALUE          ((uint32_t)5000)  /* 5 s */
#define RTC_TIMEOUT_VALUE          ((uint32_t)1000)  /* 1 s */

#define USE_TIMEOUT       0

#define RTC_ERROR_NONE    0
#define RTC_ERROR_TIMEOUT 1
/* Defines related to Clock configuration */
/* Uncomment to enable the adequate Clock Source */
#define RTC_CLOCK_SOURCE_LSE
//#define RTC_CLOCK_SOURCE_LSI

#ifdef RTC_CLOCK_SOURCE_LSI
/* ck_apre=LSIFreq/(ASYNC prediv + 1) with LSIFreq=37 kHz RC */
#define RTC_ASYNCH_PREDIV          ((uint32_t)0x7F)
/* ck_spre=ck_apre/(SYNC prediv + 1) = 1 Hz */
#define RTC_SYNCH_PREDIV           ((uint32_t)0x122)
#endif

#ifdef RTC_CLOCK_SOURCE_LSE
/* ck_apre=LSEFreq/(ASYNC prediv + 1) = 256Hz with LSEFreq=32768Hz */
#define RTC_ASYNCH_PREDIV          ((uint32_t)0x7F)
/* ck_spre=ck_apre/(SYNC prediv + 1) = 1 Hz */
#define RTC_SYNCH_PREDIV           ((uint32_t)0x00FF)
#endif

/* Define used to indicate date/time updated */
#define RTC_BKP_DATE_TIME_UPDTATED ((uint32_t)0x32F2)
/* Private macro -------------------------------------------------------------*/
#define  tmYearToCalendar(Y) ((Y) + 1970)  // full four digit year
#define  CalendarYrToTm(Y)   ((Y) - 1970)
/* Private variables ---------------------------------------------------------*/
const char *monthName;
/* Buffers used for displaying Time and Date */
extern uint8_t aShowTime[50];
extern uint8_t aShowDate[50];

#if (USE_TIMEOUT == 1)
uint32_t Timeout = 0; /* Variable used for Timeout management */
#endif /* USE_TIMEOUT */

struct timeStruct_t {
int Hour,Minute,Second,Day,Year;
int Month;
} ;
/* Private function prototypes -----------------------------------------------*/
void     Configure_RTC_Clock(void);
void     Configure_RTC(void);
void     Configure_RTC_Calendar(void);
uint32_t Enter_RTC_InitMode(void);
uint32_t Exit_RTC_InitMode(void);
uint32_t WaitForSynchro_RTC(void);
void     Show_RTC_Calendar(void);
bool getTime(const char *str);
bool getDate(const char *str);
#endif /* RTC_H_ */
