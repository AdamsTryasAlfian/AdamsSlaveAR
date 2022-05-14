/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

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
#define portPWMMotor3_Pin GPIO_PIN_6
#define portPWMMotor3_GPIO_Port GPIOE
#define ENC0A_Pin GPIO_PIN_0
#define ENC0A_GPIO_Port GPIOA
#define ENC0B_Pin GPIO_PIN_1
#define ENC0B_GPIO_Port GPIOA
#define buzzer_Pin GPIO_PIN_4
#define buzzer_GPIO_Port GPIOA
#define portDir2Motor2_Pin GPIO_PIN_5
#define portDir2Motor2_GPIO_Port GPIOA
#define portPWMMotor1_Pin GPIO_PIN_6
#define portPWMMotor1_GPIO_Port GPIOA
#define portPWMMotor2_Pin GPIO_PIN_7
#define portPWMMotor2_GPIO_Port GPIOA
#define portDir1Motor0_Pin GPIO_PIN_4
#define portDir1Motor0_GPIO_Port GPIOC
#define portDir2Motor0_Pin GPIO_PIN_5
#define portDir2Motor0_GPIO_Port GPIOC
#define portDir1Motor1_Pin GPIO_PIN_0
#define portDir1Motor1_GPIO_Port GPIOB
#define portDir2Motor1_Pin GPIO_PIN_1
#define portDir2Motor1_GPIO_Port GPIOB
#define portDir1Motor3_Pin GPIO_PIN_2
#define portDir1Motor3_GPIO_Port GPIOB
#define portDir2Motor3_Pin GPIO_PIN_7
#define portDir2Motor3_GPIO_Port GPIOE
#define portDir1Motor2_Pin GPIO_PIN_8
#define portDir1Motor2_GPIO_Port GPIOD
#define ENC3A_Pin GPIO_PIN_15
#define ENC3A_GPIO_Port GPIOA
#define ENC3B_Pin GPIO_PIN_3
#define ENC3B_GPIO_Port GPIOB
#define ENC2A_Pin GPIO_PIN_4
#define ENC2A_GPIO_Port GPIOB
#define ENC2B_Pin GPIO_PIN_5
#define ENC2B_GPIO_Port GPIOB
#define ENC1A_Pin GPIO_PIN_6
#define ENC1A_GPIO_Port GPIOB
#define ENC1B_Pin GPIO_PIN_7
#define ENC1B_GPIO_Port GPIOB
#define portPWMMotor0_Pin GPIO_PIN_9
#define portPWMMotor0_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
