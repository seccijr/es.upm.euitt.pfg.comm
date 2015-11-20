#ifndef _SPIUARTWRAPPER_H
#define _SPIUARTWRAPPER_H

#include "utility/AbstractUartWrapper.h"

#define THR        0x00 << 3
#define RHR        0x00 << 3
#define IER        0x01 << 3
#define FCR        0x02 << 3
#define IIR        0x02 << 3
#define LCR        0x03 << 3
#define MCR        0x04 << 3
#define LSR        0x05 << 3
#define MSR        0x06 << 3
#define SPR        0x07 << 3
#define TXLVL      0x08 << 3
#define RXLVL      0x09 << 3
#define DLAB       0x80 << 3
#define IODIR      0x0A << 3
#define IOSTATE    0x0B << 3
#define IOINTMSK   0x0C << 3
#define IOCTRL     0x0E << 3
#define EFCR       0x0F << 3

#define DLL        0x00 << 3
#define DLM        0x01 << 3
#define EFR        0x02 << 3
#define XON1       0x04 << 3
#define XON2       0x05 << 3
#define XOFF1      0x06 << 3
#define XOFF2      0x07 << 3

#define SPI_READ_MODE_FLAG 0x80
#define BAUD_RATE_DEFAULT 9600

#define EFR_ENABLE_CTS 1 << 7
#define EFR_ENABLE_RTS 1 << 6
#define EFR_ENABLE_ENHANCED_FUNCTIONS 1 << 4
#define EFR_ADDRESS 0xBF
#define FIFO_REMOVE_RESET 0x06
#define FIFO_ENABLE 0x01
#define LCR_ENABLE_DIVISOR_LATCH 1 << 7

#ifndef USE_14_MHZ_CRYSTAL
#define USE_14_MHZ_CRYSTAL true
#endif

#if USE_14_MHZ_CRYSTAL
#define XTAL_FREQUENCY 14745600UL
#else
#define XTAL_FREQUENCY 12288000UL
#endif

#define PRESCALER 1
#define BAUD_RATE_DIVISOR(baud) ((XTAL_FREQUENCY/PRESCALER)/(baud*16UL))

namespace Comm {
    class SpiUartWrapper: public AbstractUartWrapper, public Stream {
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
