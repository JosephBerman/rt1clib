#include "device_common.h"
#include "device_motor.h"
#include "unity.h"

device_message message;

void setUp(void)
{
    memset(message, 0, DEVICE_MESSAGE_LENGTH);
}

void tearDown(void)
{
}

void test_set_left_right_motor_speed(void)
{
    int left;
    left = 0x64000000;
    int right;
    right = 0x64000000;
    device_message message;
    device_message actual = {0x01, 0x04, 0x00, 0x00, 0x00, 0x00, 0x64, 0x00, 0x00, 0x00, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD1};
    set_left_right_motor_speed(message, &left, &right);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(actual, message, 20);
}
int main()
{
}
