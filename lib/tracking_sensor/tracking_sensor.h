#ifndef TRACKING_SENSOR_H
#define TRACKING_SENSOR_H

#include <Arduino.h>

// 定义传感器引脚
#define SENSOR1_PIN 25
#define SENSOR2_PIN 26
#define SENSOR3_PIN 33
#define SENSOR4_PIN 32

class TrackingSensor {
public:
    void init();
    uint8_t readSensors();
    void printSensorStates();

private:
    const uint8_t sensorPins[4] = {SENSOR1_PIN, SENSOR2_PIN, SENSOR3_PIN, SENSOR4_PIN};
    bool sensorStates[4] = {0};
};

#endif