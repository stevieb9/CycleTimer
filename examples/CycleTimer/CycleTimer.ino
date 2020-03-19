#include "CycleTimer.h"

CycleTimer ct(2, 5000, 1000); // Pin, Start Millis, End Millis

void setup() {
    // Optionally set a name for the object
    ct.name("CT");
}

void loop() {

    // Signal the timer on each pass of loop()
    ct.process();

    // Check the current state of the pin
    bool state = ct.state();

    // Check if we're in reversed relay mode
    bool reversed = ct.reverse();

    // Get the name of the object
    char* name = ct.name();
}
