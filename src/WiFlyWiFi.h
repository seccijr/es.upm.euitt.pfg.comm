#ifndef _WIFLYWIFI_H
#define _WIFLYWIFI_H

#include <AbstractWiFly.h>
#include "utility/AbstractWiFlyDrv.h"

namespace Comm {
    class WiFlyWiFiClass: public AbstractWiFly {
        public:
            WiFlyWiFiClass(AbstractWiFlyDrv *wiflydrv);
            char *FirmwareVersion();
            int Begin(char *ssid);
            int Begin(char *ssid, uint8_t key_idx, const char *key);
            int Begin(char *ssid, const char *passphrase);
            void Config(IPAddress local_ip);
            void Config(IPAddress local_ip, IPAddress dns_server);
            void Config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway);
            void Config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway, IPAddress subnet);
            void SetDNS(IPAddress dns_server1);
            void SetDNS(IPAddress dns_server1, IPAddress dns_server2);
            int Disconnect(void);
            uint8_t *MacAddress(uint8_t *mac);
            IPAddress LocalIP();
            IPAddress SubnetMask();
            IPAddress GatewayIP();
            char *SSID();
            uint8_t *BSSID(uint8_t *bssid);
            int32_t RSSI();
            uint8_t EncryptionType();
            int8_t ScanNetworks();
            char *SSID(uint8_t networkItem);
            uint8_t EncryptionType(uint8_t networkItem);
            int32_t RSSI(uint8_t networkItem);
            uint8_t Status();
            int HostByName(const char *aHostname, IPAddress &aResult);
        private:
            void Init();
            AbstractWiFlyDrv *wiflydrv_;
    };
}

#endif
