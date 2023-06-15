/*
 * StopWatchPROJ.c
 *
 * Created: 10/21/2022 3:45:37 PM
 *  Author: moham
 */ 
/*
 * ALLinOne.c
 *
 * Created: 10/15/2022 1:27:40 AM
 * Author : Mohamed
 */ 
/*
#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "SEGMENT.h"
#define F_CPU 8000000
#include <util/delay.h>
#include "SEGMENT.h"
#include "DIO_interface.h"

int main(void)
{
	DDRA=0xFF;
	DDRB=0xFF;
	DDRD=0x00;
	DDRC=0xFF;
	PORTD=0xFF;
	PORTC=0x00;
	u8 x=0;
	segment_print_mlx(x);
	u8 flag=0;
	u8 flagMOD=0;
	while (1)
	{

		if (flagMOD==0)
		{
				if (flag==0)
				{
					x++;
					if (x==99)
						
						for(int i=0;i<200;i++)
						{
							segment_print_mlx(x);
							SET_BIT(PORTC,5);
							
						}
						CLR_BIT(PORTC,5);
					if (x==100)
						x=0;
						

				}
				if (flag==1)
				{
	
				}
				for (int i=0;i<300;i++)
				{
					if(!READ_BIT(PIND,4))
					{
						flagMOD=!flagMOD;
						flag=0;
						while(!READ_BIT(PIND,4))
						{
							segment_print_mlx(x);
						}
					}
					if(!READ_BIT(PIND,3))
					{
						flag=!flag;
			
						while(!READ_BIT(PIND,3))
						{
							segment_print_mlx(x);
						}
					}
					if(!READ_BIT(PIND,2))
					{
						x=0;
						while(!READ_BIT(PIND,2))
						{segment_print_mlx(x);}
					}
					segment_print_mlx(x);

				}
			}
			else
			{
				
				for (int i=0;i<300;i++)
				{
					if(!READ_BIT(PIND,4))
					{
						flagMOD=0;
						while(!READ_BIT(PIND,4))
						{segment_print_mlx(x);}
					}
					if(!READ_BIT(PIND,2))
					{
						x=x+10;
						if (x>=100)
						x=0+x%10;
						while(!READ_BIT(PIND,2))
						{segment_print_mlx(x);}

					}
					if(!READ_BIT(PIND,3))
					{
						x++;
						if (x==255)
						x=99;
						while(!READ_BIT(PIND,3))
						{segment_print_mlx(x);}
					}
					segment_print_mlx(x);
				}
			}
	}
}
*/