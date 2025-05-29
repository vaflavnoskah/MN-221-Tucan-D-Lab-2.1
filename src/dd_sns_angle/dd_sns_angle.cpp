#include "dd_sns_angle.h"
#include <Arduino.h>
#include <ed_potentiometer/ed_potentiometer.h>
#include <lib_cond/lib_cond.h>

#define DD_ANGLE_OFFSET 100 // Define DD_ANGLE_OFFSET with an appropriate value
#define ED_POTENTIOMETER_VOLTAGE_SAT_MIN 1000
#define ED_POTENTIOMETER_VOLTAGE_SAT_MAX 4000
#define ED_POTENTIOMETER_RAW_MIN 0
#define ED_POTENTIOMETER_RAW_MAX 1023
#define DD_SNS_ANGLE_MIN 0
#define DD_SNS_ANGLE_MAX 270
// Removed redundant definition of dd_sns_angle_value
int dd_sns_angle_value_offset = (DD_ANGLE_OFFSET / 2);
int dd_sns_angle_voltage = 0;
int dd_sns_angle_voltage_saturated = 0;
int dd_sns_angle_voltage_filtered_median = 0;


// sensor angle signal (0-270 degrees)
int dd_sns_angle_value = 0;

void dd_sns_angle_setup() {
    // Setup function does not return a value
}

#define DD_SNS_ANGLE_MEDIAN_FIFO_SIZE 3
#define DD_SNS_ANGLE_FIFO_SIZE 4
#define DD_SNS_ANGLE_WEIGHTS_SIZE 4
#define DD_SNS_ANGLE_AVG_FIFO_SIZE 4
#define DD_SNS_ANGLE_WAIGHTS 4
#define DD_SNS_ANGLE_WINDOW_SIZE 4 // Define DD_SNS_ANGLE_WINDOW_SIZE with an appropriate value
int sns_angle_voltage_avg_fifo[DD_SNS_ANGLE_AVG_FIFO_SIZE] = {0};
int dd_sns_angle_voltage_filtered_avg = 0;
int sns_angle_voltage_median_fifo[DD_SNS_ANGLE_MEDIAN_FIFO_SIZE] = {0};
int sns_angle_avg_fifo[DD_SNS_ANGLE_AVG_FIFO_SIZE] = {0};
int sns_angle_weights[DD_SNS_ANGLE_WEIGHTS_SIZE] = {40, 30, 20, 10};

void dd_sns_angle_loop() {
    // (1) get voltage value from potentiometer
    // (1) get voltage value from potentiometer
    dd_sns_angle_voltage = ed_potentiometer_get_voltage();
    // (2) Saturate the value to the range of the potentiometer (1000 - 4000 mV)
    dd_sns_angle_voltage_saturated = lib_cond_saturate(dd_sns_angle_voltage,
                                                           ED_POTENTIOMETER_VOLTAGE_SAT_MIN,
                                                           ED_POTENTIOMETER_VOLTAGE_SAT_MAX);

                                                        dd_sns_angle_voltage_filtered_median = lib_cond_median_filter(dd_sns_angle_voltage_saturated,
                                                                                                                      sns_angle_voltage_median_fifo,
                                                                                                                      sns_angle_voltage_window,
                                                                                                                      DD_SNS_ANGLE_WINDOW_SIZE);

    // (4) weighted average filtering
    dd_sns_angle_voltage_filtered_avg = lib_cond_weighted_average(dd_sns_angle_voltage_filtered_median,
                                                                  sns_angle_voltage_avg_fifo,
                                                                  sns_angle_weights,
                                                                  DD_SNS_ANGLE_WAIGHTS);

    // (5) convert voltage to angle (0-270 degrees)
    dd_sns_angle_value = map(dd_sns_angle_voltage,
                             ED_POTENTIOMETER_RAW_MIN,
                             ED_POTENTIOMETER_RAW_MAX,
                             DD_SNS_ANGLE_MIN, DD_SNS_ANGLE_MAX) -
                         dd_sns_angle_value_offset;
}

int dd_sns_angle_get_value() {
}

int dd_sns_angle_get_voltage() {
    return dd_sns_angle_voltage;
}

int dd_sns_angle_get_voltage_saturated() {
    return dd_sns_angle_voltage_saturated;
}

int dd_sns_angle_get_voltage_filtered_median() {
    return dd_sns_angle_voltage_filtered_median;
}

int dd_sns_angle_get_voltage_filtered_avg() {
    return dd_sns_angle_voltage_filtered_avg;
}

