/*
 * IIC.c
 *
 * Created: 12/31/2022 6:32:05 PM
 *  Author: Tabana
 */ 
#include "IIC.h"
void I2C_Init(void)
{
	//bit rate
	TWBR= 72;
	//slave address - general call off
	TWAR=0x02;
	//ACK on - enable on 
	TWCR=0x44;
	TWSR=0x00;
	TWSR &= (~((1<<TWPS1)|(1<<TWPS0))); 
}

void TWIStart(void)
{
	//send start condition
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	//wait for TWINT flag to be set 
	while (!(TWCR & (1<<TWINT)));
}
void TWIStop(void)
{
	//send stop condition
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

void TWIWrite(u8 DATA)
{
	//put data on TWI Register
	TWDR = DATA;
	//send data
	TWCR = (1<<TWINT) | (1<<TWEN);
	//wait for TWINT flag to be set
	while (!(TWCR & (1<<TWINT)));
}

u8 TWIReadACK(void)
{
	//enable ACK
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	//wait for TWINT flag to be set
	while (!(TWCR & (1<<TWINT)));
	//Read DATA
	return TWDR;
}
u8 TWIReadNACK(void)
{
	
	TWCR = (1<<TWINT)|(1<<TWEN);
	//wait for TWINT flag to be set
	while (!(TWCR & (1<<TWINT)));
	//Read DATA
	return TWDR;
}
u8 TWIGetStatus(void)
{
	
	u8 status;
	status= TWSR & 0xF8;
	return status;
}
u8 I2C_SendByte(u8 SlaveAddress,u8 data)
{
	TWIStart();
	if (TWIGetStatus() != TW_START)
	return 0;
	TWIWrite(SlaveAddress<<1|W);
	if (TWIGetStatus() != TW_MT_SLA_ACK)
	return 0;
	TWIWrite(data);
	TWIStop();

}
u8 I2C_SendString(u8 SlaveAddress,u8* str)
{
	TWIStart();
	if (TWIGetStatus() != TW_START)
	return 0;
	TWIWrite(SlaveAddress<<1|W);
	if (TWIGetStatus() != TW_MT_SLA_ACK)
		return 0;
	for(u8 i=0;str[i];i++)
	{
		TWIWrite(str[i]);
		if(TWIGetStatus()!=TW_MT_DATA_ACK)
			return 0;
	TWIStop();
	}

}