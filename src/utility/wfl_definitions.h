#ifndef _WFL_DEFINITIONS_H
#define _WFL_DEFINITIONS_H

#define WFL_SSID_MAX_LENGTH 32
#define WFL_WPA_KEY_MAX_LENGTH 63
#define WFL_WEP_KEY_MAX_LENGTH 13
#define WFL_MAC_ADDR_LENGTH 6
#define WFL_IPV4_LENGTH 4
#define WFL_NETWORKS_LIST_MAXNUM 10
#define NA_STATE -1
#define WFL_MAX_ATTEMPT_CONNECTION 10

#define KEY_IDX_LEN     1
#define MAX_CMD_RESPONSE_LEN 255
#define MAX_CMD_LEN 255
#define WFL_READY_STR "READY"
#define WFL_OK_STR "AOK"
#define WFL_END_COMMAND_STR "<4.00>"
#define WFL_DELAY_START_CONNECTION 5000
#define WFL_FW_VER_LENGTH 6
#define WFL_READ_TIMEOUT 1000
#define WFL_COMMAND_GUARD_TIME 250
#define WFL_REBOOT_GUARD_TIME 1000

#define CMD_RESET "factory RESET"
#define CMD_REBOOT "reboot"
#define CMD_JOIN "join"
#define CMD_PHRASE "set wlan phrase"
#define CMD_ASSOCIATED_STR "Associated"
#define CMD_PROTOCOL "set ip protol"
#define CMD_IP_HOST "set ip host"
#define CMD_IP_REMOTE "set ip remote"
#define UDP_PROTOCOL_FLAG "1"

typedef enum {
    WFL_NO_SHIELD = 255,
    WFL_IDLE_STATUS = 0,
    WFL_NO_SSID_AVAIL,
    WFL_SCAN_COMPLETED,
    WFL_CONNECTED,
    WFL_CONNECT_FAILED,
    WFL_CONNECTION_LOST,
    WFL_DISCONNECTED
} wfl_status_t;

enum wfl_enc_type {
    ENC_TYPE_WEP  = 5,
    ENC_TYPE_TKIP = 2,
    ENC_TYPE_CCMP = 4,
    ENC_TYPE_NONE = 7,
    ENC_TYPE_AUTO = 8
};

#endif
