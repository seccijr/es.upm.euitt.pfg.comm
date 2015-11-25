#include "utility/ServerDrv.h"
#include "utility/wfl_definitions.h"
#include "utility/wfl_types.h"
#include <IPAddress.h>
#include <Arduino.h>

using namespace Comm;

ServerDrv::ServerDrv(AbstractWiFlyDrv *wiflydrv, AbstractUartWrapper *uart):
    wiflydrv_(wiflydrv), uart_(uart), data_idx_(0) {
        memset(data_buf_, 0, WFL_MAX_BUF_SIZE);
    }

void ServerDrv::StartServer(uint16_t port, uint8_t protMode) {
    if (protMode == UDP_MODE) {
        StartServerUdp(port);
    }
}

void ServerDrv::StartClient(uint32_t ipAddress, uint16_t port, uint8_t protMode) {
    if (protMode == UDP_MODE) {
        StartClientUdp(ipAddress, port);
    }
}

void ServerDrv::StopClient() {
}

uint16_t ServerDrv::AvailableData() {
    return uart_->Available();
}

bool ServerDrv::GetData(uint8_t *data, uint8_t peek) {
    if (uart_->Available()) {
        *data = uart_->Read();
        return true;
    }
    return false;
}

bool ServerDrv::GetDataBuf(uint8_t *data, size_t *len) {
    bool result = true;
    return result;
}

bool ServerDrv::InsertDataBuf(const uint8_t *data, size_t len) {
    if (data_idx_ + len < WFL_MAX_BUF_SIZE) {
        uint8_t *curr = data_buf_ + data_idx_;
        memcpy(curr, data, len);
        data_idx_ += len;
        return true;
    }
    return false;
}

bool ServerDrv::SendUdpData() {
    size_t writen = 0;
    uint8_t i = 0;
    while (i < data_idx_) {
        uart_->Write((byte)(data_buf_[i++]));
    }
    memset(data_buf_, 0, WFL_MAX_BUF_SIZE);
    data_idx_ = 0;
    return true;
}

void ServerDrv::StartServerUdp(uint16_t port) {
    char response[MAX_CMD_RESPONSE_LEN + 1] = {0};
    int8_t result = wiflydrv_->SendCommandAndParam(CMD_PROTOCOL, UDP_PROTOCOL_FLAG, response, MAX_CMD_RESPONSE_LEN, WFL_OK_STR);
    if (result == WFL_SUCCESS) {
        char port_str[17] = {0};
        sprintf(port_str, "%d", port);
        memset(response, 0, MAX_CMD_RESPONSE_LEN + 1);
        result = wiflydrv_->SendCommandAndParam(CMD_LOCAL_PORT, port_str, response, MAX_CMD_RESPONSE_LEN, WFL_OK_STR);
    }
}

void ServerDrv::StartClientUdp(uint32_t ipAddress, uint16_t port) {
    char response[MAX_CMD_RESPONSE_LEN + 1] = {0};
    int8_t result = wiflydrv_->SendCommandAndParam(CMD_PROTOCOL, UDP_PROTOCOL_FLAG, response, MAX_CMD_RESPONSE_LEN, WFL_OK_STR);
    if (result == WFL_SUCCESS) {
        IPAddress addr(ipAddress);
        char addr_str[17] = {0};
        sprintf(addr_str, "%u.%u.%u.%u", addr[0], addr[1], addr[2], addr[3]);
        memset(response, 0, MAX_CMD_RESPONSE_LEN + 1);
        result = wiflydrv_->SendCommandAndParam(CMD_IP_HOST, addr_str, response, MAX_CMD_RESPONSE_LEN, WFL_OK_STR);
    }
    if (result == WFL_SUCCESS) {
        char port_str[17] = {0};
        sprintf(port_str, "%u", port);
        memset(response, 0, MAX_CMD_RESPONSE_LEN + 1);
        result = wiflydrv_->SendCommandAndParam(CMD_IP_REMOTE, port_str, response, MAX_CMD_RESPONSE_LEN, WFL_OK_STR);
    }
}
