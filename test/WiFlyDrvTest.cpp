#include "WiFlyDrvTest.h"
#include "credentials.h"
#include "utility/wfl_definitions.h"
#include "utility/WiFlyDrv.h"
#include "utility/SpiDrv.h"

using namespace Comm;
using namespace CommIntegration;

void WiFlyDrvTest::testInit() {
    // Arrange
    // Act
    // Assert
    assertTrue(SpiDrv::uartConnected());
}

void WiFlyDrvTest::testSendCommand() {
    // Arrange
    char response[MAX_CMD_RESPONSE_LEN + 1] = {0};

    // Act
    int8_t result = WiFlyDrv::sendCommand(CMD_VERSION, response, MAX_CMD_RESPONSE_LEN, WFL_END_COMMAND_STR);

    // Assert
    assertTrue(result == WFL_SUCCESS);
    char *match = strstr(response, "wifly-GSX");
    assertTrue(match != NULL);
}

void WiFlyDrvTest::testEndCommand() {
    // Arrange
    char response[MAX_CMD_RESPONSE_LEN + 1] = {0};

    // Act
    int8_t result = WiFlyDrv::sendCommand(CMD_VERSION, response, MAX_CMD_RESPONSE_LEN, WFL_END_COMMAND_STR);

    // Assert
    assertTrue(result == WFL_SUCCESS);
    char *match = strstr(response, WFL_END_COMMAND_STR);
    assertTrue(match != NULL);
}

void WiFlyDrvTest::testSetNetwork() {
    // Arrange
    // Act
    int8_t set_result = WiFlyDrv::setNetwork((char *)OPEN_SSID, strlen(OPEN_SSID));

    // Assert
    assertTrue(set_result == WFL_SUCCESS);
}

void WiFlyDrvTest::testSetPassphrase() {
    // Arrange
    // Act
    int8_t set_result = WiFlyDrv::setPassphrase((char *)SECURED_SSID, strlen(SECURED_SSID), (char *)SECURED_PASS, strlen(SECURED_PASS));

    // Assert
    assertTrue(set_result == WFL_SUCCESS);
}

void WiFlyDrvTest::setup() {
    WiFlyDrv::init();
}

void WiFlyDrvTest::once() {
    testInit();
    testSendCommand();
    testEndCommand();
    testSetNetwork();
    testSetPassphrase();
}
