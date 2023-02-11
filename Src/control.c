#include "control.h"
#include "tim.h"
#include "main.h"
#include "math.h"

unsigned int MotorSpeed;  // 全局变量，电机当前速度数值，从编码器中获取
int SpeedTarget = 5000;	  // 全局变量，速度目标值
int MotorOutput;		  // 全局变量，电机输出
extern uint16_t countsum; //电机当前位置

// 1.通过TIM4读取电机脉冲并计算速度
void GetMotorPulse(void)
{
  // TIM4计数器获得电机脉冲，该电机在10ms采样的脉冲/18则为实际转速的rpm
  //MotorSpeed = (short)(__HAL_TIM_GET_COUNTER(&htim4)/18*7200/100); 
		MotorSpeed = (short)countsum;  
  //__HAL_TIM_SET_COUNTER(&htim4,0);  // 计数器清零
}


// 2.增量式PID控制器
int Error_Last,Error_Prev;          // 上一次偏差值，上上次误差
int Pwm_add,Pwm;                    // PWM增量，PWM输出占空比
float Kp = 0.4, Ki = 0.4, Kd = 13;       // PID系数，这里只用到PI控制器
//float Kp = 5, Ki = 10, Kd = 20;       // PID系数，这里只用到PI控制器
//KI = 20	>0.02	KP=3
int SpeedInnerControl(int Speed,int Target) // 速度内环控制
{
    int Error = Speed - Target;		  // 偏差 = 目标速度 - 实际速度

    Pwm_add = Kp * (Error - Error_Last) + 					  // 比例
			  Ki * Error +							    	  // 积分
			  Kd * (Error - 2.0f * Error_Last + Error_Prev)	  // 微分
              +1;  // 加一的目的是如果输出信号为0时，系统将进入失控状态

    Pwm += Pwm_add;		              // 原始量+增量 = 输出量
	
	Error_Prev = Error_Last;	  	  // 保存上上次误差
    Error_Last = Error;	              // 保存上次偏差

    if(Pwm > 25) Pwm = 25;	      // 限幅
    if(Pwm <-25) Pwm = -25;

    return Pwm;	                      // 返回输出值
} 

//3.电机电压和方向控制函数
void SetMotorVoltageAndDirection(int Pwm)
{
  __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, Pwm);
}
