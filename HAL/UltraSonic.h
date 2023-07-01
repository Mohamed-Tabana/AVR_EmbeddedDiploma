/*
 * UltraSonic.h
 *
 * Created: 7/1/2023 3:32:50 AM
 *  Author: ALTAWKEL
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include <util/delay.h>
#include "DIO_interface.h"
#include "Timer.h"


typedef DIO_Pin_Type ULTRASONIC_type ;

void US_vidUltraSonicInit(void);

void US_vidGetDistance(ULTRASONIC_type copy_eULTRASONIC, u32 *copy_d);


#endif /* ULTRASONIC_H_ */