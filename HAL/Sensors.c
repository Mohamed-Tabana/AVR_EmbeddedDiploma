/*
 * Sensors.c
 *
 * Created: 11/18/2022 11:00:33 PM
 *  Author: Tabana
 */ 
#include "Sensors.h"

u16 Temp_Read(void)
{

	u16 temp= ADC_ReadVolt(LM35_CH);
	

	return temp;
}
u16 Smoke_Read(void)
{
	u16 volt= ADC_ReadVolt(MPX_4115);
	u16 smoke =(((volt/5.1)+95)/9)*10;
	return smoke;
}
