#include "device_sound.h"

//  COMMAND ID 0
void play_note(device_message msg,const uint32_t *frequency, const uint16_t *duration)
{
    const void *params[2] = {frequency, duration};
    const uint8_t params_len[2] = {sizeof(*frequency), sizeof(*duration)};
    set_payload_params(msg, DEVICE_ID_SOUND, 0, 0, params, params_len, 2);
    crc_update(msg);
}

// COMMAND ID 1
void stop_sound(device_message msg)
{
    set_empty_payload(msg, DEVICE_ID_SOUND, 1, 0);
    crc_update(msg);
}

//  COMMAND ID 4
void say_phrase(device_message msg,const  char *phrase)
{
    const void *params[1] = {phrase};
    const uint8_t params_len[1] = {strnlen(phrase, DEVICE_PAYLOAD_LENGTH)};
    set_payload_params(msg, DEVICE_ID_SOUND, 4, 0, params, params_len, 1);
    crc_update(msg);
}

// COMMAND ID 5
void play_sweep(device_message msg,
                const uint32_t *start_frequency,
                const uint32_t *end_frequency,
                const uint16_t *duration,
                const uint8_t *attack,
                const uint8_t *release,
                const uint8_t *volume,
                const uint8_t *modulation,
                const uint8_t *modulation_rate,
                const uint8_t *append)
{
    const void *params[9] = {
        start_frequency,
        end_frequency,
        duration,
        attack,
        release,
        volume,
        modulation,
        modulation_rate,
        append};
    const uint8_t params_len[9] = {sizeof(*start_frequency),
                                   sizeof(*end_frequency),
                                   sizeof(*duration),
                                   sizeof(*attack),
                                   sizeof(*release),
                                   sizeof(*volume),
                                   sizeof(*modulation),
                                   sizeof(*modulation_rate),
                                   sizeof(*append)};
    set_payload_params(msg, DEVICE_ID_SOUND, 5, 0, params, params_len, 9);
    crc_update(msg);
}
