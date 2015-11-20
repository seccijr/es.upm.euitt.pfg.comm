#include "utility/WiFlyDrv.h"

using namespace Comm;

WiFlyDrv::WiFlyDrv(AbstractUartWrapper *uart): uart_(uart) {};

void WiFlyDrv::Init() {
    uart_->Begin(SPI_DEFAULT_BAUDRATE);
}

int8_t WiFlyDrv::SetNetwork(char *ssid, uint8_t ssid_len) {
    int8_t result = 0;
    return result;
}

int8_t WiFlyDrv::SetPassphrase(char *ssid, uint8_t ssid_len, const char *passphrase, const uint8_t len) {
    int8_t result = 0;
    return result;
}

int8_t WiFlyDrv::SetKey(char *ssid, uint8_t ssid_len, uint8_t key_idx, const void *key, const uint8_t len) {
    int8_t result = 0;
    return result;
}

void WiFlyDrv::Config(uint8_t validParams, uint32_t local_ip, uint32_t gateway, uint32_t subnet) {
}

void WiFlyDrv::SetDNS(uint8_t validParams, uint32_t dns_server1, uint32_t dns_server2) {
}

int8_t WiFlyDrv::Disconnect() {
    int8_t result = 0;
    return result;
}

uint8_t WiFlyDrv::ConnectionStatus() {
    uint8_t result = 0;
    return result;
}

uint8_t *WiFlyDrv::MacAddress() {
    uint8_t tmp = 0;
    uint8_t *result = &tmp;
    return result;
}

void WiFlyDrv::IpAddress(IPAddress &ip) {
}

void WiFlyDrv::SubnetMask(IPAddress &mask) {
}

void WiFlyDrv::GatewayIP(IPAddress &ip) {
}

char *WiFlyDrv::CurrentSSID() {
}

uint8_t *WiFlyDrv::CurrentBSSID() {
    uint8_t tmp = 0;
    uint8_t *result = &tmp;
    return result;
}

int32_t WiFlyDrv::CurrentRSSI() {
    int32_t result = 0;
    return result;
}

uint8_t WiFlyDrv::CurrentEncryptionType() {
    uint8_t result = 0;
    return result;
}

int8_t WiFlyDrv::StartScanNetworks() {
    int8_t result = 0;
    return result;
}

uint8_t WiFlyDrv::GetScanNetworks() {
    uint8_t result = 0;
    return result;
}

char *WiFlyDrv::SSIDNetoworks(uint8_t networkItem) {
}

uint8_t WiFlyDrv::EncTypeNetowrks(uint8_t networkItem) {
    uint8_t result = 0;
    return result;
}

int32_t WiFlyDrv::RSSINetoworks(uint8_t networkItem) {
    int32_t result = 0;
    return result;
}

int WiFlyDrv::GetHostByName(const char *aHostname, IPAddress &aResult) {
    int result = 0;
    return result;
}

char *WiFlyDrv::FwVersion() {
    char result[1] = {'\0'};
}

void WiFlyDrv::GetRemoteData(uint8_t sock, uint8_t *ip, uint8_t *port) {
}

bool WiFlyDrv::SendCommand(const char *cmd) {

}

bool WiFlyDrv::FactoryReset() {

}

bool WiFlyDrv::Reboot() {

}
