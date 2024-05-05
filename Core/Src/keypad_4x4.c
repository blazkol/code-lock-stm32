/*
 * keypad_4x4.c
 *
 *  Created on: May 4, 2024
 *      Author: Blaze
 */
#include <stdbool.h>

#include "keypad_4x4.h"
#include "tim.h"
#include "gpio.h"

long int timer10 = 0;

void keypad_init(void)
{
	HAL_TIM_Base_Start_IT(&htim10);
}

char keypad_read(void)
{
  HAL_GPIO_WritePin(KP_R1_GPIO_Port, KP_R1_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(KP_R2_GPIO_Port, KP_R2_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(KP_R3_GPIO_Port, KP_R3_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(KP_R4_GPIO_Port, KP_R4_Pin, GPIO_PIN_SET);
  if (!(HAL_GPIO_ReadPin(KP_C4_GPIO_Port, KP_C4_Pin))) { return 'A'; }
  else if (!(HAL_GPIO_ReadPin(KP_C1_GPIO_Port, KP_C1_Pin))) { return '1'; }
  else if (!(HAL_GPIO_ReadPin(KP_C2_GPIO_Port, KP_C2_Pin))) { return '2'; }
  else if (!(HAL_GPIO_ReadPin(KP_C3_GPIO_Port, KP_C3_Pin))) { return '3'; }

  HAL_GPIO_WritePin(KP_R1_GPIO_Port, KP_R1_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(KP_R2_GPIO_Port, KP_R2_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(KP_R3_GPIO_Port, KP_R3_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(KP_R4_GPIO_Port, KP_R4_Pin, GPIO_PIN_SET);
  if (!(HAL_GPIO_ReadPin(KP_C4_GPIO_Port, KP_C4_Pin))) { return 'B'; }
  else if (!(HAL_GPIO_ReadPin(KP_C1_GPIO_Port, KP_C1_Pin))) { return '4'; }
  else if (!(HAL_GPIO_ReadPin(KP_C2_GPIO_Port, KP_C2_Pin))) { return '5'; }
  else if (!(HAL_GPIO_ReadPin(KP_C3_GPIO_Port, KP_C3_Pin))) { return '6'; }

  HAL_GPIO_WritePin(KP_R1_GPIO_Port, KP_R1_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(KP_R2_GPIO_Port, KP_R2_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(KP_R3_GPIO_Port, KP_R3_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(KP_R4_GPIO_Port, KP_R4_Pin, GPIO_PIN_SET);
  if (!(HAL_GPIO_ReadPin(KP_C4_GPIO_Port, KP_C4_Pin))) { return 'C'; }
  else if (!(HAL_GPIO_ReadPin(KP_C1_GPIO_Port, KP_C1_Pin))) { return '7'; }
  else if (!(HAL_GPIO_ReadPin(KP_C2_GPIO_Port, KP_C2_Pin))) { return '8'; }
  else if (!(HAL_GPIO_ReadPin(KP_C3_GPIO_Port, KP_C3_Pin))) { return '9'; }

  HAL_GPIO_WritePin(KP_R1_GPIO_Port, KP_R1_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(KP_R2_GPIO_Port, KP_R2_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(KP_R3_GPIO_Port, KP_R3_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(KP_R4_GPIO_Port, KP_R4_Pin, GPIO_PIN_RESET);
  if (!(HAL_GPIO_ReadPin(KP_C4_GPIO_Port, KP_C4_Pin))) { return 'D'; }
  else if (!(HAL_GPIO_ReadPin(KP_C1_GPIO_Port, KP_C1_Pin))) { return '*'; }
  else if (!(HAL_GPIO_ReadPin(KP_C2_GPIO_Port, KP_C2_Pin))) { return '0'; }
  else if (!(HAL_GPIO_ReadPin(KP_C3_GPIO_Port, KP_C3_Pin))) { return '#'; }

  return '\0';
}

char keypad_get_key(void)
{
  static bool pressed = false;

  char key = keypad_read();

  if (key == '\0')
  {
	timer10 = 0;
    pressed = false;
  }
  else if (timer10 > 10 && pressed == false)
  {
    pressed = true;
    return key;
  }

  return '\0';
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim-> Instance == TIM10)
	{
		timer10++;
	}
}
