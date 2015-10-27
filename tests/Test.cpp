#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "ArduinoUnit.h"
#include "src/Comm.h"

using namespace UrlParser;


test(http_scheme) {
    String url = String("https://github.com/seccijr/quintocrawl");
    ParseUrlClass parsed = ParseUrlClass::ParseUrl(url);
    assertEqual(parsed.get_scheme().c_str(), "http");
}

void setup() {
    Serial.begin(9600);
    while(!Serial.available()) {
        ;
    }
}

void loop() {
    Test::run();
}
