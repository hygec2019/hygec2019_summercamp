#include <stdio.h>
#define MAX 20

int win(char a, char b){
    switch (a){
        case 'R':
            switch (b){
                case 'R':
                    return 0;
                case 'S':
                    return 1;
                case 'P':
                    return -1;
            }

        case 'S':
            switch (b){
                case 'R':
                    return -1;
                case 'S':
                    return 0;
                case 'P':
                    return 1;
            }

        case 'P':
            switch (b){
                case 'R':
                    return 1;
                case 'S':
                    return -1;
                case 'P':
                    return 0;
            }
    }
}



int main(){
    char arr[MAX] = {'S', 'R', 'S', 'P', 'P', 'P', 'P', 'R', 'R', 'S', 'R', 'S', 'R', 'P', 'R', 'P', 'P', 'R', 'S', 'S'};
    char arr_1[MAX/2];
    char arr_2[MAX/2];
    int hy=0, dy=0, draw=0;

    for (int i=0, j=0; i<MAX; i+=2, j++) arr_1[j] = arr[i];

    for (int i=1, j=0; i<MAX; i+=2, j++) arr_2[j] = arr[i];

    for (int i=0; i<MAX/2; i++) win(arr_1[i], arr_2[i]) ? win(arr_1[i], arr_2[i]) == 1 ? hy++ : dy++ :  draw++;
    printf("win: %s hy: %d, dy: %d, draw: %d\n", hy > dy ? "hanyang" : hy < dy ? "duyang" : "N/A" , hy, dy, draw);

    return 0;
}
