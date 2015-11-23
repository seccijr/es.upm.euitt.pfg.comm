#ifndef _ABSTRACTWIFLYDRV_H
#define _ABSTRACTWIFLYDRV_H

#include <stdint.h>
#include <IPAddress.h>
#include <Arduino.h>

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
            virtual int GetHostByName(const char *aHostname, IPAddress &aResult) =0;

            // Added members
            virtual int8_t GetResponse(char *response, int len, const char *end) =0;
            virtual int8_t SendCommand(const char *cmd, char *response, int len, const char *end) =0;
            virtual int8_t SendCommandAndParam(const char *cmd, const char *param, char *response, int len, const char *end) =0;
            virtual int8_t FactoryReset() =0;
            virtual int8_t Reboot() =0;
    };
}

#endif
