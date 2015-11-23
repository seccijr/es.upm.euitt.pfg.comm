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
            uint8_t Begin(uint16_t);
            void Stop();
            int BeginPacket(IPAddress ip, uint16_t port);
            int BeginPacket(const char *host, uint16_t port);
            int EndPacket();
            size_t Write(uint8_t);
            size_t Write(const uint8_t *buffer, size_t size);
            int ParsePacket();
            int Available();
            int Read();
            int Read(unsigned char* buffer, size_t len);
            int Read(char* buffer, size_t len);
            int Peek();
            void Flush();

        private:
            uint16_t port_;
            AbstractWiFly *wifly_;
            AbstractWiFlyDrv *wiflydrv_;
            AbstractServerDrv *serverdrv_;
    };
}

#endif
