#include "SpiUartWrapperTest.h"
#include "utility/SpiUartWrapper.h"

using namespace Comm;
using namespace CommIntegration;

void SpiUartWrapperTest::TestBegin() {
    // Arrange
    SpiUartWrapper spiwrapper;

    // Act
    spiwrapper.Begin();

    // Assert
    assertTrue(spiwrapper.UartConnected());
}

void SpiUartWrapperTest::setup() {
}

void SpiUartWrapperTest::once() {
    TestBegin();
}
