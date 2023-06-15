/*
 * UART_Services.h
 *
 * Created: 12/27/2022 8:39:01 PM
 *  Author: Tabana
 */ 


#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_
#include "UART.h"

void UART_SendString(u8* data);
void UART_ReceiveString(u8* data);

void UART_SendNumber(u32 number);
void UART_SendNumber2(u32 number);
u32 UART_ReceiveNumber(void);
u32 UART_ReceiveNumber2(void);
void UART_SendStringCheckSum(u8* data);
u8 UART_ReceiveStringCheckSum(u8* data);
void UART_SendStringAsynch(u8* str);
void FUNC_TX(void);
void UART_ReceiveStringAsynch(u8* str);
void FUNC_RX(void);
void UART_BCM_Init(void);
void UART_BCM_Runnable(u8* str);
void FUNC_TX2(void);

#endif /* UART_SERVICES_H_ */