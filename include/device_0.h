#ifndef DEVICE_0_H
#define DEVICE_0_H

// GENERAL

#include "device_common.h"

#define DEVICE_0_ID 0

#define BOARD_VERSION_MAIN 0xA5
#define BOARD_VERSION_COLOR 0xC6

//To robot
//COMAND ID 0
int get_version(device_message msg, const uint8_t* board_type);

int set_name(device_message msg, const char* name);

int get_name(device_message msg);

int stop_and_reset(device_message msg);

int disconnect(device_message msg);

//events 16 bytes
int enable_events(device_message msg, const char* events);

//events 16 bytes
int disable_events(device_message msg, const char* events);

int get_enabled_events(device_message msg);

int get_serial_number(device_message msg);

int get_sku(device_message msg);



#endif //DEVICE_0_H
