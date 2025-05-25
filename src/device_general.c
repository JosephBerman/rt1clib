#include "device_general.h"

//  COMMAND ID 0
void get_version(device_message msg, const uint8_t board_type)
{
    const void* params[1] = {board_type};
    const uint8_t params_len[1] = {sizeof(board_type)};
    set_payload_params(msg, DEVICE_ID_GENERAL,0,0, params, params_len, 1);
    crc_update(msg);
}

// COMMAND ID 1
// Will only keep the first 16 characters
void set_name(device_message msg, const char *name)
{
    const void* params[1] = {name};
    const uint8_t params_len[1] = {strlen(name)};
    set_payload_params(msg, DEVICE_ID_GENERAL, 1, 0, params, params_len,1);
    crc_update(msg);
}

// COMMAND ID 2
void get_name(device_message msg)
{
    set_empty_payload(msg, DEVICE_ID_GENERAL, 2, 0);
    crc_update(msg);
}

// COMMAND ID 3
void stop_and_reset(device_message msg)
{
    set_empty_payload(msg, DEVICE_ID_GENERAL, 3, 0);
    crc_update(msg);
}

// COMMAND ID 6
void disconnect(device_message msg)
{
    set_empty_payload(msg, DEVICE_ID_GENERAL, 6, 0);
    crc_update(msg);
}
// COMMAND ID 7
void enable_events(device_message msg, const char *events)
{
}

// events 16 bytes
//  COMMAND ID 9
void disable_events(device_message msg, const char *events)
{
}

// COMMAND ID 11
void get_enabled_events(device_message msg)
{
    set_empty_payload(msg, DEVICE_ID_GENERAL, 11, 0);
    crc_update(msg);
}

// COMMAND ID 14
void get_enabled_events(device_message msg)
{
    set_empty_payload(msg, DEVICE_ID_GENERAL, 14, 0);
    crc_update(msg);
}

// COMMAND ID 15
void get_enabled_events(device_message msg)
{
    set_empty_payload(msg, DEVICE_ID_GENERAL, 15, 0);
    crc_update(msg);
}
