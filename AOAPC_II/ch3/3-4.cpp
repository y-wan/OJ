#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <time.h>

int main()
{
	char s[85];
	int T, t, i, j, k, rep, n;
	scanf("%d", &T);
	bool period;
	for (t = 0; t < T; t++)
	{
		if (t > 0)
		{
			printf("\n");
		}
		scanf("%s", s);
		n = strlen(s);
		for (i = 1; i < n; i++)
		{
			period = true;
			if (n % i != 0)
			{
				continue;
			}
			rep = n / i;
			for (j = 0; j < i; j++)
			{
				if (!period)
				{
					break;
				}
				for (k = 1; k <= rep - 1; k++)
				{
					if (s[j] != s[j + k * i])
					{
						period = false;
						break;
					}
				}
			}
			if (period)
			{
				printf("%d\n", i);
				break;
			}
		}
		if (i == n)
		{
			printf("%d\n", i);
		}
	}
	//printf("Time used:%.3f\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}

/* 2017-07-25Αν½β
#include <stdio.h>
#include <string.h>
int main() {
	int T, period;
	char s[85];
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		memset(s, '\0', sizeof(s));
		scanf("%s", s);
		int l = strlen(s);
		for (int p = 1; p <= l; p++) {
			if (l % p != 0)
				continue;
			int count = l / p;
			bool periodic = true;
			for (int x = 0; x < p; x++) {
				for (int y = 0; y < count - 1; y++) {
					if (s[y * p + x] != s[y * p + p + x]) {
						periodic = false;
						break;
					}
				}
				if (!periodic)
					break;
			}
			if (periodic) {
				period = p;
				break;
			}
			else
				period = l;
		}		
		printf("%d\n", period);
		if (i < T - 1)
			printf("\n");
	}
	return 0;
}
*/