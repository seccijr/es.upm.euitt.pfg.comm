#ifndef _COMMADDRESS_H
#define _COMMADDRESS_H

#include <stdint.h>

namespace Comm {
    class AddressClass {
        protected:
            uint16_t type_;
    };
}

#define CNT_SEPO (0x0u << 1)
#define CNT_LCB (0x0u << 2)
#define CNT_MAC (0x0u << 3)
#define CNT_AAC (0x0u << 4)

#endif

