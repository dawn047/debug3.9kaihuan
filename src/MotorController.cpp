#include "MotorController.h"

// MotorController 类的实现
MotorController::MotorController() : motorL(13, 12), motorR(14, 27) //GPIO13-AIN1，GPIO12-AIN2，GPIO14-BIN1，GPIO27-BIN2
//GPIO13控制电机 A 的正转信号,GPIO12控制电机 A 的反转信号
//GPIO14控制电机 B 的正转信号,GPIO27控制电机 B 的反转信号

{
    currentSpeed = 0;    // 初始速度为0
}

void MotorController::begin() {
    motorL.init();
    motorR.init();
}

void MotorController::moveForward() {   // 前进
    motorL.forward(currentSpeed);
    motorR.forward(currentSpeed);
}

void MotorController::moveBackward() {  // 后退
    motorL.backward(currentSpeed);
    motorR.backward(currentSpeed);
}

void MotorController::turnLeft() {  // 左转
    motorL.backward(currentSpeed);
    motorR.forward(currentSpeed);
}

void MotorController::turnRight() { // 右转
    motorL.forward(currentSpeed);
    motorR.backward(currentSpeed);
}

void MotorController::stop() {  // 停止
    motorL.stop();
    motorR.stop();
}

void MotorController::setSpeed(int speed) {   
    currentSpeed = speed;
    motorL.setSpeed(speed);
    motorR.setSpeed(speed);
}

void MotorController::setSpeedOpenLoop(int speedL, int speedR) {    
    motorL.setSpeed(speedL);
    motorR.setSpeed(speedR+5);// 右电机速度补偿
}