#include "Core.h"
#include "unity.h"
#include "Main.h"
#include "MockExecutor.h"
#include "cmock.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Main_should_init_drivers(void)
{
    Executor_Init_Expect();

    Executor_Exec_ExpectAndReturn(TRUE);
    Executor_Exec_ExpectAndReturn(TRUE);
    Executor_Exec_ExpectAndReturn(FALSE);

    TEST_ASSERT_EQUAL(0, TestableMain());
}

