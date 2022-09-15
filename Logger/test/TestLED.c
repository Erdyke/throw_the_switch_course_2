#include "Core.h"
#include "unity.h"
#include "cmock.h"
#include "LPC1768.h"
#include "LED.h"

#define EXPECTED_LED_BITS (BIT_TO_MASK(18) | \
                           BIT_TO_MASK(20) | \
                           BIT_TO_MASK(21) | \
                           BIT_TO_MASK(23) )

void test_led_init_turns_on_only_LEDs(void)
{
    LPC_GPIO1->FIODIR = 0;
    LPC_GPIO1->FIOSET = 0;

    LED_Init();

    TEST_ASSERT_EQUAL_HEX32(EXPECTED_LED_BITS, LPC_GPIO1->FIODIR);
    TEST_ASSERT_EQUAL_HEX32(EXPECTED_LED_BITS, LPC_GPIO1->FIOSET);
}


void test_LED_Toggle_should_ToggleTheCorrectOutput(void)
{
    TEST_IGNORE_MESSAGE("Implement LED_Toggle");
}

void test_LED_On_should_EnableTheCorrectOutput(void)
{
    TEST_IGNORE_MESSAGE("Implement me");
}

void test_LED_Off_should_DisableTheCorrectOutput(void)
{
    TEST_IGNORE_MESSAGE("Implement me");
}