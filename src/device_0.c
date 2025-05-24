#include "device_0.h"



// COMAND ID 0
void get_version(device_message msg, const uint8_t *board_type)
{
    msg[MESSAGE_BIT_DEVICE] = DEVICE_0_ID;
    msg[MESSAGE_BIT_CMD] = 0;
    msg[MESSAGE_BIT_ID] = 0;
    msg[MESSAGE_BIT_PAYLOAD_START] = board_type;
    crc_update(msg);
}

// COMMAND ID 1
// Will only keep the first 16 characters
void set_name(device_message msg, const char* name)
{

    msg[MESSAGE_BIT_DEVICE] = DEVICE_0_ID;
    msg[MESSAGE_BIT_CMD] = 1;
    msg[MESSAGE_BIT_ID] = 0;

    for (int i = 0; i < ((sizeof(name) < DEVICE_PAYLOAD_LENGTH)? sizeof(name) - 1 : DEVICE_PAYLOAD_LENGTH); i++)
    {
        msg[MESSAGE_BIT_ID + i] = name[i];
    }

    crc_update(msg);
}

// COMMAND ID 2
void get_name(device_message msg)
{
    msg[MESSAGE_BIT_DEVICE] = DEVICE_0_ID;
    msg[MESSAGE_BIT_CMD] = 2;
    msg[MESSAGE_BIT_ID] = 0;

    crc_update(msg);
}


// COMMAND ID 3
void stop_and_reset(device_message msg)
{
    msg[MESSAGE_BIT_DEVICE] = DEVICE_0_ID;
    msg[MESSAGE_BIT_CMD] = 3;
    msg[MESSAGE_BIT_ID] = 0;

    crc_update(msg);
}

// COMMAND ID 6
void disconnect(device_message msg)
{
    msg[MESSAGE_BIT_DEVICE] = DEVICE_0_ID;
    msg[MESSAGE_BIT_CMD] = 6;
    msg[MESSAGE_BIT_ID] = 0;

    crc_update(msg);
}

void enable_events(device_message msg, const char* events)
{

}

//events 16 bytes
void disable_events(device_message msg, const char* events)
{

}



// COMMAND ID 11
void get_enabled_events(device_message msg)
{

    msg[MESSAGE_BIT_DEVICE] = DEVICE_0_ID;
    msg[MESSAGE_BIT_CMD] = 6;
    msg[MESSAGE_BIT_ID] = 0;

    crc_update(msg);
}
