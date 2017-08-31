#include <stdio.h>
#include <string.h>
//#include <stdlib.h>
//#include <time.h>
#include <ctype.h>

int main()
{
	int r, c, kase = 0, temp;
	char s[15][15];
	bool flag[15][15][2];
	int order[15][15], count;
	scanf("%d", &r);
	while (r != 0)
	{
		count = 0;
		memset(flag, false, sizeof(bool) * 15 * 15 * 2);
		memset(order, 0, sizeof(int) * 15 * 15);
		scanf("%d", &c);
		for (int i = 0; i < r; i++)
		{
			scanf("%s", s[i]);
			//printf("%s\n", s[i]);
		}
		//printf("Puzzle #%d\nAcross\n", ++kase);
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (s[i][j] != '*' && (j == 0 || s[i][j - 1] == '*'))
				{
					flag[i][j][0] = true;
					order[i][j] = ++count;
				}
				if (s[i][j] != '*' && (i == 0 || s[i - 1][j] == '*'))
				{
					flag[i][j][1] = true;
					if(order[i][j] == 0)
						order[i][j] = ++count;
				}
			}
		}
		if (kase > 0)
		{
			printf("\n");
		}
		printf("puzzle #%d:\nAcross\n", ++kase);
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (flag[i][j][0] == true)
				{
					temp = j;
					printf("%3d.", order[i][j]);
					while (temp < c && isalpha(s[i][temp]))
					{
						printf("%c", s[i][temp++]);
					}
					printf("\n");
				}
			}
		}
		printf("Down\n");
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (flag[i][j][1] == true)
				{
					temp = i;
					printf("%3d.", order[i][j]);
					while (temp < r && isalpha(s[temp][j]))
					{
						printf("%c", s[temp++][j]);
					}
					printf("\n");
				}
			}
		}
		scanf("%d", &r);
	}
	//printf("Time used:%.3f\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}