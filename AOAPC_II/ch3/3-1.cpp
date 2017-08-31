#include <stdio.h>
#include <string.h>
#define MAXN 85
int main() {
	int T;
	char s[MAXN];
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		memset(s, '\0', sizeof(s));
		scanf("%s", s);
		int l = strlen(s), score = 0, curr = 0;
		for (int j = 0; j < l; j++) {
			if (s[j] == 'O') {
				curr++;
				score += curr;
			}
			else
				curr = 0;
		}
		printf("%d\n", score);
	}
	return 0;
}