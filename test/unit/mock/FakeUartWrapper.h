#ifndef _FAKEUARTWRAPPER_H
#define _FAKEUARTWRAPPER_H

#include "utility/AbstractUartWrapper.h"
#include <Arduino.h>

using namespace Comm;

#define MAX_FUNC_CALLS 12

namespace CommUnit {
    class FakeUartWrapper: public AbstractUartWrapper {
        public:
            FakeUartWrapper();
            void Begin(unsigned long baudrate);
            int Available();
            int Read();
            size_t Write(byte value);
            size_t Write(const char *str);
            size_t Write(const uint8_t *buf, size_t len);
            void Flush();
            int Peek();
            void IoSetDirection(unsigned char bits);
            void IoSetState(unsigned char bits);
            bool HaveBeenCalledWith(const String &func, const String &args);

        private:
            bool PushCall(const String &func, const String &args);
            String calls_[2][MAX_FUNC_CALLS];
            int i_, j_;
    };
}

#endif
