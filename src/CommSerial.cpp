#include "CommAddress.h"
#include "CommSerial.h"
#include "HardwareSerial.h"


CommSerialClass::CommSerialClass(): _serial(Serial)
{};

CommSerialClass::CommSerialClass(HardwareSerial hw): _serial(hw)
{};

int CommSerialClass::Connect(CommAddressClass add)
{

}

size_t CommSerialClass::Write(uint8_t)
{

}

size_t CommSerialClass::Write(const uint8_t *buf, size_t size)
{

}

int CommSerialClass::Available()
{

}

int CommSerialClass::Read()
{

}

int CommSerialClass::Read(uint8_t *buf, size_t size)
{

}

int CommSerialClass::Peek()
{

}

void CommSerialClass::Flush()
{

}

void CommSerialClass::Stop()
{

}

uint8_t CommSerialClass::Connected()
{

}

CommSerialClass::operator bool()
{

}

CommSerialClass CommSerial(Serial);
