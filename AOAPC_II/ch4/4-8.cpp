#include <stdio.h>
#include <string.h>

bool equal(int a[], const int const_a[], int num) {
	for (int i = 0; i < num; i++)
		if (a[i] != const_a[i])
			return false;
	return true;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int num, kase = 0;
	while (scanf("%d", &num) == 1 && num) {
		int awake = 0, cycle[10], a[10], b[10], c[10], begin_c[10], time = 1;
		for (int i = 0; i < num; i++) {
			scanf("%d%d%d", &a[i], &b[i], &c[i]);
			cycle[i] = a[i] + b[i];
			awake += c[i] <= a[i] ? 1 : 0;
		}
		memcpy(begin_c, c, sizeof(c));
		do {
			int da = 0;
			time++;
			for (int i = 0; i < num; i++) {
				c[i] %= cycle[i];
				c[i]++;
				if (c[i] == 1)
					da++;
				else if (c[i] == a[i] + 1)
					if (num - awake > awake)
						da--;
					else
						c[i]--;
			}
			awake += da;
		} while (awake < num && !equal(c, begin_c, num));
		if (awake == num)
			printf("Case %d: %d\n", ++kase, time);
		else
			printf("Case %d: -1\n", ++kase);
	}
	return 0;
}