#include <unistd.h>
#include <stdio.h>

int main(void) {
  char *cwd;
  char wd[BUFSIZ];

  cwd = getcwd(NULL, BUFSIZ);  // NULL을 준이유: 내가 메모리 지정x 유닉스가 지정한 위치o
  printf("1.Current Directory : %s\n", cwd);

  chdir("hanbit");

  getcwd(wd, BUFSIZ);
  printf("2. Current Directory : %s\n", wd);

  return 0;
}
