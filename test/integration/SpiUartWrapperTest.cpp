#include "SpiUartWrapperTest.h"
#include "utility/SpiUartWrapper.h"

using namespace Comm;

void SpiUartWrapperTest::TestBegin() {
    // Arrange
    SpiUartDevice test_uart;
    SpiUartWrapper spiwrapper = SpiUartWrapper(test_uart);
    unsigned long test_baudrate = 9600;

    // Act
    spiwrapper.Begin(test_baudrate);

    // Assert
}

void SpiUartWrapperTest::setup() {
}

void SpiUartWrapperTest::once() {
}
