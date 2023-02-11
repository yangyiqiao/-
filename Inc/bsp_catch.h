#ifndef __bsp_catch_H
#define __bsp_catch_H
#include "main.h"
#include "bsp_stepmotor.h"
#include "bsp_move.h"
#include "bsp_servo.h"

extern uint8_t mission_buf[7];
extern uint8_t Order_buf[1];
extern int Position;				//��е������λ��
extern int CatchPosition;		//ץȡ����λ��

#define CATCHMOVE 700 		//ץȡʱ�ƶ�����
#define PUTLAST 40     		//����Ѳ��ʱ����

#define POS     0					//���0��λ��
#define FIRPOS  232				//�����һ�����Ƕ�
#define SECPOS	180				//����ڶ������Ƕ�
#define THIPOS	145				//������������Ƕ�

//ֵԽСλ��Խ�� 10000Ϊ��׼
#define TOP     	9200		//����������߶�
#define BOTTOM  	9850		//�ŵ����ϵ�λ��
#define CATBOT  	10900		//�ŵ����ϵ�λ��
#define CATMA  		10300		//����λ��
#define CATUP  		9700		//ץȡ�ϲ�����λ��CATUP
#define CATDOWN		10670//10600		//ץȡ�²�����λ��

#define PUTANG    35

#define OneGrid 	800//1000//1600		//ץȡ���������ʱ�ƶ�һ�����
#define TwoGrid 	2800		//ץȡ���������ʱ�ƶ��������



void CatchWithMission1(void); //ץ��һ������
void CatchWithMission2(void); //ץ�ڶ�������
void CatchWithMission3(void); //ץ����������
void MoveBack(void);					//�ص�ԭ��
void PutWithOrder1(void);			//���õ�һ������
void PutWithOrder2(void);			//���õڶ�������
void PutWithOrder3(void);			//���õ���������
void MoveBack2(void);					//���Ʒ�����ּӹ����ص�ԭ��
void MoveBack3(void);					//�ּӹ����ص���ɫ��
void CatchWithOrder1(void);
void CatchWithOrder2(void);
void CatchWithOrder3(void);
void PutWithOrderCU1(void);
void PutWithOrderCU2(void);
void PutWithOrderCU3(void);
void PutWithOrderCU4(void);
void PutWithOrderCU5(void);
void PutWithOrderCU6(void);
#endif

