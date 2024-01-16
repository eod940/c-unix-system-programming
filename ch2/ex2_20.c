#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *fname;
  char fntmp[BUFSIZ];
  char template[32];

  fname = tmpnam(NULL);
  printf("1. TMP File Name(tmpnam) : %s\n", fname);

  tmpnam(fntmp);  // 사이즈를 가진 인자를 줌
  printf("2. TMP File Name(tmpnam) : %s\n", fntmp);

  fname = tempnam("/tmp", "hanbit");
  printf("3. TMP File Name(tempnam) : %s\n", fname);

  strcpy(template, "/tmp/hanbitXXXXXX");  // 30자 넘으면 잘림
  fname = mktemp(template);
  printf("4. TMP File Name(mktemp) : %s \n", fname);

  return 0;
}
