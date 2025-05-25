#ifndef DEVICE_GENERAL_H
#define DEVICE_GENERAL_H

// GENERAL

#include "device_common.h"

#define DEVICE_ID_GENERAL 0

#define BOARD_VERSION_MAIN 0xA5
#define BOARD_VERSION_COLOR 0xC6

// To robot
// COMAND ID 0
void get_version(device_message msg, const uint8_t *board_type);

void set_name(device_message msg, const char *name);

void get_name(device_message msg);

void stop_and_reset(device_message msg);

void disconnect(device_message msg);

// events 16 bytes
void enable_events(device_message msg, const char *events);

// events 16 bytes
void disable_events(device_message msg, const char *events);

void get_enabled_events(device_message msg);

void get_serial_number(device_message msg);

void get_sku(device_message msg);

#endif // DEVICE_GENERAL_H
