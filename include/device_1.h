#ifndef DEVICE_1_H
#define DEVICE_1_H

// MOTORS
#include "device_common.h"

// Max 100, Min -100 mm/s
int set_right_left_motor_speed(const int* left_speed, const int* right_speed);

int set_left_motor_speed(const int* left_speed);

int set_right_motor_speed(const int* right_speed);

//Units of MM
int drive_distance(const int* distance);

int rotate_angle(const int* angle);

int set_gravity_compensation(const uint8_t* active, const  uint16_t* amount);

int reset_position();

int get_position();

int navigate_to_position(const int* pos_x, const int* pos_y, const uint8_t * heading);

int drive_arc(const int* angle, const int* radius);



#endif //DEVICE_1_H
