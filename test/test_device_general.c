#include "device_common.h"
#include "device_general.h"
#include "unity.h"

device_message message;

void setUp(void)
{
    memset(message, 0, DEVICE_MESSAGE_LENGTH);
}

void tearDown(void)
{
}

void test_get_version_main(void)
{
    uint8_t version = BOARD_VERSION_MAIN;

    device_message actual = {0, 0, 0, version, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x4D};
    get_version(message, &version);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(actual, message, 20);
}

void test_get_version_color(void)
{
    uint8_t version = BOARD_VERSION_COLOR;

    device_message actual = {0, 0, 0, version, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x8B};
    get_version(message, &version);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(actual, message, 20);
}

void test_get_enabled_events(void)
{
    device_message actual = {0, 0x0B, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x29};
    get_enabled_events(message);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(actual, message, 20);
}

void test_set_name_empty(void)
{
    const char *name = "";
    device_message actual = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x2A};
    set_name(message, name);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(actual, message, 20);
}

void test_set_name_basic(void)
{
    const char *name = "test";
    device_message actual = {0, 1, 0, 0x74, 0x65, 0x73, 0x74, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x81};
    set_name(message, name);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(actual, message, 20);
}

void test_set_name_max(void)
{
    const char *name = "123456789abcdefg";
    device_message actual = {
        0,
        1,
        0,
        0x31,
        0x32,
        0x33,
        0x34,
        0x35,
        0x36,
        0x37,
        0x38,
        0x39,
        0x61,
        0x62,
        0x63,
        0x64,
        0x65,
        0x66,
        0x67,
        0x7D};
    set_name(message, name);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(actual, message, 20);
}

void test_set_name_over(void)
{
    const char *name = "123456789abcdefghijklmn";
    device_message actual = {
        0,
        1,
        0,
        0x31,
        0x32,
        0x33,
        0x34,
        0x35,
        0x36,
        0x37,
        0x38,
        0x39,
        0x61,
        0x62,
        0x63,
        0x64,
        0x65,
        0x66,
        0x67,
        0x7d};
    set_name(message, name);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(actual, message, 20);
}

int main()
{
    UNITY_BEGIN();

    // COMMAND 0
    RUN_TEST(test_get_version_main);
    RUN_TEST(test_get_version_color);

    // COMMAND 1
    RUN_TEST(test_set_name_basic);
    RUN_TEST(test_set_name_empty);
    RUN_TEST(test_set_name_max);
    RUN_TEST(test_set_name_over);

    // COMMAND 11
    RUN_TEST(test_get_enabled_events);

    return UNITY_END();
}
