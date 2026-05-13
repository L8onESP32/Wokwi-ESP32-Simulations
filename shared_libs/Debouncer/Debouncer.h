#ifndef DEBOUNCER_H
#define DEBOUNCER_H

#include <Arduino.h>

class Debouncer {
public:
    Debouncer(uint8_t pin, unsigned long delay_ms = 50);
    bool read();          // returns debounced state (LOW = pressed if INPUT_PULLUP)
    bool pressed();       // returns true only on falling edge (once per press)
    void update();        // call in loop

private:
    uint8_t _pin;
    unsigned long _delay;
    unsigned long _lastTime;
    bool _lastSteadyState;
    bool _lastFallingEdge;
    bool _state;
};

#endif
