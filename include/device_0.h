#ifndef DEVICE_0
#define DEVICE_0

// GENERAL

#include "device_common.h"

#define BOARD_VERSION_MAIN 0xA5
#define BOARD_VERSION_COLOR 0xC6

//To robot
int get_version(char* board_type);

int set_name(char* name);

int get_name();

int stop_and_reset();

int disconnect();

//events  16 bytes
int enable_events(char* events);

//events 16 bytes
int disable_events(char* events);

int get_enabled_events();

int get_serial_number();

int get_sku();



#endif //DEVICE_0
