#include "utility/ServerDrv.h"
#include "utility/wfl_definitions.h"
#include "utility/wfl_types.h"
#include <IPAddress.h>
#include <Arduino.h>

using namespace Comm;

ServerDrv::ServerDrv(AbstractWiFlyDrv *wiflydrv): wiflydrv_(wiflydrv) {}

void ServerDrv::StartServer(uint16_t port, uint8_t protMode) {
}

void ServerDrv::StartClient(uint32_t ipAddress, uint16_t port, uint8_t protMode) {
    if (protMode == UDP_MODE) {
        StartClientUdp(ipAddress, port);
    }
}

void ServerDrv::StopClient() {
}

uint16_t ServerDrv::AvailData() {
    uint16_t result = 0;
    return result;
}

bool ServerDrv::GetData(uint8_t *data, uint8_t peek) {
    bool result = true;
    return result;
}

bool ServerDrv::GetDataBuf(uint8_t *_data, uint16_t *_dataLen) {
    bool result = true;
    return result;
}

bool ServerDrv::InsertDataBuf(const uint8_t *data, uint16_t _len) {
    bool result = true;
    return result;
}

bool ServerDrv::SendUdpData() {
    bool result = true;
    return result;
}

void ServerDrv::StartClientUdp(uint32_t ipAddress, uint16_t port) {
    char response[MAX_CMD_RESPONSE_LEN + 1] = {0};
    int8_t result = wiflydrv_->SendCommandAndParam(CMD_PROTOCOL, UDP_PROTOCOL_FLAG, response, MAX_CMD_RESPONSE_LEN, WFL_OK_STR);
    if (result == WFL_SUCCESS) {
        IPAddress addr(ipAddress);
        char addr_str[17] = {0};
        sprintf(addr_str, "%d.%d.%d.%d", addr[0], addr[1], addr[2], addr[3]);
        memset(response, 0, MAX_CMD_RESPONSE_LEN + 1);
        result = wiflydrv_->SendCommandAndParam(CMD_IP_HOST, addr_str, response, MAX_CMD_RESPONSE_LEN, WFL_OK_STR);
    }
    if (result == WFL_SUCCESS) {
        char port_str[17] = {0};
        sprintf(port_str, "%d", port);
        memset(response, 0, MAX_CMD_RESPONSE_LEN + 1);
        result = wiflydrv_->SendCommandAndParam(CMD_IP_REMOTE, port_str, response, MAX_CMD_RESPONSE_LEN, WFL_OK_STR);
    }
}
