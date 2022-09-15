#include "Core.h"
#include "Executor.h"
#include "LED.h"
#include "Main.h"

#ifndef TEST
int main(void)
#else
int TestableMain(void)
#endif
{
    Executor_Init();
    while(Executor_Exec()){};
    return 0;
}