//图论、动态规划
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const double coeff = sqrt(2);
const int MAX = 1001;
int a[MAX][MAX], b[MAX][MAX];
bool diag[MAX][MAX];

int main() {
	int n, m, k, x, y;
	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i) {
		cin >> x >> y;
		diag[x][y] = true;
	}
	for (int i = 1; i <= n; i++) a[i][0] = i;
	for (int i = 1; i <= m; i++) a[0][i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i - 1][j] + b[i - 1][j] * coeff < a[i][j - 1] + b[i][j - 1] * coeff) {
				a[i][j] = a[i - 1][j] + 1;
				b[i][j] = b[i - 1][j];
			}
			else a[i][j] = a[i][j - 1] + 1, b[i][j] = b[i][j - 1];
			if (diag[i][j] && a[i - 1][j - 1] + (b[i - 1][j - 1] + 1) * coeff < a[i][j] + b[i][j] * coeff)
				a[i][j] = a[i - 1][j - 1], b[i][j] = b[i - 1][j - 1] + 1;
		}
	}
	printf("%.f\n", (a[n][m] + b[n][m] * coeff) * 100);
	return 0;
}