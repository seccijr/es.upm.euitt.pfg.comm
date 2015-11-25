#ifndef _SPIUARTWRAPPER_H
#define _SPIUARTWRAPPER_H

#include <Arduino.h>
#include "utility/SpiUartWrapper.h"
#include "utility/wfl_spi.h"

namespace Comm {
    class SpiUartWrapper: public Stream {
        public:
            void Begin(unsigned long baudrate = BAUD_RATE_DEFAULT);
            int available();
            int Available();
            int read();
            int Read();
            using Print::write;
            size_t write(byte value);
            size_t Write(byte value);
            size_t Write(const char *str);
            size_t Write(const uint8_t *buf, size_t len) {
                return write(buf, len);
            };
            void flush();
            void Flush();
            int peek();
            int Peek();
            void IoSetDirection(unsigned char bits);
            void IoSetState(unsigned char bits);
            bool UartConnected();

        private:
            void ConfigureUart(unsigned long baudrate);
            void SetBaudRate(unsigned long baudrate);
            void WriteRegister(byte address, byte data);
            byte ReadRegister(byte address);
            void Deselect();
            void Select();
    };
}

#endif
