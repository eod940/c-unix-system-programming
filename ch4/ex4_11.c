#include <shadow.h>
#include <stdio.h>

int main(void) {
  struct spwd *spw;
  int n;

  for (n = 0; n < 3; n++) {
    spw = getspnam("hbooks");
    printf("LoginName: %s, Passwd: %s\n", spw -> sp_namp, spw -> sp_pwdp);
    printf("Last Change: %d\n", spw -> sp_lstchg);
  }

  return 0;
}
