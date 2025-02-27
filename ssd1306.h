#ifndef SSD1306_H
#define SSD1306_H

#include "pico/stdlib.h"
#include "hardware/i2c.h"

#define SSD1306_WIDTH 128
#define SSD1306_HEIGHT 64

void ssd1306_init(i2c_inst_t *i2c, uint8_t address);
void ssd1306_clear();
void ssd1306_set_text_size(uint8_t size);
void ssd1306_set_text_color(uint16_t color);
void ssd1306_draw_text(int x, int y, const char *text, uint16_t color);
void ssd1306_update();

#endif // SSD1306_H
