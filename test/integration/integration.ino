#include <Arduino.h>
#include <ArduinoUnit.h>
#include <Comm.h>
#include "SpiUartWrapperTest.h"
#include "WiFlyDrvTest.h"
#include "ServerDrvTest.h"

CommIntegration::SpiUartWrapperTest spiwrapper_test("Comm::SpiUartWrapper");
CommIntegration::WiFlyDrvTest wiflydrv_test("Comm::WiFlyDrv");
CommIntegration::ServerDrvTest serverdrv_test("Comm::ServerDrv");


#include "utility/SpiUartWrapper.h"

using namespace Comm;

void setup() {
    Serial.begin(9600);
}

void loop() {
    Test::run();
}
