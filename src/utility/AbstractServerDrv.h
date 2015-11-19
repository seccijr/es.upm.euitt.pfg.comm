#ifndef _ABSTRACTSERVERDRV_H
#define _ABSTRACTSERVERDRV_H

#include <stdint.h>

typedef enum {
    TCP_MODE,
    UDP_MODE
} tProtMode;

namespace Comm {
    class AbstractServerDrv {
        public:
            virtual void startServer(uint16_t port, uint8_t sock, uint8_t protMode = TCP_MODE) =0;
            virtual void startClient(uint32_t ipAddress, uint16_t port, uint8_t sock, uint8_t protMode = TCP_MODE) =0;
            virtual void stopClient(uint8_t sock) =0;
            virtual uint8_t getServerState(uint8_t sock) =0;
            virtual uint8_t getClientState(uint8_t sock) =0;
            virtual bool getData(uint8_t sock, uint8_t *data, uint8_t peek = 0) =0;
            virtual bool getDataBuf(uint8_t sock, uint8_t *data, uint16_t *len) =0;
            virtual bool insertDataBuf(uint8_t sock, const uint8_t *_data, uint16_t _dataLen) =0;
            virtual bool sendData(uint8_t sock, const uint8_t *data, uint16_t len) =0;
            virtual bool sendUdpData(uint8_t sock) =0;
            virtual uint16_t availData(uint8_t sock) =0;
            virtual uint8_t checkDataSent(uint8_t sock) =0;
    };
}

#endif
