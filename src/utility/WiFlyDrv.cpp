#include "utility/WiFlyDrv.h"
#include "utility/wfl_definitions.h"

using namespace Comm;

WiFlyDrv::WiFlyDrv(AbstractUartWrapper *uart): uart_(uart) {};

void WiFlyDrv::Init() {
    uart_->Begin(BAUD_RATE_DEFAULT);
    int8_t result = FactoryReset();
    if (result == WFL_SUCCESS) {
        result = Reboot();
    }
}

int8_t WiFlyDrv::SetNetwork(char *ssid, uint8_t ssid_len) {
    char response[MAX_CMD_RESPONSE_LEN + 1] = {0};
    int8_t result = SendCommandAndParam(CMD_JOIN, (const char *)ssid, response, MAX_CMD_RESPONSE_LEN, CMD_ASSOCIATED_STR);
    return result;
}

int8_t WiFlyDrv::SetPassphrase(char *ssid, uint8_t ssid_len, const char *passphrase, const uint8_t len) {
    char response[MAX_CMD_RESPONSE_LEN + 1] = {0};
    int8_t result = SendCommandAndParam(CMD_PHRASE, passphrase, response, MAX_CMD_RESPONSE_LEN, WFL_OK_STR);
    if (result == WFL_SUCCESS) {
        result = SetNetwork(ssid, ssid_len);
    } else {
        return WFL_FAILURE;
    }
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
    char response[MAX_CMD_RESPONSE_LEN + 1] = {0};
    uint8_t result = SendCommand(CMD_NETWORK_STATUS, response, MAX_CMD_RESPONSE_LEN, WFL_END_COMMAND_STR);
    bool associated = false, authenticated = false;
    if (result == WFL_SUCCESS) {
        associated = CheckStatusOk((const char *)response, STATUS_ASSOC, STATUS_OK);
        authenticated = CheckStatusOk((const char *)response, STATUS_AUTH, STATUS_OK);
    }
    return associated && authenticated ? WFL_CONNECTED : WFL_DISCONNECTED;
}

uint8_t *WiFlyDrv::MacAddress() {
    uint8_t tmp = 0;
    uint8_t *result = &tmp;
    return result;
}

void WiFlyDrv::IpAddress(IPAddress &ip) {
}

int WiFlyDrv::GetHostByName(const char *aHostname, IPAddress &aResult) {
    int result = 0;
    return result;
}

int8_t WiFlyDrv::GetResponse(char *response, int len, const char *end) {
    bool read_condition = true, smaller, ended;
    int i = 0;
    do {
        unsigned long time_out = millis() + WFL_READ_TIMEOUT;
        while (uart_->Available() <= 0) {
            if (millis() > time_out) {
                return WFL_FAILURE;
            }
            delay(1);
        }
        smaller = i < len;
        if (smaller) {
            response[i++] = uart_->Read();
        }
        ended = strstr(response, end) != NULL;
        read_condition =  smaller && !ended;
    } while (read_condition);
    return WFL_SUCCESS;
}

int8_t WiFlyDrv::SendCommand(const char *cmd, char *response, int len, const char *end) {
    delay(WFL_COMMAND_GUARD_TIME);
    uart_->Write("$$$");
    delay(WFL_COMMAND_GUARD_TIME);
    uart_->Write(13);
    delay(WFL_COMMAND_GUARD_TIME);
    uart_->Flush();
    uart_->Write(cmd);
    uart_->Write(13);
    int result = GetResponse(response, len, end);
    delay(WFL_COMMAND_GUARD_TIME);
    uart_->Write("exit");
    uart_->Write(13);
    delay(WFL_COMMAND_GUARD_TIME);
    uart_->Flush();
    return result;
}

int8_t WiFlyDrv::SendCommandAndParam(const char *cmd, const char *param, char *response, int len, const char *end) {
    char dest[MAX_CMD_LEN + 1] = {0};
    if (strlen(cmd) + strlen(param) < MAX_CMD_LEN) {
        sprintf(dest, "%s %s", cmd, param);
        int8_t result = SendCommand(dest, response, len, end);
        return result;
    }
    return WFL_FAILURE;
}

int8_t WiFlyDrv::FactoryReset() {
    char response[MAX_CMD_RESPONSE_LEN + 1] = {0};
    int8_t result = SendCommand(CMD_RESET, response, MAX_CMD_RESPONSE_LEN, WFL_END_COMMAND_STR);
    return result;
}

int8_t WiFlyDrv::Reboot() {
    char response[MAX_CMD_RESPONSE_LEN + 1] = {0};
    int8_t result = SendCommand(CMD_REBOOT, response, MAX_CMD_RESPONSE_LEN, WFL_READY_STR);
    return result;
}

bool WiFlyDrv::CheckStatusOk(const char *response, const char *status_indicator, const char *success_indicator) {
    bool result = false;
    char *status_line = strstr(response, status_indicator);
    if (status_line != NULL) {
        char *cr = strstr(status_line, "\r\n");
        char status[MAX_CMD_RESPONSE_LEN + 1] = {0};
        memcpy(status, status_line, cr - status_line);
        char *success = strstr(status, success_indicator);
        result = success != NULL;
    }
    return result;
}
