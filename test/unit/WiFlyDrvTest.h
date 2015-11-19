#ifndef _URLPARSERTEST_H
#define _URLPARSERTEST_H

#include <Arduino.h>
#include <ArduinoUnit.h>

namespace Comm {
    class WiFlyDrvTest: public TestOnce {
        public:
            WiFlyDrvTest(const char *name): TestOnce(name) {
                verbosity = TEST_VERBOSITY_ALL;
            }
            void setup();
            void once();
        private:
            void TestInit();
    };
}

#endif
