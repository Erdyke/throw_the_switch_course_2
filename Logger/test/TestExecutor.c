#include "unity.h"
#include "MockLED.h"
#include "MockDigital.h"
#include "Executor.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Executor_Init_should_InitializeAllSubsystems(void)
{
    LED_Init_Expect();
    Digital_Init_Expect();

    Executor_Init();
}

void test_Executor_Exec_should_AlwaysReturnTrue(void)
{
    Digital_GetBits_IgnoreAndReturn(0);
    LED_Off_Ignore();
    TEST_ASSERT_TRUE( Executor_Exec() );
    TEST_ASSERT_TRUE( Executor_Exec() );
    TEST_ASSERT_TRUE( Executor_Exec() );
    TEST_ASSERT_TRUE( Executor_Exec() );
    TEST_ASSERT_TRUE( Executor_Exec() );
}

void test_Executor_Exec_should_ToggleLED0_when_Digita0or1isHigh(void)
{
    Digital_GetBits_ExpectAndReturn(0x01);
    LED_Toggle_Expect(LED0);
    LED_Off_Expect(LED1);
    LED_Off_Expect(LED2);
    Executor_Exec();

    Digital_GetBits_ExpectAndReturn(0x02);
    LED_Toggle_Expect(LED0);
    LED_Off_Expect(LED1);
    LED_Off_Expect(LED2);
    Executor_Exec();
}

void test_Executor_Exec_should_ToggleLED1_when_Digita2or3isHigh(void)
{
    Digital_GetBits_ExpectAndReturn(0x04);
    LED_Off_Expect(LED0);
    LED_Toggle_Expect(LED1);
    LED_Off_Expect(LED2);
    Executor_Exec();

    Digital_GetBits_ExpectAndReturn(0x08);
    LED_Off_Expect(LED0);
    LED_Toggle_Expect(LED1);
    LED_Off_Expect(LED2);
    Executor_Exec();
}

void test_Executor_Exec_should_ToggleLED2_when_Digita4or5isHigh(void)
{
    Digital_GetBits_ExpectAndReturn(0x10);
    LED_Off_Expect(LED0);
    LED_Off_Expect(LED1);
    LED_Toggle_Expect(LED2);
    Executor_Exec();

    Digital_GetBits_ExpectAndReturn(0x20);
    LED_Off_Expect(LED0);
    LED_Off_Expect(LED1);
    LED_Toggle_Expect(LED2);
    Executor_Exec();
}

void test_Executor_Exec_should_not_Toggle_Any_LED0_when_Digital0and1areLow(void)
{
    Digital_GetBits_ExpectAndReturn(0x00);
    LED_Off_Expect(LED0);
    LED_Off_Expect(LED1);
    LED_Off_Expect(LED2);
    Executor_Exec();
}