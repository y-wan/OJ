#include <iostream>
using namespace std;

int f[1005];

int main() {
	int a, res = 1, max = 0;
	cin >> a;
	for (int i = 0; i < a; i++)
		cin >> f[i];
	for (int i = 1; i < a - 1; i++)
		if (f[i - 1] + f[i] + f[i + 1] > max) { res = i; max = f[i - 1] + f[i] + f[i + 1]; }
	cout << max << ' ' << res + 1 << endl;
	return 0;
}
