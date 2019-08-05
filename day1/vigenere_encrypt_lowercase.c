#include <stdio.h>
#include <string.h>
#define MAX 100

int main(void){
	char string[MAX] = "";
	char string2[MAX] = "";
	scanf("%s", string);
	scanf("%s", string2);
	
	int fuck=0;
	for(int i=0; i<strlen(string); i++){
		string[i] += string2[fuck] -123;
		// HACK: char 타입은 255까지 가능한데 그걸 넘으면 버퍼 오버플로우가 발생함.  따라서 -97(a의 ascii 값이 0이 되게 하는 수)과 -26을 한꺼번에 하고 나중에 26(ascii z-a+1)을 더하는걸로 구현. 
		if(string[i] < 'a'){
			string[i]+=26;
		}
		fuck++;
		if (!(fuck<strlen(string2))) fuck = 0;
	}
	printf("%s\n", string);
	return 0;
}
