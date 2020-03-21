#ifndef CYCLETIMERRELAY_H
#define CYCLETIMERRELAY_H

#define DEBUG_TIMING true

#include "Arduino.h"
#include "../ArduinoRelay/ArduinoRelay.h"

using namespace std;

class CycleTimerRelay : public ArduinoRelay {

    private:
        unsigned long _onTime   = 0;
        unsigned long _offTime  = 0;
        unsigned long _pMillis  = 0;

    public:
        /* Relay pin; On time; Off time */
        CycleTimerRelay(int8_t, unsigned long, unsigned long);
 
        /* No relay pin */
        CycleTimerRelay(unsigned long, unsigned long);

        void    process ();

        unsigned long prevMillis () { return _pMillis; }
        unsigned long prevMillis (unsigned long millis) { _pMillis = millis; return _pMillis; }

        unsigned long onTime () { return _onTime; }
        unsigned long onTime (unsigned long time) { _onTime = time; return _onTime; }

        unsigned long offTime () { return _offTime; }
        unsigned long offTime (unsigned long time) { _offTime = time; return _offTime; }
};

#endif

