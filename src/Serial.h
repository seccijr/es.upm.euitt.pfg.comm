#ifndef _COMMSERIAL_H
#define _COMMSERIAL_H

#include "Client.h"
#include "HardwareSerial.h"

namespace Comm {
    class SerialClass: public ClientClass {
        private:
            HardwareSerial _serial;

        public:
            SerialClass();
            SerialClass(HardwareSerial hw);
            virtual int Connect(AddressClass add);
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

    extern SerialClass CommSerial;
}

#endif

