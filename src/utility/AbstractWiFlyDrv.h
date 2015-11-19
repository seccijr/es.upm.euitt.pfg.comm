#ifndef _ABSTRACTWIFLYDRV_H
#define _ABSTRACTWIFLYDRV_H

#include <stdint.h>
#include <IPAddress.h>

namespace Comm {
    class AbstractWiFlyDrv {
        public:
            virtual void Init() =0;
            virtual int8_t SetNetwork(char *ssid, uint8_t ssid_len) =0;
            virtual int8_t SetPassphrase(char *ssid, uint8_t ssid_len, const char *passphrase, const uint8_t len) =0;
            virtual int8_t SetKey(char *ssid, uint8_t ssid_len, uint8_t key_idx, const void *key, const uint8_t len) =0;
            virtual void Config(uint8_t validParams, uint32_t local_ip, uint32_t gateway, uint32_t subnet) =0;
            virtual void SetDNS(uint8_t validParams, uint32_t dns_server1, uint32_t dns_server2) =0;
            virtual int8_t Disconnect() =0;
            virtual uint8_t ConnectionStatus() =0;
            virtual uint8_t *MacAddress() =0;
            virtual void IpAddress(IPAddress &ip) =0;
            virtual void SubnetMask(IPAddress &mask) =0;
            virtual void GatewayIP(IPAddress &ip) =0;
            virtual char *CurrentSSID() =0;
            virtual uint8_t *CurrentBSSID() =0;
            virtual int32_t CurrentRSSI() =0;
            virtual uint8_t CurrentEncryptionType() =0;
            virtual int8_t StartScanNetworks() =0;
            virtual uint8_t GetScanNetworks() =0;
            virtual char *SSIDNetoworks(uint8_t networkItem) =0;
            virtual int32_t RSSINetoworks(uint8_t networkItem) =0;
            virtual uint8_t EncTypeNetowrks(uint8_t networkItem) =0;
            virtual int GetHostByName(const char *aHostname, IPAddress &aResult) =0;
            virtual char *FwVersion() =0;
            virtual void GetRemoteData(uint8_t sock, uint8_t *ip, uint8_t *port) =0;
    };
}

#endif
