/*
 * EEPROM.c
 *
 * Created: 1/1/2023 5:09:41 PM
 *  Author: Tabana
 */ 
#include "EEPROM.h"
void EEPROM_writeByte(u8 uiAddress, u8 ucData)
{
	/* Wait for completion of previous write */
	while(READ_BIT(EECR,EEWE));
	/* Set up address and data registers */
	EEAR = uiAddress;
	EEDR = ucData;
	/* Write logical one to EEMWE */
	SET_BIT(EECR,EEMWE);
	/* Start EEPROM write by setting EEWE */
	SET_BIT(EECR,EEWE);
}
void EEPROM_writeString(u8 uiAddress, u8* ucData,u8 size)
{
	for(u8 i =0 ; i < size ;i++)
	{
		EEPROM_writeByte(uiAddress++,ucData[i]);
	}
}

u8 EEPROM_readByte(u8 uiAddress)
{
	/* Wait for completion of previous write */
	while(READ_BIT(EECR,EEWE));
	/* Set up address register */
	EEAR = uiAddress;
	/* Start EEPROM read by writing EERE */
	SET_BIT(EECR,EERE);
	/* Return data from data register */
	return EEDR;
}

u8 EEPROM_readString(u8 uiAddress, u8* ucData,u8 size)
{
	for(u8 i =0 ; i < size ;i++)
	{
		ucData[i]=EEPROM_readByte(uiAddress++);
	}
}