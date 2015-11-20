#include "FakeUartWrapper.h"

using namespace Comm;

FakeUartWrapper::FakeUartWrapper() {
    begin_called_with = 0;
}

void FakeUartWrapper::Begin(unsigned long baudrate) {
    begin_called_with = baudrate;
}

int FakeUartWrapper::Available() {
    int result = 0;
    return result;
}

int FakeUartWrapper::Read() {
    int result = 0;
    return result;
}

size_t FakeUartWrapper::Write(byte value) {
    size_t result = 0;
    return result;
}

size_t FakeUartWrapper::Write(const char *str) {
    size_t result = 0;
    return result;
}

void FakeUartWrapper::Flush() {

}

int FakeUartWrapper::Peek() {
    int result = 0;
    return result;
}

void FakeUartWrapper::IoSetDirection(unsigned char bits) {

}

void FakeUartWrapper::IoSetState(unsigned char bits) {

}
