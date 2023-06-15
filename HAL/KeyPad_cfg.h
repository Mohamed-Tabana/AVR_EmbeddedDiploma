/*
 * KeyPad_cfg.h
 *
 * Created: 11/5/2022 1:23:10 AM
 *  Author: Tabana
 */ 
#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#include "DIO_interface.h"

#define ROWS 4
#define COLS 4 

#define FIRST_OUTPUT PINA4
#define FIRST_INPUT  PINC1
#define NO_KEY		 'T'

#ifdef KEYPAD_PROG

u8 KeyArray[ROWS][COLS]=
	{ 
		{'7','8','9','A'},
		{'4','5','6','B'},
		{'1','2','3','D'},
		{'C','0','=','E'}
	};
#endif

#endif /* KEYPAD_CFG_H_ */