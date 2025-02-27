#ifndef WS2812_H
#define WS2812_H

#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define WS2812_PIN 7 // Altere conforme necessário

void ws2812_init();
void ws2812_set_pixel(uint32_t index, uint8_t red, uint8_t green, uint8_t blue);
void ws2812_update();

#endif // WS2812_H
