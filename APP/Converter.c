/*
 * Converter.c
 *
 * Created: 11/5/2022 3:31:14 PM
 *  Author: Mohamed TABANA
 */ 
/*

#include "Converter.h"

u8 t = NO_KEY,f = NO_KEY, k = NO_KEY;
s32 num = 0;

void Converter_Runnable(void)
{
	LCD_SetCursorClear(1,0,16);
	LCD_WriteString("Convert From");
	LCD_SetCursorClear(2,0,16);
	LCD_WriteString("1:D  2:B  3:H");
	while(f == NO_KEY)
	{
		f=KEYPAD_GetKey();
	}
	LCD_SetCursorClear(1,0,16);
	LCD_WriteString("Convert To ");
	LCD_SetCursorClear(2,0,16);
	LCD_WriteString("1:D  2:B  3:H");
	while(t == NO_KEY)
	{
		t=KEYPAD_GetKey();
	}
	
	if (f==t)
	{
		LCD_SetCursorClear(2,0,16);
		LCD_SetCursorClear(1,0,16);
		LCD_WriteString("CAN't CONVERT SAME TYPE");
		f=NO_KEY;
		t=NO_KEY;
		_delay_ms(500);
		
	}
	LCD_SetCursorClear(2,0,16);
	LCD_SetCursorClear(1,0,16);
	while(f==DECIMAL && t== BINARY)
	{
		LCD_SetCursorClear(1,0,16);
		LCD_WriteString("DEC:");
		LCD_SetCursorClear(2,0,16);
		LCD_WriteString("BIN:");
		LCD_SetCursor(1,4);
		while(k != '=')
		{
			k=KEYPAD_GetKey();
			
			if ((k>='0')&&(k<='9'))
			{
				LCD_WriteChar(k);
				num=num*10+(k-'0');
				k=NO_KEY;
			}
		}
		LCD_SetCursor(2,4);
		LCD_WriteBinary(num);
		k=NO_KEY;
		while(k == NO_KEY)
		{
		k=KEYPAD_GetKey();
		f=NO_KEY;
		t=NO_KEY;
		num=0;
		

		}
		
	}
	

	if(f==DECIMAL && t== HEXA)
	{
		
		LCD_SetCursorClear(1,0,16);
		LCD_WriteString("DEC:");
		LCD_SetCursorClear(2,0,16);
		LCD_WriteString("HEX:");
		LCD_SetCursor(1,4);
		while(k != '=')
		{
			k=KEYPAD_GetKey();
			
			if ((k>='0')&&(k<='9'))
			{
				LCD_WriteChar(k);
				num=num*10+(k-'0');
				k=NO_KEY;
			}
		}
		LCD_SetCursor(2,4);
		LCD_WriteHex(num);
		k=NO_KEY;
		while(k == NO_KEY)
		{
			k=KEYPAD_GetKey();
			f=NO_KEY;
			t=NO_KEY;
			num=0;
		}	
	}
	if(f==BINARY && t== DECIMAL)
	{
				LCD_SetCursorClear(1,0,16);
				LCD_WriteString("BIN:0b");
				LCD_SetCursorClear(2,0,16);
				LCD_WriteString("DEC:");
				LCD_SetCursor(1,6);
				while(k != '=')
				{
					k=KEYPAD_GetKey();
					
					if ((k>='0')&&(k<='9'))
					{
						LCD_WriteChar(k);
						num=num*10+(k-'0');
						k=NO_KEY;
					}
				}
				LCD_SetCursor(2,4);
				Converter_BinaryDEC(num);
				k=NO_KEY;
				while(k == NO_KEY)
				{
					k=KEYPAD_GetKey();
					f=NO_KEY;
					t=NO_KEY;
					num=0;
				}
		
	}
	if(f==BINARY && t== HEXA)
	{
				LCD_SetCursorClear(1,0,16);
				LCD_WriteString("BIN:0b");
				LCD_SetCursorClear(2,0,16);
				LCD_WriteString("DEC:");
				LCD_SetCursor(1,6);
				while(k != '=')
				{
					k=KEYPAD_GetKey();
							
					if ((k>='0')&&(k<='9'))
					{
						LCD_WriteChar(k);
						num=num*10+(k-'0');
						k=NO_KEY;
					}
				}
				LCD_SetCursor(2,4);
				Converter_BinaryHEX(num);
				k=NO_KEY;
				while(k == NO_KEY)
				{
					k=KEYPAD_GetKey();
					f=NO_KEY;
					t=NO_KEY;
					num=0;
						}
	}
	if(f==HEXA && t== DECIMAL)
	{
			LCD_SetCursorClear(1,0,16);
			LCD_WriteString("HEX:0x");
			LCD_SetCursorClear(2,0,16);
			LCD_WriteString("DEC:");
			LCD_SetCursor(1,6);
			s32 base=1;
			u8 i=0;
			u8 arr[4];
				while(k != '=')
				{
					k=KEYPAD_GetKey();
									
					if(k >= '0' && k <= '9')
					{
						arr[i++]=k;
						LCD_WriteChar(k);
						k=NO_KEY;

					}
					else if(k >= 'A' && k <= 'F')
					{
						arr[i++]=k;
						LCD_WriteChar(k);
						k=NO_KEY;
					}
									
				}
				i--;
				for(u8 j =0;j<=i;j++)
				{
					if(arr[i-j]>= '0' && arr[i-j] <= '9')
					{
						num = num +((arr[i-j] - 48) * base);
						base *= 16;
					}
					else if(arr[i-j] >= 'A' && arr[i-j] <= 'F')
					{
						num = num + ((arr[i-j] - 55) * base);
						base *= 16;
					}
				}
			LCD_SetCursor(2,4);
			LCD_WriteNumber(num);
			k=NO_KEY;
			while(k == NO_KEY)
			{
				k=KEYPAD_GetKey();
				f=NO_KEY;
				t=NO_KEY;
				num=0;
			}
		
	}
	if(f==HEXA && t== BINARY)
	{
		LCD_SetCursorClear(1,0,16);
		LCD_WriteString("HEX:0x");
		LCD_SetCursorClear(2,0,16);
		LCD_WriteString("BIN:");
		LCD_SetCursor(1,6);
		s32 base=1;
		u8 arr[4];
		u8 i =0;
		while(k != '=')
		{
			k=KEYPAD_GetKey();
						
			if(k >= '0' && k <= '9')
			{
				arr[i++]=k;
				LCD_WriteChar(k);
				k=NO_KEY;

			}
			else if(k >= 'A' && k <= 'F')
			{
				arr[i++]=k;
				LCD_WriteChar(k);
				k=NO_KEY;
			}
						
		}
		i--;
		for(u8 j =0;j<=i;j++)
		{
			if(arr[i-j]>= '0' && arr[i-j] <= '9')
			{
				num = num +((arr[i-j] - 48) * base);
				base *= 16;
			}
			else if(arr[i-j] >= 'A' && arr[i-j] <= 'F')
			{
				num = num + ((arr[i-j] - 55) * base);
				base *= 16;
			}
		}
		LCD_SetCursor(2,4);
		LCD_WriteBinary(num);
		k=NO_KEY;
		while(k == NO_KEY)
		{
			k=KEYPAD_GetKey();
			f=NO_KEY;
			t=NO_KEY;
			num=0;
		}
}
	}

void Converter_BinaryDEC(s32 num){
	u8 reminder,result=0,base=1;
	while(num!=0)
	{
			reminder=num%10;
			result=result+reminder*base;
			num=num/10;
			base=base*2;
	}
	LCD_WriteNumber(result);
}
void Converter_BinaryHEX(s32 num){
	u8 reminder,result=0,base=1;
	while(num!=0)
	{
		reminder=num%10;
		result=result+reminder*base;
		num=num/10;
		base=base*2;
	}
	LCD_WriteHex(result);
}

Converter_HEXDEC(num){
	
}
Converter_HEXBIN(num){
	
}
	

*/
