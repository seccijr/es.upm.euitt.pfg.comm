#ifndef _WIFLYDRV_H
#define _WIFLYDRV_H

#include <stdint.h>
#include <IPAddress.h>
#include "utility/AbstractUartWrapper.h"
#include "utility/AbstractWiFlyDrv.h"
#include "utility/wfl_spi.h"
#include "utility/wfl_types.h"

namespace Comm {
    class WiFlyDrv: public AbstractWiFlyDrv {
        public:
            // Own members
            WiFlyDrv(AbstractUartWrapper *uart);

            // Abstract implementation
            void Init();
            int8_t SetNetwork(char *ssid, uint8_t ssid_len);
            int8_t SetPassphrase(char *ssid, uint8_t ssid_len, const char *passphrase, const uint8_t len);
            int8_t SetKey(char *ssid, uint8_t ssid_len, uint8_t key_idx, const void *key, const uint8_t len);
            void Config(uint8_t validParams, uint32_t local_ip, uint32_t gateway, uint32_t subnet);
            void SetDNS(uint8_t validParams, uint32_t dns_server1, uint32_t dns_server2);
            int8_t Disconnect();
            uint8_t ConnectionStatus();
            uint8_t *MacAddress();
            void IpAddress(IPAddress &ip);
            int GetHostByName(const char *aHostname, IPAddress &aResult);

            // Abstract added members
            int8_t GetResponse(char *response, int len, const char *end);
            int8_t SendCommand(const char *cmd, char *response, int len, const char *end);
            int8_t SendCommandAndParam(const char *cmd, const char *param, char *response, int len, const char *end);
            int8_t FactoryReset();
            int8_t Reboot();
            bool CheckStatusOk(const char *response, const char *status_indicator, const char *success_indicator);

        private:
            AbstractUartWrapper *uart_;
    };
}

#endif
