#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int status;
    pid_t pid1, pid2;

    if((pid1 = fork()) < 0){
        /*fork failed*/
        perror("fork1");
        exit(1);
    }
    if (pid1 == 0){
        /*child1 process*/
        printf("--> Child1 process\n");
        sleep(3);
        exit(4);
    }

    if ((pid2 = fork()) == 0){
        /*child1 process*/
        printf("--> Child2 process\n");
        sleep(5);
        exit(5);
    }

    printf("--> Parent process\n");

    while(waitpid(pid2, &status, WNOHANG) == 0){
        printf("Parent still wait...\n");
        sleep(1);
    }

    printf("Child Exit Status : %d\n", status >> 8);

    return 0;
}