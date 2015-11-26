#ifndef _SERVERDRVTEST_H
#define _SERVERDRVTEST_H

#include <Arduino.h>
#include <ArduinoUnit.h>

namespace CommIntegration {
    class ServerDrvTest: public TestOnce {
        public:
            ServerDrvTest(const char *name): TestOnce(name) {
                verbosity = TEST_VERBOSITY_ALL;
            }
            void setup();
            void once();
        private:
            void testStartClientUdp();
            void testStartServerUdp();
    };
}

#endif
