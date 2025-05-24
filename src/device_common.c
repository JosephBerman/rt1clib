#include "device_common.h"

void set_payload_one_param(device_message msg,
                           const uint8_t *message_device,
                           const uint8_t *message_cmd,
                           const uint8_t *message_id,
                           const void *param,
                           const uint8_t param_len)
{

    set_empty_payload(msg, message_device, message_cmd, message_id);
    _clear_payload(msg);

    if (param_len > DEVICE_PAYLOAD_LENGTH)
    {
        // TODO Error handling
        return;
    }

    // msg[3 : param_len or maximum payload length, which ever is smallest]
    memcpy(&msg[MESSAGE_BIT_PAYLOAD_START], param, param_len);
}

void set_payload_two_param(device_message msg,
                           const uint8_t *message_device,
                           const uint8_t *message_cmd,
                           const uint8_t *message_id,
                           const void *param1,
                           const uint8_t param1_len,
                           const void *param2,
                           const uint8_t param2_len)
{

    set_empty_payload(msg, message_device, message_cmd, message_id);
    // clear payload
    _clear_payload(msg);

    if ((param1_len + param2_len) > DEVICE_PAYLOAD_LENGTH)
    {
        // TODO Error handling
        return;
    }

    // msg[3: param1_len - 1]
    memcpy(&msg[MESSAGE_BIT_PAYLOAD_START], param1, param1_len);
    // msg[param1_len : param1_len + param2_len -1 ]
    memcpy(&msg[MESSAGE_BIT_PAYLOAD_START + param1_len], param2, param2_len);
}

void set_payload_three_param(device_message msg,
                             const uint8_t *message_device,
                             const uint8_t *message_cmd,
                             const uint8_t *message_id,
                             const void *param1,
                             const uint8_t param1_len,
                             const void *param2,
                             const uint8_t param2_len,
                             const void *param3,
                             const uint8_t param3_len)
{

    set_empty_payload(msg, message_device, message_cmd, message_id);
    _clear_payload(msg);

    if ((param1_len + param2_len + param3_len) > DEVICE_PAYLOAD_LENGTH)
    {
        // TODO Error handling
        return;
    }

    // msg[3: param1_len - 1]
    memcpy(&msg[MESSAGE_BIT_PAYLOAD_START], param1, param1_len);
    // msg[param1_len : param1_len + param2_len -1 ]
    memcpy(&msg[MESSAGE_BIT_PAYLOAD_START + param1_len], param2, param2_len);
    // msg[sizeof(param1_len + param2_len) : param1_len + param2_len + param3_len - 1]
    memcpy(&msg[MESSAGE_BIT_PAYLOAD_START + param1_len + param2_len], param3, param3_len);
}
