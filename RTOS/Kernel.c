/*
 * Kernel.c
 *
 * Created: 1/2/2023 1:13:46 AM
 *  Author: Tabana
 */ 
#include "Kernel_interface.h"
#include "LCD.h"
Task_type SystemTasks[TASK_NUM]={0};
	#define OK 1
	#define NOK 0
	#define RESUMED 1
	#define PAUSED 0
void RTOS_voidStart(void)
{
	Timer1_SetInterruptTime_ms(1,RTOS_voidScheduler);
	sei();
}

u8 RTOS_voidCreateTask(u8 copy_u8Priority, void (*Copy_pvTaskFunc)(void),u16 copy_u16Periodicity,u16 copy_u16FirstDelay)
{
	u8 Local_u8ErrorState =OK;
	if (Copy_pvTaskFunc != 0)
	{
		if (SystemTasks[copy_u8Priority].TaskFunc == 0)
		{
			SystemTasks[copy_u8Priority].periodicity=copy_u16Periodicity;
			SystemTasks[copy_u8Priority].TaskFunc=Copy_pvTaskFunc;
			SystemTasks[copy_u8Priority].status=RESUMED;
			SystemTasks[copy_u8Priority].FirstDelay=copy_u16FirstDelay;
		}
	}
	else
	{
		Local_u8ErrorState=NOK;
	}
	return Local_u8ErrorState;
}
void RTOS_voidScheduler(void)
{
	volatile static u32 Local_u16SystickCounter=0;
	Local_u16SystickCounter++;
	for (u8 Local_u8TaskCounter=0;Local_u8TaskCounter<TASK_NUM;Local_u8TaskCounter++)
	{
	if (SystemTasks[Local_u8TaskCounter].status == RESUMED)
	{
		if (SystemTasks[Local_u8TaskCounter].FirstDelay == 0)
		{
			if(SystemTasks[Local_u8TaskCounter].TaskFunc!=0)
			{
						SystemTasks[Local_u8TaskCounter].TaskFunc();
						LCD_SetCursor(1,0);
						LCD_WriteNumber(Local_u16SystickCounter);
						SystemTasks[Local_u8TaskCounter].FirstDelay = SystemTasks[Local_u8TaskCounter].periodicity-1;
			}
		}
		else
		{
			SystemTasks[Local_u8TaskCounter].FirstDelay--;
		}
	}
	}
}

void RTOS_voidSuspendTask(u8 copy_u8Priority)
{
	SystemTasks[copy_u8Priority].status=PAUSED;
}
void RTOS_voidResumeTask(u8 copy_u8Priority)
{
	SystemTasks[copy_u8Priority].status=RESUMED;
}

void RTOS_voidDeleteTask(u8 copy_u8Priority)
{
	SystemTasks[copy_u8Priority].TaskFunc=0;
}