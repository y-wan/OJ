#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <time.h>
#include <list>
//#include <ctype.h>

using namespace std;

int find(list<int>* dividends, int n)
{
	int index = 0;
	for (list<int>::iterator it = dividends->begin(); it != dividends->end(); it++)
	{
		if (*it == n)
		{
			return index;
		}
		index++;
	}
	return dividends->size();
}

// n / m
int GetCycle(int n, int m, list<int>* afterpt)
{
	n %= m;
	list<int>* nom = new list<int>();
	if (n == 0)
	{
		afterpt->push_back(0);
		return 1;
	}
	while (true)
	{
		while (n < m)
		{
			n *= 10;
			if (n >= m)
			{
				break;
			}
			afterpt->push_back(0);
			nom->push_back(n);
		}
		afterpt->push_back(n / m);
		nom->push_back(n);
		n %= m;
		if (n == 0)
		{
			afterpt->push_back(0);
			return 1;
		}
		n *= 10;
		int index = find(nom, n);
		if (index < nom->size())
		{
			return afterpt->size() - index;
		}
		while (n < m)
		{
			afterpt->push_back(0);
			nom->push_back(n);
			n *= 10;
			int index = find(nom, n);
			if (index < nom->size())
			{
				return afterpt->size() - index;
			}
		}
	}
}

int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b) == 2)
	{
		int count = 0;
		list<int>* afterpt = new list<int>();
		int cycle = GetCycle(a, b, afterpt);
		int aftersize = afterpt->size();
		int notcycle = aftersize - cycle;
		printf("%d/%d = %d.", a, b, a/b);
		//printf("(aftersize = %d)", aftersize);
		for (list<int>::iterator it = afterpt->begin(); it != afterpt->end(); it++)
		{
			if (count == notcycle)
			{
				printf("(");
			}
			count++;
			if (count <= 50)
			{
				printf("%d", *it);
				if (count == aftersize)
				{
					printf(")");
					break;
				}
			}
			else
			{
				printf("...)");
				break;
			}
		}
		printf("\n   %d = number of digits in repeating cycle\n\n", cycle);
	}
	//printf("Time used:%.3f\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}