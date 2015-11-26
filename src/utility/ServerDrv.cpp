#include "utility/ServerDrv.h"
#include "utility/SpiDrv.h"
#include "utility/wfl_definitions.h"
#include "utility/wfl_types.h"
#include <IPAddress.h>
#include <Arduino.h>

namespace Comm {
    uint8_t ServerDrv::data_buf_[WFL_MAX_BUF_SIZE] = {0};
    uint8_t ServerDrv::data_idx_ = 0;

    void ServerDrv::startServer(uint16_t port, uint8_t protMode) {
        if (protMode == UDP_MODE) {
            startServerUdp(port);
        }
    }

    void ServerDrv::startClient(uint32_t ipAddress, uint16_t port, uint8_t protMode) {
        if (protMode == UDP_MODE) {
            startClientUdp(ipAddress, port);
        }
    }

    void ServerDrv::stopClient() {
    }

    uint16_t ServerDrv::availableData() {
        return SpiDrv::available();
    }

    bool ServerDrv::getData(uint8_t *data, uint8_t peek) {
        if (SpiDrv::available()) {
            *data = SpiDrv::read();
            return true;
        }
        return false;
    }

    bool ServerDrv::getDataBuf(uint8_t *data, size_t *len) {
        bool result = true;
        return result;
    }

    bool ServerDrv::insertDataBuf(const uint8_t *data, size_t len) {
        if (data_idx_ + len < WFL_MAX_BUF_SIZE) {
            uint8_t *curr = data_buf_ + data_idx_;
            memcpy(curr, data, len);
            data_idx_ += len;
            return true;
        }
        return false;
    }

    bool ServerDrv::sendUdpData() {
        size_t writen = 0;
        uint8_t i = 0;
        while (i < data_idx_) {
            SpiDrv::write((byte)(data_buf_[i++]));
        }
        memset(data_buf_, 0, WFL_MAX_BUF_SIZE);
        data_idx_ = 0;
        return true;
    }

    void ServerDrv::startServerUdp(uint16_t port) {
        char response[MAX_CMD_RESPONSE_LEN + 1] = {0};
        int8_t result = WiFlyDrv::sendCommandAndParam(CMD_PROTOCOL, UDP_PROTOCOL_FLAG, response, MAX_CMD_RESPONSE_LEN, WFL_OK_STR);
        if (result == WFL_SUCCESS) {
            char port_str[17] = {0};
            sprintf(port_str, "%d", port);
            memset(response, 0, MAX_CMD_RESPONSE_LEN + 1);
            result = WiFlyDrv::sendCommandAndParam(CMD_LOCAL_PORT, port_str, response, MAX_CMD_RESPONSE_LEN, WFL_OK_STR);
        }
    }

    void ServerDrv::startClientUdp(uint32_t ipAddress, uint16_t port) {
        char response[MAX_CMD_RESPONSE_LEN + 1] = {0};
        int8_t result = WiFlyDrv::sendCommandAndParam(CMD_PROTOCOL, UDP_PROTOCOL_FLAG, response, MAX_CMD_RESPONSE_LEN, WFL_OK_STR);
        if (result == WFL_SUCCESS) {
            IPAddress addr(ipAddress);
            char addr_str[17] = {0};
            sprintf(addr_str, "%u.%u.%u.%u", addr[0], addr[1], addr[2], addr[3]);
            memset(response, 0, MAX_CMD_RESPONSE_LEN + 1);
            result = WiFlyDrv::sendCommandAndParam(CMD_IP_HOST, addr_str, response, MAX_CMD_RESPONSE_LEN, WFL_OK_STR);
        }
        if (result == WFL_SUCCESS) {
            char port_str[17] = {0};
            sprintf(port_str, "%u", port);
            memset(response, 0, MAX_CMD_RESPONSE_LEN + 1);
            result = WiFlyDrv::sendCommandAndParam(CMD_IP_REMOTE, port_str, response, MAX_CMD_RESPONSE_LEN, WFL_OK_STR);
        }
    }
}
