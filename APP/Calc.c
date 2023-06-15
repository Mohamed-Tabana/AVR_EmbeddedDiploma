/*
 * Calc.c
 *
 * Created: 11/5/2022 12:10:16 PM
 *  Author: Tabana
 */ 
#include "Calc.h"

void CALC_Init(void)
{
	/*NO THING HERE*/
	LCD_WriteString("Calculator");
	_delay_ms(1000);
	LCD_Clear();

}

u8 k,flagNUM=0,sign='.',flag=0,flagSign1=0,flagSign2=0;
s32 num1=0, num2=0, res=0;
void CALC_Runnable(void)
{
	k=KEYPAD_GetKey();
	if(k>='0' && k<='9')
	{
		if (flag==0 && res!=0)
		{
			LCD_SetCursorClear(2,0,16);
			LCD_SetCursorClear(1,0,16);
			LCD_SetCursor(1,0);
			num1=0;
			num2=0;
			res=0;
			flag=1;
		}
		if (flagNUM==1)
		{
			LCD_WriteChar(k);
			num2=num2*10+(k-'0');		
		}
		else
		{
			LCD_WriteChar(k);
			num1=num1*10+(k-'0');
		}
	}
	else if (k == '+' || k == '-' || k == '*' || k == '/')
	{
		if(num2 !=0)
		{
			flag=1;
			LCD_SetCursorClear(2,0,16);
			LCD_SetCursorClear(1,0,16);
			LCD_SetCursor(1,0);
			num1=res;
			res=0;
			num2=0;
			LCD_WriteNumber(num1);
		}
		
		flagNUM=1;
		LCD_WriteChar(k);
		if (num1==0 && k=='-')
		{
			flagSign1=1;
			flagNUM=0;
		}
		if (num2==0 && k=='-' && (sign=='-'||sign=='/'||sign=='*'||sign=='+'))
		{
			flagSign2=1;
		}
		if(sign=='.')
			sign=k;
	}
	else if (k == '=')
	{
		if(sign== '/' && (num2==0))
		{
			LCD_SetCursor(2,0);
			LCD_WriteString("!! DIVISION BY 0");
			res=0;
		}
		else
		{
			if (flagSign1)
				num1*=-1;
			if (flagSign2)
				num2*=-1;
			
			res=result(num1,num2,sign);
			LCD_SetCursor(2,0);
			LCD_WriteNumber(res);
		}
		flagNUM=0;
		flag=0;
		flagSign1=0;
		flagSign2=0;
		sign='.';
	}
	else if (k == 'C')
	{
		res=0;
		num1=0;
		num2=0;
		flag=0;
		flagNUM=0;
		flagSign1=0;
		flagSign2=0;
		LCD_Clear();
	}
}
s32 result(s32 num1,s32 num2,u8 sign){
	switch(sign)
	{
	case'+':
		return num1+num2;
	case'-':
		return num1-num2;
	case'/':
		return num1/num2;
	case'*':
		return num1*num2;
	}
 }


