#include "device_motor.h"

// COMMAND ID 4
void set_left_right_motor_speed(device_message msg, const int32_t *left_speed, const int32_t *right_speed)
{
    const void *params[2] = {left_speed, right_speed};
    const uint8_t params_len[2] = {sizeof(*left_speed), sizeof(*right_speed)};
    set_payload_params(msg, DEVICE_ID_MOTOR, 4, 0, params, params_len, 2);

    crc_update(msg);
}

// COMMAND ID 6
void set_left_motor_speed(device_message msg, const int32_t *left_speed)
{
    const void *params[1] = {left_speed};
    const uint8_t params_len[1] = {sizeof(*left_speed)};
    set_payload_params(msg, DEVICE_ID_MOTOR, 6, 0, params, params_len, 1);
    crc_update(msg);
}

// COMMAND ID 7
void set_right_motor_speed(device_message msg, const int32_t *right_speed)
{
    const void *params[1] = {right_speed};
    const uint8_t params_len[1] = {sizeof(*right_speed)};
    set_payload_params(msg, DEVICE_ID_MOTOR, 7, 0, params, params_len, 1);
    crc_update(msg);
}

// COMMAND ID 8
void drive_distance(device_message msg, const int32_t *distance)
{
    const void *params[1] = {distance};
    const uint8_t params_len[1] = {sizeof(*distance)};
    set_payload_params(msg, DEVICE_ID_MOTOR, 8, 0, params, params_len, 1);
    crc_update(msg);
}

// COMMAND ID 12
void rotate_angle(device_message msg, const int32_t *angle)
{
    const void *params[1] = {angle};
    const uint8_t params_len[1] = {sizeof(*angle)};
    set_payload_params(msg, DEVICE_ID_MOTOR, 12, 0, params, params_len, 1);
    crc_update(msg);
}

// COMMAND ID 13
void set_gravity_compensation(device_message msg, const uint8_t *active, const uint16_t *amount)
{
    const void *params[2] = {active, amount};
    const uint8_t params_len[2] = {sizeof(*active), sizeof(*amount)};
    set_payload_params(msg, DEVICE_ID_MOTOR, 13, 0, params, params_len, 2);
    crc_update(msg);
}

// COMMAND ID 15
void reset_position(device_message msg)
{
    set_empty_payload(msg, DEVICE_ID_MOTOR, 15, 0);
    crc_update(msg);
}

// COMMAND ID 16
void get_position(device_message msg)
{
    set_empty_payload(msg, DEVICE_ID_MOTOR, 16, 0);
    crc_update(msg);
}

// COMMAND ID 17
void navigate_to_position(device_message msg, const int32_t *pos_x, const int32_t *pos_y, const uint8_t *heading)
{
    const void *params[3] = {pos_x, pos_y, heading};
    const uint8_t params_len[3] = {sizeof(*pos_x), sizeof(*pos_y), sizeof(*heading)};
    set_payload_params(msg, DEVICE_ID_MOTOR, 17, 0, params, params_len, 3);
    crc_update(msg);
}

// COMMAND 27
void drive_arc(device_message msg, const int32_t *angle, const int32_t *radius)
{
    const void *params[2] = {angle, radius};
    const uint8_t params_len[2] = {sizeof(*angle), sizeof(*radius)};
    set_payload_params(msg, DEVICE_ID_MOTOR, 27, 0, params, params_len, 2);
    crc_update(msg);
}
