#include "utility/SpiUartWrapper.h"

using namespace Comm;

SpiUartWrapper::SpiUartWrapper(SpiUartDevice &uart): uart_(uart) {}

void SpiUartWrapper::Begin(unsigned long baudrate) {

}

int SpiUartWrapper::Available() {
    int result = 0;
    return result;
}

int SpiUartWrapper::Read() {
    int result = 0;
    return result;
}

size_t SpiUartWrapper::Write(byte value) {
    size_t result = 0;
    return result;
}

size_t SpiUartWrapper::Write(const char *str) {
    size_t result = 0;
    return result;
}

void SpiUartWrapper::Flush() {

}

int SpiUartWrapper::Peek() {
    int result = 0;
    return result;
}

void SpiUartWrapper::IoSetDirection(unsigned char bits) {

}

void SpiUartWrapper::IoSetState(unsigned char bits) {

}
