#include <iostream>
#include <algorithm>
using namespace std;

int res[25010];

int main() {
	int n;
	cin >> n;
	if (!n) return 0;
	for (int i = 0; i < n; i++)
		cin >> res[i];
	sort(res, res + n);

	for (int i = n - 1; i > 0; i--)
		cout << res[i] << ' ';
	cout << res[0];
	return 0;
}
