/*
 * MOTOR.h
 *
 * Created: 10/21/2022 11:08:06 PM
 *  Author: Mohamed TABANA
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_
#include "DIO_interface.h"
#include "MOTOR_cfg.h"
#include "MOTOR_private.h"


typedef enum {
	M1,
	M2,
	M3,
	M4
}MOTOR_Type;

void MOTOR_CW(MOTOR_Type motor);
void MOTOR_CCW(MOTOR_Type motor);
void MOTOR_Stop(MOTOR_Type motor);

#endif /* MOTOR_H_ */