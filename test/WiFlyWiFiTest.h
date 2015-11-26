#ifndef _WIFLYWIFITEST_H
#define _WIFLYWIFITEST_H

#include <Arduino.h>
#include <ArduinoUnit.h>

namespace CommIntegration {
    class WiFlyWiFiTest: public TestOnce {
        public:
            WiFlyWiFiTest(const char *name): TestOnce(name) {
                verbosity = TEST_VERBOSITY_ALL;
            }
            void setup();
            void once();
        private:
            void testBeginOpen();
            void testBeginWPA2();
    };
}

#endif
