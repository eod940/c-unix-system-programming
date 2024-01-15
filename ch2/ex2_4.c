#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  int fd, n;
  char buf[10];
  // unix.txt 내용이 있어야 함
  fd = open("unix.txt", O_RDONLY);
  if (fd == -1) {
    perror("Open");
    exit(1);
  }

  n = read(fd, buf, 6);
  if (n == -1) {
    perror("Read");
    exit(1);
  }
  
  buf[n] = '\0';  // null character (출력 깔끔하게)
  printf("n=%d, buf=%s\n", n, buf);
  close(fd);

  return 0;
}
