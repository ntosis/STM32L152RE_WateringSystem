/*
 * eeprom_calib.h
 *
 *  Created on: Jul 5, 2016
 *      Author: unix
 */

#ifndef EEPROM_CALIB_H_
#define EEPROM_CALIB_H_
#include <hardware_init.h>
// Create structure
typedef struct {
    uint8_t  oneLevelSystem_C;
    float K_P_Htng;
    float K_I_Htng;
    float K_D_Htng;
    float K_P_Coolg;
    float K_I_Coolg;
    float K_D_Coolg;
    uint8_t smartCnt_C;
    uint8_t debugInfosFlag_C:1;
} CAL_PARAM;

void LoadCALvars(void);
void SaveCALvars(void);

extern CAL_PARAM CALinRAM;
extern CAL_PARAM volatile const CALinEE;
extern CAL_PARAM volatile const *p;

#define K_P_Htng (p->K_P_Htng)
#define K_I_Htng (p->K_I_Htng)
#define K_D_Htng (p->K_D_Htng)
#define K_P_Coolg (p->K_P_Coolg)
#define K_I_Coolg (p->K_I_Coolg)
#define K_D_Coolg (p->K_D_Coolg)
#define oneLevelSystem_C (p->oneLevelSystem_C)
#define smartCnt_C (p->smartCnt_C)
#define debugInfosFlag_C p->debugInfosFlag_C)
#endif /* EEPROM_CALIB_H_ */

