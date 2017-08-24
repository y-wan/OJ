#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (a <= b)
		cout << 2 << endl;
	else
		cout << (a * 2 - 1) / b + 1 << endl;
	return 0;
}
