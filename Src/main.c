/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "bsp_stepmotor.h"
#include "bsp_move.h"
#include "bsp_servo.h"
#include "bsp_lifter.h"
#include "oled.h"
#include "control.h"
#include "bsp_catch.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

uint16_t step_to_run[4]={24000,24000,24000,24000}; //Ҫ�������еĲ���       �ܹ����в��� = ACCELERATED_SPEED_LENGTH*2 + step_to_run                   
float fre[ACCELERATED_SPEED_LENGTH]; //����洢���ٹ�����ÿһ����Ƶ�� 
unsigned short period[ACCELERATED_SPEED_LENGTH]; //���鴢����ٹ�����ÿһ����ʱ�����Զ�װ��ֵ   
uint32_t count[4]={0,0,0,0};
uint32_t num_callback[4]={0,0,0,0};
uint8_t status[4]={1,1,1,1};

 unsigned char BMP1[]=	
{

0x00,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x30,0xF0,0xFC,0xFC,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x7F,0x7F,0x00,0x00,0x00,0x00,0x00,/*"C:\Users\����\Desktop\1.bmp",0*/

};

 unsigned char BMP2[]=	
{

	0x00,0x00,0x00,0xC0,0xC0,0xFE,0xFE,0x3E,0x3E,0xFE,0xFE,0xFE,0xC0,0x00,0x00,0x00,
	0x00,0x00,0x00,0x0F,0x0F,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x30,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xC0,0xF8,0xFF,0xFF,0xFF,0x3F,0x00,0x00,0x00,
	0x00,0x00,0x00,0xF0,0xF0,0xFF,0xFF,0x7F,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x3C,0x3F,0x3F,0x3F,0x33,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x00,0x00,/*"C:\Users\����\Desktop\2.bmp",0*/

};

 unsigned char BMP3[]=	
{

	0x00,0x00,0xF8,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xF8,0xF8,0xF8,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0xFF,0xFF,0xFF,0xFF,0x7F,0x00,
	0x00,0x00,0x00,0x1E,0x1E,0x1E,0x1E,0x1F,0x1F,0xFF,0xFF,0xFF,0xFF,0xF9,0xE0,0x00,
	0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x83,0xFF,0xFF,0xFF,0xFF,0x18,
	0x00,0x3F,0x3F,0x7E,0x7E,0x7E,0x7E,0x7E,0x7E,0x7E,0x3F,0x3F,0x3F,0x07,0x01,0x00,/*"C:\Users\����\Desktop\3.bmp",0*/


};

 unsigned char BMPS[]=	
{

	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x3E,0x3E,0x3E,0x3E,0x3E,0xFF,0xFF,0xFF,0x3E,0x3E,0x3E,0x3E,0x3E,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x7F,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"C:\Users\����\Desktop\+.bmp",0*/


};


uint8_t ADmode = 0;//Ѳ��ģʽ

uint16_t step_to_runAD[4]={ADSTEP,ADSTEP,ADSTEP,ADSTEP};
float freAD[ACCELERATED_SPEED_LENGTH_AD]; //����洢���ٹ�����ÿһ����Ƶ�� 
unsigned short periodAD[ACCELERATED_SPEED_LENGTH_AD]; //���鴢����ٹ�����ÿһ����ʱ�����Զ�װ��ֵ   
uint32_t countAD[4]={0,0,0,0};
uint32_t num_callbackAD[4]={0,0,0,0};
uint8_t statusAD[4]={1,1,1,1};


uint8_t mission = 0;		//�������
uint8_t i = 0;					//ѭ������
uint8_t Openmvmission=0;//���͸�Openmv������
uint8_t j = 0;					//��ѭ��
uint8_t p = 0;
uint8_t o = 0;

uint8_t num = 0;

int error = 0;
uint8_t change1 = 0 ;		//Խ�����߱��
uint8_t change2 = 0;
uint8_t TrackSw = 0;		//Ѳ�߿���
uint8_t Track[1] = {0X57};  //���͸�ѭ����������ָ��
uint8_t TrackData[3] = {0};	//��ѭ�����������ص�����
uint8_t ADsign = 0;

