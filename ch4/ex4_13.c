#include <grp.h>
#include <stdio.h>

int main(void) {
  struct group *grp;
  int n;

  grp = getgrnam("gdm");
  printf("Group Name : %s\n", grp -> gr_name);
  printf("GID : %d\n", (int)grp -> gr_gid);

  n = 0;
  printf("Members : ");
  while (grp -> gr_mem[n] != NULL)
    printf("%s ", grp -> gr_mem[n++]);
  printf("\n");

  return 0;
}
