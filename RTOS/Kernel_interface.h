/*
 * Kernel_interface.h
 *
 * Created: 1/2/2023 1:14:38 AM
 *  Author: Tabana
 */ 


#ifndef KERNEL_INTERFACE_H_
#define KERNEL_INTERFACE_H_

#include "Timer_Services.h"
#include "Kernel_private.h"
#include "Kernel_cfg.h"

void RTOS_voidStart(void);
u8 RTOS_voidCreateTask(u8 copy_u8Priority, void (*Copy_pvTaskFunc)(void),u16 copy_u16Periodicity,u16 copy_u16FirstDelay);
void RTOS_voidScheduler(void);
void RTOS_voidSuspendTask(u8 copy_u8Priority);
void RTOS_voidResumeTask(u8 copy_u8Priority);
void RTOS_voidDeleteTask(u8 copy_u8Priority);

#endif /* KERNEL_INTERFACE_H_ */