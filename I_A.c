#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "font.h"
#include "ssd1306.h"
#include "ws2812.h"

// Definindo os pinos
#define BUTTON_1_PIN 5
#define BUTTON_2_PIN 6
#define BUTTON_3_PIN 22
#define BUZZER_PIN_1 21
#define BUZZER_PIN_2 10
#define LED_PIN 7
#define OLED_SDA_PIN 14
#define OLED_SCL_PIN 15

// Estados das emoções
typedef enum {
    HAPPY,
    SAD,
    ANGRY
} EmotionState;

EmotionState currentEmotion = HAPPY;

void setup();
void displayEmotion(EmotionState emotion);
void handleButton1Pressed();
void handleButton2Pressed();
void handleButton3Pressed();
void handleTick();
void setBuzzer(EmotionState emotion);
void updateLEDs(EmotionState emotion);
void updateDisplay(EmotionState emotion);

int main() {
    setup();

    while (1) {
        handleTick();
    }

    return 0;
}

void setup() {
    stdio_init_all();
    
    // Inicializando o I2C
    i2c_init(i2c0, 400000);
    gpio_set_function(OLED_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(OLED_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(OLED_SDA_PIN);
    gpio_pull_up(OLED_SCL_PIN);
    
    // Inicializando a matriz WS2812
    ws2812_init(LED_PIN);

    // Inicializando o display SSD1306
    ssd1306_init(i2c0, 0x3C);

    // Configurando os botões
    gpio_init(BUTTON_1_PIN);
    gpio_set_dir(BUTTON_1_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_1_PIN);
    
    gpio_init(BUTTON_2_PIN);
    gpio_set_dir(BUTTON_2_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_2_PIN);

    gpio_init(BUTTON_3_PIN);
    gpio_set_dir(BUTTON_3_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_3_PIN);

    // Configurando o buzzer
    gpio_init(BUZZER_PIN_1);
    gpio_set_dir(BUZZER_PIN_1, GPIO_OUT);

    gpio_init(BUZZER_PIN_2);
    gpio_set_dir(BUZZER_PIN_2, GPIO_OUT);

    // Exibindo a emoção inicial
    updateLEDs(currentEmotion);
    updateDisplay(currentEmotion);
}

void displayEmotion(EmotionState emotion) {
    switch (emotion) {
        case HAPPY:
            updateLEDs(HAPPY);
            updateDisplay(HAPPY);
            setBuzzer(HAPPY);
            break;
        case SAD:
            updateLEDs(SAD);
            updateDisplay(SAD);
            setBuzzer(SAD);
            break;
        case ANGRY:
            updateLEDs(ANGRY);
            updateDisplay(ANGRY);
            setBuzzer(ANGRY);
            break;
    }
}

void handleButton1Pressed() {
    // Perguntar "Como você está?"
    currentEmotion = HAPPY;  // Ou lógica para obter emoção
    displayEmotion(currentEmotion);
}

void handleButton2Pressed() {
    // Perguntar "Me dê um conselho"
    currentEmotion = SAD;  // Ou lógica para gerar um conselho
    displayEmotion(currentEmotion);
}

void handleButton3Pressed() {
    // Reiniciar a emoção para "feliz"
    currentEmotion = HAPPY;
    displayEmotion(currentEmotion);
}

void handleTick() {
    if (!gpio_get(BUTTON_1_PIN)) {
        sleep_ms(200);  // Anti-rebote
        handleButton1Pressed();
    }

    if (!gpio_get(BUTTON_2_PIN)) {
        sleep_ms(200);
        handleButton2Pressed();
    }

    if (!gpio_get(BUTTON_3_PIN)) {
        sleep_ms(200);
        handleButton3Pressed();
    }
}

void setBuzzer(EmotionState emotion) {
    switch (emotion) {
        case HAPPY:
            gpio_put(BUZZER_PIN_1, 1);
            gpio_put(BUZZER_PIN_2, 0);
            break;
        case SAD:
            gpio_put(BUZZER_PIN_1, 0);
            gpio_put(BUZZER_PIN_2, 1);
            break;
        case ANGRY:
            gpio_put(BUZZER_PIN_1, 1);
            gpio_put(BUZZER_PIN_2, 1);
            break;
    }
}

void updateLEDs(EmotionState emotion) {
    switch (emotion) {
        case HAPPY:
            ws2812_set_pixel(LED_PIN, 255, 255, 0);  // Amarelo
            break;
        case SAD:
            ws2812_set_pixel(LED_PIN, 0, 0, 255);  // Azul
            break;
        case ANGRY:
            ws2812_set_pixel(LED_PIN, 255, 0, 0);  // Vermelho
            break;
    }
}

void updateDisplay(EmotionState emotion) {
    ssd1306_clear();
    switch (emotion) {
        case HAPPY:
            ssd1306_draw_text(0, 0, "Feliz :)", 1);
            break;
        case SAD:
            ssd1306_draw_text(0, 0, "Triste :(", 1);
            break;
        case ANGRY:
            ssd1306_draw_text(0, 0, "Raiva >:(", 1);
            break;
    }
    ssd1306_update();
}
