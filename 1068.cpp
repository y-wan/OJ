#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (1 > n) cout << (1 + n)*(2 - n) / 2;
	else cout << (1 + n)*n / 2;
	return 0;
}
