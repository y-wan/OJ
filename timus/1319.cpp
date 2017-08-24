#include <iostream>
using namespace std;

int table[101][101];

void init(int n) {
	int cnt = 0, d = n - 1;
	for (int d = n - 1; d >= 1 - n; d--)
		for (int i = 0, j = i + d; i >= 0 && i < n && j >= 0 && j < n; i++, j++)
			table[i][j] = ++cnt;
	for (int d = 1; d <= n - 1; d++)
		for (int j = 0, i = j + d; i >= 0 && i < n && j >= 0 && j < n; i++, j++)
			table[i][j] = ++cnt;
}

int main() {
	int n;
	cin >> n;
	init(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j > 0) cout << ' ';
			cout << table[i][j];
		}
		cout << endl;
	}
	return 0;
}
