#ifndef _WIFLYDRV_H
#define _WIFLYDRV_H

#include <stdint.h>
#include <IPAddress.h>
#include "utility/SpiDrv.h"
#include "utility/wfl_spi.h"
#include "utility/wfl_types.h"

namespace Comm {
    class WiFlyDrv {
        public:
            static void init();
            static int8_t setNetwork(char *ssid, uint8_t ssid_len);
            static int8_t setPassphrase(char *ssid, uint8_t ssid_len, const char *passphrase, const uint8_t len);
            static int8_t setKey(char *ssid, uint8_t ssid_len, uint8_t key_idx, const void *key, const uint8_t len);
            static void config(uint8_t validParams, uint32_t local_ip, uint32_t gateway, uint32_t subnet);
            static void setDNS(uint8_t validParams, uint32_t dns_server1, uint32_t dns_server2);
            static int8_t disconnect();
            static uint8_t connectionStatus();
            static uint8_t *macAddress();
            static void ipAddress(IPAddress &ip);
            static int getHostByName(const char *aHostname, IPAddress &aResult);
            static int8_t getResponse(char *response, int len, const char *end);
            static int8_t sendCommand(const char *cmd, char *response, int len, const char *end);
            static int8_t sendCommandAndParam(const char *cmd, const char *param, char *response, int len, const char *end);
            static int8_t factoryReset();
            static int8_t reboot();
            static bool checkStatusOk(const char *response, const char *status_indicator, const char *success_indicator);
    };
}

#endif
