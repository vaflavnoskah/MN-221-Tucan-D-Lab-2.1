#include "app_lab_2_2.h"
#include <Arduino_FreeRTOS.h>
#include <srv_serial_stdio/srv_serial_stdio.h>
#include <dd_button/dd_button.h>
#include <dd_led/dd_led.h>
#include "semphr.h"

#define ONE_SEC 1000
#define TASK_1_REC 100
#define TASK_1_OFSSET 100

//defenirea semaforului
SemaphoreHandle_t xSemaphore = NULL;

int task1_led_time_cnt = -1;


//define a freeRTOS task
void task1(void *pvParameters) {
    TickType_t xLastWakeTime = xTaskGetTickCount();


    //delay for ofsset
    vTaskDelay(TASK_1_OFSSET/portTICK_PERIOD_MS);
    xLastWakeTime = xTaskGetTickCount();


    while (1) {
        printf("Task 1\n");

        // asteptam apasarea butonului
        if (dd_button_is_pressed() && task1_led_time_cnt <0 ){ // no spin lock
            task1_led_time_cnt = ONE_SEC / TASK_1_REC;
            dd_led_turn_on();
            printf("Button pressed\n");
        }

        //mentinera led-ului aprins
        if (task1_led_time_cnt > 0) {
            task1_led_time_cnt--;
            dd_led_turn_on();
            printf("Led on\n");
        } else if (task1_led_time_cnt == 0) {
            dd_led_turn_off();
            printf("Led off\n");
            //ridicam semaforul
            xSemaphoreGive(xSemaphore);
            printf("Semaphore given\n");
            task1_led_time_cnt--;
        } 
       

        vTaskDelayUntil(
            &xLastWakeTime, // Pointer to the variable that holds the last wake time.
            TASK_1_REC);    // The period of the task in ticks.
    }
}  

//task 2

#define TASK_2_REC 50
#define TASK_2_OFSSET 50

int task_N_cnt = 0;
QueueHandle_t xQueue = NULL;

void task2(void *pvParameters) {


    while (1) {
        // (1) asteptam ridicarea semaforului
        if (xSemaphoreTake(xSemaphore, portMAX_DELAY) == pdTRUE) {
            printf("task 2: semaphore detected\n");
            // (2) incrementam variabila
            task_N_cnt++;
            // (3) trimitem in buffer N caractere
            for (int i = 0; i < task_N_cnt; i++) {
                xQueueSend(xQueue, &i, portMAX_DELAY);
                vTaskDelay(50 / portTICK_PERIOD_MS);
            }
        }

        printf("task 2: queue sent\n");

        // (4) controlam led-ul
        for (int i = 0; i < task_N_cnt; i++) {
            dd_led_turn_on();
            vTaskDelay(500/ portTICK_PERIOD_MS);
            dd_led_turn_off();
            vTaskDelay(300/ portTICK_PERIOD_MS);
            printf("Led blinked times\n");
        }
        vTaskDelay(500 / portTICK_PERIOD_MS);
        printf("task 2: running\n");
    }

}

//task 3 
void task3(void *pvParameters) {
    while (1) {
        int data;
        // citirea din buffer fiecare 200ms
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        // citirea buffer
        while (xQueueReceive(xQueue, &data, 200 / portTICK_PERIOD_MS) == pdTRUE) {
            printf("Task 3: Data received: %d\n", data);
        printf("Task 3: buffer empty\n");
        }
    }
}


void app_lab_2_2_setup() {
    //init serial
    srv_serial_stdio_setup();
    dd_button_setup();
    dd_led_setup();

    //create a binary semaphore
    xSemaphore = xSemaphoreCreateBinary();
    //create a freeRTOS task
    xTaskCreate(
        task1,           // Function that implements the task.
        "Task 1",       // Text name for the task.
        2000,           // Stack size in words, not bytes.
        NULL,           // Parameter passed into the task.
        1,              // Priority at which the task is created.
        NULL);          // Used to pass out the created task's handle.
    xTaskCreate(
        task2,           // Function that implements the task.
        "Task 2",       // Text name for the task.
        2000,           // Stack size in words, not bytes.
        NULL,           // Parameter passed into the task.
        1,              // Priority at which the task is created.
        NULL);          // Used to pass out the created task's handle.
    xTaskCreate(
        task3,           // Function that implements the task.
        "Task 3",       // Text name for the task.
        2000,           // Stack size in words, not bytes.
        NULL,           // Parameter passed into the task.
        1,              // Priority at which the task is created.
        NULL);          // Used to pass out the created task's handle.

    // Start the scheduler so the task(s) start executing.
    vTaskStartScheduler();
   
}


void app_lab_2_2_loop() {
    
}