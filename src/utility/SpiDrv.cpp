#include "utility/SpiDrv.h"
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

void SpiDrv::begin(unsigned long baudrate) {
    SPI.begin();
    do {
        configureUart(baudrate);
    } while(!uartConnected());
}

int SpiDrv::available() {
    int result = readRegister(RXLVL);
    return result;
}

int SpiDrv::read() {
    if (available() <= 0) {
        return -1;
    }
    return readRegister(RHR);
}

size_t SpiDrv::write(byte value) {
    while (readRegister(TXLVL) == 0) {}
    writeRegister(THR, value);
    return 1;
}

size_t SpiDrv::write(const char *str) {
    int len = strlen(str);
    size_t result = write((const uint8_t *) str, len);
    while (readRegister(TXLVL) < 64) {}
    return result;
}

size_t SpiDrv::write(const uint8_t *buffer, size_t size) {
    size_t n = 0;
    while (size--) {
        if (write(*buffer++)) n++;
        else break;
    }
    return n;
}

void SpiDrv::flush() {
    while(available() > 0) {
        //read();
        char c = (char)read();
    }
}

int SpiDrv::peek() {
    return 0;
}

void SpiDrv::ioSetDirection(unsigned char bits) {
    writeRegister(IODIR, bits);
}

void SpiDrv::ioSetState(unsigned char bits) {
    writeRegister(IOSTATE, bits);
}

void SpiDrv::configureUart(unsigned long baudrate) {
    setBaudRate(baudrate);
    writeRegister(LCR, EFR_ADDRESS);
    writeRegister(EFR, SPI_Uart_config.Flow);
    writeRegister(LCR, SPI_Uart_config.DataFormat);
    writeRegister(FCR, FIFO_REMOVE_RESET);
    writeRegister(FCR, FIFO_ENABLE);
}

bool SpiDrv::uartConnected() {
    const char TEST_CHARACTER = 'H';
    writeRegister(SPR, TEST_CHARACTER);
    return (readRegister(SPR) == TEST_CHARACTER);
}

void SpiDrv::setBaudRate(unsigned long baudrate) {
    unsigned long divisor = BAUD_RATE_DIVISOR(baudrate);
    writeRegister(LCR, LCR_ENABLE_DIVISOR_LATCH);
    writeRegister(DLL, lowByte(divisor));
    writeRegister(DLM, highByte(divisor));
}

void SpiDrv::writeRegister(byte address, byte data) {
    select();
    SPI.transfer(address);
    SPI.transfer(data);
    deselect();
}

byte SpiDrv::readRegister(byte address) {
    const byte SPI_DUMMY_BYTE = 0xFF;
    select();
    SPI.transfer(SPI_READ_MODE_FLAG | address);
    char result = SPI.transfer(SPI_DUMMY_BYTE);
    deselect();
    return result;
}

void SpiDrv::deselect() {
    digitalWrite(SS, HIGH);
}


void SpiDrv::select() {
    digitalWrite(SS, LOW);
}
