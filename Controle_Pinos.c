#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "teclado_matricial/teclado_matricial.h"

//define o LED de saída
#define GPIO_LED_RED 18
#define GPIO_LED_GREEN 17
#define GPIO_LED_BLUE 16

int main(){
    stdio_init_all();
    
    gpio_init(GPIO_LED_RED);
    gpio_init(GPIO_LED_GREEN);
    gpio_init(GPIO_LED_BLUE);
    gpio_set_dir(GPIO_LED_RED, GPIO_OUT);
    gpio_set_dir(GPIO_LED_GREEN, GPIO_OUT);
    gpio_set_dir(GPIO_LED_BLUE, GPIO_OUT);

    set_rows_output();
    set_cols_input();

    while (true) {

      printf("Tecla pressionada: %c\n", detect_button());

      if (detect_button()=='*')
        {
            gpio_put(GPIO_LED_RED,true);
            gpio_put(GPIO_LED_GREEN,true);
            gpio_put(GPIO_LED_BLUE,true);
        }else
        {
            gpio_put(GPIO_LED_RED,false);
            gpio_put(GPIO_LED_GREEN,false);
            gpio_put(GPIO_LED_BLUE,false);
        }
        // busy_wait_us(500000);
        sleep_ms(1000);

      // sleep_ms(1000);
    }
}