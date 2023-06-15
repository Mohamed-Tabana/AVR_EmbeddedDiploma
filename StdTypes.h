
#ifndef STDTYPES_H_
#define STDTYPES_H_

typedef unsigned char u8;
typedef signed char	  s8;

typedef unsigned short u16;
typedef signed short s16;

typedef unsigned long u32;
typedef signed long s32;

typedef unsigned long long u64;
typedef signed long long s64;

typedef enum {
	OK,
	NOK,
	NULL_PTR,
	OUT_OF_RANGE,
}Error_type;
typedef enum{
	FALSE,
	TRUE
}Bool_type;
#define NULL_PTR ((void*)0)
#define NULL ((char)0)

#define MAX_u8 ((u8)255)
#define MAX_s8 ((s8)127)
#define MIN_s8 ((s8)-128)




#endif /* STDTYPES_H_ */