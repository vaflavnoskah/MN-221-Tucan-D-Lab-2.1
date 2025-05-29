#ifndef ED_RELAY_H
#define ED_RELAY_H

#include "Arduino.h"

#define ED_RELAY_PIN 2

#define ED_RELAY_ON  1
#define ED_RELAY_OFF 0

void ed_relay_setup();
void ed_relay_loop();

int ed_relay_on();
int ed_relay_off();

int ed_relay_on_hw();
int ed_relay_off_hw();

int ed_relay_is_on_hw();
int ed_relay_is_off();

#endif // ed_RELAY_H