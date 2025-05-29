#include "app_lab_3_1.h"
#include <Arduino_FreeRTOS.h>
#include <srv_serial_stdio/srv_serial_stdio.h>
#include "Arduino.h"
#include <ed_potentiometer/ed_potentiometer.h>



int dd_sns_angle_value = 0;
int dd_sns_angle_value_offset = 270/2;


void app_lab_1_3_angle_sns_task(void *pvParameters) {
    (void)pvParameters;

    // Task offset
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    TickType_t xLastWakeTime = xTaskGetTickCount();

    for (;;) {
        // delay until recurrent task
        ed_potentiometer_loop();

        int ed_potentiometer_value_voltage = ed_potentiometer_get_voltage();
        // convert voltage to angle (0-270 degrees)
        dd_sns_angle_value = map(ed_potentiometer_value_voltage, 0, 5000, 0, 270) - dd_sns_angle_value_offset;

        // task recurrent time
        vTaskDelayUntil(&xLastWakeTime, 1000 / portTICK_PERIOD_MS);
    }
}

void app_lab_1_3_system_report_task(void *pvParameters) {
    (void)pvParameters;
    for (;;) {
        printf("\n------------------- System report -------------------\n");
        printf("System report\n");
        int ed_potentiometr_value_raw = ed_potentiometer_get_raw();
        printf("Potentiometer raw value (from ADC 0-1023): %d RAW\n", ed_potentiometer_get_raw());
        int ed_potentiometr_value_voltage = ed_potentiometer_get_voltage();
        printf("Sensor voltage: %d mV\n", ed_potentiometer_get_voltage());
        printf("Sensor angle: %d degrees\n", dd_sns_angle_value);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void app_lab_3_1_setup() {
    //Initialize serial communication
    srv_serial_stdio_setup();
   //Craete task for analog read
    xTaskCreate(
        app_lab_1_3_angle_sns_task, // Function that implements the task.
        "app_lab_1_3_angle_sns_task",             // Text name for the task.
        128,                       // Stack size in words, not bytes.
        NULL,                       // Parameter passed into the task.
        1,                          // Priority at which the task is created.
        NULL);                      // Used to pass out the created task's handle.
    xTaskCreate(
        app_lab_1_3_system_report_task, // Function that implements the task.
        "app_lab_1_3_system_report_task",             // Text name for the task.
        128,                       // Stack size in words, not bytes.
        NULL,                       // Parameter passed into the task.
        1,                          // Priority at which the task is created.
        NULL);                      // Used to pass out the created task's handle.

    // Start the scheduler so the task(s) start executing.
    vTaskStartScheduler();
}


void app_lab_3_1_loop() {
    
}