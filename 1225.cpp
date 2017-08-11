#include <iostream>
using namespace std;

long long fact[46];

void init() {
	fact[1] = 2;
	fact[2] = 2;
	for (int i = 3; i <= 45; i++)
		fact[i] = fact[i - 2] + fact[i - 1];
}

int main() {
	int n;
	init();
	cin >> n;
	cout << fact[n] << endl;
	return 0;
}
