#ifndef DEVICE_COMMON_H
#define DEVICE_COMMON_H

#include <stdint.h>

#define DEVICE_MESSAGE_LENGTH 20
#define DEVICE_PAYLOAD_LENGTH 16
#define MESSAGE_ID_POSITION 2
#define CRC_BIT_POS 19

typedef uint8_t device_message[DEVICE_MESSAGE_LENGTH];

static inline void init_device_message(device_message msg){
    memset(msg, 0, DEVICE_MESSAGE_LENGTH);
}

// CRC check
static inline uint8_t _crc_update(const device_message msg) {

    uint8_t crc = 0;

    for (uint8_t i = 0; i < DEVICE_MESSAGE_LENGTH - 1; i++) {
            uint8_t c = msg[i];
            for (uint8_t j = 0x80; j != 0; j >>= 1) {
                uint8_t bit = crc & 0x80;
                if (c & j) {
                    bit = !bit;
                }
                crc <<= 1;
                if (bit) {
                    crc ^= 0x07;
                }
            }
        }
    return crc;
}

static inline void crc_update(device_message msg){
    msg[CRC_BIT_POS] = _crc_update(msg);
}


// Keeping this in here incase there is a use case in the future where the crc does NOT want to be updated.
static inline void _set_message_id(device_message msg, uint8_t ID){
    msg[MESSAGE_ID_POSITION] = ID;
}


static inline void set_message_id_and_crc_update(device_message msg, uint8_t ID){
    msg[MESSAGE_ID_POSITION] = ID;
    msg[CRC_BIT_POS] = _crc_update(msg);
}




typedef uint8_t device_payload[DEVICE_PAYLOAD_LENGTH];



#endif // DEVICE_COMMON_H
