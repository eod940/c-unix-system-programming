#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){
    int pd, n;
    char msg[] = "hello, FIFO";
    char msg1[] = "hello, FIFO1";
    printf("Server =====\n");

    if(mkfifo("./HAN-FIFO", 0666) == -1){
        perror("mkfifo");
        exit(1);
    }

    if((pd = open("./HAN-FIFO", O_WRONLY)) == -1){
        perror("open");
        exit(1);
    }

    printf("To Client : %s\n", msg);
    sleep(2);
    n = write(pd, msg, strlen(msg)+1);
    if (n==-1){
        perror("write");
        exit(1);
    }
    printf("To Client : %s\n", msg1);
    sleep(2);
    n = write(pd, msg1, strlen(msg1)+1);
    if (n==-1){
        perror("write");
        exit(1);
    }
    close(pd);

    return 0;
}
