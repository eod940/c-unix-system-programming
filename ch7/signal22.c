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
for ( ; ; ) { // 이부분을 바꿔야함
sleep(1); kill(ppid, SIGUSR1); pause();
}
default:
for ( ; ; ) {
pause(); sleep(1); kill(pid, SIGUSR1);
}
// 여기까지 바꿔서 이곳 반대로 동작하게 만들어 보기. ( c_action이 먼저 동작, 그다음 p_action)
} }
p_action()
{ printf("Parent caught signal #%d\n", ++ntimes);
signal(SIGUSR1, p_action); // 이곳을 코멘트 처리해도 지금 우분투는 작동함
 }
c_action()
{ printf("Child caught signal #%d\n", ++ntimes);
signal(SIGUSR1, c_action);
}

