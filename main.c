
#define F_CPU 8000000
#include <util/delay.h>
#define  KEYPAD_PROG

#include "task.h"
#include "DIO_interface.h"
#include "FreeRTOS.h"
#include "semphr.h"
void LED1 (void* pvPArameter);
void LED2 (void* pvPArameter);


xSemaphoreHandle LCDSem;

void main(void)
{
	DIO_Init();

	//ADC_Init(VREF_VCC,ADC_SCALER_64);
	sei();
	xTaskCreate(LED1,NULL,150,NULL,1,NULL);
	xTaskCreate(LED2,NULL,150,NULL,2,NULL);
	vTaskStartScheduler(); 
	LCDSem=xSemaphoreCreateCounting(1,1);
	if (LCDSem != NULL_PTR)
	{
		
	}
	while (1)
	{
	//	DIO_TogglePin(PINC0);
		//_delay_ms(400);
	}
}
void LCD1 (void* pvPArameter)
{
	u8 state;
	while (1)
	{
		state=xSemaphoreTake(LCDSem,0);
		if (state==pdPASS)
		{
			LCD_WriteString("Task1");	
			xSemaphoreGive(LCDSem);
		}
		vTaskDelay(2);
	}
	
}
void LCD2 (void* pvPArameter)
{
	u8 state;
	while (1)
	{
		state=xSemaphoreTake(LCDSem,0);
		if (state==pdPASS)
		{
			LCD_WriteString("Task2");
			xSemaphoreGive(LCDSem);
		}
		vTaskDelay(2);
	}
	
}