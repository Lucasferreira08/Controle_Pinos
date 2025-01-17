#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define LED_VERMELHO_GPIO 13

void inicializa_led_vermelho() {
    gpio_init(LED_VERMELHO_GPIO);
    gpio_set_dir(LED_VERMELHO_GPIO, GPIO_OUT);
}

int main() {
    stdio_init_all();
    inicializa_led_vermelho();

    bool led_ligado = false; // Estado atual do LED

    while (true) {
        char tecla = '\0';

        // Verifica se há uma tecla pressionada
        if (scanf("%c", &tecla) == 1) {
            if (tecla == 'A') { // Tecla associada ao LED vermelho
                gpio_put(LED_VERMELHO_GPIO, 1); // Liga o LED
                led_ligado = true;
            }
        }

        // Se nenhuma tecla está sendo pressionada, desliga o LED
        if (led_ligado && tecla != 'A') {
            gpio_put(LED_VERMELHO_GPIO, 0); // Desliga o LED
            led_ligado = false;
        }

        // Pequeno atraso para evitar leituras excessivas
        sleep_ms(100);
    }

    return 0;
}