uint8_t sign = 0;

uint8_t start_flag = 0; //���������ʼ
uint8_t start_flag_PID = 0;//PID��ʼ
uint8_t uwDirection=0;	//�����̷���
uint16_t CaptureNumber=0;//�����̶�ʱ���Ĵ���ֵ
uint16_t countsum=0;		//�����̼���
int Position = 0;				//��е������λ��

int CatchPosition = CATUP; 	//ץ�ϲ�����λ��

uint8_t mission_buf[7]={0}; //��Openmv��ȡ������
uint8_t Order_buf[1]={0};
uint8_t missioncmd[1]={0};			//���͸�Openmv��ָ��

//���͸�Openmv��ֵ 1Ϊ����������ȡ��2Ϊ��ʼ���ʶ��3Ϊ������ʶ��
//4Ϊ��ʼɫ��ʶ��5Ϊ���ɫ��ʶ��6Ϊ��ʼ����ʶ��7Ϊ�������ʶ��



#define ADLEFT 	2
#define ADRIGHT 3
#define ADFRONT 4
#define SCAN  3
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM1_Init();
  MX_TIM4_Init();
  MX_USART1_UART_Init();
  MX_TIM6_Init();
  MX_USART3_UART_Init();
  MX_I2C1_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
	  
	HAL_TIM_Base_Start(&htim2);//������ʱ��
	HAL_TIM_Base_Start_IT(&htim6);
	//HAL_TIM_Base_Start_IT(&htim7);
	
	#if 1  //�������
	Move_Enable;
	CalculateSModelLine(fre,period,ACCELERATED_SPEED_LENGTH,FRE_MAX,FRE_MIN,4);
	CalculateSModelLine(freAD,periodAD,ACCELERATED_SPEED_LENGTH_AD,FRE_MAX+11000,FRE_MAX,4);//��������
	#endif
