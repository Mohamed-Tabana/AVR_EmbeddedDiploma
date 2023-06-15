/*
 * LCD.c
 *
 * Created: 10/28/2022 11:27:16 PM
 *  Author: Mohamed TABANA
 */ 
#include "LCD.h"
#if LCD_MODE == _8_BIT
void LCD_writeInstruction(u8 ins){
	DIO_WritePin(RS,LOW);
	DIO_WritePort(LCD_PORT,ins);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
void LCD_Init(void){
	_delay_ms(50);
	LCD_writeInstruction(0x38); // screen on - 8 bit mode
	LCD_writeInstruction(0x0C); // screen FULL - Cursor OFF (0F/0E)
	LCD_writeInstruction(0x01); // clear Screen
	_delay_ms(1);
	LCD_writeInstruction(0x06); // SHIFT TO RIGHT - NO SHIFT
}
#elif LCD_MODE == _4_BIT
void LCD_writeInstruction(u8 ins){
	DIO_WritePin(RS,LOW);
	DIO_WritePin(D7,READ_BIT(ins,7));
	DIO_WritePin(D6,READ_BIT(ins,6));
	DIO_WritePin(D5,READ_BIT(ins,5));
	DIO_WritePin(D4,READ_BIT(ins,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,READ_BIT(ins,3));
	DIO_WritePin(D6,READ_BIT(ins,2));
	DIO_WritePin(D5,READ_BIT(ins,1));
	DIO_WritePin(D4,READ_BIT(ins,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(D7,READ_BIT(data,7));
	DIO_WritePin(D6,READ_BIT(data,6));
	DIO_WritePin(D5,READ_BIT(data,5));
	DIO_WritePin(D4,READ_BIT(data,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,READ_BIT(data,3));
	DIO_WritePin(D6,READ_BIT(data,2));
	DIO_WritePin(D5,READ_BIT(data,1));
	DIO_WritePin(D4,READ_BIT(data,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
void LCD_Init(void){
	_delay_ms(50);
	LCD_writeInstruction(0x02);
	LCD_writeInstruction(0x28); // screen on - 8 bit mode
	LCD_writeInstruction(0x0C); // screen FULL - Cursor OFF (0F/0E)
	LCD_writeInstruction(0x01); // clear Screen
	_delay_ms(1);
	LCD_writeInstruction(0x06); // SHIFT TO RIGHT - NO SHIFT
}
#endif

void LCD_Clear(void){
	LCD_writeInstruction(0x01);
}

void LCD_WriteChar(u8 ch)
{
	LCD_WriteData(ch);
}
void LCD_WriteNumber(s32 num)
{
	u8 flag=0;
	u8 digit[8];
	u8 i;
	if(num<0)
	{
		flag=1;
	}
	if(num==0)
	{
		LCD_WriteChar('0');
	}
	if(flag==1){
		num=num*-1;
	}
	for(i=0;num;i++)
	{
	digit[i] =num%10+'0';
	num=num/10;
	}
	if(flag==1)
	{
		LCD_WriteChar('-');
	}
	for(;i>0;i--)
	{
		LCD_WriteChar(digit[i-1]);
	}
}
void LCD_WriteBinary(u8 num)
{
	LCD_WriteChar('0');
	LCD_WriteChar('b');
	for(u8 i =0;i<8;i++)
	{
		LCD_WriteNumber( (num>>(7-i)) & 1);
	}
}
void LCD_WriteHex(u16 num)
{
	u8 Remainder[8];
	u8 i=0;
	for(i=0;num !=0;i++)
	{
		if(num%16 >9)
		{
			Remainder[i]=((num%16)-10)+'A';
		}
		else
		{
			Remainder[i]=num%16;
		}
		num=num/16;
	}
	LCD_WriteChar('0');
	LCD_WriteChar('x');
	for(;i>0;i--)
	{
		if(Remainder[i-1]<10)
		{
		LCD_WriteNumber(Remainder[i-1]);
		}
		else
		{
		LCD_WriteChar(Remainder[i-1]);
		}
	}
	

}
void LCD_SetCursor(u8 line,u8 cell)
{
	if(line==0)
	{
		LCD_writeInstruction(0x80 | cell);
	}
	else if(line==1)
	{
		LCD_writeInstruction(0x80 | 0x40 |cell);
	}
	
}
void LCD_WriteString(u8* str)
{
	for(u8 i=0;str[i];i++)
	{
		LCD_WriteChar(str[i]);
	}
}
void LCD_WriteNumber_4D(u16 num)
{
	LCD_WriteNumber((num%10000)/1000);
	LCD_WriteNumber((num%1000)/100);
	LCD_WriteNumber((num%100)/10);
	LCD_WriteNumber((num%10)/1);
}
void LCD_createPattern(u8* pattern,u8 address)
{
	LCD_writeInstruction(0x40|(address*8));
	for(u8 i=0 ;i<8;i++)
	{
	LCD_WriteData(pattern[i]);
	}
	LCD_writeInstruction(0x80);
}
void LCD_SetCursorClear(u8 line, u8 cell,u8 numOfCells)
{
	LCD_SetCursor(line,cell);
	for(u8 i=0;i<numOfCells;i++)
	{
		LCD_WriteChar(' ');
	}
	LCD_SetCursor(line,cell);
}
void LCD_SetCursorWriteString(u8 line, u8 cell,u8* str)
{
	LCD_SetCursor(line,cell);
	LCD_WriteString(str);
}