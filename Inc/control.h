#ifndef __CONTROL_H
#define __CONTROL_H


//ȫ�ֱ���
extern unsigned int MotorSpeed; // ����ٶ�
extern int SpeedTarget;         // Ŀ���ٶ�
extern int MotorOutput;         // ������

//��������
void GetMotorPulse(void);                     // ͨ��TIM4��ȡ������岢�����ٶ�
int SpeedInnerControl(int Speed,int Target);  // ����ʽPID������
void SetMotorVoltageAndDirection(int Pwm);    // �����ѹ�ͷ�����ƺ���

#endif

