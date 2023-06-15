/*
 * Utils.h
 *
 * Created: 10/15/2022 1:33:58 AM
 *  Author: moham
 */ 


#ifndef UTILS_H_
#define UTILS_H_
#define READ_BIT(REG,BIT) ((REG>>BIT)&1)
#define SET_BIT(REG,BIT) REG|=(1<<BIT)
#define CLR_BIT(REG,BIT) REG&=~(1<<BIT)
#define TGL_BIT(REG,BIT) REG^=(1<<BIT)

#endif /* UTILS_H_ */