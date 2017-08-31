#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXN 85
int main() {
	int T;
	char s[MAXN];
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		memset(s, '\0', sizeof(s));
		scanf("%s", s);
		int l = strlen(s);
		double mass = 0;
		for (int j = 0; j < l; j++) {
			if (s[j + 1] && isdigit(s[j + 1])) {
				if (s[j + 2] && isdigit(s[j + 2])) {
					switch (s[j])
					{
					case 'C':
						mass += 12.01 * ((s[j + 1] - '0') * 10 + (s[j + 2] - '0'));
						break;
					case 'H':
						mass += 1.008 * ((s[j + 1] - '0') * 10 + (s[j + 2] - '0'));
						break;
					case 'O':
						mass += 16.00 * ((s[j + 1] - '0') * 10 + (s[j + 2] - '0'));
						break;
					case 'N':
						mass += 14.01 * ((s[j + 1] - '0') * 10 + (s[j + 2] - '0'));
						break;
					default:
						break;
					}
				}
				else {
					switch (s[j])
					{
					case 'C':
						mass += 12.01 * (s[j + 1] - '0');
						break;
					case 'H':
						mass += 1.008 * (s[j + 1] - '0');
						break;
					case 'O':
						mass += 16.00 * (s[j + 1] - '0');
						break;
					case 'N':
						mass += 14.01 * (s[j + 1] - '0');
						break;
					default:
						break;
					}
				}
			}
			else
				switch (s[j])
				{
				case 'C':
					mass += 12.01;
					break;
				case 'H':
					mass += 1.008;
					break;
				case 'O':
					mass += 16.00;
					break;
				case 'N':
					mass += 14.01;
					break;
				default:
					break;
				}
		}
		printf("%.3f\n", mass);
	}
	return 0;
}