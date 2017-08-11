#include <iostream>
using namespace std;

int main() {
	long long a, b, c, m;
	cin >> a >> b >> c;
	if (a + b < c) {
		cout << "Impossible" << endl;
		return 0;
	}
	m = c < a ? c : a;
	cout << m << ' ' << c - m << endl;
 	return 0;
}
