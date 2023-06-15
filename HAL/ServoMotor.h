/*
 * ServoMotor.h
 *
 * Created: 12/9/2022 5:44:04 PM
 *  Author: Tabana
 */ 


#ifndef SERVOMOTOR_H_
#define SERVOMOTOR_H_

#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
typedef enum
{
	Servo_PIND4,
	Servo_PIND5
}Servo_PIN_type;
void servo_Init(void);
void servo_Angle(s8 angle,Servo_PIN_type pin);



#endif /* SERVOMOTOR_H_ */