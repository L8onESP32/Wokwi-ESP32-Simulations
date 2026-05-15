#include "OLEDHelper.h"

OLEDHelper::OLEDHelper(uint8_t width, uint8_t height, uint8_t i2cAddr)
  : display(width, height, &Wire, -1), address(i2cAddr) {}

bool OLEDHelper::begin() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, address)) return false;
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  return true;
}

void OLEDHelper::clear() {
  display.clearDisplay();
}

void OLEDHelper::show() {
  display.display();
}

void OLEDHelper::displayText(const char* text, int x, int y, int size) {
  display.setTextSize(size);
  display.setCursor(x, y);
  display.print(text);
  // Do NOT call show() here – let caller decide when to refresh
}

void OLEDHelper::showPotValue(int raw, float voltage) {
  clear();
  display.setCursor(0, 0);
  display.print("Potentiometer");
  display.setCursor(0, 20);
  display.print("Raw: ");
  display.println(raw);
  display.setCursor(0, 40);
  display.print("Voltage: ");
  display.print(voltage, 2);
  display.println(" V");
  show();
}
