//StirlingÊı
#include <iostream>

using namespace std;

int s[11][11];

void init() {
	for (int i = 1; i <= 10; i++) s[i][i] = 1;
	for (int i = 2; i <= 10; i++)
		for (int j = 1; j < i; j++) s[i][j] = j * s[i - 1][j] + s[i - 1][j - 1];
}

int permut(int n) {
	int res = 1;
	while (n > 0) {
		res *= n;
		--n;
	}
	return res;
}

int sum(int n) {
	int res = 0;
	for (int i = 1; i <= n; i++) res += s[n][i] * permut(i);
	return res;
}

int main() {
	init();
	int n;
	while (cin >> n && n != -1) cout << sum(n) << endl;
	return 0;
}