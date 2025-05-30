#include "sensor.h"
#include <iostream>

Sensor::Sensor() : value(0.0) {}

Sensor::~Sensor() {}

void Sensor::read() {
    // Симуляция чтения значения с датчика
    value = getSimulatedValue();
}

double Sensor::getValue() const {
    return value;
}

double Sensor::getSimulatedValue() const {
    // Здесь можно реализовать получение значения с реального датчика
    // Пока что возвращаем случайное значение для примера
    return static_cast<double>(rand()) / RAND_MAX * 100.0;
}