#include <iostream>

using namespace std;

int main() {
	//ios_base::sync_with_stdio(false);
	int n, x, b = -1000, f = 1000, tmp;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp > 0) f = f < tmp ? f : tmp;
		else b = b > tmp ? b : tmp;
	}
	if (b < x && x < f) {
		if (x > 0) cout << x << ' ' << 2 * (-b) + x << endl;
		else cout << 2 * f - x << ' ' << -x << endl;
	}
	else cout << "Impossible" << endl;
	return 0;
}
