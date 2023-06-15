/*
 * SPI.c
 *
 * Created: 12/30/2022 1:52:22 PM
 *  Author: Tabana
 */ 
#include "SPI.h"
void SPI_Init(MasterSlave_type mode) 
{
	//master slave choose
	switch(mode)
	{
		case MASTER:
		SET_BIT(SPCR,MSTR);
		break;
		case SLAVE:
		CLR_BIT(SPCR,MSTR);
		break;
	}
	//ENABLE
	SET_BIT(SPCR,SPE);
}

u8 SPI_SendReceive(u8 data)
{
	SPDR=data;
	while(!READ_BIT(SPSR,SPIF));
	return SPDR;
}
void SPI_Send(u8 data)
{
	SPDR=data;
}
u8 SPI_ReceivePeriodic(u8* data)
{
	if (READ_BIT(SPSR,SPIF))
	{
		*data=SPDR;
		return 1;
	}
	return 0;
}
u8 SPI_Receive(void)
{
	return SPDR;
}

