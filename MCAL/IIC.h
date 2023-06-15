/*
 * IIC.h
 *
 * Created: 12/31/2022 6:32:18 PM
 *  Author: Tabana
 */ 


#ifndef IIC_H_
#define IIC_H_

#include "MemMap.h"
#include "StdTypes.h"
#include "Utils.h"

#define TW_MT_ARB_LOST 0x38
#define TW_START 0x08
#define TW_REP_START 0x10
#define TW_MT_SLA_ACK 0x18
#define TW_MT_DATA_ACK 0x28
#define TW_MR_DATA_NOT_ACK 0x58
#define TW_MR_SLA_NOT_ACK 0x48
#define TW_MT_SLA_NOT_ACK 0x20
#define TW_MT_DATA_NOT_ACK 0x30
#define TW_MR_DATA_ACK 0x50
#define TW_MR_SLA_ACK 0x40
#define W 0
#define R 0

void I2C_Init(void);
void TWIStart(void);
void TWIStop(void);
void TWIWrite(u8 DATA);
u8 TWIReadACK(void);
u8 TWIReadNACK(void);
u8 TWIGetStatus(void);






#endif /* IIC_H_ */