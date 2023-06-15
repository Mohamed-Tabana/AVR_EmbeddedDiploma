/*
 * SmartHome_Slave.c
 *
 * Created: 1/6/2023 9:23:03 PM
 *  Author: Tabana
 */ 

#define F_CPU 8000000
#include <util/delay.h>
#define  KEYPAD_PROG

#include "main.h"

//Slave
void SmartHome_Slave_Init(void)
{
		DIO_Init();
		LCD_Init();
		KEYPAD_Init();
		ADC_Init(VREF_VCC,ADC_SCALER_64);
		SPI_Init(SLAVE);
	
}
void SmartHome_Slave_Runnable(void)
{
	sei();
	u8 KEY=NO_KEY;
	u8 Request=DUMMY;
	u8 Response=DUMMY;
	
	while(1)
	{
		Request=SPI_SendReceive(Response);
		switch(Request)
		{
			case ROOM1_STATUS:
			if(DIO_ReadPin(PINC0)==HIGH)
			{
				Response=ON_STATUS;
			}
			else if(DIO_ReadPin(PINC0)==LOW)
			{
				Response=OFF_STATUS;
			}
			SPI_SendReceive(Response);
			break;
			case ROOM2_STATUS:
			if(DIO_ReadPin(PINC1)==HIGH)
			{
				Response=ON_STATUS;
			}
			else if(DIO_ReadPin(PINC1)==LOW)
			{
				Response=OFF_STATUS;
			}
			SPI_SendReceive(Response);
			break;
			case ROOM3_STATUS:
			if(DIO_ReadPin(PINC2)==HIGH)
			{
				Response=ON_STATUS;
			}
			else if(DIO_ReadPin(PINC2)==LOW)
			{
				Response=OFF_STATUS;
			}
			SPI_SendReceive(Response);
			break;
			case ROOM4_STATUS:
			if(DIO_ReadPin(PINC3)==HIGH)
			{
				Response=ON_STATUS;
			}
			else if(DIO_ReadPin(PINC3)==LOW)
			{
				Response=OFF_STATUS;
			}
			SPI_SendReceive(Response);
			break;
			case TV_STATUS:
			if(DIO_ReadPin(PIND7)==HIGH)
			{
				Response=ON_STATUS;
			}
			else if(DIO_ReadPin(PIND7)==LOW)
			{
				Response=OFF_STATUS;
			}
			SPI_SendReceive(Response);
			break;
			case FAN_STATUS:
			if(DIO_ReadPin(PIND6)==HIGH)
			{
				Response=ON_STATUS;
			}
			else if(DIO_ReadPin(PIND6)==LOW)
			{
				Response=OFF_STATUS;
			}
			SPI_SendReceive(Response);
			break;
			case ROOM1_TURN_ON:
			DIO_WritePin(PINC0,HIGH);
			break;
			case ROOM2_TURN_ON:
			DIO_WritePin(PINC1,HIGH);
			break;
			case ROOM3_TURN_ON:
			DIO_WritePin(PINC2,HIGH);
			break;
			case ROOM4_TURN_ON:
			DIO_WritePin(PINC3,HIGH);
			break;
			case TV_TURN_ON:
			DIO_WritePin(PIND7,HIGH);
			break;
			case FAN_TURN_ON:
			DIO_WritePin(PIND6,HIGH);
			break;

			case ROOM1_TURN_OFF:
			DIO_WritePin(PINC0,LOW);
			break;
			case ROOM2_TURN_OFF:
			DIO_WritePin(PINC1,LOW);
			break;
			case ROOM3_TURN_OFF:
			DIO_WritePin(PINC2,LOW);
			break;
			case ROOM4_TURN_OFF:
			DIO_WritePin(PINC3,LOW);
			break;
			case TV_TURN_OFF:
			DIO_WritePin(PIND7,LOW);
			break;
			case FAN_TURN_OFF:
			DIO_WritePin(PIND6,LOW);
			break;
		}
		
		
	}

}

