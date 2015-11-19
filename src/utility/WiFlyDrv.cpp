#include "utility/WiFlyDrv.h"

void WiFiDrv::Init() {
}

int8_t WiFiDrv::SetNetwork(char *ssid, uint8_t ssid_len) {
    int8_t result = 0;
    return result;
}

int8_t WiFiDrv::SetPassphrase(char *ssid, uint8_t ssid_len, const char *passphrase, const uint8_t len) {
    int8_t result = 0;
    return result;
}

int8_t WiFiDrv::SetKey(char *ssid, uint8_t ssid_len, uint8_t key_idx, const void *key, const uint8_t len) {
    int8_t result = 0;
    return result;
}

void WiFiDrv::Config(uint8_t validParams, uint32_t local_ip, uint32_t gateway, uint32_t subnet) {
}

void WiFiDrv::SetDNS(uint8_t validParams, uint32_t dns_server1, uint32_t dns_server2) {
}

int8_t WiFiDrv::Disconnect() {
    int8_t result = 0;
    return result;
}

uint8_t WiFiDrv::ConnectionStatus() {
    uint8_t result = 0;
    return result;
}

uint8_t *WiFiDrv::MacAddress() {
    uint8_t result = 0;
    return result;
}

void WiFiDrv::IpAddress(IPAddress &ip) {
}

void WiFiDrv::SubnetMask(IPAddress &mask) {
}

void WiFiDrv::GatewayIP(IPAddress &ip) {
}

char *WiFiDrv::CurrentSSID() {
}

uint8_t *WiFiDrv::CurrentBSSID() {
    uint8_t result = 0;
    return result;
}

int32_t WiFiDrv::CurrentRSSI() {
    int32_t result = 0;
    return result;
}

uint8_t WiFiDrv::CurrentEncryptionType() {
    uint8_t result = 0;
    return result;
}

int8_t WiFiDrv::StartScanNetworks() {
    int8_t result = 0;
    return result;
}

uint8_t WiFiDrv::GetScanNetworks() {
    uint8_t result = 0;
    return result;
}

char *WiFiDrv::SSIDNetoworks(uint8_t networkItem) {
}

uint8_t WiFiDrv::EncTypeNetowrks(uint8_t networkItem) {
    uint8_t result = 0;
    return result;
}

int32_t WiFiDrv::RSSINetoworks(uint8_t networkItem) {
    int32_t result = 0;
    return result;
}

int WiFiDrv::GetHostByName(const char *aHostname, IPAddress &aResult) {
    int result = 0;
    return result;
}

char *WiFiDrv::FwVersion() {
    char result[1] = "\0";
}

static void WiFiDrv::GetRemoteData(uint8_t sock, uint8_t *ip, uint8_t *port) {
}
