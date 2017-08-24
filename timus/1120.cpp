#include <iostream>
#include <ctime>
using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);
	long long n, a, p, tmp;
	cin >> n;
	for (p = 100000000, tmp = 2 * n + p - p*p;; p--) {
		if (tmp > 0 && tmp % (2 * p) == 0) {
			cout << tmp / (2 * p) << ' ' << p << endl;
			//cout << (double)clock() / CLOCKS_PER_SEC << endl;
			return 0;
		}
		tmp += 2 * p - 2;
	}
	return 0;
}
