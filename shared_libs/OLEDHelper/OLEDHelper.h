#ifndef OLEDHELPER_H
#define OLEDHELPER_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class OLEDHelper {
public:
  OLEDHelper(uint8_t width, uint8_t height, uint8_t i2cAddr);
  bool begin();
  void displayText(const char* text, int x, int y, int size = 1);
  void clear();
  void showPotValue(int raw, float voltage);
private:
  Adafruit_SSD1306 display;
  uint8_t address;
};

#endif
