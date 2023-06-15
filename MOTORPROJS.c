/*#define F_CPU 8000000
#include <util/delay.h>
#include "DIO_interface.h"
#include "MOTOR.h"


int main(void)
{
	DIO_Init();
	int flag=0;
	int flagMODE=0;
	while (1)
	{
		if (!DIO_ReadPin(PINB0))
		{
			flag=!flag;
			while(!DIO_ReadPin(PINB0));
		}
		if (!DIO_ReadPin(PINB1))
		{
			flagMODE=!flagMODE;
			while(!DIO_ReadPin(PINB1));
		}

		if (flagMODE==0)
		{
					if (flag==0)
					{
						MOTOR_CW(M1);
					}
					else
					{
						MOTOR_CCW(M1);
					}
		}
		else
		{
			MOTOR_Stop(M1);
		}
	}
}
*/