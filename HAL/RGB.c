/*
 * RGB.c
 *
 * Created: 12/10/2022 3:25:57 PM
 *  Author: Tabana
 */ 
#include "RGB.h"

u8 RGB_ColorArr[15][3]=
{
	{0,0,0},
	{254,254,254},
	{254,0,0},
	{0,254,0},
	{0,0,254},
	{254,254,0},
	{254,0,254},
	{0,254,254},
	{127,0,0},
	{0,127,0},
	{0,0,127},
	{127,127,0},
	{127,0,127},
	{0,127,127},
};
void RGB_Init()
{
	TIMER1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8);
	Timer1_OCRA1Mode(OCRA_NON_INVERTING);
	Timer1_OCRB1Mode(OCRB_NON_INVERTING);
		
	TIMER0_Init(TIMER0_FASTPWM_MODE,TIMER0_SCALER_8);
	TIMER0_OC0Mode(OC0_NON_INVERTING);
	ICR1=255;

}
void RGB_color(RGB_Color_type color,RGB_PIN_type red,RGB_PIN_type green, RGB_PIN_type blue )
{
	
	switch (red)
	{
		case OCR0_pin:
		OCR0=RGB_ColorArr[color][0];
		break;
		case OCRA1_pin:
		OCR1A=RGB_ColorArr[color][0];
		break;
		case OCRB1_pin:
		OCR1B=RGB_ColorArr[color][0];
		break;	
	}
	switch (green)
	{
		case OCR0_pin:
		OCR0=RGB_ColorArr[color][1];
		break;
		case OCRA1_pin:
		OCR1A=RGB_ColorArr[color][1];
		break;
		case OCRB1_pin:
		OCR1B=RGB_ColorArr[color][1];
		break;
	}
	switch (blue)
	{
		case OCR0_pin:
		OCR0=RGB_ColorArr[color][2];
		break;
		case OCRA1_pin:
		OCR1A=RGB_ColorArr[color][2];
		break;
		case OCRB1_pin:
		OCR1B=RGB_ColorArr[color][2];
		break;
	}
		
}


void RGB_Flashing()
{
	static u8 col1=0;
	static u8 col2=254;
	col1++;
	col2--;
	OCR0=col1;
	OCR1A=col2;
	OCR1B=5;
}