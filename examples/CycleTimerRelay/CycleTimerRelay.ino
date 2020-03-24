#include "CycleTimerRelay.h"

#define RELAY_PIN   2
#define ON_MILLIS   5000
#define OFF_MILLIS  1000

/* Normal constructor */
CycleTimerRelay ctr(RELAY_PIN, ON_MILLIS, OFF_MILLIS);

/* No pin constructor */
//CycleTimerRelay ctr(ON_MILLIS, OFF_MILLIS);

void setup() {
    /* Reverse: On = LOW, Off = HIGH */
    //ctr.reverse(true);
}

void loop() {

    /* Signal the timer on each pass of loop() */
    ctr.process();

    /* Check the current state of the pin */
    bool state = ctr.state();

    /* Check reverse state */
    bool reversed = ctr.reverse();
    
    /* Get the on or off times */
    unsigned long onTime  = ctr.onTime();
    unsigned long offTime = ctr.offTime();

    /* Set the on and off cycle times */
    ctr.onTime(ON_MILLIS);
    ctr.offTime(OFF_MILLIS);

    /* Get/set the relay pin */
    int8_t = ctr.pin();
    //ctr.pin(RELAY_PIN);

    /* Disable the relay */
    //ctr.pin(-1);
}
