#include "Debouncer.h"

Debouncer::Debouncer(uint8_t pin, unsigned long delay_ms)
    : _pin(pin), _delay(delay_ms), _lastTime(0), _lastSteadyState(HIGH), _lastFallingEdge(false), _state(HIGH) {
    pinMode(_pin, INPUT_PULLUP);
}

void Debouncer::update() {
    bool reading = digitalRead(_pin);
    if (reading != _lastSteadyState) {
        _lastTime = millis();
    }
    if ((millis() - _lastTime) > _delay) {
        if (reading != _state) {
            _state = reading;
            if (_state == LOW) _lastFallingEdge = true;
        }
    }
    _lastSteadyState = reading;
}

bool Debouncer::read() {
    return _state;
}

bool Debouncer::pressed() {
    if (_lastFallingEdge) {
        _lastFallingEdge = false;
        return true;
    }
    return false;
}
