#include "bsp_move.h"

extern uint16_t step_to_run[];
extern uint32_t count[4];
extern uint32_t num_callback[4];
extern uint8_t status[4];
uint8_t k = 0;
extern uint16_t data[4];
	
void Move_Step(unsigned char way,unsigned int step)
{

			for(k=0;k<4;k++)
		{
			step_to_run[k]=step;
		}
	switch (way)
	{
		case FORWORD:
		DIR_Left_Front_Monitor_Foward;
		DIR_Right_Front_Monitor_Foward;
		DIR_Left_Back_Monitor_Foward;
		DIR_Right_Back_Monitor_Foward;
		break;
		
		case BACKWORD:
		DIR_Left_Front_Monitor_Backward;
		DIR_Right_Front_Monitor_Backward;
		DIR_Left_Back_Monitor_Backward;
		DIR_Right_Back_Monitor_Backward;
		break;
		
		case LEFT:
		DIR_Left_Front_Monitor_Backward;
		DIR_Right_Front_Monitor_Foward;
		DIR_Left_Back_Monitor_Foward;
		DIR_Right_Back_Monitor_Backward;
		break;
		
		case RIGHT:
		DIR_Left_Front_Monitor_Foward;
		DIR_Right_Front_Monitor_Backward;
		DIR_Left_Back_Monitor_Backward;
		DIR_Right_Back_Monitor_Foward;		
		break;
		
		case TURN_LEFT:
		DIR_Left_Front_Monitor_Foward;
		DIR_Right_Front_Monitor_Backward;
		DIR_Left_Back_Monitor_Foward;
		DIR_Right_Back_Monitor_Backward;
		break;
	}
	HAL_TIM_OC_Start_IT(&htim2, TIM_CHANNEL_1);//启动定时器2通道1比较输出中断
	HAL_TIM_OC_Start_IT(&htim2, TIM_CHANNEL_2);//启动定时器2通道2比较输出中断
	HAL_TIM_OC_Start_IT(&htim2, TIM_CHANNEL_3);//启动定时器2通道3比较输出中断
	HAL_TIM_OC_Start_IT(&htim2, TIM_CHANNEL_4);//启动定时器2通道4比较输出中断
	TIM_CCxChannelCmd(TIM2, TIM_CHANNEL_1, TIM_CCx_ENABLE);
	TIM_CCxChannelCmd(TIM2, TIM_CHANNEL_2, TIM_CCx_ENABLE);
	TIM_CCxChannelCmd(TIM2, TIM_CHANNEL_3, TIM_CCx_ENABLE);
	TIM_CCxChannelCmd(TIM2, TIM_CHANNEL_4, TIM_CCx_ENABLE);
	while(TIM2->CCER&0X1111);
	HAL_TIM_OC_Stop_IT(&htim2, TIM_CHANNEL_1);
	HAL_TIM_OC_Stop_IT(&htim2, TIM_CHANNEL_2);
	HAL_TIM_OC_Stop_IT(&htim2, TIM_CHANNEL_3);
	HAL_TIM_OC_Stop_IT(&htim2, TIM_CHANNEL_4);
	for(k=0;k<4;k++)
	{
	count[k]=0;
	num_callback[k]=0;
	status[k]=1;
	}
}

