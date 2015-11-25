#include "WiFlyWiFiTest.h"
#include "utility/wfl_definitions.h"
#include "utility/WiFlyDrv.h"
#include "utility/SpiUartWrapper.h"
#include <WiFlyWiFi.h>

using namespace Comm;
using namespace CommIntegration;

void WiFlyWiFiTest::TestBeginOpen() {
    // Arrange
    SpiUartWrapper spi_uart;
    WiFlyDrv drv(&spi_uart);
    WiFlyWiFiClass wifi(&drv);
    char test_ssid[5] = "aros";

    // Act
    int result = wifi.Begin(test_ssid);

    // Assert
    assertTrue(result == WFL_CONNECTED);
}

void WiFlyWiFiTest::TestBeginWPA2() {
    // Arrange
    SpiUartWrapper spi_uart;
    WiFlyDrv drv(&spi_uart);
    WiFlyWiFiClass wifi(&drv);
    char test_ssid[6] = "secci";
    char test_pass[11] = "seccisecci";

    // Act
    int result = wifi.Begin(test_ssid, test_pass);

    // Assert
    assertTrue(result == WFL_CONNECTED);
}

void WiFlyWiFiTest::setup() {
}

void WiFlyWiFiTest::once() {
    TestBeginOpen();
    TestBeginWPA2();
}
