#include "i2c_comm.h"
#include <Wire.h>

// Инициализация I2C
void I2CComm::begin(uint8_t address) {
    Wire.begin(address);
}

// Отправка данных по I2C
bool I2CComm::send(uint8_t deviceAddress, const uint8_t* data, size_t length) {
    Wire.beginTransmission(deviceAddress);
    Wire.write(data, length);
    uint8_t result = Wire.endTransmission();
    return (result == 0);
}

// Получение данных по I2C
bool I2CComm::receive(uint8_t deviceAddress, uint8_t* buffer, size_t length) {
    Wire.requestFrom(deviceAddress, (uint8_t)length);
    size_t index = 0;
    while (Wire.available() && index < length) {
        buffer[index++] = Wire.read();
    }
    return (index == length);
}