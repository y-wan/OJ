#include <iostream>
#include <string>
using namespace std;

string a[201];

void init() {
	a[1] = "sin(1)";
	for (int i = 2; i <= 200; i++)
		a[i] = a[i - 1].substr(0, a[i - 1].find(')')) + (i % 2 ? '+' : '-') + "sin(" + to_string(i) + ')' + a[i - 1].substr(a[i - 1].find(')'));
}

int main() {
	init();
	int n;
	cin >> n;
	string s = "";
	for (int i = 1; i < n; i++)
		s += '(';
	for (int i = 1; i <= n; i++) {
		s += a[i] + '+' + to_string(n + 1 - i);
		if (i < n) s += ')';
	}
	cout << s << endl;
 	return 0;
}
