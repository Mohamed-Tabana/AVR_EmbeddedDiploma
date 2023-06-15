/*
 * SmartHome_Master.c
 *
 * Created: 1/6/2023 9:17:43 PM
 *  Author: Tabana
 */ 


#include "SmartHome_Master.h"
//MASTER
u8 MODE_Current=MODE_NO;
u8 Fault_Counter=0;
u8 Menu_State=MAIN_MENU;
u8 temperature=0;
u8 TimeOut_FLAG=0;

void SmartHome_Master_Init(void)
{
	DIO_Init();
	LCD_Init();
	KEYPAD_Init();
	ADC_Init(VREF_VCC,ADC_SCALER_64);
	SPI_Init(MASTER);
	sei();
	//RGB_Init();
	//	UART_Init();
	//SPI_Init(MASTER);
	//	TempF_Init();
}
void SmartHome_Master_Runnable(void)
{

	u8 KEY=NO_KEY;
	if (EEPROM_readByte(NVM_PASS_ADMIN_FB) == 0xFF || EEPROM_readByte(NVM_PASS_Guest_FB) == 0xFF)
	{
		/***ADMIN pass***/
		
		u8 PASSWORD_ADMIN[PASS_Size]={0};
		u8 PASSWORD_ADMIN_Byte=0;
		LCD_SetCursor(0,0);
		LCD_WriteString("Set PASS ADMIN");
		LCD_SetCursor(1,0);
		LCD_WriteString("PASS:");
		for (u8 i = 0 ; i<PASS_Size ;i++)
		{
			
			while(KEY ==NO_KEY)
			{
				KEY=KEYPAD_GetKey();
			}
			PASSWORD_ADMIN[i]=(KEY -'0');
			PASSWORD_ADMIN_Byte=PASSWORD_ADMIN_Byte*10 +PASSWORD_ADMIN[i];
			LCD_WriteChar(KEY);
			KEY=NO_KEY;
		}
		EEPROM_writeString(NVM_PASS_ADMIN_FB,PASSWORD_ADMIN,PASS_Size);
		EEPROM_writeByte(NVM_PASS_ADMIN_SET,0);
		/***guest pass***/
		LCD_Clear();
		KEY=NO_KEY;
		u8 PASSWORD_Guest[PASS_Size]={0};
		u8 PASSWORD_Guest_Byte=0;
		LCD_SetCursor(0,0);
		LCD_WriteString("Set PASS Guest");
		LCD_SetCursor(1,0);
		LCD_WriteString("PASS:");
		for (u8 i = 0 ; i<PASS_Size ;i++)
		{
			
			while(KEY ==NO_KEY)
			{
				KEY=KEYPAD_GetKey();
			}
			PASSWORD_Guest[i]=(KEY -'0');
			PASSWORD_Guest_Byte=PASSWORD_Guest_Byte*10 +PASSWORD_Guest[i];
			LCD_WriteChar(KEY);
			KEY=NO_KEY;
		}
		EEPROM_writeString(NVM_PASS_Guest_FB,PASSWORD_Guest,PASS_Size);
		EEPROM_writeByte(NVM_PASS_Guest_SET,0);
	}
	
	while (1)
	{

		while (MODE_Current == MODE_NO)
		{
			u8 PASSWORD_ADMIN_Entered[PASS_Size]={0};
			u8 PASSWORD_Guest_Entered[PASS_Size]={0};
			u8 PASSWORD_ADMIN_Actual[PASS_Size]={0};
			u8 PASSWORD_Guest_Actual[PASS_Size]={0};
			LCD_Clear();
			LCD_SetCursor(0,0);
			LCD_WriteString("Choose The Mode:");
			LCD_SetCursor(1,0);
			LCD_WriteString("1:ADMIN 2:Guest");
			while(KEY ==NO_KEY)
			{
				KEY=KEYPAD_GetKey();
			}
			// if key not admin or guest
			if (KEY-'0' !=MODE_ADMIN &&  KEY-'0' !=MODE_Guest  )
			{
				continue;
			}
			switch (KEY-'0')
			{
				
				case MODE_ADMIN :
				while (MODE_Current != MODE_ADMIN)
				{
					KEY=NO_KEY;
					LCD_Clear();
					LCD_SetCursor(0,0);
					LCD_WriteString("Enter The Password:");
					LCD_SetCursor(1,0);
					LCD_WriteString("PASS:");
					//To Take Password
					for (u8 i=0 ;i<PASS_Size; i++)
					{
						while(KEY ==NO_KEY)
						{
							KEY=KEYPAD_GetKey();
						}
						
						PASSWORD_ADMIN_Entered[i]=(KEY -'0');
						LCD_WriteChar(KEY);
						KEY=NO_KEY;
					}
					//To Check Password
					EEPROM_readString(NVM_PASS_ADMIN_FB,PASSWORD_ADMIN_Actual,PASS_Size);
					// in case password right
					if (u8ComparePassword(PASSWORD_ADMIN_Actual,PASSWORD_ADMIN_Entered))
					{
						LCD_Clear();
						LCD_SetCursor(0,0);
						LCD_WriteString("Right Password ");
						LCD_SetCursor(1,0);
						LCD_WriteString("ADMIN Mode");
						Timer1_SetInterruptTime_ms(10,&setcallFUNC);
						TimeOut_FLAG=0;
						MODE_Current=MODE_ADMIN;
						_delay_ms(1000);

					}
					// in case password Wrong
					else
					{
						LCD_Clear();
						LCD_SetCursor(0,0);
						LCD_WriteString("Wrong Enter it again ");
						LCD_SetCursor(1,0);
						MODE_Current=MODE_NO;
						Fault_Counter++;
						_delay_ms(2000);
						if (Fault_Counter==3)
						{
							LCD_Clear();
							LCD_SetCursor(0,0);
							LCD_WriteString("System Blocked ");
							LCD_SetCursor(1,0);
							LCD_WriteString("Try After 10 Secs ");
							_delay_ms(10000);
						}
						continue;
					}
				}
				break;
				case MODE_Guest :
				while (MODE_Current != MODE_Guest &&TimeOut_FLAG==0)
				{
					KEY=NO_KEY;
					LCD_Clear();
					LCD_SetCursor(0,0);
					LCD_WriteString("Enter The Password:");
					LCD_SetCursor(1,0);
					LCD_WriteString("PASS:");
					//To Take Password
					for (u8 i=0 ;i<PASS_Size; i++)
					{
						while(KEY ==NO_KEY)
						{
							KEY=KEYPAD_GetKey();
						}
						
						PASSWORD_Guest_Entered[i]=(KEY -'0');
						LCD_WriteChar(KEY);
						KEY=NO_KEY;
					}
					//To Check Password
					EEPROM_readString(NVM_PASS_Guest_FB,PASSWORD_Guest_Actual,PASS_Size);
					// in case password right
					if (u8ComparePassword(PASSWORD_Guest_Actual,PASSWORD_Guest_Entered))
					{
						LCD_Clear();
						LCD_SetCursor(0,0);
						LCD_WriteString("Right Password ");
						LCD_SetCursor(1,0);
						LCD_WriteString("Guest Mode");
						MODE_Current=MODE_Guest;
						Fault_Counter=0;
						Timer1_SetInterruptTime_ms(10,setcallFUNC);
						TimeOut_FLAG=0;
						_delay_ms(2000);

					}
					// in case password Wrong
					else
					{
						LCD_Clear();
						LCD_SetCursor(0,0);
						LCD_WriteString("Wrong Enter it again ");
						LCD_SetCursor(1,0);
						MODE_Current=MODE_NO;
						Fault_Counter++;
						_delay_ms(2000);
						if (Fault_Counter==3)
						{
							LCD_Clear();
							LCD_SetCursor(0,0);
							LCD_WriteString("System Blocked ");
							LCD_SetCursor(1,0);
							LCD_WriteString("Try After 10 Secs ");
							_delay_ms(10000);
						}
						continue;
					}
				}
				break;
			}
		}
		if (TimeOut_FLAG == 1 )
		{
			//TimeOut_FLAG == 0;
			MODE_Current = MODE_NO;
			KEY=NO_KEY;
			continue;
		}
		switch (Menu_State)
		{

			
			case MAIN_MENU:
			
			while (Menu_State == MAIN_MENU)
			{
				LCD_SetCursor(0,0);
				LCD_WriteString("1:ROOM1 2:ROOM2");
				
				if (MODE_Current == MODE_Guest)
				{
					LCD_SetCursor(1,0);
					LCD_WriteString("3:ROOM3 4:ROOM4");
				}
				else
				{
					LCD_SetCursor(1,0);
					LCD_WriteString("3:ROOM3 4:MORE..");
				}
				KEY =NO_KEY;
				while(KEY == NO_KEY)
				{
					KEY=KEYPAD_GetKey();
				}
				
				if (KEY -'0' == ROOM1_SELECT)
				{
					Menu_State=ROOM1_MENU;
				}
				else if (KEY -'0' == ROOM2_SELECT)
				{
					Menu_State=ROOM2_MENU;
				}
				else if (KEY -'0' == ROOM3_SELECT)
				{
					Menu_State=ROOM3_MENU;
				}
				else if (KEY -'0' == ROOM4_SELECT && MODE_Current== MODE_Guest)
				{
					Menu_State=ROOM4_MENU;
				}
				else if (KEY -'0' == MORE_SELECT_ADMIN && MODE_Current== MODE_ADMIN)
				{
					Menu_State=More_MENU;
					//	Menu_State=MORE_MENU;

				}
				else
				{
					LCD_Clear();
					LCD_SetCursor(0,0);
					LCD_WriteString("wrong try again");
					Menu_State=MAIN_MENU;
				}
			}
			break;
			
			case More_MENU :
			while (Menu_State == More_MENU)
			{
				LCD_Clear();
				LCD_SetCursor(0,0);
				LCD_WriteString("1:Room4    2:TV   ");
				LCD_SetCursor(1,0);
				LCD_WriteString("3:FAN   4:RET");
				
				KEY = NO_KEY;
				while(KEY == NO_KEY)
				{
					KEY=KEYPAD_GetKey();
				}
				if (KEY -'0' == ROOM4_SELECT_ADMIN)
				{
					Menu_State=ROOM4_MENU;
				}
				else if (KEY -'0' == TV_SELECT)
				{
					Menu_State=TV_MENU;
				}
				else if (KEY -'0' == FAN_SELECT)
				{
					Menu_State=FAN_MENU;
				}
				else if (KEY -'0' == RETURN_SELECT)
				{
					Menu_State=MAIN_MENU;
				}
				else
				{
					Menu_State=More_MENU;
				}
				
			}
			break;
			case FAN_MENU :
			while(Menu_State==FAN_MENU)
			{
				LCD_Clear();
				LCD_SetCursor(0,0);
				LCD_WriteString("1:Set temperature ");
				LCD_SetCursor(1,0);
				LCD_WriteString("2:Control  3:RET");
				KEY =NO_KEY;
				while(KEY == NO_KEY)
				{
					KEY=KEYPAD_GetKey();
				}
				
				if (KEY -'0' == FAN_SET_TEMP_SELECT)
				{
					Menu_State=TEMPERATURE_MENU;
				}
				else if (KEY -'0' == FAN_CTRL_SELECT)
				{
					Menu_State=FAN_CTRL_MENU;
				}
				else if (KEY -'0' == FAN_RETURN_SELECT)
				{
					
					Menu_State=More_MENU;
				}
				else
				{
					//	Menu_State=FAN_MENU;
				}
			}
			break;
			case ROOM1_MENU :
			vGetStatusAndControl(ROOM1_MENU);
			Menu_State = MAIN_MENU;
			break;
			case ROOM2_MENU :
			vGetStatusAndControl(ROOM2_MENU);
			Menu_State = MAIN_MENU;

			break;
			case ROOM3_MENU :
			vGetStatusAndControl(ROOM3_MENU);
			Menu_State = MAIN_MENU;

			break;
			case ROOM4_MENU :
			vGetStatusAndControl(ROOM4_MENU);
			Menu_State = MAIN_MENU;

			break;
			case FAN_CTRL_MENU :
			vGetStatusAndControl(FAN_CTRL_MENU);
			Menu_State = FAN_MENU;

			break;
			case TV_MENU :
			vGetStatusAndControl(TV_MENU);
			Menu_State = More_MENU;

			break;
			case TEMPERATURE_MENU :
			LCD_Clear();
			LCD_SetCursor(0,0);
			LCD_WriteString("Write TEMP: ");
			while(temperature == 0 )
			{
				KEY =NO_KEY;
				for (u8 i = 0;i<2 ;i++)
				{
					while(KEY == NO_KEY)
					{
						KEY=KEYPAD_GetKey();
					}
					LCD_WriteNumber(KEY-'0');
					temperature=temperature*10 + (KEY-'0');
					KEY =NO_KEY;
				}
				//SPI_SendReceive(SET_TEMPERATURE);
				_delay_ms(200);
				//	SPI_SendReceive(temperature);
				LCD_Clear();
				LCD_WriteString("temp sent");
				_delay_ms(700);
			}
			MODE_Current=FAN_MENU;
			break;
		}
	}
}

