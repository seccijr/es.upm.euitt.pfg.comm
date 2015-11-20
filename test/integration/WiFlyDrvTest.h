#ifndef _WIFLYDRVTEST_H
#define _WIFLYDRVTEST_H

#include <Arduino.h>
#include <ArduinoUnit.h>

namespace CommIntegration {
    class WiFlyDrvTest: public TestOnce {
        public:
            WiFlyDrvTest(const char *name): TestOnce(name) {
                verbosity = TEST_VERBOSITY_ALL;
            }
            void setup();
            void once();
        private:
            void TestSendCommand();
            void TestInit();
            void TestSetNetwork();
    };
}

#endif
