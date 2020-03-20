#include "Arduino.h"
#include "CycleTimerRelay.h"

/* CONSTRUCTORS */

/* Default Constructor */

CycleTimerRelay::CycleTimerRelay (int8_t pin, unsigned long onTime, unsigned long offTime) {
    _pin = pin;
    _onTime = onTime;
    _offTime = offTime;
}

/* No Pin Constructor */

CycleTimerRelay::CycleTimerRelay (unsigned long onTime, unsigned long offTime) {
    _onTime = onTime;
    _offTime = offTime;
}

/* METHODS */

uint8_t CycleTimerRelay::reverse (uint8_t set) {

    if (set) {
        _reverseState = true; 
        _on = LOW;
        _off = HIGH;
    }

    return _reverseState;
}

void CycleTimerRelay::process () {

    if (_pin == -1) {
        return;
    }

    if (_pMillis == 0) {
        _pMillis = millis();
    }

    unsigned long currentMillis = millis();

    // Turn the outlet on

    if (_state == _off && currentMillis - _pMillis >= _offTime || ! _init) {
        if (! _init) {
            _init = true;
        }
        _state = _on;
        _pMillis = currentMillis;
        digitalWrite(_pin, _on);
    }

    // Turn the outlet off

    else if (_state == _on && currentMillis - _pMillis >= _onTime) {
        _state = _off;
        _pMillis = currentMillis;
        digitalWrite(_pin, _off);
    }
}
