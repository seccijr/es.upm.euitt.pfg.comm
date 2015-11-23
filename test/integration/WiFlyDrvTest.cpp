#include "WiFlyDrvTest.h"
#include "utility/wfl_definitions.h"
#include "utility/WiFlyDrv.h"
#include "utility/SpiUartWrapper.h"

using namespace Comm;
using namespace CommIntegration;

void WiFlyDrvTest::TestInit() {
    // Arrange
    SpiUartWrapper spi_uart = SpiUartWrapper();
    WiFlyDrv drv = WiFlyDrv(&spi_uart);

    // Act
    drv.Init();

    // Assert
    assertTrue(spi_uart.UartConnected());
}

void WiFlyDrvTest::TestSendCommand() {
    // Arrange
    SpiUartWrapper spi_uart = SpiUartWrapper();
    WiFlyDrv drv = WiFlyDrv(&spi_uart);
    char response[MAX_CMD_RESPONSE_LEN + 1] = {0};

    // Act
    drv.Init();
    int8_t result = drv.SendCommand(CMD_VERSION, response, MAX_CMD_RESPONSE_LEN, WFL_END_COMMAND_STR);

    // Assert
    assertTrue(result == WFL_SUCCESS);
    char *match = strstr(response, "wifly-GSX");
    assertTrue(match != NULL);
}

void WiFlyDrvTest::TestEndCommand() {
    // Arrange
    SpiUartWrapper spi_uart = SpiUartWrapper();
    WiFlyDrv drv = WiFlyDrv(&spi_uart);
    char response[MAX_CMD_RESPONSE_LEN + 1] = {0};

    // Act
    drv.Init();
    int8_t result = drv.SendCommand(CMD_VERSION, response, MAX_CMD_RESPONSE_LEN, WFL_END_COMMAND_STR);

    // Assert
    assertTrue(result == WFL_SUCCESS);
    char *match = strstr(response, WFL_END_COMMAND_STR);
    assertTrue(match != NULL);
}

void WiFlyDrvTest::TestSetNetwork() {
    // Arrange
    SpiUartWrapper spi_uart = SpiUartWrapper();
    WiFlyDrv drv = WiFlyDrv(&spi_uart);
    char test_ssid[5] = "aros";

    // Act
    drv.Init();
    int8_t set_result = drv.SetNetwork(test_ssid, 8);

    // Assert
    assertTrue(set_result == WFL_SUCCESS);
}

void WiFlyDrvTest::TestSetPassphrase() {
    // Arrange
    SpiUartWrapper spi_uart = SpiUartWrapper();
    WiFlyDrv drv = WiFlyDrv(&spi_uart);
    char test_ssid[9] = "SECCIFLY";
    char test_pass[10] = "P4j4r1t0s";

    // Act
    drv.Init();
    int8_t set_result = drv.SetPassphrase(test_ssid, 8, test_pass, 9);

    // Assert
    assertTrue(set_result == WFL_SUCCESS);
}

void WiFlyDrvTest::setup() {
}

void WiFlyDrvTest::once() {
    TestInit();
    TestSendCommand();
    TestEndCommand();
    TestSetNetwork();
    TestSetPassphrase();
}
