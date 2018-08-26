#ifndef _TEMPERATURESENS_H_
#define _TEMPERATURESENS_H_

#include "spi.h"
#include "hardware_init.h"

void initTempSens();
float actualTemperature();
extern  uint8_t Temperature;
#endif
