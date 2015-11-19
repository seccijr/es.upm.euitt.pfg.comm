#include "utility/ServerDrv.h"

using namespace Comm;

void ServerDrv::startServer(uint16_t port, uint8_t sock, uint8_t protMode) {
}

void ServerDrv::startClient(uint32_t ipAddress, uint16_t port, uint8_t sock, uint8_t protMode) {
}

void ServerDrv::stopClient(uint8_t sock) {
}

uint8_t ServerDrv::getServerState(uint8_t sock) {
    uint8_t result = 0;
    return result;
}

uint8_t ServerDrv::getClientState(uint8_t sock) {
    uint8_t result = 0;
    return result;
}

uint16_t ServerDrv::availData(uint8_t sock) {
    uint16_t result = 0;
    return result;
}

bool ServerDrv::getData(uint8_t sock, uint8_t *data, uint8_t peek) {
    bool result = true;
    return result;
}

bool ServerDrv::getDataBuf(uint8_t sock, uint8_t *_data, uint16_t *_dataLen) {
    bool result = true;
    return result;
}

bool ServerDrv::insertDataBuf(uint8_t sock, const uint8_t *data, uint16_t _len) {
    bool result = true;
    return result;
}

bool ServerDrv::sendUdpData(uint8_t sock) {
    bool result = true;
    return result;
}

bool ServerDrv::sendData(uint8_t sock, const uint8_t *data, uint16_t len) {
    bool result = true;
    return result;
}

uint8_t ServerDrv::checkDataSent(uint8_t sock) {
    uint8_t result = 0;
    return result;
}
