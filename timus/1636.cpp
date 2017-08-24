#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int m, n, new_n, pt = 0, tmp;
	cin >> m >> n;
	for (int i = 0; i < 10; i++) {
		cin >> tmp;
		pt += tmp;
	}
	new_n = n - 20 * pt;
	if (new_n < m) cout << "Dirty debug :(" << endl;
	else cout << "No chance." << endl;
 	return 0;
}
