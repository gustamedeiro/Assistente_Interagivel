#include "ssd1306.h"
#include "hardware/i2c.h"

static i2c_inst_t *i2c_instance;
static uint8_t i2c_address;

// Comandos de inicialização para o SSD1306
static const uint8_t init_sequence[] = {
    0xAE, 0xA8, 0x3F, 0xD3, 0x00, 0x40, 0x8D, 0x14, 0x20, 0x00,
    0xA1, 0xC8, 0xDA, 0x12, 0x81, 0x7F, 0xA4, 0xA6, 0xD5, 0x80,
    0x8D, 0x14, 0xAF
};

void ssd1306_init(i2c_inst_t *i2c, uint8_t address) {
    i2c_instance = i2c;
    i2c_address = address;

    i2c_write_blocking(i2c_instance, i2c_address, init_sequence, sizeof(init_sequence), false);
}

void ssd1306_clear() {
    uint8_t clear_buffer[SSD1306_WIDTH * SSD1306_HEIGHT / 8] = {0};  // Tela 128x64
    i2c_write_blocking(i2c_instance, i2c_address, clear_buffer, sizeof(clear_buffer), false);
}

void ssd1306_set_text_size(uint8_t size) {
    // Definir o tamanho do texto. Aqui você pode adicionar lógica para manipular tamanhos diferentes.
}

void ssd1306_set_text_color(uint16_t color) {
    // Definir a cor do texto, mas isso pode ser uma limitação do SSD1306 (apenas preto ou branco)
}

void ssd1306_draw_text(int x, int y, const char *text, uint16_t color) {
    // Implementar a função para desenhar o texto no display
    // Para simplicidade, não vamos detalhar a codificação de fontes aqui, mas um método básico seria
    // usar uma tabela de caracteres para mapear cada letra para um padrão de pixels.
    // Isso exigiria um buffer de dados para o texto e a escrita desses dados no display via I2C.
}

void ssd1306_update() {
    // Após desenhar o texto ou fazer outras atualizações, envie os dados para o display.
    // Isso pode envolver enviar blocos de memória de pixel para o display via I2C.
}
