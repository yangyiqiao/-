#ifndef __bsp_servo_H
#define __bsp_servo_H
#include "tim.h"


void Servo_Init(void);    //��ʼ��
void Catch_Control(uint16_t angle);//ץȡ
void Rotate_Control(uint16_t angle);//��ת


#endif

