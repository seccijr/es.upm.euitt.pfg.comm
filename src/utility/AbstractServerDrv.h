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
            virtual bool GetDataBuf(uint8_t *data, size_t *len) =0;
            virtual bool InsertDataBuf(const uint8_t *data, size_t len) =0;
            virtual bool SendUdpData() =0;
            virtual uint16_t AvailableData() =0;
    };
}

#endif
