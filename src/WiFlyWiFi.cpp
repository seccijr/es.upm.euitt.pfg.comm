#include <WiFlyWiFi.h>
#include <Arduino.h>
#include "utility/WiFlyDrv.h"
#include "utility/wfl_spi.h"
#include "utility/wfl_types.h"

using namespace Comm;

int16_t WiFlyWiFiClass::state_[MAX_SOCK_NUM] = { NA_STATE, NA_STATE, NA_STATE, NA_STATE };
uint16_t WiFlyWiFiClass::server_port_[MAX_SOCK_NUM] = { 0, 0, 0, 0 };

WiFlyWiFiClass::WiFlyWiFiClass() {}

void WiFlyWiFiClass::init() {
    WiFlyDrv::Init();
}

uint8_t WiFlyWiFiClass::getSocket() {
    for (uint8_t i = 0; i < MAX_SOCK_NUM; ++i) {
        if (WiFlyWiFiClass::server_port_[i] == 0) {
            return i;
        }
    }
    return NO_SOCKET_AVAIL;
}

char *WiFlyWiFiClass::firmwareVersion() {
    return WiFlyDrv::FwVersion();
}

int WiFlyWiFiClass::begin(char *ssid) {
    uint8_t status = WFL_IDLE_STATUS;
    uint8_t attempts = WFL_MAX_ATTEMPT_CONNECTION;
    if (WiFlyDrv::SetNetwork(ssid, strlen(ssid)) != WFL_FAILURE) {
        do {
            delay(WFL_DELAY_START_CONNECTION);
            status = WiFlyDrv::ConnectionStatus();
        } while (((status == WFL_IDLE_STATUS) || (status == WFL_SCAN_COMPLETED)) && (--attempts > 0));
    } else {
        status = WFL_CONNECT_FAILED;
    }
    return status;
}

int WiFlyWiFiClass::begin(char *ssid, uint8_t key_idx, const char *key) {
    uint8_t status = WFL_IDLE_STATUS;
    uint8_t attempts = WFL_MAX_ATTEMPT_CONNECTION;
    if (WiFlyDrv::SetKey(ssid, strlen(ssid), key_idx, key, strlen(key)) != WFL_FAILURE) {
        do {
            delay(WFL_DELAY_START_CONNECTION);
            status = WiFlyDrv::ConnectionStatus();
        } while (((status == WFL_IDLE_STATUS) || (status == WFL_SCAN_COMPLETED)) && (--attempts > 0));
    } else {
        status = WFL_CONNECT_FAILED;
    }
    return status;
}

int WiFlyWiFiClass::begin(char *ssid, const char *passphrase) {
    uint8_t status = WFL_IDLE_STATUS;
    uint8_t attempts = WFL_MAX_ATTEMPT_CONNECTION;
    if (WiFlyDrv::SetPassphrase(ssid, strlen(ssid), passphrase, strlen(passphrase))!= WFL_FAILURE) {
        do {
            delay(WFL_DELAY_START_CONNECTION);
            status = WiFlyDrv::ConnectionStatus();
        } while (((status == WFL_IDLE_STATUS) || (status == WFL_SCAN_COMPLETED)) && (--attempts > 0));
    } else {
        status = WFL_CONNECT_FAILED;
    }
    return status;
}

void WiFlyWiFiClass::config(IPAddress local_ip) {
    WiFlyDrv::Config(1, (uint32_t)local_ip, 0, 0);
}

void WiFlyWiFiClass::config(IPAddress local_ip, IPAddress dns_server) {
    WiFlyDrv::Config(1, (uint32_t)local_ip, 0, 0);
    WiFlyDrv::SetDNS(1, (uint32_t)dns_server, 0);
}

void WiFlyWiFiClass::config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway) {
    WiFlyDrv::Config(2, (uint32_t)local_ip, (uint32_t)gateway, 0);
    WiFlyDrv::SetDNS(1, (uint32_t)dns_server, 0);
}

void WiFlyWiFiClass::config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway, IPAddress subnet) {
    WiFlyDrv::Config(3, (uint32_t)local_ip, (uint32_t)gateway, (uint32_t)subnet);
    WiFlyDrv::SetDNS(1, (uint32_t)dns_server, 0);
}

void WiFlyWiFiClass::setDNS(IPAddress dns_server1) {
    WiFlyDrv::SetDNS(1, (uint32_t)dns_server1, 0);
}

void WiFlyWiFiClass::setDNS(IPAddress dns_server1, IPAddress dns_server2){
    WiFlyDrv::SetDNS(2, (uint32_t)dns_server1, (uint32_t)dns_server2);
}

int WiFlyWiFiClass::disconnect() {
    return WiFlyDrv::Disconnect();
}

uint8_t *WiFlyWiFiClass::macAddress(uint8_t *mac){
    uint8_t *_mac = WiFlyDrv::MacAddress();
    memcpy(mac, _mac, WFL_MAC_ADDR_LENGTH);
    return mac;
}

IPAddress WiFlyWiFiClass::localIP() {
    IPAddress ret;
    WiFlyDrv::IpAddress(ret);
    return ret;
}

IPAddress WiFlyWiFiClass::subnetMask() {
    IPAddress ret;
    WiFlyDrv::SubnetMask(ret);
    return ret;
}

IPAddress WiFlyWiFiClass::gatewayIP() {
    IPAddress ret;
    WiFlyDrv::GatewayIP(ret);
    return ret;
}

char *WiFlyWiFiClass::SSID() {
    return WiFlyDrv::CurrentSSID();
}

uint8_t *WiFlyWiFiClass::BSSID(uint8_t *bssid) {
    uint8_t *bssid_ = WiFlyDrv::CurrentBSSID();
    memcpy(bssid, bssid_, WFL_MAC_ADDR_LENGTH);
    return bssid;
}

int32_t WiFlyWiFiClass::RSSI() {
    return WiFlyDrv::CurrentRSSI();
}

uint8_t WiFlyWiFiClass::encryptionType() {
    return WiFlyDrv::CurrentEncryptionType();
}

int8_t WiFlyWiFiClass::scanNetworks() {
    uint8_t attempts = 10;
    uint8_t numOfNetworks = 0;
    if (WiFlyDrv::StartScanNetworks() == WFL_FAILURE) {
        return WFL_FAILURE;
    }
    do {
        delay(2000);
        numOfNetworks = WiFlyDrv::GetScanNetworks();
    }
    while ((numOfNetworks == 0) && (--attempts > 0));
    return numOfNetworks;
}

char *WiFlyWiFiClass::SSID(uint8_t networkItem) {
    return WiFlyDrv::SSIDNetoworks(networkItem);
}

int32_t WiFlyWiFiClass::RSSI(uint8_t networkItem) {
    return WiFlyDrv::RSSINetoworks(networkItem);
}

uint8_t WiFlyWiFiClass::encryptionType(uint8_t networkItem) {
    return WiFlyDrv::EncTypeNetowrks(networkItem);
}

uint8_t WiFlyWiFiClass::status() {
    return WiFlyDrv::ConnectionStatus();
}

int WiFlyWiFiClass::hostByName(const char *aHostname, IPAddress& aResult) {
    return WiFlyDrv::GetHostByName(aHostname, aResult);
}

WiFlyWiFiClass WiFlyWiFi;
