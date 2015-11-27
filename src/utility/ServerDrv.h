#ifndef _SERVERDRV_H
#define _SERVERDRV_H

#include <stdint.h>
#include "utility/SpiDrv.h"
#include "utility/WiFlyDrv.h"
#include "utility/wfl_definitions.h"

class ServerDrv {
    public:
        static void startServer(uint16_t port, uint8_t protMode=TCP_MODE);
        static void startClient(uint32_t ipAddress, uint16_t port, uint8_t protMode=TCP_MODE);
        static void stopClient();
        static bool sendUdpData();
        static bool insertDataBuf(const uint8_t *data, size_t len);
        static uint16_t availableData();
        static bool getData(uint8_t *data, uint8_t peek = 0);
        static bool getDataBuf(uint8_t *data, size_t *len);

    private:
        static void startClientUdp(uint32_t ipAddress, uint16_t port);
        static uint8_t data_buf_[WFL_MAX_BUF_SIZE];
        static uint8_t data_idx_;
};

#endif
