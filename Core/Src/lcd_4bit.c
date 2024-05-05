/*
 * lcd_4bit.c
 *
 *  Created on: May 3, 2024
 *      Author: Blaze
 */
#include "lcd_4bit.h"
#include "gpio.h"

void lcd_nibble(unsigned char input_nibble)
{
  if (input_nibble & (1<<0)) HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, GPIO_PIN_SET);
  else HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, GPIO_PIN_RESET);

  if (input_nibble & (1<<1)) HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, GPIO_PIN_SET);
  else HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, GPIO_PIN_RESET);

  if (input_nibble & (1<<2)) HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, GPIO_PIN_SET);
  else HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, GPIO_PIN_RESET);

  if (input_nibble & (1<<3)) HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, GPIO_PIN_SET);
  else HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, GPIO_PIN_RESET);
}

void lcd_byte(unsigned char input_byte)
{
  HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, GPIO_PIN_SET);
  lcd_nibble(input_byte>>4);
  HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, GPIO_PIN_RESET);

  HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, GPIO_PIN_SET);
  lcd_nibble(input_byte);
  HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, GPIO_PIN_RESET);

  HAL_Delay(1);
}

void lcd_cmd(unsigned char cmd)
{
  HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, GPIO_PIN_RESET);
  lcd_byte(cmd);
}

void lcd_data(unsigned char data)
{
  HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, GPIO_PIN_SET);
  lcd_byte(data);
}

void lcd_init(void)
{
  HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, GPIO_PIN_SET);
  HAL_Delay(15);
  HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, GPIO_PIN_RESET);

  HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, GPIO_PIN_SET);
  lcd_nibble(0x03);
  HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, GPIO_PIN_RESET);
  HAL_Delay(1);
  HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, GPIO_PIN_SET);
  lcd_nibble(0x03);
  HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, GPIO_PIN_RESET);
  HAL_Delay(1);
  HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, GPIO_PIN_SET);
  lcd_nibble(0x03);
  HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, GPIO_PIN_RESET);
  HAL_Delay(1);
  HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, GPIO_PIN_SET);
  lcd_nibble(0x02);
  HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, GPIO_PIN_RESET);
  HAL_Delay(1);

  lcd_cmd( HD44780_FUNCTION_SET | HD44780_4_BIT | HD44780_TWO_LINE | HD44780_FONT5x7 );
  lcd_cmd( HD44780_DISPLAY_ONOFF | HD44780_DISPLAY_ON | HD44780_CURSOR_OFF );
  lcd_cmd( HD44780_ENTRY_MODE );
  lcd_cmd( HD44780_CLEAR );
  HAL_Delay(2);
}

void lcd_clear(void)
{
  lcd_cmd( HD44780_CLEAR );
  HAL_Delay(2);
}

void lcd_set_cursor(unsigned char x, unsigned char y)
{
  unsigned char xy = x + y * 0x40;
  lcd_cmd((xy | 0x80));
}

void lcd_move_cursor_left(void)
{
  lcd_cmd( HD44780_DISPLAY_CURSOR_SHIFT | HD44780_SHIFT_CURSOR | HD44780_SHIFT_LEFT );
}

void lcd_move_cursor_right(void)
{
  lcd_cmd( HD44780_DISPLAY_CURSOR_SHIFT | HD44780_SHIFT_CURSOR | HD44780_SHIFT_RIGHT );
}

void lcd_print_char(char data)
{
  lcd_data(data);
}

void lcd_print_str(char *data)
{
  while (*data) lcd_data(*data++);
}

