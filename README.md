
## Projects

### `Two-Buttons-LEDs-OLED`
- Two pushbuttons (GPIO4, GPIO7) toggle two LEDs (GPIO5, GPIO6)
- OLED displays "Hello, World!"
- **Simulation**: [Open in Wokwi](https://wokwi.com/projects/new/esp32) (copy diagram.json and code)

### `Two-Buttons-LEDs-OLED-Counter`
- Same hardware, but OLED shows how many times each button has been pressed
- Uses non‑blocking debounce (one count per press)

### `ESP32-D0WD-V3-Blink-LED`
- Classic LED blink (built‑in LED) – verifies basic platform setup
- **Includes a test of shared libraries** – demonstrates how to reuse code from `shared_libs/TestLib`
- The test prints `"Shared library works!"` to the serial monitor

## Shared libraries (`shared_libs/`)

Custom code that can be copied into any project’s `lib/` folder.  
Currently contains:

- `TestLib/` – a minimal test library (proves that libraries can be shared across projects)
- `Debouncer/` – example debouncer class (work in progress)

To use a shared library in a project, copy its folder into the project’s `lib/` directory.  
PlatformIO automatically includes such libraries.

## Potentiometer-Reading

Simple analog read from a potentiometer connected to GPIO26. Serial output shows raw values (0‑4095).  
- **Uses** `esp:TX0`/`esp:RX0` for reliable serial monitor.
- **Demonstrates** `analogRead()` and live terminal output.

[Diagram and code](./Potentiometer-Reading/)
## How to run a simulation

1. Open a project folder (e.g., `Two-Buttons-LEDs-OLED`) in VS Code.
2. Build the project (`✓` button in PlatformIO toolbar).
3. Start Wokwi: `F1` → `Wokwi: Start Simulator`.

## License

MIT – free to use, modify, and share.

Created by [L8onESP32](https://github.com/L8onESP32)
