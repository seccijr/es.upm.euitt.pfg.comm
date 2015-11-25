#include <WiFlyUdp.h>
#include <WiFlyWiFi.h>
#include "utility/WiFlyDrv.h"
#include "utility/ServerDrv.h"
#include "utility/wfl_spi.h"

using namespace Comm;

WiFlyUDPClass::WiFlyUDPClass(
        AbstractWiFly *wifly,
        AbstractWiFlyDrv *wiflydrv,
        AbstractServerDrv *serverdrv):
    wifly_(wifly),
    wiflydrv_(wiflydrv),
    serverdrv_(serverdrv) {
    }

uint8_t WiFlyUDPClass::Begin(uint16_t port) {
    serverdrv_->StartServer(port, UDP_MODE);
    port_ = port;
    return port;
}

void WiFlyUDPClass::Stop() {
    serverdrv_->StopClient();
}

int WiFlyUDPClass::BeginPacket(const char *host, uint16_t port) {
    int ret = 0;
    IPAddress remote_addr;
    if (wifly_->HostByName(host, remote_addr)) {
        return BeginPacket(remote_addr, port);
    }
    return ret;
}

int WiFlyUDPClass::BeginPacket(IPAddress ip, uint16_t port) {
    serverdrv_->StartClient(uint32_t(ip), port, UDP_MODE);
}

int WiFlyUDPClass::EndPacket() {
    return serverdrv_->SendUdpData();
}

size_t WiFlyUDPClass::Write(uint8_t byte) {
    return Write(&byte, 1);
}

size_t WiFlyUDPClass::Write(const uint8_t *buffer, size_t size) {
    serverdrv_->InsertDataBuf(buffer, size);
    return size;
}

int WiFlyUDPClass::ParsePacket() {
    return Available();
}

int WiFlyUDPClass::Available() {
    return serverdrv_->AvailableData();
}

int WiFlyUDPClass::Read() {
    uint8_t b;
    if (Available() > 0) {
        serverdrv_->GetData(&b);
        return b;
    } else {
        return -1;
    }
}

int WiFlyUDPClass::Read(unsigned char *buffer, size_t len) {
    if (Available() > 0) {
        size_t size = 0;
        if (!serverdrv_->GetDataBuf(buffer, &size)) {
            return -1;
        }
        return size;
    } else {
        return -1;
    }
}

int WiFlyUDPClass::Read(char *buffer, size_t len) {
    return Read((unsigned char *)buffer, len);
}

int WiFlyUDPClass::Read(char *buffer, size_t len, unsigned long time_out) {
    int i = 0;
    bool smaller =  i < len;
    while (smaller) {
        unsigned long time_limit = millis() + time_out;
        while (Available() <= 0) {
            if (millis() > time_limit) {
                return -1;
            }
            delay(1);
        }
        if (smaller) {
            buffer[i++] = Read();
        }
        smaller = i < len;
    }
    return i;
}

int WiFlyUDPClass::Peek() {
    uint8_t b;
    if (Available() <= 0) {
        return -1;
    }
    serverdrv_->GetData(&b, 1);
    return b;
}

void WiFlyUDPClass::Flush() {
    while (Available() > 0) {
        Read();
    }
}
