#ifndef _SPIUARTWRAPPER_H
#define _SPIUARTWRAPPER_H

#include <WiFly.h>
#include "utility/AbstractUartWrapper.h"

namespace Comm {
    class SpiUartWrapper: public AbstractUartWrapper {
        public:
            // Own members
            SpiUartWrapper(SpiUartDevice &uart);

            // Abstract members
            void Begin(unsigned long baudrate);
            int Available();
            int Read();
            size_t Write(byte value);
            size_t Write(const char *str);
            void Flush();
            int Peek();
            void IoSetDirection(unsigned char bits);
            void IoSetState(unsigned char bits);
        private:
            SpiUartDevice uart_;
    };
}

#endif
