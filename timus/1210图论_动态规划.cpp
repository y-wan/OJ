#include <iostream>
#include <cstring>
#include <string>

using namespace std;

long long a[31], b[31];

int main() {
	int n, m, id, cost;
	string tmp;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		memcpy(a, b, sizeof(b));
		//memset(b, 1000000000LL, 30);
		for (int j = 0; j < 31; ++j)b[j] = 1000000000;
		cin >> m;
		for (int j = 1; j <= m; ++j) {
			while (cin >> id && id != 0) {
				cin >> cost;
				if (b[j] > a[id] + cost) b[j] = a[id] + cost;
			}
		}
		if (i < n) cin >> tmp;
	}
	long long res = 1000000000;
	for (int i = 1; i <= 30; ++i)
		if (res > b[i]) res = b[i];
	cout << res << endl;
	return 0;
}
