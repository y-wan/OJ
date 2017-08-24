#include <iostream>

using namespace std;

long long a[501][32];

int main() {
	a[3][2] = a[4][2] = 1;
	a[5][2] = 2;
	for (int i = 6; i <= 500; ++i) {
		a[i][2] = (i - 1) / 2;
		for (int j = 3; j <= i - 3 && j < 32; ++j)
			a[i][j] = a[i - j][j] + a[i - j][j - 1];
	}
	int n;
	long long res = 0;
	cin >> n;
	for (int i = 2; a[n][i] != 0; ++i)res += a[n][i];
	cout << res << endl;
	return 0;
}
