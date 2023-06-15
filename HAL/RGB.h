/*
 * RGB.h
 *
 * Created: 12/10/2022 3:25:42 PM
 *  Author: Tabana
 */ 


#ifndef RGB_H_
#define RGB_H_
#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"
#include "Timer.h"


typedef enum
{
	Color_1,
	Color_2,
	Color_3,
	Color_4,
	Color_5,
	Color_6,
	Color_7,
	Color_8,
	Color_9,
	Color_10,
	Color_11,
	Color_12,
	Color_13,
	Color_14,
	Color_15
}RGB_Color_type;

typedef enum
{
	OCR0_pin,
	OCRA1_pin,
	OCRB1_pin,

}RGB_PIN_type;
extern u8 RGB_ColorArr[15][3];
void RGB_Init();
void RGB_color(RGB_Color_type color,RGB_PIN_type red,RGB_PIN_type green, RGB_PIN_type blue );

void RGB_Flashing();

#endif /* RGB_H_ */