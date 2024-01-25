#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
	int status;
	pid_t pid1, pid2;

	if((pid1 = fork()) == 0){
		
		printf("Child process 1\n");
		sleep(3);
		exit(2);

	}
	
	if((pid2 = fork()) == 0){
		
		printf("Child process 2\n");
		sleep(10);
		exit(3);

	}

// Parent process
// if wait() != -1 then, wait for both child
	while(wait(&status) != pid1)
		continue;
	printf("Parent--\n");
	printf("Status: %d, %x\n", status, status);
	printf("Child process Exit Status: %d\n", status >> 8);

	return 0;
}
