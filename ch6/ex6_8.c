#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int status;
    pid_t pid;
    switch (pid = fork()){
        case -1 : /*fork failed*/
            perror("fork");
            exit(1);
            break;
        case 0 : /*child process*/
            printf("--> Child Process\n");
            sleep(3); // wait for 3 seconds
            exit(4);
            break;
        default : /*parent process*/
            while (wait(&status) != pid)
                continue;
            printf("--> Parent process\n");
            printf("Status: %d, %x\n", status, status);
            printf("Child process Exit Status:%d\n", status >> 8); // shift 8bits
            break;
    }

    return 0;
}