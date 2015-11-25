#ifndef _WIFLYUDP_H
#define _WIFLYUDP_H

#include <stdint.h>
#include <Udp.h>
#include <WiFlyWiFi.h>
#include "utility/WiFlyDrv.h"
#include "utility/ServerDrv.h"

namespace Comm {
    class WiFlyUDPClass {
        public:
            WiFlyUDPClass(
                    WiFlyWiFiClass *wifly,
                    WiFlyDrv *wiflydrv,
                    ServerDrv *serverdrv);
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
            int Read(unsigned char *buffer, size_t len);
            int Read(char* buffer, size_t len);
            int Read(char *buffer, size_t len, unsigned long time_out);
            int Peek();
            void Flush();

        private:
            uint16_t port_;
            WiFlyWiFiClass *wifly_;
            WiFlyDrv *wiflydrv_;
            ServerDrv *serverdrv_;
    };
}

#endif
