#ifndef _WIFLYUDP_H
#define _WIFLYUDP_H

#include <stdint.h>
#include <Udp.h>
#include <WiFlyWiFi.h>
#include "utility/WiFlyDrv.h"
#include "utility/ServerDrv.h"

namespace Comm {
    class WiFlyUDPClass: public UDP {
        public:
            uint8_t begin(uint16_t);
            void stop();
            int beginPacket(IPAddress ip, uint16_t port);
            int beginPacket(const char *host, uint16_t port);
            int endPacket();
            size_t write(uint8_t);
            size_t write(const uint8_t *buffer, size_t size);
            int parsePacket();
            int available();
            int read();
            int read(unsigned char *buffer, size_t len);
            int read(char* buffer, size_t len);
            int read(char *buffer, size_t len, unsigned long time_out);
            int peek();
            void flush();
            IPAddress remoteIP();
            uint16_t remotePort();

        private:
            uint16_t port_;
    };
}

#endif
