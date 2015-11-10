#ifndef _COMMADDRESS_H
#define _COMMADDRESS_H

#include <stdint.h>

namespace Comm {
    class AddressClass {
        protected:
            uint8_t type_;
    };
}

// COMMUNICATION NETWORK TYPE

#define CNT_SEP (0x00 << 1)  // SERIAL PORT
#define CNT_LCB (0x00 << 2)  // LOCAL CALLBACK
#define CNT_MAC (0x00 << 3)  // MAC
#define CNT_AAC (0x00 << 4)  // ACOUSTIC CHANNEL

#endif

