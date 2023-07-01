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

/**
* interrupt setters 
*/

// Limited to 65 ms, can be fixed as the function with seconds later
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
typedef void (*Pfunc)(void);
volatile Pfunc Global_pfTimerPointer;
static u32 NoOfOverFlow =0;

static void Timer_Func()
{
	static u32 counter=0;
	counter++;
	if (NoOfOverFlow == counter)
	{
		Global_pfTimerPointer();
		counter=0;

	}
}

void Timer1_SetInterruptTime_s(u16 time, void (*LocalFptr)(void))
{
	Global_pfTimerPointer=LocalFptr;
	
	TIMER1_Init(TIMER1_CTC_OCRA_TOP_MODE,TIMER1_SCALER_8);
	OCR1A= 999;
	NoOfOverFlow= time*1000;
	Timer1_OCA_SetCallBack(Timer_Func);
	Timer1_OCA_InterruptEnable();
	
}

/*
* measure PWM
*/
// PWM on PIND6
void PWM_Measure(u32* pfreq, u8* pduty)
{
	u32 Ton,Toff;
	while(DIO_ReadPin(PIND6));
	while(!DIO_ReadPin(PIND6));
	TCNT1=0;
	while(DIO_ReadPin(PIND6));
	Ton=TCNT1;
	TCNT1=0;
	while(!DIO_ReadPin(PIND6));
	Toff=TCNT1;
	
	*pfreq=(u32) 1000000/((u32)Ton+Toff);
	*pduty=((u32) Ton*100/((u32)Ton+Toff));
	
}
static volatile u32 t1=0,t2=0,t3=0,flag=0;
static void Func_ICU(void)
{
	if (flag==0)
	{
		t1=ICR1;
		Timer1_ICU_SelectEdge(FALLING);
		flag=1;
	}
	else if (flag==1)
	{
		t2=ICR1;
		Timer1_ICU_SelectEdge(RISING);
		flag=2;
	}
	else if (flag==2)
	{
		t3=ICR1;
		Timer1_ICU_InterruptDisable();
		flag=3;
		
	}

}

void PWM_Measure2(u32* pfreq, u8* pduty)
{
	TCNT1=0;
	Timer1_ICU_SetCallBack(Func_ICU );
	Timer1_ICU_SelectEdge(RISING);
	Timer1_ICU_InterruptEnable();
	flag=0;
	while (flag<3);
	u32 Ton=0,Toff=0;
	Ton=t2-t1;
	Toff=t3-t2;
	*pfreq=(u32)1000000  /((u32)Ton+Toff);
	*pduty=((u32)Ton*100)/((u32) Ton+Toff);
}
