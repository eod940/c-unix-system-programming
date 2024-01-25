#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
main(){
    int fd; /*file descriptor*/
    int pid; /*process id*/
    char buf[10]; /*buffer to hold file data*/
    if((fd = open("a.txt", O_RDONLY)) < 0){
        printf("file open\n");;
        exit(1);
    }

    read(fd, buf, 10);
    printpos("Before fork", fd);
    if((pid = fork()) < 0){
        printf("fork error\n");
        exit(1);
    }
    else if(pid == 0) /*child*/{
        printpos("Child before read", fd);
        read(fd, buf, 10);
        printpos("Child after read", fd);
        sleep(2);
    }
    else /*parent*/{
        wait( (int *) 0 );
        printpos("Parent after wait", fd);
        read(fd, buf, 10);
        printpos("Parent 2nd after wait", fd);
    }
}
  printpos(string, filedes)
char *string;
int filedes;
{
    long pos, lseek();
    if((pos = lseek(filedes, 0L, 1)) < 0L)
        printf("error: lseek failed\n");
    printf("%s: %ld\n", string, pos);
}