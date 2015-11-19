#include <WiFlyWiFi.h>
#include <Arduino.h>
#include "utility/WiFlyDrv.h"
#include "utility/wfl_spi.h"
#include "utility/wfl_types.h"

using namespace Comm;

WiFlyWiFiClass::WiFlyWiFiClass(AbstractWiFlyDrv *wiflydrv): wiflydrv_(wiflydrv) {
    int16_t state_[4] = {NA_STATE, NA_STATE, NA_STATE, NA_STATE};
    memcpy(state, state_, 4 * sizeof(int16_t));
    uint16_t server_port_[4] = {0, 0, 0, 0};
    memcpy(server_port, server_port_, 4 * sizeof(uint16_t));
}

void WiFlyWiFiClass::init() {
    wiflydrv_->Init();
}

uint8_t WiFlyWiFiClass::getSocket() {
    for (uint8_t i = 0; i < MAX_SOCK_NUM; ++i) {
        if (server_port[i] == 0) {
            return i;
        }
    }
    return NO_SOCKET_AVAIL;
}

char *WiFlyWiFiClass::firmwareVersion() {
    return wiflydrv_->FwVersion();
}

int WiFlyWiFiClass::begin(char *ssid) {
    uint8_t status = WFL_IDLE_STATUS;
    uint8_t attempts = WFL_MAX_ATTEMPT_CONNECTION;
    if (wiflydrv_->SetNetwork(ssid, strlen(ssid)) != WFL_FAILURE) {
        do {
            delay(WFL_DELAY_START_CONNECTION);
            status = wiflydrv_->ConnectionStatus();
        } while (((status == WFL_IDLE_STATUS) || (status == WFL_SCAN_COMPLETED)) && (--attempts > 0));
    } else {
        status = WFL_CONNECT_FAILED;
    }
    return status;
}

int WiFlyWiFiClass::begin(char *ssid, uint8_t key_idx, const char *key) {
    uint8_t status = WFL_IDLE_STATUS;
    uint8_t attempts = WFL_MAX_ATTEMPT_CONNECTION;
    if (wiflydrv_->SetKey(ssid, strlen(ssid), key_idx, key, strlen(key)) != WFL_FAILURE) {
        do {
            delay(WFL_DELAY_START_CONNECTION);
            status = wiflydrv_->ConnectionStatus();
        } while (((status == WFL_IDLE_STATUS) || (status == WFL_SCAN_COMPLETED)) && (--attempts > 0));
    } else {
        status = WFL_CONNECT_FAILED;
    }
    return status;
}

int WiFlyWiFiClass::begin(char *ssid, const char *passphrase) {
    uint8_t status = WFL_IDLE_STATUS;
    uint8_t attempts = WFL_MAX_ATTEMPT_CONNECTION;
    if (wiflydrv_->SetPassphrase(ssid, strlen(ssid), passphrase, strlen(passphrase))!= WFL_FAILURE) {
        do {
            delay(WFL_DELAY_START_CONNECTION);
            status = wiflydrv_->ConnectionStatus();
        } while (((status == WFL_IDLE_STATUS) || (status == WFL_SCAN_COMPLETED)) && (--attempts > 0));
    } else {
        status = WFL_CONNECT_FAILED;
    }
    return status;
}

void WiFlyWiFiClass::config(IPAddress local_ip) {
    wiflydrv_->Config(1, (uint32_t)local_ip, 0, 0);
}

void WiFlyWiFiClass::config(IPAddress local_ip, IPAddress dns_server) {
    wiflydrv_->Config(1, (uint32_t)local_ip, 0, 0);
    wiflydrv_->SetDNS(1, (uint32_t)dns_server, 0);
}

void WiFlyWiFiClass::config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway) {
    wiflydrv_->Config(2, (uint32_t)local_ip, (uint32_t)gateway, 0);
    wiflydrv_->SetDNS(1, (uint32_t)dns_server, 0);
}

void WiFlyWiFiClass::config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway, IPAddress subnet) {
    wiflydrv_->Config(3, (uint32_t)local_ip, (uint32_t)gateway, (uint32_t)subnet);
    wiflydrv_->SetDNS(1, (uint32_t)dns_server, 0);
}

void WiFlyWiFiClass::setDNS(IPAddress dns_server1) {
    wiflydrv_->SetDNS(1, (uint32_t)dns_server1, 0);
}

void WiFlyWiFiClass::setDNS(IPAddress dns_server1, IPAddress dns_server2){
    wiflydrv_->SetDNS(2, (uint32_t)dns_server1, (uint32_t)dns_server2);
}

int WiFlyWiFiClass::disconnect() {
    return wiflydrv_->Disconnect();
}

uint8_t *WiFlyWiFiClass::macAddress(uint8_t *mac){
    uint8_t *_mac = wiflydrv_->MacAddress();
    memcpy(mac, _mac, WFL_MAC_ADDR_LENGTH);
    return mac;
}

IPAddress WiFlyWiFiClass::localIP() {
    IPAddress ret;
    wiflydrv_->IpAddress(ret);
    return ret;
}

IPAddress WiFlyWiFiClass::subnetMask() {
    IPAddress ret;
    wiflydrv_->SubnetMask(ret);
    return ret;
}

IPAddress WiFlyWiFiClass::gatewayIP() {
    IPAddress ret;
    wiflydrv_->GatewayIP(ret);
    return ret;
}

char *WiFlyWiFiClass::SSID() {
    return wiflydrv_->CurrentSSID();
}

uint8_t *WiFlyWiFiClass::BSSID(uint8_t *bssid) {
    uint8_t *bssid_ = wiflydrv_->CurrentBSSID();
    memcpy(bssid, bssid_, WFL_MAC_ADDR_LENGTH);
    return bssid;
}

int32_t WiFlyWiFiClass::RSSI() {
    return wiflydrv_->CurrentRSSI();
}

uint8_t WiFlyWiFiClass::encryptionType() {
    return wiflydrv_->CurrentEncryptionType();
}

int8_t WiFlyWiFiClass::scanNetworks() {
    uint8_t attempts = 10;
    uint8_t numOfNetworks = 0;
    if (wiflydrv_->StartScanNetworks() == WFL_FAILURE) {
        return WFL_FAILURE;
    }
    do {
        delay(2000);
        numOfNetworks = wiflydrv_->GetScanNetworks();
    }
    while ((numOfNetworks == 0) && (--attempts > 0));
    return numOfNetworks;
}

char *WiFlyWiFiClass::SSID(uint8_t networkItem) {
    return wiflydrv_->SSIDNetoworks(networkItem);
}

int32_t WiFlyWiFiClass::RSSI(uint8_t networkItem) {
    return wiflydrv_->RSSINetoworks(networkItem);
}

uint8_t WiFlyWiFiClass::encryptionType(uint8_t networkItem) {
    return wiflydrv_->EncTypeNetowrks(networkItem);
}

uint8_t WiFlyWiFiClass::status() {
    return wiflydrv_->ConnectionStatus();
}

int WiFlyWiFiClass::hostByName(const char *aHostname, IPAddress& aResult) {
    return wiflydrv_->GetHostByName(aHostname, aResult);
}
