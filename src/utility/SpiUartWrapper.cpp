#include "utility/SpiUartWrapper.h"
#include "utility/wfl_spi.h"
#include <Arduino.h>
#include <SPI.h>

struct SPI_UART_cfg {
    char DataFormat;
    char Flow;
};

struct SPI_UART_cfg SPI_Uart_config = {
    0x03,
    EFR_ENABLE_CTS | EFR_ENABLE_RTS | EFR_ENABLE_ENHANCED_FUNCTIONS
};

using namespace Comm;

void SpiUartWrapper::Begin(unsigned long baudrate) {
    SPI.begin();
    do {
        ConfigureUart(baudrate);
    } while(!UartConnected());
}

int SpiUartWrapper::available() {
    return (ReadRegister(RXLVL));
}

int SpiUartWrapper::Available() {
    return available();
}

int SpiUartWrapper::read() {
    if (!Available()) {
        return -1;
    }
    return ReadRegister(RHR);
}

int SpiUartWrapper::Read() {
    return read();
}

size_t SpiUartWrapper::write(byte value) {
    while (ReadRegister(TXLVL) == 0) {}
    WriteRegister(THR, value);
    return 1;
}

size_t SpiUartWrapper::Write(byte value) {
    return write(value);
}

size_t SpiUartWrapper::Write(const char *str) {
    int len = strlen(str);
    write((const uint8_t *) str, len);
    while (ReadRegister(TXLVL) < 64) {}
    return len;
}

void SpiUartWrapper::flush() {
    while(Available() > 0) {
        Read();
    }
}

void SpiUartWrapper::Flush() {
    flush();
}

int SpiUartWrapper::peek() {
    return 0;
}

int SpiUartWrapper::Peek() {
    return peek();
}

void SpiUartWrapper::IoSetDirection(unsigned char bits) {
    WriteRegister(IODIR, bits);
}

void SpiUartWrapper::IoSetState(unsigned char bits) {
    WriteRegister(IOSTATE, bits);
}

void SpiUartWrapper::ConfigureUart(unsigned long baudrate) {
    SetBaudRate(baudrate);
    WriteRegister(LCR, EFR_ADDRESS);
    WriteRegister(EFR, SPI_Uart_config.Flow);
    WriteRegister(LCR, SPI_Uart_config.DataFormat);
    WriteRegister(FCR, FIFO_REMOVE_RESET);
    WriteRegister(FCR, FIFO_ENABLE);
}

bool SpiUartWrapper::UartConnected() {
    const char TEST_CHARACTER = 'H';
    WriteRegister(SPR, TEST_CHARACTER);
    return (ReadRegister(SPR) == TEST_CHARACTER);
}

void SpiUartWrapper::SetBaudRate(unsigned long baudrate) {
    unsigned long divisor = BAUD_RATE_DIVISOR(baudrate);
    WriteRegister(LCR, LCR_ENABLE_DIVISOR_LATCH);
    WriteRegister(DLL, lowByte(divisor));
    WriteRegister(DLM, highByte(divisor));
}

void SpiUartWrapper::WriteRegister(byte address, byte data) {
    Select();
    SPI.transfer(address);
    SPI.transfer(data);
    Deselect();
}

byte SpiUartWrapper::ReadRegister(byte address) {
    const byte SPI_DUMMY_BYTE = 0xFF;
    Select();
    SPI.transfer(SPI_READ_MODE_FLAG | address);
    char result = SPI.transfer(SPI_DUMMY_BYTE);
    Deselect();
    return result;
}

void SpiUartWrapper::Deselect() {
    digitalWrite(SS, HIGH);
}


void SpiUartWrapper::Select() {
    digitalWrite(SS, LOW);
}
