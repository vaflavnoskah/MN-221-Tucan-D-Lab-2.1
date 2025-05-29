#include "app_lab_4_1.h"
#include "Arduino_FreeRTOS.h"

#include "dd_fan/dd_fan.h"
#include "ed_relay/ed_relay.h"
#include "srv_serial_stdio/srv_serial_stdio.h"


// create a task for relay control
void app_lab_4_1_relay_task(void *pvParameters)
{
    (void)pvParameters;
    // Task offset

    // init relay
    ed_relay_setup();

    vTaskDelay(1000 / portTICK_PERIOD_MS);

    TickType_t xLastWakeTime = xTaskGetTickCount();

    for (;;)
    {
        // delay until recurrent task
        // run the relay loop
        ed_relay_loop();

        // task recurrent time
        vTaskDelayUntil(&xLastWakeTime, 100 / portTICK_PERIOD_MS);
    }
}


// create a task for fan control
void app_lab_4_1_fan_task(void *pvParameters)
{
    (void)pvParameters;
    // Task offset


    // init fan
    dd_fan_setup();

    vTaskDelay(1000 / portTICK_PERIOD_MS);

    TickType_t xLastWakeTime = xTaskGetTickCount();

    for (;;)
    {
        // delay until recurrent task
        // run the fan loop
        dd_fan_loop();

        // task recurrent time
        vTaskDelayUntil(&xLastWakeTime, 100 / portTICK_PERIOD_MS);
    }
}

char serial_input[1000];


// create a task for app_lab_4_1 that will read the serial and control the fan
void app_lab_4_1_task(void *pvParameters)
{
    (void)pvParameters;
    // Task offset

    // init serial
    srv_serial_stdio_setup();

    vTaskDelay(1000 / portTICK_PERIOD_MS);

    TickType_t xLastWakeTime = xTaskGetTickCount();

    for (;;)
    {
        // read serial terminal for fan control command
        scanf("%s", serial_input);

        // check if the input is "fan on"
        if (strcmp(serial_input, "fan_on") == 0)
        {
            // turn on the fan
            dd_fan_on();
        }
        // check if the input is "fan off"
        else if (strcmp(serial_input, "fan_off") == 0)
        {
            // turn off the fan
            dd_fan_off();
        }
        // wrong command 
        else{
            // print error messege 
            printf("wrong command \n");
        }

        // task recurrent time
        vTaskDelayUntil(&xLastWakeTime, 100 / portTICK_PERIOD_MS);
    }
}

void app_lab_4_1_setup()
{
    // create the relay task
    xTaskCreate(app_lab_4_1_relay_task, "Relay Task",128, NULL, 1, NULL);

    // create the fan task
    xTaskCreate(app_lab_4_1_fan_task, "Fan Task", 128, NULL, 1, NULL);

    vTaskStartScheduler();
}

