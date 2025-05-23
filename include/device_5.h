#ifndef DEVICE_5_H
#define DEVICE_5_H

// Sound


#include "device_common.h"

int play_note(const uint32_t* frequency, const  uint16_t duration);

int stop_sound();

int say_phrase(device_payload* phrase);

int play_sweep(const uint32_t* start_frequency,
        const uint32_t* end_frequency,
        const uint16_t* duration,
        const uint8_t* attack,
        const uint8_t* release,
        const uint8_t* volume,
        const uint8_t* modulation,
        const uint8_t* modulation_rate,
        const  uint8_t* append);


#endif //DEVICE_5_H
