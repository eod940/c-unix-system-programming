#include <time.h>
#include <stdio.h>

char *output[] = {
	"%x %X",
	"%GYears, %mMonth %dDay %UWeeks %H:%M",
	"%r",
	"%j"	
};

int main(void){
	struct tm *tm;
	int n;
	time_t t;
	char buf[257];

	time(&t);
	tm = localtime(&t);
	
	for (n = 0; n < 4; n++){
		strftime(buf, sizeof(buf), output[n], tm);
		printf("%s = %s\n", output[n], buf);
	}

	return 0;
}
