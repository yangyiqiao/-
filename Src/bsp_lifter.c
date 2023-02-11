#include "bsp_lifter.h"

extern uint16_t countsum;

#if 0
extern struct _pidlook
{
	float SetSpeed;         //�趨ֵ
	float ActualSpeed;			//ʵ��ֵ
	float errk;							//e(k)
	float errk_1;						//e(k-1)
	float errk_2;						//e(k-2)
	float Kp,Ki,Kd;					//���������֡�΢��ϵ��
	float IncSpeed2;
	int16_t PWM;//����PWMֵ
}pidlook;
#endif

void Lifter_Init(void)//�������
{
		HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1);
		HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
}

void Lifter_Control(int8_t val)//���뷶ΧΪ-50~50,������Ϊצ�������ƶ�
{
	if(val>Amplitude)
	{
		val=Amplitude;
	}
	else if(val<-Amplitude)
	{
		val=-Amplitude;
	}//�޷�
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, val+50);
}

void Lifter_Stop(void)//���ֹͣ
{
		HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_1);
		HAL_TIM_PWM_Stop(&htim1,TIM_CHANNEL_1);
}

struct _pid
{
	float SetSpeed;         //�趨ֵ
	float ActualSpeed;			//ʵ��ֵ
	float errk;							//e(k)
	float errk_1;						//e(k-1)
	float errk_2;						//e(k-2)
	float Kp,Ki,Kd;					//���������֡�΢��ϵ��
	int16_t PWM;//����PWMֵ
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
	pid.SetSpeed=Speed;               			//��ȡĿ��ֵ
	pid.ActualSpeed=countsum;					//��ȡʵ��ֵ
	pid.errk=pid.SetSpeed-pid.ActualSpeed;	//��ȡ���
	float IncSpeed=pid.Kp*(pid.errk-pid.errk_1)+pid.Ki*pid.errk+pid.Kd*(pid.errk-2*pid.errk_1+pid.errk_2);  //��������
	
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
	
	printf("����ֵ��%f\r\n",IncSpeed);	
	printf("ʵ��ֵ��%f\r\n",pid.ActualSpeed);	
	printf("���ֵ��%f\r\n",pid.errk);				
	printf("PWMֵ��%d\r\n",pid.PWM);	
	return pid.PWM;
}
