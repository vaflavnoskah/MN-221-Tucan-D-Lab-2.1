#ifndef app_lab_5_2_h
#define app_lab_5_2_h

#include <Arduino.h>
#include <timer-api.h>
#include "own_stdio.h"
#include "encode.h"
#include "pid.h"
#include "MeanFilter.h"
#include "simpleMeanFilter.h"
#include "dd_h_bridge.h"

void setup(void);

void loop(void);

void timer_handle_interrupts(int timer);

void serialEvent();

int setPointToPercent(int set_point);
int percentToSetPoint(int percent);

#endif // !MAIN_H