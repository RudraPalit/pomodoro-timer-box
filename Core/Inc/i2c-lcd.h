#ifndef __I2C_LCD_H__
#define __I2C_LCD_H__

#include "stm32f4xx_hal.h"

// 0x27 is the address
#define LCD_ADDR (0x27 << 1)

extern I2C_HandleTypeDef hi2c1;

void lcd_init(void);
void lcd_send_cmd(char cmd);
void lcd_send_data(char data);
void lcd_send_string(char *str);
void lcd_put_cur(int row, int col);
void lcd_clear(void);

#endif
