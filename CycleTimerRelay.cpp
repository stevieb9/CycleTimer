#include "Arduino.h"
#include "CycleTimerRelay.h"

CycleTimerRelay::CycleTimerRelay (int8_t pin, unsigned long onTime, unsigned long offTime) : ArduinoRelay(pin) {
    _onTime = onTime;
    _offTime = offTime;
}

CycleTimerRelay::CycleTimerRelay (unsigned long onTime, unsigned long offTime) : ArduinoRelay() {
    _onTime = onTime;
    _offTime = offTime;
}

void CycleTimerRelay::process () {

    if (pin() == -1) {
        return;
    }

    if (prevMillis() == 0) {
        prevMillis(millis());
    }

    unsigned long currentMillis = millis();

    // Turn the outlet on

    if (state() == off() && currentMillis - prevMillis() >= offTime() || ! init()) {
        if (! init()) {
            init(true);
        }
        state(on());
        prevMillis(currentMillis);
        turnOn();
    }

    // Turn the outlet off

    else if (state() == on() && currentMillis - prevMillis() >= onTime()) {
        state(off());
        prevMillis(currentMillis);
        turnOff();
    }
}
