/*
 * TempF.h
 *
 * Created: 11/25/2022 1:31:05 PM
 *  Author: Tabana
 */ 


#ifndef TEMPF_H_
#define TEMPF_H_
#include "StdTypes.h"
#include "ADC.h"
void TempF_Init(void);
void TempF_Runnable(void);
u16 TempF_GetRead(void);





#endif /* TEMPF_H_ */