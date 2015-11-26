#ifndef _WIFLYWIFI_H
#define _WIFLYWIFI_H

#include <WiFlyWiFi.h>
#include "utility/WiFlyDrv.h"

namespace Comm {
    class WiFlyWiFiClass {
        public:
            WiFlyWiFiClass();
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
            uint8_t status();
            int hostByName(const char *aHostname, IPAddress &aResult);
        private:
            void init();
    };
}

#endif
