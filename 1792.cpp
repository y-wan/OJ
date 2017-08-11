#include <iostream>
#include <string>
using namespace std;

int main() {
	int a, b, c, d, x, y, z;
	bool b1, b2, b3;
	cin >> a >> b >> c >> d >> x >> y >> z;
	b1 = (b + c + d) % 2 == x % 2;
	b2 = (a + c + d) % 2 == y % 2;
	b3 = (a + b + d) % 2 == z % 2;
	if (b1) {
		if (b2) {
			if (!b3) z = !z;
		}
		else {
			if (b3) y = !y;
			else a = !a;
		}
	}
	else {
		if (b2) {
			if (b3) x = !x;
			else b = !b;
		}
		else {
			if (b3) c = !c;
			else d = !d;
		}
	}
	cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << x << ' ' << y << ' ' << z << endl;
	return 0;
}
