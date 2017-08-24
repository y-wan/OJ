#include <iostream>

using namespace std;

int screen[100][100];

int main() {
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> screen[i][j];
	//0~2n-2
	for (int i = 0; i < 2 * n - 1; i++) {
		for (int j = 0; j <= i; j++) {
			if (i - j < n && j < n) {
				if (cnt++ > 0)
					cout << ' ';
				cout << screen[i - j][j];
			}
		}
	}
	return 0;
}
