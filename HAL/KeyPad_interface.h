/*
 * KeyPad_interface.h
 *
 * Created: 11/5/2022 1:22:44 AM
 *  Author: Tabana
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#include "DIO_interface.h"
#include "KeyPad_cfg.h"

extern u8 KeyArray[ROWS][COLS];
extern u8 KEYPAD_GetKey(void);
extern void KEYPAD_Init();

#endif /* KEYPAD_INTERFACE_H_ */