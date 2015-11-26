#include "ServerDrvTest.h"
#include "utility/ServerDrv.h"
#include "utility/WiFlyDrv.h"
#include "utility/SpiDrv.h"
#include "utility/wfl_definitions.h"
#include "WiFlyWiFi.h"
#include <IPAddress.h>

using namespace Comm;
using namespace CommIntegration;

void ServerDrvTest::testStartClientUdp() {
    // Arrange
    uint16_t remote_port = 4444;
    uint8_t remote_ip_raw[4] = {192, 168, 1, 107};
    IPAddress remote_ip(remote_ip_raw);
    char response[MAX_CMD_RESPONSE_LEN + 1] = {0};

    // Act
    ServerDrv::startClient((uint32_t)remote_ip, remote_port, UDP_MODE);
    int8_t result = WiFlyDrv::sendCommand(CMD_GET_IP, response, MAX_CMD_RESPONSE_LEN, WFL_END_COMMAND_STR);

    // Assert
    assertTrue(result == WFL_SUCCESS);
    char *match = strstr(response, "HOST=192.168.1.107:4444");
    assertTrue(match != NULL);
    match = strstr(response, "PROTO=UDP");
    assertTrue(match != NULL);
}

void ServerDrvTest::testStartServerUdp() {
    // Arrange
    uint16_t local_port = 4444;
    char response[MAX_CMD_RESPONSE_LEN + 1] = {0};

    // Act
    ServerDrv::startServer(local_port, UDP_MODE);
    int8_t result = WiFlyDrv::sendCommand(CMD_GET_IP, response, MAX_CMD_RESPONSE_LEN, WFL_END_COMMAND_STR);

    // Assert
    assertTrue(result == WFL_SUCCESS);
    char *match = strstr(response, "IP=0.0.0.0:4444");
    assertTrue(match != NULL);
    match = strstr(response, "PROTO=UDP");
    assertTrue(match != NULL);
}

void ServerDrvTest::setup() {
    WiFlyDrv::init();
}

void ServerDrvTest::once() {
    testStartClientUdp();
    testStartServerUdp();
}
