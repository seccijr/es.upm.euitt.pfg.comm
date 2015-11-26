#include <WiFlyUdp.h>
#include "utility/WiFlyDrv.h"
#include "utility/ServerDrv.h"
#include "utility/wfl_spi.h"

uint8_t WiFlyUDPClass::begin(uint16_t port) {
    ServerDrv::startServer(port, UDP_MODE);
    port_ = port;
    return port;
}

void WiFlyUDPClass::stop() {
    ServerDrv::stopClient();
}

int WiFlyUDPClass::beginPacket(const char *host, uint16_t port) {
    int ret = 0;
    IPAddress remote_addr;
    if (WiFlyDrv::getHostByName(host, remote_addr)) {
        return beginPacket(remote_addr, port);
    }
    return ret;
}

int WiFlyUDPClass::beginPacket(IPAddress ip, uint16_t port) {
    ServerDrv::startClient(uint32_t(ip), port, UDP_MODE);
}

int WiFlyUDPClass::endPacket() {
    return ServerDrv::sendUdpData();
}

size_t WiFlyUDPClass::write(uint8_t byte) {
    return write(&byte, 1);
}

size_t WiFlyUDPClass::write(const uint8_t *buffer, size_t size) {
    ServerDrv::insertDataBuf(buffer, size);
    return size;
}

int WiFlyUDPClass::parsePacket() {
    return available();
}

int WiFlyUDPClass::available() {
    return ServerDrv::availableData();
}

int WiFlyUDPClass::read() {
    uint8_t b;
    if (available() > 0) {
        ServerDrv::getData(&b);
        return b;
    } else {
        return -1;
    }
}

int WiFlyUDPClass::read(unsigned char *buffer, size_t len) {
    if (available() > 0) {
        size_t size = 0;
        if (!ServerDrv::getDataBuf(buffer, &size)) {
            return -1;
        }
        return size;
    } else {
        return -1;
    }
}

int WiFlyUDPClass::read(char *buffer, size_t len) {
    return read((unsigned char *)buffer, len);
}

int WiFlyUDPClass::read(char *buffer, size_t len, unsigned long time_out) {
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
        if (smaller) {
            buffer[i++] = read();
        }
        smaller = i < len;
    }
    return i;
}

int WiFlyUDPClass::peek() {
    uint8_t b;
    if (available() <= 0) {
        return -1;
    }
    ServerDrv::getData(&b, 1);
    return b;
}

void WiFlyUDPClass::flush() {
    while (available() > 0) {
        read();
    }
}

IPAddress WiFlyUDPClass::remoteIP() {

}

uint16_t WiFlyUDPClass::remotePort() {

}

WiFlyUDPClass WiFlyUDP;
