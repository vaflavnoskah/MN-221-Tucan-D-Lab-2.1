#ifndef I2C_COMM_H
#define I2C_COMM_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// Инициализация I2C интерфейса
void i2c_init(void);

// Отправка данных по I2C
// addr - адрес устройства
// data - указатель на буфер данных
// len  - длина данных
// Возвращает 0 при успехе, иначе код ошибки
int i2c_write(uint8_t addr, const uint8_t *data, size_t len);

// Чтение данных по I2C
// addr - адрес устройства
// data - указатель на буфер для чтения
// len  - количество байт для чтения
// Возвращает 0 при успехе, иначе код ошибки
int i2c_read(uint8_t addr, uint8_t *data, size_t len);

#ifdef __cplusplus
}
#endif

#endif // I2C_COMM_H