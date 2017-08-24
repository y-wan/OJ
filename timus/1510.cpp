#include <iostream>
#include <map>
using namespace std;

map<int, int> d;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	long long k, tmp, max_cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (!d.count(tmp)) d[tmp] = 1;
		else d[tmp]++;
		if (d[tmp] > max_cnt) {
			max_cnt = d[tmp];
			k = tmp;
		}
	}
	cout << k << endl;
	return 0;
}
