#include "device_accelerometer.h"

//  COMMAND ID 1
void get_accelerometer(device_message msg)
{
    set_empty_payload(msg, DEVICE_ID_ACCELEROMETER, 1, 0);
    crc_update(msg);
}
