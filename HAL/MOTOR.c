/*
 * MOTOR.c
 *
 * Created: 10/21/2022 11:07:44 PM
 *  Author: Mohamed TABANA
 */ 
#include "MOTOR_interface.h"
void MOTOR_CW(MOTOR_Type motor)
{	
		DIO_WritePin(MotorPinsArray[motor][IN1],HIGH);
		DIO_WritePin(MotorPinsArray[motor][IN2],LOW);
}
void MOTOR_CCW(MOTOR_Type motor)
{
		DIO_WritePin(MotorPinsArray[motor][0],LOW);
		DIO_WritePin(MotorPinsArray[motor][1],HIGH);

}
void MOTOR_Stop(MOTOR_Type motor)
{
		DIO_WritePin(MotorPinsArray[motor][0],LOW);
		DIO_WritePin(MotorPinsArray[motor][1],LOW);

}