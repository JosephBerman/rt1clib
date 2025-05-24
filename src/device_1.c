#include "device_1.h"
#include <device_0.h>

// COMMAND ID 4
void set_left_right_motor_speed(device_message msg, const int32_t *left_speed, const int32_t *right_speed)
{
    set_payload_two_param(msg, DEVICE_ID_1, 4, 0, left_speed, right_speed);
    crc_update(msg);
}

// COMMAND ID 6
void set_left_motor_speed(device_message msg, const int32_t *left_speed)
{
    set_payload_one_param(msg, DEVICE_ID_1, 6, 0, left_speed);
    crc_update(msg);
}

// COMMAND ID 7
void set_right_motor_speed(device_message msg, const int32_t *right_speed)
{
    set_payload_one_param(msg, DEVICE_ID_1, 7, 0, right_speed);
    crc_update(msg);
}

// COMMAND ID 8
void drive_distance(device_message msg, const int32_t *distance)
{
    set_payload_one_param(msg, DEVICE_ID_1, 8, 0, distance);
    crc_update(msg);
}

// COMMAND ID 12
void rotate_angle(device_message msg, const int32_t *distance)
{
    set_payload_one_param(msg, DEVICE_ID_1, 12, 0, distance);
    crc_update(msg);
}

// COMMAND ID 13
void set_gravity_compensation(device_message msg, const uint8_t *active, const uint16_t *amount)
{
    set_payload_two_param(msg, DEVICE_ID_1, 13, 0, active, amount);
    crc_update(msg);
}

// COMMAND ID 15
void reset_position(device_message msg)
{
    set_empty_payload(msg, DEVICE_ID_1, 15, 0);
    crc_update(msg);
}

// COMMAND ID 16
void get_position(device_message msg)
{
    set_empty_payload(msg, DEVICE_ID_1, 16, 0);
    crc_update(msg);
}
