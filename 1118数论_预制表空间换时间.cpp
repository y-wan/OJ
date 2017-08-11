//数论_预制表空间换时间
#include <iostream>
using namespace std;

long long s[1000010];

int main() {
	//ios_base::sync_with_stdio(false);
	for (int i = 2; i <= 1000000; ++i) {
		++s[i];
		for (int j = i + i; j <= 1000000; j += i)
			s[j] += i;
	}

	int m, n, res = -1;
	double t = 1e13;
	cin >> m >> n;
	for (int i = m; i <= n; i++) {
		if (t > double(s[i]) / i) {
			t = double(s[i]) / i;
			res = i;
		}
	}
	cout << res << endl;
	return 0;
}