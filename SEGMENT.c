#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "SEGMENT.h"
#define F_CPU 8000000
#include <util/delay.h>
#include "SEGMENT.h"

void segment_print(u8 x)
{
	char seg[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67};
	int d0 =x%10;
	int d1=d0/10;
	SEGMENT_PORT=seg[d0]<<1;
	SEGMENT_PORT=seg[d1]<<1;
}
void segment_print_mlx(u8 x)
{
	
	char seg[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};
	int d0 =x % 10;
	int d1=x/10;
	
	SET_BIT(SEGMENT_EN_PORT,S2_EN);
	SEGMENT_PORT=seg[d1]<<1;
	CLR_BIT(SEGMENT_EN_PORT,S1_EN);
	_delay_ms(1);
	
	SET_BIT(SEGMENT_EN_PORT,S1_EN);
	SEGMENT_PORT=seg[d0]<<1;
	CLR_BIT(SEGMENT_EN_PORT,S2_EN);
	_delay_ms(1);
}