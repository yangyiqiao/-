#include "bsp_servo.h"

// angle:�Ƕ�ֵ��0~180

void Catch_Control(uint16_t angle)
{
   float temp;
   temp =(1.0 / 9.0) * angle + 5.0;//ռ�ձ�ֵ = 1/9 * �Ƕ� + 5
   __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, (uint16_t )temp);
}

void Rotate_Control(uint16_t angle)
{
   float temp;
   temp =(1.0 / 18.0) * angle + 5.0;//ռ�ձ�ֵ = 1/18 * �Ƕ� + 5
   __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, (uint16_t )temp);
}

void Servo_Init(void)//��ʼ��
{
	HAL_TIM_Base_Start(&htim3);//������ʱ��
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);//צ��
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_2);//ת̨
//	Catch_Control(0);//ץȡ
//	Rotate_Control(0);
}

