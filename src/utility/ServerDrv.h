#ifndef _SERVERDRV_H
#define _SERVERDRV_H

#include <stdint.h>

typedef enum {
    TCP_MODE,
    UDP_MODE
} tProtMode;

namespace Comm {
    class ServerDrv {
        public:
            static void startServer(uint16_t port, uint8_t sock, uint8_t protMode=TCP_MODE);
            static void startClient(uint32_t ipAddress, uint16_t port, uint8_t sock, uint8_t protMode=TCP_MODE);
            static void stopClient(uint8_t sock);
            static uint8_t getServerState(uint8_t sock);
            static uint8_t getClientState(uint8_t sock);
            static bool getData(uint8_t sock, uint8_t *data, uint8_t peek = 0);
            static bool getDataBuf(uint8_t sock, uint8_t *data, uint16_t *len);
            static bool insertDataBuf(uint8_t sock, const uint8_t *_data, uint16_t _dataLen);
            static bool sendData(uint8_t sock, const uint8_t *data, uint16_t len);
            static bool sendUdpData(uint8_t sock);
            static uint16_t availData(uint8_t sock);
            static uint8_t checkDataSent(uint8_t sock);
    };
}

#endif
