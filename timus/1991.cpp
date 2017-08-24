#include <iostream>
using namespace std;

int main() {
	int n, k, tmp, unused = 0, sum = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		sum += (tmp > k ? 0 : k - tmp);
		unused += (tmp > k ? tmp - k : 0);
	}
	cout << unused << ' ' << sum << endl;
	return 0;
}
