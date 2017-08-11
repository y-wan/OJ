#include <iostream>
using namespace std;

long long table[101][101];

void init() {
	for (int i = 1; i <= 100; i++) {
		table[i][0] = 1;
		for (int j = 1; j <= 100; j++) {
			table[i][j] = table[i][j - 1] * i;
			table[i][j] %= (1 << 30) - 1 + (1 << 30);
		}
	}
}

void print_table(int row, int col) {
	for (int i = 1; i <= row; i++) {
		cout << "i=" << i << ":\t";
		for (int j = 1; j <= col; j++) {
			cout << table[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	//cout << (1 << 30) - 1 + (1 << 30) << endl;
	init();
	//print_table(5, 5);
	int n;
	cin >> n;
	for (int i = 1; i <= 100; i++) {
		for (int j = i + 1; j <= 100; j++) {
			for (int k = j + 1; k <= 100; k++) {
				if (table[i][n] + table[j][n] == table[k][n]) {
					cout << i << ' ' << j << ' ' << k << endl;
					return 0;
				}
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
