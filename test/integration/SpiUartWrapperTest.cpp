#include "SpiUartWrapperTest.h"
#include "utility/SpiUartWrapper.h"
#include "utility/wfl_definitions.h"

using namespace Comm;
using namespace CommIntegration;

void SpiUartWrapperTest::TestBegin() {
    // Arrange
    SpiUartWrapper spi;

    // Act
    spi.Begin();

    // Assert
    assertTrue(spi.UartConnected());
}

void SpiUartWrapperTest::TestWrite() {
    // Arrange
    SpiUartWrapper spi;
    spi.Begin();
    char response[MAX_CMD_RESPONSE_LEN + 1] = {0};

    // Act
    spi.Flush();
    delay(WFL_COMMAND_GUARD_TIME);
    spi.Write("$$$");
    delay(WFL_COMMAND_GUARD_TIME);
    spi.Write(13);
    delay(WFL_COMMAND_GUARD_TIME);
    spi.Flush();
    spi.Write(CMD_VERSION);
    spi.Write(13);
    delay(WFL_COMMAND_GUARD_TIME);
    bool read_condition = true, smaller, ended;
    int i = 0;
    do {
        unsigned long time_out = millis() + WFL_READ_TIMEOUT;
        while (spi.Available() <= 0) {
            if (millis() > time_out) {
                i = MAX_CMD_RESPONSE_LEN;
                break;
            }
            delay(1);
        }
        smaller = i < MAX_CMD_RESPONSE_LEN;
        if (smaller) {
            response[i++] = spi.Read();
        }
        ended = strstr(response, WFL_END_COMMAND_STR) != NULL;
        read_condition =  smaller && !ended;
    } while (read_condition);
    delay(WFL_COMMAND_GUARD_TIME);
    spi.Flush();
    spi.Write("exit");
    spi.Write(13);

    // Assert
    char *match = strstr(response, "wifly-GSX");
    assertTrue(match != NULL);
}

void SpiUartWrapperTest::setup() {
}

void SpiUartWrapperTest::once() {
    TestBegin();
    TestWrite();
}
