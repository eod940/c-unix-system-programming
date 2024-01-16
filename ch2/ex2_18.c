#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
// 오픈한 파일의 디스크립터 번호를 이용해 file 포인터를 반환할 수 있음
int main(void) {
  FILE *fp;
  int fd;
  char str[BUFSIZ];

  fd = open("unix.txt", O_RDONLY);  // 저수준 오픈: 3
  if (fd == -1) {
    perror("open");
    exit(1);
  }

  fp = fdopen(fd, "r");  // 파일 포인터 생성

  fgets(str, BUFSIZ, fp);  // 고수준 오픈
  printf("Read : %s\n", str);

  fclose(fp);

  return 0;
}
