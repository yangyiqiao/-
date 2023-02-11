#include "bsp_servo.h"

// angle:角度值，0~180

void Catch_Control(uint16_t angle)
{
   float temp;
   temp =(1.0 / 9.0) * angle + 5.0;//占空比值 = 1/9 * 角度 + 5
   __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, (uint16_t )temp);
}

void Rotate_Control(uint16_t angle)
{
   float temp;
   temp =(1.0 / 18.0) * angle + 5.0;//占空比值 = 1/18 * 角度 + 5
   __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, (uint16_t )temp);
}

void Servo_Init(void)//初始化
{
	HAL_TIM_Base_Start(&htim3);//启动定时器
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);//爪子
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_2);//转台
//	Catch_Control(0);//抓取
//	Rotate_Control(0);
}

