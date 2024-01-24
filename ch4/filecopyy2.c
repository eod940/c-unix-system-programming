#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
main()
{
	int fd1, fd2, n;
	char buf[10];
	fd1 = open("a.txt", O_RDONLY);
	fd2 = creat("b.txt", 0644);
	lseek(fd1, 5L, 0);
	while( (n = read(fd1, buf, 3)) > 0){
		printf("n=%d\n",n);
		write(fd2, buf, n);
		// n is best
		write(fd2, "\n",1);
		lseek(fd1, 19L, 1);
	}
	printf("program is finish\n");
}
