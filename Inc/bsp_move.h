#ifndef __bsp_move_H
#define __bsp_move_H

#include "bsp_stepmotor.h"
#include "main.h"
#include "tim.h"

#define FORWORD  	 1
#define BACKWORD   2
#define LEFT    	 3
#define RIGHT		   4
#define TURN_LEFT  5
#define TURN_RIGHT 6

#define Left_Front  1
#define Right_Front 2
#define Left_Back   3
#define Right_Back  4

#define DIR_Left_Front_Monitor_Foward	    	HAL_GPIO_WritePin(DIR_Left_Front_GPIO_Port, DIR_Left_Front_Pin, GPIO_PIN_RESET)
#define DIR_Left_Front_Monitor_Backward	  	HAL_GPIO_WritePin(DIR_Left_Front_GPIO_Port, DIR_Left_Front_Pin, GPIO_PIN_SET)

#define DIR_Right_Front_Monitor_Foward	    HAL_GPIO_WritePin(DIR_Right_Front_GPIO_Port, DIR_Right_Front_Pin, GPIO_PIN_SET)
#define DIR_Right_Front_Monitor_Backward	  HAL_GPIO_WritePin(DIR_Right_Front_GPIO_Port, DIR_Right_Front_Pin, GPIO_PIN_RESET)

#define DIR_Left_Back_Monitor_Foward	    	HAL_GPIO_WritePin(DIR_Left_Back_GPIO_Port, DIR_Left_Back_Pin, GPIO_PIN_RESET)
#define DIR_Left_Back_Monitor_Backward	  	HAL_GPIO_WritePin(DIR_Left_Back_GPIO_Port, DIR_Left_Back_Pin, GPIO_PIN_SET)

#define DIR_Right_Back_Monitor_Foward	    	HAL_GPIO_WritePin(DIR_Right_Back_GPIO_Port, DIR_Right_Back_Pin, GPIO_PIN_SET)
#define DIR_Right_Back_Monitor_Backward	  	HAL_GPIO_WritePin(DIR_Right_Back_GPIO_Port, DIR_Right_Back_Pin, GPIO_PIN_RESET)

#define FrontLeft 0
#define XFront 1
#define FrontRight 2
#define XBack 3

void Move_Step(unsigned char way,unsigned int step);
void Move_LEFTONE(void);
#define Move_Enable HAL_GPIO_WritePin(ENABLE_GPIO_Port,ENABLE_Pin,GPIO_PIN_RESET)
#define Move_Disable HAL_GPIO_WritePin(ENABLE_GPIO_Port,ENABLE_Pin,GPIO_PIN_SET)

#endif

