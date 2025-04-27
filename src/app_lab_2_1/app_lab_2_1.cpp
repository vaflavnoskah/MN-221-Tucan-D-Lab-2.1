#include "app_lab_2_1.h"
#include "C:/Users/OXANA/Documents/PlatformIO/Projects/MN-221 Tucan D lab 2.1/src/srv_serial_stdio/srv_serial_stdio.h" // Include the serial library for stdio
#include "dd_led/dd_led.h" // Include the LED library
#include "dd_button/dd_button.h" // Include the button library
#include "Arduino.h"


void app_lab_2_1_task_1() {
  // asteptam apasarea butonului
  while (!dd_button_is_pressed());

  // verificam starea ledului
  if (dd_led_is_on()) {
    // daca e aprins il stingem
    dd_led_turn_off();
  } else {
    // daca e stins il aprindem
    dd_led_turn_on();
  }

  // asteptam sa se elibereze butonul
  while (dd_button_is_pressed());

  delay(300); // Debounce delay
}

void setup() {
  srv_serial_stdio_setup();
  printf(" Lab 2.1 Started\n");
}

void loop() {
  printf(" Lab 2.1 Run\n");
  delay(1000);
}