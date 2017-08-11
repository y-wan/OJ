#include <iostream>
using namespace std;

int mod(int a, int b) {
	while (b != 0) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int main() {
	int n, m, t;
	cin >> n >> m;
	--n;
	--m;
	t = mod(m, n);
	cout << t*(m / t + n / t - 1) << endl;
	return 0;
}
