#include <Arduino.h>
#include <ArduinoUnit.h>
#include <Comm.h>
#include "UrlParserTest.h"

Comm::UrlParserTest parser_test = Comm::UrlParserTest("Comm::UrlParserClass");

void setup() {
    Serial.begin(9600);
    while(!Serial) {
        ;
    }
}

void loop() {
    Test::run();
}
