#include <iostream>
using namespace std;

bool lucky(int n) {
	int a = 0, b = 0;
	for (int i = 0; i < 3; i++) {
		a += n % 10;
		n /= 10;
	}
	for (int i = 0; i < 3; i++) {
		b += n % 10;
		n /= 10;
	}
	return a == b;
}

int main() {
	int n;
	cin >> n;
	cout << (lucky(n - 1) || lucky(n + 1) ? "Yes" : "No") << endl;
	return 0;
}
