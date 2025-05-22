#ifndef DEVICE_5
#define DEVICE_5

// Sound


#include "device_common.h"
#include <cstdint>

int play_note(uint32_t* frequency, uint16_t duration);

int stop_sound();

int say_phrase(device_payload* phrase);

int play_sweep(uint32_t* start_frequency, uint32_t* end_frequency, uint16_t* duration, uint8_t* attack,
        uint8_t* release, uint8_t* volume, uint8_t* modulation, uint8_t* modulation_rate, uint8_t* append);


#endif //DEVICE_5
