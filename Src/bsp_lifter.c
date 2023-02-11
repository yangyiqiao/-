#include "bsp_lifter.h"

extern uint16_t countsum;

#if 0
extern struct _pidlook
{
	float SetSpeed;         //设定值
	float ActualSpeed;			//实际值
	float errk;							//e(k)
	float errk_1;						//e(k-1)
	float errk_2;						//e(k-2)
	float Kp,Ki,Kd;					//比例、积分、微分系数
	float IncSpeed2;
	int16_t PWM;//设置PWM值
}pidlook;
#endif

void Lifter_Init(void)//电机启动
{
		HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1);
		HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
}

void Lifter_Control(int8_t val)//输入范围为-50~50,正方向为爪子向下移动
{
	if(val>Amplitude)
	{
		val=Amplitude;
	}
	else if(val<-Amplitude)
	{
		val=-Amplitude;
	}//限幅
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, val+50);
}

void Lifter_Stop(void)//电机停止
{
		HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_1);
		HAL_TIM_PWM_Stop(&htim1,TIM_CHANNEL_1);
}

struct _pid
{
	float SetSpeed;         //设定值
	float ActualSpeed;			//实际值
	float errk;							//e(k)
	float errk_1;						//e(k-1)
	float errk_2;						//e(k-2)
	float Kp,Ki,Kd;					//比例、积分、微分系数
	int16_t PWM;//设置PWM值
}pid;



void PID_Init()
{
	pid.SetSpeed=0.0;
	pid.ActualSpeed=0.0;
	pid.errk=0.0;
	pid.errk_1=0.0;
	pid.errk_2=0.0;
	pid.Kp=KP;
	pid.Ki=KI;
	pid.Kd=KD;
	pid.PWM=0;
}

int16_t PID_Lifter(float Speed)
{
	pid.SetSpeed=Speed;               			//获取目标值
	pid.ActualSpeed=countsum;					//获取实际值
	pid.errk=pid.SetSpeed-pid.ActualSpeed;	//获取误差
	float IncSpeed=pid.Kp*(pid.errk-pid.errk_1)+pid.Ki*pid.errk+pid.Kd*(pid.errk-2*pid.errk_1+pid.errk_2);  //计算增量
	
	if(IncSpeed>=100)
	{
		pid.PWM=49;
	}
	else if(IncSpeed<=-100)
	{
		pid.PWM=-49;
	}
	else
	{
		if(IncSpeed>0.5&&IncSpeed<1)
		{
			IncSpeed=1;
		}
		else if(IncSpeed<0.5&&IncSpeed>-1)
		{
			IncSpeed=-1;
		}
		pid.PWM+=(int16_t)IncSpeed;
	}
	
	if(pid.PWM>=50)
	{
		pid.PWM=49;
	}
	else if(pid.PWM<=-50)
	{
		pid.PWM=-49;
	}
	
	pid.errk_2=pid.errk_1;
	pid.errk_1=pid.errk;
	
	#if 0
	pidlook.SetSpeed=pid.SetSpeed;
	pidlook.ActualSpeed=countsum;
	pidlook.errk=pid.errk;
	pidlook.errk_1=pid.errk_1;						//e(k-1)
	pidlook.errk_2=pid.errk_2;						//e(k-2)
	pidlook.IncSpeed2=IncSpeed;
	pidlook.PWM = pid.PWM;
	#endif
	
	printf("增量值：%f\r\n",IncSpeed);	
	printf("实际值：%f\r\n",pid.ActualSpeed);	
	printf("误差值：%f\r\n",pid.errk);				
	printf("PWM值：%d\r\n",pid.PWM);	
	return pid.PWM;
}
