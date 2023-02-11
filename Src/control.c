#include "control.h"
#include "tim.h"
#include "main.h"
#include "math.h"

unsigned int MotorSpeed;  // ȫ�ֱ����������ǰ�ٶ���ֵ���ӱ������л�ȡ
int SpeedTarget = 5000;	  // ȫ�ֱ������ٶ�Ŀ��ֵ
int MotorOutput;		  // ȫ�ֱ�����������
extern uint16_t countsum; //�����ǰλ��

// 1.ͨ��TIM4��ȡ������岢�����ٶ�
void GetMotorPulse(void)
{
  // TIM4��������õ�����壬�õ����10ms����������/18��Ϊʵ��ת�ٵ�rpm
  //MotorSpeed = (short)(__HAL_TIM_GET_COUNTER(&htim4)/18*7200/100); 
		MotorSpeed = (short)countsum;  
  //__HAL_TIM_SET_COUNTER(&htim4,0);  // ����������
}


// 2.����ʽPID������
int Error_Last,Error_Prev;          // ��һ��ƫ��ֵ�����ϴ����
int Pwm_add,Pwm;                    // PWM������PWM���ռ�ձ�
float Kp = 0.4, Ki = 0.4, Kd = 13;       // PIDϵ��������ֻ�õ�PI������
//float Kp = 5, Ki = 10, Kd = 20;       // PIDϵ��������ֻ�õ�PI������
//KI = 20	>0.02	KP=3
int SpeedInnerControl(int Speed,int Target) // �ٶ��ڻ�����
{
    int Error = Speed - Target;		  // ƫ�� = Ŀ���ٶ� - ʵ���ٶ�

    Pwm_add = Kp * (Error - Error_Last) + 					  // ����
			  Ki * Error +							    	  // ����
			  Kd * (Error - 2.0f * Error_Last + Error_Prev)	  // ΢��
              +1;  // ��һ��Ŀ�����������ź�Ϊ0ʱ��ϵͳ������ʧ��״̬

    Pwm += Pwm_add;		              // ԭʼ��+���� = �����
	
	Error_Prev = Error_Last;	  	  // �������ϴ����
    Error_Last = Error;	              // �����ϴ�ƫ��

    if(Pwm > 25) Pwm = 25;	      // �޷�
    if(Pwm <-25) Pwm = -25;

    return Pwm;	                      // �������ֵ
} 

//3.�����ѹ�ͷ�����ƺ���
void SetMotorVoltageAndDirection(int Pwm)
{
  __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, Pwm);
}
