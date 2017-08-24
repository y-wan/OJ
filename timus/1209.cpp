#include <iostream>
#include <set>
using namespace std;

set<int> one;

int main() {
	//freopen("in.txt", "r", stdin);
	for (long long i = 0; i < 65536; i++)
		one.insert(i*(i + 1) / 2);
	long long n, tmp;
	cin >> n;
	for (long long i = 0; i < n; i++) {
		cin >> tmp;
		if (i > 0) cout << ' ';
		if (one.count(tmp - 1)) cout << '1';
		else cout << '0';
	}
	return 0;
}
