#include <stdio.h>
#include <string.h>
#define EPS 1e-6
int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int m, n, kase = 0, height[29][29];
	while (scanf("%d%d", &m, &n) == 2 && m) {
		int level = (1 << 30), watered = 0, leveled = 0;
		double volume;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &height[i][j]);
				level = level < height[i][j] ? level : height[i][j];
			}
		}
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (height[i][j] == level)
					leveled++;
		scanf("%lf", &volume);
		volume /= 100;
		while (volume >= watered + EPS && volume > EPS) {
			bool extra = (volume > watered + EPS);
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (height[i][j] < level) {
						volume -= 1.0;
					}
					else if (height[i][j] == level) {
						volume -= 1.0;
						watered++;
						leveled--;
					}
					else if (height[i][j] == level + 1) {
						leveled++;
					}
				}
			}
			level++;
		}


		double real_level = double(level) + volume / (watered + leveled);
		double percent;
		if (volume > EPS)
			percent = double(watered + leveled) * 100 / m / n;
		else
			percent = double(watered) * 100 / m / n;
		if (kase > 0) printf("\n");
		printf("Region %d\nWater level is %.2f meters.\n%.2f percent of the region is under water.\n", ++kase, real_level, percent);
	}
	return 0;
}