/*
 * UART_Services.c
 *
 * Created: 12/27/2022 8:38:42 PM
 *  Author: Tabana
 */ 
// sync function 

#include "UART_Services.h"

void UART_SendString(u8* data)
{
	for (u8 i =0 ;data[i]; i++)
	{
		UART_Send(data[i]);
	}
}

void UART_ReceiveString(u8* data)
{
	u8 i_u=0;
	data[i_u]=UART_Receive();
	for (i_u =0 ;data[i_u] !='#';)
	{
		i_u++;
		data[i_u]=UART_Receive();
	}
		data[i_u]=0;
}


void UART_SendNumber(u32 number)
{
	UART_Send((u8)number);
	UART_Send((u8)(number>>8));
	UART_Send((u8)(number>>16));
	UART_Send((u8)(number>>24));
}
void UART_SendNumber2(u32 number)
{
	u8*pd=(u8*)&number;
	UART_Send(*pd);
	UART_Send(*(pd+1));
	UART_Send(*(pd+2));
	UART_Send(*(pd+3));
}
u32 UART_ReceiveNumber(void)
{
	u32 num;
	num=UART_Receive();
	num=num|(UART_Receive() << 8);
	num=num|((u32)UART_Receive() << 16);
	num=num|((u32)UART_Receive() << 24);
	return num;
}
u32 UART_ReceiveNumber2(void)
{
	u32 num;
	u8* pd=(u8*)&num;
	pd[0]=UART_Receive();
	pd[1]=UART_Receive();
	pd[2]=UART_Receive();
	pd[3]=UART_Receive();
	return num;
}

void UART_SendStringCheckSum(u8* data)
{
	u8 len;
	u16 sum=0;
	for(len=0;data[len];len++);
	// Length of data {max write= 255 byte so size = 1 byte}
	UART_Send(len);
	// Send data 
	// send sum of them
	for(u8 i=0 ; data[i] ; i++)
	{
		UART_Send(data[i]);
		sum =sum + data[i];
	}
	UART_Send((u8)sum);
	UART_Send((u8)(sum>>8));
	
}
u8 UART_ReceiveStringCheckSum(u8* data)
{
	u8 i,rec_len = UART_Receive();
	
	u16 sum_calc=0,sum_rec=0;
	for ( i=0;i<rec_len;i++)
	{
		data[i]=UART_Receive();
		sum_calc+=data[i];
	}
	data[i]=0;
	
	sum_rec=UART_Receive();
	sum_rec=sum_rec|(UART_Receive()<<8);
	if (sum_rec == sum_calc)
	{
		return 1;
	}
	return 0; 
}

u8 *TX_str[20];
u8 UART_FLAG=0;
void UART_SendStringAsynch(u8* str)
{
	static u8 i=0;
	TX_str[i]=str;
	if (UART_FLAG==0)
	UART_Send(TX_str[i][0]);
	UART_FLAG=1;
	UART_TX_SetCallBack(FUNC_TX);
	UART_TX_InterruptEnable();
	i++;
}
void FUNC_TX(void)
{
	
	static u8 j=1,i=0;
	if (TX_str[i][j])
	{
		UART_SendNoBlock(TX_str[i][j++]);
	}
	else
	{
		i++;
		j=1;
		UART_Send(TX_str[i][0]);
	}
}

static u8* RX_str[20];
void UART_ReceiveStringAsynch(u8* str)
{
	static u8 i =0 ;
	UART_RX_SetCallBack(FUNC_RX);
	UART_RX_InterruptEnable();
	RX_str[i]=str;
	i++;
}
void FUNC_RX(void)
{
	static u8 i=0;
	static u8 k=0;

	RX_str[k][i]=UART_ReceiveNoBlock();
		i++;
	if (RX_str[k][i-1]==13)
	{
		RX_str[k][i-1]=='0';
		k++;
		i=0;
	}

	
}
static u8 flag=0;
void UART_BCM_Init(void)
{
		UART_TX_SetCallBack(FUNC_TX2);
		UART_TX_InterruptEnable();
}

void UART_BCM_Runnable(u8* str)
{
	static u8 i =0 ;
	if (flag==1)
	{
		if (str[i])
		{
			UART_SendNoBlock(str[i]);
			i++;
			flag=0;
			
		}

	}



}
void FUNC_TX2(void)
{
	
	flag=1;
}