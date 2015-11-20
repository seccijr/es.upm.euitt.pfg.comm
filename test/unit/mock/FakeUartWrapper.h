#ifndef _FAKEUARTWRAPPER_H
#define _FAKEUARTWRAPPER_H

#include "utility/AbstractUartWrapper.h"

namespace Comm {
    class FakeUartWrapper: public AbstractUartWrapper {
        public:
            FakeUartWrapper();
            void Begin(unsigned long baudrate);
            int Available();
            int Read();
            size_t Write(byte value);
            size_t Write(const char *str);
            void Flush();
            int Peek();
            void IoSetDirection(unsigned char bits);
            void IoSetState(unsigned char bits);
            unsigned long begin_called_with;
    };
}

#endif
