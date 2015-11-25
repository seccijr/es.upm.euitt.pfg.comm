#ifndef _WIFLYWIFI_H
#define _WIFLYWIFI_H

#include <WiFlyWiFi.h>
#include "utility/WiFlyDrv.h"

namespace Comm {
    class WiFlyWiFiClass {
        public:
            WiFlyWiFiClass(WiFlyDrv *wiflydrv);
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
            uint8_t Status();
            int HostByName(const char *aHostname, IPAddress &aResult);
        private:
            void Init();
            WiFlyDrv *wiflydrv_;
    };
}

#endif
