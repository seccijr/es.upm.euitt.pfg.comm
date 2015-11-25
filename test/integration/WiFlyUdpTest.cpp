#include "WiFlyUdpTest.h"
#include "utility/wfl_definitions.h"
#include "utility/WiFlyDrv.h"
#include "utility/ServerDrv.h"
#include "utility/SpiUartWrapper.h"
#include <WiFlyWiFi.h>
#include <WiFlyUdp.h>

using namespace Comm;
using namespace CommIntegration;

void WiFlyUDPTest::TestWriteRead() {
    // Arrange
    bool bored = false;
    SpiUartWrapper spi_uart;
    WiFlyDrv wiflydrv(&spi_uart);
    ServerDrv serverdrv(&wiflydrv, &spi_uart);
    WiFlyWiFiClass wiflywifi(&wiflydrv);
    WiFlyUDPClass wiflyudp(&wiflywifi, &wiflydrv, &serverdrv);
    IPAddress test_host(255, 255, 255, 255);
    size_t test_packet_len = 4;
    char test_packet[5] = "HOLA";
    char response[5] = {0};

    // Act
    wiflywifi.Begin("SECCIFLY", "P4j4r1t0s");
    wiflyudp.Begin(4444);
    wiflyudp.BeginPacket(test_host, 4444);
    wiflyudp.Write((const uint8_t *)test_packet, test_packet_len);
    wiflyudp.EndPacket();
    int result_read = wiflyudp.Read(response, test_packet_len, 1000);

    // Assert
    assertEqual(result_read, test_packet_len);
    char *match = strstr(response, test_packet);
    assertTrue(response == match);
}

void WiFlyUDPTest::setup() {
}

void WiFlyUDPTest::once() {
    TestWriteRead();
}
