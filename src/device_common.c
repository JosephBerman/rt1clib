#include "device_common.h"


void set_payload_params(device_message msg,
                           const uint8_t message_device,
                           const uint8_t message_cmd,
                           const uint8_t message_id,
                           const void **params,
                           const uint8_t *params_lens,
                           const uint8_t num_params)
{

    set_empty_payload(msg, message_device, message_cmd, message_id);

    // TODO fix overflow vulnerability here if total length rolls over 255 it will be less than payload length
    uint8_t total_len = 0;
    for (uint8_t i = 0; i < num_params; i++){
        total_len += params_lens[i];
    }

    if (total_len > DEVICE_PAYLOAD_LENGTH)
    {
        // TODO Error handling
        return;
    }

    uint8_t offset = MESSAGE_BIT_PAYLOAD_START;
    for (uint8_t i = 0; i < num_params ; i++)
    {
        memcpy(&msg[offset], params[i], params_lens[i]);
        offset  += params_lens[i];
    }
}
