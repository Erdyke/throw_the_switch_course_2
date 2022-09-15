#include "Core.h"
#include "Main.h"
#include "Executor.h"

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
