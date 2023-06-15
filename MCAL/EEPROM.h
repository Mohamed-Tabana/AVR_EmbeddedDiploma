/*
 * EEPROM.h
 *
 * Created: 1/1/2023 5:09:56 PM
 *  Author: Tabana
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_
#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"

void EEPROM_writeByte(u8 uiAddress, u8 ucData);
void EEPROM_writeString(u8 uiAddress, u8* ucData,u8 size);
u8 EEPROM_readByte(u8 uiAddress);
u8 EEPROM_readString(u8 uiAddress, u8* ucData,u8 size);
#endif /* EEPROM_H_ */