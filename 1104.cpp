#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int conv(char c) {
	if (isdigit(c)) return c - '0';
	else return c - 'A' + 10;
}

int main() {
	//ios_base::sync_with_stdio(false);
	string s;
	
	cin >> s;
	int k = 2, n = s.size(), sum = 0;
	for (int i = 0; i < n; i++) {
		sum += conv(s[i]);
		k = k > conv(s[i]) + 1 ? k: conv(s[i]) + 1;
	}
	for (; k <= 36; k++) {
		if (sum % (k - 1) == 0) {
			cout << k << endl;
			return 0;
		}
	}
	cout << "No solution.\n";
	return 0;
}
