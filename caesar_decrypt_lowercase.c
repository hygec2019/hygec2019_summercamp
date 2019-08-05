#include <stdio.h>
#define MAX 100

int main(void){
	char string[MAX] = "";
	int fuck = 0;
	scanf("%s", string);
	scanf("%d", &fuck);
	for (int i=0; i<MAX; i++){
		string[i]+=fuck;
		if (string[i] <'a') string[i]+=26;
	}
	printf("%s\n", string);
	return 0;
}
