#include "device_common.h"

void set_payload_one_param(device_message msg,
                           const uint8_t *message_device,
                           const uint8_t *message_cmd,
                           const uint8_t *message_id,
                           const void *param)
{

    msg[MESSAGE_BIT_DEVICE] = message_device;
    msg[MESSAGE_BIT_CMD] = message_cmd;
    msg[MESSAGE_BIT_ID] = message_id;

    // clear payload
    memset(&msg[MESSAGE_BIT_PAYLOAD_START], 0,
           ((sizeof(*param) < DEVICE_PAYLOAD_LENGTH) ? sizeof(*param) : DEVICE_PAYLOAD_LENGTH));

    // msg[3 : siezof(*param) or maximum payload length, which ever is smallest]
    memcpy(&msg[MESSAGE_BIT_PAYLOAD_START], param,
           ((sizeof(*param) < DEVICE_PAYLOAD_LENGTH) ? sizeof(*param) : DEVICE_PAYLOAD_LENGTH));
}

void set_payload_two_param(device_message msg,
                           const uint8_t *message_device,
                           const uint8_t *message_cmd,
                           const uint8_t *message_id,
                           const void *param1,
                           const void *param2)
{

    msg[MESSAGE_BIT_DEVICE] = message_device;
    msg[MESSAGE_BIT_CMD] = message_cmd;
    msg[MESSAGE_BIT_ID] = message_id;

    // clear payload
    memset(&msg[MESSAGE_BIT_PAYLOAD_START], 0,
           ((sizeof(*param1) + sizeof(*param2)) < DEVICE_PAYLOAD_LENGTH)
               ? sizeof(*param1) + sizeof(*param2)
               : DEVICE_PAYLOAD_LENGTH);

    // msg[3: sizeof(param1) - 1]
    memcpy(&msg[MESSAGE_BIT_PAYLOAD_START], param1, sizeof(*param1));
    // msg[sizeof(param1) : sizeof(param1) + sizeof(param2) -1 ]
    memcpy(&msg[MESSAGE_BIT_PAYLOAD_START + sizeof(*param1)], param2, sizeof(*param2));
}
