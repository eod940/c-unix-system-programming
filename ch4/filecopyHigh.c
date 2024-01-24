#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *fp1, *fp2;
	int n;
	char buf[BUFSIZ];

	if((fp1 = fopen("a.txt", "r")) == NULL){
		perror("fp1");
		exit(1);
	}

	if((fp2 = fopen("b1.txt", "w")) == NULL){
		perror("fp2");
		exit(1);
	}

	fseek(fp1, 5L, SEEK_SET);
	while((n = fread(buf, sizeof(char), 3, fp1)) >0){
		printf("n = %d\n", n);
		fwrite(buf, sizeof(char), n, fp2);
		fwrite("\n",sizeof(char), 1, fp2);
		fseek(fp1, 19L, SEEK_CUR);
	}
	printf("Program is finish!\n");
	fclose(fp1);
	fclose(fp2);
	return 0;
}
