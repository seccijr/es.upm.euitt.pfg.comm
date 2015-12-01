#include "utility/WiFlyDrv.h"
#include "utility/wfl_definitions.h"

void WiFlyDrv::init() {
    SpiDrv::begin(BAUD_RATE_DEFAULT);
    int8_t result = factoryReset();
    if (result == WFL_SUCCESS) {
        result = reboot();
    }
}

int8_t WiFlyDrv::setNetwork(char *ssid, uint8_t ssid_len) {
    char response[MAX_CMD_RESPONSE_LEN + 1] = {0};
    int8_t result = sendCommandAndParam(CMD_JOIN, (const char *)ssid, response, MAX_CMD_RESPONSE_LEN, CMD_ASSOCIATED_STR);
    return result;
}

int8_t WiFlyDrv::setPassphrase(char *ssid, uint8_t ssid_len, const char *passphrase, const uint8_t len) {
    char response[MAX_CMD_RESPONSE_LEN + 1] = {0};
    int8_t result = sendCommandAndParam(CMD_PHRASE, passphrase, response, MAX_CMD_RESPONSE_LEN, WFL_OK_STR);
    if (result == WFL_SUCCESS) {
        result = setNetwork(ssid, ssid_len);
    } else {
        return WFL_FAILURE;
    }
    return result;
}

int8_t WiFlyDrv::setKey(char *ssid, uint8_t ssid_len, uint8_t key_idx, const void *key, const uint8_t len) {
    int8_t result = 0;
    return result;
}

void WiFlyDrv::config(uint8_t validParams, uint32_t local_ip, uint32_t gateway, uint32_t subnet) {
}

void WiFlyDrv::setDNS(uint8_t validParams, uint32_t dns_server1, uint32_t dns_server2) {
}

int8_t WiFlyDrv::disconnect() {
    int8_t result = 0;
    return result;
}

uint8_t WiFlyDrv::connectionStatus() {
    char response[MAX_CMD_RESPONSE_LEN + 1] = {0};
    uint8_t result = sendCommand(CMD_NETWORK_STATUS, response, MAX_CMD_RESPONSE_LEN, WFL_END_COMMAND_STR);
    bool associated = false, authenticated = false;
    if (result == WFL_SUCCESS) {
        associated = checkStatusOk((const char *)response, STATUS_ASSOC, STATUS_OK);
        authenticated = checkStatusOk((const char *)response, STATUS_AUTH, STATUS_OK);
    }
    return associated && authenticated ? WFL_CONNECTED : WFL_DISCONNECTED;
}

uint8_t *WiFlyDrv::macAddress() {
    uint8_t tmp = 0;
    uint8_t *result = &tmp;
    return result;
}

uint8_t WiFlyDrv::captureIncommingIp() {
    char response[MAX_CMD_RESPONSE_LEN + 1] = {0};
    uint8_t result = WiFlyDrv::sendCommandAndParam(CMD_IP_FLAG, IP_CACHE_ADD_FLAG, response, MAX_CMD_RESPONSE_LEN, WFL_OK_STR);
    if (result == WFL_SUCCESS) {
        result = WiFlyDrv::sendCommandAndParam(CMD_IP_HOST, NO_REMOTE_HOST, response, MAX_CMD_RESPONSE_LEN, WFL_OK_STR);
    }
    return result;
}

void WiFlyDrv::ipAddress(IPAddress &ip) {
}

void WiFlyDrv::ipAddressHost(IPAddress &ip) {
    char response[MAX_CMD_RESPONSE_LEN + 1] = {0};
    uint8_t result = sendCommand(CMD_GET_IP, response, MAX_CMD_RESPONSE_LEN, WFL_END_COMMAND_STR);
    if (result == WFL_SUCCESS) {
        char ip_str[17] = {0};
        bool parsed = parseIpHost(response, ip_str);
        if (parsed) {
            ip.fromString(ip_str);
        }
    }
}

int WiFlyDrv::getHostByName(const char *aHostname, IPAddress &aResult) {
    int result = 0;
    return result;
}

int8_t WiFlyDrv::getResponse(char *response, int len, const char *end) {
    bool read_condition = true, smaller, ended;
    int i = 0;
    do {
        unsigned long time_out = millis() + WFL_READ_TIMEOUT;
        while (SpiDrv::available() <= 0) {
            if (millis() > time_out) {
                return WFL_FAILURE;
            }
            delay(1);
        }
        smaller = i < len;
        if (smaller) {
            response[i++] = SpiDrv::read();
        }
        ended = strstr(response, end) != NULL;
        read_condition =  smaller && !ended;
    } while (read_condition);
    return WFL_SUCCESS;
}

int8_t WiFlyDrv::sendCommand(const char *cmd, char *response, int len, const char *end) {
    delay(WFL_COMMAND_GUARD_TIME);
    SpiDrv::write("$$$");
    delay(WFL_COMMAND_GUARD_TIME);
    SpiDrv::write(13);
    delay(WFL_COMMAND_GUARD_TIME);
    SpiDrv::flush();
    SpiDrv::write(cmd);
    SpiDrv::write(13);
    int result = getResponse(response, len, end);
    SpiDrv::write("exit");
    SpiDrv::write(13);
    delay(WFL_COMMAND_GUARD_TIME);
    SpiDrv::flush();
    return result;
}

int8_t WiFlyDrv::sendCommandAndParam(const char *cmd, const char *param, char *response, int len, const char *end) {
    char dest[MAX_CMD_LEN + 1] = {0};
    if (strlen(cmd) + strlen(param) < MAX_CMD_LEN) {
        sprintf(dest, "%s %s", cmd, param);
        int8_t result = sendCommand(dest, response, len, end);
        return result;
    }
    return WFL_FAILURE;
}

int8_t WiFlyDrv::factoryReset() {
    char response[MAX_CMD_RESPONSE_LEN + 1] = {0};
    int8_t result = sendCommand(CMD_RESET, response, MAX_CMD_RESPONSE_LEN, WFL_END_COMMAND_STR);
    return result;
}

int8_t WiFlyDrv::reboot() {
    char response[MAX_CMD_RESPONSE_LEN + 1] = {0};
    int8_t result = sendCommand(CMD_REBOOT, response, MAX_CMD_RESPONSE_LEN, WFL_READY_STR);
    return result;
}

bool WiFlyDrv::checkStatusOk(const char *response, const char *status_indicator, const char *success_indicator) {
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

bool WiFlyDrv::parseIpHost(const char *response, char *ip) {
    bool result = false;
    char *host_line = strstr(response, RES_LINE_HOST);
    if (host_line != NULL) {
        char *dp = strstr(host_line, ":");
        char *ini = host_line + strlen(RES_LINE_HOST);
        int len = dp - ini;
        if (len < 17) {
            memcpy(ip, ini, len);
            result = true;
        } else {
            result = false;
        }
    }
    return result;
}

bool WiFlyDrv::parsePortHost(const char *response, char *port) {
    bool result = false;
    char *host_line = strstr(response, RES_LINE_HOST);
    if (host_line != NULL) {
        char *dp = strstr(host_line, ":");
        char *cr = strstr(host_line, "\r\n");
        int len = cr - dp - 1;
        if (len < 6) {
            memcpy(port, dp + 1, len);
            result = true;
        } else {
            result = false;
        }
    }
    return result;
}
