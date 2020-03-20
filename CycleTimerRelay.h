#ifndef CYCLETIMERRELAY_H
#define CYCLETIMERRELAY_H

#define DEBUG_TIMING true

#include "Arduino.h"

using namespace std;

class CycleTimerRelay {

    private:
        uint8_t _init           = false;
        uint8_t _reverseState   = false;
        uint8_t _on             = HIGH;
        uint8_t _off            = LOW;
        uint8_t _state          = _on;

        char*         _name     = "";
        int8_t        _pin      = -1;
        unsigned long _onTime   = 0;
        unsigned long _offTime  = 0;

        unsigned long _pMillis  = 0;

    public:
        /* Relay pin; On time; Off time */
        CycleTimerRelay(int8_t, unsigned long, unsigned long);
 
        /* No relay pin */
        CycleTimerRelay(unsigned long, unsigned long);

        void    process ();
        uint8_t state () { return _state; }

        char*   name () { return _name; }
        char*   name (char* name) { _name = name; }

        uint8_t reverse () { return _reverseState; }
        uint8_t reverse (uint8_t);

        unsigned long onTime () { return _onTime; }
        unsigned long onTime (unsigned long time) { _onTime = time; return _onTime; }

        unsigned long offTime () { return _offTime; }
        unsigned long offTime (unsigned long time) { _offTime = time; return _offTime; }

        int8_t pin () { return _pin; }
        int8_t pin (int8_t pin) { _pin = pin; return _pin; }
};

#endif

