#ifndef _WIFLYUDP_H
#define _WIFLYUDP_H

#include <stdint.h>
#include <Udp.h>
#include <AbstractWiFly.h>
#include "utility/AbstractWiFlyDrv.h"
#include "utility/AbstractServerDrv.h"

namespace Comm {
    class WiFlyUDPClass: public UDP {
        public:
            WiFlyUDPClass(
                    AbstractWiFly *wifly,
                    AbstractWiFlyDrv *wiflydrv,
                    AbstractServerDrv *serverdrv);
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
            int read(unsigned char* buffer, size_t len);
            int read(char* buffer, size_t len);
            int peek();
            void flush();
            IPAddress remoteIP();
            uint16_t remotePort();

        private:
            uint8_t sock_;
            uint16_t port_;
            AbstractWiFly *wifly_;
            AbstractWiFlyDrv *wiflydrv_;
            AbstractServerDrv *serverdrv_;
    };
}

#endif
