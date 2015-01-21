#include <stdio.h>
#include <stdlib.h>

void at_exit_1()
{
    printf("First at exit function\n");
}

void at_exit_2()
{
    printf("Second at exit function\n");
}


int main(void)
{
    if(atexit(at_exit_2) != 0)
    {
        perror("atexit");
    }
    if(atexit(at_exit_1) != 0)
    {
        perror("atexit");
    }
    if(atexit(at_exit_1) != 0)
    {
        perror("atexit");
    }
    return 0;
}