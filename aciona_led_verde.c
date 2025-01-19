#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define GPIO_LED_VERDE 11

void setup() {
    gpio_init(GPIO_LED_VERDE);
    gpio_set_dir(GPIO_LED_VERDE, GPIO_OUT);
}

int aciona_led_verde() {
    // Chama função de inicialização da GPIO
    setup();

    // Inicializa todos os códigos stdio padrão que estão ligados ao binário
    stdio_init_all();

    bool led_state = gpio_get(GPIO_LED_VERDE); // Estado atual do LED

    while (true) {
        char tecla = '\0';

        // Verifica se alguma tecla do teclado foi pressionada
        if (scanf("%c", &tecla) == 1) {
            if (tecla == 'D') { // Verifica se a tecla "D" foi pressionada
                gpio_put(GPIO_LED_VERDE, !led_state); // Liga o LED
            }
        }

        // Se nenhuma tecla está sendo pressionada, desliga o LED
        if (led_ligado && tecla != 'A') {
            gpio_put(LED_VERMELHO_GPIO, 0); // Desliga o LED
            led_ligado = false;
        }
        sleep_ms(200);
    }
    return 0;
}
