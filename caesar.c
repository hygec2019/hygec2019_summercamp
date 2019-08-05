#include <stdio.h>
#include <string.h>
#define MAX 100

int main(void){
    char string[MAX] = "";
    int fuck = 0;
    int choice = 0;
    int isuppercase = 0;

    printf("============================================\n");    
    printf("Caesar Cipher Algorithm Encryption / Decryption Program v0.1\n");
    printf("by computerpark\n");
    printf("Distributed under the MIT License\n");
    printf("============================================\n\n");
    printf("세웅이 야동본다!!!!\n\n");

    printf("Enter Mode (1: Encrypt, 2: Decrypt) > ");
    
    scanf("%d", &choice);
    if(!(choice == 1 || choice == 2)) { printf("Invalid!\n"); return -1; } 

    printf("Input String to %s (string) > ", choice==1 ? "Encrypt":"Decrypt");
    scanf("%s", string);
    printf("Input mod (int) > ");
    scanf("%d", &fuck);
 
    if (choice==1){     
        for (int i=0; i<strlen(string); i++){
            isuppercase = ('A' <= string[i] && string[i]<= 'Z') ? 1:0;        
	    string[i]+=fuck;
	    if (string[i] > (isuppercase ? 'Z' : 'z')) string[i]-=26;
        }
    }else{
        for(int i=0; i<strlen(string); i++){
	    isuppercase = ('A' <= string[i] && string[i]<= 'Z') ? 1:0;
	    string[i] -= fuck;
	    if (string[i] < (isuppercase ? 'A' :'a')) string[i]+=26;
	}
    }

    printf("%s\n", string);
    return 0;
}
