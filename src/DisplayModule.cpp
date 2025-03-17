// DisplayModule.cpp
#include "DisplayModule.h"

DisplayModule::DisplayModule(uint8_t sda, uint8_t scl, uint8_t addr, int width, int height)
    : display(width, height, &Wire, -1),
      sdaPin(sda),
      sclPin(scl),
      i2cAddress(addr),
      screenWidth(width),
      screenHeight(height) {}

bool DisplayModule::init() {
    Wire.begin(sdaPin, sclPin);
    if (!display.begin(SSD1306_SWITCHCAPVCC, i2cAddress)) {
        return false;
    }
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    return true;
}

void DisplayModule::showDistance(float distance) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Distance:");
    display.setCursor(0, 16);
    display.setTextSize(2);
    display.print(distance, 1);
    display.print(" cm");
    display.display();
}

void DisplayModule::showSystemStatus(const String& status) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print("Status:");
    display.setCursor(0, 16);
    display.print(status);
    display.display();
}