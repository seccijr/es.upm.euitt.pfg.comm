#ifndef _commclient_h
#define _commclient_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "CommAddress.h"
#include <stdint.h>

class CommClientClass {
    public:
        virtual ~CommClientClass(){};
        virtual int Connect(CommAddressClass add) =0;
        virtual size_t Write(uint8_t) =0;
        virtual size_t Write(const uint8_t *buf, size_t size) =0;
        virtual int Available() =0;
        virtual int Read() =0;
        virtual int Read(uint8_t *buf, size_t size) =0;
        virtual int Peek() =0;
        virtual void Flush() =0;
        virtual void Stop() =0;
        virtual uint8_t Connected() =0;
        virtual operator bool() =0;
};

#endif
