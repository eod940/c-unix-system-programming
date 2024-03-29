#include <sys/types.h>
#include <sys/mman.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void handler(int dummy){
    ;
}

int main(void){
    key_t key;
    int shmid;
    void *shmaddr;
    char buf[1024];
    sigset_t mask;

    key = ftok("shmfile", 1);
    shmid = shmget(key, 1024, IPC_CREAT|0666);

    sigfillset(&mask);
    sigdelset(&mask, SIGUSR1);
    sigset(SIGUSR1, handler);

    printf("Listner wait for Talker\n");
    sigsuspend(&mask);

    printf("Listner start=========\n");
    shmaddr = shmat(shmid, NULL, 0);
    strcpy(buf, shmaddr);
    printf("Listener received : %s\n", buf);

    strcpy(shmaddr, "Have a nice day\n");
    sleep(3);
    shmdt(shmaddr);

    return 0;
}