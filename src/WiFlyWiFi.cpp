#include <WiFlyWiFi.h>
#include <Arduino.h>
#include "utility/WiFlyDrv.h"
#include "utility/wfl_definitions.h"
#include "utility/wfl_spi.h"
#include "utility/wfl_types.h"

namespace Comm {
    WiFlyWiFiClass::WiFlyWiFiClass() {
        init();
    }

    void WiFlyWiFiClass::init() {
        WiFlyDrv::init();
    }

    int WiFlyWiFiClass::begin(char *ssid) {
        uint8_t status = WFL_IDLE_STATUS;
        uint8_t attempts = WFL_MAX_ATTEMPT_CONNECTION;
        if (WiFlyDrv::setNetwork(ssid, strlen(ssid)) != WFL_FAILURE) {
            do {
                delay(WFL_DELAY_START_CONNECTION);
                status = WiFlyDrv::connectionStatus();
            } while (((status == WFL_IDLE_STATUS) || (status == WFL_SCAN_COMPLETED)) && (--attempts > 0));
        } else {
            status = WFL_CONNECT_FAILED;
        }
        return status;
    }

    int WiFlyWiFiClass::begin(char *ssid, uint8_t key_idx, const char *key) {
        uint8_t status = WFL_IDLE_STATUS;
        uint8_t attempts = WFL_MAX_ATTEMPT_CONNECTION;
        if (WiFlyDrv::setKey(ssid, strlen(ssid), key_idx, key, strlen(key)) != WFL_FAILURE) {
            do {
                delay(WFL_DELAY_START_CONNECTION);
                status = WiFlyDrv::connectionStatus();
            } while (((status == WFL_IDLE_STATUS) || (status == WFL_SCAN_COMPLETED)) && (--attempts > 0));
        } else {
            status = WFL_CONNECT_FAILED;
        }
        return status;
    }

    int WiFlyWiFiClass::begin(char *ssid, const char *passphrase) {
        uint8_t status = WFL_IDLE_STATUS;
        uint8_t attempts = WFL_MAX_ATTEMPT_CONNECTION;
        if (WiFlyDrv::setPassphrase(ssid, strlen(ssid), passphrase, strlen(passphrase))!= WFL_FAILURE) {
            do {
                delay(WFL_DELAY_START_CONNECTION);
                status = WiFlyDrv::connectionStatus();
            } while (((status == WFL_IDLE_STATUS) || (status == WFL_SCAN_COMPLETED)) && (--attempts > 0));
        } else {
            status = WFL_CONNECT_FAILED;
        }
        return status;
    }

    void WiFlyWiFiClass::config(IPAddress local_ip) {
        WiFlyDrv::config(1, (uint32_t)local_ip, 0, 0);
    }

    void WiFlyWiFiClass::config(IPAddress local_ip, IPAddress dns_server) {
        WiFlyDrv::config(1, (uint32_t)local_ip, 0, 0);
        WiFlyDrv::setDNS(1, (uint32_t)dns_server, 0);
    }

    void WiFlyWiFiClass::config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway) {
        WiFlyDrv::config(2, (uint32_t)local_ip, (uint32_t)gateway, 0);
        WiFlyDrv::setDNS(1, (uint32_t)dns_server, 0);
    }

    void WiFlyWiFiClass::config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway, IPAddress subnet) {
        WiFlyDrv::config(3, (uint32_t)local_ip, (uint32_t)gateway, (uint32_t)subnet);
        WiFlyDrv::setDNS(1, (uint32_t)dns_server, 0);
    }

    void WiFlyWiFiClass::setDNS(IPAddress dns_server1) {
        WiFlyDrv::setDNS(1, (uint32_t)dns_server1, 0);
    }

    void WiFlyWiFiClass::setDNS(IPAddress dns_server1, IPAddress dns_server2){
        WiFlyDrv::setDNS(2, (uint32_t)dns_server1, (uint32_t)dns_server2);
    }

    int WiFlyWiFiClass::disconnect() {
        return WiFlyDrv::disconnect();
    }

    uint8_t *WiFlyWiFiClass::macAddress(uint8_t *mac){
        uint8_t *_mac = WiFlyDrv::macAddress();
        memcpy(mac, _mac, WFL_MAC_ADDR_LENGTH);
        return mac;
    }

    IPAddress WiFlyWiFiClass::localIP() {
        IPAddress ret;
        WiFlyDrv::ipAddress(ret);
        return ret;
    }

    uint8_t WiFlyWiFiClass::status() {
        return WiFlyDrv::connectionStatus();
    }

    int WiFlyWiFiClass::hostByName(const char *aHostname, IPAddress &aResult) {
        return WiFlyDrv::getHostByName(aHostname, aResult);
    }
}
