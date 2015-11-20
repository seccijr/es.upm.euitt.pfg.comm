#include "FakeUartWrapper.h"

using namespace CommUnit;

FakeUartWrapper::FakeUartWrapper() {
    i_ = 0;
    j_ = 0;
}

void FakeUartWrapper::Begin(unsigned long baudrate) {
    PushCall("Begin", String(baudrate));
}

int FakeUartWrapper::Available() {
    int result = 0;
    PushCall("Begin", "");
    return result;
}

int FakeUartWrapper::Read() {
    int result = 0;
    return result;
}

size_t FakeUartWrapper::Write(byte value) {
    size_t result = 0;
    PushCall("Write", String(value));
    return result;
}

size_t FakeUartWrapper::Write(const char *str) {
    size_t result = 0;
    PushCall("Write", String(str));
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

bool FakeUartWrapper::HaveBeenCalledWith(const String &func, const String &args) {
    for (int i = 0; i <= i_; i++) {
        if (calls_[i][1] == func && calls_[i][2] == args) {
            return true;
        }
    }
    return false;
}

bool FakeUartWrapper::PushCall(const String &func, const String &args) {
    if (i_ < MAX_FUNC_CALLS) {
        calls_[i_][1] = func;
        calls_[i_][2] = args;
        i_++;
        return true;
    }
    return false;
}
