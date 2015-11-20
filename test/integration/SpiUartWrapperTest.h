#ifndef _SPIUARTWRAPPERTEST_H
#define _SPIUARTWRAPPERTEST_H

#include <Arduino.h>
#include <ArduinoUnit.h>

namespace Comm {
    class SpiUartWrapperTest: public TestOnce {
        public:
            SpiUartWrapperTest(const char *name): TestOnce(name) {
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
