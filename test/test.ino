#include <Arduino.h>
#include <ArduinoUnit.h>
#include <Comm.h>
#include "SpiUartWrapperTest.h"
#include "WiFlyDrvTest.h"
#include "ServerDrvTest.h"
#include "WiFlyWiFiTest.h"
#include "WiFlyUdpTest.h"

//CommIntegration::SpiUartWrapperTest spiwrapper_test("Comm::SpiUartWrapper");
//CommIntegration::WiFlyDrvTest wiflydrv_test("Comm::WiFlyDrv");
//CommIntegration::ServerDrvTest serverdrv_test("Comm::ServerDrv");
//CommIntegration::WiFlyWiFiTest wiflywifi_test("Comm::WiFlyWiFiClass");
//CommIntegration::WiFlyUDPTest wiflyudp_test("Comm::WiFlyUDPClass");


#include "utility/SpiUartWrapper.h"

using namespace Comm;

void setup() {
    Serial.begin(9600);
}

void loop() {
    Test::run();
}
