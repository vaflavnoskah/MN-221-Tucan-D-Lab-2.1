#ifndef DD_FAN_H_
#define DD_FAN_H_

#define DD_FAN_ON 1
#define DD_FAN_OFF 0

void dd_fan_setup();
void dd_fan_loop();

int dd_fan_on();
int dd_fan_off();

int dd_fan_on_hw();
int dd_fan_off_hw();

int dd_fan_is_on();
int dd_fan_is_on_hw();

#endif