/*
 * SmartProgram.h
 *
 * Created: 12/28/2022 12:10:06 PM
 *  Author: Tabana
 */ 


#ifndef SMARTPROGRAM_H_
#define SMARTPROGRAM_H_

#include "LCD.h"
#include "ServoMotor.h"
#include "RGB.h"
void SERVO (u8 ang);
void LEDON (u32 led);
void LCD (u32 num);

typedef struct{
	u8* pdevice;
	void (*pfun)(u32);
}task_type;




u32 Smart_StringToNumber(u8*str);
u8 Smart_StringCompare(u8*str1,u8*str2);



#endif /* SMARTPROGRAM_H_ */