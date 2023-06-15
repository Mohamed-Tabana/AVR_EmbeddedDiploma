#include "DIO_interface.h"
#include "MOTOR_interface.h"
DIO_Pin_Type MotorPinsArray[NUMBER_OF_MOTORS][NUMBER_OF_PIN_PER_MOTOR]={
						/*IN1	IN2*/
	/*MOTOR 1*/			{PINC6,PINC7},
	/*MOTOR 2*/			{PINA2,PINA3},
	/*MOTOR 3*/			{PINA4,PINA5},
	/*MOTOR 4*/			{PINA6,PINA7}
	};

