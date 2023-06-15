/*
 * Calc.h
 *
 * Created: 11/5/2022 12:10:26 PM
 *  Author: Tabana
 */ 


#ifndef CALC_H_
#define CALC_H_

#include "StdTypes.h"
#include "LCD.h"
#include "KeyPad_interface.h"
s32 result(s32 num1,s32 num2,u8 sign);
void Calc_clearBuffer(void);
void CALC_Init(void);
void CALC_Runnable(void);






#endif /* CALC_H_ */