/* USER CODE BEGIN 2 */
	
	#if 1  //ֱ���������
	HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);
	Lifter_Init();
	#endif
	
	#if 1//�����ʼ��
	Servo_Init();
	#endif
	
	#if 1 //OLED��ʼ��
  OLED_Init();
	OLED_CLS();
	#endif
	
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1)
	{
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		
		#if 1
		start_flag = 1;//��ʼ�������
		Position = 10000; //��ֹ
		start_flag_PID = 1;
		//HAL_Delay(1000);
		#endif
		
//		#if 1
//		Position = TOP; //����
//		HAL_Delay(2000);
//		Catch_Control(0);
//		Rotate_Control(0);
//		HAL_Delay(1000);
//		#endif
//		Position = CATDOWN; //����
//		
//		while(1);
		mission = 1;//���˰������
		Move_Step(BACKWORD,20000);
		HAL_Delay(200);
		
		#if 1
		Position = TOP; //����
		HAL_Delay(2000);
		Catch_Control(0);
		Rotate_Control(0);
		HAL_Delay(1000);
		#endif
		
		mission = 2;//��������Ѳ��
		ADsign = 1;
		Move_Step(LEFT,40000);
		HAL_Delay(200);
		
		#if 1
		Openmvmission = 1;//����openmv����
		missioncmd[0]=1;
		HAL_UART_Receive_IT(&huart3, mission_buf, sizeof(mission_buf));//���������жϽ�������
		while(sign==0)
		{
			HAL_UART_Transmit(&huart3, (uint8_t*)missioncmd,sizeof(missioncmd),0XFFFF);
			HAL_Delay(500);
			//printf("%c",mission_buf[0]);
		}
		sign = 0;//��λ
		#endif
		
		mission = 3;//�����ĸ�Ѳ��
		ADsign = 1;
		Move_Step(LEFT,40000);
		HAL_Delay(500);	
		
		for(j=0;j<2;j++)
		{
		#if 1
		Openmvmission = 2;//����openmv����
		if(j==0)
		{
			missioncmd[0]=2;//��һ�η���2���ϲ�
		}
		else if(j==1)
		{
			mission_buf[0]=mission_buf[4];
			mission_buf[1]=mission_buf[5];
			mission_buf[2]=mission_buf[6];//�Ѻ��������ֵ��ǰ����Ԫ��
			missioncmd[0]=3;//�ڶ��η���3���²�
		}
		HAL_UART_Receive_IT(&huart3, Order_buf, sizeof(Order_buf));//���������жϽ�������
		while(sign==0)
		{
			HAL_UART_Transmit(&huart3, (uint8_t*)missioncmd,sizeof(missioncmd),0XFFFF);
			HAL_Delay(500);
			//printf("%d",Order_buf[0]);
		}
		sign = 0;
		
		if(j==0)//��һ��
		{
			CatchPosition = CATUP;
		}
		else if(j==1)//�ڶ���
		{
			CatchPosition = CATDOWN;
		}
		CatchWithMission1(); //ץ��һ������
		CatchWithMission2(); //ץ�ڶ�������
		CatchWithMission3(); //ץ����������
		MoveBack();//�ص�ԭ��

		#endif
		
		
		mission = 4;//��ת90��
		Move_Step(TURN_LEFT,6000);
		HAL_Delay(500);	
		
		mission = 5;//��������Ѳ�����ּӹ���
		ADsign = 1;
		Move_Step(LEFT,40000);
		HAL_Delay(500);
		
		Move_Step(BACKWORD,300);
		
		mission = 14;//ǰ����ץȡ
		Move_Step(FORWORD,20000);
		HAL_Delay(500);
		
		#if 1
		PutWithOrder1();			//���õ�һ������
		PutWithOrder2();			//���õڶ�������
		PutWithOrder3();			//���õ���������
		MoveBack2();					//�ּӹ����ص�ԭ��
		CatchWithOrder1();
		CatchWithOrder2();
		CatchWithOrder3();
		MoveBack3();					//�ּӹ����ص���ɫ��
		#endif
		
//		Move_Step(LEFT,6850);
//		HAL_Delay(500);	
		
		mission = 6;//��������
		ADsign = 1;
		Move_Step(LEFT,40000);
		HAL_Delay(200);	
		
//		mission = 7;//��ת90��
//		Move_Step(TURN_LEFT,6000);
//		HAL_Delay(500);	
		
		Move_Step(TURN_LEFT,TURN90);//��ת90��
		HAL_Delay(200);	
		
		mission = 8;//�������������Ʒ��
		ADsign = 1;
		Move_Step(LEFT,40000);
		HAL_Delay(200);	
		
		#if 1
		if(j==0)
		{
			PutWithOrderCU1();			//���Ʒ����������
			PutWithOrderCU2();			//
			PutWithOrderCU3();
		}
		else if(j==1)
		{
			PutWithOrderCU4();			//���Ʒ����������
			PutWithOrderCU5();			//
			PutWithOrderCU6();
		}
		
		MoveBack2();		//�ص�ԭ��
		//Move_Step(BACKWORD,1900);
		#endif
		if(j==0)//��ʼ�ڶ���
		{
		mission = 9;//��ת90��
		Move_Step(TURN_LEFT,6000);
		HAL_Delay(200);	
			
//		Move_Step(TURN_LEFT,TURN90);//��ת90��
//		HAL_Delay(500);	
		
		mission = 10;//�������
		ADsign = 1;
		Move_Step(LEFT,40000);
		HAL_Delay(200);	
		
			
		Move_Step(TURN_LEFT,TURN90);//��ת90��
		HAL_Delay(200);	
			
//		mission = 11;//��ת90��
//		Move_Step(TURN_LEFT,6000);
//		HAL_Delay(500);	
		
		//Move_Step(LEFT,1500);
			
		mission = 12;//��������
		ADsign = 1;
		Move_Step(LEFT,40000);
		HAL_Delay(200);	
		}
		}
	mission = 13;//��������
	//ADsign = 1;
	Move_Step(LEFT,40000);
	
	Move_Step(FORWORD,4300);
	while(1);
  }

  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == htim6.Instance) //�ж��Ƿ�ʱ��6
		{
//			if(TrackSw == 1)
//			{
//				HAL_UART_Receive_IT(&huart2, TrackData, sizeof(TrackData));//���������жϣ����ݸ���Ӧ����
//				HAL_UART_Transmit(&huart2, (uint8_t*)Track,sizeof(Track),0XFFFF);  //�ô�������������
//				TrackSw = 0;
//			}
	if(ADsign == 1)  //1Ϊ�����߲�������2Ϊ�����߲�����
	{
		if(TrackLM==1&&TrackLL==0&&TrackLR==0)
		{
			p=0;
			//ADmode = 0;//����ѭ��
		}
		else if(TrackLM==1&&TrackLL==1&&TrackLR==1)
		{
			p=0;
			//ADmode = 0;//����ѭ��
		}
//		else if(TrackLM==1&&TrackLL==1&&TrackLR==1)
//		{
//			k=0;
//			//ADmode = 0;//����ѭ��
//		}
		else if(TrackLL==1&&status[3]==3)
		{
			p+=1;
			if(ADmode == 0&&p>=SCAN)
			{
				for(i=0;i<4;i++)
				{
				countAD[i]=0;
				num_callbackAD[i]=0;
				statusAD[i]=1;
				step_to_runAD[i]=ADSTEP;
				}
				statusAD[0] = 0;//���ֲ���
				statusAD[1] = 0;
				ADmode = 1;
				p=0;
			}
			//ǰ��һ�𶯿�һ��
		}
		else if(TrackLR==1&&status[3]==3)
		{
			p+=1;
			if(ADmode == 0&&p>=SCAN)
			{
				for(i=0;i<4;i++)
				{
				countAD[i]=0;
				num_callbackAD[i]=0;
				statusAD[i]=1;
				step_to_runAD[i]=ADSTEP;
				}
				statusAD[2] = 0;//ǰ�ֲ���
				statusAD[3] = 0;
				ADmode = 1;
				p=0;
			}
			//����һ�𶯿�һ��
		}
	}
			if(mission==1)//�������ڶ������ߺ���
			{
				if(TrackRR==1)
				{
					change1=1;
				}
				if((change1==1)&&(TrackRR==0))
				{
					change1=0;//��λ
					num+=1;
				}
				if(num>=2)
				{
					for(i=0;i<4;i++)
					{
						step_to_run[i]=700;
					}
					mission=0;
					num=0;//��λ
					ADsign = 0;//�رյ���
					ADmode = 0;
				}
			}
				
			if(mission==2)//��⵽��������
			{
				if(TrackRR==1)
					{
						change1=1;
					}
					if((change1==1)&&(TrackRR==0))
					{
						change1=0;//��λ
						num+=1;
					}
				if(num==2)
				{
					for(i=0;i<4;i++)
					{
						step_to_run[i]=1500;
					}
					mission=0;
					num=0;//��λ
					ADsign = 0;//�رյ���
					ADmode = 0;
				}
			}
			if(mission==3)//��⵽�������ߵ�ԭ����
			{
				if(TrackRR==1)
				{
					change1=1;
				}
				if((change1==1)&&(TrackRR==0))
				{
					change1=0;//��λ
					num+=1;
				}
				if(num>=3)
				{
					for(i=0;i<4;i++)
						{
						step_to_run[i]=TrackPre;
						}
					mission=0;
					num=0;//��λ
					ADsign = 0;//�رյ���
					ADmode = 0;
				}
			}
			if((mission==4)&&(TrackLL==1))//��ת90�㲢��⵽����
			{
				for(i=0;i<4;i++)
				{
					step_to_run[i]=470;
				}
				mission=0;
				num=0;//��λ
				ADsign = 0;//�رյ���
				ADmode = 0;
			}
			
			if(mission==5)//��������Ѳ��
			{
				if(TrackRR==1)
				{
					change1=1;
				}
				if((change1==1)&&(TrackRR==0))
				{
					change1=0;//��λ
					num+=1;
				}
					if(num>=2)
					{
						for(i=0;i<4;i++)
							{
							step_to_run[i]=TrackPre;
							}
							o++;
							if(o>=2)
							{
							num=0;//��λ
							mission=0;
							ADsign = 0;//�رյ���
							ADmode = 0;
								o=0;
							}
					}
			}
			
			if(mission==6)//��������Ѳ��
			{
				if(TrackRR==1)
				{
					change1=1;
				}
				if((change1==1)&&(TrackRR==0))
				{
					change1=0;//��λ
					num+=1;
				}
					if(num>=1)
					{
						for(i=0;i<4;i++)
							{
							step_to_run[i]=TrackPre;
							}
							o++;
							if(o>=2)
							{
							num=0;//��λ
							mission=0;
							ADsign = 0;//�رյ���
							ADmode = 0;
								o=0;
							}
					}
			}
			
			if((mission==7)&&(TrackRL==1))//��ת90��
			{
					for(i=0;i<4;i++)
					{
						step_to_run[i]=100;
					}
					mission=0;
					num=0;//��λ
					ADsign = 0;//�رյ���
					ADmode = 0;
			}
			
			if(mission==8)//����3�񲢵���
			{
				if(TrackRR==1)
				{
					change1=1;
				}
				if((change1==1)&&(TrackRR==0))
				{
					change1=0;//��λ
					num+=1;
				}
					if(num>=2)
					{
						for(i=0;i<4;i++)
							{
							step_to_run[i]=TrackPre;
							}
											o++;
							if(o>=2)
							{
							num=0;//��λ
							mission=0;
							ADsign = 0;//�رյ���
							ADmode = 0;
								o=0;
							}
					}
			}
			
			if((mission==9)&&(TrackLL==1))//��ת90��
			{
					for(i=0;i<4;i++)
					{
						step_to_run[i]=470;
					}
					mission=0;
					num=0;//��λ
					ADsign = 0;//�رյ���
					ADmode = 0;
			}
			if(mission==10)//����5�񲢵���
			{
				if(TrackRR==1)
				{
					change1=1;
				}
				if((change1==1)&&(TrackRR==0))
				{
					change1=0;//��λ
					num+=1;
				}
					if(num>=4)
					{
						for(i=0;i<4;i++)
							{
							step_to_run[i]=TrackPre;
							}
							o++;
							if(o>=2)
							{
							num=0;//��λ
							mission=0;
							ADsign = 0;//�رյ���
							ADmode = 0;
								o=0;
							}
					}
			}
			
			if((mission==11)&&(TrackRL==1))//��ת90��
			{
					for(i=0;i<4;i++)
					{
						step_to_run[i]=100;
					}
					mission=0;
					num=0;//��λ
					ADsign = 0;//�رյ���
					ADmode = 0;
			}
			
			if(mission==12)//����2�񲢵���
			{
				if(TrackRR==1)
				{
					change1=1;
				}
				if((change1==1)&&(TrackRR==0))
				{
					change1=0;//��λ
					num+=1;
				}
					if(num>=1)
					{
						for(i=0;i<4;i++)
							{
							step_to_run[i]=TrackPre;
							}
							o++;
							if(o>=3)
							{
							num=0;//��λ
							mission=0;
							ADsign = 0;//�رյ���
							ADmode = 0;
								o=0;
							}
					}
			}
			if(mission==13)//����3�񲢵���
			{
				if(TrackLM==1)
				{
					change1=1;
				}
				if((change1==1)&&(TrackLM==0))
				{
					change1=0;//��λ
					num+=1;
				}
					if(num>=3)
					{
						for(i=0;i<4;i++)
							{
							step_to_run[i]=2400;
							}
							num=0;//��λ
							mission=0;
							ADsign = 0;//�رյ���
							ADmode = 0;
					}
			}
			
			if(mission==14)//����2�񲢵���
			{
				if(TrackLR==1)
				{
					change1=1;
				}
				if((change1==1)&&(TrackLR==0))
				{
					change1=0;//��λ
					num+=1;
				}
					if(num>=1)
					{
						for(i=0;i<4;i++)
							{
							step_to_run[i]=3450;
							}
						mission=0;
						num=0;//��λ
						ADsign = 0;//�رյ���
						ADmode = 0;
					}
			}
			if(start_flag) // �ȴ����������ſ�ʼ��ʱ
			{
				/* Get the current direction */
				uwDirection = __HAL_TIM_IS_TIM_COUNTING_DOWN(&htim4);     
				CaptureNumber=__HAL_TIM_GET_COUNTER(&htim4);
				countsum=10000+CaptureNumber;	
			}
			if(start_flag_PID)
			{
				// 1.��ȡ���λ��
				GetMotorPulse();
				
				// 2.PID��������ȡ��ռ�ձ�
				MotorOutput = SpeedInnerControl(Position,MotorSpeed);
				
				// 3.��ռ�ձȵ�����������ƺ���
				Lifter_Control(MotorOutput);
				#if 0						//��ӡ������
				l++;
				if(l>100)
				{
					//��ӡ��ʱ��4�ļ���ֵ��short��-32768����32767��
					//printf("��ǰλ�� = %d ռ�ձ� = %d \r\n",MotorSpeed,MotorOutput);	
					l=0;
				}
				#endif
			}
		}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance == USART3)
	{
		if(Openmvmission == 1)
		{
			uint8_t i = 0;
			OLED_CLS();
			for(i=0;i<7;i++)
			{
				switch (mission_buf[i])
				{
					case '1':
					//OLED_ShowChar(1+i*16,4,'1',16);
					OLED_DrawBMP(1+i*16,0,17+i*16,6,BMP1);
					break;
					case '2':
					//OLED_ShowChar(1+i*16,4,'2',16);
					OLED_DrawBMP(1+i*16,0,17+i*16,6,BMP2);
					break;
					case '3':
					//OLED_ShowChar(1+i*16,4,'3',16);
					OLED_DrawBMP(1+i*16,0,17+i*16,6,BMP3);
					break;
					case '+':
					//OLED_ShowChar(1+i*16,4,'+',16);
					OLED_DrawBMP(1+i*16,0,17+i*16,6,BMPS);
					break;
					default:
					break;
				}
			}
			sign = 1;
		}
		if(Openmvmission == 2 )
		{
			sign = 1;
		}
	}
	if(huart->Instance == USART2)  //ѭ����������������
	{
		if(((TrackData[0] >> 1)%2) == 1)		//������
		{
			if(((TrackData[0] >> 3)%2) == 0)		//����������
			{
				if(TrackData[0]%2 == 0)     //��ƫ��
				{
					error = -((TrackData[1]<<8)|TrackData[2]);	//���ֵ
					//printf("��ƫ��%d",error);
					ADsign=ADLEFT;
				}
				else if(TrackData[0]%2 == 1)		//��ƫ��
				{
					error = ((TrackData[1]<<8)|TrackData[2]);  //���ֵ
					//printf("��ƫ��%d",error);
					ADsign=ADRIGHT;
				}
			}
			else if(((TrackData[0] >> 3)%2) == 1)		//ȫ��������
			{
				printf("ȫ��������");
			}
		}	
		else if(((TrackData[0] >> 1)%2) == 0)		//����
		{
			if(((TrackData[0] >> 2)%2) == 0)		//�����
			{
				printf("�����");
			}
			else if(((TrackData[0] >> 2)%2) == 1)		//�ҳ���
			{
				printf("�ҳ���");
			}
		}
	}
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
