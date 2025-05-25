#include "device_marker.h"

//  COMMAND ID 0
void set_marker_eraser_position(device_message msg, const uint8_t position)
{
    const void *params[1] = {position};
    const uint8_t params_len[1] = {sizeof(position)};
    set_payload_params(msg, DEVICE_ID_MARKER, 0, 0, params, params_len, 1);
    crc_update(msg);
}
