#include "SpiDrvTest.h"
#include "utility/SpiDrv.h"
#include "utility/wfl_definitions.h"

using namespace Comm;
using namespace CommIntegration;

void SpiDrvTest::testBegin() {
    // Arrange
    // Act
    // Assert
    assertTrue(SpiDrv::uartConnected());
}

void SpiDrvTest::testWrite() {
    // Arrange
    char response[MAX_CMD_RESPONSE_LEN + 1] = {0};

    // Act
    SpiDrv::flush();
    delay(WFL_COMMAND_GUARD_TIME);
    SpiDrv::write("$$$");
    delay(WFL_COMMAND_GUARD_TIME);
    SpiDrv::write(13);
    delay(WFL_COMMAND_GUARD_TIME);
    SpiDrv::flush();
    SpiDrv::write(CMD_VERSION);
    SpiDrv::write(13);
    delay(WFL_COMMAND_GUARD_TIME);
    bool read_condition = true, smaller, ended;
    int i = 0;
    do {
        unsigned long time_out = millis() + WFL_READ_TIMEOUT;
        while (SpiDrv::available() <= 0) {
            if (millis() > time_out) {
                i = MAX_CMD_RESPONSE_LEN;
                break;
            }
            delay(1);
        }
        smaller = i < MAX_CMD_RESPONSE_LEN;
        if (smaller) {
            response[i++] = SpiDrv::read();
        }
        ended = strstr(response, WFL_END_COMMAND_STR) != NULL;
        read_condition =  smaller && !ended;
    } while (read_condition);
    delay(WFL_COMMAND_GUARD_TIME);
    SpiDrv::flush();
    SpiDrv::write("exit");
    SpiDrv::write(13);

    // Assert
    char *match = strstr(response, "wifly-GSX");
    assertTrue(match != NULL);
}

void SpiDrvTest::setup() {
    SpiDrv::begin();
}

void SpiDrvTest::once() {
    testBegin();
    testWrite();
}
