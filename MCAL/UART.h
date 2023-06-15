/*
 * UART.h
 *
 * Created: 12/27/2022 1:53:55 PM
 *  Author: Tabana
 */ 


#ifndef UART_H_
#define UART_H_
#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"

void UART_Init(void);
void UART_Send(u8 data);
void UART_SendNoBlock(u8 data);
u8 UART_ReceiveNoBlock(void);

u8 UART_Receive(void);
u8 UART_ReceivePeriodic(u8* pdata);

void UART_TX_SetCallBack(void (*Localptr)(void));
void UART_RX_SetCallBack(void (*Localptr)(void));

void UART_TX_InterruptEnable(void);
void UART_RX_InterruptEnable(void);
void UART_TX_InterruptDISABLE(void);
void UART_RX_InterruptDISABLE(void);

#endif /* UART_H_ */