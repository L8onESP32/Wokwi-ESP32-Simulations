#include <Arduino.h>
#include "OLEDHelper.h"

OLEDHelper oled(128, 64, 0x3C);

const int potPin = 32;

void setup() {
  Serial.begin(115200);
  if (!oled.begin()) {
    Serial.println("OLED init failed");
    while (1);
  }
  oled.displayText("Potentiometer:", 0, 0);
  delay(500);
}

void loop() {
  int raw = analogRead(potPin);
  float voltage = raw * (3.3 / 4095.0);
  Serial.print("Raw: "); Serial.print(raw); Serial.print(" Voltage: "); Serial.println(voltage, 2);
  oled.showPotValue(raw, voltage);
  delay(200);
}
