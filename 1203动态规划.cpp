//¶¯Ì¬¹æ»®
#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> a[100000];

int main() {
	//ios_base::sync_with_stdio(false);
	int n, end = -1, p = 0, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i].second >> a[i].first;
	sort(a, a + n);
	for (int i = a[0].first; i <= a[n - 1].first; i++) {
		for (; a[p].first <= i; p++) {
			if (a[p].second > end) {
				end = a[p].first;
				sum++;
			}
		}
	}
	cout << sum << endl;
	return 0;
}