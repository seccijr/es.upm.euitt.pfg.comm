#ifndef _SERVERDRV_H
#define _SERVERDRV_H

#include <stdint.h>
#include "utility/AbstractUartWrapper.h"
#include "utility/AbstractServerDrv.h"
#include "utility/AbstractWiFlyDrv.h"
#include "utility/wfl_definitions.h"

namespace Comm {
    class ServerDrv: public AbstractServerDrv {
        public:
            // Own members
            ServerDrv(AbstractWiFlyDrv *wiflydrv, AbstractUartWrapper *uart);

            // Util
            void StartServer(uint16_t port, uint8_t protMode=TCP_MODE);
            void StartClient(uint32_t ipAddress, uint16_t port, uint8_t protMode=TCP_MODE);
            void StopClient();
            bool SendUdpData();
            bool InsertDataBuf(const uint8_t *data, size_t len);
            uint16_t AvailableData();
            bool GetData(uint8_t *data, uint8_t peek = 0);
            bool GetDataBuf(uint8_t *data, size_t *len);

        private:
            AbstractWiFlyDrv *wiflydrv_;
            AbstractUartWrapper *uart_;
            void StartClientUdp(uint32_t ipAddress, uint16_t port);
            void StartServerUdp(uint16_t port);
            uint8_t data_buf_[WFL_MAX_BUF_SIZE];
            uint8_t data_idx_;
    };
}

#endif
