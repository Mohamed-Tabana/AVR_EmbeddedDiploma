/*
 * Sensors.h
 *
 * Created: 11/18/2022 11:00:15 PM
 *  Author: Tabana
 */ 


#ifndef SENSORS_H_
#define SENSORS_H_

#include "StdTypes.h"
#include "ADC.h"


#define LM35_CH CH_0
#define MPX_4115 CH_7

/* Temp C X10 */
u16 Temp_Read(void);

u16 Smoke_Read(void);





#endif /* SENSORS_H_ */