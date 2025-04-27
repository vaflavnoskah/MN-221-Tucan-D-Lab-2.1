#include "dd_button.h"
#include "Arduino.h"

void dd_button_setup() {
    pinMode(DD_BUTTON_PIN, INPUT);
}

int dd_button_read() {
    return digitalRead(DD_BUTTON_PIN);
}

int dd_button_is_pressed() {
    return dd_button_read() == HIGH;
}