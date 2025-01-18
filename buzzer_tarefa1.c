#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "teclado_matricial/teclado_matricial.h"

// Definindo o pino do buzzer
#define BUZZER_PIN 21

void setup() {
    stdio_init_all();

    // Inicializa o pino do buzzer
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);

    // teclado matricial pra configuracao
    set_rows_output();
    set_cols_input();
}

void acionar_buzzer() {
    gpio_put(BUZZER_PIN, true); // Liga o buzzer
    sleep_ms(2000);              // Aguardar 2 segundos
    gpio_put(BUZZER_PIN, false); // Desliga o buzzer
}

int main() {
    setup();

    while (true) {
        char tecla = detect_button(); // Detecta a tecla pressionada no teclado
        printf("Tecla pressionada: %c\n", tecla);

        // Aciona o buzzer se a tecla for pressionada
        if (tecla == '*') {
            acionar_buzzer(); // Aciona o buzzer
        }

        sleep_ms(100);
    }

    return 0;
}
