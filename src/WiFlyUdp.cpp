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
}

void WiFlyUDPClass::Stop() {
    serverdrv_->StopClient();
}

int WiFlyUDPClass::BeginPacket(const char *host, uint16_t port) {
    int ret = 0;
    IPAddress remote_addr;
    if (wifly_->HostByName(host, remote_addr)) {
        return beginPacket(remote_addr, port);
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
    return write(&byte, 1);
}

size_t WiFlyUDPClass::Write(const uint8_t *buffer, size_t size) {
    serverdrv_->InsertDataBuf(buffer, size);
    return size;
}

int WiFlyUDPClass::ParsePacket() {
    return available();
}

int WiFlyUDPClass::Available() {
    return serverdrv_->AvailData();
}

int WiFlyUDPClass::Read() {
    uint8_t b;
    if (available()) {
        serverdrv_->GetData(&b);
        return b;
    } else {
        return -1;
    }
}

int WiFlyUDPClass::Read(unsigned char* buffer, size_t len) {
    if (available())
    {
        uint16_t size = 0;
        if (!serverdrv_->GetDataBuf(buffer, &size)) {
            return -1;
        }
        return size;
    } else {
        return -1;
    }
}

int WiFlyUDPClass::Peek() {
    uint8_t b;
    if (!available()) {
        return -1;
    }
    serverdrv_->GetData(&b, 1);
    return b;
}

void WiFlyUDPClass::Flush() {
    while (available()) {
        read();
    }
}

IPAddress WiFlyUDPClass::RemoteIP() {
    uint8_t remoteIp_[4] = {0};
    uint8_t remotePort_[2] = {0};
    wiflydrv_->GetRemoteData(remoteIp_, remotePort_);
    IPAddress ip(remoteIp_);
    return ip;
}

uint16_t WiFlyUDPClass::RemotePort() {
    uint8_t remoteIp_[4] = {0};
    uint8_t remotePort_[2] = {0};
    wiflydrv_->GetRemoteData(remoteIp_, remotePort_);
    uint16_t port = (remotePort_[0] << 8) + remotePort_[1];
    return port;
}
