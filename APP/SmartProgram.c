/*
 * SmartProgram.c
 *
 * Created: 12/28/2022 12:09:47 PM
 *  Author: Tabana
 */ 
#include "SmartProgram.h"




void SERVO (u8 ang)
{
	servo_Angle(ang,Servo_PIND4);
}
void LEDON (u32 led)
{
	switch(led)
	{
		case 0:
		DIO_WritePin(PINC0,HIGH);
		break;
		case 1:
		DIO_WritePin(PINC1,HIGH);
		break;
		case 2:
		DIO_WritePin(PINC2,HIGH);
		break;
		case 3:
		DIO_WritePin(PINC3,HIGH);
		break;
	}
}
void LCD (u32 num)
{
	LCD_SetCursor(0,0);
	LCD_WriteNumber(num);
	LCD_WriteString("              ");
}
void RGB (u32 num)
{
	RGB_color(num,OCR0_pin,OCRA1_pin,OCRB1_pin);
}

void analyzer (u8* instruction)
{
	task_type arr3[10]={
		{"SERVO",SERVO},
		{"LEDON",LEDON},
		{"LCD",LCD},
		{"RGB",RGB},
	};
	u8 device[20]={0};
	u8 number[6]={0};
	u32 num=0;
	u8 i = 0 ;
	for (i = 0 ;instruction [i] != ' '; i++ )
	{
		device [i] = instruction [i];
		if (instruction [i] == '#')
		{
		LCD_SetCursor(0,0);
		LCD_WriteString("again please");
		return;
		}
	}
	
	i++;
	u8 j=0;
	
	for ( i ; instruction [i] ; i++ )
	{
		number [j] = instruction [i];
		j++;
	}
	
	num=Smart_StringToNumber(number);

	
		
	for(u8 i =0 ;i<4 ; i++)
	{
		if (!strcmp(device,arr3[i].pdevice))
		{
			arr3[i].pfun(num);
			break;
		}
	}

	
		
}


u32 Smart_StringToNumber(u8*str)
{
	u32 num=0;
	for(u8 i=0;str[i];i++)
	{
		num=(num*10)+str[i]-'0';
	}
	return num;
}

u8 Smart_StringCompare(u8*str1,u8*str2)
{
	for(u8 i=0;str1[i] || str2[i];i++)
	{
		if (str1[i] != str2[i] )
		{
			return 0;
		}
	}
	return 1;
}