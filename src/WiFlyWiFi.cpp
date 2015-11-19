#include <WiFlyWiFi.h>
#include "utility/WiFlyDrv.h"

using namespace Comm;

int16_t WiFlyWiFlyClass::state_[MAX_SOCK_NUM] = { NA_STATE, NA_STATE, NA_STATE, NA_STATE };
uint16_t WiFlyWiFlyClass::server_port_[MAX_SOCK_NUM] = { 0, 0, 0, 0 };

WiFlyWiFlyClass::WiFlyWiFlyClass() {}

void WiFlyWiFlyClass::init() {
    WiFlyDrv::Init();
}

uint8_t WiFlyWiFlyClass::getSocket() {
    for (uint8_t i = 0; i < MAX_SOCK_NUM; ++i) {
        if (WiFlyWiFlyClass::server_port_[i] == 0) {
            return i;
        }
    }
    return NO_SOCKET_AVAIL;
}

char *WiFlyWiFlyClass::firmwareVersion() {
    return WiFlyDrv::FwVersion();
}

int WiFlyWiFlyClass::begin(char *ssid) {
    uint8_t status = WL_IDLE_STATUS;
    uint8_t attempts = WL_MAX_ATTEMPT_CONNECTION;
    if (WiFlyDrv::SetNetwork(ssid, strlen(ssid)) != WL_FAILURE) {
        do {
            delay(WL_DELAY_START_CONNECTION);
            status = WiFlyDrv::ConnectionStatus();
        } while (((status == WL_IDLE_STATUS) || (status == WL_SCAN_COMPLETED)) && (--attempts > 0));
    } else {
        status = WL_CONNECT_FAILED;
    }
    return status;
}

int WiFlyWiFlyClass::begin(char *ssid, uint8_t key_idx, const char *key) {
    uint8_t status = WL_IDLE_STATUS;
    uint8_t attempts = WL_MAX_ATTEMPT_CONNECTION;
    if (WiFlyDrv::SetKey(ssid, strlen(ssid), key_idx, key, strlen(key)) != WL_FAILURE) {
        do {
            delay(WL_DELAY_START_CONNECTION);
            status = WiFlyDrv::ConnectionStatus();
        } while (((status == WL_IDLE_STATUS) || (status == WL_SCAN_COMPLETED)) && (--attempts > 0));
    } else {
        status = WL_CONNECT_FAILED;
    }
    return status;
}

int WiFlyWiFlyClass::begin(char *ssid, const char *passphrase) {
    uint8_t status = WL_IDLE_STATUS;
    uint8_t attempts = WL_MAX_ATTEMPT_CONNECTION;
    if (WiFlyDrv::SetPassphrase(ssid, strlen(ssid), passphrase, strlen(passphrase))!= WL_FAILURE) {
        do {
            delay(WL_DELAY_START_CONNECTION);
            status = WiFlyDrv::ConnectionStatus();
        } while (((status == WL_IDLE_STATUS) || (status == WL_SCAN_COMPLETED)) && (--attempts > 0));
    } else {
        status = WL_CONNECT_FAILED;
    }
    return status;
}

void WiFlyWiFlyClass::config(IPAddress local_ip) {
    WiFlyDrv::Config(1, (uint32_t)local_ip, 0, 0);
}

void WiFlyWiFlyClass::config(IPAddress local_ip, IPAddress dns_server) {
    WiFlyDrv::Config(1, (uint32_t)local_ip, 0, 0);
    WiFlyDrv::SetDNS(1, (uint32_t)dns_server, 0);
}

void WiFlyWiFlyClass::config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway) {
    WiFlyDrv::Config(2, (uint32_t)local_ip, (uint32_t)gateway, 0);
    WiFlyDrv::SetDNS(1, (uint32_t)dns_server, 0);
}

void WiFlyWiFlyClass::config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway, IPAddress subnet) {
    WiFlyDrv::Config(3, (uint32_t)local_ip, (uint32_t)gateway, (uint32_t)subnet);
    WiFlyDrv::SetDNS(1, (uint32_t)dns_server, 0);
}

void WiFlyWiFlyClass::setDNS(IPAddress dns_server1) {
    WiFlyDrv::SetDNS(1, (uint32_t)dns_server1, 0);
}

void WiFlyWiFlyClass::setDNS(IPAddress dns_server1, IPAddress dns_server2){
    WiFlyDrv::SetDNS(2, (uint32_t)dns_server1, (uint32_t)dns_server2);
}

int WiFlyWiFlyClass::disconnect() {
    return WiFlyDrv::Disconnect();
}

uint8_t *WiFlyWiFlyClass::macAddress(uint8_t *mac){
    uint8_t *_mac = WiFlyDrv::MacAddress();
    memcpy(mac, _mac, WL_MAC_ADDR_LENGTH);
    return mac;
}

IPAddress WiFlyWiFlyClass::localIP() {
    IPAddress ret;
    WiFlyDrv::IpAddress(ret);
    return ret;
}

IPAddress WiFlyWiFlyClass::subnetMask() {
    IPAddress ret;
    WiFlyDrv::SubnetMask(ret);
    return ret;
}

IPAddress WiFlyWiFlyClass::gatewayIP() {
    IPAddress ret;
    WiFlyDrv::GatewayIP(ret);
    return ret;
}

char *WiFlyWiFlyClass::SSID() {
    return WiFlyDrv::CurrentSSID();
}

uint8_t *WiFlyWiFlyClass::BSSID(uint8_t *bssid) {
    uint8_t *bssid_ = WiFlyDrv::CurrentBSSID();
    memcpy(bssid, bssid_, WL_MAC_ADDR_LENGTH);
    return bssid;
}

int32_t WiFlyWiFlyClass::RSSI() {
    return WiFlyDrv::CurrentRSSI();
}

uint8_t WiFlyWiFlyClass::encryptionType() {
    return WiFlyDrv::CurrentEncryptionType();
}

int8_t WiFlyWiFlyClass::scanNetworks() {
    uint8_t attempts = 10;
    uint8_t numOfNetworks = 0;
    if (WiFlyDrv::StartScanNetworks() == WL_FAILURE) {
        return WL_FAILURE;
    }
    do {
        delay(2000);
        numOfNetworks = WiFlyDrv::GetScanNetworks();
    }
    while ((numOfNetworks == 0) && (--attempts > 0));
    return numOfNetworks;
}

char *WiFlyWiFlyClass::SSID(uint8_t networkItem) {
    return WiFlyDrv::SSIDNetoworks(networkItem);
}

int32_t WiFlyWiFlyClass::RSSI(uint8_t networkItem) {
    return WiFlyDrv::RSSINetoworks(networkItem);
}

uint8_t WiFlyWiFlyClass::encryptionType(uint8_t networkItem) {
    return WiFlyDrv::EncTypeNetowrks(networkItem);
}

uint8_t WiFlyWiFlyClass::status() {
    return WiFlyDrv::ConnectionStatus();
}

int WiFlyWiFlyClass::hostByName(const chari *aHostname, IPAddress& aResult) {
    return WiFlyDrv::GetHostByName(aHostname, aResult);
}

WiFlyWiFlyClass WiFlyWiFi;
