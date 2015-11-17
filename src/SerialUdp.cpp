#include <SerialUdp.h>
#include <HardwareSerial.h>

using namespace Comm;

/* Start SerialUDP socket, listening at PORT bauds */
uint8_t SerialUDP::begin(uint16_t port) {
    Serial.begin(port);
    while(!Serial) {
        ;
    }
    baud_ = port;
    return 1;

}

/* return number of bytes available in the current packet,
   will return zero if parsePacket hasn't been called yet */
int SerialUDP::available() {
    return Serial.available();
}

/* Release any resources being used by this SerialUDP instance */
void SerialUDP::stop() {}

int SerialUDP::beginPacket(const char *host, uint16_t port) {}

int SerialUDP::beginPacket(IPAddress ip, uint16_t port) {}

int SerialUDP::endPacket() {}

size_t SerialUDP::write(uint8_t byte) {
    return Serial.write(byte);
}

size_t SerialUDP::write(const uint8_t *buffer, size_t size) {
    return Serial.write(buffer, size);
}

int SerialUDP::parsePacket() {
    return available();
}

int SerialUDP::read() {
    uint8_t b;
    if (available()) {
        return Serial.read();
    } else {
        return -1;
    }
}

int SerialUDP::read(unsigned char* buffer, size_t len) {
    if (available()) {
        return Serial.readBytes(buffer, len);
    } else {
        return -1;
    }
}

int SerialUDP::peek() {
    if (!available())
        return -1;
    return Serial.peek();
}

void SerialUDP::flush() {
    Serial.flush();
}

IPAddress SerialUDP::remoteIP() {
    return IPAddress(255, 255, 255, 255);
}

uint16_t  SerialUDP::remotePort() {
    return baud_;
}

