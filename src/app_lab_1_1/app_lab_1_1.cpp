#include "app_lab_1_1.h"
#include "Arduino.h"


#include "srv_serial_stdio/srv_serial_stdio.h" // Include the serial library for stdio
#include "dd_led/dd_led.h" // Include the LED library



void app_lab_1_1_setup()
{
    srv_serial_stdio_setup(); // Initialize the serial stdio library
    dd_led_setup(); // Initialize the LED library
    printf("Hello World!\n"); // Print "Hello World!" to the serial console
}

void app_lab_1_1_loop()
{
    char cmd;
    printf("Enter command : Led on/led off\n");
    scanf("%c", &cmd);

    printf("Command: %c\n", cmd); // Print the command entered by the user

    if (cmd == '1') {
        printf("Led on\n"); // Print "Led on" if the command is '1'
        dd_led_turn_on(); // Turn on the LED
    } else if (cmd == '0') {
        printf("Led off\n"); // Print "Led off" if the command is '0'
        dd_led_turn_off(); // Turn off the LED
    } else {
        printf("Invalid command\n"); // Print "Invalid command" for any other input
    }
    delay(1000); // Delay for 1 second
}