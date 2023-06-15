/*
 * Kernel_private.h
 *
 * Created: 1/2/2023 1:14:18 AM
 *  Author: Tabana
 */ 


#ifndef KERNEL_PRIVATE_H_
#define KERNEL_PRIVATE_H_

typedef struct
{
	u32 periodicity;
	void(*TaskFunc)(void);
	u8 status;
	u16 FirstDelay;
	
}Task_type;




#endif /* KERNEL_PRIVATE_H_ */