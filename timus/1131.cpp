#include <iostream>
using namespace std;

int main() {
	int a, b, res = 0;
	cin >> a >> b;
	a--;
	if (a <= 0) {
		cout << 0 << endl;
		return 0;
	}
	for (; (1 << res) <= b && a - (1 << res) >= 0; res++)
		a -= (1 << res);
	cout << res + a / b + (a%b != 0) << endl;
 	return 0;
}
