#include <Arduino.h>
#include <ArduinoUnit.h>
#include <Comm.h>
#include "UrlParserTest.h"
#include "WiFlyDrvTest.h"

Comm::UrlParserTest parser_test("Comm::UrlParserClass");
Comm::WiFlyDrvTest wiflydrv_test("Comm::WiFlyDrv");

void setup() {
    Serial.begin(9600);
    while(!Serial) {
        ;
    }
}

void loop() {
    Test::run();
}
