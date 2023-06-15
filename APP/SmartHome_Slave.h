/*
 * SmartHome_Slave.h
 *
 * Created: 1/6/2023 9:22:48 PM
 *  Author: Tabana
 */ 


#ifndef SMARTHOME_SLAVE_H_
#define SMARTHOME_SLAVE_H_


#include "DIO_interface.h"
#include "LCD.h"
#include "KeyPad_interface.h"
#include "ADC.h"
#include "MOTOR_interface.h"
#include "TempF.h"
#include "EX_Interrupt.h"
#include "Timer.h"
#include "ServoMotor.h"
#include "RGB.h"
#include "UART.h"
#include "SPI.h"
#include "EEPROM.h"
#include "Timer_Services.h"
void setcallFUNC(void);
u8 u8ComparePassword (u8* str1,u8* str2);
void vGetStatusAndControl(Menu_State);
#define PASS_Size 4
#define NVM_PASS_ADMIN_SET 0
#define NVM_PASS_Guest_SET 1
#define NVM_PASS_ADMIN_FB 2 // First BYTE for admin password 2 3 4 5
#define NVM_PASS_Guest_FB 6 // First BYTE for guest password 6 7 8 9

#define MODE_NO 0
#define MODE_ADMIN 1
#define MODE_Guest 2

/*********** menu select **********/
#define ROOM1_SELECT 1
#define ROOM2_SELECT 2
#define ROOM3_SELECT 3
#define ROOM4_SELECT 4
#define MORE_SELECT_ADMIN 4

#define ROOM4_SELECT_ADMIN 1
#define TV_SELECT 2
#define FAN_SELECT 3
#define RETURN_SELECT 4

#define FAN_SET_TEMP_SELECT 1
#define FAN_CTRL_SELECT 2
#define FAN_RETURN_SELECT 3
/**********************************/
/*********** menu number **********/
#define MAIN_MENU 0 //
#define ROOM1_MENU 2//
#define ROOM2_MENU 3//
#define ROOM3_MENU 4//
#define ROOM4_MENU 5//
#define FAN_MENU 6 //
#define TV_MENU 7
#define TEMPERATURE_MENU 8
#define FAN_CTRL_MENU 9
#define More_MENU 10 //


/**********************************/


#define ROOM1_STATUS    0x11
#define ROOM2_STATUS    0x12
#define ROOM3_STATUS    0x13
#define ROOM4_STATUS    0x14
#define TV_STATUS 		0x15
#define FAN_STATUS 0x16

#define ROOM1_TURN_ON    0x21
#define ROOM2_TURN_ON    0x22
#define ROOM3_TURN_ON    0x23
#define ROOM4_TURN_ON    0x24
#define TV_TURN_ON 		 0x25
#define FAN_TURN_ON 0x26

#define ROOM1_TURN_OFF    0x31
#define ROOM2_TURN_OFF    0x32
#define ROOM3_TURN_OFF    0x33
#define ROOM4_TURN_OFF    0x34
#define TV_TURN_OFF 	  0x35
#define FAN_TURN_OFF 0x36

#define SET_TEMPERATURE 0x40
#define DUMMY 0xFF
#define ON_STATUS   0x01
#define OFF_STATUS  0x00
/**********************************/



#endif /* SMARTHOME_SLAVE_H_ */