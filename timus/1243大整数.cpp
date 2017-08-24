//´óÕûÊı
#include <iostream>
#include <string>
using namespace std;

int a[6];

int main() {
	string s;
	cin >> s;
	int len = s.size(), ext = len % 6;
	for (int i = ext - 1, j = 5; i >= 0; i--, j--)
		a[j] += (s[i] - '0');
	for (int i = 0; i < len - ext; i++)
		a[i % 6] += (s[i + ext] - '0');
	int res = 0, base = 1;
	for (int i = 5; i >= 0; i--) {
		if (a[i]) {
			res += a[i] * base;
			base *= 10;
		}
	}
	cout << res % 7 << endl;
	return 0;
}