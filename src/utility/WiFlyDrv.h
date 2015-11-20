#ifndef _WIFLYDRV_H
#define _WIFLYDRV_H

#include <stdint.h>
#include <IPAddress.h>
#include "utility/AbstractUartWrapper.h"
#include "utility/AbstractWiFlyDrv.h"
#include "utility/wfl_spi.h"

#define KEY_IDX_LEN     1
#define WFL_DELAY_START_CONNECTION 5000
#define WFL_FW_VER_LENGTH 6

namespace Comm {
    class WiFlyDrv: public AbstractWiFlyDrv {
        public:
            // Own members
            WiFlyDrv(AbstractUartWrapper *uart);
            bool SendCommand(const char *cmd);
            bool FactoryReset();
            bool Reboot();

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
            void SubnetMask(IPAddress &mask);
            void GatewayIP(IPAddress &ip);
            char *CurrentSSID();
            uint8_t *CurrentBSSID();
            int32_t CurrentRSSI();
            uint8_t CurrentEncryptionType();
            int8_t StartScanNetworks();
            uint8_t GetScanNetworks();
            char *SSIDNetoworks(uint8_t networkItem);
            int32_t RSSINetoworks(uint8_t networkItem);
            uint8_t EncTypeNetowrks(uint8_t networkItem);
            int GetHostByName(const char *aHostname, IPAddress &aResult);
            char *FwVersion();
            void GetRemoteData(uint8_t sock, uint8_t *ip, uint8_t *port);

        private:
            AbstractUartWrapper *uart_;
    };
}

#endif
