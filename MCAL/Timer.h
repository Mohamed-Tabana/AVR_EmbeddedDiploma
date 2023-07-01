/*
 * Timer.h
 *
 * Created: 12/9/2022 12:52:54 AM
 *  Author: Tabana
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "MemMap.h"
#include "StdTypes.h"
#include "Utils.h"
/************************************** Timer0 ********************************************************/

typedef enum {
	TIMER0_STOP,
	TIMER0_SCALER_1,
	TIMER0_SCALER_8,
	TIMER0_SCALER_64,
	TIMER0_SCALER_256,
	TIMER0_SCALER_1024,
	TIMER0_EXTERNAL_FALLING, // FOR TIMER0 T0 PIN
	TIMER0_EXTERNAL_RISING	 // FOR TIMER0 T1 PIN
	}Timer0Scaler_type;
typedef enum {
	TIMER0_NORMAL_MODE,
	TIMER0_PHASECORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FASTPWM_MODE,
}Timer0Mode_type;
typedef enum {
	OC0_DISCONNECTED,
	OC0_TOGGLE,
	OC0_NON_INVERTING,
	OC0_INVERTING,
 }OC0Mode_type;
 
void TIMER0_Init(Timer0Mode_type timerMode,Timer0Scaler_type scaleMode);
void TIMER0_OC0Mode(OC0Mode_type mode);
void TIMER0_OC_InterruptEnable(void);
void TIMER0_OC_InterruptDisable(void);
void TIMER0_OV_InterruptEnable(void);
void TIMER0_OV_InterruptDisable(void);
void TIMER0_OV_SetCallBack(void (*Local_fptr)(void));

/************************************** Timer1 ********************************************************/
typedef enum {
	TIMER1_STOP,
	TIMER1_SCALER_1,
	TIMER1_SCALER_8,
	TIMER1_SCALER_64,
	TIMER1_SCALER_256,
	TIMER1_SCALER_1024,
	TIMER1_EXTERNAL_FALLING, // FOR TIMER1 T1 PIN
	TIMER1_EXTERNAL_RISING	 // FOR TIMER1 T1 PIN
}Timer1Scaler_type;
typedef enum {
	TIMER1_NORMAL_MODE,
	TIMER1_CTC_ICR_TOP_MODE,
	TIMER1_CTC_OCRA_TOP_MODE,
	TIMER1_FASTPWM_ICR_TOP_MODE,
	TIMER1_FASTPWM_OCRA_TOP_MODE,
}Timer1Mode_type;
typedef enum
{
	OCRA_DISCONNECTED=0,
	OCRA_TOGGLE,
	OCRA_NON_INVERTING,
	OCRA_INVERTING

}OC1A_Mode_type;

typedef enum
{
	OCRB_DISCONNECTED=0,
	OCRB_TOGGLE,
	OCRB_NON_INVERTING,
	OCRB_INVERTING

}OC1B_Mode_type;

typedef enum {
	FALLING=0,
	RISING=1
}ICU_EDGE_type;



void TIMER1_Init(Timer1Mode_type mode,Timer1Scaler_type scaler);
void Timer1_Stop(void);

void Timer1_OCRA1Mode(OC1A_Mode_type oc1a_mode);
void Timer1_OCRB1Mode(OC1B_Mode_type oc1b_mode);

void Timer1_ICU_InterruptEnable(void);
void Timer1_ICU_InterruptDisable(void);

void Timer1_OVF_InterruptEnable(void);
void Timer1_OVF_InterruptDisable(void);

void Timer1_OCA_InterruptEnable(void);
void Timer1_OCA_InterruptDisable(void);

void Timer1_OCB_InterruptEnable(void);
void Timer1_OCB_InterruptDisable(void);

void Timer1_ICU_SelectEdge(ICU_EDGE_type copy_eEdgeType);

void Timer1_OVF_SetCallBack(void(*LocalFptr)(void));
void Timer1_OCA_SetCallBack(void(*LocalFptr)(void));
void Timer1_OCB_SetCallBack(void(*LocalFptr)(void));
void Timer1_ICU_SetCallBack(void(*LocalFptr)(void));



#endif /* TIMER_H_ */