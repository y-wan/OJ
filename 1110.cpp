#include <iostream>
using namespace std;

int mod(int x, int n, int m) {
	int base = x;
	for (int i = 0; i < n - 1; i++) {
		x *= base;
		x %= m;
	}
	return x % m;
}


int main() {
	int n, m, y;
	bool first = true;
	cin >> n >> m >> y;
	for (int x = 0; x < m; x++) {
		if (mod(x, n, m) == y) {
			if (first) first = false;
			else cout << ' ';
			cout << x;
		}
	}
	if (first) cout << -1;
	cout << endl;
	return 0;
}
