#include "ws2812.h"
#include "hardware/gpio.h"
#include "pico/stdlib.h"
#define WS2812_PIN 7

#define NUM_LEDS 25
static uint8_t led_data[NUM_LEDS * 3] = {0};

void send_bit(bool bit) {
    if (bit) {
        gpio_put(WS2812_PIN, 1);
        sleep_us(1);
        gpio_put(WS2812_PIN, 0);
        sleep_us(3);
    } else {
        gpio_put(WS2812_PIN, 1);
        sleep_us(3);
        gpio_put(WS2812_PIN, 0);
        sleep_us(1);
    }
}

void ws2812_init() {
    gpio_init(WS2812_PIN);
    gpio_set_dir(WS2812_PIN, GPIO_OUT);
}

void ws2812_set_pixel(uint32_t index, uint8_t red, uint8_t green, uint8_t blue) {
    if (index >= NUM_LEDS) return;
    uint32_t base_idx = index * 3;
    led_data[base_idx] = green;
    led_data[base_idx + 1] = red;
    led_data[base_idx + 2] = blue;
}

void ws2812_update() {
    for (int i = 0; i < NUM_LEDS; i++) {
        uint32_t base_idx = i * 3;
        uint8_t red = led_data[base_idx];
        uint8_t green = led_data[base_idx + 1];
        uint8_t blue = led_data[base_idx + 2];

        for (int j = 7; j >= 0; j--) {
            send_bit((green >> j) & 1);
            send_bit((red >> j) & 1);
            send_bit((blue >> j) & 1);
        }
    }
}
