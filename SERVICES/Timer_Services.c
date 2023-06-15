/*
 * Timer_Services.c
 *
 * Created: 1/2/2023 12:13:12 AM
 *  Author: Tabana
 */ 
#include "Timer_Services.h"
#include "DIO_interface.h"

void PWM_Init(void)
{
	TIMER1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8);
}
void PWM_Freq_KHZ(u16 freq)
{
	if (freq==0)
	{}
	else
	{
		u16 Ttotal=1000/freq;
		if(Ttotal>=1)
		ICR1=Ttotal-1;
		else
		ICR1=0;

	}
}
void PWM_Freq_HZ(u16 freq)
{
	if (freq==0)
	{}
	else
	{
		u16 Ttotal=1000000/freq;
		if(Ttotal>=1)
		ICR1=Ttotal-1;
		else
		ICR1=0;

	}
}
void PWM_Duty(u16 duty)
{
	u16 Ton= ((u32)duty * (ICR1+1)) /100;
	if(Ton>1)
	{
		OCR1A=Ton-1;
	}
	else
	OCR1A=0;
}

void Timer1_SetInterruptTime_ms(u16 time, void (*LocalFptr)(void))
{
	TIMER1_Init(TIMER1_CTC_OCRA_TOP_MODE,TIMER1_SCALER_8);
	
	OCR1A= ((u32)time*1000) -1;
	Timer1_OCA_SetCallBack(LocalFptr);
	Timer1_OCRA1Mode(OCRA_TOGGLE);
	Timer1_OCA_InterruptEnable();
	
}
void Timer1_SetInterruptTime_us(u16 time, void (*LocalFptr)(void))
{
	TIMER1_Init(TIMER1_CTC_OCRA_TOP_MODE,TIMER1_SCALER_8);
	OCR1A= (time) -1;
	Timer1_OCA_SetCallBack(LocalFptr);
	Timer1_OCA_InterruptEnable();
}
void Timer1_SetInterruptTime_s(u16 time, void (*LocalFptr)(void))
{
	TIMER1_Init(TIMER1_CTC_OCRA_TOP_MODE,TIMER1_SCALER_8);
	OCR1A= (time*1000000) -1;
	Timer1_OCA_SetCallBack(LocalFptr);
	Timer1_OCA_InterruptEnable();
}
void PWM_Measure(u32* pfreq, u8* pduty)
{
	u16 Ton,Toff;
	while(DIO_ReadPin(PIND6));
	while(!DIO_ReadPin(PIND6));
	TCNT1=0;
	while(DIO_ReadPin(PIND6));
	Ton=TCNT1;
	TCNT1=0;
	while(!DIO_ReadPin(PIND6));
	Toff=TCNT1;
	
	*pfreq=(u32) 1000000/((u32)Ton+Toff);
	*pduty=((u32) Ton/((u32)Ton+Toff))*100;
	
}
//void PWM_Measure2(u32* pfreq, u8* pduty);
//static void Func_ICU(void);