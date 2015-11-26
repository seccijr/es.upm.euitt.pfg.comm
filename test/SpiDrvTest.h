#ifndef _SPIDRVTEST_H
#define _SPIDRVTEST_H

#include <Arduino.h>
#include <ArduinoUnit.h>

class SpiDrvTest: public TestOnce {
    public:
        SpiDrvTest(const char *name): TestOnce(name) {
            verbosity = TEST_VERBOSITY_ALL;
        }
        void setup();
        void once();
    private:
        void testBegin();
        void testWrite();
};

#endif
