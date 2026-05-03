#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Pin definitions
const int redLed = 5;
const int greenLed = 6;
const int redBtn = 4;
const int greenBtn = 7;

// Button states and counters
bool lastRedState = HIGH;
bool lastGreenState = HIGH;
int redCount = 0;
int greenCount = 0;

unsigned long lastDebounceTimeRed = 0;
unsigned long lastDebounceTimeGreen = 0;
const unsigned long debounceDelay = 50;

void updateDisplay() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Button Press Counts:");
  display.setCursor(0, 20);
  display.print("Red (GPIO4): ");
  display.println(redCount);
  display.setCursor(0, 40);
  display.print("Green (GPIO7): ");
  display.println(greenCount);
  display.display();
}

void setup() {
  Serial.begin(115200);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redBtn, INPUT_PULLUP);
  pinMode(greenBtn, INPUT_PULLUP);
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, LOW);

  // Initialize OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED allocation failed");
    for (;;);
  }
  display.clearDisplay();
  updateDisplay();
}

void loop() {
  // Read button states
  bool redReading = digitalRead(redBtn);
  bool greenReading = digitalRead(greenBtn);

  // Debounce and count red button
  if (redReading != lastRedState) {
    lastDebounceTimeRed = millis();
  }
  if ((millis() - lastDebounceTimeRed) > debounceDelay) {
    if (redReading == LOW && redCount >= 0) {
      redCount++;
      digitalWrite(redLed, !digitalRead(redLed)); // toggle LED on each press
      updateDisplay();
    }
  }
  lastRedState = redReading;

  // Debounce and count green button
  if (greenReading != lastGreenState) {
    lastDebounceTimeGreen = millis();
  }
  if ((millis() - lastDebounceTimeGreen) > debounceDelay) {
    if (greenReading == LOW && greenCount >= 0) {
      greenCount++;
      digitalWrite(greenLed, !digitalRead(greenLed)); // toggle LED on each press
      updateDisplay();
    }
  }
  lastGreenState = greenReading;
}
