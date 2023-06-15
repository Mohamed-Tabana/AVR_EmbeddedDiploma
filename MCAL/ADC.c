/*
 * ADC.c
 *
 * Created: 11/18/2022 2:30:23 AM
 *  Author: Tabana
 */ 
#include "ADC.h"
u8 ADC_Flag=0;
void ADC_Init(ADC_VoltRef_type ref, ADC_Prescaler_type scaler)
{
	//PRESCALER
		ADCSRA&=0xF8; //0B11111000
		scaler|=0X07; //0B00000111
		ADCSRA|=scaler;
		
	//READ ADJUSTED 
	CLR_BIT(ADMUX,ADLAR);
	//VREF
	switch(ref)
	{
		case VREF_AREF:
			CLR_BIT(ADMUX,REFS0);
			CLR_BIT(ADMUX,REFS1);
			break;
		case VREF_VCC:
			SET_BIT(ADMUX,REFS0);
			CLR_BIT(ADMUX,REFS1);
			break;
		case VREF_256:
			SET_BIT(ADMUX,REFS0);
			SET_BIT(ADMUX,REFS1);
			break;	
	}
		//ADC Enable
		SET_BIT(ADCSRA,ADEN);

	
	
	
}
u16 ADC_Read(ADC_Channel_type ch)
{
	// select MUX 
	ADMUX&=0XE0;//11100000
	ch&=0X1F;
	ADMUX|=ch;
	
	//start Conversion 
	SET_BIT(ADCSRA,ADSC);
	
	
	//wait till end 
	while(READ_BIT(ADCSRA,ADSC));
	
	//get read 

	/*u16 adc=0;
	adc=(u16)ADCH<<8 | (u16)ADCL;*/ 
	return ADC;
}
void ADC_StartConversion(ADC_Channel_type ch)
{
	if (ADC_Flag==0)
	{
			// select MUX
			ADMUX&=0XE0;//11100000
			ch&=0X1F;
			ADMUX|=ch;
			
			//start Conversion
			SET_BIT(ADCSRA,ADSC);
			ADC_Flag=1;
	}

}
u16 ADC_GetRead()
{
	//wait till end 
	while(READ_BIT(ADCSRA,ADSC));	
	//get read 
	/*u16 adc=0;
	adc=(u16)ADCH<<8 | (u16)ADCL;*/ 
	ADC_Flag=0;
	return ADC;
}

u8 ADC_GetReadPeriodic(u16* pdata)
{
	//wait till end 
	if(!READ_BIT(ADCSRA,ADSC))
	{
		*pdata=ADC;
		ADC_Flag=0;

		return 1;	
	}
	return 0;
}


u16 ADC_ReadVolt(ADC_Channel_type ch)
{
	u16 adc=ADC_Read(ch);
	u16 volt=(adc*ADC_VREF)/1024;	
	return volt;
}

u16 ADC_ReadNoBlock()
{
	return ADC;
}