#include "CycleTimerRelay.h"

/* Normal constructor */
CycleTimerRelay ctr(2, 5000, 1000); // Pin, Start Millis, End Millis

/* No pin constructor */
//CycleTimerRelay ctr(5000, 1000); // Pin, Start Millis, End Millis

void setup() {
    /* Optionally set a name for the object */
    ctr.name("CTR");

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
    
    /* Get the name of the object */
    char* name = ctr.name();

    /* Get and change the on or off times */
    unsigned long onTime  = ctr.onTime();
    unsigned long offTime = ctr.offTime();

    ctr.onTime(5000);
    ctr.offTime(1000);

    /* Get/set the relay pin */

    int8_t = ctr.pin();
    //ctr.pin(2);

    /* Disable the relay */
    //ctr.pin(-1);
}
