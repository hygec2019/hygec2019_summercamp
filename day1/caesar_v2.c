#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_SIZE 100
#define MAX_KEY      26
#define TRUE         1
#define FALSE        0

char getMode();
void getMessage(char Msg[]);
int getKey();
void translateMessage(char mode, char msg[], int key, char TMsg[]);
int isalpha(char symbol);
int isupper(char symbol);

char Msg[MAX_MSG_SIZE];
char TMsg[MAX_MSG_SIZE];

int main(){
	printf("면책 조항: 모든 코드는 고양이가 쨨습니다. \n\n");

	char mode;
	int key;
	while(TRUE){
		memset(TMsg, 0, MAX_MSG_SIZE);
		mode = getMode();
		switch(mode){
			case 'e':
				printf("메시지를 암호화합니다.\n");
				getMessage(Msg);
				key= getKey();
				translateMessage(mode, Msg, key, TMsg);
				printf("암호문: %s\n", TMsg);
				break;
			case 'd':
				printf("메시지를 복호화합니다.\n");
				getMessage(Msg);
				key = getKey();
				translateMessage(mode, Msg, key, TMsg);
				printf("복호문: %s\n", TMsg);
				break;
			case 'b':
				getMessage(Msg);
				printf("** 메시지를 공격합니다.\n");
				
				/* implement here */
				for (key=1; key<MAX_KEY; key++){
					translateMessage(mode,Msg,key,TMsg);
					printf(" 키: %d --> %s\n", key, TMsg);
				}
				
				break;
			case 'x': exit(0);
		}
	}
	return 0;
}


int getKey(){
	int key;
	while (TRUE){
		printf(">> 키 값을 입력하세요 (1~26): ");
		scanf("%d", &key);
		if (key>0 && key <= MAX_KEY) return key;
	}
}

int isalpha(char symbol){
	if ((symbol >= 'a' && symbol <= 'z') || (symbol>='A' && symbol<='Z')) return TRUE;
	else return FALSE;
}

int isupper(char symbol){
	if (symbol >= 'A' && symbol <= 'Z') return TRUE;
	else return FALSE;
}

char getMode(){
	int mode=0;
	while (TRUE){
		printf("\n=====================\n");
		printf("1. 메시지 암호화\n");
		printf("2. 암호문 복호화\n");
		printf("3. Brute Force\n");
		printf("0. 프로그램 종료\n");
		printf("=====================\n");
		printf(">> 기능을 선택하세요: ");
		scanf("%d", &mode);
		/* Enter키 이전까지 읽으므로 키보드 버퍼에 \n이 남아있음*/
		switch(mode){
			case 1: return 'e';
			case 2: return 'd';
			case 3: return 'b';
			case 0: return 'x';
		}
	}
}


void getMessage(char Msg[]){
	int blank;
	blank = getc(stdin);
	printf(">> 메시지를 입력하세요.\n");
	gets(Msg);
}


void translateMessage(char mode, char Msg[], int key, char TMsg[]){
	int idx=0, len, num;
	char symbol;
	len = strlen(Msg);
	memset(TMsg, 0, MAX_MSG_SIZE);
	for (idx=0; idx<len; idx++){
		symbol = Msg[idx];
		if (isalpha(symbol)){
			num = symbol;
			if (mode == 'e'){
				num+=key;
				if ((isupper(symbol) && num > 'Z') || (!isupper(symbol) && num > 'z')) num -= MAX_KEY;
			} else {
				num -= key;
				if ((isupper(symbol) && num < 'A') || (!isupper(symbol) && num < 'a')) num += MAX_KEY;
			}
			TMsg[idx] = num;
		} else {
			TMsg[idx] = symbol;
		}
	}
}



