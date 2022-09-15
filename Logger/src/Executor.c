#include "Core.h"
#include "Executor.h"
#include "LED.h"

void Executor_Init(void)
{
    LED_Init();
}

bool Executor_Exec(void)
{
    return TRUE;
}