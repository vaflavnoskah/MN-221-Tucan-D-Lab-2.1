#include "ed_potentiometer.h"
#include <Arduino.h>

#define ED_POTENTIOMETER_ADC_PIN A0
#define ED_POTENTIOMETER_RAW_MIN 0
#define ED_POTENTIOMETER_RAW_MAX 1023
#define ED_POTENTIOMETER_VOLTAGE_MIN 0
#define ED_POTENTIOMETER_VOLTAGE_MAX 5000
#define ED_POTENTIOMETER_VOLTAGE_SAT_MAX 4000
#define ED_POTENTIOMETER_VOLTAGE_SAT_MIN 1000


int ed_potentiometr_value_raw = 0;
int ed_potentiometr_value_voltage = 0;

void ed_potentiometer_setup() {
}

void ed_potentiometer_loop() {

    // get raw value from potentiometer

    ed_potentiometr_value_raw = analogRead(A0);

    //  convert raw value  to voltage 
    ed_potentiometr_value_voltage = map(ed_potentiometr_value_raw, 
                                        ED_POTENTIOMETER_RAW_MIN, 
                                        ED_POTENTIOMETER_RAW_MAX, 
                                        ED_POTENTIOMETER_VOLTAGE_MIN, 
                                        ED_POTENTIOMETER_VOLTAGE_MAX);
}

// Removed duplicate or conflicting declaration of ed_potentiometer_get_raw

int ed_potentiometer_get_voltage() {
    return ed_potentiometr_value_voltage;
}