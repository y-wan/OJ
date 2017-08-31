#include <stdio.h>
#include <string.h>
int count[10001][10];
int main() {
	int T, n;
	scanf("%d", &T);
	memset(count, 0, sizeof(count[0]));
	for (int i = 1; i <= 10000; i++) {
		memcpy(&count[i], &count[i - 1], sizeof(count[i]));
		int tmp = i;
		while (tmp > 0) {
			count[i][tmp % 10]++;
			tmp /= 10;
		}
	}
	for (int i = 0; i < T; i++) {
		scanf("%d", &n);
		for (int j = 0; j < 9; j++)
			printf("%d ", count[n][j]);
		printf("%d\n", count[n][9]);
	}
	return 0;
}