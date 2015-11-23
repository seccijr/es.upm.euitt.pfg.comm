#ifndef _WFL_DEFINITIONS_H
#define _WFL_DEFINITIONS_H

#define WFL_MAX_ATTEMPT_CONNECTION 10
#define WFL_READY_STR "READY"
#define WFL_OK_STR "AOK"
#define WFL_END_COMMAND_STR "<4.00>"
#define WFL_DELAY_START_CONNECTION 5000
#define WFL_READ_TIMEOUT 1000
#define WFL_COMMAND_GUARD_TIME 300
#define WFL_MAC_ADDR_LENGTH 6

#define MAX_CMD_RESPONSE_LEN 255
#define MAX_CMD_LEN 255
#define CMD_RESET "factory RESET"
#define CMD_REBOOT "reboot"
#define CMD_JOIN "join"
#define CMD_PHRASE "set wlan phrase"
#define CMD_ASSOCIATED_STR "Associated"
#define CMD_PROTOCOL "set ip protocol"
#define CMD_IP_HOST "set ip host"
#define CMD_IP_REMOTE "set ip remote"
#define CMD_GET_IP "get ip"
#define CMD_VERSION "ver"
#define UDP_PROTOCOL_FLAG "1"

typedef enum {
    WFL_IDLE_STATUS = 0,
    WFL_SCAN_COMPLETED,
    WFL_CONNECT_FAILED
} wfl_status_t;

#endif
