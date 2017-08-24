#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	cout << (n - m)*(n - m - 1) / 2 + m*(n - 2 * m) + 3 * m*(m - 1) / 2 << endl;
	return 0;
}
