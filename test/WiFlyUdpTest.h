#ifndef _WIFLYUDPTEST_H
#define _WIFLYUDPTEST_H

#include <Arduino.h>
#include <ArduinoUnit.h>

namespace CommIntegration {
    class WiFlyUDPTest: public TestOnce {
        public:
            WiFlyUDPTest(const char *name): TestOnce(name) {
                verbosity = TEST_VERBOSITY_ALL;
            }
            void setup();
            void once();
        private:
            void TestWriteRead();
    };
}

#endif
