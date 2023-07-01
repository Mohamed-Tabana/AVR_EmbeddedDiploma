
#define F_CPU 8000000

#include <util/delay.h>

#define  KEYPAD_PROG


#include "DIO_interface.h"
#include "LCD.h"
#include "Timer.h"
#include "Timer_Services.h"
#include "UltraSonic.h"

void LED1 (void* pvPArameter);
void LED2 (void* pvPArameter);

void main(void)
{
	DIO_Init();
	LCD_Init();
	TIMER1_Init(TIMER1_NORMAL_MODE,TIMER1_SCALER_8);
	US_vidUltraSonicInit();
	//ADC_Init(VREF_VCC,ADC_SCALER_64);

	sei();

	
	//while(READ_BIT(TIFR,5)==0);
	//t1=ICR1;
	//SET_BIT(TIFR,5);
	//
	//Timer1_ICU_SelectEdge(FALLING);
	//while(READ_BIT(TIFR,5)==0);
	//t2=ICR1;
	//SET_BIT(TIFR,5);
	//
	//du = t2-t1;
	//LCD_WriteString("Freq: ");
	//LCD_WriteNumber(fr);
	u32 d=0;
	u32 f=0,du=0;
	LCD_SetCursor(0,1);
	LCD_WriteString("TEMP");
	
	while (1)
	{
		
		//PWM_Measure2(&fr, &du);
		//LCD_SetCursor(0,1);
		//LCD_WriteString("Duty: ");
		//LCD_WriteNumber(fr);
		//LCD_SetCursor(1,1);
		//LCD_WriteString("Duty: ");
		//LCD_WriteNumber(du);
	//	DIO_TogglePin(PINC0);
		//_delay_ms(400);
	
			//PWM_Measure2(&f,&du);
			US_vidGetDistance(PINA0, &d);
	
				LCD_SetCursor(1,1);
				LCD_WriteString("distance: ");
				LCD_WriteNumber(d);
				LCD_WriteString("    ");
		    	_delay_ms(1000);
	}
}
