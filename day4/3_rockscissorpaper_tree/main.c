#include <stdio.h>
#define MAX 16

int tournament(char a, char b) {
	switch (a) {
	case 'R':
		return (b == 'P') ? 'P' : 'R';
	case 'S':
		return (b == 'R') ? 'R' : 'S';
	case 'P':
		return (b == 'S') ? 'S' : 'P';
	}
}


int main() {
	char tree[MAX] = { 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'N', 'R', 'S', 'P', 'R', 'S', 'P', 'R', 'S' };
	for (int j = MAX/2; j > 1; ) {
		for (int i = j; i < j*2-1; i += 2) {
			tree[i / 2] = tournament(tree[i], tree[i + 1]);

		}
		j = j / 2;
	}
	for (int i = 0; i < MAX; i++) {
		printf(" %d ", tree[i]);
	}
	return 0;
	
}