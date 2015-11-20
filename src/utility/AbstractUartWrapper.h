#ifndef _ABSTRACTUARTWRAPPER_H
#define _ABSTRACTUARTWRAPPER_H

#include <Arduino.h>
#include <stdint.h>

namespace Comm {
    class AbstractUartWrapper {
        public:
            virtual void Begin(unsigned long baudrate) =0;
            virtual int Available() =0;
            virtual int Read() =0;
            virtual size_t Write(byte value) =0;
            virtual size_t Write(const char *str) =0;
            virtual void Flush() =0;
            virtual int Peek() =0;
            virtual void IoSetDirection(unsigned char bits) =0;
            virtual void IoSetState(unsigned char bits) =0;
    };
}

#endif
