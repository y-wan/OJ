#include <iostream>
using namespace std;

int main() {
	long long n, m, t;
	cin >> n >> m;
	if (m >= n) t = (n - 1) * 2;
	else t = 2 * m - 1;
	cout << t << endl;
	return 0;
}
