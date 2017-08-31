#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count[1005][4];	//A, C, G, T
void getmax(int count[1005][4], char ans[1005], int n)
{
	for (int i = 0; i < n; i++)
	{
		int m = count[i][0];
		char cur = 'A';
		if (m < count[i][1])
		{
			cur = 'C';
			m = count[i][1];
		}
		if (m < count[i][2])
		{
			cur = 'G';
			m = count[i][2];
		}
		if (m < count[i][3])
		{
			cur = 'T';
			m = count[i][3];
		}
		ans[i] = cur;
	}
}

void addcount(int count[1005][4], char* s, int n)
{
	for (int i = 0; i < n; i++)
	{
		switch (s[i])
		{
		case 'A':
			count[i][0]++;
			break;
		case 'C':
			count[i][1]++;
			break;
		case 'G':
			count[i][2]++;
			break;
		case 'T':
			count[i][3]++;
			break;
		default:
			break;
		}
	}
}

int main()
{
	int T, n, m;
	char s[1005], maxs[1005];
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d%d", &m, &n);
		int err = m * n;
		memset(count, 0, sizeof(int) * 4020);
		memset(maxs, '\0', sizeof(char) * 1005);
		for (int j = 0; j < m; j++)
		{
			scanf("%s", s);
			addcount(count, s, n);
		}
		getmax(count, maxs, n);
		for (int k = 0; k < n; k++)
		{
			switch (maxs[k])
			{
			case 'A':
				err -= count[k][0];
				break;
			case 'C':
				err -= count[k][1];
				break;
			case 'G':
				err -= count[k][2];
				break;
			case 'T':
				err -= count[k][3];
				break;
			default:
				break;
			}
		}
		printf("%s\n%d\n", maxs, err);
	}
	return 0;
}