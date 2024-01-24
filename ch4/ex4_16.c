#include <sys/types.h>
#include <time.h>
#include <stdio.h>
#include <sys/time.h>

int main(void){
	time_t tt;
	struct timeval tv;

	gettimeofday(&tv, NULL);
	printf("Time(sec) : %d\n", (int)tv.tv_sec);
	printf("Time(micro-sec) : %d\n", (int)tv.tv_usec);
	time(&tt);
	printf("Time(sec) : %d\n", (int)tt);

	return 0;
}
