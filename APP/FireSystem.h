/*
 * FireSystem.h
 *
 * Created: 11/19/2022 2:44:35 PM
 *  Author: Tabana
 */ 


#ifndef FIRESYSTEM_H_
#define FIRESYSTEM_H_

#include "StdTypes.h"
#include "LCD.h"
#include "KeyPad_interface.h"
#include "MOTOR_interface.h"
#include "Sensors.h"

void FireSystem_Init(void);
void FireSystem_Runnable(void);


#endif /* FIRESYSTEM_H_ */