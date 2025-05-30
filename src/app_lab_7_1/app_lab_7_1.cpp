#include <Arduino.h>

// Настройки
#define NUM_SENSORS 1
#define I2C_SLAVE_ADDRESS 0x12

// Структура пакета данных
typedef struct {
    uint8_t head;
    uint8_t length;
    uint16_t distances[NUM_SENSORS];
    uint8_t checksum;
} SensorPacket;

// Инициализация модулей
void sensors_init();
void i2c_slave_init();
void data_buffer_init();

// FreeRTOS задачи
void task_acquire(void *pvParameters);
void task_update_buffer(void *pvParameters);

extern SensorPacket sharedPacket;