#include <iostream>
using namespace std;

int main() {
	int a, b, num = 0, tmp;
	cin >> a >> b;
	for (int i = 0; i < b; i++) {
		cin >> tmp;
		num += tmp;
		if (num < a) num = 0;
		else num -= a;
	}
	cout << num << endl;
	return 0;
}
