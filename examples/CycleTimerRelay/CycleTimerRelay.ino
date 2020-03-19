#include "CycleTimerRelay.h"

CycleTimerRelay ctr(2, 5000, 1000); // Pin, Start Millis, End Millis

void setup() {
    // Optionally set a name for the object
    ctr.name("CTR");
}

void loop() {

    // Signal the timer on each pass of loop()
    ctr.process();

    // Check the current state of the pin
    bool state = ctr.state();

    // Check if we're in reversed relay mode
    bool reversed = ctr.reverse();

    // Get the name of the object
    char* name = ctr.name();
}
