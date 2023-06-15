/* a3lanaaaat
#define F_CPU 8000000
#include <util/delay.h>
#include "DIO_interface.h"
#include "MOTOR_interface.h"
#include "MOVE.h"
#include "LCD.h"


int main(void)
{
	DIO_Init();
	MOVE_Init();
	LCD_Init();
	u8 arr [] ="Mohamed TABANA";
	u8 si=strlen(arr);
	s8 x = 1;

	while (1)
	{
		for(u8 i=0 ;i<si;i++)
		{
			LCD_SetCursor(x,0);
			LCD_WriteString(arr+(si-i));
			_delay_ms(50);
			LCD_Clear();
		}
		for(u8 i=0 ;i<16;i++)
		{
			LCD_SetCursor(x,i+1);
			LCD_WriteString(arr);
			_delay_ms(50);
			LCD_Clear();
		}
		if (x==1)
		x=2;
		else
		x=1;
	}
}

*/



/* man killed 

#define F_CPU 8000000
#include <util/delay.h>
#include "DIO_interface.h"
#include "MOTOR_interface.h"
#include "MOVE.h"
#include "LCD.h"


int main(void)
{
	DIO_Init();
	MOVE_Init();
	LCD_Init();
	s8 x = 1;
	u8 i=0;
	
	u8 pattern1[]={0x00,0x04,0x02,0x1f,0x02,0x04,0x00,0x00};
	u8 pattern2[]={ 0x04, 0x0a, 0x04, 0x0e, 0x15, 0x04, 0x0a, 0x0a};
	u8 pattern3[]={ 0x04, 0x0e, 0x06, 0x1f, 0x17, 0x04, 0x0a, 0x0a};
	u8 pattern4[]={ 0x00, 0x00, 0x08, 0x06, 0x01, 0x06, 0x08, 0x00};
	LCD_createPattern(pattern1,1);
	LCD_createPattern(pattern2,2);
	LCD_createPattern(pattern3,3);
	LCD_createPattern(pattern4,4);
	DIO_WritePort(PB,10);
	while (1)
	{
		
		for(x=1;x<15;x++)
		{
			LCD_SetCursor(1,0);
			LCD_WriteChar(3);
			LCD_SetCursor(1,15);
			LCD_WriteChar(2);
			LCD_SetCursor(1,x);
			LCD_WriteChar(1);
			if(x==14)
			{
				LCD_SetCursor(1,14);
				LCD_WriteChar(' ');
				LCD_SetCursor(1,15);
				LCD_WriteChar(4);
			}
			_delay_ms(350);
			LCD_Clear();
		}
	}
}




*/


