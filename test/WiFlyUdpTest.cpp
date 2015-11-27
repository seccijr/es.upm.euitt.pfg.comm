#include "WiFlyUdpTest.h"
#include "credentials.h"
#include <WiFlyWiFi.h>
#include <WiFlyUdp.h>

void WiFlyUDPTest::testWriteRead() {
    // Arrange
    IPAddress test_host(255, 255, 255, 255);
    size_t test_packet_len = 4;
    char test_packet[5] = "HOLA";
    char response[5] = {0};

    // Act
    WiFlyWiFi.begin((char *)OPEN_SSID);
    WiFlyUDP.beginPacket(test_host, 2000);
    WiFlyUDP.write((const uint8_t *)test_packet, test_packet_len);
    WiFlyUDP.endPacket();
    int result_read = WiFlyUDP.read(response, test_packet_len, 5000);

    // Assert
    assertEqual(result_read, test_packet_len);
    char *match = strstr(response, test_packet);
    assertTrue(response == match);
}

void WiFlyUDPTest::setup() {
}

void WiFlyUDPTest::once() {
    testWriteRead();
}
