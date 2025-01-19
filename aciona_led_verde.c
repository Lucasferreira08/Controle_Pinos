#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define GPIO_LED_VERDE 11

void setup_led_verde() {
    gpio_init(GPIO_LED_VERDE);
    gpio_set_dir(GPIO_LED_VERDE, GPIO_OUT);
}

int aciona_led_verde() {
    // Chama função de inicialização da GPIO
    setup_led_verde();

    // Inicializa todos os códigos stdio padrão que estão ligados ao binário
    stdio_init_all();

    if (scanf("%c", &tecla) == 1) {
        gpio_put(GPIO_LED_VERDE, tecla == 'D'); // Liga o LED se a tecla 'D' estiver pressionada
    }
    return 0;
}
