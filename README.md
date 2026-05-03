# Wokwi ESP32 Simulations

A collection of ESP32 simulations using PlatformIO and the Wokwi extension.

## Two-Buttons-LEDs-OLED

Two pushbuttons toggle two independent LEDs. An OLED display shows "Hello, World!".

### How to run
1. Clone this repository.
2. Open the `Two-Buttons-LEDs-OLED` folder (or the root if files are there) in VS Code with PlatformIO.
3. Build and start the Wokwi simulator.

## Counter Version (Two-Buttons-LEDs-OLED-Counter)

Same hardware as above, but the OLED now shows **button press counters**:
- Press the blue button (GPIO4) → red LED toggles, red counter increments.
- Press the green button (GPIO7) → green LED toggles, green counter increments.

### How to run
1. Clone this repository.
2. Open the `Two-Buttons-LEDs-OLED-Counter` folder in VS Code with PlatformIO.
3. Build and start the Wokwi simulator.

## Future simulations
- Analog sensor (potentiometer)
- DHT22 temperature/humidity
- GPS and LoRa simulation (for wearable project)

Created by L8onESP32
