#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  char buf[BUFSIZ];
  int n;

  n = readlink("unix.sym", buf, BUFSIZ);
  if (n == -1) {
    perror("readlink");
    exit(1);
  }

  buf[n] = '\n';
  printf("unix.sym : READLINK = %s\n", buf);
  // 심볼릭 링크는 원본 파일에 대한 포인터 역할을 함
  return 0;

}
