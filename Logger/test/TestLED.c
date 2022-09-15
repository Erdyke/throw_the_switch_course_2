#include "Core.h"
#include "unity.h"
#include "Main.h"
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