#include <iostream>
using namespace std;

int fact[6];

void init_fact() {
	fact[0] = 1;
	for (int i = 1; i < 6; i++)
		fact[i] = fact[i - 1] * i;
}

int com(int m, int n) {
	return fact[m] / fact[n] / fact[m - n];
}

int main() {
	int n, a = 0, b = 0, c = 0, tmp;
	init_fact();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp == 1) a++;
		else if (tmp == 2) b++;
		else c++;
	}
	if (a > b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	if (b > c) {
		tmp = b;
		b = c;
		c = tmp;
	}
	if (a > b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	if (n >= 6)
		if (a != n && b != n && c != n) cout << "Yes" << endl;
		else cout << "No" << endl;
	else
		if (com(n, a)*com(n, b) >= 6) cout << "Yes" << endl;
		else cout << "No" << endl;
	return 0;
}
