#include <stdio.h>
#include <string.h>
#include <ctype.h>
//#include <time.h>

int main()
{
	//freopen("in.txt", "r", stdin);
	char s[5][6], temp[100];
	int x, y, num = 0;
	bool findxy, legal;
	while (strcmp(gets(s[0]), "Z\0") != 0)
	{
		findxy = false, legal = true;
		for (int i = 1; i < 5; i++)
		{
			gets(s[i]);
		}
		for (int i = 0; i < 5; i++)
		{
			if (findxy)
			{
				break;
			}
			for (int j = 0; j < 5; j++)
			{
				if (s[i][j] < 'A' || s[i][j] > 'Z')
				{
					x = i;
					y = j;
					findxy = true;
					break;
				}
			}
		}
		char c;
		while ((c = getchar()) != '0' && legal)
		{
			switch (c)
			{
			case 'A':
				if (x == 0)
				{
					legal = false;
				}
				else
				{
					s[x][y] = s[x - 1][y];
					s[x - 1][y] = ' ';
					x--;
				}
				break;
			case 'B':
				if (x == 4)
				{
					legal = false;
				}
				else
				{
					s[x][y] = s[x + 1][y];
					s[x + 1][y] = ' ';
					x++;
				}
				break;
			case 'L':
				if (y == 0)
				{
					legal = false;
				}
				else
				{
					s[x][y] = s[x][y - 1];
					s[x][y - 1] = ' ';
					y--;
				}
				break;
			case 'R':
				if (y == 4)
				{
					legal = false;
				}
				else
				{
					s[x][y] = s[x][y + 1];
					s[x][y + 1] = ' ';
					y++;
				}
				break;
			}
		}
		gets(temp);
		if (num > 0)
		{
			printf("\n");
		}
		printf("Puzzle #%d:\n", ++num);
		if (!legal)
		{
			printf("This puzzle has no final configuration.\n");
		}
		else
		{
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					printf("%c ", s[i][j]);
				}
				printf("%c\n", s[i][4]);
			}
		}
	}
	//printf("Time used:%.3f\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}

/* 2017-07-25Αν½β
// wrong answer
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
#endif // _DEBUG

	int kase = 0;
	char s[5][5], c;
	
	while (1) {
		bool findz = false;
		c = getchar();
		while (!isalpha(c) && c != ' ')
			c = getchar();
		if (c == 'Z') {
			if (!isprint(c = getchar()))
				return 0;
			else
				findz = true;
		}
			
		if (kase > 0)
			printf("\n");
		bool legal = true;
		int X = -1, Y = -1;
		if (!findz) {
			s[0][0] = c;
			for (int i = 1; i < 5; i++)
				s[0][i] = getchar();
			if (!isprint(s[0][4]))
				s[0][4] = ' ';
		}
		else {
			s[0][0] = 'Z';
			s[0][1] = c;
			for (int i = 2; i < 5; i++)
				s[0][i] = getchar();
			if (!isprint(s[0][4]))
				s[0][4] = ' ';
		}
		for (int i = 1; i < 5; i++) {
			if (s[i - 1][4] != ' ')
				getchar();
			for (int j = 0; j < 5; j++)
				s[i][j] = getchar();
			if (!isprint(s[i][4]))
				s[i][4] = ' ';
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (s[i][j] == ' ') {
					X = i;
					Y = j;
					break;
				}
			}
			if (X > -1)
				break;
		}
#ifdef _DEBUG
		printf("Debug #%d:\n", kase + 1);
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				printf("%c%c", s[i][j], j == 4 ? '\n' : ' ');
#endif // _DEBUG

		while ((c = getchar()) != '0') {
			switch (c)
			{
			case 'A':
				if (X == 0) {
					legal = false;
					break;
				}
				s[X][Y] = s[X - 1][Y];
				s[X - 1][Y] = ' ';
				X--;
				break;
			case 'B':
				if (X == 4) {
					legal = false;
					break;
				}
				s[X][Y] = s[X + 1][Y];
				s[X + 1][Y] = ' ';
				X++;
				break;
			case 'L':
				if (Y == 0) {
					legal = false;
					break;
				}
				s[X][Y] = s[X][Y - 1];
				s[X][Y - 1] = ' ';
				Y--;
				break;
			case 'R':
				if (Y == 4) {
					legal = false;
					break;
				}
				s[X][Y] = s[X][Y + 1];
				s[X][Y + 1] = ' ';
				Y++;
				break;
			default:
				break;
			}
		}
		printf("Puzzle #%d:\n", ++kase);
		if (!legal)
			printf("This puzzle has no final configuration.\n");
		else {
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					printf("%c%c", s[i][j], j == 4 ? '\n' : ' ');
		}
	}
	return 0;
}
*/