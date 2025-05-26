#include "device_common.h"
#include "device_general.h"
#include "unity.h"
#include <stdio.h>

void setUp(void)
{
}

void tearDown(void){

}
void test_get_enabled_events(void)
{
    device_message message;
    device_message actual = {0, 0x0B, 0, 0,0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x29};
    get_enabled_events(message);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(actual, message,20);

}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_get_enabled_events);
    return UNITY_END();

}
