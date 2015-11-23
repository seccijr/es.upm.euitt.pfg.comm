#ifndef _ABSTRACTWIFLY_H
#define _ABSTRACTWIFLY_H

#include <IPAddress.h>
#include <stdint.h>
#include "utility/wfl_definitions.h"

namespace Comm {
    class AbstractWiFly {
        public:
            virtual char *FirmwareVersion() =0;
            virtual int Begin(char *ssid) =0;
            virtual int Begin(char *ssid, uint8_t key_idx, const char *key) =0;
            virtual int Begin(char *ssid, const char *passphrase) =0;
            virtual void Config(IPAddress local_ip) =0;
            virtual void Config(IPAddress local_ip, IPAddress dns_server) =0;
            virtual void Config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway) =0;
            virtual void Config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway, IPAddress subnet) =0;
            virtual void SetDNS(IPAddress dns_server1) =0;
            virtual void SetDNS(IPAddress dns_server1, IPAddress dns_server2) =0;
            virtual int Disconnect(void) =0;
            virtual uint8_t *MacAddress(uint8_t *mac) =0;
            virtual IPAddress LocalIP() =0;
            virtual IPAddress SubnetMask() =0;
            virtual IPAddress GatewayIP() =0;
            virtual char *SSID() =0;
            virtual uint8_t *BSSID(uint8_t *bssid) =0;
            virtual int32_t RSSI() =0;
            virtual uint8_t EncryptionType() =0;
            virtual int8_t ScanNetworks() =0;
            virtual char *SSID(uint8_t networkItem) =0;
            virtual uint8_t EncryptionType(uint8_t networkItem) =0;
            virtual int32_t RSSI(uint8_t networkItem) =0;
            virtual uint8_t Status() =0;
            virtual int HostByName(const char *aHostname, IPAddress& aResult) =0;
    };
}

#endif
