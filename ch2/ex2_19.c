#include <unistd.h>  // 시스템 콜 사용 위함
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  FILE *fp;
  int fd, n;
  char str[BUFSIZ];

  fp = fopen("unix.txt", "r");
  if (fp == NULL) {
    perror("fopen");
    exit(1);
  }

  fd = fileno(fp);  // 파일 기술자 리턴: 3
  printf("fd : %d\n", fd);

  n = read(fd, str, BUFSIZ);  // 저수준 파일읽기 함수
  str[n] = '\0';
  printf("Read : %s\n", str);

  close(fd);

  return 0;
}

