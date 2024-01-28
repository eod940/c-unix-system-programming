#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

int main(void){
    printf("Before SIGCONT Signal top parant.\n");

    kill(getppid(), SIGCONT);

    printf("Before SIGQUIT Signal to me.\n");

    kill(getpid(), SIGQUIT);

    printf("After SIQUIT Signal.\n");

    return 0;
}