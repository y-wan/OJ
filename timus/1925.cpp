#include <iostream>
using namespace std;

int main() {
	int n, k, a, b, sum = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		sum += a - b;
	}
	sum += k - (n + 1) * 2;
	if (sum > 0) cout << sum << endl;
	else cout << "Big Bang!" << endl;
 	return 0;
}
