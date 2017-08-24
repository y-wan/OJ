#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (b == 1 || b == 0 || c == 1)
		cout << a - b - c << endl;
	else
		cout << a - b * c << endl;
	return 0;
}
