#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1  // No reset pin

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int redLed = 5;
const int greenLed = 6;
const int redBtn = 4;
const int greenBtn = 7;

bool redState = false;
bool greenState = false;

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
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Hello, World!");
  display.display();
}

void loop() {
  // Red button toggles red LED
  if (digitalRead(redBtn) == LOW) {
    redState = !redState;
    digitalWrite(redLed, redState);
    delay(200);
  }
  // Green button toggles green LED
  if (digitalRead(greenBtn) == LOW) {
    greenState = !greenState;
    digitalWrite(greenLed, greenState);
    delay(200);
  }

  // Optional: update OLED with button states
  // (you can remove or comment out – it will keep showing "Hello, World!")
}