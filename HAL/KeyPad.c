/*
 * KeyPad.c
 *
 * Created: 11/5/2022 1:22:15 AM
 *  Author: Mohamed TABANA
 */ 

#include "KeyPad_interface.h"

#define KEYPAD_PROG

u8 KEYPAD_GetKey(void)
{
	u8 r,c,key=NO_KEY;
	for(r=0;r<ROWS;r++)
	{	
		DIO_WritePin(FIRST_OUTPUT+r,LOW);
		for(c=0;c<COLS;c++)
		{
			if(!DIO_ReadPin(FIRST_INPUT+c))
			{
				key= KeyArray[r][c];
				while(!DIO_ReadPin(FIRST_INPUT+c));
			}	
		}
			DIO_WritePin(FIRST_OUTPUT+r,HIGH);

	}
	return key;
}
void KEYPAD_Init()
{
	DIO_WritePin(FIRST_OUTPUT,HIGH);
	DIO_WritePin(FIRST_OUTPUT+1,HIGH);
	DIO_WritePin(FIRST_OUTPUT+2,HIGH);
	DIO_WritePin(FIRST_OUTPUT+3,HIGH);
}
