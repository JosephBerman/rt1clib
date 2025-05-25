#include "device_battery.h"

//  COMMAND ID 1
void get_battery_level(device_message msg)
{
    set_empty_payload(msg, DEVICE_ID_SOUND, 1, 0);
    crc_update(msg);
}
