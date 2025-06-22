#include "i2c-lcd.h"
#include "stm32f4xx_hal.h"

extern I2C_HandleTypeDef hi2c1;

#define LCD_BACKLIGHT 0x08
#define ENABLE 0x04

void lcd_send_cmd(char cmd)
{
    char data_u = cmd & 0xF0;
    char data_l = (cmd << 4) & 0xF0;
    uint8_t data_t[4];
    data_t[0] = data_u | LCD_BACKLIGHT | ENABLE;
    data_t[1] = data_u | LCD_BACKLIGHT;
    data_t[2] = data_l | LCD_BACKLIGHT | ENABLE;
    data_t[3] = data_l | LCD_BACKLIGHT;
    HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDR, data_t, 4, 100);
    HAL_Delay(5);
}

void lcd_send_data(char data)
{
    char data_u = data & 0xF0;
    char data_l = (data << 4) & 0xF0;
    uint8_t data_t[4];
    data_t[0] = data_u | LCD_BACKLIGHT | ENABLE | 0x01;
    data_t[1] = data_u | LCD_BACKLIGHT | 0x01;
    data_t[2] = data_l | LCD_BACKLIGHT | ENABLE | 0x01;
    data_t[3] = data_l | LCD_BACKLIGHT | 0x01;
    HAL_I2C_Master_Transmit(&hi2c1, LCD_ADDR, data_t, 4, 100);
    HAL_Delay(5);
}

void lcd_clear(void)
{
    lcd_send_cmd(0x01);
    HAL_Delay(2);
}

void lcd_put_cur(int row, int col)
{
    uint8_t pos[] = {0x80, 0xC0, 0x94, 0xD4};
    lcd_send_cmd(pos[row] + col);
}

void lcd_send_string(char *str)
{
    while (*str) lcd_send_data(*str++);
}

void lcd_init(void)
{
    HAL_Delay(50);
    lcd_send_cmd(0x30);
    HAL_Delay(5);
    lcd_send_cmd(0x30);
    HAL_Delay(1);
    lcd_send_cmd(0x30);
    lcd_send_cmd(0x20);
    HAL_Delay(1);
    lcd_send_cmd(0x28);
    HAL_Delay(1);
    lcd_send_cmd(0x08);
    lcd_send_cmd(0x01);
    HAL_Delay(2);
    lcd_send_cmd(0x06);
    lcd_send_cmd(0x0C);
}
