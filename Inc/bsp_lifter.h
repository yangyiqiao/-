#ifndef __bsp_lifter_H
#define __bsp_lifter_H

#include "tim.h"
#include "main.h"
#include "stdio.h"

#define Amplitude 49  //限幅
#define KP 0.04
#define KI 0
#define KD 0

void Lifter_Init(void);
void Lifter_Control(int8_t val);//输入范围为-50~50,正方向为爪子向下移动
void Lifter_Stop(void);//电机停止
void PID_Init(void);       //PID初始化
int16_t PID_Lifter(float Speed);   //PID算法

#endif
