#ifndef __bsp_stepmotor_H
#define __bsp_stepmotor_H
#include "tim.h"
#ifdef __cplusplus
 extern "C" {
#endif
     
#define S_ACCEL 1
#define T_ACCEL 0
     
/* S�ͼ��ٲ��� */

#define ACCELERATED_SPEED_LENGTH 600  //������ٶȵĵ�������ʵҲ��3000��ϸ�ֲ�����˼��������������ı���ٵ�
#define ACCELERATED_SPEED_LENGTH_AD 400  //������ٶȵĵ�������ʵҲ��3000��ϸ�ֲ�����˼��������������ı���ٵ�
#define FRE_MIN 0  //��͵�����Ƶ�ʣ����������������������ٶ�
#define FRE_MAX 8000  //��ߵ�����Ƶ�ʣ����������������������ٶ�
#define ADSTEP 40   //����ʱ�������в���
#define TrackPre 3550//��Ѳ��Ԥ�о���

#define STOP                                  0 // �Ӽ�������״̬��ֹͣ
#define ACCEL                                 1 // �Ӽ�������״̬�����ٽ׶�
#define DECEL                                 2 // �Ӽ�������״̬�����ٽ׶�
#define RUN                                   3 // �Ӽ�������״̬�����ٽ׶�

void CalculateSModelLine(float fre[], unsigned short period[], float len, float fre_max, float fre_min, float flexible);    

#endif
 
 
 
 
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
