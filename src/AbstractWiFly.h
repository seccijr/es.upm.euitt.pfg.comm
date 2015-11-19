#ifndef _ABSTRACTWIFLY_H
#define _ABSTRACTWIFLY_H

#include <IPAddress.h>
#include <stdint.h>
#include "utility/wfl_definitions.h"

namespace Comm {
    class AbstractWiFly {
        public:
            virtual uint8_t getSocket() =0;
            virtual char *firmwareVersion() =0;
            virtual int begin(char *ssid) =0;
            virtual int begin(char *ssid, uint8_t key_idx, const char *key) =0;
            virtual int begin(char *ssid, const char *passphrase) =0;
            virtual void config(IPAddress local_ip) =0;
            virtual void config(IPAddress local_ip, IPAddress dns_server) =0;
            virtual void config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway) =0;
            virtual void config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway, IPAddress subnet) =0;
            virtual void setDNS(IPAddress dns_server1) =0;
            virtual void setDNS(IPAddress dns_server1, IPAddress dns_server2) =0;
            virtual int disconnect(void) =0;
            virtual uint8_t *macAddress(uint8_t *mac) =0;
            virtual IPAddress localIP() =0;
            virtual IPAddress subnetMask() =0;
            virtual IPAddress gatewayIP() =0;
            virtual char *SSID() =0;
            virtual uint8_t *BSSID(uint8_t *bssid) =0;
            virtual int32_t RSSI() =0;
            virtual uint8_t encryptionType() =0;
            virtual int8_t scanNetworks() =0;
            virtual char *SSID(uint8_t networkItem) =0;
            virtual uint8_t encryptionType(uint8_t networkItem) =0;
            virtual int32_t RSSI(uint8_t networkItem) =0;
            virtual uint8_t status() =0;
            virtual int hostByName(const char *aHostname, IPAddress& aResult) =0;
            int16_t state[MAX_SOCK_NUM];
            uint16_t server_port[MAX_SOCK_NUM];
    };
}

#endif
