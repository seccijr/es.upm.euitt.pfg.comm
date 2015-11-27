#include <Arduino.h>
#include <ArduinoUnit.h>
#include <Comm.h>
#include "SpiDrvTest.h"
#include "WiFlyDrvTest.h"
#include "ServerDrvTest.h"
#include "WiFlyWiFiTest.h"
#include "WiFlyUdpTest.h"

//SpiDrvTest spidrv_test("SpiDrv");
//WiFlyDrvTest wiflydrv_test("WiFlyDrv");
//ServerDrvTest serverdrv_test("ServerDrv");
//WiFlyWiFiTest wiflywifi_test("WiFlyWiFiClass");
WiFlyUDPTest wiflyudp_test("WiFlyUDPClass");

void setup() {
    Serial.begin(9600);
}

void loop() {
    Test::run();
}
