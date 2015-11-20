#include "WiFlyDrvTest.h"
#include "utility/WiFlyDrv.h"
#include "mock/FakeUartWrapper.h"

using namespace Comm;
using namespace CommUnit;

void WiFlyDrvTest::TestSendCommand() {
    // Arrange
    FakeUartWrapper f_uart = FakeUartWrapper();
    WiFlyDrv drv_ = WiFlyDrv(&f_uart);
    const char test_cmd[4] = "ver";

    // Act
    drv_.SendCommand(test_cmd);

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
    assertTrue(f_uart.HaveBeenCalledWith("Begin", String(SPI_DEFAULT_BAUDRATE)));
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
