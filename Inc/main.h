/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED1_Pin GPIO_PIN_5
#define LED1_GPIO_Port GPIOE
#define TRACK_LEFT_L_Pin GPIO_PIN_0
#define TRACK_LEFT_L_GPIO_Port GPIOF
#define TRACK_LEFT_M_Pin GPIO_PIN_1
#define TRACK_LEFT_M_GPIO_Port GPIOF
#define TRACK_LEFT_R_Pin GPIO_PIN_2
#define TRACK_LEFT_R_GPIO_Port GPIOF
#define TRACK_RIGHT_L_Pin GPIO_PIN_3
#define TRACK_RIGHT_L_GPIO_Port GPIOF
#define TRACK_RIGHT_M_Pin GPIO_PIN_4
#define TRACK_RIGHT_M_GPIO_Port GPIOF
#define TRACK_RIGHT_R_Pin GPIO_PIN_5
#define TRACK_RIGHT_R_GPIO_Port GPIOF
#define STEP_Left_Front_Pin GPIO_PIN_0
#define STEP_Left_Front_GPIO_Port GPIOA
#define STEP_Right_Front_Pin GPIO_PIN_1
#define STEP_Right_Front_GPIO_Port GPIOA
#define STEP_Left_Back_Pin GPIO_PIN_2
#define STEP_Left_Back_GPIO_Port GPIOA
#define STEP_Right_Back_Pin GPIO_PIN_3
#define STEP_Right_Back_GPIO_Port GPIOA
#define DIR_Left_Front_Pin GPIO_PIN_4
#define DIR_Left_Front_GPIO_Port GPIOA
#define DIR_Right_Front_Pin GPIO_PIN_5
#define DIR_Right_Front_GPIO_Port GPIOA
#define DIR_Left_Back_Pin GPIO_PIN_6
#define DIR_Left_Back_GPIO_Port GPIOA
#define DIR_Right_Back_Pin GPIO_PIN_7
#define DIR_Right_Back_GPIO_Port GPIOA
#define ENABLE_Pin GPIO_PIN_4
#define ENABLE_GPIO_Port GPIOC
#define PWM__Pin GPIO_PIN_8
#define PWM__GPIO_Port GPIOE
#define PWM_E9_Pin GPIO_PIN_9
#define PWM_E9_GPIO_Port GPIOE
#define A_Pin GPIO_PIN_12
#define A_GPIO_Port GPIOD
#define B_Pin GPIO_PIN_13
#define B_GPIO_Port GPIOD
#define Catch_Pin GPIO_PIN_6
#define Catch_GPIO_Port GPIOC
#define Rotate_Pin GPIO_PIN_7
#define Rotate_GPIO_Port GPIOC
#define LED0_Pin GPIO_PIN_5
#define LED0_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
#define TrackLM HAL_GPIO_ReadPin(TRACK_LEFT_M_GPIO_Port, TRACK_LEFT_M_Pin)
#define TrackLL HAL_GPIO_ReadPin(TRACK_LEFT_L_GPIO_Port, TRACK_LEFT_L_Pin)
#define TrackLR HAL_GPIO_ReadPin(TRACK_LEFT_R_GPIO_Port, TRACK_LEFT_R_Pin)
#define TrackRM HAL_GPIO_ReadPin(TRACK_RIGHT_M_GPIO_Port, TRACK_RIGHT_M_Pin)
#define TrackRL HAL_GPIO_ReadPin(TRACK_RIGHT_L_GPIO_Port, TRACK_RIGHT_L_Pin)
#define TrackRR HAL_GPIO_ReadPin(TRACK_RIGHT_R_GPIO_Port, TRACK_RIGHT_R_Pin)

#define TURN90 2700   //×ª90¡ãµÄÂö³åÊý
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
