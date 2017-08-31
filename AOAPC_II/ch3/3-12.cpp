/*²Î¿¼CSDN*/
#include <stdio.h>
#include <string.h>
//#include <time.h>
#include <math.h>

int main()
{
	double M[10][31];  
	long long E[10][31];  
	for (int i = 0; i < 10; i++) {
		for (int j = 1; j < 31; j++) {  
			double a = 1 - pow(2.0, -(i + 1));  
			long long b = pow(2.0, j) - 1;  
			double x = log10(a) + b * log10(2.0);  
			long long d = floor(x);  
			double c = pow(10, x - d);  
			M[i][j] = c;  
			E[i][j] = d;  
		}  
	}
	char s[30];  
	double p;  
	int q;  
	while(scanf("%s", s) == 1 && strcmp(s, "0e0\0") != 0) {  
		s[17]=' ';  
		sscanf(s,"%lf %d", &p, &q);  
		for (int i = 0; i < 10; i++)  
			for (int j = 1; j <= 30; j++)  
				if (fabs(M[i][j] - p) < 1e-4 && E[i][j] == q)  
					printf("%d %d\n", i, j);  
	} 
	//printf("Time used:%.3f\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}

/* 2017-07-27×Ô×öAC
#include <cstdio>
#include <cmath>
#include <cstring>

double exponent[30];
int exponent_base10[30];
double mantissa[10];
char table[10][30][30];

void prepare_exponent() {
	exponent[0] = 2;
	exponent_base10[30] = 0;
	for (int i = 1; i < 30; i++) {
		exponent[i] = exponent[i - 1] * exponent[i - 1];
		exponent_base10[i] = 2 * exponent_base10[i - 1];
		exponent[i] *= 2;
		while (exponent[i] > 10) {
			exponent[i] /= 10;
			exponent_base10[i]++;
		}
	}
}

void prepare_mantissa() {
	mantissa[0] = 0.5;
	double div_base = 0.25;
	for (int i = 0; i < 9; i++) {
		mantissa[i + 1] = mantissa[i];
		mantissa[i + 1] += div_base;
		div_base /= 2;
	}
}

void prepare_table() {
	double a;
	int b;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 30; j++) {
			a = mantissa[i] * exponent[j];
			b = exponent_base10[j];
			while (a < 1) {
				a *= 10;
				b--;
			}
			while (a > 10) {
				a /= 10;
				b++;
			}
			sprintf(table[i][j], "%.15fe%d", a, b);
		}
}

bool str_equal(char *s1, char *s2) {
	s1[17] = ' ';
	s2[17] = ' ';
	double a1, a2;
	int b1, b2;
	sscanf(s1, "%lf%d", &a1, &b1);
	sscanf(s2, "%lf%d", &a2, &b2);
	if (a1 - a2 < 1e-6 && a2 - a1 < 1e-6 && b1 == b2)
		return true;
	else
		return false;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	prepare_exponent();
	prepare_mantissa();
	prepare_table();
	char s[30];
	while (scanf("%s", s) == 1 && strcmp(s, "0e0")) {
		bool printed = false;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 30; j++) {
				if (str_equal(s, table[i][j])) {
					printf("%d %d\n", i, j + 1);
					printed = true;
					break;
				}
			}
			if (printed)
				break;
		}
		//if (!printed)
			//printf("Not found: %s\n", s);
	}	
	//printf("\n%.15fe%d\n", mantissa[5] * exponent[29], exponent_base10[29]);
	return 0;
}
*/