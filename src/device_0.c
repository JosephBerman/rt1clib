#include "device_0.h"

// TODO change to set_payload_one_param
//  COMMAND ID 0
void get_version(device_message msg, const uint8_t *board_type)
{
    msg[MESSAGE_BIT_DEVICE] = DEVICE_ID_0;
    msg[MESSAGE_BIT_CMD] = 0;
    msg[MESSAGE_BIT_ID] = 0;
    msg[MESSAGE_BIT_PAYLOAD_START] = board_type;
    crc_update(msg);
}

// COMMAND ID 1
// Will only keep the first 16 characters
void set_name(device_message msg, const char *name)
{
    set_payload_one_param(msg, DEVICE_ID_0, 1, 0, name, strlen(name));
    crc_update(msg);
}

// COMMAND ID 2
void get_name(device_message msg)
{
    set_empty_payload(msg, DEVICE_ID_0, 2, 0);
    crc_update(msg);
}

// COMMAND ID 3
void stop_and_reset(device_message msg)
{
    set_empty_payload(msg, DEVICE_ID_0, 3, 0);
    crc_update(msg);
}

// COMMAND ID 6
void disconnect(device_message msg)
{
    set_empty_payload(msg, DEVICE_ID_0, 6, 0);
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
    set_empty_payload(msg, DEVICE_ID_0, 11, 0);
    crc_update(msg);
}

// COMMAND ID 14
void get_enabled_events(device_message msg)
{
    set_empty_payload(msg, DEVICE_ID_0, 14, 0);
    crc_update(msg);
}

// COMMAND ID 15
void get_enabled_events(device_message msg)
{
    set_empty_payload(msg, DEVICE_ID_0, 15, 0);
    crc_update(msg);
}
