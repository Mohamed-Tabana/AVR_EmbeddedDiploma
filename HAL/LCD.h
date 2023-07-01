/*
 * LCD.h
 *
 * Created: 10/28/2022 11:27:30 PM
 *  Author: Mohamed TABANA
 */ 


#ifndef LCD_H_
#define LCD_H_
#define F_CPU 8000000
#include "DIO_interface.h"
#include "avr/delay.h"
#include "DIO_interface.h"
#define _4_BIT 1
#define _8_BIT 2
/*********************pin cfg*******************************/
#define LCD_MODE _4_BIT

#define RS PINA1
#define EN PINA2

#define D7 PINA6
#define D6 PINA5
#define D5 PINA4
#define D4 PINA3

//#define RS PINA3
//#define EN PINA2
//
//#define D7 PINC7
//#define D6 PINC6
//#define D5 PINC5
//#define D4 PINB0
#define LCD_PORT PA

/**********************************************************/

void LCD_Init(void);
void LCD_writeInstruction(u8 ins);
void LCD_WriteData(u8 data);
void LCD_WriteNumber(s32 num);
void LCD_WriteNumber_4D(u16 num);
void LCD_Clear(void);
void LCD_WriteChar(u8 ch);
void LCD_WriteString(u8* str);

void LCD_WriteBinary(u8 num);
void LCD_WriteHex(u16 num);
void LCD_SetCursor(u8 line,u8 cell);
void LCD_createPattern(u8*pattern,u8 address);
void LCD_SetCursorClear(u8 line, u8 cell,u8 numOfCells);
void LCD_SetCursorClear(u8 line, u8 cell,u8 numOfCells);
void LCD_SetCursorWriteString(u8 line, u8 cell,u8* str);




#endif /* LCD_H_ */