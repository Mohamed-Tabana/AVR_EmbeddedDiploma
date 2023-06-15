/*
 * CarProject.h
 *
 * Created: 10/22/2022 1:33:10 AM
 *  Author: Mohamed TABANA
 */ 


#ifndef CARPROJECT_H_
#define CARPROJECT_H_
#include "DIO_interface.h"


void MOVE_Forward(void);
void MOVE_Backward(void);
void MOVE_Left(void);
void MOVE_Right(void);
void MOVE_Stop(void);

void MOVE_Init(void);
void MOVE_Runnable(void);

#define FRONT_LEFT M1
#define FRONT_RIGHT M2
#define BACK_LEFT M1
#define BACK_RIGHT M1

#define FORWARD_B PINB0
#define BACKWARD_B PINB1
#define LEFT_B PINB2
#define RIGHT_B PINB3




#endif /* CARPROJECT_H_ */