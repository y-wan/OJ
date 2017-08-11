//¶¯Ì¬¹æ»®
#include <iostream>
using namespace std;

bool p[20][2000000];

int dis(int a, int b) {
	return a > b ? a - b : b - a;
}

int main() {
	int n, a[20], sum = 0, d, d1 = 2000000, d2 = 2000000;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (n == 1) {
		cout << a[0] << endl;
		return 0;
	}
	p[0][0] = true;
	p[0][a[0]] = true;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= sum; j++)
			p[i][j] = p[i - 1][j] || j >= a[i] && p[i - 1][j - a[i]];
	}
	for (int i = sum / 2; i >= 0; i--) {
		if (p[n - 1][i]) {
			d1 = dis(i, sum - i);
			break;
		}
	}
	for (int i = sum / 2; i < n; i++) {
		if (p[n - 1][i]) {
			d2 = dis(i, sum - i);
			break;
		}
	}
	d = d1 < d2 ? d1 : d2;
	cout << d << endl;
	return 0;
}