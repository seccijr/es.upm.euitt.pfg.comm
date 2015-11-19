#ifndef _WFLTYPES_H
#define _WFLTYPES_H

#include <inttypes.h>

typedef enum {
        WFL_FAILURE = -1,
        WFL_SUCCESS = 1,
} wfl_error_code_t;


enum wfl_auth_mode {
        AUTH_MODE_INVALID,
        AUTH_MODE_AUTO,
        AUTH_MODE_OPEN_SYSTEM,
        AUTH_MODE_SHARED_KEY,
        AUTH_MODE_WPA,
        AUTH_MODE_WPA2,
        AUTH_MODE_WPA_PSK,
        AUTH_MODE_WPA2_PSK
};

#endif