u8 u8ComparePassword (u8* str1,u8* str2)
{
	for (u8 i=0 ;i<PASS_Size; i++)
	{
		if (str1[i]==str2[i])
		{
			
		}
		else
		{
			return 0;
		}
	}
	return 1 ;
}
void vGetStatusAndControl(Menu_State)
{
	u8 u8TurnOnCode;
	u8 u8TurnOffCode;
	u8 u8StatusCode;
	LCD_Clear();
	LCD_SetCursor(0,0);
	switch(Menu_State)
	{
		case ROOM1_MENU:
		u8StatusCode = ROOM1_STATUS;
		u8TurnOnCode = ROOM1_TURN_ON;
		u8TurnOffCode = ROOM1_TURN_OFF;
		LCD_WriteString("Room1 S:");
		break;
		case ROOM2_MENU:
		u8StatusCode = ROOM2_STATUS;
		u8TurnOnCode = ROOM2_TURN_ON;
		u8TurnOffCode = ROOM2_TURN_OFF;
		LCD_WriteString("Room2 S:");
		break;
		case ROOM3_MENU:
		u8StatusCode = ROOM3_STATUS;
		u8TurnOnCode = ROOM3_TURN_ON;
		u8TurnOffCode = ROOM3_TURN_OFF;
		LCD_WriteString("Room3 S:");
		break;
		case ROOM4_MENU:
		u8StatusCode = ROOM4_STATUS;
		u8TurnOnCode = ROOM4_TURN_ON;
		u8TurnOffCode = ROOM4_TURN_OFF;
		LCD_WriteString("Room4 S:");
		break;
		case TV_MENU:
		u8StatusCode = TV_STATUS;
		u8TurnOnCode = TV_TURN_ON;
		u8TurnOffCode = TV_TURN_OFF;
		LCD_WriteString("TV S:");
		break;
		case FAN_CTRL_MENU:
		u8StatusCode = FAN_STATUS;
		u8TurnOnCode = FAN_TURN_ON;
		u8TurnOffCode = FAN_TURN_OFF;
		LCD_WriteString("FAN Cond. S:");
		break;
	}
	SPI_SendReceive(u8StatusCode);
	_delay_ms(200);
	u8 status=SPI_SendReceive(DUMMY);
	if (status)
	{
		LCD_WriteString(" ON");
	}
	else
	{
		LCD_WriteString(" OFF");
	}
	LCD_SetCursor(1,0);
	LCD_WriteString("1.ON 2.OFF 3.RET..");
	u8 KEY =NO_KEY;
	while(KEY ==NO_KEY)
	{
		KEY=KEYPAD_GetKey();
	}
	if (KEY - '0' == 1)
	{
		SPI_SendReceive(u8TurnOnCode);
	}
	else if (KEY - '0' == 2)
	{
		SPI_SendReceive(u8TurnOffCode);
	}
}

void setcallFUNC(void)
{
	static u16 counter=0;
	counter++;
	if (counter == 6000)
	{
		TimeOut_FLAG=1;
		counter=0;
	}

}
