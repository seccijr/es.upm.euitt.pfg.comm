#ifndef _SERVERDRV_H
#define _SERVERDRV_H

#include <stdint.h>
#include "utility/AbstractServerDrv.h"
#include "utility/AbstractWiFlyDrv.h"

namespace Comm {
    class ServerDrv: public AbstractServerDrv {
        public:
            // Own members
            ServerDrv(AbstractWiFlyDrv *wiflydrv);

            // Util
            void StartServer(uint16_t port, uint8_t protMode=TCP_MODE);
            void StartClient(uint32_t ipAddress, uint16_t port, uint8_t protMode=TCP_MODE);
            void StopClient();
            bool SendUdpData();
            bool InsertDataBuf(const uint8_t *_data, uint16_t _dataLen);
            uint16_t AvailData();
            bool GetData(uint8_t *data, uint8_t peek = 0);
            bool GetDataBuf(uint8_t *data, uint16_t *len);

        private:
            AbstractWiFlyDrv *wiflydrv_;
            void StartClientUdp(uint32_t ipAddress, uint16_t port);
    };
}

#endif
