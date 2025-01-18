// GPIO utilizada para o teclado matricial
int pins_matrix_r[4] = {8, 7, 6, 5};  // Em ordem: R1, R2, R3, R4
int pins_matrix_c[4] = {4, 3, 2, 28}; // Em ordem: C1, C2, C3, C4

void set_rows_output(){
  for (int i=0; i<4; i++){
    gpio_init(pins_matrix_r[i]);
    gpio_set_dir(pins_matrix_r[i], GPIO_OUT);
    gpio_put(pins_matrix_r[i], 0);
  }
}

void set_cols_input(){
  for (int i=0; i<4; i++){
    gpio_init(pins_matrix_c[i]);
    gpio_set_dir(pins_matrix_c[i], GPIO_IN);
  }
}