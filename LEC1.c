/*
void fun1()
{
			PORTB=0xFF;
			_delay_ms(1000);
			PORTB=0x00;
			_delay_ms(1000);
}

void fun2()
{
			PORTB=0xAA;
			_delay_ms(1000);
			PORTB=0x55;
			_delay_ms(1000);
}

void fun3()
{
			PORTB=0xCC;
			_delay_ms(1000);
			PORTB=0x33;
			_delay_ms(1000);
}
void fun4()
{
			PORTB=0xF0;
			_delay_ms(1000);
			PORTB=0x0F;
			_delay_ms(1000);
			
}
void Task1()
{
		for (int i=0;i<8;i++)
		{
			PORTB &=(1<<i);
			_delay_ms(500);
			PORTB=0xff;
		}
}
void Task2 ()
{
		for (int i=0;i<8;i++)
		{
		PORTB &=(1<<i);
		_delay_ms(500);
		PORTB=0xff;
		}
		for (int i=0;i<6;i++)
		{
			PORTB &=(1<<6-i);
			_delay_ms(500);
			PORTB=0xff;
		}
}
void Task3 ()
{
	for (int i=0;i<4;i++)
	{
		PORTB = (PORTB&(1<<i)) | (PORTB&(1<<7-i))  ;
		_delay_ms(500);
		PORTB=0xff;
	}
	for (int i=0;i<2;i++)
	{
		PORTB = (PORTB&(1<<2-i)) | (PORTB&(1<<5+i))  ;
		_delay_ms(500);
		PORTB=0xff;
	}
}
*/
