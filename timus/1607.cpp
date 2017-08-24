#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, bei, yu;
	cin >> a >> b >> c >> d;
	if (a >= c) {
		cout << a << endl;
		return 0;
	}
	bei = (c - a) / (d + b);
	yu = (c - a) % (d + b);
	if (yu >= b)
		cout << a + b * (bei + 1) << endl;
	else cout << c - d * bei << endl;
	return 0;
}
