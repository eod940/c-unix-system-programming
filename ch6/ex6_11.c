#include <stdlib.h>
#include <stdio.h>
main()
{
    int child;
    if((child = fork()) == 0)
    {
        printf("Child: child PID %d\n", getpid());
        pause(); // While do pause before input any sign
    }
    /*parent*/
    printf("Parent: child PID %d\n", child);
    exit(child);
}
