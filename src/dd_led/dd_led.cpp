#include "dd_led.h"
#include <Arduino.h>

#define LED_PIN 13 // Replace 13 with the appropriate pin number for your setup
// Ensure this macro is correctly defined and used before any function definitions

void dd_led_setup()
{
    pinMode(LED_PIN, OUTPUT);
}

void dd_led_turn_on()
{
    digitalWrite(LED_PIN, HIGH);
}

void dd_led_turn_off()
{
    digitalWrite(LED_PIN, LOW);
}

int dd_led_is_on()
{
    return (digitalRead(LED_PIN) == HIGH) ? 1 : 0;
}