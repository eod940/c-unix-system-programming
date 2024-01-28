#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ntimes=0;
main()
{
int pid, ppid;
int p_action(), c_action();
signal(SIGUSR1, p_action);
switch(pid = fork() ) {
case -1: printf("fork error\n"); exit(1);
case 0: signal(SIGUSR1, c_action);
ppid = getppid();
for ( ; ; ) {
pause(); sleep(1); kill(ppid, SIGUSR1); 
}
default:
for ( ; ; ) {
sleep(1); kill(pid, SIGUSR1); pause();
}
} }
p_action()
{ printf("Parent caught signal #%d\n", ++ntimes);
signal(SIGUSR1, p_action);
 }
c_action()
{ printf("Child caught signal #%d\n", ++ntimes);
signal(SIGUSR1, c_action);
}
