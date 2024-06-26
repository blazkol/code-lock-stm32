/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define LD1_Pin GPIO_PIN_0
#define LD1_GPIO_Port GPIOC
#define LD0_Pin GPIO_PIN_1
#define LD0_GPIO_Port GPIOC
#define LCD_D7_Pin GPIO_PIN_0
#define LCD_D7_GPIO_Port GPIOA
#define LCD_D6_Pin GPIO_PIN_1
#define LCD_D6_GPIO_Port GPIOA
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LCD_D5_Pin GPIO_PIN_4
#define LCD_D5_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define KP_C4_Pin GPIO_PIN_7
#define KP_C4_GPIO_Port GPIOA
#define LCD_D4_Pin GPIO_PIN_0
#define LCD_D4_GPIO_Port GPIOB
#define KP_R3_Pin GPIO_PIN_10
#define KP_R3_GPIO_Port GPIOB
#define KP_C2_Pin GPIO_PIN_7
#define KP_C2_GPIO_Port GPIOC
#define KP_R4_Pin GPIO_PIN_8
#define KP_R4_GPIO_Port GPIOA
#define KP_C1_Pin GPIO_PIN_9
#define KP_C1_GPIO_Port GPIOA
#define LCD_RS_Pin GPIO_PIN_10
#define LCD_RS_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define LCD_EN_Pin GPIO_PIN_3
#define LCD_EN_GPIO_Port GPIOB
#define KP_R2_Pin GPIO_PIN_4
#define KP_R2_GPIO_Port GPIOB
#define KP_R1_Pin GPIO_PIN_5
#define KP_R1_GPIO_Port GPIOB
#define KP_C3_Pin GPIO_PIN_6
#define KP_C3_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
