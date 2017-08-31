#include <stdio.h>
#include <string.h>
//#include <time.h>

int main()
{
	char s[105], t[105];
	while (scanf("%s%s", s, t) == 2)
	{
		int ls = strlen(s), lt = strlen(t);
		int best = ls + lt;
		int i, j, endj;
		for (i = 1 - lt; i < ls; i++)
		{
			bool match = true;
			endj = (i + lt) < ls ? (i + lt) : ls;
			for (j = i > 0 ? i : 0; j < endj; j++)
			{
				if (s[j] == '2' && t[j - i] == '2')
				{
					match = false;
					break;
				}
			}
			if (match)
			{
				int i1 = 0 < i ? 0 : i;
				int i2 = ls > (i + lt) ? ls : (i + lt);
				best = best < (i2 - i1) ? best : (i2 - i1);
			}
		}
		printf("%d\n", best);
	}
	//printf("Time used:%.3f\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}