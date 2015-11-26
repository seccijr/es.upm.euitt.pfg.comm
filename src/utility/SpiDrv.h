#ifndef _SPIDRV_H
#define _SPIDRV_H

#include <Arduino.h>
#include "utility/SpiDrv.h"
#include "utility/wfl_spi.h"

class SpiDrv {
    public:
        static void begin(unsigned long baudrate = BAUD_RATE_DEFAULT);
        static int available();
        static int read();
        static size_t write(byte value);
        static size_t write(const char *str);
        static size_t write(const uint8_t *buf, size_t len);
        static void flush();
        static int peek();
        static void ioSetDirection(unsigned char bits);
        static void ioSetState(unsigned char bits);
        static bool uartConnected();

    private:
        static void configureUart(unsigned long baudrate);
        static void setBaudRate(unsigned long baudrate);
        static void writeRegister(byte address, byte data);
        static byte readRegister(byte address);
        static void deselect();
        static void select();
};

#endif
