#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085.h>
#include "OLEDHelper.h"

OLEDHelper oled(128, 64, 0x3C);   // width, height, I2C address
Adafruit_BMP085 bmp;

const int potPin = 34;
const int buttonPin = 4;
int mode = 0;   // 0: pot only, 1: BMP only, 2: both

// Debouncing variables
bool lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 20;
bool buttonProcessed = false;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  if (!bmp.begin()) {
    Serial.println("BMP180 not found");
    while (1);
  }
  if (!oled.begin()) {
    Serial.println("OLED failed");
    while (1);
  }
  oled.clear();
  oled.displayText("Sensor Test", 0, 0);
  oled.show();
  delay(2000);
  oled.clear();

  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // Button debouncing (same as before)
  bool reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading == LOW && !buttonProcessed) {
      buttonProcessed = true;
      mode = (mode + 1) % 3;
    } else if (reading == HIGH && buttonProcessed) {
      buttonProcessed = false;
    }
  }
  lastButtonState = reading;

  // Read sensors
  int potValue = analogRead(potPin);
  int heartRate = map(potValue, 0, 4095, 40, 180);
  float pressure = bmp.readPressure() / 100.0F;
  float altitude = 44330 * (1 - pow(pressure / 1013.25, 0.1903));

  // Build strings
  char line1[32], line2[32], line3[32], line4[32];
  if (mode == 0) {
    snprintf(line1, sizeof(line1), "Mode: Pot only");
    snprintf(line2, sizeof(line2), "Heart Rate: %d BPM", heartRate);
    strcpy(line3, "");
    strcpy(line4, "");
  } else if (mode == 1) {
    snprintf(line1, sizeof(line1), "Mode: BMP only");
    snprintf(line2, sizeof(line2), "Pressure: %.1f hPa", pressure);
    snprintf(line3, sizeof(line3), "Altitude: %.1f m", altitude);
    strcpy(line4, "");
  } else {
    snprintf(line1, sizeof(line1), "Mode: Both");
    snprintf(line2, sizeof(line2), "HR: %d BPM", heartRate);
    snprintf(line3, sizeof(line3), "Press: %.1f hPa", pressure);
    snprintf(line4, sizeof(line4), "Alt: %.1f m", altitude);
  }

  oled.clear();
  oled.displayText(line1, 0, 0);
  oled.displayText(line2, 0, 12);
  if (strlen(line3) > 0) oled.displayText(line3, 0, 24);
  if (strlen(line4) > 0) oled.displayText(line4, 0, 36);
  oled.show();

  Serial.print("Mode: ");
  Serial.print(mode);
  Serial.print("  HR: ");
  Serial.print(heartRate);
  Serial.print("  Press: ");
  Serial.print(pressure, 1);
  Serial.print("  Alt: ");
  Serial.println(altitude, 1);

  delay(5);
}