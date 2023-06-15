/*
 * ServoMotor.c
 *
 * Created: 12/9/2022 5:43:46 PM
 *  Author: Tabana
 */ 
#include "ServoMotor.h"



void servo_Init(void)
{
	ICR1=20000;
	
}
void servo_Angle(s8 angle,Servo_PIN_type pin)
{
	switch(pin)
	{
		case Servo_PIND4:
			OCR1B=(((s32)2000*(angle-90))/180+2499);
		break;
		case Servo_PIND5:
			OCR1A=(((s32)2000*(angle-90))/180+2499);
		break;
	}
}
