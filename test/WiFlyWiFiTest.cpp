#include "WiFlyWiFiTest.h"
#include "credentials.h"
#include "utility/wfl_definitions.h"
#include "utility/WiFlyDrv.h"
#include "utility/SpiDrv.h"
#include <WiFlyWiFi.h>

void WiFlyWiFiTest::testBeginOpen() {
    // Arrange
    // Act
    int result = WiFlyWiFi.begin((char *)OPEN_SSID);

    // Assert
    assertTrue(result == WFL_CONNECTED);
}

void WiFlyWiFiTest::testBeginWPA2() {
    // Arrange
    // Act
    int result = WiFlyWiFi.begin((char *)SECURED_SSID, (char *)SECURED_PASS);

    // Assert
    assertTrue(result == WFL_CONNECTED);
}

void WiFlyWiFiTest::setup() {
}

void WiFlyWiFiTest::once() {
    testBeginOpen();
    testBeginWPA2();
}
