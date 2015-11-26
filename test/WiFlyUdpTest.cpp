#include "WiFlyUdpTest.h"
#include "credentials.h"
#include "utility/wfl_definitions.h"
#include "utility/WiFlyDrv.h"
#include "utility/ServerDrv.h"
#include "utility/SpiDrv.h"
#include <WiFlyWiFi.h>
#include <WiFlyUdp.h>

using namespace Comm;
using namespace CommIntegration;

void WiFlyUDPTest::testWriteRead() {
    // Arrange
    bool bored = false;
    IPAddress test_host(255, 255, 255, 255);
    size_t test_packet_len = 4;
    char test_packet[5] = "HOLA";
    char response[5] = {0};

    // Act
    WiFlyWiFi.begin((char *)SECURED_SSID, (char *)SECURED_PASS);
    WiFlyUDP.begin(4444);
    WiFlyUDP.beginPacket(test_host, 4444);
    WiFlyUDP.write((const uint8_t *)test_packet, test_packet_len);
    WiFlyUDP.endPacket();
    int result_read = WiFlyUDP.read(response, test_packet_len, 1000);

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
