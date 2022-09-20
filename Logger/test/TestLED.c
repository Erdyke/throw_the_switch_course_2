#include "Core.h"
#include "unity.h"
#include "cmock.h"
#include "LPC1768.h"
#include "LED.h"

#define EXPECTED_LED_BITS (BIT_TO_MASK(18) | \
                           BIT_TO_MASK(20) | \
                           BIT_TO_MASK(21) | \
                           BIT_TO_MASK(23) )

extern uint32_t led_to_mask_table[NUM_LED];


void helperUpdatePin(void)
{
    //Apply pin state
    LPC_GPIO1->FIOPIN |=  LPC_GPIO1->FIOSET;
    LPC_GPIO1->FIOPIN &= ~LPC_GPIO1->FIOCLR;

    //Clear set/clr registers
    LPC_GPIO1->FIOSET = 0;
    LPC_GPIO1->FIOCLR = 0;
}


void test_led_init_turns_on_only_LEDs(void)
{
    LPC_GPIO1->FIODIR = 0;
    LPC_GPIO1->FIOSET = 0;

    LED_Init();

    TEST_ASSERT_EQUAL_HEX32(EXPECTED_LED_BITS, LPC_GPIO1->FIODIR);
    TEST_ASSERT_EQUAL_HEX32(EXPECTED_LED_BITS, LPC_GPIO1->FIOSET);
}


void test_LED_On_should_EnableTheCorrectOutput(void)
{
    char msg[100];

    for(LED_ID_T led_id = 0; led_id < NUM_LED; led_id++)
    {
        helperUpdatePin();
        LED_On(led_id);

        sprintf(msg, "LED id %d", led_id);
        TEST_ASSERT_EQUAL_HEX32_MESSAGE(led_to_mask_table[led_id], LPC_GPIO1->FIOSET, msg);
    }
}

void test_LED_Off_should_EnableTheCorrectOutput(void)
{
    char msg[100];

    for(LED_ID_T led_id = 0; led_id < NUM_LED; led_id++)
    {
        helperUpdatePin();
        LED_Off(led_id);

        sprintf(msg, "LED id %d", led_id);
        TEST_ASSERT_EQUAL_HEX32_MESSAGE(led_to_mask_table[led_id], LPC_GPIO1->FIOCLR, msg);
    }
}


void test_LED_Toggle_should_ToggleTheCorrectOutput(void)
{
    char set_msg[100];
    char clr_msg[100];

    LPC_GPIO1->FIOPIN = 0;
    LPC_GPIO1->FIOSET = 0;
    LPC_GPIO1->FIOCLR = 0;

    for(LED_ID_T led_id = 0; led_id < NUM_LED; led_id++)
    {
        uint32_t exp_pin_mask = led_to_mask_table[led_id];
        sprintf(set_msg, "LED SET id %d", led_id);
        sprintf(clr_msg, "LED CLR id %d", led_id);

        LED_Toggle(led_id);
        TEST_ASSERT_EQUAL_HEX32_MESSAGE(exp_pin_mask, LPC_GPIO1->FIOSET, set_msg);
        helperUpdatePin();

        LED_Toggle(led_id);
        TEST_ASSERT_EQUAL_HEX32_MESSAGE(exp_pin_mask, LPC_GPIO1->FIOCLR, clr_msg);
        helperUpdatePin();
    }
}