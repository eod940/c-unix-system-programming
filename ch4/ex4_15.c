#include <stdio.h>
#include <utmpx.h>
#include <sys/types.h>

int main(void){
	struct utmpx *utx;
	printf("LoginName Line\n");
	printf("----------------");

	while((utx=getutxent()) != NULL){
		if(utx->ut_type != USER_PROCESS)
			continue;
		printf("%s	%s\n", utx->ut_user, utx->ut_line);
	}
	return 0;
}




