// CommAddress.h

#ifndef _commaddress_h
#define _commaddress_h

#include <stdint.h>

class CommAddressClass {
    protected:
        uint16_t type_;
};

#define CNT_SEPO (0x0u << 1)
#define CNT_LCB (0x0u << 2)
#define CNT_MAC (0x0u << 3)
#define CNT_AAC (0x0u << 4)

#endif

