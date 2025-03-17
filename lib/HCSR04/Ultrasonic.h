// Ultrasonic.h 
#ifndef ULTRASONIC_H 
#define ULTRASONIC_H 
 
#include <Arduino.h>
 
class Ultrasonic {
public:
    Ultrasonic(uint8_t trigPin, uint8_t echoPin);
    float getDistanceCM();
    
private:
    uint8_t _trigPin;
    uint8_t _echoPin;
    unsigned long pulseTimeout = 30000; // 超时时间(us)
};
 
#endif 