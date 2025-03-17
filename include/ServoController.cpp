#include <Arduino.h>
#include <ESP32Servo.h>

// 舵机控制模块
class ServoController {
private:
    Servo servo;
    const int pin;
    const int minUs = 500;   // 0度对应的脉冲宽度（微秒）
    const int maxUs = 2500;  // 180度对应的脉冲宽度（微秒）

public:
    ServoController(int servoPin) : pin(servoPin) {}

    void begin() {
        servo.attach(pin, minUs, maxUs); // 初始化舵机参数
        setAngle(0);                     // 上电复位到0度
        delay(500);
    }

    void setAngle(int angle) {
        angle = constrain(angle, 0, 180); // 限制角度范围
        servo.write(angle);
    }

    void open(int speedMs = 15) {
        for (int angle = 0; angle <= 180; angle++) {
            setAngle(angle);
            delay(speedMs); // 控制转动速度，默认15ms/度
        }
    }

    void close(int speedMs = 15) {
        for (int angle = 180; angle >= 0; angle--) {
            setAngle(angle);
            delay(speedMs);
        }
    }
};

// 硬件配置
//const int SERVO_PIN = 2;  // 舵机信号线接GPIO2
//ServoController myServo(SERVO_PIN);

/*void setup() {
    Serial.begin(115200);
    myServo.begin();
}

void loop() {
    Serial.println("Opening...");
    myServo.open();     // 0度到180度
    delay(1000);        // 保持1秒
    
    Serial.println("Closing...");
    myServo.close();    // 180度到0度
    delay(1000);
}
    */