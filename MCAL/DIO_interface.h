/*
 * DIO_interface.h
 *
 * Created: 10/21/2022 2:19:09 PM
 *  Author: Mohamed TABANA
 */ 




#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"

typedef enum{
	PA,
	PB,
	PC,
	PD
	}DIO_Port_Type;
typedef enum{
	OUTPUT,
	INFREE,
	INPULL
	}DIO_PinStatus_Type;
typedef enum{
	LOW,
	HIGH
	}DIO_PinVoltage_Type;

typedef enum{
	PINA0,
	PINA1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	TOTAL_PINS
}DIO_Pin_Type;

extern void DIO_Init(void);
extern void DIO_WritePin(DIO_Pin_Type pin,DIO_PinVoltage_Type vlot);
extern DIO_PinVoltage_Type DIO_ReadPin(DIO_Pin_Type pin);
extern void DIO_TogglePin(DIO_Pin_Type pin);
extern void DIO_WritePort(DIO_Port_Type port, u8 data);
extern u8 DIO_ReadPort(DIO_Port_Type port);

#endif /* DIO_INTERFACE_H_ */