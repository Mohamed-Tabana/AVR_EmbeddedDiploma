/*
 * EX_Interrupt.h
 *
 * Created: 11/26/2022 2:48:59 AM
 *  Author: Tabana
 */ 


#ifndef EX_INTERRUPT_H_
#define EX_INTERRUPT_H_
#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"
typedef enum
{
	LOW_Level_Trigger,
	ANY_Logical_Change,
	Falling_Edge,
	Rising_Edge
	
}TriggerEdge_type;

typedef enum
{
	EX_INT0,
	EX_INT1,
	EX_INT2
	
}ExInterruptSource_type;


void EXI_SetCallBack(ExInterruptSource_type INT_num,void (*Localptr)(void));


void EXI_TriggerEdge(ExInterruptSource_type INT_num,TriggerEdge_type trigger_edge);

void EXI_Enable(ExInterruptSource_type INT_num);

void EXI_Disable(ExInterruptSource_type INT_num);





#endif /* EX_INTERRUPT_H_ */