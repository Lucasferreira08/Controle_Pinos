 buzzer.h
#include "buzzer.h"

// Inicializa o pino do buzzer
void buzzer_init() {
    gpio_init(BUZZER_PIN);          // Inicializa o pino do buzzer
    gpio_set_dir(BUZZER_PIN, GPIO_OUT); // Define o pino como saída
    buzzer_off();                   // Garante que o buzzer comece desligado
}

// Liga o buzzer
void buzzer_on() {
    gpio_put(BUZZER_PIN, true);     // Liga o buzzer
}

// Desliga o buzzer
void buzzer_off() {
    gpio_put(BUZZER_PIN, false);    // Desliga o buzzer
}
