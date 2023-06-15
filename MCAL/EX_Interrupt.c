/*
 * EX_Interrupt.c
 *
 * Created: 11/26/2022 2:49:16 AM
 *  Author: Tabana
 */ 

#include "EX_Interrupt.h"

void (*INT0_Fptr)(void)=NULL_PTR;
void (*INT1_Fptr)(void)=NULL_PTR;
void (*INT2_Fptr)(void)=NULL_PTR;

ISR(INT0_vect)
{
	if (INT0_Fptr != NULL_PTR)
	{
		INT0_Fptr();
	}
}

ISR(INT1_vect)
{
	if (INT1_Fptr != NULL_PTR)
	{
		INT1_Fptr();
	}
}

ISR(INT2_vect)
{
	if (INT2_Fptr != NULL_PTR)
	{
		INT2_Fptr();
	}
	
}





void EXI_SetCallBack(ExInterruptSource_type INT_num,void (*Localptr)(void))
{
	switch(INT_num)
	{
		case EX_INT0:
		INT0_Fptr=Localptr;
			break;
		case EX_INT1:
		INT1_Fptr=Localptr;
			break;
		case EX_INT2:
		INT2_Fptr=Localptr;
			break;
	}
}


void EXI_TriggerEdge(ExInterruptSource_type INT_num,TriggerEdge_type trigger_edge)
{
		switch(INT_num)
		{
			case EX_INT0:
				switch(trigger_edge)
				{
					case LOW_Level_Trigger:
					
						CLR_BIT(MCUCR,ISC00);
						CLR_BIT(MCUCR,ISC01);
						break;
						
					case ANY_Logical_Change :
						SET_BIT(MCUCR,ISC00);
						CLR_BIT(MCUCR,ISC01);
						break;
					case Falling_Edge :
						CLR_BIT(MCUCR,ISC00);
						SET_BIT(MCUCR,ISC01);
						break;
					case Rising_Edge :
						SET_BIT(MCUCR,ISC00);
						SET_BIT(MCUCR,ISC01);
						break;						
				}	
			break;
			case EX_INT1:
				switch(trigger_edge)
				{
					case LOW_Level_Trigger:
					
					CLR_BIT(MCUCR,ISC10);
					CLR_BIT(MCUCR,ISC11);
					break;
					
					case ANY_Logical_Change :
					SET_BIT(MCUCR,ISC10);
					CLR_BIT(MCUCR,ISC11);
					break;
					case Falling_Edge :
					CLR_BIT(MCUCR,ISC10);
					SET_BIT(MCUCR,ISC11);
					break;
					case Rising_Edge :
					SET_BIT(MCUCR,ISC10);
					SET_BIT(MCUCR,ISC11);
					break;
				}
			break;
			case EX_INT2:
				switch(trigger_edge)
				{
					case Falling_Edge :
					CLR_BIT(MCUCSR,ISC2);
					break;
					case Rising_Edge :
					SET_BIT(MCUCSR,ISC2);
					break;
				}			
				break;
		}
}

void EXI_Enable(ExInterruptSource_type INT_num)
{
		switch(INT_num)
		{
			case EX_INT0:
			SET_BIT(GICR,INT0);
			break;
			case EX_INT1:
			SET_BIT(GICR,INT1);

			break;
			case EX_INT2:
			SET_BIT(GICR,INT2);
			break;
		}

}

void EXI_Disable(ExInterruptSource_type INT_num)
{
	switch(INT_num)
	{
		case EX_INT0:
		CLR_BIT(GICR,INT0);
		break;
		case EX_INT1:
		CLR_BIT(GICR,INT1);

		break;
		case EX_INT2:
		CLR_BIT(GICR,INT2);
		break;
	}
}