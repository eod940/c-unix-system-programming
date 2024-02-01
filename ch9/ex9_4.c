#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
    int fd[2];
    pid_t pid;

    if(pipe(fd) == -1){ //create pipe
        perror("pipe");
        exit(1);
    }

    switch(pid = fork()){
        case -1:
            perror("fork");
            exit(1);
            break;
        case 0: //child
            close(fd[1]); // only read
            if(fd[0] != 0){
                dup2(fd[0], 0);
                close(fd[0]);
            }
            execlp("grep", "grep", "root", (char *)NULL);
            exit(1);
            break;
        default:
            close(fd[0]);
            if(fd[1] != 1){
                dup2(fd[1], 1);
                close(fd[1]);
            }
            execlp("ps", "ps", "-ef", (char *)NULL);
            wait(NULL);
            break;
    }

    return 0;
}