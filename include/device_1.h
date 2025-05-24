#ifndef DEVICE_1_H
#define DEVICE_1_H

// MOTORS
#include "device_common.h"

// Max 100, Min -100 mm/s
void set_right_left_motor_speed(const int* left_speed, const int* right_speed);

void set_left_motor_speed(const int* left_speed);

void set_right_motor_speed(const int* right_speed);

//Units of MM
void drive_distance(const int* distance);

void rotate_angle(const int* angle);

void set_gravity_compensation(const uint8_t* active, const  uint16_t* amount);

void reset_position();

void get_position();

void navigate_to_position(const int* pos_x, const int* pos_y, const uint8_t * heading);

void drive_arc(const int* angle, const int* radius);



#endif //DEVICE_1_H
