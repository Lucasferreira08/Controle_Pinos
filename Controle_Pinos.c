#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "teclado_matricial/teclado_matricial.h"

// Definição dos LEDs
#define GPIO_LED_RED 18
#define GPIO_LED_GREEN 17
#define GPIO_LED_BLUE 16

// Definição do buzzer
#define BUZZER_PIN 21

void setup_buzzer() {
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);
}

void acionar_buzzer() {
    gpio_put(BUZZER_PIN, true); // Liga o buzzer
    sleep_ms(2000);             // Espera 2 segundos
    gpio_put(BUZZER_PIN, false); // Desliga o buzzer
}

void setup_leds() {
    gpio_init(GPIO_LED_RED);
    gpio_init(GPIO_LED_GREEN);
    gpio_init(GPIO_LED_BLUE);
    gpio_set_dir(GPIO_LED_RED, GPIO_OUT);
    gpio_set_dir(GPIO_LED_GREEN, GPIO_OUT);
    gpio_set_dir(GPIO_LED_BLUE, GPIO_OUT);
}

void controlar_leds(char tecla) {
    // Controle dos LEDs com base na tecla pressionada
    gpio_put(GPIO_LED_RED, tecla == '*' || tecla == 'A');
    gpio_put(GPIO_LED_GREEN, tecla == '*' || tecla == 'B');
    gpio_put(GPIO_LED_BLUE, tecla == '*' || tecla == 'C');
}

int main() {
    stdio_init_all();
    setup_leds();
    setup_buzzer();

    set_rows_output();
    set_cols_input();

    while (true) {
        char tecla = detect_button(); // Armazena a tecla detectada
        printf("Tecla pressionada: %c\n", tecla);

        controlar_leds(tecla); // Controla os LEDs com base na tecla

        if (tecla == '#') {
            acionar_buzzer(); // Aciona o buzzer
        }

        sleep_ms(100); // Delay para evitar múltiplas leituras rápidas
    }
}
