#include <stdio.h>
int main() {
	int kase = 0, a, b;
	double sum;
	while (scanf("%d %d", &a, &b) == 2 && a) {
		sum = 0;
		for (int i = a; i <= b; i++)
			sum += 1.0 / i / i;
		printf("Case %d: %.5f\n", ++kase, sum);
	}
	return 0;
}