#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "aciona_led_verde.h"

#define GPIO_LED_VERDE 11

void setup_led_verde() {
    gpio_init(GPIO_LED_VERDE);
    gpio_set_dir(GPIO_LED_VERDE, GPIO_OUT);
}

void aciona_led_verde(char tecla_acionada) {
    // Chama função de inicialização da GPIO
    setup_led_verde();

    // Liga o LED se a tecla 'D' estiver pressionada
    gpio_put(GPIO_LED_VERDE, tecla == '*' || tecla == 'D'); 
}
