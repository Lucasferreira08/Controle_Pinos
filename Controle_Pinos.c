#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "teclado_matricial/teclado_matricial.h"

// define o LED de saída
#define GPIO_LED_RED 18
#define GPIO_LED_GREEN 17
#define GPIO_LED_BLUE 16

// Definindo o pino do buzzer
#define BUZZER_PIN 21

void setup_buzzer()
{
    // Inicializa o pino do buzzer
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);

    // teclado matricial pra configuracao
    set_rows_output();
    set_cols_input();
}

void acionar_buzzer()
{
    gpio_put(BUZZER_PIN, true);  // Liga o buzzer
    sleep_ms(2000);              // Aguardar 2 segundos
    gpio_put(BUZZER_PIN, false); // Desliga o buzzer
}

int main()
{
    stdio_init_all();

    gpio_init(GPIO_LED_RED);
    gpio_init(GPIO_LED_GREEN);
    gpio_init(GPIO_LED_BLUE);
    gpio_set_dir(GPIO_LED_RED, GPIO_OUT);
    gpio_set_dir(GPIO_LED_GREEN, GPIO_OUT);
    gpio_set_dir(GPIO_LED_BLUE, GPIO_OUT);

    setup_buzzer();

    set_rows_output();
    set_cols_input();

    // loop
    while (true)
    {

        printf("Tecla pressionada: %c\n", detect_button());

        if (detect_button() == '*')
        {
            gpio_put(GPIO_LED_RED, true);
            gpio_put(GPIO_LED_GREEN, true);
            gpio_put(GPIO_LED_BLUE, true);
        }
        else if (detect_button() == 'B')
        {
            gpio_put(GPIO_LED_RED, false);
            gpio_put(GPIO_LED_GREEN, false);
            gpio_put(GPIO_LED_BLUE, true);
        }
        // Aciona o buzzer se a tecla for pressionada
        else if (detect_button() == '#')
        {
            acionar_buzzer(); // Aciona o buzzer
        }
        else
        {
            gpio_put(GPIO_LED_RED, false);
            gpio_put(GPIO_LED_GREEN, false);
            gpio_put(GPIO_LED_BLUE, false);
        }

        sleep_ms(1000);
    }
}