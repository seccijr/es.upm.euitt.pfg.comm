#ifndef _SERVERDRV_H
#define _SERVERDRV_H

#include <stdint.h>
#include "utility/AbstractServerDrv.h"

namespace Comm {
    class ServerDrv: public AbstractServerDrv {
        public:
            void startServer(uint16_t port, uint8_t sock, uint8_t protMode=TCP_MODE);
            void startClient(uint32_t ipAddress, uint16_t port, uint8_t sock, uint8_t protMode=TCP_MODE);
            void stopClient(uint8_t sock);
            uint8_t getServerState(uint8_t sock);
            uint8_t getClientState(uint8_t sock);
            bool getData(uint8_t sock, uint8_t *data, uint8_t peek = 0);
            bool getDataBuf(uint8_t sock, uint8_t *data, uint16_t *len);
            bool insertDataBuf(uint8_t sock, const uint8_t *_data, uint16_t _dataLen);
            bool sendData(uint8_t sock, const uint8_t *data, uint16_t len);
            bool sendUdpData(uint8_t sock);
            uint16_t availData(uint8_t sock);
            uint8_t checkDataSent(uint8_t sock);
    };
}

#endif
