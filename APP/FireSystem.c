/*
 * FireSystem.c
 *
 * Created: 11/19/2022 2:44:17 PM
 *  Author: Tabana
 */ 
#include "FireSystem.h"

void FireSystem_Init(void)
{
	
}
	u8 state;
	u8 key;
	u32 pass=0;
void FireSystem_Runnable(void)
{

	u16 temp=Temp_Read();
	LCD_SetCursor(1,0);
	LCD_WriteNumber(temp/10);
	LCD_WriteChar('.');
	LCD_WriteNumber(temp%10);

	LCD_WriteString("   ");
	if (temp<350 && state !=3)
	{
		state=1;
	}
	else if (temp>400 && state !=3)
	{
		state=2;
	}
	
	if ((temp <=400) && state==1)
	{
		pass=0;
		state=1;
		LCD_SetCursor(1,5);
		LCD_WriteString("Fine            ");
		LCD_SetCursor(2,0);
		LCD_WriteString("              ");
		DIO_WritePin(PINC1,LOW);
		DIO_WritePin(PINC0,LOW);
		MOTOR_Stop(M1);
		
	}
	else if(temp>=350 && state ==2)
	{
		pass=0;
		state=2;
		LCD_SetCursor(2,0);
		LCD_WriteString("              ");
		LCD_SetCursor(1,5);
		LCD_WriteString("Heat   ");
		DIO_WritePin(PINC1,HIGH);
		u16 smoke=Smoke_Read();
		LCD_WriteNumber(smoke/10);
		LCD_WriteChar('.');
		LCD_WriteNumber(smoke%10);
		LCD_WriteString("    ");
		MOTOR_CCW(M1);
		if(smoke>600)
		{
			state=3;
		}
	}
	else if(state == 3)
	{
		LCD_SetCursor(1,5);
		LCD_WriteString("Fire   ");
		u16 smoke=Smoke_Read();
		LCD_WriteString("    ");

		LCD_WriteNumber(smoke);
		DIO_WritePin(PINC0,HIGH);
		DIO_WritePin(PINC1,LOW);
		DIO_WritePin(PINC5,HIGH);
	

			
		key= KEYPAD_GetKey();
		if(key != NO_KEY)
		{
			pass=pass*10+key-'0';
			LCD_SetCursor(2,0);
			LCD_WriteString("pass:             ");
			LCD_SetCursor(2,6);
			LCD_WriteNumber(pass);
			if (pass==123)
			{
				state=1;
			}
		}

	}

}