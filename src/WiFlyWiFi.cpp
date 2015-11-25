#include <WiFlyWiFi.h>
#include <Arduino.h>
#include "utility/WiFlyDrv.h"
#include "utility/wfl_spi.h"
#include "utility/wfl_types.h"

using namespace Comm;

WiFlyWiFiClass::WiFlyWiFiClass(AbstractWiFlyDrv *wiflydrv): wiflydrv_(wiflydrv) {
    Init();
}

void WiFlyWiFiClass::Init() {
    wiflydrv_->Init();
}

int WiFlyWiFiClass::Begin(char *ssid) {
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

int WiFlyWiFiClass::Begin(char *ssid, uint8_t key_idx, const char *key) {
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

int WiFlyWiFiClass::Begin(char *ssid, const char *passphrase) {
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

void WiFlyWiFiClass::Config(IPAddress local_ip) {
    wiflydrv_->Config(1, (uint32_t)local_ip, 0, 0);
}

void WiFlyWiFiClass::Config(IPAddress local_ip, IPAddress dns_server) {
    wiflydrv_->Config(1, (uint32_t)local_ip, 0, 0);
    wiflydrv_->SetDNS(1, (uint32_t)dns_server, 0);
}

void WiFlyWiFiClass::Config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway) {
    wiflydrv_->Config(2, (uint32_t)local_ip, (uint32_t)gateway, 0);
    wiflydrv_->SetDNS(1, (uint32_t)dns_server, 0);
}

void WiFlyWiFiClass::Config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway, IPAddress subnet) {
    wiflydrv_->Config(3, (uint32_t)local_ip, (uint32_t)gateway, (uint32_t)subnet);
    wiflydrv_->SetDNS(1, (uint32_t)dns_server, 0);
}

void WiFlyWiFiClass::SetDNS(IPAddress dns_server1) {
    wiflydrv_->SetDNS(1, (uint32_t)dns_server1, 0);
}

void WiFlyWiFiClass::SetDNS(IPAddress dns_server1, IPAddress dns_server2){
    wiflydrv_->SetDNS(2, (uint32_t)dns_server1, (uint32_t)dns_server2);
}

int WiFlyWiFiClass::Disconnect() {
    return wiflydrv_->Disconnect();
}

uint8_t *WiFlyWiFiClass::MacAddress(uint8_t *mac){
    uint8_t *_mac = wiflydrv_->MacAddress();
    memcpy(mac, _mac, WFL_MAC_ADDR_LENGTH);
    return mac;
}

IPAddress WiFlyWiFiClass::LocalIP() {
    IPAddress ret;
    wiflydrv_->IpAddress(ret);
    return ret;
}

uint8_t WiFlyWiFiClass::Status() {
    return wiflydrv_->ConnectionStatus();
}

int WiFlyWiFiClass::HostByName(const char *aHostname, IPAddress &aResult) {
    return wiflydrv_->GetHostByName(aHostname, aResult);
}
