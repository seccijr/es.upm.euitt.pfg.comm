#ifndef _WFLTYPES_H
#define _WFLTYPES_H

#include <inttypes.h>

typedef enum {
        WFL_FAILURE = -1,
        WFL_SUCCESS = 1,
} wfl_error_code_t;

typedef enum {
    WFL_IDLE_STATUS,
    WFL_NO_SSID_AVAIL,
    WFL_SCAN_COMPLETED,
    WFL_CONNECTED,
    WFL_CONNECT_FAILED,
    WFL_CONNECTION_LOST,
    WFL_DISCONNECTED
} wfl_status_t;

typedef enum {
    TCP_MODE,
    UDP_MODE
} wfl_layer4_mode;

#endif
