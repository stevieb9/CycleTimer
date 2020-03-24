#ifndef CYCLETIMERRELAY_H
#define CYCLETIMERRELAY_H

#include "Arduino.h"
#include "../ArduinoRelay/ArduinoRelay.h"

using namespace std;

class CycleTimerRelay : public ArduinoRelay {

    private:
        uint8_t       _init     = false;
        unsigned long _onTime   = 0;
        unsigned long _offTime  = 0;
        unsigned long _pMillis  = 0;

    public:
        CycleTimerRelay(int8_t pin, unsigned long onTime, unsigned long offTime);
        CycleTimerRelay(unsigned long onTime, unsigned long offTime);

        uint8_t init () { return _init; }
        uint8_t init (uint8_t init) { _init = init; return _init; }
        
        unsigned long prevMillis () { return _pMillis; }
        unsigned long prevMillis (unsigned long millis) { _pMillis = millis; return _pMillis; }

        unsigned long onTime () { return _onTime; }
        unsigned long onTime (unsigned long millis) { _onTime = millis; return _onTime; }

        unsigned long offTime () { return _offTime; }
        unsigned long offTime (unsigned long millis) { _offTime = millis; return _offTime; }

        void    process ();
};

#endif

