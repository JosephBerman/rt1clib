#ifndef DEVICE_SOUND_H
#define DEVICE_SOUND_H

// Sound

#include "device_common.h"

#define DEVICE_ID_SOUND 5

void play_note(device_message msg, const uint32_t *frequency, const uint16_t* duration);

void stop_sound(device_message msg);

void say_phrase(device_message msg, const char *phrase);

void play_sweep(device_message msg,
                const uint32_t *start_frequency,
                const uint32_t *end_frequency,
                const uint16_t *duration,
                const uint8_t *attack,
                const uint8_t *release,
                const uint8_t *volume,
                const uint8_t *modulation,
                const uint8_t *modulation_rate,
                const uint8_t *append);

#endif // DEVICE_SOUND_H
