#include "Address.h"
#include "Serial.h"
#include "HardwareSerial.h"

using namespace Comm;


SerialClass::SerialClass(): _serial(Serial) {}

SerialClass::SerialClass(HardwareSerial hw): _serial(hw) {}

int SerialClass::Connect(AddressClass add) {}

size_t SerialClass::Write(uint8_t) {}

size_t SerialClass::Write(const uint8_t *buf, size_t size) {}

int SerialClass::Available() {}

int SerialClass::Read() {}

int SerialClass::Read(uint8_t *buf, size_t size) {}

int SerialClass::Peek() {}

void SerialClass::Flush() {}

void SerialClass::Stop() {}

uint8_t SerialClass::Connected() {}

SerialClass::operator bool() {}

SerialClass CommSerial(Serial);
