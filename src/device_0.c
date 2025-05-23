#include "device_0.h"



//COMAND ID 0
int get_version(device_message message, const uint8_t *board_type)
{
    message[0] = DEVICE_0_ID;
    message[1] = 0;
    message[2] = 0;
    message[3] = board_type;
    crc_update(message);
}
