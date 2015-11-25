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
            uint8_t Begin(uint16_t);
            void stop();
            void Stop();
            int beginPacket(IPAddress ip, uint16_t port);
            int BeginPacket(IPAddress ip, uint16_t port);
            int beginPacket(const char *host, uint16_t port);
            int BeginPacket(const char *host, uint16_t port);
            int endPacket();
            int EndPacket();
            size_t write(uint8_t);
            size_t Write(uint8_t);
            size_t write(const uint8_t *buffer, size_t size);
            size_t Write(const uint8_t *buffer, size_t size);
            int parsePacket();
            int ParsePacket();
            int available();
            int Available();
            int read();
            int Read();
            int read(unsigned char* buffer, size_t len);
            int Read(unsigned char* buffer, size_t len);
            int read(char* buffer, size_t len);
            int Read(char* buffer, size_t len);
            int Read(char *buffer, size_t len, unsigned long time_out);
            int peek();
            int Peek();
            void flush();
            void Flush();
            IPAddress remoteIP();
            IPAddress RemoteIP();
            uint16_t remotePort();
            uint16_t RemotePort();

        private:
            uint16_t port_;
            AbstractWiFly *wifly_;
            AbstractWiFlyDrv *wiflydrv_;
            AbstractServerDrv *serverdrv_;
    };
}

#endif
