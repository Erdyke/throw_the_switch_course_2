#include "unity.h"
#include "LPC1768.h"
#include "Digital.h"
#include "Utils.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Digital_Init(void)
{
    LPC_GPIO2->FIOMASK   = 0xFFFFFFFF;
    LPC_GPIO2->FIODIR    = 0xFFFFFFFF;
    LPC_PINCON->PINSEL4  = 0xFFFFFFFF;
    LPC_PINCON->PINMODE4 = 0x00000000;

    Digital_Init();

    TEST_ASSERT_EQUAL_HEX(0xFFFFFFC0, LPC_GPIO2->FIOMASK);
    TEST_ASSERT_EQUAL_HEX(0xFFFFFFC0, LPC_GPIO2->FIODIR);
    TEST_ASSERT_EQUAL_HEX(0xFFFFF000, LPC_PINCON->PINSEL4);
    TEST_ASSERT_EQUAL_HEX(0x00000FFF, LPC_PINCON->PINMODE4);
}

void test_Digital_GetBits_should_ReadDigitalInputsAndReturnCurrentValues(void)
{
    LPC_GPIO2->FIOPIN = 0;
    TEST_ASSERT_EQUAL_HEX(0, Digital_GetBits());

    LPC_GPIO2->FIOPIN = 0x1;
    TEST_ASSERT_EQUAL_HEX(1, Digital_GetBits());

    LPC_GPIO2->FIOPIN = 0xFFFFFFFF;
    TEST_ASSERT_EQUAL_HEX(MASK_RANGE(0, 5), Digital_GetBits());
}
