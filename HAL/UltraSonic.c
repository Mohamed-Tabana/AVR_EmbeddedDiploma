/*
 * UltraSonic.c
 *
 * Created: 7/1/2023 3:32:34 AM
 *  Author: TABANA
 */ 
#include "UltraSonic.h"

#include "LCD.h"

static volatile  u8 flag=0;
static volatile t1=0,t2=0;
static void FUNC_US(void)
{
	//static volatile u8 N=0;
	//
	//LCD_Init();
   //LCD_SetCursor(0,1);
	if (flag==0)
	{	
		//N++;
	//LCD_WriteString("H");
		//LCD_WriteNumber(N);
		t1=ICR1;
		Timer1_ICU_SelectEdge(FALLING);
		flag=1;
	}
	else if (flag==1)
	{
	//LCD_WriteString("A");	
		t2=ICR1;
		
		flag=2;
	}
}

void US_vidUltraSonicInit(void)
{
	
	Timer1_ICU_SetCallBack(FUNC_US);
	Timer1_ICU_InterruptEnable();
}

void US_vidGetDistance(ULTRASONIC_type copy_eULTRASONIC, u32 *copy_d)
{
	TCNT1=0;
	u32 c=0;
	//flag=0;
	Timer1_ICU_SelectEdge(RISING);
	
	DIO_WritePin(PINA0,HIGH);
	_delay_us(10);
	DIO_WritePin(PINA0,LOW);
	while (flag<2 && c<500000 )
	{
		c++;
		_delay_us(1);
	}

	if (flag==2)
	{
		*copy_d=(t2-t1)/58;
	}
	flag=0;

	// workaround for successive US measurements 
	_delay_ms(100);
}