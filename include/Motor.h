#ifndef Motor_h
#define Motor_h

#include <Arduino.h>

class Motor {
public:
    Motor(int in1, int in2);
    void init();
    void forward(int speed);
    void backward(int speed);
    void stop();
    void brake();
    void setSpeed(int speed);

private:
    int _in1, _in2;
    int _currentSpeed;
};

#endif