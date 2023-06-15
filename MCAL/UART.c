/*
 * UART.c
 *
 * Created: 12/27/2022 1:53:43 PM
 *  Author: Tabana
 */ 
#include "UART.h"

static void (*UART_RX_Fptr)(void)=NULL_PTR;
static void (*UART_TX_Fptr)(void)=NULL_PTR;

ISR(UART_TX_vect)
{
	if(UART_TX_Fptr != NULL_PTR)
	{
		UART_TX_Fptr();
	}
}
ISR(UART_RX_vect)
{
	if(UART_RX_Fptr != NULL_PTR)
	{
		UART_RX_Fptr();
	}
}

void UART_Init(void)
{
	//Baud rate 
	UBRRL=51;
//	UBRRL=12;

	//Frame : parity, data bits, stop bit
	
	
	//normal speed
	CLR_BIT(UCSRA,U2X);
	
	//Enable at last of init as usual
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
}
void UART_Send(u8 data)
{
	while(!READ_BIT(UCSRA,UDRE));
	UDR=data;
}

u8 UART_Receive(void)
{
	while(!READ_BIT(UCSRA,RXC));
	return UDR;
}
u8 UART_ReceivePeriodic(u8* pdata)
{
	if(READ_BIT(UCSRA,RXC))
	{
		*pdata=UDR;
		return 1;
	}
	return 0;
}
void UART_SendNoBlock(u8 data)
{
	UDR=data;
}
u8 UART_ReceiveNoBlock(void)
{
	return UDR;
}

void UART_TX_SetCallBack(void (*Localptr)(void))
{
	UART_TX_Fptr= Localptr;
}

void UART_RX_SetCallBack(void (*Localptr)(void))
{
	UART_RX_Fptr= Localptr;
}


void UART_TX_InterruptEnable(void)
{
	SET_BIT(UCSRB,TXCIE);
}
void UART_RX_InterruptEnable(void)
{
	SET_BIT(UCSRB,RXCIE);

}
void UART_TX_InterruptDISABLE(void)
{	
	CLR_BIT(UCSRB,TXCIE);
}
void UART_RX_InterruptDISABLE(void)
{
	CLR_BIT(UCSRB,RXCIE);
}
