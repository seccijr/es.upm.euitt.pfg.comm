#include "ServerDrvTest.h"
#include "utility/ServerDrv.h"
#include "utility/WiFlyDrv.h"
#include "utility/SpiUartWrapper.h"
#include "WiFlyWiFi.h"
#include <IPAddress.h>

using namespace Comm;
using namespace CommIntegration;

void ServerDrvTest::TestStartClient() {
    // Arrange
    SpiUartWrapper spi_uart = SpiUartWrapper();
    WiFlyDrv wiflydrv = WiFlyDrv(&spi_uart);
    ServerDrv drv = ServerDrv(&wiflydrv);
    char test_ssid[9] = "SECCIFLY";
    char test_pass[10] = "P4j4r1t0s";
    uint16_t remote_port = 4444;
    uint8_t remote_ip_raw[4] = {192, 168, 1, 107};
    IPAddress remote_ip(remote_ip_raw);

    // Act
    wiflydrv.Init();
    wiflydrv.SetPassphrase(test_ssid, 8, test_pass, 9);
    drv.StartClient((uint32_t)remote_ip, remote_port, UDP_MODE);

    // Assert
}

void ServerDrvTest::setup() {
}

void ServerDrvTest::once() {
    TestStartClient();
}
