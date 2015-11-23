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
            virtual void StartServer(uint16_t port, uint8_t protMode = TCP_MODE) =0;
            virtual void StartClient(uint32_t ipAddress, uint16_t port, uint8_t protMode = TCP_MODE) =0;
            virtual void StopClient() =0;
            virtual bool GetData(uint8_t *data, uint8_t peek = 0) =0;
            virtual bool GetDataBuf(uint8_t *data, uint16_t *len) =0;
            virtual bool InsertDataBuf(const uint8_t *_data, uint16_t _dataLen) =0;
            virtual bool SendUdpData() =0;
            virtual uint16_t AvailData() =0;
    };
}

#endif
