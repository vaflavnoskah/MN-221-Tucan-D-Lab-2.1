#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
public:
    Sensor();
    virtual ~Sensor();

    // Инициализация датчика
    virtual bool initialize() = 0;

    // Считывание значения с датчика
    virtual double readValue() = 0;

    // Проверка статуса датчика
    virtual bool isOk() const = 0;
};

#endif // SENSOR_H