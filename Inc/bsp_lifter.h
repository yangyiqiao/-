#ifndef __bsp_lifter_H
#define __bsp_lifter_H

#include "tim.h"
#include "main.h"
#include "stdio.h"

#define Amplitude 49  //�޷�
#define KP 0.04
#define KI 0
#define KD 0

void Lifter_Init(void);
void Lifter_Control(int8_t val);//���뷶ΧΪ-50~50,������Ϊצ�������ƶ�
void Lifter_Stop(void);//���ֹͣ
void PID_Init(void);       //PID��ʼ��
int16_t PID_Lifter(float Speed);   //PID�㷨

#endif
