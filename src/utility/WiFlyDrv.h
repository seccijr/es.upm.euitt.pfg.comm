#ifndef _WIFLYDRV_H
#define _WIFLYDRV_H

#include <stdint.h>
#include <IPAddress.h>

#define KEY_IDX_LEN     1
#define WFL_DELAY_START_CONNECTION 5000
#define WFL_FW_VER_LENGTH 6

namespace Comm {
    class WiFlyDrv {
        public:
            static void Init();
            static int8_t SetNetwork(char *ssid, uint8_t ssid_len);
            static int8_t SetPassphrase(char *ssid, uint8_t ssid_len, const char *passphrase, const uint8_t len);
            static int8_t SetKey(char *ssid, uint8_t ssid_len, uint8_t key_idx, const void *key, const uint8_t len);
            static void Config(uint8_t validParams, uint32_t local_ip, uint32_t gateway, uint32_t subnet);
            static void SetDNS(uint8_t validParams, uint32_t dns_server1, uint32_t dns_server2);
            static int8_t Disconnect();
            static uint8_t ConnectionStatus();
            static uint8_t *MacAddress();
            static void IpAddress(IPAddress &ip);
            static void SubnetMask(IPAddress &mask);
            static void GatewayIP(IPAddress &ip);
            static char *CurrentSSID();
            static uint8_t *CurrentBSSID();
            static int32_t CurrentRSSI();
            static uint8_t CurrentEncryptionType();
            static int8_t StartScanNetworks();
            static uint8_t GetScanNetworks();
            static char *SSIDNetoworks(uint8_t networkItem);
            static int32_t RSSINetoworks(uint8_t networkItem);
            static uint8_t EncTypeNetowrks(uint8_t networkItem);
            static int GetHostByName(const char *aHostname, IPAddress &aResult);
            static char *FwVersion();
            static void GetRemoteData(uint8_t sock, uint8_t *ip, uint8_t *port);
            friend class WiFlyUDP;
    };
}

#endif
