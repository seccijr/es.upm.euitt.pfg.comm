#include <Arduino.h>
#include <ArduinoUnit.h>
#include <Comm.h>
#include "SpiDrvTest.h"
#include "WiFlyDrvTest.h"
#include "ServerDrvTest.h"
#include "WiFlyWiFiTest.h"
#include "WiFlyUdpTest.h"

//CommIntegration::SpiDrvTest spidrv_test("Comm::SpiDrv");
//CommIntegration::WiFlyDrvTest wiflydrv_test("Comm::WiFlyDrv");
//CommIntegration::ServerDrvTest serverdrv_test("Comm::ServerDrv");
//CommIntegration::WiFlyWiFiTest wiflywifi_test("Comm::WiFlyWiFiClass");
//CommIntegration::WiFlyUDPTest wiflyudp_test("Comm::WiFlyUDPClass");

void setup() {
    Serial.begin(9600);
}

void loop() {
    Serial.println("Testing");
    delay(1000);
    Test::run();
}
