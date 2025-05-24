#ifndef DEVICE_1_H
#define DEVICE_1_H

#define DEVICE_ID_1 1

// MOTORS
#include "device_common.h"
#include <string.h>

// Max 100, Min -100 mm/s
void set_left_right_motor_speed(device_message msg, const int32_t *left_speed, const int32_t *right_speed);

void set_left_motor_speed(device_message msg, const int32_t *left_speed);

void set_right_motor_speed(device_message msg, const int32_t *right_speed);

// Units of MM
void drive_distance(device_message msg, const int32_t *distance);

void rotate_angle(device_message msg, const int32_t *angle);

void set_gravity_compensation(device_message msg, const uint8_t *active, const uint16_t *amount);

void reset_position(device_message msg);

void get_position(device_message msg);

void navigate_to_position(device_message msg, const int32_t *pos_x, const int32_t *pos_y, const uint8_t *heading);

void drive_arc(device_message msg, const int32_t *angle, const int32_t *radius);

#endif // DEVICE_1_H
