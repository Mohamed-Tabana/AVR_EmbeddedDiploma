/*
 * Timer_Services.h
 *
 * Created: 1/2/2023 12:12:45 AM
 *  Author: Tabana
 */ 


#ifndef TIMER_SERVICES_H_
#define TIMER_SERVICES_H_
#include "Timer.h"

void PWM_Init(void);
void PWM_Freq_KHZ(u16 freq);
void PWM_Freq_HZ(u16 freq);
void PWM_Duty(u16 duty);

void Timer1_SetInterruptTime_ms(u16 time, void (*LocalFptr)(void));
void Timer1_SetInterruptTime_us(u16 time, void (*LocalFptr)(void));
void Timer1_SetInterruptTime_s(u16 time, void (*LocalFptr)(void));
void PWM_Measure(u32* pfreq, u8* pduty);
void PWM_Measure2(u32* pfreq, u8* pduty);
//static void Func_ICU(void);

#endif /* TIMER_SERVICES_H_ */