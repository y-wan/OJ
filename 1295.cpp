#include <iostream>

using namespace std;

int main() {
	int n, res = 0;
	cin >> n;
	switch (n % 4) {
	case 1: res = 1; break;
	case 2: res = 1; break;
	case 3: res = 2; break;
	default:
		break;
	}
	if (n % 20 == 5) ++res;
	cout << res << endl;
	return 0;
}
