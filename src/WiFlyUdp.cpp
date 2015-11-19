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
    sock_(NO_SOCKET_AVAIL),
    wifly_(wifly),
    wiflydrv_(wiflydrv),
    serverdrv_(serverdrv) {
}

uint8_t WiFlyUDPClass::begin(uint16_t port) {
    uint8_t sock = wifly_->getSocket();
    if (sock != NO_SOCKET_AVAIL) {
        serverdrv_->startServer(port, sock, UDP_MODE);
        wifly_->server_port[sock] = port;
        sock_ = sock;
        port_ = port;
        return 1;
    }
    return 0;
}

void WiFlyUDPClass::stop() {
    if (sock_ == NO_SOCKET_AVAIL) {
        return;
    }
    serverdrv_->stopClient(sock_);
    sock_ = NO_SOCKET_AVAIL;
}

int WiFlyUDPClass::beginPacket(const char *host, uint16_t port) {
    int ret = 0;
    IPAddress remote_addr;
    if (wifly_->hostByName(host, remote_addr)) {
        return beginPacket(remote_addr, port);
    }
    return ret;
}

int WiFlyUDPClass::beginPacket(IPAddress ip, uint16_t port) {
    if (sock_ == NO_SOCKET_AVAIL) {
        sock_ = wifly_->getSocket();
    }
    if (sock_ != NO_SOCKET_AVAIL) {
        serverdrv_->startClient(uint32_t(ip), port, sock_, UDP_MODE);
        wifly_->state[sock_] = sock_;
        return 1;
    }
    return 0;
}

int WiFlyUDPClass::endPacket() {
    return serverdrv_->sendUdpData(sock_);
}

size_t WiFlyUDPClass::write(uint8_t byte) {
    return write(&byte, 1);
}

size_t WiFlyUDPClass::write(const uint8_t *buffer, size_t size) {
    serverdrv_->insertDataBuf(sock_, buffer, size);
    return size;
}

int WiFlyUDPClass::parsePacket() {
    return available();
}

int WiFlyUDPClass::available() {
    if (sock_ != NO_SOCKET_AVAIL) {
        return serverdrv_->availData(sock_);
    }
    return 0;
}

int WiFlyUDPClass::read() {
    uint8_t b;
    if (available()) {
        serverdrv_->getData(sock_, &b);
        return b;
    } else {
        return -1;
    }
}

int WiFlyUDPClass::read(unsigned char* buffer, size_t len) {
    if (available())
    {
        uint16_t size = 0;
        if (!serverdrv_->getDataBuf(sock_, buffer, &size)) {
            return -1;
        }
        return size;
    } else {
        return -1;
    }
}

int WiFlyUDPClass::peek() {
    uint8_t b;
    if (!available()) {
        return -1;
    }
    serverdrv_->getData(sock_, &b, 1);
    return b;
}

void WiFlyUDPClass::flush() {
    while (available()) {
        read();
    }
}

IPAddress WiFlyUDPClass::remoteIP() {
    uint8_t remoteIp_[4] = {0};
    uint8_t remotePort_[2] = {0};
    wiflydrv_->GetRemoteData(sock_, remoteIp_, remotePort_);
    IPAddress ip(remoteIp_);
    return ip;
}

uint16_t WiFlyUDPClass::remotePort() {
    uint8_t remoteIp_[4] = {0};
    uint8_t remotePort_[2] = {0};
    wiflydrv_->GetRemoteData(sock_, remoteIp_, remotePort_);
    uint16_t port = (remotePort_[0] << 8) + remotePort_[1];
    return port;
}
