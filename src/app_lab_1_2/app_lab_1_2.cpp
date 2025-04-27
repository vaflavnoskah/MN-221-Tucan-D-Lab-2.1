#include "srv_stdio_lcd/srv_stdio_lcd.h"
#include "srv_stdio_keypad/srv_stdio_keypad.h"
#include "dd_led/dd_led.h"
#include <stdio.h>

void app_lab_1_2_setup()
{
    srv_stdio_lcd_setup();
    srv_stdio_keypad_setup();
    printf("Hello World!");
    dd_led_setup();
}
void app_lab_1_2_loop()
{
    char code[4] = {'1', '2', '3', '4'};
    char input[4];

    // detectarea unui cod de la o tastatura 4x4, sa verifice codul si sa afiseze mesaj la un LCD.
    // codul este 1234
    scanf("%c%c%c%c", &input[0], &input[1], &input[2], &input[3]);


    // Clear the LCD screen
    printf("\x1b[2J");

    if (input[0] == code[0] && input[1] == code[1] && input[2] == code[2] && input[3] == code[3])
    {
        printf("Codul este corect!");
        dd_led_turn_on();
    }
    else
    {
        printf("Codul este incorect!");
        dd_led_turn_off();
    }
}