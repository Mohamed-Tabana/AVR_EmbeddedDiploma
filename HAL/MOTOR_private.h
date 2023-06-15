/*
 * MOTOR_private.h
 *
 * Created: 10/28/2022 8:04:24 PM
 *  Author: moham
 */ 
//#include "MOTOR_cfg.h"

#ifndef MOTOR_PRIVATE_H_
#define MOTOR_PRIVATE_H_
#include "MOTOR_interface.h"

#define NUMBER_OF_PIN_PER_MOTOR 2
#define IN1 0
#define IN2 1
extern DIO_Pin_Type MotorPinsArray[NUMBER_OF_MOTORS][NUMBER_OF_PIN_PER_MOTOR];




#endif /* MOTOR_PRIVATE_H_ */