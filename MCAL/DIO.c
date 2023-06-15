/*
 * DIO.c
 *
 * Created: 10/21/2022 2:18:27 PM
 *  Author: Mohamed TABANA
 */ 

#include "DIO_interface.h"
#include "DIO_private.h"  
#include "DIO_cfg.h"

static void DIO_PinInit(DIO_Pin_Type pin,DIO_PinStatus_Type status)
{
	int pin_num =pin % 8;
	DIO_Port_Type port =pin/8;
	switch(status)
	{
		case OUTPUT:
			switch(port)
			{
				case PA:
				SET_BIT(DDRA,pin_num);
				CLR_BIT(PORTA,pin_num);
				break;
				case PB:
				SET_BIT(DDRB,pin_num);
				CLR_BIT(PORTB,pin_num);
				break;
				case PC:
				SET_BIT(DDRC,pin_num);
				CLR_BIT(PORTC,pin_num);
				break;
				case PD:		
				SET_BIT(DDRD,pin_num);
				CLR_BIT(PORTD,pin_num);
				break;
			}
			break;
		case INPULL:
			switch(port)
			{
				case PA:
				CLR_BIT(DDRA,pin_num);
				SET_BIT(PORTA,pin_num);
				break;
				case PB:
				CLR_BIT(DDRB,pin_num);
				SET_BIT(PORTB,pin_num);
				break;
				case PC:
				CLR_BIT(DDRC,pin_num);
				SET_BIT(PORTC,pin_num);
				break;
				case PD:
				CLR_BIT(DDRD,pin_num);
				SET_BIT(PORTD,pin_num);
				break;
			}
			break;
		case INFREE:
			switch(port)
			{
				case PA:
				CLR_BIT(DDRA,pin_num);
				CLR_BIT(PORTA,pin_num);
				break;
				case PB:
				CLR_BIT(DDRB,pin_num);
				CLR_BIT(PORTB,pin_num);
				break;
				case PC:
				CLR_BIT(DDRC,pin_num);
				CLR_BIT(PORTC,pin_num);
				break;
				case PD:
				CLR_BIT(DDRD,pin_num);
				CLR_BIT(PORTD,pin_num);
				break;
			}
			break;
	}
}
void DIO_WritePin(DIO_Pin_Type pin,DIO_PinVoltage_Type vlot)
{
	int pin_num =pin % 8;
	DIO_Port_Type port =pin / 8;
	if (vlot==LOW)
	{
		switch(port)
		{
			case PA:
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			CLR_BIT(PORTD,pin_num);
			break;
		}	
	}
	else if(vlot==HIGH)
	{
		switch(port)
		{
			case PA:
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			SET_BIT(PORTD,pin_num);
			break;
		}
	}
}
DIO_PinVoltage_Type DIO_ReadPin(DIO_Pin_Type pin){	
	int pin_num =pin % 8;
	DIO_Port_Type port =pin / 8;
	switch(port)
	{
		case PA:
		return READ_BIT(PINA,pin_num);
		break;
		case PB:
		return READ_BIT(PINB,pin_num);
		break;
		case PC:
		return READ_BIT(PINC,pin_num);
		break;
		case PD:
		return READ_BIT(PIND,pin_num);
		break;
	}
}
void DIO_TogglePin(DIO_Pin_Type pin){
		int pin_num =pin % 8;
		DIO_Port_Type port =pin / 8;
		switch(port)
		{
			case PA:
			TGL_BIT(PORTA,pin_num);
			break;
			case PB:
			TGL_BIT(PORTA,pin_num);
			break;
			case PC:
			TGL_BIT(PORTC,pin_num);
			break;
			case PD:
			TGL_BIT(PORTD,pin_num);
			break;
		}
}

void DIO_WritePort(DIO_Port_Type port, u8 data)
{
	switch(port)
	{
		case PA:
		PORTA=data;
		break;
		case PB:
		PORTB=data;
		break;
		case PC:
		PORTC=data;
		break;
		case PD:
		PORTD=data;
		break;
	}
}
u8 DIO_ReadPort(DIO_Port_Type port)
{
	switch(port)
	{
		case PA:
		return PINA;
		break;
		case PB:
		return PINB;
		break;
		case PC:
		return PINC;
		break;
		case PD:
		return PIND;
		break;
	}
}

void DIO_Init(void){
	DIO_Pin_Type i;
	for(i=PINA0;i<TOTAL_PINS;i++)
	{
		DIO_PinInit(i,arr[i]);
	}
}