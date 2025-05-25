#ifndef DEVICE_COLOR_H
#define DEVICE_COLOR_H

// Color Sensor

#include "device_common.h"
#define DEVICE_ID_COLOR 4


void get_color_sensor_data(device_message msg, uint8_t *bank, const uint8_t *lighting, const uint8_t *format);

#endif // DEVICE_COLOR_H
