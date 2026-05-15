## SensorTest

A simulation that reads a potentiometer (simulated heart rate) and a BMP180 pressure sensor, displays the values on an OLED, and allows switching between three display modes with a push button.

- **Hardware**: ESP32, potentiometer (GPIO34), BMP180 (I2C), SSD1306 OLED (I2C), push button (GPIO4).
- **Features**:
  - **Mode 0**: Show only potentiometer value (heart rate, 40–180 BPM).
  - **Mode 1**: Show only BMP180 pressure and altitude.
  - **Mode 2**: Show both.
  - Reliable button debouncing (short/long press) cycles through modes.
  - Shared `OLEDHelper` library (from `shared_libs/`) is used for display.
- **How to run**:
  1. Open the `SensorTest` folder in VS Code with PlatformIO.
  2. Build (`✓`) and start the Wokwi simulator.
  3. Press the green button to cycle modes; turn the potentiometer to change the simulated heart rate.

This project demonstrates using a shared library, robust button handling, and I2C sensor integration – all essential for the final wearable.
