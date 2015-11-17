#ifndef _COMMSERIALUDP_H
#define _COMMSERIALUDP_H

#include <Arduino.h>
#include <Udp.h>
#include <stdint.h>

namespace Comm {
    class SerialUDP: UDP {
        public:
            SerialUDP() {};
            virtual uint8_t begin(uint16_t);
            virtual void stop();
            virtual int beginPacket(IPAddress ip, uint16_t port);
            virtual int beginPacket(const char *host, uint16_t port);
            virtual int endPacket();
            virtual size_t write(uint8_t);
            virtual size_t write(const uint8_t *buffer, size_t size);
            virtual int parsePacket();
            virtual int available();
            virtual int read();
            virtual int read(unsigned char* buffer, size_t len);
            virtual int read(char* buffer, size_t len) { return read((unsigned char*)buffer, len); };
            virtual int peek();
            virtual void flush();
            virtual IPAddress remoteIP();
            virtual uint16_t remotePort();
        private:
            uint16_t baud_;
    };
}

#endif
