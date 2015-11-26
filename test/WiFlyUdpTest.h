#ifndef _WIFLYUDPTEST_H
#define _WIFLYUDPTEST_H

#include <Arduino.h>
#include <ArduinoUnit.h>

class WiFlyUDPTest: public TestOnce {
    public:
        WiFlyUDPTest(const char *name): TestOnce(name) {
            verbosity = TEST_VERBOSITY_ALL;
        }
        void setup();
        void once();
    private:
        void testWriteRead();
};

#endif
