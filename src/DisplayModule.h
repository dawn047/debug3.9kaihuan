// DisplayModule.h
#pragma once
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

class DisplayModule {
private:
    Adafruit_SSD1306 display;
    uint8_t sdaPin;
    uint8_t sclPin;
    uint8_t i2cAddress;
    int screenWidth;
    int screenHeight;

public:
    DisplayModule(uint8_t sda, uint8_t scl, uint8_t addr, int width, int height);
    bool init();
    void showDistance(float distance);
    void showSystemStatus(const String& status);
};