#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int res = 40 + 2 * b > 2 * a + 39 ? 40 + 2 * b : 2 * a + 39;
	cout << res << endl;
	return 0;
}
