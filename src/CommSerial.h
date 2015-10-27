#ifndef _commserial_h
#define _commserial_h

#include "CommClient.h"
#include "HardwareSerial.h"

class CommSerialClass: public CommClientClass
{
    private:
        HardwareSerial _serial;

    public:
        CommSerialClass();
        CommSerialClass(HardwareSerial hw);
        virtual int Connect(CommAddressClass add);
        virtual size_t Write(uint8_t);
        virtual size_t Write(const uint8_t *buf, size_t size);
        virtual int Available();
        virtual int Read();
        virtual int Read(uint8_t *buf, size_t size);
        virtual int Peek();
        virtual void Flush();
        virtual void Stop();
        virtual uint8_t Connected();
        virtual operator bool();
};

extern CommSerialClass CommSerial;

#endif

