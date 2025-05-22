#ifndef DEVICE_1
#define DEVICE_1

// MOTORS
#include "device_common.h"
#include <stdint.h>

// Max 100, Min -100 mm/s
int set_right_left_motor_speed(int* left_speed, int* right_speed);

int set_left_motor_speed(int* left_speed);

int set_right_motor_speed(int* right_speed);

//Units of MM
int drive_distance(int* distance);

int rotate_angle(int* angle);

int set_gravity_compensation(uint8_t* active, uint16_t* amount);

int reset_position();

int get_position();

int navigate_to_position(int* pos_x, int* pos_y, uint8_t * heading);

int drive_arc(int* angle, int* radius);



#endif //DEVICE_1
