#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  Serial.println("Potentiometer test started");
}

void loop() {
  int value = analogRead(26);
  Serial.println(value);
  delay(200);
}