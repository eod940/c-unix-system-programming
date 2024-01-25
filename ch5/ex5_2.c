#include <unistd.h>
#include <stdio.h>

int main(void){

	printf("PID : %d\n", (int)getpid());
	printf("PGRP : %d\n", (int)getpgrp());
	printf("PGID(0) : %d\n", (int)getpgid(0));
	printf("PGID(24306) : %d\n", (int)getpgid(24306));

	return 0;
}
