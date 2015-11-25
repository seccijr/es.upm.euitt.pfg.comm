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

uint8_t WiFlyUDPClass::begin(uint16_t port) {
    serverdrv_->StartServer(port, UDP_MODE);
    port_ = port;
    return port;
}

uint8_t WiFlyUDPClass::Begin(uint16_t port) {
    return begin(port);
}

void WiFlyUDPClass::stop() {
    serverdrv_->StopClient();
}
void WiFlyUDPClass::Stop() {
    stop();
}

int WiFlyUDPClass::beginPacket(const char *host, uint16_t port) {
    int ret = 0;
    IPAddress remote_addr;
    if (wifly_->HostByName(host, remote_addr)) {
        return BeginPacket(remote_addr, port);
    }
    return ret;
}

int WiFlyUDPClass::BeginPacket(const char *host, uint16_t port) {
    return beginPacket(host, port);
}

int WiFlyUDPClass::beginPacket(IPAddress ip, uint16_t port) {
    serverdrv_->StartClient(uint32_t(ip), port, UDP_MODE);
}

int WiFlyUDPClass::BeginPacket(IPAddress ip, uint16_t port) {
    return beginPacket(ip, port);
}

int WiFlyUDPClass::endPacket() {
    return serverdrv_->SendUdpData();
}

int WiFlyUDPClass::EndPacket() {
    return endPacket();
}

size_t WiFlyUDPClass::write(uint8_t byte) {
    return write(&byte, 1);
}

size_t WiFlyUDPClass::Write(uint8_t byte) {
    return write(byte);
}

size_t WiFlyUDPClass::write(const uint8_t *buffer, size_t size) {
    serverdrv_->InsertDataBuf(buffer, size);
    return size;
}

size_t WiFlyUDPClass::Write(const uint8_t *buffer, size_t size) {
    return write(buffer, size);
}

int WiFlyUDPClass::parsePacket() {
    return available();
}

int WiFlyUDPClass::ParsePacket() {
    return parsePacket();
}

int WiFlyUDPClass::available() {
    return serverdrv_->AvailableData();
}

int WiFlyUDPClass::Available() {
    return available();
}

int WiFlyUDPClass::read() {
    uint8_t b;
    if (Available() > 0) {
        serverdrv_->GetData(&b);
        return b;
    } else {
        return -1;
    }
}

int WiFlyUDPClass::Read() {
    return read();
}

int WiFlyUDPClass::read(unsigned char *buffer, size_t len) {
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

int WiFlyUDPClass::Read(unsigned char *buffer, size_t len) {
    return read(buffer, len);
}

int WiFlyUDPClass::read(char *buffer, size_t len) {
    return read((unsigned char *)buffer, len);
}

int WiFlyUDPClass::Read(char *buffer, size_t len) {
    return read(buffer, len);
}

int WiFlyUDPClass::Read(char *buffer, size_t len, unsigned long time_out) {
    int i = 0;
    bool smaller =  i < len;
    while (smaller) {
        unsigned long time_limit = millis() + time_out;
        while (available() <= 0) {
            if (millis() > time_limit) {
                return -1;
            }
            delay(1);
        }
        smaller = i < len;
        if (smaller) {
            buffer[i++] = read();
        }
    }
    return i;
}

int WiFlyUDPClass::peek() {
    uint8_t b;
    if (Available() <= 0) {
        return -1;
    }
    serverdrv_->GetData(&b, 1);
    return b;
}

int WiFlyUDPClass::Peek() {
    return peek();
}

void WiFlyUDPClass::flush() {
    while (Available() > 0) {
        Read();
    }
}

void WiFlyUDPClass::Flush() {
    return flush();
}

IPAddress WiFlyUDPClass::remoteIP() {
    return IPAddress(0, 0, 0, 0);
}

IPAddress WiFlyUDPClass::RemoteIP() {
    return remoteIP();
}

uint16_t WiFlyUDPClass::remotePort() {
    return 0;
}

uint16_t WiFlyUDPClass::RemotePort() {
    return remotePort();
}
