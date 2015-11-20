#include "WiFlyDrvTest.h"
#include "utility/WiFlyDrv.h"
#include "mock/FakeUartWrapper.h"

using namespace Comm;

void WiFlyDrvTest::TestSendCommand() {
    // Arrange
    FakeUartWrapper f_uart_ = FakeUartWrapper();
    WiFlyDrv drv_ = WiFlyDrv(&f_uart_);
    const char test_cmd[4] = "ver";

    // Act
    drv_.SendCommand(test_cmd);

    // Assert
}

void WiFlyDrvTest::TestInit() {
    // Arrange
    FakeUartWrapper f_uart_ = FakeUartWrapper();
    WiFlyDrv drv_ = WiFlyDrv(&f_uart_);

    // Act
    drv_.Init();

    // Assert
    assertEqual(f_uart_.begin_called_with, SPI_DEFAULT_BAUDRATE);
}

void WiFlyDrvTest::TestSetNetwork() {
    // Arrange
    FakeUartWrapper f_uart_ = FakeUartWrapper();
    WiFlyDrv drv_ = WiFlyDrv(&f_uart_);
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
