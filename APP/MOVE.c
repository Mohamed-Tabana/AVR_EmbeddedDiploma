
#include "MOVE.h"
#include "MOTOR_interface.h"


void MOVE_Init(void)
{
	/*NO THING HERE*/
}
void MOVE_Runnable(void)
{
	MOVE_Stop();
	while (!DIO_ReadPin(FORWARD_B))
	{
		MOVE_Forward();
	}
	
	while (!DIO_ReadPin(BACKWARD_B))
	{
		MOVE_Backward();
	}
	while (!DIO_ReadPin(LEFT_B))
	{
		MOVE_Left();
	}
	while (!DIO_ReadPin(RIGHT_B))
	{
		MOVE_Right();
	}
}



void MOVE_Forward(void)
{
	MOTOR_CW(FRONT_LEFT);
	MOTOR_CW(FRONT_RIGHT);
	MOTOR_CW(BACK_LEFT);
	MOTOR_CW(BACK_RIGHT);
	
}
void MOVE_Backward(void)
{
	MOTOR_CCW(FRONT_LEFT);
	MOTOR_CCW(FRONT_RIGHT);
	MOTOR_CCW(BACK_LEFT);
	MOTOR_CCW(BACK_RIGHT);
	
}
void MOVE_Left(void)
{
	MOTOR_CW(FRONT_LEFT);
	MOTOR_CW(FRONT_RIGHT);
	MOTOR_CCW(BACK_LEFT);
	MOTOR_CCW(BACK_RIGHT);
	
}
void MOVE_Right(void)
{
	MOTOR_CCW(FRONT_LEFT);
	MOTOR_CCW(FRONT_RIGHT);
	MOTOR_CW(BACK_LEFT);
	MOTOR_CW(BACK_RIGHT);
	
}
void MOVE_Stop(void)
{
	MOTOR_Stop(FRONT_LEFT);
	MOTOR_Stop(FRONT_RIGHT);
	MOTOR_Stop(BACK_LEFT);
	MOTOR_Stop(BACK_RIGHT);
	
}
/*

#define F_CPU 8000000
#include <util/delay.h>
#include "DIO_interface.h"
#include "MOTOR.h"


int main(void)
{
	DIO_Init();
	while (1)
	{
		DIO_Init();
		while (!DIO_ReadPin(PINB0))
		{
			Forward();
		}
		
		while (!DIO_ReadPin(PINB1))
		{
			backward();
		}
		while (!DIO_ReadPin(PINB2))
		{
			Right();
		}
		while (!DIO_ReadPin(PINB3))
		{
			Left();
		}
		
	}
}
*/