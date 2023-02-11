#include "bsp_stepmotor.h"
#include "tim.h"
#include "math.h"
 
extern uint16_t step_to_run[4]; //要匀速运行的步数       总共运行步数 = ACCELERATED_SPEED_LENGTH*2 + step_to_run                   
extern float fre[ACCELERATED_SPEED_LENGTH]; //数组存储加速过程中每一步的频率 
extern unsigned short period[ACCELERATED_SPEED_LENGTH]; //数组储存加速过程中每一步定时器的自动装载值     
extern uint8_t ADmode;

extern float freAD[ACCELERATED_SPEED_LENGTH_AD]; //数组存储变速过程中每一步的频率 
extern unsigned short periodAD[ACCELERATED_SPEED_LENGTH_AD]; //数组储存变速过程中每一步定时器的自动装载值   
extern uint16_t step_to_runAD[4];

void CalculateSModelLine(float fre[], unsigned short period[], float len, float fre_max, float fre_min, float flexible)
{
    int i=0;
    float deno ;
    float melo ;
    float delt = fre_max-fre_min;
    for(; i<len; i++)
    {
        melo = flexible* (i-len/2) / (len/2);
        deno = 1.0f / (1 + expf(-melo));  //expf is a library function of exponential(e)?
        fre[i] = delt * deno + fre_min;
        period[i] = (unsigned short)(1000000.0f / fre[i]); // 1000000 is the timer driver frequency
    }
    return ;
}
 
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim)
{
//	static uint32_t count[4]={0,0,0,0};
//	static uint32_t num_callback[4]={0,0,0,0};
//	static uint8_t status[4]={1,1,1,1};
//	static uint8_t i = 0;

	extern uint32_t count[4];
	extern uint32_t num_callback[4];
	extern uint8_t status[4];
	uint8_t i=0;
	
	extern uint32_t countAD[4];
	extern uint32_t num_callbackAD[4];
	extern uint8_t statusAD[4];

	
	if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
	{
		num_callback[0]++;
		if(num_callback[0]%2==0)
		{
			switch(status[0])
	          {
	              case ACCEL://加速
                        __HAL_TIM_SetAutoreload(&htim2,period[count[0]]);
	                    __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,period[count[0]]/2);
	                    count[0]++;
	                    if(count[0]>=ACCELERATED_SPEED_LENGTH)
	                    {
	                        status[0]=3;
	                    }                        
	                  break;
	              case RUN://匀速
	                     step_to_run[0]--;
	                     if(step_to_run[0]<1)
	                       status[0]=2;     
	                   break;
	              case DECEL://减速
	                     count[0]--;
                        __HAL_TIM_SetAutoreload(&htim2,period[count[0]]);
	                    __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,period[count[0]]/2);
	                    if(count[0]<1)
	                        status[0]=0;
	                   break;
	              case STOP://停止
	                   // 关闭通道
	                  TIM_CCxChannelCmd(TIM2, TIM_CHANNEL_1, TIM_CCx_DISABLE);        
	                  __HAL_TIM_CLEAR_FLAG(&htim2, TIM_FLAG_CC1);
	                   break;
	          }
		}
	}
	else if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
	{
        num_callback[1]++;
		if(num_callback[1]%2==0)
		{
              switch(status[1])
	          {
	              case ACCEL://加速
                        __HAL_TIM_SetAutoreload(&htim2,period[count[1]]);
	                    __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,period[count[1]]/2);
	                    count[1]++;
	                    if(count[1]>=ACCELERATED_SPEED_LENGTH)
	                    {
	                        status[1]=3;
	                    }                        
	                  break;
	              case RUN://匀速
	                     step_to_run[1]--;
	                     if(step_to_run[1]<1)
	                       status[1]=2;     
	                   break;
	              case DECEL://减速
	                     count[1]--;
                        __HAL_TIM_SetAutoreload(&htim2,period[count[1]]);
	                    __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,period[count[1]]/2);
	                    if(count[1]<1)
	                        status[1]=0;
	                   break;
	              case STOP://停止
	                   // 关闭通道
	                  TIM_CCxChannelCmd(TIM2, TIM_CHANNEL_2, TIM_CCx_DISABLE);             
	                  __HAL_TIM_CLEAR_FLAG(&htim2, TIM_FLAG_CC2);
	                   break;
	          }
        }
	}
	else if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_3)
	{
		num_callback[2]++;
		if(num_callback[2]%2==0)
		{
               switch(status[2])
	          {
	              case ACCEL://加速
                        __HAL_TIM_SetAutoreload(&htim2,period[count[2]]);
	                    __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,period[count[2]]/2);
	                    count[2]++;
	                    if(count[2]>=ACCELERATED_SPEED_LENGTH)
	                    {
	                        status[2]=3;
	                    }                        
	                  break;
	              case RUN://匀速
	                     step_to_run[2]--;
	                     if(step_to_run[2]<1)
	                       status[2]=2;     
	                   break;
	              case DECEL://减速
	                     count[2]--;
                        __HAL_TIM_SetAutoreload(&htim2,period[count[2]]);
	                    __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,period[count[2]]/2);
	                    if(count[2]<1)
	                        status[2]=0;
	                   break;
	              case STOP://停止
	                   // 关闭通道
	                  TIM_CCxChannelCmd(TIM2, TIM_CHANNEL_3, TIM_CCx_DISABLE);        
	                  __HAL_TIM_CLEAR_FLAG(&htim2, TIM_FLAG_CC3);
										TIM_CCxChannelCmd(TIM2, TIM_CHANNEL_4, TIM_CCx_DISABLE);        
	                  __HAL_TIM_CLEAR_FLAG(&htim2, TIM_FLAG_CC4);
	                   break;
	          }
        }
	}
	else if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_4)
	{
		num_callback[3]++;
		if(num_callback[3]%2==0)
		{
              switch(status[3])
	          {
	              case ACCEL://加速
                        __HAL_TIM_SetAutoreload(&htim2,period[count[3]]);
	                    __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,period[count[3]]/2);
	                    count[3]++;
	                    if(count[3]>=ACCELERATED_SPEED_LENGTH)
	                    {
	                        status[3]=3;
	                    }                        
	                  break;
	              case RUN://匀速
	                     step_to_run[3]--;
	                     if(step_to_run[3]<1)
	                       status[3]=2;     
	                   break;
	              case DECEL://减速
	                     count[3]--;
                        __HAL_TIM_SetAutoreload(&htim2,period[count[3]]);
	                    __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,period[count[3]]/2);
	                    if(count[3]<1)
	                        status[3]=0;
	                   break;
	              case STOP://停止
	                   // 关闭通道
	                  TIM_CCxChannelCmd(TIM2, TIM_CHANNEL_4, TIM_CCx_DISABLE);        
	                  __HAL_TIM_CLEAR_FLAG(&htim2, TIM_FLAG_CC4);
	                   break;
	          }
        }
	}
  if(ADmode == 1)
	{
		if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
		{
			num_callbackAD[0]++;
			if(num_callbackAD[0]%2==0)
			{
				switch(statusAD[0])
							{
								case ACCEL://加速
												__HAL_TIM_SetAutoreload(&htim2,periodAD[countAD[0]]);
											__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,periodAD[countAD[0]]/2);
											countAD[0]++;
											if(countAD[0]>=ACCELERATED_SPEED_LENGTH_AD)
											{
													statusAD[0]=3;
											}                        
										break;
								case RUN://匀速
											 step_to_runAD[0]--;
											 if(step_to_runAD[0]<1)
												 statusAD[0]=2;     
										 break;
								case DECEL://减速
											 countAD[0]--;
												__HAL_TIM_SetAutoreload(&htim2,periodAD[countAD[0]]);
											__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,periodAD[countAD[0]]/2);
											if(countAD[0]<1)
													statusAD[0]=0;
										 break;
								case STOP://停止
										 break;
							}
			}
		}
		else if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
		{
					num_callbackAD[1]++;
			if(num_callbackAD[1]%2==0)
			{
								switch(statusAD[1])
							{
									case ACCEL://加速
													__HAL_TIM_SetAutoreload(&htim2,periodAD[countAD[1]]);
												__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,periodAD[countAD[1]]/2);
												countAD[1]++;
												if(countAD[1]>=ACCELERATED_SPEED_LENGTH_AD)
												{
														statusAD[1]=3;
												}                        
											break;
									case RUN://匀速
												 step_to_runAD[1]--;
												 if(step_to_runAD[1]<1)
													 statusAD[1]=2;     
											 break;
									case DECEL://减速
												 countAD[1]--;
													__HAL_TIM_SetAutoreload(&htim2,periodAD[countAD[1]]);
												__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,periodAD[countAD[1]]/2);
												if(countAD[1]<1)
														statusAD[1]=0;
											 break;
									case STOP://停止
											 break;
							}
					}
		}
		else if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_3)
		{
			num_callbackAD[2]++;
			if(num_callbackAD[2]%2==0)
			{
								 switch(statusAD[2])
							{
									case ACCEL://加速
													__HAL_TIM_SetAutoreload(&htim2,periodAD[countAD[2]]);
												__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,periodAD[countAD[2]]/2);
												countAD[2]++;
												if(countAD[2]>=ACCELERATED_SPEED_LENGTH_AD)
												{
														statusAD[2]=3;
												}                        
											break;
									case RUN://匀速
												 step_to_runAD[2]--;
												 if(step_to_runAD[2]<1)
													 statusAD[2]=2;     
											 break;
									case DECEL://减速
												 countAD[2]--;
													__HAL_TIM_SetAutoreload(&htim2,periodAD[countAD[2]]);
												__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,periodAD[countAD[2]]/2);
												if(countAD[2]<1)
														statusAD[2]=0;
											 break;
									case STOP://停止
											 break;
							}
					}
		}
		else if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_4)
		{
		num_callbackAD[3]++;
		if(num_callbackAD[3]%2==0)
		{
              switch(statusAD[3])
	          {
	              case ACCEL://加速
                        __HAL_TIM_SetAutoreload(&htim2,periodAD[countAD[3]]);
	                    __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,periodAD[countAD[3]]/2);
	                    countAD[3]++;
	                    if(countAD[3]>=ACCELERATED_SPEED_LENGTH_AD)
	                    {
	                        statusAD[3]=3;
	                    }                        
	                  break;
	              case RUN://匀速
	                     step_to_runAD[3]--;
	                     if(step_to_runAD[3]<1)
	                       statusAD[3]=2;     
	                   break;
	              case DECEL://减速
	                     countAD[3]--;
                        __HAL_TIM_SetAutoreload(&htim2,periodAD[countAD[3]]);
	                    __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,periodAD[countAD[3]]/2);
	                    if(countAD[3]<1)
	                        statusAD[3]=0;
	                   break;
	              case STOP://停止
	                   break;
	          }
        }
			}
		if(statusAD[2]==0&&statusAD[0]==0)
		{
			ADmode = 0;
				for(i=0;i<4;i++)
				{
				countAD[i]=0;
				num_callbackAD[i]=0;
				statusAD[i]=1;
				}
		}
	}
}

