#ifndef __bsp_servo_H
#define __bsp_servo_H
#include "tim.h"


void Servo_Init(void);    //初始化
void Catch_Control(uint16_t angle);//抓取
void Rotate_Control(uint16_t angle);//旋转


#endif

