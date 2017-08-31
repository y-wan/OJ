#include <stdio.h>
#include <string.h>
//#include <stdlib.h>
#include <time.h>
//#include <ctype.h>

//using namespace std;

char s[100000];
char t[100000];

int main()
{
	while (scanf("%s%s", s, t) == 2)
	{
		int i, j;
		int ls = strlen(s), lt = strlen(t);
		for (i=0,j=0; i<ls, j<lt;)
		{
			if (s[i] == t[j])
			{
				i++;j++;
			}
			else
			{
				j++;
			}
		}
		if (i == ls)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	//printf("Time used:%.3f\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}