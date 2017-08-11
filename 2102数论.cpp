//数论，容易TLE、MLE，需要对因子范围有比较严格的估计
#include <iostream>
#define MAXN 1953126

using namespace std;

bool is_prime(long long n) {
	for (long long i = 2; i*i < n + 1; ++i)
		if (n % i == 0)
			return false;
	return true;
}

int main() {
	long long n, i = 2, cnt = 0;
	cin >> n;
	while (n > 1 && i < MAXN) {
		while (n % i == 0) {
			++cnt;
			n /= i;
			if (cnt > 20) {
				cout << "No" << endl;
				return 0;
			}
		}
		++i;
	}
	if (n > 1) {
		if (cnt == 19 && is_prime(n)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	else if (cnt != 20) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}