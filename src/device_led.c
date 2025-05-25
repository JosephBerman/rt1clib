#include "device_led.h"

//  COMMAND ID 2
void set_LED(device_message msg, uint8_t *state, const uint8_t *red, const uint8_t *green, const uint8_t *blue)
{
    const void *params[4] = {state, red, green, blue};
    const uint8_t params_len[4] = {sizeof(*state), sizeof(*red), sizeof(*green), sizeof(*blue)};
    set_payload_params(msg, DEVICE_ID_LED, 2, 0, params, params_len, 4);
    crc_update(msg);
}
