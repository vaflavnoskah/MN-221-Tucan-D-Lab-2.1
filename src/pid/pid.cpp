#ifndef ENCODE_H
#define ENCODE_H

#include <Arduino.h>
#include "config.h"

void encode_setup(void);
void encode_interrupt(void);
uint16_t encode_get_count(void);

#endif // !ENCODE_H