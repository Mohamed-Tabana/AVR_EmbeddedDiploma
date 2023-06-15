/*
 * TempF.c
 *
 * Created: 11/25/2022 1:30:51 PM
 *  Author: Tabana
 */ 
#include "TempF.h"


static u16 TEMPF=0;
static u16 arr [10]={0};
static u8 i=0;
void TempF_Init(void)
{	
	for(u8 j=0;j<10;j++)
	{
		arr[j]=Temp_Read();
	}	
}
void TempF_Runnable(void)
{
	
		if (i==10)
		{
			i=0;
		}
		
	arr[i]=Temp_Read();
	i++;
 
	TEMPF=0;
	for(u8 j=0;j<10;j++)
	{
		TEMPF+=arr[j];
	}
	TEMPF=TEMPF/10;
}
u16 TempF_GetRead(void)
{
	return TEMPF;
}
