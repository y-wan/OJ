#include <iostream>
#include <string>
using namespace std;

int main() {
	int d[5][5], min = 1000000, a, b, c;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> d[i][j];
	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			for (int k = 1; k < 4; k++) {
				if (i == j || j == k || i == k || k == 2) continue;
				if (d[0][i] + d[i][j] + d[j][k] + d[k][4] < min) {
					min = d[0][i] + d[i][j] + d[j][k] + d[k][4];
					a = i;
					b = j;
					c = k;
				}
			}
		}
	}
	cout << min << endl << 1 << ' ' << a + 1 << ' ' << b + 1 << ' ' << c + 1 << ' ' << 5 << endl;
	return 0;
}
