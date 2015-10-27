#ifndef _COMMCLIENT_H
#define _COMMCLIENT_H

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "Address.h"
#include <stdint.h>

namespace Comm {
    class ClientClass {
        public:
            virtual ~ClientClass(){};
            virtual int Connect(AddressClass add) =0;
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
}

#endif
