#include "device_color.h"

//  COMMAND ID 1
void get_color_sensor_data(device_message msg, uint8_t *bank, const uint8_t *lighting, const uint8_t *format)
{
    const void *params[3] = {bank, lighting, format};
    const uint8_t params_len[3] = {sizeof(*bank), sizeof(*lighting), sizeof(*format)};
    set_payload_params(msg, DEVICE_ID_COLOR, 1, 0, params, params_len, 3);
    crc_update(msg);
}
