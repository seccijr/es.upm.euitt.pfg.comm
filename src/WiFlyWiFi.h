#ifndef _WIFLYWIFI_H
#define _WIFLYWIFI_H

#include <AbstractWiFly.h>
#include "utility/AbstractWiFlyDrv.h"

namespace Comm {
    class WiFlyWiFiClass: public AbstractWiFly {
        public:
            WiFlyWiFiClass(AbstractWiFlyDrv *wiflydrv);
            uint8_t getSocket();
            char *firmwareVersion();
            int begin(char *ssid);
            int begin(char *ssid, uint8_t key_idx, const char *key);
            int begin(char *ssid, const char *passphrase);
            void config(IPAddress local_ip);
            void config(IPAddress local_ip, IPAddress dns_server);
            void config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway);
            void config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway, IPAddress subnet);
            void setDNS(IPAddress dns_server1);
            void setDNS(IPAddress dns_server1, IPAddress dns_server2);
            int disconnect(void);
            uint8_t *macAddress(uint8_t *mac);
            IPAddress localIP();
            IPAddress subnetMask();
            IPAddress gatewayIP();
            char *SSID();
            uint8_t *BSSID(uint8_t *bssid);
            int32_t RSSI();
            uint8_t encryptionType();
            int8_t scanNetworks();
            char *SSID(uint8_t networkItem);
            uint8_t encryptionType(uint8_t networkItem);
            int32_t RSSI(uint8_t networkItem);
            uint8_t status();
            int hostByName(const char *aHostname, IPAddress& aResult);
        private:
            void init();
            AbstractWiFlyDrv *wiflydrv_;
    };
}

#endif
