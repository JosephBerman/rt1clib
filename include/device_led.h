#ifndef DEVICE_LED_H
#define DEVICE_LED_H

// LEDs

#include "device_common.h"
#define DEVICE_ID_LED 3

void set_LED(device_message msg, uint8_t *state, const uint8_t *red, const uint8_t *green, const uint8_t *blue);

#endif // DEVICE_LED_H
