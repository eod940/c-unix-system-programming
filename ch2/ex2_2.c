#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int fd;

  fd = open("unix.txt", O_CREAT | O_EXCL, 0644);
  if (fd == -1) {
    perror("Excl");
    exit(1);
  }
  printf("unix.txt : fd = %d\n", fd);
  close(fd);

  return 0;
}
