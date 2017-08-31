#include <stdio.h>
int main() {
	int a, b, c, kase = 0;
	while (scanf("%d %d %d", &a, &b, &c) == 3) {
		int n = 10;
		while ((n % 3 != a || n % 5 != b || n % 7 != c) && n <= 100)
			n++;
		if (n <= 100)
			printf("Case %d: %d\n", ++kase, n);
		else
			printf("Case %d: No answer\n", ++kase);
	}
	return 0;
}