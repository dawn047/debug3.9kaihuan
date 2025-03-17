#include "battery_monitor.h"

BatteryMonitor::BatteryMonitor(int adcPin, float voltageDividerRatio, float adcRefVoltage)
    : _adcPin(adcPin),
      _voltageDividerRatio(voltageDividerRatio),
      _adcRefVoltage(adcRefVoltage),
      _rawValue(0),
      _batteryVoltage(0.0f),
      _batteryLevel(0) {}

void BatteryMonitor::begin() {
    analogReadResolution(12);
    analogSetPinAttenuation(_adcPin, ADC_11db);
}

void BatteryMonitor::update() {
    _rawValue = _readFilteredADC();
    float adcVoltage = (_rawValue / 4095.0f) * _adcRefVoltage;
    _batteryVoltage = adcVoltage * _voltageDividerRatio;
    _batteryLevel = _mapVoltageToLevel(_batteryVoltage);
}

int BatteryMonitor::_readFilteredADC() {
    int raw = 0;
    for (int i = 0; i < 16; i++) {
        raw += analogRead(_adcPin);
        delay(1);
    }
    return raw / 16;
}

int BatteryMonitor::_mapVoltageToLevel(float voltage) const {
    if (voltage >= 12.6) return 100;
    if (voltage >= 12.1) return 80;
    if (voltage >= 11.8) return 60;
    if (voltage >= 11.5) return 40;
    if (voltage >= 11.0) return 20;
    return 0;
}

float BatteryMonitor::getVoltage() const { return _batteryVoltage; }
int BatteryMonitor::getLevel() const { return _batteryLevel; }
int BatteryMonitor::getRawValue() const { return _rawValue; }

void BatteryMonitor::setVoltageDividerRatio(float ratio) { _voltageDividerRatio = ratio; }
void BatteryMonitor::setAdcRefVoltage(float voltage) { _adcRefVoltage = voltage; }