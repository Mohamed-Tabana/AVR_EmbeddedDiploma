/*
 * SPI.h
 *
 * Created: 12/30/2022 1:52:34 PM
 *  Author: Tabana
 */ 


#ifndef SPI_H_
#define SPI_H_
#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"

typedef enum
{
	MASTER,
	SLAVE
	
}MasterSlave_type;

void SPI_Init(MasterSlave_type mode);

u8 SPI_SendReceive(u8 data);

void SPI_Send(u8 data);

u8 SPI_ReceivePeriodic(u8* data);
u8 SPI_Receive(void);
#endif /* SPI_H_ */