#include "WiFlyDrvTest.h"
#include "utility/WiFlyDrv.h"
#include "utility/wfl_definitions.h"
#include "utility/wfl_spi.h"
#include "mock/FakeUartWrapper.h"

using namespace Comm;
using namespace CommUnit;

void WiFlyDrvTest::TestSendCommand() {
    // Arrange
    FakeUartWrapper f_uart = FakeUartWrapper();
    WiFlyDrv drv_ = WiFlyDrv(&f_uart);
    const char test_cmd[4] = "ver";
    char response[MAX_CMD_RESPONSE_LEN];

    // Act
    drv_.SendCommand(test_cmd, response, MAX_CMD_RESPONSE_LEN, "<4.00>");

    // Assert
    assertTrue(f_uart.HaveBeenCalledWith("Write", "$$$"));
}

void WiFlyDrvTest::TestInit() {
    // Arrange
    FakeUartWrapper f_uart = FakeUartWrapper();
    WiFlyDrv drv_ = WiFlyDrv(&f_uart);

    // Act
    drv_.Init();

    // Assert
    assertTrue(f_uart.HaveBeenCalledWith("Begin", String(BAUD_RATE_DEFAULT)));
}

void WiFlyDrvTest::TestSetNetwork() {
    // Arrange
    FakeUartWrapper f_uart = FakeUartWrapper();
    WiFlyDrv drv_ = WiFlyDrv(&f_uart);
    char test_ssid[5] = "aros";

    // Act
    drv_.SetNetwork(test_ssid, strlen(test_ssid));

    // Assert
}

void WiFlyDrvTest::setup() {
}

void WiFlyDrvTest::once() {
    TestSendCommand();
    TestInit();
    TestSetNetwork();
}
