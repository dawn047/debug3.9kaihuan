#ifndef MotorController_h
#define MotorController_h

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

class MotorController {
public:
    MotorController();
    void begin();
    void moveForward();
    void moveBackward();
    void turnLeft();
    void turnRight();
    void stop();
    void brake();
    void setSpeed(int speed);
    void setSpeedOpenLoop(int speedL, int speedR);

private:
    Motor motorL;
    Motor motorR;
    int currentSpeed = 0;
};

#endif