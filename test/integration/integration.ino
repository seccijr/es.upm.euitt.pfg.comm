#include <Arduino.h>
#include <ArduinoUnit.h>
#include <Comm.h>
#include "SpiUartWrapperTest.h"

Comm::SpiUartWrapperTest spiwrapper_test("Comm::SpiUartWrapper");

void setup() {
    Serial.begin(9600);
    while(!Serial) {
        ;
    }
}

void loop() {
    Test::run();
}
